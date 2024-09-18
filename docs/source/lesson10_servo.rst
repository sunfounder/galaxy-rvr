.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec des passionnés partageant les mêmes intérêts.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprenez & partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos produits les plus récents.
    - **Promotions festives et concours** : Participez à des concours et des promotions lors des fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !


Leçon 10 : Explorer le système visuel du Rover martien - Servo et mécanisme d'inclinaison
===========================================================================================

Bienvenue, jeunes explorateurs ! Dans l'aventure d'aujourd'hui, nous allons plonger 
dans le fascinant monde du système visuel du Rover martien. 
Tout comme nos yeux et notre cou travaillent ensemble pour nous aider à voir et naviguer, 
notre Rover a besoin d'un système similaire pour affronter le paysage accidenté de Mars. 
Et c'est exactement ce que nous allons construire aujourd'hui !

Le système visuel de notre Rover comporte deux parties principales : une caméra qui agit 
comme ses "yeux", et un mécanisme d'inclinaison qui fonctionne comme son "cou", lui 
permettant de regarder en haut et en bas. À la fin de cette leçon, nous donnerons à notre 
Rover la capacité de "voir" et de "hocher la tête" !

Tout d'abord, nous allons construire le mécanisme d'inclinaison - un dispositif qui 
maintiendra la caméra de notre Rover et lui permettra de pivoter verticalement. 
C'est comme donner à notre Rover un cou, afin qu'il puisse hocher la tête vers le haut 
et le bas !

Ensuite, nous apprendrons à connaître le servo, ce petit mais puissant "muscle" qui 
actionne notre mécanisme d'inclinaison. Nous comprendrons comment il fonctionne et 
comment nous pouvons le contrôler en utilisant la programmation Arduino.

Tout comme nos muscles du cou bougent notre tête pour que nos yeux aient une meilleure 
vue, le servo déplacera le mécanisme d'inclinaison pour que la caméra du Rover puisse 
mieux observer le paysage martien.

Alors, attachez vos ceintures, explorateurs, commençons notre mission pour équiper 
notre Rover de son propre système visuel !

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/servo_range.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>


Objectif
----------------

* S'entraîner à installer et à utiliser le mécanisme d'inclinaison sur le modèle du Rover martien.
* Comprendre les principes de fonctionnement et d'application des servos.
* Apprendre à contrôler le mouvement des servos à travers la programmation Arduino.

Matériel
---------------

