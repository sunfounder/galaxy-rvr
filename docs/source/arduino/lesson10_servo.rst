.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 10 : Explorer le système visuel du Rover Martien – Servo et mécanisme d'inclinaison
==========================================================================================

Bon retour parmi nous, jeunes explorateurs ! Dans l'aventure d'aujourd'hui, nous allons plonger dans le monde fascinant du système visuel du Rover Martien.
Tout comme nos yeux et notre cou travaillent ensemble pour nous aider à voir et à naviguer dans notre environnement, notre Rover a également besoin d'un système similaire pour naviguer sur le dangereux paysage martien. Et c'est exactement ce que nous allons construire aujourd'hui !

Le système visuel de notre Rover se compose de deux parties principales : une caméra qui fait office d'« yeux », et un mécanisme d'inclinaison qui fait office de « cou », lui permettant de regarder vers le haut et vers le bas. À la fin de cette leçon, nous aurons donné à notre Rover la capacité de « voir » et de « hocher la tête » !

D'abord, nous allons construire le mécanisme d'inclinaison – un dispositif qui maintiendra la caméra de notre Rover et lui permettra de pivoter verticalement.
C'est comme donner un cou à notre Rover, afin qu'il puisse hocher sa « tête » – ou sa caméra – de haut en bas !

Ensuite, nous découvrirons le servo, le petit mais puissant « muscle » qui actionne notre mécanisme d'inclinaison.
Nous comprendrons son fonctionnement et comment le contrôler avec la programmation Arduino.

Tout comme les muscles de notre cou bougent notre tête pour que nos yeux puissent obtenir une meilleure vue, le servo déplacera le mécanisme d'inclinaison pour que la caméra du Rover puisse mieux observer le paysage martien.

Alors, attachez vos ceintures, explorateurs, et lançons notre mission d'équiper notre Rover de son propre système visuel !

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/servo_range.mp4" type="video/mp4">
        Votre navigateur ne prend pas en charge la balise vidéo.
    </video>


Objectifs d'apprentissage
-------------------------

* S'exercer à installer et à utiliser le mécanisme d'inclinaison sur le modèle de Rover Martien.
* Comprendre les principes de fonctionnement et l'application du servo.
* Apprendre à contrôler le mouvement du servo par la programmation Arduino.

Matériel nécessaire
-------------------

* Carte de développement Arduino UNO
* Servo
* Cardan et caméra
* Modèle de Rover Martien (déjà équipé du moteur TT, du système de suspension, des modules d'évitement d'obstacles ultrasonique et infrarouge, de la bande LED RGB)
* IDE Arduino
* Ordinateur

Étapes
------

**Étape 1 : Qu'est-ce qu'un servo ?**

Avez-vous déjà assisté à un spectacle de marionnettes ? Si oui, vous avez peut-être été émerveillé par la façon dont le marionnettiste peut faire bouger les bras, les jambes et la tête de la marionnette avec tant de fluidité, simplement en tirant sur des fils. D'une certaine manière, les servomoteurs sont comme nos marionnettistes.

.. image:: img/puppet_show.png
    :width: 200
    :align: center

Les servomoteurs sont un type de moteur spécial qui ne se contente pas de tourner indéfiniment comme une roue. Au contraire, ils peuvent se déplacer vers une position spécifique et la maintenir. Imaginez que vous jouez à Jacques a dit, et que Jacques dit : « Levez le bras à un angle de 90 degrés ! » Vous pouvez le faire, n'est-ce pas ? C'est parce que, comme un servo, vous pouvez contrôler exactement de combien bouger votre bras.

.. image:: img/servo.png
    :align: center

* Fil marron : GND
* Fil orange : Broche de signal, à connecter à la broche PWM de la carte principale.
* Fil rouge : VCC

Tout comme vous pouvez contrôler vos bras pour les déplacer vers des positions spécifiques, nous pouvons utiliser des servomoteurs pour contrôler la position exacte des objets dans nos projets. Dans notre Rover Martien, nous utiliserons un servo pour contrôler le mouvement de haut en bas de notre mécanisme d'inclinaison, comme lorsque vous hochez la tête.

Dans l'étape suivante, nous ferons un voyage fascinant à l'intérieur d'un servomoteur pour comprendre comment il fonctionne. Vous êtes prêts ? Allons-y !

**Étape 2 : Comment fonctionne un servo ?**

Alors, comment un servo opère-t-il sa magie ? Embarquons pour un voyage passionnant à l'intérieur d'un servo !

Si nous regardions à l'intérieur d'un servo, nous verrions plusieurs éléments. Au cœur du servo se trouve un moteur classique, très similaire aux moteurs qui font tourner les roues de notre Rover Martien. Autour du moteur, un grand engrenage est relié à un engrenage plus petit sur l'arbre du moteur. C'est ainsi que le mouvement circulaire rapide du moteur est transformé en un mouvement plus lent mais plus puissant.

.. image:: img/servo_internal.png
    :align: center

Mais ce n'est pas cela qui rend un servo spécial. La magie opère dans un petit composant électronique appelé « potentiomètre » et dans le « circuit de contrôle ». Voici comment cela fonctionne : lorsque le servo bouge, le potentiomètre tourne et modifie sa résistance. Le circuit de contrôle mesure ce changement de résistance et sait exactement dans quelle position se trouve le servo. Ingénieux, n'est-ce pas ?

