.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lección 3: Entrando en el Mundo de Arduino y la Programación
=============================================================

En nuestra lección anterior, construimos con éxito el Sistema de Suspensión Rocker-Bogie.
Sin embargo, para hacerlo funcional, necesitamos proporcionarle alimentación, una placa de control y programación para dictar sus movimientos.

Así que en esta lección, vamos a familiarizarnos con la placa de control y la plataforma de programación que utilizaremos.

.. image:: img/upload_blink.gif

Objetivos del Curso
-------------------

* Comprender los conceptos básicos y las funciones de Arduino.
* Aprender sobre la Placa SunFounder R3.
* Instalar el IDE de Arduino y familiarizarse con su interfaz.
* Aprender las reglas básicas de sintaxis para la programación con Arduino.



Materiales del Curso
--------------------

* Placa SunFounder R3
* IDE de Arduino
* Cable USB
* Computadora



Introducción a Arduino
------------------------------------------

Es posible que hayas escuchado a menudo el término "Arduino" en varios contextos, pero ¿qué es exactamente y por qué se ha vuelto tan popular?

Arduino es una plataforma electrónica de código abierto que es fácil de usar tanto para aplicaciones de hardware como de software. Está diseñada para crear dispositivos digitales y objetos interactivos que pueden sentir y controlar el mundo físico que los rodea.

Claro, vamos a desglosarlo:

* **Código abierto**: Piensa en el código abierto como un jardín comunitario. Todos pueden usarlo, todos pueden contribuir y todos pueden beneficiarse de él. Con el código abierto, tanto los diseños de las partes físicas (el hardware) como las instrucciones de programación (el software) se comparten libremente. Esto significa que cualquiera puede usarlos, mejorarlos o crear sus propias versiones. ¡Se trata de compartir y creatividad!

    .. image:: img/arduino_oscomm.png
        :width: 400
        :align: center

* **Microcontrolador**: Un microcontrolador es como el cerebro de Arduino. Es una pequeña computadora que puede ejecutar software simple. Aunque no es tan potente como la computadora que estás usando ahora, es perfecto para tareas simples como entender mensajes de sensores o encender un LED (una pequeña luz).

    .. image:: img/arduino_micro.jpg
        :width: 500
        :align: center

* **Placa de Desarrollo**: Imagina la placa de desarrollo como el cuerpo que sostiene al cerebro. Es la placa donde se encuentra el microcontrolador y contiene otras partes que ayudan al microcontrolador a interactuar con el mundo. Estas partes incluyen cosas como osciladores (que ayudan con la sincronización), reguladores de voltaje (que controlan los niveles de energía) y conectores para alimentación y datos (como los enchufes e interruptores en tu casa).

    .. image:: img/arduino_board.png
        :width: 600
        :align: center

* **IDE de Arduino**: Esto es como el aula de enseñanza para tu Arduino. Es un programa que se ejecuta en tu computadora donde puedes escribir las instrucciones que le dicen a tu Arduino qué hacer. Estas instrucciones se escriben en un lenguaje de programación basado en C++. Una vez que has escrito tus instrucciones, puedes enviarlas a la placa Arduino usando un cable USB, ¡como entregar tu tarea!

    .. image:: img/arduino_ide_icon.png
        :width: 200
        :align: center

Ahora que entiendes estas ideas básicas, estás bien encaminado para convertirte en un experto en Arduino.

Luego nos sumergiremos en algunas actividades prácticas para familiarizarte con la programación de Arduino y los principios de ingeniería.
¡Prepárate para un emocionante viaje de aprendizaje!



Conociendo la Placa SunFounder R3
------------------------------------------------------------------

Dentro de tu kit, encontrarás una placa azul, que parece una pequeña ciudad llena de torres metálicas y caminos. ¡Pero no dejes que te intimide! Esta es la placa de desarrollo SunFounder R3, un tipo de placa Arduino que se puede usar para programar y controlar una gran variedad de dispositivos y proyectos electrónicos.

Entendamos sus características clave en términos sencillos:

.. image:: img/sf_r3.jpg
    :width: 800

* **14 Pines Digitales**: Piensa en estos pines como pequeños mensajeros. Se pueden programar para enviar (salida) o recibir (entrada) mensajes simples de "sí" o "no" a otras partes de tu Mars Rover. Estos mensajes son en realidad señales de "encendido" o "apagado" que la placa usa para controlar cosas como luces o motores.

    * Seis de estos pines especiales pueden incluso enviar mensajes en una especie de código secreto llamado PWM (Modulación por Ancho de Pulso). Este código se puede usar para controlar qué tan brillante es una luz, qué tan rápido gira un motor, o incluso dónde se posiciona una pieza móvil.


