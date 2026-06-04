
.. _ir_obstacle:

Lección 6 Obstáculo IR
===========================

Conoce los "ojos" laterales de tu rover: ¡los sensores de evitación de obstáculos por infrarrojos!

Estos inteligentes sensores ayudan a tu GalaxyRVR a detectar y esquivar obstáculos a los lados, como si tuviera visión periférica. Aprende cómo funcionan y programa tu rover para navegar alrededor de objetos de forma automática.

Prepárate para convertir tu Mars Rover en un experto evadiendo obstáculos.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_ir1.mp4" type="video/mp4">
      Tu navegador no soporta la etiqueta de video.
   </video>

Objetivos de Aprendizaje
-------------------------

* Comprender los principios de funcionamiento del módulo de evitación de obstáculos por infrarrojos y su aplicación en el Mars rover.
* Aprender a leer y aplicar los datos del módulo de evitación de obstáculos por infrarrojos en Scratch.
* Crear un juego de evitación de obstáculos con temática de exploración marciana utilizando el módulo IR y el escenario de Scratch.

Conoce el Módulo de Evitación de Obstáculos
----------------------------------------------

Saluda al nuevo compañero de tu GalaxyRVR: el módulo de evitación de obstáculos por infrarrojos. Este pequeño y astuto dispositivo ayuda a tu rover a detectar y evitar obstáculos. Veamos cómo funciona:

.. image:: img/ir_avoid.png
    :width: 300
    :align: center

**Conoce los Cuatro Pines Importantes:**

* **GND** —La conexión a tierra (completa el circuito)
* **+** —Entrada de alimentación (necesita electricidad de 3.3V a 5V)
* **Out** —Salida de señal (envía mensajes de "obstáculo detectado")
* **EN** —Pin de habilitación (controla cuándo el módulo está activo)

**Cómo Funciona —La Linterna Invisible:**

Piensa en este módulo como si tuviera una linterna invisible y gafas especiales:

.. image:: img/ir_receive.png
    :align: center

1. El transmisor emite luz infrarroja (invisible a nuestros ojos)
2. Cuando la luz golpea un obstáculo, rebota
3. El receptor "ve" la luz reflejada
4. El módulo envía una señal: "¡Obstáculo adelante!"

**Datos Curiosos Sobre tu Sensor:**

* **Rango de Detección**: 2-40 cm (aproximadamente el largo de tu estuche de lápices)
* **El Color Importa**: Funciona mejor con objetos de color claro
* **Objetos Oscuros**: Más difíciles de detectar desde lejos

**Controles Avanzados (Para Mentes Curiosas):**

* **Pin EN**: El puente (jumper) mantiene el módulo siempre activo. Retíralo si quieres controlar el módulo con código.

  .. image:: img/ir_cap.png
      :width: 400
      :align: center

* **Dos Ajustes**:

  - Un potenciómetro controla qué tan lejos viaja la luz infrarroja
  - Un potenciómetro ajusta la frecuencia de la luz

  .. image:: img/ir_avoid_pot.png
      :width: 400
      :align: center

Ahora que conoces a tu nuevo compañero, conectémoslo a tu rover y comencemos a programar.

Probando tus Sensores Infrarrojos
------------------------------------------------------------

#. Primero, :ref:`app_connect`.

2. ¡Ajustemos tus sensores para un rendimiento perfecto!

   a. Asegúrate de que los componentes infrarrojos estén rectos. Ajusta suavemente si es necesario.

      .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
            </video>

   b. Coloca un objeto (como la caja de tu rover) a 20 cm. Gira el potenciómetro hasta que la luz indicadora se encienda. Prueba moviendo el objeto más cerca y más lejos.

      .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
            </video>

   c. Haz lo mismo con el otro módulo infrarrojo.

3. Luego, :ref:`app_connect`.

4. Busca los bloques "left IR status" y "right IR status" en la categoría GalaxyRVR y marca sus casillas.

   .. image:: img/4_ir_statusblock.png

