.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!


Lezione 3: Entrare nel mondo di Arduino e della programmazione
==============================================================

Nella lezione precedente, abbiamo costruito con successo il sistema di sospensione Rocker-Bogie.
Tuttavia, per renderlo funzionale, dobbiamo fornirgli alimentazione, una scheda di controllo e programmazione per dettare i suoi movimenti.

Quindi in questa lezione, faremo conoscenza con la scheda di controllo e la piattaforma di programmazione che useremo.

.. image:: img/upload_blink.gif

Obiettivi del corso
---------------------

* Comprendere i concetti di base e le funzioni di Arduino.
* Conoscere la scheda SunFounder R3.
* Installare l'IDE Arduino e familiarizzare con la sua interfaccia.
* Apprendere le regole sintattiche di base per la programmazione Arduino.



Materiali del corso
--------------------

* Scheda SunFounder R3
* Arduino IDE
* Cavo USB
* Computer


Introduzione ad Arduino
------------------------------------------

Potresti aver spesso sentito il termine "Arduino" in vari contesti, ma cos'è esattamente e perché è diventato così popolare?

Arduino è una piattaforma elettronica open-source facile da usare sia per applicazioni hardware che software. È progettata per realizzare dispositivi digitali e oggetti interattivi che possono percepire e controllare il mondo fisico circostante.

Analizziamolo:

