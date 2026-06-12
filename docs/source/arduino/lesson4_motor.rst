.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Lektion 4: Den TT Motor beherrschen
============================================

In den vorherigen Lektionen haben wir Mars Rover, ihre Federungssysteme erkundet und Wissen über Arduino erlangt.

In diesem spannenden Kurs werden wir die Funktionsweise von Motoren untersuchen, einer Schlüsselkomponente, die Mars Rover antreibt.
Wir werden die Prinzipien verstehen, die diese Motoren antreiben, und lernen, sie mit der SunFounder R3 Platine und einem GalaxyRVR Shield zu steuern.

Am Ende dieses Kurses werden Sie ein fundiertes Verständnis der Motoroperation und praktische Erfahrung in der Motorsteuerung haben.

Tauchen wir ein!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/left_1.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>

.. note::

    Wenn Sie diesen Kurs nach vollständiger Montage des GalaxyRVR lernen, müssen Sie diesen Schalter vor dem Hochladen des Codes nach rechts bewegen.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Kursziele
-----------------------
* Die grundlegenden Prinzipien von Motoren und die Eigenschaften des TT Motors verstehen.
* Lernen, wie man die Richtung und Geschwindigkeit des TT Motors steuert.
* Verstehen, wie das GalaxyRVR Shield sechs Motoren steuert.


Materialien
-----------------------

* SunFounder R3 Platine
* TT Motor
* GalaxyRVR Shield
* Batterie
* USB-Kabel
* Arduino IDE
* Computer


Kursschritte
------------------

**Schritt 1: Was ist ein Motor?**

Motoren spielen eine integrale Rolle in unserem täglichen Leben. Sie sind überall! Von den elektrischen Ventilatoren, die uns an heißen Tagen kühlen, über die Mixer, die uns helfen, köstliche Kuchen zu backen, bis hin zu den Elektroautos, die auf den Straßen vorbeisausen – Motoren bringen Dinge in Bewegung!

.. image:: img/motor_application.jpg

Ein Motor ist wie das Herz einer Maschine. Er wandelt elektrische Energie in mechanische Energie um und erweckt unsere Spielzeuge, Haushaltsgeräte und sogar große Fahrzeuge zum Leben!

Die Magie hinter einem Motor ist überhaupt keine Magie – es ist Wissenschaft, genauer gesagt das Prinzip der elektromagnetischen Induktion. So funktioniert es: Wenn Strom an einen Motor angelegt wird, erzeugt dieser ein Magnetfeld. Dieses Magnetfeld interagiert dann mit anderen Magneten im Motor, wodurch sich der Motor dreht. Diese Drehung, ähnlich dem Kreisel eines Kreisels, kann dann verwendet werden, um Räder, Propeller oder andere bewegliche Teile einer Maschine anzutreiben.

.. image:: img/motor_rotate.gif
    :align: center

Die Art von Motor, auf die wir uns in unserem GalaxyRVR konzentrieren, ist ein spezieller Typ, der als TT Getriebemotor bezeichnet wird.

.. image:: img/tt_motor_xh.jpg
    :align: center
    :width: 400

Dies ist im Wesentlichen ein normaler Motor, kombiniert mit einer Reihe von Zahnrädern, die alle in einem Kunststoffgehäuse eingeschlossen sind.

Während sich der Motor dreht, übertragen die Zahnräder diese Drehung auf die Räder unseres Rovers. Die Verwendung von Zahnrädern bietet einen entscheidenden Vorteil – sie erhöht das Drehmoment und ermöglicht es dem Motor, größere, schwerere Lasten zu bewegen.

.. image:: img/motor_internal.gif
    :align: center
    :width: 600

Ist es nicht faszinierend zu sehen, wie wissenschaftliche und technische Prinzipien zum Leben erwachen? Motoren sind ein perfektes Beispiel für diese Prinzipien in Aktion. Indem wir verstehen, wie Motoren funktionieren, können wir eine Vielzahl von Maschinen erträumen und erfinden. Tauchen wir tiefer in die Welt der Motoren ein und entfesseln wir unsere Kreativität!


