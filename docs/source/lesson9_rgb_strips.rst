Lektion 9: Den Weg mit RGB-LED-Streifen beleuchten
============================================================

Auf unserer bisherigen Reise haben wir unseren Mars-Rover in einen intelligenten Entdecker verwandelt, der geschickt um Hindernisse manövriert. Er ist mittlerweile recht geschickt darin, sich auf den Mars-ähnlichen Geländen, die wir für ihn vorbereitet haben, zurechtzufinden.

Aber, was wäre, wenn wir seinem praktischen Nutzen ein wenig Flair hinzufügen könnten? Lassen Sie uns unserem Rover die Fähigkeit geben, sich durch ein Spektakel aus Farben und Licht auszudrücken. Wir sprechen davon, RGB-LED-Streifen zu integrieren - ein cooles Feature, das es unserem Rover ermöglichen würde, seinen Weg zu erhellen, selbst unter dunkelsten Bedingungen.

Stellen Sie sich das vor - der Rover hinterlässt eine Spur aus farbcodierten Signalen, die es uns erleichtert, seine Bewegungen zu verstehen. Ein grünes Leuchten, wenn er unterwegs ist, ein strenges Rot, wenn er hält, oder ein auffälliges Gelb bei diesen schnellen Wendungen. Er könnte sogar nur zum Spaß in einem Farbenmeer aufleuchten!

Unser Ziel in dieser Lektion ist es, die Prinzipien von RGB-LED-Streifen zu verstehen, zu lernen, wie man ihre Farbe und Helligkeit steuert und dies dann mit den Bewegungen des Rovers zu synchronisieren. Am Ende wird unser Mars-Rover mehr als eine Maschine sein. Er wird eine leuchtende, farbwechselnde Entität sein, die den Weg in der weiten Marslandschaft weist!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/car_rgb.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>

.. note::

    Wenn Sie diesen Kurs nach der vollständigen Montage des GalaxyRVR absolvieren, müssen Sie diesen Schalter nach rechts bewegen, bevor Sie den Code hochladen.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Kursziele
-------------

* Verstehen der Arbeitsprinzipien und Anwendungen von RGB-LED-Streifen.
* Lernen, wie man Arduino-Programmierung verwendet, um die Farbe und Helligkeit von RGB-LED-Streifen zu steuern.
* Übung im Installieren und Verwenden von RGB-LED-Streifen am Mars-Rover-Modell als Anzeiger.

Kursmaterialien
-------------------------

* RGB-LED-Streifen (jeder Streifen hat 8 RGB-LEDs, insgesamt zwei Streifen)
* Grundwerkzeuge und Zubehör (z. B. Schraubendreher, Schrauben, Kabel usw.)
* Mars-Rover-Modell (ausgestattet mit Schaukel-Bogie-System, Hauptplatinen, Motoren, Hindernisvermeidungsmodul, Ultraschallmodul)
* USB-Kabel
* Arduino IDE
* Computer

Kursschritte
------------------
**Schritt 1: Installieren der RGB-LED-Streifen am Mars-Rover**

Fixieren Sie nun die beiden RGB-Lichtstreifen an den unteren Seiten des Wagens. Sie werden von einem einzigen Satz Pins gesteuert, daher ist während des Verdrahtungsprozesses keine Unterscheidung notwendig.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/v4YGjNwPOJE" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Schritt 2: Erforschen Sie die Magie des Lichts mit RGB-LED-Streifen**

Erinnern Sie sich an das letzte Mal, als Sie einen Regenbogen gesehen haben? Wie er den Himmel mit sieben lebendigen Farben bunt gemacht hat? Wie wäre es, wenn Sie hier bei unserem kleinen Mars-Rover Ihren eigenen Regenbogen kreieren könnten? Lassen Sie uns in die Magie des Lichts mit RGB-LED-Streifen eintauchen!

.. image:: img/4_rgb_strip.jpg

Sie werden bemerken, dass unser RGB-LED-Streifen vier Pins wie folgt beschriftet hat:

* **+5V**: Dies ist das gemeinsame „positive“ Ende oder die „Anode“ der drei kleinen Glühbirnen (LEDs) in unserem Streifen. Es muss mit DC 5V verbunden werden, einer Art elektrischem Saft, der unsere winzigen Glühbirnen antreibt!
* **B**: Dies ist das „negative“ Ende oder die „Kathode“ der blauen LED.
* **R**: Dies ist die „Kathode“ der roten LED.
* **G**: Dies ist die „Kathode“ der grünen LED.

