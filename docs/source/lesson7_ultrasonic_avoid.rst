.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto tecnico esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri nuovi prodotti.
    - **Promozioni festive e giveaway**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

Lezione 7: Migliorare la navigazione del Rover con il modulo ultrasonico
============================================================================

Nella nostra ultima avventura, abbiamo dotato il nostro Mars Rover di "occhi" ai lati, creando un sistema base di evitamento ostacoli. Tuttavia, c'è un punto cieco proprio davanti, una sfida che siamo pronti a superare!

Oggi, in questa lezione, daremo al nostro Rover un nuovo senso della "vista". Installeremo un modulo sensore ultrasonico, che fungerà da occhi centrali, aiutando il rover a rilevare ostacoli direttamente davanti a sé.

Esploreremo le affascinanti meccaniche delle onde ultrasoniche e scopriremo come migliorano la capacità del nostro Rover di navigare su terreni complessi. Con questa aggiunta, il nostro Mars Rover sarà più percettivo e agile, pronto per missioni esplorative ancora più ambiziose.

Unisciti a noi mentre facciamo un ulteriore passo in questo entusiasmante viaggio STEAM, rendendo il nostro Mars Rover ancora più abile nell'esplorare territori inesplorati!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/ultrasonic_avoid.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. note::

    Se stai seguendo questo corso dopo aver assemblato completamente il GalaxyRVR, sposta questo interruttore a destra prima di caricare il codice.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center


Obiettivi del corso
--------------------------

* Comprendere il principio della misurazione delle distanze con ultrasuoni.
* Imparare a utilizzare Arduino e il modulo ultrasonico per la misurazione delle distanze.
* Praticare l'applicazione del modulo ultrasonico per l'evitamento degli ostacoli sul modello Mars Rover.

Materiali necessari
---------------------

* Modulo Ultrasonico
* Strumenti e accessori di base (ad es. cacciavite, viti, fili ecc.)
* Modello Mars Rover (dotato di sistema rocker-bogie, schede principali, motori, modulo di evitamento ostacoli)
* Cavo USB
* Arduino IDE
* Computer

Fasi del corso
--------------------
**Passo 1: Montare il modulo sensore ultrasonico**

Ora che siamo pronti a dotare il nostro Mars Rover di un potente nuovo senso della "vista", è il momento di assemblare il modulo sensore ultrasonico.

.. raw:: html

  <iframe width="600" height="400" src="https://www.youtube.com/embed/c_xWAVapGic?si=ovuxheXdGVpHopPa" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Ed ecco fatto! Ora il nostro Mars Rover ha un modulo sensore ultrasonico completamente assemblato, pronto a migliorare le sue capacità di rilevamento degli ostacoli. Sei pronto a vedere come cambierà la navigazione del nostro Rover? Scopriamolo insieme!


**Passo 2: Esplorare il modulo ultrasonico**

Conosciamo l'HC-SR04, un potente sensore a ultrasuoni per la misurazione delle distanze. Questo piccolo dispositivo può misurare accuratamente distanze da 2 cm fino a 400 cm, senza mai toccare nulla! Sorprendente, vero? È come avere un superpotere! Può "vedere" le distanze utilizzando solo onde sonore, proprio come fanno i pipistrelli per orientarsi di notte.

Utilizza quattro superpoteri, o meglio, quattro pin per compiere la sua magia:

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG (Trigger Pulse Input)** - È il pulsante di avvio per il nostro supereroe. Gli dice: "Ehi, è ora di inviare un'onda ultrasonica!"
* **ECHO (Echo Pulse Output)** - Questo è il modo in cui il nostro supereroe ascolta l'eco dell'onda sonora che ha inviato.
* **VCC** - Anche i supereroi hanno bisogno di energia. Lo colleghiamo a un'alimentazione da 5V.
* **GND** - È la connessione a terra. Proprio come i supereroi devono rimanere connessi alla realtà!

Immagina il nostro supereroe, il sensore ultrasonico HC-SR04, mentre gioca a fare l'eco tra le montagne.

.. image:: img/ultrasonic_prin.jpg
    :width: 800

* Per prima cosa, il cervello del nostro supereroe, l'MCU, dice "Pronti, partenza, via!" inviando un segnale ad alto livello per almeno 10 microsecondi al nostro supereroe. È come quando raccogliamo energia prima di gridare in una valle.
* All'udire "Via!", il nostro supereroe grida forte 8 volte molto velocemente. Questo urlo ultrasonico viene inviato a una velocità di 40 kHz. Il supereroe avvia anche un cronometro e rimane in ascolto per eventuali echi di ritorno.
* Se c'è un ostacolo davanti, l'urlo lo colpirà e tornerà indietro come eco. Sentendo l'eco, il nostro supereroe ferma il cronometro e annota il tempo trascorso. Inoltre, invia un segnale alto per far sapere all'MCU che ha sentito un'eco.
* Infine, per capire quanto lontano si trova l'ostacolo, il nostro supereroe usa una semplice formula: prende il tempo registrato sul cronometro, lo divide per 2 e lo moltiplica per la velocità del suono (340m/s). Il risultato è la distanza dall'ostacolo!

