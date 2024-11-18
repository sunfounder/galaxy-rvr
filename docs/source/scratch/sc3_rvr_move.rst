.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!



.. _rvr_move:

Lesson 3 Remote Control Your GalaxyRVR
============================================

In this lesson, we're bringing the Mars Rover to life!

Using our coding skills, we'll guide our Rover across imagined Martian landscapes.

It's a Martian adventure in our classroom. Let's get started!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>


Learning Objectives
-----------------------

* Guide students to download and upload the corresponding Arduino code to control the rover with the APP.
* Learn to use the arrow keys in Mammoth Coding to control the rover's movements.
* Implement basic movement controls for the rover: forward, backward, left turn, right turn.

Materials
-------------

* Smartphone or tablet
* Mammoth Coding APP
* GalaxyRVR
* Computer


Uploading the Basic Program to GalaxyRVR
-------------------------------------------------

To control the GalaxyRVR with the APP, you need to upload a specific program using the Arduino IDE.

Follow these steps on your computer:

.. Download Arduino IDE
.. ^^^^^^^^^^^^^^^^^^^^^^^^

.. #. Visit https://www.arduino.cc/en/software#future-version-of-the-arduino-ide .

.. #. Download the IDE for your OS version.

..     .. image:: img/sp_001.png

.. #. Install it.

..     .. image:: img/sp_005.png


Uploading the Adapted Code
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#. Turn on the GalaxyRVR's power switch.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_start.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Connect the Arduino and computer with a USB cable, and then turn the **upload** switch of the car to the upload end.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

    .. note:: It is the USB Type B port for connecting to Arduino, not the USB Type C port for charging.

#. Check if you have completed :ref:`update_firmware` section.

#. Open the downloaded ``galaxy-rvr-1.2.0 folder``. (It has been downloaded and installed in the previous step), double-click to run the ``update-arduino-firmware.bat`` script. A command prompt will open.

    .. image:: ../img/firmware/updateFirmware.png

#. In the command prompt, you will see a serial port list showing the serial ports that the computer is currently connected to. Enter the sequence number on the left side of the serial port list to select the serial port of the Arduino Uno. Press Enter to automatically upload.

    .. image:: ../img/firmware/selectCOM.png

#. After waiting for the upload to complete, you can unplug the USB cable.

    .. image:: ../img/firmware/UNOupdating.png

#. Turn the upload switch back and press the reset button, and the car is ready to use.


    .. note:: This code enables the GalaxyRVR to respond to APP commands. You won’t need to upload any more code in the subsequent chapters that use the Mammoth Coding APP.


.. _app_connect:

Connecting the APP to GalaxyRVR
-------------------------------------------

1. To activate the ESP32 CAM, move the mode switch to the **Run** position, and press the **reset** button to reboot the R3 board. You will then observe a cyan light flashing on the bottom strip.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

2. Connect your mobile device (e.g., phone, tablet) to the WiFi hotspot provided by GalaxyRVR. Generally, its SSID is ``GalaxyRVR`` and the password is ``12345678``.


    .. image:: ../img/firmware/SSID.png

    .. note:: The default connection mode is **AP mode**. After you've connected, there might be a prompt warning that there is no internet access on this network. If so, choose "Stay connected".

        .. image:: ../img/app/camera_stay.png


3. Open the APP. Click here.

    .. image:: img/connet_app_04.png


4. Load the GalaxyRVR module.

    .. image:: img/connet_app_05.png

5. The APP will search for your robot.

    .. image:: img/connet_app_06.png

6. Connect it.

    .. image:: img/reconnect_2.png

    .. note:: The breathing light on the GalaxyRVR can help indicate the connection status. Flashing yellow means no devices are connected. A steady blue light means it’s connected.


Re-connect APP
-------------------------------------

When your device is disconnected from GalaxyRVR, you will see this pop-up window appear in the interface. Click reconnect.

    .. image:: img/reconnect_0.png

If you close the pop-up window, you can also reconnect by clicking this button in the GalaxyRVR category.

    .. image:: img/reconnect_1.png

Find your GalaxyRVR and click connect.

    .. image:: img/reconnect_2.png


Controlling the GalaxyRVR with the APP
-----------------------------------------

1. In the Code interface, you'll find the GalaxyRVR category.

    .. image:: img/3_rvr_catego.png

2. We've previously used the green flag to start programs. 
During this process, you'll notice several blocks in the Events category that trigger code execution. 
Find the ``when up arrow key pressed`` block.

    .. image:: img/3_rvr_when_arrow.png

3. Drag out four of these blocks, one for each arrow key event (up, down, left, right).

    .. image:: img/3_rvr_4_arrow.png

    .. note:: You can click the eye icon below the green flag to hide the stage area and gain more coding space.

4. Complete the code blocks for these four events. When the up arrow is pressed, make the GalaxyRVR move forward; when the left arrow is pressed, make it turn left, etc.

    .. image:: img/3_rvr_4_dir.png

5. Expand the stage by clicking this button.

    .. image:: img/3_rvr_stage.png

6. You'll enter an interface with an enlarged stage and a set of direction keys.

    .. image:: img/3_rvr_stage2.png

Press these direction keys and you'll be delighted to see you can directly control the GalaxyRVR.

Blocks Related to Movement
-----------------------------

.. image:: img/block/move_forward.png 
..    :align: center

After executing this block, the GalaxyRVR will move forward. You can:

    * Change the parameter from the dropdown menu to turn left, turn right, or reverse.


.. image:: img/block/move_set_speed.png     
..    :align: center

This block is used to set the moving speed of the GalaxyRVR. It does not initiate movement by itself.

.. image:: img/block/move_forward_1s.png 
..    :align: center

After executing this block, the GalaxyRVR will move forward for 1 second. You can:
    
    * Change the parameter from the dropdown menu to turn left, turn right, or reverse.
    * Adjust the number in the block to set the duration of GalaxyRVR’s movement.


.. image:: img/block/move_forward_80.png    
..    :align: center

After executing this block, the GalaxyRVR will move forward at 80% speed. You can:
    
    * Change the parameter from the dropdown menu to turn left, turn right, or reverse.
    * Modify the number in the block to adjust the speed of GalaxyRVR during this movement.

.. image:: img/block/move_forward_80_1s.png 
..    :align: center

After executing this block, the GalaxyRVR will move forward at 80% speed for 1 second. You can:
    
    * Change the parameter from the dropdown menu to turn left, turn right, or reverse.
    * Adjust the time in the block to set the duration of the movement.
    * Modify the speed in the block to adjust the speed of GalaxyRVR during this movement.

.. image:: img/block/move_lr_sp_1s.png 
..    :align: center

After executing this block, you can independently set the speeds of the GalaxyRVR's left and right wheels and move for the specified time. You can:
    
    * Modify the left speed to set the running speed of GalaxyRVR’s left wheel.
    * Modify the right speed to set the running speed of GalaxyRVR’s right wheel.
    * Adjust the time to determine the duration of the movement.

.. image:: img/block/move_stop.png
..    :align: center

Stops the GalaxyRVR from moving.

