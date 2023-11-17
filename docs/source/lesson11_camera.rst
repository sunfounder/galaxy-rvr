Lektion 11: Erforschung des visuellen Systems des Mars-Rovers - Kamera und Echtzeitsteuerung
================================================================================================

Willkommen zurück, junge Entdecker! In der letzten Lektion haben wir unseren Mars-Rover mit der Fähigkeit ausgestattet, mit einem Kippmechanismus zu „nicken“. Jetzt ist es an der Zeit, unserem Rover „Augen“ zu geben - die Kamera!

In dieser aufregenden Reise tauchen wir in die Einrichtung des Kamera-Systems des Rovers ein. Ihr werdet lernen, wie man die vom Rover eingefangenen Bilder auf eine Webseite überträgt, sodass ihr genau sehen könnt, was der Rover sieht, und das in Echtzeit. Stellt euch die Begeisterung vor, die Marslandschaft aus der Perspektive des Rovers zu erleben!

Die Begeisterung setzt sich fort, da wir auch die SunFounder Controller-App vorstellen. Diese Anwendung ermöglicht es uns, ein Live-Feed der Sicht des Rovers zu erhalten, während er sich bewegt, und wir können den Kippmechanismus direkt von unseren Smartphones oder Tablets aus steuern. Es ist, als hätte man eine Fernbedienung mit eingebautem Bildschirm!

Dies bietet ein noch interaktiveres und spannenderes Erlebnis mit unserem Rover. Bleibt dran für mehr Abenteuer!

    .. image:: img/app/camera_view_app.png

Kursziele
-------------------------
* Verstehen, wie man eine WLAN-Verbindung mit dem ESP32 CAM herstellt.
* Lernen, genau zu sehen, was der Rover sieht, und das in Echtzeit.
* Lernen, wie man die SunFounder Controller-App verwendet, um eine virtuelle Fernbedienung zu erstellen und den Mars-Rover zu steuern.

Kursmaterialien
-----------------------

* Mars-Rover-Modell (mit allen Komponenten ausgestattet)
* Arduino IDE
* Computer
* Tablet oder Smartphone mit installierter SunFounder Controller-App

Kursschritte
--------------

**Schritt 1: Einführung in ESP32 CAM**

In unserem vorherigen Abenteuer haben wir unseren Mars-Rover mit einem Paar „Augen“ ausgestattet, indem wir den ESP32 CAM integriert haben. Heute werden wir mehr darüber lernen und ihn tatsächlich „sehen“ lassen.

.. image:: img/esp32_cam.png
    :width: 400
    :align: center

Der ESP32 CAM, der als die Augen unseres Rovers fungiert, ist ein kleines, aber leistungsstarkes Modul. Es integriert nicht nur WLAN- und Bluetooth-Funktionalitäten, sondern verfügt auch über eine kompakte Kamera. Diese Kamera hilft unserem Rover, Bilder seiner Umgebung aufzunehmen.

Genau wie wir unsere Augen verwenden, um unsere Umgebung zu beobachten, kann der ESP32 CAM „sehen“, was vor dem Rover liegt, und diese visuellen Daten an unser Smartphone oder Computer senden. Dies ermöglicht es uns, alles zu sehen, was der Rover in Echtzeit sieht!

Es ist, als würden wir den Rover direkt steuern, nicht nur den Rover selbst beobachten, sondern auch die Welt, die er erkundet! Unglaublich, oder? Also, lasst uns tiefer eintauchen...



**Schritt 2: Programmierung der Kamera des Rovers und Betrachtung des Feeds**

Nachdem wir die ESP32-CAM an unseren Rover angebracht haben, müssen wir sie nun zum Leben erwecken.
Dazu verwenden wir die Arduino IDE, um ein Programm zu schreiben, das die Kamera steuert, es ihr ermöglicht, sich mit WLAN zu verbinden, 
und die eingefangenen Bilder zu streamen.

So können wir das tun:

#. Installieren Sie die ``SunFounder AI Camera``-Bibliothek.

    * Öffnen Sie den **Library Manager** der Arduino IDE, suchen Sie nach "SunFounder Camera" und klicken Sie auf **INSTALL**.

        .. image:: img/camera_install_lib.png

    * Ein Popup-Fenster erscheint für die Installation der Bibliotheksabhängigkeiten. Klicken Sie auf **INSTALL ALL** und warten Sie, bis der Vorgang abgeschlossen ist.

        .. image:: img/camera_install_lib1.png

