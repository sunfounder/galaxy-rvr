.. note:: 

    你好，欢迎加入 SunFounder 树莓派、Arduino 和 ESP32 爱好者社区！与其他爱好者一起，深入探索树莓派、Arduino 和 ESP32。

    **为什么加入？**

    - **专家支持**：通过社区和团队的帮助解决售后问题和技术挑战。
    - **学习与分享**：交流技巧和教程，提升你的技能。
    - **独家预览**：提前体验新产品发布和独家内容。
    - **专属折扣**：享受最新产品的专属优惠。
    - **节庆促销与赠品**：参与节日促销和赠品活动。

    👉 准备好与我们一起探索和创造了吗？点击 [|link_sf_facebook|] 即刻加入！

FAQ
==============

.. _ap_to_sta:

Q1: 如何将 AP 模式切换为 STA 模式
-------------------------------------------------

* 你需要下载相关代码。

    * :download:`GalaxyRVR 代码 <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/main.zip>`

* 安装 IDE，并安装 ``SoftPWM`` 和 ``SunFounder AI Camera`` 库。参考 :ref:`install_lib` 。

* 然后，打开位于 ``galaxy-rvr-main\galaxy-rvr`` 目录中的 ``galaxy-rvr.ino`` 文件。

* 注释掉第 69 至 71 行，取消注释第 73 至 75 行，并将 ``SSID`` 和 ``PASSWORD`` 设置为你的 WLAN 信息。

.. image:: img/ap_sta.png
    :align: center

* 使用 USB 数据线连接 Arduino 和电脑，然后将车载的 **上传** 开关切换到上传端。

.. image:: img/camera_upload.png
    :width: 400
    :align: center

* 上传你的代码。

.. _install_lib:

Q2: 编译错误：SoftPWM.h: 没有那个文件或目录？
---------------------------------------------------------------------

如果你收到“编译错误：SoftPWM.h: 没有那个文件或目录”的提示，说明你尚未安装 SoftPWM 库。

请按照下面的步骤安装所需的两个库 ``SoftPWM`` 和 ``SunFounder AI Camera``。

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>


Q3: avrdude: stk500_getsync() 尝试 10 次失败：未同步：resp=0x6e?
-----------------------------------------------------------------------------

如果在正确选择了板子和端口后，点击 **上传** 按钮时仍然出现以下提示：

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00
    这时，你需要确保 ESP32 CAM 已被拔掉。

ESP32-CAM 和 Arduino 板共用 RX（接收）和 TX（发送）引脚。因此，在上传代码之前，你需要先断开 ESP32-CAM，以避免冲突或潜在问题。

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

代码上传成功后，如果需要使用 ESP32 CAM，请将开关切换到左侧以启动 ESP32 CAM。

    .. image:: img/camera_run.png
        :width: 500
        :align: center

.. _stt_android:

Q4: 如何在我的 Android 设备上使用 STT 模式？
------------------------------------------------------------------------

STT 模式要求 Android 移动设备连接互联网，并安装 Google 服务组件。

按照以下步骤进行操作：

#. 将 ``galaxy-rvr.ino`` 文件中的 AP 模式修改为 STA 模式。

    * 打开位于 ``galaxy-rvr-main\galaxy-rvr`` 目录中的 ``galaxy-rvr.ino`` 文件。
    * 注释掉与 AP 模式相关的代码，取消注释与 STA 模式相关的代码，并填写你家 Wi-Fi 的 ``SSID`` 和 ``PASSWORD``。

        .. code-block:: arduino

            /** 配置 Wi-Fi 模式、SSID、密码*/
            // #define WIFI_MODE WIFI_MODE_AP
            // #define SSID "GalaxyRVR"
            // #define PASSWORD "12345678"

            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "xxxxxxxxxx"
            #define PASSWORD "xxxxxxxxxx"

    * 保存代码，选择正确的板子（Arduino Uno）和端口，然后点击 **上传** 按钮将代码上传至 R3 板。

#. 在 Google Play 中搜索 ``google``，找到以下应用并安装。

    .. image:: img/google_voice.png
        :width: 500
        :align: center

#. 将你的移动设备连接到与代码中相同的 Wi-Fi 网络。

    .. image:: img/sta_wifi.png
        :width: 500
        :align: center

