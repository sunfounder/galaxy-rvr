.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Lektion 7: Eine IR-Hindernis-Animation erstellen
========================================================

In unseren vorherigen Missionen haben wir das Infrarot-Hindernisvermeidungsmodul verwendet, um unseren GalaxyRVR automatisch Hindernissen ausweichen zu lassen - genau wie ein echter Mars Rover, der den Roten Planeten erkundet!

Jetzt bringen wir dies auf die nachste Ebene, indem wir die physischen IR-Sensoren mit einer virtuellen Marslandschaft kombinieren. Wir erstellen ein spannendes Animationsspiel, bei dem Sie eine Rover-Figur steuern, indem Sie die echten IR-Sensoren mit Ihren Handen auslösen!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_rock.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Lernziele
-------------------------

* Entdecken, wie das Infrarot-Hindernisvermeidungsmodul Ihren Mars Rover zum Leben erweckt
* Lernen, IR-Sensordaten zu verwenden, um Figuren in Ihren Scratch-Animationen zu steuern
* Ihr eigenes Mars-Erkundungsspiel erstellen, bei Sie mit echten Sensoren Felsen ausweichen

Die Animationsszene erstellen
-------------------------------

#. Stellen Sie zunachst eine :ref:`app_connect` her.

#. Einrichten des Mars-Hintergrunds

   * Zunachst benotigen wir einen Buhnenhintergrund im Mars-Stil. Klicken Sie, um einen Hintergrund auszuwahlen.

     .. image:: img/5_animate_choose.png

   * Wahlen Sie den **Mars**-Hintergrund aus.

     .. image:: img/5_animate_mars.png

#. Hinzufugen der Rover-Figur

   Wahlen Sie die **GalaxyRVR**-Figur aus der Bibliothek aus und passen Sie ihre Gro?e passend an die Szene an.

   .. image:: img/5_animate_rvr.png

#. Hindernisse hinzufugen

   Wahlen Sie eine **Felsen**-Figur aus der Bibliothek aus und passen Sie ihre Gro?e an.

   .. image:: img/5_animate_rock.png


Programmieren der GalaxyRVR-Figur
------------------------------------------

Programmieren Sie Ihre GalaxyRVR-Figur so, dass sie von links nach rechts über den Bildschirm fahrt. Ihre Mission: Fuhren Sie sie sicher an den Felsen vorbei!
Verwenden Sie Ihre Hande, um die IR-Sensoren des physischen Rovers auszulösen - der rechte Sensor bewegt die Figur nach unten, der linke Sensor nach oben.

#. Stellen Sie die Startposition ein, indem Sie die Figur an den linken Rand der Buhne bewegen. Die Bewegungsblocke werden automatisch mit den korrekten Koordinaten aktualisiert.

   .. image:: img/5_animate_glide.png

#. Fugen Sie einen forever-Block hinzu, um die Hauptprogrammschleife zu erstellen, die kontinuierlich lauft.

   .. image:: img/5_animate_forever.png

#. Fugen Sie einen Bedingungsblock ein, um zu prufen, ob der Rover einen Felsen beruhrt.

   .. image:: img/5_animate_touching.png

#. Wenn kein Felsen erkannt wird, bewegen Sie sich weiter vorwarts in Richtung der rechten Seite.

   .. image:: img/5_animate_moving.png

#. Wenn der Rover einen Felsen trifft, stoppen Sie alle Bewegungen und zeigen Sie eine Warnmeldung an.

   .. image:: img/5_animate_say.png

#. Fugen Sie Sensorsteuerungen hinzu: Erstellen Sie Ereignisse für beide IR-Sensoren, die die Figur nach oben (linker Sensor) oder nach unten (rechter Sensor) bewegen, wenn sie durch Ihre Hand ausgelost werden.

   .. image:: img/5_animate_y.png

Programmieren der Felsen-Figur
------------------------------------

Erstellen wir mehrere Felshindernisse, um das Spiel herausfordernder zu gestalten! Wir verwenden Klone, um Felsen an zufalligen Positionen auf der Buhne zu erzeugen.

#. Erstellen Sie Felsen-Klone mit dem Block "erzeuge Klon von mir".

   .. image:: img/5_animate_clone.png

#. Lassen Sie jeden Klon an einer zufalligen Position erscheinen, indem Sie den Block "gehe zu zufalliger Position" hinzufugen.

   .. image:: img/5_animate_clone_move.png
      :width: 200

#. Erzeugen Sie zehn Felsen, indem Sie die Klonerstellung zehnmal wiederholen.

   .. image:: img/5_animate_clone_10.png
      :width: 200

#. Stellen Sie ein, dass all diese Aktionen starten, wenn die grune Flagge angeklickt wird.

   .. image:: img/5_animate_clone_flag.png
      :width: 200

Missionsstart!
----------------------------

Herzlichen Gluckwunsch! Ihr Mars-Hindernisvermeidungsspiel ist startbereit.

Verbinden Sie Ihren GalaxyRVR mit der App und klicken Sie auf die grune Flagge, um Ihre Mission zu beginnen. Beobachten Sie, wie zufallig Felsen in der Marslandschaft erscheinen.

Ihre Herausforderung: Verwenden Sie Ihre Hande, um die IR-Sensoren auszulösen, und führen Sie die GalaxyRVR-Figur vorsichtig über den Bildschirm. Bewegen Sie sie nach oben und unten, um den Felsen auszuweichen und sicher die rechte Seite zu erreichen!

Können Sie die Mission ohne Zusammensto?e abschlie?en? Wie schnell können Sie den Hindernisparcours bewaltigen? Uben Sie weiter, um ein Meisterpilot des Mars Rovers zu werden!