.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anticipazioni.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a concorsi e promozioni speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

Lezione 11: Esplorare il sistema visivo del Rover - Fotocamera e controllo in tempo reale
==============================================================================================

Bentornati, giovani esploratori! Nella lezione precedente, abbiamo dotato il nostro Mars Rover della capacità di "annuire" usando un meccanismo di inclinazione. Ora è il momento di dare al nostro Rover gli "occhi" - la fotocamera!

In questo emozionante viaggio, ci immergeremo nell'installazione del sistema di fotocamere del Rover. Imparerai come trasmettere le immagini catturate dalla fotocamera del Rover su una pagina web, così potrai vedere esattamente ciò che vede il Rover, in tempo reale. Immagina l'emozione di vivere il paesaggio marziano dal punto di vista del Rover!

L'emozione continua con l'introduzione dell'app SunFounder Controller. Questa applicazione ci consente di ricevere un feed live della visione del Rover mentre si muove, e possiamo controllare il meccanismo di inclinazione direttamente dai nostri smartphone o tablet. È come avere un telecomando con uno schermo integrato!

Questa funzionalità offre un'esperienza ancora più interattiva e coinvolgente con il nostro Rover. Resta con noi per altre avventure!

    .. image:: img/app/camera_view_app.png

Obiettivi di apprendimento
------------------------------

* Comprendere come stabilire una connessione WiFi con l'ESP32 CAM.
* Imparare a vedere esattamente ciò che vede il Rover, in tempo reale.
* Imparare a utilizzare l'app SunFounder Controller per creare un telecomando virtuale e controllare il Mars Rover.

Materiali necessari
----------------------

* Modello Mars Rover (completo di tutti i componenti)
* Arduino IDE
* Computer
* Tablet o smartphone con l'app SunFounder Controller installata

Passaggi del corso
----------------------

**Passaggio 1: Introduzione all'ESP32 CAM**

Nella nostra precedente avventura, abbiamo dotato il nostro Mars Rover di una coppia di "occhi" integrando l'ESP32 CAM. Oggi, approfondiremo il suo funzionamento e lo faremo davvero "vedere".

.. image:: img/esp32_cam.png
    :width: 400
    :align: center

L'ESP32 CAM, che funge da occhi del nostro Rover, è un piccolo ma potente modulo. Non solo integra funzionalità Wi-Fi e Bluetooth, ma è anche dotato di una fotocamera compatta. Questa fotocamera aiuta il nostro Rover a catturare immagini dell'ambiente circostante.

Proprio come usiamo i nostri occhi per osservare l'ambiente, l'ESP32 CAM può "vedere" ciò che si trova davanti al Rover e inviare questi dati visivi al nostro smartphone o computer. Questo ci permette di vedere tutto ciò che vede il Rover in tempo reale!

È come se stessimo pilotando direttamente il Rover, osservando non solo il Rover stesso, ma anche il mondo che esplora! Incredibile, vero? Approfondiamo subito...


**Passaggio 2: Programmare la fotocamera del Rover e visualizzare il feed**

Dopo aver installato l'ESP32-CAM sul nostro Rover, dobbiamo darle vita. 
Per farlo, utilizzeremo l'Arduino IDE per scrivere un programma che controllerà la fotocamera, le consentirà di connettersi al WiFi 
e trasmettere le immagini catturate.

Ecco come possiamo farlo:

#. Installa la libreria ``SunFounder AI Camera``.

    * Apri il **Gestore Librerie** dell'Arduino IDE, cerca "SunFounder Camera" e fai clic su **INSTALLA**.

        .. image:: img/camera_install_lib.png

    * Apparirà una finestra pop-up per l'installazione delle dipendenze della libreria. Clicca su **INSTALLA TUTTO** e attendi il completamento del processo.

        .. image:: img/camera_install_lib1.png

