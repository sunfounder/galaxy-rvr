.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti esclusivi**: Approfitta di sconti riservati sui nostri nuovi prodotti.
    - **Promozioni festive e giveaway**: Partecipa a promozioni festive e concorsi a premi.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!


Lezione 3: Entrare nel Mondo di Arduino e della Programmazione
=====================================================================

Nella lezione precedente, abbiamo costruito con successo il sistema di sospensione Rocker-Bogie. 
Tuttavia, per renderlo funzionale, dobbiamo fornirgli alimentazione, una scheda di controllo e programmare i movimenti.

Quindi, in questa lezione, ci familiarizzeremo con la scheda di controllo e la piattaforma di programmazione che utilizzeremo.

.. image:: img/upload_blink.gif

Obiettivi del Corso
---------------------

* Comprendere i concetti di base e le funzioni di Arduino.
* Imparare a conoscere la scheda SunFounder R3.
* Installare l'IDE di Arduino e familiarizzare con la sua interfaccia.
* Apprendere le regole sintattiche di base per la programmazione su Arduino.



Materiali del Corso
--------------------

* Scheda SunFounder R3
* Arduino IDE
* Cavo USB
* Computer


Introduzione ad Arduino
------------------------------------------

Hai probabilmente sentito parlare di "Arduino" in vari contesti, ma cos'è esattamente e perché è diventato così popolare?

Arduino è una piattaforma elettronica open-source facile da usare sia per applicazioni hardware che software. È progettata per creare dispositivi digitali e oggetti interattivi che possono percepire e controllare il mondo fisico che li circonda.

Ecco una semplice spiegazione:

* **Open-source**: Immagina l'open-source come un giardino comunitario. Tutti possono usarlo, contribuire e trarne beneficio. Con l'open-source, sia i progetti hardware (le parti fisiche) sia i software sono condivisi liberamente. Chiunque può utilizzarli, migliorarli o creare le proprie versioni. È tutto incentrato sulla condivisione e la creatività!

    .. image:: img/arduino_oscomm.png
        :width: 400
        :align: center

* **Microcontrollore**: Un microcontrollore è come il cervello dell'Arduino. È un piccolo computer che esegue software semplici. Anche se non è potente come il computer che stai utilizzando ora, è perfetto per compiti semplici come comprendere i messaggi dai sensori o accendere un LED.

    .. image:: img/arduino_micro.jpg
        :width: 500
        :align: center

