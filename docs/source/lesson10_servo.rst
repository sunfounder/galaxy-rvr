.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Lektion 10: Erkundung des visuellen Systems des Mars-Rovers - Servo und Kippmechanismus
===========================================================================================

Willkommen zurück, junge Entdecker! In unserem heutigen Abenteuer werden wir in die faszinierende Welt des visuellen Systems des Mars-Rovers eintauchen.
Genau wie unsere Augen und unser Hals zusammenarbeiten, um uns zu helfen, unsere Umgebung zu sehen und zu navigieren, benötigt unser Rover ein ähnliches System, 
um die tückische Marslandschaft zu durchqueren. Und genau das werden wir heute bauen!

Das visuelle System unseres Rovers besteht aus zwei Hauptteilen: einer Kamera, die als seine „Augen“ dient, und einem Kippmechanismus, der wie ein „Hals“ fungiert, 
der es ihm ermöglicht, nach oben und unten zu schauen. Bis zum Ende dieser Lektion werden wir unserem Rover die Fähigkeit geben, zu „sehen“ und zu „nicken“!

Zuerst werden wir den Kippmechanismus bauen - ein Gerät, das die Kamera unseres Rovers hält und es ihr ermöglicht, sich vertikal zu drehen. 
Es ist, als würden wir unserem Rover einen Hals geben, damit er seinen „Kopf“ oder die Kamera nach oben und unten nicken kann!

Als Nächstes werden wir den Servo kennenlernen, den winzigen, aber leistungsstarken „Muskel“, der unseren Kippmechanismus bewegt. 
Wir werden verstehen, wie er funktioniert und wie wir ihn mit Arduino-Programmierung steuern können.

Genau wie unsere Halsmuskeln unseren Kopf bewegen, damit unsere Augen eine bessere Sicht haben, wird der Servo den Kippmechanismus bewegen, damit die Kamera des Rovers 
die Marslandschaft besser überblicken kann.

Also, schnallt euch an, Entdecker, lasst uns unsere Mission beginnen, unseren Rover mit seinem eigenen visuellen System auszustatten!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/servo_range.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>


Kursziele
-------------------------

* Üben Sie die Installation und Bedienung des Kippmechanismus am Mars-Rover-Modell.
* Verstehen Sie die Funktionsprinzipien und Anwendungsmöglichkeiten eines Servos.
* Erlernen Sie, wie man die Bewegung des Servos durch Arduino-Programmierung steuert.

Kursmaterialien
-----------------------

* Arduino UNO Entwicklungsboard
* Servo
* Gimbal und Kamera
* Mars-Rover-Modell (bereits ausgestattet mit TT-Motor, Federungssystem, Ultraschall- und Infrarot-Hindernisvermeidungsmodulen, RGB-LED-Streifen)
* Arduino IDE
* Computer

Kursschritte
--------------

**Schritt 1: Was ist ein Servo?**

Haben Sie schon einmal eine Puppenshow gesehen? Wenn ja, haben Sie sich vielleicht darüber gewundert, wie der Puppenspieler die Arme, Beine und den Kopf der Puppe so geschmeidig bewegen kann, nur indem er an einigen Fäden zieht. In gewisser Weise sind Servomotoren wie unsere Puppenspieler.

.. image:: img/puppet_show.png
    :width: 200
    :align: center

Servomotoren sind eine besondere Art von Motoren, die sich nicht einfach nur drehen wie ein Rad. Stattdessen können sie sich auf eine bestimmte Position bewegen und diese Position halten. Stellen Sie sich vor, Sie spielen „Simon sagt“, und Simon sagt: „Heben Sie Ihren Arm in einem 90-Grad-Winkel!“ Das können Sie, oder? Das liegt daran, dass Sie, genau wie ein Servo, genau steuern können, wie weit Sie Ihren Arm bewegen.

.. image:: img/servo.png
    :align: center

* Braune Leitung: GND
* Orange Leitung: Signalleitung, verbinden mit dem PWM-Pin des Hauptboards.
* Rotes Kabel: VCC

