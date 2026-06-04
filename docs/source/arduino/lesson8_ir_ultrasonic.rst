Lección 8: Sistema Combinado IR + Ultrasónico
================================================================================

En la lección de hoy, vamos a llevar nuestras habilidades STEAM un paso más allá. Combinaremos un módulo de evasión de obstáculos
con un sensor ultrasónico para crear un sistema avanzado de evasión de obstáculos.
También implementaremos un sistema de seguimiento inteligente en nuestro Rover.

Al final de esta lección, nuestro Mars Rover no solo podrá evitar obstáculos en su camino,
sino también seguir objetos en movimiento. ¡Imagina tener una mini mascota robótica siguiéndote!
Es emocionante, ¿verdad? Así que comencemos.

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Tu navegador no soporta la etiqueta de video.
    </video>

.. note::

    Si estás aprendiendo este curso después de haber ensamblado completamente el GalaxyRVR, debes mover este interruptor hacia la derecha antes de cargar el código.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Objetivos del Curso
--------------------------
* Aprender cómo combinar módulos de evasión de obstáculos con un módulo ultrasónico para una navegación mejorada.
* Comprender los principios y funcionalidades detrás de un sistema avanzado de evasión de obstáculos.
* Aprender cómo implementar un sistema de seguimiento inteligente en el Mars Rover.

Materiales del Curso
------------------------

* Modelo Mars Rover (el que construimos en lecciones anteriores)
* Cable USB
* Arduino IDE
* Computadora
* ¡Y por supuesto, tu mente creativa!

Pasos del Curso
--------------------

**Paso 1: Comprender el Concepto**

El módulo de evasión de obstáculos, como su nombre indica, ayuda a nuestro Rover a evitar obstáculos.
Detecta obstáculos transmitiendo una señal infrarroja y luego recibiendo la señal
reflejada de vuelta desde el objeto. Si hay un obstáculo frente al módulo,
la señal infrarroja se refleja y el módulo lo detecta.

Ahora, agregar un sensor ultrasónico a la mezcla mejora este sistema. Los sensores ultrasónicos miden la distancia
enviando una onda sonora a una frecuencia específica y escuchando el rebote de esa onda.
Al registrar el tiempo transcurrido entre la generación de la onda sonora y su rebote,
es posible calcular la distancia entre el sensor y el objeto.

¡Combinar estos dos nos da un sistema de evasión de obstáculos confiable, eficiente y versátil!


**Paso 2: Construcción de Sistemas Avanzados de Evasión de Obstáculos**

En nuestras lecciones anteriores, hemos aprendido los conceptos básicos de la evasión de obstáculos usando sensores infrarrojos. También hemos explorado cómo funciona un módulo ultrasónico. Ahora, vamos a unir todas estas piezas y construir un sistema avanzado de evasión de obstáculos.

Nuestro Mars Rover mejorado ahora utilizará tanto sensores ultrasónicos como infrarrojos para navegar por su entorno.

Imaginemos cómo deberían trabajar juntos los módulos infrarrojo y ultrasónico. Para ayudar a clarificar nuestra lógica, usemos un diagrama de flujo. Aprender a crear diagramas de flujo es un paso invaluable en nuestro viaje de programación, ya que puede ayudarte a clarificar tus pensamientos y planificar sistemáticamente tu enfoque.

.. image:: img/ultrasonic_ir_avoid_flowchart.png
    :width: 800

Ahora convirtamos este diagrama de flujo en código real para dar vida a nuestro Rover.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/53d72ee5-a4c8-4524-92f8-4b0f4760c015/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Observa que la función ``handleForwardMovement()`` es donde hemos integrado el comportamiento del sensor ultrasónico. Leemos los datos de distancia del sensor y, en base a estos datos, decidimos el movimiento del Rover.


Después de cargar el código en tu placa R3, es hora de probar el sistema.
Asegúrate de que el Rover pueda detectar y evitar obstáculos de manera eficiente.
Recuerda que puede ser necesario ajustar la distancia de detección en el código según tu entorno real para perfeccionar el sistema.

**Paso 3: Programación del Sistema de Seguimiento Inteligente**

Con nuestro Rover ahora capaz de evitar obstáculos, mejorémoslo aún más haciéndolo seguir objetos. Nuestro objetivo es modificar el código existente para que el Rover se mueva hacia un objeto en movimiento.

¿Alguna vez te has preguntado sobre las diferencias entre un sistema de seguimiento y un sistema de evasión de obstáculos?

La clave aquí es que en un sistema de seguimiento, queremos que nuestro Rover se mueva en respuesta a los objetos detectados, mientras que en un sistema de evasión de obstáculos, buscamos alejarnos de los objetos detectados.

Visualicemos el flujo de trabajo deseado:

.. image:: img/ultrasonic_ir_follow_flowchart.png

* Si el sensor ultrasónico detecta un objeto dentro de 5-30 cm, nuestro Rover debe moverse hacia él.
* Si el sensor IR izquierdo detecta un objeto, nuestro Rover debe girar a la izquierda.
* Si el sensor IR derecho detecta un objeto, nuestro Rover debe girar a la derecha.
* En todos los demás casos, nuestro Rover debe permanecer estacionario.

Ahora es el momento de completar el código.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/75662c17-4b0a-4494-b18b-089cc2b32311/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Una vez que el código esté completo, prueba si el Rover sigue tus movimientos.

Como hicimos con el sistema de evasión de obstáculos, será crucial probar nuestro sistema de seguimiento y solucionar cualquier problema que pueda surgir. ¿Listo para empezar?


**Paso 4: Resumen y Reflexión**

Hoy has logrado algo increíble. Has combinado diferentes módulos y conceptos para crear un sistema avanzado de evasión de obstáculos y seguimiento para tu Mars Rover. Recuerda, el aprendizaje no termina aquí: sigue explorando, innovando y aplicando tus nuevas habilidades a otros proyectos.

Recuerda reflexionar siempre sobre tu proceso de aprendizaje. Piensa en lo siguiente:

* ¿Por qué crees que priorizamos el módulo de evasión de obstáculos antes que el sensor ultrasónico en nuestro sistema de evasión de obstáculos, y viceversa en el sistema de seguimiento?
* ¿Cómo cambiaría el resultado si intercambiáramos el orden en que se verifican estos módulos en el código?

Los desafíos y problemas son una parte integral del proceso de aprendizaje STEAM, que ofrecen valiosas oportunidades de mejora. No huyas de la resolución de problemas: ¡es una herramienta de aprendizaje poderosa en sí misma!

A medida que continúas tu viaje, recuerda que cada obstáculo que superas te acerca un paso más a dominar tus habilidades STEAM. ¡Sigue adelante y disfruta del viaje!
