常见问题（FAQ）
=====================

如何更改 Wi-Fi 信道？
----------------------------------

2.4GHz Wi-Fi 频段的信道范围为 1 至 13，其中 ESP32 支持 1 至 11 信道。  
当其他设备使用相同信道时，可能会造成干扰，导致连接不稳定。为避免这种情况，可以尝试切换 Wi-Fi 信道。默认信道为 1，建议每次切换时跳过 1~2 个信道。例如，当前信道为 1 时，先尝试 3，如果信号仍然较差，再尝试 5。

.. note::

   若要修改 Wi-Fi 信道，ESP32 CAM 固件版本需为 1.4.2 及以上。更多信息请参阅 :ref:`update_firmware` 。

#. 打开 GalaxyRVR 电源。将模式拨至 **Run** 位置以启用 ESP32 CAM，并按下 **reset** 按钮重启 R3 主控板。

   .. raw:: html

      <video width="600" loop autoplay muted>
          <source src="_static/video/play_reset.mp4" type="video/mp4">
          Your browser does not support the video tag.
      </video>

#. 在手机或平板设备的 Wi-Fi 列表中找到 ``GalaxyRVR``，输入密码 ``12345678`` 并连接。

   .. note::

      * 当前为连接至 GalaxyRVR 热点模式，无互联网访问。如果系统提示切换网络，请选择“保持连接”。
      * :ref:`ap_to_sta`

   .. image:: img/app/camera_lan.png
      :width: 500

#. 在浏览器中输入 ``http://192.168.4.1`` ，进入 ESP32 CAM OTA 更新页面。

   .. image:: img/faq_cam_ota_141.jpg
      :width: 400

#. 在 **Wi-Fi AP Channel** 区域，选择新的信道。

   * 默认信道为 1。切换时建议每次跳过 1~2 个信道（例如从 1 到 3，如果仍不理想，再试 5）。  
   * 点击 **Confirm** 按钮保存设置。

   .. image:: img/faq_cam_ota_channel.png
      :width: 400

#. 弹窗提示重启设备，点击 **Confirm** 。

   .. image:: img/faq_cam_ota_reset.jpg
      :width: 400

#. 按下 **Reset** 按钮重启设备，GalaxyRVR 即可正常运行。

   .. image:: img/camera_reset.png

.. _update_firmware:

如何更新 ESP32 CAM 固件
-----------------------------------------

按照以下步骤更新 ESP32 CAM 固件：

#. 打开 GalaxyRVR 电源，将模式拨至 **Run** ，并按下 **reset** 按钮重启 R3 主控板。

   .. raw:: html

      <video width="600" loop autoplay muted>
          <source src="_static/video/play_reset.mp4" type="video/mp4">
          Your browser does not support the video tag.
      </video>

#. 使用手机或平板连接 ``GalaxyRVR`` Wi-Fi，密码为 ``12345678`` 。

   .. note::

      * 当前为 GalaxyRVR 热点，无互联网访问。如提示切换网络，请选择“保持连接”。
      * :ref:`ap_to_sta`

   .. image:: img/app/camera_lan.png
        :width: 500

#. 点击下方链接下载固件 ``ai-camera-firmware-v1.4.2-ota.bin`` 并保存到设备。

   * :download:`ESP32 CAM Firmware <https://github.com/sunfounder/ai-camera-firmware/releases/download/1.4.2/ai-camera-firmware-v1.4.2-ota.bin>`

#. 打开浏览器并访问 ``http://192.168.4.1`` 进入 OTA 更新页面。

   .. image:: img/faq_cam_ota.jpg
      :width: 400

#. 在 OTA 页面点击按钮选择固件文件。

   .. image:: img/faq_cam_ota_choose.png
      :width: 400

#. 选择刚下载的 ``ai-camera-firmware-v1.4.2-ota.bin`` 文件并点击 **添加** 。

   .. image:: img/faq_cam_ota_file.png
      :width: 400

#. 点击 **Update** 按钮开始更新固件。

   .. image:: img/faq_cam_ota_update.png
      :width: 400

#. 等待更新完成。当页面上显示的版本号变为 ``1.4.2`` 时，表示更新成功。

   .. image:: img/faq_cam_ota_finish.png
      :width: 400

#. 更新完成后可关闭浏览器，按下 **Reset** 按钮重启设备，ESP32 CAM 即可正常使用。

   .. image:: img/camera_reset.png

