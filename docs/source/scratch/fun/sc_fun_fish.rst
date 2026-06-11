
.. _sh_fishing:

Spaß 5 Angeln
========================================

Tauchen Sie ein in unser interaktives Angelspiel, das das linke Hindernisvermeidungsmodul für ein fesselndes Erlebnis nutzt.

Wenn das Skript aktiv ist, schwimmen Fische hin und her über die Bühne. Um einen Fisch zu fangen, müssen Sie das linke Hindernisvermeidungsmodul genau in dem Moment blockieren, in dem der Fisch am Haken vorbeischwimmt. Das Spiel zählt automatisch die Anzahl der gefangenen Fische.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_fishing.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Folgen Sie diesen ersten Schritten, um das Projekt einzurichten. Sobald Sie mit dem Aufbau vertraut sind, können Sie die Effekte nach Wunsch anpassen.

1. Hintergrund und Figuren hinzufügen
----------------------------------------------

Wählen Sie zunächst einen **Unterwasser**-Hintergrund aus, fügen Sie dann eine **Fish**-Figur hinzu und lassen Sie sie über die Bühne schwimmen.

* Verwenden Sie die Schaltfläche **Hintergrund auswählen**, um einen **Unterwasser**-Hintergrund auszuwählen.

  .. image:: img/fish_choose_backdrop.png

* Löschen Sie die ursprüngliche Figur und wählen Sie dann die Figur **Fish** aus.

  .. image:: img/fish_choose_fish.png

* Passen Sie die Größe und Position der Figur **Fish** an.

  .. image:: img/fish_set_fish.png

2. Eine **Angelhaken**-Figur zeichnen
----------------------------------------------

Erstellen Sie als Nächstes eine **Angelhaken**-Figur, die Sie über das linke Hindernisvermeidungsmodul steuern, um mit dem Angeln zu beginnen.

* Fügen Sie die Figur **Glow-J** über **Figur auswählen** hinzu und benennen Sie sie in "Fishhook" um.

  .. image:: img/fish_choose_j.png

* Wechseln Sie zur Seite **Kostüme** der Figur **Glow-J**, benennen Sie sie in **Fishhook** um, wählen Sie das innere weiße 'J' aus und ändern Sie seine Farbe in Rot.

  .. image:: img/fish_set_j1.png
    :width: 90%

* Entfernen Sie die äußere cyanfarbene Füllung und verringern Sie die Breite. Stellen Sie sicher, dass die Oberseite des Hakens mit dem Mittelpunkt ausgerichtet ist.

  .. image:: img/fish_set_j2.png

* Verwenden Sie das **Linienwerkzeug**, um eine Linie zu zeichnen, die vom Mittelpunkt nach oben verläuft und aus der Bühne herausragt.

  .. image:: img/fish_set_j3.png

3. Skript für die Figur **Fish** erstellen
--------------------------------------------------

Die Figur **Fish** soll sich auf der Bühne nach links und rechts bewegen. Wenn sie im Angelzustand mit der Figur **Fishhook** interagiert, soll sie schrumpfen, sich zu einer bestimmten Position bewegen, dann verschwinden, woraufhin eine neue Figur **Fish** erscheint.

* Erstellen Sie eine Variable **score** zum Speichern der Anzahl gefangener Fische, verstecken Sie diese Figur und klonen Sie sie.

  .. image:: img/fish_script_fish1.png

* Zeigen Sie den Klon der Figur **Fish** an, wechseln Sie sein Kostüm und setzen Sie die Anfangsposition.

  .. image:: img/fish_script_fish2.png

* Ermöglichen Sie dem Klon der Figur **Fish**, sich nach links und rechts zu bewegen und beim Berühren des Bühnenrands zurückzuprallen.

  .. image:: img/fish_script_fish3.png

* Wenn der Klon der Figur **Fish** die Figur **Fishhook** im Angelzustand (wenn sie rot ist) berührt.

  .. image:: img/fish_script_fish4.png
    :width: 90%

* Erhöhen Sie die Punktzahl (Variable score) um 1, zeigen Sie eine Punktanimationssequenz an (schrumpft um 40 %, bewegt sich schnell zur Position der Anzeigetafel und verschwindet). Gleichzeitig wird ein neuer Fisch (ein neuer Klon der Figur **Fish**) erstellt und das Spiel fortgesetzt.

  .. image:: img/fish_script_fish5.png

4. Skript für die Figur **Fishhook** erstellen
-------------------------------------------------------

Die Figur **Fishhook** bleibt normalerweise in einem gelben Zustand unter Wasser. Wenn Ihre Hand das linke Infrarotmodul blockiert, wechselt sie in den Angelzustand (rot) und bewegt sich über die Bühne.

* Wenn die grüne Flagge angeklickt wird, setzen Sie den Farbeffekt der Figur auf 30 (gelb) und legen Sie ihre Anfangsposition fest.

  .. image:: img/fish_script_hook1.png

* Wenn Ihre Hand das linke Infrarotmodul blockiert, setzen Sie den Farbeffekt auf 0 (rot, Einleitung des Angelzustands), warten Sie 0,1 Sekunden und bewegen Sie dann die Figur **Fishhook** an den oberen Rand der Bühne.

  .. image:: img/fish_script_hook2.png

* Nachdem Sie Ihre Hand entfernt haben, lassen Sie den **Fishhook** in seine Anfangsposition zurückkehren.

  .. image:: img/fish_script_hook3.png

Nachdem Sie die Programmierung abgeschlossen haben, klicken Sie auf die grüne Flagge, um das Skript auszuführen und zu sehen, ob der gewünschte Effekt erreicht wird.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_fishing.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

