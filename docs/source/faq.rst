.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

FAQ
==============

1. Warum sollte ich die Firmware aktualisieren?
----------------------------------------------------------------------------------------

SunFounder verbessert kontinuierlich die Firmware des GalaxyRVR, um ein besseres Benutzererlebnis zu bieten. Wir empfehlen, die Firmware vor der ersten Nutzung zu aktualisieren, damit alles reibungslos funktioniert. Die Aktualisierung der Firmware gewährleistet:

* **Fehlerbehebungen**: Behebt bekannte Probleme und verbessert die Stabilität.
* **App-Kompatibilität**: Die neueste Firmware wird benötigt, damit die RoboPilot-App und Mammoth Coding korrekt funktionieren.
* **Neue Funktionen**: Firmware-Updates können neue Fähigkeiten und Verbesserungen hinzufügen.
* **Bessere Leistung**: Optimierungen für WLAN-Konnektivität, Kamera-Streaming und Motorsteuerung.

Schritt-für-Schritt-Anleitungen zum Update finden Sie unter :ref:`update_firmware`.

.. note::
   Wenn Sie die Firmware nicht aktualisieren und Ihre aktuelle Konfiguration beibehalten möchten, können Sie die `GalaxyRVR v1 Dokumentation <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_ konsultieren.


2. Kann keine Verbindung zum GalaxyRVR hergestellt werden?
-------------------------------------------------------------------------------------------------

Wenn Sie keine Verbindung zum GalaxyRVR herstellen können, überprüfen Sie bitte Folgendes:

1. **Überprüfen Sie den Akku**: Schauen Sie sich die Akkuanzeigen am Rover an. Wenn beide LEDs aus sind, ist der Akku schwach. Laden Sie den Rover mit einem Typ-C-USB-Kabel auf.
2. **Überprüfen Sie die ESP32 CAM**: Stellen Sie sicher, dass die ESP32 CAM richtig in ihrem Steckplatz sitzt. Wenn die LED der ESP32 CAM nicht leuchtet, erhält das Kameramodul möglicherweise keine Spannung oder könnte beschädigt sein. Die ESP32 CAM erstellt den WLAN-Hotspot — wenn sie nicht funktioniert, wird kein Netzwerk angezeigt.
3. **Überprüfen Sie den Modusschalter**: Stellen Sie sicher, dass der Modusschalter auf **Run** (nicht **Upload**) steht. Der WLAN-Hotspot funktioniert nur im Run-Modus.

   .. image:: img/camera_run.png
        :width: 500
        :align: center

4. **Setzen Sie das R3-Board zurück**: Drücken Sie nach dem Umschalten in den Run-Modus die **Reset**-Taste auf dem R3-Board. Der untere LED-Streifen sollte blinken, um einen erfolgreichen Start anzuzeigen.
5. **Überprüfen Sie das WLAN-Passwort**: Der standardmäßige Hotspot-Name (SSID) lautet ``GalaxyRVR`` und das Passwort ``12345678``. Stellen Sie sicher, dass Sie das Passwort richtig eingegeben haben.
6. **WLAN-Interferenzen**: Andere Geräte auf demselben WLAN-Kanal können Verbindungsprobleme verursachen. Wenn Sie Interferenzen vermuten, versuchen Sie, :ref:`den WLAN-Kanal zu wechseln <change_wifi_channel>`.
7. **Nach einem Firmware-Update**: Wenn Sie gerade die ESP32-CAM-Firmware aktualisiert haben und das WLAN nicht mehr funktioniert, lesen Sie :ref:`faq_wifi_after_update`.
8. **Überprüfen Sie die Verbindung Ihres mobilen Geräts**: Wenn Sie GalaxyRVR im AP-Modus (Standard) verwenden, verbinden Sie Ihr mobiles Gerät mit dem GalaxyRVR-Hotspot. Falls Sie :ref:`ein Heim-WLAN konfiguriert haben <ap_to_sta>`, stellen Sie sicher, dass Ihr mobiles Gerät mit dem **selben** Heim-WLAN verbunden ist.


3. Die untere Leuchte leuchtet dauerhaft orange und es erscheint kein WLAN-Hotspot?
----------------------------------------------------------------------------------------------

Wenn der untere LED-Streifen des GalaxyRVR ein **dauerhaft orangefarbenes Licht** anzeigt und das WLAN-Netzwerk ``GalaxyRVR`` nicht erscheint, liegt die Ursache in einem **Firmware-Versionskonflikt**:

- Die **ESP32-CAM**-Firmware ist noch eine ältere Version (1.4.x oder 1.3.x)
- Die **UNO-R3-Board**-Firmware wurde auf Version 2.x aktualisiert
- Der Versionskonflikt verhindert die Kommunikation zwischen der ESP32 CAM und dem UNO R3

Um dies zu beheben, führen Sie die folgenden Schritte **in der genauen Reihenfolge** aus:

#. **Setzen Sie zuerst die UNO-R3-Firmware auf Version 1.x zurück**:

   Folgen Sie der Anleitung in der v1-Dokumentation: `GalaxyRVR v1 — So laden Sie den galaxy-rvr.ino-Code hoch <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/faq.html#how-to-upload-the-galaxy-rvr-ino-code>`_

