.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _sc_tap_tile:

Projet ludique 7 : Tapez sur la tuile noire
===========================================

Beaucoup d'entre vous connaissent le célèbre jeu mobile où les joueurs tapent sur les tuiles noires pour marquer des points tout en évitant les tuiles blanches. Nous recréons ce défi addictif en utilisant deux modules anti-obstacle. Lorsque votre main bloque l'un des modules IR, une pression est enregistrée sur la scène.

Si une pression atterrit sur une tuile noire, vous marquez un point ; taper sur une tuile blanche vous fait perdre un point. Les joueurs doivent décider rapidement s'ils doivent taper sur le module IR gauche ou droit en fonction de la position des tuiles noires.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_tap_black_tile.mp4"  type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>

Voici les étapes pour réaliser ce projet. Il est conseillé de les suivre dans l'ordre, et une fois familiarisé, vous pourrez modifier les effets à votre guise.

1. Dessiner un sprite **Tile**
------------------------------

Un sprite **Tile** est utilisé pour obtenir l'effet de tuiles noires et blanches alternées qui descendent ; dans la version mobile de ce jeu, il y a généralement 4 colonnes, ici nous n'en faisons que deux.


* Supprimez le sprite par défaut, appuyez sur l'icône **Ajouter un sprite**, sélectionnez **Dessiner**.

  .. image:: img/tile_paint_tile1.png

* Ensuite, allez dans l'onglet **Costumes** et utilisez l'outil **Rectangle** pour dessiner un rectangle avec une bordure grise et un remplissage blanc.

  .. image:: img/tile_paint_tile2.png
    :width: 90%

* Sélectionnez le rectangle et cliquez sur **Copier** -> **Coller** pour créer un rectangle identique, puis placez les deux rectangles côte à côte.

  .. image:: img/tile_paint_tile3.png
    :width: 90%

* Sélectionnez l'un des rectangles et choisissez une couleur de remplissage noire.

  .. image:: img/tile_paint_tile4.png
    :width: 90%

* Sélectionnez maintenant les deux rectangles et déplacez-les de sorte que leurs points centraux correspondent au centre du canevas.

  .. image:: img/tile_paint_tile5.png
    :width: 90%

* Dupliquez costume1, en alternant les couleurs de remplissage des deux rectangles. Par exemple, la couleur de remplissage de costume1 est blanche à gauche et noire à droite, et la couleur de remplissage de costume2 est noire à gauche et blanche à droite.

  .. image:: img/tile_paint_tile6.png
    :width: 90%

* Revenez à la page **Code** et nommez le sprite **Tile**.

  .. image:: img/tile_paint_tile7.png

2. Programmer le sprite **Tile**
--------------------------------

* D'abord, définissez la position initiale du sprite **Tile** pour qu'il soit en haut de la scène.

  .. image:: img/tile_script_tile1.png

* Créez une variable - **blocks** et donnez-lui une valeur initiale pour déterminer le nombre de fois que le sprite **Tile** apparaîtra. Utilisez le bloc [repeat until] pour faire diminuer progressivement la variable **blocks** jusqu'à ce qu'elle atteigne 0. Pendant ce temps, faites changer aléatoirement de costume au sprite **Tile**. Après avoir cliqué sur le drapeau vert, vous verrez le sprite **Tile** changer rapidement de costume sur la scène.

  .. image:: img/tile_script_tile2.png

* Créez des clones du sprite **Tile** pendant que la variable **blocks** diminue, et arrêtez le script lorsque blocks atteint 0. Deux blocs [wait () seconds] sont utilisés ici : le premier pour limiter l'intervalle entre les clones de **Tile** et le second pour laisser le temps à la variable blocks de diminuer jusqu'à 0 sans arrêter immédiatement le programme, donnant au dernier sprite tuile suffisamment de temps pour se déplacer.

  .. image:: img/tile_script_tile3.png

* Programmez maintenant le clone du sprite **Tile** pour qu'il descende lentement et le supprimer lorsqu'il atteint le bas de la scène. La modification de la coordonnée y affecte la vitesse de chute : plus la valeur est grande, plus la vitesse de chute est rapide.

  .. image:: img/tile_script_tile4.png

