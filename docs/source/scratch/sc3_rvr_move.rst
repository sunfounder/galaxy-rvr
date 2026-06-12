.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


.. _rvr_move:

Lektion 3: Fernsteuerung Ihres GalaxyRVR
================================================

Machen Sie sich bereit, die Kontrolle zu ubernehmen! In dieser Lektion werden Sie zum Missionskommandanten Ihres eigenen GalaxyRVR Mars Rovers.

Wir werden unser Programmierwissen in reale Aktionen umsetzen und Ihren Rover programmieren, um über simuliertes Marsgelande zu navigieren. Beobachten Sie, wie Ihre Befehle den Rover zum Leben erwecken und er sich genau so bewegt, wie Sie es im Klassenzimmer vorgeben.

Hier beginnt Ihre Mars-Mission wirklich - starten wir die Fahrt!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Lernziele
-----------------------

* Kommunikation zwischen der Mammoth Coding-App und Ihrem GalaxyRVR durch Hochladen des erforderlichen Arduino-Codes herstellen
* Die Steuerung der Rover-Bewegungen mithilfe der Pfeiltasten-Oberflache in der App meistern
* Die vier grundlegenden Rover-Manover programmieren und ausführen: vorwarts, ruckwarts, linksabbiegen und rechtsabbiegen

.. _app_connect:

Verbinden der App mit dem GalaxyRVR
-------------------------------------------

.. note::

    * Falls Sie die Firmware uberschrieben haben und die Kommunikation wiederherstellen müssen, folgen Sie :ref:`update_r3_firmware`.

.. raw:: html

   <iframe width="560" height="315" src="https://www.youtube.com/embed/kZIrm-_yWrA?si=Cbp0TxN-EZU_6Ksn" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

#. Laden Sie vor der ersten Verwendung des GalaxyRVR den Akku vollstandig mit dem mitgelieferten Typ-C-USB-Kabel auf. Schalten Sie den Strom nach dem Laden ein.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_start.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

#. Schalten Sie zum Starten des ESP32-CAM den Modus auf **Run** und drucken Sie die **Reset**-Taste auf dem R3-Board. Das untere Lichtband beginnt zu blinken, um einen erfolgreichen Start anzuzeigen.

   .. note::

      * Wenn das untere Lichtband ein **blinkendes Licht in einer anderen Farbe als Grun** zeigt, benotigt Ihr GalaxyRVR ein Firmware-Update. Bitte lesen Sie dazu :ref:`update_firmware`.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_reset_green.mp4" type="video/mp4">
            Ihr Browser unterstützt das Video-Tag nicht.
        </video>

#. Verbinden Sie Ihr mobiles Gerat mit dem WLAN-Netzwerk des GalaxyRVR.

   * Der Netzwerkname (SSID) lautet ``GalaxyRVR`` und das Passwort ist ``12345678``.
   * Wenn eine Warnung mit dem Hinweis "Kein Internetzugriff" erscheint, wahlen Sie bitte die Option **"Trotzdem verbinden"**.

     .. image:: ../img/camera_lan.png
        :width: 500

#. Öffnen Sie die Anwendung auf Ihrem mobilen Gerat, um den Verbindungsprozess zu starten.

   .. image:: img/connet_app_04.png

#. Wahlen und laden Sie die GalaxyRVR-Erweiterung in der App.

   .. image:: img/connet_app_05.png

#. Die App scannt und sucht automatisch nach verfugbaren GalaxyRVR-Geräten.

   .. image:: img/connet_app_06.png

#. Wahlen Sie Ihren GalaxyRVR aus der Liste aus, um sich zu verbinden.

   .. image:: img/reconnect_2.png

   .. note::

      Der Verbindungsstatus wird durch die LED-Leuchten des GalaxyRVR angezeigt:

      - **Blinkend Lila**: Suche nach Verbindung
      - **Dauerhaft Aus**: Erfolgreich verbunden und bereit

Erneutes Verbinden der App
-------------------------------------

Wenn Ihr Gerat vom GalaxyRVR getrennt wird, erscheint dieses Popup-Fenster in der Oberflache. Klicken Sie auf "Erneut verbinden".

   .. image:: img/reconnect_0.png

Wenn Sie das Popup-Fenster schlie?en, können Sie die Verbindung auch über diese Schaltflache in der GalaxyRVR-Kategorie wiederherstellen.

   .. image:: img/reconnect_1.png

