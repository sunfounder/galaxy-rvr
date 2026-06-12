.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Lezione 4: Padroneggiare il motore TT
=====================================

Nelle lezioni precedenti, abbiamo esplorato i rover marziani, i loro sistemi di sospensione e approfondito la conoscenza di Arduino.

In questo entusiasmante corso, esploreremo il funzionamento dei motori, un componente chiave che aziona i rover marziani.
Comprenderemo i principi che alimentano questi motori e impareremo a controllarli usando la scheda SunFounder R3 e un GalaxyRVR Shield.

Alla fine di questo corso, avrai una solida comprensione del funzionamento dei motori e un'esperienza pratica nel controllo motori.

Iniziamo!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/left_1.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::

    Se stai seguendo questo corso dopo aver completamente assemblato il GalaxyRVR, devi spostare questo interruttore a destra prima di caricare il codice.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Obiettivi del corso
----------------------
* Comprendere i principi di base dei motori e le caratteristiche del motore TT.
* Imparare a controllare la direzione e la velocità del motore TT.
* Comprendere come il GalaxyRVR Shield controlla sei motori.


Materiali del corso
-----------------------

* Scheda SunFounder R3
* Motore TT
* GalaxyRVR Shield
* Batteria
* Cavo USB
* Arduino IDE
* Computer

Procedura del corso
-------------------

**Fase 1: Cos'è un motore?**

I motori giocano un ruolo fondamentale nella nostra vita quotidiana. Sono ovunque! Dai ventilatori elettrici che ci rinfrescano nelle giornate calde, ai mixer che ci aiutano a fare torte deliziose, alle auto elettriche che sfrecciano per le strade: i motori fanno muovere le cose!

.. image:: img/motor_application.jpg

Un motore è come il cuore di una macchina. Converte l'energia elettrica in energia meccanica, dando vita ai nostri giocattoli, elettrodomestici e persino ai grandi veicoli!


La magia dietro un motore non è affatto magia: è scienza, in particolare il principio dell'induzione elettromagnetica. Ecco come funziona: quando l'elettricità viene fornita a un motore, genera un campo magnetico. Questo campo magnetico interagisce poi con altri magneti all'interno del motore, facendo girare il motore. Questa rotazione, come far girare una trottola, può poi essere usata per muovere ruote, eliche o qualsiasi altra parte mobile di una macchina.

.. image:: img/motor_rotate.gif
    :align: center

Il tipo di motore su cui ci concentriamo nel nostro GalaxyRVR è un tipo specifico chiamato motore TT a ingranaggi.

.. image:: img/tt_motor_xh.jpg
    :align: center
    :width: 400

È essenzialmente un motore normale combinato con una serie di ingranaggi, il tutto racchiuso in un guscio di plastica.

Mentre il motore gira, gli ingranaggi trasmettono questa rotazione alle ruote del nostro rover. L'uso degli ingranaggi fornisce un vantaggio cruciale: aumenta la coppia, permettendo al motore di muovere carichi più grandi e pesanti.

.. image:: img/motor_internal.gif
    :align: center
    :width: 600

Non è affascinante vedere come i principi della scienza e dell'ingegneria prendono vita? I motori sono un perfetto esempio di questi principi in azione. Comprendendo come funzionano i motori, possiamo immaginare e inventare una vasta gamma di macchine. Immergiamoci più a fondo nel mondo dei motori e liberiamo la nostra creatività!


**Fase 2: Esplorare il funzionamento e l'operatività del motore**

Avendo capito cos'è un motore e il suo ampio spettro di applicazioni, è tempo di avventurarci nel cuore del funzionamento del motore.

In sostanza, un motore funziona sul principio dell'elettromagnetismo. Quando una corrente elettrica passa attraverso un filo, genera un campo magnetico intorno ad esso. Questo campo magnetico può interagire con altri campi magnetici, causando movimento.

Considera un semplice esperimento in cui colleghiamo un motore direttamente a una batteria. La corrente dalla batteria fluisce nel motore, innescando il meccanismo interno del motore per iniziare a girare. Questa azione rotante è dovuta alle forze magnetiche all'interno del motore.

    .. image:: img/motor_battery.png

