.. note::

    ¡Hola, bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas post-venta y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Accede anticipadamente a los anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy mismo!

ESP32 CAM
=================

.. image:: img/esp32_cam.png
    :width: 500
    :align: center

El ESP32-CAM es un módulo de cámara muy pequeño con el chip ESP32-S que cuesta aproximadamente $10. Además de la cámara OV2640 y varios GPIOs para conectar periféricos, también cuenta con una ranura para tarjeta microSD que puede ser útil para almacenar imágenes tomadas con la cámara o para almacenar archivos y servir a los clientes.

El módulo puede funcionar de manera independiente como el sistema más pequeño, con un tamaño de solo 27*40.5*4.5mm, y una corriente de sueño profundo de tan solo 6mA.

ESP32-CAM se puede utilizar ampliamente en diversas aplicaciones de IoT, como dispositivos inteligentes para el hogar, control inalámbrico industrial, monitoreo inalámbrico, identificación inalámbrica de QR, sistemas de posicionamiento inalámbrico y otras aplicaciones IoT. Es una solución ideal para aplicaciones IoT.



**Especificaciones Técnicas**

.. list-table::
    :widths: 25 50

    * - Modelo del módulo
      - ESP32-CAM
    * - Empaque
      - DIP-16
    * - Tamaño
      - 27*40.5*4.5（±0.2）mm
    * - SPI Flash
      - 32Mbit por defecto
    * - RAM
      - 520KB interna + 8MB PSRAM externa
    * - Bluetooth
      - Bluetooth 4.2 BR/EDR y estándares BLE
    * - Wi-Fi
      - 802.11 b/g/n/e/i
    * - Interfaces compatibles
      - UART, SPI, I2C, PWM
    * - Soporte para tarjeta TF
      - Hasta 4G
    * - Pines IO
      - 9
    * - Velocidad del puerto serie
      - 115200 bps por defecto
    * - Formato de salida de imagen
      - JPEG (solo compatible con OV2640), BMP, ESCALA DE GRISES
    * - Rango de espectro
      - 2400 ~2483.5MHz
    * - Tipo de antena
      - Antena PCB integrada, ganancia 2dBi
    * - Potencia de transmisión
      - 802.11b: 17±2 dBm (@11Mbps) 
    * - 
      - 802.11g: 14±2 dBm (@54Mbps) 
    * - 
      - 802.11n: 13±2 dBm (@MCS7)
    * - Sensibilidad de recepción
      - CCK, 1 Mbps: -90dBm, 
    * - 
      - CCK, 11 Mbps: -85 dBm
    * - 
      - 6 Mbps (1/2 BPSK): -88 dBm
    * - 
      - 54 Mbps (3/4 64-QAM): -70dBm
    * - 
      - MCS7 (65 Mbps, 72.2 Mbps): -67dBm
    * - Consumo de energía
      - Flash apagado: 180mA@5V
    * - 
      - Flash encendido y brillo máximo: 310mA@5V
    * - 
      - Sueño profundo: el consumo de energía más bajo puede llegar a 6mA@5V
    * - 
      - Sueño moderno: mínimo 20mA@5V
    * - 
      - Sueño ligero: mínimo 6.7mA@5V
    * - Seguridad
      - WPA/WPA2/WPA2-Enterprise/WPS
    * - Rango de alimentación
      - 4.75-5.25V
    * - Temperatura de funcionamiento
      - -20 ℃ ~ 70 ℃
    * - Entorno de almacenamiento
      - -40 ℃ ~ 125 ℃, < 90%HR


**Distribución de Pines ESP32-CAM**


La siguiente imagen muestra la distribución de pines del ESP32-CAM (módulo AI-Thinker).

.. image:: img/esp32_cam_pinout.png
    :width: 800

* Hay tres pines **GND** y tres pines para alimentación: 3.3V, 5V y uno que puede ser 3.3V o 5V.
* **GPIO 1** y **GPIO 3** son los pines seriales. Necesitarás estos pines para cargar código en tu placa.
* Además, **GPIO 0** también juega un papel importante, ya que determina si el ESP32 está en modo de flash o no. Cuando **GPIO 0** está conectado a **GND**, el ESP32 está en modo flash.

* Los siguientes pines están conectados internamente al lector de tarjetas microSD:

* GPIO 14: CLK
* GPIO 15: CMD
* GPIO 2: Data 0
* GPIO 4: Data 1 (también conectado al LED integrado)
* GPIO 12: Data 2
* GPIO 13: Data 3

**Nota**

* Asegúrate de que la alimentación del módulo sea de al menos 5V 2A, de lo contrario la imagen puede presentar líneas de agua.
* El pin GPIO32 del ESP32 controla la alimentación de la cámara. Cuando la cámara está funcionando, por favor, baja GPIO32.
* Dado que GPIO0 está conectado al XCLK de la cámara, por favor, deja GPIO0 al aire cuando lo uses, y no lo conectes a nivel alto o bajo.
* El firmware predeterminado ya está incluido de fábrica y no se proporciona una descarga adicional. Ten cuidado si necesitas reprogramar otro firmware.


**Documentos**

* Diagrama esquemático: |link_esp32cam_schematic|
* Especificaciones de la cámara (versión en inglés): |link_cam_ov2640|

.. note::
    Toda la información anterior proviene de |link_aithiner|
