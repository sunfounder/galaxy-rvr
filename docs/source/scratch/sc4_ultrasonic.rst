.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

Lezione 4: Modulo a ultrasuoni
==============================

Dai al tuo GalaxyRVR il potere di "vedere" con il suono!

Scopri come i sensori a ultrasuoni funzionano come l'ecolocalizzazione di un pipistrello, inviando onde sonore e ascoltando gli echi per rilevare ostacoli e misurare distanze.

Rendi il tuo Mars Rover più intelligente e sicuro mentre esplora!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/ultrasonic_avoid.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Obiettivi di apprendimento
--------------------------

* Scoprire come i sensori a ultrasuoni usano le onde sonore per misurare la distanza
* Imparare a leggere le misurazioni di distanza usando l'app Mammoth Coding
* Programmare il GalaxyRVR per evitare ostacoli usando il sensore a ultrasuoni

Esplorare il modulo a ultrasuoni
--------------------------------------------

Ecco il sensore a ultrasuoni HC-SR04, il nuovo "superpotere" del tuo rover per vedere le distanze senza toccare nulla! Proprio come i pipistrelli usano il suono per navigare, questo ingegnoso dispositivo può rilevare oggetti da 2 cm a 400 cm di distanza.

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

**I quattro pin importanti:**

* **TRIG** - Il "pulsante di avvio" che dice al sensore di inviare onde sonore
* **ECHO** - Ascolta l'eco di ritorno dagli oggetti
* **VCC** - Connessione di alimentazione (necessita di 5V)
* **GND** - Connessione a terra (completa il circuito)

**Come funziona - Il gioco dell'eco:**

.. image:: img/ultrasonic_prin.jpg
    :width: 800

1. **AVVIO** - Il sensore invia 8 rapide onde sonore (troppo acute per essere udite!)
2. **ASCOLTO** - Inizia a cronometrare e attende che l'eco rimbalzi
3. **CALCOLO** - Usando il tempo dell'eco, calcola: Distanza = (Tempo × Velocità del suono) ÷ 2

Pensalo come gridare in un canyon e contare quanto tempo ci vuole per sentire l'eco. Più lunga è l'attesa, più lontana è la parete!

Ora diamo al tuo Mars Rover questo incredibile superpotere!

Testare il sensore a ultrasuoni
----------------------------------------------------------

#. Prima, :ref:`app_connect`.

2. Trova il blocco "distance in cm" nella categoria GalaxyRVR e seleziona la sua casella.

   .. image:: img/6_ultrasonic_value.png

3. La lettura del sensore apparirà ora in diretta sullo stage.

   .. image:: img/6_ultrasonic_value2.png

4. Agita la mano davanti al sensore a ultrasuoni e guarda il numero cambiare: sta misurando la distanza in centimetri!

Creare un rover che evita gli ostacoli
--------------------------------------------------------------------

Programmiamo il tuo GalaxyRVR per evitare automaticamente gli ostacoli usando il sensore a ultrasuoni.

1. Inizia con il blocco bandiera verde.

   .. image:: img/6_ultrasonic_flag.png

2. Imposta una velocità confortevole (consigliamo il 30%) per i test.

   .. image:: img/6_ultrasonic_speed.png

3. Aggiungi un blocco "move forward" così il rover continua a muoversi quando il percorso è libero.

   .. image:: img/6_ultrasonic_forward.png

4. Usa il blocco ``when distance < 15 cm`` per rilevare ostacoli vicini.

   .. image:: img/6_ultrasonic_when.png

5. Quando qualcosa si avvicina troppo, fai fermare il rover e indietreggiare.

   .. image:: img/6_ultrasonic_backward.png

6. Poi fallo girare leggermente (a sinistra o a destra - a tua scelta!).

   .. image:: img/6_ultrasonic_turn.png

7. Infine, digli di andare di nuovo avanti sul suo nuovo percorso.

   .. image:: img/6_ultrasonic_forward_again.png

Ora metti il tuo GalaxyRVR sul pavimento e guardalo andare! Avanzera' fino a quando rileva un ostacolo, poi cambiera' intelligentemente direzione e continuera' a esplorare.

Blocchi del sensore a ultrasuoni
-------------------------------------------------

* **Blocco di attivazione evento**

  Avvia il codice quando un oggetto viene rilevato entro una distanza impostata.

  - Cambia il simbolo di confronto (< o >)
  - Regola la soglia di distanza (in cm)

  .. image:: img/block/ultra_when.png

* **Blocco attendi fino a**

  Mette in pausa il programma fino a quando il sensore rileva un oggetto alla distanza specificata.

  - Scegli < o > per il confronto della distanza
  - Imposta il valore di distanza desiderato

  .. image:: img/block/ultra_wait_until.png

* **Blocco di controllo condizione**

  Restituisce VERO o FALSO in base al rilevamento della distanza. Perfetto per l'uso con le istruzioni ``if``.

  - Passa tra < e > secondo necessità
  - Imposta il limite di distanza

  .. image:: img/block/ultra_condition.png

* **Blocco valore distanza**

  Mostra la lettura corrente della distanza dal sensore a ultrasuoni in centimetri.

  .. image:: img/block/ultra_value.png

