.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Profundiza en el mundo de Raspberry Pi, Arduino y ESP32 con otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Previsualizaciones exclusivas**: Obtén acceso anticipado a los anuncios de nuevos productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones especiales durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy mismo!


Lección 4: Dominando el Motor TT
=====================================

En las lecciones anteriores, exploramos los rovers de Marte, sus sistemas de suspensión y profundizamos en el conocimiento sobre Arduino.

En este emocionante curso, exploraremos el funcionamiento de los motores, un componente clave que impulsa los rovers marcianos.
Entenderemos los principios que alimentan estos motores y aprenderemos a controlarlos utilizando la placa SunFounder R3 y el Shield GalaxyRVR.

Al final de este curso, tendrás una comprensión sólida del funcionamiento de los motores y experiencia práctica en su control.

¡Vamos a sumergirnos!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/left_1.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::

    Si estás aprendiendo este curso después de haber ensamblado completamente el GalaxyRVR, debes mover este interruptor hacia la derecha antes de cargar el código.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Objetivos del Curso
--------------------------
* Comprender los principios básicos de los motores y las características del motor TT.
* Aprender a controlar la dirección y la velocidad del motor TT.
* Entender cómo el Shield GalaxyRVR controla seis motores.


Materiales del Curso
-----------------------

* Placa SunFounder R3
* Motor TT
* Shield GalaxyRVR
* Batería
* Cable USB
* Arduino IDE
* Computadora

Pasos del Curso
------------------

**Paso 1: ¿Qué es un motor?**

Los motores juegan un papel fundamental en nuestras vidas diarias. ¡Están por todas partes! Desde los ventiladores eléctricos que nos refrescan en los días calurosos, los batidores que nos ayudan a hacer deliciosos pasteles, hasta los coches eléctricos que recorren las calles: ¡los motores hacen que las cosas se muevan!

.. image:: img/motor_application.jpg

Un motor es como el corazón de una máquina. Convierte la energía eléctrica en energía mecánica, dando vida a nuestros juguetes, electrodomésticos e incluso a grandes vehículos.

El "truco" detrás de un motor no es magia, es ciencia, específicamente el principio de la inducción electromagnética. Así es como funciona: cuando se suministra electricidad a un motor, se genera un campo magnético. Este campo magnético interactúa con otros imanes dentro del motor, lo que provoca que el motor gire. Este giro, como el giro de un trompo, se puede utilizar para mover ruedas, hélices u otras partes móviles de una máquina.

.. image:: img/motor_rotate.gif
    :align: center

El tipo de motor en el que nos enfocamos en nuestro GalaxyRVR es un motor con engranajes específico llamado Motor TT.

.. image:: img/tt_motor_xh.jpg
    :align: center
    :width: 400

Este es esencialmente un motor regular combinado con una serie de engranajes, todos encerrados en una carcasa de plástico.

A medida que el motor gira, los engranajes transforman este giro en movimiento para las ruedas de nuestro rover. El uso de engranajes proporciona un beneficio crucial: aumenta el torque, lo que permite que el motor mueva cargas más grandes y pesadas.

.. image:: img/motor_internal.gif
    :align: center
    :width: 600

¿No es fascinante ver cómo los principios de la ciencia y la ingeniería cobran vida? Los motores son un ejemplo perfecto de estos principios en acción. Al entender cómo funcionan los motores, podemos imaginar e inventar una amplia gama de máquinas. ¡Vamos a profundizar en el mundo de los motores y liberar nuestra creatividad!


**Paso 2: Explorando el Funcionamiento y Operación del Motor**

Habiendo comprendido qué es un motor y su amplio espectro de aplicaciones, es hora de adentrarnos en el funcionamiento interno de un motor.

Esencialmente, un motor funciona bajo el principio del electromagnetismo. Cuando una corriente eléctrica pasa a través de un cable, genera un campo magnético a su alrededor. Este campo magnético puede interactuar con otros campos magnéticos, causando movimiento.

Considera un experimento simple donde conectamos un motor directamente a una batería. La corriente de la batería fluye hacia el motor, activando el mecanismo interno del motor y haciendo que comience a girar. Esta acción de giro se debe a las fuerzas magnéticas dentro del motor.

    .. image:: img/motor_battery.png

Curiosamente, si inviertes las conexiones a la batería, el motor gira en la dirección opuesta. Esto sucede porque la dirección del flujo de corriente cambia, alterando el sentido del campo magnético y, en consecuencia, la dirección del giro del motor.

Ahora sabemos que conectar el motor directamente a una batería puede hacerlo girar, pero a menudo queremos controlar su movimiento con código, por lo que incluimos una placa Arduino entre ambos. Pero, ¿qué sucedería si intentáramos conectar el motor directamente a los pines de señal en la placa Arduino?