**Schritt 2: Die Funktionsweise und den Betrieb von Motoren erkunden**

Nachdem wir verstanden haben, was ein Motor ist und welche breite Anwendungspalette er hat, ist es an der Zeit, uns ins Herz der Motoroperation zu begeben.

Im Wesentlichen arbeitet ein Motor nach dem Prinzip des Elektromagnetismus. Wenn ein elektrischer Strom durch einen Draht fließt, erzeugt er ein Magnetfeld um ihn herum. Dieses Magnetfeld kann mit anderen Magnetfeldern interagieren und Bewegung verursachen.

Betrachten Sie ein einfaches Experiment, bei dem wir einen Motor direkt an eine Batterie anschließen. Der Strom von der Batterie fließt in den Motor, löst den internen Mechanismus des Motors aus und lässt ihn sich drehen. Diese Drehbewegung entsteht durch die magnetischen Kräfte im Motor.

    .. image:: img/motor_battery.png

Interessanterweise dreht sich der Motor in die entgegengesetzte Richtung, wenn Sie die Anschlüsse an der Batterie umkehren! Dies geschieht, weil sich die Richtung des Stromflusses ändert, was die Richtung des Magnetfelds und folglich die Drehrichtung des Motors ändert.

Nun wissen wir, dass der Motor durch direkten Anschluss an eine Batterie gedreht werden kann, aber oft möchten wir seine Bewegung mit Code steuern, also schalten wir eine Arduino-Platine dazwischen. Was würde aber passieren, wenn wir versuchen würden, den Motor direkt an die Signalpins der Arduino-Platine anzuschließen?

.. image:: img/motor_uno.png
    :width: 600
    :align: center

Wenn Sie vermutet haben, dass der Motor sich nicht drehen würde, haben Sie recht! Aber warum ist das so?

Die Antwort liegt in der Stromabgabe der Arduino-Platine. Die Signalpins einer typischen Arduino-Platine können nur etwa 20 mA Strom ausgeben, was nicht ausreicht, um einen Motor anzutreiben.

Wie können wir also Motoren mit unserem Arduino steuern? Hier kommt eine entscheidende Komponente ins Spiel – ein Motortreiber. Stellen Sie sich einen Motortreiber als eine Brücke zwischen dem Arduino und dem Motor vor. Er nimmt das stromschwache Steuersignal vom Arduino, verstärkt es und sendet es an den Motor, wodurch der Motor sich drehen kann.

.. image:: img/motor_uno2.png

Im nächsten Schritt tauchen wir in die Details des Motortreibers ein und verstehen, wie wir ihn effektiv mit unserer Arduino-Platine einsetzen können, um einen Motor zu steuern. Bleiben Sie gespannt für weitere spannende Lerninhalte!


**Schritt 3: Wie der Motor durch den Motortreiber gesteuert wird**

Unser GalaxyRVR Shield, das im Bausatz enthalten ist, dient als Kontrollzentrum für unseren Mars Rover. Es ist die zentrale Schnittstelle, an die wir all unsere Sensoren, Motoren und die Stromversorgung anschließen. Es besteht aus mehreren Komponenten, die es uns ermöglichen, unseren Rover effektiv zu steuern und mit Strom zu versorgen.

Auf der rechten Seite des Shields sehen Sie sechs Motoranschlüsse. Sie sind jedoch in zwei Gruppen unterteilt, die jeweils von einem separaten Motortreiberchip gesteuert werden. Drei mit „Left" gekennzeichnete Anschlüsse werden von einem Chip gesteuert, die anderen drei mit „Right" gekennzeichneten Anschlüsse von einem anderen.

.. image:: img/motor_shield.png