* **Open-source**: Pensa all'open-source come a un orto comunitario. Tutti possono usarlo, tutti possono contribuire e tutti possono trarne beneficio. Con l'open-source, sia i progetti delle parti fisiche (l'hardware) che le istruzioni di programmazione (il software) sono condivisi liberamente. Ciò significa che chiunque può usarli, migliorarli o creare le proprie versioni. Si tratta di condivisione e creatività!

    .. image:: img/arduino_oscomm.png
        :width: 400
        :align: center

* **Microcontrollore**: Un microcontrollore è come il cervello di Arduino. È un piccolo computer che può eseguire software semplici. Anche se non è potente come il computer che stai usando ora, è perfetto per compiti semplici come comprendere i messaggi dai sensori o accendere un LED (una piccola luce).

    .. image:: img/arduino_micro.jpg
        :width: 500
        :align: center

* **Scheda di sviluppo**: Immagina la scheda di sviluppo come il corpo che supporta il cervello. È la scheda dove risiede il microcontrollore e contiene altre parti che aiutano il microcontrollore a interagire con il mondo. Queste parti includono cose come oscillatori (che aiutano con la temporizzazione), regolatori di tensione (che controllano i livelli di potenza) e connettori per alimentazione e dati (come le prese e gli interruttori di casa).

    .. image:: img/arduino_board.png
        :width: 600
        :align: center

* **Arduino IDE**: È come l'aula di insegnamento per il tuo Arduino. È un programma che gira sul tuo computer dove puoi scrivere le istruzioni che dicono ad Arduino cosa fare. Queste istruzioni sono scritte in un linguaggio di programmazione basato su C++. Una volta scritte le istruzioni, puoi inviarle alla scheda Arduino usando un cavo USB, proprio come consegnare i compiti!

    .. image:: img/arduino_ide_icon.png
        :width: 200
        :align: center

Ora che hai compreso queste idee di base, sei sulla buona strada per diventare un esperto di Arduino!

Poi ci immergeremo in alcune attività pratiche per familiarizzare con la programmazione Arduino e i principi ingegneristici.
Preparati per un entusiasmante viaggio di apprendimento!



Conoscere la tua scheda SunFounder R3
------------------------------------------------------------------

All'interno del tuo kit, troverai una scheda blu, apparentemente una piccola città piena di piccole torri metalliche e percorsi. Ma non lasciarti intimidire! Questa è la scheda di sviluppo SunFounder R3, un tipo di scheda Arduino che può essere utilizzata per programmare e controllare una vasta gamma di dispositivi e progetti elettronici.

Comprendiamo le sue caratteristiche chiave in termini semplici:

.. image:: img/sf_r3.jpg
    :width: 800

* **14 Pin digitali**: Pensa a questi pin come piccoli messaggeri. Possono essere programmati per inviare (output) o ricevere (input) semplici messaggi "sì" o "no" ad altre parti del tuo Mars Rover. Questi messaggi sono in realtà segnali "on" o "off" che la scheda usa per controllare cose come luci o motori.

    * Sei di questi pin speciali possono persino inviare messaggi in una sorta di codice segreto chiamato PWM (Pulse Width Modulation). Questo codice può essere usato per controllare quanto è luminosa una luce, quanto veloce gira un motore o persino dove si posiziona una parte mobile.


* **6 Pin analogici**: Questi pin sono come i sei sensi speciali della scheda. Possono leggere segnali da diversi tipi di sensori (come un sensore di temperatura) e poi tradurre questi segnali in un linguaggio che la scheda può comprendere e usare nella sua programmazione.

* **Connessione USB**: È come il cordone ombelicale della scheda. Puoi usarla per collegare la scheda al computer. Questa connessione permette al computer di "insegnare" alla scheda cosa fare inviandole un programma che scrivi.

* **Jack di alimentazione**: È la fonte di cibo della scheda. Puoi collegare un alimentatore, come una batteria o un adattatore AC-DC, a questo jack per "nutrire" la scheda con l'elettricità di cui ha bisogno per funzionare.

* **Header ICSP**: È come un ingresso speciale per programmare la scheda. Può essere usato se hai un programmatore esterno (un dispositivo speciale per "insegnare" alla scheda).

* **Pulsante Reset**: Se lo premi, è come dire alla scheda di dimenticare cosa stava facendo e ricominciare il suo programma dall'inizio.

Con queste basi, sarai pronto per iniziare le tue avventure di programmazione con la scheda SunFounder R3!

.. _install_arduino_ide:

Installare Arduino IDE
-----------------------------------------------

Ora che abbiamo capito cosa sono Arduino e la scheda Arduino, è il momento di iniziare a mettere in pratica quella conoscenza. Installeremo l'IDE Arduino, che è il software che useremo per programmare la nostra scheda Arduino.

L'ultima versione dell'IDE Arduino è la versione 2.0. È ricca di funzionalità ed è super facile da usare. Tuttavia, dovresti sapere che ha alcuni requisiti di sistema:

    * Windows - Win 10 e versioni successive, 64 bit
    * Linux - 64 bit
    * Mac OS X - Versione 10.14: "Mojave" o successiva, 64 bit

Per iniziare, segui questi passaggi:

#. Visita |link_download_arduino| e scarica l'IDE per la tua versione del sistema operativo.

    .. image:: img/sp_001.png

**Per utenti Windows:**

    #. Una volta scaricato il file (si chiamerà qualcosa come ``arduino-ide_xxxx.exe``), fai doppio clic per avviare il processo di installazione.

    #. Ti verrà mostrato il **Contratto di licenza**. Prenditi un momento per leggerlo e, se accetti i termini, clicca "I Agree".

        .. image:: img/sp_002.png

    #. Successivamente, ti verrà chiesto di scegliere le opzioni di installazione. Lascia queste come sono e clicca "Next".

        .. image:: img/sp_003.png

    #. Scegli dove vuoi installare il software. In genere è meglio installarlo su un'unità diversa da quella usata dal sistema.

        .. image:: img/sp_004.png

    #. Clicca "Install" per avviare l'installazione. Una volta completata, clicca "Finish".

        .. image:: img/sp_005.png

**Per utenti macOS:**

    Fai doppio clic sul file scaricato (che si chiamerà qualcosa come ``arduino_ide_xxxx.dmg``). Segui le istruzioni sullo schermo per trascinare l'app **Arduino IDE** nella cartella **Applications**. Dopo alcuni secondi, l'IDE Arduino sarà installato con successo.

    .. image:: img/macos_install_ide.png
        :width: 800

**Per utenti Linux:**

    Puoi trovare un tutorial dettagliato sull'installazione dell'IDE Arduino 2.0 su un sistema Linux qui: |link_arduino_linux|.

Scoprire il parco giochi Arduino (IDE)
----------------------------------------------------------------

Immaginiamo insieme che l'IDE Arduino sia un parco giochi magico pieno di strumenti e gadget che aspettano di essere esplorati e con cui giocare. Ora ti guiderò a comprendere ogni angolo di questo parco giochi.


.. image:: img/ide-2-overview.png
    :width: 800

Ecco cosa troverai nel tuo parco giochi:

* **Verify / Upload** - Immagina questo come il tuo ascensore magico. Prende il codice che hai scritto e lo trasporta sulla tua scheda Arduino.
* **Select Board & Port** - Questa è la tua mappa del tesoro. Mostra automaticamente le schede Arduino che hai collegato al computer e ti dice il loro numero di porta.
* **Sketchbook** - Questa è la tua biblioteca personale. È dove tutti i tuoi sketch (programmi) sono memorizzati sul tuo computer. Inoltre, può connettersi ad Arduino Cloud, così puoi recuperare i tuoi sketch anche dal mondo online.
* **Boards Manager** - Pensa a questo come al tuo kit di strumenti. È dove puoi trovare e installare diversi pacchetti per il tuo Arduino.
* **Library Manager** - Questo è il tuo forziere infinito. Migliaia di librerie create da Arduino e dalla sua community ti aspettano qui. Hai bisogno di uno strumento o materiale per il tuo codice? Immergiti e trovalo!
* **Debugger** - Immagina di avere un superpotere che ti permette di testare e debuggare il tuo codice in tempo reale, trovando e risolvendo i problemi mentre accadono. Ecco cos'è!
* **Search** - Pensa a questo come alla tua lente d'ingrandimento. Ti aiuta a cercare parole chiave nel tuo codice.
* **Open Serial Monitor** - È come il tuo dispositivo comunicatore. Apre una nuova scheda che permette al tuo computer e alla scheda Arduino di scambiarsi messaggi.

Ora che abbiamo dato un'occhiata al parco giochi, è il momento di immergerci e iniziare a creare!

.. _upload_sketch:

Caricare il tuo primo sketch
-----------------------------------------------

Bene, è il momento di divertirsi! Faremo lampeggiare un LED - è come dire "Ciao, Mondo!" nel mondo di Arduino.

La maggior parte delle schede Arduino ha un LED integrato sul pin 13, il che rende questo un buon primo esperimento.

.. image:: img/1_led.jpg
    :width: 400
    :align: center

Analizziamolo:

#. **Collegala**: Connetti la tua scheda SunFounder R3 al computer usando un cavo USB. È così che daremo alimentazione alla nostra scheda e invieremo il nostro programma (chiamato anche "sketch"). Potresti sentirti come se stessi solo collegando un gadget del computer, ma credimi, ti stai connettendo a un mondo di possibilità!

    .. image:: img/connect_board_pc.gif

#. **Trova lo sketch di esempio**: Nell'IDE Arduino, vai su **File** -> **Examples** -> **Basic** -> **Blink**. Quello che vedi apparire è un programma pronto all'uso che modificheremo. È come ricevere una torta già pronta che stiamo per decorare!

    .. image:: img/open_blink.png

#. **Comprendi lo sketch**: Guarda il codice in questa nuova finestra. Dice ad Arduino di accendere il LED integrato (che è sul pin 13) per un secondo, poi spegnerlo per un secondo, e poi ripetere. È come inviare codice Morse, ma con la luce!

    .. image:: img/led_blink.png

#. **Carica lo sketch**: Una volta selezionati la scheda e la porta corretti, clicca semplicemente il pulsante upload. È facile come inviare una lettera; stai consegnando le tue istruzioni alla scheda Arduino! La maggior parte delle volte, il sistema rileverà automaticamente la scheda e la porta per te.

    .. image:: img/upload_blink.gif

#. **Guardalo funzionare**: Se tutto va bene, vedrai il LED sulla tua scheda Arduino iniziare a lampeggiare. È come se il tuo Arduino ti stesse facendo l'occhiolino!

    .. image:: img/blink_led.gif

Hai fatto un ottimo lavoro! Hai appena eseguito il tuo primo programma Arduino, rendendoti un programmatore a tutti gli effetti! Quindi qual è il prossimo passo? Stiamo solo grattando la superficie di ciò che Arduino può fare. Pronto per la prossima sfida?


Alcuni fatti divertenti sulla programmazione Arduino
--------------------------------------------------------

È ora di scoprire alcuni segreti interessanti sulla programmazione Arduino!

* Magia del codice: ``setup()`` e ``loop()``

    Uno sketch Arduino, o un pezzo di codice, è come un'opera in due atti:

    * ``setup()``: Questo è l'Atto 1, la scena di apertura. Accade solo una volta, quando la tua scheda Arduino si sveglia per la prima volta. È usato per preparare il palco preparando cose come modalità dei pin e librerie.
    * ``loop()``: Dopo l'Atto 1, passiamo all'Atto 2 che si ripete in loop fino al sipario finale (che accade solo se spegniamo l'alimentazione o premiamo il pulsante reset!). Questa parte del codice è come la parte principale della nostra opera, dove l'azione accade veramente.

    Ma ricorda, anche se non c'è magia (codice) nel ``setup()`` o ``loop()``, dobbiamo comunque mantenerli. Sono come il palco - anche un palco vuoto è sempre un palco.

    .. code-block:: arduino

        void setup() {
            // initialize digital pin LED_BUILTIN as an output.
            pinMode(LED_BUILTIN, OUTPUT);

            digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
            delay(1000);                      // wait for a second
            digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
            delay(1000);                      // wait for a second
        }

        // the loop function runs over and over again forever
        void loop() {

        }

* Segni di punteggiatura nella programmazione

    Proprio come in un libro di storie, Arduino usa segni di punteggiatura speciali per dare senso al codice:

    * ``Punti e virgola (;)``: Sono come i punti fermi in una storia. Dicono ad Arduino "OK, ho finito con questa azione. Qual è la prossima?"
    * ``Parentesi graffe {}``: Sono come l'inizio e la fine di un capitolo. Racchiudono pezzi di codice insieme, segnando dove una sezione inizia e finisce.

    Se ti capita di dimenticare alcuni di questi segni di punteggiatura, non preoccuparti! Arduino è come un insegnante amichevole che controllerà il tuo lavoro, indicherà dove sono gli errori e ti mostrerà come risolverli. Fa tutto parte dell'avventura di apprendimento!

    .. image:: img/blink_error.gif

* Informazioni sulle funzioni

    Immagina queste funzioni come incantesimi magici. Ogni incantesimo ha un effetto specifico nella nostra avventura Arduino:

    * ``pinMode()``: Questo incantesimo decide se un pin è INPUT o OUTPUT. È come decidere se un personaggio nella nostra storia parla (OUTPUT) o ascolta (INPUT).
    * ``digitalWrite()``: Questo incantesimo può impostare un pin HIGH (on) o LOW (off), come accendere e spegnere una luce magica.
    * ``delay()``: Questo incantesimo fa fare ad Arduino una pausa per un certo periodo di tempo, come fare un breve pisolino nel mezzo della nostra storia.

    Proprio come un libro di incantesimi, puoi trovare tutti questi incantesimi e molti altri nel |link_arduino_web|. Più incantesimi conosci, più emozionanti possono essere le tue avventure Arduino!

* Commenti: I nostri messaggi segreti

    Abbiamo anche un linguaggio segreto nella programmazione, chiamato ``commenti``. Questi sono messaggi che possiamo scrivere nel nostro codice usando ``//`` o ``/* */``. La parte magica? Arduino li ignora completamente! È un ottimo posto per lasciare appunti per te stesso o per altri per spiegare cosa fanno le parti complicate del codice.

* Leggibilità del codice: Rendere il codice amichevole

    Anche se puoi scrivere il tuo codice in qualsiasi modo tu voglia (ad esempio, mettere i punti e virgola su una riga separata non causerà errori), è importante tenere a mente la leggibilità del codice.

    .. image:: img/blink_noerror.gif

    Proprio come scrivere una buona storia, il modo in cui scriviamo il codice può renderlo divertente e facile o noioso e difficile da leggere. Ecco alcuni modi per rendere il tuo codice più amichevole:

    * Usa un'indentazione corretta per organizzare le tue frasi in paragrafi ordinati. Aiuta il lettore a capire dove finisce una sezione e ne inizia un'altra.
    * Usa nomi di variabili che hanno senso. È come chiamare un personaggio con un nome appropriato in una storia.
    * Mantieni le tue funzioni piccole e semplici, come capitoli brevi e dolci in un libro.
    * Lascia commenti per le parti complicate. È come lasciare una nota a piè di pagina per spiegare una parola difficile.

Ricorda, non stiamo programmando solo per le macchine ma anche per gli umani, quindi assicuriamoci che il nostro codice racconti una storia chiara e comprensibile!


**Rifletti e migliora**


Prendersi un momento per riflettere sul nostro viaggio può fornirci intuizioni che potremmo perdere nel turbine dell'esplorazione. Chiediti:

* Qual è stata la parte più interessante di questa avventura Arduino?
* Ci sono state sfide lungo il percorso? Come le hai superate?
* Potresti spiegare a un amico cos'è Arduino, cosa fa l'IDE Arduino o come eseguire il codice Arduino?
* Come descriveresti la tua prima esperienza di programmazione Arduino?
* Cos'altro vuoi imparare su Arduino?

Pensando a queste domande, stai approfondendo la tua comprensione e preparandoti per esplorazioni future. Ricorda sempre, non c'è una risposta "sbagliata" nella riflessione - è il tuo viaggio personale, dopo tutto!
