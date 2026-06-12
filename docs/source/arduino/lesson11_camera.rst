.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Lektion 11: Erkundung des Mars Rover-Visionssystems - Kamera und Echtzeitsteuerung
==================================================================================

Willkommen zurück, junge Entdecker! In der letzten Lektion haben wir unseren Mars Rover mit der Fähigkeit ausgestattet, mit einem Neigungsmechanismus zu "nicken". Jetzt ist es an der Zeit, unserem Rover "Augen" zu geben - die Kamera!

Auf dieser spannenden Reise werden wir uns mit der Einrichtung des Kamerasystems des Rovers befassen. Sie werden lernen, wie die von der Rover-Kamera aufgenommenen Bilder an eine Webseite übertragen werden, sodass Sie genau sehen können, was der Rover sieht - in Echtzeit. Stellen Sie sich die Aufregung vor, die Marslandschaft aus der Perspektive des Rovers zu erleben!

Die Spannung setzt sich fort, während wir auch die SunFounder Controller-App vorstellen. Diese Anwendung ermöglicht es uns, einen Live-Feed der Rover-Ansicht zu erhalten, während er navigiert, und wir können den Neigungsmechanismus direkt von unseren Smartphones oder Tablets aus steuern. Es ist, als hätten wir eine Fernbedienung mit eingebautem Bildschirm!

Lernziele
------------------
* Verstehen, wie eine WiFi-Verbindung mit dem ESP32 CAM hergestellt wird.
* Lernen, wie man genau das sieht, was der Rover sieht, in Echtzeit.
* Lernen, wie man die SunFounder Controller-App verwendet, um eine virtuelle Fernbedienung zu erstellen und den Mars Rover zu steuern.

Benötigte Materialien
------------------------

* Mars Rover-Modell (mit allen Komponenten ausgestattet)
* Arduino IDE
* Computer
* Tablet oder Smartphone mit installierter SunFounder Controller-App

Kursschritte
----------------------

**Schritt 1: Einführung in den ESP32 CAM**

In unserem vorherigen Abenteuer haben wir unseren Mars Rover mit einem Paar "Augen" ausgestattet, indem wir den ESP32 CAM integriert haben. Heute werden wir mehr darüber lernen und ihn tatsächlich zum "Sehen" bringen.

.. image:: img/esp32_cam.png
    :width: 400
    :align: center

Der ESP32 CAM, der wie die Augen unseres Rovers fungiert, ist ein kleines, aber leistungsstarkes Modul. Es integriert nicht nur WiFi- und Bluetooth-Funktionen, sondern verfügt auch über eine kompakte Kamera. Diese Kamera hilft unserem Rover, Bilder seiner Umgebung aufzunehmen.

So wie wir unsere Augen nutzen, um unsere Umgebung zu beobachten, kann der ESP32 CAM "sehen", was vor dem Rover liegt, und diese visuellen Daten an unser Smartphone oder unseren Computer senden. Dadurch können wir alles, was der Rover sieht, in Echtzeit sehen!

Es ist, als ob wir den Rover direkt steuern und nicht nur den Rover selbst, sondern auch die Welt, die er erkundet, beobachten! Unglaublich, nicht wahr? Tauchen wir also tiefer ein...


**Schritt 2: Programmieren der Rover-Kamera und Betrachten des Feeds**

Nachdem wir den ESP32-CAM an unserem Rover angebracht haben, müssen wir ihm nun Leben einhauchen.
Dazu verwenden wir die Arduino IDE, um ein Programm zu schreiben, das die Kamera steuert, ihr eine Verbindung zu WiFi ermöglicht
und die aufgenommenen Bilder streamt.

So können wir vorgehen:

#. Installieren Sie die Bibliothek ``SunFounder AI Camera``.

    * Öffnen Sie den **Bibliotheksverwalter** der Arduino IDE, suchen Sie nach "SunFounder Camera" und klicken Sie auf **INSTALL**.

        .. image:: img/camera_install_lib.png

    * Ein Pop-up-Fenster für die Installation von Bibliotheksabhängigkeiten wird angezeigt. Klicken Sie auf **INSTALL ALL** und warten Sie, bis der Vorgang abgeschlossen ist.

        .. image:: img/camera_install_lib1.png

