.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lezione 13: Controllo completo del Mars Rover
=============================================

Hai padroneggiato tutti i pezzi - ora mettiamoli insieme! Combina tutto ciò che hai imparato per creare il tuo Mars Rover completamente funzionante con vista in diretta, controlli di movimento e inclinazione della fotocamera.

Unisci tre fantastici sistemi:

- :ref:`camera_system`: Vedi attraverso gli occhi del tuo rover con video in diretta
- :ref:`rgb_move`: Guida con luci di segnalazione colorate
- :ref:`tilt_system`: Guarda su e giù con i controlli della fotocamera

Il risultato? Controllo completo del tuo GalaxyRVR! Clicca i pulsanti per i controlli della fotocamera e usa i tasti freccia per guidare.

.. image:: img/13_camera_go_all2.png


Sistema fotocamera
----------------------------------

Ripeti la configurazione della fotocamera dalla lezione precedente: :ref:`camera_system`.

1. Crea quattro sprite di controllo e disponili ordinatamente.

   .. image:: img/11_camera_4.png

2. Programma la funzione di ogni pulsante:

   - Palla 1: Fotocamera OFF

   .. image:: img/11_camera_1sp.png

   - Palla 2: Fotocamera ON con orientamento corretto

   .. image:: img/11_camera_2sp.png

   - Palloncino 1: Luce LED ON

   .. image:: img/11_camera_3sp.png

   - Palloncino 2: Luce LED OFF

   .. image:: img/11_camera_4sp.png

3. Impila i controlli per risparmiare spazio - si apriranno quando necessario!

   .. image:: img/11_camera_fold.png

4. Aggiungi ``go to back layer`` per creare un fantastico effetto a levetta tra i pulsanti.

   .. image:: img/11_camera_layer.png

Sistema di movimento e illuminazione
------------------------------------

Aggiungiamo luci colorate ai movimenti del tuo rover! Abbiamo già codificato queste nella sezione :ref:`rgb_move`.

Consigliamo di posizionare questo codice nella sezione Backdrops - questo lo mantiene separato dal codice degli sprite e rende tutto più organizzato.

   .. image:: img/13.ccc_code_in_stage.png

1. Fai brillare il tuo rover di VERDE quando avanza.

   .. image:: img/13.ccc_light_forward.png

2. Fai brillare il tuo rover di ROSSO quando indietreggia.

   .. image:: img/13.ccc_light_backfwd.png

3. Fai brillare il tuo rover di GIALLO quando gira a sinistra o a destra.

   .. image:: img/13.ccc_light_left_right.png

4. Crea un effetto di luce blu respirante quando il tuo rover è fermo.

   .. image:: img/13.ccc_light_breath.png

Il tuo codice backdrop completo dovrebbe apparire così:

   .. image:: img/11_camera_backdrops.png

Controllo inclinazione fotocamera
---------------------------------

Aggiungiamo i controlli della fotocamera! Questa parte è la stessa del :ref:`tilt_system`. Ripeti semplicemente i passaggi.


1. Aggiungi uno sprite **Arrow** per controllare l'inclinazione della tua fotocamera.

   .. image:: img/10_servo_arrow.png

2. Inizia con un blocco ``when this sprite clicked``.

   .. image:: img/6_animate_when_touch.png
       :width: 200

3. Crea un ciclo che viene eseguito mentre tocchi la freccia.

   .. image:: img/6_animate_repeat_touching.png
       :width: 400

4. Fai puntare la freccia verso il tuo dito mentre trascini.

   .. image:: img/10_servo_arrow_point_toward.png
       :width: 400

5. Collega la direzione della freccia all'angolo della fotocamera - ruota la freccia per muovere la fotocamera!

   .. image:: img/10_servo_arrow_angle_direction.png
       :width: 800

6. Imposta limiti per mantenere la fotocamera tra 0-135 gradi.

   .. image:: img/10_servo_arrow_135.png
       :width: 400

   .. image:: img/10_servo_arrow_0.png
       :width: 400

Tocca e trascina la freccia per puntare la fotocamera del tuo rover! Rendi la freccia più grande se è difficile da controllare.

Controllo completo del tuo GalaxyRVR
------------------------------------

Ora hai il controllo completo del tuo Mars Rover! Ecco come utilizzare il tuo GalaxyRVR completo:

.. image:: img/13_camera_go_all2.png

**Controlla il tuo Rover:**

- Usa i tasti freccia per guidare avanti, indietro e girare
- Clicca gli sprite Palla per accendere e spegnere il video in diretta della fotocamera
- Clicca gli sprite Palloncino per controllare l'accensione e lo spegnimento della luce LED della fotocamera
- Trascina lo sprite freccia per inclinare la fotocamera su e giù

**Testa tutte le funzionalità insieme:**

- Guida guardando il feed in diretta dalla fotocamera del tuo rover
- Nota le luci colorate che segnalano ogni movimento
- Esercitati a inclinare la fotocamera per guardare gli oggetti da diverse angolazioni
- Prova a esplorare sia in condizioni di luce che di buio usando la luce LED

Congratulazioni! Hai combinato con successo tutti i sistemi per creare un Mars Rover completamente funzionante. Hai imparato a programmare movimento, illuminazione, controlli della fotocamera e meccanismi di inclinazione - tutte le competenze necessarie per utilizzare un vero robot da esplorazione.

La tua missione su Marte è ora pronta per iniziare. Buona esplorazione!
