
.. _sc_parrot:

Spaß 2 Flappy Parrot
================================

In diesem Projekt verwenden wir ein Ultraschallmodul, um ein Flappy-Parrot-Spiel zu spielen.

Nach dem Starten des Skripts bewegt sich das grüne Bambusrohr (Paddle) von rechts nach links in einer zufälligen Höhe. Um den Papagei zu steuern, legen Sie Ihre Hand über das Ultraschallmodul. Wenn der Abstand zwischen Ihrer Hand und dem Modul weniger als 10 cm beträgt, steigt der Papagei auf; andernfalls sinkt er. Sie müssen diesen Abstand sorgfältig steuern, um den Papagei sicher am grünen Bambus vorbeizuführen. Eine Berührung mit dem Bambus beendet das Spiel.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Im Folgenden finden Sie die Schritte zur Umsetzung des Projekts. Es wird empfohlen, zunächst diesen Schritten zu folgen. Sobald Sie damit vertraut sind, können Sie die Effekte nach Wunsch verändern.

1. Figuren hinzufügen
-------------------------------

* Löschen Sie die Standardfigur und verwenden Sie die Schaltfläche **Figur auswählen**, um die Figur **Parrot** hinzuzufügen. Setzen Sie ihre Größe auf 50 % und positionieren Sie sie in der unteren linken Ecke.

  .. image:: img/parrot_choose_parrot.png

* Fügen Sie die Figur **Paddle** hinzu, setzen Sie ihre Größe auf 150 %, drehen Sie sie um 180 Grad und positionieren Sie sie in der oberen rechten Ecke.

  .. image:: img/parrot_choose_paddle.png

* Wechseln Sie zur Seite **Kostüme** der Figur **Paddle**, wählen Sie das **Paddle** auf der Zeichenfläche aus und klicken Sie dann auf das **Umriss**-Werkzeug.

  .. image:: img/parrot_set_parrot1.png
    :width: 90%

* Ändern Sie den Umrisseffekt in den Vollfüllmodus und verwenden Sie das Entfernungswerkzeug, um ihn zu beseitigen.

  .. image:: img/parrot_set_parrot2.png
    :width: 90%

2. Skript für die Figur **Parrot** erstellen
-----------------------------------------------------

Erstellen Sie ein Skript für die Figur **Parrot**, um ihren Flug zu simulieren, wobei die Höhe basierend auf der vom Ultraschallmodul erfassten Entfernung angepasst wird.

* Wenn die grüne Flagge angeklickt wird, wechseln Sie alle 0,2 Sekunden das Kostüm, um den Flugeindruck aufrechtzuerhalten.

  .. image:: img/parrot_script_parrot1.png

* Wenn die Ultraschall-Entfernung kleiner als 10 cm ist, erhöhen Sie die y-Koordinate um 50, sodass der **Parrot** aufsteigt. Andernfalls verringern Sie die y-Koordinate um 40, sodass der **Parrot** sinkt.

  .. image:: img/parrot_script_parrot3.png

* Wenn die Figur **Parrot** die Figur **Paddle** berührt, endet das Spiel und die Skriptausführung wird gestoppt.

  .. image:: img/parrot_script_parrot4.png

3. Skript für die Figur **Paddle** erstellen
----------------------------------------------------

Erstellen Sie ein Skript für die Figur **Paddle**, damit sie zufällig auf der Bühne erscheint.

* Verstecken Sie die Figur **Paddle**, wenn die grüne Flagge angeklickt wird, und erstellen Sie gleichzeitig einen Klon von sich selbst. Der Block [`erzeuge Klon von <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_] steuert diesen Klonvorgang.

  .. image:: img/parrot_script_paddle1.png

* Setzen Sie die Position des Klons mit der x-Koordinate auf 220 (ganz rechts) und die y-Koordinate zufällig zwischen (-125 und 125).

  .. image:: img/parrot_script_paddle2.png

* Verwenden Sie den Block [wiederhole], um die x-Koordinate allmählich zu verringern, sodass sich der Klon langsam von rechts nach links bewegt, bis er verschwindet.

  .. image:: img/parrot_script_paddle3.png

* Erstellen Sie einen neuen Klon der Figur **Paddle** und löschen Sie den vorherigen Klon.

  .. image:: img/parrot_script_paddle4.png

Die Programmierung ist abgeschlossen. Sie können nun auf die grüne Flagge klicken, um das Skript auszuführen und zu sehen, ob der gewünschte Effekt erreicht wird.


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>
