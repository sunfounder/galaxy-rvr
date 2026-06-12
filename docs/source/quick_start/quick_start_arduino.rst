.. note::

    Benvenuto/a nella community degli appassionati di Raspberry Pi, Arduino ed ESP32 di SunFounder su Facebook! Approfondisca le sue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolva problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impari e condivida**: Scambi suggerimenti e tutorial per migliorare le sue competenze.
    - **Anteprime esclusive**: Acceda in anteprima ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti speciali**: Goda di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipi a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicchi su |link_sf_facebook| e si unisca oggi stesso!

Gioco Rapido con Arduino
===============================

In questo capitolo imparerà come **aprire ed eseguire rapidamente codici di esempio Arduino specifici** per far eseguire al suo GalaxyRVR varie azioni.

Se desidera comprendere la logica del codice e i principi di programmazione dietro questi esempi, consulti il capitolo :ref:`programming_arduino`.

Come aprire rapidamente un esempio Arduino
---------------------------------------------

In questo esempio, dimostreremo come utilizzare l'IDE Arduino per aprire un esempio Arduino.

#. Avvii il GalaxyRVR.

   * Quando utilizza GalaxyRVR per la prima volta, si consiglia di caricare completamente la batteria collegando un cavo USB Type-C. Quindi, accenda l'alimentazione.

     .. raw:: html

          <video width="600" loop autoplay muted>
              <source src="../_static/video/play_start.mp4" type="video/mp4">
              Il tuo browser non supporta il tag video.
          </video>

    * L'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Quindi, prima di caricare il codice, deve prima rilasciare l'ESP32-CAM facendo scorrere questo interruttore sul lato destro per evitare conflitti o potenziali problemi.

      .. image:: ../img/camera_upload.png
         :width: 600

#. Colleghi la sua scheda Arduino al computer utilizzando un cavo USB.

#. Visiti |link_download_arduino| e scarichi l'IDE Arduino per il suo sistema operativo. Segua le istruzioni di installazione per completare la configurazione.

   .. image:: img/arduino_download_page.png

#. Scarichi i codici di esempio dal link seguente:

   * |download_galaxyrvr_code|

#. Estragga il file scaricato, navighi in ``galaxy-rvr-1.2.x\lesson_codes``.

   .. image:: img/arduino_open_folder.png

#. Selezioni una cartella di codice di esempio, navighi in quella cartella, quindi faccia doppio clic sul file ``.ino`` per aprirlo nell'IDE Arduino.

   .. image:: img/arduino_open_file.png

#. Nell'IDE Arduino, selezioni **Arduino Uno** come scheda e scelga la **porta** appropriata per il suo dispositivo.

   .. image:: img/arduino_choose_board.png

#. Faccia clic sul pulsante **Upload** (freccia rivolta a destra) per caricare il codice sulla sua scheda.

   .. image:: img/arduino_upload.png

.. note::

    Se non ha familiarità con l'IDE Arduino, consulti:

    * :ref:`install_arduino_ide`
    * :ref:`upload_sketch`

Esempi
------------

* ``5_car_move``: Il rover avanza, poi indietreggia, gira a sinistra e a destra e infine si ferma.
* ``6_ir_avoid``: Il rover evita gli ostacoli utilizzando i sensori IR.
* ``7_ultrasonic_avoid``: Il rover evita gli ostacoli utilizzando il modulo a ultrasuoni.
* ``8_ultrasonic_ir_avoid``: Il rover utilizza sia i sensori IR che il modulo a ultrasuoni per rilevare ostacoli.
* ``8_ultrasonic_ir_follow``: Il rover segue gli oggetti utilizzando i sensori IR e il modulo a ultrasuoni.
* ``9_rgb_car_move``: Aggiunge indicatori colorati per il movimento: verde per avanti, rosso per indietro e giallo per girare a sinistra o a destra.
* ``10_servo_range``: La testa della fotocamera ruota da 0° a 180° utilizzando un ciclo for e l'angolo corrente viene visualizzato nel Monitor Seriale.
* ``11_camera_view``: Visualizza il feed video in diretta dalla fotocamera del rover in un browser web. È richiesta la libreria **SunFounder AI Camera**.
* ``13_read_battery``: Monitora la tensione della batteria attraverso il codice.
