.. note::

    Bonjour et bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 ! Plongez au cœur de l'univers du Raspberry Pi, de l'Arduino et de l'ESP32 aux côtés d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Soutien d'experts** : Résolvez les problèmes après-vente et surmontez les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez astuces et tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et découvrez des aperçus inédits.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos dernières nouveautés.
    - **Promotions festives et concours** : Participez à des concours et à des promotions lors des fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Leçon 12 : Piloter le Rover avec l'Application
===================================================

Lors de notre dernière aventure, nous avons maîtrisé l'utilisation du SunFounder Controller pour non seulement explorer le monde à travers les yeux du rover, mais aussi ajuster son regard en contrôlant le mécanisme d'inclinaison. C'était comme donner une vision à notre rover martien !

Maintenant, imaginez si vous pouviez également diriger cet explorateur martien, contrôler son chemin à votre guise. Dans cette leçon, c'est exactement ce que nous allons faire ! Nous allons approfondir notre compréhension du SunFounder Controller et apprendre à manœuvrer notre rover, pour vivre l'exaltante expérience d'être un conducteur de rover martien !

Avec notre cours STEAM vif et interactif, les enfants n'apprendront pas seulement, ils vivront l'excitation et l'émerveillement de l'exploration spatiale ! Attachez votre ceinture et préparez-vous pour un voyage palpitant !

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/camera_app.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

Objectifs d'apprentissage
-----------------------------

* Approfondir la compréhension du SunFounder Controller.
* Apprendre à piloter le rover martien avec l'application mobile.


Matériel nécessaire
---------------------

* Modèle de Rover martien (équipé de tous les composants, sauf le panneau solaire et la plaque inférieure)
* Arduino IDE
* Ordinateur
* Tablette ou smartphone avec l'application SunFounder Controller installée

Étapes du cours
------------------

**Étape 1 : Explorer en profondeur le SunFounder Controller**

Dans notre leçon précédente, nous avons eu un premier aperçu des opérations de base et des usages du SunFounder Controller. Mais il reste sûrement des questions en suspens, n'est-ce pas ? Il est temps de satisfaire cette curiosité et d'explorer plus en détail cette merveille technologique.

Lors de la création d'un nouveau contrôleur, vous serez confronté à un écran qui peut sembler énigmatique au premier abord.

.. image:: img/app/app_blank.png

Vous verrez un kaléidoscope de formes : de longs rectangles, des rectangles courts et de grands carrés, chacun portant un identifiant unique allant de A à Q.

Vous vous demandez pourquoi tant de diversité ? Que signifient ces identifiants de A à Q ?

Partons ensemble dans cette aventure exploratoire !

* **Décoder les formes**

    Par exemple, touchez une zone rectangulaire longue. Comme ouvrir un coffre au trésor, vous découvrirez plusieurs widgets. Vous vous souvenez du **Slider** de notre dernier cours ? En le glissant à gauche ou à droite, vous contrôliez l'inclinaison de la caméra du rover. Ensuite, il y a le **Gauge**, qui peut servir de compteur de vitesse pour votre rover. Et une multitude d'autres widgets !

    .. image:: img/app/app_long.png

    Touchez le rectangle plus court, et il révèle un autre ensemble de widgets. Le widget **Button**, tel un interrupteur binaire, émet des commandes uniques, tandis que le widget **Microphone** peut écouter vos commandes vocales pour contrôler le rover, parmi d'autres widgets.

    .. image:: img/app/app_short.png

    Et le carré, vous demandez-vous ? Il abrite le widget **Joystick**, le widget D-pad et le widget Throttle. Et oui, il y a encore plus !

    .. image:: img/app/app_square.png

    Pour l'instant, ne vous inquiétez pas de la fonction ou de l'utilisation de chaque widget. Familiarisez-vous simplement avec les widgets hébergés par chaque forme.

* **Exploiter les widgets**

    Nous savons maintenant qu'il existe de nombreux widgets différents. À quoi peuvent-ils servir ?

    Nous les classons en deux types : les widgets de contrôle et les widgets d'affichage.

    * Les **widgets de contrôle** vous permettent de manipuler l'application, puis le rover martien reçoit ces commandes et effectue les actions correspondantes.
    * Les **widgets d'affichage** permettent d'afficher des valeurs dans l'application, comme des valeurs de capteurs, etc.

    Pour une description détaillée de ces widgets, veuillez vous référer à : |link_widgets_list|.

    Pour les fonctions, paramètres, etc. associés à ces widgets, veuillez consulter : |link_ai_camera_library_api|.

