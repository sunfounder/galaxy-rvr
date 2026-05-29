.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lesson 9: Mars Exploration Partner
====================================================

Now that our Rover can skillfully avoid obstacles, let's teach it a new trick - following a target! In this mission, we'll transform our obstacle-avoiding rover into a loyal companion that can follow you around.

What's the difference between following and avoiding?

- **Avoiding**: Steer away from objects (like dodging rocks)
- **Following**: Move toward objects (like following a friend)

Get ready to code your very own Mars exploration buddy!

Learning Objectives
-------------------------

* Combine ultrasonic and infrared sensors to create a following rover
* Program your Mars Rover to automatically track and follow a moving target

Creating Your Following Rover
-------------------------------------------------------

#. First, :ref:`app_connect`.

#. Now, open your saved project in Lesson 8.

   .. image:: img/8_follow_open.png

#. Save a copy to keep your original project safe. Click "Save as a copy."

   .. image:: img/8_follow_save_copy.png

#. Give your new project a fun name like "Mars Follower" or "Rover Buddy."

   .. image:: img/8_follow_save_rename.png

#. Remove the "move forward" blocks from the end of each sensor event. Our follower should stop and wait after each action.

   .. image:: img/8_follow_save_remove_forward.png

#. Now let's reprogram the IR sensors! Change the turning directions so the rover turns TOWARD the target instead of away from it.

   .. image:: img/8_follow_save_re_turn.png

#. Finally, update the ultrasonic sensor behavior. Instead of backing away, make it move FORWARD when it detects a target in front.

   .. image:: img/8_follow_save_re_ultra.png


Amazing! Your GalaxyRVR is now your Mars exploration partner. Test it out:

- Walk beside it → it turns to face you
- Stand in front → it moves toward you  
- Move away → it stops and waits

Your rover buddy is ready to follow you on your next space adventure!