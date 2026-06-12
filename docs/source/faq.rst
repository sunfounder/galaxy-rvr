.. note::

    Benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisca la Sua conoscenza di Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolva problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impari e condivida**: Scambi consigli e tutorial per migliorare le Sue competenze.
    - **Anteprime esclusive**: Ottenga accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goda di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipi a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicchi su |link_sf_facebook| e si unisca oggi!

FAQ
==============

1. Perché dovrebbe aggiornare il firmware?
----------------------------------------------------------------------------------------

SunFounder migliora continuamente il firmware del GalaxyRVR per offrire un'esperienza migliore. Consigliamo di aggiornare il firmware prima del primo utilizzo per garantire che tutto funzioni correttamente. L'aggiornamento del firmware garantisce:

* **Correzione di bug**: Risolve problemi noti e migliora la stabilità.
* **Compatibilità delle app**: Il firmware più recente è necessario per il corretto funzionamento dell'app RoboPilot e di Mammoth Coding.
* **Nuove funzionalità**: Gli aggiornamenti del firmware possono aggiungere nuove capacità e miglioramenti.
* **Prestazioni migliori**: Ottimizzazioni per la connettività WiFi, lo streaming della fotocamera e il controllo dei motori.

Per istruzioni dettagliate sull'aggiornamento, consultare :ref:`update_firmware`.

.. note::
   Se preferisce non aggiornare il firmware e desidera continuare a utilizzare la configurazione attuale, può fare riferimento alla `Documentazione GalaxyRVR v1 <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_.


2. Impossibile connettersi a GalaxyRVR?
-------------------------------------------------------------------------------------------------

Se non riesce a connettersi al GalaxyRVR, controlli quanto segue:

1. **Controlli la batteria**: Guardi gli indicatori della batteria sul rover. Se entrambi i LED sono spenti, la batteria è scarica. Carichi il rover utilizzando un cavo USB Type-C.
2. **Controlli l'interruttore di modalità**: Si assicuri che l'interruttore di modalità sia impostato su **Run** (non **Upload**). L'hotspot WiFi funziona solo in modalità Run.

   .. image:: img/camera_run.png
        :width: 500
        :align: center

3. **Reimposti la scheda R3**: Dopo essere passato alla modalità Run, prema il pulsante **Reset** sulla scheda R3. La striscia LED inferiore dovrebbe lampeggiare per indicare un avvio corretto.
4. **Controlli la password WiFi**: Il nome predefinito dell'hotspot (SSID) è ``GalaxyRVR`` e la password è ``12345678``. Si assicuri di aver inserito la password correttamente.
5. **Controlli l'ESP32 CAM**: Si assicuri che l'ESP32 CAM sia correttamente inserito nel suo slot. Se il LED dell'ESP32 CAM non è acceso, il modulo della fotocamera potrebbe non ricevere alimentazione o potrebbe essere danneggiato.
6. **Interferenze WiFi**: Altri dispositivi sullo stesso canale WiFi possono causare problemi di connessione. Se sospetta interferenze, provi a :ref:`cambiare il canale WiFi <change_wifi_channel>`.
7. **Dopo l'aggiornamento del firmware**: Se ha appena aggiornato il firmware dell'ESP32 CAM e il WiFi ha smesso di funzionare, consulti :ref:`faq_wifi_after_update`.
8. **Verifichi la connessione del Suo dispositivo mobile**: Se sta utilizzando GalaxyRVR in modalità AP (predefinita), colleghi il Suo dispositivo mobile all'hotspot GalaxyRVR. Se ha :ref:`configurato una rete WiFi domestica <ap_to_sta>`, si assicuri che il Suo dispositivo mobile sia connesso alla **stessa** rete WiFi domestica.


3. L'app RoboPilot non riesce a connettersi?
---------------------------------------------------------------------------------------

Se l'app RoboPilot non riesce a trovare o connettersi al Suo GalaxyRVR, controlli quanto segue:

1. **Il firmware R3 è aggiornato?** La scheda R3 deve avere installato il firmware di comunicazione di fabbrica. Se ha caricato codice Arduino personalizzato, questo sovrascriverà il firmware e interromperà la comunicazione con RoboPilot. Segua :ref:`update_r3_firmware` per ripristinarlo.
2. **Il firmware dell'ESP32 CAM è aggiornato?** Un firmware dell'ESP32 CAM obsoleto può causare problemi di connessione. Segua :ref:`update_esp32_firmware` per verificare e aggiornare.
3. **L'interruttore di modalità è su Run?** L'interruttore di modalità deve essere impostato su **Run** (non Upload) affinché l'hotspot WiFi funzioni.
4. **Il Suo dispositivo mobile è sulla rete WiFi corretta?** Si connetta all'hotspot GalaxyRVR (``GalaxyRVR`` / ``12345678``) oppure, se ha configurato un WiFi domestico, si connetta a quella stessa rete.
5. **Provi a reimpostare**: Passi alla modalità **Run** e prema il pulsante **Reset**, quindi provi a connettersi di nuovo.

Se nessuno dei suggerimenti precedenti aiuta, provi a :ref:`cancellare la configurazione dell'ESP32 CAM <faq_wifi_after_update>`.


