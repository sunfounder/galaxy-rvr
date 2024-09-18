.. note::

    Bonjour, et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, d'Arduino et d'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Soyez parmi les premiers à découvrir les nouvelles annonces de produits et obtenez des aperçus exclusifs.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos nouveaux produits.
    - **Promotions festives et concours** : Participez à des concours et des promotions pendant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !


Leçon 4 : Maîtriser le Moteur TT
====================================

Dans les leçons précédentes, nous avons exploré les rovers martiens, leurs systèmes de suspension, et nous avons découvert Arduino.

Dans ce cours passionnant, nous allons explorer le fonctionnement des moteurs, un composant clé qui fait avancer les rovers martiens.
Nous comprendrons les principes qui alimentent ces moteurs et apprendrons à les contrôler en utilisant la carte SunFounder R3 et un GalaxyRVR Shield.

À la fin de ce cours, vous aurez une solide compréhension du fonctionnement des moteurs et une expérience pratique du contrôle des moteurs.

Allons-y !

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/left_1.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::

    Si vous suivez ce cours après avoir entièrement assemblé le GalaxyRVR, vous devez déplacer cet interrupteur vers la droite avant de télécharger le code.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Objectifs du cours
----------------------
* Comprendre les principes de base des moteurs et les caractéristiques du moteur TT.
* Apprendre à contrôler la direction et la vitesse du moteur TT.
* Comprendre comment le Shield GalaxyRVR contrôle six moteurs.


Matériel du cours
-----------------------

* Carte SunFounder R3
* Moteur TT
* Shield GalaxyRVR
* Batterie
* Câble USB
* IDE Arduino
* Ordinateur

Étapes du cours
------------------

**Étape 1 : Qu'est-ce qu'un moteur ?**

Les moteurs jouent un rôle essentiel dans notre vie quotidienne. Ils sont partout ! Des ventilateurs électriques qui nous rafraîchissent lors des journées chaudes, aux mixeurs qui nous aident à préparer de délicieux gâteaux, en passant par les voitures électriques qui filent dans les rues – les moteurs mettent les choses en mouvement !

.. image:: img/motor_application.jpg

Un moteur est comme le cœur d'une machine. Il convertit l'énergie électrique en énergie mécanique, donnant vie à nos jouets, appareils électroménagers, et même aux grands véhicules !

La magie derrière un moteur n'est pas de la magie, mais bien de la science, plus précisément le principe de l'induction électromagnétique. Voici comment cela fonctionne : lorsque de l'électricité est fournie à un moteur, elle génère un champ magnétique. Ce champ magnétique interagit ensuite avec d'autres aimants à l'intérieur du moteur, provoquant la rotation du moteur. Cette rotation, comme faire tourner une toupie, peut ensuite être utilisée pour faire bouger des roues, des hélices ou d'autres pièces mobiles d'une machine.

.. image:: img/motor_rotate.gif
    :align: center

Le type de moteur sur lequel nous nous concentrons dans notre GalaxyRVR est un modèle spécifique appelé moteur à engrenage TT.

.. image:: img/tt_motor_xh.jpg
    :align: center
    :width: 400

Il s'agit essentiellement d'un moteur classique combiné à une série d'engrenages, le tout enfermé dans un boîtier en plastique.

Lorsque le moteur tourne, les engrenages traduisent cette rotation en mouvement pour les roues de notre rover. L'utilisation des engrenages apporte un avantage crucial : elle augmente le couple, permettant au moteur de déplacer des charges plus lourdes.

.. image:: img/motor_internal.gif
    :align: center
    :width: 600

N'est-ce pas fascinant de voir comment les principes scientifiques et d'ingénierie prennent vie ? Les moteurs sont un parfait exemple de ces principes en action. En comprenant leur fonctionnement, nous pouvons imaginer et inventer une grande variété de machines. Plongeons plus profondément dans le monde des moteurs et libérons notre créativité !


**Étape 2 : Explorer le Fonctionnement et l'Opération du Moteur**

Maintenant que nous avons compris ce qu'est un moteur et ses diverses applications, il est temps de plonger au cœur de son fonctionnement.

