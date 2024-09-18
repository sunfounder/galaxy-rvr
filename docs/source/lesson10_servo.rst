.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirte?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy!


Lección 10: Explorando el Sistema Visual del Rover Marciano - Mecanismo de Inclinación con Servo
=======================================================================================================

¡Bienvenidos de nuevo, jóvenes exploradores! En la aventura de hoy, vamos a adentrarnos 
en el fascinante mundo del sistema visual del Rover Marciano. 
Al igual que nuestros ojos y cuello trabajan juntos para ayudarnos a ver y navegar por 
nuestro entorno, nuestro Rover también necesita un sistema similar para moverse por el 
accidentado paisaje marciano. ¡Y eso es exactamente lo que construiremos hoy!

El sistema visual de nuestro Rover tiene dos partes principales: una cámara que actúa 
como sus "ojos" y un mecanismo de inclinación que actúa como su "cuello", permitiéndole 
mirar hacia arriba y hacia abajo. Al final de esta lección, ¡nuestro Rover podrá "ver" y "asentir"!

Primero, construiremos el mecanismo de inclinación, un dispositivo que sostendrá la 
cámara del Rover y le permitirá rotar verticalmente. 
¡Es como darle un cuello al Rover para que pueda mover su "cabeza" o cámara hacia 
arriba y hacia abajo!

Luego, aprenderemos sobre el servo, el pequeño pero poderoso "músculo" que mueve 
nuestro mecanismo de inclinación. 
Comprenderemos cómo funciona y cómo podemos controlarlo mediante la programación en Arduino.

Así como los músculos de nuestro cuello mueven nuestra cabeza para mejorar nuestra 
visión, el servo moverá el mecanismo de inclinación para que la cámara del Rover 
pueda explorar mejor el paisaje marciano.

¡Abróchense los cinturones, exploradores, y comencemos nuestra misión de equipar a nuestro Rover con su propio sistema visual!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/servo_range.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>


Objetivo
-----------

* Practicar la instalación y operación del mecanismo de inclinación en el modelo del Rover Marciano.
* Comprender los principios de funcionamiento y aplicación de los servos.
* Aprender a controlar el movimiento de un servo mediante la programación en Arduino.

Materiales
-------------

* Placa de desarrollo Arduino UNO
* Servo
* Gimbal y cámara
* Modelo del Rover Marciano (ya equipado con motor TT, sistema de suspensión, módulos de evasión de obstáculos ultrasónicos e infrarrojos, tira de LED RGB)
* Arduino IDE
* Computadora

Pasos
--------

**Paso 1: ¿Qué es un servo?**

¿Alguna vez has visto un espectáculo de marionetas? Si lo has hecho, puede que te hayas maravillado de cómo el titiritero puede mover los brazos, las piernas y la cabeza de la marioneta tan suavemente, solo tirando de algunas cuerdas. En cierto modo, los servos son como nuestros titiriteros.

.. image:: img/puppet_show.png
    :width: 200
    :align: center

Los servos son un tipo especial de motores que no giran continuamente como una rueda. En lugar de eso, pueden moverse a una posición específica y mantenerse allí. Imagina que estás jugando a "Simón dice" y Simón dice: "¡Levanta tu brazo a un ángulo de 90 grados!". ¿Puedes hacerlo, verdad? Eso es porque, como un servo, puedes controlar exactamente cuánto mover tu brazo.

.. image:: img/servo.png
    :align: center

* Cable marrón: GND
* Cable naranja: Pin de señal, se conecta al pin PWM de la placa principal.
* Cable rojo: VCC

Así como puedes controlar tus brazos para moverse a posiciones específicas, podemos usar servos para controlar la posición exacta de objetos en nuestros proyectos. En nuestro Rover Marciano, usaremos un servo para controlar el movimiento hacia arriba y abajo del mecanismo de inclinación, tal como tú puedes mover tu cabeza para asentir.

En el siguiente paso, haremos un fascinante viaje al interior de un servo motor para entender cómo funciona. ¿Estás emocionado? ¡Vamos allá!

**Paso 2: ¿Cómo funciona un servo?**

Entonces, ¿cómo hace un servo su magia? ¡Vamos a explorar el interior de un servo!

Si miráramos dentro de un servo, veríamos varias partes. En el corazón de un servo hay un motor regular, muy similar a los motores que giran las ruedas de nuestro Rover Marciano. Alrededor del motor, hay un engranaje grande conectado a otro más pequeño en el eje del motor. Así es como el rápido movimiento circular del motor se convierte en un movimiento más lento pero más fuerte.

.. image:: img/servo_internal.png
    :align: center

Pero eso no es lo que hace especial a un servo. La magia ocurre en una pequeña pieza electrónica llamada "potenciómetro" y en el "circuito de control". Así es como funciona: cuando el servo se mueve, el potenciómetro gira y cambia su resistencia. El circuito de control mide este cambio en la resistencia y sabe exactamente en qué posición está el servo. Ingenioso, ¿verdad?

