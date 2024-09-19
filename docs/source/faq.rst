.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri nuovi prodotti.
    - **Promozioni festive e giveaway**: Partecipa a promozioni festive e concorsi a premi.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

FAQ
==============

.. _ap_to_sta:

Q1: Cambiare la modalità AP in modalità STA
-------------------------------------------------

* È necessario scaricare il codice pertinente.

    * :download:`GalaxyRVR Codes <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/main.zip>`

* Installa IDE, quindi installa le librerie ``SoftPWM`` e ``SunFounder AI Camera``. :ref:`install_lib` .

* Poi, apri il file ``galaxy-rvr.ino`` situato nella directory ``galaxy-rvr-main\galaxy-rvr``.

* Commenta le righe 69-71, decommenta le righe 73-75 e cambia ``SSID`` e ``PASSWORD`` con i dati della tua WLAN.

.. image:: img/ap_sta.png
    :align: center

* Collega l'Arduino e il computer con un cavo USB, poi sposta l'interruttore **upload** del rover in posizione di upload.

.. image:: img/camera_upload.png
    :width: 400
    :align: center

* Carica il codice.

.. _install_lib:

Q2: Errore di compilazione: SoftPWM.h: File o directory inesistente？
-------------------------------------------------------------------------
Se ricevi il messaggio "Errore di compilazione: SoftPWM.h: File o directory inesistente", significa che non hai installato la libreria SoftPWM.

Installa le due librerie richieste ``SoftPWM`` e ``SunFounder AI Camera`` come mostrato.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>


Q3: avrdude: stk500_getsync() tentativo 10 di 10: non in sincronia: resp=0x6e?
---------------------------------------------------------------------------------
Se compare il seguente messaggio dopo aver cliccato il pulsante **Upload**, anche se la scheda e la porta sono state selezionate correttamente:

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00
    At this point, you need to make sure that the ESP32 CAM is unplugged.

L'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, dovrai scollegare l'ESP32-CAM per evitare conflitti o potenziali problemi.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Dopo aver caricato correttamente il codice, se hai bisogno di utilizzare l'ESP32 CAM, sposta l'interruttore a sinistra per avviare l'ESP32 CAM.

    .. image:: img/camera_run.png
        :width: 500
        :align: center

.. _stt_android:

Q4: Come posso utilizzare la modalità STT sul mio dispositivo Android?
------------------------------------------------------------------------

La modalità STT richiede che il dispositivo mobile Android sia connesso a Internet e che sia installato il componente Google.

Segui i passaggi qui sotto.

#. Modifica la modalità AP del file ``galaxy-rvr.ino`` in modalità STA.

    * Apri il file ``galaxy-rvr.ino`` situato nella directory ``galaxy-rvr-main\galaxy-rvr``. 
    * Poi commenta il codice relativo alla modalità AP. Decommenta il codice relativo alla modalità STA e inserisci ``SSID`` e ``PASSWORD`` del tuo Wi-Fi domestico.

        .. code-block:: arduino

            /** Configura modalità Wifi, SSID, password */
            // #define WIFI_MODE WIFI_MODE_AP
            // #define SSID "GalaxyRVR"
            // #define PASSWORD "12345678"

            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "xxxxxxxxxx"
            #define PASSWORD "xxxxxxxxxx"

    * Salva il codice, seleziona la scheda corretta (Arduino Uno) e la porta, poi clicca il pulsante **Upload** per caricarlo sulla scheda R3.

#. Cerca ``google`` su Google Play, trova l'app mostrata qui sotto e installala.

    .. image:: img/google_voice.png
        :width: 500
        :align: center

#. Collega il tuo dispositivo mobile alla stessa rete Wi-Fi che hai configurato nel codice.

    .. image:: img/sta_wifi.png
        :width: 500
        :align: center

#. Apri il controller precedentemente creato in SunFounder Controller e collegalo a ``GalaxyRVR`` tramite il pulsante |app_connect|.

    .. image:: img/app/camera_connect.png
        :width: 400
        :align: center


