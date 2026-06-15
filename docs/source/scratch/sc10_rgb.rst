.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lección 10: Iluminando el Camino con Tiras LED RGB
===============================================================

Nuestro Mars Rover se ha convertido en un explorador experto, pero ahora es momento de agregarle algo de personalidad colorida. En esta lección, transformaremos nuestro rover con tiras LED RGB que pueden brillar en cualquier color imaginable.

Imagina tu GalaxyRVR iluminando su camino como una nave espacial de una película de ciencia ficción:

- Brillo verde al avanzar
- Luz roja al detenerse
- Destellos amarillos al girar
- ¡Espectaculares shows de colores solo por diversión!

Aprenderemos a programar estas increíbles luces y sincronizarlas con los movimientos de tu rover. ¡Prepárate para crear tu propio explorador de Marte iluminado!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/car_rgb.mp4" type="video/mp4">
        Tu navegador no soporta la etiqueta de video.
    </video>

Objetivos de Aprendizaje
------------------------

* Descubrir cómo funcionan las tiras LED RGB y cómo programarlas
* Aprender a controlar colores y crear efectos de iluminación usando Mammoth Coding
* Diseñar señales luminosas y colores para tus misiones de exploración en Marte

Explora la Magia de la Luz con las Tiras LED RGB
-------------------------------------------------------------

¿Alguna vez has querido crear tu propio arcoíris? ¡Ahora puedes! Con las tiras LED RGB, puedes hacer que tu rover de Marte brille con cualquier color que puedas imaginar. ¡Descubramos la magia de las luces coloridas!

.. image:: img/4_rgb_strip.jpg

Conoce los cuatro pines importantes de tu tira LED:

* **+5V** - El pin de alimentación que da energía a todas las luces (necesita 5V de electricidad)
* **B** - Controla las luces azules
* **R** - Controla las luces rojas
* **G** - Controla las luces verdes

.. image:: img/rgb_5050.jpg

Recuerda lo que aprendiste sobre los colores primarios en la clase de arte. Así como mezclar pintura, cada LED puede combinar luz roja, azul y verde para crear colores increíbles. Cada LED "5050" es como una pequeña fábrica de colores que contiene los tres colores.

.. image:: img/rgb_5050_sche.png

Todas estas fábricas de colores están conectadas en un circuito flexible, como una autopista eléctrica colorida. Los pines de alimentación se conectan entre sí, mientras que los pines de color tienen cada uno su propio camino especial.

.. image:: img/rgb_strip_sche.png

¿La parte más emocionante? ¡Puedes programar TODOS los LEDs para que cambien de color al mismo tiempo! Imagina crear tu propio espectáculo de luces con solo unos bloques de código. ¡Prepárate para iluminar tu aventura con el rover de Marte!

Ilumina el Espectáculo
------------------------------

#. Primero, :ref:`app_connect`.

#. Ahora, ¡haz que tu GalaxyRVR brille! Arrastra un bloque "display color" para comenzar.

   .. image:: img/9_rgb_block.png

#. Elige cualquier color que te guste del menú de colores.

   .. image:: img/9_rgb_color.png

#. ¡Haz clic en el bloque y observa cómo tu GalaxyRVR se ilumina con el color que elegiste!

**Crear un Controlador de Colores**

Ahora construyamos un controlador de colores interactivo. Crearemos botones coloridos en el escenario que cambien las luces de tu GalaxyRVR cuando los toques.

1. Primero, elimina cualquier sprite existente para comenzar desde cero.

   .. image:: img/6_animate_delete.png

2. Agrega un sprite de Pelota (Ball) desde la biblioteca. Este sprite es perfecto porque viene con múltiples disfraces de colores.

   .. image:: img/9_animate_rgb_ball.png

3. Agrega un bloque "when this sprite clicked" - esto hará que sucedan cosas cuando toques la pelota.

   .. image:: img/9_animate_rgb_when.png

4. Conecta un bloque "display color" para iluminar tu GalaxyRVR.

   .. image:: img/9_animate_rgb_display.png

5. En pantallas pequeñas, asegúrate de poder ver el escenario haciendo clic en el botón del ojo.

   .. image:: img/9_animate_rgb_eye.png

6. Haz clic en el cuadro de color del bloque de visualización, luego haz clic en el botón del selector de color en la parte inferior.

   .. image:: img/9_animate_rgb_pick.png

7. Mantén presionado el área del escenario: ¡aparecerá una lupa! Suéltala sobre el sprite de la pelota para copiar su color.

   .. image:: img/9_animate_rgb_pick_color_n.png

8. Crea más botones de color manteniendo presionado el sprite de la pelota para duplicarlo.

   .. image:: img/9_animate_rgb_duplicate.png

