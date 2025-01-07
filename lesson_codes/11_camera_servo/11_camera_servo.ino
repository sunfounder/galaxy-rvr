#include "SunFounder_AI_Camera.h"
#include <Servo.h>

Servo myServo;  // create a servo object

// Wifi configuration and credentials
// AP Mode
#define WIFI_MODE WIFI_MODE_AP
#define SSID "GalaxyRVR"
#define PASSWORD "12345678"

// STA Mode
// #define WIFI_MODE WIFI_MODE_STA
// #define SSID "xxxxxxxxxx"
// #define PASSWORD "xxxxxxxxxx"

// Device configuration
#define NAME "GalaxyRVR"  // Device name
#define TYPE "AiCamera"   // Device type
#define PORT "8765"       // Port for the SunFounder Controller APP

// Create AiCamera Object
AiCamera aiCam = AiCamera(NAME, TYPE);

void setup() {
  // Initialize Serial(optional, if you need to debug)
  Serial.begin(115200);

  // Attach the servo on pin 6
  myServo.attach(6);

  // Initialize the AiCamera
  aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT);
  // Set the function to execute when data is received
  aiCam.setOnReceived(onReceive);
  // Set the command timeout
  aiCam.setCommandTimeout(100);
}

void loop() {
  // AiCamera loop. must put it in loop(). And more importantly, every time loop
  // runs, a perioad of data send receive runs, so loop must be fast enough.
  // or it will be laggy or even stuck by other code.
  aiCam.loop();
}

// Function to execute when data is received from the Controller
void onReceive() {
  // Get the value of the slider in region D
  int16_t sliderD = aiCam.getSlider(REGION_D);
  Serial.print("Slider D: ");
  Serial.println(sliderD);
  myServo.write(int(sliderD));  // control the servo to move to the current angle
}