Finden Sie Ihren GalaxyRVR und klicken Sie auf "Verbinden".

   .. image:: img/reconnect_2.png


Steuern des GalaxyRVR mit der App
-----------------------------------------

1. Finden Sie in der Programmieroberflache die spezielle GalaxyRVR-Kategorie mit allen Rover-Steuerblocken.

   .. image:: img/3_rvr_catego.png

2. Normalerweise verwenden wir die grune Flagge zum Starten von Programmen, aber es gibt auch andere Moglichkeiten, Aktionen auszulösen. Finden Sie den Block ``when up arrow key pressed`` in der Kategorie Ereignisse - dieser fuhrt Code aus, sobald Sie die entsprechende Taste drucken.

   .. image:: img/3_rvr_when_arrow.png

3. Erstellen Sie vier Ereignisblocke - einen für jede Pfeilrichtung (oben, unten, links, rechts). Dies bildet die Grundlage Ihres Rover-Steuerungssystems.

   .. image:: img/3_rvr_4_arrow.png
        :width: 800
        :align: center

   .. note:: Benotigen Sie mehr Programmierplatz? Klicken Sie auf das Augensymbol unter der grunen Flagge, um den Buhnenbereich vorubergehend auszublenden.

4. Vervollstandigen Sie nun jeden Ereignisblock mit dem entsprechenden Bewegungsbefehl:

   - Pfeil nach oben -> Vorwarts bewegen
   - Pfeil nach unten -> Ruckwarts bewegen
   - Pfeil nach links -> Links abbiegen
   - Pfeil nach rechts -> Rechts abbiegen

   .. image:: img/3_rvr_4_dir.png
        :width: 800
        :align: center

5. Klicken Sie auf die Buhnen-Erweiterungsschaltflache, um in den Vollbild-Steuerungsmodus zu wechseln.

   .. image:: img/3_rvr_stage.png

6. Sie sehen nun eine vergro?erte Buhne mit virtuellen Richtungstasten. Drucken Sie diese Tasten und beobachten Sie, wie Sie Ihren GalaxyRVR in Echtzeit direkt steuern!

   .. image:: img/3_rvr_stage2.png


Bewegungssteuerungsblocke
-----------------------------

* **Grundlegende Richtungssteuerung**

  Steuert die Bewegungsrichtung des GalaxyRVR. Verwenden Sie das Dropdown-Menu, um Vorwarts, Ruckwarts, Linksabbiegen oder Rechtsabbiegen auszuwahlen.

  .. image:: img/block/move_forward.png

* **Geschwindigkeitseinstellung**

  Stellt die Bewegungsgeschwindigkeit des GalaxyRVR ein. Hinweis: Dieser Block legt nur die Geschwindigkeit fest und lost keine Bewegung aus.

  .. image:: img/block/move_set_speed.png

* **Zeitgesteuerte Bewegung**

  Lasst den GalaxyRVR für eine bestimmte Dauer in die gewahlte Richtung fahren. Sie können:

  * Die Richtung (vorwarts/ruckwarts/links/rechts) aus dem Dropdown-Menu wahlen
  * Die Bewegungsdauer durch Andern des Zeitwerts festlegen

  .. image:: img/block/move_forward_1s.png

* **Geschwindigkeitsgesteuerte Bewegung**

  Bewegt den GalaxyRVR mit einem bestimmten Geschwindigkeitsprozentsatz. Sie können:

  * Die Bewegungsrichtung aus dem Dropdown-Menu wahlen
  * Den Geschwindigkeitsprozentsatz (0-100 %) anpassen

  .. image:: img/block/move_forward_80.png

* **Prazise Bewegungssteuerung**

  Kombiniert Geschwindigkeits- und Zeitsteuerung für prazise Bewegungen. Sie können:

  * Die Bewegungsrichtung festlegen
  * Den Geschwindigkeitsprozentsatz anpassen
  * Die Bewegungsdauer festlegen

  .. image:: img/block/move_forward_80_1s.png

* **Erweiterte Radsteuerung**

  Bietet unabhangige Steuerung jedes Rades für komplexe Manover. Sie können:

  * Die linke Radgeschwindigkeit separat einstellen
  * Die rechte Radgeschwindigkeit separat einstellen
  * Die Bewegungsdauer steuern

  .. image:: img/block/move_lr_sp_1s.png

* **Nothalt**

  Stoppt sofort samtliche Bewegungen des GalaxyRVR.

  .. image:: img/block/move_stop.png