#. **Aktualisieren Sie beide Firmware in der Reihenfolge ESP32 CAM → UNO R3**:

   Folgen Sie der aktualisierten Anleitung: :ref:`update_firmware`

.. note::

   Die Reihenfolge ist wichtig — aktualisieren Sie immer zuerst die ESP32 CAM, dann das R3-Board. Das Überspringen des Rollback-Schritts oder das Ändern der Reihenfolge behebt das Problem nicht.



4. RoboPilot-App kann keine Verbindung herstellen?
---------------------------------------------------------------------------------------

Wenn die RoboPilot-App Ihren GalaxyRVR nicht finden oder keine Verbindung herstellen kann, überprüfen Sie Folgendes:

1. **Ist die ESP32-CAM-Firmware auf dem neuesten Stand?** Eine veraltete ESP32-CAM-Firmware kann Verbindungsprobleme verursachen. Folgen Sie :ref:`update_esp32_firmware`, um dies zu überprüfen und zu aktualisieren.
2. **Ist die R3-Firmware auf dem neuesten Stand?** Das R3-Board muss über die werksseitige Kommunikationsfirmware verfügen. Wenn Sie benutzerdefinierten Arduino-Code hochgeladen haben, überschreibt dies die Firmware und unterbricht die RoboPilot-Kommunikation. Folgen Sie :ref:`update_r3_firmware`, um sie wiederherzustellen.
3. **Steht der Modusschalter auf Run?** Der Modusschalter muss auf **Run** (nicht Upload) stehen, damit der WLAN-Hotspot funktioniert.
4. **Ist Ihr mobiles Gerät mit dem richtigen WLAN-Netzwerk verbunden?** Verbinden Sie sich mit dem GalaxyRVR-Hotspot (``GalaxyRVR`` / ``12345678``), oder falls Sie ein Heim-WLAN konfiguriert haben, mit diesem selben Netzwerk.
5. **Versuchen Sie einen Neustart**: Schalten Sie in den **Run**-Modus und drücken Sie die **Reset**-Taste, dann versuchen Sie erneut, eine Verbindung herzustellen.

Wenn nichts davon hilft, versuchen Sie es mit :ref:`faq_wifi_after_update`.


5. Mammoth Coding (Scratch)-App kann keine Verbindung herstellen?
---------------------------------------------------------------------------------------

Wenn Mammoth Coding keine Verbindung zu Ihrem GalaxyRVR herstellen kann, überprüfen Sie Folgendes:

1. **Ist die ESP32-CAM-Firmware auf dem neuesten Stand?** Die ESP32 CAM verwaltet die WLAN-Verbindung, auf die Mammoth Coding angewiesen ist. Folgen Sie :ref:`update_esp32_firmware`, um sicherzustellen, dass sie auf dem neuesten Stand ist.
2. **Ist die R3-Firmware auf dem neuesten Stand?** Mammoth Coding benötigt die werksseitige Kommunikationsfirmware auf dem R3-Board. Wenn Sie Ihren eigenen Arduino-Code hochgeladen haben, wird die Kommunikationsfirmware überschrieben. Folgen Sie :ref:`update_r3_firmware`, um sie wiederherzustellen.
3. **Steht der Modusschalter auf Run?** Der Modusschalter muss auf **Run** stehen, damit der WLAN-Hotspot aktiv ist.
4. **Ist Ihr mobiles Gerät mit dem richtigen WLAN-Netzwerk verbunden?** Stellen Sie sicher, dass Ihr Gerät mit dem GalaxyRVR-Hotspot oder demselben auf dem Rover konfigurierten Heim-WLAN verbunden ist.

