.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirte?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

Módulo Ultrasónico
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG**: Entrada de pulso de disparo
* **ECHO**: Salida de pulso de eco
* **GND**: Tierra
* **VCC**: Alimentación de 5V

Este es el sensor ultrasónico de distancia HC-SR04, que proporciona medición sin contacto desde 2 cm hasta 400 cm, con una precisión de hasta 3 mm. El módulo incluye un transmisor ultrasónico, un receptor y un circuito de control.

Solo necesitas conectar 4 pines: VCC (alimentación), Trig (disparo), Echo (recepción) y GND (tierra) para usarlo fácilmente en tus proyectos de medición.

**Características**

* Voltaje de trabajo: DC5V
* Corriente de trabajo: 16mA
* Frecuencia de trabajo: 40Hz
* Rango máximo: 500cm
* Rango mínimo: 2cm
* Señal de entrada de disparo: Pulso TTL de 10uS
* Señal de salida de eco: Señal TTL proporcional a la distancia
* Conector: XH2.54-4P
* Dimensiones: 46x20.5x15 mm

**Principio de funcionamiento**

Los principios básicos son los siguientes:

* Usar un disparo de IO con una señal de nivel alto de al menos 10us.
* El módulo emite una ráfaga de ultrasonido de 8 ciclos a 40 kHz y detecta si se recibe una señal de pulso.
* El pin de Echo emitirá un nivel alto si se devuelve una señal; la duración del nivel alto es el tiempo desde la emisión hasta el retorno.
* Distancia = (tiempo de nivel alto x velocidad del sonido (340M/S)) / 2

    .. image:: img/ultrasonic_prin.jpg
        :width: 800


**Notas de aplicación**

* Este módulo no debe conectarse con la alimentación encendida; si es necesario, asegúrate de conectar primero el pin GND del módulo. De lo contrario, afectará el funcionamiento del módulo.
* El área del objeto a medir debe ser de al menos 0.5 metros cuadrados y lo más plana posible. De lo contrario, afectará los resultados.

