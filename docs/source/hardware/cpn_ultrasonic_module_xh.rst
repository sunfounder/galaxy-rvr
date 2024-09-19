.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali durante le festività.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!


Modulo Ultrasonico
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG**: Input del segnale di innesco
* **ECHO**: Output del segnale di eco
* **GND**: Massa
* **VCC**: Alimentazione 5V

Questo è il sensore di distanza ultrasonico HC-SR04, che fornisce una misurazione senza contatto da 2 cm a 400 cm con una precisione fino a 3 mm. Il modulo include un trasmettitore ultrasonico, un ricevitore e un circuito di controllo.

È sufficiente collegare 4 pin: VCC (alimentazione), Trig (innesco), Echo (ricezione) e GND (massa) per usarlo facilmente nei tuoi progetti di misurazione.

**Caratteristiche**

* Tensione di lavoro: DC5V
* Corrente di lavoro: 16mA
* Frequenza di lavoro: 40Hz
* Raggio massimo: 500cm
* Raggio minimo: 2cm
* Segnale di input del trigger: impulso TTL da 10uS
* Segnale di output dell'eco: segnale di livello TTL proporzionato alla distanza
* Connettore: XH2.54-4P
* Dimensioni: 46x20.5x15 mm

**Principio di funzionamento**

I principi di base sono i seguenti:

* Utilizzare l'IO per attivare un segnale di alto livello per almeno 10us.
* Il modulo emette un impulso ultrasonico di 8 cicli a 40 kHz e rileva se viene ricevuto un segnale di ritorno.
* Echo emetterà un segnale di alto livello se viene rilevato un segnale di ritorno; la durata del segnale alto corrisponde al tempo che intercorre tra l'emissione e il ritorno del segnale.
* Distanza = (tempo di alto livello x velocità del suono (340M/S)) / 2

    .. image:: img/ultrasonic_prin.jpg
        :width: 800


**Note sull'applicazione**

* Questo modulo non deve essere collegato con l'alimentazione accesa, se necessario, collegare prima il GND del modulo. Altrimenti, potrebbe influenzare il corretto funzionamento del modulo.
* L'area dell'oggetto da misurare dovrebbe essere di almeno 0,5 metri quadrati e il più piatta possibile. Altrimenti, i risultati potrebbero essere influenzati.
