.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


.. _ir_obstacle:

Lektion 6: IR-Hindernisvermeidung
===================================

Lernen Sie die seitlichen "Augen" Ihres Rovers kennen - die Infrarot-Hindernisvermeidungssensoren!

Diese cleveren Sensoren helfen Ihrem GalaxyRVR, Hindernisse an seinen Seiten zu erkennen und zu umgehen - ahnlich wie ein peripheres Sehen. Erfahren Sie, wie sie funktionieren, und programmieren Sie Ihren Rover, automatisch um Objekte herumzunavigieren.

Machen Sie sich bereit, Ihren Mars Rover zu einem intelligenten Hindernisvermeider zu machen!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_ir1.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Lernziele
-------------------------

* Die Funktionsprinzipien des Infrarot-Hindernisvermeidungsmoduls und seine Anwendung im Mars Rover verstehen.
* Lernen, wie man Daten des Infrarot-Hindernisvermeidungsmoduls in Scratch ausliest und anwendet.
* Ein Mars-Erkundungsspiel zur Hindernisvermeidung mit dem IR-Modul und der Scratch-Buhne erstellen.

Das Hindernisvermeidungsmodul kennenlernen
----------------------------------------------

Begru?en Sie den neuen Helfer Ihres GalaxyRVR - das Infrarot-Hindernisvermeidungsmodul! Dieses clevere kleine Gerat hilft Ihrem Rover, Hindernisse zu erkennen und zu vermeiden. Sehen wir uns an, was es ausmacht:

.. image:: img/ir_avoid.png
    :width: 300
    :align: center

**Die vier wichtigen Pins:**

* **GND** - Der Masseanschluss (schlie?t den Stromkreis)
* **+** - Stromeingang (benotigt 3,3 V bis 5 V Strom)
* **Out** - Signalausgang (sendet "Hindernis erkannt"-Meldungen)
* **EN** - Enable-Pin (steuert, wann das Modul aktiv ist)

**So funktioniert es - Die unsichtbare Taschenlampe:**

Stellen Sie sich vor, dieses Modul hatte eine unsichtbare Taschenlampe und eine spezielle Brille:

.. image:: img/ir_receive.png
    :align: center

1. Der Sender sendet infrarotes Licht aus (für unsere Augen unsichtbar)
2. Wenn das Licht auf ein Hindernis trifft, wird es zurückgeworfen
3. Der Empfanger "sieht" das reflektierte Licht
4. Das Modul sendet ein Signal: "Hindernis voraus!"

**Wissenswertes über Ihren Sensor:**

* **Erkennungsbereich**: 2-40 cm (ungefahr die Lange Ihrer Federmappe!)
* **Farbe spielt eine Rolle**: Funktioniert am besten mit hellen Objekten
* **Dunkle Objekte**: Schwerer aus der Ferne zu erkennen

**Erweiterte Steuerung (für Neugierige):**

* **EN-Pin**: Die Brucke halt das Modul dauerhaft aktiv. Entfernen Sie sie, wenn Sie das Modul mit Code steuern mochten.

  .. image:: img/ir_cap.png
      :width: 400
      :align: center

* **Zwei Einstellungen**:

  - Ein Drehregler steuert, wie weit das infrarote Licht reicht
  - Ein Drehregler stellt die Lichtfrequenz ein

  .. image:: img/ir_avoid_pot.png
      :width: 400
      :align: center

Nachdem Sie nun Ihren neuen Helfer kennengelernt haben, verbinden wir ihn mit Ihrem Rover und beginnen mit der Programmierung!

Testen Ihrer Infrarotsensoren
------------------------------------------------------------

#. Stellen Sie zunachst eine :ref:`app_connect` her.

2. Stimmen wir Ihre Sensoren für eine perfekte Leistung ab!

   a. Stellen Sie sicher, dass die Infrarotkomponenten gerade sind. Korrigieren Sie sie vorsichtig bei Bedarf.

      .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
            </video>

   b. Platzieren Sie ein Objekt (z. B. die Rover-Verpackung) in 20 cm Entfernung. Drehen Sie den Regler, bis die Anzeige-LED aufleuchtet. Testen Sie, indem Sie das Objekt näher und weiter entfernt bewegen.

      .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
            </video>

   c. Wiederholen Sie den Vorgang für das andere Infrarotmodul.

3. Stellen Sie dann eine :ref:`app_connect` her.

4. Suchen Sie die Blocke "linker IR-Status" und "rechter IR-Status" in der GalaxyRVR-Kategorie und aktivieren Sie deren Kontrollkastchen.

   .. image:: img/4_ir_statusblock.png

