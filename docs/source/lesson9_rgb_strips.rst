.. note::

    Ciao, benvenuto nella Community di appassionati di Raspberry Pi, Arduino ed ESP32 di SunFounder su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a omaggi e promozioni durante le festività.

    👉 Sei pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!


Lezione 9: Illuminare la strada con strisce LED RGB
=============================================================

Nel nostro percorso fino ad ora, abbiamo trasformato il nostro Mars Rover in un esploratore intelligente, capace di muoversi abilmente evitando ostacoli. È diventato piuttosto abile nel navigare nei terreni simili a quelli marziani che abbiamo predisposto per lui.

Ma cosa succederebbe se potessimo aggiungere un po' di stile alla sua praticità? Diamogli la capacità di esprimersi attraverso uno spettacolo di colori e luci. Parliamo dell'integrazione delle strisce LED RGB: una funzione accattivante che permetterebbe al nostro Rover di illuminare il suo cammino, anche nelle condizioni più buie.

Immagina questo: il Rover lascia una scia di segnali colorati, rendendo più facile comprendere i suoi movimenti. Una luce verde quando è in movimento, un rosso deciso quando si ferma, o un giallo lampeggiante durante quelle virate rapide. Potrebbe persino illuminarsi in una serie di colori, solo per il puro divertimento!

Il nostro obiettivo in questa lezione è comprendere i principi delle strisce LED RGB, imparare a controllarne colore e luminosità, e poi sincronizzarli con i movimenti del Rover. Alla fine, il nostro Mars Rover sarà più di una semplice macchina: sarà un'entità luminosa e multicolore che guida la strada nel vasto paesaggio marziano!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/car_rgb.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::

    Se stai seguendo questo corso dopo aver assemblato completamente il GalaxyRVR, devi spostare questo interruttore verso destra prima di caricare il codice.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Obiettivi
------------- 

* Comprendere i principi di funzionamento e le applicazioni delle strisce LED RGB.
* Imparare a utilizzare la programmazione Arduino per controllare il colore e la luminosità delle strisce LED RGB.
* Praticare l'installazione e l'uso delle strisce LED RGB sul modello del Mars Rover come indicatori.

Materiali necessari
------------------------- 

* Strisce LED RGB (ogni striscia ha 8 LED RGB, un totale di due strisce)
* Strumenti e accessori di base (ad es. cacciavite, viti, fili, ecc.)
* Modello del Mars Rover (dotato di sistema rocker-bogie, schede principali, motori, modulo di evitamento ostacoli, modulo ultrasonico)
* Cavo USB
* Arduino IDE
* Computer

Passaggi del corso
-------------------------
**Passo 1: Installa le strisce LED RGB sul Mars Rover**

Ora, fissa le due strisce LED RGB ai lati inferiori del rover. Sono controllate da un unico set di pin, quindi non è necessario differenziarle durante il cablaggio.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/v4YGjNwPOJE" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Passo 2: Esplora la magia della luce con le strisce LED RGB**

Ti ricordi l'ultima volta che hai visto un arcobaleno? Come ha colorato il cielo con sette tonalità vivaci? Che ne dici di creare il tuo arcobaleno, proprio qui nel nostro piccolo rover marziano? Immergiamoci nella magia della luce con le strisce LED RGB!

.. image:: img/4_rgb_strip.jpg

Potresti notare che la nostra striscia LED RGB ha quattro pin etichettati come segue:

* **+5V**: Questo è il "positivo" comune o l'"anodo" delle tre piccole lampadine (LED) all'interno della nostra striscia. Deve essere collegato a 5V DC, una sorta di energia elettrica che alimenta le nostre piccole lampadine!
* **B**: Questo è l'estremità "negativa" o il "catodo" del LED blu.
* **R**: Questo è il "catodo" del LED rosso.
* **G**: Questo è il "catodo" del LED verde.

.. image:: img/rgb_5050.jpg

Ti ricordi i tre colori primari - rosso, blu e verde - che abbiamo imparato a lezione di arte? Proprio come un artista mescola questi colori sulla sua tavolozza per creare nuove tonalità, la nostra striscia contiene 4 LED "5050" che possono mescolare questi colori primari per creare virtualmente qualsiasi colore! Ogni LED "5050" è come un piccolo studio artistico che ospita queste tre lampadine colorate.

.. image:: img/rgb_5050_sche.png

Questi piccoli studi artistici sono poi collegati in modo intelligente su un circuito flessibile, simile a una mini autostrada elettrica! Le estremità "positive" di tutti i LED (anodi) sono collegate insieme, mentre le estremità "negative" (catodi) sono collegate alle rispettive linee di colore (G a G, R a R, B a B).

.. image:: img/rgb_strip_sche.png

E la parte più bella? Con il nostro comando, tutti i LED su questa striscia possono cambiare colore contemporaneamente! È come avere una nostra orchestra di luci a portata di mano!

Quindi prepariamoci a suonare un po' di musica di luce! Nel prossimo passo, impareremo a controllare questi LED per visualizzare i colori che desideriamo. Sarà come dirigere una sinfonia di luce!


**Passo 3: Accendi lo spettacolo - Codifica per controllare le strisce LED RGB**

Abbiamo messo piede nel regno dei colori, è ora di dare vita al nostro Mars Rover. Preparati a dipingere l'oscurità con uno spettro di colori usando le strisce LED RGB. Pensalo come un'occasione per trasformare il tuo Mars Rover in una festa mobile!

