.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et à des aperçus privilégiés.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et concours** : Participez à des concours et des promotions durant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

ESP32 CAM
=================

.. image:: img/esp32_cam.png
    :width: 500
    :align: center

L'ESP32-CAM est un module caméra très compact équipé de la puce ESP32-S, vendu aux alentours de 10$. Outre la caméra OV2640 et plusieurs GPIO pour connecter des périphériques, il dispose également d'un emplacement pour carte microSD, utile pour stocker des images prises avec la caméra ou des fichiers à servir aux clients.

Le module peut fonctionner de manière autonome comme le plus petit système, avec une taille de seulement 27*40.5*4.5mm, et un courant de veille profonde aussi bas que 6mA.

L'ESP32-CAM peut être largement utilisé dans diverses applications IoT, adapté aux appareils domestiques intelligents, au contrôle sans fil industriel, à la surveillance sans fil, à l'identification sans fil par QR code, au positionnement sans fil et à d'autres applications IoT. C'est une solution idéale pour les applications IoT.


**Caractéristiques techniques**

.. list-table::
    :widths: 25 50

    * - Modèle du module
      - ESP32-CAM
    * - Boîtier
      - DIP-16
    * - Dimensions
      - 27*40.5*4.5（±0.2）mm
    * - SPI Flash
      - 32Mbit par défaut
    * - RAM
      - 520KB interne + 8MB PSRAM externe
    * - Bluetooth
      - Normes Bluetooth 4.2 BR/EDR et BLE
    * - Wi-Fi
      - 802.11 b/g/n/e/i
    * - Interfaces prises en charge
      - UART, SPI, I2C, PWM
    * - Prise en charge des cartes TF
      - jusqu'à 4G
    * - Broches d'IO
      - 9
    * - Vitesse du port série
      - 115200 bps par défaut
    * - Format de sortie d'image
      - JPEG (uniquement pris en charge par l'OV2640), BMP, GRAYSCALE
    * - Plage de spectre
      - 2400 ~ 2483.5MHz
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
      - MCS7 (65 Mbps, 72.2 Mbps) : -67dBm
    * - Consommation d'énergie
      - Flash désactivé : 180mA @5V
    * - 
      - Flash activé et luminosité maximale : 310mA @5V
    * - 
      - Veille profonde : la consommation la plus faible peut atteindre 6mA @5V
    * - 
      - Veille modem : minimum 20mA @5V
    * - 
      - Veille légère : minimum 6.7mA @5V
    * - Sécurité
      - WPA/WPA2/WPA2-Enterprise/WPS
    * - Plage d'alimentation
      - 4.75-5.25V
    * - Température de fonctionnement
      - -20 ℃ ~ 70 ℃
    * - Environnement de stockage
      - -40 ℃ ~ 125 ℃ , < 90%RH


**ESP32-CAM Brochage**

L'image suivante montre le brochage de l'ESP32-CAM (module AI-Thinker).

.. image:: img/esp32_cam_pinout.png
    :width: 800

* Il y a trois broches **GND** et trois broches d'alimentation : 3.3V, 5V et soit 3.3V, soit 5V.
* **GPIO 1** et **GPIO 3** sont les broches série. Vous avez besoin de ces broches pour téléverser du code sur votre carte. 
* De plus, **GPIO 0** joue également un rôle important, car il détermine si l'ESP32 est en mode flash ou non. Lorsque **GPIO 0** est connecté à **GND**, l'ESP32 est en mode flash.

Les broches suivantes sont connectées en interne au lecteur de carte microSD :

* GPIO 14 : CLK
* GPIO 15 : CMD
* GPIO 2 : Data 0
* GPIO 4 : Data 1 (également connecté à la LED intégrée)
* GPIO 12 : Data 2
* GPIO 13 : Data 3

**Remarque**

* Veuillez vous assurer que l'alimentation en entrée du module est d'au moins 5V 2A, sinon l'image pourrait présenter des lignes d'eau.
* La broche GPIO32 de l'ESP32 contrôle l'alimentation de la caméra. Lorsque la caméra est en fonctionnement, veuillez tirer GPIO32 vers le bas.
* Étant donné que GPIO0 est connecté à l'horloge XCLK de la caméra, veuillez laisser GPIO0 en l'air lors de son utilisation, et ne pas le connecter à un niveau haut ou bas.
* Le firmware par défaut est déjà inclus en usine, et aucun téléchargement supplémentaire n'est fourni. Veuillez faire attention si vous avez besoin de reprogrammer un autre firmware.


**Document**

* Schéma : |link_esp32cam_schematic|
* Spécifications de la caméra (version anglaise) : |link_cam_ov2640|

.. note::
    Toutes les informations ci-dessus proviennent de |link_aithiner|
