.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Lektion 12: Steuerung des Rovers mit der App
============================================

In unserem letzten Abenteuer haben wir gelernt, mit dem SunFounder Controller nicht nur die Welt durch die Augen des Rovers zu erkunden, sondern auch seinen Blick durch Steuerung des Neigungsmechanismus anzupassen. Es war, als hätten wir unserem Mars-Rover das Sehen beigebracht!

Stellen Sie sich nun vor, Sie könnten diesen Mars-Erkunder auch steuern und seinen Weg nach Belieben lenken. In dieser Lektion werden wir genau das tun! Wir vertiefen unser Verständnis des SunFounder Controllers und lernen, unseren Rover zu manövrieren, was uns das aufregende Erlebnis eines Mars-Rover-Fahrers bietet!

Mit unserem lebendigen und anschaulichen STEAM-Kurs werden Kinder nicht nur lernen; sie erleben die Spannung und das Wunder der Raumfahrt! Schnallen Sie sich an und bereiten Sie sich auf eine spannende Reise vor!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/camera_app.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>

Kursziele
-----------------------

* Vertiefung des Verständnisses des SunFounder Controllers.
* Erlernen der Steuerung des Mars-Rovers mittels der mobilen App.

Kursmaterialien
------------------------

* Mars-Rover-Modell (mit allen Komponenten, außer Solarpanel und Bodenplatte)
* Arduino IDE
* Computer
* Tablet oder Smartphone mit installierter SunFounder Controller-App

Kursschritte
----------------------

**Schritt 1: Vertiefung in den SunFounder Controller**

In unserer letzten Lektion haben wir erste Einblicke in den SunFounder Controller, seine grundlegenden Funktionen und Anwendungen erhalten. Aber sicherlich haben Sie noch einige brennende Fragen, richtig? Zeit, diese Neugier zu stillen und tiefer in dieses technologische Wunder einzutauchen.

Beim Erstellen eines neuen Controllers werden Sie zunächst mit einem Bildschirm konfrontiert, der anfangs wie ein Rätsel erscheinen mag.

.. image:: img/app/app_blank.png

Sie sehen eine Vielfalt von Formen: lange Rechtecke, kurze Rechtecke und große Quadrate, jedes einzigartig mit Kennzeichnungen von A bis Q versehen.

Haben Sie sich jemals gefragt, warum diese Vielfalt? Was bedeuten die Kennzeichnungen von A bis Q?

Begeben wir uns auf diese Entdeckungsreise!

* **Entschlüsselung der Formen**

    Tippen Sie beispielsweise auf ein langes Rechteck. Wie das Öffnen einer Schatztruhe werden mehrere Widgets enthüllt. Erinnern Sie sich an den **Slider** aus unserem letzten Unterricht? Durch Wischen nach links oder rechts wurde die Neigung der Mars-Rover-Kamera gesteuert. Dann gibt es das **Gauge**, das als Tachometer Ihres Rovers dienen kann. Und eine Vielzahl anderer Widgets!

    .. image:: img/app/app_long.png

    Tippen Sie auf das kürzere Rechteck, und es zeigt eine andere Gruppe von Widgets. Das **Button**-Widget, ähnlich einem binären Schalter, gibt einzelne Befehle aus, während das **Microphone**-Widget Ihre Sprachbefehle zum Steuern des Rovers hören kann, unter anderen Widgets.

    .. image:: img/app/app_short.png

    Und der quadratische Block? Er beherbergt das **Joystick**-Widget, das D-Pad-Widget und das Gashebel-Widget. Und ja, es gibt noch mehr!

    .. image:: img/app/app_square.png

    Keine Sorge um die Funktion oder Anwendung jedes Widgets zu diesem Zeitpunkt. Machen Sie sich erst einmal mit den Widgets vertraut, die in jeder Form enthalten sind.


