Lektion 7: Verbesserung der Rover-Navigation mit Ultraschallmodul
=====================================================================


In unserem letzten Abenteuer haben wir unseren Mars-Rover mit „Augen“ an seinen Seiten ausgestattet, wodurch wir ein grundlegendes Hindernisvermeidungssystem geschaffen haben. Doch gibt es einen toten Winkel direkt vorne – eine Herausforderung, die wir bereit sind zu meistern!

Heute, in dieser Lektion, werden wir unserem Rover einen neuen Sinn für „Sehen“ geben. Wir installieren ein Ultraschallsensormodul, das als ein Paar zentraler Augen fungiert, um unserem Rover zu helfen, Hindernisse direkt vor ihm zu erkennen.

Wir werden in die faszinierende Mechanik von Ultraschallwellen eintauchen und erforschen, wie sie die Fähigkeit unseres Rovers verbessern, komplexe Gelände zu navigieren. Mit dieser Ergänzung wird unser Mars-Rover wahrnehmungsfähiger und agiler sein, bereit für ambitioniertere Erkundungsmissionen.

Begleiten Sie uns, wenn wir einen Schritt weiter in diese aufregende STEAM-Reise machen, und unseren Mars-Rover noch geschickter bei der Erkundung unbekannter Gebiete machen!


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/ultrasonic_avoid.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. note::

    Wenn Sie diesen Kurs nach der vollständigen Montage des GalaxyRVR durchführen, müssen Sie diesen Schalter vor dem Hochladen des Codes nach rechts bewegen.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center


Kursziele
--------------------------

* Verstehen Sie das Prinzip der Ultraschall-Entfernungsmessung.
* Lernen Sie, wie man Arduino und Ultraschallmodul zur Entfernungsmessung verwendet.
* Üben Sie die Anwendung des Ultraschallmoduls für die Hindernisvermeidung am Mars-Rover-Modell.

Benötigte Materialien
---------------------

* Ultraschallmodul
* Grundwerkzeuge und Zubehör (z. B. Schraubendreher, Schrauben, Kabel usw.)
* Mars-Rover-Modell (ausgestattet mit Schaukel-Bogie-System, Hauptplatinen, Motoren, Hindernisvermeidungsmodul)
* USB-Kabel
* Arduino IDE
* Computer

Kursschritte
--------------------
**Schritt 1: Montieren Sie das Ultraschallsensormodul**

Nun, da wir uns darauf vorbereiten, unseren Mars-Rover mit einem neuen, leistungsstarken „Seh“-Sinn auszustatten, ist es an der Zeit, das Ultraschallsensormodul zusammenzusetzen.

.. raw:: html

  <iframe width="600" height="400" src="https://www.youtube.com/embed/LZasztI96po" title="YouTube-Video-Player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Und da haben wir es! Unser Mars-Rover hat nun ein vollständig montiertes Ultraschallsensormodul, bereit, ihm wie nie zuvor bei der Navigation zu helfen. Sind Sie gespannt, wie es die Hinderniserkennungsfähigkeiten unseres Rovers verändert? Lassen Sie uns direkt eintauchen!


**Schritt 2: Erkundung des Ultraschallmoduls**

Lernen wir den HC-SR04 kennen, einen leistungsstarken Ultraschall-Entfernungssensor. Dieses winzige Gerät kann Entfernungen von 2 cm bis zu 400 cm genau messen, und das alles ohne Berührung! Erstaunlich, nicht wahr? Es ist wie eine Superheldenkraft! Es kann die Entfernungen nur mithilfe von Schallwellen „sehen“, ähnlich wie eine Fledermaus bei Nacht navigiert.

