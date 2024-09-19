.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti esclusivi**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti subito!


Estensione 2 Flappy Parrot
==============================

In questo progetto, utilizziamo un modulo a ultrasuoni per giocare a Flappy Parrot.

Dopo aver avviato lo script, il bambù verde (Paddle) si sposterà da destra a sinistra a un'altezza casuale. Per controllare il pappagallo, posiziona la mano sopra il modulo a ultrasuoni. Se la distanza tra la tua mano e il modulo è inferiore a 10 cm, il pappagallo salirà; altrimenti scenderà. Devi gestire questa distanza con attenzione per aiutare il pappagallo a superare il bambù verde. Se tocca il bambù, il gioco termina.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Di seguito sono riportati i passaggi per implementare il progetto. Si consiglia di seguire questi passaggi inizialmente e, una volta acquisita familiarità, è possibile modificare gli effetti a piacimento.

1. Aggiungi Sprite
---------------------------

* Elimina lo sprite predefinito e usa il pulsante **Scegli uno Sprite** per aggiungere lo sprite **Parrot**. Imposta la sua dimensione al 50% e posizionalo nell'angolo in basso a sinistra.

  .. image:: img/parrot_choose_parrot.png

* Aggiungi lo sprite **Paddle**, imposta la sua dimensione al 150%, ruotalo di 180 gradi e posizionalo nell'angolo in alto a destra.

  .. image:: img/parrot_choose_paddle.png
 
* Vai alla pagina **Costumi** dello sprite **Paddle**, seleziona il **Paddle** sulla tela e poi clicca lo strumento **Outline**.

  .. image:: img/parrot_set_parrot1.png
    :width: 90%

* Cambia l'effetto contorno in modalità piena e usa lo strumento di rimozione per eliminarlo.

  .. image:: img/parrot_set_parrot2.png
    :width: 90%

2. Programmazione per lo Sprite **Parrot**
------------------------------------------------

Programma lo sprite **Parrot** per simulare il suo volo, con regolazioni dell'altitudine basate sulla distanza rilevata dal modulo a ultrasuoni.

* Quando si clicca sulla bandiera verde, cambia il costume ogni 0,2 secondi per mantenere l'aspetto del volo.

  .. image:: img/parrot_script_parrot1.png

* Se la distanza rilevata dal modulo a ultrasuoni è inferiore a 10 cm, aumenta la coordinata y di 50, facendo salire il **Parrot**. Altrimenti, diminuisci la coordinata y di 40, facendo scendere il **Parrot**.

  .. image:: img/parrot_script_parrot3.png

* Se lo sprite **Parrot** entra in contatto con lo sprite **Paddle**, il gioco termina e lo script cessa di eseguire.

  .. image:: img/parrot_script_parrot4.png

3. Programmazione per lo Sprite **Paddle**
-----------------------------------------------

Programma lo sprite **Paddle** per apparire casualmente sul palco.

* Nascondi lo sprite **Paddle** quando si clicca sulla bandiera verde e crea contemporaneamente un clone di se stesso. Il blocco [`create clone of <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`] controlla questo processo di clonazione.

  .. image:: img/parrot_script_paddle1.png

* Imposta la posizione del clone con la coordinata x a 220 (massimo a destra) e la coordinata y casualmente tra (-125 e 125).

  .. image:: img/parrot_script_paddle2.png

* Usa il blocco [ripeti] per diminuire gradualmente la sua coordinata x, facendo muovere il clone lentamente da destra a sinistra fino a scomparire.

  .. image:: img/parrot_script_paddle3.png

* Ricrea un nuovo sprite **Paddle** e elimina il clone precedente.

  .. image:: img/parrot_script_paddle4.png

La programmazione è completa. Ora puoi cliccare sulla bandiera verde per eseguire lo script e verificare se raggiunge l'effetto desiderato.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_flappy_parrot.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>