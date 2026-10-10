.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _update_firmware:

Firmware aktualisieren
======================

Ihr Gerät verfügt möglicherweise nicht über die neueste Firmware, da das Produkt ständig verbessert wird. Wir empfehlen, die Firmware vor der ersten Nutzung zu aktualisieren, damit alles reibungslos funktioniert. Die Aktualisierung der Firmware stellt Folgendes sicher:

* **Fehlerbehebungen**: Behebt bekannte Probleme und verbessert die Stabilität.
* **App-Kompatibilität**: Die neueste Firmware wird für die korrekte Funktion der RoboPilot-App und von Mammoth Coding benötigt.
* **Neue Funktionen**: Firmware-Updates können neue Fähigkeiten und Verbesserungen hinzufügen.
* **Bessere Leistung**: Optimierungen für WLAN-Konnektivität, Kamera-Streaming und Motorsteuerung.

.. note::
   Falls Sie die Firmware nicht aktualisieren möchten und Ihre aktuelle Konfiguration weiterhin verwenden wollen, finden Sie Informationen in der `GalaxyRVR v1-Dokumentation <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_.


.. raw:: html

   <iframe width="600" height="400" src="https://www.youtube.com/embed/Tl2W26pIQoU?si=98bbfUPc1g2cEz3A" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


.. _update_uno_firmware:

1. Aktualisieren der UNO R3-Firmware
----------------------------------------

Das R3-Board enthält eine integrierte Firmware, die die Kommunikation mit der RoboPilot-App und Mammoth Coding ermöglicht.

Sie müssen diese Firmware neu hochladen, wenn:

- Ihr Gerät eine ältere Firmware-Version verwendet, oder
- Sie Ihren eigenen Arduino-Code geflasht haben und die Kompatibilität wiederherstellen möchten.

Sie können die Kommunikationsfirmware mit dem Flasher im Browser neu installieren; auf Ihrem Computer ist keine zusätzliche Software erforderlich.

**Methode 1: Flasher im Browser**

#. Schalten Sie den GalaxyRVR ein, verbinden Sie das USB-A-auf-B-Kabel (nicht das USB-Typ-C-Kabel) mit der **Hauptplatine** und stellen Sie den **Upload**-Schalter des Fahrzeugs auf das Upload-Ende.

#. Entfernen Sie vor dem Flashen die ESP32 CAM aus ihrem Sockel – sie teilt sich dieselben RX- und TX-Pins mit der R3-Platine, siehe :ref:`FAQ 7 <faq_r3_upload_bat>`.

#. Öffnen Sie auf einem Computer |link_galaxy_rvr_flasher| in **Chrome** oder **Edge** und wählen Sie die Firmware-Version:

   * Version **2.0.0** ist für die aktuelle Generation des GalaxyRVR.
   * Version **1.1.0** ist für die erste Generation des GalaxyRVR.

   Wenn Sie sich nicht sicher sind, welche Generation Sie haben, prüfen Sie das Etikett auf der Schachtel oder kontaktieren Sie uns.

#. Klicken Sie auf **Connect & Flash** und wählen Sie im Dialog den seriellen Anschluss Ihrer Platine. Das Update startet automatisch und ist in etwa einer Minute abgeschlossen.

   .. image:: img/faq_web_flasher_en.png
      :width: 600
      :align: center

#. Wenn das Update abgeschlossen ist, stellen Sie den Schalter wieder auf **Run**, stecken Sie die ESP32 CAM wieder ein und schalten Sie den GalaxyRVR erneut ein.

.. note::

   * Diese Seite verwendet Web Serial. Verwenden Sie daher **Chrome** oder **Edge** auf einem Computer und stellen Sie sicher, dass die Seite über **https** geöffnet wird. Unter Windows können Sie im Geräte-Manager prüfen, ob **USB-SERIAL CH340** aufgeführt ist, um sicherzustellen, dass der USB-Seriell-Treiber installiert ist.
   * Schließen Sie andere Programme, die den seriellen Anschluss verwenden könnten, z. B. die Arduino IDE, den seriellen Monitor oder einen weiteren Browser-Tab.

**Methode 2: Aktualisierungsskript**

.. note::

   Wenn Sie einen Mac verwenden, befolgen Sie bitte die macOS-spezifische Anleitung:

   :ref:`uno_firmware_mac`

#. Verbinden Sie den Arduino über ein USB-A-auf-B-Kabel (nicht USB-Typ-C) mit dem Computer und stellen Sie den Modusschalter auf **Upload**.

   .. image:: img/camera_upload.png
        :width: 500
        :align: center

#. Überprüfen Sie, ob die Firmware-Dateien heruntergeladen wurden.

   * |download_galaxyrvr_filmware|

#. Führen Sie das Update-Skript aus.

   * Öffnen Sie den Ordner ``galaxy-rvr.ino.xxx`` (im vorherigen Schritt heruntergeladen und installiert).
   * Doppelklicken Sie auf das Skript ``update-arduino-firmware.bat``.
   * Ein Eingabeaufforderungsfenster wird automatisch geöffnet.

   .. image:: img/faq_bat_file.png

#. Wählen Sie die serielle Schnittstelle aus und laden Sie hoch.

   * In der Eingabeaufforderung wird eine Liste der verfügbaren seriellen Schnittstellen angezeigt.
   * Geben Sie die links angezeigte Sequenznummer ein, um die serielle Schnittstelle des Arduino Uno auszuwählen.
   * Drücken Sie die **Eingabetaste**, um den automatischen Upload zu starten.
   * Beispiel: Wenn die Liste `1 USB-SERIALXXX (COMxx)` anzeigt, geben Sie **1** ein und drücken Sie die **Eingabetaste**.

   .. image:: img/faq_select_com.png

#. Nachdem der Upload abgeschlossen ist, können Sie das USB-Kabel abziehen.

   .. image:: img/faq_uno_updating.png


.. _update_esp32_firmware:

2. Aktualisieren der ESP32-CAM-Firmware
---------------------------------------

Die ESP32-CAM sendet den WLAN-Hotspot aus und nimmt Videos für den GalaxyRVR auf.
Wenn die Firmware veraltet ist, funktionieren diese Funktionen möglicherweise nicht richtig. Befolgen Sie die nachstehenden Schritte, um die Firmware zu aktualisieren.

#. Schalten Sie den Netzschalter des GalaxyRVR ein. Um die ESP32-CAM zu starten, stellen Sie den Modus auf **Run** und drücken Sie die **Reset**-Taste auf dem R3-Board.

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
   * Wenn eine Warnung "Kein Internetzugriff" angezeigt wird, wählen Sie bitte die Option **"Trotzdem verbinden"**.

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Öffnen Sie einen Webbrowser auf Ihrem mobilen Gerät und rufen Sie ``http://192.168.4.1`` auf, um auf die OTA-Update-Seite der ESP32-CAM zuzugreifen.


.. note:: Auf dieser Seite werden Ihnen die OTA-Upgrade-Optionen in einer von zwei Oberflächen angezeigt. Version A (die erstere) und Version B (die letztere) werden je nach Ihrer Firmware-Version angezeigt. Wählen Sie einfach die entsprechenden Upgrade-Schritte basierend auf der angezeigten Oberfläche aus.

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center


**Version A**

   6. Wählen Sie auf der OTA-Seite die Firmware-Datei aus und starten Sie das Update:

      * Wählen Sie die zuvor heruntergeladene Datei ``ai-camera-firmware-vX.X.X-ota.bin`` auf Ihrem Gerät aus und klicken Sie auf **Add**.
      * Klicken Sie auf die Schaltfläche **Update**, um das Firmware-Update zu starten, und warten Sie, bis es abgeschlossen ist.

      .. image:: img/faq_ota_a.png
         :width: 700

   #. Nach Abschluss des Updates ändert sich der Name des WLAN-Hotspots des GalaxyRVR in "AI Camera-xxxxxx", das Passwort bleibt "12345678".


**Version B**


   6. Überprüfen Sie auf der **OTA**-Seite die aktuell angezeigte Firmware-Version.

      * Wenn Ihre Versionsnummer **höher als 1.5.1** ist, ist kein Update erforderlich. Sie können die restlichen Schritte überspringen und direkt mit dem :ref:`quick_start` fortfahren.
      * Wenn die Version **1.5.1 oder niedriger** ist, fahren Sie bitte mit dem Update fort.

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center


   #. Tippen Sie auf **Upgrade Firmware**, wählen Sie die Firmware-Datei aus und warten Sie, bis das Update abgeschlossen ist:

      * Tippen Sie auf die Schaltfläche **Upgrade Firmware** und wählen Sie die zuvor heruntergeladene Datei ``ai-camera-firware.ino.x.x.x.bin`` auf Ihrem Gerät aus.
      * Das Update beginnt sofort und dauert in der Regel 1-2 Minuten. Wählen Sie nach Abschluss **CONFIRM**, um den GalaxyRVR neu zu starten.

      .. image:: img/faq_ota_b.png
         :width: 700

   #. Nach Abschluss des Updates ändert sich der Name des WLAN-Hotspots des GalaxyRVR in "AI Camera-xxxxxx", das Passwort bleibt "12345678".


3. Startprüfung
--------------------

#. Schalten Sie den GalaxyRVR ein und überprüfen Sie den unteren Lichtstreifen.

   * Laden Sie vor der ersten Nutzung des GalaxyRVR den Akku mit dem mitgelieferten USB-C-Kabel vollständig auf.
   * Schalten Sie den Netzschalter ein.
   * Stellen Sie den Modus auf **Run** und drücken Sie die **Reset**-Taste auf dem R3-Board.
   * Der untere Lichtstreifen beginnt zu blinken und zeigt damit einen erfolgreichen Start an.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

#. Überprüfen Sie den unteren Lichtstreifen.

   * Wenn der untere Lichtstreifen **grün blinkt**, läuft die R3-Firmware korrekt. Sie können mit dem :ref:`quick_start` fortfahren.
   * Wenn der untere Lichtstreifen in einer **anderen Farbe blinkt**, installieren Sie die R3-Firmware mit :ref:`update_uno_firmware` neu.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

.. important::

   * Diese Firmware ermöglicht es dem GalaxyRVR, auf App-Befehle zu reagieren.
   * Sie müssen keinen zusätzlichen Code hochladen, wenn Sie die RoboPilot-Fernsteuerungs-App oder die Mammoth-Coding-Software verwenden.
   * Sie können nun mit dem :ref:`quick_start` fortfahren, um Ihre Reise mit dem GalaxyRVR zu beginnen!
