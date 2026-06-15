.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lección 7: Evasión de Obstáculos por Ultrasonido
=============================================================================

En nuestra última aventura, equipamos a nuestro Mars Rover con "ojos" a los lados, creando un sistema básico de evitación de obstáculos. Sin embargo, aún hay un punto ciego justo al frente: un desafío que estamos listos para superar.

Hoy, en esta lección, vamos a darle a nuestro Rover un nuevo sentido de la "vista". Instalaremos un módulo sensor de ultrasonido que actuará como un par de ojos centrales, ayudando a nuestro rover a detectar obstáculos directamente al frente.

Nos adentraremos en la fascinante mecánica de las ondas ultrasónicas y exploraremos cómo mejoran la capacidad de nuestro Rover para navegar terrenos complejos. Con esta adición, nuestro Mars Rover será más perceptivo y ágil, listo para embarcarse en misiones exploratorias más ambiciosas.

Acompáñanos a dar un paso más en este emocionante viaje STEAM, haciendo que nuestro Mars Rover sea aún más hábil para explorar territorios desconocidos.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/ultrasonic_avoid.mp4" type="video/mp4">
      Tu navegador no soporta la etiqueta de video.
   </video>

.. note::

    Si estás aprendiendo este curso después de haber ensamblado completamente el GalaxyRVR, debes mover este interruptor hacia la derecha antes de cargar el código.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Objetivos del Curso
--------------------------

* Comprender el principio de la medición de distancia por ultrasonido.
* Aprender a usar Arduino y el módulo de ultrasonido para medir distancias.
* Practicar la aplicación del módulo de ultrasonido para la evitación de obstáculos en el modelo Mars Rover.

Materiales Necesarios
---------------------

* Módulo de Ultrasonido
* Herramientas básicas y accesorios (p. ej., destornillador, tornillos, cables, etc.)
* Modelo Mars Rover (equipado con sistema rocker-bogie, placas principales, motores, módulo de evitación de obstáculos)
* Cable USB
* Arduino IDE
* Computadora

Pasos del Curso
--------------------
**Paso 1: Ensamblar el Módulo del Sensor de Ultrasonido**

Ahora que nos hemos propuesto equipar a nuestro Mars Rover con un potente nuevo sentido de la "vista", es momento de armar el módulo del sensor de ultrasonido.

.. raw:: html

  <iframe width="600" height="400" src="https://www.youtube.com/embed/c_xWAVapGic?si=ovuxheXdGVpHopPa" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Y ahí lo tenemos. Nuestro Mars Rover ahora cuenta con un módulo de sensor de ultrasonido completamente ensamblado, listo para ayudarlo a navegar como nunca antes. Estás emocionado por ver cómo cambia las capacidades de detección de obstáculos de nuestro Rover? Vamos a descubrirlo.

**Paso 2: Explorando el Módulo de Ultrasonido**

Conozcamos el HC-SR04, un potente sensor de distancia por ultrasonido. Este pequeño dispositivo puede medir distancias con precisión desde 2 cm hasta 400 cm, sin tocar nada. Increíble, verdad? Es como tener un superpoder. Puede "ver" las distancias usando ondas sonoras, igual que un murciélago se orienta por la noche.

Usa cuatro superpoderes, o más bien, cuatro pines para hacer su magia:

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG (Entrada de Pulso de Disparo)** - Es el botón de inicio de nuestro superhéroe. Le dice a nuestro superhéroe: "Oye, es hora de enviar una onda supersónica".
* **ECHO (Salida de Pulso de Eco)** - Así es como nuestro superhéroe escucha el eco de la onda sonora que emitió.
* **VCC** - Hasta los superhéroes necesitan energía. Lo conectamos a una fuente de alimentación de 5V.
* **GND** - Es la conexión a tierra. Como cuando los superhéroes necesitan mantenerse conectados a la realidad.

Imaginemos a nuestro superhéroe, el Sensor de Ultrasonido HC-SR04, jugando al eco en las montañas.

.. image:: img/ultrasonic_prin.jpg
    :width: 800

