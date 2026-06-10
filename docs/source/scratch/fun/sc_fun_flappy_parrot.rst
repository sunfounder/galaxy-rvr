.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _sc_parrot:

Divertimento 2: Flappy Parrot
==============================

In questo progetto, utilizziamo un modulo a ultrasuoni per giocare a Flappy Parrot.

Dopo aver avviato lo script, il bambù verde (Paddle) si sposterà da destra a sinistra a un'altezza casuale. Per controllare il pappagallo, posiziona la mano sopra il modulo a ultrasuoni. Se la distanza tra la mano e il modulo è inferiore a 10 cm, il pappagallo salirà; altrimenti, scenderà. Devi gestire questa distanza con attenzione per aiutare il pappagallo a superare il bambù verde. Il contatto con il bambù termina il gioco.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Di seguito sono riportati i passaggi per implementare il progetto. Si consiglia di seguire inizialmente questi passaggi e, una volta acquisita familiarità, è possibile modificare gli effetti come desiderato.

1. Aggiungere sprite
---------------------------

* Elimina lo sprite predefinito e usa il pulsante **Choose a Sprite** per aggiungere lo sprite **Parrot**. Imposta la sua dimensione al 50% e posizionalo nell'angolo in basso a sinistra.

  .. image:: img/parrot_choose_parrot.png

* Aggiungi lo sprite **Paddle**, imposta la sua dimensione al 150%, ruotalo di 180 gradi e posizionalo nell'angolo in alto a destra.

  .. image:: img/parrot_choose_paddle.png

* Vai alla pagina **Costumes** dello sprite **Paddle**, seleziona il **Paddle** sulla tela e poi clicca lo strumento **Outline**.

  .. image:: img/parrot_set_parrot1.png
    :width: 90%

* Cambia l'effetto contorno in modalità riempimento completo e usa lo strumento di rimozione per eliminarlo.

  .. image:: img/parrot_set_parrot2.png
    :width: 90%

2. Scripting per lo sprite **Parrot**
---------------------------------------------

Scrivi lo script per lo sprite **Parrot** per simulare il suo volo, con regolazioni dell'altitudine basate sulla distanza di rilevamento del modulo a ultrasuoni.

* Quando si clicca la bandiera verde, cambia il costume ogni 0,2 secondi per mantenere l'aspetto del volo.

  .. image:: img/parrot_script_parrot1.png

* Se la distanza di rilevamento a ultrasuoni è inferiore a 10 cm, aumenta la coordinata y di 50, facendo salire il **Parrot**. Altrimenti, diminuisci la coordinata y di 40, facendo scendere il **Parrot**.

  .. image:: img/parrot_script_parrot3.png

* Se lo sprite **Parrot** entra in contatto con lo sprite **Paddle**, il gioco termina e lo script cessa l'esecuzione.

  .. image:: img/parrot_script_parrot4.png

3. Scripting per lo sprite **Paddle**
-----------------------------------------------

Scrivi lo script per lo sprite **Paddle** per apparire casualmente sul palco.

* Nascondi lo sprite **Paddle** quando si clicca la bandiera verde e crea simultaneamente un clone di se stesso. Il blocco [`create clone of <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_] controlla questo processo di clonazione.

  .. image:: img/parrot_script_paddle1.png

* Imposta la posizione del clone con la coordinata x a 220 (estrema destra) e la coordinata y casualmente tra (-125 e 125).

  .. image:: img/parrot_script_paddle2.png

* Usa il blocco [repeat] per diminuire gradualmente la sua coordinata x, facendo muovere il clone lentamente da destra a sinistra fino a scomparire.

  .. image:: img/parrot_script_paddle3.png

* Riclona un nuovo sprite **Paddle** ed elimina il clone precedente.

  .. image:: img/parrot_script_paddle4.png

La programmazione è completa. Ora puoi cliccare la bandiera verde per eseguire lo script e vedere se raggiunge l'effetto desiderato.


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>