.. note::
   Wenn Sie **sowohl** Arduino-Programmierung als auch Mammoth Coding verwenden möchten, beachten Sie, dass Sie jedes Mal die R3-Firmware neu hochladen müssen, wenn Sie zwischen beiden wechseln.

.. _install_lib:

6. Kompilierungsfehler: ``SoftPWM.h`` oder ``SunFounder_AI_Camera.h``: Datei oder Verzeichnis nicht gefunden?
---------------------------------------------------------------------------------------------------------------------
Wenn Sie die Meldung „Kompilierungsfehler: ``SoftPWM.h``: Datei oder Verzeichnis nicht gefunden" erhalten, bedeutet dies, dass die SoftPWM-Bibliothek nicht installiert ist.

Bitte installieren Sie die beiden erforderlichen Bibliotheken ``SoftPWM`` und ``SunFounder AI Camera`` wie gezeigt.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

Für die Bibliothek ``SunFounder AI Camera`` müssen Sie „INSTALL ALL" auswählen, um gleichzeitig die erforderliche ``ArduinoJson``-Abhängigkeit zu installieren.

    .. image:: img/faq_install_ai_camera.png

7. avrdude: stk500_getsync() Versuch 10 von 10: nicht synchronisiert: resp=0x6e?
-------------------------------------------------------------------------------------
Wenn die folgende Meldung weiterhin erscheint, nachdem Sie auf die Schaltfläche **Upload** geklickt haben und das Board sowie der Port korrekt ausgewählt wurden.

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00

In diesem Fall müssen Sie sicherstellen, dass die ESP32 CAM ausgesteckt ist.

Die ESP32-CAM und das Arduino-Board teilen sich dieselben RX (Empfangs-) und TX (Sende-)Pins. Bevor Sie Code hochladen, müssen Sie daher zuerst die ESP32-CAM trennen, um Konflikte oder mögliche Probleme zu vermeiden.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Nachdem der Code erfolgreich hochgeladen wurde, müssen Sie den Schalter nach links bewegen, um die ESP32 CAM zu starten, falls Sie sie verwenden möchten.

    .. image:: img/camera_run.png
        :width: 500
        :align: center

.. _change_wifi_channel:

8. Wie kann ich den WLAN-Kanal ändern?
----------------------------------------

Das 2,4-GHz-WLAN-Band hat Kanäle von 1 bis 13. Der ESP32 unterstützt Kanäle 1 bis 11. Andere Geräte, die auf demselben Kanal arbeiten, können Interferenzen verursachen, was zu Verbindungsproblemen führt. Um dies zu mildern, können Sie versuchen, den Kanal zu wechseln. Standardmäßig ist der Kanal auf 1 eingestellt. Bei der Auswahl eines neuen Kanals wird empfohlen, jeweils 1–2 Kanäle zu überspringen. Wenn der aktuelle Kanal beispielsweise 1 ist, versuchen Sie zuerst Kanal 3, und falls das Signal weiterhin schwach ist, fahren Sie mit Kanal 5 fort.


#. Schalten Sie den GalaxyRVR ein. Um die ESP32 CAM zu aktivieren, stellen Sie den Modusschalter auf die **Run**-Position und drücken Sie die **Reset**-Taste, um das R3-Board neu zu starten.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Verbinden Sie Ihr mobiles Gerät mit dem WLAN-Netzwerk des GalaxyRVR.

   * Der Netzwerkname (SSID) lautet ``GalaxyRVR`` und das Passwort ``12345678``.
   * Wenn eine Warnung „Kein Internetzugriff" erscheint, wählen Sie bitte die Option **„Verbunden bleiben"**.

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Öffnen Sie einen Webbrowser auf Ihrem mobilen Gerät und gehen Sie zur Adresse ``http://192.168.4.1``. Dort gelangen Sie zum Update-Portal für die ESP32-CAM-Firmware.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. Wählen Sie auf der Seite **AP** einen anderen Kanal aus.

   * Der Standardkanal ist 1. Bei der Auswahl eines neuen Kanals überspringen Sie jeweils 1–2 Kanäle (z. B. von Kanal 1 auf 3 und bei Bedarf auf 5).

   .. image:: img/fap_ap_channel.jpg
        :width: 50%
        :align: center

