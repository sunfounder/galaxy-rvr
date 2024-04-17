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
    - ArduinoJson
    - Sunfounder_AI_Camera

  Version: 1.0.0
    -- https://github.com/sunfounder/galaxy-rvr.git
  
  Documentation:
    -- https://docs.sunfounder.com/projects/galaxy-rvr/en/latest/

  Author: Sunfounder
  Website: https://www.sunfounder.com
           https://docs.sunfounder.com

********************************************************************/
#define VERSION "1.2.0"

#include "galaxy-rvr.h"


/*********************** Global variables ****************************/
/** Instantiate aicamera, a class for serial communication with ESP32-CAM */
AiCamera aiCam = AiCamera(NAME, TYPE);

/* Config Camera Servo */
SoftServo servo;

// current state
uint8_t currentState = STATE_IDLE;
// last state
uint8_t lastState = 255;
// obstacle power
uint8_t obstaclePower = 0;
// last mode
uint8_t lastMode = 255;
/* variables of motors and servo*/
int8_t leftMotorPower = 0;
int8_t rightMotorPower = 0;
uint8_t servoAngle = 90;

/* variables of voice control */
char voice_buf_temp[20];
int8_t current_voice_code = -1;
int32_t voice_time = 0; // uint:s
uint32_t voice_start_time = 0; // uint:s

/* variables of rgb_blink when disconnected */
uint32_t rgb_blink_interval = 500; // uint: ms
uint32_t rgb_blink_start_time = 0;
bool rgb_blink_flag = 0;

/* variable of esp32-cam flash lamp*/
bool cam_lamp_status = false;
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
  Serial.print("GalaxyRVR version "); Serial.println(VERSION);

  Serial.println(F("Initialzing..."));
#if defined(ARDUINO_AVR_UNO)
  SoftPWMBegin(); // init softpwm, before the motors initialization and the rgb LEDs initialization
#endif
  rgbBegin();
  rgbWrite(ORANGE); // init hint
  carBegin();
  irObstacleBegin();
  batteryBegin();
  servo.attach(SERVO_PIN);
  servo.write(90);

  aiCam.begin(AP_SSID, AP_PASSWORD, PORT, false);
  aiCam.setOnReceivedBinary(onReceive);

  while (millis() - m < 500) {  // Wait for peripherals to be ready
    delay(1);
  }

#if WATCH_DOG
  wdt_disable();       /* Disable the watchdog and wait for more than 2 seconds */
  delay(3000);         /* Done so that the Arduino doesn't keep resetting infinitely in case of wrong configuration */
  wdt_enable(WDTO_2S); /* Enable the watchdog with a timeout of 2 seconds */
#endif

  Serial.println(F("Okie!"));
  rgbWrite(GREEN);  // init finished
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
  if (lastState != currentState) {
    Serial.print(F("State changed to "));
    lastState = currentState;
    switch (currentState) {
      case STATE_IDLE: {
        Serial.println(F("IDLE"));
        rgbWrite(COLOR_STATE_IDLE);
        carStop();
        servoAngle = 90;
        servo.write(servoAngle);
        break;
      }
      case STATE_APP: {
        Serial.println(F("APP"));
        currentMode = MODE_APP_CONTROL;
        rgbWrite(COLOR_STATE_APP);
        break;
      }
      default:
        break;
    }
  }

  switch (currentState) {
    case STATE_IDLE:
      {
        if (millis() - rgb_blink_start_time > rgb_blink_interval) {
          rgb_blink_flag = !rgb_blink_flag;
          rgb_blink_start_time = millis();
        }
        if (rgb_blink_flag) rgbWrite(COLOR_STATE_IDLE);
        else rgbOff();
        if (aiCam.ws_connected == true) {
          currentState = STATE_APP;
        }
        break;
      }
    case STATE_APP:
      {
        handleSensorData();
        if (aiCam.ws_connected == false) {
          currentState = STATE_IDLE;
        }
        modeHandler();
        break;
      }
    default:
      break;
  }

  // because the value in a is constantly updated
  // Note that the cycle interval of the "aiCam.loop()" should be less than 80ms to avoid data d
  aiCam.loop();

#if WATCH_DOG
  wdt_reset(); /* Reset the watchdog */
#endif

#if MEM
  Serial.print(F("Free RAM = "));  //F function does the same and is now a built in library, in IDE > 1.0.0
  Serial.println(freeMemory());    // print how much RAM is available in bytes.
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
 *  - MODE_APP_CONTROL
 */
