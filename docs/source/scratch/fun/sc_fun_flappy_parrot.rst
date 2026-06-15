.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Fun2 Loro Aleteador
==============================

En este proyecto, utilizamos un módulo ultrasónico para jugar un juego de loro aleteador.

Después de iniciar el script, la caña de bambú verde (Paddle) se moverá de derecha a izquierda a una altura aleatoria. Para controlar el loro, coloque su mano sobre el módulo ultrasónico. Si la distancia entre su mano y el módulo es menor a 10 cm, el loro ascenderá; de lo contrario, descenderá. Debe gestionar esta distancia cuidadosamente para ayudar al Loro a pasar la caña de bambú verde. El contacto con la caña de bambú termina el juego.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4" type="video/mp4">
      Su navegador no admite la etiqueta de video.
   </video>

A continuación se presentan los pasos para implementar el proyecto. Se recomienda seguir estos pasos inicialmente, y una vez familiarizado, puede alterar los efectos según lo desee.

1. Agregar Objetos
---------------------------

* Elimine el objeto predeterminado y use el botón **Elegir un Objeto** para agregar el objeto **Parrot**. Establezca su tamaño al 50% y colóquelo en la esquina inferior izquierda.

  .. image:: img/parrot_choose_parrot.png

* Agregue el objeto **Paddle**, establezca su tamaño al 150%, gírelo 180 grados y colóquelo en la esquina superior derecha.

  .. image:: img/parrot_choose_paddle.png

* Vaya a la página de **Disfraces** del objeto **Paddle**, seleccione **Paddle** en el lienzo y luego haga clic en la herramienta **Contorno**.

  .. image:: img/parrot_set_parrot1.png
    :width: 90%

* Cambie el efecto de contorno al modo de relleno completo y use la herramienta de eliminación para eliminarlo.

  .. image:: img/parrot_set_parrot2.png
    :width: 90%

2. Programación del Objeto **Parrot**
---------------------------------------------

Programe el objeto **Parrot** para simular su vuelo, con ajustes de altitud basados en la distancia de detección del módulo ultrasónico.

* Cuando se haga clic en la bandera verde, cambie el disfraz cada 0.2 segundos para mantener la apariencia de vuelo.

  .. image:: img/parrot_script_parrot1.png

* Si la distancia de detección ultrasónica es menor a 10 cm, aumente la coordenada y en 50, haciendo que el **Parrot** ascienda. De lo contrario, disminuya la coordenada y en 40, haciendo que el **Parrot** descienda.

  .. image:: img/parrot_script_parrot3.png

* Si el objeto **Parrot** entra en contacto con el objeto **Paddle**, el juego termina y el script deja de ejecutarse.

  .. image:: img/parrot_script_parrot4.png

3. Programación del Objeto **Paddle**
-----------------------------------------------

Programe el objeto **Paddle** para que aparezca aleatoriamente en el escenario.

* Oculte el objeto **Paddle** cuando se haga clic en la bandera verde y, simultáneamente, cree un clon de sí mismo. El bloque [`crear clon de <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_] controla este proceso de clonación.

  .. image:: img/parrot_script_paddle1.png

* Establezca la posición del clon con la coordenada x en 220 (extremo derecho) y la coordenada y aleatoriamente entre (-125 y 125).

  .. image:: img/parrot_script_paddle2.png

* Use el bloque [repetir] para disminuir gradualmente su coordenada x, haciendo que el clon se mueva lentamente de derecha a izquierda hasta que desaparezca.

  .. image:: img/parrot_script_paddle3.png

* Vuelva a clonar un nuevo objeto **Paddle** y elimine el clon anterior.

  .. image:: img/parrot_script_paddle4.png

La programación está completa. Ahora puede hacer clic en la bandera verde para ejecutar el script y ver si logra el efecto deseado.


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4"  type="video/mp4">
      Su navegador no admite la etiqueta de video.
   </video>
