
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


Updating the Firmware File
======================================

1. Download the firmwarefile.

    * :download:`GalaxyRVR Firmware File <https://github.com/sunfounder/galaxy-rvr/releases/download/1.2.0/galaxy-rvr-1.2.0.zip>`

2. Connect your mobile devices (such as phones or tablets) to the WiFi hotspot emitted by the GalaxyRVR. 
Typically, the SSID is ``GalaxyRVR``, and the password is ``12345678``.

.. image:: img/firmware/SSID.png

.. note:: The default connection mode is **AP mode**. After connecting, you may receive a warning that there is no internet access on this network. If so, opt to "Stay connected".

    .. image:: img/app/camera_stay.png

3. Navigate to http://192.168.4.1 to access the ESP32 Cam firmware update interface.

.. image:: img/firmware/OTAUpdate.jpg

4. Check the version number. If your version is above ``1.5.1``, no update is necessary (skip steps 5-9). Otherwise, an upgrade is required.

.. image:: img/firmware/OTAversion.jpg

5. Transfer the file ``ai-camera-firware.ino.1.5.1.bin`` to the device.

.. image:: img/firmware/selectBin.png

6. Return to the firmware update interface. Click to select the firmware.

.. image:: img/firmware/OTASButton.jpg

7. Select the ``ai-camera-firware.ino.1.5.1.bin`` file you just stored on your mobile device, then click upgrade.

.. image:: img/firmware/OTASelect.jpg

8. Wait for the firmware upgrade to complete. Once the current version number shows as 1.5.1, the upgrade is successful.

.. image:: img/firmware/OTAFinish.jpg

9. Close the page.
