.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme a noi.

    **Perché unirsi a noi?**

    - **Supporto tecnico**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima ai nuovi annunci sui prodotti.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a promozioni festive e concorsi a premi.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

Lezione 5: Sbloccare la Mobilità del Mars Rover
======================================================

Preparati, giovani esploratori! Abbiamo imparato a controllare i motori, ora porteremo queste competenze sul pianeta rosso. In questa lezione daremo vita al nostro Mars Rover!

Impareremo come assemblare i motori nel sistema di sospensione Rocker-Bogie e poi, utilizzando le nostre abilità di programmazione, guideremo il nostro Rover attraverso immaginari paesaggi marziani.

È un'avventura marziana nella nostra aula. Iniziamo!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. note::

    Se stai seguendo questo corso dopo aver assemblato completamente il GalaxyRVR, devi spostare questo interruttore verso destra prima di caricare il codice.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Obiettivi di Apprendimento
-------------------------------

* Comprendere come assemblare i motori nel sistema di sospensione Rocker-Bogie del Mars Rover.
* Imparare a usare Arduino per controllare il movimento del Mars Rover.
* Praticare la scrittura di un programma per controllare il movimento del Mars Rover su terreni diversi.

Materiali necessari
--------------------------
* SunFounder R3 Board
* TT Motors
* GalaxyRVR Shield
* Batteria
* Modello Mars Rover (con sistema Rocker-Bogie)
* Strumenti e accessori di base (es. cacciavite, viti, ecc.)
* Cavo USB
* Arduino IDE
* Computer

Passaggi
--------------

**Passo 1: Assemblare i Componenti del Rover**

In questo passaggio assembleremo la batteria, la scheda R3, il GalaxyRVR Shield, i motori e le ruote sul sistema Rocker-Bogie preassemblato. In questo modo il GalaxyRVR sarà pronto per essere utilizzato.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/lu8K26MY96s" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Congratulazioni! Abbiamo costruito con successo il nostro rover, ed è pronto per iniziare l'esplorazione. Mettiamolo in movimento!

**Passo 2: Mettere in Movimento il Rover**

Ora è il momento di dare vita alla nostra creazione e lanciarla nella sua prima missione.
Ma come comunichiamo con il nostro rover? Come gli diciamo dove andare e cosa fare?
È qui che entrano in gioco le nostre abilità di programmazione!

Nel mondo reale, se vogliamo che un'auto si muova in avanti, premiamo l'acceleratore e le due ruote iniziano a girare. Le ruote sul lato destro ruotano in senso orario, mentre quelle sul lato sinistro ruotano in senso antiorario.

.. image:: img/move_car.gif
    :align: center

Immagina di essere seduto al posto di guida, il mondo che sfreccia intorno a te mentre percorri la strada – è esattamente l'esperienza che daremo al nostro rover.

Ora, traduciamo questa esperienza nel linguaggio che il nostro rover comprende: il codice!

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Definire i pin dei motori 
        const int in1 = 2;
        const int in2 = 3;
        const int in3 = 4;
        const int in4 = 5;

        void setup() {
            // Inizializzare SoftPWM
            SoftPWMBegin();
        }

        void loop() {
            // Impostare i motori di sinistra per ruotare in senso antiorario
            SoftPWMSet(in1, 255);  // Velocità massima
            SoftPWMSet(in2, 0);    // Stop
            
            // Impostare i motori di destra per ruotare in senso orario
            SoftPWMSet(in3, 0);    // Stop
            SoftPWMSet(in4, 255);  // Velocità massima
        }

In questo codice stiamo comunicando al nostro rover cosa fare. 
Con la funzione ``SoftPWMSet()``, agiamo come l'acceleratore e il freno dell'auto, 
controllando la velocità e la direzione di ciascun motore. 
Diciamo ai motori di sinistra di girare in senso antiorario e a quelli di destra di girare in senso orario, e così il nostro rover si muove in avanti!

Ovviamente, il concetto di invertire il rover è semplice una volta che capisci come farlo muovere in avanti. Per farlo muovere all'indietro, basta invertire la direzione di rotazione di ciascun motore.

Ecco come lo faremmo nel codice, facendo esattamente l'opposto. Le ruote di destra dovrebbero ora ruotare in senso antiorario e quelle di sinistra in senso orario.

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Definire i pin dei motori 
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Inizializzare SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Impostare i motori di sinistra per ruotare in senso orario
        SoftPWMSet(in1, 0);    // Stop
        SoftPWMSet(in2, 255);  // Velocità massima

        // Impostare i motori di destra per ruotare in senso antiorario
        SoftPWMSet(in3, 255);  // Velocità massima
        SoftPWMSet(in4, 0);    // Stop
    }

