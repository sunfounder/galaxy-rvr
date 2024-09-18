.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirte?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy!


Lección 12: Conduciendo el Rover con la App
===============================================

En nuestra última aventura, dominamos el uso del SunFounder Controller para explorar el mundo a través de los "ojos" del rover y ajustar su vista controlando el mecanismo de inclinación. ¡Era como darle a nuestro rover marciano el sentido de la vista!

Ahora, imagina que también puedes dirigir a este explorador marciano, guiándolo por el camino que desees. En esta lección, ¡eso es exactamente lo que haremos! Llevaremos nuestra comprensión del SunFounder Controller al siguiente nivel y aprenderemos a maniobrar nuestro rover, dándonos la emocionante experiencia de ser un conductor de rover marciano.

Con nuestro curso STEAM lleno de vida, los niños no solo aprenderán, sino que vivirán la emoción y el asombro de la exploración espacial. ¡Abróchate el cinturón y prepárate para un emocionante viaje!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/camera_app.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

Objetivos de aprendizaje
--------------------------

* Profundizar en el conocimiento del SunFounder Controller.
* Aprender a conducir el rover marciano usando la aplicación móvil.


Materiales necesarios
-------------------------

* Modelo del rover marciano (equipado con todos los componentes, excepto el panel solar y la placa inferior)
* Arduino IDE
* Computadora
* Tableta o smartphone con la aplicación SunFounder Controller instalada

Pasos del curso
--------------------

**Paso 1: Sumérgete en el SunFounder Controller**

En nuestra lección anterior, probamos por primera vez el SunFounder Controller, sus operaciones básicas y usos. Pero seguramente te quedaste con algunas preguntas, ¿verdad? Es hora de saciar esa curiosidad y profundizar en este asombroso dispositivo.

Al crear un nuevo controlador, te encontrarás con una pantalla que al principio puede parecer un enigma.

.. image:: img/app/app_blank.png

Verás una variedad de formas: rectángulos largos, rectángulos cortos y cuadrados grandes, cada uno con identificadores únicos que van de la A a la Q.

¿Alguna vez te has preguntado por qué hay tanta diversidad? ¿Qué significan los identificadores de la A a la Q?

¡Vamos a descubrirlo!

* **Descifrando las formas**

    Por ejemplo, toca en un área rectangular larga. Como abrir un cofre del tesoro, revelarás varios widgets. ¿Recuerdas el **Slider** de nuestra clase anterior? Al deslizarlo hacia la izquierda o derecha controlábamos la inclinación de la cámara del rover. También está el **Gauge**, que puede ser el velocímetro personal de tu rover, ¡y muchos otros widgets más!

    .. image:: img/app/app_long.png

    Si tocas el rectángulo corto, se revelará un conjunto diferente de widgets. El widget **Botón**, como un interruptor binario, emite comandos únicos, mientras que el widget **Micrófono** puede escuchar tus comandos de voz para controlar el rover, entre otros widgets.

    .. image:: img/app/app_short.png

    ¿Y qué pasa con el bloque cuadrado? Alberga el widget **Joystick**, el widget D-pad y el widget Throttle. ¡Y sí, hay más!

    .. image:: img/app/app_square.png

    Por ahora, no te preocupes por la función o el uso de cada widget. Familiarízate con los widgets que alberga cada forma.

* **Aprovechando los widgets**

    A través del contenido anterior, sabemos que hay muchos widgets diferentes. Entonces, ¿para qué pueden ser utilizados?

    Clasificamos estos widgets en dos tipos: widgets de control y widgets de visualización.

    * Los **widgets de control** te permiten manipular la aplicación, y luego el rover recibe estos comandos de control y realiza las acciones correspondientes.
    * Los **widgets de visualización** te permiten mostrar algunos valores en la aplicación, como valores de sensores, etc.

    Para una descripción detallada de estos widgets, consulta: |link_widgets_list|.

    Además, para las funciones, parámetros, etc. relacionados con estos widgets, consulta: |link_ai_camera_library_api|.

* **El papel de los identificadores**

    Cada forma tiene un identificador en la esquina inferior derecha. ¿Por qué? Vamos a entenderlo con un ejemplo.

    En nuestra última clase, añadimos un widget **Slider** en la región **D**. El código para obtener su valor era algo así:

        .. code-block:: arduino

            int16_t sliderD = aiCam.getSlider(REGION_D);
        
    ¿Y si añadimos un widget **Slider** en la región **B**? ¿Cómo cambiaría el código? Tan simple como reemplazar ``REGION_D`` con ``REGION_B``.

        .. code-block:: arduino

            int16_t sliderD = aiCam.getSlider(REGION_B);

    ¿Fácil, verdad? Estos identificadores ayudan a distinguir qué widget has añadido en qué área.


