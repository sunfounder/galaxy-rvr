.. note::

    Ciao, benvenuto nella comunità SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

Scheda Adattatore per Fotocamera
=====================================

.. image:: img/cam_adapter_board.jpg
    :width: 500
    :align: center

* **RST**: Utilizzato per resettare l'ESP32-CAM.
* **SCL**: Pin dati seriale per il QMC6310.
* **SDA**: Pin clock seriale del QMC6310.
* **RXD**: Il pin RXD dell'ESP32-CAM; per caricare il codice sull'ESP32-CAM è necessario utilizzare questi due pin seriali, RXD e TXD.
* **TXD**: Il pin TXD dell'ESP32-CAM.
* **5V**: Ingresso di alimentazione a 5V DC.
* **GND**: Ingresso di messa a terra.

La scheda adattatore per fotocamera, come suggerisce il nome, è una scheda di espansione per l'ESP-32 CAM. È progettata per fissare l'ESP32-CAM al robot e facilitare il cablaggio.

.. image:: img/cam_adapter_esp32cam.png
    :width: 400
    :align: center

Poiché il chip geomagnetico QMC6310 è sensibile alle interferenze dei motori, lo abbiamo posizionato su questa scheda adattatore per mantenerlo il più lontano possibile dai motori.

.. image:: img/cam_adapter_qmc6310.png
    :width: 400
    :align: center

**Caratteristiche**

* Tensione di lavoro: 5V
* Modello interfaccia: ZH1.5, 7P
* Dimensioni: 40mm x 27mm x 15mm
* Protocollo di comunicazione: UART e I2C

**Documenti**

* PCB

.. image:: img/cam_adap_pcb_bottom.png
    :width: 300

.. image:: img/cam_adap_pcb_top.png
    :width: 300

* Schema

.. image:: img/cam_adapter_sche.png


**Informazioni sul QMC6310**

Il QMC6310 è un sensore magnetico a tre assi, che integra sensori magnetici e un ASIC per il condizionamento del segnale in un unico chip di silicio. Questo package Land Grid Array (LGA) è progettato per applicazioni come e-compass, rotazione della mappa, giochi e navigazione personale in dispositivi mobili e indossabili.

Il QMC6310 si basa sulla tecnologia magnetoresistiva ad alta risoluzione all'avanguardia. Insieme all'ASIC ADC a 16 bit progettato su misura, offre vantaggi come bassa rumorosità, alta precisione, basso consumo energetico, cancellazione degli offset e compensazione della temperatura. Il QMC6310 consente un'accuratezza della bussola compresa tra 1° e 2°. Il bus seriale I²C permette un'interfaccia semplice.

Il QMC6310 è disponibile in un package LGA a montaggio superficiale con dimensioni 1.2x1.2x0.53mm3 e 8 pin.

* |link_qmc6310_datasheet|
