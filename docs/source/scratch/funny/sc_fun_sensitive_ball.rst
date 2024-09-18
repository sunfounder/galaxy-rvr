.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

Extensión 6 Bola Sensible a la Distancia
===========================================================

En este proyecto, utilizamos un módulo ultrasónico para controlar el movimiento vertical de una bola en el escenario. Al hacer clic en la bandera verde, coloca tu mano sobre el módulo ultrasónico. La bola ascenderá si la distancia entre tu mano y el módulo es menor a 15 cm; de lo contrario, descenderá. Cuando la bola toque una línea, se activará un sonido agradable y efectos de estrellas brillando.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Sigue estos pasos para configurar el proyecto, y siéntete libre de ajustar los efectos a tu gusto una vez que te hayas acostumbrado a su funcionamiento.

1. Seleccionar Sprites
--------------------------

* Elimina el sprite predeterminado y selecciona los sprites **Ball**, **Bowl** y **Star**.

  .. image:: img/ball_choose_sprite.png

* Coloca el sprite **Bowl** en el centro inferior del escenario y aumenta su tamaño.

  .. image:: img/ball_set_bowl.png

* Coloca el sprite **Ball** directamente sobre el sprite **Bowl**, configurando su dirección a 0 para permitir el movimiento vertical.

  .. image:: img/ball_set_ball.png

* Ajusta el tamaño del sprite **Star** y configura su dirección a 180 para que caiga hacia abajo. Esto se puede alterar a diferentes ángulos si lo prefieres.

  .. image:: img/ball_set_star.png

* Añade el fondo **Stars** para mejorar la ambientación.

  .. image:: img/ball_select_backdrop.png

2. Dibujar un Sprite **Line**
---------------------------------

* Ahora añade un sprite de **Line**.

  .. image:: img/ball_select_line.png

* Ve a la página de **Disfraces** del sprite **Line**.

  .. image:: img/ball_open_cos.png
    :width: 90%

* Reduce ligeramente el ancho de la línea roja en el lienzo, duplícala cuatro veces y alinea estas líneas.

  .. image:: img/ball_copy_line.png
    :width: 90%

* Colorea cada línea de manera diferente. Selecciona una línea, usa la herramienta **Rellenar** y elige un color.

  .. image:: img/ball_set_bk_color.png
    :width: 90%

* Aplica este método para colorear todas las líneas según corresponda.

  .. image:: img/ball_select_line_color.png
    :width: 90%

* Regresa a la página **Código** y posiciona el sprite **Line** en la parte superior del escenario.

  .. image:: img/ball_line_position.png

3. Programación del Sprite **Ball**
----------------------------------------

Aquí programaremos el sprite **Ball** para que suba o baje en función de la distancia detectada por el módulo ultrasónico, con una restricción de movimiento para simular que aterriza sobre el sprite **Bowl**.

* Al hacer clic en la bandera verde, establece la posición inicial del sprite **Ball**.

  .. image:: img/ball_script_ball1.png

* Usa un bloque [si no] para verificar si la distancia es menor a 15. Si es cierto, mueve el sprite **Ball** hacia arriba 10 pasos, dado que su dirección está configurada en 0.

  .. image:: img/ball_script_ball3.png

* De lo contrario, deja que el sprite **Ball** caiga, limitando su coordenada Y a un mínimo de -100, ajustable para que parezca que aterriza sobre el sprite **Bowl**.

  .. image:: img/ball_script_ball4.png

* Programa la interacción para que, cuando el sprite **Ball** toque el sprite **Line**, registre su posición Y en la variable **ball_coor** y envíe un mensaje **bling**.

  .. image:: img/ball_script_ball5.png

4. Programación del Sprite **Star**
----------------------------------------

* Inicialmente, oculta el sprite **Star** cuando se haga clic en la bandera verde. Al recibir el mensaje **Bling**, clona el sprite **Star**.

  .. image:: img/ball_script_star1.png

* Configura la posición del clon y los efectos de sonido para sincronizar con la posición del sprite **Ball**.

  .. image:: img/ball_script_star2.png

* Permite que gire aleatoriamente entre -80 y 80 grados.

  .. image:: img/ball_script_star3.png

* Ajusta la apariencia y el comportamiento del sprite **Star** según sea necesario para mejorar el efecto visual.

  .. image:: img/ball_script_star4.png

La programación está completa. Haz clic en la bandera verde para ejecutar el script y ver si cumple con tus expectativas.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_sensitive_ball.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>
