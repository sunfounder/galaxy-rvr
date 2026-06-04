Lección 5: Movimiento del Rover
======================================================

Preparados, jóvenes exploradores. Hemos dominado el control de los motores, ahora estamos llevando esas habilidades al planeta rojo. En esta lección, daremos vida al Mars Rover.

Aprenderemos a ensamblar los motores en el sistema de suspensión Rocker-Bogie y luego, usando nuestras habilidades de programación, guiaremos a nuestro Rover a través de imaginarios paisajes marcianos.

Es una aventura marciana en nuestro salón de clases. ¡Empecemos!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      Su navegador no soporta la etiqueta de video.
   </video>

.. note::

    Si estás aprendiendo este curso después de haber ensamblado completamente el GalaxyRVR, debes mover este interruptor hacia la derecha antes de cargar el código.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Objetivos de Aprendizaje
---------------------------

* Comprender cómo ensamblar los motores en el sistema de suspensión Rocker-Bogie del Mars Rover.
* Aprender a usar Arduino para controlar el movimiento del Mars Rover.
* Practicar la escritura de un programa para controlar el movimiento del Mars Rover en diferentes terrenos.

Materiales Necesarios
--------------------------
* Placa SunFounder R3
* Motores TT
* Shield GalaxyRVR
* Batería
* Modelo Mars Rover (Equipado con Sistema Rocker-Bogie)
* Herramientas básicas y accesorios (ej. destornillador, tornillos, etc.)
* Cable USB
* Arduino IDE
* Computadora

Pasos
--------------

**Paso 1: Ensamblaje de los Componentes del Rover**

En este paso, ensamblaremos la batería, la placa R3, el Shield GalaxyRVR, los motores y las ruedas en el sistema rocker-bogie preensamblado. Esto pondrá el GalaxyRVR en un estado operable.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/lu8K26MY96s" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

¡Felicidades! Hemos construido con éxito nuestro propio rover, y está listo para comenzar a explorar. ¡Pongámonos en marcha!

**Paso 2: Pon el Rover en Movimiento**

Ahora es momento de darle vida a nuestra creación y enviarla en su viaje inaugural.
Pero ¿cómo nos comunicamos con nuestro rover? ¿Cómo le decimos a dónde ir y qué hacer?
¡Ahí es donde nuestras habilidades de programación entran en juego!

En el mundo real, si queremos que un auto avance, presionamos el acelerador y ambas ruedas comienzan a girar.
Las ruedas del lado derecho giran en sentido horario, mientras que las del lado izquierdo giran en sentido antihorario.

.. image:: img/move_car.gif
    :align: center

Imagina que estás sentado en el asiento del conductor, con el mundo pasando velozmente mientras conduces por la carretera abierta; esa es exactamente la experiencia que le daremos a nuestro rover.

Ahora, traduzcamos esa experiencia al lenguaje que nuestro rover entiende: ¡código!

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Define the pins of motors
        const int in1 = 2;
        const int in2 = 3;
        const int in3 = 4;
        const int in4 = 5;

        void setup() {
            // Initialize SoftPWM
            SoftPWMBegin();
        }

        void loop() {
            // Set the left motors rotate counterclockwise
            SoftPWMSet(in1, 255);  // Full speed
            SoftPWMSet(in2, 0);    // Stop

            // Set the right motors rotate clockwise
            SoftPWMSet(in3, 0);    // Stop
            SoftPWMSet(in4, 255);  // Full speed

        }

En este código, le estamos hablando a nuestro rover, diciéndole exactamente qué hacer.
Con la función ``SoftPWMSet()``, actuamos como el acelerador y los frenos del auto,
controlando la velocidad y dirección de cada motor.
Le decimos a los motores izquierdos que giren en sentido antihorario y a los motores derechos que giren en sentido horario, y así, ¡nuestro rover avanza!

Sin duda, el concepto de reversa del rover es sencillo una vez que entiendes como moverlo hacia adelante.
Para hacer que el rover retroceda, solo necesitamos invertir la dirección de rotación de cada motor.

Así es como lo haríamos en código, hacemos justo lo opuesto. Las ruedas derechas deben girar ahora en sentido antihorario, y las ruedas izquierdas deben girar en sentido horario.

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Define the pins of motors
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set the left motors to rotate clockwise
        SoftPWMSet(in1, 0);    // Stop
        SoftPWMSet(in2, 255);  // Full speed

        // Set the right motors to rotate counterclockwise
        SoftPWMSet(in3, 255);  // Full speed
        SoftPWMSet(in4, 0);    // Stop

    }

