
FAQ
==============

1. 为什么要更新固件？
----------------------------------------------------------------------------------------

SunFounder 持续改进 GalaxyRVR 的固件，以提供更好的使用体验。我们建议在首次使用前更新固件，以确保一切运行顺畅。更新固件可确保：

* **Bug 修复**：解决已知问题，提高稳定性。
* **App 兼容性**：RoboPilot App 和 Mammoth Coding 需要最新固件才能正常工作。
* **新功能**：固件更新可能会添加新的功能和改进。
* **更佳性能**：优化 WiFi 连接、摄像头视频流和电机控制。

有关详细的分步说明，请参阅 :ref:`update_firmware` 。

.. note::
   如果您不想更新固件并希望继续使用当前配置，可以参考 `GalaxyRVR v1 文档 <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_ 。


2. 无法连接到 GalaxyRVR？
-------------------------------------------------------------------------------------------------

如果您无法连接到 GalaxyRVR，请检查以下项目：

1. **检查电池**：查看火星车上的电池指示灯。如果两个 LED 都熄灭，说明电池电量不足。请使用 Type-C USB 线为火星车充电。
2. **检查模式开关**：确保模式开关设置为 **Run** （而非 **Upload** ）。WiFi 热点仅在 Run 模式下工作。

   .. image:: img/camera_run.png
        :width: 500
        :align: center

3. **重置 R3 板**：切换到 Run 模式后，按下 R3 板上的 **Reset** 按钮。底部灯带应闪烁，表示启动成功。
4. **检查 WiFi 密码**：默认热点名称（SSID）为 ``GalaxyRVR`` ，密码为 ``12345678`` 。请确保正确输入密码。
5. **检查 ESP32 CAM**：确保 ESP32 CAM 正确插入其插槽。如果 ESP32 CAM LED 不亮，则摄像头模块可能未通电或已损坏。
6. **WiFi 干扰**：同一 WiFi 频道上的其他设备可能导致连接问题。如果您怀疑存在干扰，请尝试 :ref:`更改 WiFi 频道 <change_wifi_channel>` 。
7. **固件更新后**：如果您刚刚更新了 ESP32 CAM 固件且 WiFi 无法使用，请参阅 :ref:`faq_wifi_after_update` 。
8. **验证移动设备的连接**：如果您以 AP 模式（默认）使用 GalaxyRVR，请将移动设备连接到 GalaxyRVR 热点。如果您已 :ref:`配置家庭 Wi-Fi 网络 <ap_to_sta>` ，请确保您的移动设备连接到 **同一** 家庭 Wi-Fi 网络。


3. RoboPilot App 无法连接？
---------------------------------------------------------------------------------------

如果 RoboPilot App 无法找到或连接到您的 GalaxyRVR，请检查以下项目：

1. **R3 固件是否最新？** R3 板上必须安装出厂通信固件。如果您上传了自定义 Arduino 代码，它将覆盖此固件并中断 RoboPilot 通信。请按照 :ref:`update_r3_firmware` 进行恢复。
2. **ESP32 CAM 固件是否最新？** 过旧的 ESP32 CAM 固件可能导致连接问题。请按照 :ref:`update_esp32_firmware` 进行检查和更新。
3. **模式开关是否在 Run？** 模式开关必须设置为 **Run** （而非 Upload），WiFi 热点才能工作。
4. **您的移动设备是否连接到正确的 WiFi 网络？** 连接到 GalaxyRVR 热点（ ``GalaxyRVR`` / ``12345678`` ），或者如果您配置了家庭 WiFi，请连接到同一网络。
5. **尝试重置**：切换到 **Run** 模式并按下 **Reset** 按钮，然后重新尝试连接。

如果以上方法均无效，请尝试 :ref:`清除 ESP32 CAM 配置 <faq_wifi_after_update>` 。


4. Mammoth Coding (Scratch) App 无法连接？
---------------------------------------------------------------------------------------

如果 Mammoth Coding 无法连接到您的 GalaxyRVR，请检查以下项目：

1. **R3 固件是否最新？** Mammoth Coding 需要 R3 板上的出厂通信固件。如果您上传了自己的 Arduino 代码，通信固件已被覆盖。请按照 :ref:`update_r3_firmware` 进行恢复。
2. **ESP32 CAM 固件是否最新？** ESP32 CAM 负责处理 Mammoth Coding 所依赖的 WiFi 连接。请按照 :ref:`update_esp32_firmware` 确保其为最新版本。
3. **模式开关是否在 Run？** 模式开关必须设置为 **Run** ，WiFi 热点才能激活。
4. **您的移动设备是否连接到正确的 WiFi 网络？** 确保您的设备已连接到 GalaxyRVR 热点或火星车上配置的同一家庭 WiFi 网络。
5. **上传 Arduino 代码后**：请记住，上传任何 Arduino 草图到 R3 板都会覆盖通信固件。您需要 :ref:`恢复 R3 固件 <update_r3_firmware>` ，Mammoth Coding 才能重新连接。

.. note::
   如果您想 **同时** 使用 Arduino 编程和 Mammoth Coding，请注意每次切换时都需要重新上传 R3 固件。

.. _install_lib:

5. 编译错误：``SoftPWM.h`` 或 ``SunFounder_AI_Camera.h``：No such file or directory？
-------------------------------------------------------------------------------------------------
如果您看到"编译错误：``SoftPWM.h``：No such file or directory"提示，说明您尚未安装 SoftPWM 库。

请按图示安装所需的两个库：``SoftPWM`` 和 ``SunFounder AI Camera`` 。

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            您的浏览器不支持此视频标签。
        </video>

对于 ``SunFounder AI Camera`` 库，您需要选择 "INSTALL ALL" 以同时安装所需的 ``ArduinoJson`` 依赖。

    .. image:: img/faq_install_ai_camera.png

6. avrdude：stk500_getsync() attempt 10 of 10：not in sync：resp=0x6e？
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

.. _change_wifi_channel:

7. 如何更改 Wi-Fi 频道？
----------------------------------

2.4GHz Wi-Fi 频段的频道范围为 1 到 13。ESP32 支持频道 1 到 11。同一频道上的其他设备可能造成干扰，导致连接问题。为解决此问题，您可以尝试更改频道。默认情况下，频道设置为 1。选择新频道时，建议每次跳过 1-2 个频道。例如，如果当前频道为 1，请先尝试频道 3，如果信号仍然不佳，再继续尝试频道 5。


#. 打开 GalaxyRVR 电源。要激活 ESP32 CAM，请将模式开关拨到 **Run** 位置，然后按下 **reset** 按钮重启 R3 板。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/power_start.mp4" type="video/mp4">
            您的浏览器不支持此视频标签。
        </video>


#. 将您的移动设备连接到 GalaxyRVR 的 WiFi 网络。

   * 网络名称（SSID）为 ``GalaxyRVR`` ，密码为 ``12345678`` 。
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

8. 如何更新 ESP32 CAM 固件
-----------------------------------------

为确保 App 兼容性和最佳性能，请确保您的 ESP32 CAM 固件为最新版本。

有关详细的分步说明，请参阅：:ref:`update_esp32_firmware`

9. 如何恢复 R3 固件
-----------------------------------------

GalaxyRVR 的 R3 板搭载了支持 RoboPilot App 和 Mammoth Coding 的固件。

如果您已覆盖此固件并需要恢复通信，请按照 :ref:`update_r3_firmware` 进行操作。

.. _ap_to_sta:

10. 如何设置 Wi-Fi 连接
-----------------------------------------------------

默认情况下，GalaxyRVR 以 **AP 模式** 运行，即创建自己的 Wi-Fi 热点供其他设备连接。

如果您希望 GalaxyRVR 连接到您的 **家庭 Wi-Fi 网络** ，请按照以下步骤操作：


#. 打开 GalaxyRVR 电源。要激活 ESP32 CAM，请将模式开关拨到 **Run** 位置，然后按下 **reset** 按钮重启 R3 板。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/power_start.mp4" type="video/mp4">
            您的浏览器不支持此视频标签。
        </video>


#. 将您的移动设备连接到 GalaxyRVR 的 WiFi 网络。

   * 网络名称（SSID）为 ``GalaxyRVR`` ，密码为 ``12345678`` 。
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

.. _faq_wifi_after_update:

11. 如何将 ESP32 CAM 恢复出厂设置？
---------------------------------------------------------------------------------------

如果更新 ESP32 CAM 固件后 GalaxyRVR 的 WiFi 热点不出现或无法连接，可能是 ESP32 CAM 闪存中存储的旧 WiFi 配置数据导致冲突。

要解决此问题，您需要通过清除存储的数据将 ESP32 CAM 恢复出厂设置。此操作通过短接 ESP32 CAM 上的 **IO13** 和 **IO15** 引脚完成：

#. 关闭 GalaxyRVR 的电源开关。
#. 找到 ESP32 CAM 模块上的 **IO13** 和 **IO15** 引脚。

   .. image:: img/esp32cam_io1315.png
        :width: 300
        :align: center

#. 使用跳线或镊子短接（连接） **IO13** 和 **IO15** 引脚。
#. 保持引脚短接状态，打开 GalaxyRVR 的电源开关。
#. 观察 ESP32 CAM LED —— 当其 **快速闪烁两次** 时，移除跳线。

   .. image:: img/esp32cam_led.png
        :width: 300
        :align: center

#. 将模式切换到 **Run** 并按下 R3 板上的 **Reset** 按钮。
#. ESP32 CAM 现在将以清除配置后的状态启动。您应在设备的 WiFi 列表中看到一个名为 ``AI Camera-xxxxxx`` 的热点（其中 ``xxxxxx`` 是唯一标识符）。使用密码 ``12345678`` 连接。
#. 重启 GalaxyRVR 后，热点名称将从 ``AI Camera-xxxxxx`` 变回 ``GalaxyRVR-xxxxxx`` ，表示出厂设置已成功恢复。

.. note::
   恢复出厂设置后，您需要重新配置之前保存的家庭 WiFi 设置（ :ref:`ap_to_sta` ）。