Genau wie Sie Ihre Arme kontrollieren können, um sich in bestimmte Positionen zu bewegen, können wir Servomotoren verwenden, um die genaue Position von Objekten in unseren Projekten zu steuern. In unserem Mars-Rover werden wir einen Servo verwenden, um die Auf- und Abbewegung unseres Kippmechanismus zu steuern, genau wie Sie mit Ihrem Kopf nicken können.

Im nächsten Schritt werden wir eine faszinierende Reise ins Innere eines Servomotors unternehmen, um zu verstehen, wie er funktioniert. Gespannt? Los geht's!


**Schritt 2: Wie funktioniert ein Servo?**

Wie genau funktioniert nun ein Servo? Lassen Sie uns eine spannende Reise ins Innere eines Servos unternehmen!

Wenn wir in einen Servo hineinschauen würden, würden wir einige Teile sehen. Im Herzen eines Servos befindet sich ein normaler Motor, ganz ähnlich den Motoren, die die Räder unseres Mars-Rovers drehen. Um den Motor herum befindet sich ein großes Zahnrad, das mit einem kleineren Zahnrad auf der Motorwelle verbunden ist. So wird die schnelle, kreisförmige Bewegung des Motors in eine langsamere, aber stärkere Bewegung umgewandelt.

.. image:: img/servo_internal.png
    :align: center

Aber das ist nicht das, was einen Servo besonders macht. Die Magie passiert in einem winzigen Stück Elektronik, genannt „potentiometer“, und der „control circuitry“. So funktioniert es: Wenn sich der Servo bewegt, dreht sich das Potentiometer und ändert seinen Widerstand. Die Steuerschaltung misst diese Widerstandsänderung und weiß genau, in welcher Position sich der Servo befindet. Clever, oder?

Um einen Servo zu steuern, senden wir ihm ein spezielles Signal, genannt "Pulsbreitenmodulations"-Signal oder PWM. Indem wir die Breite dieser Pulse ändern, können wir genau steuern, wie weit sich der Servo bewegt und ihn in dieser Position halten.

Im nächsten Schritt lernen wir, wie man einen Servo mit einem Arduino steuert. Bereit für ein paar magische Sprüche in Form von Code? Los geht's!

**Schritt 3: Steuerung eines Servos mit Arduino**

In Ordnung, Entdecker, jetzt, wo wir wissen, wie ein Servo funktioniert, lernen wir, wie man ihn mit unserem Zauberstab, dem Arduino, steuert!

Einen Servo zu steuern ist wie ihm Anweisungen zu geben. Erinnern Sie sich an die zuvor erwähnten Pulsbreitenmodulations- (PWM) Signale? Diese werden wir verwenden, um dem Servo zu sagen, wohin er sich bewegen soll.

Glücklicherweise macht Arduino uns diese Aufgabe leicht mit einer eingebauten Bibliothek namens ``Servo``. Mit dieser Bibliothek können wir ein ``Servo``-Objekt erstellen, einen Pin damit verbinden (den Pin, an den unser Servo angeschlossen ist) und dann einen einfachen Befehl, ``write()``, verwenden, um den Winkel einzustellen.

Hier ist ein Ausschnitt, wie der Code aussieht:

.. code-block:: arduino

    #include <Servo.h> 

    Servo myServo;  // create a servo object

    void setup() {
        myServo.attach(6);  // attaches the servo on pin 6
    }

    void loop() {
        myServo.write(90);  // tell servo to go to 90 degrees
    }

In diesem Code ist ``myServo`` unser Servo-Objekt, ``attach(6)`` sagt dem Arduino, dass unser Servo an Pin 6 angeschlossen ist, und ``write(90)`` sagt dem Servo, er soll sich auf 90 Grad bewegen.

Großartige Arbeit, Entdecker! Sie haben gerade gelernt, wie man einen Servomotor mit Arduino steuert. Sie können auch mit verschiedenen Winkeln experimentieren! 

**Schritt 4: Montage des visuellen Systems**

Jetzt sind Sie bereit, das visuelle System unseres Rovers zusammenzubauen.

