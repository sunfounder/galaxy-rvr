.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


.. _sc_balloon:

Spaß 1 Ballon aufblasen
===================================================

In diesem interaktiven Projekt steuern Sie den Flug eines Ballons.

Nach dem Klicken auf die grüne Flagge wird der Ballon allmählich aufgeblasen. Wenn der Ballon zu groß wird, platzt er; wenn er zu klein ist, fällt er herunter. Ihre Aufgabe ist es, das linke Infrarotmodul im richtigen Moment zu blockieren, um den Ballon aufsteigen zu lassen.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_balloon.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Im Folgenden finden Sie die Schritte zur Umsetzung des Projekts. Es ist empfehlenswert, zunächst diesen Schritten zu folgen. Sobald Sie damit vertraut sind, können Sie die Effekte nach Wunsch verändern.


1. Eine Figur und einen Hintergrund hinzufügen
--------------------------------------------------------

* Entfernen Sie die Standardfigur und klicken Sie auf die Schaltfläche **Figur auswählen** in der unteren rechten Ecke des Figurenbereichs. Wählen Sie dann die Figur **Ballon1** aus.

  .. image:: img/balloon_choose_sprite.png

* Fügen Sie einen **Promenade**-Hintergrund oder einen anderen Hintergrund Ihrer Wahl über die Schaltfläche **Hintergrund auswählen** hinzu.

  .. image:: img/balloon_choose_backdrop.png

2. Ein Kostüm für die Figur **Ballon1** malen
------------------------------------------------------------

Erstellen wir nun ein Explosionseffekt-Kostüm für den Ballon.

* Wechseln Sie zum Reiter **Kostüme** der Figur **Ballon1**, klicken Sie auf die Schaltfläche **Kostüm auswählen** unten links und wählen Sie **Malen**, um ein leeres **Kostüm** zu öffnen. Nennen Sie es "boom".

  .. image:: img/balloon_set_ball1.png

* Wählen Sie eine Farbe und verwenden Sie das **Pinsel**-Werkzeug, um ein Muster zu zeichnen.

  .. image:: img/balloon_set_ball2.png
    :width: 90%

* Wählen Sie eine andere Farbe, klicken Sie auf das **Füllen**-Werkzeug und tippen Sie in das Muster, um es zu füllen.

  .. image:: img/balloon_set_ball3.png
    :width: 90%

* Fügen Sie abschließend den Text "BOOM" hinzu, um das Explosionseffekt-Kostüm zu vervollständigen.

  .. image:: img/balloon_set_ball4.png
    :width: 90%

3. Skript für die Figur **Ballon** erstellen
--------------------------------------------------

* Initialisieren Sie die Position und Größe der Figur **Ballon1**.

  .. image:: img/balloon_script1.png

* Vergrößern Sie allmählich die Größe der Figur **Ballon**.

  .. image:: img/balloon_script2.png

* Blockieren Sie nun das linke Hindernisvermeidungsmodul, um die Figur **Ballon1** daran zu hindern, sich weiter aufzublähen.

  .. image:: img/balloon_script3.png

* Lassen Sie die Figur **Ballon1** nun basierend auf ihrer Größe entscheiden, ob sie auf- oder absteigt.

  * Wenn die Größe kleiner als 90 ist, sinkt sie (y-Koordinate verringert sich).
  * Wenn die Größe zwischen 90 und 120 liegt, steigt sie auf (y-Koordinate erhöht sich).

  .. image:: img/balloon_script4.png

* Wenn Sie das linke Hindernisvermeidungsmodul nicht blockieren, bläht sich der Ballon weiter auf, bis er eine Größe von 120 überschreitet, und explodiert dann (wechselt zum Explosionseffekt-Kostüm).

  .. image:: img/balloon_script5.png

Die Programmierung ist abgeschlossen. Sie können nun auf die grüne Flagge klicken, um das Skript auszuführen und zu sehen, ob der gewünschte Effekt erreicht wird.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_balloon.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>
