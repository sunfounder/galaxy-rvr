FAQ
==============

Compilation error: SoftPWM.h: No such file or directory？
---------------------------------------------------------------------
If you get a “Compilation error: SoftPWM.h: No such file or directory” prompt, it means you don’t have the SoftPWM library installed.

Please install the two required libraries ``SoftPWM`` and ``SunFounder AI Camera`` as shown.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>


avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e?
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