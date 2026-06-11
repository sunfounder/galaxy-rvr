.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _sc_balloon:

Projet ludique 1 : Gonfler le ballon
====================================

Dans ce projet interactif, nous contrôlons le vol d'un ballon.

En cliquant sur le drapeau vert, le ballon se gonflera progressivement. Si le ballon devient trop gros, il éclatera ; s'il est trop petit, il tombera. Votre mission consiste à bloquer le module infrarouge gauche au bon moment pour le faire monter.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_balloon.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>

Voici les étapes pour réaliser ce projet. Il est conseillé de les suivre dans l'ordre, et une fois familiarisé, vous pourrez modifier les effets à votre guise.


1. Ajouter un sprite et un arrière-plan
---------------------------------------

* Supprimez le sprite par défaut et cliquez sur le bouton **Choisir un sprite** dans le coin inférieur droit de la zone des sprites. Sélectionnez ensuite le sprite **Balloon1**.

  .. image:: img/balloon_choose_sprite.png

* Ajoutez un arrière-plan **Boardwalk** ou un autre arrière-plan de votre choix via le bouton **Choisir un arrière-plan**.

  .. image:: img/balloon_choose_backdrop.png

2. Dessiner un costume pour le sprite **Balloon1**
--------------------------------------------------

Maintenant, créons un costume d'explosion pour le ballon.

* Allez dans l'onglet **Costumes** du sprite **Balloon1**, cliquez sur le bouton **Choisir un costume** en bas à gauche, puis sélectionnez **Dessiner** pour ouvrir un **Costume** vierge. Nommez-le « boom ».

  .. image:: img/balloon_set_ball1.png

* Choisissez une couleur et utilisez l'outil **Pinceau** pour dessiner un motif.

  .. image:: img/balloon_set_ball2.png
    :width: 90%

* Choisissez une autre couleur, sélectionnez l'outil **Remplissage** et appuyez à l'intérieur du motif pour le remplir.

  .. image:: img/balloon_set_ball3.png
    :width: 90%

* Enfin, ajoutez le texte « BOOM » pour terminer le costume d'explosion.

  .. image:: img/balloon_set_ball4.png
    :width: 90%

3. Programmer le sprite **Ballon**
----------------------------------

* Initialisez la position et la taille du sprite **Balloon1**.

  .. image:: img/balloon_script1.png

* Augmentez progressivement la taille du sprite **Ballon**.

  .. image:: img/balloon_script2.png

* À ce stade, bloquez le module anti-obstacle gauche pour empêcher le sprite **Balloon1** de continuer à gonfler.

  .. image:: img/balloon_script3.png

* Maintenant, laissez le sprite **Balloon1** décider de monter ou de descendre en fonction de sa taille.

  * Si la taille est inférieure à 90, il descendra (la coordonnée y diminue).
  * Si la taille est comprise entre 90 et 120, il montera (la coordonnée y augmente).

  .. image:: img/balloon_script4.png

* Si vous ne parvenez pas à bloquer le module anti-obstacle gauche, le ballon continuera de gonfler jusqu'à dépasser une taille de 120, moment où il explosera (passage au costume d'explosion).

  .. image:: img/balloon_script5.png

La programmation est terminée. Vous pouvez maintenant cliquer sur le drapeau vert pour exécuter le script et voir s'il produit l'effet souhaité.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_balloon.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>
