FAQ
==============

1. 无法连接到 GalaxyRVR？
-------------------------------------------------------------------------------------------------

如果您无法连接到 GalaxyRVR，请检查以下项目：

1. 检查火星车上的电池指示灯。如果两个 LED 都熄灭，说明电池电量不足。请使用 Type-C USB 线为火星车充电。
2. 将模式切换到 **Run** 并按下 **Reset** 按钮，重置 GalaxyRVR。
3. 确认您的移动设备已连接到 GalaxyRVR 热点。
4. 如果您已配置家庭 Wi-Fi 网络，请确保您的移动设备连接到 **同一** 家庭 Wi-Fi 网络。

.. _install_lib:

2. 编译错误：``SoftPWM.h`` 或 ``SunFounder_AI_Camera.h``：No such file or directory？
-------------------------------------------------------------------------------------------------
如果您看到"编译错误：``SoftPWM.h``：No such file or directory"提示，说明您尚未安装 SoftPWM 库。

请按图示安装所需的两个库：``SoftPWM`` 和 ``SunFounder AI Camera``。

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            您的浏览器不支持此视频标签。
        </video>

对于 ``SunFounder AI Camera`` 库，您需要选择 "INSTALL ALL" 以同时安装所需的 ``ArduinoJson`` 依赖。

    .. image:: img/faq_install_ai_camera.png

3. avrdude：stk500_getsync() attempt 10 of 10：not in sync：resp=0x6e？
-----------------------------------------------------------------------------
如果在正确选择了板和端口后，点击 **Upload** 按钮时仍然持续出现以下消息：

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00

此时，您需要确保 ESP32 CAM 已拔下。

ESP32-CAM 和 Arduino 板共用相同的 RX（接收）和 TX（发送）引脚。因此，在上传代码之前，您需要先断开 ESP32-CAM 的连接，以避免任何冲突或潜在问题。

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

代码成功上传后，如果您需要使用 ESP32 CAM，则需要将开关拨到左侧以启动 ESP32 CAM。

    .. image:: img/camera_run.png
        :width: 500
        :align: center

4. 如何更改 Wi-Fi 频道？
----------------------------------

2.4GHz Wi-Fi 频段的频道范围为 1 到 13。ESP32 支持频道 1 到 11。同一频道上的其他设备可能造成干扰，导致连接问题。为解决此问题，您可以尝试更改频道。默认情况下，频道设置为 1。选择新频道时，建议每次跳过 1-2 个频道。例如，如果当前频道为 1，请先尝试频道 3，如果信号仍然不佳，再继续尝试频道 5。


#. 打开 GalaxyRVR 电源。要激活 ESP32 CAM，请将模式开关拨到 **Run** 位置，然后按下 **reset** 按钮重启 R3 板。

     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset_green.mp4" type="video/mp4">
            您的浏览器不支持此视频标签。
        </video>

#. 将您的移动设备连接到 GalaxyRVR 的 WiFi 网络。

   * 网络名称（SSID）为 ``GalaxyRVR``，密码为 ``12345678``。
   * 如果看到提示"无互联网访问"，请选择 **"保持连接"** 选项。

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. 在移动设备上打开网页浏览器，访问地址 ``http://192.168.4.1``。这将进入 ESP32-CAM 固件更新门户。

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. 在 **AP** 页面下，选择一个不同的频道。

   * 默认频道为 1。选择新频道时，每次跳过 1-2 个频道（例如，从频道 1 到 3，如有需要再到 5）。

   .. image:: img/fap_ap_channel.jpg
        :width: 50%
        :align: center

#. 返回到 **Base** 页面，点击 **Reboot** 按钮重启 GalaxyRVR。GalaxyRVR 现在即可正常运行。

   .. image:: img/faq_firmware_reboot.png
        :width: 50%
        :align: center

5. 如何更新 ESP32 CAM 固件
-----------------------------------------

有关详细的分步说明，请参阅：:ref:`update_firmware`

6. 如何恢复 R3 固件
-----------------------------------------

GalaxyRVR 的 R3 板搭载了支持 RoboPilot App 和 Mammoth Coding 的固件。

如果您已覆盖此固件并需要恢复通信，请按照 :ref:`update_r3_firmware` 进行操作。

.. _ap_to_sta:

7. 如何设置 Wi-Fi 连接
-----------------------------------------------------

默认情况下，GalaxyRVR 以 **AP 模式** 运行，即创建自己的 Wi-Fi 热点供其他设备连接。

如果您希望 GalaxyRVR 连接到您的 **家庭 Wi-Fi 网络** ，请按照以下步骤操作：


#. 打开 GalaxyRVR 电源。要激活 ESP32 CAM，请将模式开关拨到 **Run** 位置，然后按下 **reset** 按钮重启 R3 板。

     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset_green.mp4" type="video/mp4">
            您的浏览器不支持此视频标签。
        </video>

#. 将您的移动设备连接到 GalaxyRVR 的 WiFi 网络。

   * 网络名称（SSID）为 ``GalaxyRVR``，密码为 ``12345678``。
   * 如果看到提示"无互联网访问"，请选择 **"保持连接"** 选项。

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. 在移动设备上打开网页浏览器，访问地址 ``http://192.168.4.1``。这将进入 ESP32-CAM 固件更新门户。

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. 在 **WiFi** 页面下，输入您的家庭 WiFi 网络名称（SSID）和密码。

   .. image:: img/faq_wifi.png
        :width: 50%
        :align: center

#. 点击 **CONFIRM** 按钮。

   * GalaxyRVR 将尝试连接到您的家庭 Wi-Fi。
   * 如果连接成功，旋转图标将停止并显示对勾标记。

#. 重启后，将您的移动设备连接到同一家庭 Wi-Fi 网络。

#. 您现在可以通过 RoboPilot App 或 Mammoth Coding 连接到 GalaxyRVR。
