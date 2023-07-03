#include "rgb.h"

#if defined(ARDUINO_AVR_UNO)
#include <SoftPWM.h>
#endif

void rgbBegin() {
  #if defined(ARDUINO_AVR_UNO)
  for (uint8_t i = 0; i < 3; i++) {
    SoftPWMSet(RGB_PINS[i], 0);
    SoftPWMSetFadeTime(RGB_PINS[i], 100, 100);
  }
  #endif
}

void rgbWrite(uint32_t color) {
  uint8_t r = (color >> 16) & 0xFF;
  uint8_t g = (color >>  8) & 0xFF;
  uint8_t b = (color >>  0) & 0xFF;
  rgbWrite(r, g, b);
}

void rgbWrite(uint8_t r, uint8_t g, uint8_t b) {
  // calibrate brightness
  r = int(r * R_OFFSET);
  g = int(g * G_OFFSET);
  b = int(b * B_OFFSET);
  // COMMON_ANODE reverse
  #if COMMON_ANODE
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
  #endif
  // set volatge 
  #if defined(ARDUINO_AVR_UNO)
  SoftPWMSet(RGB_PINS[0], r);
  SoftPWMSet(RGB_PINS[1], g);
  SoftPWMSet(RGB_PINS[2], b);
  #elif defined(ARDUINO_MINIMA)
  analogWrite(RGB_PINS[0], r);
  analogWrite(RGB_PINS[1], g);
  analogWrite(RGB_PINS[2], b);
  #endif
}

void rgbOff() {
  rgbWrite(0, 0, 0);
}

