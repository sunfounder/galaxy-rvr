.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Placa SunFounder R3
===========================

.. image:: img/uno_r3.jpg
    :width: 600
    :align: center

.. note::

    La placa SunFounder R3 es una placa base con casi las mismas funciones que el `Arduino Uno <https://store.arduino.cc/products/arduino-uno-rev3/>`_, y ambas placas se pueden usar indistintamente.

La placa SunFounder R3 es una placa de microcontrolador basada en el ATmega328P (`hoja de datos <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_). Tiene 14 pines digitales de entrada/salida (de los cuales 6 se pueden usar como salidas PWM), 6 entradas analógicas, un resonador cerámico de 16 MHz (CSTCE16M0V53-R0), una conexión USB, un conector de alimentación, un cabezal ICSP y un botón de reinicio. Contiene todo lo necesario para soportar el microcontrolador; simplemente conéctela a una computadora con un cable USB o aliméntela con un adaptador CA-CC o una batería para ponerla en marcha.

**Parámetros técnicos**

.. image:: img/uno.jpg
    :align: center

* MICROCONTROLADOR: ATmega328P
* TENSIÓN DE OPERACIÓN: 5V
* TENSIÓN DE ENTRADA (RECOMENDADA): 7-12V
* TENSIÓN DE ENTRADA (LÍMITE): 6-20V
* PINES DIGITALES E/S: 14 (0-13, de los cuales 6 proporcionan salida PWM(3, 5, 6, 9-11))
* PINES DIGITALES PWM E/S: 6 (3, 5, 6, 9-11)
* PINES DE ENTRADA ANALÓGICA: 6 (A0-A5)
* CORRIENTE CC POR PIN E/S: 20 mA
* CORRIENTE CC PARA PIN 3.3V: 50 mA
* MEMORIA FLASH: 32 KB (ATmega328P) de los cuales 0.5 KB usados por el bootloader
* SRAM: 2 KB (ATmega328P)
* EEPROM: 1 KB (ATmega328P)
* VELOCIDAD DE RELOJ: 16 MHz
* LED_BUILTIN: 13
* LONGITUD: 68.6 mm
* ANCHURA: 53.4 mm
* PESO: 25 g
* Puerto I2C: A4(SDA), A5(SCL)


**Más información**

* `Arduino IDE <https://www.arduino.cc/en/software>`_
* `Referencia del lenguaje de programación Arduino <https://www.arduino.cc/reference/en/>`_
* `Hoja de datos del ATmega328P <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_
