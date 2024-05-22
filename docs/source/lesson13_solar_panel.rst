.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Lektion 13: Untersuchung des Energiesystems des Mars-Rovers
=================================================================

Willkommen zur letzten Lektion unserer Reise zur Erforschung des Mars-Rovers. Diesmal tauchen wir in das Herz des Rovers ein - sein Energiesystem.

Wenn wir über die Erforschung ferner Planeten wie Mars nachdenken, ist einer der wichtigsten Aspekte die Energie. 
Wie versorgen sich diese Rover in solch rauen und abgelegenen Umgebungen selbst mit Strom? 
In dieser Lektion werden wir dieses faszinierende Thema erkunden und erfahren, wie Rover, wie unser Mars-Rover-Modell, Energie nutzen und verwalten.

Wir werden die Arbeitsprinzipien von Batterie und Solarpanel untersuchen und sogar praktische Erfahrungen im Installieren und 
Nutzen dieser Energiequellen an unserem Rover-Modell sammeln. Darüber hinaus werden wir unsere Fähigkeiten mit Arduino verbessern, um 
den Batteriestand zu überwachen.

Am Ende der Lektion werden wir in der Lage sein, diese vitalen Energiestatistiken direkt in unserer App anzuzeigen, 
was uns ein Echtzeitverständnis des Energiestatus unseres Rovers ermöglicht. Bereit, unsere Erkundung mit Energie zu starten? Lass uns beginnen!

.. image:: img/solar_panel.jpg
    :width: 600
    :align: center

Kursziele
-----------------------

* Verstehen der Arbeitsprinzipien von Batterie und Solarpanel.
* Praktische Erfahrungen im Installieren des Solarpanels am Mars-Rover-Modell.
* Erlernen der Überwachung des Batteriestandes und des Ladezustandes des Solarpanels mit Arduino.
* Anzeige des Batteriestandes in der App.

Kursmaterialien
------------------------

* Mars-Rover-Modell (mit allen Komponenten, außer Solarpanel und Bodenplatte)
* Solarpanel und Bodenplatte
* Arduino IDE
* Computer
* Tablet oder Smartphone mit installierter SunFounder Controller-App



Kursschritte
----------------------

**Schritt 1: Einführung in das Energiesystem des Mars-Rovers**

Genau wie unser Körper eine ständige Energiezufuhr benötigt, braucht unser Mars-Rover eine Möglichkeit, Energie für seine Erkundungsmissionen zu speichern und zu erzeugen. Stellen Sie sich das Energiesystem des Rovers vor wie das Herz in unserem Körper. Genau wie unser Herz Blut in alle Teile unseres Körpers pumpt und notwendigen Sauerstoff und Nährstoffe liefert, hält das Energiesystem des Rovers die Energie in allen Teilen des Rovers fließend, um sicherzustellen, dass er seine Aufgaben reibungslos erfüllen kann.

Die Hauptkomponenten dieses Energiesystems sind die Batterien und die Solarpanels, die zusammenarbeiten, um sicherzustellen, dass der Rover jederzeit, Tag und Nacht, betriebsbereit ist.

Die Rolle der Batterien im Energiesystem des Rovers ist ähnlich der Rolle der Energiespeicherung in unserem Körper. Genau wie wir Energie speichern müssen, um sie bei Aktivität zu nutzen, braucht der Rover eine Möglichkeit, Energie für seine Erkundungsmissionen zu speichern. Die in den Batterien gespeicherte Energie wird kontinuierlich an verschiedene Teile des Rovers abgegeben, damit er seine Aufgaben systematisch durchführen kann.

.. image:: img/battery_galaxyrvr.png
    :width: 600
    :align: center

Aber was passiert, wenn die Energie in den Batterien zur Neige geht? Wie wird seine Energie wieder aufgefüllt? Hier kommen die Solarpanels ins Spiel.