En essence, un moteur fonctionne sur le principe de l'électromagnétisme. Lorsqu'un courant électrique traverse un fil, il génère un champ magnétique autour de lui. Ce champ magnétique peut interagir avec d'autres champs magnétiques, provoquant un mouvement.

Prenons un exemple simple où nous connectons un moteur directement à une batterie. Le courant de la batterie entre dans le moteur, déclenchant son mécanisme interne pour commencer à tourner. Cette action de rotation est due aux forces magnétiques à l'intérieur du moteur.

    .. image:: img/motor_battery.png

Fait intéressant, si vous inversez les connexions à la batterie, le moteur tournera dans le sens inverse ! Cela se produit parce que la direction du flux de courant change, modifiant ainsi la direction du champ magnétique et, par conséquent, celle de la rotation du moteur.

Nous savons maintenant que connecter un moteur directement à une batterie peut le faire tourner, mais souvent nous voulons contrôler son mouvement avec du code, c'est pourquoi nous incluons une carte Arduino entre les deux. Mais que se passerait-il si nous essayions de connecter le moteur directement aux broches de signal de la carte Arduino ?

.. image:: img/motor_uno.png
    :width: 600
    :align: center

Si vous avez deviné que le moteur ne tournerait pas, vous avez raison ! Mais pourquoi ?

La réponse réside dans la sortie de courant de la carte Arduino. Les broches de signal d'une carte Arduino typique ne peuvent fournir qu'environ 20 mA de courant, ce qui est insuffisant pour faire tourner un moteur.

Alors, comment pouvons-nous contrôler les moteurs avec notre Arduino ? C'est là qu'intervient un composant crucial : le driver de moteur. Pensez au driver de moteur comme à un pont entre l'Arduino et le moteur. Il prend le signal de contrôle à faible courant de l'Arduino, l'amplifie et l'envoie au moteur, permettant ainsi au moteur de tourner.

.. image:: img/motor_uno2.png

Dans notre prochaine étape, nous approfondirons les spécificités du driver de moteur et comprendrons comment l'utiliser efficacement avec notre carte Arduino pour contrôler un moteur. Restez à l'écoute pour plus d'apprentissages passionnants !


**Étape 3 : Comment le Moteur est Contrôlé par le Driver de Moteur**

Notre Shield GalaxyRVR, inclus dans le kit, sert de centre de contrôle pour notre Rover martien. C'est le hub où nous connectons tous nos capteurs, moteurs et source d'alimentation. Il se compose de plusieurs composants qui nous permettent de contrôler et d'alimenter efficacement notre Rover.

Sur le côté droit du Shield, vous remarquerez six ports pour les moteurs. Cependant, ils sont regroupés en deux ensembles, chacun contrôlé par une puce de driver de moteur séparée. Trois ports marqués "Left" sont contrôlés par une puce, et les trois autres ports marqués "Right" sont contrôlés par une autre puce.

.. image:: img/motor_shield.png

Apprenons comment ces deux puces de driver contrôlent les six moteurs à travers une expérience pratique :

* **1. Connexion du Circuit**

    #. Branchez le Shield GalaxyRVR sur la carte R3, connectez un moteur, et enfin branchez la batterie pour alimenter la carte d'expansion.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/connect_shield.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    #. La première fois que vous l'utilisez, il est recommandé de brancher un câble USB Type-C pour charger complètement la batterie. Ensuite, allumez l'alimentation.
    
        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/plug_usbc.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

* **2. Écriture et Téléchargement du Code**

    #. Ouvrez l'IDE Arduino et entrez le code suivant :

        .. code-block:: arduino

            void setup() {
                pinMode(2, OUTPUT);
                pinMode(3, OUTPUT);
            }

            void loop() {
                digitalWrite(2, LOW);
                digitalWrite(3, HIGH);
            }
    
        * ``pinMode()`` : Cette fonction définit une broche en tant qu'ENTRÉE ou SORTIE, comme si l'on décidait si un personnage dans notre histoire parle (SORTIE) ou écoute (ENTRÉE).
        * ``digitalWrite()`` : Cette fonction permet de mettre une broche en HIGH (activée) ou en LOW (désactivée), un peu comme allumer ou éteindre une lumière magique.

    #. Une fois que vous avez sélectionné la bonne carte (Arduino Uno) et le bon port, cliquez sur le bouton **Téléverser**. C'est comme poster une lettre – vous envoyez vos instructions à l'Arduino !

        .. image:: img/motor_upload.png
        
    #. Une fois le code téléversé avec succès, vous verrez le moteur commencer à tourner dans le sens des aiguilles d'une montre.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/left_1.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>
    
