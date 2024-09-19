.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato alle novità sui prodotti e alle anteprime.
    - **Sconti esclusivi**: Approfitta di sconti riservati sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa ai giveaway e alle promozioni speciali.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!


Lezione 4: Padronanza del Motore TT
========================================

Nelle lezioni precedenti, abbiamo esplorato i rover marziani, i loro sistemi di sospensione e acquisito conoscenze sull'Arduino.

In questo corso entusiasmante, esploreremo il funzionamento dei motori, un componente chiave che alimenta i rover marziani. 
Comprenderemo i principi che alimentano questi motori e impareremo a controllarli utilizzando la scheda SunFounder R3 e uno scudo GalaxyRVR.

Alla fine di questo corso, avrai una solida comprensione del funzionamento dei motori e avrai acquisito esperienza pratica nel controllo dei motori.

Immergiamoci!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/left_1.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::

    Se stai seguendo questo corso dopo aver completato l'assemblaggio del GalaxyRVR, devi spostare questo interruttore a destra prima di caricare il codice.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Obiettivi del Corso
-------------------------
* Comprendere i principi di base dei motori e le caratteristiche del motore TT.
* Imparare a controllare la direzione e la velocità del motore TT.
* Comprendere come lo scudo GalaxyRVR controlla sei motori.


Materiali del Corso
-----------------------

* Scheda SunFounder R3
* Motore TT
* Scudo GalaxyRVR
* Batteria
* Cavo USB
* Arduino IDE
* Computer

Fasi del Corso
------------------

**Fase 1: Cos'è un Motore?**

I motori sono parte integrante della nostra vita quotidiana. Sono ovunque! Dai ventilatori elettrici che ci rinfrescano nelle giornate calde, ai frullatori che ci aiutano a preparare deliziose torte, fino alle auto elettriche che sfrecciano per le strade: i motori fanno muovere le cose!

.. image:: img/motor_application.jpg

Un motore è come il cuore di una macchina. Converte l'energia elettrica in energia meccanica, dando vita ai nostri giocattoli, elettrodomestici e persino ai grandi veicoli!

La magia dietro un motore non è affatto magia: è scienza, più precisamente il principio dell'induzione elettromagnetica. Ecco come funziona: quando si fornisce elettricità a un motore, si genera un campo magnetico. Questo campo magnetico interagisce con altri magneti all'interno del motore, facendolo girare. Questa rotazione, simile a quella di una trottola, può essere utilizzata per muovere ruote, eliche o altre parti in movimento di una macchina.

.. image:: img/motor_rotate.gif
    :align: center

Il tipo di motore su cui ci concentreremo nel nostro GalaxyRVR è un tipo specifico chiamato TT Gear Motor.

.. image:: img/tt_motor_xh.jpg
    :align: center
    :width: 400

Questo è essenzialmente un motore normale combinato con una serie di ingranaggi, tutti racchiusi in un guscio di plastica.

Quando il motore gira, gli ingranaggi trasferiscono questa rotazione alle ruote del nostro rover. L'uso degli ingranaggi offre un vantaggio cruciale: aumenta la coppia, consentendo al motore di spostare carichi più grandi e pesanti.

.. image:: img/motor_internal.gif
    :align: center
    :width: 600

Non è affascinante vedere come i principi della scienza e dell'ingegneria prendano vita? I motori sono un perfetto esempio di questi principi in azione. Capendo come funzionano i motori, possiamo immaginare e inventare una vasta gamma di macchine. Approfondiamo il mondo dei motori e liberiamo la nostra creatività!
**Passo 2: Esplorare il Funzionamento e l'Operazione del Motore**

Dopo aver compreso cos'è un motore e le sue ampie applicazioni, è il momento di addentrarci nel cuore del suo funzionamento.

Essenzialmente, un motore funziona secondo il principio dell'elettromagnetismo. Quando una corrente elettrica passa attraverso un filo, genera un campo magnetico intorno ad esso. Questo campo magnetico può interagire con altri campi magnetici, generando movimento.

