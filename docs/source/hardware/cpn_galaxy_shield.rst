GalaxyRVR Shield
=========================

.. image:: img/galaxy_shield.jpg
    :width: 500
    :align: center

Dies ist ein All-in-One-Erweiterungsboard, das von SunFounder für Arduino entwickelt wurde und verschiedene Modulanschlüsse enthält, 
wie Motor, RGB-Streifen, Hindernisvermeidung, Graustufen, ESP32 CAM und Ultraschallmodul.

Dieses Erweiterungsboard verfügt außerdem über einen integrierten Ladekreislauf, der den Akku mit PH2.0-3P Schnittstelle aufladen kann, 
und die geschätzte Ladezeit beträgt 130 Minuten.


**Pinbelegung**

.. image:: img/zeus_car_shield_pinout.png

* Charge Port
    * Nach dem Einstecken in den 5V/2A USB-C-Port kann es zum Aufladen des Akkus für 130 Minuten verwendet werden.

* **Battery Port**: 
    * 6.6V~8.4V PH2.0-3P-Stromversorgungseingang.
    * Versorgt das GalaxyRVR Shield und das Arduino-Board gleichzeitig mit Strom.

* Reset Button
    * Drücken Sie diese Taste, um das Programm auf dem Arduino-Board zurückzusetzen.

* Indicators
    * **Charge Indicator**: Leuchtet rot, wenn das Shield über den USB-C-Port aufgeladen wird.
    * **Power Indicator**: Leuchtet grün, wenn der Netzschalter in der Position "ON" ist.
    * **Battery Indicator**: Zwei orangefarbene Anzeigen repräsentieren verschiedene Batteriestände. Sie blinken während des Ladens und gehen aus, wenn die Batterie aufgeladen werden muss.

* Netzschalter
    * Auf ON schieben, um das GalaxyRVR einzuschalten.

* :ref:`shield_motor_pin`
    * **Motor Port(Right)**: 3 Motoren können angeschlossen werden, aber alle 3 Motoren werden von demselben Satz Signalen **Pins 2 und 3** gesteuert.
    * **Motor Port(Left)**: 3 Motoren können angeschlossen werden, aber alle 3 Motoren werden von demselben Satz Signalen **Pins 4 und 5** gesteuert.
    * Anschlusstyp: XH2.54, 2P.

* :ref:`shield_strip_pin`
    * Zum Anschluss von 2 RGB-LED-Streifen, die drei Pins des Streifens sind an **12, 13 und 11** angeschlossen.
    * Anschlusstyp: ZH1.5, 4P.

* :ref:`shield_avoid_pin`
    * Zum Anschluss von zwei IR-Hindernisvermeidungsmodulen.
    * Das **left obstacle avoidance module** wird an **Pin 8** angeschlossen, das **right obstacle avoidance module** an **Pin 7**.
    * Anschlusstyp: ZH1.5, 3P.

* :ref:`shield_camera_pin`
    * Der Kamera-Adapter-Board-Anschluss.
    * Anschlusstyp: ZH1.5, 5P.

* :ref:`shield_ultrasonic_pin`
    * Zum Anschluss des Ultraschallmoduls, sowohl Trig- als auch Echo-Pins sind an **Pin 10** des Arduino-Boards angeschlossen.
    * Anschlusstyp: ZH1.5, 4P.

* Mode Switch
    * Der ESP32-CAM und das Arduino-Board teilen sich dieselben RX (Empfang) und TX (Sendung) Pins. 
    * Daher müssen Sie beim Hochladen von Code diesen Schalter auf die **right side** umlegen, um den ESP32-CAM zu trennen und so Konflikte oder potenzielle Probleme zu vermeiden.
    * Wenn Sie die Kamera verwenden möchten, stellen Sie diesen Schalter auf die **left side**, sodass der ESP32-CAM mit dem Arduino-Board kommunizieren kann.

* SOLAR
    * Dies ist der Anschluss für das Solarpanel, das den Akku aufladen kann, wenn es an das Solarpanel angeschlossen ist.
    * Anschlusstyp: XH2.54, 2P.


.. _shield_ultrasonic_pin:

Ultrasonic Port
--------------------

Hier ist die Pinbelegung für den ZH1.5-4P Ultraschallanschluss, wobei die Trig- & Echo-Pins mit Pin 10 des Arduino-Boards verbunden sind.

.. image:: img/ultrasonic_shield.png

.. _shield_camera_pin:

Camera Adapter Port
----------------------

Das Pin-Diagramm des Kameraadapter-Interfaces wird hier gezeigt, der Typ ist ZH1.5-7P.

* TX und RX werden für ESP32 CAM verwendet.

.. image:: img/camera_shield.png


.. _shield_avoid_pin:

Obstacle Avoidance Port
----------------------------------

Hier ist die Pinbelegung des Hindernisvermeidungsanschlusses.

.. image:: img/ir_shield.png


.. _shield_strip_pin:

RGB LED Strip Port
-------------------------

Unten ist das Pin-Diagramm der zwei parallel angeschlossenen RGB LED-Streifen, deren Pinbelegungen gleich sind.

.. image:: img/rgb_shield.png



.. _shield_motor_pin:

Motor Port
---------------

Hier ist die Pinbelegung der 2 Sätze von Motoranschlüssen.


.. image:: img/motor_shield.png
    :width: 600
    :align: center

