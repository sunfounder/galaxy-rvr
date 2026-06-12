.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Lezione 10: Esplorare il sistema visivo del Mars Rover - Servo e meccanismo di inclinazione
===========================================================================================

Bentornati, giovani esploratori! Nell'avventura di oggi, ci addentreremo nell'affascinante mondo del sistema visivo del Mars Rover.
Proprio come i nostri occhi e il collo lavorano insieme per aiutarci a vedere e navigare nell'ambiente circostante, anche il nostro Rover ha bisogno di un sistema simile per
navigare il pericoloso paesaggio marziano. Ed è esattamente ciò che costruiremo oggi!

Il sistema visivo del nostro Rover ha due parti principali: una fotocamera che funge da "occhi" e un meccanismo di inclinazione che funge da "collo",
permettendogli di guardare su e giù. Alla fine di questa lezione, daremo al nostro Rover la capacità di "vedere" e "annuire"!

Per prima cosa, costruiremo il meccanismo di inclinazione, un dispositivo che terrà la fotocamera del nostro Rover e le permetterà di ruotare verticalmente.
È come dare al nostro Rover un collo, così può annuire con la sua "testa" o fotocamera su e giù!

Successivamente, impareremo a conoscere il servo, il piccolo ma potente "muscolo" che muove il nostro meccanismo di inclinazione.
Capiremo come funziona e come possiamo controllarlo usando la programmazione Arduino.

Proprio come i muscoli del nostro collo muovono la nostra testa in modo che i nostri occhi possano avere una visuale migliore, il servo muoverà il meccanismo di inclinazione in modo che la
fotocamera del Rover possa meglio osservare il paesaggio marziano.

Quindi, allacciate le cinture, esploratori, iniziamo la nostra missione per equipaggiare il nostro Rover con il suo proprio sistema visivo!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/servo_range.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>


Obiettivo
----------------

* Esercitarsi nell'installazione e nel funzionamento del meccanismo di inclinazione sul modello Mars Rover.
* Comprendere i principi di funzionamento e applicazione del servo.
* Imparare a controllare il movimento del servo attraverso la programmazione Arduino.

Materiali
---------------

* Scheda di sviluppo Arduino UNO
* Servo
* Gimbal e fotocamera
* Modello Mars Rover (già equipaggiato con motore TT, sistema di sospensione, moduli evitamento ostacoli a ultrasuoni e infrarossi, striscia LED RGB)
* Arduino IDE
* Computer

Procedura
-----------

**Fase 1: Cos'è un servo?**

Hai mai visto uno spettacolo di marionette? Se sì, potresti esserti meravigliato di come il burattinaio possa far muovere così dolcemente le braccia, le gambe e la testa del burattino, semplicemente tirando alcune corde. In un certo senso, i servomotori sono come i nostri burattinai.

.. image:: img/puppet_show.png
    :width: 200
    :align: center

I servomotori sono un tipo speciale di motori che non girano semplicemente come una ruota. Invece, possono spostarsi in una posizione specifica e mantenerla. Immagina di giocare a "Simon dice" e Simon dice: "Alza il braccio a un angolo di 90 gradi!" Puoi farlo, vero? Questo perché, come un servo, puoi controllare esattamente quanto muovere il braccio.

.. image:: img/servo.png
    :align: center

* Linea marrone: GND
* Linea arancione: Pin di segnale, collegare al pin PWM della scheda principale.
* Cavo rosso: VCC

Proprio come puoi controllare le tue braccia per muoverti in posizioni specifiche, possiamo usare i servomotori per controllare la posizione esatta degli oggetti nei nostri progetti. Nel nostro Mars Rover, useremo un servo per controllare il movimento su e giù del nostro meccanismo di inclinazione, proprio come puoi annuire con la testa su e giù.

Nel prossimo passo, faremo un affascinante viaggio all'interno di un servomotore per capire come funziona. Emozionato? Andiamo!

**Fase 2: Come funziona un servo?**

Quindi come fa un servo a fare la sua magia? Facciamo un emozionante viaggio all'interno di un servo!

Se dovessimo sbirciare dentro un servo, vedremmo alcune parti. Al cuore di un servo c'è un motore normale, molto simile ai motori che fanno girare le ruote del nostro Mars Rover. Avvolto intorno al motore, c'è un grande ingranaggio collegato a un ingranaggio più piccolo sull'albero motore. È così che il veloce movimento circolare del motore viene trasformato in un movimento più lento ma più forte.

.. image:: img/servo_internal.png
    :align: center

Ma non è questo che rende speciale un servo. La magia avviene in un minuscolo componente elettronico chiamato "potenziometro" e nel "circuito di controllo". Ecco come funziona: quando il servo si muove, il potenziometro gira e cambia la sua resistenza. Il circuito di controllo misura questo cambiamento di resistenza e sa esattamente in quale posizione si trova il servo. Ingegnoso, vero?

Per controllare un servo, gli inviamo un tipo speciale di segnale chiamato "modulazione a larghezza di impulso" o PWM. Cambiando la larghezza di questi impulsi, possiamo controllare esattamente quanto si muove il servo e mantenerlo in quella posizione.

