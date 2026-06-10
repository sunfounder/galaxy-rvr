Gioco Rapido con Arduino
===============================

In questo capitolo imparerai come **aprire ed eseguire rapidamente codici di esempio Arduino specifici** per far eseguire al tuo GalaxyRVR varie azioni.

Se desideri comprendere la logica del codice e i principi di programmazione dietro questi esempi, consulta il capitolo :ref:`programming_arduino`.

Come aprire rapidamente un esempio Arduino
---------------------------------------------

In questo esempio, dimostreremo come utilizzare l'IDE Arduino per aprire un esempio Arduino.

#. Avvia il GalaxyRVR.

   * Quando utilizzi GalaxyRVR per la prima volta, si consiglia di caricare completamente la batteria collegando un cavo USB Type-C. Quindi, accendi l'alimentazione.

     .. raw:: html

          <video width="600" loop autoplay muted>
              <source src="../_static/video/play_start.mp4" type="video/mp4">
              Your browser does not support the video tag.
          </video>

    * L'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Quindi, prima di caricare il codice, devi prima rilasciare l'ESP32-CAM facendo scorrere questo interruttore sul lato destro per evitare conflitti o potenziali problemi.

      .. image:: ../img/camera_upload.png
         :width: 600

#. Collega la tua scheda Arduino al computer utilizzando un cavo USB.

#. Visita |link_download_arduino| e scarica l'IDE Arduino per il tuo sistema operativo. Segui le istruzioni di installazione per completare la configurazione.

   .. image:: img/arduino_download_page.png

#. Scarica i codici di esempio dal link qui sotto:

   * |download_galaxyrvr_code|

#. Estrai il file scaricato, naviga in ``galaxy-rvr-1.2.x\lesson_codes``.

   .. image:: img/arduino_open_folder.png

#. Seleziona una cartella di codice di esempio, naviga in quella cartella, quindi fai doppio clic sul file ``.ino`` per aprirlo nell'IDE Arduino.

   .. image:: img/arduino_open_file.png

#. Nell'IDE Arduino, seleziona **Arduino Uno** come scheda e scegli la **porta** appropriata per il tuo dispositivo.

   .. image:: img/arduino_choose_board.png

#. Clicca il pulsante **Upload** (freccia rivolta a destra) per caricare il codice sulla tua scheda.

   .. image:: img/arduino_upload.png

.. note::

    Se non hai familiarità con l'IDE Arduino, consulta:

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
