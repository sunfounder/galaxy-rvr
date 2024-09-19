.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!


.. _sc_balloon:

Estensione 1 Gonfiare il Palloncino
=========================================

In questo progetto interattivo, controlleremo il volo di un palloncino.

Cliccando sulla bandiera verde, il palloncino si gonfierà progressivamente. Se diventa troppo grande, scoppierà; se è troppo piccolo, cadrà. Il tuo compito è bloccare il modulo a infrarossi sinistro al momento giusto per farlo salire.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_balloon.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Di seguito sono riportati i passaggi per implementare il progetto. È consigliabile seguire questi passaggi inizialmente, e una volta che avrai acquisito familiarità, potrai modificare gli effetti come desideri.


1. Aggiungere uno Sprite e uno Sfondo
----------------------------------------

* Rimuovi lo sprite predefinito e clicca sul pulsante **Scegli uno Sprite** nell'angolo in basso a destra dell'area degli sprite. Poi, seleziona lo sprite **Balloon1**.

  .. image:: img/balloon_choose_sprite.png

* Aggiungi uno sfondo **Boardwalk** o un altro sfondo a tua scelta tramite il pulsante **Scegli uno Sfondo**.

  .. image:: img/balloon_choose_backdrop.png

2. Disegnare un Costume per lo Sprite **Balloon1**
-------------------------------------------------------

Ora, creiamo un costume per l'effetto esplosione del palloncino.

* Vai alla scheda **Costumi** dello sprite **Balloon1**, clicca sul pulsante **Scegli un Costume** in basso a sinistra e seleziona **Disegna** per aprire un costume vuoto. Nominalo "boom".

  .. image:: img/balloon_set_ball1.png

* Scegli un colore e utilizza lo strumento **Pennello** per disegnare un motivo.

  .. image:: img/balloon_set_ball2.png
    :width: 90%

* Scegli un altro colore, seleziona lo strumento **Riempi** e clicca all'interno del motivo per riempirlo.

  .. image:: img/balloon_set_ball3.png
    :width: 90%

* Infine, aggiungi il testo "BOOM" per completare il costume dell'effetto esplosione.

  .. image:: img/balloon_set_ball4.png
    :width: 90%

3. Programmare lo Sprite **Balloon**
------------------------------------------

* Inizializza la posizione e la dimensione dello sprite **Balloon1**.

  .. image:: img/balloon_script1.png

* Aumenta gradualmente la dimensione dello sprite **Balloon**.

  .. image:: img/balloon_script2.png

* A questo punto, blocca il modulo di evitamento ostacoli sinistro per impedire che lo sprite **Balloon1** si gonfi ulteriormente.

  .. image:: img/balloon_script3.png

* Ora, fai decidere allo sprite **Balloon1** se salire o scendere in base alla sua dimensione.

  * Se la dimensione è inferiore a 90, scenderà (la coordinata y diminuisce).
  * Se la dimensione è compresa tra 90 e 120, salirà (la coordinata y aumenta).

  .. image:: img/balloon_script4.png

* Se non riesci a bloccare il modulo di evitamento ostacoli sinistro, il palloncino continuerà a gonfiarsi fino a superare la dimensione di 120, a quel punto esploderà (passando al costume dell'effetto esplosione).

  .. image:: img/balloon_script5.png

La programmazione è completata. Ora puoi cliccare sulla bandiera verde per eseguire lo script e vedere se ottieni l'effetto desiderato.


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_balloon.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>
