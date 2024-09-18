.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirte?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones especiales durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy mismo!


Lección 6: Explorando el Módulo de Evasión de Obstáculos
==============================================================

Nos adentraremos en el mundo del Módulo Infrarrojo de Evasión de Obstáculos. Ubicados en los lados de nuestro Rover Marciano, estos sensores actúan como los "ojos" del rover, ayudándolo a esquivar obstáculos laterales y a navegar con seguridad por el paisaje marciano.

Aprenderemos cómo integrar estos módulos en nuestro rover, descubrir la magia detrás de su funcionamiento y desarrollar un código para que nuestro rover esquive con inteligencia cualquier obstáculo que encuentre.

¡Prepárate para equipar a nuestro rover con algo de inteligencia evasiva marciana! ¡Pongámonos en marcha!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_ir1.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. note::

    Si estás aprendiendo este curso después de haber ensamblado completamente el GalaxyRVR, debes mover este interruptor hacia la derecha antes de cargar el código.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Objetivos de aprendizaje
---------------------------

* Comprender el principio de funcionamiento y la aplicación del módulo infrarrojo de evasión de obstáculos.
* Aprender a usar Arduino para controlar el módulo infrarrojo de evasión de obstáculos.
* Practicar el diseño y construcción de un sistema automático de evasión de obstáculos basado en el uso de infrarrojos.

Materiales necesarios
----------------------

* Módulos de evasión de obstáculos
* Herramientas y accesorios básicos (ej. destornilladores, tornillos, cables, etc.)
* Modelo del Rover Marciano (equipado con sistema Rocker-Bogie, placas principales, motores)
* Cable USB
* Arduino IDE
* Computadora


Pasos
------------

**Paso 1: Instalar el Módulo de Evasión de Obstáculos**

Ahora instalaremos los dos módulos de evasión de obstáculos en el rover.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/UWEj_ROYAt0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Los pasos de montaje fueron simples, ¿verdad? En los siguientes pasos, aprenderemos sobre el principio de funcionamiento de estos módulos y cómo ayudan a nuestro Rover Marciano a evitar obstáculos. ¡Permanece atento!


**Paso 2: Desmitificando el Módulo**

Conoce el Módulo Infrarrojo de Evasión de Obstáculos, el astuto compañero de nuestro rover. Este pequeño dispositivo está lleno de maravillas. Vamos a descubrir sus secretos:

.. image:: img/ir_avoid.png
    :width: 300
    :align: center

Aquí tienes las definiciones de los pines:

* **GND**: Es como el ancla del módulo, conectándolo a tierra o a un punto común en el circuito.
* **+**: Aquí es donde el módulo obtiene su energía, necesitando una fuente de alimentación de 3.3 a 5V DC.
* **Out**: Es el comunicador del módulo. Por defecto, permanece alto y solo baja cuando detecta un obstáculo.
* **EN**: Es el controlador del módulo. Este pin de **activación** decide cuándo debe funcionar el módulo. Por defecto, está conectado a GND, lo que significa que el módulo siempre está en funcionamiento.

¿Tienes curiosidad por saber cómo funciona este pequeño módulo? ¡Es muy interesante! Utiliza un par de componentes infrarrojos: un transmisor y un receptor. El transmisor es como la linterna del módulo, emitiendo luz infrarroja. 
Cuando aparece un obstáculo, la luz infrarroja rebota y es captada por el receptor. Entonces, el módulo envía una señal baja, alertando a nuestro rover sobre el obstáculo.

.. image:: img/ir_receive.png
    :align: center

Nuestro pequeño módulo es bastante robusto, detectando obstáculos en un rango de 2 a 40 cm y ofreciendo una excelente capacidad antiinterferencias. 
Sin embargo, el color de los objetos afecta su detección. Los objetos más oscuros, especialmente los de color negro, se detectan a una distancia menor. 
Frente a una pared blanca, el sensor es más eficiente, detectando en un rango de 2 a 30 cm.

El estado bajo del pin **EN** activa el módulo, con el puente de conexión asegurando que el pin **EN** esté conectado a GND. Si deseas controlar el pin **EN** mediante código, deberás retirar el puente.

.. image:: img/ir_cap.png
    :width: 400
    :align: center

El módulo cuenta con dos potenciómetros, uno para ajustar la potencia de transmisión y otro para ajustar la frecuencia de transmisión. Al ajustar estos potenciómetros, puedes modificar su distancia efectiva.

