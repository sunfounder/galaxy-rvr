.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!


.. _update_firmware:

Aggiornamento del file firmware
======================================

1. Scarica il file del firmware.

    * :download:`GalaxyRVR Firmware File <https://github.com/sunfounder/galaxy-rvr/releases/download/1.2.0/galaxy-rvr-1.2.0.zip>`

2. Collega i tuoi dispositivi mobili (come smartphone o tablet) all'hotspot WiFi emesso dal GalaxyRVR. 
Tipicamente, l'SSID è ``GalaxyRVR`` e la password è ``12345678``.
.. image:: img/firmware/SSID.png

.. note:: La modalità di connessione predefinita è **modalità AP**. Dopo aver effettuato la connessione, potresti ricevere un avviso che indica l'assenza di accesso a internet su questa rete. Se accade, scegli "Rimani connesso".

    .. image:: img/app/camera_stay.png

3. Vai su http://192.168.4.1 per accedere all'interfaccia di aggiornamento del firmware ESP32 Cam.

.. image:: img/firmware/OTAUpdate.jpg

4. Controlla il numero di versione. Se la tua versione è superiore a ``1.5.1``, non è necessario alcun aggiornamento (salta i passaggi 5-9). Altrimenti, è richiesto un aggiornamento.

.. image:: img/firmware/OTAversion.jpg

5. Trasferisci il file ``ai-camera-firmware.ino.1.5.1.bin`` sul dispositivo.

.. image:: img/firmware/selectBin.png

6. Torna all'interfaccia di aggiornamento del firmware. Clicca per selezionare il firmware.

.. image:: img/firmware/OTASButton.jpg

7. Seleziona il file ``ai-camera-firmware.ino.1.5.1.bin`` che hai appena salvato sul tuo dispositivo mobile, poi clicca su aggiorna.

.. image:: img/firmware/OTASelect.jpg

8. Attendi che l'aggiornamento del firmware sia completato. Quando il numero di versione corrente visualizza 1.5.1, l'aggiornamento è avvenuto con successo.

.. image:: img/firmware/OTAFinish.jpg

9. Chiudi la pagina.

