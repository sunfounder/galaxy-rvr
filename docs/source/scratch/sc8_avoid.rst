.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _ir_ultra_avoid:

Lezione 8: Evitamento ostacoli avanzato
==================================================

Ti sei mai chiesto come fanno i robot a navigare nelle stanze senza urtare i mobili? Oggi insegneremo al nostro Mars Rover a fare proprio questo! Combineremo due diversi tipi di sensori per creare un sistema di evitamento ostacoli super-intelligente.

Come i sensori aiutano i robot a "vedere"
------------------------------------------------

Pensiamo a come usiamo i nostri sensi:

* **Sensori a infrarossi** funzionano come i pipistrelli che usano l'ecolocalizzazione! Inviano luce infrarossa invisibile e ascoltano il suo rimbalzo dagli oggetti. Se la luce ritorna rapidamente, c'è un ostacolo nelle vicinanze.

* **Sensori a ultrasuoni** funzionano con onde sonore che non possiamo sentire. Inviano suoni ad alta frequenza e misurano quanto tempo impiega l'eco a tornare. Più tempo significa che l'oggetto è più lontano.

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

Quando usiamo entrambi i sensori insieme, il nostro Rover ottiene una comprensione molto migliore dell'ambiente circostante, proprio come usare sia gli occhi che le orecchie per navigare in una stanza buia!

Obiettivi di apprendimento
----------------------------

* Combinare sensori a ultrasuoni e infrarossi per creare un sistema avanzato di evitamento ostacoli
* Programmare il tuo Mars Rover per percepire e navigare automaticamente intorno agli ostacoli

Costruire il nostro Rover super-intelligente
-----------------------------------------------------------

Ricordi il programma di evitamento ostacoli che abbiamo creato prima? Lo useremo come punto di partenza e lo renderemo ancora migliore!

#. Prima, :ref:`app_connect`.

#. Ora, apriamo il nostro precedente progetto con sensori a infrarossi da :ref:`ir_obstacle` come modello. Clicca su "File" e trova il tuo progetto salvato di evitamento ostacoli IR.

   .. image:: img/7_avoid_open.png

#. Prima di fare modifiche, salviamo una copia per non perdere il nostro lavoro originale. Clicca "Save as a copy".

   .. image:: img/7_avoid_save_copy.png

#. Dai al tuo nuovo progetto un nome interessante come "Super Smart Rover" o "Advanced Obstacle Avoidance".

   .. image:: img/7_avoid_save_rename.png

#. Ora aggiungiamo il nostro sensore a ultrasuoni! Trascina il blocco ``when distance < 15 cm``. Questo sarà il nostro "sistema di allarme precoce" che rileva gli ostacoli da più lontano.

   .. image:: img/7_avoid_when.png
       :width: 800

#. Per evitare confusione, aggiungeremo un blocco ``stop other scripts in sprite``. Questo assicura che il nostro Rover segua solo un set di istruzioni alla volta.

   .. image:: img/7_avoid_stop.png

#. Quando il sensore a ultrasuoni rileva qualcosa di vicino, vogliamo che il nostro Rover indietreggi fino a una distanza di sicurezza.

   .. image:: img/7_avoid_backward.png

#. Ora dobbiamo girare lontano dall'ostacolo. Il Rover girerà per un secondo: puoi scegliere se girare a sinistra o a destra!

   .. image:: img/7_avoid_turn.png

#. Infine, diciamo al Rover di continuare ad avanzare sul suo nuovo percorso.

   .. image:: img/7_avoid_go.png

Fantastico! Ora hai un Rover che usa tre sensori che lavorano insieme come una squadra:

- Il sensore a ultrasuoni frontale individua gli ostacoli distanti
- Il sensore IR sinistro rileva gli oggetti sul lato sinistro
- Il sensore IR destro sorveglia il lato destro

Testa il tuo programma e guarda come il tuo Rover naviga agevolmente intorno agli ostacoli. Prova a creare un percorso a ostacoli e vedi se il tuo Rover può completarlo senza incidenti!

Sfida: Puoi modificare il tempo di rotazione o la distanza per rendere il tuo Rover ancora migliore nell'evitare gli ostacoli?