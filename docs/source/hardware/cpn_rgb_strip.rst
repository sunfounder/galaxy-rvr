.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci il tuo interesse per Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto tecnico**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime speciali.
    - **Sconti esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

Striscia LED RGB a 4 LED
========================

.. image:: img/4_rgb_strip.jpg


* **+5V**: Anodo comune dei tre LED da collegare a una tensione di 5V DC
* **B**: Catodo del LED blu
* **R**: Catodo del LED rosso
* **G**: Catodo del LED verde

Questa striscia LED RGB presenta quattro LED R5050 RGB, in grado di creare qualsiasi sfumatura di colore combinando i tre colori primari: rosso, blu e verde.

I LED R5050 RGB sono progettati con una configurazione ad anodo comune. Ogni LED sulla striscia funziona come circuito indipendente, permettendo di tagliare la striscia in punti designati senza influenzare le altre sezioni. La flessibilità e l'adattabilità della striscia sono migliorate dalla sua costruzione su un circuito FPC, dotato di adesivo a doppia faccia per un'installazione facile.


**Cos'è un LED R5050 RGB?**

Il LED R5050 RGB è un tipo di LED che combina diodi emettitori di luce rossa, blu e verde in un singolo pacchetto. Ogni LED all'interno di questo pacchetto ha il proprio pin, consentendo un controllo individuale. Questa configurazione permette la produzione di un'ampia gamma di colori variando l'intensità di ciascun LED.

.. image:: img/rgb_5050.jpg
    :width: 400
.. image:: img/rgb_5050_sche.png
    :width: 200

In un'applicazione tipica, più LED R5050 RGB sono disposti su un circuito flessibile in una configurazione intelligente. Questo avviene collegando insieme i terminali "positivi" (anodi) di tutti i LED, mentre i terminali "negativi" (catodi) sono collegati alle rispettive corsie di colore. Ciò significa che tutti i catodi verdi sono collegati insieme, così come quelli rossi e quelli blu. Questa disposizione consente un controllo efficiente della miscelazione dei colori e dell'intensità della luce, rendendo questi LED molto popolari in applicazioni in cui si desidera un'illuminazione personalizzabile, come illuminazione decorativa, segnaletica e tecnologie di visualizzazione.

.. image:: img/rgb_strip_sche.png


**Caratteristiche**

* Tensione di lavoro: DC5V
* Colore: RGB a colori completi
* Temperatura di esercizio: -15-50°C
* Tipo di LED RGB: 5050RGB
* Corrente: 150mA (singolo circuito)
* Potenza: 1,5W
* Spessore della striscia luminosa: 2mm
* Larghezza della striscia luminosa: 5,5mm
* Cavo: ZH1.5-4P, 25cm, 28AWG, Nero