.. image:: img/motor_uno.png
    :width: 600
    :align: center

Si adivinaste que el motor no giraría, ¡tienes razón! ¿Pero por qué?

La respuesta radica en la salida de corriente de la placa Arduino. Los pines de señal de una placa Arduino típica solo pueden emitir alrededor de 20mA de corriente, lo cual es insuficiente para impulsar un motor.

Entonces, ¿cómo podemos controlar motores utilizando nuestro Arduino? Aquí es donde entra en juego un componente crucial: un controlador de motor. Piensa en un controlador de motor como un puente entre el Arduino y el motor. Toma la señal de control de baja corriente del Arduino, la amplifica y la envía al motor, lo que permite que gire.

.. image:: img/motor_uno2.png

En nuestro próximo paso, profundizaremos en los detalles del controlador de motor y entenderemos cómo podemos usarlo eficazmente con nuestra placa Arduino para controlar un motor. ¡Mantente atento para más aprendizaje emocionante!


**Paso 3: Cómo el motor es controlado por el controlador de motor**

El Shield GalaxyRVR, incluido en el kit, sirve como el centro de control para nuestro Rover Marciano. Es el centro donde conectamos todos nuestros sensores, motores y la fuente de alimentación. Consiste en varios componentes que nos permiten controlar y alimentar nuestro Rover de manera efectiva.

En el lado derecho del shield, notarás seis puertos para motores. Sin embargo, están agrupados en dos conjuntos, cada uno controlado por un chip controlador de motor separado. Tres puertos marcados como "Izquierda" son controlados por un chip, y los otros tres puertos marcados como "Derecha" son controlados por otro.

.. image:: img/motor_shield.png

Aprendamos cómo estos dos chips controladores manejan los seis motores a través de una experiencia práctica:

* **1. Conectando el circuito**

    #. Conecta el Shield GalaxyRVR a la placa R3, conecta un motor, y finalmente conecta la batería para alimentar la placa de expansión.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/connect_shield.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    #. La primera vez que lo uses, se recomienda que conectes un cable USB Tipo-C para cargar completamente la batería primero. Luego enciende la alimentación.
    
        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/plug_usbc.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

* **2. Escribir y cargar el código**

    #. Abre el Arduino IDE e ingresa el siguiente código:

        .. code-block:: arduino

            void setup() {
                pinMode(2, OUTPUT);
                pinMode(3, OUTPUT);
            }

            void loop() {
                digitalWrite(2, LOW);
                digitalWrite(3, HIGH);
            }
    
        * ``pinMode()``: Esta función configura un pin como INPUT o OUTPUT, similar a decidir si un personaje en nuestra historia habla (OUTPUT) o escucha (INPUT).
        * ``digitalWrite()``: Esta función puede establecer un pin en HIGH (encendido) o LOW (apagado), como encender o apagar una luz mágica.

    #. Una vez que hayas seleccionado la placa correcta (Arduino Uno) y el puerto, haz clic en el botón **Upload**. Es como poner una carta en el buzón: ¡estás enviando tus instrucciones al Arduino!

        .. image:: img/motor_upload.png
        
    #. Una vez que el código se haya cargado correctamente, verás que el motor comienza a girar en sentido horario.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/left_1.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>
    
* **3. Sobre la conexión interna del circuito**

    #. Puedes conectar otros dos motores en los puertos marcados como "Izquierda". Verás que giran simultáneamente.

    #. Ahora, entendamos el principio simple de cómo los dos chips controladores manejan los seis motores. Los pines 2 y 3 en la placa Arduino envían señales al chip controlador del motor, y el otro extremo del chip está conectado a tres motores en paralelo. De manera similar, los pines 4 y 5 envían señales a otro chip controlador, que a su vez está conectado a otros tres motores en paralelo.

        .. image:: img/motor_driver.png
            :width: 500

    #. Si deseas probar el otro chip controlador, solo necesitas cambiar los pines a ``4`` y ``5``.

        .. code-block:: arduino
            :emphasize-lines: 10,11

            const int in3 = 4;
            const int in4 = 5;

            void setup() {
                pinMode(in3, OUTPUT);
                pinMode(in4, OUTPUT);
            }

            void loop() {
                digitalWrite(in3, LOW);
                digitalWrite(in4, HIGH);
            }

        Aquí, definimos dos variables para representar los pines 4 y 5. Al usar variables, podemos gestionar y ajustar fácilmente las asignaciones de pines en todo nuestro código.

        Piensa en ello como si estuviéramos asignando un rol específico a cada número de pin. Cuando decidimos reasignar los roles, en lugar de cambiar cada instancia en todo el script, solo actualizamos la asignación al principio del script (donde se define la variable inicialmente).


