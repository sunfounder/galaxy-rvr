Gioco Rapido con Scratch
==================================

In questo capitolo imparerai come **aprire ed eseguire rapidamente progetti di esempio in Scratch (Mammoth Coding)** per vedere il tuo GalaxyRVR in azione.

Se vuoi imparare a creare questi script da zero, consulta il capitolo :ref:`programming_scratch`.

.. note::

    * La scheda R3 del GalaxyRVR viene fornita con un firmware che supporta l'App RoboPilot e Mammoth Coding.
    * Se hai sovrascritto il firmware e devi ripristinare la comunicazione, segui :ref:`update_r3_firmware`.


Come aprire rapidamente un esempio Scratch
------------------------------------------

#. Scarica i codici di esempio dal link qui sotto:

   * |download_galaxyrvr_code|

#. Estrai il file scaricato e trasferisci la cartella ``scratch_codes`` sul tuo dispositivo mobile. Puoi utilizzare qualsiasi strumento di trasferimento file, come **ES File Explorer** o **File Transfer Assistant**.

   .. image:: img/scratch_mobile_save.png
      :width: 400

#. Cerca **Mammoth Coding** su **Google Play** o **Apple App Store** e installalo.

   .. image:: img/scratch_app_install.png
      :width: 600

#. Prima di utilizzare GalaxyRVR per la prima volta, carica completamente la batteria con il cavo USB Type-C in dotazione. Dopo la ricarica, accendi l'alimentazione.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_start.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Per avviare l'ESP32 CAM, porta l'interruttore di modalità su **Run** e premi il pulsante **Reset** sulla scheda R3. La striscia luminosa inferiore inizierà a lampeggiare per indicare un avvio riuscito.

   .. note::

      * Se la striscia luminosa inferiore mostra una **luce lampeggiante di qualsiasi colore diverso dal verde**, il tuo GalaxyRVR necessita di un aggiornamento del firmware. Consulta :ref:`update_firmware`.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_reset_green.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>


#. Connetti il tuo dispositivo mobile alla rete WiFi del GalaxyRVR.

   * Il nome della rete (SSID) è ``GalaxyRVR`` e la password è ``12345678``.
   * Se vedi un avviso che indica "Nessun accesso a Internet", scegli l'opzione **"Resta connesso"**.


     .. image:: ../img/camera_lan.png
        :width: 500

#. Nell'app, tocca **File** > **Open from device** per sfogliare i file locali.

   .. image:: img/scratch_open_file.png
        :width: 600

#. Seleziona un file ``.sb3`` per aprirlo.

   .. image:: img/scratch_mobile_save.png
      :width: 400

#. Tocca l'icona della bandiera verde per avviare lo script.

   .. image:: img/scratch_run.png

Esempi
---------------

**Progetti base**

Questi progetti sono i corsi base per controllare il GalaxyRVR con Mammoth Coding. Ti guideranno passo dopo passo su come utilizzare GalaxyRVR.


* ``3_move.sb3``: Controlla il movimento del tuo GalaxyRVR in tempo reale utilizzando i tasti direzionali.
* ``4_ultrasonic.sb3``: Il rover avanza ed evita automaticamente gli ostacoli utilizzando il modulo a ultrasuoni.
* ``5_ultra_animate_jump.sb3``: Crea una scena animata del rover che si muove gioiosamente sulla superficie marziana.
* ``6_ir_obstacle_avoid.sb3``: Il rover avanza ed evita gli ostacoli utilizzando i sensori IR.
* ``7_ir_obstacle_avoid_animate.sb3``: Controlla lo sprite del rover per schivare rocce sulla superficie marziana attivando i sensori IR con le mani.
* ``8_ir_ultrasonic_avoid.sb3``: Il rover utilizza insieme sensori a ultrasuoni e IR per navigare agevolmente intorno agli ostacoli.
* ``9_ir_ultrasonic_follow.sb3``: Il rover ti segue: si avvicina quando ti trovi di fronte, gira verso di te quando sei di lato e si ferma quando ti allontani.
* ``10_rgb.sb3``: Tocca una palla colorata per far illuminare le luci RGB del rover in quel colore.
* ``10_rgb_animate.sb3``: Il rover si muove e cambia colore della luce in base ai tasti direzionali premuti.
* ``1scratch_servo.sb3``: Usa i tasti freccia per regolare l'angolo della fotocamera del rover; clicca per ripristinare la sua posizione.
* ``1scratch_servo_stage.sb3``: Tocca e trascina la freccia sullo schermo per puntare la fotocamera del rover con una risposta fluida in tempo reale.
* ``12_camera.sb3``: Visualizza il feed in diretta della fotocamera dalla prospettiva del tuo rover mentre esplora.
* ``13_realtime_control.sb3``: Controlla i movimenti e le luci del tuo rover in tempo reale attraverso Scratch.

**Progetti divertenti**

Questi progetti Scratch divertenti non richiedono il GalaxyRVR.
Puoi trovarli tutti nella cartella ``scratch_codes/fun/``.

* ``1_scratch_balloon.sb3``: Gonfia il palloncino bloccando il sensore IR sinistro; non farlo scoppiare o cadere!
* ``2_flappy_parrot.sb3``: Controlla il volo del pappagallo usando la mano sopra il sensore a ultrasuoni per schivare i pali di bambù.
* ``3_shooting.sb3``: Mira e spara ai bersagli usando il modulo evitamento ostacoli.
* ``4_eat_apple.sb3``: Guida lo scarabeo verso la mela usando i gesti della mano rilevati dal sensore IR sinistro.
* ``5_fishing.sb3``: Cattura i pesci bloccando il sensore IR sinistro al momento giusto.
* ``6_sensitive_ball.sb3``: Muovi la palla su o giù con la mano sopra il sensore a ultrasuoni; attiva suoni e luci quando tocca una linea.
* ``7_tap_white_tile.sb3``: Tocca le piastrelle nere usando due sensori IR per segnare punti — evita quelle bianche!