9. Cambia cada duplicado a un color diferente cambiando su disfraz.

   .. image:: img/9_animate_rgb_change_costume.png

10. Para cada nuevo color, usa el selector de color para que coincida con el bloque de visualización con el color actual del sprite.

   .. image:: img/9_animate_rgb_pick_blue.png

11. ¡Repite hasta que tengas cinco botones de color diferentes!

   .. image:: img/9_animate_rgb_ball5.png

Ahora toca cualquier pelota de color en el escenario y observa cómo tu GalaxyRVR brilla con ese color. Crea tu propio espectáculo de luces con solo un toque.

.. _rgb_move:

Luces de Señalización del GalaxyRVR en Acción
----------------------------------------------------------------

**Luces Indicadoras de Dirección**

Combinemos los colores de luz con el movimiento para crear luces de señalización para tu GalaxyRVR. Así como un coche tiene intermitentes, tu rover se iluminará en diferentes colores cuando se mueva.

#. Primero, :ref:`app_connect`.

#. Ahora, configura las teclas de dirección con bloques de movimiento para las cuatro direcciones.

   .. image:: img/9_rgb_move.png

#. Agrega visualizaciones de color a cada dirección:

   - Luz verde para avanzar

   .. image:: img/9_rgb_green.png

   - Luces amarillas para girar a la izquierda y a la derecha

   .. image:: img/9_rgb_yellow.png

   - Luz roja para retroceder

   .. image:: img/9_rgb_red.png

Ahora, cuando presiones las teclas de dirección, tu GalaxyRVR se moverá y brillará con el color correspondiente.

**Efecto de Luz Respiración**

Creemos un efecto de luz respiratoria que se ilumine y atenúe lentamente cuando tu rover esté en reposo, ¡como si estuviera respirando!

1. Crea un nuevo mensaje de difusión llamado "stop" para indicar cuándo el rover no se está moviendo.

   .. image:: img/9_rgb_new_message.png

   .. note:: Los mensajes de difusión ayudan a organizar tu código activando acciones específicas en el momento adecuado, haciendo que tus programas sean más limpios y fáciles de entender.

2. Agrega esta difusión después de cada comando de movimiento.

   .. image:: img/9_rgb_new_boardcast.png

3. Crea un bloque "when I receive [stop]" para iniciar la luz respiratoria.

   .. image:: img/9_rgb_when_receive.png

4. Establece el brillo al 0% para comenzar desde completamente oscuro.

   .. image:: img/9_rgb_set_bright.png

5. Usa un bucle de repetición para aumentar gradualmente el brillo de la luz azul en un 10% cada 0.2 segundos.

   .. image:: img/9_rgb_increase.png

6. Luego disminuye gradualmente el brillo para completar un ciclo de respiración.

   .. image:: img/9_rgb_decrease.png

7. Vuelve a difundir "stop" para mantener el efecto de respiración continuo.

   .. image:: img/9_rgb_stopagain.png

8. Agrega "stop other scripts" al final de cada evento de tecla para evitar conflictos de color.

   .. image:: img/9_rgb_stop.png

9. Restablece el brillo de la luz en cada evento de tecla de dirección.

   .. image:: img/9_rgb_set_bright_each.png

¡Ahora tu GalaxyRVR se iluminará con señales de colores cuando se mueva y palpitará suavemente con una luz azul respiratoria cuando esté en reposo!

Bloques Relacionados con el Módulo RGB
---------------------------------------


* Ilumina tu GalaxyRVR con cualquier color que elijas.

  - Haz clic en la muestra de color para elegir tu color favorito

  .. image:: img/block/rgb_display.png


* Ilumina tu GalaxyRVR durante un tiempo específico.

  - Elige cualquier color
  - Establece cuánto tiempo permanece encendida la luz

  .. image:: img/block/rgb_display_1s.png

* Crea colores personalizados mezclando luz roja, verde y azul, perfecto para proyectos de difuminado de colores.

  - R: Brillo rojo (0-255)
  - G: Brillo verde (0-255)
  - B: Brillo azul (0-255)

  .. image:: img/block/rgb_display_RGB.png

* Muestra colores RGB personalizados durante un tiempo determinado.

  - Ajusta los valores de rojo, verde y azul (0-255)
  - Establece la duración de la visualización

  .. image:: img/block/rgb_display_RGB_1s.png

* Establece qué tan brillantes deben ser las luces (0-100%).

  .. image:: img/block/rgb_set_brightness.png

* Haz las luces más brillantes o más tenues. Usa números negativos para disminuir el brillo.

  .. image:: img/block/rgb_increase_brightness.png


* Enciende o apaga las luces RGB.

  .. image:: img/block/rgb_turn_on.png
