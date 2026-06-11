
Lektion 12: Untersuchung des Energieversorgungssystems des Mars Rovers
=======================================================================

Willkommen zur letzten Lektion unserer Mars Rover-Erkundungsreise. Dieses Mal werden wir in das Herz des Rovers eintauchen - sein Energieversorgungssystem.

Wenn wir daran denken, entfernte Planeten wie den Mars zu erkunden, ist einer der wichtigsten Aspekte die Energieversorgung.
Wie versorgen sich diese Rover in solch rauen und abgelegenen Umgebungen mit Strom?
In dieser Lektion werden wir dieses faszinierende Thema erforschen und lernen, wie Rover, wie unser Mars Rover-Modell, Energie nutzen und verwalten.

Wir werden die Arbeitsprinzipien von Batterie und Solarpanel untersuchen und sogar praktische Erfahrungen bei der Installation und
Nutzung dieser Energiequellen an unserem Rover-Modell sammeln. Darüber hinaus werden wir unsere Fähigkeiten erweitern, indem wir mit Arduino den
Ladezustand der Batterie überwachen.


.. image:: img/solar_panel.jpg
    :width: 600
    :align: center

Lernziele
-----------------------

* Die Arbeitsprinzipien von Batterie und Solarpanel verstehen.
* Üben der Installation des Solarpanels am Mars Rover-Modell.
* Lernen, wie man mit Arduino den Batterieladezustand und den Ladestatus des Solarpanels überwacht.


Benötigte Materialien
------------------------

* Mars Rover-Modell (mit allen Komponenten ausgestattet, außer Solarpanel und Bodenplatte)
* Solarpanel und Bodenplatte
* Arduino IDE
* Computer

Kursschritte
----------------------

**Schritt 1: Einführung in das Energieversorgungssystem des Mars Rovers**

So wie unser Körper eine konstante Energiezufuhr benötigt, um zu funktionieren, braucht unser Mars Rover eine Möglichkeit, Strom für seine Erkundungsmissionen zu speichern und zu erzeugen. Stellen Sie sich das Energieversorgungssystem des Rovers wie das Herz in unserem Körper vor. So wie unser Herz Blut in alle Teile unseres Körpers pumpt und so mit notwendigem Sauerstoff und Nährstoffen versorgt, hält das Energieversorgungssystem des Rovers den Energiefluss zu jedem Teil des Rovers aufrecht und stellt sicher, dass er seine Aufgaben reibungslos erfüllen kann.

Die Hauptkomponenten dieses Energieversorgungssystems sind die Batterien und die Solarpanels, die zusammenarbeiten, um sicherzustellen, dass der Rover zu jeder Tages- und Nachtzeit betrieben werden kann.

Die Rolle der Batterien im Energieversorgungssystem des Rovers ist vergleichbar mit der Rolle der Energiespeicherung in unserem Körper. So wie wir Energie für den Gebrauch speichern müssen, wenn wir aktiv sind, benötigt der Rover eine Möglichkeit, Energie für seine Erkundungsmissionen zu speichern. Die in den Batterien gespeicherte Energie wird kontinuierlich an verschiedene Teile des Rovers verteilt, sodass er seine Aufgaben systematisch ausführen kann.

.. image:: img/battery_galaxyrvr.png
    :width: 600
    :align: center

Aber was passiert, wenn die Energie in den Batterien zur Neige geht? Wie füllt er seine Energiespeicher wieder auf? Hier kommen die Solarpanels ins Spiel.

So wie Bäume Sonnenlicht für die Photosynthese absorbieren, um Nahrung zu produzieren, nutzt unser Mars Rover Solarpanels, um Energie von der Sonne zu gewinnen und in Elektrizität umzuwandeln, die in den Batterien für den späteren Gebrauch gespeichert wird. Jedes Solarpanel besteht aus vielen kleineren Solarzellen. Diese Zellen bestehen aus einem Material, das Licht in Elektrizität umwandeln kann - ein Prozess, der als photovoltaischer Effekt bezeichnet wird. Wenn Sonnenlicht auf die Zellen trifft, erzeugen sie einen elektrischen Strom, der sofort genutzt oder in den Batterien des Rovers für später gespeichert werden kann.

.. image:: img/solar_panel_gala.png
    :width: 600
    :align: center

