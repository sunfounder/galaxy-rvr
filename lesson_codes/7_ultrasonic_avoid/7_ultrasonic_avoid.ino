#include <SoftPWM.h>

// Define the pin for the ultrasonic module
#define ULTRASONIC_PIN 10


// Define the pins of motors
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;


void setup() {
  // Initialize SoftPWM
  SoftPWMBegin();
  //Serial.begin(9600);
}

void loop() {

  // Read distance from ultrasonic sensor
  float distance = readSensorData();
  //Serial.println(distance);  // Output distance for debugging

  // Control rover based on distance reading
  if (distance > 50) {  // If it's safe to move forward
    moveForward(200);
  } else if (distance < 15 && distance > 1) {  // If there's an obstacle close
    moveBackward(200);
    delay(500);  // Wait for a while before attempting to turn
    backLeft(150);
    delay(1000);
  } else {  // For distances in between, proceed with caution
    moveForward(150);
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
  // Set the left motors to rotate clockwise
  SoftPWMSet(in1, 0);      // Stop
  SoftPWMSet(in2, speed);  // Full speed

  // Set the right motors to rotate counterclockwise
  SoftPWMSet(in3, speed);  // Full speed
  SoftPWMSet(in4, 0);      // Stop
}

// Function to turn to the back left
void backLeft(int speed) {
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, 0);
  SoftPWMSet(in3, speed);
  SoftPWMSet(in4, 0);
}
