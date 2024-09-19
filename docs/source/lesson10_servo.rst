.. note::

    Ciao, benvenuto nella Community degli appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti speciali**: Godi di sconti esclusivi sui nostri nuovi prodotti.
    - **Promozioni festive e Giveaway**: Partecipa a giveaway e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!


Lezione 10: Esplorare il Sistema Visivo del Rover di Marte - Meccanismo di Servo e Inclinazione
=========================================================================================================

Bentornati, giovani esploratori! Nell'avventura di oggi, ci immergeremo nel mondo affascinante del sistema visivo del nostro Rover di Marte. 
Proprio come i nostri occhi e il nostro collo lavorano insieme per aiutarci a vedere e navigare nell'ambiente circostante, anche il nostro Rover ha bisogno di un sistema simile per esplorare il terreno accidentato di Marte. E oggi costruiremo esattamente questo!

Il sistema visivo del nostro Rover ha due componenti principali: una telecamera che funge da "occhi" e un meccanismo di inclinazione che funge da "collo", consentendogli di guardare su e giù. Alla fine di questa lezione, daremo al nostro Rover la capacità di "vedere" e "annuire"!

Per prima cosa, costruiremo il meccanismo di inclinazione: un dispositivo che terrà la telecamera del nostro Rover e le permetterà di ruotare verticalmente. 
È come dare al nostro Rover un collo, così può annuire con la sua "testa" o la telecamera su e giù!

Successivamente, impareremo a conoscere il servo, il piccolo ma potente "muscolo" che muove il nostro meccanismo di inclinazione. 
Capiremo come funziona e come possiamo controllarlo utilizzando la programmazione di Arduino.

Proprio come i nostri muscoli del collo muovono la testa per ottenere una migliore visuale, il servo muoverà il meccanismo di inclinazione per permettere alla telecamera del Rover di osservare meglio il paesaggio marziano.

Allora, preparatevi, esploratori! Iniziamo la nostra missione per dotare il nostro Rover di un sistema visivo tutto suo!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/servo_range.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>


Obiettivi
----------------

* Pratica nell'installazione e funzionamento del meccanismo di inclinazione sul modello del Rover di Marte.
* Comprendere i principi di funzionamento e applicazione del servo.
* Imparare a controllare il movimento del servo tramite la programmazione di Arduino.

Materiali
---------------

* Scheda di sviluppo Arduino UNO
* Servo
* Gimbal e telecamera
* Modello Rover di Marte (già equipaggiato con motore TT, sistema di sospensione, moduli di evitamento ostacoli a ultrasuoni e infrarossi, striscia LED RGB)
* Arduino IDE
* Computer

Passaggi
-----------

**Passo 1: Che cos'è un Servo?**

Hai mai visto uno spettacolo di marionette? Se sì, forse ti sei stupito di come il burattinaio possa muovere braccia, gambe e testa della marionetta così fluidamente, semplicemente tirando alcune corde. In un certo senso, i motori servo sono come i nostri burattinai.

.. image:: img/puppet_show.png
    :width: 200
    :align: center

I motori servo sono un tipo speciale di motori che non girano semplicemente in tondo come una ruota. Invece, possono muoversi verso una posizione specifica e mantenerla. Immagina di giocare a "Simon dice" e Simon ti dice: "Alza il braccio a 90 gradi!". Puoi farlo, vero? Questo perché, come un servo, puoi controllare esattamente quanto muovere il tuo braccio.

.. image:: img/servo.png
    :align: center

* Filo marrone: GND
* Filo arancione: pin del segnale, collegalo al pin PWM della scheda principale.
* Filo rosso: VCC

Proprio come puoi controllare il movimento delle tue braccia in posizioni specifiche, possiamo usare i motori servo per controllare la posizione esatta degli oggetti nei nostri progetti. Nel nostro Rover di Marte, useremo un servo per controllare il movimento su e giù del meccanismo di inclinazione, proprio come puoi annuire con la testa su e giù.

Nel prossimo passaggio, intraprenderemo un viaggio affascinante all'interno di un motore servo per capire come funziona. Sei entusiasta? Andiamo!
* Filo marrone: GND
* Filo arancione: Pin del segnale, collegare al pin PWM della scheda principale.
* Filo rosso: VCC

Proprio come puoi controllare le tue braccia per muoverle in posizioni specifiche, possiamo utilizzare i motori servo per controllare la posizione esatta degli oggetti nei nostri progetti. Nel nostro Mars Rover, utilizzeremo un servo per controllare il movimento su e giù del meccanismo di inclinazione, proprio come quando annuisci con la testa su e giù.

Nel prossimo passaggio, intraprenderemo un affascinante viaggio all'interno di un motore servo per capire come funziona. Sei pronto? Andiamo!

**Passo 2: Come funziona un servo?**

Quindi, come fa un servo a compiere la sua magia? Andiamo a scoprire i segreti all'interno di un servo!

Se dovessimo dare uno sguardo all'interno di un servo, vedremmo alcune parti. Al centro del servo c'è un motore normale, molto simile a quelli che fanno girare le ruote del nostro Mars Rover. Intorno al motore c'è un grande ingranaggio collegato a un ingranaggio più piccolo sull'albero del motore. Questo è il modo in cui il movimento veloce e circolare del motore viene trasformato in un movimento più lento ma più potente.

.. image:: img/servo_internal.png
    :align: center

