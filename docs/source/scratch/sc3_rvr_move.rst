.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _rvr_move:

Lezione 3: Controllo remoto del tuo GalaxyRVR
=============================================

Preparati a prendere i controlli! In questa lezione, diventerai il comandante della missione del tuo GalaxyRVR Mars Rover.

Trasformeremo la nostra conoscenza di codifica in azione reale, programmando il tuo rover per navigare su un terreno marziano simulato. Guarda come i tuoi comandi danno vita al rover, muovendosi esattamente come lo dirigi proprio qui in classe.

È qui che la tua missione su Marte inizia veramente – iniziamo a guidare!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Obiettivi di apprendimento
--------------------------

* Stabilire la comunicazione tra l'app Mammoth Coding e il tuo GalaxyRVR caricando il codice Arduino necessario
* Padroneggiare il controllo dei movimenti del tuo rover utilizzando l'interfaccia dei tasti freccia nell'APP
* Programmare ed eseguire le quattro manovre fondamentali del rover: avanti, indietro, gira a sinistra e gira a destra

.. _app_connect:

Collegare l'APP al GalaxyRVR
-------------------------------------------

.. note::

    * Se hai sovrascritto il firmware e devi ripristinare la comunicazione, segui :ref:`update_r3_firmware`.

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

#. Apri l'applicazione sul tuo dispositivo mobile per iniziare il processo di connessione.

   .. image:: img/connet_app_04.png

#. Seleziona e carica l'estensione GalaxyRVR all'interno dell'APP.

   .. image:: img/connet_app_05.png

#. L'APP cercherà e scannerizzerà automaticamente i dispositivi GalaxyRVR disponibili.

   .. image:: img/connet_app_06.png

#. Seleziona il tuo GalaxyRVR dall'elenco per connetterti.

   .. image:: img/reconnect_2.png

   .. note::

      Lo stato della connessione è indicato dalle luci LED del GalaxyRVR:

      - **Viola lampeggiante**: Ricerca della connessione
      - **Spento fisso**: Connesso con successo e pronto

Riconnessione APP
-------------------------------------

Quando il tuo dispositivo viene disconnesso dal GalaxyRVR, vedrai apparire questa finestra pop-up nell'interfaccia. Clicca riconnetti.

   .. image:: img/reconnect_0.png

Se chiudi la finestra pop-up, puoi anche riconnetterti cliccando questo pulsante nella categoria GalaxyRVR.

   .. image:: img/reconnect_1.png

Trova il tuo GalaxyRVR e clicca connetti.

   .. image:: img/reconnect_2.png


Controllare il GalaxyRVR con l'APP
-----------------------------------------

1. Nell'interfaccia di codifica, trova la categoria dedicata GalaxyRVR contenente tutti i blocchi di controllo del rover.

   .. image:: img/3_rvr_catego.png

2. Mentre tipicamente usiamo la bandiera verde per avviare i programmi, ci sono altri modi per attivare azioni. Trova il blocco ``when up arrow key pressed`` nella categoria Events - questo eseguirà il codice ogni volta che premi quel tasto specifico.


   .. image:: img/3_rvr_when_arrow.png

3. Crea quattro blocchi evento - uno per ogni direzione delle frecce (su, giù, sinistra, destra). Questo formerà la base del sistema di controllo del tuo rover.

   .. image:: img/3_rvr_4_arrow.png
        :width: 800
        :align: center

   .. note:: Hai bisogno di più spazio per il codice? Clicca l'icona dell'occhio sotto la bandiera verde per nascondere temporaneamente l'area dello stage.

4. Ora completa ogni blocco evento con il comando di movimento corrispondente:

   - Freccia su → Avanti
   - Freccia giù → Indietro
   - Freccia sinistra → Gira a sinistra
   - Freccia destra → Gira a destra

   .. image:: img/3_rvr_4_dir.png
        :width: 800
        :align: center

5. Clicca il pulsante di espansione dello stage per entrare nella modalità di controllo completo.

   .. image:: img/3_rvr_stage.png

6. Ora vedrai uno stage ingrandito con tasti direzionali virtuali. Premi questi tasti e guarda come controlli direttamente i movimenti del tuo GalaxyRVR in tempo reale!

   .. image:: img/3_rvr_stage2.png


Blocchi di controllo del movimento
----------------------------------

* **Controllo direzione di base**

  Controlla la direzione di movimento del GalaxyRVR. Usa il menu a discesa per selezionare avanti, indietro, gira a sinistra o gira a destra.

  .. image:: img/block/move_forward.png

* **Impostazione velocità**

  Imposta la velocità di movimento del GalaxyRVR. Nota: Questo blocco imposta solo la velocità e non avvia il movimento da solo.

  .. image:: img/block/move_set_speed.png

* **Movimento temporizzato**

  Fa muovere il GalaxyRVR nella direzione selezionata per una durata specifica. Puoi:

  * Scegliere la direzione (avanti/indietro/sinistra/destra) dal menu a discesa
  * Impostare la durata del movimento cambiando il valore del tempo

  .. image:: img/block/move_forward_1s.png

* **Movimento a velocità controllata**

  Muove il GalaxyRVR a una percentuale di velocità specifica. Puoi:

  * Selezionare la direzione del movimento dal menu a discesa
  * Regolare la percentuale di velocità (0-100%)

  .. image:: img/block/move_forward_80.png

* **Controllo preciso del movimento**

  Combina il controllo di velocità e tempo per movimenti precisi. Puoi:

  * Impostare la direzione del movimento
  * Regolare la percentuale di velocità
  * Impostare la durata del movimento

  .. image:: img/block/move_forward_80_1s.png

* **Controllo avanzato delle ruote**

  Fornisce un controllo indipendente su ciascuna ruota per manovre complesse. Puoi:

  * Impostare la velocità della ruota sinistra separatamente
  * Impostare la velocità della ruota destra separatamente
  * Controllare la durata del movimento

  .. image:: img/block/move_lr_sp_1s.png

* **Arresto di emergenza**

  Ferma immediatamente tutto il movimento del GalaxyRVR.

  .. image:: img/block/move_stop.png

