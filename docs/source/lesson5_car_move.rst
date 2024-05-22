.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Lektion 5: Entfesselung der Beweglichkeit des Mars Rovers
===========================================================

Macht euch bereit, junge Entdecker! Wir haben gelernt, Motoren zu steuern, und jetzt bringen wir diese Fähigkeiten auf den roten Planeten. In dieser Lektion erwecken wir den Mars Rover zum Leben!

Wir lernen, wie man die Motoren in das Rocker-Bogie-Federungssystem des Rovers einbaut und dann, unter Verwendung unserer Programmierkenntnisse, unseren Rover über imaginäre Marslandschaften steuert.

Es ist ein Marsabenteuer in unserem Klassenzimmer. Lasst uns anfangen!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_move.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. note::

    Wenn du diesen Kurs nach dem vollständigen Zusammenbau des GalaxyRVR lernst, musst du diesen Schalter nach rechts bewegen, bevor du den Code hochlädst.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Kursziele
-------------------------

* Verstehe, wie man die Motoren in das Rocker-Bogie-Federungssystem des Mars Rovers einbaut.
* Lerne, wie man Arduino verwendet, um die Bewegung des Mars Rovers zu steuern.
* Übe das Schreiben eines Programms, um die Bewegung des Mars Rovers auf verschiedenen Geländearten zu steuern.

Kursmaterialien
-----------------------
* SunFounder R3 Board
* TT-Motoren
* GalaxyRVR-Shield
* Batterie
* Mars Rover Modell (ausgestattet mit Rocker-Bogie-System)
* Grundwerkzeuge und Zubehör (z.B. Schraubendreher, Schrauben, etc.)
* USB-Kabel
* Arduino IDE
* Computer

Kursschritte
--------------

**Schritt 1: Zusammenbau der Rover-Komponenten**

In diesem Schritt montieren wir die Batterie, das R3-Board, das GalaxyRVR-Shield, die Motoren und die Räder auf das vormontierte Rocker-Bogie-System. Dadurch wird der GalaxyRVR fahrbereit.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/lu8K26MY96s" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Glückwunsch! Wir haben erfolgreich unseren eigenen Rover gebaut, und er ist bereit, die Erkundung zu beginnen. Lasst uns loslegen!

**Schritt 2: Den Rover in Bewegung setzen**

Jetzt ist es an der Zeit, unserem Schöpfung Leben einzuhauchen und sie auf ihre Jungfernfahrt zu schicken.
Aber wie kommunizieren wir mit unserem Rover? Wie sagen wir ihm, wohin er gehen und was er tun soll?
Da kommen unsere Programmierkenntnisse ins Spiel!

In der realen Welt, wenn wir wollen, dass ein Auto vorwärtsfährt, drücken wir auf das Gaspedal, und beide Räder beginnen sich zu drehen.
Die Räder auf der rechten Seite drehen sich im Uhrzeigersinn, während die auf der linken Seite sich gegen den Uhrzeigersinn drehen.

.. image:: img/move_car.gif
    :align: center

Stell dir vor, du sitzt am Steuer, die Welt rauscht an dir vorbei, während du auf der offenen Straße dahingleitest - genau dieses Erlebnis wollen wir unserem Rover geben.

Jetzt übersetzen wir dieses Erlebnis in die Sprache, die unser Rover versteht - Code!

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Define the pins of motors 
        const int in1 = 2;
        const int in2 = 3;
        const int in3 = 4;
        const int in4 = 5;

        void setup() {
            // Initialize SoftPWM
            SoftPWMBegin();
        }

        void loop() {
            // Set the left motors rotate counterclockwise
            SoftPWMSet(in1, 255);  // Full speed
            SoftPWMSet(in2, 0);    // Stop
            
            // Set the right motors rotate clockwise
            SoftPWMSet(in3, 0);    // Stop
            SoftPWMSet(in4, 255);  // Full speed
            
        }

In diesem Code sprechen wir mit unserem Rover und sagen ihm genau, was er tun soll. 
Mit der Funktion ``SoftPWMSet()`` verhalten wir uns wie das Gaspedal und die Bremsen eines Autos, 
indem wir die Geschwindigkeit und die Richtung jedes Motors steuern. 
Wir sagen den linken Motoren, sie sollen sich gegen den Uhrzeigersinn drehen, und den rechten Motoren, sie sollen sich im Uhrzeigersinn drehen, und genau so bewegt sich unser Rover vorwärts!

Absolut, das Konzept, den Rover rückwärts zu bewegen, ist unkompliziert, sobald man versteht, wie man ihn vorwärts bewegt.
Um den Rover rückwärts fahren zu lassen, müssen wir nur die Drehrichtung jedes Motors umkehren.

So würden wir das im Code umsetzen, wir machen einfach das Gegenteil. Die rechten Räder sollten sich nun gegen den Uhrzeigersinn drehen, und die linken Räder sollten sich im Uhrzeigersinn drehen.

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

     // Define the pins of motors 
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set the left motors to rotate clockwise
        SoftPWMSet(in1, 0);    // Stop
        SoftPWMSet(in2, 255);  // Full speed

        // Set the right motors to rotate counterclockwise
        SoftPWMSet(in3, 255);  // Full speed
        SoftPWMSet(in4, 0);    // Stop
        
    }

