
Diversión 7 Toca la Baldosa Negra
==========================================

Muchos de ustedes conocen el popular juego móvil donde los jugadores tocan las baldosas negras para sumar puntos mientras evitan las blancas. Traemos este adictivo desafío utilizando dos módulos de evitación de obstáculos. Cuando su mano bloquea uno de los módulos IR, se registra un toque en el escenario.

Si un toque cae sobre una baldosa negra, se suma un punto; tocar una baldosa blanca resta un punto. Los jugadores deben decidir rápidamente si tocar sobre el módulo IR izquierdo o derecho según la posición de las baldosas negras.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_tap_black_tile.mp4"  type="video/mp4">
      Su navegador no soporta la etiqueta de video.
   </video>

A continuación se presentan los pasos para implementar el proyecto. Se recomienda seguir estos pasos inicialmente, y una vez familiarizado, puede modificar los efectos según lo desee.

1. Dibujar un objeto **Tile**
-----------------------------------

Se utiliza un objeto **Tile** para lograr el efecto de baldosas blancas y negras alternadas que se mueven hacia abajo; en la versión para teléfono móvil de este juego, generalmente hay 4 columnas, aquí solo hacemos dos columnas.


* Elimine el objeto predeterminado, toque el icono **Agregar objeto** y seleccione **Pintar**.

  .. image:: img/tile_paint_tile1.png

* A continuación, vaya a la página **Disfraces** y use la herramienta **Rectángulo** para dibujar un rectángulo con borde gris y relleno blanco.

  .. image:: img/tile_paint_tile2.png
    :width: 90%

* Seleccione el rectángulo y haga clic en **Copiar** -> **Pegar** para hacer un rectángulo idéntico, luego mueva los dos rectángulos a una posición alineada.

  .. image:: img/tile_paint_tile3.png
    :width: 90%

* Seleccione uno de los rectángulos y elija un color de relleno negro.

  .. image:: img/tile_paint_tile4.png
    :width: 90%

* Ahora seleccione ambos rectángulos y muévalos para que sus puntos centrales coincidan con el centro del lienzo.

  .. image:: img/tile_paint_tile5.png
    :width: 90%

* Duplique el disfraz1, alternando los colores de relleno de los dos rectángulos. Por ejemplo, el color de relleno del disfraz1 es blanco a la izquierda y negro a la derecha, y el color de relleno del disfraz2 es negro a la izquierda y blanco a la derecha.

  .. image:: img/tile_paint_tile6.png
    :width: 90%

* Vuelva a la página **Código** y establezca el nombre del objeto como **Tile**.

  .. image:: img/tile_paint_tile7.png

2. Programar el objeto **Tile**
-------------------------------------

* Primero, establezca la posición inicial del objeto **Tile** para que esté en la parte superior del escenario.

  .. image:: img/tile_script_tile1.png

* Cree una variable - **blocks** y asígnele un valor inicial para determinar el número de veces que aparecerá el objeto **Tile**. Use el bloque [repetir hasta] para que la variable **blocks** disminuya gradualmente hasta que **blocks** sea 0. Durante este tiempo, haga que el objeto **Tile** cambie su disfraz aleatoriamente. Después de hacer clic en la bandera verde, verá el objeto **Tile** en el escenario cambiando rápidamente de disfraces.

  .. image:: img/tile_script_tile2.png

* Cree clones del objeto **Tile** mientras la variable **blocks** disminuye, y detenga la ejecución del script cuando blocks sea 0. Aquí se usan dos bloques [esperar () segundos], el primero para limitar el intervalo entre los clones de **Tile** y el segundo para permitir que la variable blocks disminuya a 0 sin detener el programa inmediatamente, dando tiempo suficiente al último objeto tile para moverse.

  .. image:: img/tile_script_tile3.png

* Ahora programe el clon del objeto **Tile** para que se mueva lentamente hacia abajo y elimínelo cuando llegue a la parte inferior del escenario. El cambio en la coordenada y afecta la velocidad de caída; cuanto mayor sea el valor, más rápida será la velocidad de caída.

  .. image:: img/tile_script_tile4.png

