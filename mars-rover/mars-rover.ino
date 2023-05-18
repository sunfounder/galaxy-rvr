/*******************************************************************
  The control program of the Ardunio Mars Rover.
  
  Please install SunFounder Controller APP from APP Store(iOS) or Google Play(Android).

  Development test environment:
    - Arduino IDE 2.0.3
  Board tools:
    - Arduino AVR Boards 1.8.3
  Libraries:
    - IRLremote
    - SoftPWM

  Version: 0.0.1
    -- https://github.com/sunfounder/zeus-car.git
  
  Author: Sunfounder
  Website: https://www.sunfounder.com
           https://docs.sunfounder.com

 *******************************************************************/

#define VERSION "0.0.2"

#include <Arduino.h>
#include <SoftPWM.h>
#include <string.h>

#include "rgb.h"
#include "car_control.h"
#include "ir_obstacle.h"
#include "ultrasonic.h"
#include "cmd_code_config.hpp"
#include "ai_camera.h"
#include "soft_servo.h"
// #include "Servo.h"
#include "battery.h"


/*************************** Configure *******************************/
/** @name Configure 
 * 
 */
///@{
/** Whether to enable Watchdog */
#define WATCH_DOG 0
#if WATCH_DOG
  #include <avr/wdt.h>
#endif

/** Whether to enable TEST mode */
#define TEST 0
#if TEST
  #include "test.h"
#endif

/** Whether to enable  */
#define MEM 0
#if MEM
  #include <MemoryFree.h>
  #include <pgmStrToRAM.h> // not needed for new way. but good to have for reference.
#endif


/** Configure Wifi mode, SSID, password*/
#define WIFI_MODE WIFI_MODE_AP
#define SSID "Mars Rover"
#define PASSWORD "11111111"

// #define WIFI_MODE WIFI_MODE_STA
// #define SSID "xxxxxxxxxx"
// #define PASSWORD "xxxxxxxxxx"

/** Configure product name */
#define NAME "Mars Rover"

/** Configure product type */
#define TYPE "Mars Rover"

/** Configure websockets port
 * Sunfounder Controller APP fixed using port 8765
*/
#define PORT "8765"

#define SERVO_REVERSE true
#define SERVO_PIN 6
#define BATTERY_LEVEL_PIN A3

/** Configure the motors speed in different modes */
#define SPEECH_REMOTE_POWER 40
#define IR_REMOTE_POWER  50
#define OBSTACLE_AVOID_POWER 80
#define OBSTACLE_FOLLOW_POWER 80

/** Configure the follow distance of obstacle follow */
#define FOLLOW_DISTANCE 20

/** websocket communication headers */ 
#define WS_HEADER "WS+"

///@}

/*********************** Global variables ****************************/
/** Check if a string starts with a certain character */
#define IsStartWith(str, prefix) (strncmp(str, prefix, strlen(prefix)) == 0)

/** Instantiate aicamera, a class for serial communication with ESP32-CAM */
AiCamera aiCam = AiCamera(NAME, TYPE);
// Servo servo;
SoftServo servo;

bool irOrAppFlag = false; // true: App, false: IR

char speech_buf[20];
uint8_t leftMotorPower = 0;
uint8_t rightMotorPower = 0;
uint8_t servoAngle = 90;

//@}

/*********************** setup() & loop() ************************/
/**
 * setup(), Ardunio main program entrance
 * 
 * Initialization of some peripherals
 */
void setup() {
  int m = millis();
  Serial.begin(115200);
  Serial.print("Mars rover version ");Serial.println(VERSION);

  Serial.println(F("Initialzing..."));
  SoftPWMBegin(); // init softpwm, before the motors initialization and the rgb LEDs initialization
  rgbBegin();
  rgbWrite(ORANGE); // init hint
  carBegin();
  irObstacleBegin();
  batteryBegin();
  servo.attach(SERVO_PIN);
  aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT);
  aiCam.setOnReceived(onReceive);
  while (millis() - m < 500) { // Wait for peripherals to be ready
    delay(1);
  }

  #if WATCH_DOG
  wdt_disable();  /* Disable the watchdog and wait for more than 2 seconds */
  delay(3000);  /* Done so that the Arduino doesn't keep resetting infinitely in case of wrong configuration */
  wdt_enable(WDTO_2S);  /* Enable the watchdog with a timeout of 2 seconds */
  #endif

  Serial.println(F("Okie!"));
  rgbWrite(GREEN); // init finished
}

/**
 * loop(), Ardunio main loop
 * 
 * - inclued
 *  - aiCam.loop()
 *  - modeHandler()
 * - or modules test
 */
void loop() {
  #if !TEST 
    // because the value in a is constantly updated
    // Note that the cycle interval of the "aiCam.loop()" should be less than 80ms to avoid data d
    aiCam.loop();
    modeHandler();
  #else
    /* Select the item to be tested, multiple selection allowed */
    motors_test();
    // rgb_test();
    // ultrasonic_test();
    // ir_obstacle_test();
    // obstacleAvoidance();
  #endif 

  #if WATCH_DOG
    wdt_reset();  /* Reset the watchdog */
  #endif

  #if MEM
    Serial.print(F("Free RAM = ")); //F function does the same and is now a built in library, in IDE > 1.0.0
    Serial.println(freeMemory());  // print how much RAM is available in bytes.
  #endif

}

