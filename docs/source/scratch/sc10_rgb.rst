.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme agli altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!



Lezione 10 Illuminare il Percorso con Strisce LED RGB
===============================================================

Nel nostro viaggio finora, abbiamo trasformato il nostro Rover marziano in un esploratore intelligente, capace di manovrare abilmente attorno agli ostacoli. È diventato piuttosto abile nel navigare i terreni simili a quelli di Marte che abbiamo creato per lui.

Ma cosa succederebbe se aggiungessimo un po' di fascino alla sua praticità? Diamo al nostro Rover la capacità di esprimersi attraverso uno spettacolo di colori e luci. Parliamo di incorporare strisce LED RGB, una funzione fantastica che permetterebbe al nostro Rover di illuminare il suo cammino, anche nelle condizioni più buie.

Immagina questo: il Rover lascia una scia di segnali codificati a colori, rendendo più facile per noi comprendere i suoi movimenti. Una luce verde quando è in movimento, un rosso deciso quando si ferma, o un giallo lampeggiante durante le svolte rapide. Potrebbe persino illuminarsi in una varietà di colori solo per il puro divertimento!

Il nostro obiettivo in questa lezione è comprendere i principi delle strisce LED RGB, imparare a controllarne il colore e la luminosità, e poi sincronizzarle con i movimenti del Rover. Alla fine, il nostro Rover marziano sarà più di una semplice macchina. Sarà un'entità luminosa e cangiante, che guida la strada nel vasto paesaggio marziano!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/car_rgb.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>


Obiettivo
-------------

* Introdurre i principi di funzionamento e i metodi di controllo programmabile delle strisce LED RGB.
* Utilizzare le strisce LED RGB con Mammoth Coding per ottenere il controllo del colore e semplici effetti di illuminazione.
* Creare un progetto con Mammoth Coding per simulare cambi di luce in un ambiente marziano o luci di segnalazione per le missioni di esplorazione marziana.


Materiali Necessari
-------------------------

* Striscia LED RGB e controller
* APP Mammoth Coding
* Computer o tablet


Esplora la Magia della Luce con le Strisce LED RGB
-------------------------------------------------------------

Ricordi l'ultima volta che hai visto un arcobaleno? Come colorava il cielo con sette vivaci tonalità? Ti piacerebbe creare il tuo arcobaleno, proprio qui nel nostro piccolo Rover marziano? Tuffiamoci nella magia della luce con le strisce LED RGB!

.. image:: ../img/4_rgb_strip.jpg

Noterai che la nostra striscia LED RGB ha quattro pin etichettati come segue:

* **+5V**: Questo è il "positivo" comune o l' "anodo" dei tre piccoli LED all'interno della nostra striscia. Deve essere collegato a 5V DC, una sorta di energia elettrica che alimenta le nostre piccole lampadine!
* **B**: Questo è il "negativo" o il "catodo" del LED blu.
* **R**: Questo è il "catodo" del LED rosso.
* **G**: Questo è il "catodo" del LED verde.

.. image:: ../img/rgb_5050.jpg

Ricordi i tre colori primari - Rosso, Blu e Verde - che abbiamo imparato nelle lezioni di arte? Proprio come un artista mescola questi colori sulla sua tavolozza per creare nuove tonalità, la nostra striscia contiene 4 LED "5050" che possono mescolare questi colori primari per creare praticamente qualsiasi colore! Ogni LED "5050" è come un piccolo studio d'arte che ospita queste tre lampadine colorate.

.. image:: ../img/rgb_5050_sche.png

Questi piccoli studi d'arte sono poi collegati in modo intelligente su una scheda di circuito flessibile - una sorta di mini autostrada elettrica! Le estremità "positive" di tutti i LED (anodi) sono collegate insieme, mentre le estremità "negative" (catodi) sono collegate alle rispettive corsie di colore (G a G, R a R, B a B).

.. image:: ../img/rgb_strip_sche.png

E la parte più bella? Con il nostro comando, tutti i LED su questa striscia possono cambiare colore contemporaneamente! È come avere una nostra orchestra luminosa a portata di mano!


Illumina lo Spettacolo
------------------------------

