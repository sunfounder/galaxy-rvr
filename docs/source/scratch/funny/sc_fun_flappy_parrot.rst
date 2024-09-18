.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _sc_parrot:

Extensión 2 Loro Volador
==============================

En este proyecto, utilizamos un módulo ultrasónico para jugar al juego del loro volador.

Después de iniciar el script, el bambú verde (Paddle) se moverá de derecha a izquierda a una altura aleatoria. Para controlar al loro, coloca tu mano sobre el módulo ultrasónico. Si la distancia entre tu mano y el módulo es menor a 10 cm, el loro ascenderá; de lo contrario, descenderá. Debes gestionar esta distancia con cuidado para ayudar al loro a pasar el bambú verde. El contacto con el bambú terminará el juego.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

A continuación se muestran los pasos para implementar el proyecto. Se recomienda seguir estos pasos inicialmente, y una vez familiarizado, puedes alterar los efectos como desees.

1. Añadir sprites
---------------------------

* Elimina el sprite predeterminado y utiliza el botón **Elegir un Sprite** para agregar el sprite de **Loro**. Ajusta su tamaño al 50% y colócalo en la esquina inferior izquierda.

  .. image:: img/parrot_choose_parrot.png

* Agrega el sprite de **Paddle**, ajusta su tamaño al 150%, gíralo a 180 grados y colócalo en la esquina superior derecha.

  .. image:: img/parrot_choose_paddle.png
 
* Navega a la página de **Disfraces** del sprite **Paddle**, selecciona el **Paddle** en el lienzo, y luego haz clic en la herramienta **Contorno**.

  .. image:: img/parrot_set_parrot1.png
    :width: 90%

* Cambia el efecto de contorno a modo de relleno completo y usa la herramienta de eliminación para quitarlo.

  .. image:: img/parrot_set_parrot2.png
    :width: 90%

2. Programación del sprite **Loro**
---------------------------------------------

Programa el sprite **Loro** para simular su vuelo, ajustando la altitud en función de la distancia detectada por el módulo ultrasónico.

* Al hacer clic en la bandera verde, cambia el disfraz cada 0.2 segundos para mantener la apariencia de vuelo.

  .. image:: img/parrot_script_parrot1.png

* Si la distancia detectada por el ultrasónico es menor a 10 cm, aumenta la coordenada y en 50, haciendo que el **Loro** ascienda. De lo contrario, disminuye la coordenada y en 40, haciendo que el **Loro** descienda.

  .. image:: img/parrot_script_parrot3.png

* Si el sprite **Loro** entra en contacto con el sprite **Paddle**, el juego termina y el script deja de ejecutarse.

  .. image:: img/parrot_script_parrot4.png

3. Programación del sprite **Paddle**
-----------------------------------------------

Programa el sprite **Paddle** para que aparezca aleatoriamente en el escenario.

* Oculta el sprite **Paddle** cuando se haga clic en la bandera verde y simultáneamente crea un clon de sí mismo. El bloque [`crear clon de <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_] controla este proceso de clonación.

  .. image:: img/parrot_script_paddle1.png

* Establece la posición del clon con la coordenada x en 220 (extremo derecho) y la coordenada y aleatoriamente entre (-125 y 125).

  .. image:: img/parrot_script_paddle2.png

* Usa el bloque [repetir] para disminuir gradualmente su coordenada x, haciendo que el clon se mueva lentamente de derecha a izquierda hasta que desaparezca.

  .. image:: img/parrot_script_paddle3.png

* Clona de nuevo un nuevo sprite **Paddle** y elimina el clon anterior.

  .. image:: img/parrot_script_paddle4.png

La programación está completa. Ahora puedes hacer clic en la bandera verde para ejecutar el script y ver si logra el efecto deseado.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_flappy_parrot.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>
