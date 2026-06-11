
Spaß 6 Abstandsempfindlicher Ball
===================================================================

In diesem Projekt verwenden wir ein Ultraschallmodul, um die vertikale Bewegung eines Balls auf der Bühne zu steuern. Wenn Sie auf die grüne Flagge klicken, legen Sie Ihre Hand über das Ultraschallmodul. Der Ball steigt auf, wenn der Abstand zwischen Ihrer Hand und dem Modul weniger als 15 cm beträgt; andernfalls sinkt er. Wenn der Ball eine Linie berührt, wird ein erfreulicher Klang ausgelöst und ein funkelnder Sterneffekt aktiviert.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Folgen Sie diesen Schritten, um das Projekt einzurichten. Sobald Sie mit der Funktionsweise vertraut sind, können Sie die Effekte nach Wunsch anpassen.

1. Figuren auswählen
-----------------------------

* Entfernen Sie die Standardfigur und wählen Sie die Figuren **Ball**, **Bowl** und **Star** aus.

  .. image:: img/ball_choose_sprite.png

* Positionieren Sie die Figur **Bowl** am unteren Rand der Bühnenmitte und vergrößern Sie sie.

  .. image:: img/ball_set_bowl.png

* Platzieren Sie die Figur **Ball** direkt über der Figur **Bowl** und stellen Sie ihre Richtung auf 0, um eine vertikale Bewegung zu ermöglichen.

  .. image:: img/ball_set_ball.png

* Passen Sie die Größe der Figur **Star** an und stellen Sie ihre Richtung auf 180, um sicherzustellen, dass sie nach unten fällt. Dies kann bei Bedarf auf andere Winkel geändert werden.

  .. image:: img/ball_set_star.png

* Fügen Sie den **Stars**-Hintergrund für zusätzliche Atmosphäre hinzu.

  .. image:: img/ball_select_backdrop.png

2. Eine **Linie**-Figur zeichnen
--------------------------------------

* Fügen Sie nun eine **Linie**-Figur hinzu.

  .. image:: img/ball_select_line.png

* Wechseln Sie zur Seite **Kostüme** der Figur **Line**.

  .. image:: img/ball_open_cos.png
    :width: 90%

* Verringern Sie die Breite der roten Linie auf der Zeichenfläche leicht, duplizieren Sie sie viermal und richten Sie diese Linien aus.

  .. image:: img/ball_copy_line.png
    :width: 90%

* Färben Sie jede Linie unterschiedlich ein. Wählen Sie eine Linie aus, verwenden Sie das **Füllen**-Werkzeug und wählen Sie eine Farbe.

  .. image:: img/ball_set_bk_color.png
    :width: 90%

* Wenden Sie diese Methode an, um alle Linien entsprechend einzufärben.

  .. image:: img/ball_select_line_color.png
    :width: 90%

* Kehren Sie zur Seite **Code** zurück und positionieren Sie die Figur **Line** am oberen Rand der Bühne.

  .. image:: img/ball_line_position.png

3. Skript für die Figur **Ball** erstellen
--------------------------------------------------

Hier erstellen wir ein Skript für die Figur **Ball**, damit sie sich basierend auf der vom Ultraschallmodul erfassten Entfernung nach oben oder unten bewegt, mit einer Bewegungsbegrenzung, um die Landung auf der Figur **Bowl** zu simulieren.

* Wenn die grüne Flagge angeklickt wird, setzen Sie die Anfangsposition der Figur **Ball**.

  .. image:: img/ball_script_ball1.png

* Verwenden Sie einen [wenn sonst]-Block, um zu überprüfen, ob die Entfernung kleiner als 15 ist. Wenn dies zutrifft, bewegen Sie die Figur **Ball** um 10 Schritte nach oben, da ihre Richtung auf 0 eingestellt ist.

  .. image:: img/ball_script_ball3.png

* Andernfalls lassen Sie die Figur **Ball** fallen und begrenzen Sie ihre Y-Koordinate auf ein Minimum von -100, das anpassbar ist, sodass es aussieht, als würde sie auf der Figur **Bowl** landen.

  .. image:: img/ball_script_ball4.png

* Programmieren Sie die Interaktion, bei der die Figur **Ball** bei Berührung der Figur **Line** ihre Y-Position in der Variable **ball_coor** speichert und eine **bling**-Nachricht sendet.

  .. image:: img/ball_script_ball5.png

4. Skript für die Figur **Star** erstellen
--------------------------------------------------

* Verstecken Sie die Figur **Star** zunächst, wenn die grüne Flagge angeklickt wird. Beim Empfang der Nachricht **Bling** klonen Sie die Figur **Star**.

  .. image:: img/ball_script_star1.png

* Setzen Sie die Position und Toneffekte des Klons so, dass sie mit der Position der Figur **Ball** synchronisiert werden.

  .. image:: img/ball_script_star2.png

* Lassen Sie sie sich zufällig zwischen -80 und 80 Grad drehen.

  .. image:: img/ball_script_star3.png

* Passen Sie das Erscheinungsbild und Verhalten der Figur **Star** nach Bedarf an, um den visuellen Effekt zu verbessern.

  .. image:: img/ball_script_star4.png

Die Programmierung ist abgeschlossen. Klicken Sie auf die grüne Flagge, um das Skript auszuführen und zu sehen, ob es Ihren Erwartungen entspricht.


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>