void modeHandler() {
  if (lastMode != currentMode) {
    Serial.print(F("Mode Change: "));Serial.print(lastMode);Serial.print(F(" -> "));Serial.println(currentMode);
    lastMode = currentMode;
  }
  switch (currentMode) {
    case MODE_OBSTACLE_FOLLOWING:
      servo.write(servoAngle);
      obstacleFollowing();
      break;
    case MODE_OBSTACLE_AVOIDANCE:
      servo.write(servoAngle);
      obstacleAvoidance();
      break;
    case MODE_APP_CONTROL:
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
  bool leftIsClear = result & 0b00000010;
  bool rightIsClear = result & 0b00000001;
  float usDistance = ultrasonicRead();
  // usDistance = -1 while the distance is too far
  if (usDistance < 4 && usDistance > 0) {
    carStop();
  } else if (usDistance < 10 && usDistance > 0) {
    carForward(30);
  } else if (usDistance < FOLLOW_DISTANCE && usDistance > 0) {
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
int8_t last_clear = -1;  // last_clear, 1, left; -1, right;
bool last_forward = false;

void obstacleAvoidance() {
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000010;   // left, clear: True
  bool rightIsClear = result & 0b00000001;  // right, clear: True
  bool middleIsClear = ultrasonicIsClear();

  if (middleIsClear && leftIsClear && rightIsClear) {  // 111
    last_forward = true;
    carForward(OBSTACLE_AVOID_POWER);
  } else {
    if ((leftIsClear && rightIsClear) || (!leftIsClear && !rightIsClear)) {  // 101, 000, 010
      if (last_clear == 1) carTurnLeft(OBSTACLE_AVOID_POWER);
      else carTurnRight(OBSTACLE_AVOID_POWER);
      last_forward = false;
    } else if (leftIsClear) {  // 100, 110
      if (last_clear == 1 || last_forward == true) {
        carTurnLeft(OBSTACLE_AVOID_POWER);
        last_clear = 1;
        last_forward = false;
      }
    } else if (rightIsClear) {  // 001, 011
      if (last_clear == -1 || last_forward == true) {
        carTurnRight(OBSTACLE_AVOID_POWER);
        last_clear = -1;
        last_forward = false;
      }
    }
  }
}

/**
 * websocket received data processing
 */
void onReceive() {
  Serial.print("onReceive:");
  for (int i = 0; i < aiCam.recvBufferLength; i++) {
    Serial.print(aiCam.recvBuffer[i], HEX);
    Serial.print(" ");
  }
  Serial.println(" ");

  for (int i = 0; i < aiCam.recvBufferLength; i++) {
    uint8_t entityId = aiCam.recvBuffer[i];
    switch (entityId) {
      case 0x01:  // Car move
        {
          i += 1;
          leftMotorPower = aiCam.recvBuffer[i];
          i += 1;
          rightMotorPower = aiCam.recvBuffer[i];
          currentMode = MODE_APP_CONTROL;
          break;
        }
      case 0x02:  // RGB control
        {
          i += 1;
          uint8_t r = aiCam.recvBuffer[i];
          i += 1;
          uint8_t g = aiCam.recvBuffer[i];
          i += 1;
          uint8_t b = aiCam.recvBuffer[i];
          // Serial.println(F("Set RGB: ("));Serial.print(r);
          // Serial.print(F(", "));Serial.print(g);
          // Serial.print(F(", "));Serial.print(b);Serial.println(")");
          rgbWrite(r, g, b);
          break;
        }
      case 0x03:  // Servo Angle
        {
          i += 1;
          servoAngle = aiCam.recvBuffer[i];
          // Serial.println(F("Servo Angle"));
          // Serial.print(F("servoAngle:"));Serial.println(servoAngle);
          break;
        }
      case 0x04:  // Front Light
        {
          i += 1;
          if (aiCam.recvBuffer[i] == 1){
            cam_lamp_status = true;
            aiCam.lamp_on(5);  //turn on cam lamp, level 0 ~ 10 
          } else{
            cam_lamp_status = false;
            aiCam.lamp_off();
          }
          break;
        }
      case 0x05:  // Obstacle mode
        {
          i += 1;
          uint8_t state = aiCam.recvBuffer[i];
          i += 1;
          uint8_t mode = aiCam.recvBuffer[i];
          i += 1;
          obstaclePower = aiCam.recvBuffer[i];
          // Serial.print(F("Obstacle "));
          if (state) {
            // Serial.print(F(" ON"));
            if (mode == 0) {
              // Serial.print(F(" avoidance"));
              currentMode = MODE_OBSTACLE_AVOIDANCE;
            } else {
              // Serial.print(F(" following"));
              currentMode = MODE_OBSTACLE_FOLLOWING;
            }
          } else {
            // Serial.print(F(" OFF"));
            currentMode = MODE_APP_CONTROL;
          }
          // Serial.print(F(" power:"));Serial.println(obstaclePower);
          break;
        }
    }
  }
}

void handleSensorData() {
  uint8_t toSend[WS_BUFFER_SIZE];
  int index = 0;
  toSend[index] = WS_DATA_START_BIT;

  // data length placeholder
  index += 1;
  toSend[index] = 0x00;

  // checksum placeholder
  index += 1;
  toSend[index] = 0x00;

  // UltraSonic
  index += 1;
  toSend[index] = 0x81;
  uint16_t ultrasonicMM = ultrasonicRead() * 10.0;
  uint8_t ultrasonicMMMSB = ultrasonicMM >> 8;
  uint8_t ultrasonicMMLS = ultrasonicMM & 0xFF;
  index += 1;
  toSend[index] = ultrasonicMMMSB;
  index += 1;
  toSend[index] = ultrasonicMMLS;

  // IR Obstacle
  index += 1;
  toSend[index] = 0x82;
  uint8_t irObstacle = irObstacleRead();
  index += 1;
  toSend[index] = irObstacle;

  // Battery Voltage
  index += 1;
  toSend[index] = 0x83;
  uint8_t batteryVoltage = batteryGetVoltage() * 10;
  index += 1;
  toSend[index] = batteryVoltage;

  // End bit
  index += 1;
  toSend[index] = WS_DATA_END_BIT;

  uint8_t payloadLength = index + 1;

  // Data length
  toSend[1] = payloadLength - 4;

  // Checksum
  uint8_t checksum = 0;
  for (int i = 0; i < payloadLength - 1; i++) {
    checksum ^= toSend[i];
  }
  toSend[2] = checksum;

  aiCam.sendBinaryData(toSend, payloadLength);
}
