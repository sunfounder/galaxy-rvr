.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete más en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirte?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy!


Lección 13: Investigando el sistema energético del Rover marciano
=====================================================================

Bienvenidos a la última lección de nuestra aventura con el rover marciano. En esta ocasión, profundizaremos en el corazón del rover: su sistema energético.

Cuando pensamos en explorar planetas lejanos como Marte, uno de los aspectos más importantes a considerar es la energía. 
¿Cómo se alimentan estos rovers en entornos tan duros y remotos? 
En esta lección, exploraremos este fascinante tema y aprenderemos cómo los rovers, como nuestro modelo de rover marciano, captan y gestionan la energía.

Investigaremos los principios de funcionamiento de la batería y el panel solar, y pondremos manos a la obra instalando y utilizando estas fuentes de energía en nuestro modelo de rover. Además, llevaremos nuestras habilidades un paso más allá utilizando Arduino para monitorear el nivel de la batería.

Al final de la lección, seremos capaces de mostrar estas estadísticas vitales en nuestra APP, 
permitiéndonos entender en tiempo real el estado energético de nuestro rover. ¿Listos para energizar nuestra exploración? ¡Vamos allá!

.. image:: img/solar_panel.jpg
    :width: 600
    :align: center

Objetivos de aprendizaje
----------------------------

* Comprender los principios de funcionamiento de la batería y el panel solar.
* Practicar la instalación del panel solar en el modelo del rover marciano.
* Aprender a utilizar Arduino para monitorear el nivel de la batería y el estado de carga del panel solar.
* Mostrar el nivel de la batería en la APP.

Materiales necesarios
------------------------

* Modelo del rover marciano (equipado con todos los componentes, excepto el panel solar y la placa inferior)
* Panel solar y placa inferior
* Arduino IDE
* Computadora
* Tableta o smartphone con la aplicación SunFounder Controller instalada



Pasos del curso
------------------

**Paso 1: Introducción al sistema energético del Rover marciano**

Así como nuestros cuerpos necesitan un suministro constante de energía para funcionar, nuestro rover marciano necesita una forma de almacenar y generar energía para sus misiones de exploración. Imagina el sistema energético del rover como el corazón de nuestros cuerpos. Así como el corazón bombea sangre a todas las partes del cuerpo, suministrando oxígeno y nutrientes necesarios, el sistema energético del rover mantiene el flujo de energía hacia todas las partes del rover, asegurando que pueda realizar sus tareas sin problemas.

Los principales componentes de este sistema energético son las baterías y los paneles solares, que trabajan en conjunto para asegurar que el rover pueda operar en todo momento, ya sea de día o de noche.

El papel de las baterías en el sistema energético del rover es similar al rol de almacenamiento de energía en nuestros cuerpos. Al igual que necesitamos almacenar energía para usar cuando estamos activos, el rover necesita una forma de almacenar energía para sus misiones de exploración. La energía almacenada en las baterías se distribuye continuamente a las distintas partes del rover, permitiéndole realizar sus tareas de manera sistemática.

.. image:: img/battery_galaxyrvr.png
    :width: 600
    :align: center

Pero, ¿qué ocurre cuando se agota la energía de las baterías? ¿Cómo se recargan? Aquí es donde entran en juego los paneles solares.

De la misma manera que los árboles absorben la luz del sol para la fotosíntesis y crear alimento, nuestro rover marciano utiliza paneles solares para captar la energía del Sol, convirtiéndola en electricidad que se almacena en las baterías del rover para su uso. Cada panel solar está compuesto por muchas celdas solares más pequeñas. Estas celdas están hechas de un material que puede convertir la luz en electricidad, un proceso llamado efecto fotovoltaico. Cuando la luz solar incide en las celdas, generan una corriente eléctrica que se puede usar de inmediato o almacenar en las baterías del rover para más tarde.

.. image:: img/solar_panel_gala.png
    :width: 600
    :align: center

Sin embargo, captar energía solar en Marte no es tan fácil como parece. Las tormentas de polvo pueden reducir la cantidad de luz solar que llega a los paneles, y la luz solar marciana, que es más débil que la de la Tierra, significa que los paneles generan menos energía de la que lo harían aquí en casa. A pesar de estos desafíos, la energía solar sigue siendo el método más práctico y eficiente para alimentar nuestro rover marciano.

Pero, ¿cómo sabemos cuándo los paneles solares están funcionando y cuándo las baterías se están quedando sin energía? Aquí es donde entra en juego nuestro Arduino. En la siguiente sección, aprenderemos a usar Arduino para monitorear la carga y descarga de las baterías del rover.


**Paso 2: Montaje del panel solar en el Rover marciano**

