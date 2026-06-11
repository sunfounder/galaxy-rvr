
Lektion 11: Neigen der Rover-Kamera steuern
===================================================================

Geben Sie Ihrem Mars Rover eine bewegliche Kamera! Genau wie Sie Ihren Kopf auf und ab neigen können, kann Ihr Rover jetzt seine Kamera neigen, um die Marslandschaft aus verschiedenen Winkeln zu erkunden.

Wir verwenden einen speziellen Motor, einen sogenannten „Servo", der sich in exakte Positionen bewegen kann – perfekt zur Steuerung der Kameraneigung Ihres Rovers. Lernen Sie, wie Sie den Servo programmieren, um auf Marsberge hinauf oder auf interessante Steine hinunterzublicken!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/servo_range.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>

Lernziele
-------------------------

* Entdecken Sie, wie ein Servo funktioniert
* Lernen Sie, Kamerawinkel mit einfachen Code-Blöcken zu steuern
* Erstellen Sie interaktive Projekte, mit denen Sie die Kamera per Touch-Steuerung neigen können

Was ist ein Servo?
----------------------------------------

Lernen Sie den Servo kennen – den beweglichen Muskel Ihres Roboters!

Genau wie Sie Ihren Arm in die exakt richtige Position bewegen können, kann ein Servomotor sich in bestimmte Winkel bewegen und diese präzise halten. Stellen Sie sich einen intelligenten Motor vor, der genau weiß, wo er anhalten muss.

.. image:: img/servo.png
    :align: center

**Einfache Anschlüsse:**

- Braunes Kabel: Masse (GND, -)
- Rotes Kabel: Strom (+)
- Orangefarbenes Kabel: Signal (sagt dem Servo, wohin er sich bewegen soll)

In Ihrem Mars Rover fungiert der Servo wie ein nickender Kopf – er bewegt die Kamera auf und ab, um die perfekte Aussicht einzufangen!

Wie funktioniert ein Servo?
-----------------------------------------------

Im Inneren jedes Servos arbeitet ein intelligentes Team zusammen:

.. image:: img/servo_internal.png
    :align: center

1. **Gewöhnlicher Motor** - Dreht sich schnell wie die Räder Ihres Rovers
2. **Getriebe** - Verlangsamen die Bewegung und machen sie stärker
3. **Steuerplatine** - Weiß genau, in welcher Position sich der Servo befindet
4. **Positionssensor** - Meldet zurück, wohin der Servo zeigt

Wir steuern Servos mit speziellen Signalen, die sagen: „Bewege dich in diesen genauen Winkel!" Es ist, als würden Sie einem Freund genau sagen, wie weit er seinen Kopf drehen soll.

Bereit, Ihren Servo tanzen zu lassen? Dann beginnen wir mit der Programmierung!


Das Neigungssystem Ihres Rovers steuern
-------------------------------------------------------------

Lernen wir, das Neigungssystem Ihres Mars Rovers zu steuern – den Teil, der die Kamera wie ein nickender Kopf auf und ab bewegt!

**Den Kamerawinkel einstellen**

1. Zunächst: :ref:`app_connect`.

2. Überprüfen Sie den aktuellen Servowinkel – Sie sehen ihn auf der Bühne angezeigt.

   .. image:: img/10_servo_angle.png

3. Ziehen Sie einen ``set servo angle to 90 degrees``-Block heraus. Klicken Sie darauf, damit Ihr Rover nach vorne schaut.

   .. image:: img/10_servo_set_angle.png

4. Ändern Sie den Wert auf 45 und klicken Sie – jetzt schaut Ihr Rover zum Marswetterhimmel hinauf!

   .. image:: img/10_servo_set_angle_45.png

5. Experimentieren Sie mit verschiedenen Winkeln! Sie werden entdecken, dass Ihr Rover sich zwischen 0 und 135 Grad neigen kann.

**Kamerasteuerung erstellen**

1. Erstellen wir ein Bedienfeld für die Kamera Ihres Rovers:

2. Erstellen Sie einen Reset-Knopf – ziehen Sie einen ``when this sprite clicked``-Block heraus.

   .. image:: img/10_servo_when_click.png

3. Fügen Sie ``set servo angle to 90 degrees`` hinzu, damit die Kamera wieder nach vorne schaut.

   .. image:: img/10_servo_when_90.png

4. Fügen Sie Auf-/Ab-Steuerung hinzu – ziehen Sie die Blöcke ``when up arrow key pressed`` und ``when down arrow key pressed`` heraus.

   .. image:: img/10_servo_when_up.png

5. Programmieren Sie den Aufwärtspfeil, um den Winkel zu verringern (nach oben schauen).

   .. image:: img/10_servo_when_up2.png

6. Programmieren Sie den Abwärtspfeil, um den Winkel zu erhöhen (nach unten schauen).

   .. image:: img/10_servo_when_down.png

Klicken Sie nun auf die Vollbildtaste und übernehmen Sie die Steuerung! Verwenden Sie die Pfeiltasten, um die Ansicht Ihres Rovers anzupassen, und klicken Sie auf das Sprite, um zurückzusetzen. Sie sind der Kameramann!

.. _tilt_system:

Touch-Steuerung für den Kamerawinkel
-------------------------------------------------------------

Erstellen Sie eine berührungsgesteuerte Kamera! Ziehen Sie einen Pfeil, um die Kamera Ihres Rovers genau dorthin zu richten, wo Sie sie haben möchten.

1. Räumen Sie die Bühne auf, indem Sie vorhandene Sprites löschen.

   .. image:: img/6_animate_delete.png

2. Fügen Sie ein Pfeil-Sprite als Ihren Touch-Controller hinzu.

   .. image:: img/10_servo_arrow.png

3. Beginnen Sie mit ``when this sprite clicked``, um die Touch-Steuerung zu starten.

   .. image:: img/6_animate_when_touch.png
       :width: 200

4. Erstellen Sie eine Schleife, die läuft, während Sie den Pfeil berühren.

   .. image:: img/6_animate_repeat_touching.png
       :width: 400

5. Lassen Sie den Pfeil beim Ziehen in Richtung Ihres Fingers zeigen.

   .. image:: img/10_servo_arrow_point_toward.png
       :width: 400

6. Verknüpfen Sie die Richtung des Pfeils mit dem Kamerawinkel – drehen Sie den Pfeil, bewegen Sie die Kamera!

   .. image:: img/10_servo_arrow_angle_direction.png
       :width: 800

7. Setzen Sie Grenzen, um die Kamera zwischen 0 und 135 Grad zu halten.

   .. image:: img/10_servo_arrow_135.png
       :width: 400

   .. image:: img/10_servo_arrow_0.png
       :width: 400

Berühren und ziehen Sie den Pfeil, um die Kamera Ihres Rovers auszurichten! Lassen Sie den Pfeil sich sanft bewegen und sofort auf Ihre Berührung reagieren, für ein realistisches Steuerungsgefühl.

Servo-Steuerungsblöcke
-------------------------------

* Setzen Sie den Servo auf einen bestimmten Winkel (0-135 Grad)

  .. image:: img/block/servo_set_angle.png

* Erhöhen oder verringern Sie den Servowinkel (negative Zahlen zum Verringern)

  .. image:: img/block/servo_increase_angle.png

* Überprüfen Sie den aktuellen Servowinkel

  .. image:: img/block/servo_value.png