* **6 Pines Analógicos**: Estos pines son como los seis sentidos especiales de la placa. Pueden leer señales de diferentes tipos de sensores (como un sensor de temperatura) y luego traducir estas señales a un lenguaje que la placa pueda entender y usar en su programación.

* **Conexión USB**: Esto es como el cordón umbilical de la placa. Puedes usarlo para conectar tu placa a tu computadora. Esta conexión permite que tu computadora "enseñe" a la placa qué hacer enviándole un programa que escribas.

* **Conector de Alimentación**: Esta es la fuente de alimentación de la placa. Puedes conectar una fuente de alimentación, como una batería o un adaptador de CA a CC, a este conector para "alimentar" a tu placa con la electricidad que necesita para funcionar.

* **Cabezal ICSP**: Esto es como una entrada especial para programar la placa. Se puede usar si tienes un programador externo (un dispositivo especial para "enseñar" a la placa).

* **Botón de Reinicio**: Si lo presionas, es como decirle a la placa que olvide lo que estaba haciendo y que comience su programa desde el principio.

Con estos conceptos básicos, ¡estarás listo para comenzar tus aventuras de programación con la placa SunFounder R3!

.. _install_arduino_ide:

Instalar el IDE de Arduino
-----------------------------------------------

Ahora que entendemos qué son Arduino y la placa Arduino, es hora de empezar a poner ese conocimiento en práctica. Vamos a instalar el IDE de Arduino, que es el software que usaremos para programar nuestra placa Arduino.

La última versión del IDE de Arduino es la versión 2.0. Está llena de funciones y es súper fácil de usar. Sin embargo, debes saber que tiene algunos requisitos del sistema:

    * Windows - Win 10 y superior, 64 bits
    * Linux - 64 bits
    * Mac OS X - Versión 10.14: "Mojave" o superior, 64 bits

Para comenzar, sigue estos pasos:

#. Visita |link_download_arduino| y descarga el IDE para tu versión de sistema operativo.

    .. image:: img/sp_001.png

**Para usuarios de Windows:**

    #. Una vez que hayas descargado el archivo (se llamará algo como ``arduino-ide_xxxx.exe``), haz doble clic en él para iniciar el proceso de instalación.

    #. Se te mostrará el **Acuerdo de Licencia**. Tómate un momento para leerlo, y si estás de acuerdo con los términos, haz clic en "I Agree".

        .. image:: img/sp_002.png

    #. A continuación, se te pedirá que elijas las opciones de instalación. Déjalas como están y haz clic en "Next".

        .. image:: img/sp_003.png

    #. Elige dónde deseas instalar el software. Generalmente es mejor instalarlo en una unidad diferente a la que usa tu sistema.

        .. image:: img/sp_004.png

    #. Haz clic en "Install" para comenzar la instalación. Una vez que termine, haz clic en "Finish".

        .. image:: img/sp_005.png

**Para usuarios de macOS:**

    Haz doble clic en el archivo descargado (que se llamará algo como ``arduino_ide_xxxx.dmg``). Sigue las instrucciones en pantalla para arrastrar la aplicación **Arduino IDE** a la carpeta **Applications**. Después de unos segundos, el IDE de Arduino se habrá instalado correctamente.

    .. image:: img/macos_install_ide.png
        :width: 800

**Para usuarios de Linux:**

    Puedes encontrar un tutorial detallado sobre cómo instalar el IDE de Arduino 2.0 en un sistema Linux aquí: |link_arduino_linux|.

Descubriendo el Patio de Juegos de Arduino (IDE)
----------------------------------------------------------------

Imaginemos juntos que el IDE de Arduino es un patio de juegos mágico lleno de herramientas y artilugios que esperan ser explorados. A continuación, te guiaré para que conozcas cada rincón de este patio de juegos.


.. image:: img/ide-2-overview.png
    :width: 800

Esto es lo que encontrarás en tu patio de juegos:

