.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

IR-Hindernisvermeidungsmodul
=======================================

Dies ist ein Infrarot-Hindernisvermeidungsmodul, das die Anwesenheit von Objekten vor sich erkennen kann. Es wird häufig in Robotern, Automatisierungssystemen und anderen intelligenten Geräten verwendet. Sein Erfassungsbereich liegt zwischen 2 cm und 40 cm, und Objekte unterschiedlicher Farbe haben unterschiedliche Reflexionsniveaus. Daher ist der Erfassungsbereich umso kürzer, je dunkler das Objekt ist.

.. image:: img/ir_avoid.png
    :width: 400
    :align: center

Hier sind die Pin-Definitionen:

* **GND**: Erdung
* **+**: Stromversorgung, 3,3 ~ 5V DC.
* **Out**: Standardmäßig bleibt es hoch und wird nur niedrig, wenn es ein Hindernis erkennt.
* **EN**: Dieser **Enable**-Pin entscheidet, wann das Modul arbeiten soll. Standardmäßig ist er mit GND verbunden, was bedeutet, dass das Modul immer in Betrieb ist.


**Wie funktioniert das?**

Dieses Modul enthält ein Paar IR-Sendungs- und Empfangskomponenten. Der Sender emittiert Infrarotlicht, das, wenn es auf ein Hindernis trifft, zurückreflektiert und vom Empfänger aufgenommen wird. Bei Erkennung leuchtet die Anzeige auf. Nach der Schaltungsverarbeitung gibt es ein niedriges Signal aus.

.. image:: img/ir_receive.png
    :width: 600
    :align: center


Der niedrige Zustand des **EN**-Pins aktiviert das Modul, wobei die Jumperkappe den **EN**-Pin mit dem GND sichert. Um den EN-Pin programmgesteuert zu steuern, entfernen Sie die Jumperkappe.

.. image:: img/ir_cap.png
    :width: 400
    :align: center

Auf dem Modul befinden sich zwei Potentiometer, eines zur Einstellung der Sendeleistung und eines zur Einstellung der Sendefrequenz. Durch die Anpassung dieser beiden Potentiometer können Sie seine effektive Entfernung einstellen.

.. image:: img/ir_avoid_pot.png
    :width: 400
    :align: center 


**Einstellen der Erfassungsdistanz**

Der Erfassungsbereich des Hindernisvermeidungsmoduls muss präzise kalibriert werden, um eine optimale Leistung zu erzielen, da die Standardeinstellungen der Fabrik möglicherweise nicht den spezifischen Anforderungen entsprechen.

Die Kalibrierung umfasst die folgenden Schritte:

#. Ausrichtung des Moduls: Beginnen Sie mit dem rechten Hindernisvermeidungsmodul. Transport kann gelegentlich die Ausrichtung des Infrarotsenders und -empfängers des Moduls verschieben. Sie sollten manuell neu ausgerichtet werden, um Genauigkeit zu gewährleisten.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

#. Platzieren Sie ein Hindernis etwa 20 cm direkt vor dem rechten Modul. Die Box, in der unser Rover-Kit geliefert wurde, ist eine gute Wahl dafür! Drehen Sie nun das Potentiometer am Modul, bis die Anzeige am Modul gerade aufleuchtet. Bewegen Sie dann das Hindernis hin und her, um zu prüfen, ob die Anzeige im gewünschten Abstand aufleuchtet. Wenn das Licht nicht in der richtigen Entfernung aufleuchtet oder ständig eingeschaltet bleibt, müssen Sie das andere Potentiometer einstellen.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>


#. Wiederholen Sie den gleichen Prozess für ein weiteres Modul.

**Merkmale**

* Betriebsspannung: 3,3 V bis 5 V
* Ausgang: digital (ein/aus)
* Einstellschwelle: einstellbar durch 2 Potentiometer
* Distanzbereich: 2 bis 40 cm
* Einstellung R5: Frequenzeinstellung 38 kHz (bereits optimiert)
* Einstellung R6: IR-LED-Tastverhältniseinstellung (bereits optimiert)
* Betriebstemperatur: -10 °C bis +50 °C
* Effektiver Winkel: 35°
* I/O-Schnittstelle: 4-Draht-Schnittstelle (- / + / S / EN)
* Abmessungen: 45 x 16 x 10 mm
* Gewicht: 9 g 