#. Kehren Sie zur Seite **Base** zurück und klicken Sie auf die Schaltfläche **Reboot**, um den GalaxyRVR neu zu starten. Der GalaxyRVR ist nun für den normalen Betrieb bereit.

   .. image:: img/faq_firmware_reboot.png
        :width: 50%
        :align: center

9. Wie aktualisiere ich die Firmware für die ESP32 CAM?
-----------------------------------------------------------

Um die App-Kompatibilität und optimale Leistung zu gewährleisten, stellen Sie bitte sicher, dass Ihre ESP32-CAM-Firmware auf dem neuesten Stand ist.

Eine detaillierte Schritt-für-Schritt-Anleitung finden Sie unter: :ref:`update_esp32_firmware`

10. Wie stelle ich die R3-Firmware wieder her?
--------------------------------------------------

Das R3-Board des GalaxyRVR wird mit einer Firmware ausgeliefert, die sowohl die RoboPilot-App als auch Mammoth Coding unterstützt.

Wenn Sie diese Firmware überschrieben haben und die Kommunikation wiederherstellen müssen, folgen Sie :ref:`update_r3_firmware`.

.. _ap_to_sta:

11. Wie richte ich die WLAN-Verbindung ein?
-----------------------------------------------------

Standardmäßig arbeitet der GalaxyRVR im **AP-Modus**, bei dem er einen eigenen WLAN-Hotspot erstellt, mit dem sich andere Geräte verbinden können.

Wenn Sie möchten, dass sich der GalaxyRVR mit Ihrem **Heim-WLAN** verbindet, führen Sie die folgenden Schritte aus:


#. Schalten Sie den GalaxyRVR ein. Um die ESP32 CAM zu aktivieren, stellen Sie den Modusschalter auf die **Run**-Position und drücken Sie die **Reset**-Taste, um das R3-Board neu zu starten.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Verbinden Sie Ihr mobiles Gerät mit dem WLAN-Netzwerk des GalaxyRVR.

   * Der Netzwerkname (SSID) lautet ``GalaxyRVR`` und das Passwort ``12345678``.
   * Wenn eine Warnung „Kein Internetzugriff" erscheint, wählen Sie bitte die Option **„Verbunden bleiben"**.

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Öffnen Sie einen Webbrowser auf Ihrem mobilen Gerät und gehen Sie zur Adresse ``http://192.168.4.1``. Dort gelangen Sie zum Update-Portal für die ESP32-CAM-Firmware.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. Geben Sie auf der Seite **WiFi** den Namen (SSID) und das Passwort Ihres Heim-WLANs ein.

   .. image:: img/faq_wifi.png
        :width: 50%
        :align: center

#. Tippen Sie auf die Schaltfläche **CONFIRM**.

   * Der GalaxyRVR wird versuchen, eine Verbindung zu Ihrem Heim-WLAN herzustellen.
   * Wenn die Verbindung erfolgreich ist, stoppt das rotierende Symbol und ein Häkchen erscheint.

#. Verbinden Sie Ihr mobiles Gerät nach dem Neustart mit demselben Heim-WLAN.

#. Sie können jetzt über die RoboPilot-App oder Mammoth Coding eine Verbindung zum GalaxyRVR herstellen.

.. _faq_wifi_after_update:

12. Wie setze ich die ESP32 CAM auf die Werkseinstellungen zurück?
---------------------------------------------------------------------------------------

Wenn der WLAN-Hotspot des GalaxyRVR nicht erscheint oder Sie nach einem Update der ESP32-CAM-Firmware keine Verbindung herstellen können, verursachen möglicherweise die alten WLAN-Konfigurationsdaten im Flash-Speicher der ESP32 CAM einen Konflikt.

Um dies zu beheben, müssen Sie die ESP32 CAM auf die Werkseinstellungen zurücksetzen, indem Sie die gespeicherten Daten löschen. Dazu überbrücken Sie die Pins **IO13** und **IO15** an der ESP32 CAM:

#. Schalten Sie den GalaxyRVR aus.
#. Lokalisieren Sie die Pins **IO13** und **IO15** auf dem ESP32-CAM-Modul.

   .. image:: img/esp32cam_io1315.png
        :width: 300
        :align: center

#. Verwenden Sie ein Jumper-Kabel oder eine Pinzette, um die Pins **IO13** und **IO15** miteinander zu überbrücken (zu verbinden).
#. Schalten Sie den GalaxyRVR bei weiterhin überbrückten Pins ein.
#. Beobachten Sie die LED der ESP32 CAM — sobald sie **zweimal schnell blinkt**, entfernen Sie das Jumper-Kabel.

   .. image:: img/esp32cam_led.png
        :width: 300
        :align: center

