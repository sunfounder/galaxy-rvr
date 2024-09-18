
.. note::

    Bonjour, et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions lors des fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !





Leçon 7 Animation d'évitement d'obstacles IR
=====================================================

Précédemment, nous avons utilisé le module d'évitement d'obstacles à infrarouge pour que GalaxyRVR évite automatiquement les obstacles, tout comme lors d'une mission d'exploration martienne.

Dans cette activité, nous allons combiner le module d'évitement d'obstacles avec une scène pour créer une animation d’un rover évitant des rochers sur Mars.


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_rock.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>



Objectifs d'apprentissage
-----------------------------

* Approfondir la compréhension du module d'évitement d'obstacles à infrarouge et de son application dans le rover martien.
* Apprendre à lire et appliquer les données du module d'évitement d'obstacles à infrarouge dans Scratch.
* Créer un jeu d'évitement d'obstacles sur le thème de l'exploration martienne en utilisant le module IR et la scène Scratch.


Matériel
--------------

* Smartphone ou tablette
* Application Mammoth Coding
* GalaxyRVR


Création de l'animation
--------------------------------------

1. Tout d'abord, nous avons besoin d'un arrière-plan sur le thème de Mars. Cliquez pour sélectionner un décor.

.. image:: img/5_animate_choose.png

2. Choisissez l'arrière-plan de Mars.

.. image:: img/5_animate_mars.png

3. Sélectionnez le sprite GalaxyRVR dans la bibliothèque et ajustez sa taille.

.. image:: img/5_animate_rvr.png

4. Sélectionnez un sprite de rocher dans la bibliothèque et ajustez sa taille.

.. image:: img/5_animate_rock.png


5. Ensuite, programmons ces deux sprites :



**Sprite GalaxyRVR**

Le rôle du sprite GalaxyRVR est de se déplacer lentement de la gauche vers la droite de l'écran. S'il touche un rocher, il s'arrête de bouger.
Pendant ce processus, nous pouvons déclencher les deux capteurs IR du rover physique avec nos mains. Déclencher le capteur droit fait descendre légèrement le sprite ; déclencher le capteur gauche le fait monter légèrement.



a. Lorsque le drapeau vert est cliqué, il doit apparaître à l'extrême gauche de l'écran. Vous pouvez d'abord déplacer le sprite à la position correspondante sur la scène, et les valeurs de coordonnées du bloc dans la catégorie mouvement changeront en conséquence.

.. image:: img/5_animate_glide.png

b. Placez un bloc "toujours" comme boucle principale.

.. image:: img/5_animate_forever.png

c. Faites glisser un bloc conditionnel pour vérifier s'il touche le sprite rocher.

.. image:: img/5_animate_touching.png

d. S'il ne touche pas, il avance.

.. image:: img/5_animate_moving.png

e. S'il touche, il s'arrête et pousse un cri.

.. image:: img/5_animate_say.png

f. Enfin, ajoutez deux événements. Lorsque les capteurs IR gauche ou droit détectent un obstacle (votre main), le sprite monte ou descend.

.. image:: img/5_animate_y.png


**Sprite Rocher**

Le rôle du sprite rocher est plus simple. Il peut rester en place, apparaître à des endroits aléatoires ou créer plusieurs clones pour augmenter la difficulté pour le sprite GalaxyRVR.

a. Créez ses clones.

.. image:: img/5_animate_clone.png

b. Ensuite, déplacez-le à une position aléatoire. Combinez ces deux blocs et cliquez dessus. Vous verrez de nouveaux rochers apparaître aléatoirement sur la scène.

.. image:: img/5_animate_clone_move.png

c. Générez dix rochers aléatoires.

.. image:: img/5_animate_clone_10.png

d. Ces actions se déclenchent lorsque le drapeau vert est cliqué.

.. image:: img/5_animate_clone_flag.png    
   :width: 200

Maintenant, ce mini-jeu est complet.

Connectez GalaxyRVR à l'application (référez-vous à :ref:`app_connet`) et cliquez sur le drapeau vert pour démarrer le jeu.

Vous verrez de nombreux rochers générés aléatoirement sur la scène. Votre tâche est d'utiliser vos mains pour déclencher les deux capteurs IR,
guidant GalaxyRVR pour qu'il atteigne avec succès le côté droit de la scène.

