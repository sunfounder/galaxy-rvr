.. note::

    Ciao, benvenuto nella Community SunFounder di appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri entusiasti.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!


.. _quick_start:

Gioco rapido con l'APP
=========================

Immergiti subito nella tua avventura marziana! Con il codice preinstallato in fabbrica, puoi iniziare a usare il tuo GalaxyRVR subito dopo l'assemblaggio. Esplora funzionalità come guida in prima persona, evitamento ostacoli, modalità di follow e controllo vocale, tutto tramite l'app SunFounder Controller. Inizia il tuo viaggio oggi!

.. raw:: html
    
    <video width="600" loop autoplay muted>
        <source src="_static/video/play_mode.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::  

    Se la tua scheda R3 è programmata con altro codice e desideri controllare il GalaxyRVR tramite l'app, segui i passaggi in :ref:`upload_galaxy_code`.

Guida rapida
---------------------

#. Avviamo il GalaxyRVR.

   * La prima volta che utilizzi il tuo GalaxyRVR, è consigliabile collegare un cavo USB di tipo C per caricare completamente la batteria. Poi accendi l'alimentazione.
    
     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_start.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

   * Per attivare l'ESP32 CAM, sposta l'interruttore della modalità in posizione **Run** e premi il pulsante **reset** per riavviare la scheda R3. Vedrai una luce ciano lampeggiare sulla striscia inferiore.

     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Installa `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ da **APP Store(iOS)** o **Google Play(Android)**.


#. Collegati alla rete ``GalaxyRVR``.

   Per una comunicazione ottimale tra il tuo dispositivo mobile e il Rover, è necessario collegarli alla stessa rete locale (LAN) fornita dal GalaxyRVR.

   * Trova ``GalaxyRVR`` nell'elenco delle reti disponibili sul tuo dispositivo mobile (tablet o smartphone), inserisci la password ``12345678`` e connettiti.

     .. note::

        * La connessione attuale è all'hotspot del GalaxyRVR, quindi non c'è accesso a Internet. Se richiesto di cambiare rete, scegli "Rimani connesso".
        * :ref:`ap_to_sta`

     .. image:: img/app/camera_lan.png
        :width: 500


    
#. Configura un controller.

   * Per creare un controller su SunFounder Controller, tocca l'icona **+**.

     .. image:: img/app/app1.png

   * Sono disponibili controller preimpostati per alcuni prodotti, qui scegliamo **GalaxyRVR**. Dai un nome o tocca semplicemente **Conferma**.

     .. image:: img/app/play_preset.jpg
    
   * Una volta dentro, l'app cercherà automaticamente il GalaxyRVR. Dopo un momento, vedrai un messaggio che dice "Connessione riuscita".

     .. image:: img/app/auto_connect.jpg

     .. note::

       * Se non è connesso, verifica che il tuo Wi-Fi sia connesso a ``GalaxyRVR``.
       * Puoi anche toccare il pulsante |app_connect| per connetterti manualmente. Dopo un breve periodo, dovrebbe apparire ``GalaxyRVR(IP)``. Toccalo per stabilire una connessione.
     
       .. image:: img/app/camera_connect.png
           :width: 300
           :align: center


   * Ora, tocca il pulsante |app_run| per visualizzare il feed video live dalla fotocamera e controllare il rover utilizzando i widget forniti. 

     .. image:: img/app/play_run_view.jpg

#. Esploriamo ora le funzioni di ciascun widget:

   * **Servo(D)**: Controlla il meccanismo di inclinazione della fotocamera del Rover, permettendoti di osservare un'ampia gamma.
   * :ref:`app_avoid`: Attiva la modalità di evitamento ostacoli. Le distanze di rilevamento impostate in fabbrica per ciascun modulo possono variare. È necessaria una regolazione manuale.
   * :ref:`app_follow`: Attiva la modalità di follow. Le distanze di rilevamento impostate in fabbrica per ciascun modulo possono variare. È necessaria una regolazione manuale.
   * **Stop(I)**: Ferma immediatamente tutti i movimenti del Rover.
   * :ref:`app_speech_control`: Premi questo widget per avviare il riconoscimento vocale e far eseguire al Rover le azioni corrispondenti.
   * **HeadLamp(M)**: Accende/spegne il LED sull'ESP32 CAM.
   * **Widget acceleratore su K e Q**: Il widget acceleratore nell'area K controlla i motori sinistri del Rover, mentre quello nell'area Q controlla i motori destri. Coordinando entrambi i widget, il GalaxyRVR può muoversi in qualsiasi direzione.
   * **Left IR(N)**: Mostra le letture del modulo di evitamento ostacoli sinistro.
   * **Ultrasonic(O)**: Mostra la distanza misurata dal modulo ultrasonico.
   * **Right IR(P)**: Mostra le letture del modulo di evitamento ostacoli destro.

.. _app_avoid:

Evitamento ostacoli (E)
------------------------

Tocca il widget **Avoid(E)** per attivare la modalità di evitamento ostacoli.

Prima di abilitare questa modalità, potrebbe essere necessario regolare le distanze di rilevamento dei sensori in base al tuo ambiente attuale, poiché le impostazioni di fabbrica potrebbero non essere ideali per tutte le situazioni.

Ecco come puoi regolare le impostazioni:

#. Inizia regolando il modulo di evitamento ostacoli destro. Durante il trasporto, gli urti possono causare l'inclinazione del trasmettitore e del ricevitore sul modulo a infrarossi. Quindi, è necessario raddrizzarli manualmente.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Posiziona un ostacolo a circa 20 cm di fronte al modulo destro. La scatola in cui è arrivato il nostro kit Rover è una buona scelta! Ora, gira il potenziometro sul modulo fino a quando la luce di indicazione sul modulo si accende. Successivamente, sposta l'ostacolo avanti e indietro per verificare se la luce di indicazione si accende alla distanza desiderata. Se la luce non si accende alla distanza corretta o rimane accesa senza spegnersi, dovrai regolare l'altro potenziometro.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>


#. Ripeti lo stesso processo per l'altro modulo.

.. _app_follow:

Seguimento (F)
-----------------

Quando sei pronto per attivare la modalità di follow, tocca semplicemente il widget **Follow(F)**. Se non hai precedentemente regolato la distanza di rilevamento dei moduli di evitamento ostacoli, dovrai seguire i passaggi in :ref:`app_avoid` prima.

Una volta in modalità di follow, il GalaxyRVR si muoverà verso un oggetto davanti a sé o girerà a sinistra o destra per seguire il movimento dell'oggetto.

.. _app_speech_control:

STT (J)
-------------------

STT sta per Speech to Text. L'app SunFounder Controller si integra con il motore di riconoscimento vocale del tuo dispositivo mobile. Pertanto, quando tocchi e tieni premuto il widget **STT(J)** sull'app SunFounder Controller e parli nel tuo dispositivo mobile,

Il tuo dispositivo catturerà il discorso, lo convertirà in testo e lo invierà al GalaxyRVR. Se questo testo corrisponde ai comandi preimpostati nel tuo codice, il Rover eseguirà le azioni corrispondenti.

I seguenti sono i comandi attualmente preimpostati nel codice. Pronuncia uno di questi comandi e osserva come risponde il GalaxyRVR.

.. image:: img/app/play_speech.png
    :width: 600

* ``stop``: Tutti i movimenti del rover si fermeranno.
* ``forward``: Fa muovere il rover in avanti.
* ``backward``: Fa muovere il rover indietro.
* ``left``: Fa girare il rover a sinistra.
* ``right``: Fa girare il rover a destra.

.. note::

    La funzione STT (Speech to Text) richiede una connessione a Internet e i servizi Google su dispositivi Android. Tuttavia, ciò non funziona con la modalità preimpostata AP (Access Point) sul GalaxyRVR.
    
    In modalità AP, il GalaxyRVR crea una rete Wi-Fi locale a cui il tuo dispositivo mobile può connettersi, ma non fornisce accesso a Internet.
    
    Per utilizzare la funzione STT su Android, passa il codice del Rover dalla modalità AP a STA come descritto in :ref:`stt_android`.

.. note::

    I dispositivi iOS, utilizzando un motore di riconoscimento vocale offline, funzionano bene sia in modalità AP che STA. 
