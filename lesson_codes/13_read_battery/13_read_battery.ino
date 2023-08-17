#define BATTERY_PIN A3  // This pin reads the voltage of the battery

// This function reads the battery voltage
float batteryGetVoltage() {
  // Reads the analog value from the battery pin
  int adcValue = analogRead(BATTERY_PIN);
  // Converts the analog value to voltage
  float adcVoltage = adcValue / 1023.0 * 5 * 2;
  // Rounds the voltage to two decimal places
  float batteryVoltage = int(adcVoltage * 100) / 100.0;
  return batteryVoltage;
}

// This function calculates the battery percentage based on its voltage
uint8_t batteryGetPercentage() {
  float voltage = batteryGetVoltage();  // Gets the battery voltage
  // Maps the voltage to a percentage.
  int16_t temp = map(voltage, 6.6, 8.4, 0, 100);
  // Ensures the percentage is between 0 and 100
  uint8_t percentage = max(min(temp, 100), 0);
  return percentage;
}

void setup() {
  Serial.begin(115200);
  pinMode(BATTERY_PIN, INPUT);  // Sets the battery pin as an input
}

void loop() {
  // Prints the calculated battery voltage
  Serial.print(" Voltage:");
  Serial.print(batteryGetVoltage());
  // Prints the calculated battery percentage
  Serial.print(" Percentage:");
  Serial.println(batteryGetPercentage());
  delay(1000);
}
