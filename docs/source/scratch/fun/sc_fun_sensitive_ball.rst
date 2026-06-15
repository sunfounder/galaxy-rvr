.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Diversión 6: Pelota Sensible a la Distancia
===========================================================

En este proyecto, utilizamos un módulo ultrasónico para controlar el movimiento vertical de una pelota en el escenario. Al hacer clic en la bandera verde, coloca tu mano sobre el módulo ultrasónico. La pelota ascenderá si la distancia entre tu mano y el módulo es menor de 15 cm; de lo contrario, descenderá. Cuando la pelota entre en contacto con una línea, se reproducirá un sonido agradable y se activarán efectos de estrellas centelleantes.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4" type="video/mp4">
      Su navegador no soporta la etiqueta de video.
   </video>

Sigue estos pasos para configurar el proyecto, y no dudes en ajustar los efectos a tu gusto una vez que te hayas familiarizado con su funcionamiento.

1. Seleccionar Sprites
--------------------------

* Elimina el sprite predeterminado y selecciona los sprites **Ball**, **Bowl** y **Star**.

  .. image:: img/ball_choose_sprite.png

* Coloca el sprite **Bowl** en la parte inferior central del escenario y aumenta su tamaño.

  .. image:: img/ball_set_bowl.png

* Coloca el sprite **Ball** directamente encima del sprite **Bowl**, estableciendo su dirección en 0 para permitir el movimiento vertical.

  .. image:: img/ball_set_ball.png

* Ajusta el tamaño del sprite **Star** y establece su dirección en 180 para que caiga hacia abajo. Esto se puede modificar a diferentes ángulos si se prefiere.

  .. image:: img/ball_set_star.png

* Añade el fondo **Stars** para dar más ambiente.

  .. image:: img/ball_select_backdrop.png

2. Dibujar un sprite **Line**
-------------------------------

* Ahora añade un sprite **Line**.

  .. image:: img/ball_select_line.png

* Navega a la página de **Disfraces** del sprite **Line**.

  .. image:: img/ball_open_cos.png
    :width: 90%

* Reduce ligeramente el ancho de la línea roja en el lienzo, duplícala cuatro veces y alinea estas líneas.

  .. image:: img/ball_copy_line.png
    :width: 90%

* Colorea cada línea de forma diferente. Selecciona una línea, usa la herramienta **Rellenar** y elige un color.

  .. image:: img/ball_set_bk_color.png
    :width: 90%

* Aplica este método para colorear todas las líneas en consecuencia.

  .. image:: img/ball_select_line_color.png
    :width: 90%

* Vuelve a la página de **Código** y coloca el sprite **Line** en la parte superior del escenario.

  .. image:: img/ball_line_position.png

3. Programar el sprite **Ball**
-------------------------------------

Aquí, programamos el sprite **Ball** para que se mueva hacia arriba o hacia abajo según la distancia detectada por el módulo ultrasónico, con una restricción de movimiento para simular que aterriza en el sprite **Bowl**.

* Al hacer clic en la bandera verde, establece la posición inicial del sprite **Ball**.

  .. image:: img/ball_script_ball1.png

* Usa un bloque [si entonces/si no] para comprobar si la distancia es menor de 15. Si es verdadero, mueve el sprite **Ball** hacia arriba 10 pasos, ya que su dirección está establecida en 0.

  .. image:: img/ball_script_ball3.png

* De lo contrario, deja que el sprite **Ball** caiga, limitando su coordenada Y a un mínimo de -100, ajustable para que parezca que está aterrizando en el sprite **Bowl**.

  .. image:: img/ball_script_ball4.png

* Programa la interacción donde el sprite **Ball**, al tocar el sprite **Line**, registra su posición Y en la variable **ball_coor** y envía un mensaje **bling**.

  .. image:: img/ball_script_ball5.png

4. Programar el sprite **Star**
------------------------------------

* Inicialmente oculta el sprite **Star** al hacer clic en la bandera verde. Al recibir el mensaje **Bling**, clona el sprite **Star**.

  .. image:: img/ball_script_star1.png

* Establece la posición y los efectos de sonido del clon para sincronizarlos con la posición del sprite **Ball**.

  .. image:: img/ball_script_star2.png

* Permítele rotar aleatoriamente entre -80 y 80 grados.

  .. image:: img/ball_script_star3.png

* Ajusta la apariencia y el comportamiento del sprite **Star** según sea necesario para mejorar el efecto visual.

  .. image:: img/ball_script_star4.png

La programación está completa. Haz clic en la bandera verde para ejecutar el script y comprueba si cumple con tus expectativas.


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4"  type="video/mp4">
      Su navegador no soporta la etiqueta de video.
   </video>
