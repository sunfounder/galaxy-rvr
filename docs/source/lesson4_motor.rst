.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Lektion 4: Beherrschung des TT-Motors
===========================================

In den vorherigen Lektionen haben wir Mars-Rover, ihre Federungssysteme erkundet und uns in das Wissen über Arduino vertieft.

In diesem spannenden Kurs werden wir die Funktionsweise von Motoren erforschen, einer Schlüsselkomponente, die Mars-Rover antreibt.
Wir werden die Prinzipien verstehen, die diese Motoren antreiben, und lernen, sie mit Hilfe eines SunFounder R3-Boards und einem GalaxyRVR-Shield zu steuern.

Am Ende dieses Kurses wirst du ein solides Verständnis für den Betrieb von Motoren und praktische Erfahrung in der Motorsteuerung haben.

Lass uns eintauchen!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/left_1.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>

.. note::

    Wenn du diesen Kurs nach dem vollständigen Zusammenbau des GalaxyRVR lernst, musst du diesen Schalter vor dem Hochladen des Codes nach rechts bewegen.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Kursziele
----------------------
* Verstehe die grundlegenden Prinzipien von Motoren und die Eigenschaften des TT-Motors.
* Lerne, wie man die Richtung und Geschwindigkeit des TT-Motors steuert.
* Verstehe, wie das GalaxyRVR-Shield sechs Motoren steuert.


Kursmaterialien
-----------------------

* SunFounder R3-Board
* TT-Motor
* GalaxyRVR-Shield
* Batterie
* USB-Kabel
* Arduino IDE
* Computer

Kursschritte
------------------

**Schritt 1: Was ist ein Motor?**

Motoren spielen eine integrale Rolle in unserem täglichen Leben. Sie sind überall! Von den elektrischen Ventilatoren, die uns an heißen Tagen kühlen, den Mixern, die uns helfen, köstliche Kuchen zu backen, bis hin zu den Elektroautos, die auf den Straßen vorbeiflitzen – Motoren bringen Dinge in Bewegung!

.. image:: img/motor_application.jpg

Ein Motor ist wie das Herz einer Maschine. Er wandelt elektrische Energie in mechanische Energie um und bringt so unsere Spielzeuge, Haushaltsgeräte und sogar große Fahrzeuge zum Leben!


Die Magie hinter einem Motor ist gar keine Magie – es ist Wissenschaft, genauer gesagt das Prinzip der elektromagnetischen Induktion. So funktioniert es: Wenn Strom einem Motor zugeführt wird, erzeugt er ein Magnetfeld. Dieses Magnetfeld interagiert dann mit anderen Magneten innerhalb des Motors, wodurch der Motor sich zu drehen beginnt. Diese Drehung, wie das Drehen eines Kreisels, kann dann verwendet werden, um Räder, Propeller oder andere bewegliche Teile einer Maschine zu bewegen.

.. image:: img/motor_rotate.gif
    :align: center

Der Typ des Motors, auf den wir uns in unserem GalaxyRVR konzentrieren, ist eine spezifische Art namens TT-Getriebemotor.

.. image:: img/tt_motor_xh.jpg
    :align: center
    :width: 400

Dies ist im Wesentlichen ein normaler Motor, kombiniert mit einer Reihe von Zahnrädern, die alle in einem Kunststoffgehäuse eingeschlossen sind.

Während sich der Motor dreht, übersetzen die Zahnräder diese Drehung auf die Räder unseres Rovers. Der Einsatz von Zahnrädern bietet einen entscheidenden Vorteil - er erhöht das Drehmoment und ermöglicht es dem Motor, größere, schwerere Lasten zu bewegen.

.. image:: img/motor_internal.gif
    :align: center
    :width: 600

Ist es nicht faszinierend zu sehen, wie Wissenschafts- und Ingenieursprinzipien zum Leben erwachen? Motoren sind ein perfektes Beispiel für diese Prinzipien in Aktion. Indem wir verstehen, wie Motoren funktionieren, können wir uns eine Vielzahl von Maschinen ausdenken und erfinden. Lass uns tiefer in die Welt der Motoren eintauchen und unsere Kreativität entfesseln!



**Schritt 2: Erforschung der Funktionsweise und des Betriebs von Motoren**

