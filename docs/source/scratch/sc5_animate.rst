.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Preestrenos exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!


Lección 5 Animación interactiva
===============================================

En nuestra actividad anterior, utilizamos el módulo ultrasónico para hacer que el GalaxyRVR evitara automáticamente los obstáculos en su camino.

En esta actividad, combinaremos el módulo con un escenario para crear una animación interactiva de un rover atravesando alegremente la superficie de Marte.


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_jump.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>



Objetivos de aprendizaje
----------------------------

* Aprender a dibujar sprites y editar fondos.
* Comprender conceptos básicos de programación como los escuchadores de eventos y las estructuras de bucles.
* Familiarizarse con el entorno de programación de la APP y las operaciones básicas para crear una animación simple que simule un rover en Marte.

Materiales
--------------

* Teléfono inteligente o tableta
* APP Mammoth Coding
* GalaxyRVR


Añadir nuevos sprites
----------------------------

Elimina el sprite que no necesitas.

.. image:: img/6_animate_delete.png
..   :align: left



En la esquina inferior derecha de la interfaz, verás el botón "elegir un sprite". Toca para ver cuatro opciones desplegables.


.. image:: img/2_create_sp.png
..  :align: left

En pantallas más pequeñas, es posible que debas navegar a otra pantalla para ver este botón.


.. image:: img/2_create_sp0.png
..  :align: left



Las cuatro opciones son:

* **Subir Sprite** : Cargar un sprite desde el almacenamiento de tu dispositivo.
* **Sorpresa** : Seleccionar un sprite al azar de la biblioteca.
* **Pintar** : Dibujar un sprite.
* **Elegir un Sprite** : Abrir la biblioteca para elegir un sprite.

A continuación, utilizaremos **Elegir un Sprite** para seleccionar un sprite y **Pintar** para dibujar uno.


**Elegir un Sprite**

Haz clic en "elegir un sprite" (icono de lupa) para entrar en la biblioteca, que proporciona una gran cantidad de recursos para tu escenario.

.. image:: img/2_sp_list.png
.. :align: left

Busca y selecciona GalaxyRVR en la biblioteca.

.. image:: img/2_sprite_rvr.png
.. :align: left




**Pintar un nuevo sprite**

Vamos a crear un sprite de "Marte", pero desafortunadamente no hay un recurso adecuado en la biblioteca.

Por lo tanto, seleccionaremos **Pintar** (icono de pincel) y lo dibujaremos nosotros mismos.

.. image:: img/2_create_custom.png
.. :align: left

Primero, usa la herramienta de círculo para dibujar un círculo que represente el planeta.

.. image:: img/2_create_custom1.png
.. :align: left

Luego, utiliza la herramienta de puntero para mover el círculo de manera que quede alineado con el centro del lienzo.
Este paso es crucial porque las coordenadas, dirección y movimientos de tu sprite se basan en su punto central.

.. image:: img/2_create_custom2.png
.. :align: left

Usa la herramienta de balde de pintura para colorear el planeta de rojo.

.. image:: img/2_create_custom3.png
.. :align: left

A continuación, selecciona la herramienta de pincel, aumenta su tamaño y elige un color adecuado de las opciones de relleno para añadir textura a Marte.

.. image:: img/2_create_custom_pen.png
.. :align: left

Si después de pintar el color no es adecuado, puedes cambiar el color de relleno y utilizar la herramienta de balde de pintura para volver a llenar la forma.

.. image:: img/2_create_custom5.png
.. :align: left

Selecciona nuevamente el pincel, ajusta el tamaño a 2 y cambia el color a negro. Usa tu creatividad para añadir cráteres y detalles a Marte.

.. image:: img/2_create_custom6.png
.. :align: left

Con la herramienta de balde de pintura, elige un color adecuado para rellenar estos cráteres.

.. image:: img/2_create_custom7.png
.. :align: left

Una vez que hayas terminado, vuelve a la interfaz de Código. Tu sprite de Marte está listo.

.. image:: img/2_create_custom8.png
.. :align: left

Para pantallas más pequeñas, regresa a la interfaz de Código haciendo clic aquí.

.. image:: img/2_create_custom8.1.png
.. :align: left

Verás el sprite de Marte en el escenario. No olvides renombrarlo.

