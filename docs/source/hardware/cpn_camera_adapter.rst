.. note:: 

    你好，欢迎加入 SunFounder 树莓派、Arduino 和 ESP32 爱好者社区！与其他爱好者一起，深入探索树莓派、Arduino 和 ESP32。

    **为什么加入？**

    - **专家支持**：通过社区和团队的帮助解决售后问题和技术挑战。
    - **学习与分享**：交换技巧和教程，提升你的技能。
    - **独家预览**：提前体验新产品发布和独家内容。
    - **专属折扣**：享受最新产品的专属优惠。
    - **节庆促销与赠品**：参与节日促销和赠品活动。

    👉 准备好与我们一起探索和创造了吗？点击 [|link_sf_facebook|] 即刻加入！


相机适配板
========================

.. image:: img/cam_adapter_board.jpg
    :width: 500
    :align: center

* **RST**：用于重置 ESP32-CAM。
* **SCL**：QMC6310 的串行数据引脚。
* **SDA**：QMC6310 的串行时钟引脚。
* **RXD**：ESP32-CAM 的 RXD 引脚，通过这两个串行引脚 RXD 和 TXD，你可以上传代码到 ESP32-CAM。
* **TXD**：ESP32-CAM 的 TXD 引脚。
* **5V**：5V DC 电源输入。
* **GND**：接地输入。

如其名称所示，Camera Adapter Board 是一款为 ESP-32 CAM 设计的扩展板，用于将 ESP32-CAM 固定到机器人上，且便于接线。

.. image:: img/cam_adapter_esp32cam.png
    :width: 400
    :align: center

由于地磁传感器 QMC6310 容易受到电机干扰，我们将其放置在此摄像头适配器板上，以最大限度地远离电机。

.. image:: img/cam_adapter_qmc6310.png
    :width: 400
    :align: center

**特点**

* 工作电压：5V
* 接口类型：ZH1.5，7P
* 尺寸：40mm x 27mm x 15mm
* 通信协议：UART 和 I2C

**文档**

* PCB

.. image:: img/cam_adap_pcb_bottom.png
    :width: 300

.. image:: img/cam_adap_pcb_top.png
    :width: 300

* 原理图

.. image:: img/cam_adapter_sche.png

**关于 QMC6310**

QMC6310 是一款三轴磁传感器，将磁传感器和信号调理 ASIC 集成到一颗硅芯片中。该 Land Grid Array (LGA) 封装适用于电子罗盘、地图旋转、游戏以及移动和可穿戴设备中的个人导航应用。

QMC6310 基于先进的高分辨率磁阻技术，并结合定制设计的 16 位 ADC ASIC，具有低噪声、高精度、低功耗、偏移校正和温度补偿等优点。QMC6310 提供 1° 到 2° 的罗盘航向精度。I²C 串行总线使得接口连接更加简便。

QMC6310 采用 1.2x1.2x0.53mm³ 的表面贴装 8 针 LGA 封装。

* |link_qmc6310_datasheet|