#include <Servo.h>

Servo myServo;  // create a servo object

void setup() {
  myServo.attach(6);  // attaches the servo on pin 6
}

void loop() {
  myServo.write(45);  // tell servo to go to 45 degrees
}