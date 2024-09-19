.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme agli altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!



Lezione 4 Ultrasuoni
===========================


Nella nostra ultima avventura, abbiamo dotato il nostro Rover marziano di "occhi" sui lati, creando un sistema di base per evitare gli ostacoli. Tuttavia, c'è un punto cieco proprio di fronte – una sfida che siamo pronti a superare!

Oggi, in questa lezione, daremo al nostro Rover un nuovo senso della "vista". Installeremo un modulo sensore a ultrasuoni che fungerà da occhi centrali, permettendo al nostro Rover di rilevare ostacoli direttamente davanti a sé.

Approfondiremo le affascinanti meccaniche delle onde ultrasoniche e scopriremo come migliorano la capacità del nostro Rover di navigare in terreni complessi. Con questa aggiunta, il nostro Rover marziano sarà più percettivo e agile, pronto per intraprendere missioni esplorative più ambiziose.

Unisciti a noi mentre facciamo un altro passo in avanti in questo entusiasmante viaggio STEAM, rendendo il nostro Rover ancora più abile nell'esplorazione di territori inesplorati!


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/ultrasonic_avoid.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>


Obiettivi di Apprendimento
-------------------------------

* Comprendere il principio di misurazione della distanza con ultrasuoni.
* Imparare a usare l'APP Mammoth Coding e il modulo ultrasonico per la misurazione delle distanze.
* Esercitarsi ad applicare il modulo ultrasonico per evitare ostacoli con il GalaxyRVR.


Materiali
-------------

* Smartphone o tablet
* APP Mammoth Coding
* GalaxyRVR


Esplorare il Modulo Ultrasonico
------------------------------------------

Facciamo conoscenza con l'HC-SR04, un potente sensore a ultrasuoni per misurare distanze. Questo piccolo dispositivo può misurare distanze con precisione da 2 cm fino a 400 cm, senza toccare nulla! Sorprendente, vero? È come avere un superpotere! Può "vedere" le distanze semplicemente usando onde sonore, come fa un pipistrello per orientarsi di notte.

Utilizza quattro superpoteri, o meglio, quattro pin per compiere la sua magia:

.. image:: ../img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG (Trigger Pulse Input)** - È il pulsante d'avvio del nostro supereroe. Dice al nostro eroe: "Ehi, è ora di inviare un'onda ultrasonica!"
* **ECHO (Echo Pulse Output)** - È così che il nostro supereroe ascolta l'eco dell'onda sonora inviata.
* **VCC** - Anche i supereroi hanno bisogno di energia. Lo colleghiamo a una fonte di alimentazione a 5V.
* **GND** - È la connessione a terra. Proprio come i supereroi devono restare collegati alla realtà!

Immagina il nostro supereroe, il sensore a ultrasuoni HC-SR04, che gioca a fare eco tra le montagne.

.. image:: ../img/ultrasonic_prin.jpg
    :width: 800

* Prima di tutto, il cervello del nostro supereroe, l'MCU, dice: "Pronti, partenza, via!" inviando un segnale di livello alto per almeno 10 microsecondi al nostro eroe. È come quando raccogliamo energia prima di urlare in una valle.
* Sentendo "Via!", il nostro supereroe grida 8 volte molto velocemente. Questo grido ultrasonico viene inviato a una velocità di 40 kHz. Il supereroe avvia anche un cronometro e si mette in ascolto di eventuali echi di ritorno.
* Se c'è un ostacolo davanti, il grido lo colpirà e tornerà indietro come eco. Sentendo l'eco, il nostro supereroe ferma il cronometro e annota il tempo. Inoltre, invia un segnale di livello alto per informare l'MCU che ha sentito un'eco.
* Infine, per sapere quanto è lontano l'ostacolo, il nostro supereroe utilizza una formula semplice. Prende il tempo registrato sul cronometro, lo divide per 2 e lo moltiplica per la velocità del suono (340 m/s). Il risultato è la distanza dall'ostacolo!

Ed è così che il nostro sensore-supereroe può capire se c'è un ostacolo nel suo percorso e a quale distanza si trova. Straordinario, vero? Ora vediamo come possiamo usare questo superpotere nel nostro Rover marziano!




