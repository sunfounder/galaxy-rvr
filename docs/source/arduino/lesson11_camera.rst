.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

Lezione 11: Esplorare il sistema visivo del Mars Rover - Fotocamera e controllo in tempo reale
==============================================================================================

Bentornati, giovani esploratori! Nell'ultima lezione, abbiamo equipaggiato il nostro Mars Rover con la capacità di "annuire" usando un meccanismo di inclinazione. Ora, è il momento di dare al nostro Rover degli "occhi": la fotocamera!

In questo entusiasmante viaggio, ci immergeremo nella configurazione del sistema di telecamere del Rover. Imparerai a trasmettere le immagini catturate dalla fotocamera del Rover a una pagina web, così potrai vedere esattamente ciò che il Rover vede, in tempo reale. Immagina l'emozione di vivere il paesaggio marziano dalla prospettiva del Rover!

L'emozione continua mentre introduciamo anche l'app SunFounder Controller. Questa applicazione ci permette di ottenere un feed in diretta della vista del Rover mentre naviga, e possiamo controllare il meccanismo di inclinazione direttamente dai nostri smartphone o tablet. È come avere un telecomando con uno schermo incorporato!

Obiettivi di apprendimento
--------------------------
* Comprendere come stabilire una connessione WiFi con l'ESP32 CAM.
* Imparare a vedere esattamente ciò che il Rover vede, in tempo reale.
* Imparare a usare l'app SunFounder Controller per creare un telecomando virtuale e controllare il Mars Rover.

Materiali necessari
------------------------

* Modello Mars Rover (equipaggiato con tutti i componenti)
* Arduino IDE
* Computer
* Tablet o smartphone con app SunFounder Controller installata

Procedura del corso
----------------------

**Fase 1: Introduzione all'ESP32 CAM**

Nella nostra precedente avventura, abbiamo equipaggiato il nostro Mars Rover con un paio di "occhi" integrando l'ESP32 CAM. Oggi, impareremo di più su di esso e lo faremo effettivamente "vedere".

.. image:: img/esp32_cam.png
    :width: 400
    :align: center

L'ESP32 CAM, che funge da occhi del nostro Rover, è un modulo piccolo ma potente. Non solo integra funzionalità Wi-Fi e Bluetooth, ma è anche dotato di una fotocamera compatta. Questa fotocamera aiuta il nostro Rover a catturare immagini dell'ambiente circostante.

Proprio come usiamo i nostri occhi per osservare l'ambiente, l'ESP32 CAM può "vedere" cosa c'è davanti al Rover, quindi inviare questi dati visivi al nostro smartphone o computer. Questo ci permette di vedere tutto ciò che il Rover vede in tempo reale!

È come se stessimo pilotando direttamente il Rover, osservando non solo il Rover stesso, ma anche il mondo che esplora! Incredibile, vero? Quindi, approfondiamo...


**Fase 2: Programmazione della fotocamera del Rover e visualizzazione del feed**

Dopo aver montato l'ESP32-CAM sul nostro Rover, ora dobbiamo dargli vita.
Per farlo, useremo l'IDE Arduino per scrivere un programma che controllerà la fotocamera, le permetterà di connettersi al WiFi
e trasmetterà le immagini che cattura.

Ecco come possiamo farlo:

#. Installa la libreria ``SunFounder AI Camera``.

    * Apri il **Library Manager** dell'IDE Arduino, cerca "SunFounder Camera" e clicca **INSTALL**.

        .. image:: img/camera_install_lib.png

    * Apparirà una finestra pop-up per l'installazione delle dipendenze della libreria. Clicca **INSTALL ALL** e attendi il completamento del processo.

        .. image:: img/camera_install_lib1.png

#. Nell'IDE Arduino, inserisci il seguente codice.

    Per quanto riguarda le variabili ``NAME``, ``TYPE`` e ``PORT`` nel codice, non approfondiamole in questo momento. Entreranno in gioco nel nostro prossimo passo. Tieni solo presente che queste variabili saranno importanti nel nostro prossimo viaggio per stabilire un feed video in tempo reale dal nostro Mars Rover.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b648e4-23e8-4b28-accd-aac171069116/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


    Nota che abbiamo due modalità di connessione nel codice: modalità **AP** e modalità **STA**. Puoi decidere quale usare in base alle tue esigenze specifiche.

    * **Modalità AP**: In questa modalità, il Rover crea un hotspot (chiamato ``GalaxyRVR`` nel nostro codice). Questo permette a qualsiasi dispositivo come un telefono cellulare, tablet o laptop di connettersi a questa rete. Questo è particolarmente utile quando vuoi controllare il Rover a distanza in qualsiasi circostanza. Tuttavia, nota che questo renderebbe il tuo dispositivo temporaneamente impossibilitato a connettersi a Internet.

        .. code-block:: arduino

            // AP Mode
            #define WIFI_MODE WIFI_MODE_AP
            #define SSID "GalaxyRVR"
            #define PASSWORD "12345678"

    * **Modalità STA**: In questa modalità, il Rover si connette alla tua rete WiFi domestica. Ricorda che il tuo dispositivo di controllo (come un telefono cellulare o tablet) dovrebbe essere connesso alla stessa rete WiFi. Questa modalità permette al tuo dispositivo di mantenere il suo accesso regolare a Internet mentre controlla il Rover, ma limita il raggio operativo del Rover all'area di copertura WiFi.

        .. code-block:: arduino

            // STA Mode
            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "YOUR SSID"
            #define PASSWORD "YOUR PASSWORD"

#. Carica il codice sul nostro Rover e dai vita al nostro ESP32 CAM!

    * L'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Quindi, prima di caricare il codice, devi prima rilasciare l'ESP32-CAM facendo scorrere questo interruttore sul lato destro per evitare conflitti o potenziali problemi.

        .. image:: ../img/camera_upload.png
            :width: 600

    * Una volta che il codice è stato caricato con successo, riportalo sul lato sinistro per avviare l'ESP32 CAM.

        .. note::
            Questo passaggio e il precedente sono necessari ogni volta che ricarichi il codice.

        .. image:: img/camera_run.png
            :width: 600

    * Apri il **Monitor Seriale** e imposta il baud rate a 115200. Se non appare alcuna informazione, premi il **pulsante Reset** sullo shield GalaxyRVR per eseguire nuovamente il codice. Dovresti vedere un indirizzo IP nell'output del monitor seriale. Questo è l'indirizzo a cui la fotocamera del tuo Rover sta trasmettendo.

        .. image:: img/camera_serial.png


    * Ora, è il momento di vedere effettivamente ciò che il nostro Rover vede! Apri un browser web (ti consigliamo Google Chrome) e inserisci l'URL che vedi nel Monitor Seriale, nel formato ``http://ip:9000/mjpg``.

        .. image:: img/camera_view.png

Ed ecco! Ora dovresti essere in grado di vedere il feed in diretta dalla fotocamera del tuo Rover. Non è incredibile pensare che stai vedendo Marte (o forse solo il tuo salotto) dalla prospettiva del Rover? Proprio come un vero scienziato del Mars Rover!

Ricorda, questo è solo l'inizio. C'è ancora molto da esplorare e imparare. Nel nostro prossimo passo, esploreremo come controllare il nostro Rover mentre visualizziamo il feed in diretta della fotocamera. Emozionante, vero? Avanti, esploratori!