Consideriamo un esperimento semplice in cui colleghiamo un motore direttamente a una batteria. La corrente proveniente dalla batteria fluisce nel motore, attivando il meccanismo interno del motore e facendolo girare. Questo movimento di rotazione è dovuto alle forze magnetiche all'interno del motore.

    .. image:: img/motor_battery.png

Curiosamente, se inverti le connessioni alla batteria, il motore girerà nella direzione opposta! Questo accade perché il flusso di corrente cambia direzione, alterando il campo magnetico e, di conseguenza, la direzione di rotazione del motore.

Ora sappiamo che collegare il motore direttamente a una batteria lo fa girare, ma spesso vogliamo controllare il suo movimento tramite codice, quindi includiamo una scheda Arduino tra i due. Ma cosa succederebbe se provassimo a collegare il motore direttamente ai pin di segnale della scheda Arduino?

.. image:: img/motor_uno.png
    :width: 600
    :align: center

Se hai indovinato che il motore non girerebbe, hai ragione! Ma perché?

La risposta sta nell'uscita di corrente della scheda Arduino. I pin di segnale su una tipica scheda Arduino possono emettere solo circa 20mA di corrente, che non è sufficiente per far girare un motore.

Quindi, come possiamo controllare i motori utilizzando Arduino? È qui che entra in gioco un componente cruciale: il driver del motore. Pensa al driver del motore come a un ponte tra l'Arduino e il motore. Prende il segnale di controllo a bassa corrente dall'Arduino, lo amplifica e lo invia al motore, permettendogli così di girare.

.. image:: img/motor_uno2.png

Nel prossimo passo, esamineremo i dettagli del driver del motore e capiremo come utilizzarlo efficacemente con la nostra scheda Arduino per controllare un motore. Resta sintonizzato per ulteriori scoperte interessanti!


**Passo 3: Come il Motore viene controllato dal Driver del Motore**

Il nostro GalaxyRVR Shield, incluso nel kit, funge da centro di controllo per il nostro Mars Rover. È l'hub in cui colleghiamo tutti i sensori, i motori e l'alimentazione. Consiste di vari componenti che ci permettono di controllare e alimentare efficacemente il nostro Rover.

Sul lato destro dello shield, noterai sei porte per motori. Tuttavia, sono raggruppate in due serie, ciascuna controllata da un chip di controllo motore separato. Tre porte contrassegnate con "Left" sono controllate da un chip, mentre le altre tre porte contrassegnate con "Right" sono controllate da un altro chip.

.. image:: img/motor_shield.png

Impariamo come questi due chip di controllo gestiscono i sei motori attraverso un'esperienza pratica:

* **1. Collegare il Circuito**

    #. Collega lo Shield GalaxyRVR alla scheda R3, collega un motore e infine collega la batteria per fornire energia alla scheda di espansione.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/connect_shield.mp4" type="video/mp4">
                Il tuo browser non supporta il tag video.
            </video>

    #. Alla prima accensione, si consiglia di collegare un cavo USB Type-C per caricare completamente la batteria. Successivamente, accendi l'alimentazione.
    
        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/plug_usbc.mp4" type="video/mp4">
                Il tuo browser non supporta il tag video.
            </video>

* **2. Scrivere e Caricare il Codice**

    #. Apri Arduino IDE e inserisci il seguente codice:

        .. code-block:: arduino

            void setup() {
                pinMode(2, OUTPUT);
                pinMode(3, OUTPUT);
            }

            void loop() {
                digitalWrite(2, LOW);
                digitalWrite(3, HIGH);
            }
    
        * ``pinMode()``: Questa funzione imposta un pin come INPUT o OUTPUT, simile a decidere se un personaggio nella nostra storia parla (OUTPUT) o ascolta (INPUT).
        * ``digitalWrite()``: Questa funzione può impostare un pin su HIGH (acceso) o LOW (spento), proprio come accendere o spegnere una luce magica.

