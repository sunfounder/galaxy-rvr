.. note::

    Bonjour et bienvenue dans la communauté SunFounder pour les passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, d'Arduino et d'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Soyez parmi les premiers à découvrir les nouvelles annonces de produits et obtenez des avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !


Leçon 6 : Explorer le Module d'Évitement d'Obstacles
==============================================================

Plongeons dans le monde du module d'évitement d'obstacles à infrarouge. Placés sur les côtés de notre rover martien, ces capteurs agissent comme les "yeux" du rover, l'aidant à éviter les obstacles latéraux et à naviguer en toute sécurité sur le paysage martien.

Nous allons apprendre à intégrer ces modules avec notre rover, découvrir le fonctionnement qui se cache derrière leur magie, et développer du code pour permettre à notre rover d'éviter intelligemment tous les obstacles qu'il rencontre.

Préparez-vous à équiper notre rover d'une intelligence martienne capable de déjouer les obstacles ! En avant !

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_ir1.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. note::

    Si vous suivez ce cours après avoir entièrement assemblé le GalaxyRVR, vous devez déplacer cet interrupteur vers la droite avant de téléverser le code.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Objectifs d'apprentissage
---------------------------

* Comprendre le principe de fonctionnement et l'application du module d'évitement d'obstacles à infrarouge.
* Apprendre à utiliser Arduino pour contrôler le module d'évitement d'obstacles à infrarouge.
* S'exercer à concevoir et construire un système d'évitement d'obstacles automatique basé sur l'infrarouge.


Matériel nécessaire
----------------------

* Modules d'évitement d'obstacles
* Outils de base et accessoires (tournevis, vis, fils, etc.)
* Modèle de Rover martien (équipé du système Rocker-Bogie, cartes principales, moteurs)
* Câble USB
* IDE Arduino
* Ordinateur


Étapes
---------

**Étape 1 : Installer le Module d'Évitement d'Obstacles**

Nous allons maintenant installer les deux modules d'évitement d'obstacles sur le rover.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/UWEj_ROYAt0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Les étapes d'assemblage étaient simples, n'est-ce pas ? Dans les prochaines étapes, nous allons découvrir le principe de fonctionnement de ces modules et comment ils aident notre rover martien à éviter les obstacles. Restez à l'écoute !


**Étape 2 : Démystifier le Module**

Voici le module d'évitement d'obstacles à infrarouge - l'assistant intelligent de notre rover. Ce petit appareil est un concentré de technologies. Faisons un tour :

.. image:: img/ir_avoid.png
    :width: 300
    :align: center

Voici les définitions des broches :

* **GND** : C'est comme l'ancre du module, le connectant à la masse ou au point commun dans le circuit.
* **+** : C'est ici que le module reçoit son énergie, nécessitant une alimentation de 3,3 à 5V DC.
* **Out** : C'est le communicateur du module. Par défaut, il reste en position haute et ne passe en basse que lorsqu'il détecte un obstacle.
* **EN** : Voici le contrôleur du module. Cette broche d'**activation** décide quand le module doit fonctionner. Par défaut, elle est connectée à la masse (GND), ce qui signifie que le module est toujours en action.

Curieux de savoir comment fonctionne ce petit module ? C'est plutôt fascinant ! 
Il utilise une paire de composants infrarouges - un émetteur et un récepteur. 
L'émetteur agit comme une lampe de poche du module, émettant de la lumière infrarouge. 
Lorsque qu'un obstacle apparaît, la lumière infrarouge rebondit et est captée par le 
récepteur. Le module envoie alors un signal bas, alertant notre rover de la présence d'un obstacle.

.. image:: img/ir_receive.png
    :align: center

Ce petit module est très performant, détectant les obstacles dans un rayon de 2 à 40 cm, et possède d'excellentes capacités anti-interférences. 
Cependant, la couleur des objets influence sa détection. Les objets plus sombres, en particulier les noirs, sont détectés à une distance plus courte. 
Face à un mur blanc, le capteur est plus efficace, avec une détection dans une plage de 2 à 30 cm.

La broche **EN** en position basse active le module, avec le capuchon de cavalier reliant la broche **EN** à la masse. Si vous souhaitez contrôler la broche **EN** via le code, le cavalier doit être retiré.

.. image:: img/ir_cap.png
    :width: 400
    :align: center

