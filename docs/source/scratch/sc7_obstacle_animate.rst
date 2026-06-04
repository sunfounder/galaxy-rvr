Lección 7: Crear una Animación de Obstáculos con IR
=====================================================

En nuestras misiones anteriores, usamos el Módulo Infrarrojo de Evasión de Obstáculos para ayudar a nuestro GalaxyRVR a esquivar obstáculos automáticamente, ?como un verdadero rover marciano navegando por el Planeta Rojo!

Ahora, llevemos esto al siguiente nivel combinando los sensores IR físicos con un paisaje marciano virtual. ?Crearemos un emocionante juego de animación donde controlas un sprite de rover activando los sensores IR reales con tus manos!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_rock.mp4" type="video/mp4">
      Su navegador no soporta la etiqueta de video.
   </video>

Objetivos de Aprendizaje
-------------------------

* Descubrir cómo el Módulo Infrarrojo de Evasión de Obstáculos da vida a tu rover marciano
* Aprender a usar los datos del sensor IR para controlar personajes en tus animaciones de Scratch
* Crear tu propio juego de exploración marciana donde esquives rocas usando sensores reales

Creación de la Escena de Animación
----------------------------------

#. Primero, :ref:`app_connect`.

#. Configurar el fondo temático de Marte

   * Primero, necesitamos un fondo de escenario temático de Marte. Haz clic para seleccionar un fondo.

     .. image:: img/5_animate_choose.png

   * Elige el fondo **Marte**.

     .. image:: img/5_animate_mars.png

#. A?adir el personaje del rover

   Elige el sprite **GalaxyRVR** de la librería y rediménsionalo para que se ajuste adecuadamente a tu escena.

   .. image:: img/5_animate_rvr.png

#. A?adir obstáculos

   Selecciona un sprite de **Rocas** de la librería y ajusta su tama?o.

   .. image:: img/5_animate_rock.png


Programación del Sprite GalaxyRVR
---------------------------------

Programa tu sprite GalaxyRVR para que viaje por la pantalla de izquierda a derecha. Tu misión: guiarlo de forma segura entre las rocas.
Usa tus manos para activar los sensores IR del rover físico: el sensor derecho mueve el sprite hacia abajo, el izquierdo lo mueve hacia arriba.

#. Establece la posición inicial moviendo el sprite al borde izquierdo del escenario. Los bloques de movimiento se actualizarán automáticamente con las coordenadas correctas.

   .. image:: img/5_animate_glide.png

#. A?ade un bloque "por siempre" para crear el bucle principal del programa que se ejecuta continuamente.

   .. image:: img/5_animate_forever.png

#. Incluye un bloque condicional para verificar si el rover está tocando un obstáculo de roca.

   .. image:: img/5_animate_touching.png

#. Si no se detecta ninguna roca, sigue avanzando hacia el lado derecho.

   .. image:: img/5_animate_moving.png

#. Si el rover choca con una roca, detén todo el movimiento y muestra un mensaje de advertencia.

   .. image:: img/5_animate_say.png

#. A?ade controles de sensores: crea eventos para ambos sensores IR que muevan el sprite hacia arriba (sensor izquierdo) o hacia abajo (sensor derecho) cuando los actives con tu mano.

   .. image:: img/5_animate_y.png

Programación del Sprite de las Rocas
------------------------------------

?Creemos múltiples obstáculos de rocas para hacer el juego más desafiante! Usaremos la clonación para generar rocas en posiciones aleatorias en el escenario.

#. Crea clones de rocas usando el bloque "crear clon de mí mismo".

   .. image:: img/5_animate_clone.png

#. Haz que cada clon aparezca en una ubicación aleatoria a?adiendo el bloque "ir a posición aleatoria".

   .. image:: img/5_animate_clone_move.png
      :width: 200

#. Genera diez rocas repitiendo la creación de clones diez veces.

   .. image:: img/5_animate_clone_10.png
      :width: 200

#. Configura toda esta acción para que comience al hacer clic en la bandera verde.

   .. image:: img/5_animate_clone_flag.png
      :width: 200

?Lanzamiento de la Misión!
----------------------------

?Felicidades! Tu juego de evasión de obstáculos marcianos está listo para lanzarse.

Conecta tu GalaxyRVR a la APP y haz clic en la bandera verde para comenzar tu misión. Observa cómo las rocas aparecen aleatoriamente por el paisaje marciano.

Tu desafío: Usa tus manos para activar los sensores IR y guía cuidadosamente el sprite GalaxyRVR a través de la pantalla. Muévelo hacia arriba y hacia abajo para evitar las rocas y llegar al lado derecho de forma segura.

?Puedes completar la misión sin colisiones? ?Qué tan rápido puedes navegar por la pista de obstáculos? ?Sigue practicando para convertirte en un maestro piloto de rover marciano!