1. Proviamo ad accendere il GalaxyRVR con dei colori! Trascina un blocco di visualizzazione del colore.

.. image:: img/9_rgb_block.png

2. Scegli il tuo colore preferito.

.. image:: img/9_rgb_color.png

3. Cliccalo e vedrai il GalaxyRVR illuminarsi con il colore corrispondente.


**Utilizzare il Palcoscenico per Controllare il GalaxyRVR**

Successivamente, creiamo un progetto interattivo per familiarizzare con le funzioni di illuminazione del GalaxyRVR. Cliccheremo sullo sprite del palcoscenico per cambiare il colore del GalaxyRVR.

1. Elimina lo sprite esistente.

.. image:: img/6_animate_delete.png

2. Scegli uno sprite Ball. Il motivo per cui scegliamo questo sprite è che ha molti costumi, ciascuno corrispondente a un colore diverso.

.. image:: img/9_animate_rgb_ball.png

3. Trascina un blocco "quando questo sprite viene cliccato", che attiverà un'azione quando lo sprite del palcoscenico viene cliccato.

.. image:: img/9_animate_rgb_when.png

4. Trascina un blocco di visualizzazione per accendere il GalaxyRVR.

.. image:: img/9_animate_rgb_display.png

5. Se stai utilizzando un dispositivo con schermo piccolo, clicca il pulsante dell'occhio accanto per assicurarti che la finestra di anteprima del palcoscenico sia sulla stessa interfaccia.

.. image:: img/9_animate_rgb_eye.png

6. Clicca il colore sul blocco di visualizzazione. In fondo alla finestra pop-up, c'è un pulsante di selezione del colore. Cliccalo.

.. image:: img/9_animate_rgb_pick.png

7. Tieni premuto sulla zona del palcoscenico. Una lente d'ingrandimento apparirà sotto il tuo dito per selezionare il colore. Rilascia sulla sprite Ball per selezionare il suo colore per il blocco di visualizzazione.

.. image:: img/9_animate_rgb_pick_color_n.png

8. Tieni premuto lo sprite Ball sul palcoscenico per duplicarlo.

.. image:: img/9_animate_rgb_duplicate.png

9. Nell'interfaccia dei costumi, passa al colore successivo.

.. image:: img/9_animate_rgb_change_costume.png

10. Torna all'interfaccia del codice e seleziona il colore corrispondente allo sprite corrente.

.. image:: img/9_animate_rgb_pick_blue.png

11. Ripeti i passaggi 8-10 fino a impostare tutti e cinque i colori.

.. image:: img/9_animate_rgb_ball5.png

Ora puoi cliccare sullo sprite Ball nell'area del palcoscenico per fare in modo che il GalaxyRVR si illumini con colori diversi.


.. _rgb_move:


Luci di Segnalazione del GalaxyRVR in Azione
----------------------------------------------------------------

**Luci Indicatrici Direzionali**

Ora che sappiamo come fare illuminare il GalaxyRVR, combiniamo questa funzione con :ref:`rvr_move`.

1. Crea un nuovo progetto.

2. Prima, imposta i blocchi evento chiave e i blocchi di movimento per le quattro direzioni.

.. image:: img/9_rgb_move.png

3. Aggiungi visualizzazioni dei colori a ciascun evento: verde per andare avanti.

.. image:: img/9_rgb_green.png

4. Giallo per girare a sinistra e a destra.

.. image:: img/9_rgb_yellow.png

5. Rosso per andare indietro.

.. image:: img/9_rgb_red.png

Ora, quando clicchi sui tasti direzionali nell'area del palcoscenico, vedrai il GalaxyRVR muoversi e illuminarsi del colore corrispondente.


**Luce Respirante**

Una luce respirante è un effetto in cui la luce si illumina e si attenua gradualmente, simile al ritmo della respirazione. Successivamente, aggiungiamo un effetto di luce respirante quando il GalaxyRVR è fermo.

1. Crea un nuovo messaggio di trasmissione chiamato stop. Questo dirà al programma che il GalaxyRVR è in stato di fermo.

.. image:: img/9_rgb_new_message.png

