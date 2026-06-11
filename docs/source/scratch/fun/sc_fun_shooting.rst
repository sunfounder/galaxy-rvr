
.. _sc_shooting:

Spaß 3 Schießen
===========================================

Haben Sie schon einmal diese spannenden Schießspiele im Fernsehen gesehen, bei denen die Teilnehmer gekonnt auf das Ziel zielen, um Punkte zu sammeln? Jetzt können Sie denselben Adrenalinschub direkt in Scratch erleben! In unserem interaktiven Schießspiel zielen Sie mit der Fadenkreuz-Figur so nah wie möglich an das Zentrum der Zielscheibe, um mit jedem präzisen Schuss Ihre Punktzahl zu maximieren.

Klicken Sie zunächst auf die grüne Flagge. Sie steuern Ihre Schüsse mit dem innovativen Hindernisvermeidungsmodul. Sind Sie bereit, Ihre Zielgenauigkeit und Reflexe zu testen? Mal sehen, wie Sie punkten!


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Im Folgenden finden Sie die Schritte zur Umsetzung des Projekts. Es wird empfohlen, zunächst diesen Schritten zu folgen. Sobald Sie damit vertraut sind, können Sie die Effekte nach Wunsch verändern.

1. Die Figur **Crosshair** malen
--------------------------------------------------

* Löschen Sie die Standardfigur, wählen Sie die Schaltfläche **Figur** und klicken Sie auf **Malen**.

  .. image:: img/shooting_paint_cross.png

* Wechseln Sie zur Seite **Kostüme**. Verwenden Sie das **Kreis**-Werkzeug, entfernen Sie die Füllfarbe und stellen Sie die Farbe und Breite des Umrisses ein.

  .. image:: img/shooting_paint_cross1.png

* Zeichnen Sie einen Kreis mit dem **Kreis**-Werkzeug. Nach dem Zeichnen verwenden Sie das **Auswählen**-Werkzeug, um den Mittelpunkt des Kreises mit dem Mittelpunkt der Zeichenfläche auszurichten.

  .. image:: img/shooting_paint_cross2.png

* Zeichnen Sie mit dem **Linie**-Werkzeug ein Kreuz innerhalb des Kreises.

  .. image:: img/shooting_paint_cross3.png

* Kehren Sie schließlich zur Seite **Code** zurück und benennen Sie die Figur in "Crosshair" um.

  .. image:: img/shooting_paint_cross4.png

2. Die Figur **Target** malen
----------------------------------------------

* Wählen Sie ebenfalls die Schaltfläche **Figur** und klicken Sie auf **Malen**.

  .. image:: img/shooting_paint_target1.png

* Wechseln Sie zur Seite **Kostüme**. Verwenden Sie das **Kreis**-Werkzeug, wählen Sie eine schwarze Farbe, entfernen Sie den Umriss und malen Sie einen großen Kreis.

  .. image:: img/shooting_paint_target3.png
    :width: 90%

* Zeichnen Sie mit derselben Methode zusätzliche Kreise, jeweils in einer anderen Farbe. Passen Sie die Position der überlappenden Kreise mit dem Werkzeug **Nach vorne** oder **Nach hinten** an, sodass die Ursprünge aller Kreise mit dem Mittelpunkt der Zeichenfläche übereinstimmen.

  .. image:: img/shooting_paint_target4.png
    :width: 90%

* Kehren Sie zur Seite **Code** zurück und benennen Sie diese Figur in "Target" um.

  .. image:: img/shooting_paint_target5.png

3. Einen Hintergrund hinzufügen
--------------------------------------

* Fügen Sie einen geeigneten Hintergrund hinzu, der vorzugsweise weniger farbenfroh ist und nicht den Farben der Figur **Target** entspricht. Ich habe den Hintergrund **Wall1** gewählt.

  .. image:: img/shooting_choose_backdrop.png

* Passen Sie die Positionen und Größen der Figuren **Target** und **Crosshair** an.

  .. note::

    * Stellen Sie sicher, dass die Figur **Crosshair** über der Figur **Target** liegt, indem Sie zuerst die Figur **Target** und dann **Crosshair** verschieben.
    * **Crosshair** sollte kleiner sein als der Abstand zwischen den Farbringen der Figur **Target**.

  .. image:: img/shooting_choose_backdrop1.png

4. Skript für die Figur **Crosshair** erstellen
-------------------------------------------------------

* Randomisieren Sie die Position und Größe der Figur **Crosshair**, sodass sie sich unvorhersehbar bewegt.

  .. image:: img/shooting_script_cross.png

* Wenn das linke Hindernisvermeidungsmodul blockiert wird, wird eine Nachricht gesendet - Schießen.

  .. image:: img/shooting_script_cross1.png

* Wenn die Nachricht **Schießen** empfangen wird, stoppt die Figur ihre Bewegung und schrumpft allmählich, um das Abfeuern eines Projektils zu simulieren.

  .. image:: img/shooting_script_cross2.png

* Verwenden Sie den Block [Farbe () berührt], um die Position des Schusses zu bestimmen.

  .. image:: img/shooting_script_cross3.png
    :width: 90%

* Geben Sie eine Punktzahl von 10 aus, wenn der Schuss innerhalb des gelben Kreises landet.

  .. image:: img/shooting_script_cross4.png

* Geben Sie eine Punktzahl von 9 aus, wenn der Schuss innerhalb des roten Kreises landet. Verwenden Sie ebenfalls den Block [Farbe () berührt], um die Farbe des roten Kreises zu erfassen.

  .. image:: img/shooting_script_cross5.png
    :width: 90%

* Verwenden Sie dieselbe Methode, um den Landepunkt des Projektils zu bestätigen. Wenn es nicht auf der Figur **Target** landet, handelt es sich um einen Fehlschuss.

  .. image:: img/shooting_script_cross6.png

Die Programmierung ist abgeschlossen. Sie können nun auf die grüne Flagge klicken, um das Skript auszuführen und zu sehen, ob der gewünschte Effekt erreicht wird.


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>
