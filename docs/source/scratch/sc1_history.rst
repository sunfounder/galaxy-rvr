.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme agli altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

Lezione 1 Scopriamo il Rover di Marte
========================================

Benvenuti alla Lezione 1: Comprendere il Rover di Marte. Oggi esploreremo l'emozionante mondo dei rover marziani—i nostri esploratori remoti sul Pianeta Rosso. Impareremo la loro evoluzione, le loro funzioni e le meraviglie tecnologiche che rappresentano. Inoltre, metterete in gioco la vostra creatività per progettare il vostro rover e perfezionare le vostre abilità di presentazione spiegando il vostro design unico. Pronti a esplorare Marte direttamente dalla vostra classe?


Obiettivi di Apprendimento
------------------------------
* Comprendere l'evoluzione e lo scopo dei rover marziani.
* Esprimere la propria creatività progettando un rover per Marte.
* Migliorare le capacità di presentazione condividendo e spiegando il proprio design del rover.

Materiali
--------------
* Immagini e specifiche tecniche dei rover di Marte come riferimento.
* Video documentario sulla storia dei rover marziani.
* Computer con accesso a Internet per la ricerca e la visione del documentario.
* Slide di presentazione o lavagna interattiva per la lezione.
* Carta da disegno, matite e materiali colorati per l'attività di progettazione del rover.
* Schede di lavoro per prendere appunti, riflessioni e pianificazioni del design.

Passaggi
--------------

**Passaggio 1: Cosa sono i Rover di Marte?**

Prima di immergerci nei rover marziani, familiarizziamo prima con Marte. Come possiamo vedere dalle immagini e dai modelli, 
la superficie di Marte è segnata da crateri, montagne, valli e tempeste di polvere, dipingendo un paesaggio 
affascinante e allo stesso tempo impegnativo.

    .. image:: ../img/mars_surface.jpg
        :width: 600
    .. image:: ../img/mars_surface.png
        :width: 600

Riesci a immaginare cosa significherebbe navigare attraverso un terreno così accidentato? 
Ora, supponi di avere il compito di progettare un rover per Marte.

* Quali considerazioni prenderesti in considerazione data la topografia e le condizioni di Marte?
* Con quali caratteristiche lo equipaggeresti per garantire che possa svolgere efficacemente le sue funzioni?
* Quali compiti immagini che il tuo rover su Marte debba svolgere?

Ricorda, un rover di Marte è un robot progettato per esplorare Marte, studiare il suo ambiente e inviare dati sulla Terra. 
Quindi pensa ad aspetti come il movimento, la comunicazione, l'alimentazione, le capacità di ricerca scientifica e la resistenza 
alle condizioni estreme di Marte.

Prendiamoci un momento per fare brainstorming e condividere le nostre idee. È interessante pensare come ingegneri e scienziati, vero? 
Approfondiremo i veri design dei rover marziani e le loro funzioni nei passaggi successivi, 
quindi tieni a mente le tue idee creative mentre procediamo.


**Passaggio 2: Esplorare la Storia dei Rover Marziani**

Successivamente, intraprenderemo un viaggio nel tempo guardando un documentario che racconta la storia dei rover marziani. 
Il documentario ci porta dal primo tentativo di schierare un rover su Marte, il rover sovietico Mars 3, che purtroppo non riuscì 
nell'atterraggio nel 1971, fino al primo rover marziano di successo della NASA, Sojourner, nel 1997. 

Il nostro viaggio non si ferma qui, mentre andiamo oltre per comprendere le avventure dei rover più avanzati: Spirit, Opportunity, Curiosity e Perseverance.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/OO5CTBBgtXs" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Questo documentario non solo offre un contesto storico, ma fornisce anche una comprensione completa dei progressivi 
traguardi scientifici e ingegneristici che hanno portato all'attuale era dell'esplorazione marziana.


**Passaggio 3: Riassumere i Rover Marziani**

Dopo aver guardato il documentario, riassumiamo i diversi rover che sono stati inviati sul pianeta rosso.

* **Sojourner** (1997)

    **Sojourner**, il pioniere dei rover marziani, iniziò il suo viaggio come parte della missione Mars Pathfinder. 
    Fece un atterraggio di successo nella regione di Ares Vallis il 4 luglio 1997. Essendo il primo veicolo su ruote 
    a esplorare un pianeta diverso dalla Terra, Sojourner segnò un traguardo importante nell'esplorazione di Marte. 
    Sebbene fosse operativo su Marte per soli 92 giorni marziani, o sol, ha gettato le basi per i futuri rover esplorativi.

    .. image:: ../img/mars_sojourner.jpg

