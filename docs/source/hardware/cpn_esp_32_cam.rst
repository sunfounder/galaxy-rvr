.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

ESP32 CAM
=================

.. image:: img/esp32_cam.png
    :width: 500
    :align: center

El ESP32-CAM es un módulo de cámara muy pequeño con el chip ESP32-S que cuesta aproximadamente $10. Además de la cámara OV2640 y varios GPIOs para conectar periféricos, también cuenta con una ranura para tarjeta microSD que puede ser útil para almacenar imágenes tomadas con la cámara o para guardar archivos que servir a los clientes.

El módulo puede funcionar de forma independiente como el sistema más pequeño, con un tamaño de solo 27*40.5*4.5mm, y una corriente en modo de suspensión profunda tan baja como 6mA.

ESP32-CAM se puede utilizar ampliamente en diversas aplicaciones IoT, adecuado para dispositivos inteligentes del hogar, control inalámbrico industrial, monitoreo inalámbrico, identificación inalámbrica QR, sistemas de señal de posicionamiento inalámbrico y otras aplicaciones IoT. Es una solución ideal para aplicaciones IoT.



**Especificaciones técnicas**

.. list-table::
    :widths: 25 50

    * - Modelo del módulo
      - ESP32-CAM
    * - Encapsulado
      - DIP-16
    * - Tamaño
      - 27*40.5*4.5（—.2）mm
    * - SPI Flash
      - 32Mbit por defecto
    * - RAM
      - 520KB internos + 8MB PSRAM externos
    * - Bluetooth
      - Bluetooth 4.2 estándares BR/EDR y BLE
    * - Wi-Fi
      - 802.11 b/g/n/e/i
    * - Interfaces compatibles
      - UART、SPI、I2C、PWM
    * - Soporte para tarjeta TF
      - hasta 4G
    * - Pines IO
      -  9
    * - Velocidad del puerto serie
      - 115200 bps por defecto
    * - Formato de salida de imagen
      - JPEG(solo compatible con OV2640),BMP,GRAYSCALE
    * - Rango de espectro
      - 2400 ~2483.5MHz
    * - Tipo de antena
      - Antena PCB integrada, ganancia 2dBi
    * - Potencia de transmisión
      - 802.11b\: 17±2 dBm (@11Mbps)
    * -
      - 802.11g\: 14±2 dBm (@54Mbps)
    * -
      - 802.11n\: 13±2 dBm (@MCS7)
    * - Sensibilidad de recepción
      - CCK, 1 Mbps\: -90dBm,
    * -
      - CCK, 11 Mbps\: -85 dBm
    * -
      - 6 Mbps (1/2 BPSK)\: -88 dBm
    * -
      - 54 Mbps (3/4 64-QAM)\: -70dBm
    * -
      - MCS7 (65 Mbps, 72.2 Mbps)\: -67dBm
    * - Consumo de energía
      - Flash apagado\: 180mA\@5V,
    * -
      - Flash encendido y brillo máximo\: 310mA\@5V
    * -
      - Suspensión profunda\: el consumo de energía más bajo puede alcanzar 6mA\@5V
    * -
      - Suspensión en módem\: mínimo 20mA\@5V
    * -
      - Suspensión ligera\: mínimo 6.7mA\@5V
    * - Seguridad
      - WPA/WPA2/WPA2-Enterprise/WPS
    * - Rango de alimentación
      - 4.75-5.25V
    * - Temperatura de funcionamiento
      - -20 —~ 70 —
    * - Ambiente de almacenamiento
      - -40 —~ 125 —, < 90%HR


**Distribución de pines del ESP32-CAM**


La siguiente figura muestra la distribución de pines del ESP32-CAM (módulo AI-Thinker).

.. image:: img/esp32_cam_pinout.png
    :width: 800

* Hay tres pines **GND** y tres pines para alimentación: 3.3V, 5V y opcionalmente 3.3V o 5V.
* **GPIO 1** y **GPIO 3** son los pines serie. Necesita estos pines para cargar código en su placa.
* Adicionalmente, **GPIO 0** también juega un papel importante, ya que determina si el ESP32 está en modo de grabación o no. Cuando **GPIO 0** está conectado a **GND**, el ESP32 está en modo de grabación.

* Los siguientes pines están conectados internamente al lector de tarjetas microSD:

* GPIO 14: CLK
* GPIO 15: CMD
* GPIO 2: Data 0
* GPIO 4: Data 1 (también conectado al LED integrado)
* GPIO 12: Data 2
* GPIO 13: Data 3

**Nota**

* Asegúrese de que la potencia de entrada del módulo sea de al menos 5V 2A, de lo contrario, la imagen puede tener líneas de agua.
* El pin GPIO32 del ESP32 controla la alimentación de la cámara. Cuando la cámara está funcionando, ponga GPIO32 a nivel bajo.
* Dado que GPIO0 está conectado al XCLK de la cámara, deje GPIO0 al aire cuando lo utilice y no lo conecte a nivel alto o bajo.
* El firmware predeterminado ya está incluido de fábrica y no se proporciona una descarga adicional. Tenga cuidado si necesita reprogramar otro firmware.


**Documentación**

* Diagrama esquemático: |link_esp32cam_schematic|
* Especificaciones de la cámara (versión en inglés): |link_cam_ov2640|

.. note::
    Toda la información anterior proviene de |link_aithiner|
