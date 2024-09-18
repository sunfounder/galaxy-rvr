.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Preestrenos exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!


Lección 10 Iluminando el Camino con Tiras de LED RGB
=======================================================

En nuestro viaje hasta ahora, hemos transformado nuestro Rover en un explorador inteligente, capaz de maniobrar hábilmente alrededor de obstáculos. Se ha vuelto bastante ágil para navegar por los terrenos similares a Marte que hemos creado.

Pero, ¿qué tal si le añadimos un toque de estilo a su funcionalidad? Vamos a darle a nuestro Rover la capacidad de expresarse a través de un espectáculo de colores y luces. Vamos a incorporar tiras de LED RGB, una característica genial que permitirá a nuestro Rover iluminar su camino, incluso en las condiciones más oscuras.

Imagínate esto: el Rover deja un rastro de señales codificadas por colores, lo que facilita entender sus movimientos. Un resplandor verde cuando está en marcha, un rojo intenso cuando se detiene o un amarillo brillante durante esos giros rápidos. ¡Incluso podría iluminarse con una gama de colores solo por diversión!

Nuestro objetivo en esta lección es entender los principios de las tiras de LED RGB, aprender a controlar su color y brillo, y luego sincronizar esto con los movimientos del Rover. Al final, nuestro Rover de Marte será más que una máquina: será una entidad luminosa y cambiante que liderará el camino en el vasto paisaje marciano.

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/car_rgb.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

Objetivo
-----------

* Introducir los principios de funcionamiento y los métodos de control de programación de las tiras de LED RGB.
* Utilizar las tiras de LED RGB con Mammoth Coding para lograr control de color y efectos de iluminación simples.
* Crear un proyecto en Mammoth Coding para simular cambios de luz en un entorno marciano o señales luminosas para misiones de exploración en Marte.

Materiales necesarios
------------------------

* Tira de LED RGB y controlador
* APP Mammoth Coding
* Computadora o tableta

Explora la Magia de la Luz con las Tiras de LED RGB
------------------------------------------------------

¿Recuerdas la última vez que viste un arcoíris? ¿Cómo llenó el cielo con siete tonos vibrantes? ¿Qué te parecería crear tu propio arcoíris aquí mismo en nuestro pequeño rover marciano? ¡Vamos a sumergirnos en la magia de la luz con las tiras de LED RGB!

.. image:: ../img/4_rgb_strip.jpg

Te habrás dado cuenta de que nuestra tira de LED RGB tiene cuatro pines etiquetados de la siguiente manera:

* **+5V**: Este es el extremo "positivo" común o el "ánodo" de las tres pequeñas bombillas (LEDs) dentro de nuestra tira. Necesita conectarse a 5V de corriente continua, una especie de "jugo" eléctrico que alimenta nuestras pequeñas bombillas.
* **B**: Este es el extremo "negativo" o "cátodo" del LED azul.
* **R**: Este es el cátodo del LED rojo.
* **G**: Este es el cátodo del LED verde.

.. image:: ../img/rgb_5050.jpg

¿Recuerdas los tres colores primarios - rojo, azul y verde - que aprendimos en la clase de arte? Así como un artista mezcla estos colores en su paleta para crear nuevos tonos, nuestra tira contiene 4 LEDs "5050" que pueden mezclar estos colores primarios para crear prácticamente cualquier color. ¡Cada LED "5050" es como un pequeño estudio de arte que alberga estas tres bombillas de colores!

.. image:: ../img/rgb_5050_sche.png

Estos pequeños estudios de arte están conectados de manera inteligente en una placa de circuito flexible, ¡como una mini autopista eléctrica! Los extremos "positivos" de todos los LEDs (ánodos) están conectados entre sí, mientras que los extremos "negativos" (cátodos) están conectados a sus respectivos carriles de color (G a G, R a R, B a B).

.. image:: ../img/rgb_strip_sche.png

¿Y la mejor parte? ¡Con nuestros comandos, todos los LEDs de esta tira pueden cambiar sus colores al mismo tiempo! ¡Es como tener nuestra propia orquesta de luces en la punta de los dedos!

