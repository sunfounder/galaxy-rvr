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


.. _update_uno_firmware:

1. Updating the UNO R3 Firmware
-------------------------------------

The R3 board carries the firmware that talks to the RoboPilot app and Mammoth Coding. Reinstall it with the web-based flasher: it runs in your browser, needs no extra software, and shows each step with its own picture.

#. Power on the rover, connect the **main board** to your computer with the USB A to B cable (not the Type-C one), and turn the mode switch to **Upload**. The switch also selects the USB-to-serial connection, so the ESP32 CAM does not need to be removed.

#. On a computer, open |link_galaxy_rvr_flasher| in **Chrome** or **Edge** and simply follow the **Connect → Flash → Done** steps on the page.

#. When it is finished, turn the switch back to **Run** and press the **Reset** button on the R3 board.

.. note::

   * The page asks for the firmware version and the serial port itself (**Arduino UNO R3**, or **USB-SERIAL CH340** on CH340 boards) — see the pictures there.
   * Use **Chrome** or **Edge** on a computer over **https** (Web Serial), and close other programs that hold the serial port. If the flash fails, unplug the USB cable, plug it back in, keep the switch on **Upload**, and click again — re-flashing does not damage the rover.

.. _verify_r3_firmware:

Verifying the Update
~~~~~~~~~~~~~~~~~~~~

Back in **Run** mode, the log window on the flasher page shows the rover booting. The update is successful when:

* The first line reads ``GalaxyRVR version X.Y.Z``, followed by ``Initialzing...`` and ``Okie!`` — the page writes **2.0.2**.
* The light strip under the rover flashes **green** on boot.

The same log shows the camera version as ``ESP32 firmware version X.Y.Z``. If it is lower than **1.5.4**, or the strip flashes **red**, move on to :ref:`update_esp32_firmware`.


.. important::

   * This firmware enables the GalaxyRVR to respond to app commands.
   * You won’t need to upload any additional code when using either the RoboPilot remote control app or the Mammoth Coding software.
   * You can now proceed to :ref:`quick_start` to start your GalaxyRVR journey!

.. _update_esp32_firmware:

2. Updating the ESP32 CAM Firmware
--------------------------------------

The ESP32 CAM broadcasts the Wi-Fi hotspot and captures video for the GalaxyRVR. If it is older than **1.5.4**, or the light strip under the rover does not flash green on boot, update it by following the steps below.

.. note::

   The ``ESP32 firmware version X.Y.Z`` line in the flasher's log window tells you which version is currently installed.

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


Select the firmware file you downloaded and start the update:

* On the older interface, click **Add**, then **Update**.
* On the newer interface, tap **Upgrade Firmware** and then **CONFIRM** when it finishes.

The update takes 1–2 minutes. Afterwards the hotspot name changes to ``AI Camera-xxxxxx`` (password ``12345678``), so reconnect to it before continuing.

.. note::

   The OTA page shows one of two interfaces depending on the firmware version you have; both do the same thing.

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center

