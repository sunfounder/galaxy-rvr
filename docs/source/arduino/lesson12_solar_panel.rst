.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lección 12: Panel Solar y Monitoreo de Batería
=================================================================

Bienvenidos a la última lección de nuestro viaje de exploración del rover marciano. Esta vez, vamos a adentrarnos en el corazón del rover: su sistema de energía.

Cuando pensamos en explorar planetas lejanos como Marte, uno de los aspectos más cruciales a considerar es la energía.
¿Cómo se alimentan estos rovers en entornos tan hostiles y remotos?
En esta lección, exploraremos este fascinante tema y aprenderemos cómo los rovers, como nuestro modelo de rover marciano, aprovechan y gestionan la energía.

Investigaremos los principios de funcionamiento de la batería y el panel solar, e incluso pondremos en práctica la instalación y
el uso de estas fuentes de alimentación en nuestro modelo de rover. Además, llevaremos nuestras habilidades un paso más allá utilizando Arduino para monitorear
el nivel de la batería.


.. image:: img/solar_panel.jpg
    :width: 600
    :align: center

Objetivos de Aprendizaje
-------------------------

* Comprender los principios de funcionamiento de la batería y el panel solar.
* Practicar la instalación del panel solar en el modelo de rover marciano.
* Aprender a usar Arduino para monitorear el nivel de la batería y el estado de carga del panel solar.


Materiales necesarios
-----------------------

* Modelo de rover marciano (equipado con todos los componentes, excepto el panel solar y la placa inferior)
* Panel solar y placa inferior
* Arduino IDE
* Computadora

Pasos del Curso
-----------------------

**Paso 1: Introducción al Sistema de Energía del Rover Marciano**

Así como nuestros cuerpos necesitan un suministro constante de energía para funcionar, nuestro rover marciano necesita una forma de almacenar y generar energía para sus misiones de exploración. Imagine el sistema de energía del rover como el corazón de nuestro cuerpo. Así como nuestro corazón bombea sangre a todas las partes de nuestro cuerpo, suministrando el oxígeno y los nutrientes necesarios, el sistema de energía del rover mantiene el flujo de energía a cada parte del rover, asegurando que pueda realizar sus tareas sin problemas.

Los componentes principales de este sistema de energía son las baterías y los paneles solares, que trabajan en conjunto para garantizar que el rover pueda operar en todo momento, tanto de día como de noche.

El papel de las baterías en el sistema de energía del rover es similar al del almacenamiento de energía en nuestros cuerpos. Así como necesitamos almacenar energía para usarla cuando estamos activos, el rover necesita una forma de almacenar energía para sus misiones de exploración. La energía almacenada en las baterías se distribuye continuamente a las diversas partes del rover, permitiéndole llevar a cabo sus tareas de manera sistemática.

.. image:: img/battery_galaxyrvr.png
    :width: 600
    :align: center

Pero, ¿qué sucede cuando la energía de las baterías se agota? ¿Cómo repone sus reservas de energía? Aquí es donde entran en juego los paneles solares.

Al igual que los árboles absorben la luz solar para la fotosíntesis y crear alimento, nuestro rover marciano utiliza paneles solares para aprovechar la energía del Sol, convirtiéndola en electricidad que se almacena en las baterías para su uso. Cada panel solar está compuesto por muchas celdas solares más pequeñas. Estas celdas están hechas de un material que puede convertir la luz en electricidad, un proceso llamado efecto fotovoltaico. Cuando la luz solar incide sobre las celdas, estas generan una corriente eléctrica que puede usarse inmediatamente o almacenarse en las baterías del rover para su uso posterior.

.. image:: img/solar_panel_gala.png
    :width: 600
    :align: center

Sin embargo, aprovechar la energía solar en Marte no es tan fácil como parece. Las tormentas de polvo pueden reducir la cantidad de luz solar que llega a los paneles, y la luz solar marciana más débil (en comparación con la de la Tierra) significa que los paneles generan menos energía de la que generarían aquí en casa. A pesar de estos desafíos, la energía solar sigue siendo la forma más práctica y eficiente de alimentar nuestro rover marciano.