#. Una volta selezionata la scheda corretta (Arduino Uno) e la porta, clicca sul pulsante **Upload**. È come mettere una lettera in una cassetta postale: stai inviando le tue istruzioni ad Arduino!

    .. image:: img/motor_upload.png
        
#. Una volta che il codice è stato caricato con successo, vedrai il motore iniziare a ruotare in senso orario.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/left_1.mp4" type="video/mp4">
                Your browser does not support the video tag.
        </video>

* **3. Connessione interna del circuito**

    #. Puoi collegare altri due motori alle porte contrassegnate "Left". Vedrai che ruotano simultaneamente.

    #. Ora, comprendiamo il semplice principio di come i due chip di controllo gestiscono i sei motori. I pin 2 e 3 della scheda Arduino inviano segnali al chip di controllo del motore, e l'altra estremità del chip è collegata a tre motori in parallelo. Allo stesso modo, i pin 4 e 5 inviano segnali a un altro chip di controllo, che a sua volta è collegato ad altri tre motori in parallelo.

        .. image:: img/motor_driver.png
            :width: 500

    #. Se desideri testare un altro chip di controllo, basta cambiare i pin in ``4`` e ``5``.

        .. code-block:: arduino
            :emphasize-lines: 10,11

            const int in3 = 4;
            const int in4 = 5;

            void setup() {
                pinMode(in3, OUTPUT);
                pinMode(in4, OUTPUT);
            }

            void loop() {
                digitalWrite(in3, LOW);
                digitalWrite(in4, HIGH);
            }

        Qui definiamo due variabili per rappresentare i pin 4 e 5. Usare variabili ci permette di gestire facilmente e regolare gli assegnamenti dei pin nel nostro codice.

        È come assegnare un ruolo specifico a ciascun numero di pin. Quando decidiamo di riassegnare i ruoli, invece di cambiare ogni istanza nello script, modifichiamo semplicemente l'assegnazione all'inizio del codice (dove la variabile è inizialmente definita).


* **4. Logica di controllo**

    #. Nei test precedenti, avrai notato che i motori ruotano tutti in una direzione. Come possiamo farli ruotare nella direzione opposta? Qualcuno potrebbe suggerire di invertire HIGH e LOW dei due pin. Ed è corretto.

        .. code-block:: arduino
            :emphasize-lines: 1,2

            const int in3 = 4;
            const int in4 = 5;

            void setup() {
                pinMode(in3, OUTPUT);
                pinMode(in4, OUTPUT);
            }

            void loop() {
                digitalWrite(in3, HIGH);
                digitalWrite(in4, LOW);
            }

        Una volta che avrai scritto il codice e caricato sulla scheda Arduino, il motore si comporterà secondo le istruzioni.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/right_cc.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    #. Ora, vediamo la logica interna di controllo del chip.

        .. list-table::
            :widths: 25 25 50
            :header-rows: 1

            * - INA
              - INB
              - Motore
            * - L
              - L
              - Standby
            * - L
              - H
              - Senso orario
            * - H
              - L
              - Senso antiorario
            * - H
              - H
              - Freno
    
    #. Ora, proviamo a far ruotare il motore in senso orario per 2 secondi, in senso antiorario per 2 secondi e poi fermarlo.

        .. code-block:: arduino
            :emphasize-lines: 10,11,12,13,14,15,16,17,18

            const int in3 = 4;
            const int in4 = 5;
            
            void setup() {
                pinMode(in3, OUTPUT);
                pinMode(in4, OUTPUT);
            }
            
            void loop() {
                digitalWrite(in3, LOW);
                digitalWrite(in4, HIGH);
                delay(2000);
                digitalWrite(in3, HIGH);
                digitalWrite(in4, LOW);
                delay(2000);
                digitalWrite(in3, HIGH);
                digitalWrite(in4, HIGH);
                delay(5000);
            }

        * Qui utilizziamo la funzione ``delay()`` per fare in modo che Arduino si fermi per un certo periodo di tempo, come se facesse un breve riposo nel bel mezzo della nostra storia.
        * Nel codice, usiamo lo stato "Freno" per fermare il motore, e noterai che il motore si ferma bruscamente. Prova a impostare entrambi i pin su LOW per testare lo stato "Standby" e noterai che il motore rallenta gradualmente fino a fermarsi.