#. Nell'Arduino IDE, inserisci il seguente codice.

    Riguardo alle variabili ``NAME``, ``TYPE`` e ``PORT`` nel codice, non approfondiremo per ora. Saranno rilevanti nel nostro prossimo passaggio per stabilire un feed video in tempo reale dal nostro Mars Rover.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b648e4-23e8-4b28-accd-aac171069116/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


    Nota che nel codice abbiamo due modalità di connessione: modalità **AP** e modalità **STA**. Puoi decidere quale usare in base alle tue esigenze specifiche.

    * **Modalità AP**: In questa modalità, il Rover crea un hotspot (denominato ``GalaxyRVR`` nel nostro codice). Ciò consente a qualsiasi dispositivo, come un telefono cellulare, tablet o laptop, di connettersi a questa rete. Questa modalità è utile quando vuoi controllare il Rover da remoto in qualsiasi circostanza. Tuttavia, tieni presente che questo renderà temporaneamente impossibile la connessione del tuo dispositivo a Internet.

      .. code-block:: arduino

          // AP Mode
          #define WIFI_MODE WIFI_MODE_AP
          #define SSID "GalaxyRVR"
          #define PASSWORD "12345678"

    * **Modalità STA**: In questa modalità, il Rover si connette alla tua rete WiFi domestica. Ricorda che il tuo dispositivo di controllo (come un telefono o tablet) deve essere connesso alla stessa rete WiFi. Questa modalità consente al tuo dispositivo di mantenere l'accesso regolare a Internet mentre controlli il Rover, ma limita l'area operativa del Rover alla copertura WiFi.

      .. code-block:: arduino

            // STA Mode
            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "YOUR SSID"
            #define PASSWORD "YOUR PASSWORD"

#. Carica il codice sul nostro Rover e attiva il nostro ESP32 CAM!

    * L'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Quindi, prima di caricare il codice, dovrai prima rilasciare l'ESP32-CAM spostando questo interruttore a destra per evitare conflitti o problemi.

        .. image:: img/camera_upload.png
            :width: 600

    * Una volta caricato correttamente il codice, sposta nuovamente l'interruttore a sinistra per avviare l'ESP32 CAM.

        .. note::
            Questo passaggio e quello precedente sono necessari ogni volta che ricarichi il codice.

        .. image:: img/camera_run.png
            :width: 600
        
    * Apri il **Monitor Seriale** e imposta il baud rate a 115200. Se non appare alcuna informazione, premi il **pulsante di Reset** sullo scudo GalaxyRVR per far partire nuovamente il codice. Dovresti vedere un indirizzo IP nell'output del monitor seriale. Questo è l'indirizzo a cui la telecamera del Rover sta trasmettendo.

        .. image:: img/camera_serial.png


    * Ora è il momento di vedere realmente ciò che vede il nostro Rover! Apri un browser web - consigliamo Google Chrome - e inserisci l'URL che vedi nel Monitor Seriale, nel formato ``http://ip:9000/mjpg``.

        .. image:: img/camera_view.png

Ed ecco fatto! Ora dovresti essere in grado di vedere il feed live dalla telecamera del tuo Rover. Non è sorprendente pensare che stai vedendo Marte (o forse solo il tuo soggiorno) dalla prospettiva del Rover? Proprio come uno scienziato che controlla un vero Rover marziano!

Ricorda, questo è solo l'inizio. C'è molto altro da esplorare e imparare. Nel nostro prossimo passaggio, esploreremo come controllare il nostro Rover mentre visualizziamo il feed della telecamera live. Emozionante, vero? Avanti, esploratori!


**Passaggio 3: Controllare e visualizzare il feed della fotocamera utilizzando l'app**

Hai mai desiderato visualizzare il feed video del Mars Rover direttamente sul tuo smartphone e contemporaneamente controllarne il meccanismo di inclinazione? 
Ora puoi! Con l'app SunFounder Controller, potrai fare proprio questo. Segui i passaggi di seguito:


#. Installa l'app dal **APP Store(iOS)** o **Google Play(Android)**.

