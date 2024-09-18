.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et à des aperçus privilégiés.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et concours** : Participez à des concours et des promotions durant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Module Ultrasonique
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG** : Entrée d'impulsion de déclenchement
* **ECHO** : Sortie d'impulsion d'écho
* **GND** : Masse
* **VCC** : Alimentation 5V

Voici le capteur de distance à ultrasons HC-SR04, qui fournit une mesure sans contact de 2 cm à 400 cm avec une précision allant jusqu'à 3 mm. Le module comprend un émetteur à ultrasons, un récepteur et un circuit de contrôle.

Vous n'avez besoin de connecter que 4 broches : VCC (alimentation), Trig (déclenchement), Echo (réception) et GND (masse), ce qui le rend facile à utiliser pour vos projets de mesure.

**Caractéristiques**

* Tension de fonctionnement : DC 5V
* Courant de fonctionnement : 16mA
* Fréquence de fonctionnement : 40Hz
* Portée maximale : 500 cm
* Portée minimale : 2 cm
* Signal d'entrée de déclenchement : impulsion TTL de 10µS
* Signal de sortie d'écho : signal de niveau TTL en proportion de la distance
* Connecteur : XH2.54-4P
* Dimensions : 46 x 20,5 x 15 mm

**Principe**

Les principes de base sont les suivants :

* Utiliser un déclenchement IO pour générer un signal de niveau haut d'au moins 10µs.
* Le module émet une rafale de 8 cycles d'ultrasons à 40 kHz et détecte si un signal de retour est reçu.
* Echo émettra un niveau haut si un signal est renvoyé ; la durée du niveau haut correspond au temps écoulé entre l'émission et le retour.
* Distance = (temps de niveau haut x vitesse du son (340M/S)) / 2

    .. image:: img/ultrasonic_prin.jpg
        :width: 800

**Notes d'application**

* Ce module ne doit pas être branché sous tension, si nécessaire, veillez à ce que la masse (GND) soit connectée en premier. Sinon, cela pourrait affecter son fonctionnement.
* La surface de l'objet à mesurer doit être d'au moins 0,5 mètre carré et aussi plane que possible. Sinon, les résultats seront affectés.