È interessante notare che se inverti i collegamenti alla batteria, il motore gira nella direzione opposta! Questo accade perché la direzione del flusso di corrente cambia, alterando la direzione del campo magnetico e di conseguenza la direzione di rotazione del motore.

Ora sappiamo che collegare il motore direttamente a una batteria può farlo girare, ma spesso vogliamo controllare il suo movimento con il codice, quindi includiamo una scheda Arduino tra di loro. Ma cosa succederebbe se provassimo a collegare il motore direttamente ai pin di segnale sulla scheda Arduino?

.. image:: img/motor_uno.png
    :width: 600
    :align: center

Se hai indovinato che il motore non girerebbe, hai ragione! Ma perché?

La risposta sta nell'uscita di corrente della scheda Arduino. I pin di segnale su una tipica scheda Arduino possono emettere solo circa 20mA di corrente, che è insufficiente per azionare un motore.

Quindi, come possiamo controllare i motori usando il nostro Arduino? È qui che entra in gioco un componente cruciale: un driver per motori. Pensa a un driver per motori come a un ponte tra Arduino e il motore. Prende il segnale di controllo a bassa corrente da Arduino, lo amplifica e lo invia al motore, permettendo così al motore di girare.

.. image:: img/motor_uno2.png

Nel nostro prossimo passo, approfondiremo le specifiche del driver per motori e capiremo come possiamo usarlo efficacemente con la nostra scheda Arduino per controllare un motore. Resta sintonizzato per un apprendimento ancora più entusiasmante!


**Fase 3: Come il motore è controllato dal driver per motori**

Il nostro GalaxyRVR Shield, incluso nel kit, funge da centro di controllo per il nostro Mars Rover. È l'hub dove colleghiamo tutti i nostri sensori, motori e alimentazione. È composto da diversi componenti che ci permettono di controllare e alimentare efficacemente il nostro Rover.

Sul lato destro dello shield, noterai sei porte motore. Tuttavia, sono raggruppate in due set, ciascuno controllato da un chip driver motore separato. Tre porte contrassegnate "Left" sono controllate da un chip, e le altre tre porte contrassegnate "Right" sono controllate da un altro.

.. image:: img/motor_shield.png

Impariamo come questi due chip driver controllano i sei motori attraverso l'esperienza pratica:

* **1. Collegamento del circuito**

    #. Inserisci il GalaxyRVR Shield nella scheda R3, collega un motore e infine collega la batteria per fornire alimentazione alla scheda di espansione.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/connect_shield.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    #. Al primo utilizzo, si consiglia di collegare un cavo USB Type-C per caricare completamente la batteria. Poi accendi l'alimentazione.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/plug_usbc.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

* **2. Scrittura e caricamento del codice**

    #. Apri l'IDE Arduino e inserisci il seguente codice:

        .. code-block:: arduino

            void setup() {
                pinMode(2, OUTPUT);
                pinMode(3, OUTPUT);
            }

            void loop() {
                digitalWrite(2, LOW);
                digitalWrite(3, HIGH);
            }

        * ``pinMode()``: Questa funzione imposta un pin come INPUT o OUTPUT, come decidere se un personaggio nella nostra storia parla (OUTPUT) o ascolta (INPUT).
        * ``digitalWrite()``: Questa funzione può impostare un pin HIGH (acceso) o LOW (spento), come accendere e spegnere una luce magica.

    #. Una volta selezionati la scheda corretta (Arduino Uno) e la porta, clicca sul pulsante **Upload**. È come mettere una lettera in una cassetta postale: stai inviando le tue istruzioni ad Arduino!

        .. image:: img/motor_upload.png

    #. Una volta che il codice è stato caricato con successo, vedrai il motore iniziare a ruotare in senso orario.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/left_1.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