Le module possède deux potentiomètres, l'un pour ajuster la puissance d'émission et l'autre pour ajuster la fréquence d'émission. En ajustant ces deux potentiomètres, vous pouvez ajuster la distance de détection.

.. image:: img/ir_avoid_pot.png
    :width: 400
    :align: center 

C'est tout pour notre petit module. Dans la prochaine étape, nous apprendrons comment l'intégrer à notre rover et le contrôler à l'aide d'Arduino. Restez avec nous !

**Étape 3 : Lire les Données des 2 Modules**

Comme des explorateurs curieux, plongeons dans l'univers des codes et des capteurs !

#. Notre rover martien est équipé de deux capteurs spéciaux "Alien-Eye", fixés aux broches 7 (droite) et 8 (gauche). Ces capteurs sont en fait nos modules d'évitement d'obstacles à infrarouge, toujours vigilants pour éviter tout "rocher spatial" (obstacle) sur le parcours interstellaire de notre rover !

    .. image:: img/ir_shield.png

#. Ensuite, nous devons communiquer avec notre rover en utilisant le langage universel du code Arduino.

    Commençons par donner un nom unique à chaque œil du rover. Appelons-les ``IR_DROIT`` et ``IR_GAUCHE``, pour ne pas les confondre.

        .. code-block:: arduino

            #define IR_RIGHT 7
            #define IR_LEFT 8

    Ensuite, faisons savoir à notre rover que ce sont ses yeux spéciaux - ils transmettront des informations du monde extérieur au cerveau électronique du rover.

        .. code-block:: arduino

            pinMode(IR_RIGHT, INPUT);
            pinMode(IR_LEFT, INPUT);

    Pour nous assurer que notre rover partage ses découvertes avec nous, nous établissons une ligne de communication secrète, comme des espions dans un film de science-fiction. Cette prochaine ligne lance une conversation série à la vitesse de 9600 bits par seconde - c'est une discussion ultra rapide !

        .. code-block:: arduino

            Serial.begin(9600);

    Maintenant, notre rover scanne ses environs avec ses "Alien-Eyes" et nous transmet ses découvertes. S'il détecte un obstacle, la valeur sera 0 ; si le chemin est dégagé, la valeur sera 1. Il continue d'envoyer ces messages, nous tenant informés.

        .. code-block:: arduino

            int rightValue = digitalRead(IR_RIGHT);
            int leftValue = digitalRead(IR_LEFT);
            Serial.print("Right IR: ");
            Serial.println(rightValue);
            Serial.print("Left IR: ");
            Serial.println(leftValue);

    Enfin, le rover marque une pause (environ 200 millisecondes) après chaque transmission. Cette petite pause nous donne le temps d'interpréter le message du rover avant qu'il n'envoie un autre.

        .. code-block:: arduino

            delay(200);

    Voici le code complet :

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/98546821-5f4b-42ae-bc9f-e7ec15544c8b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Une fois votre code prêt, sélectionnez la bonne carte et le bon port, et téléchargez le code vers votre rover martien. Ensuite, ouvrez la ligne de communication secrète (le moniteur série) en cliquant sur son icône en haut à droite.

    .. image:: img/ir_open_serial.png

#. Avant de commencer à recevoir les messages du rover, assurez-vous que votre ligne de communication est réglée à la même vitesse (9600 bauds) que celle de votre rover. Et voilà - des mises à jour en direct de votre rover martien !

    .. image:: img/ir_serial.png

#. Pour tester notre système, agitez un "rocher spatial" (votre main) devant l'un des capteurs. Vous verrez la valeur passer à 0, et la LED correspondante sur le module s'allume. Le rover dit alors : "Attention, rocher spatial à droite !"

    .. code-block::

        Right IR: 0
        Left IR: 1
        Right IR: 0
        Left IR: 1
        Right IR: 0
        Left IR: 1

Vous avez maintenant non seulement parcouru l'espace, mais aussi décrypté le langage martien ! Nous avons hâte de découvrir quels autres secrets interstellaires nous révélera notre prochaine mission !

**Étape 4 : Ajuster la Distance de Détection**

Nous arrivons à une étape essentielle : ajuster les distances de détection de nos capteurs en fonction de l'environnement. Les réglages d'usine peuvent ne pas être optimaux.