.. note::
    * Instrucciones detalladas sobre cómo crear y añadir widgets, conectar y operar el SunFounder Controller están disponibles en el ``Paso 3`` de la ``Lección 11``.
    * Para operaciones más avanzadas, visita |link_sc_page|.

**Paso 2: Controla el Rover Marciano con Doble Acelerador**

Ahora que hemos profundizado en los widgets del SunFounder Controller, llevemos nuestro juego al siguiente nivel incorporando dos widgets de **Throttle** para comandar el movimiento del Rover Marciano.

#. Coloca un widget **Throttle** en las regiones **K** y **Q**. Necesitarás pulsar el botón |app_edit| en la parte superior derecha para cambiar al modo de edición, y una vez que hayas terminado de configurar todo, haz clic en |app_save| para guardar tus cambios.

    .. image:: img/app/app_throttle.png

#. Como planeamos utilizar dos widgets de **Throttle** para gobernar la movilidad del rover, ajustemos la función que dicta los movimientos del rover en consecuencia:

    .. code-block:: arduino

        // Función para configurar la potencia de los motores
        void carSetMotors(int8_t power_L, int8_t power_R) {
            // Configurar potencia para el motor izquierdo
            if (power_L >= 0) {
                SoftPWMSet(in1, map(power_L, 0, 100, 0, 255));
                SoftPWMSet(in2, 0);
            } else {
                SoftPWMSet(in1, 0);
                SoftPWMSet(in2, map(power_L, 0, -100, 0, 255));
            }

            // Configurar potencia para el motor derecho
            if (power_R >= 0) {
                SoftPWMSet(in3, 0);
                SoftPWMSet(in4, map(power_R, 0, 100, 0, 255));
            } else {
                SoftPWMSet(in3, map(power_R, 0, -100, 0, 255));
                SoftPWMSet(in4, 0);
            }
        }

    La función ``carSetMotors()`` acepta dos argumentos, ``power_L`` y ``power_R``, que son probablemente los ajustes de potencia para los motores izquierdo y derecho, respectivamente. Los valores de estos argumentos varían entre -100 y 100, donde los valores negativos indican movimiento hacia atrás, 0 indica detenerse y los valores positivos indican avance.

    * Configurar potencia para el motor izquierdo:

        * Si ``power_L`` es mayor o igual a 0, el motor izquierdo avanza.

        * ``SoftPWMSet(in1, map(power_L, 0, 100, 0, 255))`` usa la función ``map`` de Arduino para mapear el rango de entrada (0 a 100) al rango de salida (0 a 255), ya que los valores de PWM en Arduino están entre 0 (0% de ciclo de trabajo) y 255 (100% de ciclo de trabajo). Este valor mapeado se pasa a la función ``SoftPWMSet`` junto con ``in1``.

        * Si ``power_L`` es menor que 0, el motor izquierdo retrocede y el rango de entrada de la función ``map`` cambia de 0 a -100.

    * Configurar potencia para el motor derecho:

        * Esto sigue la misma lógica que configurar la potencia para el motor izquierdo, pero usando ``in3`` e ``in4``, y los valores de entrada son ``power_R`` en lugar de ``power_L``.

    En general, esta función toma dos valores de potencia de los motores, los convierte en los valores PWM apropiados y ajusta los valores PWM en los pines correctos para lograr el movimiento deseado.

#. Dentro de la función ``onReceive()``, recupera los valores de los dos widgets de **Throttle** y úsalos como la potencia para los motores izquierdo y derecho del Rover Marciano.

    .. code-block:: arduino
        :emphasize-lines: 9,10,13

        void onReceive() {
            // Obtener el valor del control deslizante en la región D
            int16_t sliderD = aiCam.getSlider(REGION_D);

            // Mover el servo al ángulo indicado por el control deslizante
            myServo.write(int(sliderD));

            // Obtener los valores del acelerador para la izquierda y la derecha
            int throttle_L = aiCam.getThrottle(REGION_K);
            int throttle_R = aiCam.getThrottle(REGION_Q);

            // Configurar la potencia para los motores
            carSetMotors(throttle_L, throttle_R);
        }

Aquí tienes el código completo:

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c70d2598-a1f9-465a-83bb-4ebd38eb74fa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Cada vez que vuelvas a ejecutar el código, necesitarás repetir los siguientes cuatro pasos:

