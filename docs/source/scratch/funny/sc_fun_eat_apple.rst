.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.


Extensión 4 Comer la manzana
===============================

En este proyecto, usamos un módulo de evitación de obstáculos por infrarrojos para guiar al sprite Beetle hacia una manzana.

Después de hacer clic en la bandera verde, pasa rápidamente tu mano por encima del módulo de evitación de obstáculos izquierdo (bloquea y retira rápidamente tu mano frente al módulo) para iniciar la rotación del Beetle. Una vez que esté alineado correctamente, desliza nuevamente tu mano sobre el módulo para mover el Beetle hacia adelante, asegurándote de que evite las líneas negras en el mapa. Si es necesario realizar ajustes o giros, desliza tu mano nuevamente sobre el módulo para rotar el Beetle al ángulo deseado. Repite estos pasos hasta que el sprite Beetle llegue a la manzana.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_eat_apple.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

A continuación, se detallan los pasos para implementar el proyecto. Se recomienda seguir estos pasos inicialmente, y una vez familiarizado, puedes modificar los efectos a tu gusto.

1. Dibujar el Fondo **Laberinto**
-------------------------------------

Aquí dibujaremos un fondo de mapa con una manzana roja.

* Primero, selecciona un fondo en blanco.

  .. image:: img/apple_click_backdrop.png

* Haz clic en **Fondos** para comenzar a dibujar el fondo del mapa. Primero, renombra el fondo como **Laberinto**.

  .. image:: img/apple_open_backdrop.png

* Usa la herramienta **Línea**, establece el color en negro, el ancho en 4, y comienza a dibujar el mapa. Puedes diseñar el mapa según tus ideas; no tiene que ser igual al mío.

  .. image:: img/apple_paint_bk_maze2.png
    :width: 90%

* Ahora, dibuja una manzana. Usando la herramienta **Círculo**, dibuja un elipse o círculo en rojo sin contorno.

  .. image:: img/apple_paint_bk_maze3.png

  .. note::

    Puedes eliminar el contorno haciendo clic en la ventana de **Contorno** y luego utilizando la herramienta **Eliminar**.

    .. image:: img/apple_paint_bk_maze4.png

* Selecciona la herramienta **Pincel**, elige un color y un ancho para terminar de dibujar la manzana.

  .. image:: img/apple_paint_bk_maze5.png

2. Dibujar el Fondo **Victoria**
------------------------------------

Ahora comienza a dibujar; sigue los pasos a continuación, o dibuja el fondo basándote en tu creatividad, asegurándote de que represente una victoria.

* Haz clic en el botón para agregar un nuevo fondo en la parte inferior, selecciona **Pintar**, y nombra este fondo **Victoria**.

  .. image:: img/apple_paint_bk_win.png

* Usando la herramienta **Círculo**, dibuja un elipse en rojo sin contorno.

  .. image:: img/apple_paint_bk_win2.png
    :width: 90%

* Luego, usa la herramienta **Texto** para escribir "¡VICTORIA!". Configura el color de la fuente en negro y ajusta el tamaño y la posición del texto.

  .. image:: img/apple_paint_bk_cus2.png
    :width: 90%

3. Programar el Fondo **Laberinto**
--------------------------------------

Asegúrate de que el fondo se cambie a **Laberinto** cada vez que comienza el juego.

.. image:: img/apple_switch_backdrop.png
  :width: 90%

4. Seleccionar el Sprite **Beetle**
-----------------------------------------

* Elimina el sprite predeterminado y selecciona el sprite **Beetle**.

  .. image:: img/apple_choose_sprite.png

* Coloca el sprite **Beetle** en la entrada del fondo **Laberinto**, toma nota de los valores de coordenadas x, y en este punto, y redimensiona el sprite al 40%.

  .. image:: img/apple_place_sprite.png

5. Programar el Sprite **Beetle**
-----------------------------------------------

Ahora, escribe un script para que el sprite **Beetle** avance y cambie de dirección bajo el control del módulo de evitación de obstáculos izquierdo.

* Cuando se haga clic en la bandera verde, establece el ángulo del **Beetle** a 90, y la posición a (-124, -113), o usa los valores de coordenadas de tu ubicación.

  .. image:: img/apple_point_in.png
    :width: 90%

* Crea la variable **flag** y establece su valor inicial en -1.

  .. image:: img/apple_vable_flag.png

A continuación, dentro del bloque [por siempre], usa cuatro bloques [si] para manejar diferentes escenarios.

* Si el infrarrojo izquierdo está bloqueado, usa el bloque [`mod <https://en.scratch-wiki.info/wiki/Boolean_Block>`_] para alternar la variable **flag** entre 0 y 1 (alternando entre 0 en esta pulsación y 1 en la siguiente).

   .. image:: img/apple_read_ir.png

* Si el flag es 0 (el infrarrojo izquierdo está bloqueado), deja que el sprite **Beetle** gire en el sentido de las agujas del reloj. Si el flag es 1 (el infrarrojo izquierdo está bloqueado de nuevo), el **Beetle** avanza. De lo contrario, sigue girando en el sentido de las agujas del reloj.

  .. image:: img/apple_read_flag.png

* Si el sprite **Beetle** toca el color negro (la línea negra en el fondo **Laberinto**), el juego termina, y el script deja de ejecutarse.

  .. image:: img/apple_touch_black1.png

  .. note::
    
    Haz clic en el área de color en el bloque [Tocar color] y selecciona la herramienta de cuentagotas para recoger el color de la línea negra en el escenario. Si eliges un negro al azar, este bloque [Tocar color] no funcionará correctamente.

    .. image:: img/apple_touch_black.png

* Si el **Beetle** toca el color rojo (también usa la herramienta de cuentagotas para recoger el color rojo de la manzana), el fondo cambiará a **Victoria**, lo que indica que el juego ha sido exitoso y el script deja de ejecutarse.

  .. image:: img/apple_touch_red.png

Programación completa. Ahora puedes hacer clic en la bandera verde para ejecutar el script y ver si logra el efecto deseado.


  .. raw:: html

    <video loop autoplay muted style = "max-width:70%">
        <source src="../_static/video/sc_eat_apple.mp4"  type="video/mp4">
        Your browser does not support the video tag.
    </video>
