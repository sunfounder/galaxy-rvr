.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Preestrenos exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!


.. _ir_ultra_avoid: 


Lección 8 Evasión Avanzada de Obstáculos
===============================================

El módulo de evasión de obstáculos, como su nombre lo indica, ayuda a nuestro Rover a evitar obstáculos. Detecta los obstáculos transmitiendo una señal infrarroja y luego recibiendo la señal reflejada desde el objeto. Si hay un obstáculo frente al módulo, la señal infrarroja se refleja y el módulo la detecta.

Ahora, al agregar un sensor ultrasónico, mejoramos este sistema. Los sensores ultrasónicos miden la distancia enviando una onda sonora a una frecuencia específica y escuchando el rebote de esa onda. Al registrar el tiempo transcurrido entre la generación de la onda y su rebote, es posible calcular la distancia entre el sensor y el objeto.

¡La combinación de estos dos sensores nos proporciona un sistema de evasión de obstáculos confiable, eficiente y versátil!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

Objetivos de aprendizaje
--------------------------

* Combinar los módulos de evasión de obstáculos ultrasónico e infrarrojo para habilitar la función básica de evasión de obstáculos en el modelo de Mars Rover.
* Aprender a programar el modelo de Mars Rover para que detecte y evite obstáculos automáticamente.


Materiales
-------------

* Teléfono inteligente o tableta
* APP Mammoth Coding
* GalaxyRVR

Construcción de Sistemas Avanzados de Evasión de Obstáculos
---------------------------------------------------------------

En lecciones anteriores, aprendimos lo básico sobre el uso de sensores infrarrojos para evitar obstáculos. También exploramos los principios de los módulos ultrasónicos. Ahora, vamos a juntar todas estas partes para construir un sistema avanzado de evasión de obstáculos.

Nuestro Rover mejorado ahora navegará por su entorno utilizando tanto sensores ultrasónicos como infrarrojos.

1. Podemos usar el bloque de código de :ref:`ir_obstacle` como plantilla. Ábrelo desde tus proyectos guardados.

.. image:: img/7_avoid_open.png

2. Luego, guárdalo como una copia.

.. image:: img/7_avoid_save_copy.png

3. Renombra el proyecto y guárdalo.

.. image:: img/7_avoid_save_rename.png

4. Añade la detección de distancia usando el sensor ultrasónico. Arrastra un bloque ``when distance < 15 cm``.

.. image:: img/7_avoid_when.png
    :width: 800

5. De manera similar, arrastra un bloque ``stop other scripts in sprite`` para asegurarte de que el GalaxyRVR solo responda a un sensor a la vez.

.. image:: img/7_avoid_stop.png

6. Retrocede hasta alcanzar una distancia segura.

.. image:: img/7_avoid_backward.png

7. Gira durante un segundo (hacia la izquierda o derecha).

.. image:: img/7_avoid_turn.png

8. Avanza nuevamente.

.. image:: img/7_avoid_go.png

Ahora, los sensores IR en ambos lados y el sensor ultrasónico en la parte frontal trabajarán juntos para formar un poderoso sistema de evasión de obstáculos, asegurando que el GalaxyRVR no colisione con ningún obstáculo durante sus misiones.

