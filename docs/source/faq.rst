.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

FAQ
==============

.. _install_lib:

Q1: Kompilierungsfehler: SoftPWM.h: Datei oder Verzeichnis nicht gefunden?
---------------------------------------------------------------------------------
Wenn die Meldung „Compilation error: SoftPWM.h: No such file or directory“ erscheint, bedeutet dies, dass die SoftPWM-Bibliothek nicht installiert ist.

Bitte installieren Sie die beiden erforderlichen Bibliotheken ``SoftPWM`` und ``SunFounder AI Camera``, wie gezeigt.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>


Q2: avrdude: stk500_getsync() Versuch 10 von 10: nicht synchronisiert: resp=0x6e?
-----------------------------------------------------------------------------------------
Wenn die folgende Nachricht weiterhin erscheint, nachdem Sie auf die Schaltfläche **Upload** geklickt haben und das Board sowie der Port korrekt ausgewählt wurden.

.. code-block::
    
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00
    At this point, you need to make sure that the ESP32 CAM is unplugged.

Das ESP32-CAM und das Arduino-Board teilen sich die gleichen RX (Empfang) und TX (Sendung) Pins. Daher müssen Sie vor dem Hochladen des Codes zuerst das ESP32-CAM trennen, um Konflikte oder potenzielle Probleme zu vermeiden.

    .. image:: img/camera_upload.png
        :width: 600

Nachdem der Code erfolgreich hochgeladen wurde, wenn Sie das ESP32 CAM nutzen möchten, müssen Sie den Schalter nach links bewegen, um das ESP32 CAM zu starten.

    .. image:: img/camera_run.png
        :width: 600

.. _stt_android:

Q3: Wie kann ich den STT-Modus auf meinem Android-Gerät verwenden?
------------------------------------------------------------------------

Der STT-Modus erfordert, dass das Android-Mobilgerät mit dem Internet verbunden ist und die Google-Servicekomponente installiert ist.

Folgen Sie nun den untenstehenden Schritten.

#. Ändern Sie den AP-Modus der Datei ``galaxy-rvr.ino`` in den STA-Modus.

    * Öffnen Sie die Datei ``galaxy-rvr.ino``, die sich im Verzeichnis ``galaxy-rvr-main\galaxy-rvr`` befindet. 
    * Kommentieren Sie dann den AP-Modus bezogenen Code aus. Kommentieren Sie den STA-Modus bezogenen Code ein und füllen Sie das ``SSID`` und das ``PASSWORD`` Ihres Heim-WLANs ein.

        .. code-block:: arduino

            /** Configure Wifi mode, SSID, password*/
            // #define WIFI_MODE WIFI_MODE_AP
            // #define SSID "GalaxyRVR"
            // #define PASSWORD "12345678"

            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "xxxxxxxxxx"
            #define PASSWORD "xxxxxxxxxx"

    * Speichern Sie diesen Code, wählen Sie das richtige Board (Arduino Uno) und den Port aus, dann klicken Sie auf die Schaltfläche **Upload**, um ihn auf das R3-Board zu laden.

#. Suchen Sie in Google Play nach ``google``, finden Sie die unten gezeigte App und installieren Sie sie.

    .. image:: img/google_voice.png

#. Verbinden Sie Ihr Mobilgerät mit demselben WLAN, das Sie im Code angegeben haben.

    .. image:: img/sta_wifi.png

#. Öffnen Sie den zuvor in SunFounder Controller erstellten Controller und verbinden Sie ihn durch den |app_connect|-Button mit ``GalaxyRVR``.

    .. image:: img/app/camera_connect.png


#. Tippen und halten Sie das **STT(J)**-Widget, nachdem Sie den |app_run|-Button angeklickt haben. Es erscheint ein Hinweis, dass es zuhört. Sagen Sie den folgenden Befehl, um das Auto zu bewegen.

    .. image:: img/app/play_speech.png

    * ``stop``: Alle Bewegungen des Rovers können gestoppt werden.
    * ``forward``: Lassen Sie den Rover vorwärts fahren.
    * ``backward``: Lassen Sie den Rover rückwärts fahren.
    * ``left``: Lassen Sie den Rover nach links abbiegen.
    * ``right``: Lassen Sie den Rover nach rechts abbiegen.

Q4: Über die ESP32 CAM Firmware
---------------------------------------------------