Nel prossimo passo, impareremo come controllare un servo usando un Arduino. Pronto per alcuni incantesimi magici sotto forma di codice? Andiamo!

**Fase 3: Controllare un servo usando Arduino**

Bene, esploratori, ora che sappiamo come funziona un servo, impariamo a controllarlo usando la nostra bacchetta magica, Arduino!

Controllare un servo è come dargli delle direzioni. Ricordi i segnali di modulazione a larghezza di impulso (PWM) che abbiamo menzionato prima? Li useremo per dire al servo dove muoversi.

Fortunatamente, Arduino rende questo compito facile per noi con una libreria integrata chiamata ``Servo``. Con questa libreria, possiamo creare un oggetto ``Servo``, collegarlo a un pin (il pin a cui è connesso il nostro servo) e poi usare un semplice comando, ``write()``, per impostare l'angolo.

Ecco un frammento di come appare il codice:

.. code-block:: arduino

    #include <Servo.h>

    Servo myServo;  // create a servo object

    void setup() {
        myServo.attach(6);  // attaches the servo on pin 6
    }

    void loop() {
        myServo.write(90);  // tell servo to go to 90 degrees
    }

In questo codice, ``myServo`` è il nostro oggetto Servo, ``attach(6)`` dice ad Arduino che il nostro servo è collegato al pin 6, e ``write(90)`` dice al servo di muoversi a 90 gradi.

Ottimo lavoro, esploratori! Avete appena imparato a controllare un servomotore con Arduino. Potete anche sperimentare con angoli diversi!

**Fase 4: Assemblare il sistema visivo**

Ora sei pronto per assemblare il sistema visivo del nostro Rover.

.. note::

    * Quando inserisci l'ESP32 CAM nell'adattatore per fotocamera, fai attenzione al suo orientamento. Dovrebbe allinearsi correttamente con l'adattatore ESP32.

    .. image:: img/esp32_cam_direction.png
        :width: 300
        :align: center

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/h43JVI3xLqE?si=Q7-RvRvZOusK7vPo" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Fase 5: Comprendere i limiti del meccanismo di inclinazione**

Anche se il servo è progettato per ruotare tra 0 e 180 gradi, potresti notare che smette di rispondere oltre un certo punto (diciamo dopo 150 gradi). Ti sei mai chiesto perché questo accade? Esploriamo insieme questo mistero nella nostra prossima avventura!


Riesci a immaginare un uccello che cerca di piegare il collo così tanto da colpire il proprio corpo e non potersi più muovere? Il meccanismo di inclinazione del nostro Rover affronta una situazione simile. Mentre il servo muove il meccanismo verso il basso, può urtare il corpo del nostro Rover e non può andare oltre un certo angolo.

Se proviamo a forzarlo a muoversi oltre questo punto scrivendo un angolo irraggiungibile nel nostro codice, il nostro piccolo uccellino servo può bloccarsi e persino danneggiarsi! Non vogliamo che questo accada, vero? Quindi, comprendiamo i suoi limiti di movimento con un piccolo esperimento.

Usiamo un ciclo for per ruotare il servo da 0 a 180 gradi tenendo nota dell'angolo nel Monitor Seriale.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/848c7a3a-16b2-4a7e-8d66-bb91848bc6d9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

* L'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Quindi, prima di caricare il codice, devi prima rilasciare l'ESP32-CAM facendo scorrere questo interruttore sul lato destro per evitare conflitti o potenziali problemi.

    .. image:: ../img/camera_upload.png
        :width: 600

* Dopo aver caricato questo codice, apri il **Monitor Seriale**. Se non appare alcuna informazione, premi il **pulsante Reset** sullo shield GalaxyRVR per eseguire nuovamente il codice.

* Vedrai il servo ruotare e il Monitor Seriale visualizzerà l'angolo.

.. image:: img/servo_range.png

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/servo_range.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

Sul mio Rover, il meccanismo di inclinazione poteva arrivare fino a circa 135° prima di colpire il corpo del Rover e non poter andare oltre.

Quindi, esploratori, ricordate sempre di rispettare i limiti del vostro rover per mantenerlo sicuro e funzionante!


**Fase 6: Condivisione e riflessione**

Ben fatto, esploratori! Oggi non solo avete costruito un meccanismo di inclinazione per il vostro Rover, ma avete anche capito come controllare un servo per muoverlo. Questo è un grande passo avanti nella nostra missione Mars Rover.

Ora, condividiamo le nostre esperienze e riflettiamo su ciò che abbiamo imparato.

Avete incontrato sfide durante la configurazione del meccanismo di inclinazione o la programmazione del servo? Come le avete superate?

Ricorda, ogni sfida che superiamo ci rende più intelligenti e il nostro Rover migliore. Quindi non esitare a condividere le tue storie, idee e soluzioni. Non si sa mai, la tua soluzione innovativa potrebbe aiutare un compagno esploratore nel suo viaggio!