* **3. À propos de la Connexion Interne du Circuit**

    #. Vous pouvez brancher deux autres moteurs dans les ports marqués "Left". Vous les verrez tourner simultanément.

    #. Comprenons maintenant le principe simple de la manière dont les deux puces de commande de moteur contrôlent les six moteurs. Les broches 2 et 3 sur la carte Arduino envoient des signaux à la puce de commande du moteur, et l'autre extrémité de la puce est connectée à trois moteurs en parallèle. De même, les broches 4 et 5 envoient des signaux à une autre puce de commande, qui est elle-même connectée à trois autres moteurs en parallèle.

        .. image:: img/motor_driver.png
            :width: 500

    #. Si vous souhaitez tester une autre puce de commande, vous devez simplement changer les broches en ``4`` et ``5``.

        .. code-block:: arduino
            :emphasize-lines: 10,11

            const int in3 = 4;
            const int in4 = 5;

            void setup() {
                pinMode(in3, OUTPUT);
                pinMode(in4, OUTPUT);
            }

            void loop() {
                digitalWrite(in3, LOW);
                digitalWrite(in4, HIGH);
            }

        Ici, nous définissons deux variables pour représenter les broches 4 et 5. En utilisant des variables, nous pouvons facilement gérer et ajuster nos attributions de broches dans tout le code.

        C'est un peu comme si nous assignions un rôle spécifique à chaque numéro de broche. Si nous décidons de réassigner ces rôles, au lieu de modifier chaque occurrence dans le script, il suffit de mettre à jour l'assignation au début du script (là où la variable est initialement définie).


* **4. À propos de la Logique de Commande**

    #. Lors des tests précédents, vous avez probablement remarqué que les moteurs tournent tous dans une direction. Comment les faire tourner dans l'autre sens ? Quelqu'un pourrait suggérer d'inverser les états HIGH et LOW des deux broches. C'est exact.

        .. code-block:: arduino
            :emphasize-lines: 1,2

            const int in3 = 4;
            const int in4 = 5;

            void setup() {
                pinMode(in3, OUTPUT);
                pinMode(in4, OUTPUT);
            }

            void loop() {
                digitalWrite(in3, HIGH);
                digitalWrite(in4, LOW);
            }

        Une fois que vous avez écrit votre code et l'avez téléversé sur votre carte Arduino, le moteur se comportera comme prévu.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/right_cc.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    #. Examinons maintenant la logique interne de commande de la puce de commande de moteur.

        .. list-table::
            :widths: 25 25 50
            :header-rows: 1

            * - INA
              - INB
              - Moteur
            * - L
              - L
              - Veille
            * - L
              - H
              - Sens horaire
            * - H
              - L
              - Sens antihoraire
            * - H
              - H
              - Frein
    
    #. Maintenant, essayons de faire tourner le moteur dans le sens horaire pendant 2 secondes, puis dans le sens antihoraire pendant 2 secondes, et enfin l'arrêter.

        .. code-block:: arduino
            :emphasize-lines: 10,11,12,13,14,15,16,17,18

            const int in3 = 4;
            const int in4 = 5;
            
            void setup() {
                pinMode(in3, OUTPUT);
                pinMode(in4, OUTPUT);
            }
            
            void loop() {
                digitalWrite(in3, LOW);
                digitalWrite(in4, HIGH);
                delay(2000);
                digitalWrite(in3, HIGH);
                digitalWrite(in4, LOW);
                delay(2000);
                digitalWrite(in3, HIGH);
                digitalWrite(in4, HIGH);
                delay(5000);
            }

        * Ici, nous utilisons la fonction ``delay()`` pour faire faire une pause à l'Arduino pendant un certain temps, comme prendre une petite pause dans notre histoire.
        * Dans le code, nous utilisons l'état "Frein" pour arrêter le moteur, et vous remarquerez que le moteur s'arrête brusquement. Essayez de régler les deux broches sur LOW pour tester l'état "Veille", et vous constaterez que le moteur ralentit progressivement jusqu'à s'arrêter.