#. Stellen Sie den Modus auf **Run** und drücken Sie die **Reset**-Taste auf dem R3-Board.
#. Die ESP32 CAM startet nun mit gelöschter Konfiguration. Sie sollten in der WLAN-Liste Ihres Geräts einen Hotspot mit dem Namen ``AI Camera-xxxxxx`` sehen (wobei ``xxxxxx`` eine eindeutige Kennung ist). Verbinden Sie sich mit dem Passwort ``12345678``.
#. Nach einem Neustart des GalaxyRVR ändert sich der Hotspot-Name von ``AI Camera-xxxxxx`` zurück zu ``GalaxyRVR-xxxxxx``. Dies zeigt an, dass die Werkseinstellungen erfolgreich wiederhergestellt wurden.

.. note::
   Nach dem Zurücksetzen auf die Werkseinstellungen müssen Sie zuvor gespeicherte Heim-WLAN-Einstellungen erneut konfigurieren (:ref:`ap_to_sta`).


.. _uno_firmware_mac:

13. Wie aktualisiert man die R3-Firmware unter macOS?
---------------------------------------------------------

Das R3-Board enthält eine integrierte Firmware, die die Kommunikation mit der RoboPilot-App und Mammoth Coding ermöglicht.

Sie müssen diese Firmware neu hochladen, wenn:

- Ihr Gerät eine ältere Firmware-Version verwendet, oder
- Sie Ihren eigenen Arduino-Code geflasht haben und die Kompatibilität wiederherstellen möchten.

Befolgen Sie die nachstehenden Schritte, um die Kommunikations-Firmware neu zu installieren.

#. Verbinden Sie den Arduino mit einem USB-Kabel mit Ihrem Computer und stellen Sie den Modusschalter auf **Upload**.

   .. image:: img/camera_upload.png
        :width: 500

   .. note:: Verwenden Sie den USB-Typ-B-Anschluss (zum Anschließen des Arduino), nicht den USB-Typ-C-Anschluss (nur zum Laden).

#. Stellen Sie sicher, dass die Firmware-Dateien heruntergeladen wurden.

   * |download_galaxyrvr_filmware|

#. Entpacken Sie das heruntergeladene Archiv, um einen ``output``-Ordner zu erhalten. Klicken Sie mit der rechten Maustaste (oder bei gedrückter Control-Taste) auf den ``output``-Ordner und wählen Sie **New Terminal at Folder** aus dem Kontextmenü.

   .. image:: img/faq_mac_firmware_open.png
      :width: 400

#. Das Terminal öffnet sich direkt im ``output``-Ordner.

   * Führen Sie den Befehl ``bash update-arduino-firmware-mac.sh`` aus
   * Geben Sie dann die Nummer des erkannten COM-Ports ein (z. B. ``1``):

   .. image:: img/faq_mac_firmware_run.png
      :width: 600

#. Wenn die Meldung **"avrdude not Opened"** erscheint:

   .. image:: img/faq_mac_firmware_avrdude.png
      :width: 300

#. Gehen Sie zu **Systemeinstellungen** > **Privatsphäre & Sicherheit** und klicken Sie auf **Allow Anyway**.

   .. image:: img/faq_mac_firmware_allow.png
      :width: 600

#. Führen Sie das Skript erneut aus: ``bash update-arduino-firmware-mac.sh``

   Diesmal können Sie **Open Anyway** auswählen. Geben Sie Ihren Administrator-Benutzernamen und Ihr Passwort ein, um den Vorgang zu erlauben.

   .. image:: img/faq_mac_firmware_anyway.png
      :width: 600

#. Sobald die Erfolgsmeldung erscheint, können Sie das USB-Kabel abziehen.

   .. image:: img/faq_mac_firmware_finish.png
      :width: 600

.. important::

   * Diese Firmware ermöglicht es dem GalaxyRVR, auf App-Befehle zu reagieren.
   * Sie müssen keinen zusätzlichen Code hochladen, wenn Sie die RoboPilot-Fernsteuerungs-App oder die Mammoth-Coding-Software verwenden.
   * Sie können nun mit dem :ref:`quick_start` fortfahren, um Ihre Reise mit dem GalaxyRVR zu beginnen!
