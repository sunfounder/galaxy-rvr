通过 Arduino 快速开始
===============================

在本章中，您将学习如何 **快速打开并运行特定的 Arduino 示例代码** ，让您的 GalaxyRVR 执行各种动作。

如果您想了解这些示例背后的代码逻辑和编程原理，请参阅 :ref:`programming_arduino` 章节。

如何快速打开 Arduino 示例
-----------------------------------------

在此示例中，我们将演示如何使用 Arduino IDE 打开一个 Arduino 示例。

#. 启动 GalaxyRVR。

   * 首次使用 GalaxyRVR 时，建议通过插入 Type-C USB 线将电池充满电。然后打开电源。

     .. raw:: html

          <video width="600" loop autoplay muted>
              <source src="../_static/video/play_start.mp4" type="video/mp4">
              您的浏览器不支持此视频标签。
          </video>

    * ESP32-CAM 和 Arduino 板共用相同的 RX（接收）和 TX（发送）引脚。因此，在上传代码之前，您需要先将此开关滑到右侧以释放 ESP32-CAM，避免任何冲突或潜在问题。

      .. image:: ../img/camera_upload.png
         :width: 600

#. 使用 USB 线将 Arduino 板连接到计算机。

#. 访问 |link_download_arduino| 并下载适用于您操作系统的 Arduino IDE。按照安装提示完成设置。

   .. image:: img/arduino_download_page.png

#. 从以下链接下载示例代码：

   * |download_galaxyrvr_code|

#. 解压下载的文件，进入 ``galaxy-rvr-1.2.x\lesson_codes`` 目录。

   .. image:: img/arduino_open_folder.png

#. 选择一个示例代码文件夹，进入该文件夹，然后双击 ``.ino`` 文件在 Arduino IDE 中打开。

   .. image:: img/arduino_open_file.png

#. 在 Arduino IDE 中，选择 **Arduino Uno** 作为板型，并为您的设备选择正确的 **端口**。

   .. image:: img/arduino_choose_board.png

#. 点击 **Upload** 按钮（右箭头）将代码上传到您的板。

   .. image:: img/arduino_upload.png

.. note::

    如果您不熟悉 Arduino IDE，请参阅：

    * :ref:`install_arduino_ide`
    * :ref:`upload_sketch`

示例
------------

* ``5_car_move``：火星车前进、后退、左转和右转，最后停止。
* ``6_ir_avoid``：火星车使用红外传感器避障。
* ``7_ultrasonic_avoid``：火星车使用超声波模块避障。
* ``8_ultrasonic_ir_avoid``：火星车同时使用红外和超声波模块检测障碍物。
* ``8_ultrasonic_ir_follow``：火星车使用红外和超声波模块跟随物体。
* ``9_rgb_car_move``：为移动添加颜色指示：绿色表示前进，红色表示后退，黄色表示左转或右转。
* ``10_servo_range``：摄像头云台使用 for 循环从 0° 旋转到 180°，当前角度显示在串口监视器中。
* ``11_camera_view``：在网页浏览器中查看火星车摄像头的实时视频画面。需要 **SunFounder AI Camera** 库。
* ``13_read_battery``：通过代码监控电池电压。
