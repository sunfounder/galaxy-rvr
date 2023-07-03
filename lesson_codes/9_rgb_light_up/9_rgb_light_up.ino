#include <SoftPWM.h>

// Define the pin numbers for the RGB strips
const int bluePin = 11;
const int redPin = 12;
const int greenPin = 13;

void setup() {
  // Initialize software-based PWM on all pins
  SoftPWMBegin();
}

void loop() {
  // Set the color to red by turning the red LED on and the others off
  SoftPWMSet(redPin, 255); // 255 is the maximum brightness
  SoftPWMSet(greenPin, 0); // 0 is off
  SoftPWMSet(bluePin, 0);  // 0 is off
  delay(1000); // Wait for 1 second
}
