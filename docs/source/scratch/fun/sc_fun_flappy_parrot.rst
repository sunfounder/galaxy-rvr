.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _sc_parrot:

Projet ludique 2 : Flappy Parrot
================================

Dans ce projet, nous utilisons un module ultrasonique pour jouer au jeu Flappy Parrot.

Après avoir lancé le script, le bambou vert (Paddle) se déplacera de droite à gauche à une hauteur aléatoire. Pour contrôler le perroquet, placez votre main au-dessus du module ultrasonique. Si la distance entre votre main et le module est inférieure à 10 cm, le perroquet montera ; sinon, il descendra. Vous devez gérer cette distance avec soin pour aider le perroquet à passer à travers le bambou vert. Tout contact avec le bambou met fin au jeu.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>

Voici les étapes pour réaliser ce projet. Il est conseillé de les suivre dans l'ordre, et une fois familiarisé, vous pourrez modifier les effets à votre guise.

1. Ajouter des sprites
----------------------

* Supprimez le sprite par défaut et utilisez le bouton **Choisir un sprite** pour ajouter le sprite **Parrot**. Réglez sa taille à 50 % et positionnez-le dans le coin inférieur gauche.

  .. image:: img/parrot_choose_parrot.png

* Ajoutez le sprite **Paddle**, réglez sa taille à 150 %, faites-le pivoter à 180 degrés et positionnez-le dans le coin supérieur droit.

  .. image:: img/parrot_choose_paddle.png

* Allez dans l'onglet **Costumes** du sprite **Paddle**, sélectionnez le **Paddle** sur le canevas, puis cliquez sur l'outil **Contour**.

  .. image:: img/parrot_set_parrot1.png
    :width: 90%

* Changez l'effet de contour en mode remplissage complet et utilisez l'outil de suppression pour l'éliminer.

  .. image:: img/parrot_set_parrot2.png
    :width: 90%

2. Programmer le sprite **Parrot**
----------------------------------

Programmez le sprite **Parrot** pour simuler son vol, avec des ajustements d'altitude basés sur la distance détectée par le module ultrasonique.

* Lorsque le drapeau vert est cliqué, changez de costume toutes les 0,2 secondes pour maintenir l'apparence de vol.

  .. image:: img/parrot_script_parrot1.png

* Si la distance de détection ultrasonique est inférieure à 10 cm, augmentez la coordonnée y de 50, faisant monter le **Parrot**. Sinon, diminuez la coordonnée y de 40, faisant descendre le **Parrot**.

  .. image:: img/parrot_script_parrot3.png

* Si le sprite **Parrot** entre en contact avec le sprite **Paddle**, le jeu se termine et le script cesse de s'exécuter.

  .. image:: img/parrot_script_parrot4.png

3. Programmer le sprite **Paddle**
----------------------------------

Programmez le sprite **Paddle** pour qu'il apparaisse aléatoirement sur la scène.

* Masquez le sprite **Paddle** lorsque le drapeau vert est cliqué et créez simultanément un clone de lui-même. Le bloc ``create clone of`` contrôle ce processus de clonage.

  .. image:: img/parrot_script_paddle1.png

* Définissez la position du clone avec la coordonnée x à 220 (tout à droite) et la coordonnée y aléatoirement entre -125 et 125.

  .. image:: img/parrot_script_paddle2.png

* Utilisez le bloc [repeat] pour diminuer progressivement sa coordonnée x, faisant avancer le clone lentement de droite à gauche jusqu'à sa disparition.

  .. image:: img/parrot_script_paddle3.png

* Clonez à nouveau un nouveau sprite **Paddle** et supprimez le clone précédent.

  .. image:: img/parrot_script_paddle4.png

La programmation est terminée. Vous pouvez maintenant cliquer sur le drapeau vert pour exécuter le script et voir s'il produit l'effet souhaité.


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4"  type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>
