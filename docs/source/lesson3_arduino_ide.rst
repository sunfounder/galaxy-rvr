.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirte?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Previsualizaciones exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.


Lección 3: Introducción al Mundo de Arduino y la Programación
================================================================

En nuestra lección anterior, construimos con éxito el sistema de suspensión Rocker-Bogie. Sin embargo, para que funcione, necesitamos proporcionarle energía, una placa de control y una programación que dicte sus movimientos.

En esta lección, nos familiarizaremos con la placa de control y la plataforma de programación que utilizaremos.

.. image:: img/upload_blink.gif

Objetivos del curso
---------------------

* Comprender los conceptos básicos y las funciones de Arduino.
* Conocer la Placa SunFounder R3.
* Instalar Arduino IDE y familiarizarse con su interfaz.
* Aprender las reglas básicas de sintaxis para la programación en Arduino.



Materiales del curso
------------------------

* Placa SunFounder R3
* Arduino IDE
* Cable USB
* Computadora


Introducción a Arduino
--------------------------

Es posible que hayas escuchado el término "Arduino" en varios contextos, pero ¿qué es exactamente y por qué se ha vuelto tan popular?

Arduino es una plataforma de electrónica de código abierto que es fácil de usar tanto para aplicaciones de hardware como de software. Está diseñada para crear dispositivos digitales y objetos interactivos que pueden detectar y controlar el mundo físico a su alrededor.

Vamos a desglosarlo:

* **Código abierto**: Piensa en código abierto como un jardín comunitario. Todos pueden usarlo, contribuir y beneficiarse de él. Con el código abierto, tanto los diseños de las partes físicas (hardware) como las instrucciones de programación (software) se comparten libremente. Esto significa que cualquiera puede usarlos, mejorarlos o crear sus propias versiones. ¡Todo se trata de compartir y ser creativo!

    .. image:: img/arduino_oscomm.png
        :width: 400
        :align: center

* **Microcontrolador**: Un microcontrolador es como el cerebro del Arduino. Es una pequeña computadora que puede ejecutar software simple. Aunque no es tan potente como la computadora que estás usando, es perfecta para tareas simples, como interpretar mensajes de sensores o encender un LED (una pequeña luz).

    .. image:: img/arduino_micro.jpg
        :width: 500
        :align: center

* **Placa de desarrollo**: Imagina la placa de desarrollo como el cuerpo que soporta el cerebro. Es la placa donde se encuentra el microcontrolador y contiene otras partes que ayudan al microcontrolador a interactuar con el mundo. Estas partes incluyen cosas como osciladores (que ayudan con la sincronización), reguladores de voltaje (que controlan los niveles de energía) y conectores para energía y datos (como los enchufes y switches en tu casa).

    .. image:: img/arduino_board.png
        :width: 600
        :align: center

* **Arduino IDE**: Este es como el salón de clases de tu Arduino. Es un programa que se ejecuta en tu computadora, donde puedes escribir las instrucciones que le dicen al Arduino qué hacer. Estas instrucciones se escriben en un lenguaje de programación basado en C++. Una vez que hayas escrito tus instrucciones, puedes enviarlas a la placa Arduino usando un cable USB, ¡como si estuvieras entregando tu tarea!

    .. image:: img/arduino_ide_icon.png
        :width: 200
        :align: center

Ahora que comprendes estas ideas básicas, ¡estás en camino de convertirte en un experto en Arduino!

Luego, realizaremos actividades prácticas para que te familiarices con la programación en Arduino y los principios de ingeniería. 
¡Prepárate para un emocionante viaje de aprendizaje!



Conociendo tu Placa SunFounder R3
--------------------------------------------

Dentro de tu kit, encontrarás una placa azul, que parece una pequeña ciudad llena de torres metálicas y caminos. Pero no te intimides, ¡esta es la placa de desarrollo SunFounder R3! Es una especie de placa Arduino que puede utilizarse para programar y controlar una amplia variedad de dispositivos y proyectos electrónicos.

Vamos a entender sus características clave de manera sencilla:

.. image:: img/sf_r3.jpg
    :width: 800

* **14 Pines digitales**: Piensa en estos pines como pequeños mensajeros. Pueden programarse para enviar (salida) o recibir (entrada) mensajes simples de "sí" o "no" a otras partes de tu rover. Estos mensajes son en realidad señales de "encendido" o "apagado" que la placa usa para controlar cosas como luces o motores.

    * Seis de estos pines especiales pueden incluso enviar mensajes en un tipo de código secreto llamado PWM (Modulación por Ancho de Pulso). Este código puede utilizarse para controlar qué tan brillante es una luz, qué tan rápido gira un motor o incluso dónde se posiciona una parte móvil.

