.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _cpn_uno:

Carte SunFounder R3
===========================

.. image:: img/uno_r3.jpg
    :width: 600
    :align: center

.. note::

    La carte SunFounder R3 est une carte mère avec presque les mêmes fonctions que l'`Arduino Uno <https://store.arduino.cc/products/arduino-uno-rev3/>`_, et les deux cartes peuvent être utilisées de manière interchangeable.

La carte SunFounder R3 est une carte microcontrôleur basée sur l'ATmega328P (`fiche technique <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_). Elle dispose de 14 broches d'entrée/sortie numériques (dont 6 peuvent être utilisées comme sorties PWM), 6 entrées analogiques, un résonateur céramique 16 MHz (CSTCE16M0V53-R0), une connexion USB, une prise d'alimentation, un connecteur ICSP et un bouton de réinitialisation. Elle contient tout le nécessaire pour prendre en charge le microcontrôleur ; connectez-la simplement à un ordinateur avec un câble USB ou alimentez-la avec un adaptateur AC-DC ou une batterie pour commencer.

**Paramètres techniques**

.. image:: img/uno.jpg
    :align: center

* MICROCONTRÔLEUR : ATmega328P
* TENSION DE FONCTIONNEMENT : 5V
* TENSION D'ENTRÉE (RECOMMANDÉE) : 7-12V
* TENSION D'ENTRÉE (LIMITE) : 6-20V
* BROCHES E/S NUMÉRIQUES : 14 (0-13, dont 6 fournissent une sortie PWM (3, 5, 6, 9-11))
* BROCHES E/S PWM NUMÉRIQUES : 6 (3, 5, 6, 9-11)
* BROCHES D'ENTRÉE ANALOGIQUE : 6 (A0-A5)
* COURANT CC PAR BROCHE E/S : 20 mA
* COURANT CC POUR BROCHE 3,3V : 50 mA
* MÉMOIRE FLASH : 32 Ko (ATmega328P) dont 0,5 Ko utilisés par le bootloader
* SRAM : 2 Ko (ATmega328P)
* EEPROM : 1 Ko (ATmega328P)
* VITESSE D'HORLOGE : 16 MHz
* LED_BUILTIN : 13
* LONGUEUR : 68,6 mm
* LARGEUR : 53,4 mm
* POIDS : 25 g
* Port I2C : A4(SDA), A5(SCL)


**En savoir plus**

* `Arduino IDE <https://www.arduino.cc/en/software>`_
* `Référence du langage de programmation Arduino <https://www.arduino.cc/reference/en/>`_
* `Fiche technique ATmega328P <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_