In diesem Code verwenden wir ``SoftPWMSet()``, um den linken Motoren zu sagen, dass sie sich im Uhrzeigersinn drehen sollen und den rechten Motoren, dass sie sich gegen den Uhrzeigersinn drehen sollen.

Ist es nicht faszinierend, dass wir die Reise unseres Rovers einfach mit Code steuern können? Das nächste Mal, wenn du in einem Auto bist, nimm dir einen Moment Zeit, um über die Reise deines Rovers nachzudenken, der die Welt eine Drehung nach der anderen erkundet. Bleib dran, denn die Reise unseres Rovers fängt gerade erst an!

**Schritt 3: Den Rover in andere Richtungen bewegen**

Jetzt, wo wir wissen, wie wir unseren Mars Rover vorwärts und rückwärts bewegen können, was ist, wenn wir ihn nach links oder rechts drehen lassen wollen?

Genau wie beim Autofahren im echten Leben gibt es zwei Hauptmethoden, um ein Auto nach links abbiegen zu lassen.

* Die erste Methode besteht darin, die Räder auf der linken Seite langsamer als die auf der rechten Seite rotieren zu lassen. Dieser Geschwindigkeitsunterschied wird den Rover nach links abbiegen lassen.
* Die zweite Methode besteht darin, beide linken und rechten Motoren in dieselbe Richtung rotieren zu lassen (in diesem Fall im Uhrzeigersinn), was den Rover auf seiner Achse nach links drehen lässt.

Lassen Sie uns sehen, wie wir beide Methoden im Code umsetzen können:

**Methode 1: Unterschiedliche Geschwindigkeiten auf jeder Seite**

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Define the pins of motors 
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set the left motors rotate counterclockwise in low speed
        SoftPWMSet(in1, 40);
        SoftPWMSet(in2, 0);

        // Set the right motors rotate clockwise in higher speed
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 200);

        delay(2000);  // Last for 2 seconds
    }

In diesem Code haben wir die Geschwindigkeit der linken Motoren verringert, während wir die rechten Motoren auf einer höheren Geschwindigkeit belassen haben. Dadurch wird der Rover nach links abbiegen.

**Methode 2: Alle Motoren in dieselbe Richtung drehen**

.. code-block:: arduino
    :emphasize-lines: 16,17,18,19

    #include <SoftPWM.h>

    // Define the motor pins
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set all motors to rotate clockwise
        SoftPWMSet(in1, 0);
        SoftPWMSet(in2, 255);
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 255);
    }

In diesem Code haben wir alle Motoren so eingestellt, dass sie sich im Uhrzeigersinn drehen. Der Rover wird sich um seine eigene Achse drehen und die Richtung nach links ändern.

Um den Rover nach rechts abbiegen zu lassen, sind die Konzepte dieselben, aber die Richtungen sind umgekehrt. Kannst du herausfinden, wie das geht?

**Schritt 4: In alle Richtungen bewegen**

Wenn wir mehr Funktionen für unseren Mars Rover entwickeln, könnte unser Code ziemlich lang und unübersichtlich werden. In der Programmierung ist es eine gute Praxis, den Code organisiert und wartbar zu halten. Eine Möglichkeit, dies zu erreichen, besteht darin, separate Funktionen für separate Aufgaben zu erstellen.

In diesem Fall können wir separate Funktionen für jede Richtung erstellen, in die sich der Rover bewegen kann. Das macht unseren Code nicht nur leichter verständlich, sondern ermöglicht es uns auch, diese Funktionen überall in unserem Programm wiederverwenden zu können, ohne die gleichen Codezeilen neu schreiben zu müssen.

Lassen Sie uns sehen, wie wir das machen können:

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/90c13522-9757-4212-b250-63ffbc790fd3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Mit dieser Struktur bleibt unsere Hauptloop einfach und übersichtlich. Wir können deutlich sehen, dass der Rover vorwärts, dann rückwärts fährt, 
dann nach links und rechts abbiegt und schließlich anhält. 

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_move.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Die Details, wie jede dieser Aktionen erreicht wird, sind in separaten Funktionen versteckt. Dies ist ein wichtiger Aspekt guter Programmierpraktiken, bekannt als Abstraktion.

**Schritt 5: Teilen und Reflektieren**

Herzlichen Glückwunsch zum Abschluss dieser Erkundungsreise mit dem Mars Rover! Das ist eine praktische Anwendung deines Wissens in Wissenschaft und Technik, und du hast fantastische Arbeit geleistet!

Jetzt kannst du teilen, wie dein Rover verschiedene Geländehindernisse überwindet. Du könntest deinen Rover filmen, wie er verschiedene Geländearten navigiert, oder deinen Rover deinen Freunden zeigen.

Das Reflektieren über deinen Lernprozess ist ebenfalls sehr wichtig. Was hast du während dieses Prozesses gelernt? Sind neue Ideen oder kreative Gedanken entstanden? Was hast du im Bereich der Motorensteuerung und Programmierung dazugewonnen?

Du kannst weiterhin erkunden, neues Wissen entdecken und dich ständig verbessern. Mach weiter so, zukünftige Wissenschaftler und Ingenieure!