#. Geben Sie in der Arduino IDE den folgenden Code ein.

    Bezüglich der Variablen ``NAME``, ``TYPE`` und ``PORT`` im Code werden wir uns an dieser Stelle nicht vertiefen. Sie kommen im nächsten Schritt zum Einsatz. Behalten Sie lediglich im Hinterkopf, dass diese Variablen in unserer bevorstehenden Reise wichtig sein werden, um einen Echtzeit-Video-Feed von unserem Mars-Rover zu etablieren.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b648e4-23e8-4b28-accd-aac171069116/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


    Beachten Sie, dass wir im Code zwei Verbindungsmodi haben - **AP**-Modus und **STA**-Modus. Sie können entscheiden, welchen Sie je nach Ihren spezifischen Bedürfnissen verwenden möchten.

    * **AP Mode**: In diesem Modus erstellt der Rover einen Hotspot (in unserem Code als ``GalaxyRVR`` benannt). Dies ermöglicht es jedem Gerät wie einem Mobiltelefon, Tablet oder Laptop, sich mit diesem Netzwerk zu verbinden. Dies ist besonders nützlich, wenn Sie den Rover unter allen Umständen fernsteuern möchten. Beachten Sie jedoch, dass dies Ihr Gerät vorübergehend daran hindert, eine Internetverbindung herzustellen.

        .. code-block:: arduino

        // AP Mode
        #define WIFI_MODE WIFI_MODE_AP
        #define SSID "GalaxyRVR"
        #define PASSWORD "12345678"

    * **STA Mode**: In diesem Modus verbindet sich der Rover mit Ihrem Heim-WLAN-Netzwerk. Denken Sie daran, dass Ihr Steuergerät (wie ein Mobiltelefon oder Tablet) ebenfalls mit demselben WLAN-Netzwerk verbunden sein sollte. Dieser Modus ermöglicht es Ihrem Gerät, seine reguläre Internetverbindung beizubehalten, während es den Rover steuert, beschränkt aber den Einsatzbereich des Rovers auf Ihre WLAN-Abdeckungsfläche.

        .. code-block:: arduino

            // STA Mode
            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "YOUR SSID"
            #define PASSWORD "YOUR PASSWORD"

#. Laden Sie den Code auf unseren Rover und erwecken Sie unsere ESP32-CAM zum Leben!

    * Der ESP32-CAM und das Arduino-Board teilen sich die gleichen RX (Empfang) und TX (Senden) Pins. Daher müssen Sie vor dem Hochladen des Codes zuerst den ESP32-CAM durch Verschieben dieses Schalters nach rechts freigeben, um Konflikte oder mögliche Probleme zu vermeiden.

        .. image:: img/camera_upload.png
            :width: 600

    * Sobald der Code erfolgreich hochgeladen wurde, schalten Sie ihn zurück auf die linke Seite, um die ESP32-CAM zu starten.

        .. note::
            Dieser Schritt und der vorherige sind jedes Mal erforderlich, wenn Sie den Code neu hochladen.

        .. image:: img/camera_run.png
            :width: 600
        
    * Öffnen Sie den **Serial Monitor** und stellen Sie die Baudrate auf 115200 ein. Wenn keine Informationen erscheinen, drücken Sie die **Reset button** auf dem GalaxyRVR-Shield, um den Code erneut auszuführen. Sie sollten eine IP-Adresse im Ausgabebereich des seriellen Monitors sehen. Dies ist die Adresse, an die die Kamera Ihres Rovers sendet.

        .. image:: img/camera_serial.png


    * Jetzt ist es an der Zeit, tatsächlich zu sehen, was unser Rover sieht! Öffnen Sie einen Webbrowser - wir empfehlen Google Chrome - und geben Sie die URL ein, die Sie im Seriellen Monitor sehen, im Format ``http://ip:9000/mjpg``.

        .. image:: img/camera_view.png

Und voilà! Jetzt sollten Sie den Live-Feed von der Kamera Ihres Rovers sehen können. Ist es nicht erstaunlich zu denken, dass Sie den Mars (oder vielleicht nur Ihr Wohnzimmer) aus der Perspektive des Rovers betrachten? Ganz wie ein echter Mars-Rover-Wissenschaftler!

Denken Sie daran, dies ist erst der Anfang. Es gibt noch so viel mehr zu entdecken und zu lernen. Im nächsten Schritt werden wir erforschen, wie wir unseren Rover steuern können, während wir den Live-Kamera-Feed betrachten. Aufregend, nicht wahr? Weiter so, Entdecker!


**Schritt 3: Steuern und Anzeigen des Kamera-Feeds mit der App**

Haben Sie sich schon einmal gewünscht, den visuellen Feed des Mars-Rovers direkt auf Ihrem Smartphone ansehen zu können, während Sie gleichzeitig seinen Kippmechanismus steuern? 
Jetzt können Sie das! Mit Hilfe der SunFounder Controller-App können Sie genau das tun. Folgen Sie den unten stehenden Schritten:


