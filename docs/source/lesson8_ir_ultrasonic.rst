.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirte?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy!

Lección 8: Sistema avanzado de evasión de obstáculos y seguimiento inteligente
===================================================================================

En la lección de hoy, vamos a llevar nuestras habilidades STEAM un paso más allá. 
Combinaremos un módulo de evasión de obstáculos con un sensor ultrasónico para 
crear un sistema avanzado de evasión de obstáculos. Además, implementaremos un 
sistema de seguimiento inteligente para nuestro Rover.

Al final de esta lección, nuestro Rover Marciano no solo podrá evitar obstáculos en 
su camino, sino que también seguirá objetos en movimiento. ¡Imagina tener una mini 
mascota robótica siguiéndote a todas partes! Emocionante, ¿verdad? ¡Comencemos!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::

    Si estás siguiendo este curso después de haber ensamblado completamente el GalaxyRVR, debes mover este interruptor hacia la derecha antes de cargar el código.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Objetivos del curso
--------------------------

* Aprender a combinar módulos de evasión de obstáculos con un módulo ultrasónico para mejorar la navegación.
* Comprender los principios y funcionalidades detrás de un sistema avanzado de evasión de obstáculos.
* Aprender a implementar un sistema de seguimiento inteligente en el Rover Marciano.

Materiales necesarios
------------------------

* Modelo del Rover Marciano (el que construimos en lecciones anteriores)
* Cable USB
* Arduino IDE
* Computadora
* ¡Y, por supuesto, tu creatividad!

Pasos del curso
--------------------

**Paso 1: Comprender el concepto**

El módulo de evasión de obstáculos, como su nombre lo indica, ayuda a nuestro Rover a evitar obstáculos. Detecta obstáculos transmitiendo una señal infrarroja y luego recibiendo la señal reflejada por el objeto. Si hay un obstáculo frente al módulo, la señal infrarroja se refleja, y el módulo lo detecta.

Ahora, al agregar un sensor ultrasónico al sistema, mejoramos esta capacidad. 
Los sensores ultrasónicos miden distancias enviando una onda sonora a una frecuencia 
específica y escuchando el rebote de esa onda. Al registrar el tiempo transcurrido entre 
la emisión de la onda sonora y su rebote, es posible calcular la distancia entre el sensor y el objeto.

¡La combinación de estos dos sensores nos ofrece un sistema de evasión de obstáculos fiable, eficiente y versátil!


**Paso 2: Construcción de sistemas avanzados de evasión de obstáculos**

En lecciones anteriores, aprendimos los fundamentos de la evasión de obstáculos usando sensores infrarrojos. También exploramos cómo funciona un módulo ultrasónico. Ahora, vamos a juntar todas estas piezas y construir un sistema avanzado de evasión de obstáculos.

Nuestro Rover Marciano mejorado usará tanto sensores ultrasónicos como infrarrojos para navegar por su entorno.

Imaginemos cómo deben trabajar juntos los módulos infrarrojo y ultrasónico. Para aclarar nuestra lógica, utilizaremos un diagrama de flujo. Aprender a crear diagramas de flujo es un paso invaluable en nuestro viaje de programación, ya que ayuda a clarificar tus pensamientos y a planificar de manera sistemática.

.. image:: img/ultrasonic_ir_avoid_flowchart.png
    :width: 800

Ahora vamos a convertir este diagrama de flujo en código para darle vida a nuestro Rover.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/53d72ee5-a4c8-4524-92f8-4b0f4760c015/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nota que la función ``handleForwardMovement()`` es donde hemos integrado el comportamiento del sensor ultrasónico. Leemos los datos de distancia del sensor y, en función de estos datos, decidimos el movimiento del Rover.

Después de cargar el código en tu placa R3, es hora de probar el sistema. Asegúrate de que el Rover pueda detectar y evitar obstáculos de manera eficiente. Recuerda que puedes necesitar ajustar la distancia de detección en el código según tu entorno real para perfeccionar el sistema.

**Paso 3: Programación del sistema de seguimiento inteligente**

Ahora que nuestro Rover puede evitar obstáculos, vamos a mejorarlo aún más haciéndolo seguir objetos. Nuestro objetivo es modificar el código existente para que el Rover se mueva hacia un objeto en movimiento.

¿Alguna vez te has preguntado sobre las diferencias entre un sistema de seguimiento y un sistema de evasión de obstáculos?

La clave aquí es que en un sistema de seguimiento, queremos que nuestro Rover se mueva en respuesta a los objetos detectados, mientras que en un sistema de evasión de obstáculos, buscamos evitar esos objetos.

Visualicemos el flujo de trabajo deseado:

.. image:: img/ultrasonic_ir_follow_flowchart.png

* Si el sensor ultrasónico detecta un objeto entre 5 y 30 cm, nuestro Rover debería moverse hacia él.
* Si el sensor infrarrojo izquierdo detecta un objeto, el Rover debería girar a la izquierda.
* Si el sensor infrarrojo derecho detecta un objeto, el Rover debería girar a la derecha.
* En todos los demás casos, el Rover debería permanecer detenido.

Ahora, es momento de completar el código.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/75662c17-4b0a-4494-b18b-089cc2b32311/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Una vez completado el código, prueba si el Rover sigue tus movimientos.

Al igual que con el sistema de evasión de obstáculos, será crucial probar nuestro sistema de seguimiento y resolver cualquier problema que pueda surgir. ¿Listo para comenzar?


**Paso 4: Resumen y reflexión**

Hoy has logrado algo asombroso. Has combinado diferentes módulos y conceptos para crear un sistema avanzado de evasión de obstáculos y seguimiento para tu Rover Marciano. Recuerda que el aprendizaje no termina aquí: sigue explorando, innovando y aplicando tus nuevas habilidades en otros proyectos.

Reflexiona siempre sobre tu proceso de aprendizaje. Piensa en lo siguiente:

* ¿Por qué crees que priorizamos el módulo de evasión de obstáculos antes que el sensor ultrasónico en nuestro sistema de evasión de obstáculos, y al revés en el sistema de seguimiento?
* ¿Cómo cambiaría el resultado si intercambiáramos el orden en que se verifican estos módulos en el código?

Los desafíos y problemas son una parte integral del proceso de aprendizaje STEAM, ya que ofrecen valiosas oportunidades para mejorar. No tengas miedo de resolver problemas, ¡es una poderosa herramienta de aprendizaje!

A medida que continúas en tu viaje, recuerda que cada obstáculo que superes te acerca un paso más a dominar tus habilidades STEAM. ¡Sigue adelante y disfruta del viaje!

