.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _update_firmware:

Update Firmware
==========================

Your device may not have the latest firmware due to ongoing product improvements.
We recommend updating the firmware before your first use to ensure everything works smoothly. Updating the firmware ensures:

* **Bug fixes**: Resolves known issues and improves stability.
* **App compatibility**: The latest firmware is required for the RoboPilot app and Mammoth Coding to work correctly.
* **New features**: Firmware updates may add new capabilities and improvements.
* **Better performance**: Optimizations for WiFi connectivity, camera streaming, and motor control.

.. note::
   If you prefer not to update the firmware and want to keep using your current configuration, you can refer to the `GalaxyRVR v1 Documentation <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_.


.. raw:: html

   <iframe width="600" height="400" src="https://www.youtube.com/embed/Tl2W26pIQoU?si=98bbfUPc1g2cEz3A" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


.. _update_uno_firmware:

1. Updating the UNO R3 Board Firmware
--------------------------------------

The R3 board includes built-in firmware that enables communication with the RoboPilot app and Mammoth Coding. You can reinstall it with the web-based flasher, which needs no additional software on your computer.

**Method 1: Web-based flasher**

#. Power on the GalaxyRVR, connect the USB A to B cable (not the USB Type C cable) to the **main board**, and then turn the **Upload** switch of the car to the upload end.

#. Remove the ESP32 CAM from its slot before flashing — it shares the same RX and TX pins with the R3 board, as explained in :ref:`the FAQ <faq_r3_upload_bat>`.

#. On a computer, open |link_galaxy_rvr_flasher| in **Chrome** or **Edge**, then select the firmware version:

   * Version **2.0.0** is for the current generation of GalaxyRVR.
   * Version **1.1.0** is for the first generation of GalaxyRVR.

   If you are not sure which generation you have, check the label on the box or contact us.

#. Click **Connect & Flash** and select your board's serial port in the dialog. The update begins automatically and finishes in about one minute.

   .. image:: img/faq_web_flasher.png
      :width: 600
      :align: center

#. When the update is complete, set the switch back to **Run**, plug the ESP32 CAM back in, and power on the GalaxyRVR again.

.. note::

   * This page uses Web Serial, so use **Chrome** or **Edge** on a computer, and make sure the page is opened over **https**. On Windows, you can confirm the USB serial driver is installed by checking for **USB-SERIAL CH340** in Device Manager.
   * Close other programs that may be using the serial port, such as the Arduino IDE, the serial monitor, or another browser tab.

.. _update_esp32_firmware:

2. Updating the ESP32 CAM Firmware
--------------------------------------

The ESP32 CAM broadcasts the Wi-Fi hotspot and captures video for the GalaxyRVR.  
If the firmware is outdated, these functions may not work properly. Follow the steps below to update the firmware.

#. Turn on the GalaxyRVR's power switch. To start the ESP32 CAM, switch the mode to **Run** and press the **Reset** button on the R3 board.

   .. image:: img/camera_run.png
        :width: 500
        :align: center
   
#. Download the firmware file.

   * |download_galaxyrvr_filmware|

#. Extract the downloaded ZIP file. Locate the firmware file named ``ai-camera-firware.ino.x.x.x.bin`` and transfer it to your mobile device. You can use any file manager app, such as ES File Explorer or a file transfer utility.

   .. image:: img/firmware_bin_file.png
        :align: center

#. Connect your mobile device to the GalaxyRVR's WiFi network.

   * The network name (SSID) is ``GalaxyRVR`` and the password is ``12345678``.  
   * If you see a warning stating "No Internet access," please choose the option to **"Stay connected."**

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Open a web browser on your mobile device and navigate to ``http://192.168.4.1`` to access the ESP32 CAM OTA update page.


.. note:: On this page, you will see OTA upgrade options in one of two interfaces. Version A (the former) and Version B (the latter) will appear depending on your firmware version. Simply select the corresponding upgrade steps based on the interface you see.

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center


**Version A**

   6. On the OTA page, select the firmware file and start the update:

      * Choose the previously downloaded ``ai-camera-firmware-vX.X.X-ota.bin`` file from your device and click **Add**.
      * Click the **Update** button to begin the firmware update, then wait for it to complete.

      .. image:: img/faq_ota_a.png
         :width: 700


   #. After the update is complete, the GalaxyRVR's WiFi hotspot name will change to "AI Camera-xxxxxx", and the password will remain "12345678".


**Version B**


   6. On the **OTA** page, check the current firmware version displayed on the webpage.
      
      * If your version number is **higher than 1.5.1**, an update is not required. You can skip the remaining steps and proceed directly to :ref:`quick_start`.
      * If the version is **1.5.1 or lower**, please continue with the update.

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center

   #. Tap **Upgrade Firmware**, select the firmware file, and wait for the update to complete:

      * Tap the **Upgrade Firmware** button, then select the previously downloaded ``ai-camera-firware.ino.x.x.x.bin`` file from your device.
      * The update will begin immediately and typically takes 1-2 minutes. Once finished, select **CONFIRM** to restart the GalaxyRVR.

      .. image:: img/faq_ota_b.png
         :width: 700

   #. After the update is complete, the GalaxyRVR's WiFi hotspot name will change to "AI Camera-xxxxxx", and the password will remain "12345678".

3. Verifying the R3 Firmware Update
----------------------------------------

#. Power on the GalaxyRVR and check the bottom light strip.

   * Before using the GalaxyRVR for the first time, fully charge the battery with the supplied Type-C USB cable.
   * Turn the power switch on.
   * Switch the mode to **Run** and press the **Reset** button on the R3 board.
   * The bottom light strip will begin flashing to indicate a successful startup.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

#. Check the bottom light strip.

   * If the bottom light strip shows a **green flashing light**, the R3 firmware is running correctly. You may proceed to :ref:`quick_start`.
   * If the bottom light strip flashes **another color**, reinstall the R3 firmware with :ref:`update_uno_firmware`.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

.. important::

   * This firmware enables the GalaxyRVR to respond to app commands.
   * You won’t need to upload any additional code when using either the RoboPilot remote control app or the Mammoth Coding software.
   * You can now proceed to :ref:`quick_start` to start your GalaxyRVR journey!
