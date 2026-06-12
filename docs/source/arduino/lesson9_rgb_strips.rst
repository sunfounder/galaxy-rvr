.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Lektion 9: Den Weg mit RGB-LED-Streifen beleuchten
============================================================

Auf unserer bisherigen Reise haben wir unseren Mars Rover in einen intelligenten Entdecker verwandelt, der geschickt um Hindernisse herummanövrieren kann. Er ist ziemlich geschickt darin geworden, die marsähnlichen Gelände zu durchqueren, die wir für ihn aufgebaut haben.

Aber was wäre, wenn wir seiner Praktikabilität ein wenig Flair verleihen könnten? Geben wir unserem Rover die Fähigkeit, sich durch ein Spektakel aus Farben und Licht auszudrücken. Wir sprechen hier von der Integration von RGB-LED-Streifen - eine coole Funktion, die es unserem Rover ermöglichen würde, selbst bei dunkelsten Bedingungen seinen Weg zu beleuchten.

Stellen Sie sich Folgendes vor: Der Rover hinterlässt eine Spur von farbcodierten Signalen, die es uns erleichtern, seine Bewegungen zu verstehen. Ein grünes Leuchten, wenn er unterwegs ist, ein strenges Rot, wenn er anhält, oder ein auffälliges Gelb bei schnellen Kurven. Er könnte sogar in einer Vielzahl von Farben leuchten, einfach nur zum Spaß!

Unser Ziel in dieser Lektion ist es, die Prinzipien von RGB-LED-Streifen zu verstehen, zu lernen, ihre Farbe und Helligkeit zu steuern, und dies dann mit den Bewegungen des Rovers zu synchronisieren. Am Ende wird unser Mars Rover mehr als nur eine Maschine sein. Er wird ein leuchtendes, farbwechselndes Wesen sein, das den Weg in der weiten Marslandschaft weist!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/car_rgb.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>

.. note::

    Wenn Sie diesen Kurs nach der vollständigen Montage des GalaxyRVR lernen, müssen Sie diesen Schalter vor dem Hochladen des Codes nach rechts stellen.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Zielsetzung
-------------

* Die Arbeitsprinzipien und Anwendungen von RGB-LED-Streifen verstehen.
* Lernen, wie man mit Arduino-Programmierung die Farbe und Helligkeit von RGB-LED-Streifen steuert.
* Üben der Installation und Verwendung von RGB-LED-Streifen am Mars Rover-Modell als Anzeigen.

Benötigte Materialien
-------------------------

* RGB-LED-Streifen (jeder Streifen hat 8 RGB-LEDs, insgesamt zwei Streifen)
* Grundlegende Werkzeuge und Zubehörteile (z. B. Schraubendreher, Schrauben, Kabel usw.)
* Mars Rover-Modell (ausgestattet mit Rocker-Bogie-System, Hauptplatinen, Motoren, Hindernisvermeidungsmodul, Ultraschallmodul)
* USB-Kabel
* Arduino IDE
* Computer

Kursschritte
------------------
**Schritt 1: Installieren Sie die RGB-LED-Streifen am Mars Rover**

Befestigen Sie nun die beiden RGB-Lichtstreifen an den unteren Seiten des Fahrzeugs. Sie werden über einen einzigen Pinsatz gesteuert, daher ist keine Unterscheidung beim Verdrahtungsprozess erforderlich.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/v4YGjNwPOJE" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Schritt 2: Erkunden Sie die Magie des Lichts mit RGB-LED-Streifen**

Erinnern Sie sich an das letzte Mal, als Sie einen Regenbogen gesehen haben? Wie er den Himmel mit sieben lebhaften Farben bunt gemacht hat? Wie würden Sie es finden, Ihren eigenen Regenbogen zu erschaffen, direkt hier in unserem kleinen Marsrover? Tauchen wir ein in die Magie des Lichts mit RGB-LED-Streifen!

.. image:: img/4_rgb_strip.jpg

Ihnen ist vielleicht aufgefallen, dass unser RGB-LED-Streifen vier Pins mit den folgenden Bezeichnungen hat:

* **+5V**: Dies ist das gemeinsame "positive" Ende oder die "Anode" der drei kleinen Glühbirnen (LEDs) in unserem Streifen. Es muss an DC 5V angeschlossen werden, eine Art elektrischer Saft, der unsere winzigen Birnen mit Strom versorgt!
* **B**: Dies ist das "negative" Ende oder die "Kathode" der blauen LED.
* **R**: Dies ist die "Kathode" der roten LED.
* **G**: Dies ist die "Kathode" der grünen LED.