.. note::

    * Achten Sie beim Einsetzen der ESP32 CAM in den Kameraadapter auf die Ausrichtung. Sie sollte richtig mit dem ESP32-Adapter ausgerichtet sein.

    .. image:: img/esp32_cam_direction.png
        :width: 300
        :align: center
    
.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/h43JVI3xLqE?si=Q7-RvRvZOusK7vPo" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Schritt 5: Die Grenzen des Kippmechanismus verstehen**

Obwohl der Servo dafür ausgelegt ist, sich zwischen 0 und 180 Grad zu drehen, haben Sie vielleicht bemerkt, dass er jenseits eines bestimmten Punktes (sagen wir nach 150 Grad) nicht mehr reagiert. Haben Sie sich jemals gefragt, warum das passiert? Lassen Sie uns dieses Geheimnis in unserem nächsten Abenteuer zusammen erkunden!

Können Sie sich einen Vogel vorstellen, der versucht, seinen Hals zu weit zu beugen, sodass er seinen eigenen Körper berührt und sich nicht weiterbewegen kann? Unser Rover-Kippmechanismus steht vor einer ähnlichen Situation. Wenn sich der Servo nach unten bewegt, kann er gegen den Körper unseres Rovers stoßen und kann nicht über einen bestimmten Winkel hinausgehen.

Wenn wir versuchen, ihn durch Schreiben eines unerreichbaren Winkels in unserem Code zu zwingen, sich über diesen Punkt hinaus zu bewegen, kann unser kleiner Servo-Vogel stecken bleiben und sich sogar beschädigen! Das wollen wir nicht, oder? Daher wollen wir seine Bewegungsgrenzen mit einem kleinen Experiment verstehen.

Wir verwenden eine for-Schleife, um den Servo von 0 bis 180 Grad zu drehen, während wir den Winkel im Seriellen Monitor notieren.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/848c7a3a-16b2-4a7e-8d66-bb91848bc6d9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

* Der ESP32-CAM und das Arduino-Board teilen sich dieselben RX (Empfang) und TX (Senden) Pins. Daher müssen Sie vor dem Hochladen des Codes zuerst den ESP32-CAM durch Verschieben dieses Schalters nach rechts freigeben, um Konflikte oder potenzielle Probleme zu vermeiden.

    .. image:: img/camera_upload.png
        :width: 600

* Nachdem Sie diesen Code hochgeladen haben, öffnen Sie den **Serial Monitor**. Wenn keine Informationen erscheinen, drücken Sie die **Reset button** auf dem GalaxyRVR-Shield, um den Code erneut auszuführen.

* Sie werden sehen, wie sich der Servo dreht, und der Serielle Monitor zeigt den Winkel an.

.. image:: img/servo_range.png

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/servo_range.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>
    
Bei meinem Rover konnte der Kippmechanismus bis zu etwa 140° hochgehen, bevor er den Körper des Rovers berührte und nicht weiter gehen konnte.

Also, Entdecker, denken Sie immer daran, die Grenzen Ihres Rovers zu respektieren, um ihn sicher und funktionsfähig zu halten!


**Schritt 6: Teilen und Reflektieren**

Gut gemacht, Entdecker! Heute haben Sie nicht nur einen Kippmechanismus für Ihren Rover gebaut, sondern auch verstanden, wie man einen Servo steuert, um ihn zu bewegen. Das ist ein großer Schritt vorwärts in unserer Mars-Rover-Mission.

Jetzt wollen wir unsere Erfahrungen teilen und über das, was wir gelernt haben, nachdenken.

Sind Ihnen beim Aufbau des Kippmechanismus oder bei der Programmierung des Servos Herausforderungen begegnet? Wie haben Sie diese überwunden?

Denken Sie daran, jede Herausforderung, die wir überwinden, macht uns klüger und unseren Rover besser. Zögern Sie also nicht, Ihre Geschichten, Ideen und Lösungen zu teilen. Wer weiß, vielleicht hilft Ihre innovative Lösung einem anderen Entdecker auf seiner Reise!