.. image:: img/rgb_5050.jpg

Erinnern Sie sich an die drei Grundfarben - Rot, Blau und Grün - die wir im Kunstunterricht gelernt haben? Genau wie ein Künstler diese Farben auf seiner Palette mischt, um neue Schattierungen zu kreieren, enthält unser Streifen 4 „5050“ LEDs, die diese Grundfarben mischen können, um praktisch jede Farbe zu erzeugen! Jede „5050“ LED ist wie ein winziges Kunststudio, das diese drei farbigen Glühbirnen beherbergt.

.. image:: img/rgb_5050_sche.png

Diese winzigen Kunststudios sind dann auf einer flexiblen Platine clever verbunden - quasi wie eine Mini-Elektroautobahn! Die „positiven“ Enden aller LEDs (Anoden) sind miteinander verbunden, während die „negativen“ Enden (Kathoden) mit ihren entsprechenden Farbspuren verbunden sind (G zu G, R zu R, B zu B).

.. image:: img/rgb_strip_sche.png

Und das coolste daran? Auf unseren Befehl hin können alle LEDs auf diesem Streifen gleichzeitig ihre Farben ändern! Es ist, als hätten wir unser eigenes Lichtorchester an der Spitze unserer Finger!

Also bereiten wir uns darauf vor, etwas Lichtmusik zu spielen! Im nächsten Schritt lernen wir, wie wir diese LEDs steuern können, um die gewünschten Farben anzuzeigen. Es wird sein, als würden wir eine Symphonie des Lichts dirigieren!


**Schritt 3: Die Show erleuchten - Programmierung zur Steuerung der RGB-LED-Streifen**

Wir sind in das Reich der Farben eingetreten, es ist Zeit, unseren Mars-Rover zum Leben zu erwecken. Machen Sie sich bereit, die Dunkelheit mit einem Farbspektrum zu bemalen, das mit RGB-LED-Streifen erzeugt wird. Denken Sie daran, dies als Chance zu sehen, Ihren Mars-Rover in eine mobile Diskoparty zu verwandeln!

* Bevor wir in den spaßigen Teil eintauchen, sollten wir verstehen, dass wir zwar zwei LED-Streifen haben, diese jedoch beide von denselben Pins gesteuert werden. Denken Sie daran, als hätten Sie zwei umwerfende Tänzer, die sich in perfekter Synchronisation bewegen!

    .. image:: img/rgb_shield.png

* Jetzt ist es an der Zeit, unsere Programmiermagie zu beschwören. Wir werden unsere Pins mit dem Arduino-Code initialisieren.

    .. code-block:: arduino

        #include <SoftPWM.h>

         // Define the pin numbers for the RGB strips
        const int bluePin = 11;
        const int redPin = 12;
        const int greenPin = 13;

* Mit unseren Pins an ihrem Platz werden wir jetzt die Funktion ``SoftPWMSet()`` verwenden, um diese Pins zu steuern. Um den RGB-Streifen rot anzeigen zu lassen, schalten wir die rote LED ein und die anderen aus.

    .. code-block:: arduino

        void setup() {
            // Initialize software-based PWM on all pins
            SoftPWMBegin();
        }

        void loop() {
            // Set the color to red by turning the red LED on and the others off
            SoftPWMSet(redPin, 255); // 255 is the maximum brightness
            SoftPWMSet(greenPin, 0); // 0 is off
            SoftPWMSet(bluePin, 0);  // 0 is off
            delay(1000); // Wait for 1 second
        }

Im obigen Code haben wir nur demonstriert, wie man eine einzelne Farbe anzeigt.

Wenn wir eine Vielzahl von Farben mit dieser Methode präsentieren würden, könnte der Code recht umständlich werden. Daher, um unseren Code prägnanter und wartbarer zu machen, können wir eine Funktion erstellen, um PWM-Werte den drei Pins zuzuweisen. Dann können wir innerhalb der ``loop()``-Funktion ganz einfach eine Vielzahl von Farben einstellen.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cac90501-04c1-44c2-a1d7-4f863e50f186/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Nachdem Sie den Code auf Ihr R3-Board hochgeladen haben, stellen Sie möglicherweise fest, dass die Farben Orange und Gelb etwas abweichen. 
Dies liegt daran, dass die rote LED auf dem Streifen im Vergleich zu den anderen beiden LEDs relativ schwach leuchtet. 
Daher müssen Sie in Ihrem Code Offset-Werte einführen, um diese Farbabweichung zu korrigieren.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/60ec867f-5637-44bd-b72d-4709fc4f5349/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Nun sollte der RGB-LED-Streifen die richtigen Farben anzeigen können. Wenn Sie immer noch Abweichungen bemerken, können Sie die Werte von ``R_OFFSET``, ``G_OFFSET`` und ``B_OFFSET`` manuell anpassen.

