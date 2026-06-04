Lección 6: Evasión de Obstáculos por Infrarrojos
==============================================================

¡Nos adentramos en el mundo del Módulo Infrarrojo de Evitación de Obstáculos! Situados a los lados de nuestro Mars Rover, estos sensores actúan como los "ojos" del rover, ayudándolo a esquivar obstáculos laterales y navegar de forma segura por el paisaje marciano.

Aprenderemos a integrar estos módulos con nuestro rover, descubriremos la magia detrás de su funcionamiento y desarrollaremos código para que nuestro rover sortee inteligentemente cualquier obstáculo que encuentre.

¡Prepárate para equipar nuestro rover con inteligencia marciana para esquivar obstáculos! ¡Pongámonos en marcha!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_ir1.mp4" type="video/mp4">
      Tu navegador no soporta la etiqueta de video.
   </video>

.. note::

    Si estás aprendiendo este curso después de haber ensamblado completamente el GalaxyRVR, debes mover este interruptor hacia la derecha antes de cargar el código.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Objetivos de Aprendizaje
------------------------

* Comprender el principio de funcionamiento y la aplicación del módulo infrarrojo de evitación de obstáculos.
* Aprender a usar Arduino para controlar el módulo infrarrojo de evitación de obstáculos.
* Practicar el diseño y la construcción de un sistema automático de evitación de obstáculos basado en infrarrojos.

Materiales Necesarios
---------------------

* Módulos de Evitación de Obstáculos
* Herramientas y accesorios básicos (p. ej., destornillador, tornillos, cables, etc.)
* Modelo Mars Rover (Equipado con sistema rocker-bogie, placas principales, motores)
* Cable USB
* Arduino IDE
* Computadora

Pasos
-------------
**Paso 1: Instalar el Módulo de Evitación de Obstáculos**

Ahora instalaremos los dos módulos de evitación de obstáculos en el rover.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/UWEj_ROYAt0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Los pasos de montaje fueron sencillos, ¿verdad? En los siguientes pasos, aprenderemos sobre el principio de funcionamiento de estos módulos y cómo ayudan a nuestro Mars Rover a evitar obstáculos. ¡Mantente atento!


**Paso 2: Desmitificando el Módulo**

Conoce el Módulo Infrarrojo de Evitación de Obstáculos, el compañero inteligente de nuestro rover. Este pequeño dispositivo está lleno de maravillas. Hagamos un recorrido:

.. image:: img/ir_avoid.png
    :width: 300
    :align: center


Aquí están las definiciones de los pines:

* **GND**: Es como el ancla del módulo, conectándolo a tierra o al punto común del circuito.
* **+**: Aquí es donde el módulo obtiene su energía, necesitando una alimentación de 3.3 a 5V DC.
* **Out**: Es el comunicador del módulo. Por defecto, permanece en alto y solo se pone en bajo cuando detecta un obstáculo.
* **EN**: Conoce el controlador del módulo. Este pin **enable** (habilitación) decide cuándo debe funcionar el módulo. Por defecto, está conectado a GND, lo que significa que el módulo está siempre activo.


¿Sientes curiosidad por saber cómo funciona este pequeño módulo? ¡Es bastante interesante! Utiliza un par de componentes IR: un transmisor y un receptor. El transmisor es como la linterna del módulo, emitiendo luz infrarroja.
Cuando aparece un obstáculo, la luz infrarroja rebota y es captada por el receptor. El módulo emite entonces una señal baja, alertando a nuestro rover del obstáculo.

.. image:: img/ir_receive.png
    :align: center

Nuestro pequeño módulo es bastante robusto: detecta obstáculos en un rango de 2 a 40 cm y cuenta con excelentes capacidades de antinterferencias.
Sin embargo, el color de los objetos afecta su detección. Los objetos más oscuros, especialmente los negros, se detectan a una distancia menor.
Contra una pared blanca, el sensor es más eficiente, detectando en el rango de 2 a 30 cm.


El estado de nivel bajo del pin **EN** activa el módulo, con el puente (jumper) asegurando el pin **EN** a GND. Si deseas controlar el pin **EN** mediante código, el puente debe retirarse.

.. image:: img/ir_cap.png
    :width: 400
    :align: center

Hay dos potenciómetros en el módulo, uno para ajustar la potencia de transmisión y otro para ajustar la frecuencia de transmisión. Ajustando estos dos potenciómetros puedes modificar su distancia efectiva.

.. image:: img/ir_avoid_pot.png
    :width: 400
    :align: center


