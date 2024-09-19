.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme agli altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!



.. _rvr_move:

Lezione 3 Controlla da Remoto il Tuo GalaxyRVR
=================================================

In questa lezione daremo vita al Rover di Marte!

Usando le nostre capacità di programmazione, guideremo il nostro Rover attraverso paesaggi immaginari marziani.

Un'avventura marziana nella nostra classe. Iniziamo!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>


Obiettivi di Apprendimento
----------------------------------

* Guidare gli studenti a scaricare e caricare il codice Arduino corrispondente per controllare il rover con l'APP.
* Imparare a utilizzare i tasti freccia in Mammoth Coding per controllare i movimenti del rover.
* Implementare i controlli di base del movimento del rover: avanti, indietro, svolta a sinistra, svolta a destra.

Materiali
-------------

* Smartphone o tablet
* APP Mammoth Coding
* GalaxyRVR
* Computer


Caricamento del Programma Base su GalaxyRVR
-------------------------------------------------

Per controllare il GalaxyRVR con l'APP, è necessario caricare un programma specifico utilizzando l'IDE di Arduino.

Segui questi passaggi sul tuo computer:

Scaricare l'IDE di Arduino
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#. Visita https://www.arduino.cc/en/software#future-version-of-the-arduino-ide.

#. Scarica l'IDE per la versione del tuo sistema operativo.

    .. image:: img/sp_001.png

#. Installalo.

    .. image:: img/sp_005.png


Caricamento del Codice Adattato
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

1. Accendi l'interruttore di alimentazione del GalaxyRVR.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_start.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

2. Collega l'Arduino al computer con un cavo USB e sposta l'interruttore **upload** della macchina sulla posizione di caricamento.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

.. note:: Si tratta della porta USB Type B per collegarsi all'Arduino, non della porta USB Type C per la ricarica.

3. Apri la cartella galaxy-rvr-1.2.0 scaricata (è stata già scaricata e installata nella sezione :ref:`update_firmware`), fai doppio clic per eseguire lo script ``update-arduino-firmware.bat``. Si aprirà un prompt dei comandi.

.. image:: ../img/firmware/updateFirmware.png

4. Nel prompt dei comandi vedrai un elenco delle porte seriali attualmente collegate al computer. Inserisci il numero di sequenza sul lato sinistro dell'elenco delle porte per selezionare quella dell'Arduino Uno. Premi Invio per caricare automaticamente il programma.

.. image:: ../img/firmware/selectCOM.png

5. Dopo aver atteso il completamento del caricamento, puoi scollegare il cavo USB.

.. image:: ../img/firmware/UNOupdating.png

6. Riporta l'interruttore di caricamento alla posizione iniziale e premi il pulsante di reset: il rover è pronto per l'uso.


.. note:: Questo codice consente al GalaxyRVR di rispondere ai comandi dell'APP. Non sarà necessario caricare altro codice nei capitoli successivi che utilizzano l'APP Mammoth Coding.


.. _app_connect:

Collegare l'APP al GalaxyRVR
-------------------------------------------

1. Per attivare l'ESP32 CAM, sposta l'interruttore della modalità sulla posizione **Run** e premi il pulsante **reset** per riavviare la scheda R3. Noterai una luce ciano lampeggiante sulla striscia inferiore.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

2. Collega il tuo dispositivo mobile (es., telefono, tablet) all'hotspot WiFi fornito da GalaxyRVR. Generalmente, il suo SSID è ``GalaxyRVR`` e la password è ``12345678``.

.. image:: ../img/firmware/SSID.png

.. note:: La modalità di connessione predefinita è **modalità AP**. Dopo la connessione, potrebbe apparire un avviso che segnala l'assenza di accesso a Internet su questa rete. Se così fosse, scegli "Rimani connesso".

    .. image:: ../img/app/camera_stay.png


3. Apri l'APP. Clicca qui.

.. image:: img/connet_app_04.png


4. Carica il modulo GalaxyRVR.

.. image:: img/connet_app_05.png

5. L'APP cercherà il tuo robot.

.. image:: img/connet_app_06.png

6. Collegalo.

.. note:: La luce respiratoria sul GalaxyRVR può indicare lo stato della connessione. Il lampeggio giallo significa che nessun dispositivo è connesso. Una luce blu fissa indica che è connesso.


Riconnettere l'APP
-------------------------------------

