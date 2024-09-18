
.. note::

    Bonjour, et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et surmontez les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions lors des fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !


Leçon 10 Illuminer le chemin avec des bandes LED RVB
===============================================================

Au cours de notre exploration, nous avons transformé notre Rover martien en un explorateur intelligent, capable de contourner habilement les obstacles. Il est devenu très performant pour naviguer dans les terrains simulés de Mars que nous avons créés.

Mais que diriez-vous d'ajouter une touche d'élégance à sa praticité ? Donnons à notre Rover la capacité de s'exprimer à travers un spectacle de couleurs et de lumières. En intégrant des bandes LED RVB, nous pourrions permettre à notre Rover d'illuminer son chemin, même dans les conditions les plus sombres.

Imaginez cela : le Rover laisse une traînée de signaux colorés, facilitant ainsi la compréhension de ses mouvements. Un éclat vert lorsqu'il avance, un rouge vif lorsqu'il s'arrête, ou un jaune clignotant pendant qu'il effectue des virages rapides. Il pourrait même s'illuminer en une multitude de couleurs, juste pour le plaisir !

Notre objectif dans cette leçon est de comprendre les principes des bandes LED RVB, d'apprendre à contrôler leur couleur et leur luminosité, puis de synchroniser ces effets avec les mouvements du Rover. À la fin, notre Rover martien sera bien plus qu'une machine. Il deviendra un être lumineux et changeant de couleur, ouvrant la voie dans les vastes paysages martiens !

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/car_rgb.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

Objectif
-------------

* Introduire les principes de fonctionnement et les méthodes de contrôle des bandes LED RVB.
* Utiliser les bandes LED RVB avec Mammoth Coding pour réaliser des contrôles de couleurs et des effets lumineux simples.
* Créer un projet Mammoth Coding pour simuler des changements lumineux dans un environnement martien ou des feux de signalisation pour les missions d'exploration de Mars.

Matériel nécessaire
-------------------------

* Bande LED RVB et contrôleur
* Application Mammoth Coding
* Ordinateur ou tablette

Découvrez la magie des bandes LED RVB
-------------------------------------------------------------

Vous vous souvenez de la dernière fois que vous avez vu un arc-en-ciel ? Comment il rendait le ciel coloré avec ses sept teintes vibrantes ? Que diriez-vous de créer votre propre arc-en-ciel, ici même dans notre petit Rover martien ? Plongeons dans la magie de la lumière avec les bandes LED RVB !

.. image:: ../img/4_rgb_strip.jpg

Vous remarquerez peut-être que notre bande LED RVB comporte quatre broches, étiquetées comme suit :

* **+5V** : Il s'agit de l'extrémité commune "positive" ou de "l'anode" des trois petites ampoules (LED) à l'intérieur de notre bande. Elle doit être connectée à un courant continu de 5V pour alimenter nos petites ampoules !
* **B** : C'est l'extrémité "négative" ou la "cathode" de la LED bleue.
* **R** : C'est la cathode de la LED rouge.
* **G** : C'est la cathode de la LED verte.

.. image:: ../img/rgb_5050.jpg

Vous vous souvenez des trois couleurs primaires - Rouge, Bleu et Vert - que nous avons apprises en cours d'art ? Tout comme un artiste mélange ces couleurs sur sa palette pour créer de nouvelles nuances, notre bande contient des LED "5050" qui peuvent mélanger ces couleurs primaires pour créer presque n'importe quelle couleur ! Chaque LED "5050" est comme un petit atelier d'art qui héberge ces trois ampoules colorées.

.. image:: ../img/rgb_5050_sche.png

Ces petits ateliers d'art sont ensuite connectés de manière intelligente sur une carte de circuit flexible - un peu comme une autoroute électrique miniature ! Les extrémités "positives" de toutes les LED (anodes) sont connectées ensemble, tandis que les extrémités "négatives" (cathodes) sont reliées à leurs lignes de couleur correspondantes (G à G, R à R, B à B).

.. image:: ../img/rgb_strip_sche.png

Et la meilleure partie ? Sur commande, toutes les LED de cette bande peuvent changer de couleur en même temps ! C'est comme avoir notre propre orchestre de lumière au bout des doigts !

Illuminez le spectacle
------------------------------