Allerdings ist die Nutzung von Sonnenenergie auf dem Mars nicht so einfach, wie es klingt. Staubstürme können die Menge an Sonnenlicht, die die Panels erreicht, reduzieren, und das schwächere Mars-Sonnenlicht (im Vergleich zur Erde) führt dazu, dass die Panels weniger Strom erzeugen als hier auf der Erde. Trotz dieser Herausforderungen ist Solarenergie immer noch die praktischste und effizienteste Methode, um unseren Mars Rover mit Strom zu versorgen.

Aber woher wissen wir, wann die Solarpanels ihren Dienst verrichten und wann die Batterien schwach werden? Hier kommt unser Arduino ins Spiel. Im nächsten Abschnitt werden wir lernen, wie man mit Arduino das Laden und Entladen der Rover-Batterien überwacht.

**Schritt 2: Montieren des Solarpanels am Mars Rover**

Bevor wir mit diesem Schritt beginnen, benötigen wir unser Mars Rover-Modell, ein Solarpanel und die Kabel, um das Solarpanel an das Stromversorgungssystem des Rovers anzuschließen.

Dies ist ein Prozess, der es uns ermöglicht, die Theorie in die Praxis umzusetzen und den Charme der MINT-Bildung (Wissenschaft, Technologie, Ingenieurwesen und Mathematik) wirklich zu schätzen. Legen wir los!

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/-Vj-dcniFrA" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Schritt 3: Programmierung zur Überwachung der Batteriespannung und -ladung**

Nachdem wir die Solarpanels an unserem Mars Rover-Modell installiert haben, besteht der nächste Schritt darin, die Spannung und Ladung der Batterie durch Programmierung zu überwachen.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2e85e234-9575-4a1f-982b-2f9aba8e3156/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Dieser Code erstellt effektiv einen einfachen Batteriemonitor, der besonders bei Anwendungen wie dem Mars Rover nützlich ist, wo das Energiemanagement entscheidend ist. Er ermöglicht es Ihnen, den Zustand der Batterie zu überwachen und hilft Ihnen zu verstehen, wann der Rover aufgeladen werden muss oder wann stromverbrauchende Aufgaben geplant werden sollten.

Lassen Sie uns die verschiedenen Teile dieses Codes aufschlüsseln:

*  Diese Zeile definiert ``BATTERY_PIN`` als den analogen Pin A3, von dem die Batteriespannung ausgelesen wird.

    .. code-block:: arduino

        #define BATTERY_PIN A3

* Diese Funktion berechnet die Spannung der Batterie. Sie liest zuerst den analogen Wert von ``BATTERY_PIN`` und wandelt ihn dann in Spannung um. Da der Analog-Digital-Wandler (ADC) des Arduinos auf einer Skala von 0-1023 arbeitet, teilen wir den Rohwert durch 1023. Wir multiplizieren dann mit 5 (der Referenzspannung des Arduinos) und mit 2 (unter Annahme eines Spannungsteilers von 2), um dies in einen Spannungswert umzuwandeln.

    .. code-block:: arduino
        :emphasize-lines: 5

        float batteryGetVoltage() {
            // Liest den analogen Wert vom Batteriepin
            int adcValue = analogRead(BATTERY_PIN);
            // Wandelt den analogen Wert in Spannung um
            float adcVoltage = adcValue / 1023.0 * 5 * 2;
            // Rundet die Spannung auf zwei Dezimalstellen
            float batteryVoltage = int(adcVoltage * 100) / 100.0;
            return batteryVoltage;
        }


    Der rohe ADC-Wert vom Analog-Digital-Wandler des Arduinos wird durch 1023 geteilt, um ihn in einen Bruch umzuwandeln, dann mit 5 multipliziert, um ihn in Spannung zu übersetzen, da der Arduino eine Referenzspannung von 5 Volt verwendet.

    Da die Batteriespannung jedoch höher ist als die maximale Eingangsspannung des Arduinos, wird ein Widerstand zum Schutz des Arduinos verwendet. Daher multiplizieren wir die ADC-Spannung mit 2, um die Wirkung des Widerstands auszugleichen und die korrekte Batteriespannung zu erhalten.

* Diese Funktion berechnet den prozentualen Ladezustand der Batterie basierend auf ihrer Spannung. Sie verwendet die Funktion ``map``, um den Spannungswert (im Bereich von 6,6 bis 8,4 Volt) auf einen Prozentsatz (im Bereich von 0 bis 100) abzubilden.

    .. code-block:: arduino

        uint8_t batteryGetPercentage() {
            float voltage = batteryGetVoltage();  // Ermittelt die Batteriespannung
            // Bildet die Spannung auf einen Prozentsatz ab.
            int16_t temp = map(voltage, 6.6, 8.4, 0, 100);
            // Stellt sicher, dass der Prozentsatz zwischen 0 und 100 liegt
            uint8_t percentage = max(min(temp, 100), 0);
            return percentage;
        }