* **Verify / Upload (Verificar / Subir)** - Imagina esto como tu ascensor mágico. Toma el código que has escrito y lo transporta rápidamente a tu placa Arduino.
* **Select Board & Port (Seleccionar Placa y Puerto)** - Este es tu mapa del tesoro. Muestra automáticamente las placas Arduino que has conectado a tu computadora e indica su número de puerto.
* **Sketchbook (Libro de Bocetos)** - Esta es tu biblioteca personal. Es donde se almacenan todos tus sketches (programas) en tu computadora. Además, puede conectarse a la nube de Arduino, para que puedas obtener tus sketches desde el mundo en línea también.
* **Boards Manager (Gestor de Placas)** - Piensa en esto como tu caja de herramientas. Es donde puedes encontrar e instalar diferentes paquetes para tu Arduino.
* **Library Manager (Gestor de Bibliotecas)** - Este es tu cofre del tesoro sin fin. Miles de bibliotecas creadas por Arduino y su comunidad te esperan aquí. ¿Necesitas una herramienta o material para tu código? ¡Sumérgete y encuéntralo!
* **Debugger (Depurador)** - Imagina que tuvieras un superpoder que te permitiera probar y depurar tu código en tiempo real, encontrando y solucionando problemas a medida que ocurren. ¡Eso es esto!
* **Search (Buscar)** - Piensa en esto como tu lupa. Te ayuda a buscar palabras clave en tu código.
* **Open Serial Monitor (Abrir Monitor Serie)** - Esto es como tu dispositivo de comunicación. Abre una nueva pestaña que permite que tu computadora y la placa Arduino se envíen mensajes de ida y vuelta.

Ahora que hemos visto el patio de juegos, es hora de sumergirnos y empezar a crear.

.. _upload_sketch:

Sube tu Primer Sketch
-----------------------------------------------

¡Muy bien, es hora de divertirnos! Vamos a hacer parpadear un LED - es como decir "¡Hola, Mundo!" en el mundo de Arduino.

La mayoría de las placas Arduino tienen un LED incorporado en el pin 13, lo que hace que este sea un buen primer experimento.

.. image:: img/1_led.jpg
    :width: 400
    :align: center

Vamos a desglosarlo:

#. **Conéctalo**: Conecta tu Placa SunFounder R3 a tu computadora usando un cable USB. Así es como vamos a alimentar nuestra placa y enviarle nuestro programa (también llamado "sketch"). Puede que sientas que solo estás conectando un dispositivo de computadora, pero créeme, ¡te estás conectando a un mundo de posibilidades!

    .. image:: img/connect_board_pc.gif

#. **Encuentra el ejemplo de sketch**: En el IDE de Arduino, ve a **File** -> **Examples** -> **Basic** -> **Blink**. Lo que ves que aparece es un programa listo para usar que vamos a modificar. ¡Es como tener un pastel ya preparado que estamos a punto de decorar!

    .. image:: img/open_blink.png

#. **Entiende el sketch**: Observa el código en esta nueva ventana. Le indica a Arduino que encienda el LED incorporado (que está en el pin 13) durante un segundo, luego lo apague durante un segundo, y luego repita. ¡Es como enviar código Morse, pero con luz!

    .. image:: img/led_blink.png

#. **Sube el sketch**: Una vez que hayas seleccionado la placa y el puerto correctos, simplemente haz clic en el botón de subir. Es tan fácil como enviar una carta; ¡estás entregando tus instrucciones a la placa Arduino! La mayoría de las veces, el sistema detectará automáticamente la placa y el puerto por ti.

    .. image:: img/upload_blink.gif

#. **Míralo funcionar**: Si todo va bien, verás que el LED en tu placa Arduino comienza a parpadear. ¡Es como si tu Arduino te estuviera guiñando un ojo!

    .. image:: img/blink_led.gif

¡Has hecho un gran trabajo! Acabas de ejecutar tu primer programa de Arduino, ¡convirtiéndote en un programador de verdad! ¿Y ahora qué? Solo estamos arañando la superficie de lo que Arduino puede hacer. ¿Listo para el siguiente desafío?


Datos Curiosos sobre la Programación con Arduino
--------------------------------------------------------

Es hora de descubrir algunos secretos interesantes sobre la programación con Arduino.

* Magia del Código: ``setup()`` y ``loop()``

    Un sketch de Arduino, o un fragmento de código, es como una obra de teatro en dos actos:

    * ``setup()``: Este es el Acto 1, la escena de apertura. Solo ocurre una vez, cuando tu placa Arduino se enciende por primera vez. Se usa para preparar el escenario configurando cosas como los modos de los pines y las bibliotecas.
    * ``loop()``: Después del Acto 1, pasamos al Acto 2, que se repite en un bucle hasta el telón final (¡que solo ocurre si apagamos la alimentación o presionamos el botón de reinicio!). Esta parte del código es como la parte principal de nuestra obra, donde realmente ocurre la acción.

    Pero recuerda, incluso si no hay magia (código) en ``setup()`` o ``loop()``, todavía debemos mantenerlos. Son como el escenario - incluso un escenario vacío sigue siendo un escenario.

    .. code-block:: arduino

        void setup() {
            // initialize digital pin LED_BUILTIN as an output.
            pinMode(LED_BUILTIN, OUTPUT);

            digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
            delay(1000);                      // wait for a second
            digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
            delay(1000);                      // wait for a second
        }

        // the loop function runs over and over again forever
        void loop() {

        }

