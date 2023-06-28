/*******************************************************************
  The control program of the Ardunio GalaxyRVR.
  
  Please install the SunFounder Controller APP from APP Store(iOS) or Google Play(Android).

  Development test environment:
    - Arduino IDE 2.0.3
  Board tools:
    - Arduino AVR Boards 1.8.3
  Libraries:
    - IRLremote
    - SoftPWM
    - Servo
    - ArduinoJson
    - Sunfounder_AI_Camera

  Version: 0.0.4
    -- https://github.com/sunfounder/galaxy-rvr.git
  
  Documentation:
    -- https://docs.sunfounder.com/projects/galaxy-rvr/en/latest/

  Author: Sunfounder
  Website: https://www.sunfounder.com
           https://docs.sunfounder.com

********************************************************************/
#define VERSION "0.0.4"

#include <Arduino.h>
#include <SoftPWM.h>
#include <Servo.h>
#include <string.h>

#include "rgb.h"
#include "car_control.h"
#include "ir_obstacle.h"
#include "ultrasonic.h"
#include "cmd_code_config.hpp"
#include "SunFounder_AI_Camera.h"
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

/** Whether to enable print Memory Used */
#define MEM 0
#if MEM
  // https://github.com/mpflaga/Arduino-MemoryFree
  #include <MemoryFree.h>
  #include <pgmStrToRAM.h> // not needed for new way. but good to have for reference.
#endif


/** Configure Wifi mode, SSID, password*/
#define WIFI_MODE WIFI_MODE_AP
#define SSID "GalaxyRVR"
#define PASSWORD "12345678"

// #define WIFI_MODE WIFI_MODE_STA
// #define SSID "xxxxxxxxxx"
// #define PASSWORD "xxxxxxxxxx"

/** Configure product name */
#define NAME "GalaxyRVR"

/** Configure product type */
#define TYPE "GalaxyRVR"

/** Configure websockets port
 * Sunfounder Controller APP fixed using port 8765
*/
#define PORT "8765"


/** Configure the motors speed in different modes */
#define OBSTACLE_AVOID_POWER 80
#define OBSTACLE_FOLLOW_POWER 80
#define VOICE_CONTROL_POWER 80

/** Configure the follow distance of obstacle follow */
#define FOLLOW_DISTANCE 20

/** websocket communication headers */ 
#define WS_HEADER "WS+"

///@} 

/*********************** Global variables ****************************/
/** Instantiate aicamera, a class for serial communication with ESP32-CAM */
AiCamera aiCam = AiCamera(NAME, TYPE);

/* Config Camera Servo */
Servo servo;
#define SERVO_PIN 6
#define SERVO_REVERSE true

/* variables of voice control */
char voice_buf_temp[20];
int8_t current_voice_code = -1;
int32_t voice_time = 0; // uint:s
uint32_t voice_start_time = 0; // uint:s

/* variables of motors and servo*/
int8_t leftMotorPower = 0;
int8_t rightMotorPower = 0;
uint8_t servoAngle = 90;

/* variables of rgb_blink when disconnected */
uint32_t rgb_blink_interval = 500; // uint: ms
uint32_t rgb_blink_start_time = 0;
bool rgb_blink_flag = 0;
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
  Serial.print("GalaxyRVR version ");Serial.println(VERSION);

  Serial.println(F("Initialzing..."));
  SoftPWMBegin(); // init softpwm, before the motors initialization and the rgb LEDs initialization
  rgbBegin();
  rgbWrite(ORANGE); // init hint
  carBegin();
  irObstacleBegin();
  batteryBegin();
  servo.attach(SERVO_PIN);
  servo.write(90);

  #if !TEST
    aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT);
    aiCam.setOnReceived(onReceive);
  #endif

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
   if (aiCam.ws_connected == false) {
      currentMode = MODE_DISCONNECT;
      int8_t current_voice_code = -1;
      int8_t voice_time = 0;
      if (currentMode != MODE_DISCONNECT) {
        rgb_blink_start_time = 0;
        rgb_blink_flag = 1;
      }
    } else {
      if (currentMode == MODE_DISCONNECT) currentMode = MODE_NONE;
    }
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
      carStop();
      servoAngle = 90;
      servo.write(servoAngle);
      break;
    case MODE_DISCONNECT:
      if (millis() - rgb_blink_start_time > rgb_blink_interval) {
        rgb_blink_flag = !rgb_blink_flag;
        rgb_blink_start_time = millis();
      }
      if (rgb_blink_flag) rgbWrite(MODE_DISCONNECT_COLOR);
      else rgbOff();
      carStop();
      servoAngle = 90;
      servo.write(servoAngle);
      break;
    case MODE_OBSTACLE_FOLLOWING:
      rgbWrite(MODE_OBSTACLE_FOLLOWING_COLOR);
      servo.write(servoAngle);
      obstacleFollowing();
      break;
    case MODE_OBSTACLE_AVOIDANCE:
      rgbWrite(MODE_OBSTACLE_AVOIDANCE_COLOR);
      servo.write(servoAngle);
      obstacleAvoidance();
      break;
    case MODE_APP_CONTROL:
      rgbWrite(MODE_APP_CONTROL_COLOR);
      servo.write(servoAngle);
      carSetMotors(leftMotorPower, rightMotorPower);
      break;
    case MODE_VOICE_CONTROL:
      rgbWrite(MODE_VOICE_CONTROL_COLOR);
      servo.write(servoAngle);
      voice_control();
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
  bool leftIsClear = result & 0b00000010;
  bool rightIsClear = result & 0b00000001;
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
int8_t last_clear = -1; // last_clear, 1, left; -1, right;
bool last_forward = false;

