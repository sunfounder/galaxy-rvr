.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme agli altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

Estensione 6 Pallina Sensibile alla Distanza
===========================================================

In questo progetto, utilizziamo un modulo ultrasonico per controllare il movimento verticale di una pallina sulla scena. Quando clicchi sulla bandiera verde, posiziona la tua mano sopra il modulo ultrasonico. La pallina salirà se la distanza tra la tua mano e il modulo è inferiore a 15 cm; altrimenti, scenderà. Quando la pallina tocca una linea, si attiva un suono piacevole e si innescano effetti di stelle scintillanti.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Segui questi passaggi per configurare il progetto, e sentiti libero di modificare gli effetti a tuo piacimento una volta che hai familiarizzato con il funzionamento.

1. Seleziona gli Sprite
---------------------------

* Rimuovi lo sprite predefinito e seleziona gli sprite **Pallina**, **Ciotola** e **Stella**.

  .. image:: img/ball_choose_sprite.png

* Posiziona lo sprite **Ciotola** al centro inferiore della scena e aumentane la dimensione.

  .. image:: img/ball_set_bowl.png

* Posiziona lo sprite **Pallina** direttamente sopra lo sprite **Ciotola**, impostando la sua direzione a 0 per consentire il movimento verticale.

  .. image:: img/ball_set_ball.png

* Regola la dimensione dello sprite **Stella** e imposta la sua direzione a 180 per farlo cadere verso il basso. Puoi modificarlo ad angoli diversi se preferisci.

  .. image:: img/ball_set_star.png

* Aggiungi lo sfondo **Stelle** per creare un'atmosfera suggestiva.

  .. image:: img/ball_select_backdrop.png

2. Disegna uno Sprite **Linea**
-----------------------------------

* Ora aggiungi uno sprite **Linea**.

  .. image:: img/ball_select_line.png

* Vai alla pagina **Costumi** dello sprite **Linea**.

  .. image:: img/ball_open_cos.png
    :width: 90%

* Riduci leggermente la larghezza della linea rossa sul canvas, duplicala quattro volte e allinea queste linee.

  .. image:: img/ball_copy_line.png
    :width: 90%

* Colora ciascuna linea in modo diverso. Seleziona una linea, usa lo strumento **Riempi** e scegli un colore.

  .. image:: img/ball_set_bk_color.png
    :width: 90%

* Applica questo metodo per colorare tutte le linee di conseguenza.

  .. image:: img/ball_select_line_color.png
    :width: 90%

* Torna alla pagina **Codice** e posiziona lo sprite **Linea** nella parte superiore della scena.

  .. image:: img/ball_line_position.png

3. Script per lo Sprite **Pallina**
--------------------------------------

Qui scriviamo lo script per lo sprite **Pallina** per muoversi su o giù in base alla distanza rilevata dal modulo ultrasonico, con un vincolo di movimento per simulare l'atterraggio sulla sprite **Ciotola**.

* Quando si clicca sulla bandiera verde, imposta la posizione iniziale dello sprite **Pallina**.

  .. image:: img/ball_script_ball1.png

* Usa un blocco [se altrimenti] per verificare se la distanza è inferiore a 15. Se è vero, sposta lo sprite **Pallina** verso l'alto di 10 passi, dato che la sua direzione è impostata su 0.

  .. image:: img/ball_script_ball3.png

* Altrimenti, fai cadere lo sprite **Pallina**, limitando la sua coordinata Y a un minimo di -100, regolabile per far sembrare che atterri sulla sprite **Ciotola**.

  .. image:: img/ball_script_ball4.png

* Scrivi un'interazione in cui lo sprite **Pallina**, quando tocca lo sprite **Linea**, registra la sua posizione Y nella variabile **ball_coor** e invia un messaggio **bling**.

  .. image:: img/ball_script_ball5.png

4. Script per lo Sprite **Stella**
-------------------------------------

* Inizialmente nascondi lo sprite **Stella** quando si clicca sulla bandiera verde. Al ricevimento del messaggio **Bling**, clona lo sprite **Stella**.

  .. image:: img/ball_script_star1.png

* Imposta la posizione e gli effetti sonori del clone in modo che si sincronizzino con la posizione dello sprite **Pallina**.

  .. image:: img/ball_script_star2.png

* Consenti di ruotare tra -80 e 80 gradi in modo casuale.

  .. image:: img/ball_script_star3.png

* Regola l'aspetto e il comportamento dello sprite **Stella** come necessario per migliorare l'effetto visivo.

  .. image:: img/ball_script_star4.png

La programmazione è completata. Clicca sulla bandiera verde per eseguire lo script e verificare se soddisfa le tue aspettative.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_sensitive_ball.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>
