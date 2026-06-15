.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Módulo Ultrasónico
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG**: Entrada de pulso de disparo
* **ECHO**: Salida de pulso de eco
* **GND**: Tierra
* **VCC**: Alimentación de 5V

Este es el sensor ultrasónico de distancia HC-SR04, que proporciona medición sin contacto desde 2 cm hasta 400 cm con una precisión de alcance de hasta 3 mm. El módulo incluye un transmisor ultrasónico, un receptor y un circuito de control.

Solo necesita conectar 4 pines: VCC (alimentación), Trig (disparo), Echo (recepción) y GND (tierra) para facilitar su uso en sus proyectos de medición.

**Características**

* Voltaje de trabajo: DC5V
* Corriente de trabajo: 16mA
* Frecuencia de trabajo: 40Hz
* Alcance máximo: 500cm
* Alcance mínimo: 2cm
* Señal de entrada de disparo: pulso TTL de 10uS
* Señal de salida de eco: señal de nivel TTL de entrada y la proporción del alcance
* Conector: XH2.54-4P
* Dimensiones: 46x20.5x15 mm

**Principio**

Los principios básicos son los siguientes:

* Utilizar la activación por IO para una señal de nivel alto de al menos 10us.
* El módulo envía una ráfaga de 8 ciclos de ultrasonido a 40 kHz y detecta si se recibe una señal de pulso.
* Echo emitirá un nivel alto si se recibe una señal; la duración del nivel alto es el tiempo desde la emisión hasta el retorno.
* Distancia = (tiempo de nivel alto x velocidad del sonido (340 m/s)) / 2

    .. image:: img/ultrasonic_prin.jpg
        :width: 800



**Notas de aplicación**

* Este módulo no debe conectarse mientras esté encendido; si es necesario, conecte primero el GND del módulo. De lo contrario, afectará el funcionamiento del módulo.
* El área del objeto a medir debe ser de al menos 0.5 metros cuadrados y lo más plana posible. De lo contrario, afectará los resultados.
