.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Lektion 7: Die Rover-Navigation mit dem Ultraschallmodul verbessern
===============================================================================

In unserem letzten Abenteuer haben wir unseren Mars Rover mit „Augen" an den Seiten ausgestattet und ein einfaches Hindernisvermeidungssystem geschaffen. Doch es gibt einen toten Winkel direkt vorne – eine Herausforderung, die wir bereit sind zu meistern!

Heute, in dieser Lektion, werden wir unserem Rover einen neuen „Sehsinn" verleihen. Wir installieren ein Ultraschallsensormodul, das als eine Art zentrales Auge fungiert und unserem Rover hilft, Hindernisse direkt vor ihm zu erkennen.

Wir werden uns mit der faszinierenden Mechanik von Ultraschallwellen befassen und erkunden, wie sie die Fähigkeit unseres Rovers verbessern, komplexes Gelände zu navigieren. Mit dieser Ergänzung wird unser Mars Rover wahrnehmungsfähiger und wendiger sein, bereit für anspruchsvollere Erkundungsmissionen.

Begleiten Sie uns auf diesem weiteren Schritt in dieser aufregenden MINT-Reise, die unseren Mars Rover noch geschickter darin macht, unerforschte Gebiete zu erkunden!


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/ultrasonic_avoid.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. note::

    Wenn Sie diesen Kurs nach vollständiger Montage des GalaxyRVR lernen, müssen Sie diesen Schalter vor dem Hochladen des Codes nach rechts bewegen.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center


Kursziele
---------------------------

* Das Prinzip der Ultraschall-Distanzmessung verstehen.
* Lernen, wie man mit Arduino und dem Ultraschallmodul Distanzen misst.
* Üben, das Ultraschallmodul zur Hindernisvermeidung am Mars-Rover-Modell einzusetzen.

Benötigte Materialien
--------------------------

* Ultraschallmodul
* Grundlegende Werkzeuge und Zubehör (z. B. Schraubendreher, Schrauben, Kabel usw.)
* Mars-Rover-Modell (ausgestattet mit Rocker-Bogie-System, Hauptplatinen, Motoren, Hindernisvermeidungsmodul)
* USB-Kabel
* Arduino IDE
* Computer

Kursschritte
-----------------------
**Schritt 1: Das Ultraschallsensormodul montieren**

Nachdem wir uns nun vorgenommen haben, unseren Mars Rover mit einem leistungsstarken neuen „Sehsinn" auszustatten, ist es an der Zeit, das Ultraschallsensormodul zusammenzubauen.

.. raw:: html

  <iframe width="600" height="400" src="https://www.youtube.com/embed/c_xWAVapGic?si=ovuxheXdGVpHopPa" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Und da haben wir es! Unser Mars Rover hat nun ein vollständig montiertes Ultraschallsensormodul, bereit, ihm bei der Navigation zu helfen wie nie zuvor. Sind Sie gespannt, wie es die Hinderniserkennungsfähigkeiten unseres Rovers verändert? Tauchen wir direkt ein!


**Schritt 2: Das Ultraschallmodul erkunden**

Lernen wir den HC-SR04 kennen, einen leistungsstarken Ultraschall-Distanzsensor. Dieses winzige Gerät kann Distanzen von 2 cm bis zu 400 cm genau messen, ganz ohne Berührung! Erstaunlich, oder? Es ist wie eine Superheldenkraft! Es kann Distanzen allein mithilfe von Schallwellen „sehen", ähnlich wie eine Fledermaus in der Nacht navigiert.

Es verwendet vier Superkräfte, oder besser gesagt vier Pins, um seine Magie zu wirken:

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG (Trigger Pulse Input)** – Es ist der Startknopf für unseren Superhelden. Es sagt unserem Superhelden: „Hey, es ist Zeit, eine Superschallwelle auszusenden!"
* **ECHO (Echo Pulse Output)** – So hört unser Superheld auf das Echo der ausgesendeten Schallwelle.
* **VCC** – Selbst Superhelden brauchen etwas Energie. Wir schließen es an eine 5V-Stromversorgung an.
* **GND** – Es ist der Masseanschluss. Genau wie Superhelden mit der Realität verbunden bleiben müssen!