Fühlen Sie sich frei zu experimentieren und jede beliebige Farbe Ihrer Wahl auf dem LED-Streifen anzuzeigen. Alles, was Sie tun müssen, ist, die RGB-Werte für die gewünschte Farbe einzugeben.

Hier ein Tipp: Sie können das Malprogramm auf Ihrem Computer verwenden, um die RGB-Werte Ihrer gewünschten Farbe zu ermitteln.

.. image:: img/rgb_paint.png

Jetzt, wo wir die Kunst des Farbsettings gemeistert haben, werden wir im nächsten Schritt diese schillernden Displays mit den Bewegungen des Mars-Rovers integrieren. Aufregende Zeiten stehen bevor!

**Schritt 4: Bewegung des Rovers mit Farbanzeige**

Nun werden wir Farbanzeigen zu den Bewegungen des Mars-Rovers hinzufügen. Beispielsweise können wir Grün für Vorwärtsbewegungen, Rot für Rückwärtsbewegungen und Gelb für das Abbiegen nach links oder rechts verwenden.

Um dies zu tun, werden wir einen Steuermechanismus in unserem Code hinzufügen, der die Farbe des LED-Streifens basierend auf der Bewegung des Rovers einstellt. Dies wird beinhalten, unseren Rover-Steuerungscode zu modifizieren, um unsere Farbsteuerungsfunktionen einzubeziehen.

Lassen Sie uns ein Beispiel sehen, wie wir das machen können:

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/5412eebe-75b8-4f98-a348-f0889e8a7fde/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Innerhalb der ``loop()``-Funktion haben wir den Rover beauftragt, eine Reihe von Aktionen durchzuführen, indem wir verschiedene Funktionen aufrufen. 
Jede Aktion hatte ihre entsprechende Farbanzeige - Grün für Vorwärtsbewegungen, Rot für Rückwärtsbewegungen und Gelb für das Abbiegen. 
Diese Farbanzeigefunktion wurde mit der Funktion ``setColor()`` zum Leben erweckt, welche die Helligkeit 
jedes RGB-Farbkanals steuerte.

Für die Stop-Aktion haben wir ein fesselndes Element eingeführt - einen Atmungseffekt mit rotem und blauem Licht. 
Dies wurde erreicht, indem die Helligkeit der roten und blauen Kanäle in der Funktion ``stopMove()`` zyklisch angepasst wurde. 
So wechselte der LED-Streifen beim Anhalten die Farben zwischen Rot und Blau und schuf einen dynamischen visuellen Effekt.

Nun besitzt unser Mars-Rover seine eigenen lebhaften Farbeffekte und hinterlässt eine Spur aus farbcodierten Signalen, von denen jedes 
eine einzigartige Bewegung darstellt. 

Durch dieses Projekt haben wir entdeckt, wie STEAM-Fächer verschmelzen können, um einem 
ansonsten gewöhnlichen Gerät Leben einzuhauchen, und es in ein lebendiges, interaktives und unterhaltsames Lernwerkzeug zu verwandeln.


**Schritt 5: Zusammenfassung und Reflexion**

In der heutigen Lektion haben wir uns in die Welt der RGB-LED-Streifen vertieft und erforscht, wie man sie manipuliert, um eine lebendige Palette von Farben anzuzeigen. Diese brillanten Farbtöne hauchten unserem Mars-Rover neues Leben ein und verwandelten ihn von einer bloßen Maschine in ein lebendiges Spektakel.

Nun lade ich Sie ein, nachzudenken - Wenn Sie am Steuer säßen, wie würden Sie diese Farben nutzen, um Ihren Mars-Rover zu verbessern? Welche einzigartigen Effekte möchten Sie, dass er zeigt?

Darüber hinaus hoffe ich, dass Sie durch den Prozess ein praktisches Verständnis dafür gewonnen haben, wie verschiedene STEAM-Konzepte in einem ansprechenden Projekt verwoben werden können, und Ihnen eine breitere Perspektive ihrer praktischen Anwendungen bieten. 

Wir sehen uns in unserem nächsten spannenden Abenteuer!
