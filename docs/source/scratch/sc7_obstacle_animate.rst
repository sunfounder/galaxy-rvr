.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lezione 7: Creare un'animazione con ostacoli IR
=====================================================

Nelle nostre missioni precedenti, abbiamo usato il modulo evitamento ostacoli a infrarossi per aiutare il nostro GalaxyRVR a evitare automaticamente gli ostacoli, proprio come un vero rover marziano che naviga sul Pianeta Rosso!

Ora, portiamo questo al livello successivo combinando i sensori IR fisici con un paesaggio marziano virtuale. Creeremo un emozionante gioco di animazione in cui controlli uno sprite rover attivando i veri sensori IR con le mani!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_rock.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Obiettivi di apprendimento
--------------------------

* Scoprire come il modulo evitamento ostacoli a infrarossi dà vita al tuo Mars Rover
* Imparare a usare i dati del sensore IR per controllare i personaggi nelle tue animazioni Scratch
* Costruire il tuo gioco di esplorazione marziana in cui schivi rocce usando sensori reali

Creare la scena dell'animazione
-------------------------------

#. Prima, :ref:`app_connect`.

#. Impostazione dello sfondo a tema marziano

   * Per prima cosa, abbiamo bisogno di uno sfondo a tema marziano. Clicca per selezionare uno sfondo.

     .. image:: img/5_animate_choose.png

   * Scegli lo sfondo **Mars**.

     .. image:: img/5_animate_mars.png

#. Aggiunta del personaggio rover

   Scegli lo sprite **GalaxyRVR** dalla libreria e ridimensionalo per adattarlo appropriatamente alla tua scena.

   .. image:: img/5_animate_rvr.png

#. Aggiunta degli ostacoli

   Seleziona uno sprite **Rocks** dalla libreria e regola le sue dimensioni.

   .. image:: img/5_animate_rock.png


Programmare lo sprite GalaxyRVR
------------------------------------------

Programma il tuo sprite GalaxyRVR per attraversare lo schermo da sinistra a destra. La tua missione: guidarlo in sicurezza oltre le rocce!
Usa le mani per attivare i sensori IR del rover fisico: il sensore destro sposta lo sprite verso il basso, il sensore sinistro lo sposta verso l'alto.

#. Imposta la posizione iniziale spostando lo sprite sul bordo sinistro dello stage. I blocchi di movimento si aggiorneranno automaticamente con le coordinate corrette.

   .. image:: img/5_animate_glide.png

#. Aggiungi un blocco forever per creare il ciclo principale del programma che viene eseguito continuamente.

   .. image:: img/5_animate_forever.png

#. Includi un blocco condizionale per verificare se il rover sta toccando un ostacolo roccia.

   .. image:: img/5_animate_touching.png

#. Se non viene rilevata alcuna roccia, continua a muoverti in avanti verso il lato destro.

   .. image:: img/5_animate_moving.png

#. Se il rover colpisce una roccia, ferma tutto il movimento e mostra un messaggio di avviso.

   .. image:: img/5_animate_say.png

#. Aggiungi controlli sensore: crea eventi per entrambi i sensori IR che spostano lo sprite verso l'alto (sensore sinistro) o verso il basso (sensore destro) quando attivati dalla tua mano.

   .. image:: img/5_animate_y.png

Programmare lo sprite roccia
------------------------------------

Creiamo più ostacoli roccia per rendere il gioco più impegnativo! Useremo la clonazione per generare rocce in posizioni casuali sullo stage.

#. Crea cloni di roccia usando il blocco "create clone of myself".

   .. image:: img/5_animate_clone.png

#. Fai apparire ogni clone in una posizione casuale aggiungendo il blocco "go to random position".

   .. image:: img/5_animate_clone_move.png
      :width: 200

#. Genera dieci rocce ripetendo la creazione del clone dieci volte.

   .. image:: img/5_animate_clone_10.png
      :width: 200

#. Imposta tutta questa azione per iniziare quando si clicca la bandiera verde.

   .. image:: img/5_animate_clone_flag.png
      :width: 200

Lancio della missione!
----------------------------

Congratulazioni! Il tuo gioco di evitamento ostacoli marziano è pronto per il lancio.

Connetti il tuo GalaxyRVR all'APP e clicca la bandiera verde per iniziare la tua missione. Guarda come le rocce appaiono casualmente sul paesaggio marziano.

La tua sfida: Usa le mani per attivare i sensori IR e guida attentamente lo sprite GalaxyRVR attraverso lo schermo. Muovilo su e giù per evitare le rocce e raggiungere il lato destro in sicurezza!

Riesci a completare la missione senza collisioni? Quanto velocemente puoi navigare il percorso a ostacoli? Continua a esercitarti per diventare un pilota esperto di rover marziani!