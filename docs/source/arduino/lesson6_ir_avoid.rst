.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!


Lezione 6: Esplorare il modulo evitamento ostacoli
==============================================================

Ci immergiamo nel mondo del modulo a infrarossi per l'evitamento degli ostacoli. Posizionati ai lati del nostro Mars Rover, questi sensori fungono da "occhi" del rover, aiutandolo a schivare gli ostacoli laterali e a navigare in sicurezza nel paesaggio marziano.

Impareremo come integrare questi moduli con il nostro rover, svelare la magia dietro il loro funzionamento e sviluppare codice per far sì che il nostro rover eviti intelligentemente qualsiasi ostacolo incontri.

Preparati a equipaggiare il nostro rover con un'intelligenza marziana per schivare gli ostacoli! Iniziamo!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_ir1.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. note::

    Se stai seguendo questo corso dopo aver completamente assemblato il GalaxyRVR, devi spostare questo interruttore a destra prima di caricare il codice.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Obiettivi di apprendimento
--------------------------

* Comprendere il principio di funzionamento e l'applicazione del modulo evitamento ostacoli a infrarossi.
* Imparare a usare Arduino per controllare il modulo evitamento ostacoli a infrarossi.
* Esercitarsi a progettare e costruire un sistema automatico di evitamento ostacoli basato su infrarossi.

Materiali necessari
---------------------

* Moduli evitamento ostacoli
* Strumenti e accessori di base (es. cacciavite, viti, cavi, ecc.)
* Modello Mars Rover (dotato di sistema rocker-bogie, schede principali, motori)
* Cavo USB
* Arduino IDE
* Computer

Procedura
-------------
**Fase 1: Installare il modulo evitamento ostacoli**

Ora installeremo i due moduli evitamento ostacoli sul rover.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/UWEj_ROYAt0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

I passaggi di assemblaggio sono stati semplici, vero? Nei prossimi passi, impareremo il principio di funzionamento di questi moduli e come aiutano il nostro Mars Rover a evitare gli ostacoli. Resta sintonizzato!


**Fase 2: Demistificare il modulo**

Ecco il modulo evitamento ostacoli a infrarossi, il nostro intelligente compagno di bordo. Questo piccolo dispositivo è un concentrato di meraviglie. Facciamo un tour:

.. image:: img/ir_avoid.png
    :width: 300
    :align: center


Ecco le definizioni dei pin:

* **GND**: È come l'ancora del modulo, che lo collega a terra o al punto comune nel circuito.
* **+**: Qui è dove il modulo ottiene la sua energia, necessitando di un'alimentazione da 3,3 a 5V CC.
* **Out**: Questo è il comunicatore del modulo. Per impostazione predefinita, rimane alto e va basso solo quando rileva un ostacolo.
* **EN**: Ecco il controllore del modulo. Questo pin di **abilitazione** decide quando il modulo deve funzionare. Per impostazione predefinita, è collegato a GND, il che significa che il modulo è sempre in servizio.


Curioso di sapere come funziona questo piccolo modulo? È piuttosto interessante! Utilizza una coppia di componenti IR: un trasmettitore e un ricevitore. Il trasmettitore è come la torcia del modulo, che emette luce infrarossa.
Quando appare un ostacolo, la luce infrarossa rimbalza e viene catturata dal ricevitore. Il modulo quindi emette un segnale basso, avvisando il nostro rover dell'ostacolo.

.. image:: img/ir_receive.png
    :align: center

Il nostro piccolo modulo è piuttosto robusto, rilevando ostacoli entro un raggio di 2-40 cm e vantando eccellenti capacità anti-interferenza.
Tuttavia, il colore degli oggetti influisce sul suo rilevamento. Gli oggetti più scuri, specialmente quelli neri, vengono rilevati a una distanza più breve.
Contro un muro bianco, il sensore è più efficiente, rilevando entro il raggio di 2-30 cm.


Lo stato a livello basso del pin **EN** attiva il modulo, con il cappuccio jumper che fissa il pin **EN** a GND. Se desideri controllare il pin **EN** via codice, il cappuccio jumper deve essere rimosso.

.. image:: img/ir_cap.png
    :width: 400
    :align: center

Ci sono due potenziometri sul modulo, uno per regolare la potenza di trasmissione e uno per regolare la frequenza di trasmissione; regolando questi due potenziometri puoi regolare la sua distanza effettiva.

.. image:: img/ir_avoid_pot.png
    :width: 400
    :align: center