Nachdem wir verstanden haben, was ein Motor ist und sein breites Spektrum an Anwendungen kennen, wird es Zeit, uns in das Herz des Motorbetriebs zu begeben.

Im Wesentlichen funktioniert ein Motor nach dem Prinzip des Elektromagnetismus. Wenn ein elektrischer Strom durch einen Draht fließt, erzeugt er ein Magnetfeld um sich herum. Dieses Magnetfeld kann mit anderen Magnetfeldern interagieren und Bewegung verursachen.

Betrachten wir ein einfaches Experiment, bei dem wir einen Motor direkt an eine Batterie anschließen. Der Strom aus der Batterie fließt in den Motor und löst den internen Mechanismus des Motors aus, der zu drehen beginnt. Diese Drehbewegung ist auf die magnetischen Kräfte im Inneren des Motors zurückzuführen.

    .. image:: img/motor_battery.png

Interessanterweise dreht sich der Motor in die entgegengesetzte Richtung, wenn Sie die Anschlüsse an der Batterie umkehren! Dies geschieht, weil sich die Richtung des Stromflusses ändert, was wiederum die Richtung des Magnetfelds und somit die Drehrichtung des Motors ändert.

Nun wissen wir, dass der Anschluss des Motors direkt an eine Batterie ihn zum Drehen bringen kann, aber oft möchten wir seine Bewegung mit Code steuern, also schließen wir ein Arduino-Board dazwischen an. Aber was würde passieren, wenn wir versuchen, den Motor direkt an die Signalpins auf dem Arduino-Board anzuschließen?

.. image:: img/motor_uno.png
    :width: 600
    :align: center

Wenn Sie erraten haben, dass sich der Motor nicht drehen würde, liegen Sie richtig! Aber warum ist das so?

Die Antwort liegt im Stromausgang des Arduino-Boards. Die Signalpins auf einem typischen Arduino-Board können nur etwa 20 mA Strom ausgeben, was nicht ausreicht, um einen Motor anzutreiben.

Wie können wir also Motoren mit unserem Arduino steuern? Hier kommt eine entscheidende Komponente ins Spiel - ein Motor-Treiber. Denken Sie an einen Motor-Treiber als eine Brücke zwischen dem Arduino und dem Motor. Er nimmt das schwache Steuersignal des Arduino auf, verstärkt es und leitet es an den Motor weiter, wodurch der Motor sich zu drehen beginnt.

.. image:: img/motor_uno2.png

Im nächsten Schritt werden wir uns mit den Einzelheiten des Motor-Treibers befassen und verstehen, wie wir ihn effektiv mit unserem Arduino-Board verwenden können, um einen Motor zu steuern. Bleiben Sie dran für weiteres spannendes Lernen!


**Schritt 3: Wie der Motor durch den Motor-Treiber gesteuert wird**

Unser GalaxyRVR-Shield, das im Kit enthalten ist, dient als Kontrollzentrum für unseren Mars-Rover. Es ist der Hub, an den wir alle unsere Sensoren, Motoren und die Stromversorgung anschließen. Es besteht aus mehreren Komponenten, die es uns ermöglichen, unseren Rover effektiv zu steuern und mit Strom zu versorgen.

Auf der rechten Seite des Shields finden Sie sechs Motoranschlüsse. Diese sind jedoch in zwei Gruppen unterteilt, die jeweils von einem separaten Motor-Treiber-Chip gesteuert werden. Drei Anschlüsse, die mit „Links“ gekennzeichnet sind, werden von einem Chip gesteuert, und die anderen drei Anschlüsse, die mit „Rechts“ gekennzeichnet sind, werden von einem anderen gesteuert.

.. image:: img/motor_shield.png

Lernen wir, wie diese beiden Treiber-Chips die sechs Motoren steuern, durch praktische Erfahrung:

* **1. Verbinden des Schaltkreises**

    #. Stecken Sie das GalaxyRVR-Shield in das R3-Board, schließen Sie einen Motor an und stecken Sie schließlich den Akku ein, um das Erweiterungsboard mit Strom zu versorgen.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/connect_shield.mp4" type="video/mp4">
                Ihr Browser unterstützt das Video-Tag nicht.
            </video>

    #. Beim ersten Gebrauch wird empfohlen, zuerst ein Type-C USB-Kabel anzuschließen, um den Akku vollständig aufzuladen. Schalten Sie dann den Strom ein.
    
        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/plug_usbc.mp4" type="video/mp4">
                Ihr Browser unterstützt das Video-Tag nicht.
            </video>