* **Nutzung der Widgets**

    Durch den oben genannten Inhalt wissen wir, dass es viele verschiedene Widgets gibt. Wofür können diese Widgets also verwendet werden?

    Wir kategorisieren diese Widgets in zwei Typen: Steuerungs-Widgets und Anzeige-Widgets.

    * **Steuerungs-Widgets** ermöglichen es Ihnen, die App zu manipulieren, woraufhin der Mars-Rover diese Steuerbefehle empfängt und entsprechende Aktionen ausführt.
    * **Anzeige-Widgets** erlauben es Ihnen, bestimmte Werte in der App anzuzeigen, wie zum Beispiel Sensordaten.

    Für eine detaillierte Beschreibung dieser Widgets, siehe bitte: |link_widgets_list|.

    Für Funktionen, Parameter usw., die mit diesen Widgets zusammenhängen, siehe bitte: |link_ai_camera_library_api|.

* **Die Rolle der Kennzeichner**

    Jede Form trägt einen Kennzeichner in der unteren rechten Ecke. Warum, fragen Sie? Verstehen wir das anhand eines Beispiels.

    In unserer letzten Klasse haben wir ein **Slider**-Widget im Bereich **D** hinzugefügt. Der Code, um dessen Wert zu erhalten, sah in etwa so aus:

        .. code-block:: arduino

            int16_t sliderD = aiCam.getSlider(REGION_D);
        
    Was, wenn wir ein **Slider**-Widget im Bereich **B** hinzugefügt hätten? Wie würde sich der Code ändern? So einfach, wie ``REGION_D`` durch ``REGION_B`` zu ersetzen.

        .. code-block:: arduino

            int16_t sliderD = aiCam.getSlider(REGION_B);

    Einfach, richtig? Diese Kennzeichner helfen dabei, zu erkennen, welches Widget Sie in welchem Bereich hinzugefügt haben.


.. note::
    * Detaillierte Anweisungen zum Erstellen und Hinzufügen von Widgets sowie zum Verbinden und Bedienen des SunFounder Controllers finden Sie in ``Schritt 3`` von ``Lektion 11``.
    * Für tiefgreifendere Operationen besuchen Sie bitte |link_sc_page|.

**Schritt 2: Steuerung des Mars-Rovers mit Dual-Throttles**

Jetzt, da wir uns eingehend mit den SunFounder Controller Widgets beschäftigt haben, steigern wir unser Spiel, indem wir zwei Drosselklappen-Widgets verwenden, um die Bewegung des Mars-Rovers zu steuern.

#. Platzieren Sie je ein **Throttle**-Widget in den Bereichen **K** und **Q**. Sie müssen oben rechts auf die Schaltfläche |app_edit| klicken, um in den Bearbeitungsmodus zu wechseln, und nachdem Sie alles eingerichtet haben, klicken Sie auf |app_save|, um Ihre Änderungen zu speichern.

    .. image:: img/app/app_throttle.png

