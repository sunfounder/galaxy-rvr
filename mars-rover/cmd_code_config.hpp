#ifndef __CMD_CODE_CONFIG_H__
#define __CMD_CODE_CONFIG_H__

#include <Arduino.h>
#include "rgb.h"
#include "car_control.h"

/** Mode Value Definition */
#define MODE_NONE                    0
#define MODE_OBSTACLE_FOLLOWING      3
#define MODE_OBSTACLE_AVOIDANCE      4
#define MODE_REMOTE_CONTROL          5
#define MODE_APP_CONTROL             6

/** Set the color to match the mode */
#define ERROR_COLOR 0xFF0000 // Red
#define WARN_COLOR ORANGE

#define MODE_NONE_COLOR 0xE08080  // LightCyan

#define MODE_REMOTE_CONTROL_COLOR           GREEN_CYAN
#define MODE_APP_CONTROL_COLOR              MAGENTA

#define MODE_OBSTACLE_FOLLOWING_COLOR       BLUE
#define MODE_OBSTACLE_AVOIDANCE_COLOR       PURPLE


// State machine for almost all mode. State define see every function
uint8_t currentMode = MODE_NONE;

int8_t leftMotorDir = 0;
int8_t rightMotorDir = 0;

bool remoteDriftEnable  = false;

#define CMD_SUM 12

// Pay attention to the order,
// eg: 'left forward' needs to be placed before' left' and 'forward'
const char cmd_str_0[] PROGMEM = "stop";
const char cmd_str_1[] PROGMEM = "forward";
const char cmd_str_2[] PROGMEM = "backward";
const char cmd_str_3[] PROGMEM = "turn left";
const char cmd_str_4[] PROGMEM = "turn right";
const char cmd_str_5[] PROGMEM = "left forward";
const char cmd_str_6[] PROGMEM = "left backward";
const char cmd_str_7[] PROGMEM = "right forward";
const char cmd_str_8[] PROGMEM = "right backward";
const char cmd_str_9[] PROGMEM = "move left";
const char cmd_str_10[] PROGMEM = "move right";
const char cmd_str_11[] PROGMEM = "pasue";

const char *const cmd_str_table[] PROGMEM = {
  cmd_str_0, cmd_str_1, cmd_str_2, cmd_str_3,
  cmd_str_4, cmd_str_5, cmd_str_6, cmd_str_7,
  cmd_str_8, cmd_str_9, cmd_str_10,cmd_str_11,
};

#define STOP             0x00
#define FORWARD          0x01
#define BACKWARD         0x02
#define TRUE_LEFT        0x03
#define TRUE_RIGHT       0x04
#define PAUSE            0x0B

const int8_t cmd_code_table[CMD_SUM] PROGMEM={
  STOP,
  FORWARD,
  BACKWARD,
  TRUE_LEFT,
  TRUE_RIGHT,
  PAUSE,
};


int8_t text_2_cmd_code(char* text){
  String str = String(text);
  char buffer[20];
  for(uint8_t i=0; i<CMD_SUM; i++){
    strcpy_P(buffer, (char *)pgm_read_word(&cmd_str_table[i]));
    if(str.indexOf(buffer) != -1){
      // Serial.print(pgm_read_byte(&cmd_code_table[i]), HEX);
      // Serial.print(" , ");
      // Serial.println(buffer);
      return pgm_read_byte(&cmd_code_table[i]);
    }
  }
  return -1; //error-code
}


void stop();
void forward();
void backward();
void turn_left();
void turn_right();
void pause();

void (*cmd_fuc_table [])(){
  stop,
  forward,
  backward,
  turn_left,
  turn_right,
  pause,
};

void stop(){
  currentMode = MODE_NONE;
  leftMotorDir = 0;
  rightMotorDir = 0;
  carStop();
}

void forward(){
  leftMotorDir = 1;
  rightMotorDir = 1;
}

void backward(){
  leftMotorDir = -1;
  rightMotorDir = -1;
}

void turn_left(){
  leftMotorDir = -1;
  rightMotorDir = 1;
}

void turn_right(){
  leftMotorDir = 1;
  rightMotorDir = -1;
}

void pause(){
  leftMotorDir = 0;
  rightMotorDir = 0;
  carStop();
}

#endif

