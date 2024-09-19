.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperti**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e concorsi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

Lezione 12: Guidare il Rover con l'App
===========================================

Nella nostra ultima avventura, abbiamo imparato a usare il SunFounder Controller per esplorare il mondo attraverso gli "occhi" del rover e a regolarne lo sguardo controllando il meccanismo di inclinazione. È stato come dare al nostro rover marziano un senso della vista!

Ora immagina se potessi anche guidare questo esploratore marziano, dirigendo il suo percorso a tuo piacimento. In questa lezione, faremo proprio questo! Porteremo la nostra comprensione del SunFounder Controller a un livello superiore e impareremo a manovrare il nostro rover, provando l'emozione di essere un vero pilota di rover su Marte!

Con il nostro vivace corso STEAM, i bambini non solo impareranno, ma vivranno l'emozione e la meraviglia dell'esplorazione spaziale! Allacciate le cinture e preparatevi per un viaggio emozionante!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/camera_app.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

Obiettivi di apprendimento
-------------------------------

* Acquisire una comprensione più approfondita del SunFounder Controller.
* Imparare a guidare il rover marziano utilizzando l'app mobile.


Materiali necessari
-------------------------

* Modello Mars Rover (dotato di tutti i componenti, esclusi pannello solare e piastra inferiore)
* Arduino IDE
* Computer
* Tablet o smartphone con installata l'app SunFounder Controller

Fasi del corso
--------------------

**Fase 1: Approfondimento del SunFounder Controller**

Nella lezione precedente, abbiamo avuto un primo assaggio del SunFounder Controller, delle sue operazioni di base e dei suoi usi. Ma sicuramente hai ancora qualche domanda, vero? È ora di soddisfare quella curiosità e approfondire questa meraviglia tecnologica.

Creando un nuovo controller, ti troverai di fronte a uno schermo che, inizialmente, potrebbe sembrare un enigma.

.. image:: img/app/app_blank.png

Vedrai una varietà di forme: rettangoli lunghi, rettangoli corti e grandi quadrati, ciascuno contrassegnato da identificatori che vanno da A a Q.

Ti sei mai chiesto perché tanta diversità? Cosa implicano gli identificatori da A a Q?

Iniziamo questo viaggio esplorativo!

* **Decifrare le forme**

    Ad esempio, tocca un'area rettangolare lunga. Come aprire uno scrigno del tesoro, svelerai diversi widget. Ricordi lo **Slider** della nostra lezione precedente? Spostandolo a sinistra o a destra, controllava l'inclinazione della telecamera del Mars rover. Poi c'è il **Gauge**, che può essere usato come tachimetro personale del rover. E una pletora di altri widget!

    .. image:: img/app/app_long.png

    Tocca il rettangolo più corto, e si riveleranno un altro insieme di widget. Il widget **Button**, come un interruttore binario, invia comandi singoli, mentre il widget **Microphone** può ascoltare i tuoi comandi vocali per controllare il rover, tra gli altri widget.

    .. image:: img/app/app_short.png

    E il blocco quadrato, ti chiedi? Ospita il widget **Joystick**, il widget D-pad e il widget Throttle. E sì, c'è altro ancora!

    .. image:: img/app/app_square.png

    A questo punto, non preoccuparti di ogni funzione o utilizzo di ciascun widget. Familiarizza con quali widget ogni forma ospita.

* **Sfruttare i widget**

    Attraverso il contenuto sopra, sappiamo che ci sono molti widget diversi. Quindi, per cosa possono essere utilizzati questi widget?

    Classifichiamo questi widget in due tipi: widget di controllo e widget di visualizzazione.

    * I **widget di controllo** ti consentono principalmente di manipolare l'app, e quindi il rover marziano riceve questi comandi di controllo ed esegue le azioni corrispondenti.
    * I **widget di visualizzazione** ti permettono di mostrare alcuni valori nell'app, come i valori dei sensori, ecc.

    Per una descrizione dettagliata di questi widget, fai riferimento a: |link_widgets_list|.

    Inoltre, per le funzioni, i parametri, ecc. relativi a questi widget, fai riferimento a: |link_ai_camera_library_api|.

* **Il ruolo degli identificatori**

    Ogni forma porta un identificatore nell'angolo in basso a destra. Perché, ti chiedi? Capiremo questo con un esempio.

    Nella nostra ultima lezione, abbiamo aggiunto un widget **Slider** nella regione **D**. Il codice per ottenere il suo valore sembrava qualcosa del genere:

        .. code-block:: arduino

            int16_t sliderD = aiCam.getSlider(REGION_D);
        
    E se aggiungessimo un widget **Slider** nella regione **B**? Come cambierebbe il codice? Basterebbe semplicemente sostituire ``REGION_D`` con ``REGION_B``.

        .. code-block:: arduino

            int16_t sliderD = aiCam.getSlider(REGION_B);

    Facile, vero? Questi identificatori aiutano a distinguere quale widget hai aggiunto in quale area.