Pour contrôler un servo, nous lui envoyons un type de signal spécial appelé signal à « modulation de largeur d'impulsion » ou PWM. En modifiant la largeur de ces impulsions, nous pouvons contrôler exactement l'amplitude du mouvement du servo et le maintenir dans cette position.

Dans l'étape suivante, nous apprendrons à contrôler un servo avec un Arduino. Prêts pour quelques formules magiques sous forme de code ? Allons-y !

**Étape 3 : Contrôler un servo avec Arduino**

Très bien, explorateurs, maintenant que nous savons comment fonctionne un servo, apprenons à le contrôler avec notre baguette magique, l'Arduino !

Contrôler un servo, c'est comme lui donner des instructions. Vous vous souvenez des signaux de modulation de largeur d'impulsion (PWM) que nous avons mentionnés plus tôt ? Nous allons les utiliser pour indiquer au servo où se déplacer.

Heureusement, Arduino nous facilite cette tâche avec une bibliothèque intégrée appelée ``Servo``. Avec cette bibliothèque, nous pouvons créer un objet ``Servo``, lui associer une broche (la broche à laquelle notre servo est connecté), puis utiliser une simple commande, ``write()``, pour définir l'angle.

Voici un extrait du code correspondant :

.. code-block:: arduino

    #include <Servo.h>

    Servo myServo;  // créer un objet servo

    void setup() {
        myServo.attach(6);  // associe le servo à la broche 6
    }

    void loop() {
        myServo.write(90);  // ordonne au servo d'aller à 90 degrés
    }

Dans ce code, ``myServo`` est notre objet Servo, ``attach(6)`` indique à l'Arduino que notre servo est connecté à la broche 6, et ``write(90)`` ordonne au servo de se déplacer à 90 degrés.

Excellent travail, explorateurs ! Vous venez d'apprendre à contrôler un servomoteur avec Arduino. Vous pouvez également expérimenter avec différents angles !

**Étape 4 : Assembler le système visuel**

Vous êtes maintenant prêt à assembler le système visuel de notre Rover.

.. note::

    * Lors de l'insertion de l'ESP32-CAM dans l'adaptateur caméra, faites attention à son orientation. Il doit s'aligner correctement avec l'adaptateur ESP32.

    .. image:: img/esp32_cam_direction.png
        :width: 300
        :align: center

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/h43JVI3xLqE?si=Q7-RvRvZOusK7vPo" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Étape 5 : Comprendre les limites du mécanisme d'inclinaison**

Même si le servo est conçu pour tourner entre 0 et 180 degrés, vous remarquerez peut-être qu'il cesse de répondre au-delà d'un certain point (disons après 150 degrés). Vous êtes-vous déjà demandé pourquoi ? Explorons ce mystère ensemble dans notre prochaine aventure !


Pouvez-vous imaginer un oiseau essayant de trop plier le cou au point de heurter son propre corps et de ne plus pouvoir bouger davantage ? Le mécanisme d'inclinaison de notre Rover est confronté à une situation similaire. Lorsque le servo déplace le mécanisme vers le bas, il peut buter contre le corps de notre Rover et ne peut pas dépasser un certain angle.

Si nous essayons de le forcer à aller au-delà de ce point en écrivant un angle inatteignable dans notre code, notre petit oiseau servo peut se bloquer et même s'endommager ! Nous ne voulons pas que cela arrive, n'est-ce pas ? Alors, comprenons ses limites de mouvement avec une petite expérience.

Nous utilisons une boucle for pour faire tourner le servo de 0 à 180 degrés tout en notant l'angle dans le moniteur série.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/848c7a3a-16b2-4a7e-8d66-bb91848bc6d9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

* L'ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Donc, avant de téléverser le code, vous devez d'abord déconnecter l'ESP32-CAM en faisant glisser cet interrupteur vers la droite pour éviter tout conflit ou problème potentiel.

    .. image:: ../img/camera_upload.png
        :width: 600

* Après avoir téléversé ce code, ouvrez le **Moniteur Série**. Si aucune information n'apparaît, appuyez sur le bouton **Reset** du shield GalaxyRVR pour exécuter le code à nouveau.

* Vous verrez le servo tourner et le Moniteur Série affichera l'angle.

.. image:: img/servo_range.png

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/servo_range.mp4" type="video/mp4">
        Votre navigateur ne prend pas en charge la balise vidéo.
    </video>

Sur mon Rover, le mécanisme d'inclinaison pouvait atteindre environ 135° avant de heurter le corps du Rover et de ne plus pouvoir aller plus loin.

Alors, explorateurs, souvenez-vous toujours de respecter les limites de votre rover pour le garder en sécurité et fonctionnel !


**Étape 6 : Partage et réflexion**

Bravo, explorateurs ! Aujourd'hui, vous avez non seulement construit un mécanisme d'inclinaison pour votre Rover, mais vous avez également compris comment contrôler un servo pour le faire bouger. C'est un grand pas en avant dans notre mission Rover Martien.

Maintenant, partageons nos expériences et réfléchissons à ce que nous avons appris.

Avez-vous rencontré des difficultés lors du montage du mécanisme d'inclinaison ou de la programmation du servo ? Comment les avez-vous surmontées ?

Rappelez-vous, chaque défi que nous relevons nous rend plus intelligents et notre Rover meilleur. Alors n'hésitez pas à partager vos histoires, vos idées et vos solutions. Qui sait, votre solution innovante pourrait aider un autre explorateur dans son aventure !