* **2. Code schreiben und hochladen**

    #. Öffne die Arduino IDE und gib den folgenden Code ein:

        .. code-block:: arduino

            void setup() {
                pinMode(2, OUTPUT);
                pinMode(3, OUTPUT);
            }

            void loop() {
                digitalWrite(2, LOW);
                digitalWrite(3, HIGH);
            }
    
        * ``pinMode()``: Diese Funktion setzt einen Pin als EINGANG oder AUSGANG, vergleichbar mit der Entscheidung, ob eine Figur in unserer Geschichte spricht (OUTPUT) oder zuhört (INPUT).
        * ``digitalWrite()``: Mit dieser Funktion kann ein Pin auf HIGH (on) oder LOW (off) gesetzt werden, ähnlich dem Ein- und Ausschalten eines magischen Lichts.

    #. Nachdem du das richtige Board (Arduino Uno) und den Port ausgewählt hast, klicke auf den **Upload**-Button. Es ist, als würdest du einen Brief in einen Briefkasten legen - du schickst deine Anweisungen an Arduino!

        .. image:: img/motor_upload.png
        
    #. Sobald der Code erfolgreich hochgeladen wurde, siehst du, wie sich der Motor im Uhrzeigersinn zu drehen beginnt.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/left_1.mp4" type="video/mp4">
                Ihr Browser unterstützt das Video-Tag nicht.
            </video>
    
* **3. Über den internen Schaltungsaufbau**

    #. Du kannst zwei weitere Motoren in die mit „Links“ gekennzeichneten Motoranschlüsse stecken. Du wirst sehen, dass sie sich gleichzeitig drehen.

    #. Jetzt verstehen wir das einfache Prinzip, wie die beiden Treiber-Chips die sechs Motoren steuern. Pins 2 und 3 auf dem Arduino-Board geben Signale an den Motor-Treiber-Chip aus, und das andere Ende des Chips ist parallel mit drei Motoren verbunden. Ähnlich geben die Pins 4 und 5 Signale an einen anderen Treiber-Chip aus, der wiederum parallel mit drei weiteren Motoren verbunden ist.

        .. image:: img/motor_driver.png
            :width: 500

    #. Wenn du einen anderen Treiber-Chip testen möchtest, musst du nur die Pins auf ``4`` und ``5`` ändern.

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

        Hier definieren wir zwei Variablen, um die Pins 4 und 5 zu repräsentieren. Durch die Verwendung von Variablen können wir unsere Pin-Zuweisungen im gesamten Code leicht verwalten und anpassen.

        Denk daran, als ob wir jeder Pin-Nummer eine spezifische Rolle oder Aufgabe zuweisen. Wenn wir uns entscheiden, die Rollen neu zuzuweisen, müssen wir anstatt das gesamte Skript zu durchlaufen und jede Instanz zu ändern, lediglich die Zuweisung am Anfang des Skripts aktualisieren (wo die Variable zuerst definiert wird).


* **4. Über die Antriebslogik**

    #. In den vorherigen Tests haben Sie vielleicht bemerkt, dass sich die Motoren alle in eine Richtung drehen. Wie lassen wir sie in die entgegengesetzte Richtung drehen? Jemand könnte vorschlagen, die Zustände HIGH und LOW der beiden Pins zu tauschen. Das ist korrekt.

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

        Sobald Sie Ihren Code geschrieben und auf Ihr Arduino-Board hochgeladen haben, wird sich der Motor entsprechend verhalten.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/right_cc.mp4" type="video/mp4">
                Ihr Browser unterstützt das Video-Tag nicht.
            </video>

    #. Schauen wir uns jetzt die interne Antriebslogik des Treiberchips an.

        .. list-table::
            :widths: 25 25 50
            :header-rows: 1

            * - INA
              - INB
              - Motor
            * - L
              - L
              - Standby
            * - L
              - H
              - Im Uhrzeigersinn
            * - H
              - L
              - Gegen den Uhrzeigersinn
            * - H
              - H
              - Bremse
    
    #. Versuchen wir jetzt, den Motor 2 Sekunden lang im Uhrzeigersinn, 2 Sekunden lang gegen den Uhrzeigersinn drehen zu lassen und dann anzuhalten.

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

        * Hier verwenden wir die Funktion ``delay()``, um Arduino eine gewisse Zeit pausieren zu lassen, ähnlich einer kurzen Ruhepause in unserer Geschichte.
        * Im Code verwenden wir den Zustand „Brake“ zum Anhalten des Motors, und Sie werden bemerken, dass der Motor abrupt stoppt. Versuchen Sie, beide Pins auf LOW zu setzen, um den Zustand "Standby" zu testen, und Sie werden feststellen, dass der Motor allmählich langsamer wird, bis er stoppt.

