.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _update_firmware:

Aggiornamento Firmware
======================

Il Suo dispositivo potrebbe non avere il firmware più recente a causa dei continui miglioramenti del prodotto.
Si consiglia di aggiornare il firmware prima del primo utilizzo per garantire il corretto funzionamento. L'aggiornamento del firmware garantisce:

* **Correzioni di bug**: Risolve problemi noti e migliora la stabilità.
* **Compatibilità con le app**: Il firmware più recente è necessario per il corretto funzionamento dell'app RoboPilot e di Mammoth Coding.
* **Nuove funzionalità**: Gli aggiornamenti del firmware possono aggiungere nuove capacità e miglioramenti.
* **Migliori prestazioni**: Ottimizzazioni per la connettività WiFi, lo streaming video e il controllo dei motori.

.. note::
   Se preferisce non aggiornare il firmware e desidera continuare a utilizzare la configurazione attuale, può fare riferimento alla `Documentazione GalaxyRVR v1 <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_.


.. raw:: html

   <iframe width="600" height="400" src="https://www.youtube.com/embed/Tl2W26pIQoU?si=98bbfUPc1g2cEz3A" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


1. Verificare se è necessario un aggiornamento
-----------------------------------------------

#. Accendere GalaxyRVR e controllare la striscia luminosa inferiore.

   * Prima di utilizzare GalaxyRVR per la prima volta, caricare completamente la batteria con il cavo USB Type-C in dotazione.
   * Accendere l'interruttore di alimentazione.
   * Portare la modalità su **Run** e premere il pulsante **Reset** sulla scheda R3.
   * La striscia luminosa inferiore inizierà a lampeggiare per indicare l'avvenuto avvio.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

#. Controllare la striscia luminosa inferiore.

   * Se la striscia luminosa inferiore mostra una **luce verde lampeggiante**, il firmware dell'ESP32 è già aggiornato. Può procedere a :ref:`quick_start`.
   * Se la striscia luminosa inferiore lampeggia di **un altro colore**, sarà necessario:

     - :ref:`update_esp32_firmware`
     - :ref:`update_r3_firmware`


.. _update_esp32_firmware:

2. Aggiornamento del Firmware dell'ESP32 CAM
----------------------------------------------

L'ESP32 CAM trasmette l'hotspot Wi-Fi e acquisisce video per GalaxyRVR.
Se il firmware non è aggiornato, queste funzioni potrebbero non funzionare correttamente. Segua i passaggi seguenti per aggiornare il firmware.

#. Accendere l'interruttore di alimentazione di GalaxyRVR. Per avviare l'ESP32 CAM, portare la modalità su **Run** e premere il pulsante **Reset** sulla scheda R3.

   .. image:: img/camera_run.png
        :width: 500
        :align: center

#. Scaricare il file del firmware.

   * |download_galaxyrvr_filmware|

#. Estrarre il file ZIP scaricato. Individuare il file firmware denominato ``ai-camera-firware.ino.x.x.x.bin`` e trasferirlo sul Suo dispositivo mobile. Può utilizzare qualsiasi app di gestione file, come ES File Explorer o un'utility di trasferimento file.

   .. image:: img/firmware_bin_file.png
        :align: center

#. Connettersi alla rete Wi-Fi di GalaxyRVR con il proprio dispositivo mobile.

   * Il nome della rete (SSID) è ``GalaxyRVR`` e la password è ``12345678``.
   * Se viene visualizzato un avviso che indica "Nessun accesso a Internet", scelga l'opzione **"Rimani connesso"**.

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Aprire un browser web sul dispositivo mobile e navigare all'indirizzo ``http://192.168.4.1`` per accedere alla pagina di aggiornamento OTA dell'ESP32 CAM.


.. note:: In questa pagina, vedrà le opzioni di aggiornamento OTA in una delle due interfacce. La Versione A (la prima) e la Versione B (la seconda) appariranno in base alla versione del firmware. Selezioni semplicemente i passaggi di aggiornamento corrispondenti in base all'interfaccia visualizzata.

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center


**Versione A**

   6. Nella pagina OTA, selezioni il file del firmware e avvii l'aggiornamento:

      * Scelga il file ``ai-camera-firmware-vX.X.X-ota.bin`` precedentemente scaricato dal dispositivo e faccia clic su **Add**.
      * Faccia clic sul pulsante **Update** per avviare l'aggiornamento del firmware e attenda il completamento.

      .. image:: img/faq_ota_a.png
         :width: 700

   #. Dopo il completamento dell'aggiornamento, il nome dell'hotspot Wi-Fi di GalaxyRVR cambierà in "AI Camera-xxxxxx" e la password rimarrà "12345678".


**Versione B**


   6. Nella pagina **OTA**, verificare la versione del firmware corrente visualizzata sulla pagina web.

      * Se il numero di versione è **superiore a 1.5.1**, non è necessario alcun aggiornamento. Può saltare i passaggi rimanenti e procedere direttamente a :ref:`quick_start`.
      * Se la versione è **1.5.1 o inferiore**, continui con l'aggiornamento.

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center


   #. Tocchi **Upgrade Firmware**, selezioni il file del firmware e attenda il completamento dell'aggiornamento:

      * Tocchi il pulsante **Upgrade Firmware**, quindi selezioni il file ``ai-camera-firware.ino.x.x.x.bin`` precedentemente scaricato sul dispositivo.
      * L'aggiornamento inizierà immediatamente e richiede solitamente 1-2 minuti. Al termine, selezioni **CONFIRM** per riavviare GalaxyRVR.

      .. image:: img/faq_ota_b.png
         :width: 700

   #. Dopo il completamento dell'aggiornamento, il nome dell'hotspot Wi-Fi di GalaxyRVR cambierà in "AI Camera-xxxxxx" e la password rimarrà "12345678".


.. _update_r3_firmware:

3. Aggiornamento del Firmware della Scheda R3
-----------------------------------------------

La scheda R3 include un firmware integrato che consente la comunicazione con l'APP RoboPilot e Mammoth Coding.

È necessario ricaricare questo firmware se:

- Il dispositivo utilizza una versione precedente del firmware, oppure
- Ha caricato il proprio codice Arduino e desidera ripristinare la compatibilità.

Segua i passaggi seguenti per reinstallare il firmware di comunicazione.

.. note::

   Se sta utilizzando un Mac, consulti la guida specifica per macOS:

   :ref:`uno_firmware_mac`

#. Colleghi Arduino al computer con un cavo USB A-B (non USB Type-C) e porti l'interruttore di modalità su **Upload**.

   .. image:: img/camera_upload.png
        :width: 500
        :align: center

#. Verificare che i file del firmware siano stati scaricati.

   * |download_galaxyrvr_filmware|

#. Eseguire lo script di aggiornamento.

   * Aprire la cartella ``galaxy-rvr.ino.xxx`` (scaricata e installata nel passaggio precedente).
   * Fare doppio clic sul file script ``update-arduino-firmware.bat``.
   * Apparirà automaticamente una finestra del prompt dei comandi.

   .. image:: img/faq_bat_file.png

#. Selezionare la porta seriale e caricare.

   * Nel prompt dei comandi, verrà visualizzato un elenco delle porte seriali disponibili.
   * Inserire il numero di sequenza mostrato a sinistra per selezionare la porta seriale di Arduino Uno.
   * Premere **Invio** per avviare il caricamento automatico.
   * Esempio: se l'elenco mostra `1 USB-SERIALXXX (COMxx)`, inserire **1** e premere **Invio**.

   .. image:: img/faq_select_com.png

#. Dopo aver atteso il completamento del caricamento, è possibile scollegare il cavo USB.

   .. image:: img/faq_uno_updating.png

.. important::

   * Questo firmware consente a GalaxyRVR di rispondere ai comandi dell'app.
   * Non sarà necessario caricare alcun codice aggiuntivo quando si utilizza l'app di controllo remoto RoboPilot o il software Mammoth Coding.
   * Ora può procedere a :ref:`quick_start` per iniziare il Suo viaggio con GalaxyRVR!
