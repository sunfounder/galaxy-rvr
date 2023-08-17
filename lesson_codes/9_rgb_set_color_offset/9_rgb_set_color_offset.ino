#include <SoftPWM.h>  // Include the SoftPWM library

// Define the pin numbers for the RGB strips
const int bluePin = 11;
const int redPin = 12;
const int greenPin = 13;

/* Calibrate brightness */
#define R_OFFSET 1.0
#define G_OFFSET 0.25
#define B_OFFSET 0.45

void setup() {
  SoftPWMBegin();  // Initialize software-based PWM on all pins
}

void loop() {
  // Set different colors with a delay of 1 second (1000 ms) in between
  setColor(255, 0, 0);  // Set the color to red
  delay(1000);
  setColor(255, 128, 0);  // Set the color to orange
  delay(1000);
  setColor(255, 255, 0);  // Set the color to yellow
  delay(1000);
  setColor(0, 255, 0);  // Set the color to green
  delay(1000);
  setColor(0, 0, 255);  // Set the color to blue
  delay(1000);
  setColor(0, 255, 255);  // Set the color to lightblue
  delay(1000);
  setColor(255, 0, 255);  // Set the color to purple
  delay(1000);
  setColor(255, 255, 255);  // Set the color to white
  delay(1000);
}

// Define a function to set color
void setColor(int red, int green, int blue) {
  SoftPWMSet(redPin, red * R_OFFSET);      // Set red color
  SoftPWMSet(greenPin, green * G_OFFSET);  // Set green color
  SoftPWMSet(bluePin, blue * B_OFFSET);    // Set blue color
}