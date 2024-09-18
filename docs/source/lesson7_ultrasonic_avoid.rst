.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirte?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones especiales durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy mismo!

Lección 7: Mejorando la navegación del Rover con el módulo ultrasónico
=============================================================================

En nuestra última aventura, equipamos a nuestro Rover Marciano con "ojos" en sus lados, creando un sistema básico de evasión de obstáculos. Sin embargo, aún queda un punto ciego justo enfrente, un desafío que estamos listos para superar.

Hoy, en esta lección, vamos a darle a nuestro Rover un nuevo sentido de "visión". Instalaremos un módulo de sensor ultrasónico que actuará como un par de ojos centrales, ayudando a nuestro rover a detectar obstáculos directamente frente a él.

Nos sumergiremos en la fascinante mecánica de las ondas ultrasónicas y exploraremos cómo mejoran la capacidad de nuestro Rover para navegar en terrenos complejos. Con esta adición, nuestro Rover Marciano será más perceptivo y ágil, listo para emprender misiones exploratorias más ambiciosas.

¡Únete a nosotros mientras damos un paso más en este emocionante viaje STEAM, haciendo que nuestro Rover Marciano sea aún más hábil para explorar territorios desconocidos!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/ultrasonic_avoid.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. note::

    Si estás aprendiendo este curso después de haber ensamblado completamente el GalaxyRVR, debes mover este interruptor hacia la derecha antes de cargar el código.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center


Objetivos del curso
----------------------------

* Comprender el principio de la medición de distancia ultrasónica.
* Aprender cómo usar Arduino y el módulo ultrasónico para la medición de distancias.
* Practicar la aplicación del módulo ultrasónico para evitar obstáculos en el modelo del Rover Marciano.

Materiales necesarios
-------------------------

* Módulo ultrasónico
* Herramientas y accesorios básicos (ej. destornillador, tornillos, cables, etc.)
* Modelo del Rover Marciano (equipado con sistema rocker-bogie, placas principales, motores y módulo de evasión de obstáculos)
* Cable USB
* Arduino IDE
* Computadora

Pasos del curso
--------------------

**Paso 1: Montar el módulo de sensor ultrasónico**

Ahora que estamos listos para equipar a nuestro Rover Marciano con un nuevo sentido de "visión", es momento de montar el módulo de sensor ultrasónico.

.. raw:: html

  <iframe width="600" height="400" src="https://www.youtube.com/embed/c_xWAVapGic?si=ovuxheXdGVpHopPa" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

¡Y ahí lo tenemos! Nuestro Rover Marciano ahora tiene un módulo de sensor ultrasónico completamente montado, listo para ayudarlo a navegar como nunca antes. ¿Estás emocionado por ver cómo mejora las habilidades de detección de obstáculos de nuestro Rover? ¡Vamos a sumergirnos en ello!


**Paso 2: Explorando el módulo ultrasónico**

Vamos a conocer el HC-SR04, un potente sensor ultrasónico de distancia. Este pequeño dispositivo puede medir con precisión distancias desde 2 cm hasta 400 cm, ¡sin tocar nada! Increíble, ¿verdad? Es como tener un súper poder. Puede "ver" las distancias solo usando ondas sonoras, como los murciélagos cuando navegan de noche.

Utiliza cuatro "superpoderes", o mejor dicho, cuatro pines para hacer su magia:

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG (Entrada de pulso de disparo)** - Es el botón de inicio de nuestro superhéroe. Le dice, "¡Hey, es hora de enviar una onda ultrasónica!"
* **ECHO (Salida de pulso de eco)** - Así es como nuestro superhéroe escucha el eco de la onda sonora que emitió.
* **VCC** - Incluso los superhéroes necesitan energía. Lo conectamos a una fuente de 5V.
* **GND** - Es la conexión a tierra. ¡Como los superhéroes, que siempre necesitan estar conectados a la realidad!

Imagina a nuestro superhéroe, el sensor ultrasónico HC-SR04, jugando a hacer eco en las montañas.

.. image:: img/ultrasonic_prin.jpg
    :width: 800

