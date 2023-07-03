#include "ultrasonic.h"
#include <Arduino.h>

float ultrasonicRead() {
  delay(4); // A delay is required between consecutive readings, otherwise the reading may be 0

  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);

  // noInterrupts(); // Pause all interruptions to avoid affecting data
                  // However，turning off interrupts affects the functionality of softpwm, such as motors

  // float duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  // it will return 0 while timeout
  float duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH, ULTRASONIC_READ_TIMEOUT);
 
  // interrupts(); // resume interruptions
 
  float distance = duration  * 0.017; // S = vt = 340m/s * (t/2)us= (340 * 100 cm/s) * 0.5 * (t / 10^6)s = 0.017 * t
  

  if (distance > MAX_DISTANCE || distance == 0) {
    return -1;
  } 
  return distance;
}

bool ultrasonicIsObstacle() {
  return ultrasonicRead() < ULTRASONIC_AVOIDANCE_THRESHOLD;
}

bool ultrasonicIsClear() {
  float distance = ultrasonicRead();
  if (distance > ULTRASONIC_AVOIDANCE_THRESHOLD || distance < 0) {
    return true;
  } else {
    return false;
  }
}