5. Los valores de los sensores aparecerán ahora en tu escenario.

   .. image:: img/4_ir_statusvalue.png

6. Mueve tu mano cerca de cada sensor infrarrojo y observa cómo cambian los valores.

**Qué Significan los Valores:**

- **True** = Obstáculo detectado
- **False** = Camino despejado

¡Ahora estás listo para ver lo que tu rover puede "ver"!


Programando tu Rover para Evitar Obstáculos
-------------------------------------------------------------

Enseñémosle a tu GalaxyRVR a esquivar obstáculos automáticamente usando sus sensores infrarrojos.

#. Primero, :ref:`app_connect`.

#. Inicia el programa con un bloque de bandera verde.

   .. image:: img/4_ir_start.png

#. Establece una velocidad segura del 30% para facilitar las pruebas y la depuración.

   .. image:: img/4_ir_speed.png

#. Encuentra el bloque ``when left IR is blocked`` para la detección del sensor izquierdo.

   .. image:: img/4_ir_when_blocked.png

#. Cuando el sensor izquierdo detecte un obstáculo, haz que el rover gire a la derecha.

   .. image:: img/4_ir_turn_right.png

#. Sigue girando a la derecha hasta que el lado izquierdo ya no detecte el obstáculo.

   .. image:: img/4_ir_wait_until.png

#. Detén el movimiento una vez que el camino esté despejado.

   .. image:: img/4_ir_stop.png

#. Prueba activando el sensor infrarrojo izquierdo con tu mano. El GalaxyRVR debería girar inteligentemente a la derecha para evitarlo.

#. Duplica el código manteniendo presionados los bloques y seleccionando duplicar en el menú.

   .. image:: img/4_ir_duplicate.png

#. En el código duplicado, intercambia los lados izquierdo y derecho para que maneje los obstáculos del lado derecho.

   .. image:: img/4_ir_left_right.png

#. Para evitar un comportamiento errático cuando ambos sensores se activan a la vez, agrega un bloque "stop other scripts in sprite". Esto asegura que solo se maneje un evento de sensor a la vez.

   .. image:: img/4_ir_stop_script.png
       :width: 800

   .. note:: El bloque de detener scripts puede entrar en conflicto con los bloques de movimiento temporizado, así que evita usarlos juntos cuando sea posible.

#. Ahora tu GalaxyRVR girará a la izquierda o a la derecha cuando se detecten obstáculos en cualquier lado. Prueba activando ambos sensores con tus manos.

#. Agrega un bloque de avance debajo de cada sección de código para que el rover continúe moviéndose después de evitar los obstáculos.

   .. image:: img/4_ir_avoid_move.png
       :width: 800

¡Ahora haz clic en la bandera verde! Tu GalaxyRVR se moverá hacia adelante continuamente, esquivando inteligentemente los obstáculos y reanudando su camino después de evitarlos.

Bloques Relacionados con el Módulo IR
----------------------------------------

* Bloque de evento que se activa cuando el sensor IR izquierdo detecta un obstáculo.

  - Cambia "left" por "right" en el menú desplegable.

  .. image:: img/block/ir_when.png

* Pausa el programa hasta que el sensor IR izquierdo ya no detecte un obstáculo.

  - Cambia "left" por "right" para el otro sensor.
  - Cambia "is not" por "is" para la condición opuesta.

  .. image:: img/block/ir_wait_until.png

* Bloque condicional que devuelve VERDADERO si el sensor IR izquierdo detecta un obstáculo.

  - Perfecto para usar con declaraciones ``if``.
  - Cambia "left" por "right" para el otro sensor.

  .. image:: img/block/ir_condition.png

* Muestra el estado de detección actual del sensor IR izquierdo.

  .. image:: img/block/ir_left_value.png

* Muestra el estado de detección actual del sensor IR derecho.

  .. image:: img/block/ir_right_value.png
