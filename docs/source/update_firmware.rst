.. _update_firmware:

更新固件
==========================

由于产品持续改进，您的设备可能未搭载最新固件。
我们建议在首次使用前更新固件，以确保一切运行顺畅。更新固件可确保：

* **Bug 修复** ：解决已知问题，提高稳定性。
* **App 兼容性** ：RoboPilot App 和 Mammoth Coding 需要最新固件才能正常工作。
* ** 新功能** ：固件更新可能会添加新的功能和改进。
* ** 更佳性能** ：优化 WiFi 连接、摄像头视频流和电机控制。

.. note::
   如果您不想更新固件并希望继续使用当前配置，可以参考 `GalaxyRVR v1 文档 <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_ 。


.. 视频暂时停用：当前 Bilibili 视频演示的还是旧版更新方式，与新流程不一致，待重新录制后再启用。

.. .. raw:: html
..
..   <iframe width="600" height="400" src="https://player.bilibili.com/player.html?isOutside=true&aid=116729342663499&bvid=BV11REY6JEFs&cid=39027148026&p=1" scrolling="no" border="0" frameborder="0" framespacing="0" allowfullscreen="true"></iframe>

.. _update_r3_firmware:

1. 更新 UNO R3 固件
-------------------------------------

R3 板搭载的固件负责与 RoboPilot App 和 Mammoth Coding 通信。请使用网页烧录器重新安装：在电脑上用 **Chrome** 或 **Edge** 打开 |link_galaxy_rvr_flasher| —— 它直接在浏览器中运行，无需安装额外的软件，而且每一步都有对应的图示。

烧录器共有三个步骤：

#. **Connect** —— 打开火星车电源，用 USB A 转 B 数据线（不是 Type-C 线）将主板连接到电脑，然后把模式开关拨到 **Upload** 位置。然后点击 **Next** 。

   .. image:: img/flasher_step1.jpg
      :width: 500

#. **Flash** —— 点击 **Connect & Flash** 。在弹出的端口窗口中选择主板对应的端口（例如 ``USB Serial (COMxx)``），然后点击 **Connect** ，烧录随即开始。如果失败，再次点击 **Connect & Flash** 即可。

   .. image:: img/flasher_step2.jpg
      :width: 500

#. **Debug** —— 烧录完成后，您将在日志窗口中看到以下内容，这表示固件已写入，并显示当前版本 **2.0.2** 。此时请忽略 ``Initialzing...`` 及其之后的所有内容：火星车仍处于 **Upload** 模式，因此暂时无法与 ESP32 CAM 通信。然后点击 **Next** 。

   .. code-block::

      Reading firmwares/galaxy-rvr-2.0.2.hex
      Resetting the board...
      Connecting to the board...
      Firmware written.
      Verified - flash matches the file.

      ---------- serial open at 115200 ----------
      GalaxyRVR version 2.0.2
      Initialzing...
      SET+RESET
      ...SET+RESET
      ...SET+RESET
      ...[FAIL]

#. 接下来按提示操作：打开电源开关，把模式开关拨回原来的位置，并按下 R3 板上的 **Reset** 按钮。

   .. image:: img/flasher_step3_run.jpg
      :width: 500

#. 日志窗口随后会显示当前 ESP32 CAM 的固件版本。

   * 如果 ESP32 CAM 固件为 **1.5.0 或更高版本** ，日志会显示 UNO R3 固件、ESP32 CAM 固件，最后是一个类似 ``http://xxx.xxx.xx.xxx:9000/mjpg`` 的网址。
   * 如果 ** 低于 1.5.0** ，日志窗口会提示 ESP32 CAM 固件需要更新 —— 请继续参阅 :ref:`update_esp32_firmware`。

   .. image:: img/flasher_step3.jpg
      :width: 500

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


** 版本 A**

   6. 在 OTA 页面选择固件文件并开始更新：

      * 从设备中选择之前下载的 ``ai-camera-firmware-vX.X.X-ota.bin`` 文件，然后点击 **Add** 。
      * 点击 **Update** 按钮开始固件更新，等待完成即可。

      .. image:: img/faq_ota_a.png
         :width: 700

   #. 更新完成后，GalaxyRVR 的 WiFi 热点名称将更改为 "AI Camera-xxxxxx"，密码仍为 "12345678"。


** 版本 B**


   6. 在 **OTA** 页面上，查看网页上显示的当前固件版本。

      * 如果您的版本号为 **1.5.0 或更高** ，则无需更新。您可以跳过剩余步骤，直接前往 :ref:`quick_start` 。
      * 如果版本 ** 低于 1.5.0** ，请继续更新。

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center


   #. 点击 **Upgrade Firmware** ，选择固件文件并等待更新完成：

      * 点击 **Upgrade Firmware** 按钮，然后从设备中选择之前下载的 ``ai-camera-firware.ino.x.x.x.bin`` 文件。
      * 更新将立即开始，通常需要 1-2 分钟。完成后，选择 **CONFIRM** 重启 GalaxyRVR。

      .. image:: img/faq_ota_b.png
         :width: 700

   #. 更新完成后，GalaxyRVR 的 WiFi 热点名称将更改为 "AI Camera-xxxxxx"，密码仍为 "12345678"。

3. 开机验证结果
-----------------------------

* 首次使用 GalaxyRVR 前，请使用附带的 Type-C USB 线将电池充满电。
* 打开电源开关。
* 将模式切换到 **Run** 并按下 R3 板上的 **Reset** 按钮。
* 底部灯带将闪烁 ** 绿色** ，表示启动成功。

.. raw:: html

   <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=_idwN0kJrxbVW-5H" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