* Oculte el cuerpo y muestre el clon.

  .. image:: img/tile_script_tile5.png

3. Programar el fondo
-------------------------------

En el fondo, lea los valores de los 2 módulos IR y realice las acciones correspondientes.

* Cuando se haga clic en la bandera verde, establezca la variable **count** en 0.

  .. image:: img/tile_script_backdrop.png
    :width: 90%

* Si el módulo de evitación de obstáculos IR izquierdo detecta su mano, difunda un mensaje - **left**.

  .. image:: img/tile_script_backdrop1.png


* Si el módulo de evitación IR derecho detecta su mano, difunda un mensaje - **right**.

  .. image:: img/tile_script_backdrop2.png


4. Dibujar el objeto **Left IR**
-----------------------------------
Se utiliza un objeto **Left IR** para lograr el efecto de clic; cuando el módulo IR izquierdo detecta su mano, enviará un mensaje - **left** al objeto **Left IR**, permitiéndole comenzar a funcionar. Si toca la baldosa negra en el escenario, la puntuación aumentará en 1; de lo contrario, la puntuación disminuirá en 1.


* Nuevamente, toque el icono **Agregar objeto** y seleccione **Pintar**.

  .. image:: img/tile_paint_ir1.png

* Vaya a la página **Disfraces**, seleccione el color de relleno (cualquier color excepto blanco y negro) y dibuje un círculo.

  .. image:: img/tile_paint_ir2.png

* Vuelva a la página **Código** y cambie el nombre del objeto a **Left IR**.

  .. image:: img/tile_paint_ir3.png

5. Programar el objeto **Left IR**
------------------------------------------

* Ahora comience a programar el objeto **Left IR**. Cuando se haga clic en la bandera verde, primero oculte el objeto.

  .. image:: img/tile_script_ir1.png

* Cuando se reciba el mensaje - **left** (el módulo receptor IR izquierdo detecta un obstáculo), muestre el objeto, establezca su tamaño al 100%, y luego redúzcalo en intervalos de 10 usando un bloque [Repetir] antes de ocultarlo nuevamente. Esto le da al objeto un efecto de expansión y contracción.

  .. image:: img/tile_script_ir2.png

* Luego determine si se toca el bloque negro del objeto **Tile**, y si es así, aumente la variable **count** en 1, de lo contrario disminuya en 1.

  .. image:: img/tile_script_ir3.png

.. note::

    Necesita hacer que el objeto **Tile** aparezca en el escenario y luego absorber el color del bloque negro en el objeto **Tile**.

    .. image:: img/tile_script_ir4.png

6. Objeto **Right IR**
-------------------------------------
La función del objeto **Right IR** es básicamente la misma que la de **Left IR**, excepto que recibe información **Right**.


* Ahora duplique el objeto **Left IR** y cambie el nombre del objeto a **Right IR**.

  .. image:: img/tile_paint_ir4.png

* Luego cambie el mensaje recibido a - **right**.

    .. image:: img/tile_script_ir5.png

7. Ejecutar el script
---------------------------------

* Ahora ajuste las posiciones y tamaños de los tres objetos.

  * Arrastre el objeto **Tile** a la parte inferior del escenario y establezca su posición x en 0.
  * Mueva el objeto **Left IR** al marco izquierdo. Debe ir a la página **Disfraces** para reducir el tamaño del objeto solo al 50% del tamaño del marco.
  * De manera similar, mueva el objeto **Right IR** al marco derecho. Debe ir a la página **Disfraces** para reducir el tamaño del objeto solo al 50% del tamaño del marco.
  * Asegúrese de que los objetos **Left IR** y **Right IR** estén encima del objeto **Tile**.

  .. image:: img/tile_paint_ir5.png

* Ahora toda la programación está lista, y puede hacer clic en la bandera verde para ejecutar el script.

  .. raw:: html

    <video loop autoplay muted style = "max-width:70%">
        <source src="../../_static/video/sc_tap_black_tile.mp4"  type="video/mp4">
        Su navegador no soporta la etiqueta de video.
    </video>
