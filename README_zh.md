# GalaxyRVR

GalaxyRVR 机器人小车的 Arduino UNO 控制固件，配合 SunFounder Controller APP 使用。

当前版本：**2.0.0**

- [开发环境](#开发环境)
- [快速开始](#快速开始)
- [项目结构](#项目结构)
- [烧录固件](#烧录固件)
- [文档](#文档)
- [关于 SunFounder](#关于-sunfounder)

## 开发环境

| 项目 | 版本 |
|------|------|
| Board | Arduino UNO |
| IDE | Arduino IDE 2.x |
| AVR Boards | 1.8.3 |

依赖库：

- IRLremote
- SoftPWM
- Servo
- ArduinoJson
- SunFounder_AI_Camera

## 快速开始

1. 用 Arduino IDE 打开 `galaxy-rvr/galaxy-rvr.ino`
2. 选择 Board: Arduino UNO，选择正确端口
3. 编译并上传
4. 手机安装 SunFounder Controller APP，连接 WiFi `GalaxyRVR`（密码 `12345678`）

## 项目结构

```
galaxy-rvr/
├── galaxy-rvr/                   # 主固件代码
│   ├── galaxy-rvr.ino            # 主程序入口（setup/loop/状态机/WS 消息处理）
│   ├── galaxy-rvr.h              # 集中配置（引脚、常量、库引用）
│   ├── cmd_code_config.hpp       # 模式定义、语音指令表
│   ├── car_control.cpp/h         # 电机驱动
│   ├── rgb.cpp/h                 # RGB LED 灯带
│   ├── ir_obstacle.cpp/h         # 红外避障传感器
│   ├── ultrasonic.cpp/h          # 超声波测距
│   ├── soft_servo.cpp/h          # 软件 PWM 舵机（摄像头云台）
│   ├── battery.h                 # 电池电压/电量检测
│   └── test.h                    # 各模块测试函数
├── lesson_codes/                 # 教程示例代码（按章节排列）
│   ├── 5_car_move/               # 小车移动
│   ├── 6_read_ir/                # 红外传感器读取
│   ├── 6_ir_avoid/               # 红外避障
│   ├── 7_read_ultrasonic/        # 超声波读取
│   ├── 7_ultrasonic_avoid/       # 超声波避障
│   ├── 8_ultrasonic_ir_avoid/    # 超声波+红外联合避障
│   ├── 8_ultrasonic_ir_follow/   # 超声波+红外跟随
│   ├── 9_rgb_*/                  # RGB LED 控制
│   ├── 10_servo*/                # 舵机控制
│   ├── 11_camera_*/              # 摄像头控制
│   ├── 12_app_*/                 # APP 交互
│   └── 13_*battery*/             # 电池检测
├── test/
│   └── electric-test/            # 出厂电气测试
├── ai-camera-firmware.v1.5.3-ota.bin  # ESP32-CAM 固件
├── update-arduino-firmware.bat    # 一键烧录脚本（Windows）
├── LICENSE
└── Readme.md
```

## 烧录固件

### 方式一：一键脚本（Windows）

```bat
update-arduino-firmware.bat
```

脚本自动调用 `avrdude` 烧录 `galaxy-rvr.ino.2.0.0.hex`。

### 方式二：Arduino IDE

打开 `galaxy-rvr/galaxy-rvr.ino`，编译并上传。

### ESP32-CAM 固件

AI Camera 模块需烧录专用固件，源码及说明见 [ai-camera-firmware](https://github.com/sunfounder/ai-camera-firmware)。

## 文档

https://docs.sunfounder.com/projects/galaxy-rvr/en/latest/

## 关于 SunFounder

SunFounder 专注于 STEAM 教育，提供开源机器人、开发板、套件、模块等产品，帮助中小学生及爱好者通过动手实践学习编程与工程知识。

网站：[www.sunfounder.com](https://www.sunfounder.com)

联系：[service@sunfounder.com](mailto:service@sunfounder.com)