.. image:: img/rgb_5050.jpg

Erinnern Sie sich an die drei Grundfarben - Rot, Blau und Grün -, die wir im Kunstunterricht gelernt haben? So wie ein Künstler diese Farben auf seiner Palette mischt, um neue Schattierungen zu erzeugen, enthält unser Streifen 4 "5050"-LEDs, die diese Grundfarben mischen können, um praktisch jede Farbe zu erzeugen! Jede "5050"-LED ist wie ein winziges Kunststudio, das diese drei farbigen Birnen beherbergt.

.. image:: img/rgb_5050_sche.png

Diese winzigen Kunststudios werden dann auf intelligente Weise auf einer flexiblen Leiterplatte verbunden - so etwas wie eine Mini-Elektroautobahn! Die "positiven" Enden aller LEDs (Anoden) sind miteinander verbunden, während die "negativen" Enden (Kathoden) mit ihren entsprechenden Farbspuren verbunden sind (G zu G, R zu R, B zu B).

.. image:: img/rgb_strip_sche.png

Und das Coolste daran? Mit unserem Befehl können alle LEDs auf diesem Streifen gleichzeitig ihre Farbe ändern! Es ist, als hätten wir unser eigenes Lichtorchester direkt an unseren Fingerspitzen!

Machen wir uns also bereit, etwas Lichtmusik zu spielen! Im nächsten Schritt lernen wir, wie wir diese LEDs steuern, um die gewünschten Farben anzuzeigen. Es wird sein wie das Dirigieren einer Sinfonie aus Licht!


**Schritt 3: Die Show zum Leuchten bringen - Codierung zur Steuerung der RGB-LED-Streifen**

Wir sind in das Reich der Farben eingetreten, es ist Zeit, unseren Mars Rover zum Leben zu erwecken. Machen Sie sich bereit, die Dunkelheit mit einem Spektrum von Farben zu bemalen, indem Sie RGB-LED-Streifen verwenden. Betrachten Sie dies als eine Gelegenheit, Ihren Mars Rover in eine mobile Disco-Party zu verwandeln!

* Bevor wir in den unterhaltsamen Teil eintauchen, sollten wir verstehen, dass beide LED-Streifen, obwohl wir zwei haben, über denselben Pinsatz gesteuert werden. Stellen Sie es sich wie zwei blendende Tänzer vor, die sich in perfekter Synchronisation bewegen!

    .. image:: img/rgb_shield.png

* Es ist Zeit, unsere Codierungsmagie zu beschwören. Wir werden unsere Pins mit dem Arduino-Code initialisieren.

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Definieren Sie die Pinnummern für die RGB-Streifen
        const int bluePin = 11;
        const int redPin = 12;
        const int greenPin = 13;

* Nachdem unsere Pins eingerichtet sind, verwenden wir nun die Funktion ``SoftPWMSet()``, um diese Pins zu steuern. Um den RGB-Streifen rot leuchten zu lassen, schalten wir die rote LED ein und die anderen aus.

    .. code-block:: arduino

        void setup() {
            // Initialisiert softwarebasiertes PWM auf allen Pins
            SoftPWMBegin();
        }

        void loop() {
            // Setzt die Farbe auf Rot, indem die rote LED eingeschaltet und die anderen ausgeschaltet werden
            SoftPWMSet(redPin, 255); // 255 ist die maximale Helligkeit
            SoftPWMSet(greenPin, 0); // 0 ist aus
            SoftPWMSet(bluePin, 0);  // 0 ist aus
            delay(1000); // Warte 1 Sekunde
        }

Im obigen Code haben wir nur gezeigt, wie eine einzelne Farbe angezeigt wird.

Wenn wir mit dieser Methode eine Vielzahl von Farben zeigen wollten, könnte der Code recht umständlich werden. Um unseren Code daher prägnanter und wartbarer zu machen, können wir eine Funktion erstellen, die PWM-Werte an die drei Pins zuweist. Dann können wir innerhalb der ``loop()`` problemlos eine Vielzahl von Farben einstellen.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cac90501-04c1-44c2-a1d7-4f863e50f186/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Nach dem Hochladen des Codes auf Ihr R3-Board stellen Sie möglicherweise fest, dass die Farben Orange und Gelb etwas daneben liegen.
Dies liegt daran, dass die rote LED auf dem Streifen im Vergleich zu den anderen beiden LEDs relativ dunkel ist.
Daher müssen Sie im Code Offset-Werte einführen, um diese Farbabweichung zu korrigieren.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/60ec867f-5637-44bd-b72d-4709fc4f5349/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Nun sollte der RGB-LED-Streifen in der Lage sein, die korrekten Farben anzuzeigen. Wenn Sie immer noch Abweichungen feststellen, können Sie die Werte von ``R_OFFSET``, ``G_OFFSET`` und ``B_OFFSET`` manuell anpassen.

