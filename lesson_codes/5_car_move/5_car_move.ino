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
  moveForward(200); // Move the Rover forward
  delay(1000);

  moveBackward(200);  // Move the Rover backward
  delay(1000);

  turnLeft(200); // Turn the Rover to the left
  delay(1000);

  turnRight(200); // Turn the Rover to the right
  delay(1000);

  stopMove(); // Stop the Rover
  delay(5000);
}

void moveForward(int speed) {
  // Set the left motors rotate counterclockwise
  SoftPWMSet(in1, speed);
  SoftPWMSet(in2, 0);

  // Set the right motors rotate clockwise
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, speed);
}

void moveBackward(int speed) {
  // Set the left motors rotate clockwise
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, speed);

  // Set the right motors rotate counterclockwise
  SoftPWMSet(in3, speed);
  SoftPWMSet(in4, 0);
}

void turnLeft(int speed) {
  // Set al motors to rotate clockwise
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, speed);
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, speed);
}

void turnRight(int speed) {
  // Set all motors to rotate counterclockwise
  SoftPWMSet(in1, speed);
  SoftPWMSet(in2, 0);
  SoftPWMSet(in3, speed);
  SoftPWMSet(in4, 0);
}

void stopMove() {
  // Stop all the motors
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, 0);
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, 0);
}
