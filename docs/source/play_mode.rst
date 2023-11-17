.. _play_mode:

Spielmodus
=========================

Sind Sie bereit, Ihre Marsreise sofort zu beginnen? Unser Spielmodus ist perfekt für diejenigen unter Ihnen zugeschnitten, die es kaum erwarten können, einzutauchen. Ausgestattet mit werkseitig vorinstalliertem Code, können Sie direkt nach dem Zusammenbau Ihres GalaxyRVR in das Geschehen einsteigen. Nutzen Sie die benutzerfreundliche SunFounder Controller-App, um seine zahlreichen Funktionen zu erkunden, einschließlich Fahren aus der Ich-Perspektive, Umschalten zwischen Hindernisvermeidungs- und Folgemodus und sogar Sprachsteuerung.

.. raw:: html
    
    <video width="600" loop autoplay muted>
        <source src="_static/video/play_mode.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>

Aber bevor Sie den Roten Planeten erkunden, stellen wir sicher, dass Sie voll ausgestattet und bereit für das Abenteuer sind. Unten finden Sie eine Schnellstartanleitung, die Sie auf dieser spannenden Reise unterstützt!

.. note::

    * Wenn Ihr R3-Board bereits mit anderem Code hochgeladen wurde, aber Sie weiterhin den Spielmodus verwenden möchten, müssen Sie den relevanten Code herunterladen.

        * :download:`GalaxyRVR Codes <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/main.zip>`

    * Öffnen Sie dann die Datei ``galaxy-rvr.ino``, die sich im Verzeichnis ``galaxy-rvr-main\galaxy-rvr`` befindet.
    
    * Bewegen Sie den Schalter nach rechts und klicken Sie dann auf **Upload**.

    .. image:: img/camera_upload.png
        :width: 400
        :align: center


Schnellstartanleitung
---------------------

#. Lassen Sie uns den GalaxyRVR starten.

    * Beim ersten Gebrauch Ihres GalaxyRVR wird empfohlen, zuerst ein Typ-C-USB-Kabel anzuschließen, um den Akku vollständig aufzuladen. Schalten Sie dann die Stromversorgung ein.
    
        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/play_start.mp4" type="video/mp4">
                Ihr Browser unterstützt das Video-Tag nicht.
            </video>

    * Um die ESP32 CAM zu aktivieren, bewegen Sie den Modusschalter in die Position **Run**, und drücken Sie die **reset**-Taste, um das R3-Board neu zu starten. Sie werden dann ein zyanfarbenes Licht am unteren Streifen blinken sehen.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/play_reset.mp4" type="video/mp4">
                Ihr Browser unterstützt das Video-Tag nicht.
            </video>

#. Installieren Sie `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ aus dem **APP Store(iOS)** oder **Google Play(Android)**.


#. Verbinden Sie sich mit dem Netzwerk ``GalaxyRVR``.

    Für eine optimale Kommunikation zwischen Ihrem mobilen Gerät und dem Rover müssen Sie beide mit demselben lokalen Netzwerk (LAN) verbinden, das von GalaxyRVR bereitgestellt wird.


    * Finden Sie ``GalaxyRVR`` in der Liste der verfügbaren Netzwerke auf Ihrem mobilen Gerät (Tablet oder Smartphone), geben Sie das Passwort ``12345678`` ein und verbinden Sie sich damit.

        .. image:: img/app/camera_lan.png

    * Der Standardverbindungsmodus ist **AP mode**. Nachdem Sie sich verbunden haben, könnte eine Warnung erscheinen, dass dieses Netzwerk keinen Internetzugang hat. Wenn ja, wählen Sie „Stay connected“.

        .. image:: img/app/camera_stay.png


#. Einrichtung eines Controllers.

    * Um einen Controller in der SunFounder Controller App zu erstellen, tippen Sie auf das **+** Symbol.

        .. image:: img/app/app1.png

    * Voreingestellte Controller sind für einige Produkte verfügbar, hier wählen wir **GalaxyRVR**. Geben Sie ihm einen Namen oder tippen Sie einfach auf **Confirm**.

        .. image:: img/app/play_preset.jpg
    
    * Sobald Sie in der App sind, sucht diese automatisch nach dem GalaxyRVR. Nach einem Moment erscheint eine Meldung „Connected Successfully“.

        .. image:: img/app/auto_connect.jpg

        .. note::

            * Wenn keine Verbindung besteht, überprüfen Sie bitte, ob Ihr WLAN mit ``GalaxyRVR`` verbunden ist.
            * Sie können auch den |app_connect| Button antippen, um manuell zu verbinden. Nach kurzer Wartezeit sollte ``GalaxyRVR(IP)`` erscheinen. Tippen Sie darauf, um eine Verbindung herzustellen.

            .. image:: img/app/camera_connect.png
                :width: 300
                :align: center


    * Jetzt aktivieren Sie mit dem |app_run| Button die Live-Videoübertragung von der Kamera und steuern das Fahrzeug mit den bereitgestellten Widgets. 

        .. image:: img/app/play_run_view.jpg

