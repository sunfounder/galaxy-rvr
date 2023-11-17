Lektion 6: Erkundung des Hindernisvermeidungsmoduls
==============================================================

Wir tauchen in die Welt des Infrarot-Hindernisvermeidungsmoduls ein. Versteckt an den Seiten unseres Mars Rovers, agieren diese Sensoren als die „Augen“ des Rovers und helfen ihm, seitliche Hindernisse zu umgehen und sicher durch die Marslandschaft zu navigieren.

Wir lernen, wie wir diese Module in unseren Rover integrieren, das Geheimnis ihrer Funktion entwirren und Code entwickeln, um unseren Rover geschickt um alle Hindernisse herumzuführen.

Machen wir uns bereit, unseren Rover mit ein wenig marsianischer Hindernisvermeidungsintelligenz auszustatten! Lasst uns loslegen!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_ir1.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. note::

    Wenn du diesen Kurs nach dem vollständigen Zusammenbau des GalaxyRVR lernst, musst du diesen Schalter nach rechts bewegen, bevor du den Code hochlädst.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Kursziele
----------------------

* Verstehe das Arbeitsprinzip und die Anwendung des Infrarot-Hindernisvermeidungsmoduls.
* Lerne, wie man Arduino verwendet, um das Infrarot-Hindernisvermeidungsmodul zu steuern.
* Übe das Design und den Bau eines automatischen Hindernisvermeidungssystems basierend auf der Infrarot-Hindernisvermeidung.

Kursmaterialien
-----------------------

* Hindernisvermeidungsmodule
* Grundwerkzeuge und Zubehör (z.B. Schraubendreher, Schrauben, Kabel usw.)
* Mars Rover Modell (ausgestattet mit Rocker-Bogie-System, Hauptplatinen, Motoren)
* USB-Kabel
* Arduino IDE
* Computer

Kursschritte
--------------
**Schritt 1: Installiere das Hindernisvermeidungsmodul**

Jetzt werden wir die beiden Hindernisvermeidungsmodule am Rover installieren.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/UWEj_ROYAt0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Die Montageschritte waren einfach, nicht wahr? In den folgenden Schritten werden wir das Arbeitsprinzip dieser Module kennenlernen und erfahren, wie sie unserem Mars Rover helfen, Hindernisse zu vermeiden. Bleibt dran!


**Schritt 2: Entmystifizierung des Moduls**

Triff das Infrarot-Hindernisvermeidungsmodul - der schlaue Begleiter unseres Rovers. Dieses kleine Gerät ist ein Wunderwerk. Lass uns eine Tour machen:

.. image:: img/ir_avoid.png
    :width: 300
    :align: center


Hier sind die Pin-Definitionen:

* **GND**: Das ist wie der Anker des Moduls, das es mit dem Boden oder dem gemeinsamen Punkt im Schaltkreis verbindet.
* **+**: Hier erhält das Modul seine Energie, benötigt eine Stromversorgung von 3,3 bis 5V DC.
* **Out**: Das ist der Kommunikator des Moduls. Standardmäßig bleibt es hoch und wird nur niedrig, wenn es ein Hindernis erkennt.
* **EN**: Treffe den Controller des Moduls. Dieser **Enable**-Pin entscheidet, wann das Modul arbeiten soll. Standardmäßig ist es mit GND verbunden, was bedeutet, dass das Modul immer im Einsatz ist.


Bist du neugierig, wie dieses winzige Modul funktioniert? Es ist ziemlich interessant! Es verwendet ein Paar IR-Komponenten - einen Sender und einen Empfänger. Der Sender ist wie die Taschenlampe des Moduls und emittiert Infrarotlicht. 
Wenn ein Hindernis auftaucht, wird das Infrarotlicht zurückgeworfen und vom Empfänger aufgefangen. Das Modul gibt dann ein niedriges Signal aus und warnt unseren Rover vor dem Hindernis.

.. image:: img/ir_receive.png
    :align: center

Unser kleines Modul ist ziemlich robust und erkennt Hindernisse in einem Bereich von 2-40 cm und verfügt über ausgezeichnete Störunterdrückungsfähigkeiten. 
Allerdings wirkt sich die Farbe der Objekte auf die Sensorik aus. Dunklere Objekte, insbesondere schwarze, werden auf kürzere Distanz erkannt. 
Gegen eine weiße Wand ist der Sensor am effizientesten und erkennt innerhalb eines Bereichs von 2-30 cm.

Der niedrige Zustand des **EN**-Pins aktiviert das Modul, wobei die Jumper-Kappe den **EN**-Pin mit dem GND verbindet. Wenn du den **EN**-Pin über Code steuern möchtest, muss die Jumper-Kappe entfernt werden.

.. image:: img/ir_cap.png
    :width: 400
    :align: center

Es gibt zwei Potentiometer auf dem Modul, eines zur Einstellung der Sendeleistung und eines zur Einstellung der Sendefrequenz, und durch Anpassen dieser beiden Potentiometer kannst du seine effektive Distanz anpassen.

.. image:: img/ir_avoid_pot.png
    :width: 400
    :align: center 

