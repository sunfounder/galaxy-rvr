.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _sc_balloon:

Divertimento 1: Gonfiare il palloncino
=========================================

In questo progetto interattivo, controlliamo il volo di un palloncino.

Al clic della bandiera verde, il palloncino si gonfierà progressivamente. Se il palloncino diventa troppo grande, scoppierà; se troppo piccolo, cadrà. Il tuo compito è bloccare il modulo a infrarossi sinistro al momento giusto per farlo salire.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_balloon.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Di seguito sono riportati i passaggi per implementare il progetto. Si consiglia di seguire inizialmente questi passaggi e, una volta acquisita familiarità, è possibile modificare gli effetti come desiderato.


1. Aggiungere uno sprite e uno sfondo
----------------------------------------

* Rimuovi lo sprite predefinito e clicca il pulsante **Choose a Sprite** nell'angolo in basso a destra dell'area degli sprite. Quindi, seleziona lo sprite **Balloon1**.

  .. image:: img/balloon_choose_sprite.png

* Aggiungi uno sfondo **Boardwalk** o un altro sfondo a tua scelta tramite il pulsante **Choose a Backdrop**.

  .. image:: img/balloon_choose_backdrop.png

2. Disegnare un costume per lo sprite **Balloon1**
-------------------------------------------------------

Ora, creiamo un costume con effetto esplosione per il palloncino.

* Vai alla scheda **Costumes** per lo sprite **Balloon1**, clicca il pulsante **Choose a Costume** in basso a sinistra e seleziona **Paint** per aprire un **Costume** vuoto. Chiamalo "boom".

  .. image:: img/balloon_set_ball1.png

* Scegli un colore e usa lo strumento **Brush** per disegnare un motivo.

  .. image:: img/balloon_set_ball2.png
    :width: 90%

* Scegli un altro colore, seleziona lo strumento **Fill** e tocca all'interno del motivo per riempirlo.

  .. image:: img/balloon_set_ball3.png
    :width: 90%

* Infine, aggiungi il testo "BOOM" per completare il costume con effetto esplosione.

  .. image:: img/balloon_set_ball4.png
    :width: 90%

3. Scripting per lo sprite **Balloon**
------------------------------------------

* Inizializza la posizione e la dimensione dello sprite **Balloon1**.

  .. image:: img/balloon_script1.png

* Aumenta gradualmente la dimensione dello sprite **Balloon**.

  .. image:: img/balloon_script2.png

* A questo punto, blocca il modulo evitamento ostacoli sinistro per impedire allo sprite **Balloon1** di gonfiarsi ulteriormente.

  .. image:: img/balloon_script3.png

* Ora, lascia che lo sprite **Balloon1** decida se salire o scendere in base alla sua dimensione.

  * Se la dimensione è inferiore a 90, scenderà (la coordinata y diminuisce).
  * Se la dimensione è tra 90 e 120, salirà (la coordinata y aumenta).

  .. image:: img/balloon_script4.png

* Se non riesci a bloccare il modulo evitamento ostacoli sinistro, il palloncino continuerà a gonfiarsi fino a superare una dimensione di 120, momento in cui esploderà (passa al costume con effetto esplosione).

  .. image:: img/balloon_script5.png

La programmazione è completa. Ora puoi cliccare la bandiera verde per eseguire lo script e vedere se raggiunge l'effetto desiderato.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_balloon.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>