* **Spirit** (2004–2010) e **Opportunity** (2004–2018)

    **Spirit** e **Opportunity** sono rover gemelli della missione Mars Exploration Rover (MER) della NASA. **Spirit**, noto anche come MER-A, 
    ha operato su Marte dal 2004 al 2010. 
    
    D'altro canto, **Opportunity**, o MER-B, ha avuto un ciclo operativo straordinariamente lungo, dal 2004 al 2018. 
    Insieme, hanno notevolmente ampliato la nostra comprensione della superficie e della storia geologica marziana.

    .. image:: ../img/mars_opportunity.jpg

* **Curiosity** (2012–oggi):

    **Curiosity**, un rover di Marte delle dimensioni di un'automobile, è stato progettato per esplorare il cratere Gale su Marte come parte della 
    missione Mars Science Laboratory (MSL) della NASA. Dalla sua arrivata nel 2012, **Curiosity** ha fatto numerose scoperte significative, 
    inclusa la prova dell'esistenza di acqua liquida nel passato di Marte.

    .. image:: ../img/mars_curiosity.jpg

* Perseverance (2021–oggi):

    **Perseverance**, noto anche come Percy, è il rover più recente a essere arrivato su Marte. È progettato per esplorare il cratere Jezero 
    come parte della missione Mars 2020 della NASA. Oltre ai suoi strumenti scientifici, **Perseverance** porta con sé Ingenuity, un piccolo elicottero sperimentale marziano, segnando un'altra prima volta nell'esplorazione di Marte.

    .. image:: ../img/mars_perseverance.jpg

Ora, discutiamo insieme. Rifletti sull'evoluzione di questi rover.

* In che modo i design di questi rover differiscono? In che modo sono simili?
* Come hanno influenzato gli obiettivi della missione il design di ciascun rover?
* Quali progressi tecnologici puoi identificare tra un rover e l'altro?
* Quali caratteristiche pensi che dovrebbe avere il prossimo rover marziano?
* Condividi i tuoi pensieri e riflessioni, e qualsiasi domanda tu possa avere!

**Passaggio 4: Attività Artistica: Disegna il Tuo Rover per Marte**

.. image:: ../img/sojourner-first.jpg
.. image:: ../img/spirit-opportunity.jpg
    :width: 500
.. image:: ../img/curiosity.png
.. image:: ../img/perseverance_rover.png

Per la nostra prossima attività, mettiamo in pratica le nostre conoscenze e creatività progettando il nostro rover per Marte. Considera le caratteristiche chiave dei rover che abbiamo studiato finora, ma pensa anche alle caratteristiche uniche che vorresti incorporare nel tuo design.

Materiali necessari:

* Carta da disegno
* Matite e gomme
* Matite colorate, pastelli o pennarelli


Istruzioni per il disegno:

#. Inizia con il corpo del rover. Quale forma avrà? Quanto sarà grande?
#. Considera le ruote. Quante ne avrà il tuo rover? Di che dimensioni e forma saranno?
#. Non dimenticare gli strumenti. Quali attrezzature scientifiche porterà il tuo rover? Fotocamere, trapani, spettrometri o qualcosa di completamente nuovo?
#. Infine, pensa a eventuali caratteristiche uniche. Il tuo rover avrà pannelli solari o utilizzerà una fonte di alimentazione diversa? Potrà comunicare direttamente con la Terra o avrà bisogno di un satellite di collegamento?

Una volta che tutti avranno completato i loro disegni, li condivideremo con la classe. Spiega le tue scelte di design e la missione che immagini per il tuo rover.

**Passaggio 5: Presenta i Tuoi Progetti di Rover per Marte**

Ora che tutti hanno completato i loro disegni di Rover per Marte, è il momento di condividerli! Durante la presentazione, discuti il processo di pensiero dietro il tuo design. Qual è la missione del tuo rover? Come supporta il design questa missione?

Ricorda, non ci sono risposte sbagliate in questa attività. Lo scopo è stimolare la tua creatività e approfondire la tua comprensione della tecnologia dei rover marziani.

**Passaggio 6: Riflessione e Conclusione**

Concludendo la nostra lezione sui rover di Marte, prendiamoci qualche minuto per riflettere su ciò che abbiamo imparato. In che modo i nostri progetti di rover riflettono i progressi nella tecnologia e negli obiettivi scientifici? Come potrebbero evolvere i veri rover marziani in futuro?

Ricorda, l'esplorazione dello spazio, come qualsiasi campo STEAM, riguarda il porsi domande, risolvere problemi e usare la creatività. Continua a esplorare, continua a farti domande e continua a essere curioso!
