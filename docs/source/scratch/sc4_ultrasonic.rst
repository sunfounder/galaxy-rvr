
Lektion 4: Ultraschallmodul
===============================

Statten Sie Ihren GalaxyRVR mit der Fahigkeit aus, mithilfe von Schall zu "sehen"!

Entdecken Sie, wie Ultraschallsensoren wie die Echoortung von Fledermausen funktionieren - sie senden Schallwellen aus und hören auf Echos, um Hindernisse zu erkennen und Entfernungen zu messen.

Machen Sie Ihren Mars Rover intelligenter und sicherer, während er erkundet!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/ultrasonic_avoid.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Lernziele
-------------------

* Entdecken, wie Ultraschallsensoren Schallwellen zur Entfernungsmessung nutzen
* Lernen, Entfernungsmessungen mit der Mammoth Coding-App auszulesen
* Programmieren Ihres GalaxyRVR zur Hindernisvermeidung mit dem Ultraschallsensor

Das Ultraschallmodul erkunden
--------------------------------------------

Lernen Sie den HC-SR04-Ultraschallsensor kennen - die neue "Superkraft" Ihres Rovers, um Entfernungen zu sehen, ohne etwas zu berühren! Genau wie Fledermause Schall zur Navigation nutzen, kann dieses clevere Gerat Objekte von 2 cm bis 400 cm Entfernung erkennen.

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

**Die vier wichtigen Pins:**

* **TRIG** - Der "Startknopf", der dem Sensor sagt, dass er Schallwellen aussenden soll
* **ECHO** - Hort auf das zurückkehrende Echo von Objekten
* **VCC** - Stromanschluss (benotigt 5V Strom)
* **GND** - Masseanschluss (schlie?t den Stromkreis)

**So funktioniert es - Das Echo-Spiel:**

.. image:: img/ultrasonic_prin.jpg
    :width: 800

1. **START** - Der Sensor sendet 8 schnelle Schallwellen aus (zu hoch für unser Gehor!)
2. **HOREN** - Er beginnt mit der Zeitmessung und wartet auf das zurückkommende Echo
3. **BERECHNEN** - Mithilfe der Echozeit berechnet er: Entfernung = (Zeit x Schallgeschwindigkeit) / 2

Stellen Sie es sich wie Rufen in einer Schlucht vor - je langer Sie auf Ihr Echo warten müssen, desto weiter entfernt ist die Wand!

Jetzt geben wir Ihrem Mars Rover diese erstaunliche Superkraft!

Testen des Ultraschallsensors
----------------------------------------------------------

#. Stellen Sie zunachst eine :ref:`app_connect` her.

2. Suchen Sie den Block "Entfernung in cm" in der GalaxyRVR-Kategorie und aktivieren Sie dessen Kontrollkastchen.

   .. image:: img/6_ultrasonic_value.png

3. Die Messwerte des Sensors werden nun live auf der Buhne angezeigt.

   .. image:: img/6_ultrasonic_value2.png

4. Winken Sie mit Ihrer Hand vor dem Ultraschallsensor und beobachten Sie, wie sich der Wert andert - er misst die Entfernung in Zentimetern!

Erstellen eines hindernisvermeidenden Rovers
--------------------------------------------------------------------

Programmieren wir Ihren GalaxyRVR so, dass er mithilfe des Ultraschallsensors automatisch Hindernissen ausweicht.

1. Beginnen Sie mit dem grunen Flaggenblock.

   .. image:: img/6_ultrasonic_flag.png

2. Stellen Sie eine angenehme Geschwindigkeit ein (wir empfehlen 30 %) zum Testen.

   .. image:: img/6_ultrasonic_speed.png

3. Fugen Sie einen "vorwarts bewegen"-Block hinzu, damit der Rover sich weiterbewegt, wenn der Weg frei ist.

   .. image:: img/6_ultrasonic_forward.png

4. Verwenden Sie den Block ``when distance < 15 cm``, um nahe Hindernisse zu erkennen.

   .. image:: img/6_ultrasonic_when.png

5. Wenn etwas zu nahe kommt, lassen Sie den Rover anhalten und zurücksetzen.

   .. image:: img/6_ultrasonic_backward.png

6. Lassen Sie ihn dann leicht abbiegen (links oder rechts - Ihre Wahl!).

   .. image:: img/6_ultrasonic_turn.png

7. Sagen Sie ihm schlie?lich, er solle auf seinem neuen Weg wieder vorwarts fahren.

   .. image:: img/6_ultrasonic_forward_again.png

Stellen Sie nun Ihren GalaxyRVR auf den Boden und beobachten Sie ihn! Er fahrt vorwarts, bis er ein Hindernis erkennt, andert dann intelligent die Richtung und setzt seine Erkundung fort.

Ultraschallsensor-Blocke
-------------------------------------------------

* **Ereignisausloser-Block**

  Startet Code, wenn ein Objekt innerhalb einer eingestellten Entfernung erkannt wird.

  - Andern Sie das Vergleichssymbol (< oder >)
  - Passen Sie den Entfernungsschwellenwert (in cm) an

  .. image:: img/block/ultra_when.png

* **Warte-bis-Block**

  Halt Ihr Programm an, bis der Sensor ein Objekt in der angegebenen Entfernung erkennt.

  - Wahlen Sie < oder > für den Entfernungsvergleich
  - Stellen Sie Ihren gewunschten Entfernungswert ein

  .. image:: img/block/ultra_wait_until.png

* **Bedingungsprufungs-Block**

  Gibt WAHR oder FALSCH basierend auf der Entfernungserkennung zurück. Perfekt für die Verwendung mit ``if``-Anweisungen.

  - Wechseln Sie nach Bedarf zwischen < und >
  - Legen Sie den Entfernungsgrenzwert fest

  .. image:: img/block/ultra_condition.png

* **Entfernungswert-Block**

  Zeigt die aktuelle Entfernungsmessung des Ultraschallsensors in Zentimetern an.

  .. image:: img/block/ultra_value.png


