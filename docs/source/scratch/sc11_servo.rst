.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions lors des fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Leçon 11 Mécanisme de Servo et d'Inclinaison
===============================================================

Bienvenue de nouveau, jeunes explorateurs ! Dans l'aventure d'aujourd'hui, nous allons plonger dans le fascinant système visuel du Rover martien. Tout comme nos yeux et notre cou travaillent ensemble pour nous aider à voir et à naviguer dans notre environnement, notre Rover a également besoin d'un système similaire pour traverser le dangereux paysage martien. Et c'est exactement ce que nous allons construire aujourd'hui !

Le système visuel de notre Rover se compose de deux parties principales : une caméra qui agit comme ses "yeux" et un mécanisme d'inclinaison qui fonctionne comme un "cou", lui permettant de regarder vers le haut et vers le bas. À la fin de cette leçon, notre Rover aura la capacité de "voir" et de "hocher la tête" !

Tout d'abord, nous allons construire le mécanisme d'inclinaison - un dispositif qui tiendra la caméra de notre Rover et lui permettra de tourner verticalement. C'est comme donner à notre Rover un cou, pour qu'il puisse faire bouger sa "tête" ou sa caméra de haut en bas !

Ensuite, nous apprendrons à connaître le servo, le petit mais puissant "muscle" qui actionne notre mécanisme d'inclinaison. Nous comprendrons son fonctionnement et comment le contrôler en utilisant la programmation Arduino.

Tout comme nos muscles du cou déplacent notre tête pour que nos yeux aient une meilleure vue, le servo déplacera le mécanisme d'inclinaison afin que la caméra du Rover puisse mieux explorer le paysage martien.

Alors, préparez-vous, explorateurs, commençons notre mission pour équiper notre Rover de son propre système visuel !

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/servo_range.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>



Objectifs d'apprentissage
------------------------------

* Introduire les principes de fonctionnement des moteurs servo et leur application dans le contrôle mécanique.
* Apprendre à régler facilement les angles des servos en utilisant Mammoth Coding, pour un contrôle précis.
* Concevoir des projets interactifs sur la plateforme Mammoth Coding permettant une interaction physique à l'aide des moteurs servo.


Matériel nécessaire
-----------------------

* Smartphone ou tablette
* Application Mammoth Coding
* GalaxyRVR

Qu'est-ce qu'un Servo ?
----------------------------------------

Avez-vous déjà assisté à un spectacle de marionnettes ? Si oui, vous avez peut-être été émerveillé de voir comment le marionnettiste peut faire bouger les bras, les jambes et la tête de la marionnette avec une telle fluidité, simplement en tirant sur quelques ficelles. D'une certaine manière, les moteurs servo sont comme nos marionnettistes.

.. image:: ../img/puppet_show.png
    :width: 200
    :align: center

Les moteurs servo sont des types spéciaux de moteurs qui ne tournent pas simplement comme une roue. Au lieu de cela, ils peuvent se déplacer vers une position spécifique et maintenir cette position. Imaginez que vous jouez à "Simon dit", et Simon dit : "Lève ton bras à un angle de 90 degrés !" Vous pouvez le faire, n'est-ce pas ? C'est parce qu'à l'instar d'un servo, vous pouvez contrôler exactement combien vous devez déplacer votre bras.

.. image:: ../img/servo.png
    :align: center

* Ligne brune : GND
* Ligne orange : Broche de signal, connectée à la broche PWM de la carte principale.
* Fil rouge : VCC

Tout comme vous pouvez contrôler vos bras pour atteindre des positions spécifiques, nous pouvons utiliser des moteurs servo pour contrôler la position exacte des objets dans nos projets. Dans notre Rover martien, nous utiliserons un servo pour contrôler le mouvement de haut en bas de notre mécanisme d'inclinaison, tout comme vous pouvez hocher la tête de haut en bas.

À l'étape suivante, nous allons entreprendre un voyage fascinant à l'intérieur d'un moteur servo pour comprendre son fonctionnement. Prêt pour un peu de magie ? Allons-y !

Comment fonctionne un Servo ?
-------------------------------------------

Alors, comment un servo opère-t-il sa magie ? Partons en voyage captivant à l'intérieur d'un servo !

Si nous regardions à l'intérieur d'un servo, nous verrions plusieurs pièces. Au cœur d'un servo se trouve un moteur régulier, très similaire aux moteurs qui font tourner les roues de notre Rover martien. Enroulé autour du moteur, il y a un grand pignon qui est connecté à un petit pignon sur l'arbre du moteur. C'est ainsi que le mouvement circulaire rapide du moteur est transformé en un mouvement plus lent mais plus puissant.

.. image:: ../img/servo_internal.png
    :align: center

Mais ce n'est pas ce qui rend un servo spécial. La magie se passe dans un petit composant électronique appelé "potentiomètre" et dans le "circuit de contrôle". Voici comment cela fonctionne : lorsque le servo se déplace, le potentiomètre tourne et change sa résistance. Le circuit de contrôle mesure ce changement de résistance et sait exactement dans quelle position se trouve le servo. C'est astucieux, non ?

