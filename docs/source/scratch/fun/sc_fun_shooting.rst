.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _sc_shooting:

Divertimento 3: Tiro a segno
====================================

Hai mai visto quegli emozionanti giochi di tiro in TV, dove i concorrenti mirano abilmente al bersaglio per accumulare punti? Ora puoi provare la stessa scarica di adrenalina proprio qui in Scratch! Nel nostro gioco di tiro interattivo, userai lo sprite Crosshair per mirare e colpire il più vicino possibile al centro del bersaglio, massimizzando il tuo punteggio con ogni tiro preciso.

Per iniziare, clicca la bandiera verde. Controllerai i tuoi colpi usando l'innovativo modulo evitamento ostacoli. Pronto a testare la tua mira e i tuoi riflessi? Vediamo che punteggio fai!


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Di seguito sono riportati i passaggi per implementare il progetto. Si consiglia di seguire inizialmente questi passaggi e, una volta acquisita familiarità, è possibile modificare gli effetti come desiderato.

1. Disegnare lo sprite **Crosshair**
----------------------------------------------

* Elimina lo sprite predefinito, seleziona il pulsante **Sprite** e clicca **Paint**.

  .. image:: img/shooting_paint_cross.png

* Vai alla pagina **Costumes**. Usa lo strumento **Circle**, rimuovi il colore di riempimento e imposta il colore e la larghezza del contorno.

  .. image:: img/shooting_paint_cross1.png

* Disegna un cerchio con lo strumento **Circle**. Dopo aver disegnato, usa lo strumento **Select** per allineare il centro del cerchio con il centro della tela.

  .. image:: img/shooting_paint_cross2.png

* Con lo strumento **Line**, disegna una croce all'interno del cerchio.

  .. image:: img/shooting_paint_cross3.png

* Infine, torna alla pagina **Code** e rinomina lo sprite in "Crosshair".

  .. image:: img/shooting_paint_cross4.png

2. Disegnare lo sprite **Target**
----------------------------------------

* Allo stesso modo, seleziona il pulsante **Sprite** e clicca **Paint**.

  .. image:: img/shooting_paint_target1.png

* Entra nella pagina **Costumes**. Usa lo strumento **Circle**, seleziona un colore nero, rimuovi il contorno e dipingi un grande cerchio.

  .. image:: img/shooting_paint_target3.png
    :width: 90%

* Disegna cerchi aggiuntivi usando lo stesso metodo, ognuno di un colore diverso. Regola la posizione dei cerchi sovrapposti usando lo strumento **Forward** o **Backward** per assicurarti che tutte le origini dei cerchi siano allineate con il centro della tela.

  .. image:: img/shooting_paint_target4.png
    :width: 90%

* Torna alla pagina **Code** e rinomina questo sprite "Target".

  .. image:: img/shooting_paint_target5.png

3. Aggiungere uno sfondo
--------------------------

* Aggiungi uno sfondo adatto che sia preferibilmente meno colorato e non corrisponda ai colori dello sprite **Target**. Io ho scelto lo sfondo **Wall1**.

  .. image:: img/shooting_choose_backdrop.png

* Regola le posizioni e le dimensioni degli sprite **Target** e **Crosshair**.

  .. note::

    * Assicurati che lo sprite **Crosshair** sia sopra lo sprite **Target** spostando prima lo sprite **Target** e poi il **Crosshair**.
    * Il **Crosshair** dovrebbe essere più piccolo dello spazio tra gli anelli colorati dello sprite **Target**.

  .. image:: img/shooting_choose_backdrop1.png

4. Script per lo sprite **Crosshair**
---------------------------------------

* Randomizza la posizione e la dimensione dello sprite **Crosshair**, permettendogli di muoversi in modo imprevedibile.

  .. image:: img/shooting_script_cross.png

* Quando il modulo evitamento ostacoli sinistro è bloccato, viene trasmesso un messaggio - shooting.

  .. image:: img/shooting_script_cross1.png

* Quando viene ricevuto il messaggio **shooting**, lo sprite smette di muoversi e si riduce gradualmente, simulando lo sparo di un proiettile.

  .. image:: img/shooting_script_cross2.png

* Usa il blocco [Touch color ()] per determinare la posizione del colpo.

  .. image:: img/shooting_script_cross3.png
    :width: 90%

* Segnala un punteggio di 10 se il colpo atterra all'interno del cerchio giallo.

  .. image:: img/shooting_script_cross4.png

* Segnala un punteggio di 9 se il colpo atterra all'interno del cerchio rosso. Allo stesso modo, usa il blocco [Touch color ()] per abbinare il colore del cerchio rosso.

  .. image:: img/shooting_script_cross5.png
    :width: 90%

* Usa lo stesso metodo per confermare l'atterraggio del proiettile. Se non atterra sullo sprite **Target**, indica un colpo mancato.

  .. image:: img/shooting_script_cross6.png

La programmazione è completa. Ora puoi cliccare la bandiera verde per eseguire lo script e vedere se raggiunge l'effetto desiderato.


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>