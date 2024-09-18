.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et à des aperçus privilégiés.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et concours** : Participez à des concours et à des promotions pendant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !


Leçon 4 : Module Ultrasonique
==================================

Lors de notre dernière aventure, nous avons équipé notre Rover martien de "yeux" sur ses côtés pour créer un système de détection d'obstacles basique. Cependant, il reste un angle mort à l'avant – un défi que nous sommes prêts à relever !

Aujourd'hui, dans cette leçon, nous allons offrir à notre Rover un nouveau sens de la "vision". Nous installerons un module à capteur ultrasonique, qui jouera le rôle de "yeux" centraux et aidera notre Rover à détecter les obstacles directement devant lui.

Nous allons explorer les fascinants mécanismes des ondes ultrasoniques et découvrir comment elles améliorent la capacité de notre Rover à naviguer sur des terrains complexes. Avec cette addition, notre Rover martien sera encore plus perceptif et agile, prêt à entreprendre des missions d'exploration plus ambitieuses.

Rejoignez-nous dans cette nouvelle étape passionnante de notre parcours STEAM, et rendons notre Rover encore plus performant pour explorer des territoires inconnus !

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/ultrasonic_avoid.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>


Objectifs d'apprentissage
----------------------------

* Comprendre le principe de la mesure de distance par ultrasons.
* Apprendre à utiliser l'APP Mammoth Coding et le module ultrasonique pour mesurer des distances.
* Pratiquer l'utilisation du module ultrasonique pour éviter les obstacles avec le GalaxyRVR.

Matériel
-------------

* Smartphone ou tablette
* APP Mammoth Coding
* GalaxyRVR

Exploration du Module Ultrasonique
--------------------------------------------

Faisons connaissance avec le HC-SR04, un capteur de distance ultrasonique puissant. Ce petit appareil peut mesurer avec précision des distances de 2 cm à 400 cm, sans avoir besoin de toucher quoi que ce soit ! Impressionnant, non ? C'est comme avoir un super-pouvoir ! Il peut "voir" des distances en utilisant des ondes sonores, un peu comme une chauve-souris qui navigue dans l'obscurité.

Il utilise quatre "super-pouvoirs", ou plutôt, quatre broches pour réaliser sa magie :

.. image:: ../img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG (Trigger Pulse Input)** - C'est le bouton de départ de notre super-héros. Il lui dit : "Hé, c'est le moment d'envoyer une onde ultrasonique !"
* **ECHO (Echo Pulse Output)** - C'est ainsi que notre super-héros écoute l'écho de l'onde sonore qu'il a envoyée.
* **VCC** - Même les super-héros ont besoin d'énergie. Nous le connectons à une alimentation de 5V.
* **GND** - C'est la connexion à la masse, tout comme les super-héros doivent rester connectés à la réalité !

Imaginez notre super-héros, le capteur ultrasonique HC-SR04, jouant à un jeu d'écho dans les montagnes.

.. image:: ../img/ultrasonic_prin.jpg
    :width: 800

* Tout d'abord, le cerveau de notre super-héros, le MCU, dit "Prêt, feu, partez !" en envoyant un signal de niveau haut pendant au moins 10 microsecondes. C'est comme lorsque nous rassemblons notre énergie avant de crier dans une vallée.
* À l'écoute de "Partez !", notre super-héros émet 8 ondes ultrasoniques à une vitesse de 40 kHz. Le super-héros commence également un chronomètre et reste attentif au retour de l'écho.
* S'il y a un obstacle devant, l'onde frappera l'obstacle et renverra un écho. Dès que l'écho est détecté, le super-héros arrête le chronomètre et enregistre le temps. Il envoie également un signal de niveau haut pour informer le MCU qu'il a entendu l'écho.
* Enfin, pour déterminer à quelle distance se trouve l'obstacle, le super-héros utilise une formule simple. Il prend le temps enregistré sur le chronomètre, le divise par 2 et le multiplie par la vitesse du son (340 m/s). Le résultat est la distance jusqu'à l'obstacle !