* Masquez le corps et affichez le clone.

  .. image:: img/tile_script_tile5.png

3. Programmer l'arrière-plan
----------------------------

Dans l'arrière-plan, lisez les valeurs des 2 modules IR et effectuez les actions correspondantes.

* Lorsque le drapeau vert est cliqué, définissez la variable **count** à 0.

  .. image:: img/tile_script_backdrop.png
    :width: 90%

* Si le module anti-obstacle IR gauche détecte votre main, diffusez un message - **left**.

  .. image:: img/tile_script_backdrop1.png


* Si le module anti-obstacle IR droit détecte votre main, diffusez un message - **right**.

  .. image:: img/tile_script_backdrop2.png


4. Dessiner le sprite **Left IR**
---------------------------------

Un sprite **Left IR** est utilisé pour obtenir l'effet de clic ; lorsque le module IR gauche détecte votre main, il enverra un message - **left** au sprite **Left IR**, le faisant fonctionner. S'il touche la tuile noire sur la scène, le score augmentera de 1, sinon, le score diminuera de 1.


* Encore une fois, appuyez sur l'icône **Ajouter un sprite** et sélectionnez **Dessiner**.

  .. image:: img/tile_paint_ir1.png

* Allez dans l'onglet **Costumes**, sélectionnez la couleur de remplissage (n'importe quelle couleur sauf noir et blanc) et dessinez un cercle.

  .. image:: img/tile_paint_ir2.png

* Revenez à la page **Code** et nommez le sprite **Left IR**.

  .. image:: img/tile_paint_ir3.png

5. Programmer le sprite **Left IR**
-----------------------------------

* Maintenant, commencez à programmer le sprite **Left IR**. Lorsque le drapeau vert est cliqué, masquez d'abord le sprite.

  .. image:: img/tile_script_ir1.png

* Lorsque le message - **left** est reçu (le module récepteur IR gauche détecte un obstacle), affichez le sprite, définissez sa taille à 100 %, puis réduisez-la par intervalles de 10 à l'aide d'un bloc [Repeat] avant de le masquer à nouveau. Cela donne au sprite un effet d'expansion et de contraction.

  .. image:: img/tile_script_ir2.png

* Déterminez ensuite si le bloc noir du sprite **Tile** est touché, et si c'est le cas, augmentez la variable **count** de 1, sinon diminuez-la de 1.

  .. image:: img/tile_script_ir3.png

.. note::

    Vous devez faire apparaître le sprite **Tile** sur la scène, puis prélever la couleur du bloc noir du sprite **Tile**.

    .. image:: img/tile_script_ir4.png

6. Sprite **Right IR**
----------------------

La fonction du sprite **Right IR** est essentiellement la même que celle de **Left IR**, sauf qu'il reçoit l'information **Right**.


* Maintenant, dupliquez le sprite **Left IR** et renommez-le **Right IR**.

  .. image:: img/tile_paint_ir4.png

* Modifiez ensuite le message reçu en - **right**.

    .. image:: img/tile_script_ir5.png

7. Exécuter le script
---------------------

* Maintenant, ajustez les positions et les tailles des trois sprites.

  * Faites glisser le sprite **Tile** en bas de la scène et réglez sa position x à 0.
  * Déplacez le sprite **Left IR** dans le cadre gauche. Vous devez aller dans l'onglet **Costumes** pour réduire la taille du sprite à seulement 50 % de la taille du cadre.
  * De même, déplacez le sprite **Right IR** dans le cadre droit. Vous devez aller dans l'onglet **Costumes** pour réduire la taille du sprite à seulement 50 % de la taille du cadre.
  * Assurez-vous que les sprites **Left IR** et **Right IR** sont au-dessus du sprite **Tile**.

  .. image:: img/tile_paint_ir5.png

* Maintenant, toute la programmation est terminée, et vous pouvez cliquer sur le drapeau vert pour exécuter le script.

  .. raw:: html

    <video loop autoplay muted style = "max-width:70%">
        <source src="../../_static/video/sc_tap_black_tile.mp4"  type="video/mp4">
        Votre navigateur ne prend pas en charge la balise vidéo.
    </video>