Pour contrôler un servo, nous lui envoyons un type spécial de signal appelé "modulation de largeur d'impulsion" ou PWM. En modifiant la largeur de ces impulsions, nous pouvons contrôler exactement combien le servo se déplace et maintenir cette position.

À l'étape suivante, nous apprendrons à contrôler un servo en utilisant une application. Prêt pour quelques sorts sous forme de code ? Allons-y !



Exploration du Système d'Inclinaison du Rover Martien
---------------------------------------------------------


**Réglage de l'Angle du Cardan**

1. Vérifiez l'angle du servo, et vous pouvez voir l'angle actuel sur la scène.

.. image:: img/10_servo_angle.png

2. Faites glisser un bloc ``réglage de l'angle du servo à 90 degrés``. Cliquez dessus, et vous verrez le GalaxyRVR faire face vers l'avant.

.. image:: img/10_servo_set_angle.png

3. Changez la valeur à 45 et cliquez dessus, vous verrez le GalaxyRVR regarder vers le haut.

.. image:: img/10_servo_set_angle_45.png

4. Après plusieurs essais, vous découvrirez que le cardan du GalaxyRVR peut se déplacer entre 0 et 135 degrés. À mesure que l'angle augmente, le cardan s'abaisse.


**Changement de l'Angle du Cardan**

1. Le système de cardan du servo du GalaxyRVR est une structure à un seul degré de liberté, donc vous n'avez besoin de contrôler que ses fonctions "réinitialiser", "monter" et "descendre".

.. raw:: html

   <br></br>

2. Créons maintenant son bouton de réinitialisation. Faites glisser un bloc ``quand ce sprite est cliqué``.

.. image:: img/10_servo_when_click.png

3. Intégrez un bloc ``réglage de l'angle du servo à 90 degrés`` pour faire face le cardan vers l'avant.

.. image:: img/10_servo_when_90.png

4. Faites glisser un bloc ``quand la touche fléchée vers le haut est pressée``.

.. image:: img/10_servo_when_up.png

5. Diminuez l'angle du servo lorsque la touche fléchée vers le haut est pressée.

.. image:: img/10_servo_when_up2.png

6. De même, ajoutez un événement pour la touche fléchée vers le bas pour faire regarder le cardan vers le bas.

.. image:: img/10_servo_when_down.png

Maintenant, cliquez sur le bouton plein écran pour agrandir la scène. Cliquez sur haut et bas pour ajuster l'angle du cardan, et cliquez sur le sprite pour réinitialiser l'angle.

.. _tilt_system:

Touchez la Zone de la Scène pour Ajuster l'Angle du Cardan
-------------------------------------------------------------

Ensuite, nous utiliserons un sprite en forme de flèche pour obtenir des ajustements plus fluides de l'angle du servo.

Lorsque nous touchons la flèche, nous pouvons faire glisser la direction du sprite de flèche.

1. Supprimez le sprite d'origine.

.. image:: img/6_animate_delete.png

2. Ajoutez un sprite en forme de flèche. Nous allons définir la direction du cardan en fonction de son orientation.

.. image:: img/10_servo_arrow.png

3. Un bloc ``quand ce sprite est cliqué`` est exactement ce dont nous avons besoin.

.. image:: img/6_animate_when_touch.png
    :width: 230

4. Laissez le programme se répéter jusqu'à ce que nous le relâchions, c'est-à-dire que nous ne touchons plus le sprite.

.. image:: img/6_animate_repeat_touching.png
    :width: 550

5. Faites glisser un bloc ``pointer vers touch_position`` pour que le sprite fasse face à la position touchée.

.. image:: img/10_servo_arrow_point_toward.png

6. Faites glisser un bloc ``réglage de l'angle du servo à 90 degrés`` et intégrez un bloc ``direction`` pour aligner l'angle du cardan avec l'orientation du sprite en flèche. De cette manière, lorsque nous modifions la direction du sprite en flèche (c'est-à-dire que nous touchons la zone de la scène), nous pouvons changer l'angle du cardan.

.. image:: img/10_servo_arrow_angle_direction.png

7. Ajoutez une vérification de limite pour garantir que l'orientation du sprite en flèche ne dépasse pas 135 degrés.

.. image:: img/10_servo_arrow_135.png

8. De même, assurez-vous que son orientation ne tombe pas en dessous de 0 degrés.

.. image:: img/10_servo_arrow_0.png

Touchez le sprite, et il changera de direction au fur et à mesure que vous faites glisser, modifiant l'angle du cardan.

Si vous trouvez qu'il est facile de faire glisser votre doigt hors du sprite en flèche, vous pouvez augmenter la taille du sprite en conséquence.

Blocs liés au Servo
-------------------------------

.. image:: img/block/servo_set_angle.png

Ce bloc est utilisé pour régler l'angle du servo. La plage est de 0 à 180 degrés (mais en raison des limitations structurelles, la plage réellement utilisable est de 0 à 135 degrés).

.. image:: img/block/servo_increase_angle.png

Ce bloc augmente (ou diminue) l'angle du servo. La valeur peut être négative.

.. image:: img/block/servo_value.png

L'angle actuel du servo.