#. Installieren Sie  aus dem **APP Store(iOS)** oder **Google Play(Android)**.

#. Erstellen Sie einen Controller.

    * Um einen Controller in der SunFounder Controller-App hinzuzufügen, klicken Sie auf das **+**-Symbol.

        .. image:: img/app/app1.png

    * Wählen Sie das **Blank**-Voreinstellung, wählen Sie entweder **Dual** oder **Single Stick** je nach Ihrer Präferenz. Geben Sie Ihrem neuen Controller einen Namen und klicken Sie auf **Confirm**.

        .. image:: img/app/camera_controller.png

    * Sie befinden sich jetzt im Controller. Klicken Sie im D-Bereich auf das **+**-Symbol und wählen Sie Slider aus dem Popup-Menü.

    .. image:: img/app/camera_add_slider.png

    * Dieses Slider-Widget ist dazu gedacht, den Kippmechanismus zu steuern. Wie wir in der vorherigen Lektion gelernt haben, liegt sein Bereich zwischen 0 und 140. Daher werden wir diese Werte als Mindest- und Höchstwerte für unser Slider-Widget festlegen.

        .. image:: img/app/camera_slider_set.png
    
    * Klicken Sie auf den |app_save|-Button in der oberen rechten Ecke, um diesen Controller zu speichern.

    
#. Schreiben wir einen Code, um den Wert des Sliders zu erfassen:

    * Basierend auf dem vorherigen Code wechseln wir in den AP-Modus, in dem Sie das SSID und PASSWORD nach Ihren Wünschen festlegen können.
    
    .. code-block:: arduino
    
        // AP Mode
        #define WIFI_MODE WIFI_MODE_AP
        #define SSID "GalaxyRVR"
        #define PASSWORD "12345678"

    * Als Nächstes fügen wir eine ``onReceive()``-Funktion hinzu, um Werte vom SunFounder Controller zu empfangen und diese Werte im Seriellen Monitor anzuzeigen. Wir verwenden die Funktion ``getSlider()``, um den Wert des **slider**-Widgets zu erhalten. Ich habe ein **slider**-Widget in Region D hinzugefügt, aber wenn Sie es in einer anderen Region hinzugefügt haben, müssen Sie ``REGION_D`` in Ihre Region ändern.

        .. code-block::

            void onReceive() {
                int16_t sliderD = aiCam.getSlider(REGION_D);
                Serial.print("Slider D: ");
                Serial.println(sliderD);
            }

            void setup() {
                ...
                // Set the function to execute when data is received
                aiCam.setOnReceived(onReceive);
                ...
            }

    * Hier ist der komplette Code:

        .. raw:: html

            <iframe src=https://create.arduino.cc/editor/sunfounder01/b914aa48-85e7-4682-b420-89961cc761ca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
    * Stellen Sie vor dem Hochladen des Codes sicher, dass der Schalter nach rechts gedreht ist.

        .. image:: img/camera_upload.png
            :width: 600

    * Nachdem der Code erfolgreich hochgeladen wurde, bewegen Sie den Schalter nach links, um die ESP32-CAM zu starten.

        .. image:: img/camera_run.png
            :width: 600

    * Wenn Sie die folgenden Informationen im Seriellen Monitor sehen, können Sie mit dem nächsten Schritt fortfahren.

        .. code-block:: arduino
        
            ...[OK]
            SET+PORT8765
            ...[OK]
            SET+START
            ...[OK]
            WebServer started on ws://192.168.4.1:8765
            Video streamer started on http://192.168.4.1:9000/mjpg
            WS+null

#. Verbinden Sie sich mit dem Netzwerk ``GalaxyRVR``.

    An diesem Punkt sollten Sie Ihr mobiles Gerät mit dem lokalen Netzwerk (LAN) verbinden, das von GalaxyRVR bereitgestellt wird.
    Dadurch befinden sich sowohl Ihr mobiles Gerät als auch der Rover im selben Netzwerk, was eine reibungslose Kommunikation 
    zwischen den Anwendungen auf Ihrem mobilen Gerät und dem Rover ermöglicht.

    * Finden Sie ``GalaxyRVR`` in der Liste der verfügbaren Netzwerke auf Ihrem mobilen Gerät (Tablet oder Smartphone), geben Sie das Passwort ``12345678`` ein und verbinden Sie sich damit.

        .. image:: img/app/camera_lan.png

    * Der Standardverbindungsmodus ist **AP mode**. Nachdem Sie die Verbindung hergestellt haben, kann eine Warnmeldung erscheinen, dass es keinen Internetzugang in diesem WLAN-Netzwerk gibt, bitte wählen Sie, die Verbindung fortzusetzen.

        .. image:: img/app/camera_stay.png

