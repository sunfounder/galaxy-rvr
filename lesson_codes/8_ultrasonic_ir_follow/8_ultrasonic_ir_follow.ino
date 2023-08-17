#include <SoftPWM.h>

// Define the pin for the ultrasonic module
#define ULTRASONIC_PIN 10

// Define the pins for the IR modules
#define IR_RIGHT 7
#define IR_LEFT 8

// Define the pins of motors
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;

void setup() {

  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize SoftPWM
  SoftPWMBegin();

  // Set the IR module pins as inputs
  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_LEFT, INPUT);
}

void loop() {

  float distance = readSensorData();

  // Read values from IR sensors
  int rightValue = digitalRead(IR_RIGHT);
  int leftValue = digitalRead(IR_LEFT);

  if (distance > 5 && distance < 30) {
    moveForward(150);
  }
  // Based on IR sensor readings, control rover's movements
  else if (rightValue == 0 && leftValue == 1) {  // Right ir module blocked
    turnRight(150);
  } 
  else if (rightValue == 1 && leftValue == 0) {  // Left ir module blocked
    turnLeft(150);
  } 
  else {  // Paths clear
    stopMove();
  }
}


float readSensorData() {
  // A 4ms delay is required, otherwise the reading may be 0
  delay(4);

  //Set to OUTPUT to send signal
  pinMode(ULTRASONIC_PIN, OUTPUT);

  // Clear the trigger pin
  digitalWrite(ULTRASONIC_PIN, LOW);
  delayMicroseconds(2);

  // Trigger the sensor by sending a high pulse for 10us
  digitalWrite(ULTRASONIC_PIN, HIGH);
  delayMicroseconds(10);

  // Set the trigger pin back to low
  digitalWrite(ULTRASONIC_PIN, LOW);

  //Set to INPUT to read
  pinMode(ULTRASONIC_PIN, INPUT);

  // pulseIn returns the duration of the pulse on the pin
  float duration = pulseIn(ULTRASONIC_PIN, HIGH);

  // Calculate the distance (in cm) based on the speed of sound (340 m/s or 0.034 cm/us)
  float distance = duration * 0.034 / 2;

  return distance;
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
