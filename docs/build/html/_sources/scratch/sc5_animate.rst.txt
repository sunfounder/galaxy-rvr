

.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

Lesson 5 Interactive Animation
===============================================

Previously, we used the ultrasonic module to make GalaxyRVR automatically avoid obstacles in its path.

In this activity, we will combine the module with a stage to create an interactive animation of a rover joyfully traversing the surface of Mars.


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_jump.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Learning Objectives
-------------------------

* Learn how to draw sprites and edit backgrounds.
* Understand basic programming concepts such as event listeners and loop structures.
* Get familiar with the APP programming environment and basic operations to create a simple animation simulating a Mars rover.

Adding New Sprites
----------------------------

#. First, :ref:`app_connect`.

#. Delete any sprites you don’t need.

   .. image:: img/6_animate_delete.png 

#. In the bottom right corner of the interface, tap the **Choose a Sprite** button to reveal four options.

   .. image:: img/5_create_sp.png

#. On smaller screens, you may need to switch to another screen to see this button.

   .. image:: img/5_create_sp0.png

The four options are:

* **Upload Sprite** – Load a sprite from your device.  
* **Surprise** – Randomly select a sprite from the library.  
* **Paint** – Draw your own sprite.  
* **Choose a Sprite** – Select from the sprite library.

Next, we will use **Choose a Sprite** to select a sprite and **Paint** to draw one.

**Choose a Sprite**

#. Tap **Choose a Sprite** (magnifier icon) to open the sprite library.

   .. image:: img/5_sp_list.png

#. Find and select **GalaxyRVR** from the library.

   .. image:: img/1_choose_galaxyrvr.png


**Paint a New Sprite**

#. Tap **Paint** (brush icon) to create a new sprite. We’ll draw a **Mars** sprite.

   .. image:: img/5_create_custom.png

#. Use the **Circle Tool** to draw a circle representing the planet.

   .. image:: img/5_create_custom1.png

#. Use the **Pointer Tool** to move the circle to the center of the canvas. This step is important because the sprite’s coordinates and movements are based on its center.

   .. image:: img/5_create_custom2.png

#. Use the **Paint Bucket Tool** to fill the circle with red.

   .. image:: img/5_create_custom3.png

#. Select the **Brush Tool**, increase the brush size, and add texture with a suitable fill color.

   .. image:: img/5_create_custom_pen.png

#. If the color doesn’t look right, change the fill color and use the **Paint Bucket Tool** again.

   .. image:: img/5_create_custom5.png

#. Select the **Brush Tool** again, set the size to 2, change the color to black, and draw craters on Mars.

   .. image:: img/5_create_custom6.png

#. Use the **Paint Bucket Tool** to fill the craters with a suitable color.

   .. image:: img/5_create_custom7.png

#. Once finished, switch back to the **Code Interface**.

   .. image:: img/5_create_custom8.png

#. On smaller screens, click the icon to return to the Code Interface.

   .. image:: img/5_create_custom8.1.png

#. You’ll now see the Mars sprite on the stage. Don’t forget to **rename** it.

   .. image:: img/5_create_custom9.png


**Stage**

#. Click on **Backdrops** to modify the background. The default white backdrop will be changed to simulate a night sky.

   .. image:: img/6_jump_backdrop.png

#. Enter the **Backdrops** interface.

   .. image:: img/6_jump_backdrop_page.png

#. Draw a rectangle on the canvas.

   .. image:: img/6_jump_rect.png

#. Use the **Paint Bucket Tool** to fill it with a dark color.

   .. image:: img/6_jump_fill.png

#. Use the **Brush Tool** to add some stars.

   .. image:: img/6_jump_paint.png


Creating the Animation
-------------------------------

Now that we have Mars and GalaxyRVR, and we know how to animate sprites, let's create an animation of GalaxyRVR moving on Mars.
We can make the sprite appear to move by rotating Mars in the opposite direction, creating the effect of GalaxyRVR moving across its surface.

#. First, :ref:`app_connect`.

#. Adjust the size and position of both sprites.  
   
   * Set the GalaxyRVR sprite to **(0, 0)** and position Mars so GalaxyRVR appears to stand on its surface.

   .. image:: img/6_jump_place.png


**Mars Sprite**

#. Select the Mars sprite. Its task is to rotate counterclockwise, creating the illusion that GalaxyRVR is moving forward.

   .. image:: img/6_ssp_mars.png

#. Drag a green flag block. All animation starts with the green flag.

   .. image:: img/6_jump_mar_flag.png

#. Drag a ``forever`` block to keep the animation running continuously.

   .. image:: img/6_jump_mar_forever.png


#. Drag a ``turn`` block and a ``wait`` block to make Mars rotate continuously.

   .. image:: img/6_jump_mar_turn.png

#. Now click the green flag, and you will see Mars rotating counterclockwise.



**GalaxyRVR Sprite**

#. Select the GalaxyRVR sprite. Its task is to animate as if it’s moving, even though it isn’t actually moving.

   .. image:: img/6_ssp_rvr.png
    
#. Drag a green flag block. All animation starts with the green flag.

   .. image:: img/6_jump_mar_flag.png

#. Drag a ``forever`` block to keep the animation running continuously.

   .. image:: img/6_jump_mar_forever.png

#. Drag a ``next costume`` block and a ``wait`` block to make GalaxyRVR continuously animate.

   .. image:: img/6_jump_mar_next.png

#. Drag a ``when distance`` block. This will trigger when the ultrasonic module detects an obstacle (e.g., your hand).

   .. image:: img/6_jump_when.png


#. Drag two ``glide`` blocks and change the y-value of the first one to make the sprite jump up and then come down, creating a jumping effect.

   .. image:: img/6_jump_glide.png

#. The complete code for the GalaxyRVR sprite should look like this:

   .. image:: img/6_jump_mar_rvr_all.png


Now, click the green flag to start the animation. Simulate an obstacle by placing your hand in front of the ultrasonic module, and the GalaxyRVR sprite will jump to avoid it.

