.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

FAQ
==============

1. Impossibile connettersi a GalaxyRVR?
-------------------------------------------------------------------------------------------------

Se non riesci a connetterti al GalaxyRVR, controlla quanto segue:

1. Controlla gli indicatori della batteria sul rover. Se entrambi i LED sono spenti, la batteria è scarica. Carica il rover utilizzando un cavo USB Type-C.
2. Reimposta il GalaxyRVR portando l'interruttore di modalità su **Run** e premendo il pulsante **Reset**.
3. Verifica che il tuo dispositivo mobile sia connesso all'hotspot GalaxyRVR.
4. Se hai configurato una rete Wi-Fi domestica, assicurati che il tuo dispositivo mobile sia connesso alla **stessa** rete Wi-Fi domestica.

.. _install_lib:

2. Errore di compilazione: ``SoftPWM.h`` o ``SunFounder_AI_Camera.h``: File o directory non esistente?
------------------------------------------------------------------------------------------------------
Se ricevi un messaggio "Errore di compilazione: ``SoftPWM.h``: File o directory non esistente", significa che la libreria SoftPWM non è installata.

Installa le due librerie richieste ``SoftPWM`` e ``SunFounder AI Camera`` come mostrato.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

Per la libreria ``SunFounder AI Camera``, devi selezionare "INSTALL ALL" per installare contemporaneamente la dipendenza richiesta ``ArduinoJson``.

    .. image:: img/faq_install_ai_camera.png

3. avrdude: stk500_getsync() tentativo 10 di 10: non in sync: resp=0x6e?
-----------------------------------------------------------------------------
Se il seguente messaggio continua ad apparire dopo aver cliccato il pulsante **Upload** quando la scheda e la porta sono state selezionate correttamente.

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00
    A questo punto, devi assicurarti che l'ESP32 CAM sia scollegato.

L'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Quindi, prima di caricare il codice, devi prima scollegare l'ESP32-CAM per evitare conflitti o potenziali problemi.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Dopo che il codice è stato caricato con successo, se devi utilizzare l'ESP32 CAM, devi spostare l'interruttore a sinistra per avviare l'ESP32 CAM.

    .. image:: img/camera_run.png
        :width: 500
        :align: center

4. Come cambiare il canale Wi-Fi?
----------------------------------

La banda Wi-Fi a 2,4GHz ha canali che vanno da 1 a 13. L'ESP32 supporta i canali da 1 a 11. Altri dispositivi che operano sullo stesso canale possono causare interferenze, portando a problemi di connessione. Per mitigare questo, puoi provare a cambiare canale. Per impostazione predefinita, il canale è impostato su 1. Quando selezioni un nuovo canale, si consiglia di saltare 1-2 canali alla volta. Ad esempio, se il canale attuale è 1, prova prima il canale 3, e se il segnale è ancora debole, passa al canale 5.


#. Accendi il GalaxyRVR. Per attivare l'ESP32 CAM, sposta l'interruttore di modalità in posizione **Run** e premi il pulsante **reset** per riavviare la scheda R3.

     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset_green.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Connetti il tuo dispositivo mobile alla rete WiFi del GalaxyRVR.

   * Il nome della rete (SSID) è ``GalaxyRVR`` e la password è ``12345678``.
   * Se vedi un avviso che indica "Nessun accesso a Internet", scegli l'opzione **"Resta connesso"**.

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Apri un browser web sul tuo dispositivo mobile e vai all'indirizzo ``http://192.168.4.1``. Verrai indirizzato al portale di aggiornamento del firmware ESP32-CAM.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. Nella pagina **AP**, seleziona un canale diverso.

   * Il canale predefinito è 1. Quando selezioni un nuovo canale, salta 1-2 canali alla volta (ad esempio, dal canale 1 al 3 e, se necessario, al 5).

   .. image:: img/fap_ap_channel.jpg
        :width: 50%
        :align: center

#. Torna alla pagina **Base** e clicca il pulsante **Reboot** per riavviare il GalaxyRVR. Il GalaxyRVR è ora pronto per il normale funzionamento.

   .. image:: img/faq_firmware_reboot.png
        :width: 50%
        :align: center

5. Come aggiornare il firmware dell'ESP32 CAM
---------------------------------------------

Per istruzioni dettagliate passo dopo passo, consulta: :ref:`update_firmware`

6. Come ripristinare il firmware R3
-----------------------------------------

La scheda R3 del GalaxyRVR viene fornita con un firmware che supporta sia l'App RoboPilot che Mammoth Coding.

Se hai sovrascritto questo firmware e devi ripristinare la comunicazione, segui :ref:`update_r3_firmware`.

.. _ap_to_sta:

7. Come configurare la connessione Wi-Fi
-----------------------------------------------------

Per impostazione predefinita, GalaxyRVR opera in **modalità AP**, dove crea il proprio hotspot Wi-Fi a cui altri dispositivi possono connettersi.

Se desideri che GalaxyRVR si connetta alla tua **rete Wi-Fi domestica**, segui i passaggi seguenti:


#. Accendi il GalaxyRVR. Per attivare l'ESP32 CAM, sposta l'interruttore di modalità in posizione **Run** e premi il pulsante **reset** per riavviare la scheda R3.

     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset_green.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Connetti il tuo dispositivo mobile alla rete WiFi del GalaxyRVR.

   * Il nome della rete (SSID) è ``GalaxyRVR`` e la password è ``12345678``.
   * Se vedi un avviso che indica "Nessun accesso a Internet", scegli l'opzione **"Resta connesso"**.

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Apri un browser web sul tuo dispositivo mobile e vai all'indirizzo ``http://192.168.4.1``. Verrai indirizzato al portale di aggiornamento del firmware ESP32-CAM.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. Nella pagina **WiFi**, inserisci il nome della tua rete WiFi domestica (SSID) e la password.

   .. image:: img/faq_wifi.png
        :width: 50%
        :align: center

#. Tocca il pulsante **CONFIRM**.

   * GalaxyRVR tenterà di connettersi alla tua rete Wi-Fi domestica.
   * Se la connessione ha successo, l'icona di caricamento si fermerà e apparirà un segno di spunta.

#. Dopo il riavvio, connetti il tuo dispositivo mobile alla stessa rete Wi-Fi domestica.

#. Ora puoi connetterti a GalaxyRVR tramite l'App RoboPilot o Mammoth Coding.
