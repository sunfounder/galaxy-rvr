.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 8 : Système avancé d’évitement d’obstacles et de suivi intelligent
=========================================================================

Dans la leçon d’aujourd’hui, nous allons aller encore plus loin dans notre aventure STEAM. Nous allons combiner un module d’évitement d’obstacles avec un capteur à ultrasons afin de créer un système avancé d’évitement d’obstacles.

Nous mettrons également en place un système de suivi intelligent pour notre Rover.

À la fin de cette leçon, notre Mars Rover sera non seulement capable d’éviter les obstacles sur son chemin, mais aussi de suivre des objets en mouvement. Imaginez un petit animal robotique qui vous suit partout ! Passionnant, n’est-ce pas ? Alors, commençons sans plus attendre.

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Votre navigateur ne prend pas en charge la lecture de vidéos HTML5.
    </video>

.. note::

    Si vous suivez ce cours après avoir entièrement assemblé le GalaxyRVR, vous devez déplacer cet interrupteur vers la droite avant de téléverser le programme.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Objectifs du cours
--------------------------

* Apprendre à combiner des modules d’évitement d’obstacles avec un module à ultrasons pour améliorer la navigation.
* Comprendre les principes et le fonctionnement d’un système avancé d’évitement d’obstacles.
* Apprendre à mettre en œuvre un système de suivi intelligent sur le Mars Rover.

Matériel nécessaire
------------------------

* Le modèle de Mars Rover construit lors des leçons précédentes
* Un câble USB
* Arduino IDE
* Un ordinateur
* Et bien sûr, votre créativité !

Étapes du cours
--------------------

**Étape 1 : Comprendre le principe**

Comme son nom l’indique, le module d’évitement d’obstacles aide notre Rover à éviter les obstacles. Il les détecte en émettant un signal infrarouge puis en recevant le signal réfléchi par l’objet.

Lorsqu’un obstacle se trouve devant le module, le signal infrarouge est réfléchi vers le capteur, qui détecte alors sa présence.

L’ajout d’un capteur à ultrasons améliore encore ce système. Les capteurs à ultrasons mesurent les distances en émettant une onde sonore à une fréquence spécifique puis en écoutant son écho. En mesurant le temps écoulé entre l’émission de l’onde et la réception de l’écho, il est possible de calculer la distance séparant le capteur de l’objet.

La combinaison de ces deux technologies nous permet d’obtenir un système d’évitement d’obstacles fiable, efficace et polyvalent !

**Étape 2 : Construire un système avancé d’évitement d’obstacles**

Dans les leçons précédentes, nous avons appris les bases de l’évitement d’obstacles à l’aide de capteurs infrarouges. Nous avons également découvert le fonctionnement d’un module à ultrasons. Il est maintenant temps de réunir toutes ces connaissances pour construire un système d’évitement d’obstacles plus avancé !

Notre Mars Rover amélioré utilisera désormais à la fois des capteurs infrarouges et un capteur à ultrasons pour analyser son environnement.

Réfléchissons à la manière dont les modules infrarouges et ultrasoniques doivent collaborer. Pour mieux comprendre notre logique, utilisons un organigramme. Apprendre à créer des organigrammes est une compétence précieuse dans le développement de programmes, car cela permet d’organiser ses idées et de planifier méthodiquement son projet.

.. image:: img/ultrasonic_ir_avoid_flowchart.png
    :width: 800

Transformons maintenant cet organigramme en véritable programme afin de donner vie à notre Rover.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/53d72ee5-a4c8-4524-92f8-4b0f4760c015/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Notez que la fonction ``handleForwardMovement()`` est l’endroit où nous avons intégré le comportement du capteur à ultrasons. Nous y lisons la distance mesurée et décidons du mouvement du Rover en fonction de cette information.

Après avoir téléversé le programme sur votre carte R3, il est temps de tester le système.

Assurez-vous que le Rover détecte et évite efficacement les obstacles.

N’oubliez pas qu’il peut être nécessaire d’ajuster les distances de détection dans le programme en fonction de votre environnement afin d’optimiser le comportement du système.

**Étape 3 : Programmer le système de suivi intelligent**

Maintenant que notre Rover est capable d’éviter les obstacles, allons encore plus loin en lui permettant de suivre des objets. Notre objectif est de modifier le programme existant afin que le Rover se déplace vers un objet en mouvement.

Vous êtes-vous déjà demandé quelle était la différence entre un système de suivi et un système d’évitement d’obstacles ?

La différence essentielle est que, dans un système de suivi, nous voulons que le Rover se dirige vers les objets détectés, tandis que dans un système d’évitement d’obstacles, nous cherchons au contraire à les éviter.

Visualisons le comportement souhaité :

.. image:: img/ultrasonic_ir_follow_flowchart.png

* Si le capteur à ultrasons détecte un objet situé entre 5 cm et 30 cm, le Rover doit avancer vers lui.
* Si le capteur infrarouge gauche détecte un objet, le Rover doit tourner à gauche.
* Si le capteur infrarouge droit détecte un objet, le Rover doit tourner à droite.
* Dans tous les autres cas, le Rover doit rester immobile.

Il est maintenant temps de compléter le programme.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/75662c17-4b0a-4494-b18b-089cc2b32311/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Une fois le programme terminé, testez si le Rover est capable de suivre vos déplacements.

Comme pour le système d’évitement d’obstacles, il sera important de tester soigneusement le système de suivi et de résoudre les éventuels problèmes rencontrés. Prêt à relever le défi ?

**Étape 4 : Résumé et réflexion**

Aujourd’hui, vous avez accompli quelque chose de remarquable. Vous avez combiné différents modules et concepts pour créer un système avancé d’évitement d’obstacles et de suivi pour votre Mars Rover.

N’oubliez pas que l’apprentissage ne s’arrête pas ici. Continuez à explorer, à innover et à appliquer vos nouvelles compétences à d’autres projets.

Prenez également le temps de réfléchir à ce que vous avez appris :

* Pourquoi, selon vous, avons-nous donné la priorité au module d’évitement d’obstacles avant le capteur à ultrasons dans le système d’évitement, alors que nous avons fait l’inverse dans le système de suivi ?
* Que se passerait-il si nous inversions l’ordre dans lequel ces modules sont vérifiés dans le programme ?

Les défis et les problèmes font partie intégrante de l’apprentissage STEAM et constituent d’excellentes occasions de progresser. N’hésitez pas à faire du dépannage : c’est en soi un puissant outil d’apprentissage.

Au fil de votre parcours, souvenez-vous que chaque obstacle surmonté vous rapproche un peu plus de la maîtrise de vos compétences STEAM. Continuez à avancer et profitez pleinement de cette aventure !