4. L'app Mammoth Coding (Scratch) non riesce a connettersi?
---------------------------------------------------------------------------------------

Se Mammoth Coding non riesce a connettersi al Suo GalaxyRVR, controlli quanto segue:

1. **Il firmware R3 è aggiornato?** Mammoth Coding richiede il firmware di comunicazione di fabbrica sulla scheda R3. Se ha caricato il Suo codice Arduino, il firmware di comunicazione viene sovrascritto. Segua :ref:`update_r3_firmware` per ripristinarlo.
2. **Il firmware dell'ESP32 CAM è aggiornato?** L'ESP32 CAM gestisce la connessione WiFi su cui si basa Mammoth Coding. Segua :ref:`update_esp32_firmware` per assicurarsi che sia aggiornato.
3. **L'interruttore di modalità è su Run?** L'interruttore di modalità deve essere impostato su **Run** affinché l'hotspot WiFi sia attivo.
4. **Il Suo dispositivo mobile è sulla rete WiFi corretta?** Si assicuri che il Suo dispositivo sia connesso all'hotspot GalaxyRVR o alla stessa rete WiFi domestica configurata sul rover.
5. **Dopo aver caricato codice Arduino**: Ricordi che il caricamento di qualsiasi sketch Arduino sulla scheda R3 sovrascriverà il firmware di comunicazione. Dovrà :ref:`ripristinare il firmware R3 <update_r3_firmware>` prima che Mammoth Coding possa connettersi di nuovo.

.. note::
   Se desidera utilizzare **sia** la programmazione Arduino che Mammoth Coding, tenga presente che dovrà ricaricare il firmware R3 ogni volta che passa da una all'altra.

.. _install_lib:

5. Errore di compilazione: ``SoftPWM.h`` o ``SunFounder_AI_Camera.h``: File o directory non esistente?
--------------------------------------------------------------------------------------------------------------
Se riceve un messaggio "Errore di compilazione: ``SoftPWM.h``: File o directory non esistente", significa che la libreria SoftPWM non è installata.

Installi le due librerie richieste ``SoftPWM`` e ``SunFounder AI Camera`` come mostrato.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Il tuo browser non supporta il tag video.
        </video>

Per la libreria ``SunFounder AI Camera``, deve selezionare "INSTALL ALL" per installare contemporaneamente la dipendenza richiesta ``ArduinoJson``.

    .. image:: img/faq_install_ai_camera.png

6. avrdude: stk500_getsync() tentativo 10 di 10: non in sync: resp=0x6e?
-----------------------------------------------------------------------------
Se il seguente messaggio continua ad apparire dopo aver cliccato il pulsante **Upload** quando la scheda e la porta sono state selezionate correttamente.

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00

A questo punto, deve assicurarsi che l'ESP32 CAM sia scollegato.

L'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Quindi, prima di caricare il codice, deve prima scollegare l'ESP32-CAM per evitare conflitti o potenziali problemi.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Dopo che il codice è stato caricato con successo, se deve utilizzare l'ESP32 CAM, deve spostare l'interruttore a sinistra per avviare l'ESP32 CAM.

    .. image:: img/camera_run.png
        :width: 500
        :align: center

.. _change_wifi_channel:

7. Come cambiare il canale WiFi?
----------------------------------

La banda WiFi a 2,4 GHz ha canali che vanno da 1 a 13. L'ESP32 supporta i canali da 1 a 11. Altri dispositivi che operano sullo stesso canale possono causare interferenze, portando a problemi di connessione. Per mitigare questo problema, può provare a cambiare canale. Per impostazione predefinita, il canale è impostato su 1. Quando seleziona un nuovo canale, si consiglia di saltare 1-2 canali alla volta. Ad esempio, se il canale attuale è 1, provi prima il canale 3 e, se il segnale è ancora debole, passi al canale 5.


#. Accenda il GalaxyRVR. Per attivare l'ESP32 CAM, sposti l'interruttore di modalità in posizione **Run** e prema il pulsante **reset** per riavviare la scheda R3.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Colleghi il Suo dispositivo mobile alla rete WiFi del GalaxyRVR.

   * Il nome della rete (SSID) è ``GalaxyRVR`` e la password è ``12345678``.
   * Se vede un avviso che indica "Nessun accesso a Internet", scelga l'opzione **"Resta connesso"**.

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Apra un browser web sul Suo dispositivo mobile e vada all'indirizzo ``http://192.168.4.1``. Verrà indirizzato al portale di aggiornamento del firmware ESP32-CAM.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. Nella pagina **AP**, selezioni un canale diverso.

   * Il canale predefinito è 1. Quando seleziona un nuovo canale, salti 1-2 canali alla volta (ad esempio, dal canale 1 al 3 e, se necessario, al 5).

   .. image:: img/fap_ap_channel.jpg
        :width: 50%
        :align: center

