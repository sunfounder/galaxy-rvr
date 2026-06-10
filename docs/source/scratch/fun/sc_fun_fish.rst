.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _sh_fishing:

Divertimento 5: Pesca
===========================

Immergiti nel nostro gioco di pesca interattivo, utilizzando il modulo evitamento ostacoli sinistro per un'esperienza coinvolgente.

Quando lo script è attivo, i pesci nuoteranno avanti e indietro sul palco. Per catturare un pesce, devi bloccare il modulo evitamento ostacoli sinistro proprio mentre il pesce sta per passare l'amo. Il gioco registra automaticamente il numero di pesci che catturi.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_fishing.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Segui questi passaggi iniziali per configurare il progetto e sentiti libero di personalizzare gli effetti una volta acquisita familiarità con la configurazione.

1. Aggiungere sfondo e sprite
------------------------------------

Per prima cosa, seleziona uno sfondo **Underwater**, poi aggiungi uno sprite **Fish** e fallo nuotare attraverso il palco.

* Usa il pulsante **Choose a Backdrop** per selezionare uno sfondo **Underwater**.

  .. image:: img/fish_choose_backdrop.png

* Elimina lo sprite originale, poi seleziona lo sprite **Fish**.

  .. image:: img/fish_choose_fish.png

* Regola la dimensione e la posizione dello sprite **Fish**.

  .. image:: img/fish_set_fish.png

2. Disegnare uno sprite **Fishhook**
-------------------------------------

Successivamente, crea uno sprite **Fishhook**, che controllerai tramite il modulo evitamento ostacoli sinistro per iniziare a pescare.

* Aggiungi lo sprite **Glow-J** tramite **Choose a Sprite** e rinominalo "Fishhook".

  .. image:: img/fish_choose_j.png

* Vai alla pagina **Costumes** dello sprite **Glow-J**, rinominalo **Fishhook**, seleziona la 'J' bianca interna e cambia il suo colore in rosso.

  .. image:: img/fish_set_j1.png
    :width: 90%

* Rimuovi il riempimento ciano esterno e riduci la sua larghezza. Assicurati che la parte superiore dell'amo sia allineata con il punto centrale.

  .. image:: img/fish_set_j2.png

* Usa lo **strumento Linea** per disegnare una linea che si estende verso l'alto dal punto centrale, estendendosi fuori dal palco.

  .. image:: img/fish_set_j3.png

3. Scripting per lo sprite **Fish**
---------------------------------------

Lo sprite **Fish** dovrebbe muoversi a sinistra e a destra sul palco, e quando interagisce con lo sprite **Fishhook** nello stato di pesca, dovrebbe ridursi, spostarsi in una posizione specifica, poi scomparire, seguito dalla generazione di un nuovo sprite **Fish**.

* Crea una variabile **score** per memorizzare il numero di pesci catturati, nascondi questo sprite e clonalo.

  .. image:: img/fish_script_fish1.png

* Mostra il clone dello sprite **Fish**, cambia il suo costume e imposta la posizione iniziale.

  .. image:: img/fish_script_fish2.png

* Abilita il clone dello sprite **Fish** a muoversi a sinistra e a destra e a rimbalzare quando tocca il bordo del palco.

  .. image:: img/fish_script_fish3.png

* Se il clone dello sprite **Fish** tocca lo sprite **Fishhook** nello stato di pesca (quando diventa rosso).

  .. image:: img/fish_script_fish4.png
    :width: 90%

* Aumenta il punteggio (variabile score) di 1, mostra un'animazione di punteggio (si riduce del 40%, si sposta rapidamente alla posizione del tabellone e scompare). Simultaneamente, crea un nuovo pesce (un nuovo clone dello sprite **Fish**) e continua il gioco.

  .. image:: img/fish_script_fish5.png

4. Scripting per lo sprite **Fishhook**
---------------------------------------------

Lo sprite **Fishhook** generalmente rimane sott'acqua in uno stato giallo. Quando la tua mano blocca il modulo a infrarossi sul lato sinistro, passa allo stato di pesca (rosso) e si sposta sopra il palco.

* Quando si clicca la bandiera verde, imposta l'effetto colore dello sprite a 30 (giallo) e imposta la sua posizione iniziale.

  .. image:: img/fish_script_hook1.png

* Quando la tua mano blocca il modulo a infrarossi sul lato sinistro, imposta l'effetto colore a 0 (rosso, avviando lo stato di pesca), attendi 0,1 secondi, poi sposta lo sprite **Fishhook** nella parte superiore del palco.

  .. image:: img/fish_script_hook2.png

* Dopo aver rimosso la mano, lascia che il **Fishhook** ritorni alla sua posizione iniziale.

  .. image:: img/fish_script_hook3.png

Una volta completata la programmazione, clicca la bandiera verde per eseguire lo script e vedere se raggiunge l'effetto desiderato.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_fishing.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