#. 打开之前在 SunFounder Controller 中创建的控制器，并通过 |app_connect| 按钮连接到 ``GalaxyRVR``。

    .. image:: img/app/camera_connect.png
        :width: 400
        :align: center

#. 在点击 |app_run| 按钮后，按住 **STT(J)** 小部件。出现提示信息表示正在听取。然后说出以下命令来控制车辆移动。

    .. image:: img/app/play_speech.png

    * ``stop``: 停止所有漫游车的运动。
    * ``forward``: 让漫游车向前移动。
    * ``backward``: 让漫游车向后移动。
    * ``left``: 让漫游车向左转。
    * ``right``: 让漫游车向右转。

Q5: 关于 ESP32 CAM 固件
---------------------------------------------------

这里是 ESP32 CAM 的固件链接：|link_ai_camera_firmware|



.. ↓ 这个固件仅适用于 SunFounder 控制器


.. Q6: 如何将新固件刷入 ESP32 CAM？
.. ----------------------------------------------------
.. 摄像头模块出厂时已预先刷入固件。不过，如果你遇到数据损坏的问题，可以使用 Arduino IDE 重新刷入新固件。操作步骤如下：

.. **1. 准备好编程器**

.. #. 首先，准备好编程器。

..     .. image:: img/esp32_cam_programmer.png
..         :width: 300
..         :align: center

.. #. 将 ESP32 CAM 插入编程器，然后将编程器连接到电脑。

..     .. image:: img/esp32_cam_usb.jpg
..         :width: 300
..         :align: center

.. **2. 安装 ESP32 板**

.. 要对 ESP32 微控制器进行编程，必须在 Arduino IDE 中安装 ESP32 板包。按照以下步骤操作：

.. #. 打开 **文件** 菜单，选择 **首选项**。

..     .. image:: img/install_esp321.png
..         :width: 500
..         :align: center

.. #. 在 **首选项** 窗口中，找到 **附加开发板管理器 URL** 字段，点击启用文本框。

..     .. image:: img/install_esp322.png
..         :width: 500
..         :align: center

.. #. 在 **附加开发板管理器 URL** 字段中添加以下 URL：https://espressif.github.io/arduino-esp32/package_esp32_index.json。该 URL 指向 ESP32 板的包索引文件。点击 **确定** 保存更改。

..     .. image:: img/install_esp323.png
..         :width: 500
..         :align: center

.. #. 在 **开发板管理器** 窗口中，搜索 **ESP32**，点击 **安装** 按钮开始安装。这将下载并安装 ESP32 板包。

..     .. image:: img/install_esp324.png
..         :align: center

.. **3. 安装库**

.. #. 从 **库管理器** 安装 ``WebSockets`` 库。

..     .. image:: img/esp32_cam_websockets.png
..         :width: 500
..         :align: center

.. #. 按照相同的步骤安装 ``ArduinoJson`` 库。

..     .. image:: img/esp32_cam_arduinojson.png
..         :width: 500
..         :align: center

.. **4. 下载并上传固件**

.. #. 下载固件文件。

..     * :download:`ai-camera-firmware <https://github.com/sunfounder/ai-camera-firmware/archive/refs/heads/main.zip>`

.. #. 解压下载的固件文件，并将解压后的文件夹从 ``ai-camera-firmware-main`` 重命名为 ``ai-camera-firmware``。

..     .. image:: img/esp32_cam_change_name.png
..         :align: center

.. #. 用 Arduino IDE 打开 ``ai-camera-firmware.ino`` 文件，这会自动打开相关的代码文件。

..     .. image:: img/esp32_cam_ino.png
..         :align: center

.. #. 选择 **开发板** -> **ESP32** -> **ESP32 Dev Module**。

..     .. image:: img/esp32_cam_board.png
..         :width: 500
..         :align: center

.. #. 选择正确的端口。

..     .. image:: img/esp32_cam_port.png
..         :width: 400
..         :align: center

.. #. 确保启用 **PSRAM** 并在 **分区方案** 中选择 **Huge APP**。

..     .. image:: img/esp32_cam_psram.png
..         :width: 400
..         :align: center

.. #. 最后，将固件上传到 ESP32 CAM。

..     .. image:: img/esp32_cam_upload.png
..         :width: 500
..         :align: center

.. #. 固件上传成功后，可以在以下链接找到更多信息：https://github.com/sunfounder/ai-camera-firmware.