#. Verbinden und Aktivieren des Controllers.

    * Kehren Sie nun zu dem Controller zurück, den Sie zuvor erstellt haben (in meinem Fall heißt er "camera"). Verwenden Sie den |app_connect|-Button, um den SunFounder Controller mit dem Rover zu verbinden und eine Kommunikationsverbindung herzustellen. Nach einer kurzen Wartezeit erscheint „GalaxyRVR(IP)“ (der Name, den Sie im Code mit ``#define NAME "GalaxyRVR"`` zugewiesen haben). Klicken Sie darauf, um eine Verbindung herzustellen.

        .. image:: img/app/camera_connect.png

        .. note::
            Bitte überprüfen Sie, ob Ihr WLAN mit „GalaxyRVR“ verbunden ist, falls Sie die obige Nachricht nach einiger Zeit nicht sehen.

    * Sobald Sie die Nachricht „Connected Successfully“ sehen, drücken Sie den |app_run|-Button. Dies wird das Live-Footage der Kamera in der App anzeigen.

        .. image:: img/app/camera_view_app.png

    * Bewegen Sie jetzt den Schieberegler und öffnen Sie gleichzeitig den seriellen Monitor der Arduino IDE. Sie sollten ähnliche Daten wie unten sehen.

        .. code-block:: 
    
            Slider D: 105
            WS+null
            Slider D: 105
            WS+null
            Slider D: 105
            WS+null


#. Lassen Sie den Schieberegler den Kippmechanismus steuern.

    Jetzt, wo wir die vom Slider-Widget übertragenen Werte kennen, können wir diese Werte direkt verwenden, um den Servo zu drehen.
     Fügen Sie daher basierend auf dem vorherigen Code die folgenden Zeilen hinzu, um den Servo zu initialisieren und den Wert des Schiebereglers auf den Servo zu schreiben.

    .. code-block::

        ...
        #include <Servo.h>

        Servo myServo;  // create a servo object
        myServo.write(int(sliderD));  // control the servo to move to the current angle

        ...

        void onReceive() {
            ...
            myServo.write(int(sliderD));  // control the servo to move to the current angle
        }

        void setup() {
            ...
            myServo.attach(6);  // attaches the servo on pin 6
            ...
        }

    Hier ist der vollständige Code:
    
    .. raw:: html
    
        <iframe src=https://create.arduino.cc/editor/sunfounder01/b737352b-2509-4967-8147-1fd6bdc7d19d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

    Laden Sie den oben stehenden Code auf den GalaxyRVR, wiederholen Sie die Schritte 4 und 5 von oben, verbinden Sie sich erneut mit dem LAN ``GalaxyRVR`` und führen Sie den Vorgang im 
    SunFounder Controller erneut aus, dann können Sie den Schieberegler verwenden, um den Kippmechanismus des Rovers zu steuern.

Jetzt haben Sie erfolgreich gelernt, den SunFounder Controller zu implementieren und wie Sie das Schieberegler-Widget verwenden, um Servobewegungen zu steuern. Dieser Prozess ermöglicht es Ihnen, auf intuitive und direkte Weise mit Ihrem GalaxyRVR zu interagieren.


**Schritt 4: Reflexion und Zusammenfassung**

Die Verwendung des SunFounder Controllers zur Bedienung Ihres Mars-Rovers mag anfangs etwas kompliziert erscheinen. Jedes Mal, wenn Sie Ihren Code ändern, müssen Sie die folgenden Schritte wiederholen:

* Stellen Sie vor dem Hochladen des Codes sicher, dass der Schalter nach rechts gedreht ist.

    .. image:: img/camera_upload.png
        :width: 600

* Nachdem der Code erfolgreich hochgeladen wurde, schalten Sie auf die linke Seite, um die ESP32-CAM zu starten.
* Verbinden Sie sich mit dem Netzwerk ``GalaxyRVR``.
* Verbinden und starten Sie den Controller.

Obwohl diese Schritte mühsam erscheinen mögen, sind sie entscheidend für den Prozess. Nachdem Sie sie einige Male wiederholt haben, werden Sie mit dem Verfahren vertrauter und wohler fühlen.


Jetzt, da wir diese Lektion abgeschlossen haben, lassen Sie uns über das Nachdenken, was wir gelernt haben, durch einige Fragen reflektieren:

* Bei der Erstellung eines neuen Controllers sind Sie auf viele verschiedene Arten von Bausteinen gestoßen. Haben Sie sich überlegt, welche individuellen Funktionen diese haben könnten?
* Ist es möglich, andere Widgets zu verwenden, um den Kippmechanismus zu steuern?
* Oder sogar direkt die Bewegungen des Mars-Rovers zu steuern?

Lassen Sie uns unsere Erkundung dieser Fragen in der nächsten Lektion mit Spannung erwarten!