* Primero, el cerebro de nuestro superhéroe, el MCU, dice "¡Listo, a correr!" enviando una señal de nivel alto durante al menos 10 microsegundos. Esto es como cuando tomamos aire antes de gritar en un valle.
* Al oír "¡Corre!", nuestro superhéroe grita 8 veces rápidamente. Este súper grito ultrasónico se envía a una velocidad de 40 kHz. El superhéroe también inicia un cronómetro y se pone atento para escuchar cualquier eco que regrese.
* Si hay un obstáculo delante, el grito lo golpeará y rebotará hacia atrás. Al escuchar el eco, nuestro superhéroe detiene el cronómetro y anota el tiempo. También envía una señal alta para informar al MCU que ha escuchado un eco.
* Por último, para descubrir a qué distancia está el obstáculo, nuestro superhéroe usa una fórmula simple. Toma el tiempo registrado en el cronómetro, lo divide por 2 y lo multiplica por la velocidad del sonido (340 m/s). ¡El resultado es la distancia al obstáculo!

Así es como nuestro sensor puede determinar si hay un obstáculo en su camino y a qué distancia está. ¡Asombroso, verdad? A continuación, aprenderemos cómo usar este poder en nuestro Rover Marciano.

**Paso 3: Programando nuestro sensor súper héroe**

Después de montar nuestro sensor y entender cómo usa sus superpoderes, es hora de ponerlos en acción. Vamos a escribir un sketch en Arduino para que el sensor ultrasónico mida distancias y nos muestre esas mediciones.

Aquí están los pasos clave que seguirá nuestro sensor:

* Hemos conectado ambos pines TRIG y ECHO al pin 10 en el escudo GalaxyRVR. Esto nos permite controlar tanto la transmisión como la recepción del módulo ultrasónico con un solo pin de Arduino.

.. image:: img/ultrasonic_shield.png

.. code-block:: arduino

    // Definir el pin para el módulo ultrasónico
    #define ULTRASONIC_PIN 10

* **Preparación**: Para comenzar, establecemos la comunicación en serie a 9600 baudios para que podamos ver las mediciones del sensor en nuestro Monitor Serial.

.. code-block:: arduino

    void setup() {
        // Iniciar la comunicación en serie
        Serial.begin(9600);
    }

* **¡Lanzar el grito!**: Configuramos el ``ULTRASONIC_PIN`` como un pin de ``SALIDA`` para enviar un pulso de 10 microsegundos, lo que equivale a ordenar a nuestro sensor ultrasónico que emita un poderoso grito (ondas ultrasónicas).

.. code-block:: arduino

    // Se requiere un retraso de 4ms, de lo contrario la lectura puede ser 0
    delay(4);

    // Configurar como salida para enviar la señal
    pinMode(ULTRASONIC_PIN, OUTPUT);

    // Limpiar el pin de disparo
    digitalWrite(ULTRASONIC_PIN, LOW);
    delayMicroseconds(2);

    // Activar el sensor enviando un pulso alto de 10us
    digitalWrite(ULTRASONIC_PIN, HIGH);
    delayMicroseconds(10);

    // Restablecer el pin de disparo a bajo
    digitalWrite(ULTRASONIC_PIN, LOW);


* **Esperar y escuchar**: Configuramos el ``ULTRASONIC_PIN`` como ``ENTRADA``. De esta forma, nuestro sensor ultrasónico está listo para escuchar el eco de su grito. Si hay un obstáculo, el grito lo golpeará y rebotará. Al escuchar el eco, nuestro sensor detendrá el cronómetro y notará el tiempo.

.. code-block:: arduino

    pinMode(ULTRASONIC_PIN, INPUT);
    float duration = pulseIn(ULTRASONIC_PIN, HIGH);

* **Cálculo del súper héroe**: Con el eco devuelto, nuestro sensor usa la velocidad del sonido para calcular la distancia al objeto. Dividimos el tiempo total del eco por 2 porque el tiempo incluye tanto el grito como la espera por el eco.

.. code-block:: arduino

    float distance = duration * 0.034 / 2;


* **Informar los resultados**: Nuestro sensor súper héroe luego revela el resultado de su misión, imprimiendo la distancia en el Monitor Serial para que podamos verla.

.. code-block:: arduino

    // Imprimir la distancia en el monitor serial
    Serial.print("The distance is: ");
    Serial.print(distance);
    Serial.println(" cm");

* **Descanso y preparación**: Todo súper héroe necesita un descanso, por lo que nuestro sensor toma una breve pausa antes de la próxima misión. Esto permite que el sensor "se reinicie" antes de comenzar otra medición.

.. code-block:: arduino

    delay(200);

Aquí está el código completo que convierte a nuestro sensor en un súper héroe:

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/35bddbcf-145c-4e4f-b3ea-21e8210af4a6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Paso 4: Programar el módulo ultrasónico para controlar el Rover Marciano**

