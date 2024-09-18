.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Preestrenos exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!


Lección 11 Servo y Mecanismo de Inclinación
================================================

¡Bienvenidos de nuevo, jóvenes exploradores! En la aventura de hoy, nos adentraremos en el fascinante mundo del sistema visual del Rover de Marte. Así como nuestros ojos y cuello trabajan juntos para ayudarnos a ver y navegar nuestro entorno, nuestro Rover también necesita un sistema similar para moverse por el traicionero paisaje marciano. ¡Y eso es lo que vamos a construir hoy!

El sistema visual de nuestro Rover tiene dos partes principales: una cámara que actúa como sus "ojos" y un mecanismo de inclinación que funciona como su "cuello", permitiéndole mirar hacia arriba y hacia abajo. Al final de esta lección, ¡nuestro Rover podrá "ver" y "asentir"!

Primero, construiremos el mecanismo de inclinación, un dispositivo que sujetará la cámara de nuestro Rover y le permitirá rotar verticalmente. ¡Es como darle a nuestro Rover un cuello, para que pueda mover su "cabeza" o cámara hacia arriba y hacia abajo!

Luego aprenderemos sobre el servo, el pequeño pero poderoso "músculo" que mueve nuestro mecanismo de inclinación. Entenderemos cómo funciona y cómo podemos controlarlo usando la programación de Arduino.

Así como los músculos de nuestro cuello mueven nuestra cabeza para que nuestros ojos tengan una mejor vista, el servo moverá el mecanismo de inclinación para que la cámara del Rover pueda observar mejor el paisaje marciano.

¡Así que prepárense, exploradores! ¡Comencemos nuestra misión para equipar a nuestro Rover con su propio sistema visual!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/servo_range.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>



Objetivos de Aprendizaje
----------------------------

* Introducir los principios de funcionamiento de los servomotores y su aplicación en el control mecánico.
* Aprender a ajustar fácilmente los ángulos del servo usando Mammoth Coding, logrando un control preciso.
* Diseñar proyectos interactivos en la plataforma Mammoth Coding que permitan la interacción física a través de servomotores.


Materiales
--------------

* Smartphone o tableta
* APP Mammoth Coding
* GalaxyRVR

¿Qué es un Servo?
-----------------

¿Alguna vez has visto un espectáculo de marionetas? Si es así, tal vez te hayas maravillado de cómo el titiritero puede mover los brazos, piernas y cabeza de la marioneta tan suavemente, solo tirando de algunos hilos. De alguna manera, los servomotores son como nuestros titiriteros.

.. image:: ../img/puppet_show.png
    :width: 200
    :align: center

Los servomotores son tipos especiales de motores que no solo giran como una rueda. En cambio, pueden moverse a una posición específica y mantener esa posición. Imagina que estás jugando a "Simón dice", y Simón te dice: "¡Levanta el brazo a un ángulo de 90 grados!" Puedes hacerlo, ¿verdad? Eso es porque, al igual que un servo, puedes controlar exactamente cuánto mover tu brazo.

.. image:: ../img/servo.png
    :align: center

* Línea marrón: GND
* Línea naranja: Pin de señal, conéctalo al pin PWM de la placa principal.
* Cable rojo: VCC

Así como puedes controlar tus brazos para moverse a posiciones específicas, podemos usar servomotores para controlar la posición exacta de objetos en nuestros proyectos. En nuestro Rover de Marte, usaremos un servo para controlar el movimiento hacia arriba y hacia abajo de nuestro mecanismo de inclinación, tal como tú puedes mover tu cabeza hacia arriba y hacia abajo.

En el siguiente paso, haremos un fascinante viaje dentro de un servomotor para entender cómo funciona. ¿Emocionado? ¡Vamos!

¿Cómo Funciona un Servo?
----------------------------

Entonces, ¿cómo hace un servo su magia? ¡Vamos a emprender un emocionante viaje dentro de un servo!

Si pudiéramos mirar dentro de un servo, veríamos algunas partes. En el corazón de un servo hay un motor regular, muy similar a los motores que hacen girar las ruedas de nuestro Rover de Marte. Alrededor del motor, hay un engranaje grande que está conectado a un engranaje más pequeño en el eje del motor. Así es como el movimiento rápido y circular del motor se transforma en un movimiento más lento pero más fuerte.

.. image:: ../img/servo_internal.png
    :align: center

Pero eso no es lo que hace especial a un servo. La magia ocurre en una pequeña pieza electrónica llamada "potenciómetro" y el "circuito de control". Así es como funciona: cuando el servo se mueve, el potenciómetro gira y cambia su resistencia. El circuito de control mide este cambio de resistencia y sabe exactamente en qué posición se encuentra el servo. Ingenioso, ¿no?

