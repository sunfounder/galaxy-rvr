#include <SoftPWM.h>

// Define the pins of motors 
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;

void setup() {
  // Initialize SoftPWM
  SoftPWMBegin();
}

void loop() {
  // Set the left motors rotate counterclockwise
  SoftPWMSet(in1, 255);  // Full speed
  SoftPWMSet(in2, 0);    // Stop

  // Set the right motors rotate clockwise
  SoftPWMSet(in3, 0);    // Stop
  SoftPWMSet(in4, 255);  // Full speed

}