.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _sc_tap_tile:

Extensión 7 Toca el Azulejo Negro
==========================================

Muchos de ustedes están familiarizados con el popular juego móvil donde los jugadores deben tocar los azulejos negros para ganar puntos mientras evitan los azulejos blancos. Estamos trayendo este adictivo desafío usando dos módulos de evitación de obstáculos. Cuando tu mano bloquea uno de los módulos IR, se registra un toque en el escenario.

Si el toque cae sobre un azulejo negro, ganas un punto; si tocas un azulejo blanco, se te resta un punto. Los jugadores deben decidir rápidamente si tocar sobre el módulo IR izquierdo o derecho según la posición de los azulejos negros.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_tap_black_tile.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

A continuación se detallan los pasos para implementar el proyecto. Se recomienda seguir estos pasos inicialmente, y una vez familiarizado, puedes modificar los efectos a tu gusto.

1. Pinta un sprite de **Azulejo**
------------------------------------

Un sprite de **Azulejo** se usa para lograr el efecto de alternar azulejos blancos y negros que se mueven hacia abajo; en la versión de este juego para teléfonos móviles, generalmente hay 4 columnas, aquí solo usamos dos.

* Elimina el sprite predeterminado, toca el ícono de **Añadir Sprite**, selecciona **Pintar**.

  .. image:: img/tile_paint_tile1.png

* Luego, ve a la página de **Disfraces** y usa la herramienta **Rectángulo** para dibujar un rectángulo con un borde gris y un relleno blanco.

  .. image:: img/tile_paint_tile2.png
    :width: 90%

* Selecciona el rectángulo y haz clic en **Copiar** -> **Pegar** para hacer un rectángulo idéntico, luego mueve los dos rectángulos a una posición alineada.

  .. image:: img/tile_paint_tile3.png
    :width: 90%

* Selecciona uno de los rectángulos y elige un color de relleno negro.

  .. image:: img/tile_paint_tile4.png
    :width: 90%

* Ahora selecciona ambos rectángulos y muévelos para que sus puntos centrales coincidan con el centro del lienzo.

  .. image:: img/tile_paint_tile5.png
    :width: 90%

* Duplica el disfraz1, alternando los colores de relleno de los dos rectángulos. Por ejemplo, el color de relleno del disfraz1 es blanco a la izquierda y negro a la derecha, y el color de relleno del disfraz2 es negro a la izquierda y blanco a la derecha.

  .. image:: img/tile_paint_tile6.png
    :width: 90%

* Regresa a la página de **Código** y asigna al sprite el nombre **Azulejo**.

  .. image:: img/tile_paint_tile7.png

2. Programando el sprite **Azulejo**
----------------------------------------

* Primero, ajusta la posición inicial del sprite **Azulejo** para que esté en la parte superior del escenario.

  .. image:: img/tile_script_tile1.png

* Crea una variable - **bloques** y asígnale un valor inicial para determinar cuántas veces aparecerá el sprite **Azulejo**. Usa el bloque [repetir hasta] para hacer que la variable **bloques** disminuya gradualmente hasta que **bloques** sea 0. Durante este tiempo, haz que el sprite **Azulejo** cambie aleatoriamente su disfraz. Después de hacer clic en la bandera verde, verás que el sprite **Azulejo** en el escenario cambia rápidamente de disfraz.

  .. image:: img/tile_script_tile2.png

* Crea clones del sprite **Azulejo** mientras la variable **bloques** disminuye, y detén el script cuando **bloques** llegue a 0. Se usan dos bloques [esperar () segundos] aquí, el primero para limitar el intervalo entre los clones de **Azulejo** y el segundo para permitir que la variable **bloques** disminuya a 0 sin detener el programa de inmediato, dando tiempo suficiente al último sprite de azulejo para moverse.

  .. image:: img/tile_script_tile3.png

* Ahora programa el clon del sprite **Azulejo** para que se mueva hacia abajo lentamente y se elimine cuando llegue al fondo del escenario. El cambio en la coordenada y afecta la velocidad de caída, cuanto mayor sea el valor, más rápida será la caída.

  .. image:: img/tile_script_tile4.png

