.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!


Lezione 9: Illuminare il cammino con strisce LED RGB
============================================================

Nel nostro viaggio finora, abbiamo trasformato il nostro Mars Rover in un esploratore intelligente, capace di manovrare abilmente intorno agli ostacoli. È diventato piuttosto abile nel navigare i terreni simili a Marte che abbiamo allestito per lui.

Ma cosa succederebbe se potessimo aggiungere un tocco di stile alla sua praticità? Diamo al nostro Rover la capacità di esprimersi attraverso uno spettacolo di colori e luci. Stiamo parlando di incorporare strisce LED RGB, una caratteristica fantastica che permetterebbe al nostro Rover di illuminare il suo cammino, anche nelle condizioni più buie.

Immagina questo: il Rover lascia una scia di segnali codificati a colori, rendendo più facile per noi capire le sue mosse. Un bagliore verde quando è in movimento, un rosso severo quando si ferma, o un giallo lampeggiante durante quelle rapide virate. Potrebbe persino illuminarsi in una serie di colori solo per il puro divertimento!

Il nostro obiettivo in questa lezione è comprendere i principi delle strisce LED RGB, imparare a controllare il loro colore e luminosità, e poi sincronizzare questo con i movimenti del Rover. Alla fine, il nostro Mars Rover sarà più di una macchina. Sarà un'entità luminosa e cangiante, che apre la strada nel vasto paesaggio marziano!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/car_rgb.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::

    Se stai seguendo questo corso dopo aver completamente assemblato il GalaxyRVR, devi spostare questo interruttore a destra prima di caricare il codice.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Obiettivo
-------------

* Comprendere i principi di funzionamento e le applicazioni delle strisce LED RGB.
* Imparare a usare la programmazione Arduino per controllare il colore e la luminosità delle strisce LED RGB.
* Esercitarsi nell'installazione e nell'uso delle strisce LED RGB sul modello Mars Rover come indicatori.

Materiali necessari
-------------------------

* Strisce LED RGB (ogni striscia ha 8 LED RGB, per un totale di due strisce)
* Strumenti e accessori di base (es. cacciavite, viti, cavi, ecc.)
* Modello Mars Rover (dotato di sistema rocker-bogie, schede principali, motori, modulo evitamento ostacoli, modulo a ultrasuoni)
* Cavo USB
* Arduino IDE
* Computer

Procedura del corso
-------------------
**Fase 1: Installare le strisce LED RGB sul Mars Rover**

Ora, fissa le due strisce luminose RGB ai lati inferiori dell'auto. Sono controllate da un unico set di pin, quindi non c'è bisogno di differenziarle durante il processo di cablaggio.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/v4YGjNwPOJE" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Fase 2: Esplorare la magia della luce con le strisce LED RGB**

Ricordi l'ultima volta che hai visto un arcobaleno? Come ha reso il cielo colorato con sette tonalità vibranti? Ti piacerebbe creare il tuo arcobaleno, proprio qui nel nostro piccolo rover marziano? Immergiamoci nella magia della luce con le strisce LED RGB!

.. image:: img/4_rgb_strip.jpg

Potresti notare che la nostra striscia LED RGB ha quattro pin etichettati come segue:

* **+5V**: Questo è il "polo positivo" comune o l'"anodo" delle tre piccole lampadine (LED) all'interno della nostra striscia. Deve connettersi a 5V CC, una sorta di succo elettrico che alimenta le nostre piccole lampadine!
* **B**: Questo è il "polo negativo" o il "catodo" del LED blu.
* **R**: Questo è il "catodo" del LED rosso.
* **G**: Questo è il "catodo" del LED verde.

.. image:: img/rgb_5050.jpg

Ricordi i tre colori primari - Rosso, Blu e Verde - che abbiamo imparato nella nostra classe d'arte? Proprio come un artista mescola questi colori sulla sua tavolozza per creare nuove tonalità, la nostra striscia contiene 4 LED "5050" che possono mescolare questi colori primari per creare virtualmente qualsiasi colore! Ogni LED "5050" è come un piccolo studio d'arte che ospita queste tre lampadine colorate.

.. image:: img/rgb_5050_sche.png

Questi piccoli studi d'arte sono poi collegati in modo intelligente su un circuito flessibile, una specie di mini autostrada elettrica! Le estremità "positive" di tutti i LED (anodi) sono collegate insieme, mentre le estremità "negative" (catodi) sono collegate alle loro corrispondenti linee di colore (G a G, R a R, B a B).

.. image:: img/rgb_strip_sche.png

E la parte più bella? Con il nostro comando, tutti i LED su questa striscia possono cambiare i loro colori contemporaneamente! È come avere la nostra orchestra di luci a portata di mano!

Quindi prepariamoci a suonare un po' di musica leggera! Nel nostro prossimo passo, impareremo come controllare questi LED per visualizzare i colori che vogliamo. Sarà come dirigere una sinfonia di luce!


**Fase 3: Accendere lo spettacolo - Codifica per controllare le strisce LED RGB**

Siamo entrati nel regno dei colori, è il momento di dare vita al nostro Mars Rover. Preparati a dipingere l'oscurità con uno spettro di colori usando le strisce LED RGB. Pensa a questo come un'opportunità per trasformare il tuo Mars Rover in una festa da discoteca mobile!

* Prima di immergerci nella parte divertente, comprendiamo che anche se abbiamo due strisce LED, sono entrambe controllate dallo stesso set di pin. Pensalo come avere due ballerini abbaglianti che si muovono in perfetta sincronizzazione!

    .. image:: img/rgb_shield.png

