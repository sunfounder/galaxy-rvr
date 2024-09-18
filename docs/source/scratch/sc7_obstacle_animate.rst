.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Preestrenos exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!





Lección 7 Animación de Evasión de Obstáculos Infrarrojos
============================================================

Anteriormente, utilizamos el Módulo de Evasión de Obstáculos Infrarrojo para que el GalaxyRVR evitara automáticamente obstáculos, tal como lo haría en una misión de exploración en Marte.

En esta actividad, combinaremos el módulo de evasión de obstáculos con un escenario para crear una animación de un rover esquivando rocas en Marte.


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_rock.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>



Objetivos de aprendizaje
---------------------------

* Comprender más a fondo el Módulo de Evasión de Obstáculos Infrarrojo y su aplicación en el rover marciano.
* Aprender a leer y aplicar los datos del Módulo de Evasión de Obstáculos Infrarrojo en Scratch.
* Crear un juego temático de exploración marciana utilizando el módulo IR y el escenario de Scratch.


Materiales
-------------

* Teléfono inteligente o tableta
* APP Mammoth Coding
* GalaxyRVR


Creación de la animación
--------------------------------------

1. Primero, necesitamos un fondo con temática de Marte. Haz clic para seleccionar un fondo.

.. image:: img/5_animate_choose.png

2. Elige el fondo de Marte.

.. image:: img/5_animate_mars.png

3. Selecciona el sprite de GalaxyRVR de la biblioteca y ajusta su tamaño.

.. image:: img/5_animate_rvr.png

4. Selecciona un sprite de roca de la biblioteca y ajusta su tamaño.

.. image:: img/5_animate_rock.png


5. A continuación, vamos a programar estos dos sprites:



**Sprite GalaxyRVR**

La tarea del sprite GalaxyRVR es moverse lentamente de izquierda a derecha en la pantalla. Si toca una roca, se detendrá.
Durante este proceso, podemos activar los dos sensores infrarrojos del rover físico con nuestras manos. Al activar el sensor derecho, el sprite se moverá un poco hacia abajo; al activar el sensor izquierdo, se moverá hacia arriba.



a. Cuando se haga clic en la bandera verde, el sprite debe aparecer en el extremo izquierdo de la pantalla. Puedes mover el sprite a la posición correspondiente en el escenario, y los valores de coordenadas del bloque en la categoría de movimiento cambiarán en consecuencia.

.. image:: img/5_animate_glide.png

b. Coloca un bloque de "por siempre" como bucle principal.

.. image:: img/5_animate_forever.png

c. Arrastra un bloque condicional para verificar si está tocando el sprite de roca.

.. image:: img/5_animate_touching.png

d. Si no está tocando, se mueve hacia adelante.

.. image:: img/5_animate_moving.png

e. Si toca, se detiene y emite un grito.

.. image:: img/5_animate_say.png

f. Finalmente, agrega dos eventos. Cuando los sensores infrarrojos izquierdo o derecho detecten un obstáculo (tu mano), el sprite se moverá hacia arriba o hacia abajo.

.. image:: img/5_animate_y.png


**Sprite de Roca**

La tarea del sprite de roca es más sencilla. Puede quedarse en su lugar, aparecer en ubicaciones aleatorias o crear múltiples clones para aumentar la dificultad del sprite GalaxyRVR.

a. Crea sus clones.

.. image:: img/5_animate_clone.png

b. Luego, muévete a una posición aleatoria. Combina estos dos bloques y haz clic en ellos. Notarás nuevas rocas apareciendo aleatoriamente en el escenario.

.. image:: img/5_animate_clone_move.png

c. Genera diez rocas aleatorias.

.. image:: img/5_animate_clone_10.png

d. Estas acciones ocurren cuando se hace clic en la bandera verde.

.. image:: img/5_animate_clone_flag.png    
   :width: 200

Ahora, este mini-juego está completo.

Conecta el GalaxyRVR a la APP (refer to :ref:`app_connet`) y haz clic en la bandera verde para iniciar el juego.

Verás muchas rocas generadas aleatoriamente en el escenario. Tu tarea es usar tus manos para activar los dos sensores infrarrojos, guiando al GalaxyRVR para llegar con éxito al lado derecho del escenario.

