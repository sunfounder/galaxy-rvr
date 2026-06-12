.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Lektion 12: Durch die Augen Ihres Rovers sehen
========================================================

Jetzt, da Ihr Rover seine Kamera neigen kann, geben wir ihm echtes Sehvermögen! In dieser Lektion lernen Sie, genau das zu sehen, was Ihr Mars Rover durch seine Kamera sieht.

Beobachten Sie Live-Video aus der Perspektive Ihres Rovers, während er erkundet – sehen Sie Marslandschaften, entdecken Sie interessante Steine und navigieren Sie wie ein echter Weltraumforscher!

.. image:: img/11_camera_image.png

Lernziele
-------------------------

* Live-Kamerabilder von Ihrem Mars Rover in Echtzeit anzeigen
* Kamerabildbetrachtung mit Servosteuerung für interaktive Erkundung kombinieren

Lernen Sie die Augen Ihres Rovers kennen: ESP32 CAM
---------------------------------------------------------------

Sagen Sie Hallo zum ESP32 CAM – dem leistungsstarken Sehsystem Ihres Rovers! Dieses erstaunliche Modul ist, als würden Sie Ihrem Rover superintelligente Augen geben.

.. image:: img/esp32_cam.png
    :width: 400
    :align: center

Der ESP32 CAM kann zwei unglaubliche Dinge:

1. **Fotos und Videos aufnehmen** von allem, was Ihr Rover gerade betrachtet
2. **Das Video direkt** an Ihr Telefon oder Ihren Computer senden

Es ist, als wären Sie direkt auf dem Mars bei Ihrem Rover! Sie werden alles sehen, was er sieht, in Echtzeit. Bereit, mit der Erkundung durch die Augen Ihres Rovers zu beginnen?

.. _camera_system:

Das Kamerasystem Ihres Rovers erkunden
-----------------------------------------------------

1. Ziehen Sie einen ``turn camera ON``-Block heraus und klicken Sie darauf – beobachten Sie, wie sich die Bühne in eine Live-Kameraansicht Ihres Rovers verwandelt!

   .. image:: img/11_camera_on.png

2. Falls das Kamerabild auf dem Kopf steht, verwenden Sie ``set camera image orientation to inverted``, um es zu korrigieren.

   .. image:: img/11_camera_orientation.png

3. Benötigen Sie mehr Licht? Verwenden Sie ``turn camera LED ON``, um das eingebaute Licht der Kamera zu aktivieren.

   .. image:: img/11_camera_led.png

**Kamera-Steuerungstasten erstellen**

1. Erstellen wir ein Kamera-Bedienfeld! Erstellen Sie vier Sprites und ordnen Sie sie ordentlich an.

   .. image:: img/11_camera_4.png

2. Programmieren Sie jede Taste:

   - Ball 1: Schaltet die Kamera AUS

   .. image:: img/11_camera_1sp.png

   - Ball 2: Schaltet die Kamera EIN und stellt die Ausrichtung ein

   .. image:: img/11_camera_2sp.png

   - Balloon 1: Schaltet das LED-Licht EIN

   .. image:: img/11_camera_3sp.png

   - Balloon 2: Schaltet das LED-Licht AUS

   .. image:: img/11_camera_4sp.png

3. Sparen Sie Platz, indem Sie die Steuerungen stapeln – sie werden bei Bedarf ausgeklappt!

   .. image:: img/11_camera_fold.png

4. Fügen Sie ``go to back layer`` zu jedem Sprite hinzu – durch Klicken auf eine Taste wird die nächste sichtbar, was einen coolen Umschalteffekt erzeugt.

   .. image:: img/11_camera_layer.png

5. Klicken Sie auf die Bühnenvergrößerungstaste, um in den vollständigen Steuerungsmodus zu gelangen.

   .. image:: img/11_camera_go_stage.png

6. Sie sehen nun Live-Video aus der Perspektive Ihres Rovers, während er erkundet – sehen Sie Marslandschaften, entdecken Sie interessante Steine und navigieren Sie wie ein echter Weltraumforscher!

   .. image:: img/11_camera_image.png

Kamera-Steuerungsblöcke
-------------------------------

* Schalten Sie die Kamera ein oder aus. Wenn sie eingeschaltet ist, zeigt die Bühne Live-Video von Ihrem Rover!

  .. image:: img/block/camera_turn.png

* Steuern Sie das LED-Licht der Kamera – perfekt für Erkundungen im Dunkeln.

  .. image:: img/block/camera_led_turn.png

* Passen Sie die Transparenz der Kameraansicht an.

  .. image:: img/block/camera_transp.png

* Drehen Sie das Kamerabild, falls es auf dem Kopf steht.

  .. image:: img/block/camera_orientation.png