.. image:: img/ir_avoid_pot.png
    :width: 400
    :align: center 

Eso es bastante información sobre nuestro pequeño módulo. En el siguiente paso, aprenderemos cómo integrarlo en nuestro rover y controlarlo usando Arduino. ¡Permanece atento!

**Paso 3: Lectura de los 2 Módulos**

Al igual que exploradores espaciales curiosos, ¡vamos a sumergirnos en el universo de los códigos y sensores!

#. Nuestro Rover Marciano está equipado con dos sensores especiales llamados "Ojos de Alien", colocados en los pines 7 (derecho) y 8 (izquierdo). Estos "Ojos de Alien" son en realidad nuestros módulos infrarrojos de evasión de obstáculos, siempre atentos para esquivar cualquier "roca espacial" (obstáculo) en el viaje interestelar de nuestro rover.

    .. image:: img/ir_shield.png

#. A continuación, necesitaremos comunicarnos con nuestro rover utilizando el lenguaje universal del código de Arduino.

    Primero, asignemos un nombre único a cada ojo del rover. Llamémoslos ``IR_RIGHT`` y ``IR_LEFT`` para no confundirnos.

        .. code-block:: arduino

            #define IR_RIGHT 7
            #define IR_LEFT 8

    Ahora, le diremos a nuestro rover que estos son sus ojos especiales: le proporcionarán información del mundo exterior a su cerebro electrónico.

        .. code-block:: arduino

            pinMode(IR_RIGHT, INPUT);
            pinMode(IR_LEFT, INPUT);

    Para asegurarnos de que nuestro rover comparta sus hallazgos con nosotros, establecemos una línea de comunicación secreta, como espías en una película de ciencia ficción. La siguiente línea inicia una conversación en serie a la velocidad de 9600 bits por segundo: ¡es una charla rapidísima!

        .. code-block:: arduino

            Serial.begin(9600);

    Ahora, nuestro rover escanea sus alrededores con sus "Ojos de Alien" y nos informa de lo que encuentra. Si detecta un obstáculo, el valor será 0; si el camino está despejado, el valor será 1. Sigue enviando estos mensajes, manteniéndonos al tanto.

        .. code-block:: arduino

            int rightValue = digitalRead(IR_RIGHT);
            int leftValue = digitalRead(IR_LEFT);
            Serial.print("Right IR: ");
            Serial.println(rightValue);
            Serial.print("Left IR: ");
            Serial.println(leftValue);

    Finalmente, el rover hace una pequeña pausa (de unos 200 milisegundos) después de cada transmisión. Este pequeño descanso nos da tiempo para interpretar el mensaje del rover antes de que envíe otro.

        .. code-block:: arduino

            delay(200);

    Aquí tienes el código completo:

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/98546821-5f4b-42ae-bc9f-e7ec15544c8b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que tu código esté listo, selecciona la placa y el puerto correctos y carga el código en tu Rover Marciano. Luego, sintoniza nuestra línea de comunicación secreta (el Monitor Serial) haciendo clic en su ícono en la esquina superior derecha.

    .. image:: img/ir_open_serial.png

#. Antes de empezar a recibir los mensajes del rover, asegúrate de que la línea de comunicación esté ajustada a la misma velocidad (9600 baudios) que tu rover. ¡Y ahí lo tienes! Actualizaciones en tiempo real desde tu Rover Marciano.

    .. image:: img/ir_serial.png

#. Para probar el sistema, pasa una "roca espacial" (tu mano) frente a uno de los sensores. Verás que el valor cambia a 0, y el LED correspondiente en el módulo se ilumina. Es como si el rover dijera: "¡Cuidado, roca espacial a la derecha!".

    .. code-block::

        Right IR: 0
        Left IR: 1
        Right IR: 0
        Left IR: 1
        Right IR: 0
        Left IR: 1

Hasta ahora, no solo hemos viajado por el espacio, sino que también hemos descifrado el idioma marciano. ¡No puedo esperar a ver qué otros secretos interestelares descubriremos en nuestra próxima misión!

**Paso 4: Ajustando la Distancia de Detección**

Hemos llegado a un paso esencial: ajustar las distancias de detección de nuestros sensores según el entorno actual. La configuración de fábrica puede no ser la óptima.

Si la distancia de detección de los dos módulos infrarrojos es demasiado corta, el Rover Marciano podría chocar con los obstáculos. Si es demasiado larga, el rover podría empezar a girar estando todavía a una distancia significativa del obstáculo, lo que podría afectar su movimiento.

