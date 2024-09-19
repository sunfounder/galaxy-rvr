.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme agli altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!




Lezione 9 Partner di Esplorazione su Marte
====================================================

Ora che il nostro Rover è in grado di evitare gli ostacoli, lo potenziamo ulteriormente facendolo seguire gli oggetti. Il nostro obiettivo è modificare il codice esistente in modo che il Rover si muova verso un oggetto in movimento.

Ti sei mai chiesto quali sono le differenze tra un sistema di inseguimento e un sistema di evitamento degli ostacoli?

La differenza chiave è che in un sistema di inseguimento vogliamo che il Rover si muova in risposta agli oggetti rilevati, mentre in un sistema di evitamento, stiamo cercando di allontanarci dagli oggetti rilevati.


Obiettivi di Apprendimento
-----------------------------

* Combinare i moduli di evitamento ostacoli a ultrasuoni e infrarossi per implementare la funzionalità di inseguimento nel modello di Rover marziano.
* Imparare a programmare il modello di Rover marziano per seguire automaticamente un obiettivo.


Materiali
------------

* Smartphone o tablet
* APP Mammoth Coding
* GalaxyRVR


Programmare il Sistema di Inseguimento Intelligente
-------------------------------------------------------

1. Utilizza il blocco di codice della lezione :ref:`ir_ultra_avoid` come modello e aprilo dal progetto salvato.

.. image:: img/8_follow_open.png

2. Poi, salvalo come una copia.

.. image:: img/8_follow_save_copy.png

3. Rinomina il progetto e salvalo.

.. image:: img/8_follow_save_rename.png

4. Per prima cosa, rimuovi il blocco avanti alla fine di ciascun blocco di codice, poiché il Rover dovrebbe fermarsi dopo ogni evento sensoriale.

.. image:: img/8_follow_save_remove_forward.png

5. Successivamente, modifica le direzioni di svolta dei due eventi IR, poiché il GalaxyRVR deve seguire la direzione dell'obiettivo.

.. image:: img/8_follow_save_re_turn.png

6. Infine, modifica gli eventi del sensore a ultrasuoni. Invece di arretrare a una distanza di sicurezza e girare, ora dovrebbe avanzare finché l'obiettivo non esce dal raggio d'azione.

.. image:: img/8_follow_save_re_ultra.png

Ora, il GalaxyRVR seguirà i tuoi passi. Quando sei accanto a lui, si girerà per fronteggiarti. Se sei davanti, si muoverà verso di te. Se non riesce a rilevarti, rimarrà fermo.