void obstacleAvoidance() {
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000010; // left, clear: True
  bool rightIsClear = result & 0b00000001; // right, clear: True
  bool middleIsClear = ultrasonicIsClear();

  if (middleIsClear && leftIsClear && rightIsClear) { // 111
    last_forward = true;
    carForward(OBSTACLE_AVOID_POWER);
  } else {
    if( (leftIsClear&& rightIsClear) || (!leftIsClear&& !rightIsClear)) { // 101, 000, 010
      if (last_clear == 1)  carTurnLeft(OBSTACLE_AVOID_POWER);
      else carTurnRight(OBSTACLE_AVOID_POWER);
      last_forward = false;
    }
    else if (leftIsClear) { // 100, 110
      if (last_clear == 1 || last_forward == true) {
        carTurnLeft(OBSTACLE_AVOID_POWER);
        last_clear = 1;
        last_forward = false;
      }
    } 
    else if ( rightIsClear) { // 001, 011
      if (last_clear == -1 || last_forward == true) {
        carTurnRight(OBSTACLE_AVOID_POWER);
        last_clear = -1;
        last_forward = false;
      }
    }
  }
}

/**
 * voice control program
 */
void voice_control() {
  if (voice_time == -1) {
    voice_action(current_voice_code, VOICE_CONTROL_POWER);
  } else {
    if (millis() - voice_start_time <= voice_time) {
      voice_action(current_voice_code, VOICE_CONTROL_POWER);
    } else {
      currentMode = MODE_NONE;
      voice_start_time = 0;
      current_voice_code = -1;
    }
  }
}

/**
 * websocket received data processing
 */
void onReceive() {  
  // --------------------- send data ---------------------
  // battery voltage
  // Serial.print(F("voltage:"));Serial.println(batteryGetVoltage());
  aiCam.sendDoc["BV"] = batteryGetVoltage();

  // IR obstacle detection data
  byte result = irObstacleRead();
  aiCam.sendDoc["N"] = int(!bool(result & 0b00000010)); // left, clear:0
  aiCam.sendDoc["P"] = int(!bool(result & 0b00000001)); // right, clear:0

  // ultrasonic
  float usDistance = int(ultrasonicRead()*100)/100.0; // round two decimal places
  aiCam.sendDoc["O"] = usDistance;

  // --------------------- get data ---------------------
  // Stop
  if (aiCam.getButton(REGION_I)) {
    currentMode = MODE_NONE;
    current_voice_code = -1;
    voice_time = 0;
    carStop();
    return;
  }

  // Mode select: obstacle following, obstacle avoidance
  if (aiCam.getSwitch(REGION_E)) {
    if (currentMode != MODE_OBSTACLE_AVOIDANCE) {
      currentMode = MODE_OBSTACLE_AVOIDANCE;
    }
  } else if (aiCam.getSwitch(REGION_F)) {
    if (currentMode != MODE_OBSTACLE_FOLLOWING) {
      currentMode = MODE_OBSTACLE_FOLLOWING;
    }
  } else {
    if (currentMode == MODE_OBSTACLE_FOLLOWING || currentMode == MODE_OBSTACLE_AVOIDANCE) {
      currentMode = MODE_NONE;
      carStop();
      return;
    }
  }

  // Speech control
  if (currentMode != MODE_VOICE_CONTROL) {
    current_voice_code = -1;
    voice_time = 0;
    voice_start_time = 0;
    aiCam.sendDoc["J"] = 0;
  }

  int8_t code = -1;
  voice_buf_temp[0] = 0; // voice_buf_temp
  aiCam.getSpeech(REGION_J, voice_buf_temp);
  if (strlen(voice_buf_temp) > 0) {
    aiCam.sendDoc["J"] = 1;
    aiCam.sendData();
    aiCam.sendDoc["J"] = 0;
    code = text_2_cmd_code(voice_buf_temp);
    if (code != -1) {
      current_voice_code = code;
      voice_time = voice_action_time[code];
      voice_start_time = millis();
    }
  }

  if (current_voice_code != -1) {
    currentMode = MODE_VOICE_CONTROL;
  }

  // servo angle
  int temp = aiCam.getSlider(REGION_D);
  if (servoAngle != temp) {
    if (currentMode == MODE_NONE || currentMode == MODE_DISCONNECT) {
      currentMode = MODE_APP_CONTROL;
    }
    temp = constrain(temp, 40, 180);
    if (SERVO_REVERSE) {
      temp = 180 - temp;      
    }
    servoAngle = temp;
  }
   
  // throttle
  int throttle_L = aiCam.getThrottle(REGION_K);
  int throttle_R = aiCam.getThrottle(REGION_Q);
  // Serial.print("throttle_L: "); Serial.print(throttle_L);
  // Serial.print("throttle_R: "); Serial.println(throttle_R);
  if ( throttle_L != 0 || throttle_R != 0 || throttle_L != leftMotorPower || throttle_R != rightMotorPower) {
    currentMode = MODE_APP_CONTROL;
    leftMotorPower = throttle_L;
    rightMotorPower = throttle_R;
  }

}
