.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 7 : Créer une animation avec le capteur IR
================================================

Lors de nos missions précédentes, nous avons utilisé le module infrarouge anti-obstacle pour aider notre GalaxyRVR à éviter automatiquement les obstacles – comme un véritable Rover Martien naviguant sur la Planète Rouge !

Maintenant, passons au niveau supérieur en combinant les capteurs IR physiques avec un paysage martien virtuel. Nous allons créer un jeu d'animation passionnant où vous contrôlez un sprite de rover en déclenchant les vrais capteurs IR avec vos mains !

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_rock.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>

Objectifs d'apprentissage
-------------------------

* Découvrir comment le module infrarouge anti-obstacle donne vie à votre Rover Martien
* Apprendre à utiliser les données des capteurs IR pour contrôler des personnages dans vos animations Scratch
* Construire votre propre jeu d'exploration martienne où vous esquivez des rochers à l'aide de vrais capteurs

Créer la scène d'animation
---------------------------

#. Commencez par :ref:`app_connect`.

#. Mise en place de l'arrière-plan martien

   * D'abord, nous avons besoin d'un arrière-plan sur le thème de Mars. Cliquez pour choisir un arrière-plan.

     .. image:: img/5_animate_choose.png

   * Choisissez l'arrière-plan **Mars**.

     .. image:: img/5_animate_mars.png

#. Ajout du personnage rover

   Choisissez le sprite **GalaxyRVR** dans la bibliothèque et redimensionnez-le pour l'adapter correctement à votre scène.

   .. image:: img/5_animate_rvr.png

#. Ajout d'obstacles

   Sélectionnez un sprite **Rocks** dans la bibliothèque et ajustez sa taille.

   .. image:: img/5_animate_rock.png


Programmer le sprite GalaxyRVR
------------------------------

Programmez votre sprite GalaxyRVR pour qu'il traverse l'écran de gauche à droite. Votre mission : le guider en toute sécurité entre les rochers !
Utilisez vos mains pour déclencher les capteurs IR du rover physique – le capteur droit déplace le sprite vers le bas, le capteur gauche le déplace vers le haut.

#. Définissez la position de départ en déplaçant le sprite vers le bord gauche de la scène. Les blocs de mouvement se mettront automatiquement à jour avec les bonnes coordonnées.

   .. image:: img/5_animate_glide.png

#. Ajoutez un bloc « répéter indéfiniment » pour créer la boucle principale du programme qui s'exécute en continu.

   .. image:: img/5_animate_forever.png

#. Incluez un bloc conditionnel pour vérifier si le rover touche un obstacle rocher.

   .. image:: img/5_animate_touching.png

#. Si aucun rocher n'est détecté, continuez d'avancer vers la droite.

   .. image:: img/5_animate_moving.png

#. Si le rover heurte un rocher, arrêtez tout mouvement et affichez un message d'avertissement.

   .. image:: img/5_animate_say.png

#. Ajoutez les commandes des capteurs : créez des événements pour les deux capteurs IR qui déplacent le sprite vers le haut (capteur gauche) ou vers le bas (capteur droit) lorsqu'ils sont déclenchés par votre main.

   .. image:: img/5_animate_y.png

Programmer le sprite Rocher
---------------------------

Créons plusieurs obstacles rochers pour rendre le jeu plus stimulant ! Nous utiliserons le clonage pour générer des rochers à des positions aléatoires sur la scène.

#. Créez des clones de rocher en utilisant le bloc « create clone of myself ».

   .. image:: img/5_animate_clone.png

#. Faites apparaître chaque clone à un emplacement aléatoire en ajoutant le bloc « go to random position ».

   .. image:: img/5_animate_clone_move.png
      :width: 200

#. Générez dix rochers en répétant la création de clones dix fois.

   .. image:: img/5_animate_clone_10.png
      :width: 200

#. Faites démarrer toute cette action lorsque le drapeau vert est cliqué.

   .. image:: img/5_animate_clone_flag.png
      :width: 200

Lancement de la mission !
-------------------------

Félicitations ! Votre jeu d'évitement d'obstacles martien est prêt à être lancé.

Connectez votre GalaxyRVR à l'application et cliquez sur le drapeau vert pour commencer votre mission. Regardez les rochers apparaître aléatoirement dans le paysage martien.

Votre défi : utilisez vos mains pour déclencher les capteurs IR et guidez soigneusement le sprite GalaxyRVR à travers l'écran. Déplacez-le vers le haut et vers le bas pour éviter les rochers et atteindre le côté droit en toute sécurité !

Pouvez-vous terminer la mission sans aucune collision ? À quelle vitesse pouvez-vous naviguer dans le parcours d'obstacles ? Continuez à vous entraîner pour devenir un maître pilote de Rover Martien !
