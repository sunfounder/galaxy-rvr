.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Projet ludique 6 : La balle sensible à la distance
==================================================

Dans ce projet, nous utilisons un module ultrasonique pour contrôler le mouvement vertical d'une balle sur la scène. Lorsque vous cliquez sur le drapeau vert, placez votre main au-dessus du module ultrasonique. La balle montera si la distance entre votre main et le module est inférieure à 15 cm ; sinon, elle descendra. Lorsque la balle entre en contact avec une ligne, elle déclenche un son agréable et active des effets scintillants d'étoiles.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>

Suivez ces étapes pour mettre en place le projet, et n'hésitez pas à modifier les effets à votre guise une fois que vous êtes habitué à son fonctionnement.

1. Sélectionner les sprites
---------------------------

* Supprimez le sprite par défaut et sélectionnez les sprites **Ball**, **Bowl** et **Star**.

  .. image:: img/ball_choose_sprite.png

* Positionnez le sprite **Bowl** au centre en bas de la scène et augmentez sa taille.

  .. image:: img/ball_set_bowl.png

* Placez le sprite **Ball** directement au-dessus du sprite **Bowl**, en définissant sa direction à 0 pour permettre un mouvement vertical.

  .. image:: img/ball_set_ball.png

* Ajustez la taille du sprite **Star** et définissez sa direction à 180 pour qu'il tombe vers le bas. Cela peut être modifié selon d'autres angles si vous préférez.

  .. image:: img/ball_set_star.png

* Ajoutez l'arrière-plan **Stars** pour plus d'ambiance.

  .. image:: img/ball_select_backdrop.png

2. Dessiner un sprite **Line**
------------------------------

* Ajoutez maintenant un sprite **Line**.

  .. image:: img/ball_select_line.png

* Allez dans l'onglet **Costumes** du sprite **Line**.

  .. image:: img/ball_open_cos.png
    :width: 90%

* Réduisez légèrement la largeur de la ligne rouge sur le canevas, dupliquez-la quatre fois et alignez ces lignes.

  .. image:: img/ball_copy_line.png
    :width: 90%

* Colorez chaque ligne différemment. Sélectionnez une ligne, utilisez l'outil **Remplissage** et choisissez une couleur.

  .. image:: img/ball_set_bk_color.png
    :width: 90%

* Appliquez cette méthode pour colorer toutes les lignes.

  .. image:: img/ball_select_line_color.png
    :width: 90%

* Revenez à la page **Code** et positionnez le sprite **Line** en haut de la scène.

  .. image:: img/ball_line_position.png

3. Programmer le sprite **Ball**
--------------------------------

Ici, nous programmons le sprite **Ball** pour qu'il monte ou descende en fonction de la distance détectée par le module ultrasonique, avec une contrainte de mouvement pour simuler l'atterrissage sur le sprite **Bowl**.

* Lorsque le drapeau vert est cliqué, définissez la position initiale du sprite **Ball**.

  .. image:: img/ball_script_ball1.png

* Utilisez un bloc [if else] pour vérifier si la distance est inférieure à 15. Si c'est vrai, déplacez le sprite **Ball** de 10 pas vers le haut, étant donné que sa direction est définie à 0.

  .. image:: img/ball_script_ball3.png

* Sinon, laissez le sprite **Ball** tomber, en limitant sa coordonnée Y à un minimum de -100, ajustable pour donner l'impression qu'il atterrit sur le sprite **Bowl**.

  .. image:: img/ball_script_ball4.png

* Programmez l'interaction où le sprite **Ball**, en touchant le sprite **Line**, enregistre sa position Y dans la variable **ball_coor** et diffuse un message **bling**.

  .. image:: img/ball_script_ball5.png

4. Programmer le sprite **Star**
--------------------------------

* Masquez d'abord le sprite **Star** lorsque le drapeau vert est cliqué. À la réception du message **Bling**, clonez le sprite **Star**.

  .. image:: img/ball_script_star1.png

* Définissez la position et les effets sonores du clone pour les synchroniser avec la position du sprite **Ball**.

  .. image:: img/ball_script_star2.png

* Faites-le pivoter aléatoirement entre -80 et 80 degrés.

  .. image:: img/ball_script_star3.png

* Ajustez l'apparence et le comportement du sprite **Star** selon les besoins pour améliorer l'effet visuel.

  .. image:: img/ball_script_star4.png

La programmation est terminée. Cliquez sur le drapeau vert pour exécuter le script et voir s'il répond à vos attentes.


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4"  type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>