Stellen Sie sich unseren Superhelden, den HC-SR04 Ultraschallsensor, vor, wie er in den Bergen ein Echo-Spiel spielt.

.. image:: img/ultrasonic_prin.jpg
    :width: 800

* Zuerst sagt das Gehirn unseres Superhelden, der MCU: „Fertig, los!" und sendet ein High-Level-Signal für mindestens 10 Mikrosekunden an unseren Superhelden. Das ist, als ob wir unsere Energie sammeln, bevor wir in ein Tal rufen.
* Auf das Kommando „Los!" ruft unser Superheld 8 Mal sehr schnell laut. Dieser Überschallruf wird mit einer Geschwindigkeit von 40 kHz ausgesendet. Der Superheld startet auch eine Stoppuhr und horcht auf zurückkehrende Rufe.
* Wenn sich ein Hindernis vor ihm befindet, trifft der Ruf darauf und wird als Echo zurückgeworfen. Beim Hören des Echos stoppt unser Superheld die Stoppuhr und notiert die Zeit. Er sendet auch ein High-Level-Signal, um dem MCU mitzuteilen, dass er ein Echo gehört hat.
* Schließlich verwendet unser Superheld eine einfache Formel, um herauszufinden, wie weit das Hindernis entfernt ist. Er nimmt die auf der Stoppuhr aufgezeichnete Zeit, teilt sie durch 2 und multipliziert sie mit der Schallgeschwindigkeit (340 m/s). Das Ergebnis ist die Entfernung zum Hindernis!

So kann unser Superheld-Sensor herausfinden, ob sich ein Hindernis in seinem Weg befindet und wie weit es entfernt ist. Erstaunlich, nicht wahr? Als Nächstes lernen wir, wie wir diese Superheldenkraft in unserem Mars Rover einsetzen können!


**Schritt 3: Unseren Superhelden-Sensor programmieren**

Nachdem wir unseren Superhelden-Sensor montiert und verstanden haben, wie er seine Superkräfte einsetzt, ist es an der Zeit, diese Kräfte in Aktion zu setzen! Lassen Sie uns einen Arduino-Sketch schreiben, der es unserem Ultraschallsensor ermöglicht, Distanzen zu messen und uns diese Messungen anzuzeigen.

Hier sind die wichtigsten Schritte, denen unser Superhelden-Sensor folgen wird:

* Wir haben sowohl den TRIG- als auch den ECHO-Pin mit Pin 10 auf dem GalaxyRVR Shield verbunden. Dadurch können wir sowohl die Signalübertragung als auch den Empfang des Ultraschallmoduls mit einem einzigen Arduino-Pin steuern.

.. image:: img/ultrasonic_shield.png

.. code-block:: arduino

    // Definiert den Pin für das Ultraschallmodul
    #define ULTRASONIC_PIN 10

* **Vorbereitung**: Zu Beginn stellen wir eine serielle Kommunikation mit einer Baudrate von 9600 her, damit wir die Messungen des Superhelden im Serial Monitor sehen können.

.. code-block:: arduino

    void setup() {
        // Startet die serielle Kommunikation
        Serial.begin(9600);
    }

* **Rausschreien!**: Wir setzen den ``ULTRASONIC_PIN`` als ``OUTPUT``-Pin, um einen 10-Mikrosekunden-Puls zu senden. Das ist, als ob wir unserem Ultraschall-Superhelden befehlen, einen kraftvollen Ruf (Ultraschall-Schallwellen) auszusenden!