Questo è quanto sul nostro piccolo modulo. Nel prossimo passo, impareremo come integrarlo con il nostro rover e controllarlo usando Arduino. Resta sintonizzato!


**Fase 3: Leggere dai 2 moduli**

Proprio come curiosi esploratori spaziali, immergiamoci nell'universo dei codici e dei sensori!


#. Il nostro Mars Rover è equipaggiato con due speciali sensori "Occhi-Alieni", posizionati ordinatamente sui pin 7 (destro) e 8 (sinistro). Questi sensori "Occhi-Alieni" sono in realtà i nostri moduli evitamento ostacoli a infrarossi, sempre vigili per schivare qualsiasi "roccia spaziale" (ostacolo) nel viaggio interstellare del nostro Rover!

    .. image:: img/ir_shield.png

#. Successivamente, dovremo comunicare con il nostro Rover usando il linguaggio universale del codice Arduino.


    Per prima cosa, diamo un nome unico a ciascun occhio del Rover. Chiamiamoli ``IR_RIGHT`` e ``IR_LEFT``, così non li confonderemo.

        .. code-block:: arduino

            #define IR_RIGHT 7
            #define IR_LEFT 8

    Ora, facciamo sapere al nostro Rover che questi sono i suoi occhi speciali: invieranno informazioni dal mondo esterno al cervello elettronico del Rover.

        .. code-block:: arduino

            pinMode(IR_RIGHT, INPUT);
            pinMode(IR_LEFT, INPUT);


    Per assicurarci che il nostro Rover condivida le sue scoperte con noi, stabiliamo una linea di comunicazione segreta, come spie in un film di fantascienza. Questa prossima riga avvia una conversazione seriale alla velocità di 9600 bit al secondo: è una chiacchierata fulminea!

        .. code-block:: arduino

            Serial.begin(9600);


    Ora, il nostro Rover scansiona l'ambiente circostante con i suoi "Occhi-Alieni" e ci trasmette i risultati. Se individua un ostacolo, il valore sarà 0; se il percorso è libero, il valore sarà 1. Continua a inviarci questi messaggi, tenendoci informati.

        .. code-block:: arduino

            int rightValue = digitalRead(IR_RIGHT);
            int leftValue = digitalRead(IR_LEFT);
            Serial.print("Right IR: ");
            Serial.println(rightValue);
            Serial.print("Left IR: ");
            Serial.println(leftValue);


    Infine, il Rover si ferma per un momento (circa 200 millisecondi) dopo ogni trasmissione. Questa piccola pausa ci dà la possibilità di interpretare il messaggio del Rover prima che ne invii un altro.

        .. code-block:: arduino

            delay(200);

    Ecco il codice completo:

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/98546821-5f4b-42ae-bc9f-e7ec15544c8b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una volta che il tuo codice è pronto, seleziona la scheda e la porta corrette e trasmetti il codice al tuo Mars Rover. Poi, sintonizzati sulla nostra linea di comunicazione segreta (il Monitor Seriale) cliccando sulla sua icona nell'angolo in alto a destra.

    .. image:: img/ir_open_serial.png

#. Prima di iniziare a ricevere i messaggi del Rover, assicurati che la tua linea di comunicazione segreta sia sintonizzata alla stessa velocità (9600 baud) del tuo Rover. Ed ecco fatto: aggiornamenti in diretta dal tuo Mars Rover!

    .. image:: img/ir_serial.png

#. Per mettere alla prova il nostro sistema, agita una "roccia spaziale" (la tua mano) davanti a uno dei sensori. Vedrai il valore cambiare a 0 e il LED corrispondente sul modulo si illuminerà. È il Rover che dice: "Attenzione, roccia spaziale alla mia destra!"

    .. code-block::

        Right IR: 0
        Left IR: 1
        Right IR: 0
        Left IR: 1
        Right IR: 0
        Left IR: 1

Finora, non solo hai viaggiato nello spazio ma hai anche decifrato il marziano! Non vedo l'ora di scoprire quali segreti interstellari sveleremo nella nostra prossima missione!

**Fase 4: Regolazione della distanza di rilevamento**

Siamo arrivati a un passaggio essenziale, che consiste nel regolare le distanze di rilevamento dei nostri sensori in base al nostro ambiente attuale. Le impostazioni di fabbrica potrebbero non essere ottimali.

Se la distanza di rilevamento dei due moduli a infrarossi è troppo corta, il Mars Rover potrebbe scontrarsi con gli ostacoli. Se è troppo lunga, il Rover potrebbe iniziare a girare mentre è ancora a una distanza significativa da un ostacolo, influenzando potenzialmente il suo movimento.

