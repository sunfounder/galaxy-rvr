.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme agli altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sc_tap_tile:

Estensione 7 Tocca la Tessera Nera
==========================================

Molti di voi conoscono il popolare gioco per cellulari in cui i giocatori toccano le tessere nere per accumulare punti, evitando quelle bianche. Stiamo portando questa sfida avvincente su Scratch utilizzando due moduli di evitamento ostacoli. Quando la tua mano blocca uno dei moduli IR, viene registrato un tocco sulla scena.

Se il tocco cade su una tessera nera, guadagni un punto; toccare una tessera bianca comporta la perdita di un punto. I giocatori devono decidere rapidamente se toccare il modulo IR sinistro o destro in base alla posizione delle tessere nere.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_tap_black_tile.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Di seguito i passaggi per implementare il progetto. Si consiglia di seguirli inizialmente, e una volta acquisita familiarità, puoi modificare gli effetti a tuo piacimento.

1. Dipingi uno Sprite **Tessera**
-----------------------------------

Uno sprite **Tessera** viene utilizzato per ottenere l'effetto delle tessere nere e bianche alternate che si muovono verso il basso; nella versione per cellulare di questo gioco, ci sono generalmente 4 colonne, qui ne utilizziamo solo due.

* Elimina lo sprite predefinito, tocca l'icona **Aggiungi Sprite** e seleziona **Dipingi**.

  .. image:: img/tile_paint_tile1.png

* Vai alla pagina **Costumi** e utilizza lo strumento **Rettangolo** per disegnare un rettangolo con un bordo grigio e riempimento bianco.

  .. image:: img/tile_paint_tile2.png
    :width: 90%

* Seleziona il rettangolo e clicca su **Copia** -> **Incolla** per creare un rettangolo identico, quindi sposta i due rettangoli in modo che siano allineati.

  .. image:: img/tile_paint_tile3.png
    :width: 90%

* Seleziona uno dei rettangoli e scegli un colore di riempimento nero.

  .. image:: img/tile_paint_tile4.png
    :width: 90%

* Ora seleziona entrambi i rettangoli e spostali in modo che i loro punti centrali coincidano con il centro del canvas.

  .. image:: img/tile_paint_tile5.png
    :width: 90%

* Duplica il costume1, alternando i colori di riempimento dei due rettangoli. Ad esempio, il colore di riempimento del costume1 è bianco a sinistra e nero a destra, e il colore di riempimento del costume2 è nero a sinistra e bianco a destra.

  .. image:: img/tile_paint_tile6.png
    :width: 90%

* Torna alla pagina **Codice** e imposta il nome dello sprite su **Tessera**.

  .. image:: img/tile_paint_tile7.png

2. Scrivere lo script per lo sprite **Tessera**
-----------------------------------------------------

* Per prima cosa, imposta la posizione iniziale dello sprite **Tessera** in modo che sia in cima alla scena.

  .. image:: img/tile_script_tile1.png

* Crea una variabile - **blocchi** e assegna un valore iniziale per determinare quante volte lo sprite **Tessera** apparirà. Usa il blocco [ripeti fino a] per far diminuire gradualmente la variabile **blocchi** fino a che **blocchi** non raggiunge 0. Durante questo tempo, fai sì che lo sprite **Tessera** cambi costume casualmente. Dopo aver cliccato sulla bandiera verde, vedrai lo sprite **Tessera** cambiare costume rapidamente sulla scena.

  .. image:: img/tile_script_tile2.png

* Crea cloni dello sprite **Tessera** mentre la variabile **blocchi** diminuisce e ferma l'esecuzione dello script quando **blocchi** raggiunge 0. Qui vengono utilizzati due blocchi [attendi () secondi], il primo per limitare l'intervallo tra i cloni dello sprite **Tessera** e il secondo per far diminuire la variabile blocchi a 0 senza fermare immediatamente il programma, dando al clone della tessera abbastanza tempo per spostarsi.

  .. image:: img/tile_script_tile3.png

* Ora scrivi lo script per fare in modo che il clone dello sprite **Tessera** si muova lentamente verso il basso e si elimini quando raggiunge il fondo della scena. La modifica della coordinata y influisce sulla velocità di discesa: maggiore è il valore, più veloce è la discesa.

  .. image:: img/tile_script_tile4.png

* Nascondi il corpo e mostra il clone.

  .. image:: img/tile_script_tile5.png

