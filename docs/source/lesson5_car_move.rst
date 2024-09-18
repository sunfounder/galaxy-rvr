.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Adéntrate en el mundo de Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirte?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] ¡y únete hoy mismo!


Lección 5: Desatando la movilidad del Rover Marciano
=========================================================

¡Prepárense, jóvenes exploradores! Hemos dominado el control de motores, ahora llevaremos esas habilidades al planeta rojo. En esta lección, ¡daremos vida al Rover Marciano!

Aprenderemos cómo ensamblar los motores en el sistema de suspensión Rocker-Bogie y luego, utilizando nuestras habilidades de codificación, guiaremos a nuestro rover a través de paisajes marcianos imaginarios.

Es una aventura marciana en nuestro salón de clases. ¡Comencemos!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. note::

    Si estás aprendiendo este curso después de haber ensamblado completamente el GalaxyRVR, debes mover este interruptor hacia la derecha antes de cargar el código.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Objetivos de aprendizaje
---------------------------

* Comprender cómo ensamblar los motores en el sistema de suspensión Rocker-Bogie del Rover Marciano.
* Aprender a usar Arduino para controlar el movimiento del Rover Marciano.
* Practicar la escritura de un programa para controlar el movimiento del Rover en diferentes terrenos.

Materiales necesarios
--------------------------
* Placa SunFounder R3
* Motores TT
* Shield GalaxyRVR
* Batería
* Modelo del Rover Marciano (equipado con el sistema Rocker-Bogie)
* Herramientas y accesorios básicos (como destornilladores, tornillos, etc.)
* Cable USB
* Arduino IDE
* Computadora

Pasos
--------------

**Paso 1: Ensamblando los componentes del Rover**

En este paso, ensamblaremos la batería, la placa R3, el Shield GalaxyRVR, los motores y las ruedas en el sistema Rocker-Bogie preensamblado. Esto pondrá al GalaxyRVR en estado de funcionamiento.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/lu8K26MY96s" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

¡Felicidades! Hemos ensamblado con éxito nuestro propio rover y está listo para comenzar a explorar. ¡Pongámonos en marcha!

**Paso 2: Pon el Rover en movimiento**

Ahora es momento de darle vida a nuestra creación y enviarlo a su primer viaje. 
¿Pero cómo nos comunicamos con nuestro rover? ¿Cómo le decimos a dónde ir y qué hacer? 
¡Ahí es donde entran en juego nuestras habilidades de codificación!

En el mundo real, si queremos que un coche avance, presionamos el acelerador y ambas ruedas comienzan a girar. 
Las ruedas del lado derecho giran en el sentido de las agujas del reloj, mientras que las del lado izquierdo giran en sentido antihorario.

.. image:: img/move_car.gif
    :align: center

Imagina que estás sentado en el asiento del conductor, viendo el mundo pasar mientras avanzas por una carretera abierta. Esa es exactamente la experiencia que le vamos a dar a nuestro rover.

Ahora, traducimos esa experiencia al lenguaje que entiende nuestro rover: ¡código!

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Definir los pines de los motores
        const int in1 = 2;
        const int in2 = 3;
        const int in3 = 4;
        const int in4 = 5;

        void setup() {
            // Inicializar SoftPWM
            SoftPWMBegin();
        }

        void loop() {
            // Configurar los motores izquierdos para que giren en sentido antihorario
            SoftPWMSet(in1, 255);  // Velocidad máxima
            SoftPWMSet(in2, 0);    // Detener
            
            // Configurar los motores derechos para que giren en sentido horario
            SoftPWMSet(in3, 0);    // Detener
            SoftPWMSet(in4, 255);  // Velocidad máxima
        }

En este código, estamos "hablando" con nuestro rover, diciéndole exactamente qué hacer. 
Con la función ``SoftPWMSet()``, actuamos como el acelerador y el freno del coche, controlando la velocidad y la dirección de cada motor. 
Le decimos a los motores izquierdos que giren en sentido antihorario y a los derechos en sentido horario, ¡y así, nuestro rover avanza!

El concepto de hacer que el rover retroceda es bastante sencillo una vez que entiendes cómo hacerlo avanzar.
Para que el rover retroceda, solo necesitamos invertir la dirección de rotación de cada motor. 

Así es como lo haríamos en el código, simplemente hacemos lo contrario. Ahora las ruedas derechas deben girar en sentido antihorario y las izquierdas en sentido horario.

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Definir los pines de los motores 
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Inicializar SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Configurar los motores izquierdos para que giren en sentido horario
        SoftPWMSet(in1, 0);    // Detener
        SoftPWMSet(in2, 255);  // Velocidad máxima

        // Configurar los motores derechos para que giren en sentido antihorario
        SoftPWMSet(in3, 255);  // Velocidad máxima
        SoftPWMSet(in4, 0);    // Detener
    }