Nun solltest du ein besseres Verständnis davon haben, wie der Motor-Treiber-Chip die Motoren über das GalaxyRVR-Shield steuert und wie wir Arduino-Code verwenden können, um die Bewegungen des Motors zu beeinflussen. Ist es nicht faszinierend, wie ein paar Zeilen Code das Verhalten eines physischen Objekts wie unseres Motors bestimmen können?

Betrachte folgende Fragen, während du weitermachst:

* Wenn wir den gesamten Code aus der Funktion ``loop()`` in die Funktion ``setup()`` verschieben, wie würde sich das Verhalten des Motors ändern?
* Wie würdest du den Code ändern, um sechs Motoren gleichzeitig zu steuern?

Denk daran, je mehr du mit deinem Code experimentierst und spielst, desto mehr lernst du. Fühle dich frei, deinen Code nach Belieben anzupassen, zu modifizieren und zu optimieren. Viel Spaß beim Programmieren!


**Schritt 4: Steuerung der Motorgeschwindigkeit**

Im vorherigen Schritt haben wir die Richtung des Motors gesteuert, indem wir seine Pins einfach auf HIGH oder LOW gesetzt haben.
Das ist so, als würden wir dem Motor volle Leistung geben, ähnlich wie wenn wir das Gaspedal in einem Auto durchtreten.
In vielen Situationen möchten wir jedoch die Motorgeschwindigkeit an unterschiedliche Szenarien anpassen,
genau wie wir die Geschwindigkeit eines Autos anpassen, je nachdem, ob wir in der Stadt oder auf der Autobahn fahren.
Hier kommt die Pulsweitenmodulation (PWM) ins Spiel.

.. image:: img/motor_pwm.jpg

PWM ist eine Technik, die verwendet wird, um den Effekt einer variablen Spannungsausgabe zu erzeugen, indem der Ausgang schnell zwischen HIGH und LOW geschaltet wird.
Mit PWM können wir den Effekt eines analogen Signals simulieren, während wir tatsächlich nur digitale Signale ausgeben.

Du findest das vielleicht schwer zu verstehen, und das ist in Ordnung! Wir werden im Folgenden lernen, wie man die Motorgeschwindigkeit durch Programmierung mit PWM anpasst.

Beachte, dass das SunFounder R3-Board einige Pins mit eingebauter PWM-Funktionalität hat, diese können wir aber für unseren Motor nicht verwenden, da sie bereits andere Funktionen erfüllen. Daher verbinden wir die Treiberchips mit den Pins 2, 3, 4 und 5 und verwenden die SoftPWM-Bibliothek von Arduino, um PWM auf diesen Pins zu ermöglichen.

Das werden wir als Nächstes tun:

#. Öffne die Arduino IDE, suche in der **LIBRARY MANAGER** nach ``softpwm`` und installiere sie.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

