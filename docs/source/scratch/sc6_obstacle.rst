.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!



.. _ir_obstacle:


Lesson 6 IR Obstacle
===========================

We're diving into the world of the Infrared Obstacle Avoidance Module. Tucked at the sides of our Mars Rover, these sensors act as the rover's "eyes," helping it dodge side obstacles and safely navigate the Martian landscape.

We'll learn how to integrate these modules with our rover, unravel the magic behind their functioning, and develop code to make our rover smartly sidestep any hurdles it comes across.

Get ready to gear up our rover with some Martian obstacle-dodging intelligence! Let's get rolling!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_ir1.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Learning Objectives
-------------------------

* Understand the working principles of the Infrared Obstacle Avoidance Module and its application in the Mars rover.
* Learn how to read and apply data from the Infrared Obstacle Avoidance Module in Scratch.
* Create a Mars exploration-themed obstacle avoidance game using the IR module and the Scratch stage.


Materials
-----------

* Smartphone or tablet
* Mammoth Coding APP
* GalaxyRVR

Demystifying the Module
-------------------------------------

Meet the Infrared Obstacle Avoidance Module - our rover's smart sidekick. This little device is a pack of wonders. Let's take a tour:

.. image:: ../img/ir_avoid.png
    :width: 300
    :align: center


Here are the pin definitions:

* **GND**: This is like the module's anchor, connecting it to the ground or common point in the circuit.
* **+**: Here's where the module gets its energy, needing a power supply of 3.3 to 5V DC.
* **Out**: This is the module's communicator. By default, it stays high and only goes low when it spots an obstacle.
* **EN**: Meet the module's controller. This **enable** pin decides when the module should work. By default, it is connected to GND, meaning the module is always on the job.


Curious about how this tiny module works? It's quite interesting! It uses a pair of IR components - a transmitter and a receiver. The transmitter is like the module's flashlight, emitting infrared light. 
When an obstacle appears, the infrared light bounces back and gets caught by the receiver. The module then gives a low signal, alerting our rover of the obstacle.

.. image:: ../img/ir_receive.png
    :align: center

Our little module is quite robust, spotting obstacles within a range of 2-40cm and boasting excellent anti-interference abilities. 
However, the color of objects does impact its sensing. Darker objects, especially black ones, are detected at a shorter range. 
Against a white wall, the sensor is most efficient, sensing within the 2-30cm range.


The **EN** pin's low-level state activates the module, with the jumper cap securing the **EN** pin to the GND. If you wish to control the **EN** pin via code, the jumper cap needs to be removed.

.. image:: ../img/ir_cap.png
    :width: 400
    :align: center

There are two potentiometers on the module, one for adjusting the transmitting power and one for adjusting the transmitting frequency, and by adjusting these two potentiometers you can adjust its effective distance.

.. image:: ../img/ir_avoid_pot.png
    :width: 400
    :align: center 


That's quite a bit about our little module. In the next step, we'll learn how to integrate it with our rover and control it using the Arduino. Stay tuned!



Infrared Obstacle Avoidance Module Detection Values
------------------------------------------------------------

1. Power up the GalaxyRVR.


.. raw:: html

   <br></br>

2. We have arrived at an essential step, which is to adjust the detection distances of our sensors based on our current environment. The factory settings may not be optimal. If the detection distance of the two infrared modules is too short, the Mars Rover might collide with obstacles. If it's too far, the Rover might start turning while still a significant distance from an obstacle, potentially impacting its movement.

    Here's how you can make adjustments:

    a. Start by adjusting the right obstacle avoidance module. During transportation, collisions may cause the transmitter and receiver on the infrared module to tilt. Therefore, you need to manually straighten them.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    b. Place an obstacle about 20 cm directly in front of the right module. The box in which our Rover kit came is a good choice for this! Now, turn the potentiometer on the module until the indicator light on the module just lights up. Then, keep moving the obstacle back and forth to check if the indicator light comes on at the desired distance. If the light doesn't turn on at the correct distance or if it remains on without going out, you'll need to adjust the other potentiometer.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>


    c. Repeat the same process for another module.



3. Let's see what these two signals are. First, :ref:`app_connect`.

.. raw:: html

   <br></br>


4. In the GalaxyRVR category, find the left IR status and right IR status blocks. These store the detection results of the IR modules. Make sure to check the boxes for these.

    .. image:: img/4_ir_statusblock.png

5. The values will now be displayed on the stage.

    .. image:: img/4_ir_statusvalue.png

6. Move your hand close to the infrared obstacle avoidance modules to trigger detection and observe the value changes on the stage.

If the IR modules detect an obstacle, the value will be True; if no obstacle is detected, the value will be False.



Responding to the Infrared Obstacle Avoidance Module
-------------------------------------------------------------

We can utilize the infrared obstacle avoidance modules to make the GalaxyRVR automatically dodge obstacles on both sides.


1. Drag in a green flag block

.. image:: img/4_ir_start.png

2. Set the speed. Here we set the speed to 30%, so it isn't too fast, making it easier to debug.

.. image:: img/4_ir_speed.png


3. Find the ``when left IR is blocked`` block.

.. image:: img/4_ir_when_blocked.png

4. When the left side detects an obstacle, the GalaxyRVR should turn right.

.. image:: img/4_ir_turn_right.png

5. Keep turning right until the left side no longer detects the obstacle.

.. image:: img/4_ir_wait_until.png


6. Stop moving.

.. image:: img/4_ir_stop.png


7. Once you have assembled these blocks, try triggering the left infrared obstacle avoidance module with your hand. The GalaxyRVR will smartly turn right to avoid your hand.

.. raw:: html

   <br></br>



8. Long-press these blocks to bring up a menu, where you can duplicate the code.

.. image:: img/4_ir_duplicate.png

9. In the duplicated code, swap the left and right sides.

.. image:: img/4_ir_left_right.png

10. You will notice that if both IR events are triggered simultaneously, the behavior may become erratic. To prevent this, the "stop other scripts in sprite" block will come in handy. It ensures that only one sensor event is responded to at a time.

.. image:: img/4_ir_stop_script.png

.. note:: The stop scripts block and blocks with time parameters (e.g., forward for 1 sec) can conflict in some cases, so avoid using them together when possible.


11. Now, the GalaxyRVR will turn left or right when obstacles are detected on either side. You can now test this by triggering both sensors with your hand to make the GalaxyRVR dodge left and right.


.. raw:: html

   <br></br>


12. Add a forward block under each code block so that the GalaxyRVR continues to move forward after avoiding the obstacle.

.. image:: img/4_ir_avoid_move.png


Now, click the green flag, and the GalaxyRVR will move forward continuously, turning to avoid obstacles and resuming its path after avoiding them.



Blocks Related to the IR Module
----------------------------------------

.. image:: img/block/ir_when.png

This is an event block triggered when the left IR sensor detects an obstacle. You can:

    * Change "left" to "right" in the dropdown menu

.. image:: img/block/ir_wait_until.png

This block pauses the program until the left IR sensor no longer detects an obstacle, then continues. You can:

    * Change "left" to "right" in the first dropdown menu
    * Change "is not" to "is" in the second dropdown menu to operate under the opposite condition

.. image:: img/block/ir_condition.png

This is a conditional block that returns TRUE if the left IR sensor detects an obstacle, otherwise FALSE. It is commonly used in blocks requiring conditionals like ``if``. You can:

    * Change "left" to "right" in the dropdown menu

.. image:: img/block/ir_left_value.png

This block displays whether the left IR sensor currently detects an obstacle.

.. image:: img/block/ir_right_value.png

This block displays whether the right IR sensor currently detects an obstacle.

