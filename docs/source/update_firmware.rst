
.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _update_firmware:

Aggiornamento Firmware
==========================

Il tuo dispositivo potrebbe non avere il firmware più recente a causa dei continui miglioramenti del prodotto.
Per garantire prestazioni ottimali e stabili, segui i passaggi seguenti per controllare e aggiornare il firmware del tuo ESP32 CAM e della scheda R3.

1. Verifica se è necessario un aggiornamento
---------------------------------------------

#. Prima di utilizzare GalaxyRVR per la prima volta, carica completamente la batteria con il cavo USB Type-C in dotazione. Dopo la ricarica, accendi l'alimentazione.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_start.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Per avviare l'ESP32 CAM, porta l'interruttore di modalità su **Run** e premi il pulsante **Reset** sulla scheda R3. La striscia luminosa inferiore inizierà a lampeggiare per indicare un avvio riuscito.

   .. note::

      * Se la striscia luminosa inferiore mostra una **luce verde lampeggiante**, il firmware ESP32 è già aggiornato.
      * Puoi procedere a :ref:`quick_start`.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset_green.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Se la striscia luminosa inferiore lampeggia di **un altro colore**, dovrai:

   * :ref:`update_esp32_firmware`
   * :ref:`update_r3_firmware`

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>


.. _update_esp32_firmware:

2. Aggiornamento del firmware ESP32 CAM
---------------------------------------

L'ESP32 CAM trasmette l'hotspot Wi-Fi e cattura video per il GalaxyRVR.
Se il firmware è obsoleto, queste funzioni potrebbero non funzionare correttamente. Segui i passaggi seguenti per aggiornare il firmware.

#. Accendi l'interruttore di alimentazione del GalaxyRVR. Per avviare l'ESP32 CAM, porta l'interruttore di modalità su **Run** e premi il pulsante **Reset** sulla scheda R3.

   .. image:: img/camera_run.png
        :width: 500
        :align: center

#. Scarica il file del firmware.

   * |download_galaxyrvr_filmware|

#. Estrai il file ZIP scaricato. Individua il file firmware chiamato ``ai-camera-firware.ino.x.x.x.bin`` e trasferiscilo sul tuo dispositivo mobile. Puoi utilizzare qualsiasi app di gestione file, come ES File Explorer o un'utilità di trasferimento file.

   .. image:: img/firmware_bin_file.png
        :align: center

#. Connetti il tuo dispositivo mobile alla rete WiFi del GalaxyRVR.

   * Il nome della rete (SSID) è ``GalaxyRVR`` e la password è ``12345678``.
   * Se vedi un avviso che indica "Nessun accesso a Internet", scegli l'opzione **"Resta connesso"**.

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Apri un browser web sul tuo dispositivo mobile e naviga a ``http://192.168.4.1`` per accedere alla pagina di aggiornamento OTA dell'ESP32 CAM.


.. note:: In questa pagina, vedrai le opzioni di aggiornamento OTA in una delle due interfacce. La Versione A (la prima) e la Versione B (la seconda) appariranno in base alla versione del tuo firmware. Seleziona semplicemente i passaggi di aggiornamento corrispondenti in base all'interfaccia che vedi.

   .. image:: img/firmware_access_ab.png
      :width: 90%
      :align: center


**Versione A**

   6. Nella pagina OTA, clicca il pulsante per selezionare il file del firmware.

      .. image:: img/faq_cam_ota_choose.png
         :width: 400

   #. Scegli il file ``ai-camera-firmware-vX.X.X-ota.bin`` precedentemente scaricato dal tuo dispositivo e clicca **Add**.

      .. image:: img/faq_cam_ota_file.png
         :width: 400

   #. Clicca il pulsante **Update** per avviare il processo di aggiornamento del firmware.

      .. image:: img/faq_cam_ota_update.png
         :width: 400

   #. Attendi il completamento dell'aggiornamento.

      .. image:: img/faq_cam_ota_finish.png
         :width: 400

   #. Dopo il completamento dell'aggiornamento, puoi chiudere il browser web. Premi il pulsante **Reset** per riavviare il dispositivo. L'ESP32 CAM è ora pronto per il normale funzionamento.

      .. image:: img/camera_reset.png
         :width: 600

   .. note:: Dopo il completamento dell'aggiornamento, il nome dell'hotspot WiFi del GalaxyRVR cambierà in "AI Camera-xxxxxx" e la password rimarrà "12345678".