* Prima di entrare nella parte divertente, capiamo che, anche se abbiamo due strisce LED, entrambe sono controllate dallo stesso set di pin. Pensalo come avere due ballerini scintillanti che si muovono in perfetta sincronia!

    .. image:: img/rgb_shield.png

* È ora di evocare la nostra magia di codifica. Inizieremo i nostri pin con il codice Arduino.

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Definisci i numeri dei pin per le strisce RGB
        const int bluePin = 11;
        const int redPin = 12;
        const int greenPin = 13;

* Con i nostri pin a posto, ora useremo la funzione ``SoftPWMSet()`` per controllare questi pin. Per far visualizzare il colore rosso sulla striscia RGB, accendiamo il LED rosso e spegniamo gli altri.

    .. code-block:: arduino

        void setup() {
            // Inizializza il PWM basato su software su tutti i pin
            SoftPWMBegin();
        }

        void loop() {
            // Imposta il colore su rosso accendendo il LED rosso e spegnendo gli altri
            SoftPWMSet(redPin, 255); // 255 è la massima luminosità
            SoftPWMSet(greenPin, 0); // 0 è spento
            SoftPWMSet(bluePin, 0);  // 0 è spento
            delay(1000); // Attendi 1 secondo
        }

Nel codice sopra, abbiamo mostrato solo come visualizzare un singolo colore. 

Se volessimo mostrare una varietà di colori usando questo metodo, il codice potrebbe diventare piuttosto ingombrante. Pertanto, per rendere il nostro codice più conciso e manutenibile, possiamo creare una funzione per assegnare valori PWM ai tre pin. Poi, all'interno del ``loop()``, possiamo facilmente impostare una moltitudine di colori.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cac90501-04c1-44c2-a1d7-4f863e50f186/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo aver caricato il codice sulla tua scheda R3, potresti notare che i colori arancione e giallo sembrano un po' sfasati. 
Questo perché il LED rosso sulla striscia è relativamente più debole rispetto agli altri due LED. 
Quindi, sarà necessario introdurre valori di offset nel tuo codice per correggere questa discrepanza cromatica.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/60ec867f-5637-44bd-b72d-4709fc4f5349/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Ora la striscia LED RGB dovrebbe essere in grado di visualizzare i colori corretti. Se noti ancora delle discrepanze, puoi regolare manualmente i valori di ``R_OFFSET``, ``G_OFFSET`` e ``B_OFFSET``.

Sentiti libero di sperimentare e visualizzare qualsiasi colore tu desideri sulla striscia LED. Tutto ciò che devi fare è inserire i valori RGB del colore che vuoi.

Ecco un suggerimento: puoi utilizzare lo strumento Paint sul tuo computer per determinare i valori RGB del colore desiderato.

.. image:: img/rgb_paint.png

Ora che abbiamo padroneggiato l'arte di impostare i colori, nel prossimo passo integreremo questi spettacolari effetti luminosi con i movimenti del Mars Rover. Tempi entusiasmanti ci attendono!

**Passo 4: Muovi il Rover con l'indicazione dei colori**

Ora aggiungeremo le indicazioni di colore ai movimenti del Mars Rover. Ad esempio, possiamo usare il verde per avanzare, il rosso per indietreggiare e il giallo per girare a sinistra o a destra.

Per fare ciò, aggiungeremo un meccanismo di controllo nel nostro codice che imposta il colore della striscia LED in base al movimento del Rover. Questo comporterà la modifica del nostro codice di controllo del Rover per includere le nostre funzioni di controllo dei colori.

Vediamo un esempio di come possiamo fare:

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/5412eebe-75b8-4f98-a348-f0889e8a7fde/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

All'interno della funzione ``loop()``, abbiamo comandato al Rover di eseguire una serie di azioni chiamando diverse funzioni. 
Ogni azione aveva la sua corrispondente visualizzazione del colore - verde per avanzare, rosso per indietreggiare e giallo per girare. 
Questa funzione di visualizzazione del colore è stata resa possibile usando la funzione ``setColor()``, che ha manipolato la luminosità di ciascun canale di colore RGB.

Per l'azione di arresto, abbiamo introdotto un elemento coinvolgente: un effetto di "respiro" con una luce rossa e blu. 
Questo è stato ottenuto regolando ciclicamente la luminosità dei canali rosso e blu all'interno della funzione ``stopMove()``. 
Così, quando si fermava, la striscia LED passava tra il rosso e il blu, creando un effetto visivo dinamico.

Ora il nostro Mars Rover possiede i suoi effetti di colore vivaci, lasciando dietro di sé una scia di segnali codificati a colori, ognuno dei quali rappresenta un movimento unico. 

Attraverso questo progetto, abbiamo scoperto come le materie STEAM possano amalgamarsi per dare vita a una 
macchina ordinaria, trasformandola in uno strumento di apprendimento vibrante, interattivo e divertente.


**Passo 5: Riflessioni e riepilogo**

Nella lezione di oggi, ci siamo addentrati nel mondo delle strisce LED RGB, esplorando come manipolarle per mostrare una vivida gamma di colori. Questi brillanti colori hanno dato nuova vita al nostro Mars Rover, trasformandolo da semplice macchina a uno spettacolo luminoso.

Ora, ti invito a riflettere: se fossi tu al comando, come utilizzeresti questi colori per migliorare il tuo Mars Rover? Quali effetti unici vorresti che mostrasse?

Inoltre, attraverso il processo, spero che tu abbia acquisito una comprensione pratica di come i concetti STEAM possano essere intrecciati in un progetto coinvolgente, offrendoti una prospettiva più ampia delle sue applicazioni pratiche.

Ci vediamo nella nostra prossima entusiasmante avventura!