#. Da wir zwei **Throttle**-Widgets zur Steuerung der Mobilität des Rovers verwenden wollen, passen wir die Funktion, die die Bewegungen des Rovers steuert, entsprechend an:


    .. code-block:: arduino

        // Function to set the power of the motors
        void carSetMotors(int8_t power_L, int8_t power_R) {
            // Set power for the left motor
            if (power_L >= 0) {
                SoftPWMSet(in1, map(power_L, 0, 100, 0, 255));
                SoftPWMSet(in2, 0);
            } else {
                SoftPWMSet(in1, 0);
                SoftPWMSet(in2, map(power_L, 0, -100, 0, 255));
            }

            // Set power for the right motor
            if (power_R >= 0) {
                SoftPWMSet(in3, 0);
                SoftPWMSet(in4, map(power_R, 0, 100, 0, 255));
            } else {
                SoftPWMSet(in3, map(power_R, 0, -100, 0, 255));
                SoftPWMSet(in4, 0);
            }
        }

    Natürlich, lassen Sie uns die Funktion ``carSetMotors()`` genauer betrachten. Diese Funktion nimmt zwei Argumente entgegen, ``power_L`` und ``power_R``, die wahrscheinlich die Leistungseinstellungen für die linken und rechten Motoren sind. Die Werte dieser Argumente liegen vermutlich zwischen -100 und 100, wobei negative Werte Rückwärtsbewegung anzeigen, 0 einen Stopp bedeutet und positive Werte Vorwärtsbewegung signalisieren.

    * Leistungseinstellung für den linken Motor:

        * Wenn ``power_L`` größer oder gleich 0 ist, wird der linke Motor auf Vorwärtsbewegung eingestellt. 

        * ``SoftPWMSet(in1, map(power_L, 0, 100, 0, 255))`` verwendet die Arduino-Funktion ``map``, um den Eingabebereich (0 bis 100) auf den Ausgabebereich (0 bis 255) abzubilden - dies liegt daran, dass die PWM-Werte in Arduino zwischen 0 (0 % Tastverhältnis) und 255 (100 % Tastverhältnis) liegen. Dieser abgebildete Wert wird dann zusammen mit ``in1`` an die Funktion ``SoftPWMSet`` übergeben.

        * Wenn ``power_L`` kleiner als 0 ist, wird der linke Motor auf Rückwärtsbewegung eingestellt, und der Eingabebereich für die Funktion ``map`` ist jetzt 0 bis -100.

    * Leistungseinstellung für den rechten Motor:

        * Dies folgt der gleichen Logik wie das Einstellen der Leistung für den linken Motor, aber benutzt stattdessen ``in3`` und ``in4``, und die Werte für die Eingangsleistung sind ``power_R`` anstelle von ``power_L``.

    Insgesamt nimmt diese Funktion zwei Motorleistungswerte, wandelt sie in die entsprechenden PWM-Werte um und setzt die PWM-Werte auf den richtigen Motorsteuerungspins, um die gewünschte Bewegung zu erreichen.

#. Innerhalb der Funktion ``onReceive()`` holen Sie die Werte von den beiden **Throttle**-Widgets ab und verwenden sie als Leistung für die linken und rechten Motoren des Mars-Rovers.

    .. code-block:: arduino
        :emphasize-lines: 9,10,13

        void onReceive() {
            // Get the value of the slider in region D
            int16_t sliderD = aiCam.getSlider(REGION_D);

            // Move the servo to the angle indicated by the slider
            myServo.write(int(sliderD));

            // Get the throttle values for the left and right
            int throttle_L = aiCam.getThrottle(REGION_K);
            int throttle_R = aiCam.getThrottle(REGION_Q);

            // Set the power for the motors
            carSetMotors(throttle_L, throttle_R);
        }

Hier ist der vollständige Code:

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c70d2598-a1f9-465a-83bb-4ebd38eb74fa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Jedes Mal, wenn Sie den Code erneut ausführen, müssen Sie die folgenden vier Schritte wiederholen:

* Vor dem Hochladen des Codes stellen Sie sicher, dass der Schalter nach rechts gedreht ist.

    .. image:: img/camera_upload.png

* Nachdem der Code erfolgreich hochgeladen wurde, schalten Sie auf die linke Seite, um die ESP32 CAM zu starten.
* Verbinden Sie sich mit dem Netzwerk ``GalaxyRVR``.
* Verbinden Sie sich und führen Sie den Controller aus.

Nun können Sie mit einer einfachen Bewegung Ihres Daumens auf den ``Throttle``-Widgets den Mars-Rover in Aktion sehen, wie er mit erneuertem Geist an Kraft gewinnt und sich dreht. Lasst die Erkundung beginnen!

**Schritt 3: Visualisierung von Sensorwerten**

Auf unserer Reise mit dem SunFounder Controller haben wir aktiv mit unserem Mars-Rover interagiert, unter anderem durch Steuerungs-Widgets wie Schieberegler zur Neigungsanpassung und Drosselklappen zur Bewegungssteuerung des Rovers. Aber wie steht es mit der Nutzung von Anzeige-Widgets, um ein lebendiges Bild von der Umgebung unseres Rovers zu zeichnen?

