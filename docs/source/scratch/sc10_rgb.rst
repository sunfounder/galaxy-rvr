.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!


Lezione 10: Illuminare il cammino con strisce LED RGB
===============================================================

Il nostro Mars Rover è diventato un abile esploratore, ma ora è il momento di aggiungere un po' di personalità colorata! In questa lezione, trasformeremo il nostro rover con strisce LED RGB che possono brillare in qualsiasi colore immaginabile.

Immagina il tuo GalaxyRVR illuminare il suo cammino come un'astronave di un film di fantascienza:

- Bagliore verde quando avanza
- Luce rossa quando si ferma
- Lampi gialli quando gira
- Bellissimi spettacoli di colori solo per divertimento!

Impareremo a programmare queste fantastiche luci e a sincronizzarle con i movimenti del tuo rover. Preparati a creare il tuo esploratore marziano luminoso!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/car_rgb.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

Obiettivi di apprendimento
--------------------------

* Scoprire come funzionano le strisce LED RGB e come programmarle
* Imparare a controllare i colori e creare effetti di luce usando Mammoth Coding
* Progettare segnali luminosi e colori per le tue missioni di esplorazione marziana

Esplorare la magia della luce con le strisce LED RGB
-------------------------------------------------------------

Hai mai desiderato creare il tuo arcobaleno? Ora puoi! Con le strisce LED RGB, puoi far brillare il tuo Mars Rover con qualsiasi colore tu possa immaginare. Scopriamo la magia delle luci colorate!

.. image:: img/4_rgb_strip.jpg

Ecco i quattro pin importanti sulla tua striscia LED:

* **+5V** - Il pin di alimentazione che dà energia a tutte le luci (necessita di 5V)
* **B** - Controlla le luci blu
* **R** - Controlla le luci rosse
* **G** - Controlla le luci verdi

.. image:: img/rgb_5050.jpg

Ricordi di aver imparato i colori primari a lezione d'arte? Proprio come mescolare la pittura, ogni LED può fondere luce rossa, blu e verde per creare colori fantastici! Ogni LED "5050" è come una piccola fabbrica di colori che contiene tutti e tre i colori.

.. image:: img/rgb_5050_sche.png

Tutte queste fabbriche di colori sono collegate insieme su un circuito flessibile, come un'autostrada elettrica colorata! I pin di alimentazione si collegano insieme, mentre i pin dei colori hanno ciascuno il proprio percorso speciale.

.. image:: img/rgb_strip_sche.png

La parte più emozionante? Puoi programmare TUTTI i LED per cambiare colore contemporaneamente! Immagina di creare il tuo spettacolo di luci con solo pochi blocchi di codice. Preparati a illuminare la tua avventura con il Mars Rover!

Accendere lo spettacolo
------------------------------

#. Prima, :ref:`app_connect`.

#. Ora, facciamo brillare il tuo GalaxyRVR! Trascina un blocco "display color" per iniziare.

   .. image:: img/9_rgb_block.png

#. Scegli qualsiasi colore ti piaccia dal menu dei colori.

   .. image:: img/9_rgb_color.png

#. Clicca il blocco e guarda il tuo GalaxyRVR illuminarsi con il colore che hai scelto!

**Crea un controller di colori**

Ora costruiamo un controller di colori interattivo! Creeremo pulsanti colorati sullo stage che cambiano le luci del tuo GalaxyRVR quando li tocchi.

1. Prima, elimina qualsiasi sprite esistente per ricominciare da capo.

   .. image:: img/6_animate_delete.png

2. Aggiungi uno sprite Ball dalla libreria. Questo sprite è perfetto perché viene fornito con costumi di più colori.

   .. image:: img/9_animate_rgb_ball.png

3. Aggiungi un blocco "when this sprite clicked" - questo farà accadere cose quando tocchi la palla.

   .. image:: img/9_animate_rgb_when.png

4. Collega un blocco "display color" per illuminare il tuo GalaxyRVR.

   .. image:: img/9_animate_rgb_display.png

5. Sugli schermi piccoli, assicurati di poter vedere lo stage cliccando il pulsante dell'occhio.

   .. image:: img/9_animate_rgb_eye.png

6. Clicca la casella del colore nel blocco display, poi clicca il pulsante del selettore colore in basso.

   .. image:: img/9_animate_rgb_pick.png

7. Tieni premuto sull'area dello stage: apparirà una lente d'ingrandimento! Rilasciala sopra lo sprite della palla per copiare il suo colore.

   .. image:: img/9_animate_rgb_pick_color_n.png

8. Crea più pulsanti colore tenendo premuto lo sprite della palla per duplicarlo.

   .. image:: img/9_animate_rgb_duplicate.png

