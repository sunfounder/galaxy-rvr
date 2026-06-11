
Lektion 10: Erkundung des Mars Rover-Visionssystems - Servo und Neigungsmechanismus
===================================================================================

Willkommen zurück, junge Entdecker! Im heutigen Abenteuer tauchen wir in die faszinierende Welt des Visionssystems des Mars Rovers ein.
So wie unsere Augen und unser Hals zusammenarbeiten, um uns das Sehen und Navigieren in unserer Umgebung zu ermöglichen, benötigt auch unser Rover ein ähnliches System, um
die tückische Marslandschaft zu erkunden. Und genau das werden wir heute bauen!

Das Visionssystem unseres Rovers besteht aus zwei Hauptteilen: einer Kamera, die als seine "Augen" fungiert, und einem Neigungsmechanismus, der wie ein "Hals" wirkt
und es ihm ermöglicht, nach oben und unten zu schauen. Am Ende dieser Lektion werden wir unserem Rover die Fähigkeit geben, zu "sehen" und zu "nicken"!

Zuerst bauen wir den Neigungsmechanismus - ein Gerät, das die Kamera unseres Rovers hält und ihr eine vertikale Drehung ermöglicht.
Es ist, als ob wir unserem Rover einen Hals geben, damit er seinen "Kopf" oder seine Kamera nach oben und unten neigen kann!

Als nächstes lernen wir den Servo kennen, den winzigen, aber leistungsstarken "Muskel", der unseren Neigungsmechanismus bewegt.
Wir werden verstehen, wie er funktioniert und wie wir ihn mit Arduino-Programmierung steuern können.

So wie unsere Nackenmuskeln unseren Kopf bewegen, damit unsere Augen eine bessere Sicht bekommen, wird der Servo den Neigungsmechanismus bewegen, damit die Kamera
des Rovers die Marslandschaft besser erkunden kann.

Also, schnallen Sie sich an, Entdecker, lasst uns unsere Mission beginnen, unseren Rover mit seinem eigenen Visionssystem auszustatten!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/servo_range.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>


Zielsetzung
----------------

* Üben der Installation und Bedienung des Neigungsmechanismus am Mars Rover-Modell.
* Die Funktionsprinzipien und die Anwendung eines Servos verstehen.
* Lernen, wie man die Servobewegung durch Arduino-Programmierung steuert.

Materialien
---------------

* Arduino UNO-Entwicklungsboard
* Servo
* Gimbal und Kamera
* Mars Rover-Modell (bereits ausgestattet mit TT-Motor, Federungssystem, Ultraschall- und Infrarot-Hindernisvermeidungsmodulen, RGB-LED-Streifen)
* Arduino IDE
* Computer

Schritte
-----------

**Schritt 1: Was ist ein Servo?**

Haben Sie jemals eine Puppenshow gesehen? Wenn ja, haben Sie sich vielleicht gewundert, wie der Puppenspieler die Arme, Beine und den Kopf der Puppe so geschmeidig bewegen kann, indem er einfach an einigen Fäden zieht. In gewisser Weise sind Servomotoren wie unsere Puppenspieler.

.. image:: img/puppet_show.png
    :width: 200
    :align: center

Servomotoren sind spezielle Motoren, die sich nicht einfach wie ein Rad drehen und immer weiterdrehen. Stattdessen können sie sich in eine bestimmte Position bewegen und diese Position halten. Stellen Sie sich vor, Sie spielen "Simon sagt" und Simon sagt: "Heben Sie Ihren Arm in einem 90-Grad-Winkel!" Sie können das, oder? Das liegt daran, dass Sie, wie ein Servo, genau kontrollieren können, wie weit Sie Ihren Arm bewegen.

.. image:: img/servo.png
    :align: center

* Braune Leitung: GND
* Orange Leitung: Signalpin, an den PWM-Pin der Hauptplatine anschließen.
* Rotes Kabel: VCC

