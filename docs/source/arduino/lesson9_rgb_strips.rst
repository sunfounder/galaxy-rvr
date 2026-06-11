.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 9 : Illuminer le chemin avec des bandes LED RGB
=====================================================

Au fil de notre aventure, nous avons transformé notre Mars Rover en un véritable explorateur intelligent, capable d’éviter habilement les obstacles. Il est désormais très à l’aise pour se déplacer sur les terrains martiens que nous avons recréés.

Mais si nous pouvions ajouter une touche de style à toutes ces fonctionnalités ?

Donnons à notre Rover la capacité de s’exprimer à travers un spectacle de couleurs et de lumière. Pour cela, nous allons intégrer des bandes LED RGB, une fonctionnalité amusante qui permettra à notre Rover d’éclairer son chemin, même dans les environnements les plus sombres.

Imaginez un instant : le Rover laisse derrière lui des signaux lumineux colorés qui nous aident à comprendre ce qu’il fait. Une lueur verte lorsqu’il avance, un rouge vif lorsqu’il s’arrête, ou encore un jaune clignotant lorsqu’il effectue un virage rapide. Il pourra même afficher toute une palette de couleurs simplement pour le plaisir !

L’objectif de cette leçon est de comprendre le fonctionnement des bandes LED RGB, d’apprendre à contrôler leur couleur et leur luminosité, puis de synchroniser leurs effets lumineux avec les mouvements du Rover.

À la fin de cette leçon, notre Mars Rover sera bien plus qu’une simple machine. Il deviendra un explorateur lumineux et multicolore, guidant son chemin à travers les vastes paysages martiens !

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/car_rgb.mp4" type="video/mp4">
        Votre navigateur ne prend pas en charge la lecture de vidéos HTML5.
    </video>

.. note::

    Si vous suivez ce cours après avoir entièrement assemblé le GalaxyRVR, vous devez déplacer cet interrupteur vers la droite avant de téléverser le programme.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Objectifs
-------------

* Comprendre le principe de fonctionnement et les applications des bandes LED RGB.
* Apprendre à utiliser la programmation Arduino pour contrôler la couleur et la luminosité des bandes LED RGB.
* S’exercer à installer et utiliser des bandes LED RGB sur le modèle de Mars Rover comme indicateurs lumineux.

Matériel nécessaire
-------------------------

* Bandes LED RGB (chaque bande comporte 8 LED RGB, soit deux bandes au total)
* Outils et accessoires de base (tournevis, vis, câbles, etc.)
* Modèle de Mars Rover (équipé du système rocker-bogie, des cartes principales, des moteurs, du module d’évitement d’obstacles et du module à ultrasons)
* Câble USB
* Arduino IDE
* Un ordinateur

Étapes du cours
------------------

**Étape 1 : Installer les bandes LED RGB sur le Mars Rover**

Fixez maintenant les deux bandes LED RGB sous les côtés du Rover. Les deux bandes sont contrôlées par le même ensemble de broches ; il n’est donc pas nécessaire de les distinguer lors du câblage.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/v4YGjNwPOJE" title="Lecteur vidéo YouTube" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Étape 2 : Découvrir la magie de la lumière avec les bandes LED RGB**

Vous souvenez-vous de la dernière fois où vous avez vu un arc-en-ciel ? Comment il remplissait le ciel de couleurs éclatantes ?

Et si nous pouvions créer notre propre arc-en-ciel directement sur notre petit Rover martien ?

Plongeons ensemble dans la magie des bandes LED RGB !

.. image:: img/4_rgb_strip.jpg

Vous remarquerez que notre bande LED RGB possède quatre broches identifiées comme suit :

* **+5V** : c’est la borne positive commune, également appelée « anode », des trois petites LED présentes dans chaque module RGB. Elle doit être reliée à une alimentation de 5 V qui fournit l’énergie nécessaire aux LED.
* **B** : c’est la borne négative (« cathode ») de la LED bleue.
* **R** : c’est la cathode de la LED rouge.
* **G** : c’est la cathode de la LED verte.