* **Le rôle des identifiants**

    Chaque forme porte un identifiant en bas à droite. Pourquoi, demandez-vous ? Comprenons cela avec un exemple.

    Lors de notre dernier cours, nous avons ajouté un widget **Slider** dans la région **D**. Le code pour obtenir sa valeur ressemblait à ceci :

        .. code-block:: arduino

            int16_t sliderD = aiCam.getSlider(REGION_D);

    Et si nous ajoutions un widget **Slider** dans la région **B** ? Comment le code changerait-il ? Il suffit de remplacer ``REGION_D`` par ``REGION_B``.

        .. code-block:: arduino

            int16_t sliderD = aiCam.getSlider(REGION_B);

    Simple, non ? Ces identifiants aident à distinguer quel widget vous avez ajouté dans quelle zone.

.. note::
    * Des instructions détaillées sur la création et l'ajout de widgets, ainsi que la connexion et l'utilisation du SunFounder Controller, sont disponibles dans ``Étape 3`` de ``Leçon 11``.
    * Pour des opérations plus approfondies, veuillez consulter |link_sc_page|.

**Étape 2 : Contrôler le Rover Martien avec deux manettes des gaz**

Maintenant que nous avons exploré les widgets du SunFounder Controller, passons à l'étape suivante en intégrant deux widgets **Throttle** pour commander les mouvements du Rover Martien.

#. Placez un widget **Throttle** dans les régions **K** et **Q**. Vous devrez appuyer sur le bouton |app_edit| en haut à droite pour passer en mode édition, puis, une fois que vous aurez tout configuré, cliquez sur |app_save| pour enregistrer vos modifications.

    .. image:: img/app/app_throttle.png

#. Comme nous prévoyons d'utiliser deux widgets **Throttle** pour contrôler la mobilité du rover, ajustons la fonction qui gère les mouvements du rover en conséquence :

    .. code-block:: arduino

        // Fonction pour régler la puissance des moteurs
        void carSetMotors(int8_t power_L, int8_t power_R) {
            // Régler la puissance pour le moteur gauche
            if (power_L >= 0) {
                SoftPWMSet(in1, map(power_L, 0, 100, 0, 255));
                SoftPWMSet(in2, 0);
            } else {
                SoftPWMSet(in1, 0);
                SoftPWMSet(in2, map(power_L, 0, -100, 0, 255));
            }

            // Régler la puissance pour le moteur droit
            if (power_R >= 0) {
                SoftPWMSet(in3, 0);
                SoftPWMSet(in4, map(power_R, 0, 100, 0, 255));
            } else {
                SoftPWMSet(in3, map(power_R, 0, -100, 0, 255));
                SoftPWMSet(in4, 0);
            }
        }

    Décortiquons la fonction ``carSetMotors()``. Cette fonction accepte deux arguments, ``power_L`` et ``power_R``, qui sont probablement les réglages de puissance pour les moteurs gauche et droit respectivement. Les valeurs de ces arguments vont vraisemblablement de -100 à 100, où les valeurs négatives indiquent un mouvement en marche arrière, 0 indique un arrêt, et les valeurs positives indiquent un mouvement en avant.

    * Régler la puissance pour le moteur gauche :

        * Si ``power_L`` est supérieur ou égal à 0, le moteur gauche est réglé pour avancer.

        * ``SoftPWMSet(in1, map(power_L, 0, 100, 0, 255))`` utilise la fonction ``map`` d'Arduino pour mapper l'intervalle d'entrée (0 à 100) à l'intervalle de sortie (0 à 255) - cela parce que les valeurs PWM dans Arduino sont comprises entre 0 (0 % de cycle de travail) et 255 (100 % de cycle de travail). Cette valeur mappée est ensuite transmise à la fonction ``SoftPWMSet`` avec ``in1``.

        * Si ``power_L`` est inférieur à 0, le moteur gauche est réglé pour reculer et l'intervalle d'entrée de la fonction ``map`` est maintenant de 0 à -100.

    * Régler la puissance pour le moteur droit :

        * Cela suit la même logique que pour régler la puissance du moteur gauche, mais utilise ``in3`` et ``in4`` à la place, et les valeurs de puissance d'entrée sont ``power_R`` au lieu de ``power_L``.

    Globalement, cette fonction prend deux valeurs de puissance des moteurs, les convertit en valeurs PWM appropriées, et définit ces valeurs PWM sur les broches de contrôle des moteurs pour obtenir le mouvement souhaité.

#. Dans la fonction ``onReceive()``, récupérez les valeurs des deux widgets **Throttle** et utilisez-les comme puissance pour les moteurs gauche et droit du rover martien.

    .. code-block:: arduino
        :emphasize-lines: 9,10,13

        void onReceive() {
            // Obtenir la valeur du slider dans la région D
            int16_t sliderD = aiCam.getSlider(REGION_D);

            // Déplacer le servo à l'angle indiqué par le slider
            myServo.write(int(sliderD));

            // Obtenir les valeurs des manettes des gaz pour gauche et droite
            int throttle_L = aiCam.getThrottle(REGION_K);
            int throttle_R = aiCam.getThrottle(REGION_Q);

            // Régler la puissance des moteurs
            carSetMotors(throttle_L, throttle_R);
        }