Eso es bastante sobre nuestro pequeño módulo. En el siguiente paso, aprenderemos cómo integrarlo con nuestro rover y controlarlo usando Arduino. ¡Mantente atento!


**Paso 3: Leer desde los 2 Módulos**

Al igual que curiosos exploradores espaciales, ¡sumerjámonos en el universo de los códigos y los sensores!


#. Nuestro Mars Rover está equipado con dos sensores especiales "Ojo Alienígena", colocados en los pines 7 (derecho) y 8 (izquierdo). Estos sensores "Ojo Alienígena" son en realidad nuestros módulos infrarrojos de evitación de obstáculos, siempre vigilantes para esquivar cualquier "roca espacial" (obstáculo) en el viaje interestelar de nuestro Rover.

    .. image:: img/ir_shield.png

#. A continuación, necesitaremos comunicarnos con nuestro Rover usando el lenguaje universal del código Arduino.


    Primero lo primero, asignemos un nombre único a cada ojo del Rover. Llamémoslos ``IR_RIGHT`` e ``IR_LEFT``, así no los confundiremos.

        .. code-block:: arduino

            #define IR_RIGHT 7
            #define IR_LEFT 8

    Ahora, hacemos saber a nuestro Rover que estos son sus ojos especiales: alimentarán de información del mundo exterior el cerebro electrónico del Rover.

        .. code-block:: arduino

            pinMode(IR_RIGHT, INPUT);
            pinMode(IR_LEFT, INPUT);


    Para asegurarnos de que nuestro Rover comparte sus descubrimientos con nosotros, establecemos una línea de comunicación secreta, como espías en una película de ciencia ficción. Esta siguiente línea inicia una conversación serie a una velocidad de 9600 bits por segundo, ¡eso es un parloteo ultrarrápido!

        .. code-block:: arduino

            Serial.begin(9600);


    Ahora, nuestro Rover escanea su entorno con sus "Ojos Alienígenas" y nos transmite los resultados. Si detecta un obstáculo, el valor será 0; si el camino está despejado, el valor será 1. Sigue enviándonos estos mensajes, manteniéndonos al tanto.

        .. code-block:: arduino

            int rightValue = digitalRead(IR_RIGHT);
            int leftValue = digitalRead(IR_LEFT);
            Serial.print("Right IR: ");
            Serial.println(rightValue);
            Serial.print("Left IR: ");
            Serial.println(leftValue);


    Finalmente, el Rover hace una pausa (de unos 200 milisegundos) después de cada transmisión. Esta pequeña pausa nos da la oportunidad de interpretar el mensaje del Rover antes de que envíe el siguiente.

        .. code-block:: arduino

            delay(200);

    Aquí está el código completo:

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/98546821-5f4b-42ae-bc9f-e7ec15544c8b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que tu código esté listo, selecciona la placa y el puerto correctos, y transmite el código a tu Mars Rover. Luego, sintoniza nuestra línea de comunicación secreta (el Monitor Serie) haciendo clic en su icono en la esquina superior derecha.

    .. image:: img/ir_open_serial.png

#. Antes de comenzar a recibir los mensajes del Rover, asegúrate de que tu línea de comunicación secreta esté sintonizada a la misma velocidad (9600 baudios) que tu Rover. ¡Y ahí lo tienes: actualizaciones en vivo de tu Mars Rover!

    .. image:: img/ir_serial.png

#. Para poner a prueba nuestro sistema, agita una "roca espacial" (tu mano) frente a uno de los sensores. Verás que el valor cambia a 0 y el LED correspondiente en el módulo se enciende. Eso es el Rover diciendo: "¡Cuidado, roca espacial a mi derecha!"

    .. code-block::

        Right IR: 0
        Left IR: 1
        Right IR: 0
        Left IR: 1
        Right IR: 0
        Left IR: 1

¡Hasta ahora, no solo has viajado por el espacio sino que también has descifrado el marciano! ¡No puedo esperar a ver qué secretos interestelares descubriremos en nuestra próxima misión!

**Paso 4: Ajustando la Distancia de Detección**

Hemos llegado a un paso esencial: ajustar las distancias de detección de nuestros sensores según el entorno actual. La configuración de fábrica puede no ser la óptima.

Si la distancia de detección de los dos módulos infrarrojos es demasiado corta, el Mars Rover podría chocar con obstáculos. Si es demasiado larga, el Rover podría empezar a girar cuando aún esté a una distancia considerable de un obstáculo, afectando potencialmente su movimiento.

