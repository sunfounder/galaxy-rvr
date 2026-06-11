.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message
.. _programming_scratch:

Programmation avec Scratch
============================

En plus de la programmation sur l'IDE Arduino, nous pouvons également utiliser la programmation graphique.

Nous vous recommandons d'utiliser Scratch pour la programmation.
Cependant, Scratch officiel ne prend actuellement en charge que Raspberry Pi. Pour résoudre ce problème, nous avons développé Mammoth Coding,
un logiciel de programmation graphique basé sur Scratch 3, spécifiquement pour les cartes Arduino (Uno, Mega2560 et Nano).

Mammoth Coding conserve les fonctionnalités de base de Scratch 3 tout en ajoutant la capacité de contrôler diverses cartes telles que Arduino Uno,
Mega, Nano et cartes personnalisées. Il vous permet d'utiliser des capteurs externes et des robots pour contrôler les sprites sur scène, offrant des capacités d'interaction matérielle robustes.

De plus, cette application est facile à utiliser même si vous n'avez pas beaucoup d'expérience en programmation. Vous pouvez apprendre et utiliser ces technologies de pointe en toute simplicité.

Faites simplement glisser et déposer des blocs de codage Scratch pour créer des jeux passionnants, des animations, des projets interactifs, et même contrôler des robots exactement comme vous l'imaginez !

Embarquons dès maintenant dans ce voyage d'exploration !


**Télécharger le code**


.. note::

    Tous les scripts Scratch pour les projets ci-dessous ont été téléchargés sur GitHub. Vous pouvez les télécharger via le lien fourni. Tous les fichiers de script ``.sb3`` se trouvent dans le dossier ``galaxy-rvr-main/scratch_codes/``.

   * |download_galaxyrvr_code|

Ou consultez le code sur `SunFounder GalaxyRVR Kit pour Arduino - GitHub <https://github.com/sunfounder/galaxy-rvr/tree/1.2>`_.


**Projets de base**

Ces projets sont les cours de base pour contrôler le GalaxyRVR avec Mammoth Coding. Ils vous guideront étape par étape sur la façon d'utiliser GalaxyRVR.

.. toctree::
    :maxdepth: 1


    sc1_history
    sc2_app
    sc3_rvr_move
    sc4_ultrasonic
    sc5_animate
    sc6_obstacle
    sc7_obstacle_animate
    sc8_avoid
    sc9_follow
    sc10_rgb
    sc11_servo
    sc12_camera
    sc13_all


**Projets amusants**

Voici quelques projets amusants qui ne nécessitent pas le Galaxy RVR, mais que vous pouvez réaliser ici.

.. toctree::
    :maxdepth: 1

    fun/sc_fun_balloon
    fun/sc_fun_flappy_parrot
    fun/sc_fun_shooting
    fun/sc_fun_eat_apple
    fun/sc_fun_fish
    fun/sc_fun_sensitive_ball
    fun/sc_fun_tap_tile