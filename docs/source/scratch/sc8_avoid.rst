.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme agli altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!



.. _ir_ultra_avoid:


Lezione 8 Evasione Avanzata degli Ostacoli
==================================================

Il modulo di evitamento ostacoli, come suggerisce il nome, aiuta il nostro Rover a evitare gli ostacoli. Rileva gli ostacoli trasmettendo un segnale a infrarossi e ricevendo il segnale riflesso dall'oggetto. Se c'è un ostacolo davanti al modulo, il segnale a infrarossi viene riflesso indietro e il modulo lo rileva.

Ora, aggiungendo un sensore a ultrasuoni al sistema, miglioriamo questa funzionalità. I sensori a ultrasuoni misurano la distanza inviando un'onda sonora a una frequenza specifica e ascoltando il ritorno dell'onda riflessa. Registrando il tempo trascorso tra la generazione dell'onda sonora e il suo ritorno, è possibile calcolare la distanza tra il sensore e l'oggetto.

Combinando questi due sistemi, otteniamo un sistema di evitamento degli ostacoli affidabile, efficiente e versatile!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

Obiettivi di Apprendimento
---------------------------------

* Combinare i moduli di evitamento ostacoli a ultrasuoni e infrarossi per abilitare la funzione base di evitamento degli ostacoli nel modello di Rover marziano.
* Imparare a programmare il modello di Rover marziano per rilevare e evitare automaticamente gli ostacoli.


Materiali
-------------

* Smartphone o tablet
* APP Mammoth Coding
* GalaxyRVR


Costruzione di Sistemi Avanzati di Evasione Ostacoli
-------------------------------------------------------

Nelle lezioni precedenti, abbiamo imparato le basi dell'uso dei sensori a infrarossi per l'evitamento degli ostacoli. Abbiamo anche esplorato i principi dei moduli a ultrasuoni. Ora metteremo insieme tutti questi elementi per costruire un sistema di evitamento ostacoli avanzato!

Il nostro Rover marziano potenziato navigherà nei suoi dintorni utilizzando sia sensori a ultrasuoni che a infrarossi.

1. Possiamo utilizzare il blocco di codice della lezione :ref:`ir_obstacle` come modello. Aprilo dai tuoi progetti salvati.

.. image:: img/7_avoid_open.png

2. Poi, salvalo come copia.

.. image:: img/7_avoid_save_copy.png

3. Rinomina il progetto e salvalo.

.. image:: img/7_avoid_save_rename.png

4. Aggiungi il rilevamento della distanza utilizzando il sensore a ultrasuoni. Trascina un blocco ``quando distanza < 15 cm``.

.. image:: img/7_avoid_when.png
    :width: 800

5. Allo stesso modo, trascina un blocco ``ferma altri script nello sprite`` per assicurarti che il GalaxyRVR risponda solo a un sensore alla volta.

.. image:: img/7_avoid_stop.png

6. Muoviti all'indietro fino a raggiungere una distanza di sicurezza.

.. image:: img/7_avoid_backward.png

7. Gira per un secondo (a sinistra o a destra).

.. image:: img/7_avoid_turn.png

8. Procedi di nuovo in avanti.

.. image:: img/7_avoid_go.png

Ora, i sensori IR su entrambi i lati e il sensore a ultrasuoni anteriore lavoreranno insieme per formare un potente sistema di evitamento ostacoli, garantendo che il GalaxyRVR non si scontri con alcun ostacolo durante le sue missioni.

