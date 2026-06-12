.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message



Schnellstart mit der App
=============================

Bereit für Ihr Mars-Abenteuer?
Mit der Schnellstart-Funktion der RoboPilot-App können Sie sofort loslegen, sobald Ihr GalaxyRVR zusammengebaut ist.

Mit RoboPilot können Sie:

- Den Rover aus der Ego-Perspektive steuern
- Zwischen drei Steuerungsmodi wechseln: **Fernsteuerung**, **Ausweichen** und **Folgen**


.. note::

    * Falls Sie die Firmware überschrieben haben und die Kommunikation wiederherstellen müssen, folgen Sie der Anleitung unter :ref:`update_r3_firmware`.

Kurzanleitung
---------------------

.. raw:: html


   <iframe width="600" height="400" src="https://www.youtube.com/embed/NwWjgP9ldZw?si=_3PADiRd-UlDvtHc" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Starten Sie den GalaxyRVR.

   * Laden Sie den Akku vor der ersten Verwendung des GalaxyRVR mit dem mitgelieferten Typ-C-USB-Kabel vollständig auf.
   * Schalten Sie den Netzschalter ein.
   * Stellen Sie den Modus auf **Run** und drücken Sie die **Reset**-Taste auf dem R3-Board.
   * Der untere Lichtstreifen blinkt **grün** und zeigt damit einen erfolgreichen Start an.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Installieren Sie **RoboPilot** aus dem **APP Store (iOS)** oder **Google Play (Android)**.

#. Verbinden Sie Ihr Mobilgerät mit dem WLAN-Netzwerk des GalaxyRVR.

   * Der Netzwerkname (SSID) lautet ``GalaxyRVR`` und das Passwort ist ``12345678``.
   * Wenn eine Warnung mit dem Hinweis "Kein Internetzugriff" erscheint, wählen Sie bitte die Option **"Trotzdem verbinden"**.

     .. image:: ../img/camera_lan.png
        :width: 500

#. Öffnen Sie RoboPilot. Tippen Sie auf 'Go into', um die Steuerungsoberfläche zu öffnen.

   .. image:: img/rp1_inter.png



Fernsteuerungsmodus
----------------------------------------------

Nachdem Sie die Steuerungsoberfläche betreten haben, sehen Sie den folgenden Bildschirm.
Der Hintergrund zeigt die Ansicht der GalaxyRVR-Kamera, überlagert mit den Fernsteuerungs-Widgets.

.. image:: img/rp2_page.png

Hier sind die Steuerelemente:

A. Zurück
B. Einstellungen: Hier können Sie den Namen und das Passwort des AP (Hotspots) ändern, WLAN einrichten, das Bild spiegeln und die Verbindung trennen.

   .. image:: img/rp3_setting.jpg

C. Akkuladestandsanzeige
D. App pausieren/starten
E. Modusauswahl: Hier können Sie zwischen Fernsteuerungsmodus, Ausweichmodus und Folgemodus wählen. Die Standardeinstellung ist der **Fernsteuerungsmodus**.

   .. image:: img/rp4_mode.jpg

F. Hindernisüberwachung: Dieses Modul ist in drei Bereiche unterteilt. Die linke und rechte Seite zeigen die Ergebnisse der Hindernismodule, der mittlere Bereich zeigt die Messwerte des Ultraschallsensors.
G. Farbauswahl: Wählen Sie hier die Beleuchtungsfarbe für das Chassis.

   .. image:: img/rp5_color.png

H. Kamera-LED-Schalter.
I. Stellen Sie den Neigungswinkel der Kameraplattform ein, Bereich 0–130°. Bei 0° zeigt die Kamera nach oben zum Himmel.
J. Bewegen Sie den Joystick, um die Bewegung des GalaxyRVR zu steuern. Ein sanfter Druck lässt den GalaxyRVR langsam fahren.


Ausweichmodus und Folgemodus
----------------------------------------------

* **Ausweichmodus**: Der GalaxyRVR fährt vorwärts und weicht Hindernissen auf seinem Weg aus.
* **Folgemodus**: Der GalaxyRVR bewegt sich auf ein Objekt vor ihm zu oder dreht sich nach links oder rechts, um der Bewegung des Objekts zu folgen.

Wenn Sie den **Ausweichmodus** oder den **Folgemodus** auswählen, sehen Sie die folgende Oberfläche. Das Live-Kamerabild des GalaxyRVR bildet den Hintergrund, mit darüberliegenden Steuerungsoptionen.

.. image:: img/rp6_avoid.png

**Oberflächensteuerungen:**

A. **Geschwindigkeitsregelung** – Passen Sie die Bewegungsgeschwindigkeit des GalaxyRVR an
B. **Motorsteuerung** – Starten oder Stoppen der Bewegung des GalaxyRVR
C. **Plattformsteuerung** – Passen Sie den Kamerawinkel von 0° (zum Himmel gerichtet) bis 130° an
D. **Hindernisüberwachung** – Visuelles Feedback von den Sensoren:

   - Linker/rechter Bereich: Infrarot-Hinderniserkennung
   - Mittlerer Bereich: Ultraschall-Entfernungsmessungen

**Einstellen des Hinderniserkennungsbereichs**

Kalibrieren Sie vor der Verwendung dieses Modus den Sensorerkennungsbereich an Ihre Umgebung. Die Werkseinstellungen sind möglicherweise nicht optimal.

- Zu kurz: Der Rover könnte Hindernisse rammen
- Zu lang: Der Rover könnte unnötig ausweichen

Kalibrierungsschritte:

1. **Beginnen Sie mit dem rechten Modul**

   - Stellen Sie sicher, dass Sender und Empfänger richtig ausgerichtet sind
   - Richten Sie sie gerade, wenn sie während des Transports verbogen wurden

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
        </video>

2. **Testen und justieren Sie die Empfindlichkeit**

   - Platzieren Sie ein Hindernis in 20 cm Entfernung (verwenden Sie die Rover-Box)
   - Drehen Sie das Potentiometer, bis die Anzeige-LED aufleuchtet
   - Überprüfen Sie die zuverlässige Auslösung in der gewünschten Entfernung
   - Verwenden Sie bei Bedarf das zweite Potentiometer

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
        </video>

3. **Wiederholen Sie den Vorgang für das linke Modul**


Erneute Verbindung
-------------------------------

Wenn Ihre Netzwerkverbindung fehlschlägt oder getrennt wird, werden Sie zu dieser Seite weitergeleitet.

.. image:: img/rp7_reconnect.png

Setzen Sie in diesem Fall Ihre Netzwerkeinstellungen zurück und klicken Sie dann auf die IP-Adresse, die Ihrem GalaxyRVR entspricht, um die Verbindung wiederherzustellen.