#. Crea un controller.

    * Per aggiungere un controller su SunFounder Controller, clicca sull'icona **+**.

        .. image:: img/app/app1.png

    * Scegli il preset **Vuoto**, seleziona **Dual** o **Single Stick** secondo le tue preferenze. Dai un nome al tuo nuovo controller e clicca su **Conferma**.

        .. image:: img/app/camera_controller.png

    * Ora sei dentro il controller. Clicca sull'icona **+** nella sezione D, quindi seleziona Slider dal menu a comparsa.

    .. image:: img/app/camera_add_slider.png

    * Questo widget Slider è progettato per controllare il meccanismo di inclinazione. Come abbiamo imparato nella lezione precedente, il suo intervallo va da 0 a 140. Pertanto, imposteremo questi valori come minimo e massimo per il nostro widget Slider.

        .. image:: img/app/camera_slider_set.png
    
    * Clicca sul pulsante |app_save| in alto a destra per salvare questo controller.
    
#. Scriviamo un codice per catturare il valore dello slider:

    * Basandoci sul codice precedente, passiamo alla modalità AP, dove puoi impostare l'SSID e la PASSWORD secondo le tue preferenze.
    
      .. code-block:: arduino
    
          // AP Mode
          #define WIFI_MODE WIFI_MODE_AP
          #define SSID "GalaxyRVR"
          #define PASSWORD "12345678"

    * Successivamente, aggiungiamo una funzione ``onReceive()`` per ricevere valori dal SunFounder Controller e stampare questi valori nel Monitor Seriale. Usiamo la funzione ``getSlider()`` per ottenere il valore del widget **slider**. Ho aggiunto un widget **slider** nella Regione D, ma se lo hai aggiunto in un'altra regione, devi cambiare ``REGION_D`` con la tua regione.

        .. code-block::

            void onReceive() {
                int16_t sliderD = aiCam.getSlider(REGION_D);
                Serial.print("Slider D: ");
                Serial.println(sliderD);
            }

            void setup() {
                ...
                // Imposta la funzione da eseguire quando vengono ricevuti dati
                aiCam.setOnReceived(onReceive);
                ...
            }

    * Ecco il codice completo:

        .. raw:: html

            <iframe src=https://create.arduino.cc/editor/sunfounder01/b914aa48-85e7-4682-b420-89961cc761ca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
    * Prima di caricare il codice, assicurati che l'interruttore sia spostato verso destra.

        .. image:: img/camera_upload.png
            :width: 600

    * Dopo che il codice è stato caricato correttamente, sposta l'interruttore a sinistra per avviare l'ESP32 CAM.

        .. image:: img/camera_run.png
            :width: 600

    * Quando vedrai le seguenti informazioni nel Monitor Seriale, potrai passare al passaggio successivo.

        .. code-block:: arduino
        
            ...[OK]
            SET+PORT8765
            ...[OK]
            SET+START
            ...[OK]
            WebServer started on ws://192.168.4.1:8765
            Video streamer started on http://192.168.4.1:9000/mjpg
            WS+null

#. Connettiti alla rete ``GalaxyRVR``. Tieni aperto il Monitor Seriale, poiché riaprire il Monitor Seriale farà riavviare l'Arduino Uno, richiedendo di ripetere questo passaggio.

    A questo punto, dovresti connettere il tuo dispositivo mobile alla rete locale (LAN) fornita dal GalaxyRVR. 
    In questo modo, sia il tuo dispositivo mobile che il Rover saranno sulla stessa rete, consentendo una comunicazione fluida 
    tra le applicazioni del tuo dispositivo mobile e il Rover.

    * Trova ``GalaxyRVR`` nell'elenco delle reti disponibili sul tuo dispositivo mobile (tablet o smartphone), inserisci la password ``12345678`` e connettiti.

        .. image:: img/app/camera_lan.png

    * La modalità di connessione predefinita è la **modalità AP**. Dopo la connessione, potrebbe apparire un messaggio di avviso che indica che non c'è accesso a Internet su questa rete WLAN, scegli di continuare la connessione.

        .. image:: img/app/camera_stay.png

