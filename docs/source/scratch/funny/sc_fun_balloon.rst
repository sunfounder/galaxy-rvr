.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirte?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _sc_balloon:

Extensión 1 Inflar el Globo
=========================================

En este proyecto interactivo, controlamos el vuelo de un globo.

Al hacer clic en la bandera verde, el globo comenzará a inflarse progresivamente. Si el globo se hace demasiado grande, explotará; si es demasiado pequeño, caerá. Tu tarea es bloquear el módulo de infrarrojos izquierdo en el momento adecuado para hacerlo ascender.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_balloon.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

A continuación se detallan los pasos para implementar el proyecto. Es recomendable seguir estos pasos inicialmente y, una vez familiarizado, puedes modificar los efectos según lo desees.

1. Añadir un Objeto y un Fondo
----------------------------------------

* Elimina el objeto predeterminado y haz clic en el botón **Elegir un Objeto** en la esquina inferior derecha del área de objetos. Luego, selecciona el objeto **Balloon1**.

  .. image:: img/balloon_choose_sprite.png

* Añade un fondo de **Boardwalk** u otro fondo de tu elección a través del botón **Elegir un Fondo**.

  .. image:: img/balloon_choose_backdrop.png

2. Dibujar un Disfraz para el Objeto **Balloon1**
-------------------------------------------------------

Ahora, vamos a crear un disfraz con efecto de explosión para el globo.

* Navega a la pestaña **Disfraces** del objeto **Balloon1**, haz clic en el botón **Elegir un Disfraz** en la esquina inferior izquierda y selecciona **Pintar** para abrir un **Disfraz** en blanco. Llámalo "boom".

  .. image:: img/balloon_set_ball1.png

* Elige un color y usa la herramienta **Pincel** para dibujar un patrón.

  .. image:: img/balloon_set_ball2.png
    :width: 90%

* Escoge otro color, selecciona la herramienta **Relleno** y pulsa dentro del patrón para llenarlo.

  .. image:: img/balloon_set_ball3.png
    :width: 90%

* Finalmente, añade el texto "BOOM" para completar el disfraz con efecto de explosión.

  .. image:: img/balloon_set_ball4.png
    :width: 90%

3. Programar el Objeto **Balloon**
------------------------------------------

* Inicializa la posición y el tamaño del objeto **Balloon1**.

  .. image:: img/balloon_script1.png

* Aumenta gradualmente el tamaño del objeto **Balloon**.

  .. image:: img/balloon_script2.png

* En este punto, bloquea el módulo de evitación de obstáculos izquierdo para evitar que el objeto **Balloon1** se siga inflando.

  .. image:: img/balloon_script3.png

* Ahora, deja que el objeto **Balloon1** decida si ascender o descender en función de su tamaño.

  * Si el tamaño es menor de 90, descenderá (la coordenada y disminuirá).
  * Si el tamaño está entre 90 y 120, ascenderá (la coordenada y aumentará).

  .. image:: img/balloon_script4.png

* Si no bloqueas el módulo de evitación de obstáculos izquierdo, el globo seguirá inflándose hasta que supere un tamaño de 120, momento en el cual explotará (cambiará al disfraz con efecto de explosión).

  .. image:: img/balloon_script5.png

La programación está completa. Ahora puedes hacer clic en la bandera verde para ejecutar el script y ver si logra el efecto deseado.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_balloon.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>
