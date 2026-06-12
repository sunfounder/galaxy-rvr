.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _cpn_uno:

Scheda SunFounder R3
===========================

.. image:: img/uno_r3.jpg
    :width: 600
    :align: center

.. note::

    La scheda SunFounder R3 è una scheda principale con quasi le stesse funzioni di `Arduino Uno <https://store.arduino.cc/products/arduino-uno-rev3/>`_ e le due schede possono essere utilizzate in modo intercambiabile.

La scheda SunFounder R3 è una scheda microcontrollore basata su ATmega328P (`scheda tecnica <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_). Dispone di 14 pin di input/output digitali (di cui 6 possono essere utilizzati come uscite PWM), 6 ingressi analogici, un risonatore ceramico a 16 MHz (CSTCE16M0V53-R0), una connessione USB, un jack di alimentazione, un header ICSP e un pulsante di reset. Contiene tutto il necessario per supportare il microcontrollore; è sufficiente collegarlo a un computer con un cavo USB o alimentarlo con un adattatore AC-DC o una batteria per iniziare.

**Parametri tecnici**

.. image:: img/uno.jpg
    :align: center

* MICROCONTROLLORE: ATmega328P
* TENSIONE OPERATIVA: 5V
* TENSIONE IN INGRESSO (CONSIGLIATA): 7-12V
* TENSIONE IN INGRESSO (LIMITE): 6-20V
* PIN I/O DIGITALI: 14 (0-13, di cui 6 forniscono uscita PWM(3, 5, 6, 9-11))
* PIN I/O DIGITALI PWM: 6 (3, 5, 6, 9-11)
* PIN INGRESSO ANALOGICO: 6 (A0-A5)
* CORRENTE CC PER PIN I/O: 20 mA
* CORRENTE CC PER PIN 3,3V: 50 mA
* MEMORIA FLASH: 32 KB (ATmega328P) di cui 0,5 KB utilizzati dal bootloader
* SRAM: 2 KB (ATmega328P)
* EEPROM: 1 KB (ATmega328P)
* VELOCITÀ CLOCK: 16 MHz
* LED_BUILTIN: 13
* LUNGHEZZA: 68,6 mm
* LARGHEZZA: 53,4 mm
* PESO: 25 g
* Porta I2C: A4(SDA), A5(SCL)


**Ulteriori informazioni**

* `Arduino IDE <https://www.arduino.cc/en/software>`_
* `Riferimento linguaggio di programmazione Arduino <https://www.arduino.cc/reference/en/>`_
* `Scheda tecnica ATmega328P <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_