Lassen Sie uns durch praktische Erfahrung lernen, wie diese beiden Treiberchips die sechs Motoren steuern:

* **1. Schaltungsaufbau**

    #. Stecken Sie das GalaxyRVR Shield auf die R3 Platine, schließen Sie einen Motor an und stecken Sie schließlich die Batterie ein, um die Erweiterungsplatine mit Strom zu versorgen.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/connect_shield.mp4" type="video/mp4">
                Ihr Browser unterstützt das Video-Tag nicht.
            </video>

    #. Bei der ersten Verwendung wird empfohlen, zuerst ein USB-C-Kabel anzuschließen, um die Batterie vollständig aufzuladen. Schalten Sie dann die Stromversorgung ein.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/plug_usbc.mp4" type="video/mp4">
                Ihr Browser unterstützt das Video-Tag nicht.
            </video>

* **2. Code schreiben und hochladen**

    #. Öffnen Sie die Arduino IDE und geben Sie den folgenden Code ein:

        .. code-block:: arduino

            void setup() {
                pinMode(2, OUTPUT);
                pinMode(3, OUTPUT);
            }

            void loop() {
                digitalWrite(2, LOW);
                digitalWrite(3, HIGH);
            }

        * ``pinMode()``: Diese Funktion setzt einen Pin als INPUT oder OUTPUT, ähnlich wie die Entscheidung, ob eine Figur in unserer Geschichte spricht (OUTPUT) oder zuhört (INPUT).
        * ``digitalWrite()``: Diese Funktion kann einen Pin auf HIGH (ein) oder LOW (aus) setzen, ähnlich wie das Ein- und Ausschalten eines magischen Lichts.

    #. Sobald Sie das richtige Board (Arduino Uno) und den richtigen Port ausgewählt haben, klicken Sie auf die Schaltfläche **Upload**. Es ist, als ob Sie einen Brief in den Briefkasten werfen – Sie senden Ihre Anweisungen an den Arduino!

        .. image:: img/motor_upload.png

    #. Nach erfolgreichem Hochladen des Codes werden Sie sehen, dass der Motor beginnt, sich im Uhrzeigersinn zu drehen.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/left_1.mp4" type="video/mp4">
                Ihr Browser unterstützt das Video-Tag nicht.
            </video>

* **3. Über die interne Schaltungsverbindung**

    #. Sie können zwei weitere Motoren in die mit „Left" gekennzeichneten Motoranschlüsse stecken. Sie werden sehen, dass sie sich gleichzeitig drehen.

    #. Nun wollen wir das einfache Prinzip verstehen, wie die beiden Treiberchips die sechs Motoren steuern. Die Pins 2 und 3 auf der Arduino-Platine geben Signale an den Motortreiberchip aus, und das andere Ende des Chips ist parallel mit drei Motoren verbunden. Ebenso geben die Pins 4 und 5 Signale an einen anderen Treiberchip aus, der wiederum parallel mit drei weiteren Motoren verbunden ist.

        .. image:: img/motor_driver.png
            :width: 500

    #. Wenn Sie einen anderen Treiberchip testen möchten, müssen Sie nur die Pins auf ``4`` und ``5`` ändern.

        .. code-block:: arduino
            :emphasize-lines: 10,11

            const int in3 = 4;
            const int in4 = 5;

            void setup() {
                pinMode(in3, OUTPUT);
                pinMode(in4, OUTPUT);
            }

            void loop() {
                digitalWrite(in3, LOW);
                digitalWrite(in4, HIGH);
            }

        Hier definieren wir zwei Variablen, um die Pins 4 und 5 darzustellen. Durch die Verwendung von Variablen können wir unsere Pin-Zuweisungen im gesamten Code einfach verwalten und anpassen.

        Stellen Sie es sich so vor, als ob wir jeder Pin-Nummer eine bestimmte Rolle oder Aufgabe zuweisen. Wenn wir die Rollen neu zuweisen möchten, aktualisieren wir einfach die Zuweisung am Anfang des Sketches (wo die Variable ursprünglich definiert wird), anstatt das gesamte Skript durchzugehen und jede Instanz zu ändern.