Para controlar un servo, le enviamos un tipo especial de señal llamada señal de "modulación por ancho de pulso" o PWM. Al cambiar el ancho de estos pulsos, podemos controlar exactamente cuánto se mueve el servo y mantenerlo en esa posición.

En el siguiente paso, aprenderemos a controlar un servo usando un Arduino. ¿Listo para algunos hechizos mágicos en forma de código? ¡Vamos!

**Paso 3: Controlando un Servo con Arduino**

Muy bien, exploradores, ahora que sabemos cómo funciona un servo, aprendamos cómo controlarlo con nuestra varita mágica, el Arduino.

Controlar un servo es como darle direcciones. ¿Recuerdas las señales PWM de las que hablamos antes? Vamos a usarlas para decirle al servo a dónde moverse.

Afortunadamente, Arduino facilita esta tarea con una biblioteca incorporada llamada ``Servo``. Con esta biblioteca, podemos crear un objeto ``Servo``, adjuntar un pin a él (el pin al que está conectado nuestro servo) y luego usar un comando simple, ``write()``, para establecer el ángulo.

Aquí tienes un fragmento de código que muestra cómo hacerlo:

.. code-block:: arduino

    #include <Servo.h> 

    Servo myServo;  // crear un objeto servo

    void setup() {
        myServo.attach(6);  // adjunta el servo al pin 6
    }

    void loop() {
        myServo.write(90);  // indica al servo que vaya a 90 grados
    }

En este código, ``myServo`` es nuestro objeto Servo, ``attach(6)`` le dice al Arduino que nuestro servo está conectado al pin 6, y ``write(90)`` indica al servo que se mueva a 90 grados.

¡Gran trabajo, exploradores! Acaban de aprender a controlar un servo con Arduino. ¡También pueden experimentar con diferentes ángulos!

**Paso 4: Ensamblar el Sistema Visual**

Ahora estás listo para ensamblar el sistema visual de nuestro Rover.

.. note::

    * Al insertar la ESP32 CAM en el Adaptador de Cámara, ten en cuenta su orientación. Debe alinearse correctamente con el adaptador ESP32.

    .. image:: img/esp32_cam_direction.png
        :width: 300
        :align: center
    
.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/h43JVI3xLqE?si=Q7-RvRvZOusK7vPo" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Paso 5: Comprender los Límites del Mecanismo de Inclinación**

Aunque el servo está diseñado para rotar entre 0 y 180 grados, puedes notar que deja de responder después de cierto punto (digamos, después de 150 grados). ¿Te has preguntado por qué ocurre esto? ¡Vamos a explorar este misterio en nuestra próxima aventura!


¿Puedes imaginar a un pájaro intentando inclinar su cuello tanto que choca contra su propio cuerpo y no puede moverse más? El mecanismo de inclinación de nuestro Rover enfrenta una situación similar. A medida que el servo mueve el mecanismo hacia abajo, puede chocar con el cuerpo del Rover y no puede ir más allá de cierto ángulo.

Si intentamos forzarlo más allá de este punto escribiendo un ángulo inalcanzable en nuestro código, nuestro pequeño servo podría atascarse e incluso dañarse. ¡No queremos que eso ocurra! Así que vamos a entender las limitaciones de su movimiento con un pequeño experimento.

Usamos un bucle for para rotar el servo de 0 a 180 grados mientras observamos el ángulo en el Monitor Serial.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/848c7a3a-16b2-4a7e-8d66-bb91848bc6d9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

* La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Entonces, antes de cargar el código, primero necesitarás liberar la ESP32-CAM deslizando este interruptor hacia el lado derecho para evitar conflictos o posibles problemas.

    .. image:: img/camera_upload.png
        :width: 600

* Después de cargar este código, abre el **Monitor Serial**. Si no aparece información, presiona el **botón de reinicio** en el escudo GalaxyRVR para ejecutar el código nuevamente. 

* Verás cómo el servo rota y el Monitor Serial mostrará el ángulo.

.. image:: img/servo_range.png

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/servo_range.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>
    
En mi Rover, el mecanismo de inclinación podía moverse hasta unos 140° antes de golpear el cuerpo del Rover y no poder avanzar más.


Así que, exploradores, recuerden siempre respetar los límites de su Rover para mantenerlo seguro y funcionando correctamente.


**Paso 6: Compartir y Reflexionar**


¡Bien hecho, exploradores! Hoy, no solo construyeron un mecanismo de inclinación para su Rover, sino que también aprendieron cómo controlar un servo para moverlo. Eso es un gran paso adelante en nuestra misión con el Rover Marciano.

Ahora, compartamos nuestras experiencias y reflexionemos sobre lo que hemos aprendido. 

¿Te encontraste con algún desafío al configurar el mecanismo de inclinación o al programar el servo? ¿Cómo los superaste?

Recuerda, cada desafío que superamos nos hace más inteligentes y mejora nuestro Rover. Así que no dudes en compartir tus historias, ideas y soluciones. ¡Nunca se sabe, tu solución innovadora podría ayudar a otro explorador en su viaje!