* Primero, el cerebro de nuestro superhéroe, el MCU, dice: "Preparados, listos, ya" enviando una señal de nivel alto durante al menos 10 microsegundos a nuestro superhéroe. Esto es como cuando reunimos energía antes de gritar en un valle.
* Al oír "Ya", nuestro superhéroe emite un grito 8 veces muy rápidamente. Este grito supersónico se envía a una velocidad de 40 kHz. El superhéroe también pone en marcha un cronómetro y se mantiene atento a cualquier grito que regrese.
* Si hay un obstáculo al frente, el grito chocará contra él y rebotará. Al oír el eco, nuestro superhéroe detiene el cronómetro y anota el tiempo. También envía una señal de nivel alto para que el MCU sepa que escuchó un eco.
* Finalmente, para saber qué tan lejos está el obstáculo, nuestro superhéroe usa una fórmula simple. Toma el tiempo que registró en el cronómetro, lo divide entre 2 y lo multiplica por la velocidad del sonido (340 m/s). El resultado es la distancia al obstáculo.

Así es como nuestro sensor superhéroe puede determinar si hay un obstáculo en su camino y a qué distancia está. Increíble, no? A continuación, aprenderemos cómo podemos usar este superpoder en nuestro Mars Rover.

**Paso 3: Programando a Nuestro Sensor Superhéroe**

Habiendo ensamblado nuestro sensor superhéroe y entendido cómo usa sus superpoderes, es hora de poner esos poderes en acción. Escribamos un sketch de Arduino para permitir que nuestro sensor de ultrasonido mida distancias y luego nos muestre esas mediciones.

Estos son los pasos clave que seguirá nuestro sensor superhéroe:

* Hemos conectado tanto el pin TRIG como el ECHO al pin 10 en el GalaxyRVR Shield. Esto nos permite controlar tanto la transmisión de señal como la recepción del módulo de ultrasonido usando un solo pin de Arduino.

.. image:: img/ultrasonic_shield.png

.. code-block:: arduino

    // Define the pin for the ultrasonic module
    #define ULTRASONIC_PIN 10

* **Preparación**: Para comenzar, establecemos comunicación serial a una velocidad de 9600 baudios para poder ver las mediciones del superhéroe en nuestro Monitor Serial.

.. code-block:: arduino

    void setup() {
        // Start the serial communication
        Serial.begin(9600);
    }

* **Grita Fuerte**: Configuramos ``ULTRASONIC_PIN`` como un pin de ``OUTPUT`` para enviar un pulso de 10 microsegundos, lo cual es como ordenar a nuestro superhéroe ultrasónico que emita un potente grito (ondas sonoras ultrasónicas).

.. code-block:: arduino

    // A 4ms delay is required, otherwise the reading may be 0
    delay(4);

    //Set to OUTPUT to send signal
    pinMode(ULTRASONIC_PIN, OUTPUT);

    // Clear the trigger pin
    digitalWrite(ULTRASONIC_PIN, LOW);
    delayMicroseconds(2);

    // Trigger the sensor by sending a high pulse for 10us
    digitalWrite(ULTRASONIC_PIN, HIGH);
    delayMicroseconds(10);

    // Set the trigger pin back to low
    digitalWrite(ULTRASONIC_PIN, LOW);

* **Espera y Escucha**: Configuramos ``ULTRASONIC_PIN`` como INPUT. De esta manera, nuestro sensor superhéroe ahora está listo para escuchar el eco de su grito. Si hay un obstáculo al frente, el grito chocará contra él y rebotará. Al oír el eco, nuestro superhéroe detiene el cronómetro y anota el tiempo. También envía una señal de nivel alto para que el MCU sepa que escuchó un eco.

.. code-block:: arduino

    pinMode(ULTRASONIC_PIN, INPUT);
    float duration = pulseIn(ULTRASONIC_PIN, HIGH);

* **Súper Matemáticas**: Con el eco recibido, nuestro sensor usa la velocidad del sonido para calcular la distancia al objeto. Dividimos el tiempo total del eco entre 2 porque el tiempo incluye tanto la emisión del grito como la espera del eco.

.. code-block:: arduino

    float distance = duration * 0.034 / 2;

* **Reportar los Hallazgos**: Nuestro sensor superhéroe revela entonces el resultado de su misión, imprimiendo la distancia en el Monitor Serial para que la veamos.

.. code-block:: arduino

    // Print the distance to the serial monitor
    Serial.print("The distance is: ");
    Serial.print(distance);
    Serial.println(" cm");

* **Descanso y Listo**: Todo superhéroe necesita un descanso, así que nuestro sensor hace una pausa breve antes de la siguiente misión. Esto permite que el sensor se "reinicie" antes de pedirle que comience otra medición.

.. code-block:: arduino

    delay(200);