Vous devriez maintenant avoir une meilleure compréhension de la manière dont la puce de commande de moteur contrôle les moteurs via le Shield GalaxyRVR et comment nous pouvons utiliser le code Arduino pour manipuler les mouvements du moteur. N'est-ce pas fascinant de voir comment quelques lignes de code peuvent dicter le comportement d'un objet physique comme notre moteur ?

Réfléchissez aux questions suivantes en avançant :

* Si nous déplaçons tout le code de la fonction ``loop()`` vers la fonction ``setup()``, comment le comportement du moteur changerait-il ?
* Comment modifieriez-vous le code pour contrôler six moteurs simultanément ?

Souvenez-vous, plus vous expérimentez et jouez avec votre code, plus vous apprenez. N'hésitez pas à ajuster, modifier et optimiser votre code à votre guise. Bon codage !

**Étape 4 : Contrôler la Vitesse du Moteur**

Dans l'étape précédente, nous avons contrôlé la direction du moteur en définissant simplement ses broches sur HIGH ou LOW. 
C'est un peu comme donner toute la puissance au moteur, à l'image d'appuyer à fond sur l'accélérateur d'une voiture. 
Cependant, dans de nombreuses situations, nous souhaitons ajuster la vitesse du moteur pour s'adapter à différents scénarios, 
tout comme nous ajustons la vitesse d'une voiture en fonction de si nous roulons en ville ou sur l'autoroute. 
C'est ici qu'intervient la modulation de largeur d'impulsion (PWM, Pulse Width Modulation).

.. image:: img/motor_pwm.jpg

Le PWM est une technique utilisée pour créer un effet de sortie de tension variable en basculant rapidement la sortie entre HIGH et LOW. 
Avec le PWM, nous pouvons simuler l'effet d'un signal analogique tout en ne générant que des signaux numériques.

Cela peut sembler difficile à comprendre, et c'est normal ! Nous allons apprendre à ajuster la vitesse du moteur à l'aide du PWM dans les sections suivantes à travers la programmation.

Notez que même si la carte SunFounder R3 dispose de certaines broches avec la fonctionnalité PWM intégrée, nous ne pouvons pas les utiliser pour notre moteur car elles remplissent déjà d'autres fonctions. Ainsi, nous connectons les puces de commande aux broches 2, 3, 4 et 5, et utilisons la bibliothèque SoftPWM d'Arduino pour activer le PWM sur ces broches.

Voici ce que nous allons faire ensuite :

#. Ouvrez l'IDE Arduino, recherchez ``softpwm`` dans le **GESTIONNAIRE DE BIBLIOTHÈQUES** et installez-la.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Entrez le code suivant dans l'IDE Arduino. Après avoir téléversé le code avec succès, le moteur tournera dans le sens des aiguilles d'une montre.

    .. code-block:: arduino
        :emphasize-lines: 1, 7,11,12

        #include <SoftPWM.h>

        const int in1 = 2;
        const int in2 = 3;

        void setup() {
            SoftPWMBegin();
        }

        void loop() {
            SoftPWMSet(in1, 0);
            SoftPWMSet(in2, 255);

        }

    * Dans le code ci-dessus, nous commençons par ajouter ``SoftPWM.h`` en haut du code, ce qui nous permet d'utiliser directement les fonctions de la bibliothèque ``SoftPWM``.
    * Ensuite, nous initialisons la bibliothèque ``SoftPWM`` avec la fonction ``SoftPWMBegin()``.
    * Enfin, dans la fonction ``loop()``, nous utilisons ``SoftPWMSet()`` pour assigner des valeurs différentes à ``in1`` et ``in2``, mettant ainsi le moteur en mouvement. Vous remarquerez que l'effet est similaire à l'utilisation directe de ``LOW`` et ``HIGH``, mais ici, nous utilisons des valeurs numériques comprises entre ``0 et 255``.
    * Rappelez-vous, dans le monde d'Arduino, la vitesse est exprimée par une valeur entre 0 (comme une voiture à un feu rouge) et 255 (comme une voiture à pleine vitesse sur l'autoroute). Donc, quand nous disons ``SoftPWMSet(in2, 255)``, cela signifie que le moteur doit aller à pleine vitesse !

