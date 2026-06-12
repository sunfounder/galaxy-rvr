.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lezione 5: Animazione interattiva
===============================================

In precedenza, abbiamo usato il modulo a ultrasuoni per far evitare automaticamente al GalaxyRVR gli ostacoli sul suo percorso.

In questa attività, combineremo il modulo con uno stage per creare un'animazione interattiva di un rover che attraversa gioiosamente la superficie di Marte.


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_jump.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Obiettivi di apprendimento
--------------------------

* Imparare a disegnare sprite e modificare sfondi.
* Comprendere concetti di programmazione di base come listener di eventi e strutture di loop.
* Familiarizzare con l'ambiente di programmazione dell'APP e le operazioni di base per creare una semplice animazione che simula un rover marziano.

Aggiungere nuovi sprite
----------------------------

#. Prima, :ref:`app_connect`.

#. Elimina gli sprite che non ti servono.

   .. image:: img/6_animate_delete.png

#. Nell'angolo in basso a destra dell'interfaccia, tocca il pulsante **Choose a Sprite** per rivelare quattro opzioni.

   .. image:: img/5_create_sp.png

#. Sugli schermi più piccoli, potresti dover passare a un'altra schermata per vedere questo pulsante.

   .. image:: img/5_create_sp0.png

Le quattro opzioni sono:

* **Upload Sprite** – Carica uno sprite dal tuo dispositivo.
* **Surprise** – Seleziona casualmente uno sprite dalla libreria.
* **Paint** – Disegna il tuo sprite.
* **Choose a Sprite** – Seleziona dalla libreria degli sprite.

Successivamente, useremo **Choose a Sprite** per selezionare uno sprite e **Paint** per disegnarne uno.

**Choose a Sprite**

#. Tocca **Choose a Sprite** (icona della lente d'ingrandimento) per aprire la libreria degli sprite.

   .. image:: img/5_sp_list.png

#. Trova e seleziona **GalaxyRVR** dalla libreria.

   .. image:: img/1_choose_galaxyrvr.png


**Paint a New Sprite**

#. Tocca **Paint** (icona del pennello) per creare un nuovo sprite. Disegneremo uno sprite **Marte**.

   .. image:: img/5_create_custom.png

#. Usa lo **Strumento Cerchio** per disegnare un cerchio che rappresenta il pianeta.

   .. image:: img/5_create_custom1.png

#. Usa lo **Strumento Puntatore** per spostare il cerchio al centro della tela. Questo passaggio è importante perché le coordinate e i movimenti dello sprite sono basati sul suo centro.

   .. image:: img/5_create_custom2.png

#. Usa lo **Strumento Secchiello** per riempire il cerchio di rosso.

   .. image:: img/5_create_custom3.png

#. Seleziona lo **Strumento Pennello**, aumenta la dimensione del pennello e aggiungi texture con un colore di riempimento adatto.

   .. image:: img/5_create_custom_pen.png

#. Se il colore non sembra giusto, cambia il colore di riempimento e usa di nuovo lo **Strumento Secchiello**.

   .. image:: img/5_create_custom5.png

#. Seleziona di nuovo lo **Strumento Pennello**, imposta la dimensione a 2, cambia il colore in nero e disegna crateri su Marte.

   .. image:: img/5_create_custom6.png

#. Usa lo **Strumento Secchiello** per riempire i crateri con un colore adatto.

   .. image:: img/5_create_custom7.png

#. Una volta finito, torna all'**Interfaccia Codice**.

   .. image:: img/5_create_custom8.png

#. Sugli schermi più piccoli, clicca l'icona per tornare all'Interfaccia Codice.

   .. image:: img/5_create_custom8.1.png

#. Ora vedrai lo sprite Marte sullo stage. Non dimenticare di **rinominarlo**.

   .. image:: img/5_create_custom9.png


**Stage**

#. Clicca su **Backdrops** per modificare lo sfondo. Lo sfondo bianco predefinito sarà cambiato per simulare un cielo notturno.

   .. image:: img/6_jump_backdrop.png

#. Entra nell'interfaccia **Backdrops**.

   .. image:: img/6_jump_backdrop_page.png

#. Disegna un rettangolo sulla tela.

   .. image:: img/6_jump_rect.png

#. Usa lo **Strumento Secchiello** per riempirlo con un colore scuro.

   .. image:: img/6_jump_fill.png

#. Usa lo **Strumento Pennello** per aggiungere alcune stelle.

   .. image:: img/6_jump_paint.png


Creare l'animazione
-------------------------------

Ora che abbiamo Marte e GalaxyRVR, e sappiamo come animare gli sprite, creiamo un'animazione di GalaxyRVR che si muove su Marte.
Possiamo far sembrare che lo sprite si muova ruotando Marte nella direzione opposta, creando l'effetto di GalaxyRVR che si muove sulla sua superficie.

#. Prima, :ref:`app_connect`.

#. Regola la dimensione e la posizione di entrambi gli sprite.

   * Imposta lo sprite GalaxyRVR a **(0, 0)** e posiziona Marte in modo che GalaxyRVR sembri poggiare sulla sua superficie.

   .. image:: img/6_jump_place.png


**Sprite Marte**

#. Seleziona lo sprite Marte. Il suo compito è ruotare in senso antiorario, creando l'illusione che GalaxyRVR stia avanzando.

   .. image:: img/6_ssp_mars.png

#. Trascina un blocco bandiera verde. Tutta l'animazione inizia con la bandiera verde.

   .. image:: img/6_jump_mar_flag.png

#. Trascina un blocco ``forever`` per mantenere l'animazione in esecuzione continua.

   .. image:: img/6_jump_mar_forever.png


#. Trascina un blocco ``turn`` e un blocco ``wait`` per far ruotare Marte continuamente.

   .. image:: img/6_jump_mar_turn.png

#. Ora clicca la bandiera verde e vedrai Marte ruotare in senso antiorario.



**Sprite GalaxyRVR**

#. Seleziona lo sprite GalaxyRVR. Il suo compito è animarsi come se si muovesse, anche se in realtà non si sta muovendo.

   .. image:: img/6_ssp_rvr.png

#. Trascina un blocco bandiera verde. Tutta l'animazione inizia con la bandiera verde.

   .. image:: img/6_jump_mar_flag.png

#. Trascina un blocco ``forever`` per mantenere l'animazione in esecuzione continua.

   .. image:: img/6_jump_mar_forever.png

#. Trascina un blocco ``next costume`` e un blocco ``wait`` per far animare GalaxyRVR continuamente.

   .. image:: img/6_jump_mar_next.png

#. Trascina un blocco ``when distance``. Questo si attiverà quando il modulo a ultrasuoni rileva un ostacolo (es. la tua mano).

   .. image:: img/6_jump_when.png


#. Trascina due blocchi ``glide`` e cambia il valore y del primo per far saltare lo sprite verso l'alto e poi scendere, creando un effetto di salto.

   .. image:: img/6_jump_glide.png

#. Il codice completo per lo sprite GalaxyRVR dovrebbe apparire così:

   .. image:: img/6_jump_mar_rvr_all.png


Ora, clicca la bandiera verde per avviare l'animazione. Simula un ostacolo mettendo la mano davanti al modulo a ultrasuoni e lo sprite GalaxyRVR salterà per evitarlo.
