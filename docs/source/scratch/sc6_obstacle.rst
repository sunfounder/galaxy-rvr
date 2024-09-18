
.. note::

    Bonjour, et bienvenue dans la communauté SunFounder pour les passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et surmontez les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions lors des fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !



.. _ir_obstacle:


Leçon 6 Évitement d'obstacles avec IR
==========================================

Nous plongeons dans l'univers du module d'évitement d'obstacles à infrarouge. Placés sur les côtés de notre rover martien, ces capteurs jouent le rôle des "yeux" du rover, l'aidant à éviter les obstacles latéraux et à naviguer en toute sécurité sur le paysage martien.

Nous apprendrons à intégrer ces modules avec notre rover, à comprendre leur fonctionnement et à développer un code permettant à notre rover d'éviter intelligemment les obstacles.

Préparez-vous à équiper notre rover d'une intelligence martienne pour l'évitement d'obstacles ! C'est parti !


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_ir1.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Objectifs d'apprentissage
----------------------------

* Comprendre les principes de fonctionnement du module d'évitement d'obstacles à infrarouge et son application dans le rover martien.
* Apprendre à lire et à appliquer les données du module d'évitement d'obstacles à infrarouge dans Scratch.
* Créer un jeu d'évitement d'obstacles sur le thème de l'exploration martienne en utilisant le module IR et la scène Scratch.


Matériel
--------------

* Smartphone ou tablette
* Application Mammoth Coding
* GalaxyRVR

Démystifier le module
---------------------------------------

Voici le module d'évitement d'obstacles à infrarouge - le compagnon intelligent de notre rover. Ce petit appareil est un concentré de technologies. Faisons-en le tour :

.. image:: ../img/ir_avoid.png
    :width: 300
    :align: center


Voici les définitions des broches :

* **GND** : C'est comme l'ancre du module, le connectant à la masse ou au point commun du circuit.
* **+** : C'est ici que le module reçoit son énergie, nécessitant une alimentation de 3,3 à 5V DC.
* **Out** : C'est le communicant du module. Par défaut, il reste en état haut et ne passe à bas que lorsqu'il détecte un obstacle.
* **EN** : Voici le contrôleur du module. Cette broche **enable** décide quand le module doit fonctionner. Par défaut, elle est connectée à la masse (GND), ce qui signifie que le module est toujours actif.


Curieux de savoir comment ce petit module fonctionne ? C'est assez fascinant ! Il 
utilise une paire de composants IR - un émetteur et un récepteur. L'émetteur 
fonctionne comme une lampe torche, émettant de la lumière infrarouge. 
Lorsqu'un obstacle apparaît, la lumière infrarouge est réfléchie et captée par le 
récepteur. Le module émet alors un signal bas, avertissant notre rover de la présence 
de l'obstacle.

.. image:: ../img/ir_receive.png
    :align: center

Notre petit module est plutôt robuste, détectant les obstacles dans une plage de 2 à 
40 cm et disposant d'excellentes capacités anti-interférences. Cependant, la couleur 
des objets influence sa capacité de détection. Les objets plus sombres, en particulier 
les noirs, sont détectés à une distance plus courte. 
Face à un mur blanc, le capteur est le plus efficace, détectant dans une plage de 2 à 30 cm.


L'état bas de la broche **EN** active le module, le cavalier maintenant la broche **EN** connectée à la masse. Si vous souhaitez contrôler la broche **EN** par code, il faudra retirer le cavalier.

.. image:: ../img/ir_cap.png
    :width: 400
    :align: center

Le module possède deux potentiomètres, l'un pour ajuster la puissance d'émission et l'autre pour ajuster la fréquence d'émission. En ajustant ces deux potentiomètres, vous pouvez ajuster la distance de détection effective.

.. image:: ../img/ir_avoid_pot.png
    :width: 400
    :align: center 


Voilà pour notre petit module. À l'étape suivante, nous apprendrons comment l'intégrer à notre rover et le contrôler à l'aide de l'Arduino. Restez à l'écoute !



Valeurs de détection du module d'évitement d'obstacles à infrarouge
--------------------------------------------------------------------------

1. Allumez le GalaxyRVR.


.. raw:: html

   <br></br>

2. Nous arrivons à une étape essentielle, qui consiste à ajuster les distances de détection de nos capteurs en fonction de l'environnement actuel. Les paramètres d'usine peuvent ne pas être optimaux. Si la distance de détection des deux modules infrarouges est trop courte, le rover pourrait heurter des obstacles. Si elle est trop longue, le rover pourrait commencer à tourner alors qu'il est encore loin de l'obstacle, ce qui pourrait affecter son mouvement.

    Voici comment faire les ajustements :

    a. Commencez par ajuster le module d'évitement d'obstacles droit. Pendant le transport, des collisions peuvent avoir incliné l'émetteur et le récepteur sur le module infrarouge. Vous devrez donc les redresser manuellement.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    b. Placez un obstacle à environ 20 cm directement devant le module droit. La boîte dans laquelle notre kit Rover est arrivé est un bon choix pour cela ! Maintenant, tournez le potentiomètre sur le module jusqu'à ce que la lumière indicatrice du module s'allume. Ensuite, déplacez l'obstacle d'avant en arrière pour vérifier si la lumière indicatrice s'allume à la distance souhaitée. Si la lumière ne s'allume pas à la bonne distance ou reste allumée sans s'éteindre, vous devrez ajuster l'autre potentiomètre.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>


    c. Répétez le même processus pour l'autre module.



