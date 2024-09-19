.. note::

    Ciao, benvenuto nella Community SunFounder di appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri entusiasti.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

Lezione 8: Sistema Avanzato di Evitamento Ostacoli e Inseguimento Intelligente
=====================================================================================

Nella lezione di oggi, faremo un passo avanti con le nostre competenze STEAM. 
Combineremo un modulo di evitamento ostacoli con un sensore ultrasonico per 
creare un sistema avanzato di evitamento ostacoli. Implementeremo inoltre un 
sistema di inseguimento intelligente nel nostro Rover.

Alla fine di questa lezione, il nostro Mars Rover non solo sarà in grado di 
evitare ostacoli sul suo percorso, ma anche di seguire oggetti in movimento. 
Immagina un piccolo robot che ti segue ovunque! Non è emozionante? Iniziamo subito.

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::

    Se stai seguendo questo corso dopo aver assemblato completamente il GalaxyRVR, devi spostare questo interruttore verso destra prima di caricare il codice.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Obiettivi del corso
--------------------------
* Imparare come combinare moduli di evitamento ostacoli con un modulo ultrasonico per migliorare la navigazione.
* Capire i principi e le funzionalità di un sistema avanzato di evitamento ostacoli.
* Imparare a implementare un sistema di inseguimento intelligente nel Mars Rover.

Materiali del corso
------------------------
* Modello di Mars Rover (quello che abbiamo costruito nelle lezioni precedenti)
* Cavo USB
* Arduino IDE
* Computer
* E, naturalmente, la tua mente creativa!

Passi del corso
--------------------

**Passo 1: Comprendere il concetto**

Il modulo di evitamento ostacoli, come suggerisce il nome, aiuta il nostro 
Rover a evitare ostacoli. Rileva gli ostacoli trasmettendo un segnale a 
infrarossi e poi ricevendo il segnale riflesso dall'oggetto. Se c'è un 
ostacolo davanti al modulo, il segnale infrarosso viene riflesso e il modulo lo rileva.

Ora, aggiungere un sensore ultrasonico migliora ulteriormente questo sistema. 
I sensori ultrasonici misurano la distanza inviando un'onda sonora a una frequenza 
specifica e ascoltando che questa onda sonora rimbalzi indietro. Registrando il 
tempo trascorso tra l'emissione dell'onda sonora e il suo ritorno, è possibile 
calcolare la distanza tra il sensore e l'oggetto.

Combinando questi due sistemi, otteniamo un sistema di evitamento ostacoli affidabile, efficiente e versatile!

**Passo 2: Costruire sistemi avanzati di evitamento ostacoli**

Nelle lezioni precedenti, abbiamo appreso le basi dell'evitamento ostacoli utilizzando sensori a infrarossi. Abbiamo anche esplorato come funziona un modulo ultrasonico. Ora, mettiamo insieme tutti questi elementi e costruiamo un sistema avanzato di evitamento ostacoli!

Il nostro Mars Rover potenziato utilizzerà sia sensori ultrasonici che infrarossi per navigare nel suo ambiente.

Immaginiamo come dovrebbero funzionare insieme i moduli infrarosso e ultrasonico. Per chiarire la nostra logica, utilizziamo un diagramma di flusso. Imparare a creare diagrammi di flusso è un passaggio fondamentale nel nostro percorso di programmazione poiché ti aiuta a chiarire i tuoi pensieri e a delineare sistematicamente il tuo piano.

.. image:: img/ultrasonic_ir_avoid_flowchart.png
    :width: 800

Ora trasformiamo questo diagramma di flusso in codice reale per dare vita al nostro Rover.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/53d72ee5-a4c8-4524-92f8-4b0f4760c015/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nota che la funzione ``handleForwardMovement()`` è dove abbiamo integrato il comportamento del sensore ultrasonico. Leggiamo i dati di distanza dal sensore e, basandoci su questi dati, decidiamo il movimento del Rover.

Dopo aver caricato il codice sulla tua scheda R3, è il momento di testare il sistema. Assicurati che il Rover rilevi e eviti ostacoli in modo efficiente. Ricorda che potresti dover regolare la distanza di rilevamento nel codice in base all'ambiente reale per perfezionare il sistema.

**Passo 3: Programmare il sistema di inseguimento intelligente**

Ora che il nostro Rover è in grado di evitare ostacoli, potenziamolo ulteriormente facendolo seguire gli oggetti. Il nostro obiettivo è modificare il codice esistente per far muovere il Rover verso un oggetto in movimento.

Ti sei mai chiesto quali siano le differenze tra un sistema di inseguimento e uno di evitamento ostacoli?

La chiave qui è che in un sistema di inseguimento vogliamo che il nostro Rover si muova in risposta agli oggetti rilevati, mentre in un sistema di evitamento ostacoli stiamo cercando di evitare gli oggetti rilevati.

Visualizziamo il flusso di lavoro desiderato:

.. image:: img/ultrasonic_ir_follow_flowchart.png

* Se il sensore ultrasonico rileva un oggetto entro 5-30 cm, il nostro Rover dovrebbe muoversi verso di esso.
* Se il sensore IR sinistro rileva un oggetto, il Rover dovrebbe svoltare a sinistra.
* Se il sensore IR destro rileva un oggetto, il Rover dovrebbe svoltare a destra.
* In tutti gli altri casi, il Rover dovrebbe rimanere fermo.

Ora è il momento di completare il codice.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/75662c17-4b0a-4494-b18b-089cc2b32311/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Una volta completato il codice, prova a vedere se il Rover segue i tuoi movimenti.

Come abbiamo fatto con il sistema di evitamento ostacoli, sarà cruciale testare anche il sistema di inseguimento e risolvere eventuali problemi che potrebbero sorgere. Sei pronto per iniziare?


**Passo 4: Riflessioni e riepilogo**

Oggi hai realizzato qualcosa di straordinario. Hai combinato diversi moduli e concetti per creare un sistema avanzato di evitamento ostacoli e inseguimento per il tuo Mars Rover. Ricorda, l'apprendimento non finisce qui: continua a esplorare, innovare e applicare le tue nuove competenze ad altri progetti.

Ricorda di riflettere sempre sul tuo processo di apprendimento. Pensa a quanto segue:

* Perché pensi che abbiamo dato priorità al modulo di evitamento ostacoli prima del sensore ultrasonico nel nostro sistema di evitamento, e viceversa nel sistema di inseguimento?
* Come cambierebbe il risultato se invertissimo l'ordine in cui vengono controllati questi moduli nel codice?

Sfide e problemi fanno parte integrante del processo di apprendimento STEAM, offrendo preziose opportunità di miglioramento. Non evitare la risoluzione dei problemi: è uno strumento di apprendimento potente! 

Man mano che continui il tuo percorso, ricorda che ogni ostacolo superato ti avvicina di un passo al padroneggiare le tue abilità STEAM. Continua così e goditi il viaggio!