Para controlar un servo, le enviamos un tipo especial de señal llamada señal de "modulación por ancho de pulso" o PWM. Al cambiar el ancho de estos pulsos, podemos controlar exactamente cuánto se mueve el servo y mantenerlo en esa posición.

En el siguiente paso, aprenderemos cómo controlar un servo usando una APP. ¿Listo para hacer magia con códigos? ¡Vamos!



Explorando el Sistema de Inclinación del Rover de Marte
-------------------------------------------------------------


**Configurando el Ángulo del Gimbal**

1. Revisa el ángulo del servo, y puedes ver el ángulo actual en el escenario.

.. image:: img/10_servo_angle.png

2. Arrastra un bloque ``set servo angle to 90 degrees``. Haz clic en él y verás que el GalaxyRVR mira hacia adelante.

.. image:: img/10_servo_set_angle.png

3. Cambia el valor a 45 y haz clic en él; verás que el GalaxyRVR mira hacia arriba.

.. image:: img/10_servo_set_angle_45.png

4. A través de varios intentos, descubrirás que el gimbal del GalaxyRVR puede moverse entre 0 y 135 grados. A medida que aumenta el ángulo, el gimbal se inclina hacia abajo.


**Cambiando el Ángulo del Gimbal**

1. El sistema de gimbal servo del GalaxyRVR es una estructura refinada de un solo grado de libertad, por lo que solo necesitas controlar sus funciones de "reiniciar", "mover hacia arriba" y "mover hacia abajo".

.. raw:: html

   <br></br>


2. Ahora, vamos a crear su botón de reinicio. Arrastra un bloque ``when this sprite clicked``.

.. image:: img/10_servo_when_click.png

3. Inserta un bloque ``set servo angle to 90 degrees`` para que el gimbal mire hacia adelante.

.. image:: img/10_servo_when_90.png

4. Arrastra un bloque ``when up arrow key pressed``.

.. image:: img/10_servo_when_up.png

5. Disminuye el ángulo del servo cuando se presione la tecla de flecha hacia arriba.

.. image:: img/10_servo_when_up2.png

6. De manera similar, añade un evento de tecla de flecha hacia abajo para hacer que el gimbal mire hacia abajo.

.. image:: img/10_servo_when_down.png

Ahora, haz clic en el botón de pantalla completa para agrandar el escenario. Presiona las teclas hacia arriba y hacia abajo para ajustar el ángulo del gimbal, y haz clic en el sprite para restablecer el ángulo.


.. _tilt_system:

Toca el Área del Escenario para Ajustar el Ángulo del Gimbal
-----------------------------------------------------------------

A continuación, usaremos un sprite de flecha para lograr ajustes más suaves en el ángulo del servo.

Cuando toquemos la flecha, podemos arrastrar la dirección del sprite de la flecha.

1. Elimina el sprite original.

.. image:: img/6_animate_delete.png

2. Añade un sprite de Flecha. Configuraremos la dirección del gimbal en función de su orientación.

.. image:: img/10_servo_arrow.png


3. Un bloque ``when this sprite clicked`` es justo lo que necesitamos.

.. image:: img/6_animate_when_touch.png
    :width: 230

4. Haz que el programa se repita hasta que lo soltemos, lo que significa que ya no tocamos el sprite.

.. image:: img/6_animate_repeat_touching.png
    :width: 550

5. Arrastra un bloque ``point towards touch_position`` para que el sprite mire hacia la posición tocada.

.. image:: img/10_servo_arrow_point_toward.png

6. Arrastra un bloque ``set servo angle to 90 degrees`` y añade un bloque ``direction`` para alinear el ángulo del gimbal con la orientación del sprite de la flecha. De esta manera, cuando cambiemos la dirección del sprite de la flecha (es decir, toquemos el área del escenario), podremos cambiar el ángulo del gimbal.

.. image:: img/10_servo_arrow_angle_direction.png

7. Añade una verificación de límite para asegurarte de que la orientación del sprite de la flecha no supere los 135 grados.

.. image:: img/10_servo_arrow_135.png

8. De manera similar, asegúrate de que su orientación no baje de 0 grados.

.. image:: img/10_servo_arrow_0.png


Toca el sprite, y cambiará de dirección a medida que lo arrastres, alterando el ángulo del gimbal.

Si te resulta fácil deslizar el dedo fuera del sprite de flecha, puedes aumentar el tamaño del sprite según sea necesario.


Bloques Relacionados con el Servo
--------------------------------------

.. image:: img/block/servo_set_angle.png

Este bloque se utiliza para establecer el ángulo del servo. El rango es de 0 a 180 grados (sin embargo, debido a limitaciones estructurales, el rango usable real es de 0 a 135 grados).

.. image:: img/block/servo_increase_angle.png

Este bloque aumenta (o disminuye) el ángulo del servo. El valor puede ser negativo.

.. image:: img/block/servo_value.png

El ángulo actual del servo.
