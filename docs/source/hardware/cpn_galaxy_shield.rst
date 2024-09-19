.. note::

    Ciao, benvenuto nella comunità di appassionati SunFounder di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e concorsi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

GalaxyRVR Shield
=========================

.. image:: img/galaxy_shield.jpg
    :width: 500
    :align: center

Questa è una scheda di espansione all-in-one progettata da SunFounder per 
Arduino, che contiene vari moduli come porte per motore, striscia RGB, 
evitamento ostacoli, scala di grigi, ESP32 CAM e modulo a ultrasuoni.

Questa scheda di espansione ha anche un circuito di ricarica integrato, che può 
caricare la batteria tramite l'interfaccia PH2.0-3P. Il tempo di ricarica stimato è di 130 minuti.

**Pinout**

.. image:: img/galaxyrvr_shield_pinout.png

* Porta di ricarica
    * Dopo aver collegato alla porta USB-C 5V/2A, può essere utilizzata per caricare la batteria in 130 minuti.

* **Porta batteria**:
    * Ingresso alimentazione 6.6V~8.4V PH2.0-3P.
    * Alimenta contemporaneamente lo Shield GalaxyRVR e la scheda Arduino.

* Pulsante di reset
    * Premi questo pulsante per resettare il programma sulla scheda Arduino.

* Indicatori
    * **Indicatore di ricarica**: Si illumina di rosso quando lo shield è in carica tramite la porta USB-C.
    * **Indicatore di alimentazione**: Si illumina di verde quando l'interruttore è nella posizione "ON".
    * **Indicatore di batteria**: Due indicatori arancioni rappresentano diversi livelli della batteria. Lampeggiano durante la carica e si spengono quando la batteria necessita di essere caricata.

* Interruttore di alimentazione
    * Sposta su ON per accendere il GalaxyRVR.

* Servo della fotocamera
    * Il servo della fotocamera è collegato qui.
    * Il filo marrone si collega a "-", il filo rosso a "+", e il filo giallo al Pin 6.

* :ref:`shield_motor_pin`
    * **Porta motore (destra)**: Possono essere collegati 3 motori, ma tutti e tre i motori sono controllati dallo stesso set di segnali, **pin 2 e 3**.
    * **Porta motore (sinistra)**: Possono essere collegati 3 motori, ma tutti e tre i motori sono controllati dallo stesso set di segnali, **pin 4 e 5**.
    * Tipo di porta: XH2.54, 2P.

* :ref:`shield_strip_pin`
    * Per collegare 2 strisce LED RGB, i tre pin della striscia sono collegati rispettivamente ai pin **12, 13 e 11**.
    * Tipo di porta: ZH1.5, 4P.

* :ref:`shield_avoid_pin`
    * Usato per collegare due moduli a infrarossi per l'evitamento degli ostacoli.
    * Il **modulo sinistro** è collegato al **pin 8**, mentre il **modulo destro** è collegato al **pin 7**.
    * Tipo di porta: ZH1.5, 3P.

* :ref:`shield_camera_pin`
    * Porta per la scheda adattatrice della fotocamera.
    * Tipo di porta: ZH1.5, 5P.

* :ref:`shield_ultrasonic_pin`
    * Per collegare il modulo a ultrasuoni, i pin Trig ed Echo sono collegati al **pin 10** della scheda Arduino.
    * Tipo di porta: ZH1.5, 4P.

* Interruttore di modalità
    * L'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione).
    * Quindi, quando carichi il codice, dovrai spostare questo interruttore sul **lato destro** per disconnettere l'ESP32-CAM ed evitare conflitti o problemi.
    * Quando hai bisogno di usare la fotocamera, sposta l'interruttore sul **lato sinistro** in modo che l'ESP32-CAM possa comunicare con la scheda Arduino.

* SOLARE
    * Questa è la porta per il pannello solare, che può caricare la batteria quando è collegato al pannello solare.
    * Tipo di porta: XH2.54, 2P.


.. _shield_ultrasonic_pin:

SONAR
--------------------

Questo è il pinout per la porta a ultrasuoni ZH1.5-4P, con i pin Trig ed Echo collegati al pin 10 della scheda Arduino.

.. image:: img/ultrasonic_shield.png

.. _shield_camera_pin:

FOTOCAMERA
----------------------

Di seguito è mostrato il diagramma dei pin dell'interfaccia dell'adattatore della fotocamera, tipo ZH1.5-7P.

* TX e RX sono utilizzati per l'ESP32 CAM.

.. image:: img/camera_shield.png


.. _shield_avoid_pin:

IR SINISTRO/DESTRO 
----------------------------

Questi sono i pin per i moduli di evitamento ostacoli sinistro e destro.

.. image:: img/ir_shield.png


.. _shield_strip_pin:

Striscia RGB
-------------------------

Di seguito è riportato il diagramma del pinout delle due strisce LED RGB, collegate in parallelo con lo stesso pinout.

.. image:: img/rgb_shield.png



.. _shield_motor_pin:

Porta Motore
---------------

Ecco il pinout dei 2 set di porte per motore.

.. image:: img/motor_shield.png
    :width: 600
    :align: center
