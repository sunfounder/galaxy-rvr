.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!




Lesson 9 Mars Exploration Partner
====================================================


With our Rover now capable of avoiding obstacles, let's enhance it further by making it follow objects. Our goal is to modify our existing code to make the Rover move towards a moving object.

Ever wondered about the differences between a following system and an obstacle avoidance system?

The key here is that in a following system, we want our Rover to move in response to detected objects, while in an obstacle avoidance system, we're looking to steer clear of detected objects.


Learning Objectives
-------------------------

* Combine ultrasonic and infrared obstacle avoidance modules to implement the following functionality in the Mars rover model.
* Learn how to program the Mars rover model to automatically follow a target.


Materials
-----------

* Smartphone or tablet
* Mammoth Coding APP
* GalaxyRVR


Coding the Intelligent Following System
-------------------------------------------------------

1. Use the code block from :ref:`ir_ultra_avoid` as a template and open it from the saved project.

.. image:: img/8_follow_open.png

2. Then, save it as a copy.

.. image:: img/8_follow_save_copy.png

3. Rename the project and save it.

.. image:: img/8_follow_save_rename.png

4. First, remove the forward block at the end of each code block, as the rover should stop after each sensor event.

.. image:: img/8_follow_save_remove_forward.png

5. Next, modify the turning directions of the two IR events, as the GalaxyRVR needs to follow the direction of the target.

.. image:: img/8_follow_save_re_turn.png

6. Finally, modify the ultrasonic sensor events. Instead of backing up to a safe distance and turning, it should now move forward until the target moves out of range.

.. image:: img/8_follow_save_re_ultra.png

Now, the GalaxyRVR will move along with your steps. When you are beside it, it will turn to face you. If you are in front of it, it will move towards you. If it cannot detect you, it will stay still.