Voici le code complet :

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c70d2598-a1f9-465a-83bb-4ebd38eb74fa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Chaque fois que vous relancez le code, vous devez répéter les quatre étapes suivantes :

* Avant de téléverser le code, assurez-vous que l'interrupteur est positionné vers la droite.

    .. image:: img/camera_upload.png

* Une fois le code téléversé avec succès, passez l'interrupteur vers la gauche pour démarrer l'ESP32 CAM.
* Connectez-vous au réseau ``GalaxyRVR``.
* Connectez et lancez le contrôleur.

D'un simple mouvement du pouce sur vos widgets ``Throttle``, vous verrez le rover martien entrer en action, avançant et pivotant avec un nouvel élan. Que l'exploration commence !

**Étape 3 : Visualiser les données des capteurs**

Au cours de notre aventure avec le SunFounder Controller, nous avons interagi activement avec notre rover martien à l'aide de widgets de contrôle, notamment des sliders pour ajuster l'inclinaison et des manettes pour diriger les mouvements du rover. Mais qu'en est-il de l'utilisation des widgets d'affichage pour obtenir un aperçu clair de l'environnement du rover ?

Voyons comment nous pouvons concrétiser cela en visualisant les valeurs des modules infrarouges (IR) d'évitement gauche et droit, ainsi que la distance mesurée par le module ultrasonique. Ces données en temps réel nous offriront une vue d'ensemble de l'environnement de fonctionnement du rover.

Voici comment nous pouvons y parvenir :

#. Commencez par ajouter trois widgets **Number** à votre SunFounder Controller. N'oubliez pas que vous pouvez personnaliser leurs noms et unités via le bouton de configuration.

    .. image:: img/app/app_show.png

#. Ensuite, passons au code. Commencez par importer les extraits de code des modules IR d'évitement et du module ultrasonique de nos leçons précédentes.

    .. code-block:: arduino

        ...
        // Définir la broche pour le module ultrasonique
        #define ULTRASONIC_PIN 10

        // Définir les broches pour les modules IR
        #define IR_RIGHT 7
        #define IR_LEFT 8

        void setup() {
            ...

            // Définir les broches des modules IR comme entrées
            pinMode(IR_RIGHT, INPUT);
            pinMode(IR_LEFT, INPUT);
        }

        float readSensorData() {
            // Un délai de 4 ms est nécessaire, sinon la lecture peut être de 0
            delay(4);

            // Passer en OUTPUT pour envoyer le signal
            pinMode(ULTRASONIC_PIN, OUTPUT);

            ...
        }

#. Dans la fonction ``onReceive()``, extrayez les valeurs des modules d'évitement et du capteur ultrasonique. Ensuite, mettez à jour ces valeurs dans le dictionnaire ``sendDoc[]``. Les clés ``N``, ``P`` et ``O`` correspondent aux codes régionaux des trois widgets **Number** que vous avez ajoutés.

    .. code-block:: arduino

        // Fonction exécutée lors de la réception des données du contrôleur
        void onReceive() {

            ...

            // Lire les valeurs des capteurs IR
            int leftValue = digitalRead(IR_LEFT);
            int rightValue = digitalRead(IR_RIGHT);
            aiCam.sendDoc["N"] = leftValue;
            aiCam.sendDoc["P"] = rightValue;
            
            // ultrason
            float distance = readSensorData();
            aiCam.sendDoc["O"] = distance;
        }

Voici le code complet :

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6c867007-a0e8-4f85-980d-ec1cd1a70969/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Une fois le code téléversé avec succès, lancez votre SunFounder Controller. Vous verrez alors apparaître les valeurs en temps réel des modules d'évitement et la distance détectée par le capteur ultrasonique, offrant une vue précise de l'environnement immédiat du rover.

.. image:: img/app/app_show_ir_ultrasonic.png

Avec cette étape derrière vous, vous avez maîtrisé le monde des widgets d'affichage. N'hésitez pas à expérimenter avec différents widgets pour afficher les informations qui vous intéressent. Bonne exploration !

**Étape 4 : Réflexion et conclusion**

Dans cette leçon, nous avons approfondi notre compréhension du SunFounder Controller, en apprenant à utiliser ses widgets pour non seulement piloter notre rover martien, mais aussi surveiller en temps réel les données environnementales de celui-ci.

Maintenant, voici un défi pour vous :

Pourquoi ne pas ajouter des widgets Switch à votre SunFounder Controller ? Avec ces interrupteurs activés, le rover pourrait basculer entre les modes d'évitement et de suivi. Ou encore, utilisez les interrupteurs pour contrôler la bande lumineuse - en l'allumant ou en l'éteignant, voire en changeant sa couleur !

Avez-vous confiance pour relever ce défi ?

Nous avons hâte de vous voir triompher !
