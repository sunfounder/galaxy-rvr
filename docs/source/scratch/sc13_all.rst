.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anticipo agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!



Lezione 13 Controllo in Tempo Reale
=======================================

Abbiamo esplorato la maggior parte delle funzionalità del GalaxyRVR. 
Per completare il nostro viaggio e trasformare il GalaxyRVR in un robot completamente funzionale, 
dobbiamo combinare le tre parti principali che abbiamo trattato.


    * :ref:`camera_system` : Questa parte include le funzioni di controllo della fotocamera e del LED.

    * :ref:`rgb_move` : Questa sezione riguarda il movimento e gli effetti luminosi.

    * :ref:`tilt_system` : Questa parte include la regolazione della direzione del giunto cardanico della fotocamera.

Metti tutto insieme e puoi cliccare sugli sprite per accendere o spegnere la fotocamera e il LED, e usare le frecce direzionali per muovere il GalaxyRVR.

.. image:: img/13_camera_go_all2.png


**Sistema della Fotocamera**
------------------------------------


Per questa parte, ripeti i passaggi della sezione :ref:`camera_system`.

1. Crea quattro nuovi sprite per controllare la fotocamera e il suo LED. Regola le dimensioni per renderli armoniosi.

.. image:: img/11_camera_4.png
.. :align: center

2. Programma ogni sprite: cliccando su ball 1 spegnerai la fotocamera.

.. image:: img/11_camera_1sp.png
.. :align: center

3. Cliccando su ball 2 accenderai la fotocamera e imposterai l'orientamento dell'immagine.

.. image:: img/11_camera_2sp.png
.. :align: center

4. Cliccando su ball 3 accenderai il LED.

.. image:: img/11_camera_3sp.png
.. :align: center

5. Cliccando su ball 4 spegnerai il LED.

.. image:: img/11_camera_4sp.png
.. :align: center

6. Per risparmiare spazio sul palcoscenico, impila ciascun set di controlli.

.. image:: img/11_camera_fold.png
.. :align: center

7. Aggiungi un blocco ``vai al livello posteriore`` per ogni sprite. Quando viene cliccato, lo sprite si sposterà al livello posteriore, rivelando lo sprite successivo, creando un effetto toggle.

.. image:: img/11_camera_layer.png
.. :align: center




**Sistema di Movimento e RGB**
----------------------------------



Potenzia le funzionalità di movimento. Abbiamo già programmato questi comandi nella sezione :ref:`rgb_move`.

Ti consigliamo di posizionare questi blocchi di codice nei Backdrop. In questo modo, modificare il codice dello sprite non influenzerà questa funzionalità.

.. image:: img/13.ccc_code_in_stage.png

1. Fai accendere la luce verde del GalaxyRVR quando si muove in avanti.

.. image:: img/13.ccc_light_forward.png


2. Fai accendere la luce rossa del GalaxyRVR quando si muove all'indietro.

.. image:: img/13.ccc_light_left_right.png

3. Fai accendere la luce gialla del GalaxyRVR quando gira a sinistra o a destra.

.. image:: img/13.ccc_light_backfwd.png

4. Fai accendere la luce "respirante" quando il GalaxyRVR non si muove.

.. image:: img/13.ccc_light_breath.png

Infine, il tuo codice dovrebbe apparire come segue. 
Nota che questi codici devono essere scritti nei Backdrop.

.. image:: img/11_camera_backdrops.png



**Sistema di Inclinazione**
----------------------------------


Questa parte è uguale a quella della sezione :ref:`tilt_system`. Ripeti semplicemente i passaggi.

1. Aggiungi uno sprite a forma di Freccia. Imposteremo la direzione del giunto cardanico in base all'orientamento della freccia.

.. image:: img/10_servo_arrow.png


2. Un blocco ``quando questo sprite viene cliccato`` è esattamente ciò di cui abbiamo bisogno.

.. image:: img/6_animate_when_touch.png
    :width: 230


3. Fai ripetere il programma finché non rilasciamo lo sprite, ovvero finché non smettiamo di toccarlo.

.. image:: img/6_animate_repeat_touching.png
    :width: 550

4. Trascina un blocco ``punta verso la posizione toccata`` per far sì che lo sprite si orienti verso la posizione toccata.

.. image:: img/10_servo_arrow_point_toward.png

5. Trascina un blocco ``imposta angolo servo a 90 gradi`` e incorpora un blocco ``direzione`` per allineare l'angolo del giunto cardanico all'orientamento dello sprite freccia. In questo modo, quando cambiamo la direzione dello sprite freccia (ovvero tocchiamo l'area del palcoscenico), possiamo modificare l'angolo del giunto cardanico.

.. image:: img/10_servo_arrow_angle_direction.png

6. Aggiungi un controllo di limite per garantire che l'orientamento dello sprite freccia non superi i 135 gradi.

.. image:: img/10_servo_arrow_135.png


7. Allo stesso modo, garantisci che l'orientamento non vada al di sotto di 0 gradi.

.. image:: img/10_servo_arrow_0.png


Tocca lo sprite e cambierà direzione mentre lo trascini, modificando l'angolo del giunto cardanico.

Se trovi difficile mantenere il dito sulla freccia, puoi aumentare la dimensione dello sprite di conseguenza.