Lassen Sie uns sehen, wie wir dies umsetzen können, indem wir die Werte von den linken und rechten Infrarot (IR)-Vermeidungsmodulen und die vom Ultraschallmodul erfasste Entfernung visualisieren. Diese Echtzeitdaten geben uns ein klares Bild von der Betriebsumgebung des Rovers.

So können wir das erreichen:

#. Beginnen Sie damit, drei Nummern-Widgets zu Ihrem SunFounder Controller hinzuzufügen. Vergessen Sie nicht, Sie können deren Namen und Einheiten mit dem Einstellungsbutton personalisieren.

    .. image:: img/app/app_show.png

#. Als Nächstes tauchen wir in den Code ein. Starten Sie, indem Sie die Code-Schnipsel für die IR-Vermeidungsmodule und das Ultraschallmodul aus unseren vorherigen Lektionen übernehmen.

    .. code-block:: arduino

        ...
        // Define the pin for the ultrasonic module
        #define ULTRASONIC_PIN 10

        // Define the pins for the IR modules
        #define IR_RIGHT 7
        #define IR_LEFT 8

        void setup() {
            ...

            // Set the IR module pins as inputs
            pinMode(IR_RIGHT, INPUT);
            pinMode(IR_LEFT, INPUT);
        }


        float readSensorData() {
            // A 4ms delay is required, otherwise the reading may be 0
            delay(4);

            //Set to OUTPUT to send signal
            pinMode(ULTRASONIC_PIN, OUTPUT);

            ...
        }


#. In der Funktion ``onReceive()`` extrahieren Sie die Werte aus den Vermeidungsmodulen und dem Ultraschallsensor. Aktualisieren Sie anschließend diese Werte im Wörterbuch ``sendDoc[]``. Die Schlüssel ``N``, ``P`` und ``O`` entsprechen den Regionscodes der drei hinzugefügten Nummern-Widgets.

    .. code-block:: arduino

        // Function to execute when data is received from the Controller
        void onReceive() {

            ...

            // Read values from IR sensors
            int leftValue = digitalRead(IR_LEFT);
            int rightValue = digitalRead(IR_RIGHT);
            aiCam.sendDoc["N"] = leftValue;
            aiCam.sendDoc["P"] = rightValue;
            
            // ultrasonic
            float distance = readSensorData();
            aiCam.sendDoc["O"] = distance;
        }

Hier ist der vollständige Code:

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6c867007-a0e8-4f85-980d-ec1cd1a70969/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, starten Sie Ihren SunFounder Controller. Sie werden mit den Echtzeitwerten der Vermeidungsmodule und der vom Ultraschallsensor erfassten Entfernung begrüßt, was ein klares Bild von der unmittelbaren Umgebung des Rovers zeichnet.

.. image:: img/app/app_show_ir_ultrasonic.png

Mit diesem Schritt haben Sie die Welt der Anzeige-Widgets erfolgreich erkundet. Experimentieren Sie ruhig mit verschiedenen Widgets, um die Informationen anzuzeigen, die Sie interessant finden. Viel Spaß beim Erforschen!

**Schritt 4: Reflexion und Schlussfolgerung**

In dieser Lektion haben wir ein tieferes Verständnis für den SunFounder Controller entwickelt und verstanden, wie wir seine Widgets nicht nur zur Steuerung unseres Mars-Rovers, sondern auch zur Überwachung seiner Umweltdaten in Echtzeit nutzen können.

Nun, hier ist eine Herausforderung für Sie:

Wie wäre es, einige Schalter-Widgets zu Ihrem SunFounder Controller hinzuzufügen? Mit diesen aktivierten Schaltern könnte der Mars-Rover zwischen Vermeidungs- und Folgemodi umschalten. Oder nutzen Sie die Schalter zur Steuerung des Lichtstreifens – ihn ein- oder ausschalten oder sogar seine Farbe ändern?

Haben Sie das Vertrauen, diese Herausforderung anzunehmen?

Wir freuen uns darauf, Sie diese Herausforderung meistern zu sehen!
