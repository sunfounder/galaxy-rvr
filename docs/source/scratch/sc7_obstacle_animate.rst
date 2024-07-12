.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!






Lesson 7 IR Obstacle Animate
=====================================================

Previously, we used the Infrared Obstacle Avoidance Module to make GalaxyRVR automatically avoid obstacles, just like on a Mars exploration mission.

In this activity, we will combine the obstacle avoidance module with a stage to create an animation of a rover dodging rocks on Mars.


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="./_static/video/sc_animate_rock.wmv" type="video/wmv">
      Your browser does not support the video tag.
   </video>



Learning Objectives
-------------------------

* Gain a deeper understanding of the Infrared Obstacle Avoidance Module and its application in the Mars rover.
* Learn how to read and apply data from the Infrared Obstacle Avoidance Module in Scratch.
* Create a Mars exploration-themed obstacle avoidance game using the IR module and the Scratch stage.


Materials
-----------

* Smartphone or tablet
* Mammoth Coding APP
* GalaxyRVR


Creating the Animation
--------------------------------------

1. First, we need a Mars-themed stage background. Click to select a backdrop.

.. image:: img/5_animate_choose.png

2. Choose the Mars background.

.. image:: img/5_animate_mars.png

3. Select the GalaxyRVR sprite from the library and adjust its size.

.. image:: img/5_animate_rvr.png

4. Select a rock sprite from the library and adjust its size.

.. image:: img/5_animate_rock.png


5. Next, let's program these two sprites:



**GalaxyRVR Sprite**

The task for the GalaxyRVR sprite is to move slowly from the left side to the right side of the screen. If it touches a rock sprite, it will stop moving.
During this process, we can trigger the two IR sensors on the physical rover with our hands. Triggering the right sensor makes the sprite move down a bit; triggering the left sensor makes it move up a bit.



a. When the green flag is clicked, it should appear on the far left of the screen. You can first move the sprite to the corresponding position on the stage, and the coordinate values of the block in the motion category will change accordingly.

.. image:: img/5_animate_glide.png

b. Place a forever block as the main loop.

.. image:: img/5_animate_forever.png

c. Drag a conditional block to check if it is touching the rock sprite.

.. image:: img/5_animate_touching.png

d. If it is not touching, it moves forward.

.. image:: img/5_animate_moving.png

e. If it touches, it stops and emits a shout.

.. image:: img/5_animate_say.png

f. Finally, add two events. When the left or right IR sensors detect an obstacle (your hand), the sprite moves up or down.

.. image:: img/5_animate_y.png


**Rocks Sprite**

The task for the rock sprite is simpler. It can either stay in place, appear at random locations, or create multiple clones to increase the difficulty for the GalaxyRVR sprite.

a. Create its clones.

.. image:: img/5_animate_clone.png

b. Then move to a random position. Combine these two blocks and click them. You'll notice new rocks appearing randomly on the stage.

.. image:: img/5_animate_clone_move.png

c. Generate ten random rocks.

.. image:: img/5_animate_clone_10.png

d. These actions occur when the green flag is clicked.

.. image:: img/5_animate_clone_flag.png    


Now, this mini-game is complete.

Connect GalaxyRVR to the APP (refer to :ref:`app_connet`) and click the green flag to start the game.

You will see many rocks randomly generated on the stage. Your task is to use your hands to trigger the two IR sensors,
guiding GalaxyRVR to successfully reach the right side of the stage.