.. code-block:: arduino

    // Eine Verzögerung von 4ms ist erforderlich, da sonst der Messwert 0 sein kann
    delay(4);

    // Auf OUTPUT setzen, um Signal zu senden
    pinMode(ULTRASONIC_PIN, OUTPUT);

    // Trigger-Pin zurücksetzen
    digitalWrite(ULTRASONIC_PIN, LOW);
    delayMicroseconds(2);

    // Sensor durch Senden eines HIGH-Pulses für 10us auslösen
    digitalWrite(ULTRASONIC_PIN, HIGH);
    delayMicroseconds(10);

    // Trigger-Pin wieder auf LOW setzen
    digitalWrite(ULTRASONIC_PIN, LOW);



* **Warten und Lauschen**: Setzen Sie den ``ULTRASONIC_PIN`` als INPUT. Auf diese Weise ist unser Superhelden-Sensor nun bereit, auf das Echo seines Rufs zu lauschen. Wenn sich ein Hindernis vor ihm befindet, trifft der Ruf darauf und wird als Echo zurückgeworfen. Beim Hören des Echos stoppt unser Superheld die Stoppuhr und notiert die Zeit. Er sendet auch ein High-Level-Signal, um dem MCU mitzuteilen, dass er ein Echo gehört hat.

.. code-block:: arduino

    pinMode(ULTRASONIC_PIN, INPUT);
    float duration = pulseIn(ULTRASONIC_PIN, HIGH);

* **Super-Mathe**: Mit dem zurückgekehrten Echo verwendet unser Sensor die Schallgeschwindigkeit, um die Entfernung zum Objekt zu berechnen. Wir teilen die gesamte Echozeit durch 2, da die Zeit sowohl den Ausruf als auch das Warten auf das Echo umfasst.

.. code-block:: arduino

    float distance = duration * 0.034 / 2;


* **Ergebnisse melden**: Unser Superhelden-Sensor gibt dann das Ergebnis seiner Mission preis, indem er die Entfernung im Serial Monitor für uns sichtbar ausgibt.

.. code-block:: arduino

    // Gibt die Entfernung im Serial Monitor aus
    Serial.print("The distance is: ");
    Serial.print(distance);
    Serial.println(" cm");

* **Ruhe und Bereitschaft**: Jeder Superheld braucht eine Pause, also macht unser Sensor eine kurze Pause vor der nächsten Mission. Dies ermöglicht dem Sensor, sich „zurückzusetzen", bevor wir ihn bitten, eine weitere Messung zu starten.

.. code-block:: arduino

    delay(200);

Hier ist der vollständige Code, der unseren Sensor in einen Superhelden verwandelt:

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/35bddbcf-145c-4e4f-b3ea-21e8210af4a6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Schritt 4: Das Ultraschallmodul programmieren, um den Mars Rover zu steuern**

Nachdem wir unseren Mars Rover nun mit einem Ultraschallsensormodul ausgestattet haben, ist es an der Zeit, ihn so zu programmieren, dass er basierend auf den Messungen des Sensors reagiert.

* Für eine bessere Lesbarkeit haben wir eine Funktion namens ``readSensorData()`` erstellt. Diese Funktion kapselt den gesamten Code, der zum Auslesen der Entfernung vom Ultraschallsensor erforderlich ist.

  .. code-block:: arduino

    float readSensorData() {
        // Eine Verzögerung von 4ms ist erforderlich, da sonst der Messwert 0 sein kann
        delay(4);

        //Auf OUTPUT setzen, um Signal zu senden
        pinMode(ULTRASONIC_PIN, OUTPUT);

        // Trigger-Pin zurücksetzen
        digitalWrite(ULTRASONIC_PIN, LOW);
        delayMicroseconds(2);

        // Sensor durch Senden eines HIGH-Pulses für 10us auslösen
        digitalWrite(ULTRASONIC_PIN, HIGH);
        delayMicroseconds(10);

        // Trigger-Pin wieder auf LOW setzen
        digitalWrite(ULTRASONIC_PIN, LOW);

        //Auf INPUT setzen, um zu lesen
        pinMode(ULTRASONIC_PIN, INPUT);

        // pulseIn gibt die Dauer des Pulses auf dem Pin zurück
        float duration = pulseIn(ULTRASONIC_PIN, HIGH);

        // Berechnet die Entfernung (in cm) basierend auf der Schallgeschwindigkeit (340 m/s oder 0,034 cm/µs)
        float distance = duration * 0.034 / 2;

        return distance;
    }

