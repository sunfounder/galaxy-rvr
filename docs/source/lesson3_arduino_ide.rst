.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez-vous dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Soyez parmi les premiers à découvrir les nouvelles annonces de produits et à bénéficier d'aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et concours** : Participez à des concours et à des promotions pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Leçon 3 : Entrer dans le Monde de l'Arduino et du Codage
==============================================================

Lors de notre précédente leçon, nous avons construit avec succès le système de suspension Rocker-Bogie. 
Cependant, pour le rendre fonctionnel, nous devons lui fournir de l'énergie, une carte de contrôle et le programmer pour dicter ses mouvements.

Dans cette leçon, nous allons nous familiariser avec la carte de contrôle et la plateforme de programmation que nous allons utiliser.

.. image:: img/upload_blink.gif

Objectifs du cours
----------------------

* Comprendre les concepts de base et les fonctions d'Arduino.
* Découvrir la carte SunFounder R3.
* Installer l'IDE Arduino et se familiariser avec son interface.
* Apprendre les règles de base de la syntaxe de la programmation Arduino.



Matériel du cours
--------------------

* Carte SunFounder R3
* IDE Arduino
* Câble USB
* Ordinateur

Introduction à Arduino
------------------------------------------

Vous avez peut-être souvent entendu le terme "Arduino" dans différents contextes, mais qu'est-ce que c'est exactement et pourquoi est-il devenu si populaire ?

Arduino est une plateforme électronique open-source facile à utiliser, tant pour les applications matérielles que logicielles. Elle est conçue pour créer des dispositifs numériques et des objets interactifs qui peuvent percevoir et contrôler le monde physique qui les entoure.

Démystifions tout cela :

* **Open-source** : Imaginez l'open-source comme un jardin communautaire. Tout le monde peut l'utiliser, y contribuer et en bénéficier. Avec l'open-source, les conceptions des pièces physiques (le matériel) et les instructions de programmation (le logiciel) sont partagées librement. Cela signifie que chacun peut les utiliser, les améliorer ou créer ses propres versions. Il s'agit de partage et de créativité !

    .. image:: img/arduino_oscomm.png
        :width: 400
        :align: center

* **Microcontrôleur** : Un microcontrôleur est comme le cerveau de l'Arduino. C'est un petit ordinateur capable d'exécuter des logiciels simples. Bien qu'il ne soit pas aussi puissant que l'ordinateur que vous utilisez actuellement, il est parfait pour des tâches simples comme comprendre des messages provenant de capteurs ou allumer une LED (une petite lumière).

    .. image:: img/arduino_micro.jpg
        :width: 500
        :align: center

