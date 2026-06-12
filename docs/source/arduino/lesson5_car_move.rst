.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lezione 5: Scatenare la mobilità del Mars Rover
======================================================

Preparatevi, giovani esploratori! Abbiamo imparato a controllare i motori, ora stiamo portando quelle competenze sul pianeta rosso. In questa lezione, daremo vita al Mars Rover!

Impareremo come assemblare i motori nel sistema di sospensione Rocker-Bogie e poi, usando le nostre competenze di codifica, guideremo il nostro Rover attraverso paesaggi marziani immaginati.

È un'avventura marziana nella nostra classe. Iniziamo!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. note::

    Se stai seguendo questo corso dopo aver completamente assemblato il GalaxyRVR, devi spostare questo interruttore a destra prima di caricare il codice.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Obiettivi di apprendimento
---------------------------

* Comprendere come assemblare i motori nel sistema di sospensione Rocker-Bogie del Mars Rover.
* Imparare a usare Arduino per controllare il movimento del Mars Rover.
* Esercitarsi a scrivere un programma per controllare il movimento del Mars Rover su diversi terreni.

Materiali necessari
--------------------------
* Scheda SunFounder R3
* Motori TT
* GalaxyRVR Shield
* Batteria
* Modello Mars Rover (dotato di sistema Rocker-Bogie)
* Strumenti e accessori di base (es. cacciavite, viti, ecc.)
* Cavo USB
* Arduino IDE
* Computer

Procedura
--------------

**Fase 1: Assemblare i componenti del Rover**

In questa fase, assembleremo la batteria, la scheda R3, il GalaxyRVR Shield, i motori e le ruote sul sistema rocker-bogie pre-assemblato. Questo porterà il GalaxyRVR a uno stato funzionante.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/lu8K26MY96s" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Congratulazioni! Abbiamo costruito con successo il nostro rover, ed è pronto per iniziare a esplorare. Mettiamoci in movimento!

**Fase 2: Mettere il Rover in movimento**

Ora è il momento di dare vita alla nostra creazione e mandarla nel suo viaggio inaugurale.
Ma come comunichiamo con il nostro rover? Come gli diciamo dove andare e cosa fare?
È qui che entrano in gioco le nostre competenze di codifica!

Nel mondo reale, se vogliamo che un'auto vada avanti, premiamo l'acceleratore ed entrambe le ruote iniziano a girare.
Le ruote sul lato destro girano in senso orario, mentre quelle sul lato sinistro girano in senso antiorario.

.. image:: img/move_car.gif
    :align: center

Immagina di essere seduto al posto di guida, con il mondo che scorre veloce mentre navighi lungo la strada aperta: è esattamente l'esperienza che daremo al nostro rover.

Ora, traduciamo quell'esperienza nel linguaggio che il nostro rover capisce: il codice!

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Define the pins of motors
        const int in1 = 2;
        const int in2 = 3;
        const int in3 = 4;
        const int in4 = 5;

        void setup() {
            // Initialize SoftPWM
            SoftPWMBegin();
        }

        void loop() {
            // Set the left motors rotate counterclockwise
            SoftPWMSet(in1, 255);  // Full speed
            SoftPWMSet(in2, 0);    // Stop

            // Set the right motors rotate clockwise
            SoftPWMSet(in3, 0);    // Stop
            SoftPWMSet(in4, 255);  // Full speed

        }

In questo codice, stiamo parlando al nostro rover, dicendogli esattamente cosa fare.
Con la funzione ``SoftPWMSet()``, agiamo come l'acceleratore e i freni dell'auto,
controllando la velocità e la direzione di ciascun motore.
Diciamo ai motori sinistri di girare in senso antiorario e ai motori destri di girare in senso orario, e proprio così, il nostro rover avanza!

Il concetto di far retrocedere il rover è semplice una volta capito come farlo avanzare.
Per far muovere il rover all'indietro, dobbiamo solo invertire la direzione di rotazione di ciascun motore.

Ecco come lo faremmo nel codice: facciamo esattamente l'opposto. Le ruote destre dovrebbero ora ruotare in senso antiorario, e le ruote sinistre dovrebbero ruotare in senso orario.

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Define the pins of motors
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set the left motors to rotate clockwise
        SoftPWMSet(in1, 0);    // Stop
        SoftPWMSet(in2, 255);  // Full speed

        // Set the right motors to rotate counterclockwise
        SoftPWMSet(in3, 255);  // Full speed
        SoftPWMSet(in4, 0);    // Stop

    }

