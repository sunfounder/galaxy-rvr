#include "soft_servo.h"

SoftServo::SoftServo() {
  this->pin = 0;
}

void SoftServo::begin(uint8_t pin) {
  this->pin = pin;
  SoftPWMSet(this->pin, 0);
  SoftPWMSetFadeTime(this->pin, 100, 100);
}

void SoftServo::attach(uint8_t pin) {
  this->begin(pin);
}

void SoftServo::write(uint8_t angle) {
  uint16_t pulseWidth = map(angle, 0, 180, 500, 2500);
  // Note that the softPWM frequency is 60hz, so the period is: 1/60 = 16666 us 
  uint16_t value = map(pulseWidth, 0, 16666, 0, 255); 
  SoftPWMSet(this->pin, value);
}

