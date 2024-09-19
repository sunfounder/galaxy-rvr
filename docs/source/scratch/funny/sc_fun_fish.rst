.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti esclusivi**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti subito!


Estensione 5 Pesca
===========================

Immergiti nel nostro gioco interattivo di pesca, utilizzando il modulo di evitamento ostacoli sinistro per un'esperienza coinvolgente.

Quando lo script è attivo, i pesci nuoteranno avanti e indietro sul palco. Per catturare un pesce, devi bloccare il modulo di evitamento ostacoli sinistro proprio quando il pesce sta per passare vicino all'amo. Il gioco registra automaticamente il numero di pesci che catturi.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_fishing.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Segui questi passaggi iniziali per configurare il progetto, e sentiti libero di personalizzare gli effetti una volta che avrai familiarità con l'impostazione.

1. Aggiungi Sfondo e Sprite
------------------------------------

Per prima cosa, seleziona uno sfondo **Sottomarino**, poi aggiungi uno sprite **Pesce** e fallo nuotare sul palco.

* Usa il pulsante **Scegli uno Sfondo** per selezionare uno sfondo **Sottomarino**.

  .. image:: img/fish_choose_backdrop.png

* Elimina lo sprite originale, quindi seleziona lo sprite **Pesce**.

  .. image:: img/fish_choose_fish.png

* Regola la dimensione e la posizione dello sprite **Pesce**.

  .. image:: img/fish_set_fish.png

2. Disegna uno Sprite **Amo**
-------------------------------------

Successivamente, crea uno sprite **Amo**, che controllerai tramite il modulo di evitamento ostacoli sinistro per iniziare la pesca.

* Aggiungi lo sprite **Glow-J** tramite **Scegli uno Sprite** e rinominalo "Amo".

  .. image:: img/fish_choose_j.png

* Vai alla pagina **Costumi** dello sprite **Glow-J**, rinominalo **Amo**, seleziona la parte interna bianca della 'J' e cambia il colore in rosso.

  .. image:: img/fish_set_j1.png
    :width: 90%

* Rimuovi il riempimento esterno ciano e riduci la sua larghezza. Assicurati che la parte superiore dell'amo sia allineata con il punto centrale.

  .. image:: img/fish_set_j2.png

* Usa lo **Strumento Linea** per disegnare una linea che si estende verso l'alto dal punto centrale, uscendo dal palco.

  .. image:: img/fish_set_j3.png

3. Programmazione per lo Sprite **Pesce**
---------------------------------------------

Lo sprite **Pesce** deve muoversi a sinistra e a destra sul palco, e quando interagisce con lo sprite **Amo** durante lo stato di pesca, deve ridursi, spostarsi in una posizione specifica, poi scomparire, seguito dalla comparsa di un nuovo sprite **Pesce**.

* Crea una variabile **punteggio** per memorizzare il numero di pesci catturati, nascondi questo sprite e clonalo.

  .. image:: img/fish_script_fish1.png

* Visualizza il clone dello sprite **Pesce**, cambia il suo costume e imposta la posizione iniziale.

  .. image:: img/fish_script_fish2.png

* Fai in modo che il clone dello sprite **Pesce** si muova a sinistra e a destra e rimbalzi quando tocca il bordo del palco.

  .. image:: img/fish_script_fish3.png

* Se il clone dello sprite **Pesce** tocca lo sprite **Amo** durante lo stato di pesca (quando diventa rosso).

  .. image:: img/fish_script_fish4.png
    :width: 90%

* Aumenta il punteggio (variabile punteggio) di 1, mostra un'animazione di punteggio (si riduce del 40%, si sposta rapidamente alla posizione del tabellone dei punteggi e scompare). Contemporaneamente, crea un nuovo pesce (un nuovo clone dello sprite **Pesce**) e continua il gioco.

  .. image:: img/fish_script_fish5.png

4. Programmazione per lo Sprite **Amo**
---------------------------------------------

Lo sprite **Amo** generalmente rimane sott'acqua in uno stato giallo. Quando la tua mano blocca il modulo a infrarossi sul lato sinistro, cambia nello stato di pesca (rosso) e si muove sopra il palco.

* Quando viene cliccata la bandiera verde, imposta l'effetto colore dello sprite su 30 (giallo) e la sua posizione iniziale.

  .. image:: img/fish_script_hook1.png

* Quando la tua mano blocca il modulo a infrarossi sul lato sinistro, imposta l'effetto colore su 0 (rosso, avviando lo stato di pesca), attendi 0,1 secondi, poi sposta lo sprite **Amo** in cima al palco.

  .. image:: img/fish_script_hook2.png

* Dopo aver rimosso la mano, fai tornare l'**Amo** alla sua posizione iniziale.

  .. image:: img/fish_script_hook3.png

Una volta completata la programmazione, clicca sulla bandiera verde per eseguire lo script e vedere se ottieni l'effetto desiderato.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_fishing.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