.. image:: img/2_create_custom9.png
.. :align: left




**Escenario**

Haz clic en fondos. El fondo actual es blanco; necesitamos oscurecerlo para simular el cielo nocturno.

1. Haz clic en Fondos del escenario.

.. image:: img/6_jump_backdrop.png
.. :align: left

2. Entra en la interfaz de Fondos.

.. image:: img/6_jump_backdrop_page.png
.. :align: left

2. Dibuja un rectángulo.

.. image:: img/6_jump_rect.png
.. :align: left

3. Usa el balde de pintura para llenarlo con un color oscuro.

.. image:: img/6_jump_fill.png
.. :align: left

4. Utiliza la herramienta de pincel para añadir algunas estrellas.

.. image:: img/6_jump_paint.png
.. :align: left



Crear la animación
----------------------

Ahora que tenemos Marte y GalaxyRVR, y sabemos cómo animar sprites, vamos a crear una animación en la que el GalaxyRVR se mueva sobre Marte.
Podemos hacer que el sprite parezca moverse haciendo que Marte gire en la dirección opuesta, creando el efecto de que GalaxyRVR se desplaza por su superficie.


Ajusta el tamaño y posición de los sprites, 
establece las coordenadas del sprite GalaxyRVR en 0,0, y colócalo sobre Marte.

Y ajusta la posición y el tamaño del sprite Marte de manera que el sprite GalaxyRVR "se pose" sobre él.

.. image:: img/6_jump_place.png
.. :align: left


**Sprite Marte**

.. image:: img/6_ssp_mars.png
    :align: left

Selecciona el sprite Marte. Su tarea es girar en sentido antihorario, creando la ilusión de que el GalaxyRVR se mueve hacia adelante.


.. raw:: html

   <br></br>

1. Arrastra un bloque de bandera verde. Toda animación comienza con la bandera verde.

.. image:: img/6_jump_mar_flag.png
.. :align: left

2. Arrastra un bloque ``por siempre`` para mantener la animación en funcionamiento de forma continua.

.. image:: img/6_jump_mar_forever.png
.. :align: left

3. Arrastra un bloque ``girar`` y un bloque ``esperar`` para que Marte gire de manera continua.

.. image:: img/6_jump_mar_turn.png
.. :align: left


Ahora haz clic en la bandera verde, y verás a Marte girar en sentido antihorario.



**Sprite GalaxyRVR**

.. image:: img/6_ssp_rvr.png
    :align: left


Selecciona el sprite GalaxyRVR. Su tarea es animarse como si se estuviera moviendo, aunque en realidad no lo esté.

.. raw:: html

   <br></br>

1. Arrastra un bloque de bandera verde. Toda animación comienza con la bandera verde.

.. image:: img/6_jump_mar_flag.png
.. :align: left


2. Arrastra un bloque ``por siempre`` para mantener la animación en funcionamiento de forma continua.

.. image:: img/6_jump_mar_forever.png
.. :align: left

3. Arrastra un bloque ``siguiente disfraz`` y un bloque ``esperar`` para que GalaxyRVR se anime de forma continua.

.. image:: img/6_jump_mar_next.png
.. :align: left


**Añadiendo más diversión**

.. image:: img/6_ssp_rvr.png
    :align: left

Podemos añadir interactividad a esta animación utilizando el módulo ultrasónico 
para hacer que el sprite GalaxyRVR salte para evitar obstáculos.

Por favor, continúa programando en el sprite GalaxyRVR.


1. Arrastra un bloque ``cuando la distancia``. Este se activará cuando el módulo ultrasónico detecte un obstáculo (por ejemplo, tu mano).

.. image:: img/6_jump_when.png
.. :align: left

2. Arrastra dos bloques ``deslizar`` y cambia el valor de y en el primero para hacer que el sprite salte hacia arriba y luego baje, creando un efecto de salto.

.. image:: img/6_jump_glide.png
.. :align: left


3. El código completo para el sprite GalaxyRVR debería verse así:

.. image:: img/6_jump_mar_rvr_all.png
.. :align: left


Ahora, haz clic en la bandera verde para iniciar la animación. Simula un obstáculo colocando tu mano frente al módulo ultrasónico, y el sprite GalaxyRVR saltará para evitarlo.

