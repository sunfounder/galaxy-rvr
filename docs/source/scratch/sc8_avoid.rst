.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _ir_ultra_avoid:

Leçon 8 : Évitement d'obstacles avancé
======================================

Vous êtes-vous déjà demandé comment les robots peuvent naviguer dans une pièce sans heurter les meubles ? Aujourd'hui, nous allons apprendre à notre Rover Martien à faire exactement cela ! Nous allons combiner deux types de capteurs différents pour créer un système d'évitement d'obstacles super intelligent.

Comment les capteurs aident le robot à « voir »
------------------------------------------------

Réfléchissons à la façon dont nous utilisons nos sens :

* **Les capteurs infrarouges** fonctionnent comme l'écholocalisation des chauves-souris ! Ils émettent une lumière infrarouge invisible et écoutent son rebond sur les objets. Si la lumière revient rapidement, un obstacle se trouve à proximité.

* **Les capteurs ultrasoniques** fonctionnent avec des ondes sonores que nous ne pouvons pas entendre. Ils émettent des sons à haute fréquence et mesurent le temps que met l'écho à revenir. Plus le temps est long, plus l'objet est éloigné.

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Votre navigateur ne prend pas en charge la balise vidéo.
    </video>

Lorsque nous utilisons les deux capteurs ensemble, notre Rover obtient une bien meilleure compréhension de son environnement – comme lorsque vous utilisez à la fois vos yeux et vos oreilles pour naviguer dans une pièce sombre !

Objectifs d'apprentissage
-------------------------

* Combiner les capteurs ultrasoniques et infrarouges pour créer un système avancé d'évitement d'obstacles
* Programmer votre Rover Martien pour qu'il détecte automatiquement les obstacles et les contourne

Construire notre Rover super intelligent
----------------------------------------

Vous souvenez-vous du programme d'évitement d'obstacles que nous avons créé précédemment ? Nous allons l'utiliser comme point de départ et l'améliorer encore !

#. Commencez par :ref:`app_connect`.

#. Maintenant, ouvrons notre projet précédent de capteurs infrarouges de :ref:`ir_obstacle` comme modèle. Cliquez sur « Fichier » et retrouvez votre projet d'évitement d'obstacles IR enregistré.

   .. image:: img/7_avoid_open.png

#. Avant de faire des modifications, sauvegardons une copie pour ne pas perdre notre travail original. Cliquez sur « Enregistrer une copie ».

   .. image:: img/7_avoid_save_copy.png

#. Donnez à votre nouveau projet un nom sympa comme « Rover Super Intelligent » ou « Évitement d'obstacles avancé ».

   .. image:: img/7_avoid_save_rename.png

#. Ajoutons maintenant notre capteur ultrasonique ! Glissez le bloc ``when distance < 15 cm``. Ce sera notre « système d'alerte précoce » qui détecte les obstacles de plus loin.

   .. image:: img/7_avoid_when.png
       :width: 800

#. Pour éviter toute confusion, nous ajouterons un bloc ``stop other scripts in sprite``. Cela garantit que notre Rover ne suit qu'un seul ensemble d'instructions à la fois.

   .. image:: img/7_avoid_stop.png

#. Lorsque le capteur ultrasonique détecte quelque chose de proche, nous voulons que notre Rover recule jusqu'à une distance de sécurité.

   .. image:: img/7_avoid_backward.png

#. Maintenant, nous devons nous écarter de l'obstacle. Le Rover tournera pendant une seconde – vous pouvez choisir un virage à gauche ou à droite !

   .. image:: img/7_avoid_turn.png

#. Enfin, nous ordonnons au Rover de continuer à avancer sur sa nouvelle trajectoire.

   .. image:: img/7_avoid_go.png

Incroyable ! Vous avez maintenant un Rover qui utilise trois capteurs travaillant ensemble comme une équipe :

- Le capteur ultrasonique avant repère les obstacles éloignés
- Le capteur IR gauche détecte les objets sur le côté gauche
- Le capteur IR droit surveille le côté droit

Testez votre programme et observez avec quelle fluidité votre Rover contourne les obstacles. Essayez de créer un parcours d'obstacles et voyez si votre Rover peut le terminer sans aucune collision !

Défi : Pouvez-vous modifier le temps de rotation ou la distance pour rendre votre Rover encore meilleur dans l'évitement d'obstacles ?
