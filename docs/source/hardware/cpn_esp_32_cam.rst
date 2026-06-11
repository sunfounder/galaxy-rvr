.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

ESP32 CAM
=================

.. image:: img/esp32_cam.png
    :width: 500
    :align: center

L'ESP32-CAM est un module caméra très compact équipé de la puce ESP32-S qui coûte environ 10 $. Outre la caméra OV2640 et plusieurs GPIO pour connecter des périphériques, il dispose également d'un emplacement pour carte microSD, utile pour stocker des images prises avec la caméra ou des fichiers à servir aux clients.

Le module peut fonctionner de manière autonome en tant que plus petit système, avec une taille de seulement 27*40,5*4,5 mm, et un courant de sommeil profond aussi bas que 6 mA.

L'ESP32-CAM peut être largement utilisé dans diverses applications IoT, adapté aux appareils domestiques intelligents, au contrôle sans fil industriel, à la surveillance sans fil, à l'identification sans fil par QR, aux signaux de systèmes de positionnement sans fil et à d'autres applications IoT. C'est une solution idéale pour les applications IoT.



**Spécifications techniques**

.. list-table::
    :widths: 25 50

    * - Modèle du module
      - ESP32-CAM
    * - Boîtier
      - DIP-16
    * - Dimensions
      - 27*40,5*4,5（±0,2）mm
    * - SPI Flash
      - 32Mbit par défaut
    * - RAM
      - 520Ko interne + 8Mo PSRAM externe
    * - Bluetooth
      - Normes Bluetooth 4.2 BR/EDR et BLE
    * - Wi-Fi
      - 802.11 b/g/n/e/i
    * - Interfaces prises en charge
      - UART, SPI, I2C, PWM
    * - Carte TF prise en charge
      - jusqu'à 4G
    * - Broches IO
      - 9
    * - Vitesse du port série
      - 115200 bps par défaut
    * - Format de sortie d'image
      - JPEG (prise en charge OV2640 uniquement), BMP, GRAYSCALE
    * - Plage de spectre
      - 2400 ~2483,5MHz
    * - Type d'antenne
      - Antenne PCB intégrée, gain 2dBi
    * - Puissance de transmission
      - 802.11b : 17±2 dBm (@11Mbps)
    * -
      - 802.11g : 14±2 dBm (@54Mbps)
    * -
      - 802.11n : 13±2 dBm (@MCS7)
    * - Sensibilité de réception
      - CCK, 1 Mbps : -90dBm
    * -
      - CCK, 11 Mbps : -85 dBm
    * -
      - 6 Mbps (1/2 BPSK) : -88 dBm
    * -
      - 54 Mbps (3/4 64-QAM) : -70dBm
    * -
      - MCS7 (65 Mbps, 72,2 Mbps) : -67dBm
    * - Consommation électrique
      - Flash désactivé : 180mA@5V
    * -
      - Flash activé et luminosité maximale : 310mA@5V
    * -
      - Sommeil profond : la consommation la plus basse peut atteindre 6mA@5V
    * -
      - Sommeil modem : minimum 20mA@5V
    * -
      - Sommeil léger : minimum 6,7mA@5V
    * - Sécurité
      - WPA/WPA2/WPA2-Enterprise/WPS
    * - Plage d'alimentation
      - 4,75-5,25V
    * - Température de fonctionnement
      - -20 ℃ ~ 70 ℃
    * - Environnement de stockage
      - -40 ℃ ~ 125 ℃ , < 90%HR


**Brochage ESP32-CAM**


La figure suivante montre le brochage de l'ESP32-CAM (module AI-Thinker).

.. image:: img/esp32_cam_pinout.png
    :width: 800

* Il y a trois broches **GND** et trois broches pour l'alimentation : 3,3V, 5V et soit 3,3V soit 5V.
* **GPIO 1** et **GPIO 3** sont les broches série. Vous avez besoin de ces broches pour téléverser du code sur votre carte.
* De plus, **GPIO 0** joue également un rôle important, car il détermine si l'ESP32 est en mode flash ou non. Lorsque **GPIO 0** est connecté à **GND**, l'ESP32 est en mode flash.

* Les broches suivantes sont connectées en interne au lecteur de carte microSD :

* GPIO 14 : CLK
* GPIO 15 : CMD
* GPIO 2 : Data 0
* GPIO 4 : Data 1 (également connecté à la LED intégrée)
* GPIO 12 : Data 2
* GPIO 13 : Data 3

**Remarque**

* Veuillez vous assurer que la puissance d'entrée du module est d'au moins 5V 2A, sinon l'image peut présenter des lignes d'eau.
* La broche GPIO32 de l'ESP32 contrôle l'alimentation de la caméra. Lorsque la caméra fonctionne, veuillez tirer GPIO32 vers le bas.
* Étant donné que GPIO0 est connecté au XCLK de la caméra, veuillez laisser GPIO0 en l'air lors de son utilisation et ne pas le connecter à un niveau haut ou bas.
* Le firmware par défaut est déjà inclus en usine et aucun téléchargement supplémentaire n'est fourni. Veuillez faire attention si vous devez re-flasher un autre firmware.


**Document**

* Schéma : |link_esp32cam_schematic|
* Spécification de la caméra (version anglaise) : |link_cam_ov2640|

.. note::
    Toutes les informations ci-dessus proviennent de |link_aithiner|