* **Scheda di Sviluppo**: Immagina la scheda di sviluppo come il corpo che sostiene il cervello. È la scheda su cui risiede il microcontrollore e contiene altre parti che aiutano il microcontrollore a interagire con il mondo. Queste parti includono oscillatori (per la temporizzazione), regolatori di tensione (per il controllo dell'energia) e connettori per alimentazione e dati.

    .. image:: img/arduino_board.png
        :width: 600
        :align: center

* **Arduino IDE**: Questo è come la classe dove il tuo Arduino impara. È un programma che gira sul tuo computer e ti permette di scrivere le istruzioni che diranno ad Arduino cosa fare. Queste istruzioni sono scritte in un linguaggio di programmazione basato su C++. Una volta scritte, puoi inviarle alla scheda Arduino tramite un cavo USB, proprio come consegnare i compiti a un insegnante!

    .. image:: img/arduino_ide_icon.png
        :width: 200
        :align: center

Ora che conosci queste idee di base, sei pronto per diventare un esperto di Arduino!

Poi passeremo ad attività pratiche per farti familiarizzare con la programmazione e i principi ingegneristici di Arduino. Preparati per un emozionante percorso di apprendimento!


Conosci la tua Scheda SunFounder R3
------------------------------------------------------------------

All'interno del tuo kit, troverai una scheda blu, che sembra una piccola città piena di torri metalliche e percorsi intricati. Ma non lasciarti intimidire! Questa è la scheda di sviluppo SunFounder R3, una versione di Arduino che può essere utilizzata per programmare e controllare un'ampia gamma di dispositivi ed esperimenti elettronici.

Ecco alcune caratteristiche chiave spiegate in termini semplici:

.. image:: img/sf_r3.jpg
    :width: 800

* **14 Pin Digitali**: Pensa a questi pin come piccoli messaggeri. Possono essere programmati per inviare (output) o ricevere (input) semplici messaggi "sì" o "no" agli altri componenti del tuo Mars Rover. Questi messaggi sono in realtà segnali "acceso" o "spento" che la scheda usa per controllare luci o motori.

    * Sei di questi pin speciali possono inviare messaggi in un codice segreto chiamato PWM (Pulse Width Modulation), utilizzato per controllare la luminosità di una luce, la velocità di un motore o la posizione di una parte mobile.

* **6 Pin Analogici**: Questi pin sono come i sei sensi speciali della scheda. Possono leggere segnali da diversi sensori (come un sensore di temperatura) e tradurli in un linguaggio che la scheda può comprendere e utilizzare nella sua programmazione.

* **Connessione USB**: Questo è come il cordone ombelicale della scheda. Puoi usarlo per collegare la scheda al computer, permettendo al tuo computer di "insegnare" alla scheda cosa fare inviandole un programma che hai scritto.

* **Jack di Alimentazione**: Questo è il cibo della scheda. Puoi collegare un'alimentazione esterna, come una batteria, per fornire l'elettricità necessaria al funzionamento della scheda.

* **ICSP Header**: Questo è come un ingresso speciale per programmare la scheda, usato con un programmatore esterno.

* **Pulsante di Reset**: Premendolo, è come dire alla scheda di dimenticare quello che stava facendo e di ricominciare il programma da capo.

Con queste basi, sarai pronto per iniziare la tua avventura di programmazione con la scheda SunFounder R3!

Installa l'IDE di Arduino
-----------------------------------------------

Ora che capiamo cos'è Arduino e come funziona la scheda, è il momento di iniziare a mettere in pratica ciò che abbiamo imparato. Installeremo l'IDE di Arduino, il software che useremo per programmare la nostra scheda Arduino.

L'ultima versione dell'IDE Arduino è la 2.0, ricca di funzionalità e molto facile da usare. Ecco i requisiti di sistema per installarla:

    * Windows - Win 10 e successivi, 64 bit
    * Linux - 64 bit
    * Mac OS X - Versione 10.14: "Mojave" o successivi, 64 bit

Per iniziare, segui questi passaggi:

#. Visita |link_download_arduino| e scarica l'IDE per la tua versione del sistema operativo.

    .. image:: img/sp_001.png

**Per utenti Windows:**

    #. Una volta scaricato il file (sarà chiamato qualcosa come ``arduino-ide_xxxx.exe``), fai doppio clic per iniziare il processo di installazione.

    #. Ti verrà mostrato il **Contratto di Licenza**. Leggilo e, se sei d'accordo, clicca su "Accetto".

        .. image:: img/sp_002.png

    #. Successivamente, ti verranno richieste le opzioni di installazione. Lasciale come sono e clicca su "Avanti".

        .. image:: img/sp_003.png

    #. Scegli dove vuoi installare il software. È consigliabile installarlo su un'unità diversa da quella utilizzata dal sistema operativo.

        .. image:: img/sp_004.png

    #. Clicca su "Installa" per avviare l'installazione. Al termine, clicca su "Fine".

        .. image:: img/sp_005.png

**Per utenti macOS:**

    Fai doppio clic sul file scaricato (chiamato ``arduino_ide_xxxx.dmg``) e segui le istruzioni per trascinare l'app **Arduino IDE** nella cartella **Applicazioni**.

    .. image:: img/macos_install_ide.png
        :width: 800

**Per utenti Linux:**

    Puoi trovare un tutorial dettagliato su come installare l'IDE di Arduino 2.0 su un sistema Linux qui: |link_arduino_linux|.

Ora che abbiamo familiarizzato con il nostro "parco giochi" Arduino, è il momento di iniziare a creare!

**Per utenti Linux:**

    Puoi trovare un tutorial dettagliato su come installare l'IDE di Arduino 2.0 su un sistema Linux qui: |link_arduino_linux|.
    
Scoprire il Parco Giochi di Arduino (IDE)
----------------------------------------------------------------

Immaginiamo insieme l'IDE di Arduino come un parco giochi magico, pieno di strumenti e gadget che aspettano solo di essere esplorati e utilizzati. Ora ti guiderò nella comprensione di ogni angolo di questo parco giochi.


.. image:: img/ide-2-overview.png
    :width: 800

Ecco cosa troverai nel tuo parco giochi:

* **Verifica / Carica** - Immaginalo come il tuo ascensore magico. Prende il codice che hai scritto e lo carica sulla tua scheda Arduino.
* **Seleziona Scheda e Porta** - Questa è la tua mappa del tesoro. Mostra automaticamente le schede Arduino collegate al tuo computer e ti dice il loro numero di porta.
* **Sketchbook** - Questa è la tua libreria personale. Qui vengono salvati tutti i tuoi sketch (programmi) sul tuo computer. Inoltre, può collegarsi al Cloud Arduino, permettendoti di recuperare i tuoi sketch dal mondo online.
* **Gestione Schede** - Pensalo come il tuo set di strumenti. Qui puoi trovare e installare pacchetti diversi per il tuo Arduino.
* **Gestione Librerie** - Questo è il tuo forziere senza fine. Migliaia di librerie create da Arduino e dalla sua comunità ti aspettano qui. Hai bisogno di uno strumento o materiale per il tuo codice? Tuffati e trova quello che ti serve!
* **Debugger** - Immagina di avere un superpotere che ti consente di testare e correggere il tuo codice in tempo reale, trovando e risolvendo i problemi mentre si verificano. Questo è il suo scopo!
* **Cerca** - Pensalo come la tua lente d'ingrandimento. Ti aiuta a cercare parole chiave nel tuo codice.
* **Apri Monitor Seriale** - È come il tuo dispositivo di comunicazione. Apre una nuova scheda che consente al tuo computer e alla scheda Arduino di inviare messaggi avanti e indietro.

Ora che abbiamo dato una sbirciata al parco giochi, è il momento di tuffarci e iniziare a creare!


Carica il tuo Primo Sketch
-----------------------------------------------

È ora di divertirci! Faremo lampeggiare un LED: è come dire "Ciao, Mondo!" nel mondo di Arduino.

La maggior parte delle schede Arduino ha un LED incorporato sul pin 13, il che rende questo un ottimo primo esperimento.

.. image:: img/1_led.jpg
    :width: 400
    :align: center

Ecco una suddivisione:

#. **Collega la scheda**: Collega la tua scheda SunFounder R3 al computer utilizzando un cavo USB. Questo è il modo in cui daremo energia alla scheda e invieremo il programma (chiamato anche "sketch") alla scheda stessa. Potresti pensare di star collegando un gadget del computer, ma credimi, stai accedendo a un mondo di possibilità!

    .. image:: img/connect_board_pc.gif

#. **Trova lo sketch di esempio**: Nell'IDE di Arduino, vai su **File** -> **Esempi** -> **Basic** -> **Blink**. Ciò che vedrai apparire è un programma pronto all'uso che modificheremo. È come avere una torta già pronta da decorare!

    .. image:: img/open_blink.png

#. **Comprendi lo sketch**: Osserva il codice nella nuova finestra. Dice ad Arduino di accendere il LED incorporato (che è sul pin 13) per un secondo, poi di spegnerlo per un secondo, e poi ripetere. È come inviare un codice Morse, ma con la luce!

    .. image:: img/led_blink.png

#. **Carica lo sketch**: Una volta selezionata la scheda e la porta corrette, basta fare clic sul pulsante di caricamento. È facile come inviare una lettera: stai consegnando le tue istruzioni alla scheda Arduino! Nella maggior parte dei casi, il sistema rileverà automaticamente la scheda e la porta per te.

    .. image:: img/upload_blink.gif

#. **Guarda come funziona**: Se tutto va bene, vedrai il LED sulla tua scheda Arduino iniziare a lampeggiare. È come se Arduino ti strizzasse l'occhio!

    .. image:: img/blink_led.gif

Hai fatto un ottimo lavoro! Hai appena eseguito il tuo primo programma su Arduino, rendendoti un vero programmatore! E adesso? Abbiamo appena scalfito la superficie di ciò che Arduino può fare. Sei pronto per la prossima sfida?


Alcuni Fatti Divertenti sulla Programmazione Arduino
--------------------------------------------------------

È il momento di scoprire alcuni segreti interessanti sulla programmazione Arduino!

* Magia del Codice: ``setup()`` e ``loop()``

    Uno sketch di Arduino, o pezzo di codice, è come una rappresentazione teatrale in due atti:

    * ``setup()``: Questo è l'Atto 1, la scena di apertura. Avviene solo una volta, quando la tua scheda Arduino si "sveglia". Serve a preparare il palcoscenico configurando elementi come le modalità dei pin e le librerie.
    * ``loop()``: Dopo l'Atto 1, passiamo all'Atto 2, che si ripete in un ciclo continuo fino al termine (che avviene solo se spegniamo l'alimentazione o premiamo il pulsante di reset!). Questa parte del codice è come la parte principale dello spettacolo, dove avviene l'azione.

    Ma ricorda, anche se non c'è "magia" (codice) in ``setup()`` o ``loop()``, dobbiamo comunque mantenerli. Sono come il palcoscenico: anche se vuoto, è sempre un palcoscenico.

    .. code-block:: arduino
    
        void setup() {
            // inizializza il pin digitale LED_BUILTIN come output.
            pinMode(LED_BUILTIN, OUTPUT);

            digitalWrite(LED_BUILTIN, HIGH);  // accende il LED (HIGH è il livello di tensione)
            delay(1000);                      // attende un secondo
            digitalWrite(LED_BUILTIN, LOW);   // spegne il LED abbassando la tensione (LOW)
            delay(1000);                      // attende un secondo
        }

        // la funzione loop viene eseguita continuamente
        void loop() {

        }

* Punteggiatura nel Codice

    Proprio come in una storia, Arduino usa segni di punteggiatura speciali per dare senso al codice:

    * ``Punti e virgola (;)``: Sono come i punti alla fine di una frase. Dicono ad Arduino: "Ok, ho finito con questa azione. Cosa segue?"
    * ``Graffe {}``: Sono come l'inizio e la fine di un capitolo. Racchiudono insieme pezzi di codice, indicando dove inizia e finisce una sezione.
    
    Se dimentichi qualcuno di questi segni di punteggiatura, non preoccuparti! Arduino è come un insegnante amichevole che controllerà il tuo lavoro, evidenziando gli errori e mostrando come correggerli. Fa parte del divertimento dell'apprendimento!

    .. image:: img/blink_error.gif

* Riguardo alle Funzioni

    Immagina queste funzioni come incantesimi magici. Ogni incantesimo ha un effetto specifico nella nostra avventura Arduino:

    * ``pinMode()``: Questo incantesimo decide se un pin è INPUT o OUTPUT. È come decidere se un personaggio della storia parla (OUTPUT) o ascolta (INPUT).
    * ``digitalWrite()``: Questo incantesimo può accendere (HIGH) o spegnere (LOW) un pin, come accendere e spegnere una luce magica.
    * ``delay()``: Questo incantesimo fa fare una pausa ad Arduino per un certo tempo, come fare un breve sonnellino a metà della nostra storia.
    
    Proprio come in un libro di incantesimi, puoi trovare tutti questi incantesimi e molti altri su |link_arduino_web|. Più incantesimi conosci, più emozionanti saranno le tue avventure con Arduino!

* Commenti: I Nostri Messaggi Segreti

    Esiste anche un linguaggio segreto nella programmazione, chiamato ``commenti``. Questi sono messaggi che possiamo scrivere nel codice usando ``//`` o ``/* */``. La parte magica? Arduino li ignora completamente! È un ottimo posto per lasciare note per te stesso o per spiegare ad altri cosa fanno le parti più complesse del codice.

* Leggibilità del Codice: Rendere il Codice Amichevole

    Anche se puoi scrivere il codice in qualsiasi modo tu voglia (ad esempio, mettere i punti e virgola su una linea separata non causerà errori), è importante considerare la leggibilità del codice.

    .. image:: img/blink_noerror.gif

    Proprio come scrivere una buona storia, il modo in cui scriviamo il codice può renderlo divertente e facile da leggere o noioso e difficile da seguire. Ecco alcuni modi per rendere il tuo codice più accessibile:

    * Usa la corretta indentazione per organizzare le tue frasi in paragrafi ordinati. Aiuta il lettore a capire dove termina una sezione e inizia un'altra.
    * Usa nomi di variabili che abbiano senso. È come dare a un personaggio un nome appropriato in una storia.
    * Mantieni le tue funzioni piccole e semplici, come capitoli brevi e concisi.
    * Lascia commenti per le parti complicate. È come lasciare una nota a piè di pagina per spiegare una parola difficile.

Ricorda, non stiamo solo programmando per le macchine ma anche per gli esseri umani, quindi assicuriamoci che il nostro codice racconti una storia chiara e comprensibile!


**Rifletti e Migliora**


Prendere un momento per riflettere sul nostro percorso può fornirci intuizioni che potremmo aver trascurato nella frenesia dell'esplorazione. Chiediti:

* Qual è stata la parte più interessante di questa avventura con Arduino?
* Ci sono state delle sfide lungo il cammino? Come le hai superate?
* Potresti spiegare a un amico cos'è Arduino, cosa fa l'IDE di Arduino o come eseguire un codice su Arduino?
* Come descriveresti la tua prima esperienza di programmazione con Arduino?
* Cos'altro vorresti imparare su Arduino?

Riflettendo su queste domande, stai approfondendo la tua comprensione e ti stai preparando per esplorazioni future. Ricorda sempre, non ci sono risposte "sbagliate" nella riflessione: dopotutto, è il tuo percorso personale!