* **4. Sobre la lógica de control**

    #. En las pruebas anteriores, habrás notado que los motores giran en una dirección. ¿Cómo hacemos que giren en la dirección opuesta? Alguien podría sugerir intercambiar el HIGH y LOW de los dos pines. Eso es correcto.

        .. code-block:: arduino
            :emphasize-lines: 1,2

            const int in3 = 4;
            const int in4 = 5;

            void setup() {
                pinMode(in3, OUTPUT);
                pinMode(in4, OUTPUT);
            }

            void loop() {
                digitalWrite(in3, HIGH);
                digitalWrite(in4, LOW);
            }

        Una vez que hayas escrito tu código y lo hayas cargado en tu placa Arduino, el motor se comportará según las instrucciones.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/right_cc.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

#. Ahora, echemos un vistazo a la lógica de control interna del chip controlador.

    .. list-table::
        :widths: 25 25 50
        :header-rows: 1

        * - INA
          - INB
          - Motor
        * - L
          - L
          - En espera
        * - L
          - H
          - Sentido horario
        * - H
          - L
          - Sentido antihorario
        * - H
          - H
          - Freno

#. Ahora, intentemos hacer que el motor gire en sentido horario durante 2 segundos, en sentido antihorario durante 2 segundos y luego se detenga.

    .. code-block:: arduino
        :emphasize-lines: 10,11,12,13,14,15,16,17,18

        const int in3 = 4;
        const int in4 = 5;
        
        void setup() {
            pinMode(in3, OUTPUT);
            pinMode(in4, OUTPUT);
        }
        
        void loop() {
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
            delay(2000);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
            delay(2000);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, HIGH);
            delay(5000);
        }

    * Aquí utilizamos la función ``delay()`` para hacer que Arduino haga una pausa por un tiempo determinado, como si tomara una breve siesta en medio de nuestra historia.
    * En el código, usamos el estado de "Freno" para detener el motor, y notarás que el motor se detiene abruptamente. Prueba estableciendo ambos pines en LOW para probar el estado de "En espera", y verás que el motor se desacelera gradualmente hasta detenerse.

Ahora deberías tener una mejor comprensión de cómo el chip controlador de motores controla los motores a través del Shield GalaxyRVR y cómo podemos usar el código Arduino para manipular los movimientos del motor. ¿No es fascinante cómo unas pocas líneas de código pueden dictar el comportamiento de un objeto físico como nuestro motor?

Considera las siguientes preguntas a medida que avanzas:

* Si movemos todo el código desde la función ``loop()`` a la función ``setup()``, ¿cómo cambiaría el comportamiento del motor?
* ¿Cómo modificarías el código para controlar seis motores simultáneamente?

Recuerda, cuanto más experimentes y juegues con tu código, más aprenderás. Siéntete libre de ajustar, modificar y optimizar tu código según lo consideres necesario. ¡Feliz programación!


**Paso 4: Control de la velocidad del motor**

En el paso anterior, controlamos la dirección del motor simplemente estableciendo sus pines en HIGH o LOW. 
Esto es como darle al motor toda la potencia para que funcione, similar a presionar el pedal del acelerador a fondo en un coche. 
Pero en muchas situaciones, es posible que queramos ajustar la velocidad del motor para adaptarla a diferentes escenarios, 
tal como ajustamos la velocidad de un coche dependiendo de si estamos conduciendo en una ciudad o en una autopista. 
Aquí es donde entra en juego la Modulación por Ancho de Pulso (PWM).

.. image:: img/motor_pwm.jpg

PWM es una técnica que se utiliza para crear el efecto de salida de voltaje variable al cambiar rápidamente la salida entre HIGH y LOW. 
Con PWM, podemos simular el efecto de una señal analógica mientras en realidad solo enviamos señales digitales.

Puede que esto te resulte difícil de entender, ¡y está bien! Aprenderemos cómo ajustar la velocidad del motor utilizando PWM mediante programación en las siguientes secciones.

Ten en cuenta que aunque la placa SunFounder R3 tiene algunos pines con funcionalidad PWM integrada, no podemos utilizarlos para nuestro motor porque ya están cumpliendo otras funciones. Por lo tanto, conectamos los chips controladores a los pines 2, 3, 4 y 5, y utilizamos la biblioteca SoftPWM de Arduino para habilitar PWM en estos pines.

Esto es lo que haremos a continuación:

#. Abre Arduino IDE, busca ``softpwm`` en el **ADMINISTRADOR DE BIBLIOTECAS** e instálala.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Ingresa el siguiente código en Arduino IDE. Después de cargar el código con éxito, el motor girará en sentido horario.

    .. code-block:: arduino
        :emphasize-lines: 1, 7,11,12

        #include <SoftPWM.h>

        const int in1 = 2;
        const int in2 = 3;

        void setup() {
            SoftPWMBegin();
        }

        void loop() {
            SoftPWMSet(in1, 0);
            SoftPWMSet(in2, 255);

        }

    * En el código anterior, primero añadimos ``SoftPWM.h`` en la parte superior del código, lo que nos permite usar directamente las funciones de la biblioteca ``SoftPWM``.
    * Luego, inicializamos la biblioteca ``SoftPWM`` con la función ``SoftPWMBegin()``.
    * Finalmente, en la función ``loop()``, usamos ``SoftPWMSet()`` para asignar diferentes valores a ``in1`` e ``in2``, poniendo en marcha el motor. Notarás que el efecto es similar a usar directamente ``LOW`` y ``HIGH``, pero aquí utilizamos valores numéricos dentro de un rango de ``0~255``.
    * Recuerda, en el mundo de Arduino, la velocidad se expresa como un valor entre 0 (como un coche en una señal de stop) y 255 (a toda velocidad en la autopista). Así que cuando decimos ``SoftPWMSet(in2, 255)``, ¡estamos diciéndole al motor que avance a toda velocidad!

#. Ahora, ingresemos otros valores y observemos las diferencias en la velocidad del motor.

    .. code-block:: arduino
        :emphasize-lines: 12,13,14,15

        #include <SoftPWM.h>

        const int in1 = 2;
        const int in2 = 3;

        void setup() {
            SoftPWMBegin();
        }

        void loop() {
            SoftPWMSet(in1, 0);
            for (int i = 0; i <= 255; i++) {
                SoftPWMSet(in2, i);
                delay(100);
        }
            delay(1000);
        }

    En el código anterior, utilizamos un bucle ``for`` para incrementar una variable ``i`` hasta ``255``. El bucle ``for`` en el lenguaje C se usa para iterar sobre una parte del programa varias veces. Consiste en tres partes:

    .. image:: img/motor_for123.png
        :width: 400
        :align: center

    * **Inicialización**: Este paso se ejecuta primero y solo una vez cuando ingresamos al bucle por primera vez. Nos permite declarar e inicializar cualquier variable de control del bucle.
    * **Condición**: Este es el siguiente paso después de la inicialización. Si es verdadera, se ejecuta el cuerpo del bucle. Si es falsa, el cuerpo del bucle no se ejecuta y el flujo de control sale del bucle.
    * **Incremento o Decremento**: Después de ejecutar los pasos de Inicialización y Condición, y el código del cuerpo del bucle, se ejecuta el paso de Incremento o Decremento. Esta declaración nos permite actualizar cualquier variable de control del bucle.

    El diagrama de flujo para el bucle ``for`` se muestra a continuación:

    .. image:: img/motor_for.png

    Así que, después de ejecutar el código anterior, verás que la velocidad del motor aumenta gradualmente. Se detiene durante un segundo, y luego comienza nuevamente desde 0 y aumenta gradualmente.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/left_speed.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

En este paso, hemos aprendido sobre la Modulación por Ancho de Pulso (PWM), una técnica para controlar la velocidad de nuestro motor. Al usar la biblioteca SoftPWM de Arduino, podemos ajustar la velocidad del motor, lo que nos permite simular señales analógicas mientras solo enviamos señales digitales. Esto nos proporciona un mayor control sobre los movimientos de nuestro rover y nos prepara para maniobras más complejas en el futuro.

**Paso 5: Reflexiona y mejora**

Habiendo completado esta lección, ahora deberías estar familiarizado con los principios de funcionamiento de los motores, así como con cómo controlar su dirección y velocidad mediante programación.

Pongamos a prueba tu comprensión con estos desafíos:

* ¿Cómo modificarías el bucle ``for`` para reducir gradualmente la velocidad del motor?
* ¿Cómo controlarías el motor para acelerar o desacelerar mientras gira en sentido antihorario?

Puedes experimentar con el código proporcionado para responder a estas preguntas. Siéntete libre de ajustar el código según tus hipótesis y observar los cambios en el comportamiento del motor.

Tus experimentos prácticos y reflexiones sobre estas preguntas profundizarán tu comprensión y mejorarán tus habilidades para resolver problemas. Es a través de desafíos como estos que se produce el verdadero aprendizaje. Recuerda siempre, no hay "correcto" o "incorrecto" en tu viaje exploratorio, ¡todo se trata de aprender y descubrir!

