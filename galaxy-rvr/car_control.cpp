#include "car_control.h"

#include <Arduino.h>
#include <SoftPWM.h>

#define MOTOR_POWER_MIN 28  // 28/255

/** 
* @brief Initialize the motor, and (block) the initialization compass
*/
void carBegin() {
  for (uint8_t i = 0; i < 4; i++) {
    SoftPWMSet(MOTOR_PINS[i], 0);
    SoftPWMSetFadeTime(MOTOR_PINS[i], 100, 100);
  }
}

/** 
 * @name simple move functions
 */
void carForward(int8_t power)       { carSetMotors( power,  power); }
void carBackward(int8_t power)      { carSetMotors(-power, -power); }
void carTurnLeft(int8_t power)      { carSetMotors(-power,  power); }
void carTurnRight(int8_t power)     { carSetMotors( power, -power); }
void carStop()                      { carSetMotors(     0,      0); }

/** 
 * @brief Set speed for 2 motors
 *
 * @param power0  0 ~ 100
 * @param power1  0 ~ 100
 */
void carSetMotors(int8_t power0, int8_t power1) {
  bool dir[2];
  int8_t power[2] = {power0, power1};
  int8_t newPower[2];

  for (uint8_t i = 0; i < 2; i++) {
    dir[i] = power[i] > 0;

    if (MOTOR_DIRECTIONS[i]) dir[i] = !dir[i];

    if (power[i] == 0) {
      newPower[i] = 0;
    } else {
      newPower[i] = map(abs(power[i]), 0, 100, MOTOR_POWER_MIN, 255);
    }
    SoftPWMSet(MOTOR_PINS[i*2], dir[i] * newPower[i]);
    SoftPWMSet(MOTOR_PINS[i*2+1], !dir[i] * newPower[i]);
  }
}
