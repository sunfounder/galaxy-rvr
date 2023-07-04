
Lesson 10: Exploring the Mars Rover Visual System - Servo and Tilt Mechanism
===================================================================================

Welcome back, young explorers! In today's adventure, we are going to delve into the fascinating world of the Mars Rover's visual system. 
Just like our eyes and neck work together to help us see and navigate our surroundings, our Rover too needs a similar system to 
navigate the treacherous Martian landscape. And that's exactly what we are going to build today!

The visual system of our Rover has two main parts: a camera that acts as its "eyes", and a tilt mechanism that acts like a "neck", 
allowing it to look up and down. By the end of this lesson, we'll give our Rover the ability to "see" and "nod"!

First, we'll build the tilt mechanism - a device that will hold our Rover's camera and let it rotate vertically. 
It's like giving our Rover a neck, so it can nod its "head" or camera up and down!

Next, we'll learn about the servo, the tiny yet powerful "muscle" that moves our tilt mechanism. 
We'll understand how it works and how we can control it using Arduino programming.

Just as our neck muscles move our head so our eyes can get a better view, the servo will move the tilt mechanism so the Rover's 
camera can better survey the Martian landscape.

So, buckle up, explorers, let's start our mission to equip our Rover with its very own visual system!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/servo_range.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

Objective
----------------

* Practice installing and operating the tilt mechanism on the Mars Rover model.
* Understand the principles of operation and application of servo.
* Learn how to control servo movement through Arduino programming.

Materials
---------------

* Arduino UNO development board
* Servo
* Gimbal and camera
* Mars Rover model (already equipped with TT motor, suspension system, ultrasonic and infrared obstacle avoidance modules, RGB LED strip)
* Arduino IDE
* Computer

Steps
-----------

**Step 1: What is a Servo?**

Have you ever watched a puppet show? If you have, you might have marveled at how the puppeteer can make the puppet's arms, legs, and head move so smoothly, just by pulling on some strings. In a way, servo motors are like our puppeteers.

.. image:: img/puppet_show.png
    :width: 200
    :align: center

Servo motors are special type of motors that don’t just spin around and around like a wheel. Instead, they can move to a specific position and hold that position. Imagine if you're playing a game of Simon says, and Simon says, "Raise your arm to a 90-degree angle!" You can do it, right? That's because, like a servo, you can control exactly how much to move your arm.

.. image:: img/servo.png
    :align: center

* Brown Line: GND
* Orange Line: Signal pin, connect to the PWM pin of main board.
* Red wire: VCC

Just like you can control your arms to move to specific positions, we can use servo motors to control the exact position of objects in our projects. In our Mars Rover, we will use a servo to control the up and down movement of our tilt mechanism, just like how you can nod your head up and down.

In the next step, we will go on a fascinating journey inside a servo motor to understand how it works. Excited? Let's go!

**Step 2: How does a Servo Work?**

So how does a servo work its magic? Let's go on an exciting journey inside a servo!

If we were to peek inside a servo, we would see a few parts. At the heart of a servo is a regular motor, very similar to the motors that spin our Mars Rover's wheels. Wrapped around the motor, there is a big gear that is connected to a smaller gear on the motor shaft. This is how the motor's fast, circular motion gets transformed into slower but stronger motion.

.. image:: img/servo_internal.png
    :align: center

But that's not what makes a servo special. The magic happens in a tiny piece of electronics called a "potentiometer" and the "control circuitry". Here's how it works: when the servo moves, the potentiometer turns and changes its resistance. The control circuitry measures this change in resistance and knows exactly what position the servo is in. Clever, isn't it?

To control a servo, we send it a special kind of signal called a "pulse-width modulation" signal or PWM. By changing the width of these pulses, we can control exactly how much the servo moves and hold it in that position.

In the next step, we'll learn how to control a servo using an Arduino. Ready for some magic spells in the form of code? Let's go!

**Step 3: Controlling a Servo using Arduino**

Alright, explorers, now that we know how a servo works, let's learn how to control it using our magic wand, the Arduino!

Controlling a servo is like giving it directions. Remember the pulse-width modulation (PWM) signals we mentioned earlier? We are going to use those to tell the servo where to move.

Luckily, Arduino makes this task easy for us with a built-in library called ``Servo``. With this library, we can create a ``Servo`` object, attach a pin to it (the pin that our servo is connected to), and then use a simple command, ``write()``, to set the angle.

Here's a snippet of what the code looks like:

.. code-block:: arduino

    #include <Servo.h> 

    Servo myServo;  // create a servo object

    void setup() {
        myServo.attach(6);  // attaches the servo on pin 6
    }

    void loop() {
        myServo.write(90);  // tell servo to go to 90 degrees
    }

In this code, ``myServo`` is our Servo object, ``attach(6)`` tells the Arduino that our servo is connected to pin 6, and ``write(90)`` tells the servo to move to 90 degrees.

Great job, explorers! You've just learned how to control a servo motor with Arduino. You can experiment with different angles too! 

**Step 4: Assemble the Visual System**

You're now ready to assemble the visual system of our Rover.

.. note::

    * When inserting the ESP32 CAM into the Camera Adapter, be aware of its orientation. It should align properly with the ESP32 Adapter.

    .. image:: img/esp32_cam_direction.png
        :width: 300
        :align: center
    
.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/YCmkalk8ebk" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Step 5: Understanding the Limits of the Tilt Mechanism**

Even though servo is designed to rotate between 0 and 180 degrees, you may notice that it stops responding beyond a certain point (let's say after 150 degrees). Have you ever wondered why this happens? Let's explore this mystery together in our next adventure!


Can you imagine a bird trying to bend its neck too much that it hits its own body and can't move any further? Our Rover's tilt mechanism faces a similar situation. As the servo moves the mechanism downwards, it can bump into the body of our Rover and can't go beyond a certain angle.

If we try to force it to move beyond this point by writing an unreachable angle in our code, our little servo birdie can get stuck and even damage itself! We don't want that to happen, do we? So, let's understand its movement limitations with a little experiment.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/848c7a3a-16b2-4a7e-8d66-bb91848bc6d9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

We use a for loop to rotate the servo from 0 to 180 degrees while keeping a note of the angle in the Serial Monitor.

After we upload this code, the servo starts to rotate from 0°. On my Rover, the tilt mechanism could go up to around 140° before it hit the body of the Rover and couldn't go any further.

.. image:: img/servo_range.png

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/servo_range.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

So, explorers, always remember to respect the limits of your rover to keep it safe and functioning!


**Step 6: Sharing and Reflection**

Well done, explorers! Today, you've not only built a tilt mechanism for your Rover but also understood how to control a servo to move it around. That's a big step forward in our Mars Rover mission.

Now, let's share our experiences and reflect on what we've learned. 

Did you encounter any challenges while setting up the tilt mechanism or programming the servo? How did you overcome them?

Remember, every challenge we overcome makes us smarter and our Rover better. So don't hesitate to share your stories, ideas, and solutions. You never know, your innovative solution might help a fellow explorer in their journey!