.. _upload_galaxy_code:

如何上传 ``galaxy-rvr.ino`` 代码？
-----------------------------------------------

GalaxyRVR 的 Uno R3 板预装了固件，可直接通过 APP 控制。如果你之前覆盖了其他代码，想恢复默认固件以继续 :ref:`play_mode` ，请按以下步骤重新上传：

#. 用 USB 线将 Arduino 与电脑连接，将小车上的 **upload** 拨到“上传”位置。

   .. image:: img/camera_upload.png
        :width: 400
        :align: center

#. 下载所需固件：
        
   * :download:`R3 Board Firmware <https://github.com/sunfounder/galaxy-rvr/releases/download/1.1.0/galaxy-rvr-1.1.0.zip>`

#. 解压文件，双击 ``update-arduino-firmware.bat`` 运行。

   .. image:: img/faq_firmware_file.png

#. 输入对应的 Arduino Uno 序号（如 ``2``），按 **Enter** 开始更新。

   .. note::

     * 如果端口未正确识别，请拔掉其他 USB 设备，仅保留小车连接。
     * 若提示 "avrdude.exe: stk500_getsync() attempt 1 of 10: not in sync: resp=0xXX"，请确认 **upload** 拨码已设置为“上传”模式。

   .. image:: img/faq_firmware_port.png

#. 稍等片刻，新的代码将成功上传至 R3 主控板。

   .. image:: img/faq_firmware_finish.png

.. _ap_to_sta:

小车网络配置：家庭 Wi-Fi 与 AP 模式
-----------------------------------------------------

默认情况下，Uno R3 板加载的是 AP 模式代码。GalaxyRVR 会开启热点，允许手机通过 SunFounder Controller APP 进行连接和控制。

如果希望通过家庭 Wi-Fi 控制小车，或需恢复 AP 模式，可按以下步骤修改并上传代码：

#. 下载代码：

   * :download:`GalaxyRVR Codes <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/main.zip>`

#. 参阅 :ref:`install_arduino_ide` 完成 Arduino IDE 安装。

#. 通过 **Library Manager** 安装 ``SoftPWM`` 与 ``SunFounder AI Camera`` 库，详见 :ref:`install_lib`。

#. 打开 ``galaxy-rvr-main\galaxy-rvr`` 目录下的 ``galaxy-rvr.ino`` 文件。

   .. image:: img/faq_galaxy_code.png

#. 注释第 69–71 行，取消注释 73–75 行，并将 ``SSID`` 和 ``PASSWORD`` 替换为家庭 Wi-Fi 信息。

   .. code-block:: c

      // /** Configure Wifi mode, SSID, password*/
      // #define WIFI_MODE WIFI_MODE_AP
      // #define SSID "GalaxyRVR"
      // #define PASSWORD "12345678"

      #define WIFI_MODE WIFI_MODE_STA
      #define SSID "xxxxxxxxxx"
      #define PASSWORD "xxxxxxxxxx"

#. 使用 USB 线连接小车和电脑，并将拨码开关拨到“上传”端。

   .. image:: img/camera_upload.png
        :width: 400
        :align: center

#. 在 Arduino IDE 中点击 **Upload** 上传修改后的代码。

   .. image:: img/faq_galaxy_upload.png

#. 将模式开关拨至 **Run**，按下 **reset** 重启 R3 主控板。此时底部灯条会闪烁青色光。

   .. raw:: html

       <video width="600" loop autoplay muted>
           <source src="_static/video/play_reset.mp4" type="video/mp4">
           Your browser does not support the video tag.
       </video>

#. 确保移动设备连接到家庭 Wi-Fi。

   .. image:: img/faq_connect_wifi.jpg
        :width: 400
        :align: center

#. 打开 SunFounder Controller App，点击 “+” 新建控制器，选择 “GalaxyRVR” 预设，输入名称或直接确认。

   .. image:: img/app/play_preset.jpg
        :width: 600

#. APP 会自动搜索 GalaxyRVR，连接成功后会出现提示。

   .. image:: img/app/auto_connect.jpg
        :width: 600

#. 点击 |app_run| 按钮，即可查看摄像头实时画面并控制小车。

   .. image:: img/app/play_run_view.jpg
        :width: 600

**重置为 AP 模式**