#. Collega e attiva il Controller.

    * Ora, torna al controller che hai creato in precedenza (nel mio caso, si chiama "camera"). Utilizza il pulsante |app_connect| per collegare il SunFounder Controller al Rover e stabilire una linea di comunicazione. Dopo un breve periodo, apparirà ``GalaxyRVR(IP)`` (il nome che hai assegnato nel codice con ``#define NAME "GalaxyRVR"``). Clicca su di esso per stabilire la connessione.

        .. image:: img/app/camera_connect.png
            :width: 400

        .. note::
            Verifica che il tuo Wi-Fi sia connesso a ``GalaxyRVR`` se non vedi il messaggio sopra dopo un po' di tempo.

    * Una volta visualizzato il messaggio "Connesso con successo", premi il pulsante |app_run|. Questo farà apparire il feed live della telecamera sull'app.

        .. image:: img/app/camera_view_app.png
            :width: 400

    * Ora, sposta il cursore, dovresti vedere dati simili a quelli riportati di seguito nel monitor seriale dell'IDE Arduino. Se hai riaperto il Monitor Seriale, dovrai ripetere i passaggi 4 e 5 per riconnettere il GalaxyRVR e l'app.

        .. code-block:: 
    
            Slider D: 105
            WS+null
            Slider D: 105
            WS+null
            Slider D: 105
            WS+null


#. Lascia che il cursore controlli il meccanismo di inclinazione.

    Ora che conosciamo i valori trasmessi dal widget del cursore, possiamo usare direttamente questi valori per ruotare il servo. Quindi, basandoci sul codice precedente, aggiungiamo le seguenti righe per inizializzare il servo e scrivere il valore del cursore al servo.

    .. code-block::

        ...
        #include <Servo.h>

        Servo myServo;  // create a servo object
        ...

        void setup() {
            ...
            myServo.attach(6);  // attaches the servo on pin 6
            ...
        }

        void loop() {
            ...
        }

        void onReceive() {
            ...
            myServo.write(int(sliderD));  // control the servo to move to the current angle
        }

    Ecco il codice completo:
    
    .. raw:: html
    
        <iframe src=https://create.arduino.cc/editor/sunfounder01/b737352b-2509-4967-8147-1fd6bdc7d19d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

    Carica il codice sopra sul GalaxyRVR, ripeti i passaggi 4 e 5 sopra, riconnettiti alla LAN ``GalaxyRVR`` e riavvia nel SunFounder Controller, quindi potrai far scorrere il cursore per controllare il meccanismo di inclinazione del rover.

Ora hai imparato con successo a implementare il SunFounder Controller e come utilizzare il widget del cursore per controllare i movimenti del servo. Questo processo ti permetterà di interagire con il tuo GalaxyRVR in un modo più intuitivo e diretto.


**Passaggio 4: Riflessione e riepilogo**

Usare il SunFounder Controller per operare il tuo Mars Rover potrebbe sembrare un po' complicato all'inizio. Ogni volta che modifichi il tuo codice, dovrai ripetere i seguenti passaggi:

* Prima di caricare il codice, assicurati che l'interruttore sia spostato a destra.

    .. image:: img/camera_upload.png
        :width: 600

* Una volta che il codice è stato caricato con successo, sposta l'interruttore a sinistra per avviare l'ESP32 CAM.
* Connettiti alla rete ``GalaxyRVR``.
* Connetti e avvia il controller.

Anche se questi passaggi possono sembrare noiosi, sono fondamentali per il processo. Dopo averli ripetuti alcune volte, diventerai più familiare e a tuo agio con la procedura.

Ora che abbiamo terminato questa lezione, riflettiamo su ciò che abbiamo imparato attraverso alcune domande:

* Nel processo di creazione di un nuovo controller, hai incontrato molti tipi diversi di blocchi. Hai pensato a quali potrebbero essere le loro funzioni individuali?
* È possibile utilizzare altri widget per controllare il meccanismo di inclinazione?
* O persino controllare direttamente i movimenti del Mars Rover?

Aspettiamo con impazienza l'esplorazione di queste domande nella prossima lezione!