Es verwendet vier Superkräfte oder besser gesagt, vier Pins, um seine Magie zu wirken:

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG (Trigger-Puls-Eingang)** - Es ist der Startknopf für unseren Superhelden. Es sagt unserem Superhelden: "Hey, es ist Zeit, eine supersonische Welle auszusenden!"
* **ECHO (Echo-Puls-Ausgang)** - So hört unser Superheld das Echo der Schallwelle, die er ausgesendet hat.
* **VCC** - Auch Superhelden brauchen Energie. Wir verbinden es mit einer 5V-Stromversorgung.
* **GND** - Es ist die Erdverbindung. So wie Superhelden mit der Realität verbunden bleiben müssen!

Stellen Sie sich unseren Superhelden, den HC-SR04 Ultraschallsensor, vor, wie er in den Bergen ein Echo-Spiel spielt.

.. image:: img/ultrasonic_prin.jpg
    :width: 800

* Zunächst sagt das Gehirn unseres Superhelden, der MCU, „Ready, Set, Go!“, indem es ein Hochpegelsignal für mindestens 10 Mikrosekunden an unseren Superhelden sendet. Das ist so, als würden wir unsere Energie sammeln, bevor wir in ein Tal hineinrufen.
* Auf das „Go!“ hin ruft unser Superheld achtmal sehr schnell laut heraus. Dieser supersonische Ruf wird mit einer Geschwindigkeit von 40 kHz ausgesendet. Der Superheld startet auch eine Stoppuhr und hält Ausschau nach zurückkehrenden Rufen.
* Gibt es ein Hindernis vorne, trifft der Ruf darauf und hallt zurück. Beim Hören des Echos stoppt unser Superheld die Stoppuhr und notiert die Zeit. Er sendet auch ein Hochpegelsignal aus, um dem MCU mitzuteilen, dass er ein Echo gehört hat.
* Zuletzt, um herauszufinden, wie weit das Hindernis entfernt ist, verwendet unser Superheld eine einfache Formel. Er nimmt die auf der Stoppuhr aufgezeichnete Zeit, teilt sie durch 2 und multipliziert sie mit der Schallgeschwindigkeit (340 m/s). Das Ergebnis ist die Entfernung zum Hindernis!

So kann unser Superhelden-Sensor herausfinden, ob ein Hindernis auf seinem Weg ist und wie weit es entfernt ist. Erstaunlich, nicht wahr? Als Nächstes lernen wir, wie wir diese Superheldenkraft in unserem Mars-Rover einsetzen können!


**Schritt 3: Programmierung unseres Superhelden-Sensors**

Nachdem wir unseren Superhelden-Sensor zusammengesetzt und verstanden haben, wie er seine Superkräfte einsetzt, ist es an der Zeit, diese Kräfte in Aktion zu setzen! Lassen wir einen Arduino-Sketch schreiben, der es unserem Ultraschallsensor ermöglicht, Entfernungen zu messen und uns diese Messungen anzuzeigen.

Hier sind die Schlüsselschritte, die unser Superhelden-Sensor befolgen wird:

* Wir haben sowohl den TRIG- als auch den ECHO-Pin an Pin 10 auf dem GalaxyRVR Shield angeschlossen. Dies ermöglicht es uns, sowohl die Signalübertragung als auch den Empfang des Ultraschallmoduls mit einem einzigen Arduino-Pin zu steuern.

.. image:: img/ultrasonic_shield.png

.. code-block:: arduino

    // Define the pin for the ultrasonic module
    #define ULTRASONIC_PIN 10

* **Vorbereitung**: Zuerst beginnen wir die serielle Kommunikation mit einer Baudrate von 9600, damit wir die Messungen unseres Superhelden in unserem Seriellen Monitor sehen können.

.. code-block:: arduino

    void setup() {
        // Start the serial communication
        Serial.begin(9600);
    }

* **Ruf raus!**: Wir setzen den ``ULTRASONIC_PIN`` als ``OUTPUT``-Pin, um einen 10-Mikrosekunden-Impuls zu senden, was so ist, als würden wir unseren Ultraschall-Superhelden befehlen, einen kraftvollen Ruf (Ultraschall-Schallwellen) auszustoßen!

