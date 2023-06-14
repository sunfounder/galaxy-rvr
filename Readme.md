# GalaxyRVR
The control program of the GalaxyRVR for Ardunio UNO.

- [GalaxyRVR](#galaxyrvr)
  - [Development test environment](#development-test-environment)
  - [Dependency libraries](#dependency-libraries)
  - [ESP32-CAM firmware](#esp32-cam-firmware)
  - [Docs](#docs)
  - [Project Tree](#project-tree)
  - [About SunFounder](#about-sunfounder)
  - [Contact us](#contact-us)
## Development test environment
- Board: Ardunio UNO
- IDE: Arduino IDE 1.8.19
- Compiler Tools: Arduino AVR Boards 1.8.3

## Dependency libraries
- IRLremote
- SoftPWM
- Servo
- ArduinoJson
- SunFounder_AI_Camera

## ESP32-CAM firmware
https://github.com/sunfounder/ai-camera-firmware
## Docs
https://docs.sunfounder.com

## Project Tree
```
galaxy-rvr                  
├─ galaxy-rvr               
│  ├─ ai_camera.cpp         // functions for communicating with ESP32-CAM
│  ├─ ai_camera.h           
│  ├─ battery.h             // functions for getting the battery status
│  ├─ car_control.cpp       // functions for controll motors 
│  ├─ car_control.h         
│  ├─ cmd_code_config.hpp   // the command table for voice control, and the 
│  ├─ galaxy-rvr.ino        // Arduino main program
│  ├─ ir_obstacle.cpp       // functions for IR obstacle avoidance module
│  ├─ ir_obstacle.h         
│  ├─ rgb.cpp               // functions for rgb led strip
│  ├─ rgb.h                 
│  ├─ test.h                
│  ├─ ultrasonic.cpp        // functions for ultrasonic module
│  └─ ultrasonic.h          
├─ test                     
│  └─ electric-test         
│     └─ electric-test.ino  // modules test
├─ LICENSE                  
└─ Readme.md                

```
## About SunFounder
SunFounder is a company focused on STEAM education with products like open source robots, development boards, STEAM kit, modules, tools and other smart devices distributed globally. In SunFounder, we strive to help elementary and middle school students as well as hobbyists, through STEAM education, strengthen their hands-on practices and problem-solving abilities. In this way, we hope to disseminate knowledge and provide skill training in a full-of-joy way, thus fostering your interest in programming and making, and exposing you to a fascinating world of science and engineering. To embrace the future of artificial intelligence, it is urgent and meaningful to learn abundant STEAM knowledge.

## Contact us
website:
    www.sunfounder.com

E-mail:
    service@sunfounder.com