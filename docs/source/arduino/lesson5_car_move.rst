.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Lektion 5: Die Mobilität des Mars Rovers entfesseln
=============================================================

Machen Sie sich bereit, junge Entdecker! Wir haben die Motorsteuerung gemeistert, jetzt setzen wir diese Fähigkeiten auf dem Roten Planeten ein. In dieser Lektion erwecken wir den Mars Rover zum Leben!

Wir lernen, wie man die Motoren in das Rocker-Bogie-Federungssystem einbaut und dann mit unseren Programmierkenntnissen unseren Rover über imaginäre Marslandschaften steuert.

Es ist ein Mars-Abenteuer in unserem Klassenzimmer. Legen wir los!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. note::

    Wenn Sie diesen Kurs nach vollständiger Montage des GalaxyRVR lernen, müssen Sie diesen Schalter vor dem Hochladen des Codes nach rechts bewegen.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Lernziele
-------------------------------

* Verstehen, wie man die Motoren in das Rocker-Bogie-Federungssystem des Mars Rovers einbaut.
* Lernen, mit Arduino die Bewegung des Mars Rovers zu steuern.
* Üben, ein Programm zur Steuerung der Bewegung des Mars Rovers auf verschiedenen Geländen zu schreiben.

Benötigte Materialien
------------------------------
* SunFounder R3 Platine
* TT Motoren
* GalaxyRVR Shield
* Batterie
* Mars-Rover-Modell (ausgestattet mit Rocker-Bogie-System)
* Grundlegende Werkzeuge und Zubehör (z. B. Schraubendreher, Schrauben usw.)
* USB-Kabel
* Arduino IDE
* Computer

Schritte
--------------

**Schritt 1: Montieren der Rover-Komponenten**

In diesem Schritt montieren wir die Batterie, die R3 Platine, das GalaxyRVR Shield, die Motoren und die Räder auf das vormontierte Rocker-Bogie-System. Dadurch wird der GalaxyRVR in einen fahrbereiten Zustand versetzt.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/lu8K26MY96s" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Herzlichen Glückwunsch! Wir haben erfolgreich unseren eigenen Rover gebaut, und er ist bereit, mit der Erkundung zu beginnen. Bringen wir ihn in Bewegung!

**Schritt 2: Den Rover in Bewegung setzen**

Jetzt ist es an der Zeit, unserer Schöpfung Leben einzuhauchen und sie auf ihre Jungfernfahrt zu schicken.
Aber wie kommunizieren wir mit unserem Rover? Wie sagen wir ihm, wohin er gehen und was er tun soll?
Hier kommen unsere Programmierkenntnisse ins Spiel!

In der realen Welt drücken wir das Gaspedal, wenn wir wollen, dass ein Auto vorwärts fährt, und beide Räder beginnen sich zu drehen.
Die Räder auf der rechten Seite drehen sich im Uhrzeigersinn, während die auf der linken Seite sich gegen den Uhrzeigersinn drehen.

.. image:: img/move_car.gif
    :align: center

Stellen Sie sich vor, Sie sitzen auf dem Fahrersitz, die Welt rauscht an Ihnen vorbei, während Sie die offene Straße entlangfahren – genau diese Erfahrung werden wir unserem Rover bieten.

Nun übersetzen wir diese Erfahrung in die Sprache, die unser Rover versteht – Code!

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Definiert die Pins der Motoren
        const int in1 = 2;
        const int in2 = 3;
        const int in3 = 4;
        const int in4 = 5;

        void setup() {
            // Initialisiert SoftPWM
            SoftPWMBegin();
        }

        void loop() {
            // Setzt die linken Motoren auf Drehung gegen den Uhrzeigersinn
            SoftPWMSet(in1, 255);  // Volle Geschwindigkeit
            SoftPWMSet(in2, 0);    // Stopp

            // Setzt die rechten Motoren auf Drehung im Uhrzeigersinn
            SoftPWMSet(in3, 0);    // Stopp
            SoftPWMSet(in4, 255);  // Volle Geschwindigkeit

        }

In diesem Code sprechen wir mit unserem Rover und sagen ihm genau, was er tun soll.
Mit der Funktion ``SoftPWMSet()`` agieren wir wie das Gaspedal und die Bremse eines Autos
und steuern die Geschwindigkeit und Richtung jedes Motors.
Wir sagen den linken Motoren, sie sollen sich gegen den Uhrzeigersinn drehen, und den rechten Motoren im Uhrzeigersinn, und schon bewegt sich unser Rover vorwärts!

Das Konzept des Rückwärtsfahrens ist einfach, sobald Sie verstanden haben, wie man vorwärts fährt.
Um den Rover rückwärts fahren zu lassen, müssen wir nur die Drehrichtung jedes Motors umkehren.

So würden wir das im Code machen – genau das Gegenteil. Die rechten Räder sollten sich jetzt gegen den Uhrzeigersinn drehen und die linken Räder im Uhrzeigersinn.

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Definiert die Pins der Motoren
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialisiert SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Setzt die linken Motoren auf Drehung im Uhrzeigersinn
        SoftPWMSet(in1, 0);    // Stopp
        SoftPWMSet(in2, 255);  // Volle Geschwindigkeit

        // Setzt die rechten Motoren auf Drehung gegen den Uhrzeigersinn
        SoftPWMSet(in3, 255);  // Volle Geschwindigkeit
        SoftPWMSet(in4, 0);    // Stopp

    }

