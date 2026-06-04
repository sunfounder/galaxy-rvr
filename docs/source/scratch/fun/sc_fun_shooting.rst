
Fun3 Shooting
====================================

¿Alguna vez has visto esos emocionantes juegos de tiro en la televisión, donde los participantes apuntan con precisión a la diana para sumar puntos? Ahora puedes experimentar la misma adrenalina aquí mismo en Scratch. En nuestro juego de tiro interactivo, usarás el sprite Crosshair para apuntar y acertar lo más cerca posible del centro, maximizando tu puntuación con cada disparo preciso.

Para comenzar, haz clic en la bandera verde. Controlarás tus disparos usando el innovador módulo de Evitación de Obstáculos. ¿Listo para poner a prueba tu puntería y reflejos? Veamos cómo puntúas.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4" type="video/mp4">
      Tu navegador no soporta la etiqueta de video.
   </video>

A continuación se presentan los pasos para implementar el proyecto. Se recomienda seguir estos pasos inicialmente y, una vez familiarizado, puedes modificar los efectos según lo desees.

1. Pintar el sprite **Crosshair**
----------------------------------------------

* Elimina el sprite predeterminado, selecciona el botón **Sprite** y haz clic en **Paint**.

  .. image:: img/shooting_paint_cross.png

* Ve a la página **Costumes**. Usa la herramienta **Circle**, elimina el color de relleno y configura el color y grosor del contorno.

  .. image:: img/shooting_paint_cross1.png

* Dibuja un círculo con la herramienta **Circle**. Después de dibujarlo, usa la herramienta **Select** para alinear el centro del círculo con el centro del lienzo.

  .. image:: img/shooting_paint_cross2.png

* Con la herramienta **Line**, dibuja una cruz dentro del círculo.

  .. image:: img/shooting_paint_cross3.png

* Finalmente, regresa a la página **Code** y renombra el sprite como "Crosshair".

  .. image:: img/shooting_paint_cross4.png

2. Pintar el sprite **Target**
----------------------------------------

* De manera similar, selecciona el botón **Sprite** y haz clic en **Paint**.

  .. image:: img/shooting_paint_target1.png

* Ingresa a la página **Costumes**. Usa la herramienta **Circle**, selecciona color negro, elimina el Contorno y pinta un círculo grande.

  .. image:: img/shooting_paint_target3.png
    :width: 90%

* Dibuja círculos adicionales usando el mismo método, cada uno de un color diferente. Ajusta la posición de los círculos superpuestos usando la herramienta **Forward** o **Backward** para asegurar que los orígenes de todos los círculos estén alineados con el centro del lienzo.

  .. image:: img/shooting_paint_target4.png
    :width: 90%

* Regresa a la página **Code** y renombra este sprite como "Target".

  .. image:: img/shooting_paint_target5.png

3. Agregar un fondo
--------------------------

* Agrega un fondo adecuado que preferiblemente no sea muy colorido y que no coincida con los colores del sprite **Target**. Yo he elegido el fondo **Wall1**.

  .. image:: img/shooting_choose_backdrop.png

* Ajusta las posiciones y tamaños de los sprites **Target** y **Crosshair**.

  .. note::

    * Asegúrate de que el sprite **Crosshair** esté en una capa superior al sprite **Target** moviendo primero el sprite **Target** y luego el **Crosshair**.
    * El **Crosshair** debe ser más pequeño que el espacio entre los anillos de color del sprite **Target**.

  .. image:: img/shooting_choose_backdrop1.png

4. Programar el sprite **Crosshair**
---------------------------------------

* Aleatoriza la posición y el tamaño del sprite **Crosshair**, permitiendo que se mueva de forma impredecible.

  .. image:: img/shooting_script_cross.png

* Cuando el módulo de evasión de obstáculos izquierdo esté bloqueado, se transmite un mensaje - disparo.

  .. image:: img/shooting_script_cross1.png

* Cuando se recibe el mensaje **shooting**, el sprite deja de moverse y se reduce gradualmente, simulando el disparo de una bala.

  .. image:: img/shooting_script_cross2.png

* Usa el bloque [Touch color ()] para determinar la posición del disparo.

  .. image:: img/shooting_script_cross3.png
    :width: 90%

* Reporta una puntuación de 10 si el disparo cae dentro del círculo amarillo.

  .. image:: img/shooting_script_cross4.png

* Reporta una puntuación de 9 si el disparo cae dentro del círculo rojo. De manera similar, usa el bloque [Touch color ()] para que coincida con el color del círculo rojo.

  .. image:: img/shooting_script_cross5.png
    :width: 90%

* Usa el mismo método para confirmar el lugar donde cae la bala. Si no cae sobre el sprite **Target**, indica un fallo.

  .. image:: img/shooting_script_cross6.png

La programación está completa. Ahora puedes hacer clic en la bandera verde para ejecutar el script y ver si se logra el efecto deseado.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4"  type="video/mp4">
      Tu navegador no soporta la etiqueta de video.
   </video>