* **6 Pines analógicos**: Estos pines son como los seis sentidos especiales de la placa. Pueden leer señales de diferentes tipos de sensores (como un sensor de temperatura) y luego traducir estas señales a un lenguaje que la placa puede entender y usar en su programación.

* **Conexión USB**: Esta es como el cordón umbilical de la placa. Puedes usarlo para conectar tu placa a tu computadora. Esta conexión permite que tu computadora "enseñe" a la placa qué hacer enviándole un programa que has escrito.

* **Entrada de alimentación**: Esta es la fuente de alimentación de la placa. Puedes conectar una fuente de energía, como una batería o un adaptador de CA a CC, para "alimentar" tu placa con la electricidad que necesita para funcionar.

* **Encabezado ICSP**: Es como una entrada especial para programar la placa. Puede utilizarse si tienes un programador externo (un dispositivo especial para "enseñar" a la placa).

* **Botón de reinicio**: Si lo presionas, es como decirle a la placa que olvide lo que estaba haciendo y que comience su programa desde el principio.

Con estos conceptos básicos, ¡estarás listo para comenzar tus aventuras de programación con la placa SunFounder R3!

.. _install_arduino_ide:

Instalar Arduino IDE
-------------------------

Ahora que entendemos qué es Arduino y la placa Arduino, es hora de comenzar a poner en práctica ese conocimiento. Vamos a instalar el Arduino IDE, que es el software que utilizaremos para programar nuestra placa Arduino.

La última versión del Arduino IDE es la versión 2.0. Está repleta de funciones y es muy fácil de usar. Sin embargo, debes saber que tiene algunos requisitos del sistema:

    * Windows: Win 10 o más reciente, 64 bits
    * Linux: 64 bits
    * Mac OS X: Versión 10.14 "Mojave" o más reciente, 64 bits

Para comenzar, sigue estos pasos:

#. Visita |link_download_arduino| y descarga el IDE para tu versión de sistema operativo.

    .. image:: img/sp_001.png

**Para usuarios de Windows:**

    #. Una vez que hayas descargado el archivo (se llamará algo como ``arduino-ide_xxxx.exe``), haz doble clic en él para iniciar el proceso de instalación.

    #. Verás el **Acuerdo de Licencia**. Tómate un momento para leerlo, y si estás de acuerdo con los términos, haz clic en "Acepto".

        .. image:: img/sp_002.png

    #. A continuación, se te pedirá que elijas las opciones de instalación. Déjalas como están y haz clic en "Siguiente".

        .. image:: img/sp_003.png

    #. Elige dónde deseas instalar el software. Generalmente, es mejor instalarlo en una unidad diferente a la que usa tu sistema.

        .. image:: img/sp_004.png

    #. Haz clic en "Instalar" para comenzar la instalación. Una vez que haya terminado, haz clic en "Finalizar".

        .. image:: img/sp_005.png

**Para usuarios de macOS:**

    Haz doble clic en el archivo descargado (se llamará algo como ``arduino_ide_xxxx.dmg``). Sigue las instrucciones en pantalla para arrastrar la aplicación **Arduino IDE** a la carpeta **Aplicaciones**. Después de unos segundos, el Arduino IDE estará instalado correctamente.

    .. image:: img/macos_install_ide.png
        :width: 800

**Para usuarios de Linux:**

    Puedes encontrar un tutorial detallado sobre cómo instalar el Arduino IDE 2.0 en un sistema Linux aquí: |link_arduino_linux|.


Descubriendo el "Parque de Juegos" del Arduino IDE
------------------------------------------------------

Imaginemos juntos que el Arduino IDE es un parque de juegos lleno de herramientas y gadgets esperando a que los exploremos y juguemos con ellos. A continuación, te guiaré para que entiendas cada rincón de este parque.

.. image:: img/ide-2-overview.png
    :width: 800

Aquí encontrarás lo siguiente en tu "parque de juegos":

