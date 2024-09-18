.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Preestrenos exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!


Lección 13 Control en Tiempo Real
=====================================

Ahora hemos explorado la mayoría de las funciones del GalaxyRVR. Para completar 
nuestro viaje y transformar el GalaxyRVR en un robot completamente funcional, 
necesitamos combinar las tres partes principales que hemos cubierto.

* :ref:`camera_system` : Esta parte incluye las funciones de control de la cámara y el LED.

* :ref:`rgb_move` : Esta sección incluye los efectos de movimiento e iluminación.

* :ref:`tilt_system` : Esta parte involucra ajustar la dirección del gimbal de la cámara.

Ponlo todo junto y podrás hacer clic en los sprites para encender o apagar la cámara y el LED, y usar las teclas de flechas para mover el GalaxyRVR.

.. image:: img/13_camera_go_all2.png


**Sistema de Cámara**
------------------------

Para esta parte, repite los pasos del :ref:`camera_system`.

1. Crea cuatro nuevos sprites para controlar la cámara y su LED. Ajusta sus tamaños para que se vean armoniosos.

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

7. Añade un bloque ``ir a la capa de atrás`` para cada sprite. Al hacer clic, el sprite se moverá a la capa de atrás, revelando el siguiente sprite, creando un efecto de alternancia.

.. image:: img/11_camera_layer.png
.. :align: center


**Sistema de Movimiento y RGB**
-----------------------------------

Mejoremos las funcionalidades de movimiento. Ya hemos programado estas en la sección :ref:`rgb_move`.

Recomendamos colocar estos bloques de código en los fondos (Backdrops). De esta manera, modificar el código del sprite no afectará esta funcionalidad.

.. image:: img/13.ccc_code_in_stage.png

1. Haz que el GalaxyRVR encienda la luz verde cuando avance.

.. image:: img/13.ccc_light_forward.png

2. Haz que el GalaxyRVR encienda la luz roja cuando retroceda.

.. image:: img/13.ccc_light_left_right.png

3. Haz que el GalaxyRVR encienda la luz amarilla cuando gire a la izquierda o a la derecha.

.. image:: img/13.ccc_light_backfwd.png

4. Haz que el GalaxyRVR encienda la luz de respiración cuando no se esté moviendo.

.. image:: img/13.ccc_light_breath.png

Finalmente, tu código debería verse así. Ten en cuenta que estos códigos deben escribirse en los fondos.

.. image:: img/11_camera_backdrops.png



**Sistema de Inclinación**
------------------------------

Esta parte es la misma que en el :ref:`tilt_system`. Simplemente repite los pasos.

1. Añade un sprite de flecha. Estableceremos la dirección del gimbal en función de su orientación.

.. image:: img/10_servo_arrow.png

2. Un bloque ``cuando se haga clic en este sprite`` es exactamente lo que necesitamos.

.. image:: img/6_animate_when_touch.png
    :width: 230

3. Haz que el programa se repita hasta que soltemos el sprite, es decir, que ya no lo estemos tocando.

.. image:: img/6_animate_repeat_touching.png
    :width: 550

4. Arrastra un bloque ``apuntar hacia la posición de toque`` para hacer que el sprite apunte hacia la posición tocada.

.. image:: img/10_servo_arrow_point_toward.png

5. Arrastra un bloque ``establecer ángulo del servo a 90 grados`` e inserta un bloque de ``dirección`` para alinear el ángulo del gimbal con la orientación del sprite de flecha. De esta manera, cuando cambiemos la dirección del sprite (es decir, toquemos el área del escenario), podemos cambiar el ángulo del gimbal.

.. image:: img/10_servo_arrow_angle_direction.png

6. Añade una verificación de límite para asegurar que la orientación del sprite no supere los 135 grados.

.. image:: img/10_servo_arrow_135.png

7. De manera similar, asegúrate de que su orientación no baje de 0 grados.

.. image:: img/10_servo_arrow_0.png

Toca el sprite y cambiará de dirección a medida que lo arrastres, alterando el ángulo del gimbal.

Si te resulta fácil deslizar el dedo fuera del sprite de flecha, puedes aumentar su tamaño en consecuencia.