1. Essayons d'illuminer le GalaxyRVR avec des couleurs ! Faites glisser un bloc "afficher couleur".

.. image:: img/9_rgb_block.png

2. Choisissez votre couleur préférée.

.. image:: img/9_rgb_color.png

3. Cliquez dessus, et vous verrez le GalaxyRVR s'illuminer dans la couleur correspondante.

**Utilisation de la scène pour contrôler GalaxyRVR**

Ensuite, créons un projet interactif pour nous familiariser avec les fonctions d'éclairage du GalaxyRVR. Nous cliquerons sur le sprite de la scène pour changer la couleur du GalaxyRVR.

1. Supprimez le sprite existant.

.. image:: img/6_animate_delete.png

2. Choisissez un sprite de balle. La raison de ce choix est qu'il a plusieurs costumes, chacun correspondant à une couleur différente.

.. image:: img/9_animate_rgb_ball.png

3. Faites glisser un bloc "quand ce sprite est cliqué", qui déclenche une action lorsque le sprite de la scène est cliqué.

.. image:: img/9_animate_rgb_when.png

4. Faites glisser un bloc "afficher" pour que le GalaxyRVR s'illumine.

.. image:: img/9_animate_rgb_display.png

5. Si vous utilisez un appareil à écran de petite taille, cliquez sur le bouton œil à côté pour vous assurer que la fenêtre d'aperçu de la scène est sur la même interface.

.. image:: img/9_animate_rgb_eye.png

6. Cliquez sur la couleur dans le bloc d'affichage. En bas de la fenêtre contextuelle, il y a un bouton de sélection de couleur. Cliquez dessus.

.. image:: img/9_animate_rgb_pick.png

7. Maintenez appuyé sur la zone de la scène. Une loupe apparaîtra à votre doigt pour sélectionner une couleur. 
Relâchez-la sur le sprite de la balle pour choisir sa couleur pour le bloc d'affichage.

.. image:: img/9_animate_rgb_pick_color_n.png

8. Appuyez longuement sur le sprite de la balle dans la scène pour le dupliquer.

.. image:: img/9_animate_rgb_duplicate.png

9. Dans l'interface des costumes, passez à la couleur suivante.

.. image:: img/9_animate_rgb_change_costume.png

10. Revenez à l'interface Code et sélectionnez la couleur pour correspondre au sprite actuel.

.. image:: img/9_animate_rgb_pick_blue.png

11. Répétez les étapes 8 à 10 jusqu'à ce que toutes les cinq couleurs soient définies.

.. image:: img/9_animate_rgb_ball5.png

Désormais, vous pouvez cliquer sur le sprite de la balle dans la zone de la scène pour faire s'illuminer le GalaxyRVR dans différentes couleurs.

.. _rgb_move:

Feux de signalisation du GalaxyRVR en action
----------------------------------------------------------------

**Feux de direction**

Maintenant que nous savons comment faire émettre des couleurs au GalaxyRVR, combinons cette fonction avec :ref:`rvr_move`.

1. Créez un nouveau projet.

2. Tout d'abord, configurez les blocs d'événements de touches et les blocs de mouvement pour les quatre directions.

.. image:: img/9_rgb_move.png

3. Ajoutez des affichages de couleur à chaque événement : vert pour avancer.

.. image:: img/9_rgb_green.png

4. Jaune pour tourner à gauche et à droite.

.. image:: img/9_rgb_yellow.png

5. Rouge pour reculer.

.. image:: img/9_rgb_red.png

Désormais, lorsque vous cliquerez sur les touches de direction dans la zone de la scène, vous verrez le GalaxyRVR se déplacer et s'illuminer dans la couleur correspondante.

**Lumière de respiration**

Une lumière de respiration est un effet où la lumière s'intensifie et s'atténue progressivement, semblable au rythme de la respiration. Ajoutons cet effet lorsque le GalaxyRVR est à l'arrêt.

1. Créez un nouveau message de diffusion nommé "stop". Cela indiquera à votre programme que le GalaxyRVR est en état d'arrêt.

.. image:: img/9_rgb_new_message.png

.. note:: Si votre sprite a de nombreuses actions à effectuer mais doit en commencer certaines à des moments précis ou dans des conditions spécifiques, le bloc de diffusion peut vous aider à gérer cela. De cette manière, votre sprite peut exécuter différentes actions dans l'ordre souhaité sans surcharger le code, le rendant plus clair et plus facile à comprendre.