En este código, utilizamos ``SoftPWMSet()`` para indicar a los motores izquierdos que giren en sentido horario y a los motores derechos que giren en sentido antihorario.

¿No es fascinante que podamos controlar el recorrido de nuestro rover simplemente con código? La próxima vez que estés en un coche, tómate un momento para pensar en el viaje de tu rover, explorando el mundo una rotación a la vez. ¡Mantente atento, porque el viaje de nuestro rover apenas comienza!

**Paso 3: Haciendo que el Rover se mueva en otras direcciones**

Ahora que sabemos cómo hacer que nuestro Rover Marciano avance y retroceda, ¿qué pasa si queremos que gire a la izquierda o a la derecha?

Al igual que en la conducción real, hay dos formas principales de hacer que un coche gire a la izquierda.

* La primera es hacer que las ruedas del lado izquierdo giren más lento que las del lado derecho. Esta diferencia de velocidad hará que el rover gire hacia la izquierda.
* La segunda forma es hacer que ambos motores (izquierdo y derecho) giren en la misma dirección (en este caso en sentido horario), lo que hará que el rover gire sobre su eje hacia la izquierda.

Veamos cómo podemos implementar ambas formas en el código:

**Método 1: Diferentes velocidades en cada lado**

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Definir los pines de los motores 
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Inicializar SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Configurar los motores izquierdos para que giren en sentido antihorario a baja velocidad
        SoftPWMSet(in1, 40);
        SoftPWMSet(in2, 0);

        // Configurar los motores derechos para que giren en sentido horario a mayor velocidad
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 200);

        delay(2000);  // Duración de 2 segundos
    }

En este código, hemos reducido la velocidad de los motores izquierdos mientras mantenemos los derechos a mayor velocidad. Esto hará que el rover gire hacia la izquierda.

**Método 2: Hacer que todos los motores giren en la misma dirección**

.. code-block:: arduino
    :emphasize-lines: 16,17,18,19

    #include <SoftPWM.h>

    // Definir los pines de los motores
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Inicializar SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Configurar todos los motores para que giren en sentido horario
        SoftPWMSet(in1, 0);
        SoftPWMSet(in2, 255);
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 255);
    }

En este código, configuramos todos los motores para que giren en sentido horario. El rover girará sobre su propio eje y la dirección cambiará hacia la izquierda.

Para hacer que el rover gire a la derecha, los conceptos son los mismos, pero las direcciones se invierten. ¿Puedes descubrir cómo hacerlo?

**Paso 4: Movimiento en todas las direcciones**

A medida que desarrollamos más funcionalidades para nuestro Rover Marciano, nuestro código podría volverse bastante largo y desorganizado. En programación, es una buena práctica mantener el código organizado y fácil de mantener. Una forma de lograr esto es creando funciones separadas para cada tarea.

En este caso, podemos crear funciones separadas para cada dirección en la que el rover puede moverse. Esto no solo hace que el código sea más fácil de entender, sino que también nos permite reutilizar estas funciones en cualquier parte de nuestro programa sin tener que reescribir las mismas líneas de código.

Veamos cómo podemos hacerlo:

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/90c13522-9757-4212-b250-63ffbc790fd3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Con esta estructura, nuestro bucle principal permanece simple y fácil de seguir. Podemos ver claramente que el rover avanza, luego retrocede, 
gira a la izquierda y a la derecha, y finalmente se detiene.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Los detalles de cómo se logra cada una de estas acciones están ocultos en funciones separadas. Este es un aspecto clave de las buenas prácticas de programación conocido como abstracción.


**Paso 5: Compartir y reflexionar**

¡Felicidades por completar este viaje de exploración con el Rover Marciano! Esta es una aplicación práctica de tu conocimiento de ciencia e ingeniería, ¡y lo has hecho de manera excelente!

Ahora, puedes compartir cómo tu rover supera diversos obstáculos del terreno. Podrías grabar a tu rover navegando por diferentes terrenos, o mostrar tu rover a tus amigos.

Reflexionar sobre tu proceso de aprendizaje también es muy importante. ¿Qué has aprendido durante este proceso? ¿Surgieron nuevas ideas o pensamientos creativos? ¿Qué has ganado en el control de motores y la programación?

Puedes seguir explorando, descubriendo nuevos conocimientos y mejorando constantemente. ¡Sigue así, futuros científicos e ingenieros!

