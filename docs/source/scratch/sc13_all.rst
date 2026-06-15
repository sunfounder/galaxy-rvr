.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lección 13: Control Completo del Mars Rover
=============================================

Has dominado todas las piezas, ¡ahora vamos a unirlas! Combina todo lo que has aprendido para crear tu Mars Rover completamente funcional con vista de cámara en vivo, controles de movimiento e inclinación de cámara.

Reúne tres sistemas increíbles:

- :ref:`camera_system`: Ve a través de los ojos de tu rover con video en vivo
- :ref:`rgb_move`: Conduce con luces de señal coloridas
- :ref:`tilt_system`: Mira hacia arriba y hacia abajo con los controles de la cámara

El resultado: control completo de tu GalaxyRVR. Haz clic en los botones para los controles de la cámara y usa las teclas de flecha para conducir.

.. image:: img/13_camera_go_all2.png


Sistema de Cámara
----------------------------------

Repite la configuración de la cámara de tu lección anterior: :ref:`camera_system`.

1. Crea cuatro sprites de control y organízalos ordenadamente.

   .. image:: img/11_camera_4.png

2. Programa la función de cada botón:

   - Bola 1: Cámara APAGADA

   .. image:: img/11_camera_1sp.png

   - Bola 2: Cámara ENCENDIDA con orientación correcta

   .. image:: img/11_camera_2sp.png

   - Globo 1: Luz LED ENCENDIDA

   .. image:: img/11_camera_3sp.png

   - Globo 2: Luz LED APAGADA

   .. image:: img/11_camera_4sp.png

3. Apila los controles para ahorrar espacio: se desplegarán cuando los necesites.

   .. image:: img/11_camera_fold.png

4. Agrega ``ir a la capa trasera`` para crear un efecto de alternancia entre botones.

   .. image:: img/11_camera_layer.png

Sistema de Movimiento e Iluminación
--------------------------------------

Agreguemos luces coloridas a los movimientos de tu rover. Ya hemos programado esto en la sección :ref:`rgb_move`.

Recomendamos colocar este código en la sección de Escenarios: esto lo mantiene separado del código de tus sprites y hace que todo sea más organizado.

   .. image:: img/13.ccc_code_in_stage.png

1. Haz que tu rover brille en VERDE al avanzar.

   .. image:: img/13.ccc_light_forward.png

2. Haz que tu rover brille en ROJO al retroceder.

   .. image:: img/13.ccc_light_backfwd.png

3. Haz que tu rover brille en AMARILLO al girar a la izquierda o derecha.

   .. image:: img/13.ccc_light_left_right.png

4. Crea un efecto de luz azul respiratoria cuando el rover esté detenido.

   .. image:: img/13.ccc_light_breath.png

El código completo del escenario debería verse así:

   .. image:: img/11_camera_backdrops.png

Control de Inclinación de la Cámara
--------------------------------------

Agreguemos controles de cámara. Esta parte es la misma que en :ref:`tilt_system`. Simplemente repite los pasos.

1. Agrega un sprite de **Flecha** para controlar la inclinación de tu cámara.

   .. image:: img/10_servo_arrow.png

2. Comienza con un bloque ``al hacer clic en este objeto``.

   .. image:: img/6_animate_when_touch.png
       :width: 200

3. Crea un bucle que se ejecute mientras tocas la flecha.

   .. image:: img/6_animate_repeat_touching.png
       :width: 400

4. Haz que la flecha apunte hacia tu dedo mientras arrastras.

   .. image:: img/10_servo_arrow_point_toward.png
       :width: 400

5. Conecta la dirección de la flecha con el ángulo de la cámara: gira la flecha para mover la cámara.

   .. image:: img/10_servo_arrow_angle_direction.png
       :width: 800

6. Establece límites para mantener la cámara entre 0 y 135 grados.

   .. image:: img/10_servo_arrow_135.png
       :width: 400

   .. image:: img/10_servo_arrow_0.png
       :width: 400

Toca y arrastra la flecha para apuntar la cámara de tu rover. Haz la flecha más grande si es difícil de controlar.

Control Completo de tu GalaxyRVR
------------------------------------

Ahora tienes el control total de tu Mars Rover. Así es como se opera tu GalaxyRVR completo:

.. image:: img/13_camera_go_all2.png

**Controla tu Rover:**

- Usa las teclas de flecha para avanzar, retroceder y girar
- Haz clic en los sprites de Bola para encender y apagar la cámara en vivo
- Haz clic en los sprites de Globo para encender y apagar la luz LED de la cámara
- Arrastra el sprite de flecha para inclinar la cámara hacia arriba y hacia abajo

**Prueba todas las funciones juntas:**

- Conduce mientras observas la transmisión de la cámara en vivo desde tu rover
- Observa las luces de colores que indican cada movimiento
- Practica inclinando la cámara para mirar objetos desde diferentes ángulos
- Intenta explorar tanto en condiciones brillantes como oscuras usando la luz LED

Felicitaciones. Has combinado exitosamente todos los sistemas para crear un Mars Rover completamente funcional. Has aprendido a programar movimiento, iluminación, controles de cámara y mecanismos de inclinación: todas las habilidades necesarias para operar un robot de exploración real.

Tu misión a Marte ya está lista para comenzar. Feliz exploración.