.. code-block:: arduino

    // A 4ms delay is required, otherwise the reading may be 0
    delay(4);

    //Set to OUTPUT to send signal
    pinMode(ULTRASONIC_PIN, OUTPUT);

    // Clear the trigger pin
    digitalWrite(ULTRASONIC_PIN, LOW);
    delayMicroseconds(2);

    // Trigger the sensor by sending a high pulse for 10us
    digitalWrite(ULTRASONIC_PIN, HIGH);
    delayMicroseconds(10);

    // Set the trigger pin back to low
    digitalWrite(ULTRASONIC_PIN, LOW);



* **Warten und Lauschen**: Setzen Sie den ``ULTRASONIC_PIN`` als INPUT. Auf diese Weise ist unser Superhelden-Sensor nun bereit, auf das Echo seines Rufs zu lauschen. Wenn sich ein Hindernis vorne befindet, trifft der Ruf darauf und hallt zurück. Beim Hören des Echos stoppt unser Superheld die Stoppuhr und notiert die Zeit. Er sendet auch ein Hochpegelsignal aus, um dem MCU mitzuteilen, dass er ein Echo gehört hat.

.. code-block:: arduino

    pinMode(ULTRASONIC_PIN, INPUT);
    float duration = pulseIn(ULTRASONIC_PIN, HIGH);

* **Super-Mathematik**: Mit dem zurückgekehrten Echo verwendet unser Sensor die Schallgeschwindigkeit, um die Entfernung zum Objekt zu berechnen. Wir teilen die Gesamt-Echodauer durch 2, da die Zeit sowohl den Ruf als auch das Warten auf das Echo umfasst.

.. code-block:: arduino

    float distance = duration * 0.034 / 2;


* **Ergebnisse melden**: Unser Superhelden-Sensor offenbart dann das Ergebnis seiner Mission und zeigt die Entfernung auf dem Seriellen Monitor an, damit wir sie sehen können.

.. code-block:: arduino

    // Print the distance to the serial monitor
    Serial.print("The distance is: ");
    Serial.print(distance);
    Serial.println(" cm");

* **Ruhe & Bereitschaft**: Jeder Superheld braucht eine Pause, also macht unser Sensor eine kurze Pause vor der nächsten Mission. Dies ermöglicht es dem Sensor, sich "zurückzusetzen", bevor wir ihn bitten, eine weitere Messung zu starten.

.. code-block:: arduino

    delay(200);

Hier ist der vollständige Code, der unseren Sensor in einen Superhelden verwandelt:

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/35bddbcf-145c-4e4f-b3ea-21e8210af4a6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Schritt 4: Programmierung des Ultraschallmoduls zur Steuerung des Mars-Rovers**

Jetzt, da wir unseren Mars-Rover mit einem Ultraschallsensormodul ausgestattet haben, ist es an der Zeit, ihn so zu programmieren, dass er basierend auf den Messungen des Sensors reagiert.

* Zur einfacheren Lesbarkeit haben wir eine Funktion namens ``readSensorData()`` erstellt. Diese Funktion umfasst den gesamten Code, der erforderlich ist, um die Entfernung vom Ultraschallsensor zu lesen.

  .. code-block:: arduino

    float readSensorData() {
        // A 4ms delay is required, otherwise the reading may be 0
        delay(4);
      
        //Set to OUTPUT to send signal
        pinMode(ULTRASONIC_PIN, OUTPUT);
      
        // Clear the trigger pin
        digitalWrite(ULTRASONIC_PIN, LOW);
        delayMicroseconds(2);
      
        // Trigger the sensor by sending a high pulse for 10us
        digitalWrite(ULTRASONIC_PIN, HIGH);
        delayMicroseconds(10);
      
        // Set the trigger pin back to low
        digitalWrite(ULTRASONIC_PIN, LOW);
      
        //Set to INPUT to read
        pinMode(ULTRASONIC_PIN, INPUT);
      
        // pulseIn returns the duration of the pulse on the pin
        float duration = pulseIn(ULTRASONIC_PIN, HIGH);
      
        // Calculate the distance (in cm) based on the speed of sound (340 m/s or 0.034 cm/us)
        float distance = duration * 0.034 / 2;
      
        return distance;
    }