.. note::
    * Istruzioni dettagliate su come creare e aggiungere widget, connettere e utilizzare il SunFounder Controller, sono disponibili nel ``Passo 3`` della ``Lezione 11``.
    * Per operazioni più approfondite, visita |link_sc_page|.

**Fase 2: Controllare il Mars Rover con Doppi Throttle**

Ora che abbiamo approfondito i dettagli sui widget del SunFounder Controller, portiamo il nostro gioco a un livello superiore incorporando due widget Throttle per comandare il movimento del Mars Rover.

#. Posiziona un widget **Throttle** ciascuno nelle regioni **K** e **Q**. Dovrai premere il pulsante |app_edit| in alto a destra per passare alla modalità di modifica e, una volta terminata l'impostazione, fai clic su |app_save| per salvare le modifiche.

    .. image:: img/app/app_throttle.png

#. Poiché intendiamo utilizzare due widget **Throttle** per governare la mobilità del Rover, modifichiamo di conseguenza la funzione che gestisce i movimenti del rover:


    .. code-block:: arduino

        // Funzione per impostare la potenza dei motori
        void carSetMotors(int8_t power_L, int8_t power_R) {
            // Imposta la potenza per il motore sinistro
            if (power_L >= 0) {
                SoftPWMSet(in1, map(power_L, 0, 100, 0, 255));
                SoftPWMSet(in2, 0);
            } else {
                SoftPWMSet(in1, 0);
                SoftPWMSet(in2, map(power_L, 0, -100, 0, 255));
            }

            // Imposta la potenza per il motore destro
            if (power_R >= 0) {
                SoftPWMSet(in3, 0);
                SoftPWMSet(in4, map(power_R, 0, 100, 0, 255));
            } else {
                SoftPWMSet(in3, map(power_R, 0, -100, 0, 255));
                SoftPWMSet(in4, 0);
            }
        }

    La funzione ``carSetMotors()`` accetta due argomenti, ``power_L`` e ``power_R``, che sono probabilmente i valori di potenza per i motori sinistro e destro rispettivamente. I valori vanno da -100 a 100, dove i valori negativi indicano movimento inverso, 0 indica lo stop e i valori positivi indicano movimento in avanti.

    * Impostare la potenza per il motore sinistro:

        * Se ``power_L`` è maggiore o uguale a 0, il motore sinistro è impostato per muoversi in avanti. 
        
        * ``SoftPWMSet(in1, map(power_L, 0, 100, 0, 255))`` utilizza la funzione ``map`` di Arduino per mappare l'intervallo di input (0 a 100) all'intervallo di output (0 a 255). Questo valore mappato viene poi passato alla funzione ``SoftPWMSet`` insieme a ``in1``.

        * Se ``power_L`` è inferiore a 0, il motore sinistro si muove in retromarcia e l'intervallo di input per la funzione ``map`` va da 0 a -100.

    * Impostare la potenza per il motore destro:

        * Segue la stessa logica dell'impostazione della potenza per il motore sinistro, ma utilizza ``in3`` e ``in4``, e i valori di input sono ``power_R`` invece di ``power_L``.

    Questa funzione converte i valori di potenza dei motori in valori PWM appropriati e imposta i valori PWM sui pin di controllo dei motori corretti per ottenere il movimento desiderato.

#. All'interno della funzione ``onReceive()``, recupera i valori dai due widget **Throttle** e utilizzali come potenza per i motori sinistro e destro del Mars Rover.

    .. code-block:: arduino
        :emphasize-lines: 9,10,13

        void onReceive() {
            // Ottieni il valore dello slider nella regione D
            int16_t sliderD = aiCam.getSlider(REGION_D);

            // Muovi il servo all'angolo indicato dallo slider
            myServo.write(int(sliderD));

            // Ottieni i valori del throttle per sinistra e destra
            int throttle_L = aiCam.getThrottle(REGION_K);
            int throttle_R = aiCam.getThrottle(REGION_Q);

            // Imposta la potenza per i motori
            carSetMotors(throttle_L, throttle_R);
        }

Ecco il codice completo:

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c70d2598-a1f9-465a-83bb-4ebd38eb74fa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Ogni volta che riesegui il codice, devi ripetere i seguenti quattro passaggi:

* Prima di caricare il codice, assicurati che l'interruttore sia posizionato verso destra.

    .. image:: img/camera_upload.png

