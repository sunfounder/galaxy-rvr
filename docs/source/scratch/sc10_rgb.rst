.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 10 : Illuminer le chemin avec les bandes LED RGB
======================================================

Notre Rover Martien est devenu un explorateur talentueux, mais il est temps d'ajouter un peu de personnalité colorée ! Dans cette leçon, nous allons transformer notre rover avec des bandes LED RGB capables de briller dans toutes les couleurs imaginables.

Imaginez votre GalaxyRVR illuminant son chemin comme un vaisseau spatial de film de science-fiction :

- Lueur verte en avançant
- Lumière rouge à l'arrêt
- Flashs jaunes en tournant
- De magnifiques jeux de couleurs juste pour le plaisir !

Nous allons apprendre à programmer ces lumières incroyables et à les synchroniser avec les mouvements de votre rover. Préparez-vous à créer votre propre explorateur martien lumineux !

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/car_rgb.mp4" type="video/mp4">
        Votre navigateur ne prend pas en charge la balise vidéo.
    </video>

Objectifs d'apprentissage
-------------------------

* Découvrir comment fonctionnent les bandes LED RGB et comment les programmer
* Apprendre à contrôler les couleurs et à créer des effets lumineux avec Mammoth Coding
* Concevoir des signaux lumineux et des couleurs pour vos missions d'exploration martienne

Explorer la magie de la lumière avec les bandes LED RGB
-------------------------------------------------------

Avez-vous déjà rêvé de créer votre propre arc-en-ciel ? Maintenant, c'est possible ! Avec les bandes LED RGB, vous pouvez faire briller votre Rover Martien dans toutes les couleurs que vous imaginez. Découvrons la magie des lumières colorées !

.. image:: img/4_rgb_strip.jpg

Voici les quatre broches importantes de votre bande LED :

* **+5V** – La broche d'alimentation qui fournit l'énergie à toutes les lumières (nécessite 5 V)
* **B** – Contrôle les lumières bleues
* **R** – Contrôle les lumières rouges
* **G** – Contrôle les lumières vertes

.. image:: img/rgb_5050.jpg

Vous vous souvenez des couleurs primaires en cours d'art plastique ? Comme pour mélanger de la peinture, chaque LED peut combiner la lumière rouge, bleue et verte pour créer des couleurs incroyables ! Chaque LED « 5050 » est comme une petite usine de couleurs contenant les trois couleurs.

.. image:: img/rgb_5050_sche.png

Toutes ces usines de couleurs sont reliées entre elles sur un circuit flexible – comme une autoroute électrique colorée ! Les broches d'alimentation se connectent ensemble, tandis que les broches de couleur ont chacune leur propre chemin.

.. image:: img/rgb_strip_sche.png

Le plus passionnant ? Vous pouvez programmer TOUTES les LED pour changer de couleur en même temps ! Imaginez créer votre propre spectacle lumineux avec seulement quelques blocs de code. Préparez-vous à illuminer l'aventure de votre Rover Martien !

Allumer le spectacle
--------------------

#. Commencez par :ref:`app_connect`.

#. Maintenant, faisons briller votre GalaxyRVR ! Glissez un bloc « display color » pour commencer.

   .. image:: img/9_rgb_block.png

#. Choisissez la couleur de votre choix dans le menu des couleurs.

   .. image:: img/9_rgb_color.png

#. Cliquez sur le bloc et regardez votre GalaxyRVR s'illuminer de la couleur choisie !

**Créer un contrôleur de couleurs**

Construisons maintenant un contrôleur de couleurs interactif ! Nous allons créer des boutons colorés sur la scène qui changent les lumières de votre GalaxyRVR lorsque vous les touchez.

1. D'abord, supprimez les sprites existants pour repartir de zéro.

   .. image:: img/6_animate_delete.png

2. Ajoutez un sprite Ball depuis la bibliothèque. Ce sprite est parfait car il possède plusieurs costumes de couleurs.

   .. image:: img/9_animate_rgb_ball.png

3. Ajoutez un bloc « when this sprite clicked » – cela déclenchera une action lorsque vous touchez la balle.

   .. image:: img/9_animate_rgb_when.png

4. Connectez un bloc « display color » pour illuminer votre GalaxyRVR.

   .. image:: img/9_animate_rgb_display.png

5. Sur les petits écrans, assurez-vous de voir la scène en cliquant sur le bouton en forme d'œil.

   .. image:: img/9_animate_rgb_eye.png

6. Cliquez sur la case couleur dans le bloc d'affichage, puis cliquez sur le bouton pipette en bas.

   .. image:: img/9_animate_rgb_pick.png

7. Appuyez longuement sur la zone de la scène – une loupe apparaîtra ! Relâchez-la sur le sprite balle pour copier sa couleur.

   .. image:: img/9_animate_rgb_pick_color_n.png

8. Créez d'autres boutons de couleur en appuyant longuement sur le sprite balle pour le dupliquer.

   .. image:: img/9_animate_rgb_duplicate.png

