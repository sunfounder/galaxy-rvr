.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Preestrenos exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!



.. _ir_obstacle:


Lección 6 Módulo de Evasión de Obstáculos Infrarrojo
======================================================

Nos adentraremos en el mundo del Módulo de Evasión de Obstáculos Infrarrojo. Colocados en los lados de nuestro Rover marciano, estos sensores actúan como los "ojos" del rover, ayudándolo a esquivar obstáculos laterales y navegar de forma segura por el paisaje marciano.

Aprenderemos a integrar estos módulos con nuestro rover, a desentrañar la magia detrás de su funcionamiento y a desarrollar un código que permita a nuestro rover esquivar inteligentemente cualquier obstáculo que encuentre.

¡Prepárate para equipar nuestro rover con inteligencia para esquivar obstáculos en Marte! ¡Vamos a rodar!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_ir1.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Objetivos de aprendizaje
---------------------------

* Comprender los principios de funcionamiento del Módulo de Evasión de Obstáculos Infrarrojo y su aplicación en el rover marciano.
* Aprender a leer y aplicar los datos del Módulo de Evasión de Obstáculos Infrarrojo en Scratch.
* Crear un juego temático de exploración de Marte utilizando el módulo IR y el escenario de Scratch.


Materiales
-------------

* Teléfono inteligente o tableta
* APP Mammoth Coding
* GalaxyRVR

Desmitificando el módulo
-------------------------------------

Conozcamos el Módulo de Evasión de Obstáculos Infrarrojo, el compañero inteligente de nuestro rover. Este pequeño dispositivo es todo un prodigio. Vamos a hacer un recorrido:

.. image:: ../img/ir_avoid.png
    :width: 300
    :align: center


Aquí están las definiciones de los pines:

* **GND**: Es como el ancla del módulo, conectándolo al punto común o tierra del circuito.
* **+**: Aquí es donde el módulo obtiene su energía, necesitando una fuente de alimentación de 3.3 a 5V DC.
* **Out**: Es el comunicador del módulo. Por defecto, permanece en estado alto y solo pasa a bajo cuando detecta un obstáculo.
* **EN**: Este es el controlador del módulo. Este pin **enable** decide cuándo debe funcionar el módulo. Por defecto, está conectado a GND, lo que significa que el módulo está siempre activo.

¿Tienes curiosidad por saber cómo funciona este pequeño módulo? ¡Es bastante interesante! Utiliza un par de componentes infrarrojos: un transmisor y un receptor. El transmisor es como la linterna del módulo, emitiendo luz infrarroja. 
Cuando aparece un obstáculo, la luz infrarroja rebota y es captada por el receptor. El módulo entonces envía una señal baja, alertando a nuestro rover del obstáculo.

.. image:: ../img/ir_receive.png
    :align: center

Nuestro pequeño módulo es bastante robusto, detectando obstáculos en un rango 
de 2 a 40 cm y cuenta con excelentes capacidades de anti-interferencia. Sin 
embargo, el color de los objetos influye en su capacidad de detección. Los objetos 
más oscuros, especialmente los negros, son detectados a menor distancia. Contra 
una pared blanca, el sensor es más eficiente, detectando en un rango de 2 a 30 cm.

El estado bajo del pin **EN** activa el módulo, con el puente de la tapa asegurando el pin **EN** a GND. Si deseas controlar el pin **EN** mediante código, deberás retirar el puente.

.. image:: ../img/ir_cap.png
    :width: 400
    :align: center

El módulo cuenta con dos potenciómetros: uno para ajustar la potencia de transmisión y otro para ajustar la frecuencia de transmisión. Ajustando estos dos potenciómetros, puedes modificar la distancia efectiva del sensor.

.. image:: ../img/ir_avoid_pot.png
    :width: 400
    :align: center 


Hemos aprendido mucho sobre este pequeño módulo. En el próximo paso, aprenderemos cómo integrarlo con nuestro rover y controlarlo mediante Arduino. ¡Sigue atento!


Valores de detección del Módulo de Evasión de Obstáculos Infrarrojo
-----------------------------------------------------------------------

1. Enciende el GalaxyRVR.

.. raw:: html

   <br></br>

2. Hemos llegado a un paso esencial: ajustar las distancias de detección de nuestros sensores según el entorno actual. La configuración de fábrica puede no ser óptima. Si la distancia de detección de los dos módulos infrarrojos es demasiado corta, el Rover podría colisionar con obstáculos. Si es demasiado larga, el Rover podría comenzar a girar mientras aún está lejos del obstáculo, afectando su movimiento.

    Aquí te mostramos cómo hacer los ajustes:

    a. Comienza ajustando el módulo de evasión de obstáculos derecho. Durante el transporte, las colisiones pueden causar que el transmisor y el receptor en el módulo infrarrojo se inclinen. Por lo tanto, es necesario enderezarlos manualmente.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    b. Coloca un obstáculo a unos 20 cm directamente frente al módulo derecho. La caja en la que vino nuestro kit de Rover es una buena opción para esto. Ahora, gira el potenciómetro en el módulo hasta que la luz indicadora en el módulo se encienda. Luego, sigue moviendo el obstáculo hacia adelante y hacia atrás para verificar si la luz indicadora se enciende a la distancia deseada. Si la luz no se enciende a la distancia correcta o permanece encendida sin apagarse, deberás ajustar el otro potenciómetro.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    c. Repite el mismo proceso con el otro módulo.