.. note:: Se il tuo sprite deve eseguire molte azioni ma deve avviarne alcune in momenti specifici o sotto determinate condizioni, il blocco di trasmissione può aiutarti a gestire tutto questo. In questo modo, il tuo sprite può eseguire azioni diverse nell'ordine desiderato senza confondere il codice, rendendolo più chiaro e facile da comprendere.

2. Aggiungi questa trasmissione dopo ogni evento di tasto direzionale.

.. image:: img/9_rgb_new_boardcast.png

3. Trascina un blocco "quando ricevo [stop]".

.. image:: img/9_rgb_when_receive.png

4. Imposta la luminosità a 0%, iniziando la nostra luce respirante da 0.

.. image:: img/9_rgb_set_bright.png

5. Usa un blocco ripeti 10 volte per creare un cambiamento graduale nella luminosità. Qui utilizziamo la luce blu, aumentando la luminosità del 10% ogni 0,2 secondi.

.. image:: img/9_rgb_increase.png

6. Segui con un blocco per diminuire la luminosità del 10% ogni 0,2 secondi, completando un ciclo di respirazione.

.. image:: img/9_rgb_decrease.png

7. Trasmetti nuovamente stop alla fine per creare un effetto di respirazione continuo.

.. image:: img/9_rgb_stopagain.png

8. Se controlli direttamente il GalaxyRVR a questo punto, potresti notare che i colori e la luminosità non sono sincronizzati. Quindi, aggiungi un blocco "ferma altri script nello sprite" alla fine di ciascun evento chiave.

.. image:: img/9_rgb_stop.png

9. Poiché la luminosità cambia nell'evento stop, reimposta la luminosità della luce in ogni evento chiave.

.. image:: img/9_rgb_set_bright_each.png

Ora, quando premi i tasti direzionali sul palcoscenico, il GalaxyRVR si muoverà e si illuminerà del colore corrispondente. Quando smetterai di controllarlo, rimarrà fermo e inizierà a respirare luce.


Blocchi Relativi al Modulo RGB
-----------------------------------

.. image:: img/block/rgb_display.png

Illumina la striscia LED RGB sotto il tuo GalaxyRVR con il colore scelto. Puoi:

    * Cliccare sul quadrato del colore per selezionare il colore desiderato.


.. image:: img/block/rgb_display_1s.png

Illumina la striscia LED RGB sotto il tuo GalaxyRVR con il colore scelto per 1 secondo. Puoi:


    * Cliccare sul quadrato del colore per selezionare il colore desiderato.
    * Modificare il numero per cambiare la durata dell'illuminazione.


.. image:: img/block/rgb_display_RGB.png

Illumina la striscia LED RGB sotto il tuo GalaxyRVR con un colore a tua scelta, utilizzando i valori RGB per modificare il colore (regolando la proporzione di luci primarie rosse, verdi e blu, puoi produrre qualsiasi colore), il che è molto utile per i progetti che coinvolgono sfumature di colore. Puoi:

    * Modificare il valore R per regolare la luminosità della luce rossa, con un intervallo da 0 a 255.
    * Modificare il valore G per regolare la luminosità della luce verde, con un intervallo da 0 a 255.
    * Modificare il valore B per regolare la luminosità della luce blu, con un intervallo da 0 a 255.


.. image:: img/block/rgb_display_RGB_1s.png

Illumina la striscia LED RGB sotto il tuo GalaxyRVR con un colore a tua scelta per 1 secondo utilizzando i valori RGB. Puoi:

    * Modificare il valore R per regolare la luminosità della luce rossa, con un intervallo da 0 a 255.
    * Modificare il valore G per regolare la luminosità della luce verde, con un intervallo da 0 a 255.
    * Modificare il valore B per regolare la luminosità della luce blu, con un intervallo da 0 a 255.
    * Modificare la durata per cambiare la lunghezza dell'illuminazione.


.. image:: img/block/rgb_set_brightness.png

Questo blocco è utilizzato per impostare la luminosità delle luci, con un intervallo da 0 a 100.


.. image:: img/block/rgb_increase_brightness.png

Questo blocco aumenta (o diminuisce) la luminosità delle luci. Il valore può essere negativo.


.. image:: img/block/rgb_turn_on.png

Accendi o spegni la striscia LED RGB sotto il tuo GalaxyRVR.

