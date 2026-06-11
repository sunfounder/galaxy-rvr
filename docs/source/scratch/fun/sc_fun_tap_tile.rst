
.. _sc_tap_tile:

Spaß 7 Auf die schwarze Kachel tippen
=================================================================

Viele von Ihnen kennen das beliebte Handyspiel, bei dem man auf schwarze Kacheln tippt, um Punkte zu sammeln, und weiße Kacheln vermeiden muss. Wir bringen diese süchtig machende Herausforderung mit zwei Hindernisvermeidungsmodulen. Wenn Ihre Hand über einem der IR-Module blockiert wird, wird ein Tippen auf der Bühne registriert.

Wenn ein Tippen auf einer schwarzen Kachel landet, erhalten Sie einen Punkt; das Tippen auf eine weiße Kachel zieht einen Punkt ab. Die Spieler müssen schnell entscheiden, ob sie über das linke oder rechte IR-Modul tippen, basierend auf der Position der schwarzen Kacheln.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_tap_black_tile.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Im Folgenden finden Sie die Schritte zur Umsetzung des Projekts. Es wird empfohlen, zunächst diesen Schritten zu folgen. Sobald Sie damit vertraut sind, können Sie die Effekte nach Wunsch verändern.

1. Eine **Kachel**-Figur malen
-------------------------------------------------

Eine **Kachel**-Figur wird verwendet, um den Effekt abwechselnd schwarzer und weißer Kacheln zu erzielen, die sich nach unten bewegen. In der Handyversion dieses Spiels gibt es normalerweise 4 Spalten; hier machen wir nur zwei Spalten.


* Löschen Sie die Standardfigur, tippen Sie auf das Symbol **Figur hinzufügen** und wählen Sie **Malen**.

  .. image:: img/tile_paint_tile1.png

* Wechseln Sie anschließend zur Seite **Kostüme** und verwenden Sie das **Rechteck**-Werkzeug, um ein Rechteck mit einem grauen Rahmen und weißer Füllung zu zeichnen.

  .. image:: img/tile_paint_tile2.png
    :width: 90%

* Wählen Sie das Rechteck aus und klicken Sie auf **Kopieren** -> **Einfügen**, um ein identisches Rechteck zu erstellen. Verschieben Sie dann die beiden Rechtecke an eine bündige Position.

  .. image:: img/tile_paint_tile3.png
    :width: 90%

* Wählen Sie eines der Rechtecke aus und wählen Sie eine schwarze Füllfarbe.

  .. image:: img/tile_paint_tile4.png
    :width: 90%

* Wählen Sie nun beide Rechtecke aus und verschieben Sie sie so, dass ihre Mittelpunkte mit dem Mittelpunkt der Zeichenfläche übereinstimmen.

  .. image:: img/tile_paint_tile5.png
    :width: 90%

* Duplizieren Sie Kostüm1, wobei die Füllfarben der beiden Rechtecke abwechselnd angeordnet sind. Beispielsweise hat Kostüm1 links eine weiße und rechts eine schwarze Füllfarbe, und Kostüm2 hat links eine schwarze und rechts eine weiße Füllfarbe.

  .. image:: img/tile_paint_tile6.png
    :width: 90%

* Kehren Sie zur Seite **Code** zurück und setzen Sie den Namen der Figur auf **Tile**.

  .. image:: img/tile_paint_tile7.png

2. Skript für die Figur **Tile** erstellen
--------------------------------------------------

* Legen Sie zunächst die Anfangsposition der Figur **Tile** fest, sodass sie sich am oberen Rand der Bühne befindet.

  .. image:: img/tile_script_tile1.png

* Erstellen Sie eine Variable - **blocks** und geben Sie ihr einen Anfangswert, um die Anzahl der Erscheinungen der Figur **Tile** zu bestimmen. Verwenden Sie den Block [wiederhole bis], um die Variable **blocks** allmählich zu verringern, bis **blocks** 0 ist. Lassen Sie während dieser Zeit die Figur **Tile** zufällig ihr Kostüm wechseln. Nach dem Klicken auf die grüne Flagge sehen Sie, wie die Figur **Tile** auf der Bühne schnell die Kostüme wechselt.

  .. image:: img/tile_script_tile2.png

* Erstellen Sie Klone der Figur **Tile**, während die Variable **blocks** abnimmt, und stoppen Sie die Skriptausführung, wenn **blocks** 0 ist. Hier werden zwei Blöcke [warte () Sekunden] verwendet. Der erste begrenzt das Intervall zwischen den Klonen von **Tile**, und der zweite lässt die Variable **blocks** auf 0 sinken, ohne das Programm sofort zu stoppen, sodass die letzte Kachelfigur genügend Zeit hat, sich zu bewegen.

  .. image:: img/tile_script_tile3.png

* Programmieren Sie nun den Klon der Figur **Tile**, sodass er sich langsam nach unten bewegt und gelöscht wird, wenn er den unteren Rand der Bühne erreicht. Die Änderung der y-Koordinate beeinflusst die Fallgeschwindigkeit: Je größer der Wert, desto schneller die Fallgeschwindigkeit.

  .. image:: img/tile_script_tile4.png

