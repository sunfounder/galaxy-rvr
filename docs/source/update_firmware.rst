
.. _update_firmware:

更新固件
==========================

由于产品持续改进，您的设备可能未搭载最新固件。
我们建议在首次使用前更新固件，以确保一切运行顺畅。更新固件可确保：

* **Bug 修复**：解决已知问题，提高稳定性。
* **App 兼容性**：RoboPilot App 和 Mammoth Coding 需要最新固件才能正常工作。
* **新功能**：固件更新可能会添加新的功能和改进。
* **更佳性能**：优化 WiFi 连接、摄像头视频流和电机控制。

.. note::
   如果您不想更新固件并希望继续使用当前配置，可以参考 `GalaxyRVR v1 文档 <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_ 。


.. raw:: html

  <iframe width="600" height="400" src="https://player.bilibili.com/player.html?isOutside=true&aid=116729342663499&bvid=BV11REY6JEFs&cid=39027148026&p=1" scrolling="no" border="0" frameborder="0" framespacing="0" allowfullscreen="true"></iframe>


1. 检查是否需要更新
-------------------------------------

#. 启动 GalaxyRVR 并检查底部灯带。

   * 首次使用 GalaxyRVR 前，请使用附带的 Type-C USB 线将电池充满电。
   * 打开电源开关。
   * 将模式切换到 **Run** 并按下 R3 板上的 **Reset** 按钮。
   * 底部灯带将开始闪烁，表示启动成功。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/power_start.mp4" type="video/mp4">
            您的浏览器不支持此视频标签。
        </video>

#. 检查底部灯带。

   * 如果底部灯带显示 **绿色闪烁灯光** ，则您的 ESP32 固件已是最新。您可以继续前往 :ref:`quick_start` 。
   * 如果底部灯带闪烁 **其他颜色** ，您将需要：

     - :ref:`update_esp32_firmware`
     - :ref:`update_r3_firmware`


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

   * 网络名称（SSID）为 ``GalaxyRVR`` ，密码为 ``12345678`` 。
   * 如果看到提示"无互联网访问"，请选择 **"保持连接"** 选项。

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. 在移动设备上打开网页浏览器，访问 ``http://192.168.4.1`` 进入 ESP32 CAM OTA 更新页面。


.. note:: 在此页面上，您会看到两种界面之一的 OTA 升级选项。版本 A（前者）和版本 B（后者）会根据您的固件版本显示。请根据您看到的界面选择相应的升级步骤。

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center


**版本 A**

   6. 在 OTA 页面选择固件文件并开始更新：

      * 从设备中选择之前下载的 ``ai-camera-firmware-vX.X.X-ota.bin`` 文件，然后点击 **Add**。
      * 点击 **Update** 按钮开始固件更新，等待完成即可。

      .. image:: img/faq_ota_a.png
         :width: 700

   #. 更新完成后，GalaxyRVR 的 WiFi 热点名称将更改为 "AI Camera-xxxxxx"，密码仍为 "12345678"。


**版本 B**


   6. 在 **OTA** 页面上，查看网页上显示的当前固件版本。

      * 如果您的版本号 **高于 1.5.1** ，则无需更新。您可以跳过剩余步骤，直接前往 :ref:`quick_start` 。
      * 如果版本为 **1.5.1 或更低** ，请继续更新。

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center


   #. 点击 **Upgrade Firmware**，选择固件文件并等待更新完成：

      * 点击 **Upgrade Firmware** 按钮，然后从设备中选择之前下载的 ``ai-camera-firware.ino.x.x.x.bin`` 文件。
      * 更新将立即开始，通常需要 1-2 分钟。完成后，选择 **CONFIRM** 重启 GalaxyRVR。

      .. image:: img/faq_ota_b.png
         :width: 700

   #. 更新完成后，GalaxyRVR 的 WiFi 热点名称将更改为 "AI Camera-xxxxxx"，密码仍为 "12345678"。


.. _update_r3_firmware:

3. 更新 R3 板固件
--------------------------------------

R3 板包含内置固件，用于实现与 RoboPilot APP 和 Mammoth Coding 的通信。

在以下情况下，您需要重新上传此固件：

- 您的设备使用较旧的固件版本，或
- 您已烧录了自己的 Arduino 代码并希望恢复兼容性。

请按照以下步骤重新安装通信固件。

.. note::

   如果您使用的是 Mac 电脑，请参考 macOS 专用指南：

   :ref:`uno_firmware_mac`

#. 使用 USB A 转 B 线（非 USB Type C）连接 Arduino 和计算机，然后将模式开关拨到 **Upload** 位置。

   .. image:: img/camera_upload.png
        :width: 500
        :align: center

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

.. important::

   * 此固件使 GalaxyRVR 能够响应 App 命令。
   * 在使用 RoboPilot 遥控 App 或 Mammoth Coding 软件时，您无需上传任何额外代码。
   * 现在您可以前往 :ref:`quick_start` 开始您的 GalaxyRVR 之旅！