#. Torni alla pagina **Base** e clicchi il pulsante **Reboot** per riavviare il GalaxyRVR. Il GalaxyRVR è ora pronto per il normale funzionamento.

   .. image:: img/faq_firmware_reboot.png
        :width: 50%
        :align: center

8. Come aggiornare il firmware dell'ESP32 CAM
----------------------------------------------

Per garantire la compatibilità delle app e prestazioni ottimali, si assicuri che il firmware dell'ESP32 CAM sia aggiornato.

Per istruzioni dettagliate passo dopo passo, consulti: :ref:`update_esp32_firmware`

9. Come ripristinare il firmware R3
-----------------------------------------

La scheda R3 del GalaxyRVR viene fornita con un firmware che supporta sia l'App RoboPilot che Mammoth Coding.

Se ha sovrascritto questo firmware e deve ripristinare la comunicazione, segua :ref:`update_r3_firmware`.

.. _ap_to_sta:

10. Come configurare la connessione WiFi
-----------------------------------------------------

Per impostazione predefinita, GalaxyRVR opera in **modalità AP**, dove crea il proprio hotspot WiFi a cui altri dispositivi possono connettersi.

Se desidera che GalaxyRVR si connetta alla **Sua rete WiFi domestica**, segua i passaggi seguenti:


#. Accenda il GalaxyRVR. Per attivare l'ESP32 CAM, sposti l'interruttore di modalità in posizione **Run** e prema il pulsante **reset** per riavviare la scheda R3.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Colleghi il Suo dispositivo mobile alla rete WiFi del GalaxyRVR.

   * Il nome della rete (SSID) è ``GalaxyRVR`` e la password è ``12345678``.
   * Se vede un avviso che indica "Nessun accesso a Internet", scelga l'opzione **"Resta connesso"**.

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Apra un browser web sul Suo dispositivo mobile e vada all'indirizzo ``http://192.168.4.1``. Verrà indirizzato al portale di aggiornamento del firmware ESP32-CAM.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. Nella pagina **WiFi**, inserisca il nome della Sua rete WiFi domestica (SSID) e la password.

   .. image:: img/faq_wifi.png
        :width: 50%
        :align: center

#. Tocchi il pulsante **CONFIRM**.

   * GalaxyRVR tenterà di connettersi alla Sua rete WiFi domestica.
   * Se la connessione ha successo, l'icona di caricamento si fermerà e apparirà un segno di spunta.

#. Dopo il riavvio, colleghi il Suo dispositivo mobile alla stessa rete WiFi domestica.

#. Ora può connettersi a GalaxyRVR tramite l'App RoboPilot o Mammoth Coding.

.. _faq_wifi_after_update:

11. Come ripristinare le impostazioni di fabbrica dell'ESP32 CAM?
---------------------------------------------------------------------------------------

Se l'hotspot WiFi del GalaxyRVR non appare o non riesce a connettersi dopo aver aggiornato il firmware dell'ESP32 CAM, i vecchi dati di configurazione WiFi memorizzati nella memoria flash dell'ESP32 CAM potrebbero causare un conflitto.

Per risolvere il problema, deve ripristinare le impostazioni di fabbrica dell'ESP32 CAM cancellando i dati memorizzati. Questa operazione si effettua cortocircuitando i pin **IO13** e **IO15** sull'ESP32 CAM:

#. Spenga l'interruttore di alimentazione del GalaxyRVR.
#. Individui i pin **IO13** e **IO15** sul modulo ESP32 CAM.

   .. image:: img/esp32cam_io1315.png
        :width: 300
        :align: center

#. Utilizzi un cavetto jumper o una pinzetta per cortocircuitare (collegare) insieme i pin **IO13** e **IO15**.
#. Mentre tiene i pin in cortocircuito, accenda l'interruttore di alimentazione del GalaxyRVR.
#. Osservi il LED dell'ESP32 CAM — quando **lampeggia due volte rapidamente**, rimuova il cavetto jumper.

   .. image:: img/esp32cam_led.png
        :width: 300
        :align: center

#. Porti l'interruttore di modalità su **Run** e prema il pulsante **Reset** sulla scheda R3.
#. L'ESP32 CAM si avvierà ora con la configurazione cancellata. Dovrebbe vedere un hotspot chiamato ``AI Camera-xxxxxx`` (dove ``xxxxxx`` è un identificatore univoco) nell'elenco WiFi del Suo dispositivo. Si connetta utilizzando la password ``12345678``.
#. Dopo aver riavviato il GalaxyRVR, il nome dell'hotspot passerà da ``AI Camera-xxxxxx`` a ``GalaxyRVR-xxxxxx``, indicando che le impostazioni di fabbrica sono state ripristinate con successo.

.. note::
   Dopo aver ripristinato le impostazioni di fabbrica, dovrà riconfigurare eventuali impostazioni WiFi domestiche precedentemente salvate (:ref:`ap_to_sta`).