* Verstecken Sie den Körper und zeigen Sie den Klon an.

  .. image:: img/tile_script_tile5.png

3. Skript für den Hintergrund
--------------------------------------

Im Hintergrund werden die Werte der 2 IR-Module gelesen und entsprechende Aktionen ausgeführt.

* Wenn die grüne Flagge angeklickt wird, setzen Sie die Variable **count** auf 0.

  .. image:: img/tile_script_backdrop.png
    :width: 90%

* Wenn das linke IR-Hindernisvermeidungsmodul Ihre Hand erfasst, senden Sie eine Nachricht - **left**.

  .. image:: img/tile_script_backdrop1.png


* Wenn das rechte IR-Hindernisvermeidungsmodul Ihre Hand erfasst, senden Sie eine Nachricht - **right**.

  .. image:: img/tile_script_backdrop2.png


4. **Linkes IR** Figur malen
--------------------------------------
Eine **Linkes IR**-Figur wird verwendet, um den Klick-Effekt zu erzielen. Wenn das linke IR-Modul Ihre Hand erfasst, sendet es eine Nachricht - **left** an die Figur **Linkes IR**, die ihre Arbeit aufnimmt. Wenn sie die schwarze Kachel auf der Bühne berührt, wird die Punktzahl um 1 erhöht, andernfalls wird die Punktzahl um 1 verringert.


* Tippen Sie erneut auf das Symbol **Figur hinzufügen** und wählen Sie **Malen**.

  .. image:: img/tile_paint_ir1.png

* Wechseln Sie zur Seite **Kostüme**, wählen Sie die Füllfarbe (eine beliebige Farbe außer Schwarz und Weiß) und zeichnen Sie einen Kreis.

  .. image:: img/tile_paint_ir2.png

* Kehren Sie zur Seite **Code** zurück und ändern Sie den Namen der Figur in **Left IR**.

  .. image:: img/tile_paint_ir3.png

5. Skript für die Figur **Left IR** erstellen
----------------------------------------------------

* Beginnen Sie nun mit der Skripterstellung für die Figur **Left IR**. Wenn die grüne Flagge angeklickt wird, verstecken Sie die Figur zunächst.

  .. image:: img/tile_script_ir1.png

* Wenn die Nachricht - **left** empfangen wird (das linke IR-Empfängermodul erkennt ein Hindernis), zeigen Sie die Figur an, setzen Sie ihre Größe auf 100 % und schrumpfen Sie sie dann in Abständen von 10 mithilfe eines [Wiederhole]-Blocks, bevor Sie sie wieder verstecken. Dies verleiht der Figur einen Ausdehnungs- und Zusammenziehungseffekt.

  .. image:: img/tile_script_ir2.png

* Bestimmen Sie dann, ob der schwarze Block der Figur **Tile** berührt wird. Wenn ja, lassen Sie die Variable **count** um 1 erhöhen, andernfalls um 1 verringern.

  .. image:: img/tile_script_ir3.png

.. note::

    Sie müssen die Figur **Tile** auf der Bühne erscheinen lassen und dann die Farbe des schwarzen Blocks in der Figur **Tile** aufnehmen.

    .. image:: img/tile_script_ir4.png

6. **Rechtes IR** Figur
--------------------------------------------------
Die Funktion der Figur **Rechtes IR** ist im Wesentlichen dieselbe wie die von **Linkes IR**, mit dem Unterschied, dass sie die **Rechts**-Information empfängt.


* Duplizieren Sie nun die Figur **Left IR** und ändern Sie den Namen der Figur in **Right IR**.

  .. image:: img/tile_paint_ir4.png

* Ändern Sie dann die empfangene Nachricht in - **right**.

    .. image:: img/tile_script_ir5.png

7. Das Skript ausführen
---------------------------------

* Passen Sie nun die Positionen und Größen der drei Figuren an.

  * Ziehen Sie die Figur **Tile** an den unteren Rand der Bühne und setzen Sie ihre x-Position auf 0.
  * Verschieben Sie die Figur **Left IR** in den linken Rahmen. Sie müssen auf der Seite **Kostüme** die Größe der Figur auf nur 50 % der Rahmengröße reduzieren.
  * Verschieben Sie die Figur **Right IR** auf die gleiche Weise in den rechten Rahmen. Sie müssen auf der Seite **Kostüme** die Größe der Figur auf nur 50 % der Rahmengröße reduzieren.
  * Stellen Sie sicher, dass die Figuren **Left IR** und **Right IR** über der Figur **Tile** liegen.

  .. image:: img/tile_paint_ir5.png

* Nun ist die gesamte Skripterstellung abgeschlossen, und Sie können auf die grüne Flagge klicken, um das Skript auszuführen.

  .. raw:: html

    <video loop autoplay muted style = "max-width:70%">
        <source src="../../_static/video/sc_tap_black_tile.mp4"  type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>