Si la distance de détection des deux modules infrarouges est trop courte, le rover pourrait percuter des obstacles. Si elle est trop longue, le rover pourrait commencer à tourner alors qu'il est encore loin d'un obstacle, ce qui pourrait affecter son déplacement.

Voici comment procéder aux ajustements :

#. Commencez par ajuster le module d'évitement d'obstacles droit. Lors du transport, des collisions peuvent provoquer l'inclinaison de l'émetteur et du récepteur du module infrarouge. Vous devez donc les redresser manuellement.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Placez un obstacle à environ 20 cm devant le module droit. La boîte dans laquelle se trouvait notre kit de rover est un bon choix ! Maintenant, tournez le potentiomètre sur le module jusqu'à ce que le voyant sur le module s'allume juste. Ensuite, déplacez l'obstacle d'avant en arrière pour vérifier si le voyant s'allume à la distance souhaitée. Si le voyant ne s'allume pas à la bonne distance ou reste allumé sans s'éteindre, vous devrez ajuster l'autre potentiomètre.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Répétez le même processus pour l'autre module.

Maintenant que nos capteurs sont pleinement opérationnels, passons à la prochaine étape de notre voyage !

**Étape 5 : Concevoir un Système d'Évitement d'Obstacles Automatique**

Maintenant, faisons un grand bond dans notre exploration spatiale et utilisons les informations fournies par le rover. 
Nous allons créer un système d'évitement d'obstacles automatique !

Voici notre plan : Si le capteur droit détecte un obstacle, le rover tournera vers l'arrière droit. Si le capteur gauche détecte un obstacle, le rover tournera vers l'arrière gauche. Si les deux capteurs détectent un obstacle, le rover reculera. Si aucun obstacle n'est détecté, le rover continuera tout droit.

Visualisons cela dans un organigramme pour rendre tout cela encore plus clair. 
Les organigrammes sont un excellent moyen de structurer un plan de manière logique, 
surtout en programmation !

.. image:: img/ir_flowchart.png

Chuchotons ce plan à notre rover dans son langage (le code Arduino) :

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/af6539d4-7b4b-4e74-a04a-9fa069391d4d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dans ce code, nous utilisons l'instruction ``if...else`` dans la fonction ``loop()``.

    L'instruction ``if...else`` est utilisée pour exécuter un bloc de code parmi deux alternatives. 
    Cependant, lorsque nous devons choisir parmi plus de deux alternatives, nous utilisons l'instruction ``if...else if...else``.

    La syntaxe de l'instruction ``if...else if...else`` est :

    .. code-block:: arduino

        if (condition1) {
        // code block 1
        }
        else if (condition2){
        // code block 2
        }
        else if (condition3){
        // code block 3
        }
        else {
        // code block 4
        }
    
    Here,

    * If condition1 is true, code block 1 is executed.
    * If condition1 is false, then condition2 is evaluated.
    * If condition2 is true, code block 2 is executed.
    * If condition2 is false, then condition3 is evaluated.
    * If condition3 is true, code block 3 is executed.
    * If condition3 is false, code block 4 is executed.

Maintenant que nous avons conçu notre système d'évitement d'obstacles automatique, passons à la partie la plus excitante - le test en conditions réelles !

* Observez si le rover se déplace comme vous l'avez prévu.
* Ou placez-le dans différentes conditions d'éclairage pour voir comment ses mouvements changent.

En intégrant la science à notre projet d'ingénierie, nous devenons des détectives de l'espace, résolvant les mystères du comportement de notre rover. 
Il ne s'agit pas seulement de corriger des erreurs, mais d'optimiser la performance, en rendant notre rover aussi performant que possible ! Continuez votre excellent travail, détectives de l'espace !


**Étape 6 : Réflexion et Résumé**

Pendant la phase de test, vous avez peut-être remarqué un comportement intéressant de notre rover martien : alors qu'il évite habilement les obstacles à sa gauche et à sa droite, il peut avoir des difficultés à détecter les petits obstacles situés directement devant lui.

Comment pourrions-nous résoudre ce problème ?

Restez à l'écoute pour la prochaine leçon, où nous continuerons à explorer le monde fascinant du codage, des capteurs et de la détection d'obstacles.

N'oubliez pas, chaque défi est une opportunité d'apprentissage et d'innovation. Et alors que nous poursuivons notre voyage d'exploration spatiale, il y a encore tellement plus à découvrir et à apprendre !
