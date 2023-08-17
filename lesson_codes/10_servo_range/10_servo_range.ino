#include <Servo.h>

Servo myServo;  // create a servo object

void setup() {
  myServo.attach(6);  // attaches the servo on pin 6
  Serial.begin(9600);  // initialize serial communication at a baud rate of 9600
}

void loop() {
  for (int i = 0; i <= 180; i++) {  // loop from 0 to 180 degrees
    Serial.print("The angle is: ");  // print angle information
    Serial.println(i);  // print the current angle value
    myServo.write(i);  // control the servo to move to the current angle
    delay(100);  // delay for 100 milliseconds
  }
}
