#include <Arduino.h>

#define MOTOR_PIN_LEFT_A 5
#define MOTOR_PIN_LEFT_B 4
#define MOTOR_PIN_RIGHT_A 2
#define MOTOR_PIN_RIGHT_B 3
#define RGB_PIN_R 12
#define RGB_PIN_G 13
#define RGB_PIN_B 11
#define ULTRASONIC_PIN_TRIG 10
#define ULTRASONIC_PIN_ECHO 10

#define MAX_DISTANCE 2000 // unit: cm 

void setup() {
  Serial.begin(115200);
  Serial.println("Electric Test Begin...");
  delay(1000);

  Serial.println("Start Camera...");
  Serial.println("SET+START");
  delay(1000);

  pinMode(MOTOR_PIN_LEFT_A, OUTPUT);
  pinMode(MOTOR_PIN_LEFT_B, OUTPUT);
  pinMode(MOTOR_PIN_RIGHT_A, OUTPUT);
  pinMode(MOTOR_PIN_RIGHT_B, OUTPUT);
  digitalWrite(MOTOR_PIN_LEFT_A, LOW);
  digitalWrite(MOTOR_PIN_LEFT_B, LOW);
  digitalWrite(MOTOR_PIN_RIGHT_A, LOW);
  digitalWrite(MOTOR_PIN_RIGHT_B, LOW);

  pinMode(RGB_PIN_R, OUTPUT);
  pinMode(RGB_PIN_G, OUTPUT);
  pinMode(RGB_PIN_B, OUTPUT);
}

void motor_test() {
  if (millis() / 1000 % 2  < 1) {
    Serial.println("FORWARD");
    digitalWrite(MOTOR_PIN_LEFT_A, HIGH);
    digitalWrite(MOTOR_PIN_LEFT_B, LOW);
    digitalWrite(MOTOR_PIN_RIGHT_A, HIGH);
    digitalWrite(MOTOR_PIN_RIGHT_B, LOW);
  } else {
    Serial.println("BACKWARD");
    digitalWrite(MOTOR_PIN_LEFT_A, LOW);
    digitalWrite(MOTOR_PIN_LEFT_B, HIGH);
    digitalWrite(MOTOR_PIN_RIGHT_A, LOW);
    digitalWrite(MOTOR_PIN_RIGHT_B, HIGH);
  }
}

void rgb_test() {
  if (millis() / 1000 % 3 < 1) {
    Serial.println("RED");
    digitalWrite(RGB_PIN_R, HIGH);
    digitalWrite(RGB_PIN_G, LOW);
    digitalWrite(RGB_PIN_B, LOW);
  } else if (millis() / 1000 % 3 < 2) {
    Serial.println("GREEN");
    digitalWrite(RGB_PIN_R, LOW);
    digitalWrite(RGB_PIN_G, HIGH);
    digitalWrite(RGB_PIN_B, LOW);
  } else {
    Serial.println("BLUE");
    digitalWrite(RGB_PIN_R, LOW);
    digitalWrite(RGB_PIN_G, LOW);
    digitalWrite(RGB_PIN_B, HIGH);
  }
}

void ultasonic_test() {
  if (millis() / 1000 % 2 < 1) return;

  pinMode(ULTRASONIC_PIN_TRIG, OUTPUT);
  digitalWrite(ULTRASONIC_PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_PIN_TRIG, LOW);
  pinMode(ULTRASONIC_PIN_ECHO, INPUT);

  // noInterrupts(); // Pause all interruptions to avoid affecting data
                     // However，turning off interrupts affects the functionality of softpwm, such as motors

  float duration = pulseIn(ULTRASONIC_PIN_ECHO, HIGH);
  float distance = duration  * 0.017; // S = vt = 340m/s * (t/2)us= (340 * 100 cm/s) * 0.5 * (t / 10^6)s = 0.017 * t
  
  // interrupts(); // resume interruptions

  if (distance > MAX_DISTANCE) {
    Serial.println("Ultrasonic read: error");
  }

  Serial.print("Ultrasonic read:");Serial.println(distance);
  delay(200);
}

void loop() {
  // motor_test();
  rgb_test();
  // ultasonic_test();
}