* Carte de développement Arduino UNO
* Servo
* Cardan et caméra
* Modèle de Rover martien (déjà équipé de moteur TT, système de suspension, modules de détection d'obstacles à ultrasons et infrarouges, bande LED RGB)
* IDE Arduino
* Ordinateur

Étapes
-----------

**Étape 1 : Qu'est-ce qu'un Servo ?**

Avez-vous déjà assisté à un spectacle de marionnettes ? Si oui, vous avez peut-être admiré la façon dont le marionnettiste fait bouger les bras, les jambes et la tête des marionnettes en douceur, simplement en tirant sur quelques ficelles. D'une certaine manière, les servos moteurs sont comme nos marionnettistes.

.. image:: img/puppet_show.png
    :width: 200
    :align: center

Les servos moteurs sont un type particulier de moteurs qui ne tournent pas simplement en continu comme une roue. Au lieu de cela, ils peuvent se déplacer vers une position spécifique et maintenir cette position. Imaginez que vous jouez à "Jacques a dit", et que Jacques vous dit : "Levez le bras à un angle de 90 degrés !" Vous pouvez le faire, n'est-ce pas ? C'est parce que, tout comme un servo, vous pouvez contrôler exactement combien votre bras bouge.

.. image:: img/servo.png
    :align: center

* Fil marron : GND
* Fil orange : Broche du signal, connectée à la broche PWM de la carte principale.
* Fil rouge : VCC

Tout comme vous pouvez contrôler vos bras pour qu'ils se déplacent à des positions spécifiques, nous pouvons utiliser des servos moteurs pour contrôler la position exacte des objets dans nos projets. Dans notre Rover martien, nous utiliserons un servo pour contrôler le mouvement de haut en bas de notre mécanisme d'inclinaison, tout comme vous pouvez hocher la tête de haut en bas.

Dans l'étape suivante, nous embarquerons pour un voyage fascinant à l'intérieur d'un servo pour comprendre comment il fonctionne. Excités ? Allons-y !

**Étape 2 : Comment fonctionne un Servo ?**

Alors, comment un servo fait-il sa magie ? Partons pour un voyage palpitant à l'intérieur d'un servo !

Si nous jetions un coup d'œil à l'intérieur d'un servo, nous verrions quelques pièces. Au cœur d'un servo se trouve un moteur ordinaire, très similaire aux moteurs qui font tourner les roues de notre Rover martien. Autour du moteur se trouve un grand engrenage connecté à un plus petit engrenage sur l'axe du moteur. C'est ainsi que le mouvement rapide et circulaire du moteur est transformé en un mouvement plus lent mais plus puissant.

.. image:: img/servo_internal.png
    :align: center

Mais ce n'est pas ce qui rend un servo spécial. La magie réside dans un petit composant électronique appelé "potentiomètre" et dans le "circuit de contrôle". Voici comment cela fonctionne : lorsque le servo se déplace, le potentiomètre tourne et modifie sa résistance. Le circuit de contrôle mesure ce changement de résistance et sait exactement dans quelle position se trouve le servo. Astucieux, n'est-ce pas ?

Pour contrôler un servo, nous lui envoyons un signal spécial appelé "signal de modulation de largeur d'impulsion" ou PWM. En modifiant la largeur de ces impulsions, nous pouvons contrôler exactement la quantité de mouvement du servo et le maintenir dans cette position.

Dans l'étape suivante, nous allons apprendre à contrôler un servo en utilisant un Arduino. Prêts pour quelques formules magiques sous forme de code ? Allons-y !

**Étape 3 : Contrôler un Servo avec Arduino**

Bien, explorateurs, maintenant que nous savons comment fonctionne un servo, apprenons à le contrôler à l'aide de notre baguette magique, l'Arduino !

Contrôler un servo revient à lui donner des instructions. Vous vous souvenez des signaux PWM dont nous avons parlé plus tôt ? Nous allons les utiliser pour indiquer au servo où se déplacer.

Heureusement, Arduino nous simplifie la tâche grâce à une bibliothèque intégrée appelée ``Servo``. Avec cette bibliothèque, nous pouvons créer un objet ``Servo``, attacher une broche (celle à laquelle notre servo est connecté), puis utiliser une commande simple, ``write()``, pour définir l'angle.

Voici un extrait du code :

.. code-block:: arduino

    #include <Servo.h> 

    Servo myServo;  // créer un objet servo

    void setup() {
        myServo.attach(6);  // attacher le servo à la broche 6
    }

    void loop() {
        myServo.write(90);  // dire au servo de se positionner à 90 degrés
    }

Dans ce code, ``myServo`` est notre objet Servo, ``attach(6)`` indique à l'Arduino que notre servo est connecté à la broche 6, et ``write(90)`` indique au servo de se déplacer à 90 degrés.

Bravo, explorateurs ! Vous venez d'apprendre à contrôler un servo avec Arduino. Vous pouvez également expérimenter avec différents angles !

**Étape 4 : Assembler le système visuel**

Vous êtes maintenant prêts à assembler le système visuel de notre Rover.

.. note::

    * Lors de l'insertion de l'ESP32 CAM dans l'adaptateur de caméra, faites attention à son orientation. Il doit être correctement aligné avec l'adaptateur ESP32.

    .. image:: img/esp32_cam_direction.png
        :width: 300
        :align: center
    
.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/h43JVI3xLqE?si=Q7-RvRvZOusK7vPo" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Étape 5 : Comprendre les limites du mécanisme d'inclinaison**

Bien que le servo soit conçu pour tourner entre 0 et 180 degrés, vous remarquerez peut-être qu'il cesse de répondre au-delà d'un certain point (disons après 150 degrés). Vous êtes-vous déjà demandé pourquoi cela se produit ? Explorons ce mystère ensemble lors de notre prochaine aventure !

Pouvez-vous imaginer un oiseau essayant de plier son cou jusqu'à ce qu'il touche son propre corps et ne puisse plus bouger ? Le mécanisme d'inclinaison de notre Rover fait face à une situation similaire. Lorsque le servo déplace le mécanisme vers le bas, il peut heurter le corps du Rover et ne pas pouvoir aller au-delà d'un certain angle.

Si nous essayons de le forcer à se déplacer au-delà de ce point en écrivant un angle inaccessible dans notre code, notre petit servo risque de se bloquer et même de se casser ! Nous ne voulons pas que cela arrive, n'est-ce pas ? Alors, comprenons ses limites de mouvement grâce à une petite expérience.

Nous utilisons une boucle ``for`` pour faire pivoter le servo de 0 à 180 degrés tout en notant l'angle dans le **Moniteur Série**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/848c7a3a-16b2-4a7e-8d66-bb91848bc6d9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

* L'ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Donc, avant de télécharger le code, vous devez d'abord libérer l'ESP32-CAM en faisant glisser cet interrupteur sur le côté droit pour éviter tout conflit ou problème potentiel.

    .. image:: img/camera_upload.png
        :width: 600

* Après avoir téléchargé le code, ouvrez le **Moniteur Série**. Si aucune information n'apparaît, appuyez sur le **bouton de réinitialisation** du bouclier GalaxyRVR pour relancer le code.

* Vous verrez le servo tourner, et le Moniteur Série affichera l'angle.

.. image:: img/servo_range.png

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/servo_range.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>
    
Sur mon Rover, le mécanisme d'inclinaison pouvait atteindre environ 140° avant de heurter le corps du Rover et de ne plus pouvoir aller plus loin.

Donc, explorateurs, souvenez-vous toujours de respecter les limites de votre Rover pour le maintenir en sécurité et en bon état de fonctionnement !


**Étape 6 : Partage et réflexion**


Bravo, explorateurs ! Aujourd'hui, vous avez non seulement construit un mécanisme d'inclinaison pour votre Rover, mais vous avez également compris comment contrôler un servo pour le faire bouger. C'est un grand pas en avant dans notre mission Rover martien.

Maintenant, partageons nos expériences et réfléchissons à ce que nous avons appris.

Avez-vous rencontré des défis lors de la mise en place du mécanisme d'inclinaison ou de la programmation du servo ? Comment les avez-vous surmontés ?

Souvenez-vous, chaque défi surmonté nous rend plus intelligents et rend notre Rover encore meilleur. Alors, n'hésitez pas à partager vos histoires, idées et solutions. Vous pourriez bien aider un autre explorateur dans son parcours !