Ähnlich wie Bäume Sonnenlicht für die Photosynthese aufnehmen, um Nahrung zu erzeugen, nutzt unser Mars-Rover Solarpanels, um Energie von der Sonne zu nutzen und sie in Elektrizität umzuwandeln, die in den Batterien gespeichert wird. Jedes Solarpanel besteht aus vielen kleineren Solarzellen. Diese Zellen bestehen aus einem Material, das Licht in Elektrizität umwandeln kann – ein Prozess, der als photovoltaischer Effekt bezeichnet wird. Wenn Sonnenlicht auf die Zellen trifft, erzeugen sie einen elektrischen Strom, der sofort genutzt oder in den Batterien des Rovers für die spätere Nutzung gespeichert werden kann.

.. image:: img/solar_panel_gala.png
    :width: 600
    :align: center

Jedoch ist das Nutzen von Solarenergie auf dem Mars nicht so einfach, wie es klingt. Staubstürme können die Menge des Sonnenlichts, die die Panele erreicht, verringern, und das schwächere Mars-Sonnenlicht (im Vergleich zur Erde) bedeutet, dass die Panele weniger Strom erzeugen, als sie es hier zu Hause würden. Trotz dieser Herausforderungen ist Solarenergie immer noch die praktischste und effizienteste Art, unseren Mars-Rover mit Strom zu versorgen.

Aber wie wissen wir, wann die Solarpanele ihre Arbeit verrichten und wann die Batterien an Leistung verlieren? Hier kommt unser Arduino ins Spiel. Im nächsten Abschnitt lernen wir, wie wir Arduino nutzen können, um das Laden und Entladen der Rover-Batterien zu überwachen.


**Schritt 2: Montage des Solarpanels am Mars-Rover**

Bevor wir mit diesem Schritt beginnen, benötigen wir unser Mars-Rover-Modell, ein Solarpanel und die notwendigen Kabel, um das Solarpanel mit dem Stromsystem des Rovers zu verbinden.

Dies ist ein Prozess, der es uns ermöglicht, Theorie in die Praxis umzusetzen und die Faszination der Ausbildung in Wissenschaft, Technik, Ingenieurwesen und Mathematik (STEM) wirklich zu schätzen. Lass uns beginnen!

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/-Vj-dcniFrA" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Schritt 3: Programmierung zur Überwachung der Batteriespannung und -ladung**

Jetzt, da wir die Solarpanels an unserem Mars-Rover-Modell installiert haben, besteht der nächste Schritt darin, die Spannung und Ladung der Batterie durch Programmierung zu überwachen. 


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2e85e234-9575-4a1f-982b-2f9aba8e3156/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Dieser Code erstellt effektiv einen einfachen Batteriemonitor, der besonders nützlich in Anwendungen wie dem Mars-Rover ist, wo das Energiemanagement entscheidend ist. Er ermöglicht es Ihnen, den Zustand der Batterie zu überwachen und zu verstehen, wann der Rover aufgeladen werden muss oder wann energieintensive Aufgaben geplant werden sollten.

Sicher, lassen Sie uns die verschiedenen Teile dieses Codes erläutern:

*  Diese Zeile definiert ``BATTERY_PIN`` als den analogen Pin A3, von dem die Batteriespannung abgelesen wird.

    .. code-block:: arduino

        #define BATTERY_PIN A3

* Diese Funktion berechnet die Spannung der Batterie. Zuerst liest sie den analogen Wert von ``BATTERY_PIN``, dann wandelt sie ihn in Spannung um. Da der analoge-digital-Wandler (ADC) des Arduino auf einer Skala von 0-1023 arbeitet, teilen wir den Rohwert durch 1023. Wir multiplizieren dann mit 5 (die Referenzspannung des Arduino) und mit 2 (unter der Annahme eines Spannungsteilers von 2), um dies in eine Spannungsanzeige umzuwandeln.

    .. code-block:: arduino
        :emphasize-lines: 5

        float batteryGetVoltage() {
            // Reads the analog value from the battery pin
            int adcValue = analogRead(BATTERY_PIN);
            // Converts the analog value to voltage
            float adcVoltage = adcValue / 1023.0 * 5 * 2;
            // Rounds the voltage to two decimal places
            float batteryVoltage = int(adcVoltage * 100) / 100.0;
            return batteryVoltage;
        }
    

    Der rohe ADC-Wert des Arduino-Analog-Digital-Umsetzers wird durch 1023 geteilt, um ihn in einen Bruchteil umzuwandeln, und dann mit 5 multipliziert, um ihn in Spannung umzusetzen, da Arduino eine Referenzspannung von 5 Volt verwendet.

    Da jedoch die Batteriespannung höher als die maximale Eingangsspannung des Arduino ist, wird ein Widerstand verwendet, um den Arduino zu schützen. Daher multiplizieren wir die ADC-Spannung mit 2, um den Effekt des Widerstands auszugleichen und die korrekte Batteriespannung zu erhalten.