* **4. Über die Ansteuerlogik**

    #. Bei den vorherigen Tests ist Ihnen vielleicht aufgefallen, dass sich alle Motoren in eine Richtung drehen. Wie bringen wir sie dazu, sich in die entgegengesetzte Richtung zu drehen? Jemand könnte vorschlagen, die HIGH- und LOW-Werte der beiden Pins zu vertauschen. Das ist richtig.

        .. code-block:: arduino
            :emphasize-lines: 1,2

            const int in3 = 4;
            const int in4 = 5;

            void setup() {
                pinMode(in3, OUTPUT);
                pinMode(in4, OUTPUT);
            }

            void loop() {
                digitalWrite(in3, HIGH);
                digitalWrite(in4, LOW);
            }

        Sobald Sie Ihren Code geschrieben und auf Ihre Arduino-Platine hochgeladen haben, wird der Motor wie angewiesen reagieren.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/right_cc.mp4" type="video/mp4">
                Ihr Browser unterstützt das Video-Tag nicht.
            </video>

    #. Betrachten wir nun die interne Ansteuerlogik des Treiberchips.

        .. list-table::
            :widths: 25 25 50
            :header-rows: 1

            * - INA
              - INB
              - Motor
            * - L
              - L
              - Bereitschaft
            * - L
              - H
              - Im Uhrzeigersinn
            * - H
              - L
              - Gegen Uhrzeigersinn
            * - H
              - H
              - Bremse

    #. Versuchen wir nun, den Motor 2 Sekunden lang im Uhrzeigersinn, 2 Sekunden lang gegen den Uhrzeigersinn drehen zu lassen und ihn dann anzuhalten.

        .. code-block:: arduino
            :emphasize-lines: 10,11,12,13,14,15,16,17,18

            const int in3 = 4;
            const int in4 = 5;

            void setup() {
                pinMode(in3, OUTPUT);
                pinMode(in4, OUTPUT);
            }

            void loop() {
                digitalWrite(in3, LOW);
                digitalWrite(in4, HIGH);
                delay(2000);
                digitalWrite(in3, HIGH);
                digitalWrite(in4, LOW);
                delay(2000);
                digitalWrite(in3, HIGH);
                digitalWrite(in4, HIGH);
                delay(5000);
            }

        * Hier verwenden wir die Funktion ``delay()``, um den Arduino für eine bestimmte Zeit pausieren zu lassen, vergleichbar mit einem kurzen Nickerchen mitten in unserer Geschichte.
        * Im Code verwenden wir den Zustand „Bremse", um den Motor anzuhalten, und Sie werden feststellen, dass der Motor abrupt stoppt. Versuchen Sie, beide Pins auf LOW zu setzen, um den Zustand „Bereitschaft" zu testen. Sie werden feststellen, dass der Motor allmählich langsamer wird und schließlich stoppt.

Nachdem Sie nun besser verstehen sollten, wie der Motortreiberchip die Motoren über das GalaxyRVR Shield steuert und wie wir mit Arduino-Code die Bewegungen des Motors manipulieren können. Ist es nicht faszinierend, wie ein paar Zeilen Code das Verhalten eines physischen Objekts wie unseres Motors bestimmen können?

Denken Sie bei Ihrem Fortschritt über die folgenden Fragen nach:

* Wenn wir den gesamten Code aus der ``loop()``-Funktion in die ``setup()``-Funktion verschieben würden, wie würde sich das Verhalten des Motors ändern?
* Wie würden Sie den Code modifizieren, um sechs Motoren gleichzeitig zu steuern?