.. image:: img/rgb_5050.jpg

Vous souvenez-vous des trois couleurs primaires de la lumière : rouge, vert et bleu ?

Tout comme un artiste mélange ces couleurs sur sa palette pour créer de nouvelles teintes, notre bande LED contient quatre LED « 5050 » capables de combiner ces trois couleurs afin de produire pratiquement n’importe quelle couleur imaginable !

Chaque LED « 5050 » est comme un mini atelier artistique contenant trois petites sources lumineuses : une rouge, une verte et une bleue.

.. image:: img/rgb_5050_sche.png

Ces mini ateliers lumineux sont reliés intelligemment sur un circuit flexible, un peu comme un réseau de routes électriques.

Les bornes positives (anodes) de toutes les LED sont connectées ensemble, tandis que les bornes négatives (cathodes) sont regroupées par couleur : toutes les broches vertes ensemble, toutes les rouges ensemble et toutes les bleues ensemble.

.. image:: img/rgb_strip_sche.png

Et le plus impressionnant ?

Avec une seule commande, toutes les LED de la bande peuvent changer de couleur simultanément !

C’est comme si nous avions un véritable orchestre lumineux au bout des doigts.

Préparons-nous donc à jouer notre première symphonie de lumière ! Dans l’étape suivante, nous apprendrons à contrôler ces LED pour afficher les couleurs de notre choix.

**Étape 3 : Allumer le spectacle — Programmer les bandes LED RGB**

Nous avons exploré le monde des couleurs ; il est maintenant temps de donner vie à notre Mars Rover.

Préparez-vous à illuminer l’obscurité avec tout un éventail de couleurs grâce aux bandes LED RGB. Considérez cela comme l’occasion de transformer votre Mars Rover en une véritable discothèque mobile !

* Avant de commencer, il est important de comprendre que même si nous utilisons deux bandes LED, elles sont toutes deux contrôlées par le même ensemble de broches. Imaginez deux danseurs parfaitement synchronisés qui exécutent exactement les mêmes mouvements !

    .. image:: img/rgb_shield.png

* Il est maintenant temps de faire appel à notre magie de programmation. Nous allons commencer par définir les broches utilisées dans notre programme Arduino.

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Définition des broches utilisées pour les bandes RGB
        const int bluePin = 11;
        const int redPin = 12;
        const int greenPin = 13;

* Une fois les broches configurées, nous utiliserons la fonction ``SoftPWMSet()`` pour les contrôler. Pour afficher la couleur rouge sur la bande LED RGB, il suffit d’allumer la LED rouge tout en éteignant les deux autres couleurs.

    .. code-block:: arduino

        void setup() {
            // Initialize software-based PWM on all pins
            SoftPWMBegin();
        }

        void loop() {
            // Set the color to red by turning the red LED on and the others off
            SoftPWMSet(redPin, 255); // 255 is the maximum brightness
            SoftPWMSet(greenPin, 0); // 0 is off
            SoftPWMSet(bluePin, 0);  // 0 is off
            delay(1000); // Wait for 1 second
        }

Dans l'exemple précédent, nous avons seulement montré comment afficher une seule couleur.

Si nous voulions afficher de nombreuses couleurs en utilisant cette méthode, le programme deviendrait rapidement long et difficile à maintenir. Pour rendre notre code plus clair et plus facile à réutiliser, nous pouvons créer une fonction qui attribue des valeurs PWM aux trois broches RGB. Ainsi, dans la fonction ``loop()``, il suffira de définir les couleurs souhaitées de manière simple et élégante.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cac90501-04c1-44c2-a1d7-4f863e50f186/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléversé le programme sur votre carte R3, vous remarquerez peut-être que les couleurs orange et jaune ne correspondent pas exactement à ce que vous attendiez.