5. Die Sensorwerte werden nun auf Ihrer Buhne angezeigt.

   .. image:: img/4_ir_statusvalue.png

6. Winken Sie mit Ihrer Hand nahe an jedem Infrarotsensor und beobachten Sie, wie sich die Werte andern!

**Bedeutung der Werte:**

- **True** = Hindernis erkannt
- **False** = Freie Bahn

Jetzt sind Sie bereit zu sehen, was Ihr Rover "sehen" kann!


Programmieren Sie Ihren Rover zur Hindernisvermeidung
-------------------------------------------------------------

Bringen wir Ihrem GalaxyRVR bei, mithilfe seiner Infrarotsensoren automatisch Hindernissen auszuweichen!

#. Stellen Sie zunachst eine :ref:`app_connect` her.

#. Starten Sie das Programm mit einem grunen Flaggenblock.

   .. image:: img/4_ir_start.png

#. Stellen Sie eine sichere Geschwindigkeit von 30 % für einfaches Testen und Debuggen ein.

   .. image:: img/4_ir_speed.png

#. Suchen Sie den Block ``when left IR is blocked`` für die Erkennung durch den linken Sensor.

   .. image:: img/4_ir_when_blocked.png

#. Wenn der linke Sensor ein Hindernis erkennt, lassen Sie den Rover nach rechts abbiegen.

   .. image:: img/4_ir_turn_right.png

#. Fahren Sie mit dem Rechtsabbiegen fort, bis die linke Seite das Hindernis nicht mehr erkennt.

   .. image:: img/4_ir_wait_until.png

#. Stoppen Sie die Bewegung, sobald der Weg frei ist.

   .. image:: img/4_ir_stop.png

#. Testen Sie, indem Sie den linken Infrarotsensor mit Ihrer Hand auslösen. Der GalaxyRVR sollte intelligent nach rechts ausweichen.

#. Duplizieren Sie den Code, indem Sie die Blocke lang gedruckt halten und "Duplizieren" aus dem Menu auswahlen.

   .. image:: img/4_ir_duplicate.png

#. Tauschen Sie im duplizierten Code die linke und rechte Seite, sodass er Hindernisse auf der rechten Seite behandelt.

   .. image:: img/4_ir_left_right.png

#. Um erratisches Verhalten zu verhindern, wenn beide Sensoren gleichzeitig ausgelost werden, fugen Sie einen "stoppe andere Skripte der Figur"-Block hinzu. Dadurch wird sichergestellt, dass immer nur ein Sensorereignis verarbeitet wird.

   .. image:: img/4_ir_stop_script.png
       :width: 800

   .. note:: Der Block zum Stoppen von Skripten kann mit zeitgesteuerten Bewegungsblocken in Konflikt geraten. Verwenden Sie sie daher nach Moglichkeit nicht zusammen.

#. Ihr GalaxyRVR wird nun nach links oder rechts abbiegen, wenn auf einer Seite Hindernisse erkannt werden. Testen Sie, indem Sie beide Sensoren mit Ihren Handen auslösen.

#. Fugen Sie unter jedem Codeabschnitt einen Vorwarts-Block hinzu, damit der Rover sich nach der Hindernisvermeidung weiterbewegt.

   .. image:: img/4_ir_avoid_move.png
       :width: 800

Klicken Sie nun auf die grune Flagge! Ihr GalaxyRVR fahrt kontinuierlich vorwarts, weicht intelligent Hindernissen aus und setzt seinen Weg nach der Umgehung fort.

Blocke im Zusammenhang mit dem IR-Modul
----------------------------------------

* Ereignisblock, der ausgelost wird, wenn der linke IR-Sensor ein Hindernis erkennt

  - Andern Sie "links" auf "rechts" im Dropdown-Menu

  .. image:: img/block/ir_when.png

* Pausiert das Programm, bis der linke IR-Sensor kein Hindernis mehr erkennt

  - Andern Sie "links" auf "rechts" für den anderen Sensor
  - Andern Sie "ist nicht" auf "ist" für die gegenteilige Bedingung

  .. image:: img/block/ir_wait_until.png

* Bedingungsblock, der WAHR zurückgibt, wenn der linke IR-Sensor ein Hindernis erkennt

  - Perfekt für die Verwendung mit ``if``-Anweisungen
  - Andern Sie "links" auf "rechts" für den anderen Sensor

  .. image:: img/block/ir_condition.png

* Zeigt den aktuellen Erkennungsstatus des linken IR-Sensors an

  .. image:: img/block/ir_left_value.png

* Zeigt den aktuellen Erkennungsstatus des rechten IR-Sensors an

  .. image:: img/block/ir_right_value.png