So wie Sie Ihre Arme steuern können, um sich in bestimmte Positionen zu bewegen, können wir Servomotoren verwenden, um die genaue Position von Objekten in unseren Projekten zu steuern. In unserem Mars Rover werden wir einen Servo verwenden, um die Auf- und Abbewegung unseres Neigungsmechanismus zu steuern, ähnlich wie Sie Ihren Kopf auf und ab neigen können.

Im nächsten Schritt begeben wir uns auf eine faszinierende Reise in das Innere eines Servomotors, um zu verstehen, wie er funktioniert. Aufgeregt? Dann los!

**Schritt 2: Wie funktioniert ein Servo?**

Wie vollbringt ein Servo also seine Magie? Begeben wir uns auf eine aufregende Reise in das Innere eines Servos!

Wenn wir in einen Servo hineinschauen würden, würden wir ein paar Teile sehen. Im Herzen eines Servos befindet sich ein gewöhnlicher Motor, der den Motoren sehr ähnlich ist, die die Räder unseres Mars Rovers antreiben. Um den Motor herum befindet sich ein großes Zahnrad, das mit einem kleineren Zahnrad auf der Motorwelle verbunden ist. So wird die schnelle, kreisförmige Bewegung des Motors in eine langsamere, aber stärkere Bewegung umgewandelt.

.. image:: img/servo_internal.png
    :align: center

Aber das ist nicht das, was einen Servo besonders macht. Die Magie geschieht in einem winzigen elektronischen Bauteil namens "Potentiometer" und der "Steuerelektronik". So funktioniert es: Wenn sich der Servo bewegt, dreht sich das Potentiometer und ändert seinen Widerstand. Die Steuerelektronik misst diese Widerstandsänderung und weiß genau, in welcher Position sich der Servo befindet. Clever, nicht wahr?

Um einen Servo zu steuern, senden wir ihm eine spezielle Art von Signal, ein sogenanntes "Pulsweitenmodulations"-Signal oder PWM. Durch Ändern der Breite dieser Impulse können wir genau steuern, wie weit sich der Servo bewegt, und ihn in dieser Position halten.

Im nächsten Schritt lernen wir, wie man einen Servo mit einem Arduino steuert. Bereit für ein paar Zaüber in Code-Form? Dann los!

**Schritt 3: Steuern eines Servos mit Arduino**

Also gut, Entdecker, jetzt wo wir wissen, wie ein Servo funktioniert, lernen wir, wie man ihn mit unserem Zauberstab, dem Arduino, steuert!

Einen Servo zu steuern ist wie ihm Anweisungen zu geben. Erinnern Sie sich an die Pulsweitenmodulationssignale (PWM), die wir erwähnt haben? Wir werden diese verwenden, um dem Servo zu sagen, wohin er sich bewegen soll.

Glücklicherweise macht Arduino diese Aufgabe für uns einfach, mit einer integrierten Bibliothek namens ``Servo``. Mit dieser Bibliothek können wir ein ``Servo``-Objekt erstellen, einen Pin daran anhängen (den Pin, mit dem unser Servo verbunden ist), und dann einen einfachen Befehl, ``write()``, verwenden, um den Winkel einzustellen.

Hier ist ein Ausschnitt, wie der Code aussieht:

.. code-block:: arduino

    #include <Servo.h>

    Servo myServo;  // Erstelle ein Servo-Objekt

    void setup() {
        myServo.attach(6);  // Verbindet den Servo mit Pin 6
    }

    void loop() {
        myServo.write(90);  // Sage dem Servo, er soll auf 90 Grad gehen
    }

In diesem Code ist ``myServo`` unser Servo-Objekt, ``attach(6)`` teilt dem Arduino mit, dass unser Servo an Pin 6 angeschlossen ist, und ``write(90)`` sagt dem Servo, er soll sich auf 90 Grad bewegen.

Großartige Arbeit, Entdecker! Sie haben gerade gelernt, wie man einen Servomotor mit Arduino steuert. Sie können auch mit verschiedenen Winkeln experimentieren!

**Schritt 4: Montieren Sie das Visionssystem**

Sie sind nun bereit, das Visionssystem unseres Rovers zu montieren.

