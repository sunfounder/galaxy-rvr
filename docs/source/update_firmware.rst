
.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _update_firmware:

Update Firmwares
==========================

Your device may not have the latest firmware due to ongoing product improvements.  
To ensure optimal and stable performance, please follow the steps below to check and update the firmware on your ESP32 CAM and R3 board.

1. Check Whether an Update Is Needed
-------------------------------------

#. Before using the GalaxyRVR for the first time, fully charge the battery with the supplied Type-C USB cable. After charging, turn the power on.
    
   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_start.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. To start the ESP32 CAM, switch the mode to **Run** and press the **Reset** button on the R3 board. The bottom light strip will begin flashing to indicate a successful startup.

   .. note::

      * If the bottom light strip shows a **green flashing light**, your ESP32 firmware is already up to date.  
      * You may proceed to :ref:`quick_start`.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset_green.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. If the bottom light strip flashes **other color**, you will need to:

   * :ref:`update_esp32_firmware`
   * :ref:`update_r3_firmware`

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

   
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
       
#. Open a web browser on your mobile device and go to the address ``http://192.168.4.1``. This will take you to the ESP32-CAM firmware update portal.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. On the **OTA** page, check the current firmware version displayed on the webpage.
    
   * If your version number is **higher than 1.5.1**, an update is not required. You can skip the remaining steps and proceed directly to :ref:`quick_start`.
   * If the version is **1.5.1 or lower**, please continue with the update.

   .. image:: img/firmware_version.jpg
        :width: 50%
        :align: center

#. Tap the **Upgrade Firmware** button.

   .. image:: img/firmware_tap.jpg
        :width: 50%
        :align: center

#. A file selection dialog will appear. Navigate to and select the ``ai-camera-firware.ino.x.x.x.bin`` file you transferred to your mobile device earlier.

   .. image:: img/firmware_select.jpg
        :width: 50%
        :align: center

#. The firmware update will begin immediately after you select the file.

   .. image:: img/firmware_upgrade.jpg
        :width: 50%
        :align: center

#. Wait for the firmware upgrade to complete.

   * The upload process typically takes 1-2 minutes. Once finished, a success message will appear in a pop-up window.
   * You can then select **CONFIRM** to restart the GalaxyRVR or **CLOSE** to dismiss the window.

   .. image:: img/firmware_finish.jpg
        :width: 50%
        :align: center

.. _update_r3_firmware:

3. Updating the R3 Board Firmware
--------------------------------------

The R3 board includes built-in firmware that enables communication with the RoboPilot APP and Mammoth Coding.  

You need to re-upload this firmware if:

- Your device uses an older firmware version, or  
- You have flashed your own Arduino code and want to restore compatibility.

Follow the steps below to reinstall the communication firmware.

#. Connect the Arduino and computer with a USB cable, and then turn the **upload** switch of the car to the upload end.

   .. image:: img/camera_upload.png
        :width: 500
        :align: center

   .. note:: It is the USB Type B port for connecting to Arduino, not the USB Type C port for charging.

#. Check whether the firmware files have been downloaded.

   * |download_galaxyrvr_filmware| 

#. Run the update script

   * Open the ``galaxy-rvr.ino.xxx`` folder (downloaded and installed in the previous step).
   * Double-click the ``update-arduino-firmware.bat`` script.
   * A command prompt window will appear automatically.

   .. image:: img/faq_bat_file.png

#. Select the serial port and upload

   * In the command prompt, a list of available serial ports will be displayed.
   * Enter the sequence number shown on the left to select the Arduino Uno's serial port.
   * Press **Enter** to begin the automatic upload.
   * Example: If the list shows `1 USB-SERIALXXX (COMxx)`, enter **1** and press **Enter**.

   .. image:: img/faq_select_com.png

#. After waiting for the upload to complete, you can unplug the USB cable.

   .. image:: img/faq_uno_updating.png

.. note:: 

   This code enables the GalaxyRVR to respond to APP commands. You won’t need to upload any additional code when using either the RoboPilot remote control APP or the Mammoth Coding software.