#. Tocca e tieni premuto il widget **STT(J)** dopo aver cliccato il pulsante |app_run|. Apparirà un messaggio che indica che sta ascoltando. Pronuncia i seguenti comandi per muovere il rover.

    .. image:: img/app/play_speech.png

    * ``stop``: Tutti i movimenti del rover verranno fermati.
    * ``forward``: Il rover avanzerà.
    * ``backward``: Il rover si muoverà all'indietro.
    * ``left``: Il rover girerà a sinistra.
    * ``right``: Il rover girerà a destra.

Q5: Informazioni sul firmware dell'ESP32 CAM
---------------------------------------------------

Ecco il link per il firmware dell'ESP32 CAM: |link_ai_camera_firmware|


.. ↓ this firmware only for sunfounder controller


.. Q6: How to Flash New Firmware to an ESP32 CAM?
.. ----------------------------------------------------
.. The camera module comes pre-flashed from the factory. However, if you encounter a data corruption issue, you can re-flash it with new firmware using the Arduino IDE. Here's how:

.. **1. Prepare the Programmer**

.. #. First, get a programmer ready.

..     .. image:: img/esp32_cam_programmer.png
..         :width: 300
..         :align: center

.. #. Insert the ESP32 CAM into the programmer and then plug the programmer into your computer.

..     .. image:: img/esp32_cam_usb.jpg
..         :width: 300
..         :align: center

.. **2. Install the ESP32 Board**

.. To program the ESP32 microcontroller, you must install the ESP32 board package in the Arduino IDE. Follow these steps:

.. #. Go to **File** and select **Preferences** from the drop-down menu.

..     .. image:: img/install_esp321.png
..         :width: 500
..         :align: center

.. #. In the **Preferences** window, find the **Additional Board Manager URLs** field. Click on it to enable the text box.

..     .. image:: img/install_esp322.png
..         :width: 500
..         :align: center

.. #. Add this URL to the **Additional Board Manager URLs** field: https://espressif.github.io/arduino-esp32/package_esp32_index.json. This URL links to the package index file for ESP32 boards. Click **OK** to save the changes.

..     .. image:: img/install_esp323.png
..         :width: 500
..         :align: center

.. #.  In the **Boards Manager** window, search for **ESP32**. Click the **Install** button to begin installation. This downloads and installs the ESP32 board package.

..     .. image:: img/install_esp324.png
..         :align: center

.. **3. Install the Libraries**

.. #. Install the ``WebSockets`` library from the **LIBRARY MANAGER**.

..     .. image:: img/esp32_cam_websockets.png
..         :width: 500
..         :align: center

.. #. Follow the same steps to install the ``ArduinoJson`` library.

..     .. image:: img/esp32_cam_arduinojson.png
..         :width: 500
..         :align: center

.. **3. Download and Upload Firmware**

.. #. Download the firmware file.

..     * :download:`ai-camera-firmware <https://github.com/sunfounder/ai-camera-firmware/archive/refs/heads/main.zip>`

.. #. Extract the downloaded firmware file and rename the extracted folder from ``ai-camera-firmware-main`` to ``ai-camera-firmware``.

..     .. image:: img/esp32_cam_change_name.png
..         :align: center

.. #. Open ``ai-camera-firmware.ino`` with the Arduino IDE, which also opens the associated code files.

..     .. image:: img/esp32_cam_ino.png
..         :align: center

.. #. Select **Board** -> **esp32** -> **ESP32 Dev Module**.

..     .. image:: img/esp32_cam_board.png
..         :width: 500
..         :align: center

.. #. Choose the correct port.

..     .. image:: img/esp32_cam_port.png
..         :width: 400
..         :align: center

.. #. Ensure to enable **PSRAM** and select **Huge APP** in the **Partition Scheme**.

..     .. image:: img/esp32_cam_psram.png
..         :width: 400
..         :align: center

.. #. Finally, upload the firmware to the ESP32 CAM.

..     .. image:: img/esp32_cam_upload.png
..         :width: 500
..         :align: center

.. #. After successful firmware upload, you can find more information at this link: https://github.com/sunfounder/ai-camera-firmware.