* Oculta el cuerpo y muestra el clon.

  .. image:: img/tile_script_tile5.png

3. Programando el fondo
-------------------------------

En el fondo, lee los valores de los 2 módulos IR y realiza las acciones correspondientes.

* Cuando se hace clic en la bandera verde, ajusta la variable **cuenta** a 0.

  .. image:: img/tile_script_backdrop.png
    :width: 90%

* Si el módulo IR izquierdo detecta tu mano, transmite un mensaje - **izquierda**. 

  .. image:: img/tile_script_backdrop1.png

* Si el módulo IR derecho detecta tu mano, transmite un mensaje - **derecha**.

  .. image:: img/tile_script_backdrop2.png


4. Pinta el sprite **IR Izquierda**
-------------------------------------

Un sprite **IR Izquierda** se usa para lograr el efecto de clic; cuando el módulo IR izquierdo detecta tu mano, enviará un mensaje - **izquierda** al sprite **IR Izquierda**, permitiéndole comenzar a funcionar. Si toca el azulejo negro en el escenario, la puntuación aumentará en 1, de lo contrario, disminuirá en 1.

* Nuevamente, toca el ícono de **Añadir Sprite** y selecciona **Pintar**.

  .. image:: img/tile_paint_ir1.png

* Ve a la página de **Disfraces**, selecciona el color de relleno (cualquier color que no sea negro o blanco) y dibuja un círculo.

  .. image:: img/tile_paint_ir2.png

* Regresa a la página de **Código** y cambia el nombre del sprite a **IR Izquierda**.

  .. image:: img/tile_paint_ir3.png

5. Programando el sprite **IR Izquierda**
---------------------------------------------

* Ahora comienza a programar el sprite **IR Izquierda**. Cuando se hace clic en la bandera verde, primero oculta el sprite.

  .. image:: img/tile_script_ir1.png

* Cuando se recibe el mensaje - **izquierda** (el módulo receptor IR en el lado izquierdo detecta un obstáculo), muestra el sprite, ajusta su tamaño al 100%, y luego lo reduce en intervalos de 10 usando un bloque [Repetir] antes de ocultarlo nuevamente. Esto le da al sprite un efecto de expansión y contracción.

  .. image:: img/tile_script_ir2.png

* Luego determina si el bloque negro del sprite **Azulejo** es tocado, y si lo es, deja que la variable **cuenta** aumente en 1, de lo contrario, disminuye en 1.
  
  .. image:: img/tile_script_ir3.png

.. note::

    Necesitas hacer que el sprite **Azulejo** aparezca en el escenario y luego absorber el color del bloque negro en el sprite **Azulejo**.

    .. image:: img/tile_script_ir4.png

6. Sprite **IR Derecha**
-----------------------------------
La función del sprite **IR Derecha** es básicamente la misma que la de **IR Izquierda**, excepto que recibe el mensaje **derecha**.

* Ahora duplica el sprite **IR Izquierda** y cambia el nombre del sprite a **IR Derecha**.

  .. image:: img/tile_paint_ir4.png

* Luego cambia el mensaje recibido a - **derecha**.

    .. image:: img/tile_script_ir5.png

7. Ejecutando el Script
---------------------------------

* Ahora ajusta las posiciones y tamaños de los tres sprites.

  * Arrastra el sprite **Azulejo** al fondo del escenario y ajusta su posición en x a 0.
  * Mueve el sprite **IR Izquierda** al marco izquierdo. Necesitas ir a la página de **Disfraces** para reducir el tamaño del sprite al 50% del tamaño del marco.
  * De manera similar, mueve el sprite **IR Derecha** al marco derecho. Necesitas ir a la página de **Disfraces** para reducir el tamaño del sprite al 50% del tamaño del marco.
  * Asegúrate de que los sprites **IR Izquierda** y **IR Derecha** estén sobre el sprite **Azulejo**.

  .. image:: img/tile_paint_ir5.png

* Ahora toda la programación está lista, y puedes hacer clic en la bandera verde para ejecutar el script.

  .. raw:: html

    <video loop autoplay muted style = "max-width:70%">
        <source src="../_static/video/sc_tap_black_tile.mp4"  type="video/mp4">
        Your browser does not support the video tag.
    </video>

