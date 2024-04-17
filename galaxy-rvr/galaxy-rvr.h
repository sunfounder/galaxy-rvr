
#include <Arduino.h>
#include <SoftPWM.h>
#include <string.h>

#include "rgb.h"
#include "soft_servo.h"
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


/** Configure AP SSID, password*/
#define AP_SSID "GalaxyRVR"
#define AP_PASSWORD "12345678"

/** Configure product name */
#define NAME "GalaxyRVR"
/** Configure product type */
#define TYPE "GalaxyRVR"

/** Configure websockets port
 * Sunfounder Controller APP fixed using port 8765
 */
#define PORT "30102"

/**
 * Define State Machine
 */
#define STATE_IDLE 0
#define STATE_APP 1

/** Configure the motors speed in different modes */
#define SPEECH_REMOTE_POWER 60
#define OBSTACLE_AVOID_POWER 65
#define OBSTACLE_FOLLOW_POWER 65

/** Configure the follow distance of obstacle follow */
#define FOLLOW_DISTANCE 20

/** Servo settings */
#define SERVO_PIN 6
#define SERVO_REVERSE false

/** websocket communication headers */
#define WS_DATA_START_BIT 0xA0
#define WS_DATA_END_BIT 0xA1