Quando il tuo dispositivo si disconnette dal GalaxyRVR, vedrai apparire questa finestra popup nell'interfaccia. Clicca su riconnetti.

.. image:: img/reconnect_0.png

Se chiudi la finestra popup, puoi riconnetterti anche cliccando su questo pulsante nella categoria GalaxyRVR.

.. image:: img/reconnect_1.png

Trova il tuo GalaxyRVR e clicca su connetti.

.. image:: img/reconnect_2.png


Controllare il GalaxyRVR con l'APP
-----------------------------------------

1. Nell'interfaccia Codice, troverai la categoria GalaxyRVR.

.. image:: img/3_rvr_catego.png

2. Abbiamo già utilizzato la bandiera verde per avviare i programmi. 
Durante questo processo, noterai diversi blocchi nella categoria Eventi che attivano l'esecuzione del codice. 
Trova il blocco ``quando si preme la freccia su``.

.. image:: img/3_rvr_when_arrow.png

3. Trascina quattro di questi blocchi, uno per ciascun evento dei tasti freccia (su, giù, sinistra, destra).

.. image:: img/3_rvr_4_arrow.png

.. note:: Puoi cliccare sull'icona a forma di occhio sotto la bandiera verde per nascondere l'area del palcoscenico e ottenere più spazio per programmare.

4. Completa i blocchi di codice per questi quattro eventi. Quando si preme la freccia su, fai avanzare il GalaxyRVR; quando si preme la freccia sinistra, fallo girare a sinistra, ecc.

.. image:: img/3_rvr_4_dir.png

5. Espandi il palcoscenico cliccando su questo pulsante.

.. image:: img/3_rvr_stage.png

6. Entrerai in un'interfaccia con un palcoscenico ingrandito e una serie di tasti direzionali.

.. image:: img/3_rvr_stage2.png

Premi questi tasti direzionali e sarai felice di vedere che puoi controllare direttamente il GalaxyRVR.

Blocchi Relativi al Movimento
--------------------------------

.. image:: img/block/move_forward.png 
..    :align: center

Dopo l'esecuzione di questo blocco, il GalaxyRVR si muoverà in avanti. Puoi:

    * Cambiare il parametro dal menu a tendina per farlo girare a sinistra, a destra o andare in retromarcia.


.. image:: img/block/move_set_speed.png 
..    :align: center

Questo blocco è utilizzato per impostare la velocità di movimento del GalaxyRVR. Non avvia il movimento autonomamente.

.. image:: img/block/move_forward_1s.png 
..    :align: center

Dopo l'esecuzione di questo blocco, il GalaxyRVR si muoverà in avanti per 1 secondo. Puoi:
    
    * Cambiare il parametro dal menu a tendina per farlo girare a sinistra, a destra o andare in retromarcia.
    * Regolare il numero nel blocco per impostare la durata del movimento del GalaxyRVR.


.. image:: img/block/move_forward_80.png 
..    :align: center

Dopo l'esecuzione di questo blocco, il GalaxyRVR si muoverà in avanti all'80% della velocità. Puoi:
    
    * Cambiare il parametro dal menu a tendina per farlo girare a sinistra, a destra o andare in retromarcia.
    * Modificare il numero nel blocco per regolare la velocità del GalaxyRVR durante questo movimento.

.. image:: img/block/move_forward_80_1s.png 
..    :align: center

Dopo l'esecuzione di questo blocco, il GalaxyRVR si muoverà in avanti all'80% della velocità per 1 secondo. Puoi:
    
    * Cambiare il parametro dal menu a tendina per farlo girare a sinistra, a destra o andare in retromarcia.
    * Regolare il tempo nel blocco per impostare la durata del movimento.
    * Modificare la velocità nel blocco per regolare la velocità del GalaxyRVR durante questo movimento.

.. image:: img/block/move_lr_sp_1s.png 
..    :align: center

Dopo l'esecuzione di questo blocco, puoi impostare indipendentemente le velocità delle ruote sinistra e destra del GalaxyRVR e farlo muovere per il tempo specificato. Puoi:
    
    * Modificare la velocità sinistra per impostare la velocità della ruota sinistra del GalaxyRVR.
    * Modificare la velocità destra per impostare la velocità della ruota destra del GalaxyRVR.
    * Regolare il tempo per determinare la durata del movimento.

.. image:: img/block/move_stop.png
..    :align: center

Ferma il movimento del GalaxyRVR.