In diesem Code verwenden wir ``SoftPWMSet()``, um den linken Motoren zu sagen, sie sollen sich im Uhrzeigersinn drehen, und den rechten Motoren gegen den Uhrzeigersinn.

Ist es nicht faszinierend, dass wir die Reise unseres Rovers einfach mit Code steuern können? Wenn Sie das nächste Mal in einem Auto sitzen, denken Sie einen Moment über die Reise Ihres Rovers nach, der die Welt eine Umdrehung nach der anderen erkundet. Bleiben Sie gespannt, denn die Reise unseres Rovers hat gerade erst begonnen!

**Schritt 3: Den Rover in andere Richtungen bewegen**

Nachdem wir nun wissen, wie wir unseren Mars Rover vorwärts und rückwärts bewegen, wie wäre es, wenn wir ihn nach links oder rechts abbiegen lassen?

Wie im echten Fahren gibt es zwei Hauptmöglichkeiten, ein Auto nach links abbiegen zu lassen.

* Die erste Möglichkeit besteht darin, die Räder auf der linken Seite langsamer drehen zu lassen als die auf der rechten Seite. Dieser Geschwindigkeitsunterschied bewirkt, dass der Rover nach links abbiegt.
* Die zweite Möglichkeit besteht darin, beide Motoren (links und rechts) in die gleiche Richtung drehen zu lassen (in diesem Fall im Uhrzeigersinn), wodurch der Rover auf der Stelle nach links dreht.

Sehen wir uns an, wie wir beide Möglichkeiten im Code umsetzen können:

**Methode 1: Unterschiedliche Geschwindigkeiten auf jeder Seite**

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Definiert die Pins der Motoren
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialisiert SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Setzt die linken Motoren auf Drehung gegen den Uhrzeigersinn mit niedriger Geschwindigkeit
        SoftPWMSet(in1, 40);
        SoftPWMSet(in2, 0);

        // Setzt die rechten Motoren auf Drehung im Uhrzeigersinn mit höherer Geschwindigkeit
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 200);

        delay(2000);  // Dauert 2 Sekunden an
    }

In diesem Code haben wir die Geschwindigkeit der linken Motoren verringert, während die rechten Motoren mit einer höheren Geschwindigkeit laufen. Dadurch wird der Rover nach links abbiegen.

**Methode 2: Alle Motoren in die gleiche Richtung drehen**

.. code-block:: arduino
    :emphasize-lines: 16,17,18,19

    #include <SoftPWM.h>

    // Definiert die Motor-Pins
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialisiert SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Setzt alle Motoren auf Drehung im Uhrzeigersinn
        SoftPWMSet(in1, 0);
        SoftPWMSet(in2, 255);
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 255);
    }

In diesem Code setzen wir alle Motoren auf Drehung im Uhrzeigersinn. Der Rover wird sich um seine eigene Achse drehen und die Richtung ändert sich nach links.

Um den Rover nach rechts abbiegen zu lassen, sind die Konzepte dieselben, nur die Richtungen sind umgekehrt. Können Sie herausfinden, wie man das macht?

**Schritt 4: Bewegung in alle Richtungen**

Wenn wir mehr Funktionalitäten für unseren Mars Rover entwickeln, könnte unser Code recht lang und unübersichtlich werden. In der Programmierung ist es eine gute Praxis, den Code organisiert und wartbar zu halten. Eine Möglichkeit, dies zu erreichen, ist die Erstellung separater Funktionen für separate Aufgaben.

In diesem Fall können wir separate Funktionen für jede Richtung erstellen, in die sich der Rover bewegen kann. Dies macht unseren Code nicht nur leichter verständlich, sondern ermöglicht uns auch, diese Funktionen überall in unserem Programm wiederzuverwenden, ohne dieselben Codezeilen neu schreiben zu müssen.

Sehen wir uns an, wie wir das machen können:

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/90c13522-9757-4212-b250-63ffbc790fd3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Mit dieser Struktur bleibt unsere Hauptschleife einfach und leicht nachvollziehbar. Wir können klar sehen, dass der Rover sich vorwärts, dann rückwärts bewegt,
dann nach links und rechts abbiegt und schließlich anhält.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Die Details, wie jede dieser Aktionen erreicht wird, sind in separaten Funktionen verborgen. Dies ist ein zentraler Aspekt guter Programmierpraxis, der als Abstraktion bezeichnet wird.

**Schritt 5: Teilen und Reflektieren**

Herzlichen Glückwunsch zum Abschluss dieser Erkundungsreise mit dem Mars Rover! Dies ist eine praktische Anwendung Ihres Wissens über Naturwissenschaften und Technik, und Sie haben großartige Arbeit geleistet!

Jetzt können Sie zeigen, wie Ihr Rover verschiedene Geländehindernisse überwindet. Sie könnten Ihren Rover beim Navigieren durch verschiedene Gelände filmen oder Ihren Rover Ihren Freunden präsentieren.

Auch das Nachdenken über Ihren Lernprozess ist sehr wichtig. Was haben Sie während dieses Prozesses gelernt? Sind neue Ideen oder kreative Gedanken entstanden? Was haben Sie bei der Steuerung von Motoren und der Programmierung gewonnen?

Sie können weiter forschen, neues Wissen entdecken und sich ständig verbessern. Machen Sie weiter so, zukünftige Wissenschaftler und Ingenieure!
