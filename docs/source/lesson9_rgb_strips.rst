.. note::

    Bonjour, bienvenue dans la communauté des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Obtenez un accès anticipé aux nouvelles annonces de produits.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Leçon 9 : Illuminer la voie avec des bandes LED RGB
============================================================

Au cours de notre voyage jusqu'ici, nous avons transformé notre Rover martien en un explorateur intelligent, capable de manœuvrer habilement autour des obstacles. Il est devenu assez compétent pour naviguer sur les terrains semblables à ceux de Mars que nous avons mis en place pour lui.

Mais que diriez-vous d'ajouter une touche d'élégance à sa fonctionnalité ? Offrons à notre Rover la possibilité de s'exprimer à travers un spectacle de lumières et de couleurs. Nous allons intégrer des bandes LED RGB, une fonctionnalité cool qui permettra à notre Rover d'illuminer son chemin, même dans les conditions les plus sombres.

Imaginez ceci : le Rover laisse une traînée de signaux colorés, facilitant ainsi la compréhension de ses mouvements. Un halo vert lorsqu'il avance, un rouge intense lorsqu'il s'arrête, ou un jaune flashy pendant les virages rapides. Il pourrait même s'illuminer avec une gamme de couleurs, juste pour le plaisir !

Notre objectif dans cette leçon est de comprendre les principes des bandes LED RGB, d'apprendre à contrôler leurs couleurs et leur luminosité, puis de synchroniser cela avec les mouvements du Rover. À la fin, notre Rover martien ne sera plus seulement une machine, mais une entité lumineuse et changeante, guidant la voie dans le vaste paysage martien !

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/car_rgb.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::

    Si vous suivez ce cours après avoir entièrement assemblé le GalaxyRVR, vous devez déplacer cet interrupteur vers la droite avant de téléverser le code.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Objectifs
-------------

* Comprendre le fonctionnement et les applications des bandes LED RGB.
* Apprendre à utiliser la programmation Arduino pour contrôler la couleur et la luminosité des bandes LED RGB.
* S'entraîner à installer et utiliser des bandes LED RGB sur le modèle du Rover martien comme indicateurs.

Matériel nécessaire
-------------------------

* Bandes LED RGB (chaque bande comporte 8 LED RGB, soit un total de deux bandes)
* Outils et accessoires de base (par exemple : tournevis, vis, fils, etc.)
* Modèle de Rover martien (équipé d'un système rocker-bogie, de cartes principales, de moteurs, de modules d'évitement d'obstacles, et d'un module ultrasonique)
* Câble USB
* IDE Arduino
* Ordinateur

Étapes du cours
------------------
**Étape 1 : Installer les bandes LED RGB sur le Rover martien**

Fixez les deux bandes de lumières RGB sur les côtés inférieurs de la voiture. Elles sont contrôlées par un seul ensemble de broches, donc aucune différenciation n'est nécessaire lors du câblage.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/v4YGjNwPOJE" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Étape 2 : Explorer la magie des lumières avec les bandes LED RGB**

Vous souvenez-vous de la dernière fois que vous avez vu un arc-en-ciel ? Comment il remplissait le ciel de ses sept couleurs vibrantes ? Que diriez-vous de créer votre propre arc-en-ciel, ici même, dans notre petit Rover martien ? Plongeons dans la magie des lumières avec les bandes LED RGB !

.. image:: img/4_rgb_strip.jpg

Vous remarquerez peut-être que notre bande LED RGB comporte quatre broches marquées comme suit :

* **+5V** : C'est le « positif » commun ou l'« anode » des trois petites ampoules (LED) à l'intérieur de notre bande. Il doit être connecté à une alimentation DC de 5V, un peu comme le carburant qui alimente nos petites ampoules !
* **B** : C'est le « négatif » ou le « cathode » de la LED bleue.
* **R** : C'est le cathode de la LED rouge.
* **G** : C'est le cathode de la LED verte.

.. image:: img/rgb_5050.jpg

Vous souvenez-vous des trois couleurs primaires – le rouge, le bleu et le vert – que nous avons apprises en cours d'art ? Tout comme un artiste mélange ces couleurs sur sa palette pour créer de nouvelles nuances, notre bande contient 4 LEDs « 5050 » qui peuvent mélanger ces couleurs primaires pour créer pratiquement n'importe quelle couleur ! Chaque LED « 5050 » est comme un petit atelier d'art contenant ces trois ampoules colorées.

.. image:: img/rgb_5050_sche.png

Ces petits ateliers sont ensuite connectés de manière ingénieuse sur une carte de circuit flexible - un peu comme une mini-autoroute électrique ! Les pôles positifs de toutes les LEDs (anodes) sont connectés ensemble, tandis que les pôles négatifs (cathodes) sont connectés à leurs voies de couleur correspondantes (G pour G, R pour R, B pour B).

.. image:: img/rgb_strip_sche.png

Et le plus cool dans tout cela ? Avec notre commande, toutes les LEDs de cette bande peuvent changer de couleur en même temps ! C'est comme avoir notre propre orchestre de lumière à portée de main !

Préparez-vous à jouer une symphonie de lumière ! Dans notre prochaine étape, nous apprendrons à contrôler ces LEDs pour afficher les couleurs que nous voulons. Ce sera comme diriger un orchestre lumineux !


**Étape 3 : Allumer le spectacle – Programmation pour contrôler les bandes LED RGB**

Nous sommes entrés dans le royaume des couleurs, il est temps de donner vie à notre Rover martien. Préparez-vous à illuminer l'obscurité avec un spectre de couleurs en utilisant les bandes LED RGB. Imaginez cela comme une chance de transformer votre Rover en une véritable fête mobile !