/***************************** Functions ******************************/
/**
 * modeHandler(), Execute the corresponding program according to the set mode
 * 
 * - inclued
 *  - MODE_NONE
 *  - MODE_OBSTACLE_FOLLOWING
 *  - MODE_OBSTACLE_AVOIDANCE
 *  - MODE_REMOTE_CONTROL
 *  - MODE_APP_CONTROL
 */
void modeHandler() {
  switch (currentMode) {
    case MODE_NONE: 
      rgbWrite(MODE_NONE_COLOR);    
      break;
    case MODE_OBSTACLE_FOLLOWING:
      rgbWrite(MODE_OBSTACLE_FOLLOWING_COLOR);
      obstacleFollowing();
      break;
    case MODE_OBSTACLE_AVOIDANCE:
      rgbWrite(MODE_OBSTACLE_AVOIDANCE_COLOR);
      obstacleAvoidance();
      break;
    case MODE_REMOTE_CONTROL:
      rgbWrite(MODE_REMOTE_CONTROL_COLOR);
      carSetMotors(leftMotorDir * IR_REMOTE_POWER, rightMotorDir * IR_REMOTE_POWER);
      break;
    case MODE_APP_CONTROL:
      rgbWrite(MODE_APP_CONTROL_COLOR);
      servo.write(servoAngle);
      carSetMotors(leftMotorPower, rightMotorPower);
      break;
    default:
      break;
  }
}


/**
 * Obstacle follow program
 */
void obstacleFollowing() {
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000001;
  bool rightIsClear = result & 0b00000010;
  float usDistance = ultrasonicRead();

  if (usDistance < 4) {
    carStop();
  } else if (usDistance < 10) {
    carForward(30);
  } else if (usDistance < FOLLOW_DISTANCE) {
    carForward(OBSTACLE_FOLLOW_POWER);
  } else {
    if (!leftIsClear) {
      carTurnLeft((int8_t)OBSTACLE_FOLLOW_POWER);
    } else if (!rightIsClear) {
      carTurnRight(OBSTACLE_FOLLOW_POWER);
    } else {
      carStop();
    }
  }
}

/**
 * Obstacle avoidance program
 */
void obstacleAvoidance() {
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000001;
  bool rightIsClear = result & 0b00000010;
  bool middleIsClear = ultrasonicIsClear();

  if (middleIsClear && leftIsClear && rightIsClear) {
    carForward(OBSTACLE_AVOID_POWER);
  } else {
    if (leftIsClear) {
      carTurnLeft(OBSTACLE_AVOID_POWER);
    } else {
      carTurnRight(OBSTACLE_AVOID_POWER);
    }
  }
}

/**
 * websocket received data processing
 */
void onReceive() {
  
  // Mode select: obstacle following, obstacle avoidance
  if (aiCam.getSwitch(REGION_O)) {
    irOrAppFlag = true;
    if (currentMode != MODE_OBSTACLE_FOLLOWING) {
      currentMode = MODE_OBSTACLE_FOLLOWING;
    }
  } else if (aiCam.getSwitch(REGION_P)) {
    irOrAppFlag = true;
    if (currentMode != MODE_OBSTACLE_AVOIDANCE) {
      currentMode = MODE_OBSTACLE_AVOIDANCE;
    }
  } else {
    if (irOrAppFlag == true) {
      irOrAppFlag = false;
      currentMode = MODE_NONE;
      stop();
      return;
    }
  }

  int temp = aiCam.getSlider(REGION_L);
  if (servoAngle != temp) {
    if (currentMode != MODE_APP_CONTROL) {
      currentMode = MODE_APP_CONTROL;
    }
    if (SERVO_REVERSE) {
      temp = 180 - temp;      
    }
    servoAngle = temp;
  }
   
  temp = aiCam.getThrottle(REGION_K);
  if (leftMotorPower != temp) {
    if (currentMode != MODE_APP_CONTROL) {
      currentMode = MODE_APP_CONTROL;
    }
    leftMotorPower = temp;
  }
  temp = aiCam.getThrottle(REGION_Q);
  if (rightMotorPower != temp) {
    if (currentMode != MODE_APP_CONTROL) {
      currentMode = MODE_APP_CONTROL;
    }
    rightMotorPower = temp;
  }

  // uint8_t batteryPercent = batteryGetPercentage();
  // aiCam.setBattery(sendBuf, batteryPercent);

  // voltage
  float vol = analogRead(VOL_PIN)/1024.0*5*2;
  vol = int(vol*100)/100.0;
  Serial.print(F("vol:"));Serial.println(vol);
  aiCam.send_doc["BV"] = vol;
}
