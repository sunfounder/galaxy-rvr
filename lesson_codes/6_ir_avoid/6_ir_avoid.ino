#include <SoftPWM.h>

// Define the pins of motors
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;

// Define the pins for the IR modules
#define IR_RIGHT 7
#define IR_LEFT 8


void setup() {

  // Initialize SoftPWM
  SoftPWMBegin();

  // Set the IR module pins as inputs
  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_LEFT, INPUT);
}

void loop() {
  // Read values from IR sensors
  int rightValue = digitalRead(IR_RIGHT);
  int leftValue = digitalRead(IR_LEFT);

  // Based on IR sensor readings, control rover's movements
  if (rightValue == 0 && leftValue == 1) {  // Right path blocked
    backRight(150);
  } else if (rightValue == 1 && leftValue == 0) {  // Left path blocked
    backLeft(150);
  } else if (rightValue == 0 && leftValue == 0) {  // Both paths blocked
    moveBackward(150);
  } else {  // Paths clear
    moveForward(150);
  }

  delay(100);
}

// Function to move the rover backward
void moveBackward(int speed) {
  // Set the left motors to rotate clockwise
  SoftPWMSet(in1, 0);      // Stop
  SoftPWMSet(in2, speed);  // Full speed

  // Set the right motors to rotate counterclockwise
  SoftPWMSet(in3, speed);  // Full speed
  SoftPWMSet(in4, 0);      // Stop
}

void moveForward(int speed) {
  // Set the left motors rotate counterclockwise
  SoftPWMSet(in1, speed);
  SoftPWMSet(in2, 0);

  // Set the right motors rotate clockwise
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, speed);
}

// Function to turn to the back right
void backRight(int speed) {
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, speed);
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, 0);
}

// Function to turn to the back left
void backLeft(int speed) {
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, 0);
  SoftPWMSet(in3, speed);
  SoftPWMSet(in4, 0);
}
