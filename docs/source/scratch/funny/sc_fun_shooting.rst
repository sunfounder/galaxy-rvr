.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme agli altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sc_shooting:

Estensione 3 Tiro a Segno
====================================

Hai mai guardato quei giochi di tiro emozionanti in TV, dove i concorrenti mirano abilmente al bersaglio per accumulare punti? Ora puoi provare la stessa adrenalina qui su Scratch! Nel nostro gioco interattivo di tiro, utilizzerai lo sprite del Mirino per mirare e colpire il più vicino possibile al centro, massimizzando il punteggio con ogni tiro preciso.

Per iniziare, clicca sulla bandiera verde. Controllerai i tuoi tiri usando il modulo innovativo di Evitamento Ostacoli. Pronto a mettere alla prova la tua mira e i tuoi riflessi? Vediamo quanto riesci a segnare!

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Di seguito trovi i passaggi per implementare il progetto. Si consiglia di seguirli inizialmente e, una volta acquisita familiarità, puoi modificare gli effetti a tuo piacimento.

1. Dipingi lo Sprite **Mirino**
----------------------------------------------

* Elimina lo sprite predefinito, seleziona il pulsante **Sprite** e clicca su **Dipingi**.

  .. image:: img/shooting_paint_cross.png

* Vai alla pagina **Costumi**. Usa lo strumento **Cerchio**, rimuovi il colore di riempimento e imposta il colore e la larghezza del contorno.

  .. image:: img/shooting_paint_cross1.png

* Disegna un cerchio con lo strumento **Cerchio**. Dopo averlo disegnato, usa lo strumento **Seleziona** per allineare il centro del cerchio con il centro del canvas.

  .. image:: img/shooting_paint_cross2.png

* Con lo strumento **Linea**, disegna una croce all'interno del cerchio.

  .. image:: img/shooting_paint_cross3.png

* Infine, torna alla pagina **Codice** e rinomina lo sprite in "Mirino".

  .. image:: img/shooting_paint_cross4.png

2. Dipingi lo Sprite **Bersaglio**
----------------------------------------

* Allo stesso modo, seleziona il pulsante **Sprite** e clicca su **Dipingi**.

  .. image:: img/shooting_paint_target1.png

* Accedi alla pagina **Costumi**. Usa lo strumento **Cerchio**, seleziona un colore nero, rimuovi il contorno e dipingi un cerchio grande.

  .. image:: img/shooting_paint_target3.png
    :width: 90%

* Disegna cerchi aggiuntivi con lo stesso metodo, ciascuno di un colore diverso. Regola la posizione dei cerchi sovrapposti usando lo strumento **Porta avanti** o **Porta indietro** per allineare tutti i cerchi al centro del canvas.

  .. image:: img/shooting_paint_target4.png
    :width: 90%

* Torna alla pagina **Codice** e rinomina questo sprite in "Bersaglio".

  .. image:: img/shooting_paint_target5.png

3. Aggiungi uno sfondo
--------------------------

* Aggiungi uno sfondo adeguato, preferibilmente meno colorato e che non corrisponda ai colori dello sprite **Bersaglio**. Ho scelto lo sfondo **Muro1**.

  .. image:: img/shooting_choose_backdrop.png

* Regola le posizioni e le dimensioni degli sprite **Bersaglio** e **Mirino**.

  .. note::

    * Assicurati che lo sprite **Mirino** sia stratificato sopra lo sprite **Bersaglio** spostando prima lo sprite **Bersaglio** e poi il **Mirino**.
    * Il **Mirino** dovrebbe essere più piccolo dello spazio tra gli anelli colorati dello sprite **Bersaglio**.

  .. image:: img/shooting_choose_backdrop1.png
  
4. Script per lo Sprite **Mirino**
---------------------------------------

* Randomizza la posizione e la dimensione dello sprite **Mirino**, permettendogli di muoversi in modo imprevedibile.

  .. image:: img/shooting_script_cross.png

* Quando il modulo di evitamento ostacoli a sinistra è bloccato, viene inviato un messaggio - tiro.

  .. image:: img/shooting_script_cross1.png

* Quando viene ricevuto il messaggio **tiro**, lo sprite smette di muoversi e si riduce gradualmente, simulando il tiro di un proiettile.

  .. image:: img/shooting_script_cross2.png

* Usa il blocco [Touch color ()] per determinare la posizione del colpo.

  .. image:: img/shooting_script_cross3.png
    :width: 90%

* Riporta un punteggio di 10 se il colpo cade all'interno del cerchio giallo.

  .. image:: img/shooting_script_cross4.png

* Riporta un punteggio di 9 se il colpo cade all'interno del cerchio rosso. Usa allo stesso modo il blocco [Touch color ()] per corrispondere al colore del cerchio rosso.

  .. image:: img/shooting_script_cross5.png
    :width: 90%

* Usa lo stesso metodo per confermare il punto di atterraggio del proiettile. Se non atterra sullo sprite **Bersaglio**, indica che il colpo è mancato.

  .. image:: img/shooting_script_cross6.png

La programmazione è completata. Ora puoi cliccare sulla bandiera verde per eseguire lo script e verificare se ottieni l'effetto desiderato.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_shooting.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>