9. Changez chaque copie pour une couleur différente en modifiant son costume.

   .. image:: img/9_animate_rgb_change_costume.png

10. Pour chaque nouvelle couleur, utilisez la pipette pour faire correspondre le bloc d'affichage à la couleur actuelle du sprite.

    .. image:: img/9_animate_rgb_pick_blue.png

11. Répétez jusqu'à avoir cinq boutons de couleurs différentes !

    .. image:: img/9_animate_rgb_ball5.png

Maintenant, touchez n'importe quelle balle colorée sur la scène et regardez votre GalaxyRVR briller de cette couleur ! Créez votre propre spectacle lumineux d'une simple pression.

.. _rgb_move:

Les signaux lumineux du GalaxyRVR en action
-------------------------------------------

**Feux indicateurs de direction**

Combinons les couleurs lumineuses avec le mouvement pour créer des feux de signalisation pour votre GalaxyRVR ! Comme une voiture a des clignotants, votre rover s'illuminera de différentes couleurs lorsqu'il se déplace.

#. Commencez par :ref:`app_connect`.

#. Maintenant, configurez les touches directionnelles avec des blocs de mouvement pour les quatre directions.

   .. image:: img/9_rgb_move.png

#. Ajoutez des affichages de couleur à chaque direction :

   - Lumière verte pour avancer

   .. image:: img/9_rgb_green.png

   - Lumières jaunes pour tourner à gauche et à droite

   .. image:: img/9_rgb_yellow.png

   - Lumière rouge pour reculer

   .. image:: img/9_rgb_red.png

Maintenant, lorsque vous appuyez sur les touches directionnelles, votre GalaxyRVR se déplace et brille de la couleur correspondante !

**Effet de lumière respirante**

Créons un effet de lumière respirante qui s'intensifie et s'atténue doucement lorsque votre rover est au repos, comme s'il respirait !

1. Créez un nouveau message de diffusion appelé « stop » pour signaler que le rover ne bouge pas.

   .. image:: img/9_rgb_new_message.png

   .. note:: Les messages de diffusion aident à organiser votre code en déclenchant des actions spécifiques au bon moment, rendant vos programmes plus clairs et plus faciles à comprendre.

2. Ajoutez cette diffusion après chaque commande de mouvement.

   .. image:: img/9_rgb_new_boardcast.png

3. Créez un bloc « when I receive [stop] » pour démarrer la lumière respirante.

   .. image:: img/9_rgb_when_receive.png

4. Réglez la luminosité à 0 % pour commencer complètement éteint.

   .. image:: img/9_rgb_set_bright.png

5. Utilisez une boucle de répétition pour augmenter progressivement la luminosité bleue de 10 % toutes les 0,2 secondes.

   .. image:: img/9_rgb_increase.png

6. Diminuez ensuite progressivement la luminosité pour terminer un cycle de respiration.

   .. image:: img/9_rgb_decrease.png

7. Diffusez à nouveau « stop » pour que l'effet de respiration reste continu.

   .. image:: img/9_rgb_stopagain.png

8. Ajoutez « stop other scripts » à la fin de chaque événement de touche pour éviter les conflits de couleurs.

   .. image:: img/9_rgb_stop.png

9. Réinitialisez la luminosité dans chaque événement de touche directionnelle.

   .. image:: img/9_rgb_set_bright_each.png

Votre GalaxyRVR s'illuminera maintenant de signaux colorés lorsqu'il se déplace, et pulsionnera doucement d'une lumière bleue respirante au repos !

Blocs liés au module RGB
------------------------

* Illumine votre GalaxyRVR de la couleur de votre choix.

  - Cliquez sur le patch de couleur pour choisir votre couleur préférée

  .. image:: img/block/rgb_display.png

* Illumine votre GalaxyRVR pendant une durée déterminée.

  - Choisissez une couleur
  - Définissez la durée d'allumage

  .. image:: img/block/rgb_display_1s.png

* Créez des couleurs personnalisées en mélangeant la lumière rouge, verte et bleue – idéal pour les projets de dégradé de couleurs !

  - R : Luminosité du rouge (0-255)
  - G : Luminosité du vert (0-255)
  - B : Luminosité du bleu (0-255)

  .. image:: img/block/rgb_display_RGB.png

* Affiche des couleurs RGB personnalisées pendant une durée définie.

  - Ajustez les valeurs de rouge, vert et bleu (0-255)
  - Définissez la durée d'affichage

  .. image:: img/block/rgb_display_RGB_1s.png

* Définit la luminosité des lumières (0-100 %).

  .. image:: img/block/rgb_set_brightness.png

* Rend les lumières plus vives ou plus tamisées. Utilisez des nombres négatifs pour diminuer la luminosité.

  .. image:: img/block/rgb_increase_brightness.png

* Allume ou éteint les lumières RGB.

  .. image:: img/block/rgb_turn_on.png
