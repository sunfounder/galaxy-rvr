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


.. Video temporarily disabled: it shows the old update procedure and is out of date. Re-enable it once the new video is recorded.
..
.. .. raw:: html
..
..    <iframe width="600" height="400" src="https://www.youtube.com/embed/Tl2W26pIQoU?si=98bbfUPc1g2cEz3A" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


1. Updating the UNO R3 Firmware
-------------------------------------

The R3 board carries the firmware that talks to the RoboPilot app and Mammoth Coding. Reinstall it with the web-based flasher: open |link_galaxy_rvr_flasher| in **Chrome** or **Edge** on a computer — it runs in your browser, needs no extra software, and shows each step with its own picture.

The flasher has three steps:

#. **Connect** — Turn on the rover, connect the main board to your computer with a USB A to B cable (not the Type-C one), then set the mode switch to the **Upload** position. Then click **Next**.

   .. image:: img/flasher_step1.png
      :width: 500

#. **Flash** — Click **Connect & Flash**. In the port window that pops up, pick your board's port (for example ``USB Serial (COMxx)``), then click **Connect** and the flashing starts. If it fails, simply click **Connect & Flash** again.

   .. image:: img/flasher_step2.png
      :width: 500

#. **Done** — When the flash finishes you will see the following in the log window, which confirms the firmware was written and shows the current version (**2.0.2**). Ignore ``Initialzing...`` and everything after it at this point: the rover is still in **Upload** mode, so it cannot communicate with the ESP32 CAM yet. Then click **Next**.

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

#. Now follow the prompt: set the mode switch back to its original position and press the **Reset** button on the R3 board. The log window then shows the current ESP32 CAM firmware.

   * If the ESP32 CAM firmware is **1.5.0 or higher**, you can go straight to :ref:`quick_start`.
   * If it is **lower than 1.5.0**, continue with :ref:`update_esp32_firmware`.



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
      
      * If your version number is **1.5.0 or higher**, an update is not required. You can skip the remaining steps and proceed directly to :ref:`quick_start`.
      * If the version is **lower than 1.5.0**, please continue with the update.

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center

   #. Tap **Upgrade Firmware**, select the firmware file, and wait for the update to complete:

      * Tap the **Upgrade Firmware** button, then select the previously downloaded ``ai-camera-firware.ino.x.x.x.bin`` file from your device.
      * The update will begin immediately and typically takes 1-2 minutes. Once finished, select **CONFIRM** to restart the GalaxyRVR.

      .. image:: img/faq_ota_b.png
         :width: 700

   #. After the update is complete, the GalaxyRVR's WiFi hotspot name will change to "AI Camera-xxxxxx", and the password will remain "12345678".


3. Verifying the Startup
-----------------------------

   * Before using the GalaxyRVR for the first time, fully charge the battery with the supplied Type-C USB cable.
   * Turn the power switch on.
   * Switch the mode to **Run** and press the **Reset** button on the R3 board.
   * The bottom light strip will flash **green**, indicating a successful startup.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
