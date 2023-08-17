#include <SoftPWM.h>  // Include the SoftPWM library

// Define the pin numbers for the RGB strips
const int bluePin = 11;
const int redPin = 12;
const int greenPin = 13;

// Define the pins of motors
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;

/* Calibrate brightness */
#define R_OFFSET 1.0
#define G_OFFSET 0.25
#define B_OFFSET 0.45

int intensity = 0;
int direction = 1;
bool isStopped = false;

void setup() {
  SoftPWMBegin();  // Initialize software-based PWM on all pins
}

void loop() {
  moveForward(255);  // Move the Rover forward
  delay(2000);

  moveBackward(255);  // Move the Rover backward
  delay(2000);

  turnLeft(200);  // Turn the Rover to the left
  delay(2000);

  turnRight(200);  // Turn the Rover to the right
  delay(2000);

  stopMove();  // Stop the Rover
}

// Define a function to set color
void setColor(int red, int green, int blue) {
  SoftPWMSet(redPin, red * R_OFFSET);      // Set red color
  SoftPWMSet(greenPin, green * G_OFFSET);  // Set green color
  SoftPWMSet(bluePin, blue * B_OFFSET);    // Set blue color
}

void moveForward(int speed) {
  // Set the left motors rotate counterclockwise
  SoftPWMSet(in1, speed);
  SoftPWMSet(in2, 0);

  // Set the right motors rotate clockwise
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, speed);

  setColor(0, 255, 0);  // Green
}

void moveBackward(int speed) {
  // Set the left motors rotate clockwise
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, speed);

  // Set the right motors rotate counterclockwise
  SoftPWMSet(in3, speed);
  SoftPWMSet(in4, 0);
  setColor(255, 0, 0);  // Red
}

void turnLeft(int speed) {
  // Set al motors to rotate clockwise
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, speed);
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, speed);

  setColor(255, 255, 0);  // Yellow
}

void turnRight(int speed) {
  // Set all motors to rotate counterclockwise
  SoftPWMSet(in1, speed);
  SoftPWMSet(in2, 0);
  SoftPWMSet(in3, speed);
  SoftPWMSet(in4, 0);

  setColor(255, 255, 0);  // Yellow
}

void stopMove() {
  // Stop all the motors
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, 0);
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, 0);
  for (int a = 0; a < 3; a++) {
    for (int i = 0; i < 255; i++) 
    {
      setColor(i, 0, 255-i);
      delay(10);
    }
    for (int i = 255; i > 0; i--) {
      setColor(i, 0, 255-i);
      delay(10);
    }
  }
}