Das war einiges über unser kleines Modul. Im nächsten Schritt lernen wir, wie wir es in unseren Rover integrieren und mit dem Arduino steuern können. Bleibt dran!


**Schritt 3: Auslesen der 2 Module**

Wie neugierige Weltraumforscher tauchen wir in das Universum von Codes und Sensoren ein!


#. Unser Mars Rover ist mit zwei speziellen „Alien-Auge“-Sensoren ausgestattet, die ordentlich auf den Pins 7 (right) und 8 (left) angebracht sind. Diese „Alien-Auge“-Sensoren sind tatsächlich unsere Infrarot-Hindernisvermeidungsmodule, immer wachsam, um jegliche „Weltraumfelsen“ (Hindernisse) auf der interstellaren Reise unseres Rovers zu umgehen!

    .. image:: img/ir_shield.png

#. Als Nächstes müssen wir mit unserem Rover in der universellen Sprache des Arduino-Codes kommunizieren.


    Zuerst geben wir jedem Auge des Rovers einen einzigartigen Namen. Wir nennen sie ``IR_RIGHT`` und ``IR_LEFT``, so verwechseln wir sie nicht.

        .. code-block:: arduino

            #define IR_RIGHT 7
            #define IR_LEFT 8

    Jetzt lassen wir unseren Rover wissen, dass dies seine speziellen Augen sind - sie werden Informationen aus der Außenwelt in das elektronische Gehirn des Rovers übermitteln.

        .. code-block:: arduino

            pinMode(IR_RIGHT, INPUT);
            pinMode(IR_LEFT, INPUT);


    Um sicherzustellen, dass unser Rover seine Erkenntnisse mit uns teilt, richten wir eine geheime Kommunikationslinie ein, wie Spione in einem Sci-Fi-Film. Diese nächste Zeile startet ein serielles Gespräch mit einer Geschwindigkeit von 9600 Bits pro Sekunde - das ist blitzschneller Plauderei!
    
        .. code-block:: arduino

            Serial.begin(9600);


    Nun scannt unser Rover seine Umgebung mit seinen „Alien-Augen“ und leitet die Befunde an uns zurück. Wenn er ein Hindernis entdeckt, ist der Wert 0; wenn der Weg frei ist, ist der Wert 1. Er sendet uns diese Nachrichten ständig, um uns auf dem Laufenden zu halten.

        .. code-block:: arduino

            int rightValue = digitalRead(IR_RIGHT);
            int leftValue = digitalRead(IR_LEFT);
            Serial.print("Right IR: ");
            Serial.println(rightValue);
            Serial.print("Left IR: ");
            Serial.println(leftValue);


    Schließlich pausiert der Rover für einen Moment (etwa 200 Millisekunden) nach jeder Übertragung. Diese kleine Pause gibt uns die Chance, die Nachricht des Rovers zu interpretieren, bevor er eine weitere sendet.

        .. code-block:: arduino

            delay(200);

    Hier ist der vollständige Code:

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/98546821-5f4b-42ae-bc9f-e7ec15544c8b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Sobald dein Code fertig ist, wähle das richtige Board und den Port aus und sende den Code an deinen Mars Rover. Dann stimme dich in unsere geheime Kommunikationslinie (den Seriellen Monitor) ein, indem du auf sein Symbol in der oberen rechten Ecke klickst.

    .. image:: img/ir_open_serial.png

#. Bevor du die Nachrichten des Rovers empfängst, stelle sicher, dass deine geheime Kommunikationslinie mit derselben Geschwindigkeit (9600 Baud) wie dein Rover abgestimmt ist. Und da hast du es - Live-Updates von deinem Mars Rover!

    .. image:: img/ir_serial.png

#. Um unser System auf die Probe zu stellen, winke mit einem „Weltraumfelsen“ (deiner Hand) vor einem der Sensoren. Du wirst sehen, wie der Wert auf 0 umschaltet, und die entsprechende LED auf dem Modul leuchtet auf. Das ist der Rover, der sagt: „Achtung, Weltraumfelsen auf meiner rechten Seite!“

    .. code-block::

        Right IR: 0
        Left IR: 1
        Right IR: 0
        Left IR: 1
        Right IR: 0
        Left IR: 1

Bis jetzt bist du nicht nur durch den Weltraum gereist, sondern hast auch Martianisch entschlüsselt! Ich kann es kaum erwarten zu sehen, welche interstellaren Geheimnisse wir in unserer nächsten Mission enthüllen!

**Schritt 4: Anpassen der Erkennungsdistanz**

Wir sind nun bei einem wesentlichen Schritt angelangt: der Anpassung der Erkennungsdistanzen unserer Sensoren an unsere aktuelle Umgebung. Die Werkseinstellungen sind möglicherweise nicht optimal.

Ist die Erkennungsdistanz der beiden Infrarotmodule zu kurz, könnte der Mars Rover mit Hindernissen kollidieren. Ist sie zu weit, könnte der Rover anfangen, sich zu drehen, obwohl er noch weit von einem Hindernis entfernt ist, was seine Bewegung beeinträchtigen könnte.

