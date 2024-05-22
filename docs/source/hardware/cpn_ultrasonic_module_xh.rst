.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!


Ultraschallmodul
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG**: Trigger-Pulseingang
* **ECHO**: Echo-Pulseausgang
* **GND**: Erdung
* **VCC**: 5V Versorgung

Dies ist der HC-SR04 Ultraschall-Abstandssensor, der berührungslose Messungen von 2 cm bis 400 cm mit einer Bereichsgenauigkeit von bis zu 3 mm bietet. Das Modul enthält einen Ultraschall-Sender, einen Empfänger und eine Steuerschaltung.

Sie müssen nur 4 Pins anschließen: VCC (Stromversorgung), Trig (Auslöser), Echo (Empfang) und GND (Erdung), um es leicht für Ihre Messprojekte zu verwenden.

**Merkmale**

* Betriebsspannung: DC5V
* Betriebsstrom: 16mA
* Arbeitsfrequenz: 40Hz
* Maximaler Bereich: 500cm
* Minimaler Bereich: 2cm
* Trigger-Eingangssignal: 10uS TTL-Impuls
* Echo-Ausgangssignal: Eingang TTL-Pegelsignal und der Bereich im Verhältnis
* Steckverbinder: XH2.54-4P
* Abmessung: 46x20.5x15 mm

**Prinzip**

Die grundlegenden Prinzipien sind wie folgt:

* Verwendung von IO-Trigger für mindestens 10us hohes Signalniveau.
* Das Modul sendet einen 8-Zyklus-Burst von Ultraschall mit 40 kHz und erkennt, ob ein Pulssignal empfangen wird.
* Echo gibt ein hohes Niveau aus, wenn ein Signal zurückkommt; die Dauer des hohen Niveaus ist die Zeit von der Emission bis zur Rückkehr.
* Entfernung = (Zeit des hohen Niveaus x Schallgeschwindigkeit (340M/S)) / 2

    .. image:: img/ultrasonic_prin.jpg
        :width: 800



**Anwendungshinweise**

* Dieses Modul sollte nicht unter Strom angeschlossen werden, falls nötig, sollte zuerst der GND des Moduls angeschlossen werden. Andernfalls beeinflusst es die Arbeit des Moduls.
* Die Fläche des zu messenden Objekts sollte mindestens 0,5 Quadratmeter betragen und möglichst flach sein. Andernfalls beeinflusst es die Ergebnisse.