Antes de comenzar este paso, necesitamos tener nuestro modelo del rover marciano, un panel solar y los cables necesarios para conectar el panel solar al sistema de energía del rover.

Este es un proceso que nos permite poner en práctica la teoría y apreciar verdaderamente el encanto de la educación en Ciencia, Tecnología, Ingeniería y Matemáticas (STEM). ¡Comencemos!

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/-Vj-dcniFrA" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Paso 3: Programación para monitorear el voltaje y la carga de la batería**

Ahora que hemos instalado los paneles solares en nuestro modelo de rover marciano, el siguiente paso es monitorear el voltaje y la carga de la batería a través de la programación.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2e85e234-9575-4a1f-982b-2f9aba8e3156/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Este código crea un monitor de batería simple pero efectivo, que es especialmente útil en aplicaciones como el Rover marciano donde la gestión de la energía es crucial. Permitirá monitorear el estado de la batería, ayudándote a saber cuándo el rover necesita recargarse o cuándo es conveniente programar tareas que consumen mucha energía.

Vamos a desglosar las diferentes partes de este código:

* Esta línea define ``BATTERY_PIN`` como el pin analógico A3, desde donde se leerá el voltaje de la batería.

    .. code-block:: arduino

        #define BATTERY_PIN A3

* Esta función calcula el voltaje de la batería. Primero lee el valor analógico del ``BATTERY_PIN``, luego lo convierte en voltaje. Dado que el conversor analógico a digital (ADC) del Arduino opera en una escala de 0-1023, dividimos la lectura en bruto entre 1023. Luego multiplicamos por 5 (el voltaje de referencia del Arduino) y por 2 (suponiendo un divisor de voltaje de 2) para convertir esto en una lectura de voltaje.

    .. code-block:: arduino
        :emphasize-lines: 5

        float batteryGetVoltage() {
            // Lee el valor analógico del pin de la batería
            int adcValue = analogRead(BATTERY_PIN);
            // Convierte el valor analógico en voltaje
            float adcVoltage = adcValue / 1023.0 * 5 * 2;
            // Redondea el voltaje a dos decimales
            float batteryVoltage = int(adcVoltage * 100) / 100.0;
            return batteryVoltage;
        }


    La lectura en bruto del ADC del conversor analógico a digital del Arduino se divide por 1023 para convertirla en una fracción, luego se multiplica por 5 para convertirla en voltaje, ya que el Arduino utiliza un voltaje de referencia de 5 voltios.

    Sin embargo, dado que el voltaje de la batería es mayor que el voltaje máximo de entrada del Arduino, se utiliza una resistencia para proteger el Arduino. Por lo tanto, multiplicamos el voltaje del ADC por 2 para contrarrestar el efecto de la resistencia y obtener el voltaje correcto de la batería.

* Esta función calcula el porcentaje de carga de la batería en función de su voltaje. Utiliza la función ``map`` para asignar el valor del voltaje (que varía de 6.6 a 8.4 voltios) a un porcentaje (que va del 0 al 100%).

    .. code-block:: arduino

        uint8_t batteryGetPercentage() {
            float voltage = batteryGetVoltage();  // Obtiene el voltaje de la batería
            // Asigna el voltaje a un porcentaje
            int16_t temp = map(voltage, 6.6, 8.4, 0, 100);
            // Asegura que el porcentaje esté entre 0 y 100
            uint8_t percentage = max(min(temp, 100), 0);
            return percentage;
        }

**Paso 4: Poniendo a prueba el sistema energético del Rover: pruebas en interiores y exteriores**

Después de codificar nuestro sistema de monitoreo de la batería, es hora de poner 
en marcha el Rover marciano. 
Comienza cargando el Rover a plena capacidad y planifica dos misiones exploratorias 
de 30 minutos, una en interiores y otra en exteriores bajo la luz del sol. Registra el 
nivel de la batería antes de cada misión y compáralo con el porcentaje de batería al 
final de cada prueba. La siguiente tabla sirve como plantilla útil para llevar un 
registro de tus resultados:



.. list-table:: Power Test
   :widths: 50 25 25
   :header-rows: 1

   * - 
     - Luz solar
     - En interiores
   * - Porcentaje de batería inicial
     - 
     - 
   * - Porcentaje de batería al finalizar
     - 
     - 

Observa la diferencia en los niveles de batería tras cada prueba. ¿Duró más la batería del Rover cuando estaba bajo la luz solar directa en exteriores? ¿Qué conclusiones podemos sacar sobre la eficacia del panel solar a partir de esta observación?

Comprender estas variaciones nos ayudará a entender mejor cómo la energía solar puede alimentar eficazmente un Rover en Marte, incluso en entornos tan remotos y difíciles como los que se encuentran en la superficie marciana.