* Una volta caricato correttamente il codice, sposta l'interruttore verso sinistra per avviare l'ESP32 CAM.
* Connettiti alla rete ``GalaxyRVR``.
* Connettiti e avvia il controller.

Ora, con un semplice scorrimento del pollice sui widget ``Throttle``, vedrai il Mars Rover in azione, avanzare e ruotare con rinnovata energia. Che l'esplorazione abbia inizio!

**Fase 3: Visualizzare i Dati dei Sensori**

Nel nostro viaggio con il SunFounder Controller, abbiamo interagito attivamente con il nostro Mars Rover utilizzando i widget di controllo, inclusi i cursori per regolare l'inclinazione e i throttle per determinare il movimento del rover. Ma come possiamo sfruttare i widget di visualizzazione per dipingere un quadro vivace dell'ambiente circostante del rover?

Vediamo come possiamo realizzare questo obiettivo visualizzando i valori dei moduli a infrarossi (IR) per evitare ostacoli, sia a sinistra che a destra, e la distanza catturata dal modulo ad ultrasuoni. Questi dati in tempo reale ci forniranno una chiara immagine dell'ambiente operativo del rover.

Ecco come possiamo farlo:

#. Inizia aggiungendo tre widget Numero al tuo SunFounder Controller. Non dimenticare, puoi personalizzare i loro nomi e unità utilizzando il pulsante delle impostazioni.

    .. image:: img/app/app_show.png

#. Ora, immergiamoci nel codice. Iniziamo portando i frammenti di codice per i moduli IR e per il modulo ad ultrasuoni dalle nostre lezioni precedenti.

    .. code-block:: arduino

        ...
        // Definire il pin per il modulo a ultrasuoni
        #define ULTRASONIC_PIN 10

        // Definire i pin per i moduli IR
        #define IR_RIGHT 7
        #define IR_LEFT 8

        void setup() {
            ...

            // Imposta i pin dei moduli IR come input
            pinMode(IR_RIGHT, INPUT);
            pinMode(IR_LEFT, INPUT);
        }


        float readSensorData() {
            // È richiesto un ritardo di 4ms, altrimenti la lettura potrebbe essere 0
            delay(4);

            // Imposta su OUTPUT per inviare il segnale
            pinMode(ULTRASONIC_PIN, OUTPUT);

            ...
        }

#. Nella funzione ``onReceive()``, estrai i valori dai moduli di evitamento ostacoli e dal sensore a ultrasuoni. Successivamente, aggiorna questi valori nel dizionario ``sendDoc[]``. Le chiavi ``N``, ``P`` e ``O`` corrispondono ai codici delle regioni dei tre widget Numero che hai aggiunto.

    .. code-block:: arduino

        // Funzione da eseguire quando vengono ricevuti dati dal Controller
        void onReceive() {

            ...

            // Leggi i valori dai sensori IR
            int leftValue = digitalRead(IR_LEFT);
            int rightValue = digitalRead(IR_RIGHT);
            aiCam.sendDoc["N"] = leftValue;
            aiCam.sendDoc["P"] = rightValue;
            
            // ultrasuoni
            float distance = readSensorData();
            aiCam.sendDoc["O"] = distance;
        }

Ecco il codice completo:

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6c867007-a0e8-4f85-980d-ec1cd1a70969/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Una volta caricato correttamente il codice, avvia il tuo SunFounder Controller. Verrai accolto con i valori in tempo reale dei moduli di evitamento ostacoli e della distanza rilevata dal sensore a ultrasuoni, che dipingono un quadro chiaro dell'ambiente immediato del rover.

.. image:: img/app/app_show_ir_ultrasonic.png

Con questo passo completato, hai navigato con successo nel mondo dei widget di visualizzazione. Sentiti libero di sperimentare con diversi widget per visualizzare le informazioni che trovi interessanti. Buona esplorazione!

**Fase 4: Riflessione e Conclusione**

In questa lezione, abbiamo approfondito la comprensione del SunFounder Controller, imparando come utilizzare i suoi widget non solo per guidare il nostro Mars Rover, ma anche per monitorare i suoi dati ambientali in tempo reale.

Ora, ecco una sfida per te:

Che ne dici di aggiungere dei widget Switch al tuo SunFounder Controller? Con questi switch attivati, il Mars Rover potrebbe passare tra le modalità di evitamento e inseguimento. Oppure, perché non usare gli switch per controllare la striscia luminosa – accenderla, spegnerla o persino cambiarne il colore?

Hai la fiducia per affrontare questa sfida?

Non vediamo l'ora di vederti conquistare questa sfida!
