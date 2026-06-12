.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


.. _programming_scratch:

Programmierung mit Scratch
==========================

Neben der Programmierung mit der Arduino IDE können wir auch die grafische Programmierung verwenden.

Wir empfehlen Scratch für die Programmierung.
Die offizielle Scratch-Version unterstützt derzeit jedoch nur Raspberry Pi. Aus diesem Grund haben wir Mammoth Coding entwickelt,
eine grafische Programmiersoftware auf Basis von Scratch 3, speziell für Arduino-Boards (Uno, Mega2560 und Nano).

Mammoth Coding behält die grundlegenden Funktionen von Scratch 3 bei und erweitert sie um die Möglichkeit, verschiedene Boards wie Arduino Uno,
Mega, Nano und benutzerdefinierte Boards zu steuern. Sie können externe Sensoren und Roboter verwenden, um die Sprites auf der Bühne zu steuern, und so leistungsstarke Hardware-Interaktionen umsetzen.

Darüber hinaus ist diese App auch ohne große Programmiererfahrung einfach zu bedienen. Sie können diese modernsten Technologien leicht erlernen und nutzen.

Ziehen Sie einfach Scratch-Codeblöcke per Drag & Drop, um spannende Spiele, Animationen, interaktive Projekte zu erstellen und sogar Roboter genau nach Ihren Vorstellungen zu steuern!

Starten wir jetzt diese Entdeckungsreise!


**Code herunterladen**


.. note::

    Alle Scratch-Skripte für die folgenden Projekte wurden auf GitHub hochgeladen. Sie können sie über den angegebenen Link herunterladen. Alle ``.sb3``-Skriptdateien befinden sich im Ordner ``galaxy-rvr-main/scratch_codes/``.

   * |download_galaxyrvr_code|

Oder sehen Sie sich den Code auf `SunFounder GalaxyRVR Kit for Arduino - GitHub <https://github.com/sunfounder/galaxy-rvr/tree/1.2>`_ an.


**Grundlegende Projekte**

Diese Projekte sind die Basiskurse zur Steuerung des GalaxyRVR mit Mammoth Coding. Sie führen Sie Schritt für Schritt in die Nutzung des GalaxyRVR ein.

.. toctree::
    :maxdepth: 1


    sc1_history
    sc2_app
    sc3_rvr_move
    sc4_ultrasonic
    sc5_animate
    sc6_obstacle
    sc7_obstacle_animate
    sc8_avoid
    sc9_follow
    sc10_rgb
    sc11_servo
    sc12_camera
    sc13_all


**Spaßprojekte**

Hier sind einige unterhaltsame Projekte, die keinen GalaxyRVR benötigen – Sie können sie direkt umsetzen.

.. toctree::
    :maxdepth: 1

    fun/sc_fun_balloon
    fun/sc_fun_flappy_parrot
    fun/sc_fun_shooting
    fun/sc_fun_eat_apple
    fun/sc_fun_fish
    fun/sc_fun_sensitive_ball
    fun/sc_fun_tap_tile