Denken Sie daran: Je mehr Sie experimentieren und mit Ihrem Code spielen, desto mehr lernen Sie. Fühlen Sie sich frei, Ihren Code nach Belieben anzupassen, zu modifizieren und zu optimieren. Viel Spaß beim Programmieren!


**Schritt 4: Die Motorgeschwindigkeit steuern**

Im vorherigen Schritt haben wir die Richtung des Motors gesteuert, indem wir seine Pins einfach auf HIGH oder LOW gesetzt haben.
Das ist, als würde man dem Motor volle Leistung geben, ähnlich wie das Durchdrücken des Gaspedals in einem Auto.
Aber in vielen Situationen möchten wir die Motorgeschwindigkeit an verschiedene Szenarien anpassen,
genau wie wir die Geschwindigkeit eines Autos anpassen, je nachdem, ob wir in der Stadt oder auf der Autobahn fahren.
Hier kommt die Pulsweitenmodulation (PWM) ins Spiel.

.. image:: img/motor_pwm.jpg

PWM ist eine Technik, die verwendet wird, um den Effekt einer variablen Ausgangsspannung zu erzeugen, indem der Ausgang schnell zwischen HIGH und LOW umgeschaltet wird.
Mit PWM können wir die Wirkung eines analogen Signals simulieren, während wir tatsächlich nur digitale Signale ausgeben.

Vielleicht finden Sie das schwer zu verstehen, und das ist in Ordnung! Wir werden in den folgenden Abschnitten lernen, wie man die Motorgeschwindigkeit mit PWM durch Programmierung anpasst.

Beachten Sie, dass die SunFounder R3 Platine zwar einige Pins mit integrierter PWM-Funktionalität hat, wir diese jedoch nicht für unseren Motor verwenden können, da sie bereits andere Funktionen erfüllen. Daher schließen wir die Treiberchips an die Pins 2, 3, 4 und 5 an und verwenden die SoftPWM-Bibliothek von Arduino, um PWM auf diesen Pins zu ermöglichen.

Hier ist, was wir als Nächstes tun werden:

#. Öffnen Sie die Arduino IDE, suchen Sie im **LIBRARY MANAGER** nach ``softpwm`` und installieren Sie es.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/install_softpwm.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

#. Geben Sie den folgenden Code in die Arduino IDE ein. Nach erfolgreichem Hochladen des Codes dreht sich der Motor im Uhrzeigersinn.

    .. code-block:: arduino
        :emphasize-lines: 1, 7,11,12

        #include <SoftPWM.h>

        const int in1 = 2;
        const int in2 = 3;

        void setup() {
            SoftPWMBegin();
        }

        void loop() {
            SoftPWMSet(in1, 0);
            SoftPWMSet(in2, 255);

        }

    * Im obigen Code fügen wir zuerst ``SoftPWM.h`` am Anfang des Codes hinzu, was es uns ermöglicht, die Funktionen der Bibliothek ``SoftPWM`` direkt zu verwenden.
    * Dann initialisieren wir die Bibliothek ``SoftPWM`` mit der Funktion ``SoftPWMBegin()``.
    * Schließlich verwenden wir in der ``loop()``-Funktion ``SoftPWMSet()``, um verschiedene Werte für ``in1`` und ``in2`` zuzuweisen und den Motor in Bewegung zu setzen. Sie werden feststellen, dass der Effekt ähnlich ist wie bei der direkten Verwendung von ``LOW`` und ``HIGH``, aber hier verwenden wir Zahlenwerte im Bereich von ``0~255``.
    * Denken Sie daran: In der Welt von Arduino wird Geschwindigkeit als ein Wert zwischen 0 (wie ein Auto an einem Stoppschild) und 255 (mit Vollgas auf der Autobahn!) ausgedrückt. Wenn wir also ``SoftPWMSet(in2, 255)`` sagen, sagen wir diesem Motor, er soll mit voller Geschwindigkeit vorausfahren!