Ma non è questo ciò che rende speciale un servo. La magia avviene in un piccolo componente elettronico chiamato "potenziometro" e nel "circuito di controllo". Ecco come funziona: quando il servo si muove, il potenziometro ruota e cambia la sua resistenza. Il circuito di controllo misura questo cambiamento di resistenza e sa esattamente in che posizione si trova il servo. Intelligente, vero?

Per controllare un servo, inviamo un tipo speciale di segnale chiamato "modulazione della larghezza di impulso" o PWM. Modificando la larghezza di questi impulsi, possiamo controllare esattamente quanto si muove il servo e mantenerlo in quella posizione.

Nel prossimo passaggio, impareremo come controllare un servo usando un Arduino. Pronti per lanciare incantesimi sotto forma di codice? Andiamo!

**Passo 3: Controllare un servo con Arduino**

Bene, esploratori, ora che sappiamo come funziona un servo, impariamo a controllarlo con la nostra bacchetta magica, l'Arduino!

Controllare un servo è come dargli istruzioni. Ricordi i segnali di modulazione della larghezza di impulso (PWM) di cui abbiamo parlato prima? Useremo questi segnali per dire al servo dove muoversi.

Fortunatamente, Arduino semplifica questo compito con una libreria integrata chiamata ``Servo``. Con questa libreria, possiamo creare un oggetto ``Servo``, collegare un pin (quello a cui è collegato il nostro servo) e poi utilizzare un semplice comando, ``write()``, per impostare l'angolo.

Ecco un esempio di codice:

.. code-block:: arduino

    #include <Servo.h> 

    Servo myServo;  // crea un oggetto servo

    void setup() {
        myServo.attach(6);  // collega il servo al pin 6
    }

    void loop() {
        myServo.write(90);  // dice al servo di andare a 90 gradi
    }

In questo codice, ``myServo`` è il nostro oggetto Servo, ``attach(6)`` dice ad Arduino che il nostro servo è collegato al pin 6, e ``write(90)`` dice al servo di muoversi a 90 gradi.

Ottimo lavoro, esploratori! Avete appena imparato come controllare un motore servo con Arduino. Potete anche sperimentare con angoli diversi!

**Passo 4: Assemblare il sistema visivo**

Ora sei pronto per assemblare il sistema visivo del nostro Rover.

.. note::

    * Quando inserisci l'ESP32 CAM nell'adattatore per la telecamera, fai attenzione all'orientamento. Dovrebbe allinearsi correttamente con l'adattatore ESP32.

    .. image:: img/esp32_cam_direction.png
        :width: 300
        :align: center
    
.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/h43JVI3xLqE?si=Q7-RvRvZOusK7vPo" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Passo 5: Capire i limiti del meccanismo di inclinazione**

Anche se il servo è progettato per ruotare tra 0 e 180 gradi, potresti notare che smette di rispondere oltre un certo punto (diciamo dopo 150 gradi). Ti sei mai chiesto perché accade? Esploriamo questo mistero nella nostra prossima avventura!


Riesci a immaginare un uccello che cerca di piegare troppo il collo fino a colpire il proprio corpo e non riuscire a muoversi oltre? Il meccanismo di inclinazione del nostro Rover si trova in una situazione simile. Quando il servo abbassa il meccanismo, può urtare il corpo del Rover e non riuscire a superare un certo angolo.

Se proviamo a forzarlo a muoversi oltre questo punto impostando un angolo irraggiungibile nel nostro codice, il nostro piccolo servo potrebbe bloccarsi e persino danneggiarsi! Non vogliamo che succeda, vero? Quindi, cerchiamo di capire i suoi limiti di movimento con un piccolo esperimento.

Utilizziamo un ciclo for per far ruotare il servo da 0 a 180 gradi, tenendo traccia dell'angolo nel Monitor Seriale.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/848c7a3a-16b2-4a7e-8d66-bb91848bc6d9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

* L'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, dovrai prima disconnettere l'ESP32-CAM facendo scorrere questo interruttore verso destra per evitare conflitti o problemi potenziali.

    .. image:: img/camera_upload.png
        :width: 600

* Dopo aver caricato il codice, apri il **Monitor Seriale**. Se non appare nessuna informazione, premi il **pulsante di Reset** sullo scudo GalaxyRVR per eseguire nuovamente il codice. 

* Vedrai il servo ruotare e il Monitor Seriale mostrerà l'angolo.

.. image:: img/servo_range.png

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/servo_range.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>
    
Sul mio Rover, il meccanismo di inclinazione poteva raggiungere circa 140° prima di colpire il corpo del Rover e non poteva andare oltre.


Quindi, esploratori, ricordate sempre di rispettare i limiti del vostro Rover per mantenerlo sicuro e funzionante!


**Passo 6: Condivisione e riflessione**


Ben fatto, esploratori! Oggi non solo avete costruito un meccanismo di inclinazione per il vostro Rover, ma avete anche imparato a controllare un servo per muoverlo. Questo è un grande passo avanti nella nostra missione Mars Rover.

Ora, condividiamo le nostre esperienze e riflettiamo su ciò che abbiamo imparato.

Avete incontrato qualche difficoltà durante l'installazione del meccanismo di inclinazione o la programmazione del servo? Come le avete superate?

Ricordate, ogni sfida che superiamo ci rende più intelligenti e migliora il nostro Rover. Quindi non esitate a condividere le vostre storie, idee e soluzioni. Non si sa mai, la vostra soluzione innovativa potrebbe aiutare un altro esploratore nel suo viaggio!