#. Lassen Sie uns nun die Funktionen jedes Widgets betrachten:

        * **Servo(D)**: Steuert den Neigungsmechanismus der Kamera des Rovers, wodurch Sie einen größeren Bereich beobachten können.

        * :ref:`app_avoid`: Schaltet den Rover in den Hindernisvermeidungsmodus. Die werkseitig eingestellten Erkennungsentfernungen für jedes Hindernisvermeidungsmodul können unterschiedlich sein. Eine manuelle Anpassung ist erforderlich.

        * :ref:`app_follow`: Schaltet den Rover in den Verfolgungsmodus. Die werkseitig eingestellten Erkennungsentfernungen für jedes Hindernisvermeidungsmodul können unterschiedlich sein. Eine manuelle Anpassung ist erforderlich.

        * **Stop(I)**: Stoppt sofort alle Bewegungen des Rovers.

        * :ref:`app_speech_control`: Drücken Sie dieses Widget, um die Spracherkennung zu starten und den Rover entsprechende Aktionen ausführen zu lassen.

        * **HeadLamp(M)**: Um die LED am ESP32 CAM ein-/auszuschalten.
        * **Throttle Widgets on K and Q**: Das Gashebel-Widget im Bereich K steuert die linken Motoren des Rovers, während das im Bereich Q die rechten Motoren steuert. Durch die Koordination beider Widgets kann der GalaxyRVR in jede Richtung bewegt werden.

        * **Left IR(N)**: Zeigt die Messwerte des linken Hindernisvermeidungsmoduls an.

        * **Ultrasonic(O)**: Zeigt die vom Ultraschallmodul gemessene Entfernung an.

        * **Right IR(P)**: Zeigt die Messwerte des rechten Hindernisvermeidungsmoduls an.

.. _app_avoid:

Avoid(E)
------------------------

Tippen Sie auf das Widget **Avoid(E)**, um den Hindernisvermeidungsmodus zu aktivieren.

Bevor Sie diesen Modus aktivieren, müssen Sie möglicherweise die Erkennungsbereiche der Sensoren entsprechend Ihrer aktuellen Umgebung anpassen, da die Werkseinstellungen nicht für alle Situationen ideal sind.

Wenn der Erkennungsbereich der beiden Infrarotmodule zu kurz ist, könnte der Mars Rover gegen Hindernisse stoßen. Ist der Bereich hingegen zu lang, könnte der Rover beginnen, zu weit von einem Hindernis wegzuschwenken, was seine Navigation stören könnte.

So können Sie die Einstellungen feinjustieren:

#. Beginnen Sie mit der Anpassung des rechten Hindernisvermeidungsmoduls. Während des Transports können Kollisionen dazu führen, dass der Sender und Empfänger am Infrarotmodul kippen. Daher müssen Sie diese manuell begradigen.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust1.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

#. Stellen Sie ein Hindernis etwa 20 cm direkt vor dem rechten Modul auf. Die Box, in der unser Rover-Kit geliefert wurde, ist dafür eine gute Wahl! Drehen Sie nun das Potentiometer am Modul, bis die Anzeigeleuchte am Modul gerade aufleuchtet. Bewegen Sie dann das Hindernis vor und zurück, um zu überprüfen, ob die Anzeigeleuchte in der gewünschten Entfernung aufleuchtet. Leuchtet das Licht nicht in der richtigen Entfernung auf oder bleibt es an, ohne auszugehen, müssen Sie das andere Potentiometer einstellen.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust2.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>


#. Wiederholen Sie den gleichen Vorgang für das andere Modul.


.. _app_follow:

Follow(F)
------------

Wenn Sie bereit sind, den Folgemodus zu aktivieren, tippen Sie einfach auf das Widget **Follow(F)**. Wenn Sie zuvor den Erkennungsabstand der Hindernisvermeidungsmodule nicht angepasst haben, müssen Sie zuerst die Schritte in :ref:`app_avoid` befolgen.

Im Folgemodus bewegt sich der GalaxyRVR auf ein Objekt vor ihm zu oder dreht sich nach links oder rechts, um der Bewegung des Objekts zu folgen.


.. _app_speech_control:

STT(J)
-------------------


STT steht für Sprache-zu-Text. Die SunFounder Controller-App integriert sich mit dem Spracherkennungsmotor Ihres mobilen Geräts. Wenn Sie also das Widget **STT(J)** im SunFounder Controller antippen und in Ihr mobiles Gerät sprechen,

wird Ihr Gerät Ihre Sprache erfassen, in Text umwandeln und an den GalaxyRVR senden. Stimmt dieser Text mit den im Code voreingestellten Befehlen überein, führt der Rover die entsprechenden Aktionen aus.

Die folgenden Befehle sind derzeit im Code voreingestellt. Sprechen Sie einen der folgenden Befehle und beobachten Sie, wie der GalaxyRVR reagiert.

.. image:: img/app/play_speech.png
    :width: 600

* ``stop``: Alle Bewegungen des Rovers können gestoppt werden.
* ``forward``: Lassen Sie den Rover vorwärts fahren.
* ``backward``: Lassen Sie den Rover rückwärts fahren.
* ``left``: Lassen Sie den Rover nach links abbiegen.
* ``right``: Lassen Sie den Rover nach rechts abbiegen.


.. note::

    Die STT (Sprache-zu-Text)-Funktion erfordert eine Internetverbindung und Google-Dienste auf Android-Geräten. Diese funktioniert jedoch nicht mit dem voreingestellten AP-Modus (Access Point) auf dem GalaxyRVR.
    
    Im AP-Modus erstellt der GalaxyRVR ein lokales WLAN-Netzwerk, mit dem sich Ihr mobiles Gerät verbinden kann, aber es bietet keinen Internetzugang.
    
    Um die STT-Funktion auf Android zu nutzen, wechseln Sie den Code des Rovers von AP auf STA-Modus, wie in :ref:`stt_android` beschrieben.

.. note::

    iOS-Geräte, die einen Offline-Spracherkennungsmotor verwenden, funktionieren sowohl im AP- als auch im STA-Modus einwandfrei.
    