9. Cambia ogni duplicato in un colore diverso cambiando il suo costume.

   .. image:: img/9_animate_rgb_change_costume.png

10. Per ogni nuovo colore, usa il selettore colore per far corrispondere il blocco display al colore corrente dello sprite.

   .. image:: img/9_animate_rgb_pick_blue.png

11. Ripeti fino ad avere cinque diversi pulsanti colore!

   .. image:: img/9_animate_rgb_ball5.png

Ora tocca qualsiasi palla colorata sullo stage e guarda il tuo GalaxyRVR brillare di quel colore! Crea il tuo spettacolo di luci con un solo tocco.

.. _rgb_move:

Luci di segnalazione GalaxyRVR in azione
----------------------------------------------------------------

**Luci indicatrici direzionali**

Combiniamo i colori delle luci con il movimento per creare luci di segnalazione per il tuo GalaxyRVR! Proprio come un'auto ha gli indicatori di direzione, il tuo rover si illuminerà in diversi colori quando si muove.

#. Prima, :ref:`app_connect`.

#. Ora, imposta i tasti direzionali con blocchi di movimento per tutte e quattro le direzioni.

   .. image:: img/9_rgb_move.png

#. Aggiungi display di colore a ciascuna direzione:

   - Luce verde per andare avanti

   .. image:: img/9_rgb_green.png

   - Luci gialle per girare a sinistra e a destra

   .. image:: img/9_rgb_yellow.png

   - Luce rossa per andare indietro

   .. image:: img/9_rgb_red.png

Ora quando premi i tasti direzionali, il tuo GalaxyRVR si muoverà e brillerà con il colore corrispondente!

**Effetto luce respiro**

Creiamo un fantastico effetto di luce che pulsa lentamente quando il tuo rover è fermo, proprio come se stesse respirando!

1. Crea un nuovo messaggio broadcast chiamato "stop" per segnalare quando il rover non si sta muovendo.

   .. image:: img/9_rgb_new_message.png

   .. note:: I messaggi broadcast aiutano a organizzare il codice attivando azioni specifiche al momento giusto, rendendo i tuoi programmi più puliti e facili da capire.

2. Aggiungi questo broadcast dopo ogni comando di movimento.

   .. image:: img/9_rgb_new_boardcast.png

3. Crea un blocco "when I receive [stop]" per avviare la luce respiro.

   .. image:: img/9_rgb_when_receive.png

4. Imposta la luminosità allo 0% per partire da completamente spento.

   .. image:: img/9_rgb_set_bright.png

5. Usa un ciclo repeat per aumentare gradualmente la luminosità della luce blu del 10% ogni 0,2 secondi.

   .. image:: img/9_rgb_increase.png

6. Poi diminuisci gradualmente la luminosità per completare un ciclo di respiro.

   .. image:: img/9_rgb_decrease.png

7. Invia di nuovo "stop" per mantenere l'effetto respiro continuo.

   .. image:: img/9_rgb_stopagain.png

8. Aggiungi "stop other scripts" alla fine di ogni evento tasto per prevenire conflitti di colore.

   .. image:: img/9_rgb_stop.png

9. Reimposta la luminosità della luce in ogni evento tasto direzionale.

   .. image:: img/9_rgb_set_bright_each.png

Ora il tuo GalaxyRVR si illuminerà con segnali colorati quando è in movimento e pulserà delicatamente con una luce blu respirante quando è fermo!

Blocchi relativi al modulo RGB
-------------------------------


* Illumina il tuo GalaxyRVR con qualsiasi colore tu scelga.

  - Clicca la casella del colore per scegliere il tuo colore preferito

  .. image:: img/block/rgb_display.png


* Illumina il tuo GalaxyRVR per un periodo di tempo specifico.

  - Scegli qualsiasi colore
  - Imposta per quanto tempo la luce rimane accesa

  .. image:: img/block/rgb_display_1s.png

* Crea colori personalizzati mescolando luce rossa, verde e blu - perfetto per progetti di dissolvenza colore!

  - R: Luminosità rossa (0-255)
  - G: Luminosità verde (0-255)
  - B: Luminosità blu (0-255)

  .. image:: img/block/rgb_display_RGB.png

* Mostra colori RGB personalizzati per un tempo impostato.

  - Regola i valori rosso, verde e blu (0-255)
  - Imposta la durata di visualizzazione

  .. image:: img/block/rgb_display_RGB_1s.png

* Imposta quanto luminose devono essere le luci (0-100%).

  .. image:: img/block/rgb_set_brightness.png

* Rendi le luci più luminose o più fioche. Usa numeri negativi per diminuire la luminosità.

  .. image:: img/block/rgb_increase_brightness.png


* Accendi o spegni le luci RGB.

  .. image:: img/block/rgb_turn_on.png