3. Scrivere lo script per lo sfondo
------------------------------------------

Nello sfondo, leggi i valori dei 2 moduli IR e imposta le azioni corrispondenti.

* Quando si clicca sulla bandiera verde, imposta la variabile **conteggio** a 0.

  .. image:: img/tile_script_backdrop.png
    :width: 90%

* Se il modulo di evitamento ostacoli IR sinistro rileva la tua mano, trasmetti un messaggio - **sinistra**.

  .. image:: img/tile_script_backdrop1.png


* Se il modulo di evitamento ostacoli IR destro rileva la tua mano, trasmetti un messaggio - **destra**.

  .. image:: img/tile_script_backdrop2.png


4. Dipingere lo sprite **IR Sinistro**
-------------------------------------------

Uno sprite **IR Sinistro** viene utilizzato per ottenere l'effetto di clic; quando il modulo IR sinistro rileva la tua mano, invierà un messaggio - **sinistra** allo sprite **IR Sinistro**, facendolo entrare in azione. Se tocca la tessera nera sulla scena, il punteggio aumenterà di 1, altrimenti diminuirà di 1.

* Ancora una volta, tocca l'icona **Aggiungi Sprite** e seleziona **Dipingi**.

  .. image:: img/tile_paint_ir1.png

* Vai alla pagina **Costumi**, seleziona il colore di riempimento (un colore qualsiasi tra bianco e nero) e disegna un cerchio.

  .. image:: img/tile_paint_ir2.png

* Torna alla pagina **Codice** e cambia il nome dello sprite in **IR Sinistro**.

  .. image:: img/tile_paint_ir3.png

5. Scrivere lo script per lo sprite **IR Sinistro**
----------------------------------------------------------

* Ora inizia a scrivere lo script per lo sprite **IR Sinistro**. Quando si clicca sulla bandiera verde, nascondi lo sprite.

  .. image:: img/tile_script_ir1.png

* Quando viene ricevuto il messaggio - **sinistra** (il modulo ricevitore IR sinistro rileva un ostacolo), mostra lo sprite, imposta la sua dimensione al 100% e poi riducilo gradualmente a intervalli di 10 usando un blocco [Ripeti] prima di nasconderlo di nuovo. Questo conferisce allo sprite un effetto di espansione e contrazione.

  .. image:: img/tile_script_ir2.png

* Poi determina se il blocco nero dello sprite **Tessera** viene toccato e, se sì, aumenta la variabile **conteggio** di 1, altrimenti diminuiscila di 1.
  
  .. image:: img/tile_script_ir3.png

.. note::

    Devi fare in modo che lo sprite **Tessera** appaia sulla scena e poi assorbire il colore del blocco nero nello sprite **Tessera**.

    .. image:: img/tile_script_ir4.png

6. Sprite **IR Destro**
-------------------------------------

La funzione dello sprite **IR Destro** è essenzialmente la stessa di **IR Sinistro**, tranne per il fatto che riceve le informazioni **destra**.

* Ora duplica lo sprite **IR Sinistro** e cambia il nome dello sprite in **IR Destro**.

  .. image:: img/tile_paint_ir4.png

* Quindi cambia il messaggio ricevuto in - **destra**.

    .. image:: img/tile_script_ir5.png

7. Esecuzione dello script
---------------------------------

* Ora regola le posizioni e le dimensioni dei tre sprite.

  * Trascina lo sprite **Tessera** in fondo alla scena e imposta la sua posizione x a 0.
  * Sposta lo sprite **IR Sinistro** nel riquadro sinistro. Vai alla pagina **Costumi** per ridurre la dimensione dello sprite a solo il 50% della dimensione del riquadro.
  * Allo stesso modo, sposta lo sprite **IR Destro** nel riquadro destro. Vai alla pagina **Costumi** per ridurre la dimensione dello sprite a solo il 50% della dimensione del riquadro.
  * Assicurati che gli sprite **IR Sinistro** e **IR Destro** siano sopra lo sprite **Tessera**.

  .. image:: img/tile_paint_ir5.png

* Ora tutta la programmazione è terminata, e puoi cliccare sulla bandiera verde per eseguire lo script.

  .. raw:: html

    <video loop autoplay muted style = "max-width:70%">
        <source src="../_static/video/sc_tap_black_tile.mp4"  type="video/mp4">
        Your browser does not support the video tag.
    </video>
