.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!


Divertimento 4: Mangia la mela
==============================

In questo progetto, usiamo un modulo evitamento ostacoli a infrarossi per guidare lo sprite Beetle verso una mela.

Dopo aver cliccato la bandiera verde, passa rapidamente la mano sopra il modulo evitamento ostacoli sinistro (blocca e rimuovi rapidamente la mano davanti al modulo) per avviare la rotazione di Beetle. Una volta allineato correttamente, passa di nuovo la mano sopra il modulo per far avanzare Beetle, assicurandoti che eviti le linee nere sulla mappa. Se sono necessari regolazioni o giri, passa di nuovo la mano sopra il modulo per ruotare Beetle all'angolo desiderato. Ripeti questi passaggi fino a quando lo sprite Beetle raggiunge la mela.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_eat_apple.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Di seguito sono riportati i passaggi per implementare il progetto. Si consiglia di seguirli inizialmente e, una volta acquisita familiarità, è possibile modificare gli effetti come desiderato.

1. Disegnare lo sfondo **Maze**
-------------------------------------

Qui disegneremo uno sfondo mappa con una mela rossa sopra.

* Per prima cosa, seleziona uno sfondo vuoto.

  .. image:: img/apple_click_backdrop.png

* Clicca **Backdrops** per iniziare a disegnare lo sfondo della mappa. Per prima cosa, rinomina lo sfondo in **Maze**.

  .. image:: img/apple_open_backdrop.png

* Usa lo strumento **Line**, imposta il colore su nero, larghezza 4 e inizia a disegnare la mappa. Puoi progettare la tua mappa in base alle tue idee; non deve essere come la mia.

  .. image:: img/apple_paint_bk_maze2.png
    :width: 90%

* Ora, disegna una mela. Usando lo strumento **Circle**, disegna un'ellisse o un cerchio rosso senza contorno.

  .. image:: img/apple_paint_bk_maze3.png

  .. note::

    Puoi rimuovere il contorno cliccando la finestra **Outline** e poi usando lo strumento **Remove**.

    .. image:: img/apple_paint_bk_maze4.png

* Seleziona lo strumento **Brush** e scegli un colore e una larghezza per finire di disegnare la mela.

  .. image:: img/apple_paint_bk_maze5.png

2. Disegnare lo sfondo **Win**
---------------------------------

Ora inizia a disegnare; fai riferimento ai passaggi seguenti o disegna il tuo sfondo in base alla tua creatività, assicurandoti che rappresenti una vittoria.

* Clicca il pulsante per aggiungere un nuovo sfondo in basso, seleziona **Paint** e chiama questo sfondo **Win**.

  .. image:: img/apple_paint_bk_win.png

* Usando lo strumento **Circle**, disegna un'ellisse rossa senza contorno.

  .. image:: img/apple_paint_bk_win2.png
    :width: 90%

* Quindi, usa lo strumento **Text** per scrivere "WIN!". Imposta il colore del carattere su nero e regola la dimensione e la posizione del testo.

  .. image:: img/apple_paint_bk_cus2.png
    :width: 90%

3. Scripting per lo sfondo **Maze**
--------------------------------------

Assicurati che lo sfondo venga impostato su **Maze** ogni volta che il gioco inizia.

.. image:: img/apple_switch_backdrop.png
  :width: 90%

4. Selezionare lo sprite **Beetle**
-----------------------------------------

* Elimina lo sprite predefinito e seleziona lo sprite **Beetle**.

  .. image:: img/apple_choose_sprite.png

* Posiziona lo sprite **Beetle** all'ingresso dello sfondo **Maze**, annotando i valori delle coordinate x, y in questo punto e ridimensiona lo sprite al 40%.

  .. image:: img/apple_place_sprite.png

5. Scripting per lo sprite **Beetle**
-----------------------------------------------

Ora, scrivi uno script per lo sprite **Beetle** per farlo avanzare e cambiare direzione sotto il controllo del modulo evitamento ostacoli sinistro.

* Quando si clicca la bandiera verde, imposta l'angolo di **Beetle** a 90 e la posizione a (-124, -113), o usa i valori delle coordinate del tuo posizionamento.

  .. image:: img/apple_point_in.png
    :width: 90%

* Crea la variabile **flag** e imposta il suo valore iniziale a -1.

  .. image:: img/apple_vable_flag.png

Successivamente, all'interno del blocco [forever], usa quattro blocchi [if] per gestire diversi scenari.

* Se l'infrarosso sinistro è bloccato, usa il blocco [`mod <https://en.scratch-wiki.info/wiki/Boolean_Block>`_] per alternare la variabile **flag** tra 0 e 1 (alternando tra 0 per questa pressione e 1 per la successiva).

   .. image:: img/apple_read_ir.png

* Se flag è 0 (infrarosso sinistro bloccato), lascia che lo sprite **Beetle** giri in senso orario. Se flag è 1 (infrarosso sinistro bloccato di nuovo), **Beetle** avanza. Altrimenti, continua a girare in senso orario.

  .. image:: img/apple_read_flag.png

* Se lo sprite **Beetle** tocca il nero (la linea nera sullo sfondo **Maze**), il gioco termina e lo script smette di funzionare.

  .. image:: img/apple_touch_black1.png

  .. note::

    Clicca sull'area del colore nel blocco [Touch color] e seleziona lo strumento contagocce per prelevare il colore della linea nera sullo stage. Se scegli un nero a caso, questo blocco [Touch color] non funzionerà correttamente.

    .. image:: img/apple_touch_black.png

* Se Beetle tocca il rosso (usa anche lo strumento contagocce per prelevare il colore rosso della mela), lo sfondo passa a **Win**, indicando che il gioco ha avuto successo, e lo script smette di funzionare.

  .. image:: img/apple_touch_red.png

Programmazione completata, ora puoi cliccare la bandiera verde per eseguire lo script e vedere se raggiunge l'effetto desiderato.


  .. raw:: html

    <video loop autoplay muted style = "max-width:70%">
        <source src="../../_static/video/sc_eat_apple.mp4"  type="video/mp4">
        Your browser does not support the video tag.
    </video>