Ahora que hemos equipado a nuestro Rover Marciano con un módulo ultrasónico, es hora de programarlo para que responda según las mediciones del sensor.

* Para facilitar la lectura, hemos creado una función llamada ``readSensorData()``. Esta función encapsula todo el código necesario para leer la distancia desde el sensor ultrasónico.

  .. code-block:: arduino

    float readSensorData() {
        // Se requiere un retraso de 4ms, de lo contrario la lectura puede ser 0
        delay(4);
      
        // Configurar como salida para enviar la señal
        pinMode(ULTRASONIC_PIN, OUTPUT);
      
        // Limpiar el pin de disparo
        digitalWrite(ULTRASONIC_PIN, LOW);
        delayMicroseconds(2);
      
        // Activar el sensor enviando un pulso alto de 10us
        digitalWrite(ULTRASONIC_PIN, HIGH);
        delayMicroseconds(10);
      
        // Restablecer el pin de disparo a bajo
        digitalWrite(ULTRASONIC_PIN, LOW);
      
        // Configurar como entrada para leer la señal
        pinMode(ULTRASONIC_PIN, INPUT);
      
        // pulseIn devuelve la duración del pulso en el pin
        float duration = pulseIn(ULTRASONIC_PIN, HIGH);
      
        // Calcular la distancia (en cm) basada en la velocidad del sonido (340 m/s o 0.034 cm/us)
        float distance = duration * 0.034 / 2;
      
        return distance;
    }

* En la función ``loop()``, llamamos a ``readSensorData()`` y almacenamos su valor devuelto en la variable ``distance``.

  .. code-block:: arduino

    float distance = readSensorData();

* Dependiendo de esta distancia, el Rover se moverá hacia adelante, hacia atrás o se detendrá.

  .. code-block:: arduino
  
    // Controlar el rover según la lectura de distancia
    if (distance > 50) {  // Si es seguro avanzar
      moveForward(200);
    } else if (distance < 15) {  // Si hay un obstáculo cerca
      moveBackward(200);
      delay(500);  // Esperar un momento antes de intentar girar
      backLeft(150);
      delay(1000);
    } else {  // Para distancias intermedias, proceder con precaución
      moveForward(150);
    }

  * Si el camino está despejado (el obstáculo está a más de 50 cm de distancia), nuestro Rover avanza con valentía.
  * Si el obstáculo se acerca (menos de 50 cm pero más de 15 cm), nuestro Rover avanzará a menor velocidad.
  * Si un obstáculo está demasiado cerca (menos de 15 cm), el Rover se moverá hacia atrás y luego girará a la izquierda.

  .. image:: img/ultrasonic_flowchart.png

A continuación, el código completo. Puedes cargar este código en la placa R3 y comprobar si logra el efecto deseado. También puedes modificar la distancia de detección según el entorno real para hacer que este sistema de evasión de obstáculos sea más preciso.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cded6408-1469-4289-b79b-7d445b56352b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Con estas capacidades mejoradas, el Rover Marciano estará mejor equipado para identificar posibles obstáculos en su camino, medir distancias con precisión y tomar decisiones informadas para sortearlos. Esto reducirá significativamente las probabilidades de colisiones u otros peligros que puedan obstaculizar la misión de exploración del rover.

Con sus super-sentidos, el Rover Marciano podrá operar con mayor confianza y eficiencia, permitiéndole explorar más a fondo los misterios de Marte y recopilar valiosos datos científicos para los investigadores en la Tierra.

**Paso 5: Resumen y reflexión**

En esta lección, nos adentramos en el funcionamiento de las ondas ultrasónicas y cómo traducir su tiempo de retorno en el sensor en una distancia medible mediante la programación.

Posteriormente, aprovechamos las ondas ultrasónicas para diseñar un sistema de evasión de obstáculos. Este sistema varía sus respuestas según la distancia al obstáculo inminente.

Ahora, reflexionemos sobre esta lección a través de algunas preguntas:

* ¿Cómo detecta distancia un módulo ultrasónico? ¿Puedes explicar el concepto subyacente?
* ¿En qué se diferencia el sistema de evasión de obstáculos de esta lección del anterior? ¿Cuáles son sus ventajas y desventajas?
* ¿Es factible combinar estos dos sistemas de evasión de obstáculos?

Reflexionar sobre estas preguntas te ayudará a solidificar tu comprensión y a pensar en cómo aplicar estos conceptos en otros proyectos. ¡Espero con ansias nuestra próxima aventura!
