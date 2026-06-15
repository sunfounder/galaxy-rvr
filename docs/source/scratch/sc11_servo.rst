.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lección 11: Controla la Inclinación de la Cámara de tu Rover
===============================================================

¡Dale a tu Rover Marciano una cámara que se mueva! Así como puedes mover la cabeza hacia arriba y hacia abajo, tu rover ahora puede inclinar su cámara para explorar el paisaje marciano desde diferentes ángulos.

Usaremos un motor especial llamado "servo" que puede moverse a posiciones exactas, perfecto para controlar la inclinación de la cámara de tu rover. Aprende a programar el servo para mirar hacia las montañas marcianas o hacia abajo a las rocas interesantes.

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/servo_range.mp4" type="video/mp4">
        Tu navegador no soporta la etiqueta de video.
    </video>

Objetivos de Aprendizaje
-------------------------

* Descubrir cómo funcionan los servos
* Aprender a controlar los ángulos de la cámara usando bloques de código simples
* Crear proyectos interactivos que te permitan inclinar la cámara con controles táctiles

¿Qué es un Servo?
----------------------------------------

¡Conoce al servo, el músculo móvil de tu robot!

Así como puedes mover tu brazo exactamente a la posición correcta, un servo motor puede moverse a ángulos específicos y mantenerlos perfectamente. Piensa en él como un motor inteligente que sabe exactamente dónde detenerse.

.. image:: img/servo.png
    :align: center

**Conexiones simples:**

- Cable marrón: Tierra (-)
- Cable rojo: Alimentación (+)
- Cable naranja: Señal (le dice al servo hacia dónde moverse)

En tu Rover Marciano, el servo actúa como una cabeza que asiente, moviendo la cámara hacia arriba y hacia abajo para capturar la vista perfecta.

¿Cómo Funciona un Servo?
-------------------------------------------

Dentro de cada servo, hay un equipo inteligente trabajando en conjunto:

.. image:: img/servo_internal.png
    :align: center

1. **Motor normal** - Gira rápido como las ruedas de tu rover
2. **Engranajes** - Reducen el movimiento y lo hacen más fuerte
3. **Circuito cerebral** - Sabe exactamente en qué posición está el servo
4. **Sensor de posición** - Informa hacia dónde apunta el servo

Controlamos los servos usando señales especiales que dicen "¡muévete a este ángulo exacto!" Es como decirle a un amigo exactamente cuánto debe girar la cabeza.

¿Listo para hacer bailar a tu servo? ¡Empecemos a programar!


Controla el Sistema de Inclinación de tu Rover
-----------------------------------------------

Aprendamos a controlar el sistema de inclinación de tu Rover Marciano, la parte que mueve la cámara hacia arriba y hacia abajo como una cabeza que asiente.

**Configuración del Ángulo de la Cámara**

1. Primero, :ref:`app_connect`.

2. Verifica el ángulo actual del servo; lo verás mostrado en el escenario.

   .. image:: img/10_servo_angle.png

3. Arrastra un bloque ``set servo angle to 90 degrees``. Haz clic en él para que tu rover mire hacia adelante.

   .. image:: img/10_servo_set_angle.png

4. Cambia el valor a 45 y haz clic; ahora tu rover mira hacia el cielo marciano.

   .. image:: img/10_servo_set_angle_45.png

5. ¡Experimenta con diferentes ángulos! Descubrirás que tu rover puede inclinarse entre 0 y 135 grados.

**Creación de Controles de Cámara**

1. Construyamos un panel de control para la cámara de tu rover:

2. Crea un botón de reinicio: arrastra un bloque ``when this sprite clicked``.

   .. image:: img/10_servo_when_click.png

3. Agrega ``set servo angle to 90 degrees`` para que la cámara mire hacia adelante nuevamente.

   .. image:: img/10_servo_when_90.png

4. Agrega controles arriba/abajo: arrastra los bloques ``when up arrow key pressed`` y ``when down arrow key pressed``.

   .. image:: img/10_servo_when_up.png

5. Programa la flecha arriba para disminuir el ángulo (mirar hacia arriba).

   .. image:: img/10_servo_when_up2.png

6. Programa la flecha abajo para aumentar el ángulo (mirar hacia abajo).

   .. image:: img/10_servo_when_down.png

Ahora haz clic en el botón de pantalla completa y toma el control. Usa las teclas de flecha para ajustar la vista de tu rover y haz clic en el sprite para reiniciar. ¡Eres el operador de cámara!

.. _tilt_system:

Control Táctil para el Ángulo de la Cámara
-------------------------------------------------------------

¡Crea una cámara controlada por tacto! Arrastra una flecha para apuntar la cámara de tu rover exactamente hacia donde quieras.

1. Limpia el escenario eliminando cualquier sprite existente.

   .. image:: img/6_animate_delete.png

2. Agrega un sprite de Flecha para usarlo como control táctil.

   .. image:: img/10_servo_arrow.png

3. Comienza con ``when this sprite clicked`` para iniciar el control táctil.

   .. image:: img/6_animate_when_touch.png
       :width: 200

4. Crea un bucle que se ejecute mientras estés tocando la flecha.

   .. image:: img/6_animate_repeat_touching.png
       :width: 400

5. Haz que la flecha apunte hacia tu dedo mientras arrastras.

   .. image:: img/10_servo_arrow_point_toward.png
       :width: 400

6. Vincula la dirección de la flecha con el ángulo de la cámara: ¡gira la flecha, mueve la cámara!

   .. image:: img/10_servo_arrow_angle_direction.png
       :width: 800

7. Establece límites para mantener la cámara entre 0 y 135 grados.

   .. image:: img/10_servo_arrow_135.png
       :width: 400

   .. image:: img/10_servo_arrow_0.png
       :width: 400

Toca y arrastra la flecha para apuntar la cámara de tu rover. Haz que la flecha se mueva suavemente y responda instantáneamente a tu tacto para una sensación de control realista.

Bloques de Control del Servo
-------------------------------

* Establece el servo en un ángulo específico (0-135 grados)

  .. image:: img/block/servo_set_angle.png

* Aumenta o disminuye el ángulo del servo (usa números negativos para disminuir)

  .. image:: img/block/servo_increase_angle.png

* Verifica el ángulo actual del servo

  .. image:: img/block/servo_value.png
