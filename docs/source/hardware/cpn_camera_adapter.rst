.. note::

    ¡Hola, bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas post-venta y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Accede anticipadamente a los anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy mismo!

Placa Adaptadora de Cámara
=================================

.. image:: img/cam_adapter_board.jpg
    :width: 500
    :align: center

* **RST**: Se utiliza para reiniciar el ESP32-CAM.
* **SCL**: Pin de datos en serie para el QMC6310.
* **SDA**: Pin de reloj en serie del QMC6310.
* **RXD**: RXD del ESP32-CAM, necesario para cargar el código a través de estos dos pines seriales, RXD y TXD.
* **TXD**: TXD del ESP32-CAM.
* **5V**: Entrada de alimentación de 5V DC.
* **GND**: Entrada de tierra.

La Placa Adaptadora de Cámara, como su nombre lo indica, es una placa de expansión para el ESP32-CAM, diseñada para asegurar el ESP32-CAM al robot y facilitar su cableado.

.. image:: img/cam_adapter_esp32cam.png
    :width: 400
    :align: center

Además, debido a que el chip geomagnético QMC6310 es susceptible a interferencias de los motores, lo colocamos en esta placa adaptadora para mantenerlo lo más alejado posible de los motores.

.. image:: img/cam_adapter_qmc6310.png
    :width: 400
    :align: center

**Características**

* Voltaje de funcionamiento: 5V
* Modelo de interfaz: ZH1.5, 7P
* Dimensiones: 40mm x 27mm x 15mm
* Protocolo de comunicación: UART e I2C

**Documentos**

* PCB

.. image:: img/cam_adap_pcb_bottom.png
    :width: 300

.. image:: img/cam_adap_pcb_top.png
    :width: 300

* Esquemático

.. image:: img/cam_adapter_sche.png


**Acerca del QMC6310**

El QMC6310 es un sensor magnético de tres ejes, que integra sensores magnéticos y un ASIC de acondicionamiento de señales en un solo chip de silicio. Este paquete Land Grid Array (LGA) está diseñado para aplicaciones como brújula electrónica, rotación de mapas, juegos y navegación personal en dispositivos móviles y portátiles.

El QMC6310 está basado en tecnología magnetoresistiva de alta resolución y última generación. Junto con el ASIC ADC personalizado de 16 bits, ofrece ventajas como bajo ruido, alta precisión, bajo consumo de energía, cancelación de offset y compensaciones de temperatura. El QMC6310 permite una precisión de rumbo de brújula de 1° a 2°. El bus serie I²C facilita su interfaz.

El QMC6310 viene en un paquete LGA de montaje en superficie de 8 pines de 1.2x1.2x0.53mm3.

* |link_qmc6310_datasheet|
