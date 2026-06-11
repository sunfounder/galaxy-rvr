.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _sc_shooting:

Projet ludique 3 : Tir au but
=============================

Vous avez déjà vu ces jeux de tir palpitants à la télévision, où les candidats visent avec précision le centre de la cible pour accumuler des points ? Vous pouvez maintenant ressentir la même adrénaline ici dans Scratch ! Dans notre jeu de tir interactif, vous utiliserez le sprite Crosshair pour viser et atteindre le plus près possible du centre, en maximisant votre score à chaque tir précis.

Pour commencer, cliquez sur le drapeau vert. Vous contrôlerez vos tirs à l'aide du module anti-obstacle. Prêt à tester votre visée et vos réflexes ? Voyons votre score !


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>

Voici les étapes pour réaliser ce projet. Il est conseillé de les suivre dans l'ordre, et une fois familiarisé, vous pourrez modifier les effets à votre guise.

1. Dessiner le sprite **Crosshair**
-----------------------------------

* Supprimez le sprite par défaut, sélectionnez le bouton **Sprite**, puis cliquez sur **Dessiner**.

  .. image:: img/shooting_paint_cross.png

* Allez dans l'onglet **Costumes**. Utilisez l'outil **Cercle**, supprimez la couleur de remplissage et définissez la couleur et la largeur du contour.

  .. image:: img/shooting_paint_cross1.png

* Dessinez un cercle avec l'outil **Cercle**. Après l'avoir dessiné, utilisez l'outil **Sélection** pour aligner le centre du cercle avec le centre du canevas.

  .. image:: img/shooting_paint_cross2.png

* Avec l'outil **Ligne**, dessinez une croix à l'intérieur du cercle.

  .. image:: img/shooting_paint_cross3.png

* Enfin, revenez à la page **Code** et renommez le sprite « Crosshair ».

  .. image:: img/shooting_paint_cross4.png

2. Dessiner le sprite **Target**
--------------------------------

* De même, sélectionnez le bouton **Sprite** et cliquez sur **Dessiner**.

  .. image:: img/shooting_paint_target1.png

* Entrez dans l'onglet **Costumes**. Utilisez l'outil **Cercle**, choisissez une couleur noire, supprimez le contour et dessinez un grand cercle.

  .. image:: img/shooting_paint_target3.png
    :width: 90%

* Dessinez d'autres cercles avec la même méthode, chacun d'une couleur différente. Ajustez la position des cercles superposés à l'aide de l'outil **Avancer** ou **Reculer** pour vous assurer que les origines de tous les cercles sont alignées avec le centre du canevas.

  .. image:: img/shooting_paint_target4.png
    :width: 90%

* Revenez à la page **Code** et renommez ce sprite « Target ».

  .. image:: img/shooting_paint_target5.png

3. Ajouter un arrière-plan
--------------------------

* Ajoutez un arrière-plan approprié, de préférence peu coloré et qui ne correspond pas aux couleurs du sprite **Target**. J'ai choisi l'arrière-plan **Wall1**.

  .. image:: img/shooting_choose_backdrop.png

* Ajustez les positions et les tailles des sprites **Target** et **Crosshair**.

  .. note::

    * Assurez-vous que le sprite **Crosshair** est au-dessus du sprite **Target** en déplaçant d'abord le sprite **Target**, puis le **Crosshair**.
    * Le **Crosshair** doit être plus petit que l'espace entre les anneaux de couleur du sprite **Target**.

  .. image:: img/shooting_choose_backdrop1.png

4. Programmer le sprite **Crosshair**
-------------------------------------

* Randomisez la position et la taille du sprite **Crosshair**, lui permettant de se déplacer de manière imprévisible.

  .. image:: img/shooting_script_cross.png

* Lorsque le module anti-obstacle gauche est bloqué, un message est diffusé – shooting.

  .. image:: img/shooting_script_cross1.png

* Lorsque le message **shooting** est reçu, le sprite s'arrête de bouger et rétrécit progressivement, simulant le tir d'une balle.

  .. image:: img/shooting_script_cross2.png

* Utilisez le bloc [Touch color ()] pour déterminer la position du tir.

  .. image:: img/shooting_script_cross3.png
    :width: 90%

* Attribuez un score de 10 si le tir atterrit dans le cercle jaune.

  .. image:: img/shooting_script_cross4.png

* Attribuez un score de 9 si le tir atterrit dans le cercle rouge. De même, utilisez le bloc [Touch color ()] pour faire correspondre la couleur du cercle rouge.

  .. image:: img/shooting_script_cross5.png
    :width: 90%

* Utilisez la même méthode pour confirmer l'atterrissage de la balle. Si elle n'atterrit pas sur le sprite **Target**, cela indique un tir manqué.

  .. image:: img/shooting_script_cross6.png

La programmation est terminée. Vous pouvez maintenant cliquer sur le drapeau vert pour exécuter le script et voir s'il produit l'effet souhaité.


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4"  type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>
