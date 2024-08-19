.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

Lesson 13 Realtime Control
=======================================

We have now explored most of the features of the GalaxyRVR. 
To complete our journey and transform the GalaxyRVR into a fully functional robot, 
we need to combine the three main parts we've covered.


    * :ref:`camera_system` : This part includes the camera and LED control features.

    * :ref:`rgb_move` : This section includes movement and lighting effects.

    * :ref:`tilt_system` : This part involves adjusting the direction of the camera gimbal.

Put it all together and you can click the sprites to turn the camera and LED on or off, and use the arrow keys to move the GalaxyRVR.

.. image:: img/13_camera_go_all2.png


**Camera System**
------------------------------------


For this part, repeat the steps from :ref:`camera_system`.

1. create four new sprites to control the camera and its LED. Adjust their sizes to make them look harmonious.

.. image:: img/11_camera_4.png
.. :align: center

2. Program each sprite: clicking ball 1 will turn off the camera.

.. image:: img/11_camera_1sp.png
.. :align: center

3. Clicking ball 2 will turn on the camera and set the image orientation.

.. image:: img/11_camera_2sp.png
.. :align: center

4. Clicking ballon 3 will turn on the LED.

.. image:: img/11_camera_3sp.png
.. :align: center

5. Clicking ballon 4 will turn off the LED.

.. image:: img/11_camera_4sp.png
.. :align: center

6. To save space on the stage, stack each set of controls.

.. image:: img/11_camera_fold.png
.. :align: center

7. Add a ``go to back layer`` block for each sprite. When clicked, the sprite will move to the back layer, revealing the next sprite, creating a toggle effect.

.. image:: img/11_camera_layer.png
.. :align: center




**Move & RGB System**
----------------------------------



Let's enhance the movement functionalities. We have already coded these in the :ref:`rgb_move` section.

We recommend placing these code blocks in the Backdrops. This way, modifying the sprite's code won't affect this functionality.

.. image:: img/13.ccc_code_in_stage.png

1. Let GalaxyRVR turn on the green light when moving forward.

.. image:: img/13.ccc_light_forward.png


2. Let GalaxyRVR turn on the red light when moving backward.

.. image:: img/13.ccc_light_left_right.png

3. Let GalaxyRVR turn on the yellow light when turning left or right.

.. image:: img/13.ccc_light_backfwd.png

4. Let GalaxyRVR turn on the breathing light when not moving.

.. image:: img/13.ccc_light_breath.png

Finally, your code should be as follows. 
Please note that these codes should be written in Backdrops.

.. image:: img/11_camera_backdrops.png



**Tilt System**
------------------------


This part is the same as the :ref:`tilt_system`. Simply repeat the steps.

1. Add an Arrow sprite. We will set the gimbal direction based on its orientation.

.. image:: img/10_servo_arrow.png


2. A ``when this sprite clicked`` block is exactly what we need.

.. image:: img/6_animate_when_touch.png
    :width: 230


3. Let the program repeat until we release it, meaning we no longer touch the sprite.

.. image:: img/6_animate_repeat_touching.png
    :width: 550

4. Drag a ``point towards touch_position`` block to make the sprite face the touch position.

.. image:: img/10_servo_arrow_point_toward.png

5. Drag a ``set servo angle to 90 degrees`` block and embed a ``direction`` block to align the gimbal angle with the arrow sprite's orientation. This way, when we change the arrow sprite's direction (i.e., touch the stage area), we can change the gimbal angle.

.. image:: img/10_servo_arrow_angle_direction.png

6. Add a limit check to ensure the arrow sprite's orientation does not exceed 135 degrees.

.. image:: img/10_servo_arrow_135.png


7. Similarly, ensure its orientation does not go below 0 degrees.

.. image:: img/10_servo_arrow_0.png


Touch the sprite, and it will change direction as you drag, altering the gimbal angle.

If you find it easy to slide your finger off the arrow sprite, you can increase the sprite's size accordingly.