#. Geben wir nun andere Werte ein und beobachten wir die Unterschiede in der Motorgeschwindigkeit.

    .. code-block:: arduino
        :emphasize-lines: 12,13,14,15

        #include <SoftPWM.h>

        const int in1 = 2;
        const int in2 = 3;

        void setup() {
            SoftPWMBegin();
        }

        void loop() {
            SoftPWMSet(in1, 0);
            for (int i = 0; i <= 255; i++) {
                SoftPWMSet(in2, i);
                delay(100);
        }
            delay(1000);
        }

    Im obigen Code verwenden wir eine ``for``-Schleife, um eine Variable ``i`` bis auf ``255`` zu erhöhen. Die ``for``-Schleife in der Sprache C wird verwendet, um einen Teil des Programms mehrmals zu durchlaufen. Sie besteht aus drei Teilen:

    .. image:: img/motor_for123.png
        :width: 400
        :align: center

    * **Initialisierung**: Dieser Schritt wird zuerst und nur einmal ausgeführt, wenn wir das erste Mal in die Schleife eintreten. Er ermöglicht es uns, alle Schleifenkontrollvariablen zu deklarieren und zu initialisieren.
    * **Bedingung**: Dies ist der nächste Schritt nach der Initialisierung. Wenn sie wahr ist, wird der Rumpf der Schleife ausgeführt. Wenn sie falsch ist, wird der Rumpf der Schleife nicht ausgeführt und der Kontrollfluss geht außerhalb der for-Schleife weiter.
    * **Inkrement oder Dekrement**: Nach der Ausführung der Initialisierungs- und Bedingungsschritte sowie des Schleifenrumpfcodes wird der Schritt Inkrement oder Dekrement ausgeführt. Diese Anweisung ermöglicht es uns, alle Schleifenkontrollvariablen zu aktualisieren.

    Das Flussdiagramm für die for-Schleife ist unten dargestellt:

    .. image:: img/motor_for.png

    Nachdem Sie den obigen Code ausgeführt haben, werden Sie sehen, dass die Motorgeschwindigkeit allmählich zunimmt. Sie hält für eine Sekunde an und beginnt dann wieder bei 0 und nimmt allmählich zu.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/left_speed.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

In diesem Schritt haben wir etwas über die Pulsweitenmodulation (PWM) gelernt, eine Technik zur Steuerung der Geschwindigkeit unseres Motors. Durch die Verwendung der SoftPWM-Bibliothek von Arduino können wir die Geschwindigkeit des Motors anpassen, sodass wir analoge Signale simulieren können, während wir nur digitale Signale ausgeben. Dies gibt uns eine feinere Kontrolle über die Bewegungen unseres Rovers und bereitet uns auf komplexere Manöver in der Zukunft vor.

**Schritt 5: Reflektieren und verbessern**

Nach Abschluss dieser Lektion sollten Sie nun mit den Arbeitsprinzipien von Motoren vertraut sein, sowie damit, wie man ihre Richtung und Geschwindigkeit durch Programmierung steuert.

Testen wir Ihr Verständnis mit diesen Herausforderungen:

* Wie würden Sie die for-Schleife modifizieren, um die Motorgeschwindigkeit allmählich zu verringern?
* Wie würden Sie den Motor steuern, um zu beschleunigen oder zu verlangsamen, während er sich gegen den Uhrzeigersinn dreht?

Sie können mit dem bereitgestellten Code experimentieren, um diese Fragen zu beantworten. Passen Sie den Code nach Ihren Hypothesen an und beobachten Sie die Veränderungen im Verhalten des Motors.

Ihre praktischen Experimente und Überlegungen zu diesen Fragen werden Ihr Verständnis vertiefen und Ihre Problemlösungsfähigkeiten verbessern. Durch solche Herausforderungen findet wirkliches Lernen statt. Denken Sie immer daran: Auf Ihrer Entdeckungsreise gibt es kein „Richtig" oder „Falsch" – es geht um Lernen und Entdecken!