Aquí te mostramos cómo puedes hacer ajustes:

#. Comienza ajustando el módulo de evasión de obstáculos derecho. Durante el transporte, las colisiones pueden haber causado que el transmisor y receptor del módulo infrarrojo se inclinen. Por lo tanto, necesitarás enderezarlos manualmente.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Coloca un obstáculo a unos 20 cm directamente frente al módulo derecho. La caja en la que vino nuestro kit del rover es una buena opción para esto. Ahora, gira el potenciómetro en el módulo hasta que la luz indicadora del módulo se encienda. Luego, sigue moviendo el obstáculo hacia adelante y hacia atrás para verificar si la luz se enciende a la distancia deseada. Si la luz no se enciende a la distancia correcta o si permanece encendida sin apagarse, tendrás que ajustar el otro potenciómetro.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Repite el mismo proceso con el otro módulo.

Ahora que nuestros sensores están completamente preparados, ¡vamos a emprender el próximo viaje!


**Paso 5: Diseñar un Sistema Automático de Evasión de Obstáculos**

Ahora, demos un gran salto en nuestra exploración espacial y hagamos uso de estos mensajes del rover. 
¡Vamos a crear un sistema automático de evasión de obstáculos!

Aquí está nuestro plan: Si el sensor derecho detecta un obstáculo, el rover girará hacia atrás a la derecha. Si el sensor izquierdo detecta un obstáculo, el rover girará hacia atrás a la izquierda. Si ambos sensores detectan un obstáculo, el rover retrocederá. Si no se detectan obstáculos, el rover continuará avanzando.

Visualicemos esto en un diagrama de flujo para que quede aún más claro. ¡Los diagramas de flujo son una excelente manera de delinear lógicamente un plan, especialmente cuando se trata de programación!

.. image:: img/ir_flowchart.png

Vamos a susurrarle este plan a nuestro rover en su idioma (código Arduino):

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/af6539d4-7b4b-4e74-a04a-9fa069391d4d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

En este código, estamos utilizando la declaración ``if...else`` en la función ``loop()``.

    La declaración ``if...else`` se usa para ejecutar un bloque de código entre dos alternativas. 
    Sin embargo, cuando necesitamos elegir entre más de dos alternativas, usamos la declaración ``if...else if...else``.

    La sintaxis de la declaración ``if...else if...else`` es:

    .. code-block:: arduino

        if (condition1) {
        // bloque de código 1
        }
        else if (condition2){
        // bloque de código 2
        }
        else if (condition3){
        // bloque de código 3
        }
        else {
        // bloque de código 4
        }

    Aquí,

    * Si condition1 es verdadera, se ejecuta el bloque de código 1.
    * Si condition1 es falsa, se evalúa condition2.
    * Si condition2 es verdadera, se ejecuta el bloque de código 2.
    * Si condition2 es falsa, se evalúa condition3.
    * Si condition3 es verdadera, se ejecuta el bloque de código 3.
    * Si condition3 es falsa, se ejecuta el bloque de código 4.

Ahora que hemos diseñado nuestro sistema automático de evasión de obstáculos, llega la parte emocionante: ¡ponerlo a prueba!

* Puedes observar si el rover se mueve como esperabas.
* O colócalo en diferentes condiciones de iluminación para ver cómo cambian sus movimientos.

Al integrar la ciencia en nuestro proyecto de ingeniería, nos convertimos en detectives espaciales, resolviendo los misterios del comportamiento de nuestro rover. 
Esto no solo se trata de corregir errores, sino de optimizar el rendimiento, ¡haciendo que nuestro rover sea lo mejor que puede ser! ¡Sigue así, detectives espaciales!

**Paso 6: Reflexión y resumen**

En la fase de prueba, puede que hayas notado un comportamiento interesante de nuestro Rover Marciano: mientras evita obstáculos con destreza a la izquierda y a la derecha, podría tener dificultades para detectar obstáculos más pequeños directamente frente a él.

¿Cómo podemos solucionar este desafío?

Mantente atento a la próxima lección, donde continuaremos nuestra exploración en el fascinante mundo de la programación, los sensores y la detección de obstáculos.

Recuerda, cada desafío es una oportunidad para aprender e innovar. Y a medida que continuamos nuestro viaje de exploración espacial, ¡hay mucho más por descubrir y aprender!

