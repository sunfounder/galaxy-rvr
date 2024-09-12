.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

FAQ
==============

.. _ap_to_sta:

Q1: Change AP mode to STA mode
-------------------------------------------------

* You will need to download the relevant code.

    * :download:`GalaxyRVR Codes <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/main.zip>`

* Install IDE, then, install libraries ``SoftPWM`` and ``SunFounder AI Camera``. :ref:`install_lib` .

* Then, open the ``galaxy-rvr.ino`` file located in the ``galaxy-rvr-main\galaxy-rvr`` directory.

* Comment out lines 69-71, uncomment lines 73-75, and change ``SSID`` and ``PASSWORD`` to your WLAN.

.. image:: img/ap_sta.png
    :align: center

* Connect the Arduino and computer with a USB cable, and then turn the **upload** switch of the car to the upload end.

.. image:: img/camera_upload.png
    :width: 400
    :align: center

* Upload your code.

.. _install_lib:

Q2: Compilation error: SoftPWM.h: No such file or directory？
---------------------------------------------------------------------
If you get a “Compilation error: SoftPWM.h: No such file or directory” prompt, it means you don’t have the SoftPWM library installed.

Please install the two required libraries ``SoftPWM`` and ``SunFounder AI Camera`` as shown.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>


Q3: avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e?
-----------------------------------------------------------------------------
If the following message keeps appearing after clicking the **Upload** button when the board and port have been selected correctly.

.. code-block::
    
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00
    At this point, you need to make sure that the ESP32 CAM is unplugged.

The ESP32-CAM and the Arduino board share the same RX (receive) and TX (transmit) pins. So, before you’re uploading code, you’ll need to first disconnect the ESP32-CAM to avoid any conflicts or potential issues.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

After the code is successfully uploaded, if you need to use the ESP32 CAM, then you need to move the switch to the left to start the ESP32 CAM.

    .. image:: img/camera_run.png
        :width: 500
        :align: center

.. _stt_android:

Q4: How can I use the STT mode on my Android device?
------------------------------------------------------------------------

The STT mode requires the Android mobile device to be connected to the Internet and to install the Google service component.

Now follow the steps below.

#. Modify the AP mode of ``galaxy-rvr.ino`` file to STA mode.

    * Open the the ``galaxy-rvr.ino`` file located in the ``galaxy-rvr-main\galaxy-rvr`` directory. 
    * Then comment out the AP mode related code. Uncomment the STA mode related code and fill in  the ``SSID`` and ``PASSWORD`` of your home Wi-Fi.

        .. code-block:: arduino

            /** Configure Wifi mode, SSID, password*/
            // #define WIFI_MODE WIFI_MODE_AP
            // #define SSID "GalaxyRVR"
            // #define PASSWORD "12345678"

            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "xxxxxxxxxx"
            #define PASSWORD "xxxxxxxxxx"

    * Save this code, select the correct board (Arduino Uno) and port, then click the **Upload** button to upload it to the R3 board.

#. Search ``google`` in Google Play, find the app shown below and install it.

    .. image:: img/google_voice.png
        :width: 500
        :align: center

#. Connect your mobile device to the same Wi-Fi as you wrote in the code.

    .. image:: img/sta_wifi.png
        :width: 500
        :align: center

#. Open the controller previously created in SunFounder Controller and connect it to ``GalaxyRVR`` through the |app_connect| button.

    .. image:: img/app/camera_connect.png
        :width: 400
        :align: center


#. Tap and hold the **STT(J)** widget after clicking the |app_run| button. A prompt will appear indicating that it is listening. Say the following command to move the car.

    .. image:: img/app/play_speech.png

    * ``stop``: All movements of the rover can be stopped.
    * ``forward``: Let the rover move forward.
    * ``backward``: Let the rover move backward.
    * ``left``: Let the rover turn left.
    * ``right``: Let the rover turn right.

Q5: About the ESP32 CAM Firmware
---------------------------------------------------

Here is the firmeware link of ESP32 CAM: |link_ai_camera_firmware|



.. ↓ this firmware only for sunfounder controller


.. Q6: How to Flash New Firmware to an ESP32 CAM?
.. ----------------------------------------------------
.. The camera module comes pre-flashed from the factory. However, if you encounter a data corruption issue, you can re-flash it with new firmware using the Arduino IDE. Here's how:

.. **1. Prepare the Programmer**

.. #. First, get a programmer ready.

..     .. image:: img/esp32_cam_programmer.png
..         :width: 300
..         :align: center

.. #. Insert the ESP32 CAM into the programmer and then plug the programmer into your computer.

..     .. image:: img/esp32_cam_usb.jpg
..         :width: 300
..         :align: center

.. **2. Install the ESP32 Board**

.. To program the ESP32 microcontroller, you must install the ESP32 board package in the Arduino IDE. Follow these steps:

.. #. Go to **File** and select **Preferences** from the drop-down menu.

..     .. image:: img/install_esp321.png
..         :width: 500
..         :align: center

.. #. In the **Preferences** window, find the **Additional Board Manager URLs** field. Click on it to enable the text box.

..     .. image:: img/install_esp322.png
..         :width: 500
..         :align: center

.. #. Add this URL to the **Additional Board Manager URLs** field: https://espressif.github.io/arduino-esp32/package_esp32_index.json. This URL links to the package index file for ESP32 boards. Click **OK** to save the changes.

..     .. image:: img/install_esp323.png
..         :width: 500
..         :align: center

.. #.  In the **Boards Manager** window, search for **ESP32**. Click the **Install** button to begin installation. This downloads and installs the ESP32 board package.

..     .. image:: img/install_esp324.png
..         :align: center

.. **3. Install the Libraries**

.. #. Install the ``WebSockets`` library from the **LIBRARY MANAGER**.

..     .. image:: img/esp32_cam_websockets.png
..         :width: 500
..         :align: center

.. #. Follow the same steps to install the ``ArduinoJson`` library.

..     .. image:: img/esp32_cam_arduinojson.png
..         :width: 500
..         :align: center

.. **3. Download and Upload Firmware**

.. #. Download the firmware file.

..     * :download:`ai-camera-firmware <https://github.com/sunfounder/ai-camera-firmware/archive/refs/heads/main.zip>`

.. #. Extract the downloaded firmware file and rename the extracted folder from ``ai-camera-firmware-main`` to ``ai-camera-firmware``.

..     .. image:: img/esp32_cam_change_name.png
..         :align: center

.. #. Open ``ai-camera-firmware.ino`` with the Arduino IDE, which also opens the associated code files.

..     .. image:: img/esp32_cam_ino.png
..         :align: center

.. #. Select **Board** -> **esp32** -> **ESP32 Dev Module**.

..     .. image:: img/esp32_cam_board.png
..         :width: 500
..         :align: center

.. #. Choose the correct port.

..     .. image:: img/esp32_cam_port.png
..         :width: 400
..         :align: center

.. #. Ensure to enable **PSRAM** and select **Huge APP** in the **Partition Scheme**.

..     .. image:: img/esp32_cam_psram.png
..         :width: 400
..         :align: center

.. #. Finally, upload the firmware to the ESP32 CAM.

..     .. image:: img/esp32_cam_upload.png
..         :width: 500
..         :align: center

.. #. After successful firmware upload, you can find more information at this link: https://github.com/sunfounder/ai-camera-firmware.

