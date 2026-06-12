.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Spaß 4 Apfel fressen
====================================

In diesem Projekt verwenden wir ein Infrarot-Hindernisvermeidungsmodul, um die Käfer-Figur zu einem Apfel zu führen.

Klicken Sie auf die grüne Flagge. Fahren Sie dann schnell mit Ihrer Hand über das linke Hindernisvermeidungsmodul (blockieren Sie es und entfernen Sie Ihre Hand schnell wieder), um die Drehung des Käfers auszulösen. Wenn er richtig ausgerichtet ist, fahren Sie erneut mit der Hand über das Modul, um den Käfer vorwärts zu bewegen, sodass er die schwarzen Linien auf der Karte vermeidet. Wenn Anpassungen oder Drehungen erforderlich sind, fahren Sie erneut mit der Hand über das Modul, um den Käfer in den gewünschten Winkel zu drehen. Wiederholen Sie diese Schritte, bis die Käfer-Figur den Apfel erreicht.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_eat_apple.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Im Folgenden finden Sie die Schritte zur Umsetzung des Projekts. Es wird empfohlen, zunächst diesen Schritten zu folgen. Sobald Sie damit vertraut sind, können Sie die Effekte nach Wunsch verändern.

1. Den **Labyrinth**-Hintergrund zeichnen
--------------------------------------------------

Hier zeichnen wir einen Kartenhintergrund mit einem roten Apfel darauf.

* Wählen Sie zunächst einen leeren Hintergrund aus.

  .. image:: img/apple_click_backdrop.png

* Klicken Sie auf **Hintergründe**, um mit dem Zeichnen des Kartenhintergrunds zu beginnen. Benennen Sie den Hintergrund zunächst in **Maze** um.

  .. image:: img/apple_open_backdrop.png

* Verwenden Sie das **Linie**-Werkzeug, stellen Sie die Farbe auf Schwarz, die Breite auf 4 und beginnen Sie mit dem Zeichnen der Karte. Sie können Ihre Karte nach Ihren eigenen Vorstellungen gestalten; sie muss nicht wie meine aussehen.

  .. image:: img/apple_paint_bk_maze2.png
    :width: 90%

* Zeichnen Sie nun einen Apfel. Verwenden Sie das **Kreis**-Werkzeug, um eine Ellipse oder einen Kreis in Rot ohne Umriss zu zeichnen.

  .. image:: img/apple_paint_bk_maze3.png

  .. note::

    Sie können den Umriss entfernen, indem Sie auf das **Umriss**-Fenster klicken und dann das **Entfernen**-Werkzeug verwenden.

    .. image:: img/apple_paint_bk_maze4.png

* Wählen Sie das **Pinsel**-Werkzeug und eine Farbe und Breite aus, um den Apfel fertig zu zeichnen.

  .. image:: img/apple_paint_bk_maze5.png

2. Den **Gewonnen**-Hintergrund zeichnen
--------------------------------------------------

Beginnen Sie nun mit dem Zeichnen. Folgen Sie den untenstehenden Schritten oder gestalten Sie Ihren Hintergrund nach Ihrer Kreativität. Stellen Sie sicher, dass er einen Sieg darstellt.

* Klicken Sie unten auf die Schaltfläche, um einen neuen Hintergrund hinzuzufügen, wählen Sie **Malen** und nennen Sie diesen Hintergrund **Win**.

  .. image:: img/apple_paint_bk_win.png

* Zeichnen Sie mit dem **Kreis**-Werkzeug eine Ellipse in Rot ohne Umriss.

  .. image:: img/apple_paint_bk_win2.png
    :width: 90%

* Verwenden Sie dann das **Text**-Werkzeug, um "WIN!" zu schreiben. Stellen Sie die Schriftfarbe auf Schwarz und passen Sie die Größe und Position des Textes an.

  .. image:: img/apple_paint_bk_cus2.png
    :width: 90%

3. Skript für den **Labyrinth**-Hintergrund
--------------------------------------------------

Stellen Sie sicher, dass der Hintergrund jedes Mal, wenn das Spiel startet, auf **Maze** wechselt.

.. image:: img/apple_switch_backdrop.png
  :width: 90%

4. Die Figur **Beetle** auswählen
--------------------------------------------------

* Löschen Sie die Standardfigur und wählen Sie die Figur **Beetle**.

  .. image:: img/apple_choose_sprite.png

* Platzieren Sie die Figur **Beetle** am Eingang des **Maze**-Hintergrunds. Notieren Sie die x- und y-Koordinaten an dieser Stelle und passen Sie die Größe der Figur auf 40 % an.

  .. image:: img/apple_place_sprite.png

5. Skript für die Figur **Beetle** erstellen
-----------------------------------------------------

Schreiben Sie nun ein Skript für die Figur **Beetle**, damit sie sich unter der Steuerung des linken Hindernisvermeidungsmoduls vorwärts bewegt und die Richtung ändert.

* Wenn die grüne Flagge angeklickt wird, setzen Sie den Winkel des **Beetle** auf 90 und die Position auf (-124, -113) oder verwenden Sie die Koordinatenwerte Ihrer Platzierung.

  .. image:: img/apple_point_in.png
    :width: 90%

* Erstellen Sie die Variable **flag** und setzen Sie ihren Anfangswert auf -1.

  .. image:: img/apple_vable_flag.png

Verwenden Sie anschließend innerhalb des [wiederhole fortlaufend]-Blocks vier [wenn]-Blöcke, um verschiedene Szenarien zu verwalten.

* Wenn das linke Infrarot blockiert ist, verwenden Sie den [`mod <https://en.scratch-wiki.info/wiki/Boolean_Block>`_] Block, um die Variable **flag** zwischen 0 und 1 umzuschalten (abwechselnd 0 für dieses Drücken und 1 für das nächste).

   .. image:: img/apple_read_ir.png

* Wenn die Flagge 0 ist (linkes Infrarot ist blockiert), lassen Sie die Figur **Beetle** im Uhrzeigersinn drehen. Wenn die Flagge 1 ist (linkes Infrarot ist erneut blockiert), bewegt sich **Beetle** vorwärts. Andernfalls dreht er sich weiter im Uhrzeigersinn.

  .. image:: img/apple_read_flag.png

* Wenn die Figur **Beetle** Schwarz berührt (die schwarze Linie auf dem **Maze**-Hintergrund), endet das Spiel und das Skript stoppt.

  .. image:: img/apple_touch_black1.png

  .. note::

    Klicken Sie auf den Farbbereich im Block [Farbe berührt] und wählen Sie das Pipettenwerkzeug aus, um die Farbe der schwarzen Linie auf der Bühne aufzunehmen. Wenn Sie eine beliebige schwarze Farbe auswählen, funktioniert dieser Block [Farbe berührt] nicht richtig.

    .. image:: img/apple_touch_black.png

* Wenn der Käfer Rot berührt (verwenden Sie ebenfalls das Pipettenwerkzeug, um die rote Farbe des Apfels aufzunehmen), wechselt der Hintergrund zu **Win**, was den erfolgreichen Abschluss des Spiels anzeigt, und das Skript stoppt.

  .. image:: img/apple_touch_red.png

Die Programmierung ist abgeschlossen. Sie können nun auf die grüne Flagge klicken, um das Skript auszuführen und zu sehen, ob der gewünschte Effekt erreicht wird.


  .. raw:: html

    <video loop autoplay muted style = "max-width:70%">
        <source src="../../_static/video/sc_eat_apple.mp4"  type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>