#. 若需恢复 AP 模式，可启用相关代码并修改 SSID 和 PASSWORD：

   .. code-block:: c

      #define WIFI_MODE WIFI_MODE_AP 
      #define SSID "newSSIDName" 
      #define PASSWORD "newPassword"

      // #define WIFI_MODE WIFI_MODE_STA
      // #define SSID "xxxxxxxxxx"
      // #define PASSWORD "xxxxxxxxxx"

#. 按上述步骤重新上传代码。

#. 上传完成后，小车将以新的网络名称和密码开启热点，可直接连接，无需家庭 Wi-Fi。

如何翻转摄像头？
---------------------------

若在 SunFounder Controller 中摄像头画面倒置，可通过以下步骤校正：

1. 点击右上角 |app_edit| 按钮。  

   .. image:: img/app/faq_edit.png  
        :width: 500 

2. 点击 **camera** 按钮，弹出设置框，打开 **Inverted** 开关。  

   .. image:: img/app/faq_inverted.png  
        :width: 500  

3. 保存设置。  

   .. image:: img/app/faq_save.png  
        :width: 500 

4. 返回控制界面并点击 |app_run|。  

   .. note::  

        若画面偶尔不显示，可暂停控制器后再次点击运行按钮。  

   .. image:: img/app/faq_run.png  
        :width: 500 

.. _install_lib:

编译错误： ``SoftPWM.h`` 或 ``SunFounder_AI_Camera.h`` : No such file or directory？
---------------------------------------------------------------------------------------------

若出现 “Compilation error: ``SoftPWM.h`` : No such file or directory”，说明未安装 SoftPWM 库。

请按以下方式安装 ``SoftPWM`` 和 ``SunFounder AI Camera`` 库。

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

安装 ``SunFounder AI Camera`` 库时，选择“INSTALL ALL”，以同时安装依赖 ``ArduinoJson`` 。

    .. image:: img/faq_install_ai_camera.png

avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e?
-----------------------------------------------------------------------------

若点击 **Upload** 后反复出现以下错误：

.. code-block::
    
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00

请先断开 ESP32 CAM。ESP32-CAM 与 Arduino 共享 RX/TX 引脚，上载代码前需断开以避免冲突。

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

代码上传完成后，如需使用 ESP32 CAM，将拨码开关切回左侧以启动摄像头。

    .. image:: img/camera_run.png
        :width: 500
        :align: center

.. _stt_android:

如何在 Android 设备上使用 STT 模式？
------------------------------------------------------------------------

STT 模式需要 Android 设备联网并安装 Google 语音服务组件。

请按以下步骤操作：

#. 将 ``galaxy-rvr.ino`` 的 AP 模式改为 STA 模式。

   * 打开 ``galaxy-rvr-main\galaxy-rvr`` 目录下的 ``galaxy-rvr.ino`` 文件。 
   * 注释 AP 模式代码，启用 STA 模式并填写家庭 Wi-Fi 的 ``SSID`` 与 ``PASSWORD``。

     .. code-block:: arduino

            /** Configure Wifi mode, SSID, password*/
            // #define WIFI_MODE WIFI_MODE_AP
            // #define SSID "GalaxyRVR"
            // #define PASSWORD "12345678"

            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "xxxxxxxxxx"
            #define PASSWORD "xxxxxxxxxx"

   * 保存代码，选择 Arduino Uno 与正确的端口，点击 **Upload** 上传至 R3 主控板。

#. 在 Google Play 中搜索 “google” 并安装如下应用。

    .. image:: img/google_voice.png
        :width: 500
        :align: center

#. 将移动设备连接到与代码中一致的 Wi-Fi。

    .. image:: img/sta_wifi.png
        :width: 500
        :align: center

#. 打开 SunFounder Controller，点击 |app_connect| 按钮连接 GalaxyRVR。

    .. image:: img/app/camera_connect.png
        :width: 400
        :align: center

#. 点击 |app_run| 后，长按 **STT(J)** 控件，提示“正在监听”时可语音控制小车移动。

    .. image:: img/app/play_speech.png

    * ``stop``：停止所有动作  
    * ``forward``：前进  
    * ``backward``：后退  
    * ``left``：左转  
    * ``right``：右转

Q5: 关于 ESP32 CAM 固件
---------------------------------------------------

ESP32 CAM 固件下载链接：|link_ai_camera_firmware|
