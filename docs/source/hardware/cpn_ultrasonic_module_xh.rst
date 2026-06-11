.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Module à ultrasons
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG** : Entrée d'impulsion de déclenchement
* **ECHO** : Sortie d'impulsion d'écho
* **GND** : Masse
* **VCC** : Alimentation 5V

Il s'agit du capteur de distance à ultrasons HC-SR04, offrant une mesure sans contact de 2 cm à 400 cm avec une précision de portée allant jusqu'à 3 mm. Le module comprend un émetteur à ultrasons, un récepteur et un circuit de commande.

Vous n'avez besoin de connecter que 4 broches : VCC (alimentation), Trig (déclenchement), Echo (réception) et GND (masse) pour une utilisation facile dans vos projets de mesure.

**Caractéristiques**

* Tension de fonctionnement : 5V CC
* Courant de fonctionnement : 16mA
* Fréquence de fonctionnement : 40Hz
* Portée maximale : 500cm
* Portée minimale : 2cm
* Signal d'entrée de déclenchement : impulsion TTL 10µs
* Signal de sortie Echo : signal TTL d'entrée et portée proportionnelle
* Connecteur : XH2.54-4P
* Dimensions : 46x20,5x15 mm

**Principe**

Les principes de base sont les suivants :

* Utilisation d'un déclenchement IO pour un signal de niveau haut d'au moins 10µs.
* Le module envoie une rafale de 8 cycles d'ultrasons à 40 kHz et détecte si un signal d'impulsion est reçu.
* Echo produira un niveau haut si un signal est renvoyé ; la durée du niveau haut est le temps entre l'émission et le retour.
* Distance = (temps de niveau haut x vitesse du son (340M/S)) / 2

    .. image:: img/ultrasonic_prin.jpg
        :width: 800



**Notes d'application**

* Ce module ne doit pas être connecté sous tension ; si nécessaire, connectez d'abord le GND du module. Sinon, cela affectera le fonctionnement du module.
* La surface de l'objet à mesurer doit être d'au moins 0,5 mètre carré et aussi plane que possible. Sinon, cela affectera les résultats.
