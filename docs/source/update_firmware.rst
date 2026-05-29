
.. _update_firmware:

更新固件
==========================

由于产品持续改进，您的设备可能未搭载最新固件。
为确保最佳稳定性能，请按照以下步骤检查并更新您的 ESP32 CAM 和 R3 板上的固件。

1. 检查是否需要更新
-------------------------------------

#. 首次使用 GalaxyRVR 前，请使用附带的 Type-C USB 线将电池充满电。充电完成后，打开电源。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_start.mp4" type="video/mp4">
            您的浏览器不支持此视频标签。
        </video>

#. 要启动 ESP32 CAM，请将模式切换到 **Run** 并按下 R3 板上的 **Reset** 按钮。底部灯带将开始闪烁，表示启动成功。

   .. note::

      * 如果底部灯带显示 **绿色闪烁灯光** ，则您的 ESP32 固件已是最新。
      * 您可以继续前往 :ref:`quick_start`。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset_green.mp4" type="video/mp4">
            您的浏览器不支持此视频标签。
        </video>

#. 如果底部灯带闪烁 **其他颜色** ，您将需要：

   * :ref:`update_esp32_firmware`
   * :ref:`update_r3_firmware`

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            您的浏览器不支持此视频标签。
        </video>


.. _update_esp32_firmware:

2. 更新 ESP32 CAM 固件
--------------------------------------

ESP32 CAM 负责广播 Wi-Fi 热点并为 GalaxyRVR 采集视频。
如果固件过旧，这些功能可能无法正常工作。请按照以下步骤更新固件。

#. 打开 GalaxyRVR 的电源开关。要启动 ESP32 CAM，请将模式切换到 **Run** 并按下 R3 板上的 **Reset** 按钮。

   .. image:: img/camera_run.png
        :width: 500
        :align: center

#. 下载固件文件。

   * |download_galaxyrvr_filmware|

#. 解压下载的 ZIP 文件。找到名为 ``ai-camera-firware.ino.x.x.x.bin`` 的固件文件，并将其传输到您的移动设备。您可以使用任何文件管理器应用，例如 ES 文件浏览器或文件传输工具。

   .. image:: img/firmware_bin_file.png
        :align: center

#. 将您的移动设备连接到 GalaxyRVR 的 WiFi 网络。

   * 网络名称（SSID）为 ``GalaxyRVR``，密码为 ``12345678``。
   * 如果看到提示"无互联网访问"，请选择 **"保持连接"** 选项。

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. 在移动设备上打开网页浏览器，访问 ``http://192.168.4.1`` 进入 ESP32 CAM OTA 更新页面。


.. note:: 在此页面上，您会看到两种界面之一的 OTA 升级选项。版本 A（前者）和版本 B（后者）会根据您的固件版本显示。请根据您看到的界面选择相应的升级步骤。

   .. image:: img/firmware_access_ab.png
      :width: 90%
      :align: center


**版本 A**

   6. 在 OTA 页面上，点击按钮选择固件文件。

      .. image:: img/faq_cam_ota_choose.png
         :width: 400

   #. 从设备中选择之前下载的 ``ai-camera-firmware-vX.X.X-ota.bin`` 文件，然后点击 **Add** 。

      .. image:: img/faq_cam_ota_file.png
         :width: 400

   #. 点击 **Update** 按钮开始固件更新过程。

      .. image:: img/faq_cam_ota_update.png
         :width: 400

   #. 等待更新完成。

      .. image:: img/faq_cam_ota_finish.png
         :width: 400

   #. 更新完成后，您可以关闭网页浏览器。按下 **Reset** 按钮重启设备。ESP32 CAM 现在即可正常运行。

      .. image:: img/camera_reset.png
         :width: 600

   .. note:: 更新完成后，GalaxyRVR 的 WiFi 热点名称将更改为 "AI Camera-xxxxxx"，密码仍为 "12345678"。


**版本 B**


   6. 在 **OTA** 页面上，查看网页上显示的当前固件版本。

      * 如果您的版本号 **高于 1.5.1** ，则无需更新。您可以跳过剩余步骤，直接前往 :ref:`quick_start`。
      * 如果版本为 **1.5.1 或更低** ，请继续更新。

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center


   #. 点击 **Upgrade Firmware** 按钮。

      .. image:: img/firmware_tap.jpg
         :width: 50%
         :align: center

   #. 将出现文件选择对话框。找到并选择您之前传输到移动设备的 ``ai-camera-firware.ino.x.x.x.bin`` 文件。

      .. image:: img/firmware_select.jpg
         :width: 50%
         :align: center

   #. 选择文件后，固件更新将立即开始。

      .. image:: img/firmware_upgrade.jpg
         :width: 50%
         :align: center

   #. 等待固件升级完成。

      * 上传过程通常需要 1-2 分钟。完成后，弹出窗口中将显示成功消息。
      * 您可以选择 **CONFIRM** 重启 GalaxyRVR 或选择 **CLOSE** 关闭窗口。

      .. image:: img/firmware_finish.jpg
         :width: 50%
         :align: center


.. _update_r3_firmware:

3. 更新 R3 板固件
--------------------------------------

R3 板包含内置固件，用于实现与 RoboPilot APP 和 Mammoth Coding 的通信。

在以下情况下，您需要重新上传此固件：

- 您的设备使用较旧的固件版本，或
- 您已烧录了自己的 Arduino 代码并希望恢复兼容性。

请按照以下步骤重新安装通信固件。

#. 使用 USB 线连接 Arduino 和计算机，然后将车的 **upload** 开关拨到上传端。

   .. image:: img/camera_upload.png
        :width: 500
        :align: center

   .. note:: 连接 Arduino 的是 USB Type B 端口，而非用于充电的 USB Type C 端口。

#. 检查固件文件是否已下载。

   * |download_galaxyrvr_filmware|

#. 运行更新脚本

   * 打开 ``galaxy-rvr.ino.xxx`` 文件夹（在上一步中下载并安装）。
   * 双击 ``update-arduino-firmware.bat`` 脚本。
   * 命令提示符窗口将自动出现。

   .. image:: img/faq_bat_file.png

#. 选择串口并上传

   * 在命令提示符中，将显示可用串口列表。
   * 输入左侧显示的序列号以选择 Arduino Uno 的串口。
   * 按 **Enter** 开始自动上传。
   * 示例：如果列表显示 `1 USB-SERIALXXX (COMxx)`，输入 **1** 并按 **Enter** 。

   .. image:: img/faq_select_com.png

#. 等待上传完成后，即可拔掉 USB 线。

   .. image:: img/faq_uno_updating.png

   .. note::

      此代码使 GalaxyRVR 能够响应 APP 命令。在使用 RoboPilot 遥控 APP 或 Mammoth Coding 软件时，您无需上传任何额外代码。

#. 现在您可以前往 :ref:`quick_start` 开始您的 GalaxyRVR 之旅！