#. Geben Sie in der Arduino IDE den folgenden Code ein.

    Was die Variablen ``NAME``, ``TYPE`` und ``PORT`` im Code betrifft, wollen wir jetzt nicht näher darauf eingehen. Sie werden in unserem nächsten Schritt eine Rolle spielen. Behalten Sie einfach im Hinterkopf, dass diese Variablen auf unserer bevorstehenden Reise zur Einrichtung eines Echtzeit-Videofeeds von unserem Mars Rover wichtig sein werden.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b648e4-23e8-4b28-accd-aac171069116/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


    Beachten Sie, dass wir im Code zwei Verbindungsmodi haben - den **AP**-Modus und den **STA**-Modus. Sie können je nach Ihren spezifischen Anforderungen entscheiden, welchen Sie verwenden möchten.

    * **AP-Modus**: In diesem Modus erstellt der Rover einen Hotspot (im Code als ``GalaxyRVR`` benannt). Dies ermöglicht jedem Gerät wie einem Mobiltelefon, Tablet oder Laptop, eine Verbindung zu diesem Netzwerk herzustellen. Dies ist besonders nützlich, wenn Sie den Rover unter allen Umständen fernsteuern möchten. Beachten Sie jedoch, dass Ihr Gerät dadurch vorübergehend keine Verbindung zum Internet herstellen kann.

        .. code-block:: arduino

            // AP-Modus
            #define WIFI_MODE WIFI_MODE_AP
            #define SSID "GalaxyRVR"
            #define PASSWORD "12345678"

    * **STA-Modus**: In diesem Modus verbindet sich der Rover mit Ihrem Heim-WiFi-Netzwerk. Denken Sie daran, dass Ihr steuerndes Gerät (wie ein Mobiltelefon oder Tablet) ebenfalls mit demselben WiFi-Netzwerk verbunden sein sollte. Dieser Modus ermöglicht es Ihrem Gerät, während der Steuerung des Rovers weiterhin auf das Internet zuzugreifen, begrenzt jedoch die Reichweite des Rovers auf Ihren WiFi-Abdeckungsbereich.

        .. code-block:: arduino

            // STA-Modus
            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "IHR SSID"
            #define PASSWORD "IHR PASSWORT"

#. Laden Sie den Code auf unseren Rover hoch und erwecken Sie unseren ESP32 CAM zum Leben!

    * Der ESP32-CAM und das Arduino-Board teilen sich die gleichen RX (Empfangs-) und TX (Send-) Pins. Bevor Sie den Code hochladen, müssen Sie daher zuerst den ESP32-CAM freigeben, indem Sie diesen Schalter nach rechts schieben, um Konflikte oder potenzielle Probleme zu vermeiden.

        .. image:: ../img/camera_upload.png
            :width: 600

    * Sobald der Code erfolgreich hochgeladen wurde, schieben Sie ihn zurück auf die linke Seite, um den ESP32 CAM zu starten.

        .. note::
            Dieser Schritt und der vorherige sind jedes Mal erforderlich, wenn Sie den Code erneut hochladen.

        .. image:: img/camera_run.png
            :width: 600

    * Öffnen Sie den **Seriellen Monitor** und stellen Sie die Baudrate auf 115200 ein. Wenn keine Informationen angezeigt werden, drücken Sie die **Reset-Taste** auf dem GalaxyRVR-Shield, um den Code erneut auszuführen. Sie sollten eine IP-Adresse in der Ausgabe des Seriellen Monitors sehen. Dies ist die Adresse, an die die Kamera Ihres Rovers sendet.

        .. image:: img/camera_serial.png


    * Nun ist es an der Zeit, tatsächlich zu sehen, was unser Rover sieht! Öffnen Sie einen Webbrowser - wir empfehlen Google Chrome - und geben Sie die URL ein, die Sie im Seriellen Monitor sehen, im Format ``http://ip:9000/mjpg``.

        .. image:: img/camera_view.png

Und voilà! Sie sollten nun in der Lage sein, den Live-Feed von der Kamera Ihres Rovers zu sehen. Ist es nicht erstaunlich, dass Sie den Mars (oder vielleicht nur Ihr Wohnzimmer) aus der Perspektive des Rovers betrachten? Genau wie ein echter Mars Rover-Wissenschaftler!

Denken Sie daran, dies ist erst der Anfang. Es gibt noch viel mehr zu entdecken und zu lernen. In unserem nächsten Schritt werden wir erkunden, wie wir unseren Rover steuern können, während wir den Live-Kamera-Feed betrachten. Aufregend, nicht wahr? Vorwärts, Entdecker!