En este código, usamos ``SoftPWMSet()`` para indicar a los motores izquierdos que giren en sentido horario y a los motores derechos que giren en sentido antihorario.

¿No es fascinante que podamos controlar el viaje de nuestro rover simplemente con código? La próxima vez que estés en un auto, tómate un momento para pensar en el viaje de tu rover, explorando el mundo una rotación a la vez. Mantente atento, ¡porque el viaje de nuestro rover apenas comienza!

**Paso 3: Haciendo que el Rover se Mueva en Otras Direcciones**

Ahora que sabemos cómo mover nuestro Mars Rover hacia adelante y hacia atrás, ¿qué pasa si queremos que gire a la izquierda o a la derecha?

Al igual que en la conducción de la vida real, hay dos formas principales para que un auto gire a la izquierda.

* La primera forma es haciendo que las ruedas del lado izquierdo giren más lento que las del derecho. Esta diferencia de velocidad hará que el rover gire hacia la izquierda.
* La segunda forma es haciendo que ambos motores, izquierdo y derecho, giren en la misma dirección (en sentido horario en este caso), lo que hará que el rover gire sobre su propio eje hacia la izquierda.

Veamos cómo podemos implementar ambas formas en código:

**Método 1: Diferentes velocidades en cada lado**

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Define the pins of motors
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set the left motors rotate counterclockwise in low speed
        SoftPWMSet(in1, 40);
        SoftPWMSet(in2, 0);

        // Set the right motors rotate clockwise in higher speed
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 200);

        delay(2000);  // Last for 2 seconds
    }

En este código, hemos disminuido la velocidad de los motores izquierdos mientras mantenemos los motores derechos a una velocidad mayor. Esto hará que el rover gire hacia la izquierda.

**Método 2: Girando todos los motores en la misma dirección**

.. code-block:: arduino
    :emphasize-lines: 16,17,18,19

    #include <SoftPWM.h>

    // Define the motor pins
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set all motors to rotate clockwise
        SoftPWMSet(in1, 0);
        SoftPWMSet(in2, 255);
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 255);
    }

En este código, configuramos todos los motores para que giren en sentido horario. El rover girará sobre su propio eje y la dirección cambiará hacia la izquierda.

Para hacer que el rover gire a la derecha, los conceptos son los mismos pero las direcciones están invertidas. ¿Puedes descubrir cómo hacerlo?

**Paso 4: Moviéndose en Todas las Direcciones**

A medida que desarrollamos más funcionalidades para nuestro Mars Rover, nuestro código podría volverse bastante largo y desordenado. En programación, es una buena práctica mantener tu código organizado y mantenible. Una forma de lograr esto es creando funciones separadas para tareas separadas.

En este caso, podemos crear funciones separadas para cada dirección en la que el rover puede moverse. Esto no solo hace que nuestro código sea más fácil de entender, sino que también nos permite reutilizar estas funciones en cualquier parte de nuestro programa sin tener que reescribir las mismas líneas de código.

Veamos cómo podemos hacer esto:

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/90c13522-9757-4212-b250-63ffbc790fd3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Con esta estructura, nuestro bucle principal se mantiene simple y fácil de seguir. Podemos ver claramente que el rover avanza, luego retrocede,
luego gira a la izquierda y a la derecha, y finalmente se detiene.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      Su navegador no soporta la etiqueta de video.
   </video>

Los detalles de cómo se logra cada una de estas acciones están ocultos en funciones separadas. Este es un aspecto clave de las buenas prácticas de programación conocido como abstracción.

**Paso 5: Compartir y Reflexionar**

¡Felicidades por completar este viaje de exploración con el Mars Rover! Esta es una aplicación práctica de tus conocimientos de ciencia e ingeniería, ¡y lo hiciste fantásticamente!

Ahora, puedes compartir cómo tu rover supera diversos obstáculos del terreno. Podrías filmar tu rover navegando por diferentes terrenos, o mostrar tu rover a tus amigos.

Reflexionar sobre tu proceso de aprendizaje también es muy importante. ¿Qué has aprendido durante este proceso? ¿Surgió alguna idea nueva o pensamiento creativo? ¿Qué has ganado en el control de motores y la programación?

Puedes continuar explorando, descubriendo nuevos conocimientos y mejorándote constantemente. ¡Sigue así, futuros científicos e ingenieros!