Valori di Rilevamento del Modulo a Ultrasuoni
--------------------------------------------------

1. Vediamo quali sono i valori di rilevamento del modulo a ultrasuoni. Per prima cosa, :ref:`app_connect`.

2. Trova il blocco "distanza in cm" nella categoria GalaxyRVR. Seleziona la casella di controllo.

.. image:: img/6_ultrasonic_value.png

3. Questo mostrerà il valore sul palcoscenico.

.. image:: img/6_ultrasonic_value2.png

4. Muovi la mano avanti e indietro davanti al modulo ultrasonico e vedrai la distanza tra la mano e il modulo visualizzata sul palcoscenico. L'unità è cm.



Rispondere al Modulo a Ultrasuoni
--------------------------------------

Possiamo usare il modulo a infrarossi per l'evitamento degli ostacoli e fare in modo che il GalaxyRVR eviti automaticamente gli ostacoli davanti a sé.

1. Trascina un piccolo blocco con la bandiera verde.

.. image:: img/6_ultrasonic_flag.png

2. Imposta la velocità. Qui la impostiamo al 30%, così da non essere troppo veloce, rendendo più facile il debug.

.. image:: img/6_ultrasonic_speed.png

3. Inserisci un blocco "avanti" per mantenerlo in movimento quando non ci sono ostacoli.

.. image:: img/6_ultrasonic_forward.png

4. Trova il blocco ``quando distanza < 15 cm``.

.. image:: img/6_ultrasonic_when.png

5. Quando viene rilevato un ostacolo, il GalaxyRVR si ferma e inizia a muoversi in retromarcia.

.. image:: img/6_ultrasonic_backward.png

6. Effettua una leggera svolta (a sinistra o a destra).

.. image:: img/6_ultrasonic_turn.png

7. Dopo aver completato la svolta, prosegui nuovamente in avanti.

.. image:: img/6_ultrasonic_forward_again.png

Ora, posiziona il GalaxyRVR a terra, e continuerà a muoversi in avanti finché non incontrerà un ostacolo direttamente davanti a sé, punto in cui cambierà direzione.



Blocchi Relativi al Modulo a Ultrasuoni
-------------------------------------------

.. image:: img/block/ultra_when.png

Questo è un blocco evento che si attiva quando il sensore a ultrasuoni rileva un ostacolo più vicino di 15 cm. Puoi:

    * Cambiare ``<`` in ``>`` nel menu a tendina
    * Modificare il numero per regolare la condizione di soglia

.. image:: img/block/ultra_wait_until.png

Questo blocco sospende il programma fino a quando il sensore a ultrasuoni rileva un ostacolo più lontano di 15 cm, quindi prosegue l'esecuzione. Puoi:

    * Cambiare ``<`` in ``>`` nel menu a tendina
    * Modificare il numero per regolare la condizione di soglia

.. image:: img/block/ultra_condition.png

Questo è un blocco condizionale che restituisce VERO se la distanza rilevata dal sensore a ultrasuoni è effettivamente inferiore a 15 cm, altrimenti FALSO. È comunemente utilizzato in blocchi condizionali come ``se``. Puoi:

    * Cambiare ``<`` in ``>`` nel menu a tendina
    * Modificare il numero per regolare la condizione di soglia

.. image:: img/block/ultra_value.png

Questo blocco visualizza la distanza attuale misurata dal sensore a ultrasuoni.



Blocchi Relativi al Servo
-----------------------------

.. image:: img/block/servo_set_angle.png

Questo blocco è utilizzato per impostare l'angolo del servo. L'intervallo è compreso tra 0 e 180 gradi (tuttavia, a causa di limitazioni strutturali, l'intervallo utilizzabile effettivo è 0-135 gradi).

.. image:: img/block/servo_increase_angle.png

Questo blocco aumenta (o diminuisce) l'angolo del servo. Il valore può essere negativo.

.. image:: img/block/servo_value.png

Visualizza l'angolo attuale del servo.

