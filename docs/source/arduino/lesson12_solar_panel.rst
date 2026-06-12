.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Lezione 12: Investigare il sistema energetico del Mars Rover
=================================================================

Benvenuto alla lezione finale del nostro viaggio di esplorazione del Mars Rover. Questa volta, ci addentreremo nel cuore del rover: il suo sistema energetico.

Quando pensiamo all'esplorazione di pianeti lontani come Marte, uno degli aspetti più cruciali da considerare è l'energia.
Come fanno questi rover ad alimentarsi in ambienti così ostili e remoti?
In questa lezione, esploreremo questo affascinante argomento e impareremo come i rover, come il nostro modello Mars Rover, sfruttano e gestiscono l'energia.

Investigheremo i principi di funzionamento della batteria e del pannello solare e faremo persino pratica nell'installazione e
nell'uso di queste fonti di energia sul nostro modello di rover. Inoltre, porteremo le nostre competenze a un livello superiore usando Arduino per monitorare
il livello della batteria.


.. image:: img/solar_panel.jpg
    :width: 600
    :align: center

Obiettivi di apprendimento
--------------------------

* Comprendere i principi di funzionamento della batteria e del pannello solare.
* Esercitarsi nell'installazione del pannello solare sul modello Mars Rover.
* Imparare a utilizzare Arduino per monitorare il livello della batteria e lo stato di carica del pannello solare.


Materiali necessari
------------------------

* Modello Mars Rover (equipaggiato con tutti i componenti, tranne il pannello solare e la piastra inferiore)
* Pannello solare e piastra inferiore
* Arduino IDE
* Computer

Procedura del corso
----------------------

**Fase 1: Introduzione al sistema energetico del Mars Rover**

Proprio come i nostri corpi hanno bisogno di un costante apporto di energia per funzionare, il nostro Mars Rover ha bisogno di un modo per immagazzinare e generare energia per le sue missioni esplorative. Immagina il sistema energetico del Rover come il cuore nei nostri corpi. Proprio come i nostri cuori pompano sangue in tutte le parti del nostro corpo, fornendo ossigeno e nutrienti necessari, il sistema energetico del Rover mantiene il flusso di energia verso ogni parte del Rover, assicurando che possa svolgere i suoi compiti senza intoppi.

I componenti principali di questo sistema energetico sono le batterie e i pannelli solari, che lavorano in tandem per garantire che il Rover possa operare in ogni momento, giorno e notte.

Il ruolo delle batterie nel sistema energetico del Rover è simile al ruolo dell'immagazzinamento di energia nei nostri corpi. Proprio come abbiamo bisogno di immagazzinare energia da usare quando siamo attivi, il Rover ha bisogno di un modo per immagazzinare energia per le sue missioni esplorative. L'energia immagazzinata nelle batterie viene continuamente inviata a varie parti del Rover, permettendogli di svolgere i suoi compiti sistematicamente.

.. image:: img/battery_galaxyrvr.png
    :width: 600
    :align: center

Ma cosa succede quando l'energia nelle batterie si esaurisce? Come fa a ricostituire le sue riserve di energia? È qui che entrano in gioco i pannelli solari.

Proprio come gli alberi assorbono la luce solare per la fotosintesi per creare cibo, il nostro Mars Rover usa i pannelli solari per sfruttare l'energia del Sole, convertendola in elettricità che viene immagazzinata nelle batterie per l'uso. Ogni pannello solare è composto da molte celle solari più piccole. Queste celle sono composte da un materiale che può convertire la luce in elettricità, un processo chiamato effetto fotovoltaico. Quando la luce solare colpisce le celle, generano una corrente elettrica che può essere usata immediatamente o immagazzinata nelle batterie del Rover per un uso successivo.

.. image:: img/solar_panel_gala.png
    :width: 600
    :align: center

