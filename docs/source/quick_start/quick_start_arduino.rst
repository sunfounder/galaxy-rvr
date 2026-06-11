
Schnellstart mit Arduino
===============================

In diesem Kapitel lernen Sie, wie Sie **bestimmte Arduino-Beispielcodes schnell öffnen und ausführen**, um Ihren GalaxyRVR verschiedene Aktionen ausführen zu lassen.

Wenn Sie die Code-Logik und die Programmierprinzipien hinter diesen Beispielen verstehen möchten, lesen Sie bitte das Kapitel :ref:`programming_arduino`.

So öffnen Sie schnell ein Arduino-Beispiel
----------------------------------------------

In diesem Beispiel zeigen wir Ihnen, wie Sie mit der Arduino IDE ein Arduino-Beispiel öffnen.

#. Starten Sie den GalaxyRVR.

   * Bei der ersten Verwendung des GalaxyRVR wird empfohlen, den Akku durch Anschließen eines Typ-C-USB-Kabels vollständig aufzuladen. Schalten Sie dann den Strom ein.

     .. raw:: html

          <video width="600" loop autoplay muted>
              <source src="../_static/video/play_start.mp4" type="video/mp4">
              Ihr Browser unterstützt das Video-Tag nicht.
          </video>

   * Der ESP32-CAM und das Arduino-Board teilen sich dieselben RX (Empfangs-) und TX (Sende-) Pins. Bevor Sie den Code hochladen, müssen Sie daher den ESP32-CAM freigeben, indem Sie diesen Schalter nach rechts schieben, um Konflikte oder mögliche Probleme zu vermeiden.

     .. image:: ../img/camera_upload.png
        :width: 600

#. Verbinden Sie Ihr Arduino-Board mit einem USB-Kabel mit Ihrem Computer.

#. Besuchen Sie |link_download_arduino| und laden Sie die Arduino IDE für Ihr Betriebssystem herunter. Folgen Sie den Installationshinweisen, um die Einrichtung abzuschließen.

   .. image:: img/arduino_download_page.png

#. Laden Sie die Beispielcodes über den folgenden Link herunter:

   * |download_galaxyrvr_code|

#. Entpacken Sie die heruntergeladene Datei und navigieren Sie zu ``galaxy-rvr-1.2.x\lesson_codes``.

   .. image:: img/arduino_open_folder.png

#. Wählen Sie einen Beispielcode-Ordner aus, navigieren Sie in diesen Ordner und doppelklicken Sie auf die ``.ino``-Datei, um sie in der Arduino IDE zu öffnen.

   .. image:: img/arduino_open_file.png

#. Wählen Sie in der Arduino IDE **Arduino Uno** als Board aus und wählen Sie den entsprechenden **Port** für Ihr Gerät.

   .. image:: img/arduino_choose_board.png

#. Klicken Sie auf die Schaltfläche **Hochladen** (Pfeil nach rechts), um den Code auf Ihr Board zu laden.

   .. image:: img/arduino_upload.png

.. note::

    Wenn Sie mit der Arduino IDE nicht vertraut sind, lesen Sie bitte:

    * :ref:`install_arduino_ide`
    * :ref:`upload_sketch`

Beispiele
------------

* ``5_car_move``: Der Rover fährt vorwärts, dann rückwärts, dreht sich nach links und rechts und stoppt schließlich.
* ``6_ir_avoid``: Der Rover weicht Hindernissen mithilfe von IR-Sensoren aus.
* ``7_ultrasonic_avoid``: Der Rover weicht Hindernissen mithilfe des Ultraschallmoduls aus.
* ``8_ultrasonic_ir_avoid``: Der Rover verwendet sowohl das IR- als auch das Ultraschallmodul zur Hinderniserkennung.
* ``8_ultrasonic_ir_follow``: Der Rover folgt Objekten mithilfe des IR- und des Ultraschallmoduls.
* ``9_rgb_car_move``: Fügt Farbindikatoren für Bewegungen hinzu: Grün für vorwärts, Rot für rückwärts und Gelb für Links- oder Rechtsdrehungen.
* ``10_servo_range``: Die Kameraplattform dreht sich mit einer for-Schleife von 0° bis 180°, und der aktuelle Winkel wird im seriellen Monitor angezeigt.
* ``11_camera_view``: Zeigen Sie das Live-Videobild der Rover-Kamera in einem Webbrowser an. Die Bibliothek **SunFounder AI Camera** ist erforderlich.
* ``13_read_battery``: Überwacht die Batteriespannung über den Code.
