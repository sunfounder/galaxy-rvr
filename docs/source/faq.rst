FAQ
==============

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