* Avant de plonger dans la partie amusante, comprenons que bien que nous ayons deux bandes LED, elles sont toutes deux contrôlées par le même ensemble de broches. Pensez-y comme deux danseurs éblouissants bougeant en parfaite synchronisation !

    .. image:: img/rgb_shield.png

* Il est temps de faire appel à notre magie de la programmation. Nous allons initialiser nos broches avec le code Arduino.

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Définir les numéros de broche pour les bandes RGB
        const int bluePin = 11;
        const int redPin = 12;
        const int greenPin = 13;

* Avec nos broches en place, nous allons maintenant utiliser la fonction ``SoftPWMSet()`` pour contrôler ces broches. Pour que la bande RGB affiche du rouge, nous allumons la LED rouge et éteignons les autres.

    .. code-block:: arduino

        void setup() {
            // Initialiser le PWM logiciel sur toutes les broches
            SoftPWMBegin();
        }

        void loop() {
            // Régler la couleur sur rouge en allumant la LED rouge et en éteignant les autres
            SoftPWMSet(redPin, 255); // 255 est la luminosité maximale
            SoftPWMSet(greenPin, 0); // 0 est éteint
            SoftPWMSet(bluePin, 0);  // 0 est éteint
            delay(1000); // Attendre 1 seconde
        }

Dans le code ci-dessus, nous avons seulement montré comment afficher une seule couleur.

Si nous voulions afficher une variété de couleurs en utilisant cette méthode, le code pourrait devenir assez encombrant. Pour rendre notre code plus concis et facile à gérer, nous pouvons créer une fonction pour attribuer les valeurs PWM aux trois broches. Ensuite, dans la fonction ``loop()``, nous pourrons facilement définir une multitude de couleurs.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cac90501-04c1-44c2-a1d7-4f863e50f186/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléversé le code sur votre carte R3, vous constaterez peut-être que 
les couleurs orange et jaune semblent un peu fausses. C'est parce que la LED rouge 
de la bande est relativement faible par rapport aux deux autres. Vous devrez donc 
introduire des valeurs d'offset dans votre code pour corriger cette disparité.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/60ec867f-5637-44bd-b72d-4709fc4f5349/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Désormais, la bande LED RGB devrait pouvoir afficher les couleurs correctes. Si vous remarquez encore des écarts, vous pouvez ajuster manuellement les valeurs de ``R_OFFSET``, ``G_OFFSET`` et ``B_OFFSET``.

N'hésitez pas à expérimenter et à afficher la couleur de votre choix sur la bande LED. Il vous suffit de renseigner les valeurs RGB de la couleur que vous souhaitez.

Voici un conseil : vous pouvez utiliser l'outil Paint sur votre ordinateur pour déterminer les valeurs RGB de la couleur que vous désirez.

.. image:: img/rgb_paint.png

Maintenant que nous avons maîtrisé l'art de la configuration des couleurs, à l'étape suivante, nous allons intégrer ces superbes affichages aux mouvements du Rover martien. De beaux moments nous attendent !

**Étape 4 : Faire bouger le Rover avec des indications lumineuses**

Nous allons maintenant ajouter des indications lumineuses aux mouvements du Rover martien. Par exemple, nous pouvons utiliser le vert pour avancer, le rouge pour reculer et le jaune pour tourner à gauche ou à droite.

Pour ce faire, nous ajouterons un mécanisme de contrôle dans notre code qui définit la couleur de la bande LED en fonction des mouvements du Rover. Cela impliquera de modifier notre code de contrôle du Rover pour inclure nos fonctions de contrôle des couleurs.

Voyons un exemple de la manière dont nous pouvons procéder :

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/5412eebe-75b8-4f98-a348-f0889e8a7fde/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dans la fonction ``loop()``, nous avons ordonné au Rover d'effectuer une série 
d'actions en appelant différentes fonctions. Chaque action avait sa couleur 
correspondante - vert pour avancer, rouge pour reculer et jaune pour tourner. 
Cette fonction de contrôle des couleurs a été activée grâce à la fonction ``setColor()``, 
qui manipulait la luminosité de chaque canal de couleur RGB.

Pour l'action d'arrêt, nous avons introduit un élément engageant - un effet de 
respiration avec une lumière rouge et bleue. Cela a été réalisé en ajustant 
cycliquement la luminosité des canaux rouge et bleu dans la fonction ``stopMove()``. 
Ainsi, à l'arrêt, la bande LED passait du rouge au bleu, créant un effet visuel dynamique.

Désormais, notre Rover martien possède ses propres effets de couleurs vibrants, 
laissant derrière lui une traînée de signaux colorés, chacun représentant un mouvement unique.

Grâce à ce projet, nous avons découvert comment les matières STEAM peuvent 
s'unir pour donner vie à une machine ordinaire, la transformant en un outil 
d'apprentissage interactif, vibrant et amusant.


**Étape 5 : Résumé et réflexion**

Dans la leçon d'aujourd'hui, nous avons exploré le monde des bandes LED RGB et appris à les manipuler pour afficher une gamme de couleurs éclatantes. Ces couleurs ont donné un souffle nouveau à notre Rover martien, le transformant d'une simple machine en un véritable spectacle lumineux.

Maintenant, je vous invite à réfléchir : si c'était vous aux commandes, comment utiliseriez-vous ces couleurs pour améliorer votre Rover martien ? Quels effets uniques aimeriez-vous qu'il exhibe ?

De plus, à travers ce processus, j'espère que vous avez acquis une compréhension pratique de la manière dont divers concepts STEAM peuvent être intégrés dans un projet engageant, vous offrant une perspective plus large sur ses applications pratiques.

À très bientôt pour notre prochaine aventure passionnante !