Ecco come puoi effettuare le regolazioni:


#. Inizia regolando il modulo evitamento ostacoli destro. Durante il trasporto, le collisioni potrebbero far inclinare il trasmettitore e il ricevitore sul modulo a infrarossi. Pertanto, devi raddrizzarli manualmente.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Posiziona un ostacolo a circa 20 cm direttamente davanti al modulo destro. La scatola in cui è arrivato il nostro kit Rover è una buona scelta per questo! Ora, gira il potenziometro sul modulo finché la spia indicatrice sul modulo si accende appena. Quindi, continua a muovere l'ostacolo avanti e indietro per verificare se la spia si accende alla distanza desiderata. Se la spia non si accende alla distanza corretta o se rimane accesa senza spegnersi, dovrai regolare l'altro potenziometro.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>


#. Ripeti lo stesso processo per l'altro modulo.

Ora che i nostri sensori sono completamente preparati, imbarchiamoci nel prossimo viaggio!

**Fase 5: Progettare un sistema automatico di evitamento ostacoli**

Ora, facciamo un grande salto nella nostra esplorazione spaziale e utilizziamo questi messaggi dal Rover.
Creeremo un sistema automatico di evitamento ostacoli!

Ecco il nostro piano: Se il sensore destro rileva un ostacolo, il Rover girerà verso destra all'indietro. Se il sensore sinistro rileva un ostacolo, il Rover girerà verso sinistra all'indietro. Se entrambi i sensori rilevano un ostacolo, il Rover si muoverà all'indietro. Se non vengono rilevati ostacoli, il Rover continuerà ad andare dritto.

Visualizziamolo in un diagramma di flusso per renderlo ancora più chiaro. I diagrammi di flusso sono un ottimo modo per delineare logicamente un piano, specialmente quando si tratta di programmazione!

.. image:: img/ir_flowchart.png

Sussurriamo questo piano al nostro Rover nella sua lingua (codice Arduino):

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/af6539d4-7b4b-4e74-a04a-9fa069391d4d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

In questo codice, stiamo usando l'istruzione ``if...else`` nella funzione ``loop()``.

    L'istruzione ``if...else`` viene utilizzata per eseguire un blocco di codice tra due alternative.
    Tuttavia, quando dobbiamo scegliere tra più di due alternative, usiamo l'istruzione ``if...else if...else``.

    La sintassi dell'istruzione ``if...else if...else`` è:

    .. code-block:: arduino

        if (condition1) {
        // code block 1
        }
        else if (condition2){
        // code block 2
        }
        else if (condition3){
        // code block 3
        }
        else {
        // code block 4
        }

    Qui,

    * Se condition1 è vera, viene eseguito il blocco di codice 1.
    * Se condition1 è falsa, allora viene valutata condition2.
    * Se condition2 è vera, viene eseguito il blocco di codice 2.
    * Se condition2 è falsa, allora viene valutata condition3.
    * Se condition3 è vera, viene eseguito il blocco di codice 3.
    * Se condition3 è falsa, viene eseguito il blocco di codice 4.

Ora che abbiamo progettato il nostro sistema automatico di evitamento ostacoli, è il momento della parte emozionante: metterlo alla prova!

* Puoi osservare se il Rover si muove come ti aspettavi.
* Oppure, posizionalo in diverse condizioni di illuminazione per vedere come cambiano i suoi movimenti.

Integrando la scienza nel nostro progetto ingegneristico, stiamo diventando detective spaziali, risolvendo i misteri del comportamento del nostro Rover.
Non si tratta solo di correggere errori ma di ottimizzare le prestazioni, rendendo il nostro Rover il migliore possibile! Continuate con l'ottimo lavoro, detective spaziali!


**Fase 6: Riflessione e riepilogo**

Nella fase di test, potresti aver notato un comportamento interessante del nostro Mars Rover: mentre evita abilmente gli ostacoli a sinistra e a destra, potrebbe avere difficoltà a rilevare ostacoli più piccoli direttamente davanti a sé.

Come possiamo risolvere questa sfida?

Resta sintonizzato per la prossima lezione, dove continueremo la nostra esplorazione nell'affascinante mondo della codifica, dei sensori e del rilevamento ostacoli.

Ricorda, ogni sfida è un'opportunità di apprendimento e innovazione. E mentre continuiamo il nostro viaggio di esplorazione spaziale, c'è ancora molto da scoprire e imparare!