* **3. Connessione interna del circuito**

    #. Puoi collegare altri due motori nelle porte motore contrassegnate "Left". Li vedrai ruotare simultaneamente.

    #. Ora, comprendiamo il semplice principio di come i due chip driver controllano i sei motori. I pin 2 e 3 sulla scheda Arduino emettono segnali al chip driver motore, e l'altra estremità del chip è collegata a tre motori in parallelo. Allo stesso modo, i pin 4 e 5 emettono segnali a un altro chip driver, che a sua volta è collegato ad altri tre motori in parallelo.

        .. image:: img/motor_driver.png
            :width: 500

    #. Se vuoi testare un altro chip driver, devi solo cambiare i pin in ``4`` e ``5``.

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

        Qui definiamo due variabili per rappresentare i pin 4 e 5. Usando le variabili, possiamo gestire e regolare facilmente le nostre assegnazioni di pin in tutto il codice.

        Pensalo come se stessimo assegnando un ruolo o dovere specifico a ciascun numero di pin. Quando decidiamo di riassegnare i ruoli, invece di scorrere l'intero script e cambiare ogni istanza, aggiorniamo semplicemente l'assegnazione all'inizio dello script (dove la variabile è inizialmente definita).


* **4. Logica di pilotaggio**

    #. Nei test precedenti, avrai notato che i motori girano tutti in una direzione. Come facciamo a farli girare nella direzione opposta? Qualcuno potrebbe suggerire di scambiare HIGH e LOW dei due pin. È corretto.

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

        Una volta scritto il codice e caricato sulla tua scheda Arduino, il motore si comporterà come istruito.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/right_cc.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    #. Ora diamo un'occhiata alla logica di pilotaggio interna del chip driver.

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
              - Orario
            * - H
              - L
              - Antiorario
            * - H
              - H
              - Frenata

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

        * Qui usiamo la funzione ``delay()`` per far fare ad Arduino una pausa per un certo periodo di tempo, come fare un breve pisolino nel mezzo della nostra storia.
        * Nel codice, usiamo lo stato "Brake" (frenata) per fermare il motore, e noterai che il motore si ferma bruscamente. Prova a impostare entrambi i pin su LOW per testare lo stato "Standby", e scoprirai che il motore rallenta gradualmente fino a fermarsi.

Ora dovresti avere una migliore comprensione di come il chip driver motore controlla i motori attraverso il GalaxyRVR Shield e come possiamo usare il codice Arduino per manipolare i movimenti del motore. Non è affascinante come poche righe di codice possano dettare il comportamento di un oggetto fisico come il nostro motore?

Considera le seguenti domande mentre procedi:

* Se spostassimo tutto il codice dalla funzione ``loop()`` alla funzione ``setup()``, come cambierebbe il comportamento del motore?
* Come modificheresti il codice per controllare sei motori simultaneamente?

Ricorda, più sperimenti e giochi con il tuo codice, più impari. Sentiti libero di modificare, ritoccare e ottimizzare il tuo codice come meglio credi. Buona programmazione!


**Fase 4: Controllo della velocità del motore**

Nel passo precedente, abbiamo controllato la direzione del motore semplicemente impostando i suoi pin su HIGH o LOW.
È come dare al motore piena potenza per azionarlo, simile a premere il pedale dell'acceleratore a fondo in un'auto.
Ma in molte situazioni, potremmo voler regolare la velocità del motore per adattarla a diversi scenari,
proprio come regoliamo la velocità di un'auto a seconda che stiamo guidando in città o in autostrada.
È qui che entra in gioco la Modulazione a Larghezza di Impulso (PWM).

.. image:: img/motor_pwm.jpg

La PWM è una tecnica utilizzata per creare l'effetto di un'uscita di tensione variabile commutando rapidamente l'uscita tra HIGH e LOW.
Con la PWM, possiamo simulare l'effetto di un segnale analogico mentre in realtà emettiamo solo segnali digitali.

Potresti trovare difficile da capire, e va bene così! Impareremo come regolare la velocità del motore usando la PWM attraverso la codifica nelle sezioni seguenti.

Nota che sebbene la scheda SunFounder R3 abbia alcuni pin con funzionalità PWM integrata, non possiamo usarli per il nostro motore perché stanno già servendo altre funzioni. Quindi, colleghiamo i chip driver ai pin 2, 3, 4 e 5, e usiamo la libreria SoftPWM di Arduino per abilitare la PWM su questi pin.

Ecco cosa faremo dopo:

#. Apri l'IDE Arduino, cerca ``softpwm`` nel **LIBRARY MANAGER** e installalo.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Inserisci il seguente codice nell'IDE Arduino. Dopo aver caricato il codice con successo, il motore ruoterà in senso orario.

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

    * Nel codice sopra, aggiungiamo prima ``SoftPWM.h`` all'inizio del codice, permettendoci di usare direttamente le funzioni nella libreria ``SoftPWM``.
    * Poi, inizializziamo la libreria ``SoftPWM`` con la funzione ``SoftPWMBegin()``.
    * Infine, nella funzione ``loop()``, usiamo ``SoftPWMSet()`` per assegnare valori diversi a ``in1`` e ``in2``, mettendo il motore in movimento. Noterai che l'effetto è simile all'uso diretto di ``LOW`` e ``HIGH``, ma qui usiamo valori numerici in un intervallo di ``0~255``.
    * Ricorda, nel mondo di Arduino, la velocità è espressa come un valore tra 0 (come un'auto a un segnale di stop) e 255 (sfrecciando in autostrada!). Quindi, quando diciamo ``SoftPWMSet(in2, 255)``, stiamo dicendo a quel motore di andare a tutta velocità!

#. Ora, inseriamo altri valori e osserviamo eventuali differenze nella velocità del motore.

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

    Nel codice sopra, usiamo un ciclo ``for`` per incrementare una variabile ``i`` fino a ``255``. Il ciclo ``for`` nel linguaggio C è usato per iterare su una parte del programma diverse volte. È composto da tre parti:

    .. image:: img/motor_for123.png
        :width: 400
        :align: center

    * **Inizializzazione**: Questo passo viene eseguito per primo e solo una volta quando entriamo nel ciclo per la prima volta. Ci permette di dichiarare e inizializzare qualsiasi variabile di controllo del ciclo.
    * **Condizione**: Questo è il passo successivo dopo l'inizializzazione. Se è vera, il corpo del ciclo viene eseguito. Se è falsa, il corpo del ciclo non viene eseguito e il flusso di controllo esce dal ciclo for.
    * **Incremento o Decremento**: Dopo aver eseguito i passi di Inizializzazione e Condizione e il codice del corpo del ciclo, il passo di Incremento o Decremento viene eseguito. Questa istruzione ci permette di aggiornare qualsiasi variabile di controllo del ciclo.

    Il diagramma di flusso per il ciclo for è mostrato di seguito:

    .. image:: img/motor_for.png

    Quindi, dopo aver eseguito il codice sopra, vedrai la velocità del motore aumentare gradualmente. Si ferma per un secondo, e poi ricomincia da 0 e aumenta gradualmente.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/left_speed.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

In questo passo, abbiamo imparato la Modulazione a Larghezza di Impulso (PWM), una tecnica per controllare la velocità del nostro motore. Usando la libreria SoftPWM di Arduino, possiamo regolare la velocità del motore, permettendoci di simulare segnali analogici emettendo solo segnali digitali. Questo ci fornisce un controllo più fine sui movimenti del nostro rover e ci prepara per manovre più complesse in futuro.

**Fase 5: Rifletti e migliora**

Dopo aver completato questa lezione, dovresti ora avere familiarità con i principi di funzionamento dei motori, così come come controllare la loro direzione e velocità attraverso la programmazione.

Mettiamo alla prova la tua comprensione con queste sfide:

* Come modificheresti il ciclo for per diminuire gradualmente la velocità del motore?
* Come controlleresti il motore per accelerare o decelerare ruotando in senso antiorario?

Puoi sperimentare con il codice fornito per rispondere a queste domande. Sentiti libero di modificare il codice secondo le tue ipotesi e osserva i cambiamenti nel comportamento del motore.

I tuoi esperimenti pratici e le riflessioni su queste domande approfondiranno la tua comprensione e miglioreranno le tue capacità di problem-solving. È attraverso sfide come queste che avviene il vero apprendimento. Ricorda sempre, non c'è "giusto" o "sbagliato" nel tuo viaggio esplorativo: si tratta tutto di apprendimento e scoperta!