3. Voyons maintenant ce que sont ces deux signaux. Tout d'abord, :ref:`app_connect`.

.. raw:: html

   <br></br>


4. Dans la catégorie GalaxyRVR, trouvez les blocs "état IR gauche" et "état IR droit". Ces blocs stockent les résultats de détection des modules IR. Assurez-vous de cocher les cases pour ces blocs.

    .. image:: img/4_ir_statusblock.png

5. Les valeurs s'afficheront maintenant sur la scène.

    .. image:: img/4_ir_statusvalue.png

6. Approchez votre main des modules d'évitement d'obstacles à infrarouge pour déclencher la détection et observer les changements de valeur sur la scène.

Si les modules IR détectent un obstacle, la valeur sera Vrai ; s'ils ne détectent rien, la valeur sera Faux.



Réagir au module d'évitement d'obstacles à infrarouge
-------------------------------------------------------------

Nous pouvons utiliser les modules d'évitement d'obstacles à infrarouge pour que le GalaxyRVR évite automatiquement les obstacles sur les deux côtés.


1. Faites glisser un bloc drapeau vert

.. image:: img/4_ir_start.png

2. Réglez la vitesse. Ici, nous la réglons à 30 % pour que ce ne soit pas trop rapide, facilitant ainsi le débogage.

.. image:: img/4_ir_speed.png


3. Trouvez le bloc ``quand l'IR gauche est bloqué``.

.. image:: img/4_ir_when_blocked.png

4. Lorsque le côté gauche détecte un obstacle, le GalaxyRVR doit tourner à droite.

.. image:: img/4_ir_turn_right.png

5. Continuez à tourner à droite jusqu'à ce que le côté gauche ne détecte plus l'obstacle.

.. image:: img/4_ir_wait_until.png


6. Arrêtez-vous.

.. image:: img/4_ir_stop.png


7. Une fois ces blocs assemblés, essayez de déclencher le module d'évitement d'obstacles à infrarouge gauche avec votre main. Le GalaxyRVR tournera intelligemment à droite pour éviter votre main.

.. raw:: html

   <br></br>



8. Maintenez ces blocs enfoncés pour faire apparaître un menu, où vous pourrez dupliquer le code.

.. image:: img/4_ir_duplicate.png

9. Dans le code dupliqué, échangez les côtés gauche et droit.

.. image:: img/4_ir_left_right.png

10. Vous remarquerez que si les deux événements IR sont déclenchés simultanément, le comportement peut devenir erratique. Pour éviter cela, le bloc "arrêter les autres scripts dans le sprite" sera utile. Il garantit qu'un seul événement capteur est traité à la fois.

.. image:: img/4_ir_stop_script.png

.. note:: Le bloc d'arrêt des scripts et les blocs avec des paramètres de temps (par exemple, avancer pendant 1 seconde) peuvent entrer en conflit dans certains cas, donc évitez de les utiliser ensemble autant que possible.


11. Maintenant, le GalaxyRVR tournera à gauche ou à droite lorsque des obstacles seront détectés de chaque côté. Vous pouvez tester cela en déclenchant les deux capteurs avec votre main pour que le GalaxyRVR évite les obstacles à gauche et à droite.


.. raw:: html

   <br></br>


12. Ajoutez un bloc avancer sous chaque bloc de code pour que le GalaxyRVR continue d'avancer après avoir évité l'obstacle.

.. image:: img/4_ir_avoid_move.png


Maintenant, cliquez sur le drapeau vert, et le GalaxyRVR avancera en continu, tournant pour éviter les obstacles puis reprenant sa route après les avoir évités.



Blocs liés au module IR
----------------------------------------

.. image:: img/block/ir_when.png

Voici un bloc événement déclenché lorsque le capteur IR gauche détecte un obstacle. Vous pouvez :

    * Changer "gauche" en "droite" dans le menu déroulant

.. image:: img/block/ir_wait_until.png

Ce bloc met le programme en pause jusqu'à ce que le capteur IR gauche ne détecte plus d'obstacle, puis continue. Vous pouvez :

    * Changer "gauche" en "droite" dans le premier menu déroulant
    * Changer "n'est pas" en "est" dans le deuxième menu déroulant pour opérer dans la condition opposée

.. image:: img/block/ir_condition.png

Ceci est un bloc conditionnel qui renvoie VRAI si le capteur IR gauche détecte un obstacle, sinon FAUX. Il est couramment utilisé dans les blocs nécessitant des conditions comme ``si``. Vous pouvez :

    * Changer "gauche" en "droite" dans le menu déroulant

.. image:: img/block/ir_left_value.png

Ce bloc affiche si le capteur IR gauche détecte actuellement un obstacle.

.. image:: img/block/ir_right_value.png

Ce bloc affiche si le capteur IR droit détecte actuellement un obstacle.