Ilumina el Espectáculo
-------------------------

1. ¡Vamos a intentar iluminar el GalaxyRVR con colores! Arrastra un bloque de mostrar color.

.. image:: img/9_rgb_block.png

2. Elige tu color favorito.

.. image:: img/9_rgb_color.png

3. Haz clic y verás cómo el GalaxyRVR se ilumina con el color correspondiente.

**Usando el Escenario para Controlar el GalaxyRVR**

A continuación, vamos a crear un proyecto interactivo para familiarizarnos con las funciones de iluminación del GalaxyRVR. Haremos clic en el sprite del escenario para cambiar el color del GalaxyRVR.

1. Elimina el sprite existente.

.. image:: img/6_animate_delete.png

2. Elige un sprite de bola. La razón para elegir este sprite es que tiene muchos disfraces, cada uno correspondiente a un color diferente.

.. image:: img/9_animate_rgb_ball.png

3. Arrastra un bloque cuando se haga clic en este sprite, que desencadena una acción cuando se hace clic en el sprite del escenario.

.. image:: img/9_animate_rgb_when.png

4. Arrastra un bloque de mostrar para hacer que el GalaxyRVR se ilumine.

.. image:: img/9_animate_rgb_display.png

5. Si estás usando un dispositivo con pantalla pequeña, haz clic en el botón del ojo al lado para asegurarte de que la ventana de vista previa del escenario esté en la misma interfaz.

.. image:: img/9_animate_rgb_eye.png

6. Haz clic en el color del bloque de mostrar. En la parte inferior de la ventana emergente, hay un botón de selector de color. Haz clic en él.

.. image:: img/9_animate_rgb_pick.png

7. Mantén presionada el área del escenario. Aparecerá una lupa en tu dedo para seleccionar el color. Suéltalo sobre el sprite de la bola para elegir su color para el bloque de mostrar.

.. image:: img/9_animate_rgb_pick_color_n.png

8. Mantén presionada la bola en el escenario para duplicarla.

.. image:: img/9_animate_rgb_duplicate.png

9. En la interfaz de disfraces, cambia al siguiente color.

.. image:: img/9_animate_rgb_change_costume.png

10. Vuelve a la interfaz de código y selecciona el color que coincida con el sprite actual.

.. image:: img/9_animate_rgb_pick_blue.png

11. Repite los pasos 8-10 hasta que todos los cinco colores estén configurados.

.. image:: img/9_animate_rgb_ball5.png

Ahora, puedes hacer clic en el sprite de la bola en el área del escenario para hacer que el GalaxyRVR se ilumine en diferentes colores.

.. _rgb_move:

GalaxyRVR Luces de Señalización en Acción
----------------------------------------------

**Luces Indicadoras de Dirección**

Ahora que sabemos cómo hacer que el GalaxyRVR emita colores, vamos a combinar esta función con :ref:`rvr_move`.

1. Crea un nuevo proyecto.

2. Primero, configura los bloques de eventos de teclas y los bloques de movimiento para las cuatro direcciones.

.. image:: img/9_rgb_move.png

3. Añade visualizaciones de colores a cada evento: verde para avanzar.

.. image:: img/9_rgb_green.png

4. Amarillo para girar a la izquierda y derecha.

.. image:: img/9_rgb_yellow.png

5. Rojo para retroceder.

.. image:: img/9_rgb_red.png

Ahora, cuando hagas clic en las teclas de dirección en el área del escenario, verás que el GalaxyRVR se mueve e ilumina en el color correspondiente.

**Luz de Respiración**

Una luz de respiración es un efecto en el que la luz se ilumina y se atenúa gradualmente, similar al ritmo de la respiración. A continuación, vamos a añadir un efecto de luz de respiración cuando el GalaxyRVR esté detenido.

1. Crea un nuevo mensaje de transmisión llamado detener. Esto le dirá a tu programa que el GalaxyRVR está en estado detenido.

.. image:: img/9_rgb_new_message.png