2. Ajoutez cette diffusion après chaque événement de touche directionnelle.

.. image:: img/9_rgb_new_boardcast.png

3. Faites glisser un bloc "quand je reçois [stop]".

.. image:: img/9_rgb_when_receive.png

4. Réglez la luminosité à 0 %, en démarrant notre lumière de respiration à partir de 0 de luminosité.

.. image:: img/9_rgb_set_bright.png

5. Utilisez un bloc "répéter 10 fois" pour créer un changement progressif de luminosité. Ici, nous utilisons la lumière bleue, en augmentant la luminosité de 10 % toutes les 0,2 secondes.

.. image:: img/9_rgb_increase.png

6. Suivez-le avec un bloc pour diminuer la luminosité de 10 % toutes les 0,2 secondes, complétant ainsi un cycle de respiration.

.. image:: img/9_rgb_decrease.png

7. Diffusez à nouveau "stop" à la fin pour créer un effet de respiration continue.

.. image:: img/9_rgb_stopagain.png

8. Si vous contrôlez directement le GalaxyRVR à ce stade, vous remarquerez peut-être que les couleurs et la luminosité ne sont pas synchronisées. Par conséquent, ajoutez un bloc "arrêter les autres scripts dans le sprite" à la fin de chaque événement de touche directionnelle.

.. image:: img/9_rgb_stop.png

9. Comme les changements de luminosité se produisent dans l'événement "stop", réinitialisez la luminosité de la lumière dans chaque événement de touche.

.. image:: img/9_rgb_set_bright_each.png

Maintenant, lorsque vous appuierez sur les touches de direction sur la scène, le GalaxyRVR se déplacera et s'illuminera dans la couleur correspondante. Lorsqu'il s'arrêtera, il restera immobile et sa lumière "respirera" lentement.

Blocs liés au module RVB
-------------------------------

.. image:: img/block/rgb_display.png

Illuminez la bande RVB sous votre GalaxyRVR avec la couleur de votre choix. Vous pouvez :

    * Cliquer sur le patch de couleur pour sélectionner la couleur désirée.

.. image:: img/block/rgb_display_1s.png

Illuminez la bande RVB sous votre GalaxyRVR avec la couleur de votre choix pendant 1 seconde. Vous pouvez :

    * Cliquer sur le patch de couleur pour sélectionner la couleur désirée.
    * Modifier le nombre pour changer la durée de l'affichage lumineux.

.. image:: img/block/rgb_display_RGB.png

Illuminez la bande RVB sous votre GalaxyRVR avec une couleur de votre choix, en utilisant les valeurs RVB pour modifier la couleur (en ajustant la proportion des lumières rouges, vertes et bleues, vous pouvez produire n'importe quelle couleur), ce qui est très utile pour les projets impliquant des dégradés de couleurs. Vous pouvez :

    * Modifier la valeur R pour ajuster la luminosité de la lumière rouge, dans une plage de 0 à 255.
    * Modifier la valeur G pour ajuster la luminosité de la lumière verte, dans une plage de 0 à 255.
    * Modifier la valeur B pour ajuster la luminosité de la lumière bleue, dans une plage de 0 à 255.

.. image:: img/block/rgb_display_RGB_1s.png

Illuminez la bande RVB sous votre GalaxyRVR avec une couleur de votre choix pendant 1 seconde en utilisant les valeurs RVB. Vous pouvez :

    * Modifier la valeur R pour ajuster la luminosité de la lumière rouge, dans une plage de 0 à 255.
    * Modifier la valeur G pour ajuster la luminosité de la lumière verte, dans une plage de 0 à 255.
    * Modifier la durée pour changer la durée d'affichage de la lumière.

.. image:: img/block/rgb_set_brightness.png

Ce bloc est utilisé pour régler la luminosité des lumières, avec une plage de 0 à 100.

.. image:: img/block/rgb_increase_brightness.png

Ce bloc augmente (ou diminue) la luminosité des lumières. La valeur peut être négative.

.. image:: img/block/rgb_turn_on.png

Allumez (ou éteignez) la bande RVB sous votre GalaxyRVR.
