.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _ir_obstacle:

Lezione 6: Ostacoli IR
===========================

Ecco gli "occhi" laterali del tuo rover: i sensori a infrarossi per l'evitamento degli ostacoli!

Questi ingegnosi sensori aiutano il tuo GalaxyRVR a rilevare e schivare gli ostacoli sui lati, proprio come avere una visione periferica. Impara come funzionano e programma il tuo rover per navigare automaticamente intorno agli oggetti.

Preparati a rendere il tuo Mars Rover un intelligente evitatore di ostacoli!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_ir1.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Obiettivi di apprendimento
--------------------------

* Comprendere i principi di funzionamento del modulo evitamento ostacoli a infrarossi e la sua applicazione nel Mars Rover.
* Imparare a leggere e applicare i dati dal modulo evitamento ostacoli a infrarossi in Scratch.
* Creare un gioco di evitamento ostacoli a tema esplorazione marziana utilizzando il modulo IR e lo stage di Scratch.

Conoscere il modulo evitamento ostacoli
---------------------------------------

Saluta il nuovo compagno del tuo GalaxyRVR: il modulo evitamento ostacoli a infrarossi! Questo ingegnoso dispositivo aiuta il tuo rover a rilevare ed evitare gli ostacoli. Vediamo come funziona:

.. image:: img/ir_avoid.png
    :width: 300
    :align: center

**I quattro pin importanti:**

* **GND** - La connessione a terra (completa il circuito)
* **+** - Ingresso alimentazione (necessita da 3,3V a 5V)
* **Out** - Uscita segnale (invia messaggi "ostacolo rilevato")
* **EN** - Pin di abilitazione (controlla quando il modulo è attivo)

**Come funziona - La torcia invisibile:**

Pensa a questo modulo come ad avere una torcia invisibile e occhiali speciali:

.. image:: img/ir_receive.png
    :align: center

1. Il trasmettitore invia luce infrarossa (invisibile ai nostri occhi)
2. Quando la luce colpisce un ostacolo, rimbalza indietro
3. Il ricevitore "vede" la luce riflessa
4. Il modulo invia un segnale: "Ostacolo davanti!"

**Curiosità sul tuo sensore:**

* **Portata di rilevamento**: 2-40 cm (circa la lunghezza del tuo astuccio!)
* **Il colore conta**: Funziona meglio con oggetti di colore chiaro
* **Oggetti scuri**: Più difficili da rilevare da lontano

**Controlli avanzati (Per menti curiose):**

* **Pin EN**: Il cappuccio jumper mantiene il modulo sempre attivo. Rimuovilo se vuoi controllare il modulo con il codice.


  .. image:: img/ir_cap.png
      :width: 400
      :align: center

* **Due regolazioni**:

  - Una manopola controlla quanto lontano viaggia la luce infrarossa
  - Una manopola regola la frequenza della luce

  .. image:: img/ir_avoid_pot.png
      :width: 400
      :align: center

Ora che hai conosciuto il tuo nuovo compagno, colleghiamolo al tuo rover e iniziamo a programmare!

Testare i tuoi sensori a infrarossi
------------------------------------------------------------

#. Prima, :ref:`app_connect`.

2. Calibriamo i tuoi sensori per prestazioni perfette!

   a. Assicurati che i componenti a infrarossi siano dritti. Regola delicatamente se necessario.

      .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
            </video>

   b. Posiziona un oggetto (come la scatola del tuo rover) a 20 cm di distanza. Gira la manopola finché la spia indicatrice si accende. Testa muovendo l'oggetto più vicino e più lontano.

      .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
            </video>

   c. Fai lo stesso per l'altro modulo a infrarossi.

3. Poi, :ref:`app_connect`.

4. Trova i blocchi "left IR status" e "right IR status" nella categoria GalaxyRVR e seleziona le loro caselle.

   .. image:: img/4_ir_statusblock.png

5. I valori del sensore appariranno ora sul tuo stage.

   .. image:: img/4_ir_statusvalue.png

6. Agita la mano vicino a ciascun sensore a infrarossi e guarda i valori cambiare!

**Cosa significano i valori:**

- **True** = Ostacolo rilevato
- **False** = Percorso libero

Ora sei pronto per vedere cosa può "vedere" il tuo rover!


Programmare il tuo rover per evitare ostacoli
-------------------------------------------------------------

Insegniamo al tuo GalaxyRVR a schivare automaticamente gli ostacoli usando i suoi sensori a infrarossi!

#. Prima, :ref:`app_connect`.

#. Avvia il programma con un blocco bandiera verde.

   .. image:: img/4_ir_start.png

#. Imposta una velocità sicura del 30% per test e debug facili.

   .. image:: img/4_ir_speed.png

#. Trova il blocco ``when left IR is blocked`` per il rilevamento del sensore sinistro.

   .. image:: img/4_ir_when_blocked.png

#. Quando il sensore sinistro rileva un ostacolo, fai girare il rover a destra.

   .. image:: img/4_ir_turn_right.png

#. Continua a girare a destra finché il lato sinistro non rileva più l'ostacolo.

   .. image:: img/4_ir_wait_until.png

#. Ferma il movimento una volta che il percorso è libero.

   .. image:: img/4_ir_stop.png

#. Testa attivando il sensore a infrarossi sinistro con la mano. Il GalaxyRVR dovrebbe girare intelligentemente a destra per evitarlo.

#. Duplica il codice tenendo premuti i blocchi e selezionando duplicate dal menu.

   .. image:: img/4_ir_duplicate.png

#. Nel codice duplicato, scambia i lati sinistro e destro in modo che gestisca gli ostacoli sul lato destro.

   .. image:: img/4_ir_left_right.png

#. Per prevenire comportamenti irregolari quando entrambi i sensori sono attivati contemporaneamente, aggiungi un blocco "stop other scripts in sprite". Questo assicura che venga gestito solo un evento del sensore alla volta.

   .. image:: img/4_ir_stop_script.png
       :width: 800

   .. note:: I blocchi stop scripts possono entrare in conflitto con i blocchi di movimento temporizzato, quindi evita di usarli insieme quando possibile.

#. Ora il tuo GalaxyRVR girerà a sinistra o a destra quando vengono rilevati ostacoli su entrambi i lati. Testa attivando entrambi i sensori con le mani.

#. Aggiungi un blocco forward sotto ogni sezione di codice in modo che il rover continui a muoversi dopo aver evitato gli ostacoli.

   .. image:: img/4_ir_avoid_move.png
       :width: 800

Ora clicca la bandiera verde! Il tuo GalaxyRVR avanzerà continuamente, schivando intelligentemente gli ostacoli e riprendendo il suo percorso dopo averli evitati.

Blocchi relativi al modulo IR
----------------------------------------

* Blocco evento attivato quando il sensore IR sinistro rileva un ostacolo

  - Cambia "left" in "right" nel menu a discesa

  .. image:: img/block/ir_when.png

* Mette in pausa il programma finché il sensore IR sinistro non rileva più un ostacolo

  - Cambia "left" in "right" per l'altro sensore
  - Cambia "is not" in "is" per la condizione opposta

  .. image:: img/block/ir_wait_until.png

* Blocco condizionale che restituisce TRUE se il sensore IR sinistro rileva un ostacolo

  - Perfetto per l'uso con le istruzioni ``if``
  - Cambia "left" in "right" per l'altro sensore

  .. image:: img/block/ir_condition.png

* Mostra lo stato attuale di rilevamento del sensore IR sinistro

  .. image:: img/block/ir_left_value.png

* Mostra lo stato attuale di rilevamento del sensore IR destro

  .. image:: img/block/ir_right_value.png