#include "SunFounder_AI_Camera.h"
#include <Servo.h>
#include <SoftPWM.h>

// Create a Servo object
Servo myServo;

// Wifi configuration and credentials
// In AP Mode
#define WIFI_MODE WIFI_MODE_AP
#define SSID "GalaxyRVR"
#define PASSWORD "12345678"

// Device configuration
#define NAME "GalaxyRVR"  // Device name
#define TYPE "AiCamera"   // Device type
#define PORT "8765"       // Port for the SunFounder Controller APP

// Create an AiCamera object
AiCamera aiCam = AiCamera(NAME, TYPE);

// Define the pin for the ultrasonic module
#define ULTRASONIC_PIN 10

// Define the pins for the IR modules
#define IR_RIGHT 7
#define IR_LEFT 8

// This pin reads the voltage of the battery
#define BATTERY_PIN A3

// Define the pins of motors
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;

void setup() {
  // Initialize Serial for debugging
  Serial.begin(115200);

  // Attach the servo on pin 6
  myServo.attach(6);

  // Initialize the AiCamera
  aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT);
  // Set the function to execute when data is received
  aiCam.setOnReceived(onReceive);
  // Set the command timeout
  aiCam.setCommandTimeout(100);

  // Initialize SoftPWM
  SoftPWMBegin();

  // Stop all the motors
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, 0);
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, 0);

  // Set the IR module pins as inputs
  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_LEFT, INPUT);

  // Sets the battery pin as an input
  pinMode(BATTERY_PIN, INPUT);
}

void loop() {
  // Must include this in the loop.
  //Handles data sending and receiving from the Controller.
  aiCam.loop();
}

// Function to execute when data is received from the Controller
void onReceive() {
  // Get the value of the slider in region D
  int16_t sliderD = aiCam.getSlider(REGION_D);

  // Move the servo to the angle indicated by the slider
  myServo.write(int(sliderD));

  // Get the throttle values for the left and right
  int throttle_L = aiCam.getThrottle(REGION_K);
  int throttle_R = aiCam.getThrottle(REGION_Q);

  // Set the power for the motors
  carSetMotors(throttle_L, throttle_R);

  // Read values from IR sensors
  int leftValue = digitalRead(IR_LEFT);
  int rightValue = digitalRead(IR_RIGHT);
  aiCam.sendDoc["N"] = leftValue;
  aiCam.sendDoc["P"] = rightValue;

  // ultrasonic
  float distance = readSensorData();
  aiCam.sendDoc["O"] = distance;

  //show battery voltage
  aiCam.sendDoc["BV"] = batteryGetVoltage();
}

// Function to set the power of the motors
void carSetMotors(int8_t power_L, int8_t power_R) {
  // Set power for the left motor
  if (power_L >= 0) {
    SoftPWMSet(in1, map(power_L, 0, 100, 0, 255));
    SoftPWMSet(in2, 0);
  } else {
    SoftPWMSet(in1, 0);
    SoftPWMSet(in2, map(power_L, 0, -100, 0, 255));
  }

  // Set power for the right motor
  if (power_R >= 0) {
    SoftPWMSet(in3, 0);
    SoftPWMSet(in4, map(power_R, 0, 100, 0, 255));
  } else {
    SoftPWMSet(in3, map(power_R, 0, -100, 0, 255));
    SoftPWMSet(in4, 0);
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

  // Calculate the distance (in cm) based on the speed of sound
  //(340 m/s or 0.034 cm/us)
  float distance = duration * 0.034 / 2;

  return distance;
}

// This function reads the battery voltage
float batteryGetVoltage() {
  // Reads the analog value from the battery pin
  int adcValue = analogRead(BATTERY_PIN);
  // Converts the analog value to voltage
  float adcVoltage = adcValue / 1023.0 * 5 * 2;
  // Rounds the voltage to two decimal places
  float batteryVoltage = int(adcVoltage * 100) / 100.0;
  return batteryVoltage;
}