#. Maintenant, entrons d'autres valeurs et observons les différences dans la vitesse du moteur.

    .. code-block:: arduino
        :emphasize-lines: 12,13,14,15

        #include <SoftPWM.h>

        const int in1 = 2;
        const int in2 = 3;

        void setup() {
            SoftPWMBegin();
        }

        void loop() {
            SoftPWMSet(in1, 0);
            for (int i = 0; i <= 255; i++) {
                SoftPWMSet(in2, i);
                delay(100);
        }
            delay(1000);
        }
    
    Dans le code ci-dessus, nous utilisons une boucle ``for`` pour incrémenter une variable ``i`` jusqu'à ``255``. La boucle ``for`` en langage C est utilisée pour répéter une partie du programme plusieurs fois. Elle est constituée de trois parties :

    .. image:: img/motor_for123.png
        :width: 400
        :align: center

    * **Initialisation** : Cette étape est exécutée en premier et une seule fois lorsque nous entrons dans la boucle pour la première fois. Elle nous permet de déclarer et d'initialiser toutes les variables de contrôle de la boucle.
    * **Condition** : C'est l'étape suivante après l'initialisation. Si elle est vraie, le corps de la boucle est exécuté. Si elle est fausse, le corps de la boucle n'est pas exécuté et le flux de contrôle sort de la boucle ``for``.
    * **Incrément ou Décrément** : Après l'exécution des étapes d'Initialisation et de Condition et du code du corps de la boucle, l'étape d'Incrément ou Décrément est exécutée. Cette instruction nous permet de mettre à jour toutes les variables de contrôle de la boucle.

    Le diagramme de flux pour la boucle ``for`` est illustré ci-dessous :

    .. image:: img/motor_for.png

    Après avoir exécuté le code ci-dessus, vous verrez la vitesse du moteur augmenter progressivement. Il s'arrête pendant une seconde, puis recommence à partir de 0 et augmente progressivement.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/left_speed.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

Dans cette étape, nous avons appris la modulation de largeur d'impulsion (PWM), une technique permettant de contrôler la vitesse de notre moteur. En utilisant la bibliothèque SoftPWM d'Arduino, nous pouvons ajuster la vitesse du moteur, ce qui nous permet de simuler des signaux analogiques tout en générant uniquement des signaux numériques. Cela nous offre un contrôle plus précis sur les mouvements de notre rover et nous prépare à des manœuvres plus complexes à l'avenir.

**Étape 5 : Réfléchir et S'améliorer**

Après avoir complété cette leçon, vous devriez désormais être familiarisé avec les principes de fonctionnement des moteurs, ainsi que la manière de contrôler leur direction et leur vitesse par la programmation.

Testons votre compréhension avec ces défis :

* Comment modifieriez-vous la boucle ``for`` pour diminuer progressivement la vitesse du moteur ?
* Comment contrôleriez-vous le moteur pour qu'il accélère ou décélère tout en tournant dans le sens inverse des aiguilles d'une montre ?

Vous pouvez expérimenter avec le code fourni pour répondre à ces questions. N'hésitez pas à ajuster le code selon vos hypothèses et à observer les changements dans le comportement du moteur.

Vos expériences pratiques et vos réflexions sur ces questions approfondiront votre compréhension et amélioreront vos compétences en résolution de problèmes. C'est à travers ces défis que l'apprentissage réel se produit. N'oubliez jamais qu'il n'y a pas de "bonne" ou de "mauvaise" réponse dans votre voyage d'exploration – tout est question d'apprentissage et de découverte !

