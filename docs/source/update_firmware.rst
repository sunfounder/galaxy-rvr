.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _update_firmware:

Aggiornamento del firmware
==========================

Il Suo dispositivo potrebbe non avere il firmware più recente a causa dei continui miglioramenti del prodotto.
Si consiglia di aggiornare il firmware prima del primo utilizzo per garantire il corretto funzionamento. L'aggiornamento del firmware garantisce:

* **Correzioni di bug**: Risolve problemi noti e migliora la stabilità.
* **Compatibilità con le app**: Il firmware più recente è necessario per il corretto funzionamento dell'app RoboPilot e di Mammoth Coding.
* **Nuove funzionalità**: Gli aggiornamenti del firmware possono aggiungere nuove capacità e miglioramenti.
* **Migliori prestazioni**: Ottimizzazioni per la connettività WiFi, lo streaming della fotocamera e il controllo dei motori.

.. note::
   Se preferisce non aggiornare il firmware e desidera continuare a utilizzare la configurazione attuale, può fare riferimento alla `Documentazione GalaxyRVR v1 <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_.


.. Video temporaneamente disattivato: mostra la vecchia procedura di aggiornamento ed è obsoleto. Riattivarlo quando il nuovo video sarà registrato.
..
.. .. raw:: html
..
..    <iframe width="600" height="400" src="https://www.youtube.com/embed/Tl2W26pIQoU?si=98bbfUPc1g2cEz3A" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

.. _update_r3_firmware:

1. Aggiornamento del firmware dell'UNO R3
-----------------------------------------

La scheda R3 contiene il firmware che comunica con l'app RoboPilot e Mammoth Coding. Reinstallarlo con il flasher basato sul web: apra |link_galaxy_rvr_flasher| in **Chrome** o **Edge** su un computer — funziona nel browser, non richiede software aggiuntivo e mostra ogni passaggio con la propria immagine.

Il flasher prevede tre passaggi:

#. **Connect** — Accenda il rover, colleghi la scheda principale al computer con un cavo USB da A a B (non quello Type-C), quindi porti l'interruttore di modalità in posizione **Upload**. Poi faccia clic su **Next**.

   .. image:: img/flasher_step1.jpg
      :width: 500

#. **Flash** — Faccia clic su **Connect & Flash**. Nella finestra della porta che si apre, scelga la porta della Sua scheda (ad esempio ``USB Serial (COMxx)``), quindi faccia clic su **Connect** e il flashing avrà inizio. Se non funziona, faccia semplicemente di nuovo clic su **Connect & Flash**.

   .. image:: img/flasher_step2.jpg
      :width: 500

#. **Debug** — Al termine del flashing, nella finestra di log vedrà quanto segue, che conferma che il firmware è stato scritto e mostra la versione corrente (**2.0.2**). Ignori ``Initialzing...`` e tutto ciò che segue a questo punto: il rover è ancora in modalità **Upload**, quindi non può ancora comunicare con l'ESP32 CAM. Poi faccia clic su **Next**.

   .. code-block::

      Reading firmwares/galaxy-rvr-2.0.2.hex
      Resetting the board...
      Connecting to the board...
      Firmware written.
      Verified - flash matches the file.

      ---------- serial open at 115200 ----------
      GalaxyRVR version 2.0.2
      Initialzing...
      SET+RESET
      ...SET+RESET
      ...SET+RESET
      ...[FAIL]

#. Ora segua il messaggio: accenda l'interruttore di alimentazione, riporti l'interruttore di modalità nella posizione originale e prema il pulsante **Reset** sulla scheda R3.

   .. image:: img/flasher_step3_run.jpg
      :width: 500
   
#. La finestra di log mostra quindi il firmware attuale dell'ESP32 CAM.

   * Se il firmware dell'ESP32 CAM è **1.5.0 o superiore**, il log mostra il firmware dell'UNO R3, il firmware dell'ESP32 CAM e infine un indirizzo web come ``http://xxx.xxx.xx.xxx:9000/mjpg``.
   * Se è **inferiore a 1.5.0**, la finestra di log mostra che il firmware dell'ESP32 CAM deve essere aggiornato — continui con :ref:`update_esp32_firmware`.

   .. image:: img/flasher_step3.jpg
      :width: 500


.. _update_esp32_firmware:

2. Aggiornamento del firmware dell'ESP32 CAM
--------------------------------------------

L'ESP32 CAM trasmette l'hotspot Wi-Fi e acquisisce video per il GalaxyRVR.  
Se il firmware è obsoleto, queste funzioni potrebbero non funzionare correttamente. Segua i passaggi seguenti per aggiornare il firmware.

#. Accenda l'interruttore di alimentazione del GalaxyRVR. Per avviare l'ESP32 CAM, porti la modalità su **Run** e prema il pulsante **Reset** sulla scheda R3.

   .. image:: img/camera_run.png
        :width: 500
        :align: center
   
#. Scarichi il file del firmware.

   * |download_galaxyrvr_filmware|

#. Estragga il file ZIP scaricato. Individui il file firmware denominato ``ai-camera-firware.ino.x.x.x.bin`` e lo trasferisca sul Suo dispositivo mobile. Può utilizzare qualsiasi app di gestione file, come ES File Explorer o un'utility di trasferimento file.

   .. image:: img/firmware_bin_file.png
        :align: center

#. Colleghi il Suo dispositivo mobile alla rete WiFi del GalaxyRVR.

   * Il nome della rete (SSID) è ``GalaxyRVR`` e la password è ``12345678``.  
   * Se vede un avviso che indica "Nessun accesso a Internet", scelga l'opzione **"Resta connesso"**.

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Apra un browser web sul Suo dispositivo mobile e vada all'indirizzo ``http://192.168.4.1`` per accedere alla pagina di aggiornamento OTA dell'ESP32 CAM.


.. note:: In questa pagina, vedrà le opzioni di aggiornamento OTA in una delle due interfacce. La Versione A (la prima) e la Versione B (la seconda) appariranno in base alla versione del firmware. Selezioni semplicemente i passaggi di aggiornamento corrispondenti all'interfaccia visualizzata.

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center


**Versione A**

   6. Nella pagina OTA, selezioni il file del firmware e avvii l'aggiornamento:

      * Scelga il file ``ai-camera-firmware-vX.X.X-ota.bin`` precedentemente scaricato sul Suo dispositivo e faccia clic su **Add**.
      * Faccia clic sul pulsante **Update** per avviare l'aggiornamento del firmware, quindi attenda che sia completato.

      .. image:: img/faq_ota_a.png
         :width: 700


   #. Al termine dell'aggiornamento, il nome dell'hotspot WiFi del GalaxyRVR cambierà in "AI Camera-xxxxxx" e la password rimarrà "12345678".


**Versione B**


   6. Nella pagina **OTA**, controlli la versione del firmware attuale visualizzata sulla pagina web.
      
      * Se il numero di versione è **1.5.0 o superiore**, non è necessario alcun aggiornamento. Può saltare i passaggi rimanenti e procedere direttamente a :ref:`quick_start`.
      * Se la versione è **inferiore a 1.5.0**, continui con l'aggiornamento.

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center

   #. Tocchi **Upgrade Firmware**, selezioni il file del firmware e attenda il completamento dell'aggiornamento:

      * Tocchi il pulsante **Upgrade Firmware**, quindi selezioni il file ``ai-camera-firware.ino.x.x.x.bin`` precedentemente scaricato sul Suo dispositivo.
      * L'aggiornamento inizierà immediatamente e richiede in genere 1-2 minuti. Al termine, selezioni **CONFIRM** per riavviare il GalaxyRVR.

      .. image:: img/faq_ota_b.png
         :width: 700

   #. Al termine dell'aggiornamento, il nome dell'hotspot WiFi del GalaxyRVR cambierà in "AI Camera-xxxxxx" e la password rimarrà "12345678".


3. Verifica all'avvio
---------------------

* Prima di utilizzare il GalaxyRVR per la prima volta, carichi completamente la batteria con il cavo USB Type-C in dotazione.
* Accenda l'interruttore di alimentazione.
* Porti la modalità su **Run** e prema il pulsante **Reset** sulla scheda R3.
* La striscia luminosa inferiore lampeggerà in **verde**, indicando un avvio riuscito.

.. raw:: html

   <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=_idwN0kJrxbVW-5H" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