**Versione B**


   6. Nella pagina **OTA**, controlla la versione corrente del firmware visualizzata sulla pagina web.

      * Se il tuo numero di versione è **superiore a 1.5.1**, non è richiesto un aggiornamento. Puoi saltare i passaggi rimanenti e procedere direttamente a :ref:`quick_start`.
      * Se la versione è **1.5.1 o inferiore**, continua con l'aggiornamento.

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center


   #. Tocca il pulsante **Upgrade Firmware**.

      .. image:: img/firmware_tap.jpg
         :width: 50%
         :align: center

   #. Apparirà una finestra di dialogo per la selezione del file. Naviga e seleziona il file ``ai-camera-firware.ino.x.x.x.bin`` che hai trasferito in precedenza sul tuo dispositivo mobile.

      .. image:: img/firmware_select.jpg
         :width: 50%
         :align: center

   #. L'aggiornamento del firmware inizierà immediatamente dopo aver selezionato il file.

      .. image:: img/firmware_upgrade.jpg
         :width: 50%
         :align: center

   #. Attendi il completamento dell'aggiornamento del firmware.

      * Il processo di caricamento richiede in genere 1-2 minuti. Al termine, apparirà un messaggio di successo in una finestra pop-up.
      * Puoi quindi selezionare **CONFIRM** per riavviare il GalaxyRVR o **CLOSE** per chiudere la finestra.

      .. image:: img/firmware_finish.jpg
         :width: 50%
         :align: center


.. _update_r3_firmware:

3. Aggiornamento del firmware della scheda R3
---------------------------------------------

La scheda R3 include un firmware integrato che abilita la comunicazione con l'App RoboPilot e Mammoth Coding.

Devi ricaricare questo firmware se:

- Il tuo dispositivo utilizza una versione firmware precedente, o
- Hai caricato il tuo codice Arduino e vuoi ripristinare la compatibilità.

Segui i passaggi seguenti per reinstallare il firmware di comunicazione.

#. Collega Arduino al computer con un cavo USB, quindi porta l'interruttore **upload** dell'auto all'estremità di upload.

   .. image:: img/camera_upload.png
        :width: 500
        :align: center

   .. note:: È la porta USB Type B per il collegamento ad Arduino, non la porta USB Type C per la ricarica.

#. Verifica se i file del firmware sono stati scaricati.

   * |download_galaxyrvr_filmware|

#. Esegui lo script di aggiornamento

   * Apri la cartella ``galaxy-rvr.ino.xxx`` (scaricata e installata nel passaggio precedente).
   * Fai doppio clic sullo script ``update-arduino-firmware.bat``.
   * Apparirà automaticamente una finestra del prompt dei comandi.

   .. image:: img/faq_bat_file.png

#. Seleziona la porta seriale e carica

   * Nel prompt dei comandi, verrà visualizzato un elenco di porte seriali disponibili.
   * Inserisci il numero di sequenza mostrato a sinistra per selezionare la porta seriale di Arduino Uno.
   * Premi **Enter** per avviare il caricamento automatico.
   * Esempio: Se l'elenco mostra `1 USB-SERIALXXX (COMxx)`, inserisci **1** e premi **Enter**.

   .. image:: img/faq_select_com.png

#. Dopo aver atteso il completamento del caricamento, puoi scollegare il cavo USB.

   .. image:: img/faq_uno_updating.png

   .. note::

      Questo codice abilita il GalaxyRVR a rispondere ai comandi dell'APP. Non sarà necessario caricare alcun codice aggiuntivo quando si utilizza l'app di controllo remoto RoboPilot o il software Mammoth Coding.

#. Ora puoi procedere a :ref:`quick_start` per iniziare la tua avventura con GalaxyRVR!