#. Gib den folgenden Code in die Arduino IDE ein. Nach dem erfolgreichen Hochladen des Codes wird sich der Motor im Uhrzeigersinn drehen.

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

    * Im obigen Code fügen wir zuerst ``SoftPWM.h`` oben im Code hinzu, um die Funktionen in der ``SoftPWM``-Bibliothek direkt nutzen zu können.
    * Dann initialisieren wir die ``SoftPWM``-Bibliothek mit der Funktion ``SoftPWMBegin()``.
    * Schließlich verwenden wir in der Funktion ``loop()`` ``SoftPWMSet()``, um verschiedenen Werten an ``in1`` und ``in2`` zuzuweisen, was den Motor in Bewegung setzt. Du wirst bemerken, dass der Effekt dem direkten Einsatz von ``LOW`` und ``HIGH`` ähnelt, aber hier verwenden wir numerische Werte im Bereich von ``0~255``.
    * Denke daran, in der Welt von Arduino wird Geschwindigkeit als ein Wert zwischen 0 (wie ein Auto an einem Stoppschild) und 255 (rasend auf der Autobahn!) ausgedrückt. Wenn wir also sagen ``SoftPWMSet(in2, 255)``, sagen wir dem Motor, dass er Vollgas geben soll!

#. Jetzt geben wir andere Werte ein und beobachten, ob sich die Motorgeschwindigkeit ändert.

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
    
    Im obigen Code verwenden wir eine ``for``-Schleife, um eine Variable ``i`` bis ``255`` zu erhöhen. Die ``for``-Schleife in der C-Sprache wird verwendet, um einen Teil des Programms mehrmals zu iterieren. Sie besteht aus drei Teilen:

    .. image:: img/motor_for123.png
        :width: 400
        :align: center

    * **Initialization**: Dieser Schritt wird zuerst und nur einmal ausgeführt, wenn wir das erste Mal in die Schleife eintreten. Er ermöglicht es uns, jegliche Schleifensteuerungsvariablen zu deklarieren und zu initialisieren.
    * **Condition**: Dies ist der nächste Schritt nach der Initialisierung. Ist sie wahr, wird der Schleifenkörper ausgeführt. Ist sie falsch, wird der Schleifenkörper nicht ausgeführt und die Steuerung des Flusses verlässt die for-Schleife.
    * **Increment or Decrement**: Nach Ausführung der Schritte Initialisierung und Bedingung sowie des Schleifenkörper-Codes wird der Schritt Inkrement oder Dekrement ausgeführt. Diese Anweisung ermöglicht es uns, jegliche Schleifensteuerungsvariablen zu aktualisieren.
    
    Das Flussdiagramm für die for-Schleife wird unten gezeigt:

    .. image:: img/motor_for.png

    Nach dem Ausführen des obigen Codes wirst du sehen, dass die Motorgeschwindigkeit allmählich zunimmt. Er hält für eine Sekunde an und beginnt dann wieder von 0 und steigt allmählich an.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/left_speed.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

In diesem Schritt haben wir die Pulsweitenmodulation (PWM) kennengelernt, eine Technik zur Steuerung der Geschwindigkeit unseres Motors. Durch die Verwendung der SoftPWM-Bibliothek von Arduino können wir die Geschwindigkeit des Motors anpassen, was uns ermöglicht, analoge Signale zu simulieren, während wir nur digitale Signale ausgeben. Dies bietet uns eine feinere Kontrolle über die Bewegungen unseres Rovers und bereitet uns auf komplexere Manöver in der Zukunft vor.

**Schritt 5: Reflektieren und Verbessern**

Nachdem du diese Lektion abgeschlossen hast, solltest du nun mit den Arbeitsprinzipien von Motoren vertraut sein, sowie damit, wie man ihre Richtung und Geschwindigkeit durch Programmierung steuert.

Teste dein Verständnis mit diesen Herausforderungen:

* Wie würdest du die for-Schleife ändern, um die Motorgeschwindigkeit allmählich zu verringern?
* Wie würdest du den Motor so steuern, dass er beim Drehen gegen den Uhrzeigersinn beschleunigt oder verlangsamt?

Du kannst mit dem bereitgestellten Code experimentieren, um diese Fragen zu beantworten. Fühle dich frei, den Code entsprechend deinen Hypothesen anzupassen und beobachte die Veränderungen im Verhalten des Motors.

Deine praktischen Experimente und Reflexionen über diese Fragen werden dein Verständnis vertiefen und deine Problemlösungsfähigkeiten verbessern. Es ist durch Herausforderungen wie diese, dass echtes Lernen stattfindet. Denke immer daran, es gibt kein „richtig“ oder „falsch“ auf deiner Entdeckungsreise – es geht alles um Lernen und Entdecken!