Hier ist der Firmware-Link des ESP32 CAM: |link_ai_camera_firmware|

Q5: Wie wird eine neue Firmware auf einen ESP32 CAM geflasht?
---------------------------------------------------------------
Das Kameramodul wird normalerweise ab Werk mit vorinstallierter Firmware geliefert. Wenn Sie jedoch auf ein Problem mit Datenkorruption stoßen oder die Firmware aktualisieren müssen, können Sie dies mit der Arduino IDE tun. Hier ist, wie es gemacht wird:

**1. Vorbereitung des Programmiergeräts**

#. Zuerst benötigen Sie ein Programmiergerät.

    .. image:: img/esp32_cam_programmer.png
        :width: 300
        :align: center

#. Stecken Sie den ESP32-CAM in das Programmiergerät und schließen Sie dann das Programmiergerät an Ihren Computer an.

    .. image:: img/esp32_cam_usb.jpg
        :width: 300
        :align: center

**2. Installieren Sie das ESP32-Board**

Um den ESP32-Mikrocontroller zu programmieren, müssen Sie das ESP32-Boardpaket in der Arduino IDE installieren. Befolgen Sie diese Schritte:

#. Gehen Sie zu **Datei** und wählen Sie **Einstellungen** im Dropdown-Menü aus.

    .. image:: img/install_esp321.png
        :width: 500
        :align: center

#. In den **Einstellungen** finden Sie das Feld **Zusätzliche Board-Verwalter-URLs**. Klicken Sie darauf, um das Textfeld zu aktivieren.

    .. image:: img/install_esp322.png
        :width: 500
        :align: center

#. Fügen Sie die folgende URL in das Feld **Zusätzliche Board-Verwalter-URLs** ein: https://espressif.github.io/arduino-esp32/package_esp32_index.json. Diese URL verlinkt auf die Paketindexdatei für ESP32-Boards. Klicken Sie auf **OK**, um die Änderungen zu speichern.

    .. image:: img/install_esp323.png
        :width: 500
        :align: center

#. Im **Board-Verwalter** suchen Sie nach **ESP32**. Klicken Sie auf die Schaltfläche **Installieren**, um mit der Installation zu beginnen. Dadurch wird das ESP32-Boardpaket heruntergeladen und installiert.

    .. image:: img/install_esp324.png
        :align: center

**3. Installieren Sie die erforderlichen Bibliotheken**

#. Installieren Sie die ``WebSockets``-Bibliothek aus dem **BIBLIOTHEKSVERWALTER**.

    .. image:: img/esp32_cam_websockets.png
        :width: 500
        :align: center

#. Befolgen Sie die gleichen Schritte, um die ``ArduinoJson``-Bibliothek zu installieren.

    .. image:: img/esp32_cam_arduinojson.png
        :width: 500
        :align: center

**4. Firmware herunterladen und hochladen**

#. Laden Sie die Firmware-Datei hier herunter.

    * :download:`ai-camera-firmware <https://github.com/sunfounder/ai-camera-firmware/archive/refs/heads/main.zip>`

#. Entpacken Sie die heruntergeladene Firmware-Datei und benennen Sie den extrahierten Ordner von ``ai-camera-firmware-main`` in ``ai-camera-firmware`` um.

    .. image:: img/esp32_cam_change_name.png
        :align: center

#. Öffnen Sie die Datei ``ai-camera-firmware.ino`` mit der Arduino IDE, die auch die zugehörigen Code-Dateien öffnet.

    .. image:: img/esp32_cam_ino.png
        :align: center

#. Wählen Sie **Board** -> **esp32** -> **ESP32 Dev Module** aus.

    .. image:: img/esp32_cam_board.png
        :width: 500
        :align: center

#. Wählen Sie den richtigen Anschluss aus.

    .. image:: img/esp32_cam_port.png
        :width: 400
        :align: center

#. Stellen Sie sicher, dass Sie **PSRAM** aktivieren und in der **Partitionsschema** die Option **Huge APP** auswählen.

    .. image:: img/esp32_cam_psram.png
        :width: 400
        :align: center

#. Schließlich laden Sie die Firmware auf den ESP32-CAM hoch.

    .. image:: img/esp32_cam_upload.png
        :width: 500
        :align: center

#. Nach erfolgreichem Hochladen der Firmware finden Sie weitere Informationen unter diesem Link: https://github.com/sunfounder/ai-camera-firmware.