In questo codice utilizziamo ``SoftPWMSet()`` per dire ai motori di sinistra di ruotare in senso orario e a quelli di destra di ruotare in senso antiorario.

Non è affascinante come possiamo controllare il viaggio del nostro rover semplicemente con il codice? La prossima volta che ti trovi in un'auto, prendi un momento per pensare al viaggio del tuo rover, esplorando il mondo una rotazione alla volta. Resta sintonizzato, perché il viaggio del nostro rover è appena iniziato!

**Passo 3: Far Muovere il Rover in Altre Direzioni**

Ora che sappiamo come far muovere il nostro Mars Rover avanti e indietro, cosa succede se vogliamo farlo girare a sinistra o a destra?

Proprio come nella guida reale, ci sono due modi principali per far girare un'auto a sinistra.

* Il primo modo è fare in modo che le ruote sul lato sinistro ruotino più lentamente rispetto a quelle sul lato destro. Questa differenza di velocità farà girare il rover verso sinistra.
* Il secondo modo è far ruotare entrambi i motori di sinistra e destra nella stessa direzione (in senso orario in questo caso), facendo ruotare il rover su se stesso.

Vediamo come possiamo implementare entrambi i metodi nel codice:

**Metodo 1: Velocità diverse su ciascun lato**

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Definire i pin dei motori 
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Inizializzare SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Impostare i motori di sinistra per ruotare in senso antiorario a bassa velocità
        SoftPWMSet(in1, 40);
        SoftPWMSet(in2, 0);

        // Impostare i motori di destra per ruotare in senso orario a velocità più alta
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 200);

        delay(2000);  // Durata di 2 secondi
    }

In questo codice, abbiamo ridotto la velocità dei motori di sinistra mantenendo i motori di destra a una velocità più alta. Questo farà girare il rover verso sinistra.

**Metodo 2: Far ruotare tutti i motori nella stessa direzione**

.. code-block:: arduino
    :emphasize-lines: 16,17,18,19

    #include <SoftPWM.h>

    // Definire i pin dei motori 
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Inizializzare SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Impostare tutti i motori per ruotare in senso orario
        SoftPWMSet(in1, 0);
        SoftPWMSet(in2, 255);
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 255);
    }

In questo codice, impostiamo tutti i motori per ruotare in senso orario. Il rover ruoterà su se stesso e cambierà direzione verso sinistra.

Per far girare il rover a destra, i concetti sono gli stessi ma le direzioni sono invertite. Riesci a capire come farlo?

**Passo 4: Muoversi in Tutte le Direzioni**

Man mano che sviluppiamo più funzionalità per il nostro Mars Rover, il nostro codice potrebbe diventare piuttosto lungo e disordinato. In programmazione, è una buona pratica mantenere il codice organizzato e gestibile. Un modo per farlo è creare funzioni separate per ogni compito.

In questo caso, possiamo creare funzioni separate per ogni direzione in cui il rover può muoversi. Ciò non solo rende il nostro codice più facile da capire, ma ci consente anche di riutilizzare queste funzioni in qualsiasi parte del programma senza dover riscrivere le stesse righe di codice.

Vediamo come possiamo farlo:

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/90c13522-9757-4212-b250-63ffbc790fd3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Con questa struttura, il nostro loop principale rimane semplice e facile da seguire. 
Possiamo vedere chiaramente che il rover si muove in avanti, poi indietro, poi gira 
a sinistra e a destra, e infine si ferma.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

I dettagli di come ciascuna di queste azioni viene eseguita sono nascosti in funzioni separate. Questo è un aspetto fondamentale delle buone pratiche di programmazione, noto come astrazione.

**Passo 5: Condivisione e Riflessione**

Congratulazioni per aver completato questo viaggio di esplorazione con il Mars Rover! Questa è un'applicazione pratica delle tue conoscenze scientifiche e ingegneristiche, e hai fatto un lavoro fantastico!

Ora puoi condividere come il tuo rover supera vari ostacoli sul terreno. Potresti filmare il tuo rover che naviga su terreni diversi o mostrare il tuo rover ai tuoi amici.

Riflettere sul tuo processo di apprendimento è anche molto importante. Cosa hai imparato durante questo processo? Ti sono venute nuove idee o pensieri creativi? Cosa hai acquisito nel controllare i motori e nella programmazione?

Puoi continuare a esplorare, scoprire nuove conoscenze e migliorarti costantemente. Continua così, futuri scienziati e ingegneri!
