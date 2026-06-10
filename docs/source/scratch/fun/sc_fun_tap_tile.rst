.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _sc_tap_tile:

Divertimento 7: Tocca la piastrella nera
==========================================

Molti di voi conoscono il popolare gioco mobile in cui i giocatori toccano le piastrelle nere per segnare punti evitando le piastrelle bianche. Portiamo questa avvincente sfida usando due moduli evitamento ostacoli. Quando la tua mano viene bloccata sopra uno dei moduli IR, viene registrato un tocco sul palco.

Se un tocco atterra su una piastrella nera, guadagni un punto; toccare una piastrella bianca sottrae un punto. I giocatori devono decidere rapidamente se toccare sopra il modulo IR sinistro o destro in base alla posizione delle piastrelle nere.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_tap_black_tile.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Di seguito sono riportati i passaggi per implementare il progetto. Si consiglia di seguire inizialmente questi passaggi e, una volta acquisita familiarità, è possibile modificare gli effetti come desiderato.

1. Disegnare uno sprite **Tile**
-----------------------------------

Uno sprite **Tile** viene utilizzato per ottenere l'effetto di piastrelle nere e bianche alternate che si muovono verso il basso; nella versione per cellulare di questo gioco, ci sono generalmente 4 colonne, qui ne facciamo solo due.


* Elimina lo sprite predefinito, tocca l'icona **Add Sprite**, seleziona **Paint**.

  .. image:: img/tile_paint_tile1.png

* Successivamente, vai alla pagina **Costumes** e usa lo strumento **Rectangle** per disegnare un rettangolo con bordo grigio e riempimento bianco.

  .. image:: img/tile_paint_tile2.png
    :width: 90%

* Seleziona il rettangolo e clicca **Copy** -> **Paste** per creare un rettangolo identico, quindi sposta i due rettangoli in una posizione allineata.

  .. image:: img/tile_paint_tile3.png
    :width: 90%

* Seleziona uno dei rettangoli e scegli un colore di riempimento nero.

  .. image:: img/tile_paint_tile4.png
    :width: 90%

* Ora seleziona entrambi i rettangoli e spostali in modo che i loro punti centrali corrispondano al centro della tela.

  .. image:: img/tile_paint_tile5.png
    :width: 90%

* Duplica costume1, alternando i colori di riempimento dei due rettangoli. Ad esempio, il colore di riempimento di costume1 è bianco a sinistra e nero a destra, e il colore di riempimento di costume2 è nero a sinistra e bianco a destra.

  .. image:: img/tile_paint_tile6.png
    :width: 90%

* Torna alla pagina **Code** e imposta il nome dello sprite su **Tile**.

  .. image:: img/tile_paint_tile7.png

2. Scripting per lo sprite **Tile**
-------------------------------------

* Per prima cosa, imposta la posizione iniziale dello sprite **Tile** in modo che sia nella parte superiore del palco.

  .. image:: img/tile_script_tile1.png

* Crea una variabile - **blocks** e dalle un valore iniziale per determinare il numero di volte in cui lo sprite **Tile** apparirà. Usa il blocco [repeat until] per far diminuire gradualmente la variabile **blocks** fino a quando **blocks** è 0. Durante questo tempo, fai cambiare casualmente costume allo sprite **Tile**. Dopo aver cliccato sulla bandiera verde, vedrai lo sprite **Tile** sul palco cambiare rapidamente costume.

  .. image:: img/tile_script_tile2.png

* Crea cloni dello sprite **Tile** mentre la variabile **blocks** sta diminuendo e ferma l'esecuzione dello script quando blocks è 0. Qui vengono utilizzati due blocchi [wait () seconds], il primo per limitare l'intervallo tra i cloni di **Tile** e il secondo per lasciare che la variabile blocks diminuisca a 0 senza fermare immediatamente il programma, dando all'ultimo sprite tile abbastanza tempo per muoversi.

  .. image:: img/tile_script_tile3.png

* Ora scrivi lo script per il clone dello sprite **Tile** per farlo muovere lentamente verso il basso ed eliminarlo quando raggiunge la parte inferiore del palco. La modifica della coordinata y influisce sulla velocità di caduta, maggiore è il valore, più veloce è la velocità di caduta.

  .. image:: img/tile_script_tile4.png

