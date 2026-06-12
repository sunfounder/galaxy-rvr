.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lezione 12: Vedere attraverso gli occhi del tuo Rover
=====================================================

Ora che il tuo rover può annuire con la sua fotocamera, diamogli una vera visione! In questa lezione, imparerai a vedere esattamente ciò che il tuo Mars Rover vede attraverso la sua fotocamera.

Guarda video in diretta dalla prospettiva del tuo rover mentre esplora - vedi paesaggi marziani, scopri rocce interessanti e naviga come un vero esploratore spaziale!

.. image:: img/11_camera_image.png

Obiettivi di apprendimento
--------------------------

* Visualizzare filmati in diretta dalla fotocamera del tuo Mars Rover in tempo reale
* Combinare la visualizzazione della fotocamera con il controllo del servo per un'esplorazione interattiva

Gli occhi del tuo Rover: ESP32 CAM
-------------------------------------------------------

Saluta l'ESP32 CAM - il potente sistema visivo del tuo rover! Questo fantastico modulo è come dare al tuo rover occhi super-intelligenti.

.. image:: img/esp32_cam.png
    :width: 400
    :align: center

L'ESP32 CAM fa due cose incredibili:

1. **Scatta foto e video** di tutto ciò che il tuo rover sta guardando
2. **Invia il video** direttamente al tuo telefono o computer

È come essere proprio lì su Marte con il tuo rover! Vedrai tutto ciò che vede, in tempo reale. Pronto per iniziare a esplorare attraverso gli occhi del tuo rover?

.. _camera_system:

Esplorare il sistema di fotocamere del tuo Rover
----------------------------------------------------

1. Trascina un blocco ``turn camera ON`` e cliccalo - guarda lo stage trasformarsi in una vista in diretta dalla fotocamera del tuo rover!

   .. image:: img/11_camera_on.png

2. Se la vista della fotocamera appare capovolta, usa ``set camera image orientation to inverted`` per correggerla.

   .. image:: img/11_camera_orientation.png

3. Hai bisogno di più luce? Usa ``turn camera LED ON`` per attivare la luce integrata della fotocamera.

   .. image:: img/11_camera_led.png

**Crea pulsanti di controllo della fotocamera**

1. Costruiamo un pannello di controllo della fotocamera! Crea quattro sprite e disponili ordinatamente.

   .. image:: img/11_camera_4.png

2. Programma ogni pulsante:

   - Palla 1: Spegne la fotocamera

   .. image:: img/11_camera_1sp.png

   - Palla 2: Accende la fotocamera e imposta l'orientamento

   .. image:: img/11_camera_2sp.png

   - Palloncino 1: Accende il LED

   .. image:: img/11_camera_3sp.png

   - Palloncino 2: Spegne il LED

   .. image:: img/11_camera_4sp.png

3. Risparmia spazio impilando i controlli - usciranno quando necessario!

   .. image:: img/11_camera_fold.png

4. Aggiungi ``go to back layer`` a ogni sprite - cliccando un pulsante si rivela il successivo, creando un fantastico effetto a levetta.

   .. image:: img/11_camera_layer.png

5. Clicca il pulsante di espansione dello stage per entrare nella modalità di controllo completo.

   .. image:: img/11_camera_go_stage.png

6. Ora guarderai video in diretta dalla prospettiva del tuo rover mentre esplora - vedi paesaggi marziani, scopri rocce interessanti e naviga come un vero esploratore spaziale!

   .. image:: img/11_camera_image.png

Blocchi di controllo fotocamera
-------------------------------

* Accendi o spegni la fotocamera. Quando è accesa, lo stage mostra video in diretta dal tuo rover!

  .. image:: img/block/camera_turn.png

* Controlla la luce LED della fotocamera - perfetta per esplorazioni al buio.

  .. image:: img/block/camera_led_turn.png

* Regola quanto è trasparente la vista della fotocamera.

  .. image:: img/block/camera_transp.png

* Capovolgi la vista della fotocamera se appare sottosopra.

  .. image:: img/block/camera_orientation.png