Ora dovresti avere una comprensione migliore di come il chip di controllo del motore gestisce i motori attraverso lo scudo GalaxyRVR e di come possiamo utilizzare il codice Arduino per manipolare i movimenti del motore. Non è affascinante come poche righe di codice possano dettare il comportamento di un oggetto fisico come il nostro motore?

Considera le seguenti domande man mano che procedi:

* Se spostiamo tutto il codice dalla funzione ``loop()`` alla funzione ``setup()``, come cambierebbe il comportamento del motore?
* Come modificheresti il codice per controllare sei motori contemporaneamente?

Ricorda, più sperimenti e giochi con il tuo codice, più impari. Sentiti libero di apportare modifiche, ottimizzazioni e personalizzazioni al codice come ritieni opportuno. Buona programmazione!


**Fase 4: Controllo della velocità del motore**

Nel passaggio precedente, abbiamo controllato la direzione del motore semplicemente impostando i suoi pin su HIGH o LOW. 
Questo è come dare al motore la massima potenza per farlo funzionare, simile a premere il pedale dell'acceleratore a fondo in un'auto. 
Ma in molte situazioni, potremmo voler regolare la velocità del motore per adattarlo a scenari diversi, 
proprio come regoliamo la velocità di un'auto a seconda che stiamo guidando in città o in autostrada. 
Qui entra in gioco la modulazione della larghezza di impulso (PWM).
.. image:: img/motor_pwm.jpg

La modulazione della larghezza di impulso (PWM) è una tecnica utilizzata per creare l'effetto di un'uscita di tensione variabile, alternando rapidamente tra HIGH e LOW. 
Con il PWM, possiamo simulare l'effetto di un segnale analogico utilizzando esclusivamente segnali digitali.

Potrebbe sembrare complicato da comprendere, e va bene così! Impareremo come regolare la velocità del motore utilizzando il PWM attraverso il codice nelle sezioni seguenti.

Nota che, sebbene la scheda SunFounder R3 abbia alcuni pin con funzionalità PWM integrate, non possiamo utilizzarli per il nostro motore perché sono già assegnati ad altre funzioni. Pertanto, colleghiamo i driver ai pin 2, 3, 4 e 5, utilizzando la libreria SoftPWM di Arduino per abilitare il PWM su questi pin.

Ecco cosa faremo dopo:

#. Apri Arduino IDE, cerca ``softpwm`` nel **LIBRARY MANAGER** e installala.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Inserisci il seguente codice in Arduino IDE. Dopo aver caricato correttamente il codice, il motore ruoterà in senso orario.

    .. code-block:: arduino
        :emphasize-lines: 1, 7,11,12

        #include <SoftPWM.h>

        const int in1 = 2;
        const int in2 = 3;

        void setup() {
            SoftPWMBegin();
        }

        void loop() {
            SoftPWMSet(in1, 0);
            SoftPWMSet(in2, 255);

        }

    * Nel codice sopra, aggiungiamo prima ``SoftPWM.h`` all'inizio del codice, permettendoci di utilizzare direttamente le funzioni della libreria ``SoftPWM``.
    * Poi, inizializziamo la libreria ``SoftPWM`` con la funzione ``SoftPWMBegin()``.
    * Infine, nella funzione ``loop()``, utilizziamo ``SoftPWMSet()`` per assegnare valori diversi a ``in1`` e ``in2``, mettendo in moto il motore. Noterai che l'effetto è simile all'uso diretto di ``LOW`` e ``HIGH``, ma qui utilizziamo valori numerici in un intervallo tra ``0~255``.
    * Ricorda, nel mondo di Arduino, la velocità è espressa come un valore compreso tra 0 (come un'auto ferma al semaforo) e 255 (sfrecciando in autostrada!). Quindi, quando diciamo ``SoftPWMSet(in2, 255)``, stiamo dicendo al motore di andare alla massima velocità!

#. Ora, inseriamo altri valori e osserviamo le differenze nella velocità del motore.

    .. code-block:: arduino
        :emphasize-lines: 12,13,14,15

        #include <SoftPWM.h>

        const int in1 = 2;
        const int in2 = 3;

        void setup() {
            SoftPWMBegin();
        }

        void loop() {
            SoftPWMSet(in1, 0);
            for (int i = 0; i <= 255; i++) {
                SoftPWMSet(in2, i);
                delay(100);
        }
            delay(1000);
        }

    Nel codice sopra, utilizziamo un ciclo ``for`` per incrementare una variabile ``i`` fino a ``255``. Il ciclo ``for`` nel linguaggio C è usato per iterare su una parte del programma diverse volte. Consiste di tre parti:

    .. image:: img/motor_for123.png
        :width: 400
        :align: center

    * **Inizializzazione**: Questo passaggio viene eseguito per primo e solo una volta quando entriamo nel ciclo per la prima volta. Ci permette di dichiarare e inizializzare eventuali variabili di controllo del ciclo.
    * **Condizione**: Questo è il passaggio successivo all'inizializzazione. Se è vero, il corpo del ciclo viene eseguito. Se è falso, il corpo del ciclo non viene eseguito e il flusso di controllo esce dal ciclo for.
    * **Incremento o decremento**: Dopo aver eseguito i passaggi di Inizializzazione e Condizione e il codice del corpo del ciclo, viene eseguito il passaggio di Incremento o Decremento. Questa istruzione ci permette di aggiornare eventuali variabili di controllo del ciclo.

    Il diagramma di flusso per il ciclo for è mostrato di seguito:

    .. image:: img/motor_for.png

    Dopo aver eseguito il codice sopra, vedrai la velocità del motore aumentare gradualmente. Si fermerà per un secondo, quindi ripartirà da 0 e aumenterà di nuovo gradualmente.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/left_speed.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

In questo passaggio, abbiamo imparato la tecnica della modulazione della larghezza di impulso (PWM) per controllare la velocità del nostro motore. Utilizzando la libreria SoftPWM di Arduino, possiamo regolare la velocità del motore, permettendoci di simulare segnali analogici mentre emettiamo solo segnali digitali. Questo ci fornisce un controllo più fine sui movimenti del nostro rover, preparandoci per manovre più complesse in futuro.

**Step 5: Riflettere e Migliorare**

Completata questa lezione, dovresti ora essere familiare con i principi di funzionamento dei motori, nonché con il modo di controllarne la direzione e la velocità tramite la programmazione.

Metti alla prova la tua comprensione con queste sfide:

* Come modificheresti il ciclo for per diminuire gradualmente la velocità del motore?
* Come controlleresti il motore per accelerare o decelerare durante la rotazione in senso antiorario?

Puoi sperimentare con il codice fornito per rispondere a queste domande. Sentiti libero di regolare il codice in base alle tue ipotesi e osserva i cambiamenti nel comportamento del motore.

I tuoi esperimenti pratici e le riflessioni su queste domande approfondiranno la tua comprensione e miglioreranno le tue capacità di risoluzione dei problemi. È attraverso sfide come queste che avviene il vero apprendimento. Ricorda sempre, non ci sono "risposte giuste o sbagliate" nel tuo percorso di esplorazione: tutto riguarda l'apprendimento e la scoperta!