* In der ``loop()``-Funktion rufen wir ``readSensorData()`` auf und speichern den zurückgegebenen Wert in der Variable ``distance``.

  .. code-block:: arduino

    float distance = readSensorData();

* Abhängig von dieser Distanz bewegt sich der Rover vorwärts, rückwärts oder hält an.

  .. code-block:: arduino
  
    // Control rover based on distance reading
    if (distance > 50) {  // If it's safe to move forward
      moveForward(200);
    } else if (distance < 15) {  // If there's an obstacle close
      moveBackward(200);
      delay(500);  // Wait for a while before attempting to turn
      backLeft(150);
      delay(1000);
    } else {  // For distances in between, proceed with caution
      moveForward(150);
    }

  * Wenn der Weg frei ist (das Hindernis mehr als 50 cm entfernt ist), bewegt sich unser Rover mutig vorwärts.
  * Und wenn ein Hindernis näher kommt (weniger als 50 cm, aber mehr als 15 cm entfernt), bewegt sich unser Rover mit geringerer Geschwindigkeit vorwärts.
  * Wenn ein Hindernis zu nah für Komfort ist (weniger als 15 cm entfernt), bewegt sich der Mars-Rover rückwärts und dann nach links.

  .. image:: img/ultrasonic_flowchart.png

Unten finden Sie den kompletten Code. Sie können diesen Code auf das R3-Board hochladen und sehen, ob er den gewünschten Effekt erzielt. Sie können auch die Erkennungsdistanz basierend auf der tatsächlichen Umgebung anpassen, um dieses Hindernisvermeidungssystem zu perfektionieren.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cded6408-1469-4289-b79b-7d445b56352b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Indem wir diese verbesserten Fähigkeiten nutzen, wäre der Mars-Rover besser in der Lage, potenzielle Hindernisse auf seinem Weg zu identifizieren, Distanzen genau zu messen und fundierte Entscheidungen zu treffen, um sie zu umfahren. Dies würde die Wahrscheinlichkeit von Kollisionen oder anderen Gefahren, die die Erkundungsmission des Rovers behindern könnten, erheblich verringern.

Mit seinen Super-Sinnen kann der Mars-Rover mit größerem Vertrauen und Effizienz operieren, was ihm ermöglicht, tiefer in die Geheimnisse des Mars einzudringen und wertvolle wissenschaftliche Daten für die Forscher auf der Erde zu sammeln.

**Schritt 5: Zusammenfassung und Reflexion**

In dieser Lektion haben wir uns mit der Funktionsweise von Ultraschallwellen befasst und wie ihre Rückkehrzeit zum Sensor in messbare Entfernung durch Programmierung übersetzt wird.

Anschließend nutzten wir Ultraschallwellen, um ein Hindernisvermeidungssystem zu entwickeln. Dieses spezielle System variiert seine Reaktionen basierend auf der Entfernung zum bevorstehenden Hindernis.

Nun lassen Sie uns einige Fragen zur Reflexion über diese Lektion stellen:

* Wie erkennt ein Ultraschallmodul Entfernungen? Können Sie das zugrunde liegende Konzept erläutern?
* Wie unterscheidet sich das Hindernisvermeidungssystem dieser Lektion von dem der vorherigen? Was sind ihre jeweiligen Vor- und Nachteile?
* Ist es machbar, diese beiden Hindernisvermeidungssysteme zu kombinieren?

Sich mit diesen Fragen auseinanderzusetzen wird helfen, unser Verständnis zu festigen und uns dazu anregen, über die Anwendung dieser Konzepte auf andere Projekte nachzudenken. Ich freue mich auf unser nächstes Abenteuer!