Cela s'explique par le fait que la LED rouge de la bande est légèrement moins lumineuse que les LED verte et bleue. Pour corriger cette différence, nous devons appliquer des valeurs de compensation directement dans le programme.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/60ec867f-5637-44bd-b72d-4709fc4f5349/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Désormais, la bande LED RGB devrait afficher des couleurs beaucoup plus fidèles. Si vous constatez encore de légères différences, vous pouvez ajuster manuellement les valeurs de ``R_OFFSET``, ``G_OFFSET`` et ``B_OFFSET`` jusqu'à obtenir le résultat souhaité.

N'hésitez pas à expérimenter et à afficher les couleurs de votre choix sur la bande LED. Il vous suffit d'indiquer les valeurs RGB correspondant à la couleur désirée.

Petite astuce : vous pouvez utiliser l'application **Paint** de votre ordinateur pour déterminer facilement les valeurs RGB d'une couleur.

.. image:: img/rgb_paint.png

Maintenant que nous maîtrisons l'art de créer et de contrôler les couleurs, nous allons passer à l'étape suivante : synchroniser ces effets lumineux avec les mouvements du Mars Rover. Les choses deviennent vraiment intéressantes !

**Étape 4 : Déplacer le Rover avec des indications lumineuses**

Nous allons maintenant associer différentes couleurs aux mouvements du Mars Rover.

Par exemple :

* Vert pour avancer
* Rouge pour reculer
* Jaune pour tourner à gauche ou à droite

Pour cela, nous allons ajouter dans notre programme un mécanisme de contrôle qui modifie la couleur de la bande LED en fonction du mouvement effectué par le Rover.

Cela implique simplement d'intégrer nos fonctions de gestion des couleurs dans le programme de contrôle du Rover.

Voyons un exemple :

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/5412eebe-75b8-4f98-a348-f0889e8a7fde/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dans la fonction ``loop()``, nous demandons au Rover d'exécuter une série d'actions en appelant différentes fonctions.

Chaque action possède sa propre couleur associée :

* Vert pour avancer
* Rouge pour reculer
* Jaune pour tourner

Cet affichage lumineux est rendu possible grâce à la fonction ``setColor()``, qui contrôle individuellement la luminosité des canaux rouge, vert et bleu de la bande LED RGB.

Pour l'action d'arrêt, nous avons ajouté un effet visuel plus élaboré : un effet de respiration lumineux alternant entre le rouge et le bleu.

Cet effet est obtenu en modifiant progressivement la luminosité des canaux rouge et bleu dans la fonction ``stopMove()``.

Lorsque le Rover s'arrête, la bande LED passe donc en douceur du rouge au bleu puis revient au rouge, créant ainsi une animation lumineuse dynamique et attrayante.

Notre Mars Rover dispose désormais de ses propres effets lumineux personnalisés, laissant derrière lui une série de signaux colorés qui reflètent chacun de ses mouvements.

À travers ce projet, nous avons découvert comment différentes disciplines STEAM peuvent se combiner pour donner vie à une machine autrement ordinaire, en la transformant en un outil d'apprentissage interactif, dynamique et amusant.

**Étape 5 : Résumé et réflexion**

Dans cette leçon, nous avons exploré l'univers des bandes LED RGB et appris à les contrôler pour afficher une grande variété de couleurs éclatantes.

Ces effets lumineux ont apporté une nouvelle dimension à notre Mars Rover, le transformant d'une simple machine en un véhicule coloré et expressif.

Prenez maintenant un moment pour réfléchir :

* Si vous étiez le concepteur du Rover, comment utiliseriez-vous les couleurs pour améliorer son comportement ?
* Quels effets lumineux originaux aimeriez-vous lui ajouter ?

J'espère également que cette activité vous a permis de mieux comprendre comment différents concepts STEAM peuvent être combinés au sein d'un même projet afin de créer des réalisations à la fois utiles, créatives et passionnantes.

À très bientôt pour notre prochaine aventure !