* Signos de Puntuación en la Programación

    Al igual que en un cuento, Arduino utiliza signos de puntuación especiales para dar sentido al código:

    * ``Punto y coma (;)``: Son como los puntos finales en una historia. Le indican a Arduino "Bien, he terminado con esta acción. ¿Qué sigue?"
    * ``Llaves {}``: Son como el principio y el final de un capítulo. Agrupan partes de código juntas, marcando dónde comienza y termina una sección.

    Si olvidas algunos de estos signos de puntuación, ¡no te preocupes! Arduino es como un profesor amigable que revisará tu trabajo, señalará dónde están los errores y te mostrará cómo solucionarlos. ¡Todo es parte de la aventura de aprendizaje!

    .. image:: img/blink_error.gif

* Acerca de las Funciones

    Imagina estas funciones como hechizos mágicos. Cada hechizo tiene un efecto específico en nuestra aventura con Arduino:

    * ``pinMode()``: Este hechizo decide si un pin es INPUT (entrada) o OUTPUT (salida). Es como decidir si un personaje de nuestra historia habla (OUTPUT) o escucha (INPUT).
    * ``digitalWrite()``: Este hechizo puede poner un pin en HIGH (encendido) o LOW (apagado), como encender y apagar una luz mágica.
    * ``delay()``: Este hechizo hace que Arduino haga una pausa durante un cierto tiempo, como tomar una siesta corta en medio de nuestra historia.

    Al igual que un libro de hechizos, puedes encontrar todos estos hechizos y muchos más en |link_arduino_web|. ¡Cuantos más hechizos conozcas, más emocionantes pueden ser tus aventuras con Arduino!

* Comentarios: Nuestros Mensajes Secretos

    También tenemos un lenguaje secreto en la programación, llamado ``comentarios``. Son mensajes que podemos escribir en nuestro código usando ``//`` o ``/* */``. ¿La parte mágica? ¡Arduino los ignora por completo! Es un gran lugar para dejar notas para ti mismo o para otros, explicando lo que hacen las partes complicadas del código.

* Legibilidad del Código: Haciendo el Código Amigable

    Si bien puedes escribir tu código de la manera que quieras (por ejemplo, colocar los puntos y coma en una línea separada no causará errores), es importante tener en cuenta la legibilidad del código.

    .. image:: img/blink_noerror.gif

    Al igual que escribir una buena historia, la forma en que escribimos el código puede hacer que sea divertido y fácil de leer, o aburrido y difícil. Aquí hay algunas formas de hacer tu código más amigable:

    * Usa una sangría adecuada para organizar tus oraciones en párrafos ordenados. Ayuda al lector a entender dónde termina una sección y comienza otra.
    * Usa nombres de variables que tengan sentido. Es como llamar a un personaje por un nombre adecuado en una historia.
    * Mantén tus funciones pequeñas y simples, como capítulos cortos y dulces en un libro.
    * Deja comentarios para las partes complicadas. Es como dejar una nota al pie para explicar una palabra difícil.

Recuerda, no solo programamos para las máquinas, sino también para los humanos, ¡así que asegurémonos de que nuestro código cuente una historia clara y comprensible!


**Reflexiona y Mejora**


Tomar un momento para reflexionar sobre nuestro viaje puede proporcionarnos ideas que podríamos perder en el ajetreo de la exploración. Pregúntate:

* ¿Cuál fue la parte más interesante de esta aventura con Arduino?
* ¿Hubo algún desafío en el camino? ¿Cómo los superaste?
* ¿Podrías explicarle a un amigo qué es Arduino, qué hace el IDE de Arduino o cómo ejecutar código de Arduino?
* ¿Cómo describirías tu primera experiencia de programación con Arduino?
* ¿Qué más quieres aprender sobre Arduino?

Al reflexionar sobre estas preguntas, estás profundizando tu comprensión y preparándote para futuras exploraciones. Recuerda siempre, no hay una respuesta "incorrecta" en la reflexión – ¡después de todo, es tu viaje personal!
