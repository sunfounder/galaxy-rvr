FAQ
==============

Q1: Compilation error: SoftPWM.h: No such file or directory？
---------------------------------------------------------------------
If you get a “Compilation error: SoftPWM.h: No such file or directory” prompt, it means you don’t have the SoftPWM library installed.

Please install the two required libraries ``SoftPWM`` and ``SunFounder AI Camera`` as shown.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>


Q2: avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e?
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
        :width: 600

After the code is successfully uploaded, if you need to use the ESP32 CAM, then you need to move the switch to the left to start the ESP32 CAM.

    .. image:: img/camera_run.png
        :width: 600

.. _stt_android:

Q3: How can I use the STT mode on my Android device?
------------------------------------------------------------------------

The STT mode requires the Android mobile device to be connected to the Internet and to install the Google service component.

Now follow the steps below.

#. Modify the AP mode of ``galaxy-rvr.ino`` file to STA mode.

    * Open the the ``galaxy-rvr.ino`` file located in the ``galaxy-rvr-main\galaxy-rvr`` directory. 
    * Then comment out the AP mode related code. Uncomment the STA mode related code and fill in  the ``SSD`` and ``PASSWORD`` of your home Wi-Fi.

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

#. Connect your mobile device to the same Wi-Fi as you wrote in the code.

    .. image:: img/sta_wifi.png

#. Open the controller previously created in SunFounder Controller and connect it to ``GalaxyRVR`` through the |app_connect| button.

    .. image:: img/app/camera_connect.png


#. Tap and hold the **STT(J)** widget after clicking the |app_run| button. A prompt will appear indicating that it is listening. Say the following command to move the car.

    .. image:: img/app/play_speech.png

    * ``stop``: All movements of the rover can be stopped.
    * ``forward``: Let the rover move forward.
    * ``backward``: Let the rover move backward.
    * ``left``: Let the rover turn left.
    * ``right``: Let the rover turn right.