**Paso 5: Mostrar el nivel de batería en la APP**

Naturalmente, no es práctico subir un nuevo código al Rover marciano cada vez que queramos verificar el nivel de batería restante. Sería bastante incómodo.

En lugar de eso, podemos enviar el nivel de batería a una app, permitiéndonos monitorear fácilmente cuánto tiempo de juego nos queda mientras nos divertimos.

A partir de lecciones anteriores, hemos aprendido que cuando queremos mostrar datos en el SunFounder Controller o controlar el Rover utilizando widgets, primero debemos añadir estos widgets.

Sin embargo, la visualización del nivel de batería es un widget especial. Tiene una clave dedicada (``BV``), y su visualización no se encuentra en las áreas etiquetadas de la A a la Q. En su lugar, está representada por un ícono de batería en la esquina superior derecha.

Así es como lo incluimos en nuestro código:

.. code-block:: Arduino

    ...
    // Este pin lee el voltaje de la batería
    #define BATTERY_PIN A3
    ...

    void setup() {
        ...
        // Configura el pin de la batería como entrada
        pinMode(BATTERY_PIN, INPUT);
    }


    // Función que se ejecuta al recibir datos del controlador
    void onReceive() {
        ...
        // Mostrar voltaje de la batería
        aiCam.sendDoc["BV"] = batteryGetVoltage();
    }

    ...

    // Esta función lee el voltaje de la batería
    float batteryGetVoltage() {
        // Lee el valor analógico del pin de la batería
        int adcValue = analogRead(BATTERY_PIN);
        // Convierte el valor analógico en voltaje
        float adcVoltage = adcValue / 1023.0 * 5 * 2;
        // Redondea el voltaje a dos decimales
        float batteryVoltage = int(adcVoltage * 100) / 100.0;
        return batteryVoltage;
    }

Aquí tienes el código completo:


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8b6e0dbd-6fcc-45ac-8408-e8aa706a4bf3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de cargar el código con éxito, pon en marcha tu SunFounder Controller. Verás el nivel de la batería mostrado en la esquina superior derecha.

.. image:: img/battery_icon.png

Al completar este paso, hemos dominado el sistema energético del Rover marciano y obtenido la capacidad de monitorear sus niveles de energía en tiempo real.

Ahora que hemos aprendido a aprovechar el poder del sol para operar eficazmente el Rover, ¡podemos comenzar a planear exploraciones más extensas en nuestro jardín o aventurarnos en terrenos más desafiantes!

**Paso 6: Reflexión**

A lo largo de esta lección, nos hemos centrado en comprender el papel crucial del sistema energético en el Rover marciano, y los mecanismos para monitorear la energía restante del Rover. El sistema energético basado en paneles solares no solo alimenta el Rover, sino que también subraya la importancia de las fuentes de energía renovable en la exploración espacial.

Con el conocimiento que tienes ahora, piensa en las implicaciones reales de este sistema. Considera los desafíos que un sistema de energía solar podría enfrentar en Marte. ¿Cómo podrían afectar al suministro de energía las temperaturas extremas, las tormentas de polvo o los largos períodos de oscuridad? ¿Qué soluciones podrías proponer para enfrentar estos obstáculos?

**Paso 7: Mirando hacia adelante**

Ahora que hemos dado a nuestro Rover marciano la capacidad de moverse, ¡es hora de que comience su viaje de exploración! Puedes dejarlo vagar por diferentes terrenos que imiten el entorno marciano.

Por ejemplo, puedes dejar que suba sobre un montón de piedras.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/move_stone.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

O deja que navegue a través de un denso parche de hierba.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/move_grass.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

O ponlo en curso en un terreno lleno de piedras y grava.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/move_stone1.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Sin embargo, ten en cuenta que si el obstáculo es demasiado alto, el rover puede que no sea capaz de superarlo.

.. raw:: html

   <video width="400" height="400" loop autoplay muted>
      <source src="_static/video/move_failed.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Estos variados terrenos presentan desafíos únicos para el rover, tal como lo harían para un verdadero Rover en Marte. Al observar cómo tu rover intenta superar estos obstáculos, estarás experimentando una pequeña parte de lo que los científicos e ingenieros de la NASA enfrentan cuando envían rovers a Marte.



A medida que concluyen nuestras lecciones del Rover marciano, es importante reflexionar sobre lo que hemos aprendido. Esperamos que este viaje no solo haya ampliado tus conocimientos y habilidades, sino que también haya despertado tu curiosidad y deseo de explorar. Ya sea que tu Rover recorra tu jardín o a lo largo de la vasta extensión de tu imaginación, ¡los descubrimientos que hagas en el camino seguro serán extraordinarios!

