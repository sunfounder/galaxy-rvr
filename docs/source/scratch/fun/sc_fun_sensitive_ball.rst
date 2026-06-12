.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Divertimento 6: Palla sensibile alla distanza
===========================================================

In questo progetto, utilizziamo un modulo a ultrasuoni per controllare il movimento verticale di una palla sul palco. Quando clicchi la bandiera verde, posiziona la mano sopra il modulo a ultrasuoni. La palla salirà se la distanza tra la tua mano e il modulo è inferiore a 15 cm; altrimenti, scenderà. Quando la palla entra in contatto con una linea, attiva un suono piacevole e attiva effetti di luce stellare scintillante.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Segui questi passaggi per configurare il progetto e sentiti libero di modificare gli effetti a tuo piacimento una volta che ti sarai abituato al funzionamento.

1. Selezionare gli sprite
--------------------------

* Rimuovi lo sprite predefinito e seleziona gli sprite **Ball**, **Bowl** e **Star**.

  .. image:: img/ball_choose_sprite.png

* Posiziona lo sprite **Bowl** al centro in basso del palco e aumenta la sua dimensione.

  .. image:: img/ball_set_bowl.png

* Posiziona lo sprite **Ball** direttamente sopra lo sprite **Bowl**, impostando la sua direzione a 0 per consentire il movimento verticale.

  .. image:: img/ball_set_ball.png

* Regola la dimensione dello sprite **Star** e imposta la sua direzione a 180 per assicurarti che cada verso il basso. Questo può essere modificato in angoli diversi se preferito.

  .. image:: img/ball_set_star.png

* Aggiungi lo sfondo **Stars** per un'atmosfera aggiuntiva.

  .. image:: img/ball_select_backdrop.png

2. Disegnare uno sprite **Line**
--------------------------------

* Ora aggiungi uno sprite **Line**.

  .. image:: img/ball_select_line.png

* Vai alla pagina **Costumes** dello sprite **Line**.

  .. image:: img/ball_open_cos.png
    :width: 90%

* Riduci leggermente la larghezza della linea rossa sulla tela, duplicala quattro volte e allinea queste linee.

  .. image:: img/ball_copy_line.png
    :width: 90%

* Colora ogni linea in modo diverso. Seleziona una linea, usa lo strumento **Fill** e scegli un colore.

  .. image:: img/ball_set_bk_color.png
    :width: 90%

* Applica questo metodo per colorare tutte le linee di conseguenza.

  .. image:: img/ball_select_line_color.png
    :width: 90%

* Torna alla pagina **Code** e posiziona lo sprite **Line** nella parte superiore del palco.

  .. image:: img/ball_line_position.png

3. Scripting per lo sprite **Ball**
-------------------------------------

Qui scriviamo lo script per lo sprite **Ball** per farlo muovere su o giù in base alla distanza rilevata dal modulo a ultrasuoni, con un vincolo di movimento per simulare l'atterraggio sullo sprite **Bowl**.

* Quando si clicca la bandiera verde, imposta la posizione iniziale dello sprite **Ball**.

  .. image:: img/ball_script_ball1.png

* Usa un blocco [if else] per verificare se la distanza è inferiore a 15. Se vero, sposta lo sprite **Ball** in alto di 10 passi, dato che la sua direzione è impostata a 0.

  .. image:: img/ball_script_ball3.png

* Altrimenti, lascia cadere lo sprite **Ball**, limitando la sua coordinata Y a un minimo di -100, regolabile per apparire come se stesse atterrando sullo sprite **Bowl**.

  .. image:: img/ball_script_ball4.png

* Scrivi l'interazione in cui lo sprite **Ball**, toccando lo sprite **Line**, registra la sua posizione Y nella variabile **ball_coor** e trasmette un messaggio **bling**.

  .. image:: img/ball_script_ball5.png

4. Scripting per lo sprite **Star**
------------------------------------

* Inizialmente nascondi lo sprite **Star** quando si clicca la bandiera verde. Alla ricezione del messaggio **Bling**, clona lo sprite **Star**.

  .. image:: img/ball_script_star1.png

* Imposta la posizione del clone e gli effetti sonori per sincronizzarli con la posizione dello sprite **Ball**.

  .. image:: img/ball_script_star2.png

* Consentigli di ruotare tra -80 e 80 gradi casualmente.

  .. image:: img/ball_script_star3.png

* Regola l'aspetto e il comportamento dello sprite **Star** come necessario per migliorare l'effetto visivo.

  .. image:: img/ball_script_star4.png

La programmazione è completa. Clicca la bandiera verde per eseguire lo script e vedere se soddisfa le tue aspettative.


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>