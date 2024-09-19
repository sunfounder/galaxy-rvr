.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!


Estensione 4 Mangia la Mela
===========================

In questo progetto, utilizziamo un modulo di evitamento ostacoli a infrarossi per guidare lo sprite Coleottero verso una mela.

Dopo aver cliccato sulla bandiera verde, passa rapidamente la mano sopra il modulo di evitamento ostacoli sinistro (blocca e rimuovi velocemente la mano di fronte al modulo) per avviare la rotazione del Coleottero. Una volta allineato correttamente, passa di nuovo la mano sopra il modulo per far avanzare il Coleottero, assicurandoti che eviti le linee nere sulla mappa. Se sono necessari aggiustamenti o curve, passa nuovamente la mano sopra il modulo per ruotare il Coleottero all'angolo desiderato. Ripeti questi passaggi fino a che lo sprite Coleottero raggiunge la mela.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_eat_apple.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Di seguito sono riportati i passaggi per implementare il progetto. Si consiglia di seguirli inizialmente, e una volta acquisita familiarità, potrai modificare gli effetti come desideri.

1. Disegna lo sfondo **Labirinto**
----------------------------------------

Qui disegneremo uno sfondo della mappa con una mela rossa.

* Per prima cosa, seleziona uno sfondo vuoto.

  .. image:: img/apple_click_backdrop.png

* Clicca su **Sfondi** per iniziare a disegnare lo sfondo della mappa. Prima, rinomina lo sfondo in **Labirinto**.

  .. image:: img/apple_open_backdrop.png

* Usa lo strumento **Linea**, imposta il colore su nero, la larghezza su 4 e inizia a disegnare la mappa. Puoi progettare la tua mappa in base alle tue idee; non deve essere necessariamente come la mia.

  .. image:: img/apple_paint_bk_maze2.png
    :width: 90%

* Ora, disegna una mela. Usando lo strumento **Cerchio**, disegna un'ellisse o un cerchio rosso senza contorno.

  .. image:: img/apple_paint_bk_maze3.png

  .. note::

    Puoi rimuovere il contorno cliccando sulla finestra **Contorno** e poi usando lo strumento **Rimuovi**.

    .. image:: img/apple_paint_bk_maze4.png

* Seleziona lo strumento **Pennello** e scegli un colore e una larghezza per completare il disegno della mela.

  .. image:: img/apple_paint_bk_maze5.png

2. Disegna lo sfondo **Vittoria**
------------------------------------

Ora inizia a disegnare; segui i passaggi sottostanti o disegna uno sfondo basato sulla tua creatività, assicurandoti che rappresenti una vittoria.

* Clicca sul pulsante per aggiungere un nuovo sfondo in basso, seleziona **Disegna** e nomina questo sfondo **Vittoria**.

  .. image:: img/apple_paint_bk_win.png

* Usando lo strumento **Cerchio**, disegna un'ellisse in rosso senza contorno.

  .. image:: img/apple_paint_bk_win2.png
    :width: 90%

* Poi, usa lo strumento **Testo** per scrivere "WIN!". Imposta il colore del carattere su nero e regola la dimensione e la posizione del testo.

  .. image:: img/apple_paint_bk_cus2.png
    :width: 90%

3. Programmazione per lo sfondo **Labirinto**
-------------------------------------------------

Assicurati che lo sfondo sia impostato su **Labirinto** ogni volta che inizia il gioco.

.. image:: img/apple_switch_backdrop.png
  :width: 90%

4. Seleziona lo sprite **Coleottero**
----------------------------------------

* Elimina lo sprite predefinito e seleziona lo sprite **Coleottero**.

  .. image:: img/apple_choose_sprite.png

* Posiziona lo sprite **Coleottero** all'ingresso dello sfondo **Labirinto**, annotando i valori delle coordinate x e y in questo punto, e ridimensiona lo sprite al 40%.

  .. image:: img/apple_place_sprite.png

5. Programmazione per lo sprite **Coleottero**
-------------------------------------------------

Ora, scrivi uno script per lo sprite **Coleottero** in modo che possa muoversi in avanti e cambiare direzione sotto il controllo del modulo di evitamento ostacoli sinistro.

* Quando viene cliccata la bandiera verde, imposta l'angolo del **Coleottero** su 90 e la posizione su (-124, -113), o usa i valori delle coordinate del tuo posizionamento.

  .. image:: img/apple_point_in.png
    :width: 90%

* Crea la variabile **flag** e imposta il suo valore iniziale su -1.

  .. image:: img/apple_vable_flag.png

Successivamente, all'interno del blocco [per sempre], utilizza quattro blocchi [se] per gestire diversi scenari.

* Se l'infrarosso sinistro è bloccato, usa il blocco [`mod <https://en.scratch-wiki.info/wiki/Boolean_Block>`_] per alternare la variabile **flag** tra 0 e 1 (alternando tra 0 per questa pressione e 1 per la successiva).

   .. image:: img/apple_read_ir.png

* Se la variabile flag è 0 (l'infrarosso sinistro è bloccato), fai ruotare lo sprite **Coleottero** in senso orario. Se la variabile flag è 1 (l'infrarosso sinistro è bloccato di nuovo), il **Coleottero** si muove in avanti. Altrimenti, continua a ruotare in senso orario.

  .. image:: img/apple_read_flag.png

* Se lo sprite **Coleottero** tocca il nero (la linea nera sullo sfondo **Labirinto**), il gioco termina e lo script si arresta.

  .. image:: img/apple_touch_black1.png

  .. note::
    
    Clicca sull'area colore nel blocco [Tocca colore] e seleziona lo strumento contagocce per prelevare il colore della linea nera sul palco. Se scegli un nero casuale, questo blocco [Tocca colore] non funzionerà correttamente.

    .. image:: img/apple_touch_black.png

* Se il Coleottero tocca il rosso (utilizza anche lo strumento contagocce per prelevare il colore rosso della mela), lo sfondo cambia su **Vittoria**, indicando che il gioco è stato completato con successo, e lo script si arresta.

  .. image:: img/apple_touch_red.png

Programmazione completata, ora puoi cliccare sulla bandiera verde per eseguire lo script e verificare se ottieni l'effetto desiderato.


  .. raw:: html

    <video loop autoplay muted style = "max-width:70%">
        <source src="../_static/video/sc_eat_apple.mp4"  type="video/mp4">
        Your browser does not support the video tag.
    </video>
