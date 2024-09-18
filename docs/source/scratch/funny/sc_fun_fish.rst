.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.


Extensión 5 Pesca
===========================

Sumérgete en nuestro juego interactivo de pesca, utilizando el módulo de evitación de obstáculos izquierdo para una experiencia envolvente.

Cuando el script está activo, los peces nadarán de un lado a otro en el escenario. Para atrapar un pez, debes bloquear el módulo de evitación de obstáculos izquierdo justo cuando el pez esté a punto de pasar por el anzuelo. El juego registra automáticamente el número de peces que atrapas.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_fishing.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Sigue estos pasos iniciales para configurar el proyecto, y siéntete libre de personalizar los efectos una vez que estés familiarizado con la configuración.

1. Añadir fondo y sprites
------------------------------------

Primero, selecciona un fondo de **Bajo el agua**, luego añade un sprite de **Pez** y haz que nade a través del escenario.

* Usa el botón **Elegir un fondo** para seleccionar un fondo de **Bajo el agua**.

  .. image:: img/fish_choose_backdrop.png

* Elimina el sprite original y selecciona el sprite de **Pez**.

  .. image:: img/fish_choose_fish.png

* Ajusta el tamaño y la posición del sprite **Pez**.

  .. image:: img/fish_set_fish.png

2. Dibujar un sprite de **Anzuelo**
---------------------------------------

A continuación, crea un sprite de **Anzuelo**, que controlarás mediante el módulo de evitación de obstáculos izquierdo para comenzar a pescar.

* Añade el sprite **Glow-J** mediante **Elegir un Sprite** y renómbralo "Anzuelo".

  .. image:: img/fish_choose_j.png

* Navega a la página de **Disfraces** del sprite **Glow-J**, renómbralo como **Anzuelo**, selecciona la "J" blanca interna y cambia su color a rojo.

  .. image:: img/fish_set_j1.png
    :width: 90%

* Elimina el relleno cian externo y reduce su grosor. Asegúrate de que la parte superior del anzuelo esté alineada con el punto central.

  .. image:: img/fish_set_j2.png

* Usa la **Herramienta de Línea** para dibujar una línea que se extienda desde el punto central hacia arriba, saliendo del escenario.

  .. image:: img/fish_set_j3.png

3. Programación del sprite **Pez**
---------------------------------------

El sprite **Pez** debe moverse de izquierda a derecha en el escenario, y cuando interactúa con el sprite **Anzuelo** en estado de pesca, debe encogerse, moverse a una posición específica y luego desaparecer, seguido de la creación de un nuevo sprite **Pez**.

* Crea una variable **puntuación** para almacenar el número de peces atrapados, oculta este sprite y clónalo.

  .. image:: img/fish_script_fish1.png

* Muestra el clon del sprite **Pez**, cambia su disfraz y establece la posición inicial.

  .. image:: img/fish_script_fish2.png

* Habilita el clon del sprite **Pez** para que se mueva de izquierda a derecha y rebote cuando toque el borde del escenario.

  .. image:: img/fish_script_fish3.png

* Si el clon del sprite **Pez** toca el sprite **Anzuelo** en estado de pesca (cuando se pone rojo).

  .. image:: img/fish_script_fish4.png
    :width: 90%

* Aumenta la puntuación (variable **puntuación**) en 1, muestra una animación de puntuación (se encoge un 40%, se mueve rápidamente a la posición del marcador y desaparece). Simultáneamente, crea un nuevo pez (un nuevo clon del sprite **Pez**) y continúa el juego.

  .. image:: img/fish_script_fish5.png

4. Programación del sprite **Anzuelo**
---------------------------------------------

El sprite **Anzuelo** generalmente permanece bajo el agua en estado amarillo. Cuando tu mano bloquea el módulo de infrarrojos del lado izquierdo, cambia al estado de pesca (rojo) y se mueve por encima del escenario.

* Cuando se hace clic en la bandera verde, establece el efecto de color del sprite en 30 (amarillo) y establece su posición inicial.

  .. image:: img/fish_script_hook1.png

* Cuando tu mano bloquea el módulo de infrarrojos del lado izquierdo, establece el efecto de color en 0 (rojo, iniciando el estado de pesca), espera 0.1 segundos, luego mueve el sprite **Anzuelo** a la parte superior del escenario.

  .. image:: img/fish_script_hook2.png

* Después de retirar tu mano, deja que el **Anzuelo** vuelva a su posición inicial.

  .. image:: img/fish_script_hook3.png

Una vez que hayas completado la programación, haz clic en la bandera verde para ejecutar el script y ver si logra el efecto deseado.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_fishing.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

