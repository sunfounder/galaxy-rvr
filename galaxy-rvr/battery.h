#ifndef __BATTERY_H__
#define __BATTERY_H__

#include <Arduino.h>

#define BATTERY_PIN A3
#define ANALOG_REFERENCE_VOLTAGE 5.246


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
  float adcVoltage = float(adcValue) / 1024.0 * ANALOG_REFERENCE_VOLTAGE;
  float batteryVoltage = adcVoltage * 2; // Battery voltage = ADC value * 2
  batteryVoltage = int(batteryVoltage*100)/100.0; // round two decimal places
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