.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lección 5: Animación Interactiva
===============================================

Anteriormente, usamos el módulo ultrasónico para hacer que GalaxyRVR evitara obstáculos automáticamente en su camino.

En esta actividad, combinaremos el módulo con un escenario para crear una animación interactiva de un rover recorriendo alegremente la superficie de Marte.


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_jump.mp4" type="video/mp4">
      Su navegador no soporta la etiqueta de video.
   </video>

Objetivos de Aprendizaje
-------------------------

* Aprender a dibujar sprites y editar fondos.
* Comprender conceptos básicos de programación como los eventos y las estructuras de bucle.
* Familiarizarse con el entorno de programación de la APP y las operaciones básicas para crear una animación simple que simule un rover marciano.

Agregar Nuevos Sprites
----------------------------

#. Primero, :ref:`app_connect`.

#. Elimina cualquier sprite que no necesites.

   .. image:: img/6_animate_delete.png

#. En la esquina inferior derecha de la interfaz, toca el botón **Elegir un Sprite** para ver cuatro opciones.

   .. image:: img/5_create_sp.png

#. En pantallas pequeñas, es posible que necesites cambiar a otra pantalla para ver este botón.

   .. image:: img/5_create_sp0.png

Las cuatro opciones son:

* **Subir Sprite** —Cargar un sprite desde tu dispositivo.
* **Sorpresa** —Seleccionar un sprite aleatorio de la biblioteca.
* **Pintar** —Dibujar tu propio sprite.
* **Elegir un Sprite** —Seleccionar de la biblioteca de sprites.

A continuación, usaremos **Elegir un Sprite** para seleccionar un sprite y **Pintar** para dibujar uno.

**Elegir un Sprite**

#. Toca **Elegir un Sprite** (ícono de lupa) para abrir la biblioteca de sprites.

   .. image:: img/5_sp_list.png

#. Busca y selecciona **GalaxyRVR** de la biblioteca.

   .. image:: img/1_choose_galaxyrvr.png


**Pintar un Nuevo Sprite**

#. Toca **Pintar** (ícono de pincel) para crear un nuevo sprite. Dibujaremos un sprite de **Marte**.

   .. image:: img/5_create_custom.png

#. Usa la **Herramienta Círculo** para dibujar un círculo que represente el planeta.

   .. image:: img/5_create_custom1.png

#. Usa la **Herramienta Puntero** para mover el círculo al centro del lienzo. Este paso es importante porque las coordenadas y movimientos del sprite se basan en su centro.

   .. image:: img/5_create_custom2.png

#. Usa la **Herramienta Bote de Pintura** para rellenar el círculo de rojo.

   .. image:: img/5_create_custom3.png

#. Selecciona la **Herramienta Pincel**, aumenta el tamaño del pincel y agrega textura con un color de relleno adecuado.

   .. image:: img/5_create_custom_pen.png

#. Si el color no se ve bien, cambia el color de relleno y usa la **Herramienta Bote de Pintura** nuevamente.

   .. image:: img/5_create_custom5.png

#. Selecciona nuevamente la **Herramienta Pincel**, establece el tamaño en 2, cambia el color a negro y dibuja cráteres en Marte.

   .. image:: img/5_create_custom6.png

#. Usa la **Herramienta Bote de Pintura** para rellenar los cráteres con un color adecuado.

   .. image:: img/5_create_custom7.png

#. Una vez terminado, vuelve a la **Interfaz de Código**.

   .. image:: img/5_create_custom8.png

#. En pantallas pequeñas, haz clic en el ícono para regresar a la Interfaz de Código.

   .. image:: img/5_create_custom8.1.png

#. Ahora verás el sprite de Marte en el escenario. No olvides **renombrarlo**.

   .. image:: img/5_create_custom9.png


**Escenario**

#. Haz clic en **Fondos** para modificar el fondo. El fondo blanco predeterminado se cambiará para simular un cielo nocturno.

   .. image:: img/6_jump_backdrop.png

#. Ingresa a la interfaz de **Fondos**.

   .. image:: img/6_jump_backdrop_page.png

#. Dibuja un rectángulo en el lienzo.

   .. image:: img/6_jump_rect.png

#. Usa la **Herramienta Bote de Pintura** para rellenarlo con un color oscuro.

   .. image:: img/6_jump_fill.png

#. Usa la **Herramienta Pincel** para agregar algunas estrellas.

   .. image:: img/6_jump_paint.png


Creando la Animación
-------------------------------

Ahora que tenemos Marte y GalaxyRVR, y sabemos cómo animar sprites, creemos una animación de GalaxyRVR moviéndose en Marte.
Podemos hacer que el sprite parezca moverse rotando Marte en la dirección opuesta, creando el efecto de que GalaxyRVR se desplaza sobre su superficie.

#. Primero, :ref:`app_connect`.

#. Ajusta el tamaño y la posición de ambos sprites.

   * Coloca el sprite GalaxyRVR en **(0, 0)** y posiciona Marte para que GalaxyRVR parezca estar sobre su superficie.

   .. image:: img/6_jump_place.png


**Sprite de Marte**

#. Selecciona el sprite de Marte. Su tarea es rotar en sentido antihorario, creando la ilusión de que GalaxyRVR avanza.

   .. image:: img/6_ssp_mars.png

#. Arrastra un bloque de bandera verde. Toda animación comienza con la bandera verde.

   .. image:: img/6_jump_mar_flag.png

#. Arrastra un bloque ``forever`` para mantener la animación ejecutándose continuamente.

   .. image:: img/6_jump_mar_forever.png


#. Arrastra un bloque ``turn`` y un bloque ``wait`` para hacer que Marte rote continuamente.

   .. image:: img/6_jump_mar_turn.png

#. Ahora haz clic en la bandera verde y verás a Marte rotando en sentido antihorario.



**Sprite GalaxyRVR**

#. Selecciona el sprite GalaxyRVR. Su tarea es animarse como si se estuviera moviendo, aunque en realidad no se esté desplazando.

   .. image:: img/6_ssp_rvr.png

#. Arrastra un bloque de bandera verde. Toda animación comienza con la bandera verde.

   .. image:: img/6_jump_mar_flag.png

#. Arrastra un bloque ``forever`` para mantener la animación ejecutándose continuamente.

   .. image:: img/6_jump_mar_forever.png

#. Arrastra un bloque ``next costume`` y un bloque ``wait`` para que GalaxyRVR se anime continuamente.

   .. image:: img/6_jump_mar_next.png

#. Arrastra un bloque ``when distance``. Esto se activará cuando el módulo ultrasónico detecte un obstáculo (por ejemplo, tu mano).

   .. image:: img/6_jump_when.png


#. Arrastra dos bloques ``glide`` y cambia el valor y del primero para que el sprite salte hacia arriba y luego baje, creando un efecto de salto.

   .. image:: img/6_jump_glide.png

#. El código completo para el sprite GalaxyRVR debería verse así:

   .. image:: img/6_jump_mar_rvr_all.png


Ahora, haz clic en la bandera verde para iniciar la animación. Simula un obstáculo colocando tu mano frente al módulo ultrasónico, y el sprite GalaxyRVR saltará para evitarlo.
