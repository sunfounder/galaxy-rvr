#ifndef __BATTERY_H__
#define __BATTERY_H__

#include <Arduino.h>

#define BATTERY_PIN A3

/**
 * @brief init battery module
 * 
 */
void batteryBegin() {
  pinMode(BATTERY_PIN, INPUT);
}

/**
 * @brief Returns the voltage of the battery
 * 
 * @return float 
 */
float batteryGetVoltage() {
  int adcValue = analogRead(BATTERY_PIN);
  // int adcVoltage = map(adcValue, 0, 1023, 0, 5000);
  // float batteryVoltage = adcVoltage * 2 / 1000.0;
  float adcVoltage = adcValue / 1024.0*5*2;
  float batteryVoltage = int(vol*100)/100.0 // round two decimal places
  return batteryVoltage;
}

/**
 * @brief Returns the percentage of the battery
 * 
 * @return uint8_t
 */
uint8_t batteryGetPercentage() {
  float voltage = batteryGetVoltage();
  uint8_t percentage = map(voltage, 6.6, 8.4, 0, 100);
  return percentage;
}

#endif // __BATTERY_H__