So kannst du Anpassungen vornehmen:


#. Beginne mit der Anpassung des rechten Hindernisvermeidungsmoduls. Während des Transports können Stöße dazu führen, dass Sender und Empfänger auf dem Infrarotmodul kippen. Daher musst du sie manuell gerade richten.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust1.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

#. Platziere ein Hindernis etwa 20 cm direkt vor dem rechten Modul. Die Box, in der unser Rover-Kit kam, ist eine gute Wahl dafür! Drehe nun das Potentiometer am Modul, bis die Anzeigeleuchte am Modul gerade aufleuchtet. Bewege dann das Hindernis hin und her, um zu überprüfen, ob die Anzeigeleuchte in der gewünschten Entfernung aufleuchtet. Leuchtet das Licht nicht in der richtigen Entfernung auf oder bleibt es ohne auszugehen an, musst du das andere Potentiometer einstellen.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust2.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>


#. Wiederhole den gleichen Prozess für das andere Modul.

Jetzt, da unsere Sensoren vollständig vorbereitet sind, lasst uns die nächste Reise beginnen!

**Schritt 5: Entwurf eines automatischen Hindernisvermeidungssystems**

Nun machen wir einen großen Sprung in unserer Weltraumforschung und nutzen diese Nachrichten vom Rover.
Wir werden ein automatisches Hindernisvermeidungssystem erstellen!

Hier ist unser Plan: Wenn der rechte Sensor ein Hindernis erkennt, wird der Rover nach hinten rechts abbiegen. Wenn der linke Sensor ein Hindernis erkennt, wird der Rover nach hinten links abbiegen. Wenn beide Sensoren ein Hindernis erkennen, wird der Rover rückwärts fahren. Werden keine Hindernisse erkannt, fährt der Rover geradeaus weiter.

Visualisieren wir dies in einem Flussdiagramm, um es noch klarer zu machen. Flussdiagramme sind eine großartige Möglichkeit, einen Plan logisch zu skizzieren, besonders wenn es um Programmierung geht!

.. image:: img/ir_flowchart.png

Lassen Sie uns diesen Plan unserem Rover in seiner Sprache (Arduino-Code) zuflüstern:

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/af6539d4-7b4b-4e74-a04a-9fa069391d4d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

In diesem Code verwenden wir die ``if...else``-Anweisung in der Funktion ``loop()``.

    Die ``if...else``-Anweisung wird verwendet, um einen Block von Code unter zwei Alternativen auszuführen. 
    Wenn wir jedoch unter mehr als zwei Alternativen wählen müssen, verwenden wir die ``if...else if...else``-Anweisung.

    Die Syntax der ``if...else if...else``-Anweisung lautet:


    .. code-block:: arduino

        if (condition1) {
        // code block 1
        }
        else if (condition2){
        // code block 2
        }
        else if (condition3){
        // code block 3
        }
        else {
        // code block 4
        }
    
    Hier,

    * Wenn Bedingung1 wahr ist, wird Codeblock 1 ausgeführt.
    * Wenn Bedingung1 falsch ist, wird Bedingung2 ausgewertet.
    * Wenn Bedingung2 wahr ist, wird Codeblock 2 ausgeführt.
    * Wenn Bedingung2 falsch ist, wird Bedingung3 ausgewertet.
    * Wenn Bedingung3 wahr ist, wird Codeblock 3 ausgeführt.
    * Wenn Bedingung3 falsch ist, wird Codeblock 4 ausgeführt.

Nun, da wir unser automatisches Hindernisvermeidungssystem entworfen haben, kommt der spannende Teil - wir setzen es auf die Probe!

* Beobachten Sie, ob sich der Rover so bewegt, wie Sie es erwartet haben.
* Oder setzen Sie ihn verschiedenen Lichtverhältnissen aus, um zu sehen, wie sich seine Bewegungen ändern.

Indem wir Wissenschaft in unser Ingenieurprojekt integrieren, werden wir zu Weltraumdetektiven, die die Geheimnisse des Verhaltens unseres Rovers lösen.
Es geht nicht nur darum, Fehler zu korrigieren, sondern die Leistung zu optimieren, um unseren Rover bestmöglich zu machen! Macht weiter so, Weltraumdetektive!

**Schritt 6: Reflexion und Zusammenfassung**

In der Testphase haben Sie vielleicht ein interessantes Verhalten unseres Mars-Rovers bemerkt: Während er geschickt Hindernissen zu seiner Linken und Rechten ausweicht, könnte er Schwierigkeiten haben, kleinere Hindernisse direkt vor ihm zu erkennen.

Wie können wir diese Herausforderung meistern?

Bleiben Sie dran für die nächste Lektion, in der wir unsere Entdeckungsreise in die faszinierende Welt der Programmierung, Sensoren und Hinderniserkennung fortsetzen.

Denken Sie daran, jede Herausforderung ist eine Gelegenheit zum Lernen und zur Innovation. Und während wir unsere Weltraumforschungsreise fortsetzen, gibt es noch so viel mehr zu entdecken und zu lernen!
