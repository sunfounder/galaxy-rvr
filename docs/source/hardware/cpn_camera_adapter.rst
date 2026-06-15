.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Placa Adaptadora de Cámara
==========================

.. image:: img/cam_adapter_board.jpg
    :width: 500
    :align: center

* **RST**: Se utiliza para resetear el ESP32-CAM.
* **SCL**: Pin de datos serie para QMC6310
* **SDA**: Pin de reloj serie del QMC6310
* **RXD**: RXD del ESP32-CAM, necesita cargar código al ESP32-CAM a través de estos dos pines serie, RXD y TXD.
* **TXD**: TXD del ESP32-CAM
* **5V**: Entrada de alimentación de 5V DC
* **GND**: Entrada de tierra

La Placa Adaptadora de Cámara, como su nombre indica, es una placa de expansión para el ESP32-CAM, utilizada para expandir el ESP32-CAM de modo que pueda fijarse al robot y cablearse fácilmente.

.. image:: img/cam_adapter_esp32cam.png
    :width: 400
    :align: center

Además, debido a que el chip geomagnético QMC6310 es susceptible a las interferencias de los motores, lo colocamos en esta placa adaptadora de cámara para mantenerlo lo más alejado posible de los motores.

.. image:: img/cam_adapter_qmc6310.png
    :width: 400
    :align: center

**Características**

* Voltaje de trabajo: 5V
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

El QMC6310 es un sensor magnético de tres ejes que integra sensores magnéticos y un ASIC de acondicionamiento de señales en un solo chip de silicio. Este encapsulado LGA (Land Grid Array) está diseñado para aplicaciones como brújula electrónica, rotación de mapas, juegos y navegación personal en dispositivos móviles y portátiles.

El QMC6310 está basado en tecnología magneto-resistiva de alta resolución y última generación. Junto con el ASIC ADC de 16 bits diseñado a medida, ofrece las ventajas de bajo ruido, alta precisión, bajo consumo de energía, cancelación de offset y compensaciones de temperatura. El QMC6310 permite una precisión de rumbo de brújula de 1° a 2°. El bus serie I²C permite una interfaz sencilla.

El QMC6310 viene en un encapsulado LGA de montaje superficial de 8 pines de 1.2x1.2x0.53mm³.

* |link_qmc6310_datasheet|