* **Carte de développement** : Imaginez la carte de développement comme le corps qui soutient le cerveau. C'est la carte sur laquelle repose le microcontrôleur, et elle contient d'autres composants qui aident le microcontrôleur à interagir avec le monde. Ces composants incluent des oscillateurs (qui aident à la synchronisation), des régulateurs de tension (qui contrôlent les niveaux d'alimentation) et des connecteurs pour l'alimentation et les données (comme les prises et interrupteurs de votre maison).

    .. image:: img/arduino_board.png
        :width: 600
        :align: center

* **IDE Arduino** : C'est un peu comme la salle de classe de votre Arduino. C'est un programme qui s'exécute sur votre ordinateur, où vous pouvez écrire les instructions qui diront à votre Arduino quoi faire. Ces instructions sont écrites dans un langage de programmation basé sur C++. Une fois que vous avez rédigé vos instructions, vous pouvez les envoyer à la carte Arduino via un câble USB, comme si vous rendiez vos devoirs !

    .. image:: img/arduino_ide_icon.png
        :width: 200
        :align: center

Maintenant que vous comprenez ces idées de base, vous êtes bien parti pour devenir un expert Arduino !

Ensuite, nous nous plongerons dans des activités pratiques pour vous familiariser avec la programmation Arduino et les principes d'ingénierie.
Préparez-vous pour un parcours d'apprentissage passionnant !

Familiarisation avec la carte SunFounder R3
------------------------------------------------------------------

Dans votre kit, vous trouverez une carte bleue, ressemblant à une petite ville remplie de petites tours métalliques et de chemins. Mais ne vous laissez pas intimider ! Voici la carte de développement SunFounder R3, un type de carte Arduino qui peut être utilisé pour programmer et contrôler une vaste gamme de dispositifs électroniques et de projets.

Comprenons ses caractéristiques clés en termes simples :

.. image:: img/sf_r3.jpg
    :width: 800

* **14 broches numériques** : Considérez ces broches comme de petits messagers. Elles peuvent être programmées pour envoyer (sortie) ou recevoir (entrée) des messages simples de type "oui" ou "non" vers d'autres parties de votre Rover martien. Ces messages sont en fait des signaux "marche" ou "arrêt" que la carte utilise pour contrôler des éléments tels que les lumières ou les moteurs.

    * Six de ces broches spéciales peuvent même envoyer des messages dans un code spécial appelé PWM (modulation de largeur d'impulsion). Ce code peut être utilisé pour contrôler la luminosité d'une lumière, la vitesse d'un moteur ou même la position d'une pièce mobile.


* **6 broches analogiques** : Ces broches sont comme les six sens spéciaux de la carte. Elles peuvent lire des signaux provenant de différents types de capteurs (comme un capteur de température) et les traduire dans un langage que la carte peut comprendre et utiliser dans sa programmation.

* **Connexion USB** : C'est comme le cordon ombilical de la carte. Vous pouvez l'utiliser pour connecter votre carte à votre ordinateur. Cette connexion permet à votre ordinateur de "former" la carte en lui envoyant un programme que vous avez écrit.

* **Prise d'alimentation** : C'est la source d'énergie de la carte. Vous pouvez connecter une alimentation, comme une batterie ou un adaptateur AC-DC, à cette prise pour "nourrir" votre carte avec l'électricité dont elle a besoin pour fonctionner.

* **En-tête ICSP** : C'est comme une entrée spéciale pour programmer la carte. Elle peut être utilisée si vous disposez d'un programmateur externe (un dispositif spécial pour "former" la carte).

* **Bouton de réinitialisation** : Si vous appuyez dessus, c'est comme dire à la carte d'oublier ce qu'elle faisait et de recommencer son programme depuis le début.

Avec ces notions de base, vous êtes prêt à commencer vos aventures en programmation avec la carte SunFounder R3 !

Installer l'IDE Arduino
-----------------------------------------------

Maintenant que nous comprenons ce qu'est Arduino et à quoi sert la carte Arduino, il est temps de mettre ces connaissances en pratique. Nous allons installer l'IDE Arduino, qui est le logiciel que nous utiliserons pour programmer notre carte Arduino.

La dernière version de l'IDE Arduino est la version 2.0. Elle est riche en fonctionnalités et très conviviale. Cependant, elle a quelques exigences système :

    * Windows - Win 10 et versions plus récentes, 64 bits
    * Linux - 64 bits
    * Mac OS X - Version 10.14 : "Mojave" ou plus récente, 64 bits

Pour commencer, suivez ces étapes :

#. Rendez-vous sur |link_download_arduino| et téléchargez l'IDE pour votre version de système d'exploitation.

    .. image:: img/sp_001.png

**Pour les utilisateurs de Windows :**

    #. Une fois que vous avez téléchargé le fichier (il sera nommé quelque chose comme ``arduino-ide_xxxx.exe``), double-cliquez dessus pour démarrer le processus d'installation.

    #. Vous verrez l'**Accord de licence**. Prenez un moment pour le lire et, si vous êtes d'accord avec les termes, cliquez sur "J'accepte".

        .. image:: img/sp_002.png

    #. Ensuite, vous serez invité à choisir les options d'installation. Laissez-les telles qu'elles sont et cliquez sur "Suivant".

        .. image:: img/sp_003.png

    #. Choisissez où vous voulez installer le logiciel. Il est généralement préférable de l'installer sur un autre disque que celui utilisé par votre système.

        .. image:: img/sp_004.png

    #. Cliquez sur "Installer" pour démarrer l'installation. Une fois terminée, cliquez sur "Terminer".

        .. image:: img/sp_005.png

**Pour les utilisateurs de macOS :**

    Double-cliquez sur le fichier téléchargé (qui s'appellera quelque chose comme ``arduino_ide_xxxx.dmg``). Suivez les instructions à l'écran pour glisser l'application **Arduino IDE** dans le dossier **Applications**. Après quelques secondes, l'IDE Arduino sera installé avec succès.

    .. image:: img/macos_install_ide.png
        :width: 800

**Pour les utilisateurs de Linux :**

    Vous pouvez trouver un tutoriel détaillé sur l'installation de l'IDE Arduino 2.0 sur un système Linux ici : |link_arduino_linux|.

Découverte du terrain de jeu Arduino (IDE)
----------------------------------------------------------------

Imaginons ensemble que l'IDE Arduino est un terrain de jeu magique rempli d'outils et de gadgets prêts à être explorés et utilisés. Je vais vous guider pour comprendre chaque recoin de ce terrain de jeu.

.. image:: img/ide-2-overview.png
    :width: 800

Voici ce que vous trouverez dans votre terrain de jeu :

* **Vérifier / Télécharger** - Imaginez ceci comme votre ascenseur magique. Il prend le code que vous avez écrit et l'envoie directement vers votre carte Arduino.
* **Sélectionner la carte et le port** - C'est votre carte au trésor. Elle montre automatiquement les cartes Arduino que vous avez branchées à votre ordinateur et indique leur numéro de port.
* **Sketchbook** - C'est votre bibliothèque personnelle. C'est là que tous vos sketches (programmes) sont stockés sur votre ordinateur. De plus, il peut se connecter au cloud Arduino, vous permettant de récupérer vos sketches depuis le monde en ligne.
* **Gestionnaire de cartes** - Pensez à cela comme votre boîte à outils. C'est ici que vous pouvez trouver et installer différents packages pour votre Arduino.
* **Gestionnaire de bibliothèques** - C'est votre coffre au trésor infini. Des milliers de bibliothèques créées par Arduino et sa communauté vous y attendent. Besoin d'un outil ou d'un matériel pour votre code ? Plongez-y et trouvez-le !
* **Débogueur** - Imaginez avoir un super pouvoir qui vous permet de tester et de déboguer votre code en temps réel, en trouvant et en corrigeant les problèmes au fur et à mesure. C'est ce que fait cet outil !
* **Recherche** - C'est votre loupe. Elle vous aide à rechercher des mots-clés dans votre code.
* **Ouvrir le moniteur série** - C'est comme votre appareil de communication. Il ouvre un nouvel onglet qui permet à votre ordinateur et à la carte Arduino d'envoyer des messages en retour.

Maintenant que nous avons eu un aperçu du terrain de jeu, il est temps de plonger et de commencer à créer !

Téléchargez votre premier sketch
-----------------------------------------------

C'est parti pour s'amuser ! Nous allons faire clignoter une LED - c'est un peu comme dire "Hello, World!" dans le monde Arduino.

La plupart des cartes Arduino ont une LED intégrée sur la broche 13, ce qui en fait une bonne première expérience.

.. image:: img/1_led.jpg
    :width: 400
    :align: center

Décomposons cela :

#. **Branchez la carte** : Connectez votre carte SunFounder R3 à votre ordinateur à l'aide d'un câble USB. C'est ainsi que nous allons alimenter notre carte et lui envoyer notre programme (aussi appelé "sketch"). Vous avez peut-être l'impression de simplement brancher un gadget informatique, mais croyez-moi, vous vous connectez à un monde de possibilités !

    .. image:: img/connect_board_pc.gif

#. **Trouvez le sketch d'exemple** : Dans l'IDE Arduino, allez à **Fichier** -> **Exemples** -> **Basic** -> **Blink**. Ce qui s'affiche est un programme prêt à l'emploi que nous allons modifier. C'est un peu comme un gâteau déjà préparé que nous allons décorer !

    .. image:: img/open_blink.png

#. **Comprenez le sketch** : Regardez le code dans cette nouvelle fenêtre. Il dit à Arduino d'allumer la LED intégrée (qui est sur la broche 13) pendant une seconde, puis de l'éteindre pendant une seconde, et de répéter ce processus. C'est comme envoyer du code Morse, mais avec de la lumière !

    .. image:: img/led_blink.png

#. **Téléchargez le sketch** : Une fois que vous avez sélectionné la bonne carte et le bon port, il vous suffit de cliquer sur le bouton de téléchargement. C'est aussi simple que d'envoyer une lettre ; vous transmettez vos instructions à la carte Arduino ! La plupart du temps, le système détecte automatiquement la carte et le port pour vous.

    .. image:: img/upload_blink.gif

#. **Regardez-le fonctionner** : Si tout se passe bien, vous verrez la LED sur votre carte Arduino commencer à clignoter. C'est comme si votre Arduino vous faisait un clin d'œil !

    .. image:: img/blink_led.gif

Vous avez fait un excellent travail ! Vous venez de lancer votre premier programme Arduino, faisant de vous un véritable programmeur ! Alors, quelle est la suite ? Nous ne faisons que gratter la surface de ce qu'Arduino peut faire. Prêt pour le prochain défi ?

Quelques faits amusants sur la programmation Arduino
--------------------------------------------------------

Découvrons quelques secrets intéressants sur la programmation Arduino !

* Magie du code : ``setup()`` et ``loop()``

    Un sketch Arduino, ou un morceau de code, est comme une pièce de théâtre en deux actes :

    * ``setup()`` : C'est l'acte 1, la scène d'ouverture. Il ne se produit qu'une seule fois, lorsque votre carte Arduino se réveille pour la première fois. Il est utilisé pour préparer la scène en configurant des éléments comme les modes de broches et les bibliothèques.
    * ``loop()`` : Après l'acte 1, nous passons à l'acte 2, qui se répète en boucle jusqu'au rideau final (qui ne tombe que si nous coupons l'alimentation ou appuyons sur le bouton de réinitialisation !). Cette partie du code est comme la scène principale où l'action se déroule vraiment.

    Mais rappelez-vous, même s'il n'y a pas de magie (code) dans le ``setup()`` ou le ``loop()``, nous devons toujours les garder. Ils sont comme la scène - même une scène vide reste une scène.

    .. code-block:: arduino
    
        void setup() {
            // initialiser la broche numérique LED_BUILTIN comme une sortie.
            pinMode(LED_BUILTIN, OUTPUT);

            digitalWrite(LED_BUILTIN, HIGH);  // allumer la LED (HIGH est le niveau de tension)
            delay(1000);                      // attendre une seconde
            digitalWrite(LED_BUILTIN, LOW);   // éteindre la LED en passant la tension à LOW
            delay(1000);                      // attendre une seconde
        }

        // la fonction loop s'exécute en boucle à l'infini
        void loop() {

        }

* Signes de ponctuation en programmation

    Tout comme dans un livre, Arduino utilise des signes de ponctuation spéciaux pour donner du sens au code :

    * ``Points-virgules (;)`` : Ce sont comme les points dans une histoire. Ils disent à l'Arduino "D'accord, j'ai fini cette action. Quelle est la suite ?"
    * ``Accolades {}`` : Ce sont comme le début et la fin d'un chapitre. Elles encadrent les morceaux de code ensemble, marquant où une section commence et se termine.

    Si vous oubliez certains de ces signes de ponctuation, pas de panique ! L'Arduino est comme un professeur bienveillant qui vérifie votre travail, pointe les erreurs et vous montre comment les corriger. Tout cela fait partie de l'aventure d'apprentissage !

    .. image:: img/blink_error.gif

* À propos des fonctions

    Imaginez ces fonctions comme des sorts magiques. Chaque sort a un effet spécifique dans notre aventure Arduino :

    * ``pinMode()`` : Ce sort décide si une broche est en ENTRÉE ou en SORTIE. C'est comme décider si un personnage dans notre histoire parle (SORTIE) ou écoute (ENTRÉE).
    * ``digitalWrite()`` : Ce sort peut mettre une broche en HIGH (activée) ou en LOW (désactivée), comme allumer ou éteindre une lumière magique.
    * ``delay()`` : Ce sort fait faire une pause à l'Arduino pendant un certain temps, comme prendre une petite sieste au milieu de notre histoire.

    Tout comme dans un grimoire, vous pouvez trouver tous ces sorts et bien d'autres dans le |link_arduino_web|. Plus vous connaissez de sorts, plus vos aventures Arduino seront passionnantes !

* Commentaires : Nos messages secrets

    Nous avons également un langage secret en programmation, appelé ``commentaires``. Ce sont des messages que nous pouvons écrire dans notre code en utilisant ``//`` ou ``/* */``. La partie magique ? L'Arduino les ignore complètement ! C'est un excellent endroit pour laisser des notes pour vous-même ou pour expliquer ce que font les parties délicates du code.

* Lisibilité du code : Rendre le code convivial

    Bien que vous puissiez écrire votre code comme bon vous semble (par exemple, placer des points-virgules sur une ligne séparée ne causera pas d'erreur), il est important de garder à l'esprit la lisibilité du code.

    .. image:: img/blink_noerror.gif

    Tout comme écrire une bonne histoire, la façon dont nous écrivons le code peut le rendre amusant et facile à lire, ou ennuyeux et difficile. Voici quelques conseils pour rendre votre code plus convivial :

    * Utilisez une indentation correcte pour organiser vos phrases en paragraphes soignés. Cela aide le lecteur à comprendre où une section se termine et où une autre commence.
    * Utilisez des noms de variables explicites. C'est comme donner un nom approprié à un personnage dans une histoire.
    * Gardez vos fonctions petites et simples, comme des chapitres courts et agréables dans un livre.
    * Laissez des commentaires pour les parties délicates. C'est comme laisser une note de bas de page pour expliquer un mot difficile.

Rappelez-vous, nous ne codons pas seulement pour les machines, mais aussi pour les humains, alors assurons-nous que notre code raconte une histoire claire et compréhensible !

**Réfléchir et s'améliorer**

Prendre un moment pour réfléchir à notre parcours peut nous donner des perspectives que nous pourrions manquer dans l'effervescence de l'exploration. Posez-vous ces questions :

* Quelle a été la partie la plus intéressante de cette aventure Arduino ?
* Avez-vous rencontré des défis en cours de route ? Comment les avez-vous surmontés ?
* Pourriez-vous expliquer à un ami ce qu'est Arduino, ce que fait l'IDE Arduino ou comment exécuter du code Arduino ?
* Comment décririez-vous votre première expérience de programmation Arduino ?
* Qu'avez-vous envie d'apprendre de plus sur Arduino ?

En réfléchissant à ces questions, vous approfondissez votre compréhension et vous vous préparez pour de futures explorations. N'oubliez jamais qu'il n'y a pas de "mauvaises" réponses dans la réflexion – c'est votre voyage personnel après tout !
