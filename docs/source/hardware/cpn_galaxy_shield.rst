.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas post-venta y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Obtén acceso anticipado a los nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy mismo!

GalaxyRVR Shield
=========================

.. image:: img/galaxy_shield.jpg
    :width: 500
    :align: center

Esta es una placa de expansión todo-en-uno diseñada para Arduino por SunFounder, que contiene varios puertos para módulos como motor, tira RGB, evasión de obstáculos, escala de grises, ESP32 CAM y módulo ultrasónico.

Esta placa de expansión también tiene un circuito de carga integrado, que puede cargar la batería con una interfaz PH2.0-3P, y el tiempo estimado de carga es de 130 minutos.

**Distribución de Pines**

.. image:: img/galaxyrvr_shield_pinout.png

* Puerto de carga:
    * Después de conectar al puerto USB-C de 5V/2A, se puede usar para cargar la batería durante 130 minutos.

* **Puerto de batería**: 
    * Entrada de alimentación de 6.6V~8.4V PH2.0-3P.
    * Alimenta tanto la placa GalaxyRVR Shield como la placa Arduino al mismo tiempo.

* Botón de reinicio:
    * Presiona este botón para reiniciar el programa en la placa Arduino.

* Indicadores:
    * **Indicador de carga**: Se ilumina en rojo cuando la shield se está cargando a través del puerto USB-C.
    * **Indicador de encendido**: Se ilumina en verde cuando el interruptor de encendido está en la posición "ON".
    * **Indicador de batería**: Dos indicadores naranjas representan diferentes niveles de batería. Parpadean durante la carga y se apagan cuando la batería necesita ser recargada.

* Interruptor de encendido:
    * Deslízalo a la posición ON para encender el GalaxyRVR.

* Servo de la cámara:
    * El servo de la cámara está conectado aquí.
    * El cable marrón se conecta a "-", el cable rojo a "+" y el cable amarillo al Pin 6.

* :ref:`shield_motor_pin`:
    * **Puerto del motor (derecho)**: Se pueden conectar 3 motores, pero los 3 motores son controlados por el mismo conjunto de señales, **pines 2 y 3**.
    * **Puerto del motor (izquierdo)**: Se pueden conectar 3 motores, pero los 3 motores son controlados por el mismo conjunto de señales, **pines 4 y 5**.
    * Tipo de puerto: XH2.54, 2P.

* :ref:`shield_strip_pin`:
    * Para conectar 2 tiras LED RGB, los tres pines de la tira están conectados a los pines **12, 13 y 11**, respectivamente.
    * Tipo de puerto: ZH1.5, 4P.

* :ref:`shield_avoid_pin`:
    * Usado para conectar dos módulos infrarrojos de evasión de obstáculos.
    * El **módulo de evasión izquierdo** se conecta al **pin 8** y el **módulo de evasión derecho** se conecta al **pin 7**.
    * Tipo de puerto: ZH1.5, 3P.

* :ref:`shield_camera_pin`:
    * El puerto de la placa adaptadora de la cámara.
    * Tipo de puerto: ZH1.5, 5P.

* :ref:`shield_ultrasonic_pin`:
    * Para conectar el módulo ultrasónico, los pines Trig y Echo están conectados al **pin 10** de la placa Arduino.
    * Tipo de puerto: ZH1.5, 4P.

* Interruptor de modo:
    * El ESP32-CAM y la placa Arduino comparten los mismos pines RX (recibir) y TX (transmitir).
    * Cuando cargues código, debes cambiar este interruptor a la **derecha** para desconectar el ESP32-CAM y evitar conflictos o problemas potenciales.
    * Cuando necesites usar la cámara, cambia el interruptor a la **izquierda** para que el ESP32-CAM pueda comunicarse con la placa Arduino.

* SOLAR:
    * Este es el puerto para el panel solar, que puede cargar la batería cuando se conecta al panel solar.
    * Tipo de puerto: XH2.54, 2P.


.. _shield_ultrasonic_pin:

SONAR
--------------------

Esta es la distribución de pines para el puerto ultrasónico ZH1.5-4P, con los pines Trig y Echo conectados al pin 10 de la placa Arduino.

.. image:: img/ultrasonic_shield.png

.. _shield_camera_pin:

CÁMARA
----------------------

Aquí se muestra el diagrama de pines de la interfaz adaptadora de la cámara, el tipo es ZH1.5-7P.

* TX y RX se utilizan para el ESP32 CAM.

.. image:: img/camera_shield.png


.. _shield_avoid_pin:

IR IZQUIERDO/DERECHO 
----------------------------

Estos son los pines para los módulos de evasión de obstáculos izquierdo y derecho.

.. image:: img/ir_shield.png


.. _shield_strip_pin:

Tira RGB
-------------------------

A continuación se muestra el diagrama de pines de las dos tiras LED RGB, están conectadas en paralelo y los pines son los mismos.

.. image:: img/rgb_shield.png



.. _shield_motor_pin:

Puerto de motor
-------------------

Aquí está el diagrama de pines de los 2 puertos de motor.

.. image:: img/motor_shield.png
    :width: 600
    :align: center