3. Veamos qué son estas dos señales. Primero, :ref:`app_connect`.

.. raw:: html

   <br></br>


4. En la categoría GalaxyRVR, encuentra los bloques de estado del IR izquierdo y derecho. Estos almacenan los resultados de detección de los módulos IR. Asegúrate de marcar las casillas correspondientes.

    .. image:: img/4_ir_statusblock.png

5. Los valores se mostrarán ahora en el escenario.

    .. image:: img/4_ir_statusvalue.png

6. Acerca tu mano a los módulos de evasión de obstáculos infrarrojos para activar la detección y observa los cambios de valor en el escenario.

Si los módulos IR detectan un obstáculo, el valor será True; si no detectan un obstáculo, el valor será False.



Respondiendo al Módulo de Evasión de Obstáculos Infrarrojo
--------------------------------------------------------------

Podemos utilizar los módulos de evasión de obstáculos infrarrojos para hacer que el GalaxyRVR esquive automáticamente los obstáculos en ambos lados.

1. Arrastra un bloque de bandera verde.

.. image:: img/4_ir_start.png

2. Establece la velocidad. Aquí configuramos la velocidad al 30%, para que no sea demasiado rápida, lo que facilita la depuración.

.. image:: img/4_ir_speed.png


3. Encuentra el bloque ``cuando el IR izquierdo está bloqueado``.

.. image:: img/4_ir_when_blocked.png

4. Cuando el lado izquierdo detecte un obstáculo, el GalaxyRVR deberá girar hacia la derecha.

.. image:: img/4_ir_turn_right.png

5. Sigue girando a la derecha hasta que el lado izquierdo ya no detecte el obstáculo.

.. image:: img/4_ir_wait_until.png


6. Detén el movimiento.

.. image:: img/4_ir_stop.png


7. Una vez que hayas ensamblado estos bloques, intenta activar el módulo de evasión de obstáculos izquierdo con tu mano. El GalaxyRVR girará inteligentemente a la derecha para evitar tu mano.

.. raw:: html

   <br></br>



8. Mantén presionados estos bloques para abrir un menú donde puedes duplicar el código.

.. image:: img/4_ir_duplicate.png

9. En el código duplicado, intercambia los lados izquierdo y derecho.

.. image:: img/4_ir_left_right.png

10. Notarás que si ambos eventos IR se activan simultáneamente, el comportamiento puede volverse errático. Para evitar esto, el bloque "detener otros scripts en sprite" será útil. Asegura que solo se responda a un evento de sensor a la vez.

.. image:: img/4_ir_stop_script.png

.. note:: El bloque detener scripts y los bloques con parámetros de tiempo (p. ej., avanzar por 1 segundo) pueden entrar en conflicto en algunos casos, por lo que es mejor evitar usarlos juntos cuando sea posible.


11. Ahora, el GalaxyRVR girará a la izquierda o derecha cuando se detecten obstáculos en cualquiera de los lados. Puedes probar esto activando ambos sensores con tu mano para hacer que el GalaxyRVR esquive a izquierda y derecha.

.. raw:: html

   <br></br>


12. Agrega un bloque de avanzar debajo de cada bloque de código para que el GalaxyRVR continúe avanzando después de evitar el obstáculo.

.. image:: img/4_ir_avoid_move.png


Ahora, haz clic en la bandera verde, y el GalaxyRVR avanzará continuamente, girando para evitar obstáculos y reanudando su camino después de evitarlos.



Bloques relacionados con el módulo IR
------------------------------------------

.. image:: img/block/ir_when.png

Este es un bloque de evento que se activa cuando el sensor IR izquierdo detecta un obstáculo. Puedes:

    * Cambiar "izquierdo" por "derecho" en el menú desplegable

.. image:: img/block/ir_wait_until.png

Este bloque pausa el programa hasta que el sensor IR izquierdo ya no detecte un obstáculo, luego continúa. Puedes:

    * Cambiar "izquierdo" por "derecho" en el primer menú desplegable
    * Cambiar "no" por "sí" en el segundo menú desplegable para operar bajo la condición opuesta

.. image:: img/block/ir_condition.png

Este es un bloque condicional que devuelve TRUE si el sensor IR izquierdo detecta un obstáculo, de lo contrario FALSE. Se utiliza comúnmente en bloques que requieren condicionales como ``si``. Puedes:

    * Cambiar "izquierdo" por "derecho" en el menú desplegable

.. image:: img/block/ir_left_value.png

Este bloque muestra si el sensor IR izquierdo detecta actualmente un obstáculo.

.. image:: img/block/ir_right_value.png

Este bloque muestra si el sensor IR derecho detecta actualmente un obstáculo.

