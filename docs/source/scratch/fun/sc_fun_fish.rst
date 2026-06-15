.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Fun5 Pesca
===========================

Sumérgete en nuestro juego de pesca interactivo, que utiliza el módulo de evitación de obstáculos izquierdo para una experiencia envolvente.

Cuando el script está activo, los peces nadarán de un lado a otro por el escenario. Para atrapar un pez, debes bloquear el módulo de evitación de obstáculos izquierdo justo cuando el pez está a punto de pasar por el anzuelo. El juego registra automáticamente el número de peces que atrapas.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_fishing.mp4"  type="video/mp4">
      Tu navegador no soporta la etiqueta de video.
   </video>

Sigue estos pasos iniciales para configurar el proyecto, y no dudes en personalizar los efectos una vez que estés familiarizado con la configuración.

1. Añadir fondo y Sprites
------------------------------------

Primero, selecciona un fondo **Underwater**, luego añade un objeto **Fish** y haz que nade por el escenario.

* Usa el botón **Choose a Backdrop** para seleccionar un fondo **Underwater**.

  .. image:: img/fish_choose_backdrop.png

* Elimina el objeto original, luego selecciona el objeto **Fish**.

  .. image:: img/fish_choose_fish.png

* Ajusta el tamaño y la posición del objeto **Fish**.

  .. image:: img/fish_set_fish.png

2. Dibujar un objeto **Fishhook**
-------------------------------------

A continuación, crea un objeto **Fishhook**, que controlarás mediante el módulo de evitación de obstáculos izquierdo para comenzar a pescar.

* Añade el objeto **Glow-J** mediante **Choose a Sprite** y renómbralo como "Fishhook".

  .. image:: img/fish_choose_j.png

* Ve a la página de **Costumes** del objeto **Glow-J**, renómbralo como **Fishhook**, selecciona la 'J' blanca interior y cambia su color a rojo.

  .. image:: img/fish_set_j1.png
    :width: 90%

* Elimina el relleno cyan exterior y reduce su ancho. Asegúrate de que la parte superior del anzuelo esté alineada con el punto central.

  .. image:: img/fish_set_j2.png

* Usa la herramienta **Line** para dibujar una línea que se extienda hacia arriba desde el punto central, saliendo del escenario.

  .. image:: img/fish_set_j3.png

3. Programación del objeto **Fish**
---------------------------------------

El objeto **Fish** debe moverse a izquierda y derecha por el escenario, y cuando interactúe con el objeto **Fishhook** en estado de pesca, debe encogerse, moverse a una posición específica, luego desaparecer, seguido de la aparición de un nuevo objeto **Fish**.

* Crea una variable **score** para almacenar el número de peces atrapados, oculta este objeto y clónalo.

  .. image:: img/fish_script_fish1.png

* Muestra el clon del objeto **Fish**, cambia su disfraz y establece la posición inicial.

  .. image:: img/fish_script_fish2.png

* Habilita el clon del objeto **Fish** para que se mueva a izquierda y derecha y rebote al tocar el borde del escenario.

  .. image:: img/fish_script_fish3.png

* Si el clon del objeto **Fish** toca el objeto **Fishhook** en estado de pesca (cuando se vuelve rojo).

  .. image:: img/fish_script_fish4.png
    :width: 90%

* Aumenta la puntuación (variable score) en 1, muestra una animación de puntuación (se encoge un 40%, se mueve rápidamente a la posición del marcador y desaparece). Simultáneamente, crea un nuevo pez (un nuevo clon del objeto **Fish**) y continúa el juego.

  .. image:: img/fish_script_fish5.png

4. Programación del objeto **Fishhook**
---------------------------------------------

El objeto **Fishhook** generalmente permanece bajo el agua en estado amarillo. Cuando tu mano bloquea el módulo de infrarrojo izquierdo, cambia al estado de pesca (rojo) y se mueve sobre el escenario.

* Cuando se hace clic en la bandera verde, establece el efecto de color del objeto en 30 (amarillo) y define su posición inicial.

  .. image:: img/fish_script_hook1.png

* Cuando tu mano bloquea el módulo de infrarrojo izquierdo, establece el efecto de color en 0 (rojo, iniciando el estado de pesca), espera 0.1 segundos, luego mueve el objeto **Fishhook** a la parte superior del escenario.

  .. image:: img/fish_script_hook2.png

* Después de retirar tu mano, deja que el objeto **Fishhook** regrese a su posición inicial.

  .. image:: img/fish_script_hook3.png

Una vez que hayas completado la programación, haz clic en la bandera verde para ejecutar el script y ver si logra el efecto deseado.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_fishing.mp4"  type="video/mp4">
      Tu navegador no soporta la etiqueta de video.
   </video>
