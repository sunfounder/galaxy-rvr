#include <SoftPWM.h>

// Define the motor pins
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;

void setup() {
  // Initialize SoftPWM
  SoftPWMBegin();
}

void loop() {
  // Set all motors to rotate clockwise
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, 255);
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, 255);

  delay(2000);  // Last for 2 seconds

  // Stop all motors
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, 0);
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, 0);

  delay(5000);  // Pause for 5 seconds
}