* In der ``loop()``-Funktion rufen wir ``readSensorData()`` auf und speichern den zurückgegebenen Wert in der Variable ``distance``.

  .. code-block:: arduino

    float distance = readSensorData();

* Abhängig von dieser Entfernung wird der Rover vorwärts fahren, rückwärts fahren oder anhalten.

  .. code-block:: arduino

    // Steuert den Rover basierend auf der Entfernungsmessung
    if (distance > 50) {  // Wenn es sicher ist, vorwärts zu fahren
      moveForward(200);
    } else if (distance < 15) {  // Wenn sich ein Hindernis in der Nähe befindet
      moveBackward(200);
      delay(500);  // Kurz warten, bevor ein Abbiegeversuch unternommen wird
      backLeft(150);
      delay(1000);
    } else {  // Für dazwischenliegende Entfernungen vorsichtig vorwärts fahren
      moveForward(150);
    }

  * Wenn der Weg frei ist (das Hindernis ist mehr als 50 cm entfernt), fährt unser Rover mutig vorwärts.
  * Und wenn sich ein Hindernis nähert (weniger als 50 cm, aber mehr als 15 cm entfernt), fährt unser Rover mit reduzierter Geschwindigkeit vorwärts.
  * Wenn ein Hindernis zu nahe ist (weniger als 15 cm entfernt), fährt der Mars Rover rückwärts und biegt dann nach links ab.

  .. image:: img/ultrasonic_flowchart.png

Unten ist der vollständige Code. Sie können diesen Code auf die R3 Platine hochladen und prüfen, ob der gewünschte Effekt erzielt wird. Sie können die Erkennungsdistanz auch basierend auf der tatsächlichen Umgebung anpassen, um dieses Hindernisvermeidungssystem weiter zu perfektionieren.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cded6408-1469-4289-b79b-7d445b56352b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Durch die Nutzung dieser erweiterten Fähigkeiten wäre der Mars Rover besser in der Lage, potenzielle Hindernisse auf seinem Weg zu identifizieren, Entfernungen genau zu messen und fundierte Entscheidungen zu treffen, um sie zu umfahren. Dies würde die Wahrscheinlichkeit von Kollisionen oder anderen Gefahren, die die Erkundungsmission des Rovers behindern könnten, erheblich verringern.

Mit seinen Supersinnen kann der Mars Rover mit größerem Selbstvertrauen und Effizienz arbeiten, was es ihm ermöglicht, tiefer in die Geheimnisse des Mars einzutauchen und wertvolle wissenschaftliche Daten für die Forscher auf der Erde zu sammeln.

**Schritt 5: Zusammenfassung und Reflexion**

In dieser Lektion haben wir uns mit der Funktionsweise von Ultraschallwellen befasst und gelernt, wie man ihre Rückkehrzeit zum Sensor durch Programmierung in eine messbare Entfernung umwandelt.

Anschließend haben wir Ultraschallwellen genutzt, um ein Hindernisvermeidungssystem zu entwickeln. Dieses spezielle System variiert seine Reaktionen basierend auf der Entfernung zum bevorstehenden Hindernis.

Nun regen wir durch einige Fragen zur Selbstreflexion über diese Lektion an:

* Wie erkennt ein Ultraschallmodul die Entfernung? Können Sie das zugrundeliegende Konzept erläutern?
* Wie unterscheidet sich das Hindernisvermeidungssystem dieser Lektion von dem der vorherigen? Was sind ihre jeweiligen Vor- und Nachteile?
* Ist es möglich, diese beiden Hindernisvermeidungssysteme zu kombinieren?

Das Nachdenken über diese Fragen wird helfen, unser Verständnis zu festigen und uns dazu anregen, über die Anwendung dieser Konzepte auf andere Projekte nachzudenken. Wir freuen uns auf unser nächstes Vorhaben!
