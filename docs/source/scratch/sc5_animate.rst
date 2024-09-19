.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme agli altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!



Lezione 5 Animazione Interattiva
===============================================

In precedenza, abbiamo utilizzato il modulo ultrasonico per far sì che il GalaxyRVR evitasse automaticamente gli ostacoli sul suo cammino.

In questa attività, combineremo il modulo con un palcoscenico per creare un'animazione interattiva di un rover che attraversa gioiosamente la superficie di Marte.


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_jump.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>



Obiettivi di Apprendimento
------------------------------

* Imparare a disegnare personaggi e modificare sfondi.
* Comprendere concetti base di programmazione come ascoltatori di eventi e strutture di loop.
* Familiarizzare con l'ambiente di programmazione dell'APP e le operazioni di base per creare una semplice animazione che simula un rover marziano.

Materiali
------------

* Smartphone o tablet
* APP Mammoth Coding
* GalaxyRVR


Aggiunta di Nuovi Personaggi
--------------------------------

Elimina lo sprite che non ti serve.

.. image:: img/6_animate_delete.png
..   :align: left



Nell'angolo in basso a destra dell'interfaccia, vedrai il pulsante "scegli un personaggio". Toccalo per rivelare quattro opzioni a comparsa.


.. image:: img/2_create_sp.png
..  :align: left

Per schermi più piccoli, potrebbe essere necessario navigare in una schermata diversa per vedere questo pulsante.


.. image:: img/2_create_sp0.png
..  :align: left



Le quattro opzioni sono:

* **Carica Personaggio** : Carica uno sprite dall'archivio del tuo dispositivo.
* **Sorpresa** : Seleziona casualmente uno sprite dalla libreria.
* **Disegna** : Disegna un personaggio.
* **Scegli un Personaggio** : Apri la libreria per scegliere uno sprite.

Successivamente, utilizzeremo **Scegli un Personaggio** per selezionare uno sprite e **Disegna** per crearne uno.


**Scegli un Personaggio**

