
Fun1 Inflar el Globo
=========================================

En este proyecto interactivo, controlamos el vuelo de un globo.

Al hacer clic en la bandera verde, el globo se inflará progresivamente. Si el globo se vuelve demasiado grande, estallará; si es demasiado pequeño, caerá. Tu tarea es bloquear el módulo infrarrojo izquierdo en el momento adecuado para que ascienda.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_balloon.mp4" type="video/mp4">
      Tu navegador no soporta la etiqueta de video.
   </video>

A continuación se muestran los pasos para implementar el proyecto. Es recomendable seguir estos pasos inicialmente, y una vez familiarizado, puedes modificar los efectos como desees.


1. Agregar un Objeto y un Fondo
----------------------------------------

* Elimina el objeto predeterminado y haz clic en el botón **Choose a Sprite** en la esquina inferior derecha del área de objetos. Luego, selecciona el objeto **Balloon1**.

  .. image:: img/balloon_choose_sprite.png

* Agrega un fondo **Boardwalk** u otro fondo de tu elección mediante el botón **Choose a Backdrop**.

  .. image:: img/balloon_choose_backdrop.png

2. Dibujar un Disfraz para el Objeto **Balloon1**
-------------------------------------------------------

Ahora, creemos un disfraz de efecto de explosión para el globo.

* Ve a la pestaña **Costumes** del objeto **Balloon1**, haz clic en el botón **Choose a Costume** en la parte inferior izquierda y selecciona **Paint** para abrir un **Costume** en blanco. Nómbralo "boom".

  .. image:: img/balloon_set_ball1.png

* Elige un color y usa la herramienta **Brush** para dibujar un patrón.

  .. image:: img/balloon_set_ball2.png
    :width: 90%

* Elige otro color, selecciona la herramienta **Fill** y haz clic dentro del patrón para rellenarlo.

  .. image:: img/balloon_set_ball3.png
    :width: 90%

* Finalmente, agrega el texto "BOOM" para completar el disfraz de efecto de explosión.

  .. image:: img/balloon_set_ball4.png
    :width: 90%

3. Programar el Objeto **Balloon**
------------------------------------------

* Inicializa la posición y el tamaño del objeto **Balloon1**.

  .. image:: img/balloon_script1.png

* Aumenta gradualmente el tamaño del objeto **Balloon**.

  .. image:: img/balloon_script2.png

* En este punto, bloquea el módulo de evitación de obstáculos izquierdo para evitar que el objeto **Balloon1** se infle más.

  .. image:: img/balloon_script3.png

* Ahora, deja que el objeto **Balloon1** decida si ascender o descender según su tamaño.

  * Si el tamaño es menor de 90, descenderá (la coordenada y disminuye).
  * Si el tamaño está entre 90 y 120, ascenderá (la coordenada y aumenta).

  .. image:: img/balloon_script4.png

* Si no logras bloquear el módulo de evitación de obstáculos izquierdo, el globo continuará inflándose hasta que supere un tamaño de 120, momento en el que explotará (cambiará al disfraz de efecto de explosión).

  .. image:: img/balloon_script5.png

La programación está completa. Ahora puedes hacer clic en la bandera verde para ejecutar el script y ver si logra el efecto deseado.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_balloon.mp4" type="video/mp4">
      Tu navegador no soporta la etiqueta de video.
   </video>