Tuttavia, sfruttare l'energia solare su Marte non è così facile come sembra. Le tempeste di polvere possono ridurre la quantità di luce solare che raggiunge i pannelli, e la luce solare marziana più debole (rispetto a quella terrestre) significa che i pannelli generano meno energia di quanto farebbero qui a casa. Nonostante queste sfide, l'energia solare è ancora il modo più pratico ed efficiente per alimentare il nostro Mars Rover.

Ma come facciamo a sapere quando i pannelli solari stanno facendo il loro lavoro e quando le batterie stanno esaurendo l'energia? È qui che entra in gioco il nostro Arduino. Nella prossima sezione, impareremo come usare Arduino per monitorare la carica e la scarica delle batterie del Rover.

**Fase 2: Montaggio del pannello solare sul Mars Rover**

Prima di iniziare questa fase, dobbiamo avere il nostro modello Mars Rover, un pannello solare e i cavi necessari per collegare il pannello solare al sistema di alimentazione del Rover.

Questo è un processo che ci permette di mettere in pratica la teoria e apprezzare veramente il fascino dell'educazione STEM (Scienza, Tecnologia, Ingegneria e Matematica). Iniziamo!

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/-Vj-dcniFrA" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Fase 3: Programmazione per monitorare la tensione e la carica della batteria**

Ora che abbiamo installato i pannelli solari sul nostro modello Mars Rover, il passo successivo è monitorare la tensione e la carica della batteria attraverso la programmazione.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2e85e234-9575-4a1f-982b-2f9aba8e3156/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Questo codice crea efficacemente un semplice monitor della batteria, particolarmente utile in applicazioni come il Mars Rover dove la gestione dell'energia è cruciale. Ti permetterà di monitorare lo stato della batteria, aiutandoti a capire quando il Rover ha bisogno di essere ricaricato o quando i compiti ad alto consumo energetico dovrebbero essere programmati.

Analizziamo le diverse parti di questo codice:

*  Questa riga definisce ``BATTERY_PIN`` come il pin analogico A3, che è dove verrà letta la tensione della batteria.

    .. code-block:: arduino

        #define BATTERY_PIN A3

* Questa funzione calcola la tensione della batteria. Prima legge il valore analogico da ``BATTERY_PIN``, poi lo converte in tensione. Poiché il convertitore analogico-digitale (ADC) di Arduino opera su una scala di 0-1023, dividiamo la lettura grezza per 1023. Moltiplichiamo poi per 5 (la tensione di riferimento di Arduino) e per 2 (assumendo un partitore di tensione di 2), per convertirlo in una lettura di tensione.

    .. code-block:: arduino
        :emphasize-lines: 5

        float batteryGetVoltage() {
            // Reads the analog value from the battery pin
            int adcValue = analogRead(BATTERY_PIN);
            // Converts the analog value to voltage
            float adcVoltage = adcValue / 1023.0 * 5 * 2;
            // Rounds the voltage to two decimal places
            float batteryVoltage = int(adcVoltage * 100) / 100.0;
            return batteryVoltage;
        }


    La lettura grezza ADC dal convertitore analogico-digitale di Arduino è divisa per 1023 per convertirla in una frazione, poi moltiplicata per 5 per tradurla in tensione, poiché Arduino utilizza una tensione di riferimento di 5 volt.

    Tuttavia, poiché la tensione della batteria è superiore alla tensione massima di ingresso di Arduino, viene utilizzato un resistore per proteggere Arduino. Pertanto, moltiplichiamo la tensione ADC per 2 per contrastare l'effetto del resistore e ottenere la tensione corretta della batteria.

* Questa funzione calcola la percentuale di carica della batteria in base alla sua tensione. Utilizza la funzione ``map`` per "mappare" il valore di tensione (che va da 6,6 a 8,4 volt) a una percentuale (che va da 0 a 100).

    .. code-block:: arduino

        uint8_t batteryGetPercentage() {
            float voltage = batteryGetVoltage();  // Gets the battery voltage
            // Maps the voltage to a percentage.
            int16_t temp = map(voltage, 6.6, 8.4, 0, 100);
            // Ensures the percentage is between 0 and 100
            uint8_t percentage = max(min(temp, 100), 0);
            return percentage;
        }

