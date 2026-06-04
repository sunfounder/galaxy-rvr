Diversión4 Comer Manzana
===========================

En este proyecto, utilizamos un módulo infrarrojo de evitación de obstáculos para guiar al objeto Beetle hacia una manzana.

Después de hacer clic en la bandera verde, pasa rápidamente tu mano sobre el módulo de evitación de obstáculos izquierdo (bloquea y retira rápidamente tu mano del frente del módulo) para iniciar la rotación de Beetle. Una vez que se alinee correctamente, pasa tu mano sobre el módulo nuevamente para mover a Beetle hacia adelante, asegurándose de que evite las líneas negras en el mapa. Si son necesarios ajustes o giros, desliza tu mano sobre el módulo otra vez para rotar a Beetle al ángulo deseado. Repite estos pasos hasta que el objeto Beetle llegue a la manzana.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_eat_apple.mp4" type="video/mp4">
      Su navegador no soporta la etiqueta de video.
   </video>

A continuación se presentan los pasos para implementar el proyecto. Se recomienda seguirlos inicialmente y, una vez familiarizado, puedes modificar los efectos como desees.

1. Dibujar el fondo **Maze**
-------------------------------------

Aquí, dibujaremos un fondo de mapa con una manzana roja.

* Primero, selecciona un fondo en blanco.

  .. image:: img/apple_click_backdrop.png

* Haz clic en **Backdrops** para comenzar a dibujar el fondo del mapa. Primero, renombra el fondo a **Maze**.

  .. image:: img/apple_open_backdrop.png

* Usa la herramienta **Line**, establece el color en negro, ancho en 4, y comienza a dibujar el mapa. Puedes dise?ar tu mapa según tus ideas; no tiene que ser como el mío.

  .. image:: img/apple_paint_bk_maze2.png
    :width: 90%

* Ahora, dibuja una manzana. Usando la herramienta **Circle**, dibuja una elipse o círculo en rojo sin contorno.

  .. image:: img/apple_paint_bk_maze3.png

  .. note::

    Puedes eliminar el contorno haciendo clic en la ventana **Outline** y luego usando la herramienta **Remove**.

    .. image:: img/apple_paint_bk_maze4.png

* Selecciona la herramienta **Brush** y elige un color y ancho para terminar de dibujar la manzana.

  .. image:: img/apple_paint_bk_maze5.png

2. Dibujar el fondo **Win**
---------------------------------

Ahora comienza a dibujar; consulta los pasos a continuación, o dibuja tu fondo basándote en tu creatividad, asegurándote de que represente una victoria.

* Haz clic en el botón para agregar un nuevo fondo en la parte inferior, selecciona **Paint**, y nombra este fondo **Win**.

  .. image:: img/apple_paint_bk_win.png

* Usando la herramienta **Circle**, dibuja una elipse en rojo sin contorno.

  .. image:: img/apple_paint_bk_win2.png
    :width: 90%

* Luego, usa la herramienta **Text** para escribir "WIN!". Establece el color de fuente en negro y ajusta el tama?o y la posición del texto.

  .. image:: img/apple_paint_bk_cus2.png
    :width: 90%

3. Programación del fondo **Maze**
--------------------------------------

Asegúrate de que el fondo cambie a **Maze** cada vez que comience el juego.

.. image:: img/apple_switch_backdrop.png
  :width: 90%

4. Seleccionar el objeto **Beetle**
-----------------------------------------

* Elimina el objeto predeterminado y selecciona el objeto **Beetle**.

  .. image:: img/apple_choose_sprite.png

* Coloca el objeto **Beetle** en la entrada del fondo **Maze**, anotando los valores de coordenadas x, y en este punto, y redimensiona el objeto al 40%.

  .. image:: img/apple_place_sprite.png

5. Programación del objeto **Beetle**
-----------------------------------------------

Ahora, escribe un script para el objeto **Beetle** para que avance y cambie de dirección bajo el control del módulo de evitación de obstáculos izquierdo.

* Cuando se haga clic en la bandera verde, establece el ángulo de **Beetle** a 90, y la posición a (-124, -113), o usa los valores de coordenadas de tu colocación.

  .. image:: img/apple_point_in.png
    :width: 90%

* Crea la variable **flag** y establece su valor inicial en -1.

  .. image:: img/apple_vable_flag.png

A continuación, dentro del bloque [por siempre], usa cuatro bloques [si] para gestionar diferentes escenarios.

* Si el infrarrojo izquierdo está bloqueado, usa el bloque [`mod <https://en.scratch-wiki.info/wiki/Boolean_Block>`_] para alternar la variable **flag** entre 0 y 1 (alternando entre 0 para esta pulsación y 1 para la siguiente).

   .. image:: img/apple_read_ir.png

* Si la bandera es 0 (el infrarrojo izquierdo está bloqueado), deja que el objeto **Beetle** gire en sentido horario. Si la bandera es 1 (el infrarrojo izquierdo se bloquea nuevamente), **Beetle** avanza. De lo contrario, continúa girando en sentido horario.

  .. image:: img/apple_read_flag.png

* Si el objeto **Beetle** toca el negro (la línea negra en el fondo **Maze**), el juego termina y el script deja de ejecutarse.

  .. image:: img/apple_touch_black1.png

  .. note::

    Haz clic en el área de color en el bloque [Tocar color] y selecciona la herramienta cuentagotas para recoger el color de la línea negra en el escenario. Si eliges un negro al azar, este bloque [Tocar color] no funcionará correctamente.

    .. image:: img/apple_touch_black.png

* Si **Beetle** toca el rojo (también usa la herramienta cuentagotas para recoger el color rojo de la manzana), el fondo cambia a **Win**, lo que indica que el juego ha sido exitoso, y el script deja de ejecutarse.

  .. image:: img/apple_touch_red.png

Programación completa, ahora puedes hacer clic en la bandera verde para ejecutar el script y ver si logra el efecto deseado.


  .. raw:: html

    <video loop autoplay muted style = "max-width:70%">
        <source src="../../_static/video/sc_eat_apple.mp4"  type="video/mp4">
        Su navegador no soporta la etiqueta de video.
    </video>