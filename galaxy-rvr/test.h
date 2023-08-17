#ifndef _TEST_H_
#define _TEST_H_

#include <Arduino.h>

#include "car_control.h"
#include "ir_obstacle.h"
#include "ultrasonic.h"
#include "rgb.h"

/** motors test, the car cycles forward and backward */
void motors_test(){
  carForward(80);
  rgbWrite(0, 255, 0);
  delay(2000);

  carBackward(80);
  rgbWrite(255, 0, 0);
  delay(2000);

  carTurnLeft(80);
  rgbWrite(0, 0, 255);
  delay(2000);

  carTurnRight(80);
  rgbWrite(255, 255, 0);
  delay(2000);
}

/** RGB LEDs test, the LEDs cyclic transformation of R,G,B three colors */
void rgb_test() {
  rgbWrite(RED);
  delay(1000);
  rgbWrite(GREEN);
  delay(1000);
  rgbWrite(BLUE);
  delay(1000); 
}

/** ultrasonictest, cyclic printing of the detected data */
void ultrasonic_test() {
  rgbWrite(BLUE);
  float distance = ultrasonicRead();
  Serial.print("distance: ");
  Serial.println(distance);
  delay(100);
  rgbOff(); 
  delay(500);
}

/** infrared obstacle avoidance module test, cyclic printing of the detected data */
void ir_obstacle_test() {
  // uint16_t result = hc165Read();
  // Serial.println(result, BIN);
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000001;
  bool rightIsClear = result & 0b00000010;
  Serial.print(leftIsClear);
  Serial.print(", ");
  Serial.println(rightIsClear);
  delay(100);
}

#endif // TEST_H_INCLUDED