Clicca su "scegli un personaggio" (icona della lente d'ingrandimento) per accedere alla libreria, che fornisce una ricca selezione di risorse per il tuo palcoscenico.

.. image:: img/2_sp_list.png
.. :align: left

Trova e seleziona GalaxyRVR dalla libreria.

.. image:: img/2_sprite_rvr.png
.. :align: left




**Disegna un Nuovo Personaggio**

Creeremo uno sprite "Marte", ma purtroppo non ci sono risorse adatte nella libreria.

Pertanto, selezioneremo **Disegna** (icona del pennello) e lo disegneremo noi stessi.

.. image:: img/2_create_custom.png
.. :align: left

Per prima cosa, utilizza lo strumento cerchio per disegnare un cerchio che rappresenti il pianeta.

.. image:: img/2_create_custom1.png
.. :align: left

Quindi, usa lo strumento puntatore per spostare il cerchio in modo che sia allineato al centro del canvas.
Questo passaggio è cruciale perché le coordinate, la direzione e i movimenti del tuo sprite sono basati sul suo punto centrale.

.. image:: img/2_create_custom2.png
.. :align: left

Usa lo strumento secchiello per colorare il pianeta di rosso.

.. image:: img/2_create_custom3.png
.. :align: left

Successivamente, seleziona lo strumento pennello, aumenta la dimensione e scegli un colore appropriato dalle opzioni di riempimento per aggiungere texture a Marte.

.. image:: img/2_create_custom_pen.png
.. :align: left

Se trovi il colore inadatto dopo aver dipinto, puoi cambiare il colore di riempimento e usare il secchiello per riempire nuovamente la forma.

.. image:: img/2_create_custom5.png
.. :align: left

Seleziona di nuovo il pennello, imposta la dimensione a 2 e cambia il colore in nero. Usa la tua creatività per aggiungere crateri e dettagli a Marte.

.. image:: img/2_create_custom6.png
.. :align: left

Usando il secchiello, scegli un colore appropriato per riempire questi crateri.

.. image:: img/2_create_custom7.png
.. :align: left

Una volta completato, torna all'interfaccia Codice. Il tuo sprite Marte è ora pronto.

.. image:: img/2_create_custom8.png
.. :align: left

Per schermi più piccoli, torna all'interfaccia Codice cliccando qui.

.. image:: img/2_create_custom8.1.png
.. :align: left

Vedrai lo sprite Marte sul palcoscenico. Non dimenticare di rinominarlo.

.. image:: img/2_create_custom9.png
.. :align: left




**Palcoscenico**


Clicca sugli sfondi. L'attuale sfondo è bianco; dobbiamo scurirlo per simulare il cielo notturno.

1. Clicca sugli Sfondi del palcoscenico.

.. image:: img/6_jump_backdrop.png
.. :align: left

2. Entra nell'interfaccia Sfondi.

.. image:: img/6_jump_backdrop_page.png
.. :align: left

2. Disegna un rettangolo.

.. image:: img/6_jump_rect.png
.. :align: left

3. Usa il secchiello per riempirlo con un colore scuro.

.. image:: img/6_jump_fill.png
.. :align: left

4. Usa lo strumento pennello per aggiungere delle stelle.

.. image:: img/6_jump_paint.png
.. :align: left



Creare l'Animazione
------------------------

Ora che abbiamo Marte e GalaxyRVR e sappiamo come animare gli sprite, creiamo un'animazione in cui GalaxyRVR si muove su Marte.
Possiamo far sembrare che lo sprite si stia muovendo facendo ruotare Marte nella direzione opposta, creando l'effetto di GalaxyRVR che attraversa la sua superficie.

Regola la dimensione e la posizione degli sprite, 
imposta le coordinate dello sprite GalaxyRVR su 0,0 e posizionalo su Marte.

Imposta la posizione e la dimensione dello sprite Marte in modo che lo sprite GalaxyRVR sembri "stare" su di esso.

.. image:: img/6_jump_place.png
.. :align: left


**Sprite Marte**

.. image:: img/6_ssp_mars.png
    :align: left

Seleziona lo sprite Marte. Il suo compito è ruotare in senso antiorario, creando l'illusione che GalaxyRVR stia avanzando.


.. raw:: html

   <br></br>

1. Trascina un blocco con la bandiera verde. Tutte le animazioni iniziano con la bandiera verde.

.. image:: img/6_jump_mar_flag.png
.. :align: left

2. Trascina un blocco ``per sempre`` per mantenere l'animazione in esecuzione continua.

.. image:: img/6_jump_mar_forever.png
.. :align: left

3. Trascina un blocco ``ruota`` e un blocco ``attendi`` per far ruotare Marte continuamente.

.. image:: img/6_jump_mar_turn.png
.. :align: left


Ora clicca sulla bandiera verde e vedrai Marte ruotare in senso antiorario.



**Sprite GalaxyRVR**

.. image:: img/6_ssp_rvr.png
    :align: left


Seleziona lo sprite GalaxyRVR. Il suo compito è animarsi come se si stesse muovendo, anche se in realtà non si muove.

.. raw:: html

   <br></br>

1. Trascina un blocco con la bandiera verde. Tutte le animazioni iniziano con la bandiera verde.

.. image:: img/6_jump_mar_flag.png
.. :align: left


2. Trascina un blocco ``per sempre`` per mantenere l'animazione in esecuzione continua.

.. image:: img/6_jump_mar_forever.png
.. :align: left

3. Trascina un blocco ``costume successivo`` e un blocco ``attendi`` per far animare continuamente GalaxyRVR.

.. image:: img/6_jump_mar_next.png
.. :align: left


**Aggiungere Più Divertimento**

.. image:: img/6_ssp_rvr.png
    :align: left

Possiamo aggiungere interattività a questa animazione utilizzando il modulo ultrasonico per far saltare lo sprite GalaxyRVR e evitare ostacoli.

Continua a programmare nello sprite GalaxyRVR.


1. Trascina un blocco ``quando distanza``. Questo si attiverà quando il modulo ultrasonico rileva un ostacolo (es., la tua mano).

.. image:: img/6_jump_when.png
.. :align: left

2. Trascina due blocchi ``scivola`` e cambia il valore di y del primo per far saltare lo sprite in alto e poi scendere, creando un effetto di salto.

.. image:: img/6_jump_glide.png
.. :align: left


3. Il codice completo per lo sprite GalaxyRVR dovrebbe essere simile a questo:

.. image:: img/6_jump_mar_rvr_all.png
.. :align: left


Ora, clicca sulla bandiera verde per avviare l'animazione. Simula un ostacolo mettendo la tua mano davanti al modulo ultrasonico, e lo sprite GalaxyRVR salterà per evitarlo.

