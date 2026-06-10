.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

Scheda adattatore per fotocamera
================================

.. image:: img/cam_adapter_board.jpg
    :width: 500
    :align: center

* **RST**: Utilizzato per resettare l'ESP32-CAM.
* **SCL**: Pin dati seriali per QMC6310
* **SDA**: Pin clock seriale del QMC6310
* **RXD**: L'RXD dell'ESP32-CAM, è necessario caricare il codice sull'ESP32-CAM attraverso questi due pin seriali, RXD e TXD.
* **TXD**: TXD dell'ESP32-CAM
* **5V**: Ingresso alimentazione 5V CC
* **GND**: Ingresso massa

La scheda adattatore per fotocamera, come suggerisce il nome, è una scheda di espansione per l'ESP-32 CAM, utilizzata per espandere l'ESP32-CAM in modo che possa essere fissato al robot e possa essere facilmente cablato.

.. image:: img/cam_adapter_esp32cam.png
    :width: 400
    :align: center

Inoltre, poiché il chip geomagnetico QMC6310 è suscettibile alle interferenze dei motori, lo abbiamo posizionato su questa scheda adattatore per fotocamera per tenerlo il più lontano possibile dai motori.

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

* Schema elettrico

.. image:: img/cam_adapter_sche.png


**Informazioni sul QMC6310**

Il QMC6310 è un sensore magnetico a tre assi, che integra sensori magnetici e ASIC di condizionamento del segnale in un unico chip di silicio. Questo package Land Grid Array (LGA) è destinato ad applicazioni come e-compass, rotazione mappe, giochi e navigazione personale in dispositivi mobili e indossabili.

Il QMC6310 si basa su una tecnologia magnetoresistiva all'avanguardia e ad alta risoluzione. Insieme all'ADC ASIC a 16 bit progettato su misura, offre i vantaggi di basso rumore, alta precisione, basso consumo energetico, cancellazione dell'offset e compensazione della temperatura. Il QMC6310 consente una precisione di rotta della bussola da 1° a 2°. Il bus seriale I²C consente un'interfaccia semplice.

Il QMC6310 è in un package LGA a 8 pin a montaggio superficiale da 1,2x1,2x0,53mm³.

* |link_qmc6310_datasheet|
