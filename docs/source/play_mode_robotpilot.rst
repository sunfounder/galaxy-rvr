.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Immergiti più a fondo in Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!


.. _play_robopilot:

Gioca con RoboPilot
=========================

Non vedi l'ora di iniziare subito il tuo viaggio su Marte? 
La modalità Play è perfetta per chi non può aspettare di immergersi nell'azione. 
Dotato di codice preinstallato in fabbrica, puoi iniziare immediatamente dopo aver assemblato il tuo GalaxyRVR. 
Usa l'app RoboPilot facile da usare per esplorare le sue numerose funzioni, inclusa la guida in prima persona e la possibilità di passare tra la modalità di evitamento ostacoli e quella di follow.


.. image:: img/robopilot/rp1_inter.png

Ma prima di partire per esplorare il Pianeta Rosso, assicuriamoci che tu sia completamente attrezzato e pronto per l'avventura. 
Ecco una Guida Rapida che ti assisterà in questo emozionante viaggio!

.. note::

    * Se la tua scheda R3 ha già caricato un altro codice, ma vuoi continuare a utilizzare la modalità Play, dovrai scaricare il codice pertinente.

        * :download:`GalaxyRVR Codes <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/scratch.zip>`

    * Installa |link_download_arduino|, quindi :ref:`install_lib`

    * Quindi, apri il file ``galaxy-rvr.ino`` situato nella directory ``galaxy-rvr-scratch\galaxy-rvr``.
    
    * Nel programma di esempio, ti verrà chiesto di connettere il tuo dispositivo mobile all'hotspot rilasciato da GalaxyRVR, il che ti impedirà di utilizzare contemporaneamente le reti esterne. Puoi :ref:`ap_to_sta`. Dopo aver impostato la modalità STA, finché il tuo dispositivo e GalaxyRVR sono nella stessa WLAN, potrai controllare GalaxyRVR.

    * Sposta l'interruttore a destra e poi clicca su **Upload**.

    .. image:: img/camera_upload.png
        :width: 400
        :align: center


Guida Rapida
---------------------

#. Avviamo il GalaxyRVR.

    * Alla prima accensione del tuo GalaxyRVR, ti consigliamo di collegare un cavo USB Type-C per caricare completamente la batteria. Poi accendi l'alimentazione.
    
        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/play_start.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    * Per attivare l'ESP32 CAM, sposta l'interruttore della modalità sulla posizione **Run** e premi il pulsante **reset** per riavviare la scheda R3. Vedrai quindi una luce ciano lampeggiare sulla striscia inferiore.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/play_reset.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

#. Installa **RoboPilot** da **APP Store(iOS)** o **Google Play(Android)**.

#. Connettiti alla rete ``GalaxyRVR``.

    Per una comunicazione ottimale tra il tuo dispositivo mobile e il Rover, dovrai collegarli alla stessa rete locale (LAN) fornita da GalaxyRVR.


    * Trova ``GalaxyRVR`` nell'elenco delle reti disponibili sul tuo dispositivo mobile (tablet o smartphone), inserisci la password ``12345678`` e connettiti.

        .. image:: img/app/camera_lan.png

    * La modalità di connessione predefinita è **modalità AP**. Dopo esserti connesso, potrebbe apparire un avviso che segnala l'assenza di accesso a internet su questa rete. Se accade, seleziona "Rimani connesso".

        .. image:: img/app/camera_stay.png


#. Apri RoboPilot. Clicca su "Go into" per entrare nell'interfaccia di controllo.

.. image:: img/robopilot/rp1_inter.png




Controllo remoto
----------------------------------------------

Entrando nell'interfaccia di controllo, vedrai la seguente schermata.
Lo sfondo mostra la vista catturata dalla telecamera del GalaxyRVR, con widget di controllo sovrapposti.

.. image:: img/robopilot/rp2_page.png

Ecco i controlli:

A. Indietro
B. Impostazioni: Qui puoi modificare il nome del dispositivo, le impostazioni WiFi, **regolare l'angolo della telecamera**, e disconnetterti.


    .. image:: img/robopilot/rp3_setting.png