* **Verificar / Subir**: Imagina esto como tu elevador mágico. Toma el código que has escrito y lo sube a tu placa Arduino.
* **Seleccionar Placa y Puerto**: Este es tu mapa del tesoro. Muestra automáticamente las placas Arduino que has conectado a tu computadora y te dice su número de puerto.
* **Cuaderno de bocetos**: Esta es tu biblioteca personal. Aquí se almacenan todos tus bocetos (programas) en tu computadora. Además, puede conectarse a la Nube de Arduino para que puedas obtener tus bocetos del mundo en línea también.
* **Administrador de placas**: Piensa en esto como tu caja de herramientas. Aquí puedes encontrar e instalar diferentes paquetes para tu Arduino.
* **Administrador de bibliotecas**: Este es tu cofre del tesoro interminable. Miles de bibliotecas hechas por Arduino y su comunidad te esperan aquí. ¿Necesitas una herramienta o material para tu código? ¡Sumérgete y encuéntralo!
* **Depurador**: Imagina que tuvieras un superpoder que te permitiera probar y depurar tu código en tiempo real, encontrando y solucionando problemas a medida que ocurren. ¡Eso es lo que hace esta herramienta!
* **Buscar**: Piensa en esto como tu lupa. Te ayuda a buscar palabras clave en tu código.
* **Abrir Monitor Serial**: Este es como tu dispositivo de comunicación. Abre una nueva pestaña que permite a tu computadora y a tu placa Arduino enviarse mensajes entre sí.

Ahora que hemos echado un vistazo a este parque de juegos, ¡es hora de sumergirnos y comenzar a crear!


Sube tu Primer Boceto
------------------------

¡Es hora de divertirnos! Vamos a hacer que un LED parpadee, ¡es como decir "¡Hola, Mundo!" en el mundo de Arduino!

La mayoría de las placas Arduino tienen un LED incorporado en el pin 13, lo que hace que este sea un buen experimento inicial.

.. image:: img/1_led.jpg
    :width: 400
    :align: center

Desglosémoslo:

#. **Conéctalo**: Conecta tu placa SunFounder R3 a tu computadora usando un cable USB. Esta es la forma en que daremos energía a nuestra placa y le enviaremos nuestro programa (también llamado "boceto"). Podrías sentir que solo estás conectando un gadget de computadora, ¡pero créeme, estás conectando a un mundo de posibilidades!

    .. image:: img/connect_board_pc.gif

#. **Encuentra el boceto de ejemplo**: En el Arduino IDE, ve a **Archivo** -> **Ejemplos** -> **Básico** -> **Parpadeo**. Lo que verás que aparece es un programa listo para usar que vamos a modificar. ¡Es como recibir un pastel listo para decorar!

    .. image:: img/open_blink.png

#. **Entiende el boceto**: Mira el código en esta nueva ventana. Le dice al Arduino que encienda el LED incorporado (que está en el pin 13) durante un segundo, luego lo apague durante un segundo y repita. ¡Es como enviar código Morse, pero con luz!

    .. image:: img/led_blink.png

#. **Sube el boceto**: Una vez que hayas seleccionado la placa y el puerto correctos, solo haz clic en el botón de subir. Es tan fácil como enviar una carta; ¡estás entregando tus instrucciones a la placa Arduino! La mayoría de las veces, el sistema detectará automáticamente la placa y el puerto por ti.

    .. image:: img/upload_blink.gif

#. **Míralo funcionar**: Si todo va bien, verás que el LED en tu placa Arduino comienza a parpadear. ¡Es como si tu Arduino te estuviera guiñando un ojo!

    .. image:: img/blink_led.gif

¡Has hecho un gran trabajo! Acabas de ejecutar tu primer programa en Arduino, ¡lo que te convierte en un programador de verdad! ¿Qué sigue? Apenas estamos rascando la superficie de lo que Arduino puede hacer. ¿Listo para el próximo desafío?


Algunos Datos Divertidos sobre la Programación en Arduino
--------------------------------------------------------------

¡Es hora de descubrir algunos secretos interesantes sobre la programación en Arduino!

* Magia del Código: ``setup()`` y ``loop()``

    Un boceto en Arduino, o un pedazo de código, es como una obra de teatro de dos actos:

    * ``setup()``: Este es el Acto 1, la escena de apertura. Solo ocurre una vez, cuando tu placa Arduino se despierta por primera vez. Se utiliza para preparar cosas como modos de pines y bibliotecas.
    * ``loop()``: Después del Acto 1, pasamos al Acto 2 que se repite en un bucle hasta que caiga el telón final (¡lo cual solo ocurre si apagamos la energía o presionamos el botón de reinicio!). Esta parte del código es como la parte principal de nuestra obra, donde ocurre toda la acción.

    Pero recuerda, incluso si no hay magia (código) en el ``setup()`` o ``loop()``, aún necesitamos mantenerlos. Son como el escenario: incluso un escenario vacío sigue siendo un escenario.

    .. code-block:: arduino
    
        void setup() {
            // inicializar el pin digital LED_BUILTIN como salida.
            pinMode(LED_BUILTIN, OUTPUT);

            digitalWrite(LED_BUILTIN, HIGH);  // encender el LED (HIGH es el nivel de voltaje)
            delay(1000);                      // esperar un segundo
            digitalWrite(LED_BUILTIN, LOW);   // apagar el LED haciendo que el voltaje sea LOW
            delay(1000);                      // esperar un segundo
        }

        // la función loop se ejecuta una y otra vez
        void loop() {

        }