**Fase 4: Mettere alla prova il sistema energetico del Mars Rover: Corse al chiuso e all'aperto**

Dopo aver codificato il nostro sistema di monitoraggio della batteria, è ora di mettere in azione il Mars Rover.
Inizia caricando il Rover alla piena capacità e pianifica due missioni esplorative di 30 minuti: una al chiuso
e un'altra all'aperto alla luce del sole. Registra il livello iniziale della batteria prima di ogni missione
e confrontalo con la percentuale della batteria alla fine di ogni test.
La seguente tabella serve come utile modello per tenere traccia dei tuoi risultati:



.. list-table:: Test di alimentazione
   :widths: 50 25 25
   :header-rows: 1

   * -
     - Luce solare
     - In stanza
   * - Percentuale batteria iniziale
     -
     -
   * - Percentuale batteria finale
     -
     -

Osserva la differenza nei livelli della batteria dopo ogni test. La batteria del Rover è durata più a lungo quando era esposta alla
luce solare esterna? Quali conclusioni possiamo trarre sull'efficacia del pannello solare da questa osservazione?

Comprendere queste variazioni ci aiuterà a capire meglio come l'energia solare può alimentare efficacemente un Mars Rover,
anche in ambienti remoti e ostili come quelli che si trovano sulla superficie marziana.

**Fase 5: Riflessione**

In questa lezione, ci siamo concentrati sulla comprensione del ruolo cruciale del sistema energetico nel Mars Rover e sui meccanismi per monitorare l'energia rimanente del Rover. Il sistema energetico basato su pannelli solari non solo alimenta il Rover, ma sottolinea anche l'importanza delle fonti di energia rinnovabile nell'esplorazione spaziale.

Con le conoscenze che hai ora, pensa alle implicazioni reali di questo sistema. Considera le sfide che un sistema di energia solare potrebbe incontrare su Marte. Come potrebbero le temperature estreme, le tempeste di polvere o lunghi periodi di oscurità influenzare l'approvvigionamento energetico? Quali soluzioni potresti proporre per affrontare questi ostacoli?

**Fase 6: Guardando avanti**

Ora che abbiamo dato al nostro Mars Rover la capacità di muoversi, è il momento di lasciarlo iniziare il suo viaggio di esplorazione! Puoi lasciarlo vagare in vari terreni che imitano l'ambiente marziano.

Ad esempio, puoi farlo arrampicare su un cumulo di pietre.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/move_stone.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

O lasciarlo navigare attraverso uno spesso campo erboso.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/move_grass.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

O impostarlo su un percorso su un terreno ghiaioso pieno di pietre.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/move_stone1.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Tuttavia, tieni presente che se l'ostacolo è troppo alto, il rover potrebbe non essere in grado di superarlo.

.. raw:: html

   <video width="400" height="400" loop autoplay muted>
      <source src="../_static/video/move_failed.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Questi terreni vari presentano sfide uniche per il rover, proprio come farebbero per un vero Mars Rover. Mentre guardi il tuo rover cercare di superare questi ostacoli, stai vivendo una piccola parte di ciò che fanno gli scienziati e gli ingegneri della NASA quando inviano rover su Marte!

Concludendo le nostre lezioni sul Mars Rover, è importante riflettere su ciò che abbiamo imparato. Speriamo che questo viaggio non solo abbia ampliato le tue conoscenze e competenze, ma abbia anche acceso la curiosità e il desiderio di esplorare. Che il tuo Rover vaghi nel tuo giardino o attraverso la vasta distesa della tua immaginazione, le scoperte che farai lungo il cammino saranno sicuramente straordinarie.