Experimentieren Sie nach Herzenslust und zeigen Sie jede beliebige Farbe Ihrer Wahl auf dem LED-Streifen an. Sie müssen nur die RGB-Werte für die gewünschte Farbe eintragen.

Hier ist ein Tipp: Sie können das Paint-Tool auf Ihrem Computer verwenden, um die RGB-Werte Ihrer gewünschten Farbe zu ermitteln.

.. image:: img/rgb_paint.png

Nachdem wir nun die Kunst der Farbeinstellung gemeistert haben, werden wir im nächsten Schritt diese brillanten Displays mit den Bewegungen des Mars Rovers integrieren. Aufregende Zeiten stehen bevor!

**Schritt 4: Den Rover mit Farbanzeige bewegen**

Nun werden wir den Bewegungen des Mars Rovers Farbanzeigen hinzufügen. Beispielsweise können wir Grün für Vorwärtsfahrt, Rot für Rückwärtsfahrt und Gelb für Links- oder Rechtsabbiegen verwenden.

Dazu fügen wir in unserem Code einen Steuerungsmechanismus hinzu, der die Farbe des LED-Streifens basierend auf der Bewegung des Rovers einstellt. Dies beinhaltet die Modifikation unseres Rover-Steuercodes, um unsere Farbsteuerungsfunktionen zu integrieren.

Sehen wir uns ein Beispiel an, wie wir dies tun können:

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/5412eebe-75b8-4f98-a348-f0889e8a7fde/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Innerhalb der Funktion ``loop()`` haben wir dem Rover befohlen, eine Reihe von Aktionen durch Aufruf verschiedener Funktionen auszuführen.
Jede Aktion hatte ihre entsprechende Farbanzeige - Grün für Vorwärtsfahrt, Rot für Rückwärtsfahrt und Gelb für Drehungen.
Diese Farbanzeigefunktion wurde mithilfe der Funktion ``setColor()`` realisiert, die die Helligkeit jedes
RGB-Farbkanals manipulierte.

Für die Stopp-Aktion haben wir ein fesselndes Element eingeführt - einen Atemeffekt mit rotem und blauem Licht.
Dies wurde erreicht, indem die Helligkeit der roten und blauen Kanäle innerhalb der Funktion ``stopMove()`` zyklisch angepasst wurde.
Beim Anhalten wechselte der LED-Streifen somit zwischen rot und blau und erzeugte einen dynamischen visuellen Effekt.

Unser Mars Rover besitzt nun seine eigenen lebendigen Farbeffekte und hinterlässt eine Spur von farbcodierten Signalen, die jeweils eine
einzigartige Bewegung darstellen.

Durch dieses Projekt haben wir entdeckt, wie STEAM-Fächer miteinander verschmelzen können, um eine ansonsten
gewöhnliche Maschine zu beleben und in ein lebendiges, interaktives und unterhaltsames Lernwerkzeug zu verwandeln.


**Schritt 5: Zusammenfassung und Reflexion**

In der heutigen Lektion haben wir in die Welt der RGB-LED-Streifen eingetaucht und erforscht, wie man sie manipulieren kann, um eine lebendige Farbpalette anzuzeigen. Diese brillanten Farbtöne haben unseren Mars Rover mit neuem Leben erfüllt und ihn von einer bloßen Maschine in ein lebendiges Spektakel verwandelt.

Nun lade ich Sie zum Nachdenken ein - Wenn Sie am Steuer sitzen würden, wie würden Sie diese Farben nutzen, um Ihren Mars Rover zu verbessern? Welche einzigartigen Effekte sollte er Ihrer Meinung nach zeigen?

Darüber hinaus hoffe ich, dass Sie durch diesen Prozess ein praktisches Verständnis dafür gewonnen haben, wie verschiedene STEAM-Konzepte in einem ansprechenden Projekt miteinander verwoben werden können, was Ihnen eine breitere Perspektive auf deren praktische Anwendungen bietet.

Bis zu unserem nächsten spannenden Abenteuer!