* Antes de subir el código, asegúrate de que el interruptor esté deslizado hacia la derecha.

    .. image:: img/camera_upload.png

* Una vez que el código se haya subido correctamente, desliza el interruptor hacia la izquierda para iniciar la ESP32 CAM.
* Conéctate a la red ``GalaxyRVR``.
* Conéctate y ejecuta el controlador.

Ahora, con un simple deslizamiento del pulgar en tus widgets ``Throttle``, verás el Rover Marciano en acción, avanzando y girando con renovado entusiasmo. ¡Que comience la exploración!

**Paso 3: Visualización de lecturas de sensores**

En nuestro viaje con el SunFounder Controller, hemos interactuado activamente con nuestro Rover Marciano a través de widgets de control, incluidos controles deslizantes para ajustar la inclinación y aceleradores para dictar el movimiento del rover. Pero, ¿qué tal si aprovechamos el poder de los widgets de visualización para pintar un cuadro claro de los alrededores de nuestro rover?

Veamos cómo podemos hacer esto visualizando los valores de los módulos de evitación de infrarrojos (IR) izquierdo y derecho, así como la distancia captada por el módulo ultrasónico. Estos datos en tiempo real nos brindarán una imagen clara del entorno operativo del rover.

Así es como podemos lograrlo:

#. Comienza añadiendo tres widgets de Número a tu SunFounder Controller. No olvides que puedes personalizar sus nombres y unidades usando el botón de configuración.

    .. image:: img/app/app_show.png

#. A continuación, profundicemos en el código. Comienza trayendo fragmentos de código de los módulos de evitación IR y el módulo ultrasónico de nuestras lecciones anteriores.

    .. code-block:: arduino

        ...
        // Definir el pin para el módulo ultrasónico
        #define ULTRASONIC_PIN 10

        // Definir los pines para los módulos IR
        #define IR_RIGHT 7
        #define IR_LEFT 8

        void setup() {
            ...

            // Configurar los pines del módulo IR como entradas
            pinMode(IR_RIGHT, INPUT);
            pinMode(IR_LEFT, INPUT);
        }


        float readSensorData() {
            // Se requiere un retraso de 4 ms, de lo contrario la lectura puede ser 0
            delay(4);

            //Configurar en OUTPUT para enviar la señal
            pinMode(ULTRASONIC_PIN, OUTPUT);

            ...
        }


#. En la función ``onReceive()``, extrae los valores de los módulos de evitación y del sensor ultrasónico. Luego, actualiza estos valores en el diccionario ``sendDoc[]``. Las claves ``N``, ``P`` y ``O`` corresponden a los códigos de las regiones de los tres widgets de Número que has añadido.

    .. code-block:: arduino

        // Función que se ejecuta al recibir datos del Controller
        void onReceive() {

            ...

            // Leer valores de los sensores IR
            int leftValue = digitalRead(IR_LEFT);
            int rightValue = digitalRead(IR_RIGHT);
            aiCam.sendDoc["N"] = leftValue;
            aiCam.sendDoc["P"] = rightValue;
            
            // ultrasónico
            float distance = readSensorData();
            aiCam.sendDoc["O"] = distance;
        }

Aquí tienes el código completo:

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6c867007-a0e8-4f85-980d-ec1cd1a70969/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Una vez que el código se haya subido correctamente, pon en marcha tu SunFounder Controller. Serás recibido con los valores en tiempo real de los módulos de evitación y la distancia detectada por el sensor ultrasónico, lo que te proporcionará una visión clara del entorno inmediato del rover.

.. image:: img/app/app_show_ir_ultrasonic.png

Con este paso completado, has navegado con éxito por el mundo de los widgets de visualización. Siéntete libre de experimentar con diferentes widgets para mostrar la información que te parezca más interesante. ¡Feliz exploración!

**Paso 4: Reflexión y Conclusión**

En esta lección, hemos profundizado en el conocimiento del SunFounder Controller, comprendiendo cómo podemos utilizar sus widgets para no solo dirigir nuestro Rover Marciano, sino también monitorear sus datos ambientales en tiempo real.

Ahora, te planteamos un desafío:

¿Qué tal si añades algunos widgets de Interruptor a tu SunFounder Controller? Con estos interruptores activados, el Rover Marciano podría cambiar entre los modos de evitación y seguimiento. O, ¿por qué no usar los interruptores para controlar la tira de luces, encendiéndola o apagándola, o incluso cambiando su color?

¿Te sientes con confianza para aceptar este reto?

¡Estamos ansiosos por verte superar este desafío!