Pero, ¿cómo sabemos cuándo los paneles solares están haciendo su trabajo y cuándo las baterías tienen poca energía? Aquí es donde entra nuestro Arduino. En la siguiente sección, aprenderemos a usar Arduino para monitorear la carga y descarga de las baterías del rover.

**Paso 2: Montaje del Panel Solar en el Rover Marciano**

Antes de comenzar este paso, necesitamos tener nuestro modelo de rover marciano, un panel solar y los cables necesarios para conectar el panel solar al sistema de alimentación del rover.

Este es un proceso que nos permite poner la teoría en práctica y apreciar verdaderamente el encanto de la educación en Ciencia, Tecnología, Ingeniería y Matemáticas (STEM). ¡Comencemos!

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/-Vj-dcniFrA" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Paso 3: Programación para Monitorear el Voltaje y la Carga de la Batería**

Ahora que hemos instalado los paneles solares en nuestro modelo de rover marciano, el siguiente paso es monitorear el voltaje y la carga de la batería mediante programación.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2e85e234-9575-4a1f-982b-2f9aba8e3156/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Este código crea efectivamente un monitor de batería simple, que es particularmente útil en aplicaciones como el rover marciano donde la gestión de energía es crucial. Le permitirá monitorear el estado de la batería, ayudándole a comprender cuándo el rover necesita ser recargado o cuándo deben programarse tareas que consumen mucha energía.

A continuación, desglosamos las diferentes partes de este código:

*  Esta línea define ``BATTERY_PIN`` como el pin analógico A3, que es desde donde se leerá el voltaje de la batería.

    .. code-block:: arduino

        #define BATTERY_PIN A3

* Esta función calcula el voltaje de la batería. Primero lee el valor analógico de ``BATTERY_PIN``, luego lo convierte en voltaje. Debido a que el convertidor analógico-digital (ADC) de Arduino opera en una escala de 0 a 1023, dividimos la lectura bruta por 1023. Luego multiplicamos por 5 (el voltaje de referencia de Arduino) y por 2 (asumiendo un divisor de tensión de 2), para convertir esto en una lectura de voltaje.

    .. code-block:: arduino
        :emphasize-lines: 5

        float batteryGetVoltage() {
            // Reads the analog value from the battery pin
            int adcValue = analogRead(BATTERY_PIN);
            // Converts the analog value to voltage
            float adcVoltage = adcValue / 1023.0 * 5 * 2;
            // Rounds the voltage to two decimal places
            float batteryVoltage = int(adcVoltage * 100) / 100.0;
            return batteryVoltage;
        }


    La lectura ADC bruta del convertidor analógico-digital de Arduino se divide por 1023 para convertirla en una fracción, luego se multiplica por 5 para traducirla a voltaje, ya que Arduino utiliza un voltaje de referencia de 5 voltios.

    Sin embargo, debido a que el voltaje de la batería es superior al voltaje máximo de entrada de Arduino, se utiliza una resistencia para proteger el Arduino. Por lo tanto, multiplicamos el voltaje ADC por 2 para contrarrestar el efecto de la resistencia y obtener el voltaje correcto de la batería.

* Esta función calcula el porcentaje de carga de la batería en función de su voltaje. Utiliza la función ``map`` para ``mapear`` el valor de voltaje (que va de 6.6 a 8.4 voltios) a un porcentaje (que va de 0 a 100).

    .. code-block:: arduino

        uint8_t batteryGetPercentage() {
            float voltage = batteryGetVoltage();  // Gets the battery voltage
            // Maps the voltage to a percentage.
            int16_t temp = map(voltage, 6.6, 8.4, 0, 100);
            // Ensures the percentage is between 0 and 100
            uint8_t percentage = max(min(temp, 100), 0);
            return percentage;
        }

