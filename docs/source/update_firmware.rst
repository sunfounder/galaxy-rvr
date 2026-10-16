.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _update_firmware:

Firmware aktualisieren
======================

Ihr Gerät verfügt möglicherweise nicht über die neueste Firmware, da das Produkt ständig verbessert wird. Wir empfehlen, die Firmware vor der ersten Nutzung zu aktualisieren, damit alles reibungslos funktioniert. Die Aktualisierung der Firmware gewährleistet:

* **Fehlerbehebungen**: Behebt bekannte Probleme und verbessert die Stabilität.
* **App-Kompatibilität**: Die neueste Firmware wird benötigt, damit die RoboPilot-App und Mammoth Coding korrekt funktionieren.
* **Neue Funktionen**: Firmware-Updates können neue Fähigkeiten und Verbesserungen hinzufügen.
* **Bessere Leistung**: Optimierungen für WLAN-Konnektivität, Kamera-Streaming und Motorsteuerung.

.. note::
   Wenn Sie die Firmware nicht aktualisieren und Ihre aktuelle Konfiguration weiterhin beibehalten möchten, können Sie die `GalaxyRVR v1-Dokumentation <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_ konsultieren.


.. Video vorübergehend deaktiviert: Es zeigt den alten Update-Vorgang und ist veraltet. Nach Aufnahme des neuen Videos wieder aktivieren.
..
.. .. raw:: html
..
..    <iframe width="600" height="400" src="https://www.youtube.com/embed/Tl2W26pIQoU?si=98bbfUPc1g2cEz3A" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

.. _update_r3_firmware:

1. Aktualisieren der UNO R3-Firmware
------------------------------------

Das R3-Board trägt die Firmware, die mit der RoboPilot-App und Mammoth Coding kommuniziert. Installieren Sie sie mit dem webbasierten Flasher neu: Öffnen Sie |link_galaxy_rvr_flasher| in **Chrome** oder **Edge** auf einem Computer — er läuft im Browser, benötigt keine zusätzliche Software und zeigt jeden Schritt mit einem eigenen Bild.

Der Flasher hat drei Schritte:

#. **Connect** — Schalten Sie den Rover ein, verbinden Sie die Hauptplatine mit einem USB-A-auf-B-Kabel (nicht dem Typ-C-Kabel) mit Ihrem Computer und stellen Sie den Modusschalter anschließend auf die Position **Upload**. Klicken Sie dann auf **Next**.

   .. image:: img/flasher_step1.jpg
      :width: 500

#. **Flash** — Klicken Sie auf **Connect & Flash**. Wählen Sie im daraufhin angezeigten Port-Fenster den Anschluss Ihrer Platine (zum Beispiel ``USB Serial (COMxx)``) und klicken Sie dann auf **Connect**; das Flashen beginnt. Falls es fehlschlägt, klicken Sie einfach erneut auf **Connect & Flash**.

   .. image:: img/flasher_step2.jpg
      :width: 500

#. **Debug** — Wenn das Flashen abgeschlossen ist, sehen Sie das Folgende im Log-Fenster. Das bestätigt, dass die Firmware geschrieben wurde, und zeigt die aktuelle Version (**2.0.2**). Ignorieren Sie zu diesem Zeitpunkt ``Initialzing...`` und alles danach: Der Rover befindet sich noch im **Upload**-Modus und kann daher noch nicht mit der ESP32 CAM kommunizieren. Klicken Sie dann auf **Next**.

   .. code-block::

      Reading firmwares/galaxy-rvr-2.0.2.hex
      Resetting the board...
      Connecting to the board...
      Firmware written.
      Verified - flash matches the file.

      ---------- serial open at 115200 ----------
      GalaxyRVR version 2.0.2
      Initialzing...
      SET+RESET
      ...SET+RESET
      ...SET+RESET
      ...[FAIL]

#. Folgen Sie nun der Aufforderung: Schalten Sie den Netzschalter ein, stellen Sie den Modusschalter wieder auf seine ursprüngliche Position und drücken Sie die **Reset**-Taste auf dem R3-Board.

   .. image:: img/flasher_step3_run.jpg
      :width: 500

#. Das Log-Fenster zeigt dann die aktuelle ESP32-CAM-Firmware an.

   * Wenn die ESP32-CAM-Firmware **1.5.0 oder höher** ist, zeigt das Log die UNO-R3-Firmware, die ESP32-CAM-Firmware und schließlich eine Webadresse wie ``http://xxx.xxx.xx.xxx:9000/mjpg`` an.
   * Wenn sie **niedriger als 1.5.0** ist, zeigt das Log-Fenster an, dass die ESP32-CAM-Firmware aktualisiert werden muss — fahren Sie mit :ref:`update_esp32_firmware` fort.

   .. image:: img/flasher_step3.jpg
      :width: 500


.. _update_esp32_firmware:

2. Aktualisieren der ESP32-CAM-Firmware
---------------------------------------

Die ESP32 CAM sendet den WLAN-Hotspot aus und nimmt Videos für den GalaxyRVR auf.
Wenn die Firmware veraltet ist, funktionieren diese Funktionen möglicherweise nicht richtig. Befolgen Sie die nachstehenden Schritte, um die Firmware zu aktualisieren.

#. Schalten Sie den Netzschalter des GalaxyRVR ein. Um die ESP32 CAM zu starten, stellen Sie den Modus auf **Run** und drücken Sie die **Reset**-Taste auf dem R3-Board.

   .. image:: img/camera_run.png
        :width: 500
        :align: center

#. Laden Sie die Firmware-Datei herunter.

   * |download_galaxyrvr_filmware|

#. Entpacken Sie die heruntergeladene ZIP-Datei. Suchen Sie die Firmware-Datei mit dem Namen ``ai-camera-firware.ino.x.x.x.bin`` und übertragen Sie sie auf Ihr mobiles Gerät. Sie können jede Dateimanager-App verwenden, z. B. ES File Explorer oder ein Dateiübertragungsprogramm.

   .. image:: img/firmware_bin_file.png
        :align: center

#. Verbinden Sie Ihr mobiles Gerät mit dem WLAN-Netzwerk des GalaxyRVR.

   * Der Netzwerkname (SSID) lautet ``GalaxyRVR`` und das Passwort ist ``12345678``.
   * Wenn eine Warnung mit dem Hinweis „Kein Internetzugriff“ erscheint, wählen Sie bitte die Option **„Verbunden bleiben“**.

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Öffnen Sie einen Webbrowser auf Ihrem mobilen Gerät und rufen Sie ``http://192.168.4.1`` auf, um die OTA-Update-Seite der ESP32 CAM zu öffnen.


.. note:: Auf dieser Seite sehen Sie die OTA-Upgrade-Optionen in einer von zwei Oberflächen. Version A (die erstere) und Version B (die letztere) erscheinen je nach Ihrer Firmware-Version. Wählen Sie einfach die entsprechenden Upgrade-Schritte für die Oberfläche aus, die Sie sehen.

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center


**Version A**

   6. Wählen Sie auf der OTA-Seite die Firmware-Datei aus und starten Sie das Update:

      * Wählen Sie die zuvor heruntergeladene Datei ``ai-camera-firmware-vX.X.X-ota.bin`` auf Ihrem Gerät aus und klicken Sie auf **Add**.
      * Klicken Sie auf die Schaltfläche **Update**, um das Firmware-Update zu starten, und warten Sie, bis es abgeschlossen ist.

      .. image:: img/faq_ota_a.png
         :width: 700


   #. Nach Abschluss des Updates ändert sich der Name des WLAN-Hotspots des GalaxyRVR in „AI Camera-xxxxxx“, das Passwort bleibt „12345678“.


**Version B**


   6. Überprüfen Sie auf der **OTA**-Seite die aktuell auf der Webseite angezeigte Firmware-Version.

      * Wenn Ihre Versionsnummer **1.5.0 oder höher** ist, ist kein Update erforderlich. Sie können die restlichen Schritte überspringen und direkt mit :ref:`quick_start` fortfahren.
      * Wenn die Version **niedriger als 1.5.0** ist, fahren Sie bitte mit dem Update fort.

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center


   #. Tippen Sie auf **Upgrade Firmware**, wählen Sie die Firmware-Datei aus und warten Sie, bis das Update abgeschlossen ist:

      * Tippen Sie auf die Schaltfläche **Upgrade Firmware** und wählen Sie dann die zuvor heruntergeladene Datei ``ai-camera-firware.ino.x.x.x.bin`` auf Ihrem Gerät aus.
      * Das Update beginnt sofort und dauert in der Regel 1-2 Minuten. Wählen Sie nach Abschluss **CONFIRM**, um den GalaxyRVR neu zu starten.

      .. image:: img/faq_ota_b.png
         :width: 700

   #. Nach Abschluss des Updates ändert sich der Name des WLAN-Hotspots des GalaxyRVR in „AI Camera-xxxxxx“, das Passwort bleibt „12345678“.


3. Startprüfung
---------------

* Laden Sie vor der ersten Nutzung des GalaxyRVR den Akku mit dem mitgelieferten USB-Typ-C-Kabel vollständig auf.
* Schalten Sie den Netzschalter ein.
* Stellen Sie den Modus auf **Run** und drücken Sie die **Reset**-Taste auf dem R3-Board.
* Der untere Lichtstreifen blinkt **grün** und zeigt damit einen erfolgreichen Start an.

.. raw:: html

   <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=_idwN0kJrxbVW-5H" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