.. note::

    * Achten Sie beim Einsetzen der ESP32 CAM in den Kamera-Adapter auf die Ausrichtung. Sie sollte richtig mit dem ESP32-Adapter ausgerichtet sein.

    .. image:: img/esp32_cam_direction.png
        :width: 300
        :align: center

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/h43JVI3xLqE?si=Q7-RvRvZOusK7vPo" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Schritt 5: Die Grenzen des Neigungsmechanismus verstehen**

Obwohl der Servo für eine Drehung zwischen 0 und 180 Grad ausgelegt ist, stellen Sie vielleicht fest, dass er jenseits eines bestimmten Punktes (sagen wir nach 150 Grad) nicht mehr reagiert. Haben Sie sich jemals gefragt, warum das passiert? Lassen Sie uns dieses Geheimnis gemeinsam in unserem nächsten Abenteuer erforschen!


Können Sie sich einen Vogel vorstellen, der versucht, seinen Hals so stark zu beugen, dass er seinen eigenen Körper berührt und sich nicht weiterbewegen kann? Der Neigungsmechanismus unseres Rovers steht vor einer ähnlichen Situation. Wenn der Servo den Mechanismus nach unten bewegt, kann er gegen den Körper unseres Rovers stoßen und nicht über einen bestimmten Winkel hinausgehen.

Wenn wir versuchen, ihn über diesen Punkt hinaus zu bewegen, indem wir einen unerreichbaren Winkel in unseren Code schreiben, kann unser kleiner Servo-Vogel stecken bleiben und sich sogar selbst beschädigen! Das wollen wir nicht, oder? Lassen Sie uns also seine Bewegungsgrenzen mit einem kleinen Experiment verstehen.

Wir verwenden eine for-Schleife, um den Servo von 0 auf 180 Grad zu drehen, während wir den Winkel im Seriellen Monitor notieren.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/848c7a3a-16b2-4a7e-8d66-bb91848bc6d9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

* Der ESP32-CAM und das Arduino-Board teilen sich die gleichen RX (Empfangs-) und TX (Send-) Pins. Bevor Sie den Code hochladen, müssen Sie daher zuerst den ESP32-CAM freigeben, indem Sie diesen Schalter nach rechts schieben, um Konflikte oder potenzielle Probleme zu vermeiden.

    .. image:: ../img/camera_upload.png
        :width: 600

* Nachdem wir diesen Code hochgeladen haben, öffnen Sie den **Seriellen Monitor**. Wenn keine Informationen angezeigt werden, drücken Sie die **Reset-Taste** auf dem GalaxyRVR-Shield, um den Code erneut auszuführen.

* Sie werden sehen, wie sich der Servo dreht, und der Serielle Monitor zeigt den Winkel an.

.. image:: img/servo_range.png

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/servo_range.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>

Auf meinem Rover könnte der Neigungsmechanismus bis zu etwa 135° gehen, bevor er den Körper des Rovers berührte und nicht weiterkönnte.

Denken Sie also, Entdecker, immer daran, die Grenzen Ihres Rovers zu respektieren, um ihn sicher und funktionsfähig zu halten!


**Schritt 6: Austausch und Reflexion**

Gut gemacht, Entdecker! Heute haben Sie nicht nur einen Neigungsmechanismus für Ihren Rover gebaut, sondern auch verstanden, wie man einen Servo steuert, um ihn zu bewegen. Das ist ein großer Schritt nach vorne auf unserer Mars Rover-Mission.

Lassen Sie uns nun unsere Erfahrungen austauschen und darüber reflektieren, was wir gelernt haben.

Sind Sie beim Aufbau des Neigungsmechanismus oder bei der Programmierung des Servos auf Herausforderungen gestoßen? Wie haben Sie sie überwunden?

Denken Sie daran, jede Herausforderung, die wir überwinden, macht uns schlauer und unseren Rover besser. Zögern Sie also nicht, Ihre Geschichten, Ideen und Lösungen zu teilen. Sie wissen nie, ob Ihre innovative Lösung einem anderen Entdecker auf seiner Reise helfen könnte!