**Schritt 4: Das Energieversorgungssystem des Mars Rovers auf die Probe stellen: Fahrten drinnen und draußen**

Nachdem wir unser Batterieüberwachungssystem programmiert haben, ist es nun an der Zeit, den Mars Rover in Aktion zu setzen.
Laden Sie den Rover zunächst vollständig auf und planen Sie zwei 30-minütige Erkundungsmissionen - eine drinnen
und eine draußen im Sonnenlicht. Notieren Sie den anfänglichen Batterieladezustand vor jeder Mission
und vergleichen Sie ihn mit dem Batterieprozentsatz am Ende jedes Tests.
Die folgende Tabelle dient als nützliche Vorlage, um Ihre Ergebnisse festzuhalten:



.. list-table:: Leistungstest
   :widths: 50 25 25
   :header-rows: 1

   * -
     - Sonnenschein
     - Im Raum
   * - Start Batterieprozentsatz
     -
     -
   * - End Batterieprozentsatz
     -
     -

Beobachten Sie den Unterschied der Batterieladezustände nach jedem Test. Hielt die Batterie des Rovers länger, wenn er
draußen in der Sonne war? Welche Schlussfolgerungen können wir aus dieser Beobachtung über die Wirksamkeit des Solarpanels ziehen?

Das Verständnis dieser Unterschiede wird uns helfen, besser zu verstehen, wie Solarenergie einen Mars Rover effektiv mit Strom versorgen kann,
selbst in abgelegenen, rauen Umgebungen wie denen auf der Marsoberfläche.

**Schritt 5: Reflexion**

In dieser Lektion haben wir uns darauf konzentriert, die entscheidende Rolle des Energieversorgungssystems im Mars Rover und die Mechanismen zur Überwachung der verbleibenden Energie des Rovers zu verstehen. Das auf Solarpanels basierende Energieversorgungssystem versorgt nicht nur den Rover mit Strom, sondern unterstreicht auch die Bedeutung erneuerbarer Energiequellen in der Weltraumforschung.

Mit dem Wissen, das Sie jetzt haben, denken Sie über die realen Auswirkungen dieses Systems nach. Welche Herausforderungen könnte ein Solarenergiesystem auf dem Mars bewältigen müssen? Wie könnten extreme Temperaturen, Staubstürme oder lange Dunkelheitsperioden die Energieversorgung beeinträchtigen? Welche Lösungen könnten Sie vorschlagen, um diese Hindernisse zu überwinden?

**Schritt 6: Ausblick**

Nachdem wir unserem Mars Rover nun die Fähigkeit gegeben haben, sich zu bewegen, ist es an der Zeit, ihn auf seine Erkundungsreise zu schicken! Sie können ihn in verschiedenen, die Marsumgebung nachahmenden Geländen umherstreifen lassen.

Zum Beispiel können Sie ihn über einen Steinhaufen klettern lassen.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/move_stone.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Oder lassen Sie ihn durch ein dichtes Grasstück navigieren.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/move_grass.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Oder setzen Sie ihn auf einen Parcours auf einem steinigen Kiesgelände.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/move_stone1.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Beachten Sie jedoch, dass der Rover möglicherweise nicht über ein zu hohes Hindernis klettern kann.

.. raw:: html

   <video width="400" height="400" loop autoplay muted>
      <source src="../_static/video/move_failed.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Diese unterschiedlichen Gelände stellen einzigartige Herausforderungen für den Rover dar, genau wie sie es für einen echten Mars Rover tun würden. Wenn Sie zusehen, wie Ihr Rover versucht, diese Hindernisse zu überwinden, erleben Sie einen kleinen Teil dessen, was Wissenschaftler und Ingenieure bei der NASA tun, wenn sie Rover zum Mars schicken!

Zum Abschluss unserer Mars Rover-Lektionen ist es wichtig, auf das Gelernte zurückzublicken. Wir hoffen, dass diese Reise nicht nur Ihr Wissen und Ihre Fähigkeiten erweitert, sondern auch Neugier und Entdeckungsdrang geweckt hat. Ob Ihr Rover in Ihrem Hinterhof oder in den Weiten Ihrer Fantasie umherstreift, die Entdeckungen, die Sie dabei machen, werden sicherlich außergewöhnlich sein.
