

.. _update_firmware:

Firmware aktualisieren
==========================

Ihr Gerät verfügt möglicherweise nicht über die neueste Firmware, da das Produkt ständig verbessert wird.
Wir empfehlen, die Firmware vor der ersten Verwendung zu aktualisieren, um einen reibungslösen Betrieb sicherzustellen. Die Aktualisierung der Firmware gewährleistet:

* **Fehlerbehebungen**: Behebt bekannte Probleme und verbessert die Stabilität.
* **App-Kompatibilität**: Die neueste Firmware ist erforderlich, damit die RoboPilot-App und Mammoth Coding korrekt funktionieren.
* **Neue Funktionen**: Firmware-Updates können neue Fähigkeiten und Verbesserungen hinzufügen.
* **Bessere Leistung**: Optimierungen für WLAN-Konnektivität, Kamera-Streaming und Motorsteuerung.

.. note::
   Wenn Sie die Firmware nicht aktualisieren und Ihre aktuelle Konfiguration beibehalten möchten, lesen Sie bitte die `GalaxyRVR v1 Dokumentation <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_.


.. raw:: html

   <iframe width="600" height="400" src="https://www.youtube.com/embed/Tl2W26pIQoU?si=98bbfUPc1g2cEz3A" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


1. Prüfen, ob ein Update erforderlich ist
-----------------------------------------

#. Schalten Sie den GalaxyRVR ein und überprüfen Sie den unteren Lichtstreifen.

   * Laden Sie den Akku vor der ersten Verwendung des GalaxyRVR mit dem mitgelieferten Typ-C-USB-Kabel vollständig auf.
   * Schalten Sie den Netzschalter ein.
   * Stellen Sie den Modus auf **Run** und drücken Sie die **Reset**-Taste auf dem R3-Board.
   * Der untere Lichtstreifen beginnt zu blinken und zeigt damit einen erfolgreichen Start an.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

#. Überprüfen Sie den unteren Lichtstreifen.

   * Wenn der untere Lichtstreifen **grün blinkt**, ist Ihre ESP32-Firmware bereits auf dem neuesten Stand. Sie können mit :ref:`quick_start` fortfahren.
   * Wenn der untere Lichtstreifen in einer **anderen Farbe** blinkt, müssen Sie:

     - :ref:`update_esp32_firmware`
     - :ref:`update_r3_firmware`


.. _update_esp32_firmware:

2. Aktualisieren der ESP32-CAM-Firmware
------------------------------------------

Der ESP32-CAM sendet den WLAN-Hotspot aus und nimmt Videos für den GalaxyRVR auf.
Wenn die Firmware veraltet ist, funktionieren diese Funktionen möglicherweise nicht richtig. Führen Sie die folgenden Schritte aus, um die Firmware zu aktualisieren.

#. Schalten Sie den Netzschalter des GalaxyRVR ein. Um den ESP32-CAM zu starten, stellen Sie den Modus auf **Run** und drücken Sie die **Reset**-Taste auf dem R3-Board.

   .. image:: img/camera_run.png
        :width: 500
        :align: center

#. Laden Sie die Firmware-Datei herunter.

   * |download_galaxyrvr_filmware|

#. Entpacken Sie die heruntergeladene ZIP-Datei. Suchen Sie die Firmware-Datei mit dem Namen ``ai-camera-firware.ino.x.x.x.bin`` und übertragen Sie sie auf Ihr Mobilgerät. Sie können jede Dateimanager-App verwenden, z. B. ES File Explorer oder ein Dateiübertragungsprogramm.

   .. image:: img/firmware_bin_file.png
        :align: center

#. Verbinden Sie Ihr Mobilgerät mit dem WLAN-Netzwerk des GalaxyRVR.

   * Der Netzwerkname (SSID) lautet ``GalaxyRVR`` und das Passwort ist ``12345678``.
   * Wenn eine Warnung mit dem Hinweis "Kein Internetzugriff" erscheint, wählen Sie bitte die Option **"Trotzdem verbinden"**.

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Öffnen Sie einen Webbrowser auf Ihrem Mobilgerät und navigieren Sie zu ``http://192.168.4.1``, um die OTA-Update-Seite des ESP32-CAM aufzurufen.


.. note:: Auf dieser Seite sehen Sie die OTA-Upgrade-Optionen in einer von zwei Oberflächen. Version A (die erstere) und Version B (die letztere) werden je nach Ihrer Firmware-Version angezeigt. Wählen Sie einfach die entsprechenden Upgrade-Schritte basierend auf der angezeigten Oberfläche aus.

   .. image:: img/firmware_access_ab.png
      :width: 90%
      :align: center


**Version A**

   6. Klicken Sie auf der OTA-Seite auf die Schaltfläche, um die Firmware-Datei auszuwählen.

      .. image:: img/faq_cam_ota_choose.png
         :width: 300

   #. Wählen Sie die zuvor heruntergeladene Datei ``ai-camera-firmware-vX.X.X-ota.bin`` auf Ihrem Gerät aus und klicken Sie auf **Hinzufügen**.

      .. image:: img/faq_cam_ota_file.png
         :width: 300

   #. Klicken Sie auf die Schaltfläche **Update**, um den Firmware-Update-Vorgang zu starten.

      .. image:: img/faq_cam_ota_update.png
         :width: 300

   #. Warten Sie, bis das Update abgeschlossen ist.

      .. image:: img/faq_cam_ota_finish.png
         :width: 300

   #. Nach Abschluss des Updates können Sie den Webbrowser schließen. Drücken Sie die **Reset**-Taste, um das Gerät neu zu starten. Der ESP32-CAM ist nun betriebsbereit.

      .. image:: img/camera_reset.png
         :width: 500

   .. note:: Nach Abschluss des Updates ändert sich der Name des WLAN-Hotspots des GalaxyRVR in "AI Camera-xxxxxx", das Passwort bleibt "12345678".


**Version B**


   6. Überprüfen Sie auf der **OTA**-Seite die auf der Webseite angezeigte aktuelle Firmware-Version.

      * Wenn Ihre Versionsnummer **höher als 1.5.1** ist, ist kein Update erforderlich. Sie können die restlichen Schritte überspringen und direkt mit :ref:`quick_start` fortfahren.
      * Wenn die Version **1.5.1 oder niedriger** ist, fahren Sie bitte mit dem Update fort.

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center

   #. Tippen Sie auf die Schaltfläche **Firmware upgraden**.

      .. image:: img/firmware_tap.jpg
         :width: 50%
         :align: center

   #. Ein Dateiauswahldialog wird angezeigt. Navigieren Sie zu der Datei ``ai-camera-firware.ino.x.x.x.bin``, die Sie zuvor auf Ihr Mobilgerät übertragen haben, und wählen Sie sie aus.

      .. image:: img/firmware_select.jpg
         :width: 50%
         :align: center

   #. Das Firmware-Update beginnt sofort, nachdem Sie die Datei ausgewählt haben.

      .. image:: img/firmware_upgrade.jpg
         :width: 50%
         :align: center

   #. Warten Sie, bis das Firmware-Upgrade abgeschlossen ist.

      * Der Upload-Vorgang dauert in der Regel 1–2 Minuten. Nach Abschluss wird eine Erfolgsmeldung in einem Pop-up-Fenster angezeigt.
      * Sie können dann **BESTÄTIGEN** auswählen, um den GalaxyRVR neu zu starten, oder **SCHLIESSEN**, um das Fenster zu schließen.

      .. image:: img/firmware_finish.jpg
         :width: 50%
         :align: center


.. _update_r3_firmware:

3. Aktualisieren der R3-Board-Firmware
------------------------------------------

Das R3-Board enthält eine integrierte Firmware, die die Kommunikation mit der RoboPilot-App und Mammoth Coding ermöglicht.

Sie müssen diese Firmware erneut hochladen, wenn:

- Ihr Gerät eine ältere Firmware-Version verwendet, oder
- Sie Ihren eigenen Arduino-Code geflasht haben und die Kompatibilität wiederherstellen möchten.

Führen Sie die folgenden Schritte aus, um die Kommunikationsfirmware neu zu installieren.

#. Verbinden Sie das Arduino und den Computer mit einem USB-Kabel und stellen Sie dann den **Upload**-Schalter des Fahrzeugs auf die Upload-Seite.

   .. image:: img/camera_upload.png
        :width: 500
        :align: center

   .. note:: Es ist der USB-Typ-B-Anschluss zum Verbinden mit dem Arduino, nicht der USB-Typ-C-Anschluss zum Laden.

#. Überprüfen Sie, ob die Firmware-Dateien heruntergeladen wurden.

   * |download_galaxyrvr_filmware|

#. Führen Sie das Update-Skript aus

   * Öffnen Sie den Ordner ``galaxy-rvr.ino.xxx`` (im vorherigen Schritt heruntergeladen und installiert).
   * Doppelklicken Sie auf das Skript ``update-arduino-firmware.bat``.
   * Ein Eingabeaufforderungsfenster wird automatisch geöffnet.

   .. image:: img/faq_bat_file.png

#. Wählen Sie die serielle Schnittstelle aus und laden Sie hoch

   * In der Eingabeaufforderung wird eine Liste der verfügbaren seriellen Schnittstellen angezeigt.
   * Geben Sie die links angezeigte Sequenznummer ein, um die serielle Schnittstelle des Arduino Uno auszuwählen.
   * Drücken Sie die **Eingabetaste**, um den automatischen Upload zu starten.
   * Beispiel: Wenn die Liste `1 USB-SERIALXXX (COMxx)` anzeigt, geben Sie **1** ein und drücken Sie die **Eingabetaste**.

   .. image:: img/faq_select_com.png

#. Nachdem der Upload abgeschlossen ist, können Sie das USB-Kabel abziehen.

   .. image:: img/faq_uno_updating.png

   .. note::

      Dieser Code ermöglicht es dem GalaxyRVR, auf App-Befehle zu reagieren. Sie müssen keinen zusätzlichen Code hochladen, wenn Sie die RoboPilot-Fernsteuerungs-App oder die Mammoth-Coding-Software verwenden.

#. Sie können nun mit :ref:`quick_start` fortfahren, um Ihre Reise mit dem GalaxyRVR zu beginnen!