* Diese Funktion berechnet den Ladungsprozentsatz der Batterie anhand ihrer Spannung. Sie verwendet die Funktion ``map``, um den Spannungswert (der zwischen 6,6 und 8,4 Volt liegt) in einen Prozentsatz (der zwischen 0 und 100 liegt) umzuwandeln.

    .. code-block:: arduino

        uint8_t batteryGetPercentage() {
            float voltage = batteryGetVoltage();  // Gets the battery voltage
            // Maps the voltage to a percentage.
            int16_t temp = map(voltage, 6.6, 8.4, 0, 100);
            // Ensures the percentage is between 0 and 100
            uint8_t percentage = max(min(temp, 100), 0);
            return percentage;
        }

**Schritt 4: Test des Energiesystems des Mars-Rovers: Innen- und Außeneinsätze**

Nachdem wir unser Batterieüberwachungssystem programmiert haben, ist es nun an der Zeit, den Mars-Rover in Aktion zu setzen. 
Beginnen Sie damit, den Rover vollständig aufzuladen, und planen Sie zwei 30-minütige Erkundungsmissionen - eine in Innenräumen, 
und eine weitere im Sonnenlicht im Freien. Zeichnen Sie den anfänglichen Batteriestand vor jeder Mission auf 
und vergleichen Sie ihn mit dem Batterieprozentsatz am Ende jedes Tests. 
Die folgende Tabelle dient als nützliche Vorlage, um Ihre Erkenntnisse festzuhalten:



.. list-table:: Leistungstest
   :widths: 50 25 25
   :header-rows: 1

   * - 
     - Sonnenschein
     - Innenraum
   * - Anfangs Batterieprozentsatz
     -
     - 
   * - Endgültiger Batterieprozentsatz
     - 
     - 

Beobachten Sie den Unterschied in den Batterieständen nach jedem Test. Hielt die Batterie des Rovers länger, als er im Freien im Sonnenlicht stand? Welche Schlussfolgerungen können wir über die Wirksamkeit des Solarpanels aus dieser Beobachtung ziehen?

Das Verständnis dieser Unterschiede wird uns helfen, besser zu verstehen, wie Solarenergie einen Mars-Rover effektiv antreiben kann, 
selbst in abgelegenen, harschen Umgebungen wie denen auf der Marsoberfläche.

**Schritt 5: Anzeige des Batteriestands in der App**

Natürlich ist es unpraktisch, wiederholt neuen Code auf den Mars-Rover hochzuladen, nur um den verbleibenden Batteriestand zu überprüfen. Das könnte ziemlich umständlich sein.

Stattdessen können wir den Batteriestand an eine App senden, die es uns ermöglicht, einfach zu überwachen, wie viel Spielzeit noch verbleibt, während wir Spaß haben!

Aus früheren Lektionen haben wir gelernt, dass wir, wenn wir Daten auf dem SunFounder Controller anzeigen oder den Mars-Rover mit Widgets steuern wollen, diese Widgets zuerst hinzufügen müssen.

Die Anzeige des Batteriestands ist jedoch ein spezielles Widget. Es hat einen eigenen Schlüssel (``BV``), und seine Anzeige befindet sich nicht in den von A bis Q gekennzeichneten Bereichen. Stattdessen wird es durch ein Batteriesymbol in der oberen rechten Ecke dargestellt.

So fügen wir es in unseren Code ein:

.. code-block:: Arduino

    ...
    // This pin reads the voltage of the battery
    #define BATTERY_PIN A3
    ...

    void setup() {
        ...
        // Sets the battery pin as an input
        pinMode(BATTERY_PIN, INPUT);
    }


    // Function to execute when data is received from the Controller
    void onReceive() {
        ...
        //show battery voltage
        aiCam.sendDoc["BV"] = batteryGetVoltage();
    }   

    ...

    // This function reads the battery voltage
    float batteryGetVoltage() {
        // Reads the analog value from the battery pin
        int adcValue = analogRead(BATTERY_PIN);
        // Converts the analog value to voltage
        float adcVoltage = adcValue / 1023.0 * 5 * 2;
        // Rounds the voltage to two decimal places
        float batteryVoltage = int(adcVoltage * 100) / 100.0;
        return batteryVoltage;
    }

Bitte finden Sie den vollständigen Code im Anhang:


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8b6e0dbd-6fcc-45ac-8408-e8aa706a4bf3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem Sie den Code erfolgreich hochgeladen haben, starten Sie Ihren SunFounder Controller. Sie werden den Batteriestand in der oberen rechten Ecke sehen.

.. image:: img/battery_icon.png

Mit diesem Schritt haben wir das Energiesystem des Mars-Rovers gemeistert und die Fähigkeit erlangt, seine Energielevels in Echtzeit zu überwachen.

Jetzt, da wir gelernt haben, wie wir die Kraft der Sonne nutzen können, um den Mars-Rover effektiv zu betreiben, können wir mit der Planung umfangreicherer Erkundungen unseres Hinterhofs oder sogar den Aufbruch in herausforderndere Gelände beginnen!

**Schritt 6: Reflexion**

In dieser Lektion konzentrierten wir uns darauf, die entscheidende Rolle des Energiesystems im Mars-Rover zu verstehen und die Mechanismen zur Überwachung der verbleibenden Energie des Rovers. Das auf Solarmodulen basierende Energiesystem versorgt nicht nur den Rover mit Strom, sondern unterstreicht auch die Bedeutung erneuerbarer Energiequellen in der Raumfahrt.

Mit dem Wissen, das Sie jetzt haben, denken Sie über die realen Auswirkungen dieses Systems nach. Überlegen Sie, welche Herausforderungen ein Solarenergiesystem auf dem Mars antreffen könnte. Wie könnten extreme Temperaturen, Staubstürme oder lange Dunkelphasen die Energieversorgung beeinflussen? Welche Lösungen könnten Sie vorschlagen, um diese Hindernisse zu überwinden?

**Schritt 7: Ausblick**

Jetzt, da wir unserem Mars-Rover die Fähigkeit zur Bewegung gegeben haben, ist es an der Zeit, ihn seine Erkundungsreise beginnen zu lassen! Sie können ihn in verschiedenen Geländearten, die die Mars-Umgebung nachahmen, wandern lassen.

Zum Beispiel können Sie ihn über einen Haufen Steine klettern lassen.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/move_stone.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Oder lassen Sie ihn durch einen dichten Grasfleck navigieren.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/move_grass.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Oder setzen Sie ihn auf einen Kurs in einem Kiesgelände voller Steine.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/move_stone1.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Bitte beachten Sie jedoch, dass der Rover möglicherweise nicht in der Lage ist, über zu hohe Hindernisse zu klettern.

.. raw:: html

   <video width="400" height="400" loop autoplay muted>
      <source src="_static/video/move_failed.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Diese unterschiedlichen Geländearten stellen einzigartige Herausforderungen für den Rover dar, genauso wie sie es für einen echten Mars-Rover tun würden. Während Sie zusehen, wie Ihr Rover versucht, diese Hindernisse zu überwinden, erleben Sie einen kleinen Teil dessen, was Wissenschaftler und Ingenieure bei der NASA tun, wenn sie Rover zum Mars schicken!

Während wir unsere Mars-Rover-Lektionen abschließen, ist es wichtig, über das Gelernte nachzudenken. Wir hoffen, dass diese Reise nicht nur Ihr Wissen und Ihre Fähigkeiten erweitert hat, sondern auch Neugier und den Wunsch zu erkunden geweckt hat. Ob Ihr Rover in Ihrem Hinterhof oder in der weiten Ausdehnung Ihrer Fantasie umherstreift, die Entdeckungen, die Sie auf dem Weg machen, werden sicherlich außergewöhnlich sein.
