.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _sc_shooting:

Extensión 3 Tiro al Blanco
====================================

¿Alguna vez has visto esos emocionantes juegos de tiro en la televisión, donde los concursantes apuntan al blanco con precisión para acumular puntos? Ahora, ¡puedes experimentar esa misma adrenalina aquí en Scratch! En nuestro juego interactivo de tiro, usarás el sprite de la **Mira** para apuntar y acertar lo más cerca posible del centro del blanco, maximizando tu puntuación con cada disparo preciso.

Para comenzar, haz clic en la bandera verde. Controlarás tus disparos usando el innovador módulo de evitación de obstáculos. ¿Listo para poner a prueba tu puntería y reflejos? ¡Veamos qué puntuación obtienes!

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

A continuación, se detallan los pasos para implementar el proyecto. Se recomienda seguir estos pasos inicialmente, y una vez familiarizado, puedes modificar los efectos a tu gusto.

1. Dibuja el sprite **Mira**
----------------------------------------------

* Elimina el sprite predeterminado, selecciona el botón **Sprite** y haz clic en **Pintar**.

  .. image:: img/shooting_paint_cross.png

* Ve a la página de **Disfraces**. Usa la herramienta **Círculo**, quita el color de relleno y ajusta el color y el grosor del contorno.

  .. image:: img/shooting_paint_cross1.png

* Dibuja un círculo con la herramienta **Círculo**. Luego, usa la herramienta **Seleccionar** para alinear el centro del círculo con el centro del lienzo.

  .. image:: img/shooting_paint_cross2.png

* Con la herramienta **Línea**, dibuja una cruz dentro del círculo.

  .. image:: img/shooting_paint_cross3.png

* Finalmente, regresa a la página de **Código** y renombra el sprite como "Mira".

  .. image:: img/shooting_paint_cross4.png

2. Dibuja el sprite **Blanco**
----------------------------------------

* De manera similar, selecciona el botón **Sprite** y haz clic en **Pintar**.

  .. image:: img/shooting_paint_target1.png

* Entra en la página de **Disfraces**. Usa la herramienta **Círculo**, selecciona un color negro, elimina el contorno y pinta un círculo grande.

  .. image:: img/shooting_paint_target3.png
    :width: 90%

* Dibuja círculos adicionales usando el mismo método, cada uno de un color diferente. Ajusta la posición de los círculos superpuestos usando la herramienta **Adelante** o **Atrás** para que los orígenes de todos los círculos estén alineados con el centro del lienzo.

  .. image:: img/shooting_paint_target4.png
    :width: 90%

* Regresa a la página de **Código** y renombra este sprite como "Blanco".

  .. image:: img/shooting_paint_target5.png

3. Añade un fondo
--------------------------

* Añade un fondo adecuado que preferiblemente sea menos colorido y no coincida con los colores del sprite **Blanco**. Yo he elegido el fondo **Pared1**.

  .. image:: img/shooting_choose_backdrop.png

* Ajusta las posiciones y tamaños de los sprites **Blanco** y **Mira**.

  .. note::

    * Asegúrate de que el sprite **Mira** esté en una capa superior al sprite **Blanco** moviendo primero el sprite **Blanco** y luego la **Mira**.
    * La **Mira** debe ser más pequeña que el espacio entre los anillos de colores del sprite **Blanco**.

  .. image:: img/shooting_choose_backdrop1.png
  
4. Programa el sprite **Mira**
---------------------------------------

* Aleatoriza la posición y tamaño del sprite **Mira**, permitiendo que se mueva de manera impredecible.

  .. image:: img/shooting_script_cross.png

* Cuando el módulo de evitación de obstáculos izquierdo esté bloqueado, se transmite un mensaje: disparo.

  .. image:: img/shooting_script_cross1.png

* Cuando se recibe el mensaje de **disparo**, el sprite deja de moverse y se reduce gradualmente, simulando el disparo de una bala.

  .. image:: img/shooting_script_cross2.png

* Usa el bloque [Tocar color ()] para determinar la posición del disparo.

  .. image:: img/shooting_script_cross3.png
    :width: 90%

* Informa una puntuación de 10 si el disparo cae dentro del círculo amarillo.

  .. image:: img/shooting_script_cross4.png

* Informa una puntuación de 9 si el disparo cae dentro del círculo rojo. Del mismo modo, usa el bloque [Tocar color ()] para coincidir con el color del círculo rojo.

  .. image:: img/shooting_script_cross5.png
    :width: 90%

* Usa el mismo método para confirmar dónde aterriza la bala. Si no cae en el sprite **Blanco**, indica que ha fallado.

  .. image:: img/shooting_script_cross6.png

La programación está completa. Ahora puedes hacer clic en la bandera verde para ejecutar el script y ver si logra el efecto deseado.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_shooting.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>