* È il momento di evocare la nostra magia di codifica. Inizializzeremo i nostri pin con il codice Arduino.

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Define the pin numbers for the RGB strips
        const int bluePin = 11;
        const int redPin = 12;
        const int greenPin = 13;

* Con i nostri pin a posto, useremo ora la funzione ``SoftPWMSet()`` per controllare questi pin. Per far visualizzare alla striscia RGB il colore rosso, accendiamo il LED rosso e spegniamo gli altri.

    .. code-block:: arduino

        void setup() {
            // Initialize software-based PWM on all pins
            SoftPWMBegin();
        }

        void loop() {
            // Set the color to red by turning the red LED on and the others off
            SoftPWMSet(redPin, 255); // 255 is the maximum brightness
            SoftPWMSet(greenPin, 0); // 0 is off
            SoftPWMSet(bluePin, 0);  // 0 is off
            delay(1000); // Wait for 1 second
        }

Nel codice sopra, abbiamo solo dimostrato come visualizzare un singolo colore.

Se dovessimo mostrare una varietà di colori usando questo metodo, il codice potrebbe diventare piuttosto ingombrante. Pertanto, per rendere il nostro codice più conciso e manutenibile, possiamo creare una funzione per assegnare valori PWM ai tre pin. Poi, all'interno del ``loop()``, possiamo facilmente impostare una moltitudine di colori.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cac90501-04c1-44c2-a1d7-4f863e50f186/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Dopo aver caricato il codice sulla tua scheda R3, potresti notare che i colori arancione e giallo sembrano un po' sbagliati.
Questo perché il LED rosso sulla striscia è relativamente debole rispetto agli altri due LED.
Quindi, dovrai introdurre valori di offset nel tuo codice per correggere questa discrepanza di colore.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/60ec867f-5637-44bd-b72d-4709fc4f5349/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Ora, la striscia LED RGB dovrebbe essere in grado di visualizzare i colori corretti. Se noti ancora discrepanze, puoi regolare manualmente i valori di ``R_OFFSET``, ``G_OFFSET`` e ``B_OFFSET``.

Sentiti libero di sperimentare e visualizzare qualsiasi colore tu scelga sulla striscia LED. Tutto ciò che devi fare è inserire i valori RGB per il colore che desideri.

Ecco un consiglio: puoi usare lo strumento Paint sul tuo computer per determinare i valori RGB del tuo colore desiderato.

.. image:: img/rgb_paint.png

Ora che abbiamo padroneggiato l'arte dell'impostazione dei colori, nel prossimo passo integreremo questi display abbaglianti con i movimenti del Mars Rover. Tempi entusiasmanti ci aspettano!

**Fase 4: Muovere il Rover con indicazioni colorate**

Ora, aggiungeremo indicazioni colorate ai movimenti del Mars Rover. Ad esempio, possiamo usare il verde per avanti, il rosso per indietro e il giallo per girare a sinistra o a destra.

Per fare questo, aggiungeremo un meccanismo di controllo nel nostro codice che imposta il colore della striscia LED in base al movimento del Rover. Questo implicherà la modifica del nostro codice di controllo del Rover per includere le nostre funzioni di controllo del colore.

Vediamo un esempio di come possiamo farlo:

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/5412eebe-75b8-4f98-a348-f0889e8a7fde/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


All'interno della funzione ``loop()``, abbiamo comandato al Rover di eseguire una serie di azioni chiamando diverse funzioni.
Ogni azione aveva la sua corrispondente visualizzazione di colore: verde per andare avanti, rosso per andare indietro e giallo per girare.
Questa funzione di visualizzazione del colore è stata portata in vita usando la funzione ``setColor()``, che manipolava la luminosità di
ciascun canale di colore RGB.

Per l'azione di arresto, abbiamo introdotto un elemento coinvolgente: un effetto respiro con una luce rossa e blu.
Questo è stato ottenuto regolando ciclicamente la luminosità dei canali rosso e blu all'interno della funzione ``stopMove()``.
In questo modo, all'arresto, la striscia LED passava tra i colori rosso e blu, creando un effetto visivo dinamico.

Ora, il nostro Mars Rover possiede i suoi vivaci effetti di colore, lasciando dietro di sé una scia di segnali codificati a colori, ognuno dei quali rappresenta un
movimento unico.

Attraverso questo progetto, abbiamo scoperto come le materie STEAM possono amalgamarsi per dare vita a una
macchina altrimenti ordinaria, trasformandola in uno strumento di apprendimento vibrante, interattivo e divertente.


**Fase 5: Riepilogo e riflessione**

Nella lezione di oggi, ci siamo immersi nel mondo delle strisce LED RGB, esplorando come manipolarle per visualizzare una vivida gamma di colori. Queste tonalità brillanti hanno dato nuova vita al nostro Mars Rover, trasformandolo da una semplice macchina in uno spettacolo vibrante.

Ora, ti invito a riflettere: se fossi tu al posto di guida, come utilizzeresti questi colori per migliorare il tuo Mars Rover? Quali effetti unici vorresti che esibisse?

Inoltre, attraverso il processo, spero che tu abbia avuto una comprensione pratica di come diversi concetti STEAM possano essere intrecciati in un progetto coinvolgente, fornendoti una prospettiva più ampia delle sue applicazioni pratiche.

Ci vediamo nella nostra prossima entusiasmante avventura!
