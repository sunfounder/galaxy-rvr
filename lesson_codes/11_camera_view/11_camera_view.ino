#include "SunFounder_AI_Camera.h"

// Wifi configuration and credentials
// AP Mode
// #define WIFI_MODE WIFI_MODE_AP
// #define SSID "GalaxyRVR"
// #define PASSWORD "12345678"

// STA Mode
#define WIFI_MODE WIFI_MODE_STA
#define SSID "YOUR SSID"
#define PASSWORD "YOUR PASSWORD"

// Device configuration
#define NAME "GalaxyRVR"  // Device name
#define TYPE "AiCamera"   // Device type
#define PORT "8765"       // Port for the SunFounder Controller APP

// Create AiCamera Object
AiCamera aiCam = AiCamera(NAME, TYPE);

void setup() {
  // Initialize Serial(optional, if you need to debug)
  Serial.begin(115200);

  // Initialize AiCamera
  aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT);

  // Set command timeout (optional, default 100)
  aiCam.setCommandTimeout(100);
}

void loop() {
  // AiCamera loop. must put it in loop(). And more importantly, every time loop
  // runs, a perioad of data send receive runs, so loop must be fast enough.
  // or it will be laggy or even stuck by other code.
  aiCam.loop();
}