Ecco come il nostro sensore-supereroe può capire se c'è un ostacolo davanti e quanto lontano si trova. Straordinario, non è vero? Nel prossimo passo, vedremo come usare questo potere nel nostro Mars Rover!

* **Preparazione**: Per iniziare, stabiliamo la comunicazione seriale a un baud rate di 9600 per poter vedere le misurazioni del nostro "supereroe" nel Monitor Seriale.

**Passo 3: Programmare il Nostro Sensore Supereroe**

Dopo aver assemblato il nostro sensore supereroe e capito come utilizza i suoi superpoteri, è il momento di metterli in azione! Scriviamo uno sketch Arduino per permettere al nostro sensore ultrasonico di misurare le distanze e mostrarcele.

Ecco i passaggi chiave che seguirà il nostro sensore supereroe:

* Abbiamo collegato entrambi i pin TRIG ed ECHO al pin 10 sul GalaxyRVR Shield. Questo ci consente di controllare sia la trasmissione che la ricezione del segnale del modulo ultrasonico utilizzando un singolo pin Arduino.

.. image:: img/ultrasonic_shield.png

.. code-block:: arduino

    // Definire il pin per il modulo ultrasonico
    #define ULTRASONIC_PIN 10

* **Preparazione**: Per iniziare, stabiliamo la comunicazione seriale a un baud rate di 9600 per poter vedere le misurazioni del nostro supereroe nel Serial Monitor.


.. code-block:: arduino

    void setup() {
        // Avvia la comunicazione seriale
        Serial.begin(9600);
    }

* **Lancio del segnale!**: Impostiamo il pin ``ULTRASONIC_PIN`` come pin ``OUTPUT`` per inviare un impulso di 10 microsecondi, che è come comandare al nostro supereroe ultrasonico di emettere un potente "urlo" (onde sonore ultrasoniche)!

.. code-block:: arduino

    // È necessario un ritardo di 4 ms, altrimenti la lettura potrebbe essere 0
    delay(4);

    // Imposta su OUTPUT per inviare il segnale
    pinMode(ULTRASONIC_PIN, OUTPUT);

    // Azzera il pin di trigger
    digitalWrite(ULTRASONIC_PIN, LOW);
    delayMicroseconds(2);

    // Attiva il sensore inviando un impulso alto per 10us
    digitalWrite(ULTRASONIC_PIN, HIGH);
    delayMicroseconds(10);

    // Riporta il pin di trigger a basso
    digitalWrite(ULTRASONIC_PIN, LOW);



* **Attesa e ascolto**: Imposta il pin ``ULTRASONIC_PIN`` come ``INPUT``. In questo modo, il nostro sensore-supereroe è ora pronto ad ascoltare l'eco del suo urlo. Se c'è un ostacolo davanti, l'urlo lo colpirà e tornerà indietro come eco. Sentendo l'eco, il nostro supereroe ferma il cronometro e annota il tempo. Invia anche un segnale alto per informare l'MCU di aver sentito un'eco.

.. code-block:: arduino

    pinMode(ULTRASONIC_PIN, INPUT);
    float duration = pulseIn(ULTRASONIC_PIN, HIGH);

* **Super Calcolo**: Con l'eco ritornato, il nostro sensore utilizza la velocità del suono per calcolare la distanza dall'oggetto. Dividiamo il tempo totale dell'eco per 2 perché il tempo include sia l'emissione che l'attesa dell'eco.

.. code-block:: arduino

    float distance = duration * 0.034 / 2;


* **Rapporto finale**: Il nostro sensore-supereroe poi rivela il risultato della sua missione, stampando la distanza sul Monitor Seriale per farcela vedere.

.. code-block:: arduino

    // Stampa la distanza sul monitor seriale
    Serial.print("La distanza è: ");
    Serial.print(distance);
    Serial.println(" cm");

* **Riposo & Prontezza**: Ogni supereroe ha bisogno di riposare, quindi il nostro sensore prende una breve pausa prima della prossima missione. Questo permette al sensore di "resettarsi" prima di chiedergli un'altra misurazione.

.. code-block:: arduino

    delay(200);

Ecco il codice completo che trasforma il nostro sensore in un supereroe:

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/35bddbcf-145c-4e4f-b3ea-21e8210af4a6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Passo 4: Programmare il modulo ultrasonico per controllare il Mars Rover**

