
.. _ir_ultra_avoid:

Lektion 8: Erweiterte Hindernisvermeidung
============================================================

Haben Sie sich schon einmal gefragt, wie Roboter sich in Räumen bewegen können, ohne gegen Möbel zu stoßen? Heute bringen wir unserem Mars Rover genau das bei! Wir kombinieren zwei verschiedene Sensortypen, um ein superintelligentes Hindernisvermeidungssystem zu entwickeln.

Wie Sensoren Robotern helfen zu „sehen"
-------------------------------------------------------

Denken wir darüber nach, wie wir unsere Sinne einsetzen:

* **Infrarotsensoren** funktionieren wie Fledermäuse mit Echoortung! Sie senden unsichtbares Infrarotlicht aus und warten darauf, dass es von Objekten zurückgeworfen wird. Wenn das Licht schnell zurückkommt, befindet sich ein Hindernis in der Nähe.

* **Ultraschallsensoren** arbeiten mit Schallwellen, die wir nicht hören können. Sie senden hochfrequente Schallwellen aus und messen, wie lange es dauert, bis das Echo zurückkommt. Eine längere Zeit bedeutet, dass das Objekt weiter entfernt ist.

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>

Wenn wir beide Sensoren zusammen verwenden, erhält unser Rover ein viel besseres Verständnis seiner Umgebung – genau wie wenn Sie Ihre Augen und Ohren benutzen, um sich in einem dunklen Raum zurechtzufinden!

Lernziele
-------------------------

* Kombinieren von Ultraschall- und Infrarotsensoren zur Entwicklung eines erweiterten Hindernisvermeidungssystems
* Programmieren Sie Ihren Mars Rover so, dass er Hindernisse automatisch erkennt und umfährt

Unser superintelligentes Rover-System aufbauen
-------------------------------------------------------------------

Erinnern Sie sich an das Hindernisvermeidungsprogramm, das wir zuvor erstellt haben? Wir werden es als Ausgangspunkt nutzen und noch besser machen!

#. Zunächst: :ref:`app_connect`.

#. Öffnen Sie nun unser vorheriges Infrarotsensor-Projekt aus :ref:`ir_obstacle` als Vorlage. Klicken Sie auf „Datei" und suchen Sie Ihr gespeichertes IR-Hindernisvermeidungsprojekt.

   .. image:: img/7_avoid_open.png

#. Bevor wir Änderungen vornehmen, speichern wir eine Kopie, damit wir unsere ursprüngliche Arbeit nicht verlieren. Klicken Sie auf „Als Kopie speichern".

   .. image:: img/7_avoid_save_copy.png

#. Geben Sie Ihrem neuen Projekt einen coolen Namen wie „Super Smart Rover" oder „Advanced Obstacle Avoidance".

   .. image:: img/7_avoid_save_rename.png

#. Fügen wir nun unseren Ultraschallsensor hinzu! Ziehen Sie den Block ``when distance < 15 cm`` heraus. Dies wird unser „Frühwarnsystem" sein, das Hindernisse aus größerer Entfernung erkennt.

   .. image:: img/7_avoid_when.png
       :width: 800

#. Um Verwirrung zu vermeiden, fügen wir einen ``stop other scripts in sprite`` Block hinzu. Dadurch wird sichergestellt, dass unser Rover immer nur einer Anweisung zurzeit folgt.

   .. image:: img/7_avoid_stop.png

#. Wenn der Ultraschallsensor etwas in der Nähe erkennt, soll unser Rover bis zu einem sicheren Abstand zurücksetzen.

   .. image:: img/7_avoid_backward.png

#. Jetzt müssen wir vom Hindernis weg drehen. Der Rover dreht sich für eine Sekunde – Sie können eine Links- oder Rechtsdrehung wählen!

   .. image:: img/7_avoid_turn.png

#. Schließlich sagen wir dem Rover, dass er auf seinem neuen Weg weiter vorwärtsfahren soll.

   .. image:: img/7_avoid_go.png

Fantastisch! Jetzt haben Sie einen Rover, der drei Sensoren wie ein Team einsetzt:

- Der vordere Ultraschallsensor erkennt entfernte Hindernisse
- Der linke IR-Sensor erfasst Objekte auf der linken Seite
- Der rechte IR-Sensor beobachtet die rechte Seite

Testen Sie Ihr Programm und beobachten Sie, wie geschmeidig Ihr Rover Hindernisse umfährt. Versuchen Sie, einen Hindernisparcours zu erstellen und sehen Sie, ob Ihr Rover ihn ohne Zusammenstöße bewältigen kann!

Herausforderung: Können Sie die Drehzeit oder den Abstand ändern, damit Ihr Rover noch besser Hindernissen ausweicht?