**Paso 4: Poniendo a Prueba el Sistema de Energía del Rover Marciano: Recorridos en Interiores y Exteriores**

Habiendo programado nuestro sistema de monitoreo de batería, ahora es el momento de poner en acción al rover marciano.
Comience cargando el rover a plena capacidad y planifique dos misiones exploratorias de 30 minutos: una en interiores
y otra al aire libre bajo la luz solar. Registre el nivel inicial de batería antes de cada misión
y compárelo con el porcentaje de batería al final de cada prueba.
La siguiente tabla sirve como una plantilla útil para realizar un seguimiento de sus hallazgos:



.. list-table:: Prueba de Energía
   :widths: 50 25 25
   :header-rows: 1

   * -
     - Exterior Soleado
     - En Interiores
   * - Porcentaje de Batería Inicial
     -
     -
   * - Porcentaje de Batería Final
     -
     -

Observe la diferencia en los niveles de batería después de cada prueba. ¿Duró más la batería del rover cuando estaba expuesto a la luz solar
exterior? ¿Qué conclusiones podemos extraer sobre la eficacia del panel solar a partir de esta observación?

Comprender estas variaciones nos ayudará a entender mejor cómo la energía solar puede alimentar eficazmente un rover marciano,
incluso en entornos remotos y hostiles como los de la superficie marciana.

**Paso 5: Reflexión**

A lo largo de esta lección, nos hemos centrado en comprender el papel crucial del sistema de energía en el rover marciano y los mecanismos para monitorear la energía restante del rover. El sistema de energía basado en paneles solares no solo alimenta el rover, sino que también subraya la importancia de las fuentes de energía renovable en la exploración espacial.

Con el conocimiento que tiene ahora, piense en las implicaciones reales de este sistema. Considere los desafíos que un sistema de energía solar podría encontrar en Marte. ¿Cómo podrían afectar al suministro de energía las temperaturas extremas, las tormentas de polvo o los largos períodos de oscuridad? ¿Qué soluciones podría proponer para abordar estos obstáculos?

**Paso 6: Perspectivas Futuras**

Ahora que le hemos dado a nuestro rover marciano la capacidad de moverse, ¡es hora de que comience su viaje de exploración! Puede dejarlo deambular por varios terrenos que imiten el entorno de Marte.

Por ejemplo, puede dejarlo escalar sobre un montón de piedras.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/move_stone.mp4" type="video/mp4">
      Su navegador no soporta la etiqueta de video.
   </video>

O dejarlo navegar a través de una espesa capa de hierba.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/move_grass.mp4" type="video/mp4">
      Su navegador no soporta la etiqueta de video.
   </video>

O ponerlo en un recorrido sobre un terreno de grava lleno de piedras.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/move_stone1.mp4" type="video/mp4">
      Su navegador no soporta la etiqueta de video.
   </video>

Sin embargo, tenga en cuenta que si el obstáculo es demasiado alto, es posible que el rover no pueda escalarlo.

.. raw:: html

   <video width="400" height="400" loop autoplay muted>
      <source src="../_static/video/move_failed.mp4" type="video/mp4">
      Su navegador no soporta la etiqueta de video.
   </video>

Estos terrenos variados presentan desafíos únicos para el rover, tal como lo harían para un verdadero rover marciano. Mientras observa a su rover intentar superar estos obstáculos, está experimentando una pequeña parte de lo que hacen los científicos e ingenieros de la NASA cuando envían rovers a Marte.

Al concluir nuestras lecciones sobre el rover marciano, es importante reflexionar sobre lo que hemos aprendido. Esperamos que este viaje no solo haya ampliado sus conocimientos y habilidades, sino que también haya despertado su curiosidad y deseo de explorar. Ya sea que su rover deambule por su jardín o por la vasta extensión de su imaginación, los descubrimientos que haga en el camino seguramente serán extraordinarios.