Aquí te explicamos cómo hacer los ajustes:


#. Comienza ajustando el módulo de evitación de obstáculos derecho. Durante el transporte, los golpes pueden inclinar el transmisor y el receptor del módulo infrarrojo. Por lo tanto, debes enderezarlos manualmente.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
            Tu navegador no soporta la etiqueta de video.
        </video>

#. Coloca un obstáculo a unos 20 cm directamente frente al módulo derecho. ¡La caja en la que vino nuestro kit Rover es una buena opción para esto! Ahora, gira el potenciómetro del módulo hasta que la luz indicadora del módulo se encienda. Luego, sigue moviendo el obstáculo hacia adelante y hacia atrás para verificar si la luz indicadora se enciende a la distancia deseada. Si la luz no se enciende a la distancia correcta o si permanece encendida sin apagarse, deberás ajustar el otro potenciómetro.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
            Tu navegador no soporta la etiqueta de video.
        </video>


#. Repite el mismo proceso para el otro módulo.

Ahora que nuestros sensores están completamente preparados, ¡embarquémonos en el próximo viaje!

**Paso 5: Diseñar un Sistema Automático de Evitación de Obstáculos**

Ahora, demos un gran salto en nuestra exploración espacial y utilicemos estos mensajes del Rover.
¡Vamos a crear un sistema automático de evitación de obstáculos!

Aquí está nuestro plan: Si el sensor derecho detecta un obstáculo, el Rover girará hacia atrás a la derecha. Si el sensor izquierdo detecta un obstáculo, el Rover girará hacia atrás a la izquierda. Si ambos sensores detectan un obstáculo, el Rover se moverá hacia atrás. Si no se detectan obstáculos, el Rover continuará avanzando en línea recta.

Visualicemos esto en un diagrama de flujo para que quede aún más claro. Los diagramas de flujo son una excelente manera de esbozar lógicamente un plan, ¡especialmente cuando se trata de programación!

.. image:: img/ir_flowchart.png

Susurremos este plan a nuestro Rover en su lenguaje (código Arduino):

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/af6539d4-7b4b-4e74-a04a-9fa069391d4d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

En este código, estamos usando la sentencia ``if...else`` en la función ``loop()``.

    La sentencia ``if...else`` se utiliza para ejecutar un bloque de código entre dos alternativas.
    Sin embargo, cuando necesitamos elegir entre más de dos alternativas, usamos la sentencia ``if...else if...else``.

    La sintaxis de la sentencia ``if...else if...else`` es:

    .. code-block:: arduino

        if (condition1) {
        // code block 1
        }
        else if (condition2){
        // code block 2
        }
        else if (condition3){
        // code block 3
        }
        else {
        // code block 4
        }

    Aquí,

    * Si condition1 es verdadera, se ejecuta el bloque de código 1.
    * Si condition1 es falsa, entonces se evalúa condition2.
    * Si condition2 es verdadera, se ejecuta el bloque de código 2.
    * Si condition2 es falsa, entonces se evalúa condition3.
    * Si condition3 es verdadera, se ejecuta el bloque de código 3.
    * Si condition3 es falsa, se ejecuta el bloque de código 4.

Ahora que hemos diseñado nuestro sistema automático de evitación de obstáculos, ¡llega la parte emocionante: ponerlo a prueba!

* Puedes observar si el Rover se mueve como esperabas.
* O, colócalo en diferentes condiciones de iluminación para ver cómo cambian sus movimientos.

Al integrar la ciencia en nuestro proyecto de ingeniería, nos estamos convirtiendo en detectives espaciales, resolviendo los misterios del comportamiento de nuestro Rover.
No solo se trata de corregir errores, sino de optimizar el rendimiento, ¡haciendo que nuestro Rover sea lo mejor posible! ¡Sigan con el fantástico trabajo, detectives espaciales!


**Paso 6: Reflexión y Resumen**

En la fase de pruebas, es posible que hayas notado un comportamiento interesante de nuestro Mars Rover: aunque evita hábilmente los obstáculos a su izquierda y derecha, podría tener dificultades para detectar obstáculos más pequeños directamente al frente.

¿Cómo podemos resolver este desafío?

Mantente atento a la próxima lección, donde continuaremos nuestra exploración del fascinante mundo de la programación, los sensores y la detección de obstáculos.

Recuerda, cada desafío es una oportunidad para aprender e innovar. Y a medida que continuamos nuestro viaje de exploración espacial, ¡hay mucho más por descubrir y aprender!
