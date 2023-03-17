#ifndef __SOFT_SERVO_H__
#define __SOFT_SERVO_H__

#include <Arduino.h>
#include <SoftPWM.h>

class SoftServo {

public:
  SoftServo();
  void begin(uint8_t pin);
  void attach(uint8_t pin);
  void write(uint8_t angle);

private:
  uint8_t pin;
};
#endif // __SOFT_SERVO_H__