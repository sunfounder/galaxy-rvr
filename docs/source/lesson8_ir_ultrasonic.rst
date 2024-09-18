.. note::

    Bonjour, et bienvenue dans la communauté des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Leçon 8 : Système avancé d'évitement d'obstacles et suivi intelligent
==========================================================================

Dans la leçon d'aujourd'hui, nous allons franchir un pas supplémentaire dans 
nos compétences STEAM. Nous allons combiner un module d'évitement d'obstacles 
avec un capteur ultrasonique pour créer un système avancé d'évitement d'obstacles. 
Nous allons également implémenter un système de suivi intelligent à notre Rover.

À la fin de cette leçon, notre Rover martien ne pourra pas seulement éviter les 
obstacles sur son chemin, mais aussi suivre des objets en mouvement. Imaginez 
avoir un mini-robot qui vous suit partout ! Excitant, n'est-ce pas ? Alors commençons.

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::

    Si vous suivez ce cours après avoir entièrement assemblé le GalaxyRVR, vous devez déplacer cet interrupteur vers la droite avant de téléverser le code.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Objectifs du cours
--------------------------
* Apprendre à combiner des modules d'évitement d'obstacles avec un capteur ultrasonique pour améliorer la navigation.
* Comprendre les principes et fonctionnalités derrière un système avancé d'évitement d'obstacles.
* Apprendre à implémenter un système de suivi intelligent dans le Rover martien.

Matériel nécessaire
------------------------
* Modèle de Rover martien (celui que nous avons construit dans les leçons précédentes)
* Câble USB
* IDE Arduino
* Ordinateur
* Et bien sûr, votre créativité !

Étapes du cours
--------------------

**Étape 1 : Comprendre le concept**

Le module d'évitement d'obstacles, comme son nom l'indique, aide notre 
Rover à éviter les obstacles. Il détecte les obstacles en transmettant 
un signal infrarouge et en recevant le signal réfléchi par l'objet. S'il 
y a un obstacle devant le module, le signal infrarouge est renvoyé et le 
module le détecte.

L'ajout d'un capteur ultrasonique à ce système améliore ses capacités. 
Les capteurs ultrasoniques mesurent la distance en envoyant une onde sonore 
à une fréquence spécifique et en écoutant l'écho de cette onde sonore. En 
enregistrant le temps écoulé entre l'émission et la réception de l'onde, 
il est possible de calculer la distance entre le capteur et l'objet.

Combiner ces deux éléments nous offre un système d'évitement d'obstacles fiable, efficace et polyvalent !


**Étape 2 : Construire un système avancé d'évitement d'obstacles**

Dans nos leçons précédentes, nous avons appris les bases de l'évitement d'obstacles à l'aide de capteurs infrarouges. Nous avons également exploré le fonctionnement d'un module ultrasonique. Maintenant, nous allons assembler toutes ces pièces pour créer un système d'évitement d'obstacles avancé !

Notre Rover martien amélioré utilisera désormais à la fois des capteurs ultrasoniques et infrarouges pour naviguer dans son environnement.

Imaginons comment les modules infrarouge et ultrasonique devraient fonctionner ensemble. Pour clarifier notre logique, utilisons un organigramme. Apprendre à créer des organigrammes est une étape précieuse dans notre parcours de programmation, car cela aide à clarifier vos idées et à planifier votre projet de manière systématique.

.. image:: img/ultrasonic_ir_avoid_flowchart.png
    :width: 800

Transformons maintenant cet organigramme en code pour donner vie à notre Rover.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/53d72ee5-a4c8-4524-92f8-4b0f4760c015/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Notez que la fonction ``handleForwardMovement()`` est l'endroit où nous avons intégré le comportement du capteur ultrasonique. Nous lisons les données de distance à partir du capteur et, en fonction de ces données, nous décidons du mouvement du Rover.

Après avoir téléversé le code sur votre carte R3, il est temps de tester le système. Assurez-vous que le Rover peut détecter et éviter les obstacles de manière efficace. N'oubliez pas que vous devrez peut-être ajuster la distance de détection dans le code en fonction de votre environnement réel pour perfectionner le système.

**Étape 3 : Programmer le système de suivi intelligent**

Avec notre Rover désormais capable d'éviter les obstacles, allons plus loin en lui permettant de suivre des objets. Notre objectif est de modifier notre code existant pour que le Rover se déplace vers un objet en mouvement.

Vous vous êtes déjà demandé quelle est la différence entre un système de suivi et un système d'évitement d'obstacles ?

La clé ici est que dans un système de suivi, nous voulons que notre Rover réagisse en se rapprochant des objets détectés, tandis que dans un système d'évitement d'obstacles, nous cherchons à éviter ces objets.

Visualisons le flux de travail souhaité :

.. image:: img/ultrasonic_ir_follow_flowchart.png

* Si le capteur ultrasonique détecte un objet à une distance de 5 à 30 cm, notre Rover doit se déplacer vers cet objet.
* Si le capteur IR gauche détecte un objet, notre Rover doit tourner à gauche.
* Si le capteur IR droit détecte un objet, notre Rover doit tourner à droite.
* Dans tous les autres cas, notre Rover reste immobile.

Complétons maintenant le code.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/75662c17-4b0a-4494-b18b-089cc2b32311/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Une fois le code terminé, testez si le Rover suit vos mouvements.

Comme pour le système d'évitement d'obstacles, il sera essentiel de tester notre système de suivi et de résoudre tout problème qui pourrait survenir. Prêt à commencer ?


**Étape 4 : Résumé et réflexion**

Aujourd'hui, vous avez accompli quelque chose d'extraordinaire. Vous avez combiné différents modules et concepts pour créer un système avancé d'évitement d'obstacles et de suivi pour votre Rover martien. N'oubliez pas que l'apprentissage ne s'arrête pas ici - continuez à explorer, innover et appliquer vos nouvelles compétences à d'autres projets.

Prenez toujours le temps de réfléchir à votre processus d'apprentissage. Pensez aux questions suivantes :

* Pourquoi avons-nous donné la priorité au module d'évitement d'obstacles avant le capteur ultrasonique dans notre système d'évitement, et vice versa dans le système de suivi ?
* Comment le résultat changerait-il si nous inversions l'ordre de vérification de ces modules dans le code ?

Les défis et les problèmes font partie intégrante du processus d'apprentissage STEAM, offrant de précieuses opportunités d'amélioration. N'ayez pas peur de résoudre les problèmes - c'est un outil d'apprentissage puissant en soi !

En continuant votre voyage, sachez que chaque obstacle surmonté vous rapproche un peu plus de la maîtrise de vos compétences STEAM. Continuez et profitez du voyage !
