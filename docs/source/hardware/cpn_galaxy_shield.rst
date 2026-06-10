.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

GalaxyRVR Shield
=========================

.. image:: img/galaxy_shield.jpg
    :width: 500
    :align: center

Questa è una scheda di espansione tutto-in-uno progettata per Arduino da SunFounder, che contiene varie porte per moduli
come motore, striscia RGB, evitamento ostacoli, scala di grigi, ESP32 CAM e modulo a ultrasuoni.

Questa scheda di espansione ha anche un circuito di ricarica integrato, che può caricare la batteria con interfaccia PH2.0-3P,
e il tempo di ricarica stimato è di 130 minuti.


**Pinout**

.. image:: img/galaxyrvr_shield_pinout.png

* Porta di ricarica
    * Dopo aver collegato la porta USB-C 5V/2A, può essere utilizzata per caricare la batteria per 130 minuti.

* **Porta batteria**:
    * Ingresso alimentazione 6,6V~8,4V PH2.0-3P.
    * Alimenta contemporaneamente il GalaxyRVR Shield e la scheda Arduino.

* Pulsante Reset
    * Premi questo pulsante per ripristinare il programma sulla scheda Arduino.

* Indicatori
    * **Indicatore di carica**: Si illumina di rosso quando lo shield è in carica tramite la porta USB-C.
    * **Indicatore di alimentazione**: Si illumina di verde quando l'interruttore di alimentazione è in posizione "ON".
    * **Indicatore batteria**: Due indicatori arancioni rappresentano diversi livelli della batteria. Lampeggiano durante la carica e si spengono quando la batteria necessita di ricarica.

* Interruttore di alimentazione
    * Scorri su ON per accendere il GalaxyRVR.

* Camera Servo
    * Il servo sulla fotocamera è collegato qui.
    * Il cavo marrone si collega a "-", il cavo rosso si collega a "+" e il cavo giallo si collega al Pin 6.

* :ref:`shield_motor_pin`
    * **Porta motore (Destra)**: È possibile collegare 3 motori, ma tutti e 3 i motori sono controllati dallo stesso set di segnali **pin 2 e 3**.
    * **Porta motore (Sinistra)**: È possibile collegare 3 motori, ma tutti e 3 i motori sono controllati dallo stesso set di segnali **pin 4 e 5**.
    * Tipo porta: XH2.54, 2P.

* :ref:`shield_strip_pin`
    * Per collegare 2 strisce LED RGB, i tre pin della striscia sono collegati rispettivamente a **12, 13 e 11**.
    * Tipo porta: ZH1.5, 4P.

* :ref:`shield_avoid_pin`
    * Utilizzato per collegare due moduli evitamento ostacoli IR.
    * Il **modulo evitamento ostacoli sinistro** è collegato al **pin 8**, il **modulo evitamento ostacoli destro** è collegato al **pin 7**.
    * Tipo porta: ZH1.5, 3P.

* :ref:`shield_camera_pin`
    * La porta della scheda adattatore per fotocamera.
    * Tipo porta: ZH1.5, 5P.

* :ref:`shield_ultrasonic_pin`
    * Per collegare il modulo a ultrasuoni, entrambi i pin Trig ed Echo sono collegati al **pin 10** della scheda Arduino.
    * Tipo porta: ZH1.5, 4P.

* Interruttore di modalità
    * L'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione).
    * Quindi, quando carichi il codice, dovrai spostare questo interruttore sul **lato destro** per scollegare l'ESP32-CAM ed evitare conflitti o potenziali problemi.
    * Quando devi utilizzare la fotocamera, sposta questo interruttore sul **lato sinistro** in modo che l'ESP32-CAM possa comunicare con la scheda Arduino.

* SOLAR
    * Questa è la porta per il pannello solare, che può caricare la batteria quando è collegato al pannello solare.
    * Tipo porta: XH2.54, 2P.


.. _shield_ultrasonic_pin:

SONAR
--------------------

Questo è il pinout per la porta a ultrasuoni ZH1.5-4P, con i pin Trig ed Echo collegati al pin 10 della scheda Arduino.

.. image:: img/ultrasonic_shield.png

.. _shield_camera_pin:

CAMERA
----------------------

Il diagramma dei pin dell'interfaccia dell'adattatore per fotocamera è mostrato qui, il tipo è ZH1.5-7P.

* TX e RX sono utilizzati per ESP32 CAM.

.. image:: img/camera_shield.png


.. _shield_avoid_pin:

IR SINISTRO/DESTRO
----------------------------

Questi sono i pin per i moduli evitamento ostacoli sinistro e destro.

.. image:: img/ir_shield.png


.. _shield_strip_pin:

Striscia RGB
-------------------------

Di seguito è riportato il diagramma dei pinout delle due strisce LED RGB, sono collegate in parallelo e i pinout sono gli stessi.

.. image:: img/rgb_shield.png



.. _shield_motor_pin:

Porta motore
---------------

Ecco il pinout dei 2 set di porte motore.


.. image:: img/motor_shield.png
    :width: 600
    :align: center

