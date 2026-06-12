.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Schnellstart mit Scratch
==================================

In diesem Kapitel lernen Sie, wie Sie **Beispielprojekte in Scratch (Mammoth Coding) schnell öffnen und ausführen**, um Ihren GalaxyRVR in Aktion zu sehen.

Wenn Sie lernen möchten, wie Sie diese Skripte von Grund auf selbst erstellen, lesen Sie bitte das Kapitel :ref:`programming_scratch`.

.. note::

    * Das R3-Board des GalaxyRVR wird mit einer Firmware ausgeliefert, die die RoboPilot-App und Mammoth Coding unterstützt.
    * Falls Sie die Firmware überschrieben haben und die Kommunikation wiederherstellen müssen, folgen Sie der Anleitung unter :ref:`update_r3_firmware`.


So öffnen Sie schnell ein Scratch-Beispiel
----------------------------------------------

#. Laden Sie die Beispielcodes über den folgenden Link herunter:

   * |download_galaxyrvr_code|

#. Entpacken Sie die heruntergeladene Datei und übertragen Sie den Ordner ``scratch_codes`` auf Ihr Mobilgerät. Sie können jedes Dateiübertragungstool verwenden, z. B. **ES File Explorer** oder **File Transfer Assistant**.

   .. image:: img/scratch_mobile_save.png
      :width: 400

#. Suchen Sie im **Google Play Store** oder im **Apple App Store** nach **Mammoth Coding** und installieren Sie es.

   .. image:: img/scratch_app_install.png
      :width: 600

#. Starten Sie den GalaxyRVR.

   * Laden Sie den Akku vor der ersten Verwendung des GalaxyRVR mit dem mitgelieferten Typ-C-USB-Kabel vollständig auf.
   * Schalten Sie den Netzschalter ein.
   * Stellen Sie den Modus auf **Run** und drücken Sie die **Reset**-Taste auf dem R3-Board.
   * Der untere Lichtstreifen blinkt **grün** und zeigt damit einen erfolgreichen Start an.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Verbinden Sie Ihr Mobilgerät mit dem WLAN-Netzwerk des GalaxyRVR.

   * Der Netzwerkname (SSID) lautet ``GalaxyRVR`` und das Passwort ist ``12345678``.
   * Wenn eine Warnung mit dem Hinweis "Kein Internetzugriff" erscheint, wählen Sie bitte die Option **"Trotzdem verbinden"**.

     .. image:: ../img/camera_lan.png
        :width: 500

#. Tippen Sie in der App auf **Datei** > **Vom Gerät öffnen**, um lokale Dateien zu durchsuchen.

   .. image:: img/scratch_open_file.png
        :width: 600

#. Wählen Sie eine ``.sb3``-Datei aus, um sie zu öffnen.

   .. image:: img/scratch_mobile_save.png
      :width: 400

#. Tippen Sie auf das grüne Flaggen-Symbol, um das Skript zu starten.

   .. image:: img/scratch_run.png

Beispiele
---------------

**Grundlegende Projekte**

Diese Projekte sind die grundlegenden Kurse zur Steuerung des GalaxyRVR mit Mammoth Coding. Sie führen Sie Schritt für Schritt durch die Nutzung des GalaxyRVR.


* ``3_move.sb3``: Steuern Sie die Bewegung Ihres GalaxyRVR in Echtzeit mit den Richtungstasten.
* ``4_ultrasonic.sb3``: Der Rover fährt vorwärts und weicht Hindernissen mithilfe des Ultraschallmoduls automatisch aus.
* ``5_ultra_animate_jump.sb3``: Erstellt eine animierte Szene des Rovers, der sich fröhlich über die Marsoberfläche bewegt.
* ``6_ir_obstacle_avoid.sb3``: Der Rover fährt vorwärts und weicht Hindernissen mithilfe von IR-Sensoren aus.
* ``7_ir_obstacle_avoid_animate.sb3``: Steuern Sie die Rover-Figur, um Felsen auf der Marsoberfläche auszuweichen, indem Sie die IR-Sensoren mit Ihren Händen auslösen.
* ``8_ir_ultrasonic_avoid.sb3``: Der Rover verwendet Ultraschall- und IR-Sensoren gemeinsam, um Hindernisse sanft zu umfahren.
* ``9_ir_ultrasonic_follow.sb3``: Der Rover folgt Ihnen: Er nähert sich, wenn Sie vor ihm stehen, dreht sich zu Ihnen, wenn Sie seitlich stehen, und stoppt, wenn Sie sich entfernen.
* ``10_rgb.sb3``: Tippen Sie auf eine farbige Kugel, um die RGB-Lichter des Rovers in dieser Farbe leuchten zu lassen.
* ``10_rgb_animate.sb3``: Der Rover bewegt sich und ändert die Lichtfarbe entsprechend der gedrückten Richtungstaste.
* ``1scratch_servo.sb3``: Verwenden Sie die Pfeiltasten, um den Kamerawinkel des Rovers einzustellen; klicken Sie, um die Position zurückzusetzen.
* ``1scratch_servo_stage.sb3``: Berühren und ziehen Sie den Pfeil auf dem Bildschirm, um die Kamera des Rovers mit sanfter Echtzeit-Reaktion auszurichten.
* ``12_camera.sb3``: Betrachten Sie das Live-Kamerabild aus der Perspektive Ihres Rovers während der Erkundung.
* ``13_realtime_control.sb3``: Steuern Sie die Bewegungen und Lichter Ihres Rovers in Echtzeit über Scratch.

**Unterhaltsame Projekte**

Diese unterhaltsamen Scratch-Projekte benötigen den GalaxyRVR nicht.
Sie finden sie alle im Ordner ``scratch_codes/fun/``.

* ``1_scratch_balloon.sb3``: Blasen Sie den Ballon auf, indem Sie den linken IR-Sensor blockieren; lassen Sie ihn nicht platzen oder fallen!
* ``2_flappy_parrot.sb3``: Steuern Sie den Flug des Papageis mit Ihrer Hand über dem Ultraschallsensor, um Bambusstangen auszuweichen.
* ``3_shooting.sb3``: Zielen und schießen Sie auf Ziele mithilfe des Hindernisvermeidungsmoduls.
* ``4_eat_apple.sb3``: Führen Sie den Käfer mit Handgesten, die vom linken IR-Sensor erkannt werden, zum Apfel.
* ``5_fishing.sb3``: Fangen Sie Fische, indem Sie den linken IR-Sensor im richtigen Moment blockieren.
* ``6_sensitive_ball.sb3``: Bewegen Sie den Ball mit Ihrer Hand über dem Ultraschallsensor nach oben oder unten; lösen Sie Geräusche und Lichter aus, wenn er eine Linie berührt.
* ``7_tap_white_tile.sb3``: Tippen Sie mit zwei IR-Sensoren auf schwarze Kacheln, um Punkte zu erzielen – vermeiden Sie die weißen!