Aquí está el código completo que convierte a nuestro sensor en un superhéroe:

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/35bddbcf-145c-4e4f-b3ea-21e8210af4a6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Paso 4: Programando el Módulo de Ultrasonido para Conducir el Mars Rover**

Ahora que hemos equipado nuestro Mars Rover con un módulo sensor de ultrasonido, es hora de programarlo para que responda según las mediciones del sensor.

* Para facilitar la lectura, hemos creado una función llamada ``readSensorData()``. Esta función encapsula todo el código necesario para leer la distancia desde el sensor de ultrasonido.

  .. code-block:: arduino

    float readSensorData() {
        // A 4ms delay is required, otherwise the reading may be 0
        delay(4);

        //Set to OUTPUT to send signal
        pinMode(ULTRASONIC_PIN, OUTPUT);

        // Clear the trigger pin
        digitalWrite(ULTRASONIC_PIN, LOW);
        delayMicroseconds(2);

        // Trigger the sensor by sending a high pulse for 10us
        digitalWrite(ULTRASONIC_PIN, HIGH);
        delayMicroseconds(10);

        // Set the trigger pin back to low
        digitalWrite(ULTRASONIC_PIN, LOW);

        //Set to INPUT to read
        pinMode(ULTRASONIC_PIN, INPUT);

        // pulseIn returns the duration of the pulse on the pin
        float duration = pulseIn(ULTRASONIC_PIN, HIGH);

        // Calculate the distance (in cm) based on the speed of sound (340 m/s or 0.034 cm/us)
        float distance = duration * 0.034 / 2;

        return distance;
    }

* En la función ``loop()``, llamamos a ``readSensorData()`` y almacenamos su valor devuelto en la variable ``distance``.

  .. code-block:: arduino

    float distance = readSensorData();

* Dependiendo de esta distancia, el Rover avanzará, retrocederá o se detendrá.

  .. code-block:: arduino

    // Control rover based on distance reading
    if (distance > 50) {  // If it's safe to move forward
      moveForward(200);
    } else if (distance < 15) {  // If there's an obstacle close
      moveBackward(200);
      delay(500);  // Wait for a while before attempting to turn
      backLeft(150);
      delay(1000);
    } else {  // For distances in between, proceed with caution
      moveForward(150);
    }

  * Si el camino está despejado (el obstáculo está a más de 50 cm de distancia), nuestro Rover avanza con determinación.
  * Y si un obstáculo se acerca (a menos de 50 cm pero a más de 15 cm de distancia), nuestro Rover avanzará a una velocidad menor.
  * Si un obstáculo está demasiado cerca (a menos de 15 cm de distancia), el Mars rover retrocederá y luego girará a la izquierda.

  .. image:: img/ultrasonic_flowchart.png

A continuación se muestra el código completo. Puedes cargar este código en la placa R3 y ver si logra el efecto deseado. También puedes modificar la distancia de detección según el entorno real para perfeccionar este sistema de evitación de obstáculos.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cded6408-1469-4289-b79b-7d445b56352b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Al aprovechar estas capacidades mejoradas, el Mars Rover estaría mejor equipado para identificar posibles obstáculos en su camino, medir distancias con precisión y tomar decisiones informadas para sortearlos. Esto reduciría significativamente la probabilidad de colisiones u otros peligros que podrían obstaculizar la misión de exploración del rover.

Con sus superpoderes, el Mars Rover puede operar con mayor confianza y eficiencia, permitiéndole adentrarse más en los misterios de Marte y recopilar valiosos datos científicos para los investigadores en la Tierra.

**Paso 5: Resumen y Reflexión**

En esta lección, profundizamos en el funcionamiento de las ondas ultrasónicas y cómo traducir su tiempo de retorno al sensor en una distancia medible mediante la programación.

Posteriormente, aprovechamos las ondas ultrasónicas para diseñar un sistema de evitación de obstáculos. Este sistema en particular varía sus respuestas según la distancia al obstáculo inminente.

Ahora, promovamos algo de introspección sobre esta lección a través de una serie de preguntas:

* Cómo detecta la distancia un módulo de ultrasonido? Puedes explicar el concepto subyacente?
* En qué se diferencia el sistema de evitación de obstáculos de esta lección respecto al de la lección anterior? Cuáles son sus respectivas ventajas y desventajas?
* Es factible combinar estos dos sistemas de evitación de obstáculos?

Reflexionar sobre estas preguntas ayudará a solidificar nuestra comprensión y nos invitará a considerar la aplicación de estos conceptos en otros proyectos. Esperamos con ansias nuestra próxima aventura.