In questo codice, usiamo ``SoftPWMSet()`` per dire ai motori sinistri di ruotare in senso orario e ai motori destri di ruotare in senso antiorario.

Non è affascinante che possiamo controllare il viaggio del nostro rover semplicemente con il codice? La prossima volta che sei in macchina, prenditi un momento per pensare al viaggio del tuo rover, che esplora il mondo una rotazione alla volta. Resta sintonizzato, perché il viaggio del nostro rover è appena iniziato!

**Fase 3: Far muovere il Rover in altre direzioni**

Ora che sappiamo come muovere il nostro Mars Rover avanti e indietro, cosa succede se vogliamo che giri a sinistra o a destra?

Proprio come nella guida reale, ci sono due modi principali per un'auto di girare a sinistra.

* Il primo modo è far ruotare le ruote sul lato sinistro più lentamente di quelle sul lato destro. Questa differenza di velocità farà girare il rover verso sinistra.
* Il secondo modo è far ruotare entrambi i motori sinistro e destro nella stessa direzione (in questo caso in senso orario), che farà girare il rover a sinistra sul proprio asse.

Vediamo come possiamo implementare entrambi i modi nel codice:

**Metodo 1: Diverse velocità su ciascun lato**

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Define the pins of motors
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set the left motors rotate counterclockwise in low speed
        SoftPWMSet(in1, 40);
        SoftPWMSet(in2, 0);

        // Set the right motors rotate clockwise in higher speed
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 200);

        delay(2000);  // Last for 2 seconds
    }

In questo codice, abbiamo diminuito la velocità dei motori sinistri mantenendo i motori destri a una velocità più alta. Questo farà girare il rover verso sinistra.

**Metodo 2: Rotazione di tutti i motori nella stessa direzione**

.. code-block:: arduino
    :emphasize-lines: 16,17,18,19

    #include <SoftPWM.h>

    // Define the motor pins
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set all motors to rotate clockwise
        SoftPWMSet(in1, 0);
        SoftPWMSet(in2, 255);
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 255);
    }

In questo codice, impostiamo tutti i motori per ruotare in senso orario. Il rover girerà sul proprio asse e la direzione cambierà verso sinistra.

Per far girare il rover a destra, i concetti sono gli stessi ma le direzioni sono invertite. Riesci a capire come fare?

**Fase 4: Muoversi in tutte le direzioni**

Man mano che sviluppiamo più funzionalità per il nostro Mars Rover, il nostro codice potrebbe diventare piuttosto lungo e disordinato. Nella programmazione, è una buona pratica mantenere il codice organizzato e manutenibile. Un modo per raggiungere questo obiettivo è creare funzioni separate per compiti separati.

In questo caso, possiamo creare funzioni separate per ogni direzione in cui il rover può muoversi. Questo non solo rende il nostro codice più facile da capire, ma ci permette anche di riutilizzare queste funzioni ovunque nel nostro programma senza dover riscrivere le stesse righe di codice.

Vediamo come possiamo farlo:

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/90c13522-9757-4212-b250-63ffbc790fd3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Con questa struttura, il nostro loop principale rimane semplice e facile da seguire. Possiamo chiaramente vedere che il rover avanza, poi indietreggia,
poi gira a sinistra e a destra, e infine si ferma.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

I dettagli di come ciascuna di queste azioni viene realizzata sono nascosti in funzioni separate. Questo è un aspetto chiave delle buone pratiche di programmazione noto come astrazione.

**Fase 5: Condivisione e riflessione**

Congratulazioni per aver completato questo viaggio di esplorazione con il Mars Rover! Questa è un'applicazione pratica della tua conoscenza di scienza e ingegneria, e hai fatto un lavoro fantastico!

Ora, puoi condividere come il tuo rover supera vari ostacoli del terreno. Potresti filmare il tuo rover mentre naviga su diversi terreni, o mostrare il tuo rover ai tuoi amici.

Riflettere sul tuo processo di apprendimento è anche molto importante. Cosa hai imparato durante questo processo? Sono emerse nuove idee o pensieri creativi? Cosa hai guadagnato nel controllo dei motori e nella programmazione?

Puoi continuare a esplorare, scoprire nuove conoscenze e migliorarti costantemente. Continuate così, futuri scienziati e ingegneri!
