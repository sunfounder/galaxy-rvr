.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti esclusivi**: Approfitta di sconti riservati sui nostri nuovi prodotti.
    - **Promozioni festive e giveaway**: Partecipa a promozioni festive e concorsi a premi.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

Lezione 2: Comprendere e Costruire il Sistema Rocker-Bogie
===================================================================
Nella lezione precedente, abbiamo appreso informazioni sui rover marziani e 
sulla loro struttura di base. Un aspetto interessante che notiamo osservando 
l'evoluzione dei rover marziani è la costante presenza del loro sistema di 
sospensione. Nonostante i progressi tecnologici, tutti i rover, da Sojourner 
a Perseverance, sono stati progettati utilizzando un tipo simile di sistema di 
sospensione chiamato sistema Rocker-Bogie.

Ma perché continuare a utilizzare il sistema Rocker-Bogie, ti starai chiedendo? 
Quali benefici offre questo particolare design per l'esplorazione di Marte?

.. image:: img/rocker_bogie_pic.webp

Nella lezione di oggi, esploreremo più a fondo la scienza e l'ingegneria dietro il sistema Rocker-Bogie, e poi ne costruiremo uno.

Iniziamo questo entusiasmante viaggio ingegneristico!

Obiettivi di apprendimento
------------------------------

* Comprendere il principio di progettazione del sistema di sospensione Rocker-Bogie e i suoi vantaggi.
* Imparare a progettare e costruire un modello base del sistema di sospensione Rocker-Bogie.
* Applicare i principi di base della fisica per spiegare come il sistema Rocker-Bogie affronta terreni complessi.

Materiali
------------
* Schemi e materiali di riferimento (ad esempio disegni progettuali del rover marziano della NASA e video sul funzionamento del sistema Rocker-Bogie)
* Kit di struttura del Mars Rover
* Strumenti e accessori di base (es. cacciavite, viti, ecc.)

Fasi
-------

**Fase 1: Scopriamo il Sistema Rocker-Bogie**

Il sistema Rocker-Bogie è come una "capra di montagna" della meccanica: progettato per mantenere tutte le ruote del rover a contatto con il terreno mentre naviga su terreni accidentati e rocciosi. È appositamente costruito per gestire il paesaggio imprevedibile di Marte, comprese le ripide inclinazioni e i massi di grandi dimensioni. Questo sistema evita l'uso di molle e sfrutta invece la geometria delle sue sei ruote e le loro interazioni per superare terreni difficili. È un esempio brillante di come un design meccanico intelligente possa superare ostacoli ambientali.

Approfondiamo le due parti principali di questo sistema: il "rocker" e il "bogie".

.. image:: img/rocker_bogie.png

* La parte "rocker" del sistema è simile ai due grandi arti su ciascun lato del corpo del rover. Questi arti, o "rocker", sono collegati tra loro e al corpo del rover, o "chassis", tramite un meccanismo chiamato differenziale. Come due gambe che camminano, i rocker ruotano in direzioni opposte rispetto allo chassis, assicurando che la maggior parte delle ruote rimanga a contatto con il suolo. Il corpo del rover mantiene l'angolo medio di entrambi i rocker. Un'estremità di un rocker si collega a una ruota, mentre l'altra estremità si collega al bogie.

* La parte "bogie" del sistema è come una creatura con arti più piccoli collegata al rocker. È un sistema di collegamento più piccolo che ruota nel mezzo del rocker e ha una ruota a ciascuna estremità.

Con questa comprensione di base, passiamo al prossimo passo della nostra avventura.


**Fase 2: Osserviamo il Sistema in Azione**

Qui sotto trovi una GIF che mostra le caratteristiche uniche del sistema di sospensione Rocker-Bogie e illustra come permette ai rover marziani di navigare nel difficile terreno marziano.

.. image:: img/rocker_bogie.gif
    :align: center

Dopo aver visto la GIF, discutiamo insieme! Riflettiamo su queste domande:

* Perché pensi che il sistema di sospensione Rocker-Bogie sia adatto per l'esplorazione di Marte?
* Puoi descrivere come funziona il sistema Rocker-Bogie con le tue parole?
* Quali sono le caratteristiche chiave del sistema Rocker-Bogie che aiutano i rover ad affrontare terreni difficili?

Condividi pure i tuoi pensieri e le tue intuizioni sul sistema di sospensione Rocker-Bogie.

**Fase 3: Costruiamo il Sistema**

Ora che abbiamo imparato il funzionamento del sistema Rocker-Bogie, è il momento di costruirne uno nostro.

Materiali necessari:

* Kit GalaxyRVR
* Strumenti di base come cacciavite e chiave inglese
* Segui i passaggi forniti nelle istruzioni di montaggio del Kit GalaxyRVR per costruire il sistema di sospensione del Rover.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/a1xtgDUEvR0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Ricorda che qui la pazienza e la precisione sono fondamentali, assicurati di 
posizionare correttamente ogni pezzo e di fissarlo bene.

Nel frattempo, discuti con i tuoi compagni sul design e la funzione di ciascun 
componente che stai assemblando. Questo non solo ti aiuterà a comprendere meglio 
il design, ma anche la sua applicazione pratica nell'esplorazione marziana.

Ricorda, non preoccuparti se incontri problemi durante il montaggio o il test. Fa 
tutto parte del processo ingegneristico! Risolvere i problemi è il modo in cui 
impariamo e innoviamo.

**Fase 4: Riassunto e Riflessione**

Durante il montaggio del sistema di sospensione, hai notato che tutte le parti mobili utilizzano dadi autobloccanti? Ti sei mai chiesto perché?

.. image:: img/self_locking_nuts.webp
    :align: center

I dadi autobloccanti sono un tipo di fissaggio che include un anello di gomma all'interno di un dado normale. Questo design garantisce che le parti assemblate non si allentino facilmente e non cadano a causa delle vibrazioni durante il movimento.

Inoltre, assicura che le parti possano ruotare entro un certo raggio.

Durante il montaggio, devi prima stringere la vite e il dado autobloccante con una chiave e un cacciavite, poi allentarli leggermente. Questo garantisce che ci sia spazio per la rotazione libera tra le parti, senza che siano troppo allentate.

.. raw:: html

   <video width="600" loop autoplay muted>
        <source src="_static/video/rocker_bogie_system.mp4" type="video/mp4">
        Your browser does not support the video tag.
   </video>

In questa lezione, non solo abbiamo appreso il funzionamento del sistema Rocker-Bogie, ma ne abbiamo anche costruito uno noi stessi. Inoltre, possiamo simulare manualmente come permette al Mars Rover di muoversi senza problemi su vari terreni accidentati.

Con questa conoscenza e esperienza, ora siamo meglio equipaggiati per avventurarci nei reami sconosciuti dell'esplorazione marziana. Continuiamo a svelare i misteri del pianeta rosso.
