.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

4 RGB LEDs Strip
====================

.. image:: img/4_rgb_strip.jpg


* **+5V**: Common anode of the three LEDs and needs to connect to DC 5V
* **B**: Cathode of the blue LED
* **R**: Cathode of the red LED
* **G**: Cathode of the green LED

This RGB LED strip features four R5050 RGB LEDs, capable of creating any color shade by combining the three primary colors: red, blue, and green.

The R5050 RGB LEDs are designed with a common anode configuration. Each LED on the strip functions as an independent circuit, allowing you to cut the strip at designated points without affecting other sections. The strip's flexibility and adaptability are enhanced by its construction on an FPC board, which is backed with double-sided adhesive for easy installation.


**What is R5050 RGB LED?**

The R5050 RGB LED is a type of LED that combines red, blue, and green light-emitting diodes in a single package. Each LED within this package has its own pin, allowing for individual control. This configuration enables the production of a wide range of colors by varying the intensity of each LED.

.. image:: img/rgb_5050.jpg
    :width: 400

.. image:: img/rgb_5050_sche.png
    :width: 200

In a typical application, multiple R5050 RGB LEDs are arranged on a flexible circuit in a smart configuration. This is done by connecting the "positive" ends (anodes) of all LEDs together, while the "negative" ends (cathodes) are connected to their respective color lanes. This means that all green cathodes are connected together, all red cathodes are connected together, and all blue cathodes are connected together. This arrangement allows for efficient control of color blending and light intensity, making these LEDs popular in applications where customizable color lighting is desired, such as in decorative lighting, signage, and display technologies.

.. image:: img/rgb_strip_sche.png



**Features**

* Work Voltage: DC5V
* Color: Full color RGB
* Working Temperature: -15-50
* RGB Type: 5050RGB
* Current: 150mA (single circuit)
* Power: 1.5W
* Light Strip Thickness: 2mm
* Light Strip Width: 5.5mm
* Cable: ZH1.5-4P, 25cm, 28AWG, Black
