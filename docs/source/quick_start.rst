.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _quick_start:

Schnelles Spiel mit der APP
===========================

Starten Sie direkt in Ihr Mars-Abenteuer! Mit vorinstalliertem Code ab Werk können Sie Ihren GalaxyRVR direkt nach der Montage verwenden. Entdecken Sie Funktionen wie First-Person-Fahren, Hindernisvermeidung, Folgemodi und Sprachsteuerung – alles über die SunFounder Controller App. Beginnen Sie Ihre Reise noch heute!

.. raw:: html
    
    <video width="600" loop autoplay muted>
        <source src="_static/video/play_mode.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::  

    Wenn Ihr R3-Board mit anderem Code programmiert wurde und Sie den GalaxyRVR über die App steuern möchten, folgen Sie den Schritten in :ref:`upload_galaxy_code`.

Schnellstart-Anleitung
----------------------

#. Starten Sie den GalaxyRVR.

   * Beim ersten Einsatz Ihres GalaxyRVR wird empfohlen, den Akku mit einem Typ-C-USB-Kabel vollständig aufzuladen. Schalten Sie dann die Stromversorgung ein.
    
     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_start.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

   * Um die ESP32 CAM zu aktivieren, schalten Sie den Modus-Schalter in die **Run**-Position und drücken Sie die **Reset**-Taste, um das R3-Board neu zu starten. Unten am Streifen sehen Sie ein cyanfarbenes Licht blinken.

     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Installieren Sie `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ aus dem **APP Store(iOS)** oder **Google Play(Android)**.

#. Verbinden Sie sich mit dem ``GalaxyRVR``-Netzwerk.

   Für eine optimale Kommunikation zwischen Ihrem Mobilgerät und dem Rover müssen beide mit demselben lokalen Netzwerk (LAN) verbunden sein, das vom GalaxyRVR bereitgestellt wird.

   * Suchen Sie ``GalaxyRVR`` in der Liste der verfügbaren Netzwerke auf Ihrem Mobilgerät (Tablet oder Smartphone), geben Sie das Passwort ``12345678`` ein und stellen Sie die Verbindung her.

     .. note::

        * Die aktuelle Verbindung erfolgt über den Galaxy-Hotspot, sodass kein Internetzugang besteht. Wenn Sie aufgefordert werden, das Netzwerk zu wechseln, wählen Sie bitte "Verbunden bleiben".
        * :ref:`ap_to_sta`

     .. image:: img/app/camera_lan.png
        :width: 500

#. Einrichten eines Controllers.

   * Tippen Sie in der SunFounder Controller App auf das **+**-Symbol, um einen neuen Controller zu erstellen.

     .. image:: img/app/app1.png

   * Voreingestellte Controller sind für einige Produkte verfügbar. Wählen Sie hier **GalaxyRVR**. Geben Sie einen Namen ein oder tippen Sie einfach auf **Bestätigen**.

     .. image:: img/app/play_preset.jpg
    
   * Nach dem Betreten sucht die App automatisch nach dem GalaxyRVR. Nach kurzer Zeit erscheint eine Meldung "Erfolgreich verbunden".

     .. image:: img/app/auto_connect.jpg

     .. note::

       * Wenn keine Verbindung hergestellt wird, überprüfen Sie bitte, ob Ihr WLAN mit ``GalaxyRVR`` verbunden ist.
       * Sie können auch auf die |app_connect|-Schaltfläche tippen, um manuell eine Verbindung herzustellen. Nach kurzer Wartezeit sollte ``GalaxyRVR(IP)`` angezeigt werden. Tippen Sie darauf, um die Verbindung herzustellen.

       .. image:: img/app/camera_connect.png
           :width: 300
           :align: center

   * Tippen Sie nun auf die |app_run|-Schaltfläche, um den Live-Video-Feed von der Kamera anzuzeigen und das Fahrzeug mit den bereitgestellten Widgets zu steuern. 

     .. image:: img/app/play_run_view.jpg

#. Funktionen der Widgets:

   * **Servo(D)**: Steuert die Neigemechanik der Rover-Kamera und ermöglicht Ihnen eine größere Sichtweite.
   * :ref:`app_avoid`: Schaltet den Rover in den Hindernisvermeidungsmodus. Die werkseitigen Erkennungsabstände können angepasst werden.
   * :ref:`app_follow`: Schaltet den Rover in den Folgemodus. Die werkseitigen Erkennungsabstände können angepasst werden.
   * **Stop(I)**: Stoppt sofort alle Rover-Bewegungen.
   * :ref:`app_speech_control`: Aktiviert die Spracherkennung, um den Rover zu steuern.
   * **HeadLamp(M)**: Schaltet die LED an der ESP32 CAM ein/aus.
   * **Throttle Widgets auf K und Q**: Steuert die linken und rechten Motoren des Rovers. Koordinierte Steuerung ermöglicht Bewegungen in alle Richtungen.
   * **Left IR(N)**: Zeigt die Messwerte des linken Hindernisvermeidungsmoduls an.
   * **Ultrasonic(O)**: Zeigt die vom Ultraschallmodul gemessene Entfernung an.
   * **Right IR(P)**: Zeigt die Messwerte des rechten Hindernisvermeidungsmoduls an.

.. _app_avoid:

Avoid(E)
------------------------

Tippen Sie auf das **Avoid(E)**-Widget, um den Hindernisvermeidungsmodus zu aktivieren.

Vor der Aktivierung dieses Modus müssen Sie möglicherweise die Sensorreichweiten anpassen, da die Werkseinstellungen nicht für alle Situationen optimal sind.

.. _app_follow:

Follow(F)
------------

Um den Folgemodus zu aktivieren, tippen Sie auf das **Follow(F)**-Widget. Falls die Module noch nicht eingestellt sind, folgen Sie den Schritten in :ref:`app_avoid`.

.. _app_speech_control:

STT(J)
-------------------

STT (Speech to Text) ermöglicht Sprachsteuerung über die SunFounder Controller App. Halten Sie das **STT(J)**-Widget gedrückt, sprechen Sie Befehle wie ``stop``, ``forward``, ``backward``, ``left`` oder ``right``. Der Rover führt die entsprechenden Aktionen aus.

.. note::

    Die STT-Funktion erfordert eine Internetverbindung und Google-Dienste auf Android-Geräten. In AP-Modus ist kein Internetzugang verfügbar. Wechseln Sie in den STA-Modus, um STT auf Android zu verwenden.