.. note:: Si tu sprite tiene muchas acciones que realizar, pero necesita iniciar ciertas acciones en momentos específicos o bajo ciertas condiciones, el bloque de transmisión puede ayudarte a gestionar esto. De esta manera, tu sprite puede ejecutar diferentes acciones en el orden deseado sin desordenar el código, haciéndolo más claro y fácil de entender.

2. Añade esta transmisión después de cada evento de tecla direccional.

.. image:: img/9_rgb_new_boardcast.png

3. Arrastra un bloque cuando reciba [detener].

.. image:: img/9_rgb_when_receive.png

4. Configura el brillo al 0%, comenzando nuestra luz de respiración desde 0 de brillo.

.. image:: img/9_rgb_set_bright.png

5. Usa un bloque repetir 10 para crear un cambio gradual en el brillo. Aquí usamos la luz azul, aumentando el brillo en un 10% cada 0.2 segundos.

.. image:: img/9_rgb_increase.png

6. Sigue con un bloque para disminuir el brillo en un 10% cada 0.2 segundos, completando un ciclo de respiración.

.. image:: img/9_rgb_decrease.png

7. Transmite detener de nuevo al final para crear un efecto de respiración continuo.

.. image:: img/9_rgb_stopagain.png

8. Si controlas directamente el GalaxyRVR en este punto, es posible que notes que los colores y el brillo están desincronizados. Por lo tanto, añade un bloque detener otros scripts en sprite al final de cada evento de tecla.

.. image:: img/9_rgb_stop.png

9. Dado que los cambios de brillo ocurren en el evento detener, restablece el brillo de la luz en cada evento de tecla.

.. image:: img/9_rgb_set_bright_each.png

Ahora, cuando presiones las teclas de dirección en el escenario, el GalaxyRVR se moverá y se iluminará en el color correspondiente. Cuando dejes de controlarlo, permanecerá quieto y emitirá una luz de respiración lentamente.

Bloques Relacionados con el Módulo RGB
------------------------------------------

.. image:: img/block/rgb_display.png

Ilumina la tira de LED RGB bajo tu GalaxyRVR con el color que elijas. Puedes:

    * Hacer clic en el parche de color para seleccionar el color deseado.

.. image:: img/block/rgb_display_1s.png

Ilumina la tira de LED RGB bajo tu GalaxyRVR con el color que elijas durante 1 segundo. Puedes:

    * Hacer clic en el parche de color para seleccionar el color deseado.
    * Modificar el número para cambiar la duración de la visualización de luz.

.. image:: img/block/rgb_display_RGB.png

Ilumina la tira de LED RGB bajo tu GalaxyRVR con un color de tu elección, utilizando valores RGB para modificar el color (al ajustar la proporción de luces primarias roja, verde y azul, puedes producir cualquier color), lo cual es muy útil para proyectos que involucren degradados de color. Puedes:

    * Modificar el valor R para ajustar el brillo de la luz roja, dentro de un rango de 0-255.
    * Modificar el valor G para ajustar el brillo de la luz verde, dentro de un rango de 0-255.
    * Modificar el valor B para ajustar el brillo de la luz azul, dentro de un rango de 0-255.

.. image:: img/block/rgb_display_RGB_1s.png

Ilumina la tira de LED RGB bajo tu GalaxyRVR con un color de tu elección durante 1 segundo utilizando valores RGB. Puedes:

    * Modificar el valor R para ajustar el brillo de la luz roja, dentro de un rango de 0-255.
    * Modificar el valor G para ajustar el brillo de la luz verde, dentro de un rango de 0-255.
    * Modificar el valor B para ajustar el brillo de la luz azul, dentro de un rango de 0-255.
    * Modificar la duración para cambiar cuánto tiempo se muestra la luz.

.. image:: img/block/rgb_set_brightness.png

Este bloque se utiliza para configurar el brillo de las luces, con un rango de 0 a 100.

.. image:: img/block/rgb_increase_brightness.png

Este bloque incrementa (o disminuye) el brillo de las luces. El valor puede ser negativo.

.. image:: img/block/rgb_turn_on.png

Apaga (o enciende) la tira de LED RGB bajo tu GalaxyRVR.

