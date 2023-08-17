#include <SoftPWM.h> // Include the SoftPWM library

// Define the pin numbers for the RGB strips
const int bluePin = 11;
const int redPin = 12;
const int greenPin = 13;

void setup() {
  SoftPWMBegin(); // Initialize software-based PWM on all pins
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
  SoftPWMSet(redPin, red); // Set red component of color
  SoftPWMSet(greenPin, green); // Set green component of color
  SoftPWMSet(bluePin, blue); // Set blue component of color
}
