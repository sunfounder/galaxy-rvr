.. note::

    Ciao, benvenuto nella comunità SunFounder di appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

Modulo di Evitamento Ostacoli a Infrarossi (IR)
====================================================

Questo è un modulo di evitamento ostacoli a infrarossi in grado di rilevare la presenza di oggetti davanti a sé. Viene comunemente utilizzato in robot, sistemi di automazione e altri dispositivi intelligenti. Il suo raggio di rilevamento varia da 2 cm a 40 cm e gli oggetti di diversi colori hanno livelli di riflettività diversi. Pertanto, più scuro è l'oggetto, minore sarà la distanza di rilevamento.

.. image:: img/ir_avoid.png
    :width: 400
    :align: center

Di seguito sono riportate le definizioni dei pin:

* **GND**: Massa
* **+**: Alimentazione, 3.3 ~ 5V DC.
* **Out**: Di default, rimane alto e va basso solo quando rileva un ostacolo.
* **EN**: Questo pin **enable** decide quando il modulo deve funzionare. Per impostazione predefinita, è collegato a GND, il che significa che il modulo è sempre attivo.


**Come funziona?**

Questo modulo contiene una coppia di componenti trasmittenti e riceventi a infrarossi. Fondamentalmente, il trasmettitore emette luce a infrarossi e quando questa luce incontra un ostacolo, viene riflessa e ricevuta dal ricevitore. Al rilevamento, l'indicatore si illumina. Dopo l'elaborazione del circuito, viene emesso un segnale di livello basso.

.. image:: img/ir_receive.png
    :width: 600
    :align: center

Lo stato di basso livello del pin **EN** attiva il modulo, con il cappuccio jumper che collega il pin **EN** al GND. Per controllare il pin EN tramite programma, rimuovere il cappuccio jumper.

.. image:: img/ir_cap.png
    :width: 400
    :align: center

Sul modulo ci sono due potenziometri, uno per regolare la potenza di trasmissione e l'altro per regolare la frequenza di trasmissione. Regolando questi due potenziometri, è possibile regolare la distanza effettiva.

.. image:: img/ir_avoid_pot.png
    :width: 400
    :align: center 


**Regolare la distanza di rilevamento**

Per ottenere prestazioni ottimali, il raggio di rilevamento del modulo di evitamento ostacoli deve essere calibrato con precisione, poiché le impostazioni di fabbrica predefinite potrebbero non essere adeguate a requisiti specifici.

La calibrazione si svolge secondo i seguenti passaggi:

#. Allineamento del modulo: Inizia con il modulo di evitamento ostacoli sul lato destro. Il trasporto può talvolta spostare l'allineamento del trasmettitore e del ricevitore a infrarossi del modulo. Devono essere riallineati manualmente per garantire l'accuratezza.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Posiziona un ostacolo a circa 20 cm direttamente di fronte al modulo destro. La scatola in cui è contenuto il kit del nostro Rover è una buona scelta per questo! Ora, ruota il potenziometro sul modulo fino a quando la spia luminosa sul modulo si accende. Poi, continua a spostare l'ostacolo avanti e indietro per verificare se la spia si accende alla distanza desiderata. Se la spia non si accende alla distanza corretta o rimane accesa senza spegnersi, sarà necessario regolare l'altro potenziometro.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Ripeti lo stesso processo per l'altro modulo.

**Caratteristiche**

* Tensione operativa: da 3.3 V a 5 V
* Uscita: digitale (on/off)
* Soglia di rilevamento: regolabile tramite 2 potenziometri
* Gamma di distanza: da 2 a 40 cm
* Regolazione R5: regolazione della frequenza 38 kHz (già ottimizzata)
* Regolazione R6: regolazione del ciclo di lavoro del LED IR (già ottimizzata)
* Temperatura di esercizio: da -10 °C a +50 °C
* Angolo efficace: 35°
* Interfaccia I/O: interfaccia a 4 fili (- / + / S / EN)
* Dimensioni: 45 x 16 x 10 mm
* Peso: 9 g