Ora che abbiamo equipaggiato il nostro Mars Rover con un modulo sensore ultrasonico, è il momento di programmarlo affinché risponda in base alle misurazioni del sensore. 

* Per facilitare la lettura, abbiamo creato una funzione chiamata ``readSensorData()``. Questa funzione incapsula tutto il codice necessario per leggere la distanza dal sensore ultrasonico.

  .. code-block:: arduino

    float readSensorData() {
        // È necessario un ritardo di 4 ms, altrimenti la lettura potrebbe essere 0
        delay(4);
      
        // Imposta su OUTPUT per inviare il segnale
        pinMode(ULTRASONIC_PIN, OUTPUT);
      
        // Azzera il pin di trigger
        digitalWrite(ULTRASONIC_PIN, LOW);
        delayMicroseconds(2);
      
        // Attiva il sensore inviando un impulso alto per 10us
        digitalWrite(ULTRASONIC_PIN, HIGH);
        delayMicroseconds(10);
      
        // Riporta il pin di trigger a basso
        digitalWrite(ULTRASONIC_PIN, LOW);
      
        // Imposta su INPUT per leggere
        pinMode(ULTRASONIC_PIN, INPUT);
      
        // pulseIn restituisce la durata dell'impulso sul pin
        float duration = pulseIn(ULTRASONIC_PIN, HIGH);
      
        // Calcola la distanza (in cm) in base alla velocità del suono (340 m/s o 0.034 cm/us)
        float distance = duration * 0.034 / 2;
      
        return distance;
    }

* Nella funzione ``loop()``, chiamiamo ``readSensorData()`` e memorizziamo il valore restituito nella variabile ``distance``.

  .. code-block:: arduino

    float distance = readSensorData();

* A seconda di questa distanza, il Rover si muoverà in avanti, indietro o si fermerà.

  .. code-block:: arduino
  
    // Controlla il rover in base alla lettura della distanza
    if (distance > 50) {  // Se è sicuro avanzare
      moveForward(200);
    } else if (distance < 15) {  // Se c'è un ostacolo vicino
      moveBackward(200);
      delay(500);  // Attendi un po' prima di tentare una svolta
      backLeft(150);
      delay(1000);
    } else {  // Per distanze intermedie, procedi con cautela
      moveForward(150);
    }

  * Se il percorso è libero (l'ostacolo è a più di 50 cm di distanza), il nostro Rover avanza con audacia.
  * Se un ostacolo si avvicina (meno di 50 cm ma più di 15 cm), il Rover avanzerà a una velocità inferiore.
  * Se un ostacolo è troppo vicino (meno di 15 cm), il Mars Rover indietreggerà e poi si girerà a sinistra.

  .. image:: img/ultrasonic_flowchart.png

Qui sotto trovi il codice completo. Puoi caricare questo codice sulla scheda R3 e verificare se ottieni l'effetto desiderato. Puoi anche modificare la distanza di rilevamento in base all'ambiente reale per perfezionare ulteriormente questo sistema di evitamento degli ostacoli.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cded6408-1469-4289-b79b-7d445b56352b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Grazie a queste capacità avanzate, il Mars Rover sarà meglio equipaggiato per identificare eventuali ostacoli sul suo cammino, misurare le distanze con precisione e prendere decisioni informate per evitare gli ostacoli. Questo ridurrà significativamente la probabilità di collisioni o altri pericoli che potrebbero ostacolare la missione di esplorazione del rover.

Con i suoi super-sensi, il Mars Rover può operare con maggiore sicurezza ed efficienza, permettendogli di approfondire l'esplorazione dei misteri di Marte e raccogliere dati scientifici preziosi per i ricercatori sulla Terra.

**Passo 5: Riflessione e Sintesi**

In questa lezione, abbiamo esplorato il funzionamento delle onde ultrasoniche e come tradurre il loro tempo di ritorno al sensore in una distanza misurabile attraverso il codice.

Successivamente, abbiamo sfruttato le onde ultrasoniche per creare un sistema di evitamento degli ostacoli. Questo sistema specifico varia le sue risposte in base alla distanza dall'ostacolo in arrivo.


Ora, poniamo alcune domande di introspezione per riflettere su questa lezione:

* Come rileva la distanza un modulo ultrasonico? Puoi spiegare il concetto di base?
* In che modo il sistema di evitamento degli ostacoli di questa lezione differisce da quello precedente? Quali sono i rispettivi vantaggi e svantaggi?
* È possibile combinare questi due sistemi di evitamento degli ostacoli?

Riflettere su queste domande ci aiuterà a consolidare la nostra comprensione e ci spingerà a pensare all'applicazione di questi concetti ad altri progetti. Non vedo l'ora di intraprendere la nostra prossima avventura!