* Puntuación en el Código

    Al igual que en un libro de cuentos, Arduino usa signos de puntuación especiales para darle sentido al código:

    * ``Punto y coma (;)``: Estos son como los puntos finales en una historia. Le dicen al Arduino "Está bien, he terminado con esta acción. ¿Qué sigue?".
    * ``Llaves {}``: Estas son como el principio y el final de un capítulo. Envuelven trozos de código juntos, marcando dónde comienza y termina una sección.

    Si te olvidas de alguno de estos signos de puntuación, ¡no te preocupes! El Arduino es como un profesor amigable que revisará tu trabajo, señalará dónde están los errores y te mostrará cómo corregirlos. ¡Es parte de la aventura de aprender!

    .. image:: img/blink_error.gif

* Acerca de las Funciones

    Imagina estas funciones como hechizos mágicos. Cada hechizo tiene un efecto específico en nuestra aventura con Arduino:

    * ``pinMode()``: Este hechizo decide si un pin es una ENTRADA o una SALIDA. Es como decidir si un personaje de nuestra historia habla (SALIDA) o escucha (ENTRADA).
    * ``digitalWrite()``: Este hechizo puede hacer que un pin esté en ALTO (encendido) o en BAJO (apagado), como encender y apagar una luz mágica.
    * ``delay()``: Este hechizo hace que el Arduino se detenga por un tiempo determinado, como tomar una breve siesta en medio de nuestra historia.

    Al igual que un libro de hechizos, puedes encontrar todos estos hechizos y muchos más en |link_arduino_web|. ¡Cuantos más hechizos conozcas, más emocionantes podrán ser tus aventuras con Arduino!

* Comentarios: Nuestros Mensajes Secretos

    También tenemos un lenguaje secreto en la programación, llamado ``comentarios``. Estos son mensajes que podemos escribir en nuestro código usando ``//`` o ``/* */``. ¿La parte mágica? ¡El Arduino los ignora por completo! Es un gran lugar para dejar notas para ti mismo o para otros, explicando lo que están haciendo las partes más complicadas del código.

* Legibilidad del Código: Haciendo el Código Amigable

    Aunque puedes escribir tu código de cualquier manera que desees (por ejemplo, colocar punto y coma en una línea separada no causará ningún error), es importante tener en cuenta la legibilidad del código.

    .. image:: img/blink_noerror.gif

    Al igual que escribir una buena historia, la forma en que escribimos el código puede hacer que sea divertido y fácil o aburrido y difícil de leer. Aquí hay algunas formas de hacer que tu código sea más amigable:

    * Usa una indentación adecuada para organizar tus oraciones en párrafos ordenados. Ayuda al lector a entender dónde termina una sección y comienza otra.
    * Usa nombres de variables que tengan sentido. Es como dar un nombre adecuado a un personaje en una historia.
    * Mantén tus funciones pequeñas y simples, como capítulos cortos y concisos en un libro.
    * Deja comentarios en las partes complicadas. Es como dejar una nota al pie para explicar una palabra difícil.

Recuerda, no solo estamos codificando para máquinas, sino también para humanos, ¡así que asegúrate de que tu código cuente una historia clara y comprensible!



**Reflexiona y Mejora**


Tomarse un momento para reflexionar sobre nuestro viaje puede brindarnos conocimientos que podríamos pasar por alto en el frenesí de la exploración. Pregúntate:

* ¿Cuál fue la parte más interesante de esta aventura con Arduino?
* ¿Hubo algún desafío en el camino? ¿Cómo lo superaste?
* ¿Podrías explicarle a un amigo qué es Arduino, qué hace el Arduino IDE o cómo ejecutar un código en Arduino?
* ¿Cómo describirías tu primera experiencia programando con Arduino?
* ¿Qué más te gustaría aprender sobre Arduino?

Al reflexionar sobre estas preguntas, estás profundizando tu comprensión y preparándote para futuras exploraciones. Recuerda siempre que no hay una "respuesta incorrecta" en la reflexión: ¡es tu viaje personal!
