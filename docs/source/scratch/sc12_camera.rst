.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Preestrenos exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!


Lección 12 Sistema de Cámara
==================================

¡Bienvenidos de nuevo, jóvenes exploradores! En la última lección, equipamos nuestro GalaxyRVR con la capacidad de "asentir" usando un mecanismo de inclinación. Ahora, es hora de darle a nuestro Rover "ojos" - ¡la cámara!

En esta emocionante aventura, nos sumergiremos en la configuración del sistema de cámara del Rover. Aprenderás cómo transmitir las imágenes capturadas por la cámara del Rover a la APP, para que puedas ver exactamente lo que el Rover ve en tiempo real. ¡Imagina la emoción de experimentar el paisaje marciano desde la perspectiva del Rover!

Esto ofrece una experiencia aún más interactiva y envolvente con nuestro GalaxyRVR. ¡Sigue atento para más aventuras!


.. image:: img/11_camera_image.png


Objetivos de Aprendizaje
----------------------------

* Aprender a ver con precisión todo lo que el Rover de Marte ve en tiempo real.
* Comprender cómo combinar la entrada de la cámara y el control del servo para mejorar la interactividad del proyecto.


Materiales
-------------

* Smartphone o tableta
* APP Mammoth Coding
* GalaxyRVR


Introducción a ESP32 CAM
----------------------------

En nuestra aventura anterior, equipamos nuestro Rover de Marte con un par de "ojos" integrando el ESP32 CAM. Hoy, aprenderemos más sobre este módulo y haremos que realmente "vea".

.. image:: ../img/esp32_cam.png
    :width: 400
    :align: center

El ESP32 CAM, actuando como los ojos de nuestro Rover, es un módulo pequeño pero poderoso. No solo integra funcionalidades de Wi-Fi y Bluetooth, sino que también incluye una cámara compacta. Esta cámara ayuda a nuestro Rover a capturar imágenes de su entorno.

Así como usamos nuestros ojos para observar nuestro entorno, el ESP32 CAM puede "ver" lo que hay frente al Rover y luego enviar estos datos visuales a nuestro smartphone o computadora. ¡Esto nos permite ver todo lo que el Rover ve en tiempo real!

¡Es como si estuviéramos pilotando el Rover directamente, observando no solo el propio Rover, sino también el mundo que explora! ¡Increíble, ¿verdad?! Vamos a profundizar más en esto...


.. _camera_system:

Explorando el Sistema Visual del Rover de Marte
---------------------------------------------------

1. Arrastra un bloque ``turn camera ON``. Haz clic en él y verás que el fondo del escenario muestra la transmisión de la cámara.

.. image:: img/11_camera_on.png
.. :align: center

2. Si ves la transmisión de la cámara invertida, un bloque ``set camera image orientation to inverted`` puede ayudarte a corregirlo.

.. image:: img/11_camera_orientation.png
.. :align: center

3. Arrastra un bloque ``turn camera LED ON``. Haz clic en él y el LED junto a la cámara del GalaxyRVR se encenderá.

.. image:: img/11_camera_led.png
.. :align: center


**Haz clic en el sprite para encender la cámara**

1. Ahora que sabemos cómo controlar el módulo de la cámara, crea cuatro nuevos sprites para controlar la cámara y su LED. Ajusta sus tamaños para que se vean armoniosos.

.. image:: img/11_camera_4.png
.. :align: center

2. Programa cada sprite: al hacer clic en la bola 1, se apagará la cámara.

.. image:: img/11_camera_1sp.png
.. :align: center

3. Al hacer clic en la bola 2, se encenderá la cámara y se configurará la orientación de la imagen.

.. image:: img/11_camera_2sp.png
.. :align: center

4. Al hacer clic en la bola 3, se encenderá el LED.

.. image:: img/11_camera_3sp.png
.. :align: center

5. Al hacer clic en la bola 4, se apagará el LED.

.. image:: img/11_camera_4sp.png
.. :align: center

6. Para ahorrar espacio en el escenario, apila cada conjunto de controles.

.. image:: img/11_camera_fold.png
.. :align: center

7. Añade un bloque ``go to back layer`` para cada sprite. Al hacer clic, el sprite se moverá a la capa de atrás, revelando el siguiente sprite, creando un efecto de alternancia.

.. image:: img/11_camera_layer.png
.. :align: center



Bloques Relacionados con la Cámara
---------------------------------------

.. image:: img/block/camera_turn.png

Enciende (o apaga) el módulo de la cámara. Una vez activado, el fondo del escenario cambiará a la vista de la cámara.

.. image:: img/block/camera_led_turn.png

Enciende (o apaga) el LED auxiliar en el módulo de la cámara.

.. image:: img/block/camera_transp.png

Establece la opacidad de la vista de la cámara.

.. image:: img/block/camera_orientation.png

Establece la orientación de la vista de la cámara. Puedes usar este bloque para invertir la vista.