Voilà comment notre capteur super-héros peut détecter la présence d'un obstacle et en déterminer la distance. Incroyable, non ? Ensuite, nous allons apprendre comment utiliser ce super-pouvoir dans notre Rover martien !




Valeurs de détection du module ultrasonique
----------------------------------------------------------

1. Voyons quelles sont les valeurs de détection du module de distance ultrasonique. Tout d'abord, :ref:`app_connect`.

2. Trouvez le bloc "distance en cm" dans la catégorie GalaxyRVR. Cochez sa case.

.. image:: img/6_ultrasonic_value.png

3. Cela affichera la valeur sur la scène.

.. image:: img/6_ultrasonic_value2.png

4. Déplacez votre main devant le module ultrasonique et vous verrez la distance entre votre main et le module s'afficher sur la scène. L'unité est le cm.

Réagir au module de distance ultrasonique
--------------------------------------------------------------------

Nous pouvons utiliser le module de détection d'obstacles infrarouge pour permettre au GalaxyRVR d'éviter automatiquement les obstacles.

1. Faites glisser un petit bloc de drapeau vert.

.. image:: img/6_ultrasonic_flag.png

2. Réglez la vitesse. Ici, nous la réglons à 30 %, pour ne pas aller trop vite et faciliter le débogage.

.. image:: img/6_ultrasonic_speed.png

3. Placez un bloc "avancer" pour qu'il continue à se déplacer lorsqu'il n'y a pas d'obstacles.

.. image:: img/6_ultrasonic_forward.png

4. Trouvez le bloc ``quand distance < 15 cm``.

.. image:: img/6_ultrasonic_when.png

5. Lorsque l'obstacle est détecté, le GalaxyRVR s'arrête et recule.

.. image:: img/6_ultrasonic_backward.png

6. Faites un léger virage (à gauche ou à droite).

.. image:: img/6_ultrasonic_turn.png

7. Après avoir effectué le virage, avancez à nouveau.

.. image:: img/6_ultrasonic_forward_again.png

Placez maintenant le GalaxyRVR sur le sol et il continuera à avancer jusqu'à ce qu'il rencontre un obstacle directement devant lui, moment auquel il changera de direction.

Blocs liés au module ultrasonique
-------------------------------------------------

.. image:: img/block/ultra_when.png

C'est un bloc d'événement déclenché lorsque le capteur ultrasonique détecte un obstacle à moins de 15 cm. Vous pouvez :

    * Changer ``<`` to ``>`` dans le menu déroulant.
    * Modifier le nombre pour ajuster la condition de seuil.

.. image:: img/block/ultra_wait_until.png

Ce bloc met le programme en pause jusqu'à ce que le capteur ultrasonique détecte un obstacle à plus de 15 cm, puis reprend le programme. Vous pouvez :

    * Changer ``<`` to ``>`` dans le menu déroulant.
    * Modifier le nombre pour ajuster la condition de seuil.

.. image:: img/block/ultra_condition.png

C'est un bloc conditionnel qui renvoie TRUE si la distance détectée par le capteur ultrasonique est effectivement inférieure à 15 cm, sinon il renvoie FALSE. Il est couramment utilisé dans des blocs nécessitant des conditions comme ``if``. Vous pouvez :

    * Changer ``<`` to ``>`` dans le menu déroulant.
    * Modifier le nombre pour ajuster la condition de seuil.

.. image:: img/block/ultra_value.png

Ce bloc affiche la distance actuelle mesurée par le capteur ultrasonique.




Blocs liés au servo
-------------------------------

.. image:: img/block/servo_set_angle.png

Ce bloc est utilisé pour définir l'angle du servo. La plage est de 0 à 180 degrés (toutefois, en raison de limitations structurelles, la plage réelle utilisable est de 0 à 135 degrés).

.. image:: img/block/servo_increase_angle.png

Ce bloc augmente (ou diminue) l'angle du servo. La valeur peut être négative.

.. image:: img/block/servo_value.png

L'angle actuel du servo.