C. Indicatore del livello della batteria
D. Pausa del programma
E. Selezione della modalità: Qui puoi scegliere tra le modalità ostacoli e remoto. L'impostazione predefinita è la modalità Remota.


    .. image:: img/robopilot/rp4_mode.png

F. Monitor ostacoli: Questo modulo è diviso in tre aree, con i lati sinistro e destro che mostrano i risultati dei moduli ostacoli e l'area centrale che visualizza i risultati del sensore a ultrasuoni.
G. Selettore del colore: Qui puoi scegliere il colore dell'illuminazione per il telaio.


    .. image:: img/robopilot/rp5_color.png

H. Interruttore LED della telecamera.
I. Regola l'angolo del gimbal, da 0 a 135°. A 0°, guarda verso il cielo.
J. Muovi il joystick per controllare il movimento di GalaxyRVR. Una leggera spinta farà muovere lentamente il GalaxyRVR.



Rilevamento ostacoli
-------------------------------

Quando passi alla modalità Ostacoli, vedrai la seguente interfaccia.
Ancora una volta, lo sfondo mostra la vista dalla telecamera del GalaxyRVR, con i controlli della modalità ostacoli sovrapposti.


.. image:: img/robopilot/rp6_avoid.png

Ecco i controlli:

A. Regola la velocità del GalaxyRVR.
B. Passa tra le modalità **Evitare** e **Seguire**.
C. Avvia/ferma il movimento automatico del GalaxyRVR.
D. Regola l'angolo del gimbal, da 0 a 135°. A 0°, guarda verso il cielo.
E. Monitor ostacoli: Questo modulo è diviso in tre aree, con i lati sinistro e destro che mostrano i risultati dei moduli ostacoli e l'area centrale che visualizza i risultati del sensore a ultrasuoni.


**Evitare**

.. Tocca il widget **Evitare(E)** per attivare la modalità di evitamento ostacoli.

Prima di abilitare questa modalità, potresti dover regolare i campi di rilevamento dei sensori in base al tuo ambiente attuale, poiché le impostazioni di fabbrica potrebbero non essere ideali per tutte le situazioni.

Se il campo di rilevamento dei due moduli a infrarossi è troppo corto, il Mars Rover potrebbe urtare contro gli ostacoli. Al contrario, se il campo è troppo lungo, il Rover potrebbe allontanarsi troppo da un ostacolo, potenzialmente compromettendo la sua navigazione.

Ecco come puoi ottimizzare le impostazioni:

#. Inizia regolando il modulo di evitamento ostacoli destro. Durante il trasporto, gli urti possono causare l'inclinazione del trasmettitore e del ricevitore sul modulo a infrarossi. Pertanto, è necessario raddrizzarli manualmente.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Posiziona un ostacolo a circa 20 cm direttamente davanti al modulo destro. La scatola in cui è arrivato il nostro kit Rover è una buona scelta per questo! Ora, ruota il potenziometro sul modulo finché la spia sul modulo non si accende. Poi, continua a muovere l'ostacolo avanti e indietro per verificare se la spia si accende alla distanza desiderata. Se la luce non si accende alla distanza corretta o rimane accesa senza spegnersi, dovrai regolare l'altro potenziometro.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>


#. Ripeti lo stesso processo per l'altro modulo.


**Seguire**

Se non hai precedentemente regolato la distanza di rilevamento dei moduli di evitamento ostacoli, 
dovrai seguire prima i passaggi descritti in **Evitare**.

Una volta in modalità seguire, 
il GalaxyRVR si muoverà verso un oggetto di fronte a sé o girerà a sinistra o a destra per seguirne il movimento.



Riconnettersi
-------------------------------

Se la tua rete fallisce o si disconnette, verrai reindirizzato a questa pagina.

.. image:: img/robopilot/rp7_reconnect.png

A questo punto, reimposta le impostazioni di rete, quindi clicca sull'IP corrispondente al tuo GalaxyRVR per riconnetterti.
