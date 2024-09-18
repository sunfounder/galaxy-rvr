.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirte?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

Módulo de evitación de obstáculos IR
=======================================

Este es un módulo de evitación de obstáculos por infrarrojos que puede detectar la presencia de objetos delante de él. Es comúnmente utilizado en robots, sistemas de automatización y otros dispositivos inteligentes. Su rango de detección es de 2 cm a 40 cm, y los objetos de diferentes colores tienen diferentes niveles de reflectividad. Por lo tanto, cuanto más oscuro sea el objeto, menor será la distancia de detección.

.. image:: img/ir_avoid.png
    :width: 400
    :align: center

Aquí están las definiciones de los pines:

* **GND**: Tierra.
* **+**: Fuente de alimentación, 3.3 ~ 5V DC.
* **Out**: Por defecto, se mantiene en alto y solo baja cuando detecta un obstáculo.
* **EN**: Este pin de **activación** decide cuándo debe funcionar el módulo. Por defecto, está conectado a GND, lo que significa que el módulo siempre está activado.

**¿Cómo funciona?**

Este módulo contiene un par de componentes emisores y receptores de infrarrojos. Básicamente, el emisor emite luz infrarroja, cuando esta luz emitida encuentra un obstáculo, se refleja y es recibida por el receptor. Al detectarlo, el indicador se enciende. Tras el procesamiento del circuito, se emite una señal de nivel bajo.

.. image:: img/ir_receive.png
    :width: 600
    :align: center

El estado de nivel bajo del pin **EN** activa el módulo, con el puente asegurando el pin **EN** al GND. Para controlar el pin EN de manera programada, retira el puente.

.. image:: img/ir_cap.png
    :width: 400
    :align: center

Hay dos potenciómetros en el módulo, uno para ajustar la potencia de transmisión y otro para ajustar la frecuencia de transmisión. Ajustando estos dos potenciómetros, puedes modificar la distancia efectiva.

.. image:: img/ir_avoid_pot.png
    :width: 400
    :align: center 


**Ajustar la distancia de detección**

El rango de detección del módulo de evitación de obstáculos debe calibrarse con precisión para un rendimiento óptimo, ya que la configuración de fábrica puede no alinearse con los requisitos específicos.

La calibración implica los siguientes pasos:

#. Alineación del módulo: Comienza con el módulo de evitación de obstáculos del lado derecho. El transporte puede ocasionalmente desalinear el emisor y el receptor infrarrojos del módulo. Deben ser realineados manualmente para garantizar la precisión.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Coloca un obstáculo a unos 20 cm directamente frente al módulo derecho. ¡La caja en la que vino nuestro kit Rover es una buena opción para esto! Ahora, gira el potenciómetro en el módulo hasta que la luz indicadora del módulo se encienda. Luego, mueve el obstáculo hacia adelante y hacia atrás para verificar si la luz indicadora se enciende a la distancia deseada. Si la luz no se enciende a la distancia correcta o si permanece encendida sin apagarse, deberás ajustar el otro potenciómetro.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Repite el mismo proceso para el otro módulo.

**Características**

* Voltaje de operación: 3.3 V a 5 V
* Salida: digital (encendido/apagado)
* Umbral de detección: ajustable mediante 2 potenciómetros
* Rango de distancia: 2 a 40 cm
* Ajuste R5: ajuste de frecuencia a 38 kHz (ya optimizado)
* Ajuste R6: ajuste del ciclo de trabajo del LED IR (ya optimizado)
* Temperatura de operación: -10 °C a +50 °C
* Ángulo efectivo: 35°
* Interfaz I/O: interfaz de 4 cables (- / + / S / EN)
* Dimensiones: 45 x 16 x 10 mm
* Peso: 9 g

