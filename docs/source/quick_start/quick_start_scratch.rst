.. note::

    Benvenuto/a nella community degli appassionati di Raspberry Pi, Arduino ed ESP32 di SunFounder su Facebook! Approfondisca le sue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolva problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impari e condivida**: Scambi suggerimenti e tutorial per migliorare le sue competenze.
    - **Anteprime esclusive**: Acceda in anteprima ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti speciali**: Goda di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipi a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicchi su |link_sf_facebook| e si unisca oggi stesso!

Gioco Rapido con Scratch
==================================

In questo capitolo imparerà come **aprire ed eseguire rapidamente progetti di esempio in Scratch (Mammoth Coding)** per vedere il suo GalaxyRVR in azione.

Se desidera imparare a creare questi script da zero, consulti il capitolo :ref:`programming_scratch`.

.. note::

    * La scheda R3 del GalaxyRVR viene fornita con un firmware che supporta l'app RoboPilot e Mammoth Coding.
    * Se ha sovrascritto il firmware e deve ripristinare la comunicazione, segua :ref:`update_r3_firmware`.


Come aprire rapidamente un esempio Scratch
-------------------------------------------

#. Scarichi i codici di esempio dal link seguente:

   * |download_galaxyrvr_code|

#. Estragga il file scaricato e trasferisca la cartella ``scratch_codes`` sul suo dispositivo mobile. Può utilizzare qualsiasi strumento di trasferimento file, come **ES File Explorer** o **File Transfer Assistant**.

   .. image:: img/scratch_mobile_save.png
      :width: 400

#. Cerchi **Mammoth Coding** su **Google Play** o **Apple App Store** e lo installi.

   .. image:: img/scratch_app_install.png
      :width: 600

#. Avvii il GalaxyRVR.

   * Prima di utilizzare GalaxyRVR per la prima volta, carichi completamente la batteria con il cavo USB Type-C in dotazione.
   * Accenda l'interruttore di alimentazione.
   * Porti l'interruttore di modalità su **Run** e prema il pulsante **Reset** sulla scheda R3.
   * La striscia luminosa inferiore lampeggerà di **verde**, indicando un avvio riuscito.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Connetta il suo dispositivo mobile alla rete WiFi del GalaxyRVR.

   * Il nome della rete (SSID) è ``GalaxyRVR`` e la password è ``12345678``.
   * Se vede un avviso che indica "Nessun accesso a Internet", scelga l'opzione **"Resta connesso"**.


     .. image:: ../img/camera_lan.png
        :width: 500

#. Nell'app, tocchi **File** > **Open from device** per sfogliare i file locali.

   .. image:: img/scratch_open_file.png
        :width: 600

#. Selezioni un file ``.sb3`` per aprirlo.

   .. image:: img/scratch_mobile_save.png
      :width: 400

#. Tocchi l'icona della bandiera verde per avviare lo script.

   .. image:: img/scratch_run.png

Esempi
---------------

**Progetti base**

Questi progetti sono i corsi base per controllare il GalaxyRVR con Mammoth Coding. La guideranno passo dopo passo su come utilizzare GalaxyRVR.


* ``3_move.sb3``: Controlla il movimento del suo GalaxyRVR in tempo reale utilizzando i tasti direzionali.
* ``4_ultrasonic.sb3``: Il rover avanza ed evita automaticamente gli ostacoli utilizzando il modulo a ultrasuoni.
* ``5_ultra_animate_jump.sb3``: Crea una scena animata del rover che si muove gioiosamente sulla superficie marziana.
* ``6_ir_obstacle_avoid.sb3``: Il rover avanza ed evita gli ostacoli utilizzando i sensori IR.
* ``7_ir_obstacle_avoid_animate.sb3``: Controlla lo sprite del rover per schivare rocce sulla superficie marziana attivando i sensori IR con le mani.
* ``8_ir_ultrasonic_avoid.sb3``: Il rover utilizza insieme sensori a ultrasuoni e IR per navigare agevolmente intorno agli ostacoli.
* ``9_ir_ultrasonic_follow.sb3``: Il rover La segue: si avvicina quando si trova di fronte, gira verso di Lei quando è di lato e si ferma quando si allontana.
* ``10_rgb.sb3``: Tocchi una palla colorata per far illuminare le luci RGB del rover in quel colore.
* ``10_rgb_animate.sb3``: Il rover si muove e cambia colore della luce in base ai tasti direzionali premuti.
* ``1scratch_servo.sb3``: Usi i tasti freccia per regolare l'angolo della fotocamera del rover; clicchi per ripristinare la sua posizione.
* ``1scratch_servo_stage.sb3``: Tocchi e trascini la freccia sullo schermo per puntare la fotocamera del rover con una risposta fluida in tempo reale.
* ``12_camera.sb3``: Visualizza il feed in diretta della fotocamera dalla prospettiva del suo rover mentre esplora.
* ``13_realtime_control.sb3``: Controlla i movimenti e le luci del suo rover in tempo reale attraverso Scratch.

**Progetti divertenti**

Questi progetti Scratch divertenti non richiedono il GalaxyRVR.
Può trovarli tutti nella cartella ``scratch_codes/fun/``.

* ``1_scratch_balloon.sb3``: Gonfi il palloncino bloccando il sensore IR sinistro; non lo faccia scoppiare o cadere!
* ``2_flappy_parrot.sb3``: Controlli il volo del pappagallo usando la mano sopra il sensore a ultrasuoni per schivare i pali di bambù.
* ``3_shooting.sb3``: Miri e spari ai bersagli usando il modulo di evitamento ostacoli.
* ``4_eat_apple.sb3``: Guidhi lo scarabeo verso la mela usando i gesti della mano rilevati dal sensore IR sinistro.
* ``5_fishing.sb3``: Catturi i pesci bloccando il sensore IR sinistro al momento giusto.
* ``6_sensitive_ball.sb3``: Muova la palla su o giù con la mano sopra il sensore a ultrasuoni; attivi suoni e luci quando tocca una linea.
* ``7_tap_white_tile.sb3``: Tocchi le piastrelle nere usando due sensori IR per segnare punti — eviti quelle bianche!