* Nascondi il corpo e mostra il clone.

  .. image:: img/tile_script_tile5.png

3. Scripting per lo sfondo
-------------------------------

Nello sfondo, leggi i valori dei 2 moduli IR ed esegui le azioni corrispondenti.

* Quando si clicca la bandiera verde, imposta la variabile **count** a 0.

  .. image:: img/tile_script_backdrop.png
    :width: 90%

* Se il modulo evitamento ostacoli IR sinistro rileva la tua mano, trasmetti un messaggio - **left**.

  .. image:: img/tile_script_backdrop1.png


* Se il modulo evitamento ostacoli IR destro rileva la tua mano, trasmetti un messaggio - **right**.

  .. image:: img/tile_script_backdrop2.png


4. Disegnare lo sprite **Left IR**
----------------------------------
Uno sprite **Left IR** viene utilizzato per ottenere l'effetto clic; quando il modulo IR sinistro rileva la tua mano, invierà un messaggio - **left** allo sprite **Left IR**, facendolo iniziare a funzionare. Se tocca la piastrella nera sul palco, il punteggio verrà aumentato di 1, altrimenti il punteggio verrà diminuito di 1.


* Di nuovo, tocca l'icona **Add Sprite** e seleziona **Paint**.

  .. image:: img/tile_paint_ir1.png

* Vai alla pagina **Costumes**, seleziona il colore di riempimento (qualsiasi colore tranne nero e bianco) e disegna un cerchio.

  .. image:: img/tile_paint_ir2.png

* Torna alla pagina **Code** e cambia il nome dello sprite in **Left IR**.

  .. image:: img/tile_paint_ir3.png

5. Scripting per lo sprite **Left IR**
------------------------------------------

* Ora inizia a scrivere lo script per lo sprite **Left IR**. Quando si clicca la bandiera verde, nascondi prima lo sprite.

  .. image:: img/tile_script_ir1.png

* Quando viene ricevuto il messaggio - **left** (il modulo ricevitore IR a sinistra rileva un ostacolo), mostra lo sprite, imposta la sua dimensione al 100% e poi riducila a intervalli di 10 usando un blocco [Repeat] prima di nasconderlo di nuovo. Questo dà allo sprite un effetto di espansione e contrazione.

  .. image:: img/tile_script_ir2.png

* Quindi determina se il blocco nero dello sprite **Tile** viene toccato e, in tal caso, fai aumentare la variabile **count** di 1, altrimenti diminuisci di 1.

  .. image:: img/tile_script_ir3.png

.. note::

    Devi far apparire lo sprite **Tile** sul palco e poi assorbire il colore del blocco nero nello sprite **Tile**.

    .. image:: img/tile_script_ir4.png

6. Sprite **Right IR**
-------------------------------------
La funzione dello sprite **Right IR** è fondamentalmente la stessa di **Left IR**, tranne per il fatto che riceve informazioni **Right**.


* Ora duplica lo sprite **Left IR** e cambia il nome dello sprite in **Right IR**.

  .. image:: img/tile_paint_ir4.png

* Quindi cambia il messaggio ricevuto in - **right**.

    .. image:: img/tile_script_ir5.png

7. Esecuzione dello script
---------------------------------

* Ora regola le posizioni e le dimensioni dei tre sprite.

  * Trascina lo sprite **Tile** nella parte inferiore del palco e imposta la sua posizione x su 0.
  * Sposta lo sprite **Left IR** nella cornice sinistra. Devi andare alla pagina **Costumes** per ridurre la dimensione dello sprite a solo il 50% della dimensione della cornice.
  * Allo stesso modo, sposta lo sprite **Right IR** nella cornice destra. Devi andare alla pagina **Costumes** per ridurre la dimensione dello sprite a solo il 50% della dimensione della cornice.
  * Assicurati che gli sprite **Left IR** e **Right IR** siano sopra lo sprite **Tile**.

  .. image:: img/tile_paint_ir5.png

* Ora tutto lo scripting è fatto e puoi cliccare sulla bandiera verde per eseguire lo script.

  .. raw:: html

    <video loop autoplay muted style = "max-width:70%">
        <source src="../../_static/video/sc_tap_black_tile.mp4"  type="video/mp4">
        Your browser does not support the video tag.
    </video>
