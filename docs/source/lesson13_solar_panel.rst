.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur du Raspberry Pi, de l'Arduino et de l'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Soutien d'experts** : Résolvez les problèmes après-vente et surmontez les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez astuces et tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et à des promotions lors des fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !


Leçon 13 : Explorer le système énergétique du Rover martien
=================================================================

Bienvenue dans la dernière leçon de notre aventure d'exploration du Rover martien. 
Cette fois-ci, nous allons plonger au cœur du rover : son système énergétique.

Quand on pense à l'exploration de planètes lointaines comme Mars, l'un des aspects les 
plus cruciaux est l'énergie. 
Comment ces rovers se rechargent-ils dans des environnements aussi hostiles et éloignés ? 
Dans cette leçon, nous explorerons ce sujet fascinant et apprendrons comment les rovers, 
comme notre modèle de Rover martien, captent et gèrent l'énergie.

Nous étudierons les principes de fonctionnement de la batterie et du panneau solaire, 
et nous mettrons en pratique leur installation et leur utilisation sur notre modèle de 
rover. De plus, nous pousserons nos compétences encore plus loin en utilisant Arduino 
pour surveiller le niveau de la batterie.

À la fin de cette leçon, nous serons capables d'afficher ces statistiques énergétiques 
essentielles directement sur notre application, nous permettant ainsi de suivre en temps 
réel l'état énergétique de notre rover. Prêt à alimenter notre exploration ? C'est parti !

.. image:: img/solar_panel.jpg
    :width: 600
    :align: center

Objectifs d'apprentissage
-----------------------------

* Comprendre les principes de fonctionnement de la batterie et du panneau solaire.
* S'exercer à installer le panneau solaire sur le modèle du Rover martien.
* Apprendre à utiliser Arduino pour surveiller le niveau de la batterie et l'état de charge du panneau solaire.
* Afficher le niveau de la batterie sur l'application.

Matériel nécessaire
--------------------

* Modèle de Rover martien (équipé de tous les composants, sauf le panneau solaire et la plaque inférieure)
* Panneau solaire et plaque inférieure
* Arduino IDE
* Ordinateur
* Tablette ou smartphone avec l'application SunFounder Controller installée


Étapes du cours
---------------

**Étape 1 : Introduction au système énergétique du Rover martien**

Tout comme notre corps a besoin d'un approvisionnement constant en énergie pour fonctionner, notre Rover martien a besoin d'un moyen de stocker et de générer de l'énergie pour ses missions d'exploration. Imaginez le système énergétique du Rover comme le cœur de notre corps. Tout comme notre cœur pompe le sang vers toutes les parties de notre corps, fournissant l'oxygène et les nutriments nécessaires, le système énergétique du Rover assure un flux d'énergie vers chaque composant, lui permettant d'accomplir ses tâches sans encombre.

Les composants principaux de ce système énergétique sont les batteries et les panneaux solaires, qui travaillent en tandem pour garantir que le Rover puisse fonctionner à tout moment, de jour comme de nuit.

Le rôle des batteries dans le système énergétique du Rover est similaire à celui du stockage d'énergie dans notre corps. Tout comme nous avons besoin de stocker de l'énergie pour l'utiliser lorsque nous sommes actifs, le Rover a besoin d'un moyen de stocker de l'énergie pour ses missions d'exploration. L'énergie stockée dans les batteries est continuellement distribuée aux différentes parties du Rover, lui permettant d'effectuer ses tâches de manière méthodique.

.. image:: img/battery_galaxyrvr.png
    :width: 600
    :align: center

Mais que se passe-t-il lorsque l'énergie des batteries s'épuise ? Comment fait-il pour recharger ses réserves d'énergie ? C'est là que les panneaux solaires entrent en jeu.

Tout comme les arbres absorbent la lumière du soleil pour la photosynthèse afin de produire de la nourriture, notre Rover martien utilise des panneaux solaires pour capter l'énergie du Soleil, la convertissant en électricité stockée dans les batteries pour une utilisation future. Chaque panneau solaire est constitué de nombreuses petites cellules solaires. Ces cellules sont composées d'un matériau capable de convertir la lumière en électricité – un processus appelé effet photovoltaïque. Lorsque la lumière du soleil frappe les cellules, elles génèrent un courant électrique qui peut être utilisé immédiatement ou stocké dans les batteries du Rover pour une utilisation ultérieure.

.. image:: img/solar_panel_gala.png
    :width: 600
    :align: center

Cependant, capter l'énergie solaire sur Mars n'est pas aussi simple qu'il n'y paraît. Les tempêtes de poussière peuvent réduire la quantité de lumière solaire atteignant les panneaux, et la lumière martienne plus faible (comparée à celle de la Terre) signifie que les panneaux génèrent moins de puissance qu'ils ne le feraient ici. Malgré ces défis, l'énergie solaire reste le moyen le plus pratique et le plus efficace pour alimenter notre Rover martien.

Mais comment savons-nous quand les panneaux solaires font leur travail et quand les batteries sont faibles ? C'est là qu'intervient notre Arduino. Dans la section suivante, nous allons apprendre à utiliser Arduino pour surveiller la charge et la décharge des batteries du Rover.


**Étape 2 : Installation du panneau solaire sur le Rover martien**

Avant de commencer cette étape, nous devons disposer de notre modèle de Rover martien, d'un panneau solaire et des câbles nécessaires pour connecter le panneau solaire au système d'alimentation du Rover.

C'est un processus qui nous permet de mettre la théorie en pratique et d'apprécier véritablement le charme de l'éducation STEM (Science, Technologie, Ingénierie et Mathématiques). C'est parti !

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/-Vj-dcniFrA" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Étape 3 : Programmation pour surveiller la tension et la charge de la batterie**

Maintenant que nous avons installé les panneaux solaires sur notre modèle de Rover martien, l'étape suivante consiste à surveiller la tension et la charge de la batterie grâce à la programmation.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2e85e234-9575-4a1f-982b-2f9aba8e3156/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Ce code crée efficacement un simple moniteur de batterie, particulièrement utile dans des applications comme le Rover martien, où la gestion de l'alimentation est cruciale. Cela vous permettra de surveiller l'état de la batterie et de comprendre quand le Rover doit être rechargé ou quand des tâches gourmandes en énergie doivent être planifiées.

Décomposons les différentes parties de ce code :

* Cette ligne définit ``BATTERY_PIN`` comme la broche analogique A3, qui est l'endroit où la tension de la batterie sera lue.

    .. code-block:: arduino

        #define BATTERY_PIN A3

* Cette fonction calcule la tension de la batterie. Elle lit d'abord la valeur analogique de ``BATTERY_PIN``, puis la convertit en tension. Étant donné que le convertisseur analogique-numérique (ADC) de l'Arduino fonctionne sur une échelle de 0 à 1023, nous divisons la lecture brute par 1023. Nous multiplions ensuite par 5 (la tension de référence de l'Arduino) et par 2 (en supposant un diviseur de tension de 2) pour obtenir une lecture de la tension.

    .. code-block:: arduino
        :emphasize-lines: 5

        float batteryGetVoltage() {
            // Lit la valeur analogique de la broche de la batterie
            int adcValue = analogRead(BATTERY_PIN);
            // Convertit la valeur analogique en tension
            float adcVoltage = adcValue / 1023.0 * 5 * 2;
            // Arrondit la tension à deux décimales
            float batteryVoltage = int(adcVoltage * 100) / 100.0;
            return batteryVoltage;
        }

    La lecture brute de l'ADC est divisée par 1023 pour la convertir en fraction, puis multipliée par 5 pour la transformer en tension, car l'Arduino utilise une tension de référence de 5 volts.

    Cependant, étant donné que la tension de la batterie est supérieure à la tension d'entrée maximale de l'Arduino, une résistance est utilisée pour protéger l'Arduino. Nous multiplions donc la tension de l'ADC par 2 pour compenser l'effet de la résistance et obtenir la tension correcte de la batterie.

* Cette fonction calcule le pourcentage de charge de la batterie en fonction de sa tension. Elle utilise la fonction ``map`` pour « mapper » la valeur de tension (allant de 6,6 à 8,4 volts) à un pourcentage (allant de 0 à 100).

    .. code-block:: arduino

        uint8_t batteryGetPercentage() {
            float voltage = batteryGetVoltage();  // Obtient la tension de la batterie
            // Mappe la tension à un pourcentage.
            int16_t temp = map(voltage, 6.6, 8.4, 0, 100);
            // S'assure que le pourcentage est entre 0 et 100
            uint8_t percentage = max(min(temp, 100), 0);
            return percentage;
        }

**Étape 4 : Tester le système énergétique du Rover : sessions intérieures et extérieures**

Après avoir codé notre système de surveillance de la batterie, il est temps de mettre le Rover martien en action. 
Commencez par charger le Rover à pleine capacité, puis planifiez deux missions d'exploration de 30 minutes – l'une en intérieur et l'autre en extérieur, sous la lumière du soleil. Notez le niveau de la batterie avant chaque mission, 
et comparez-le avec le pourcentage de batterie à la fin de chaque test. 
Le tableau suivant vous servira de modèle utile pour suivre vos observations :



.. list-table:: Power Test
   :widths: 50 25 25
   :header-rows: 1

   * - 
     - Lumière solaire
     - En intérieur
   * - Pourcentage de batterie au départ
     - 
     - 
   * - Pourcentage de batterie à la fin
     - 
     - 

Observez la différence dans les niveaux de batterie après chaque test. La batterie du Rover a-t-elle duré plus longtemps lorsqu'il était sous la lumière du soleil ? Quelles conclusions pouvons-nous tirer de cette observation sur l'efficacité du panneau solaire ?

Comprendre ces variations nous aidera à mieux saisir comment l'énergie solaire peut efficacement alimenter un Rover martien, même dans des environnements aussi rudes et isolés que ceux de la surface martienne.

**Étape 5 : Afficher le niveau de la batterie sur l'application**

Il n'est évidemment pas pratique de téléverser à chaque fois du nouveau code sur le Rover martien juste pour vérifier le niveau de batterie restant. Ce serait assez contraignant.

À la place, nous pouvons envoyer le niveau de batterie à une application, nous permettant ainsi de suivre facilement combien de temps de jeu il nous reste tout en nous amusant !

Dans les leçons précédentes, nous avons appris que lorsque nous voulons afficher des données sur le SunFounder Controller ou contrôler le Rover martien à l'aide de widgets, il est nécessaire d'ajouter ces widgets au préalable.

Cependant, l'affichage du niveau de batterie est un widget spécial. Il possède une clé dédiée (``BV``) et son affichage ne se situe pas dans les zones étiquetées de A à Q. Il est plutôt représenté par une icône de batterie dans le coin supérieur droit.

Voici comment l'inclure dans notre code :

.. code-block:: Arduino

    ...
    // Cette broche lit la tension de la batterie
    #define BATTERY_PIN A3
    ...

    void setup() {
        ...
        // Définit la broche de la batterie comme entrée
        pinMode(BATTERY_PIN, INPUT);
    }

    // Fonction exécutée lors de la réception des données du contrôleur
    void onReceive() {
        ...
        // Afficher la tension de la batterie
        aiCam.sendDoc["BV"] = batteryGetVoltage();
    }

    ...

    // Cette fonction lit la tension de la batterie
    float batteryGetVoltage() {
        // Lit la valeur analogique de la broche de la batterie
        int adcValue = analogRead(BATTERY_PIN);
        // Convertit la valeur analogique en tension
        float adcVoltage = adcValue / 1023.0 * 5 * 2;
        // Arrondit la tension à deux décimales
        float batteryVoltage = int(adcVoltage * 100) / 100.0;
        return batteryVoltage;
    }

Veuillez trouver le code complet ci-joint :

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8b6e0dbd-6fcc-45ac-8408-e8aa706a4bf3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Une fois le code téléversé avec succès, lancez votre SunFounder Controller. Vous verrez le niveau de la batterie s'afficher dans le coin supérieur droit.

.. image:: img/battery_icon.png

En complétant cette étape, nous avons maîtrisé le système énergétique du Rover martien et acquis la capacité de surveiller ses niveaux d'énergie en temps réel.

Maintenant que nous avons appris à exploiter l'énergie du soleil pour faire fonctionner efficacement le Rover martien, nous pouvons commencer à planifier des explorations plus approfondies dans notre jardin ou même nous aventurer dans des terrains plus difficiles !

**Étape 6 : Réflexion**

Tout au long de cette leçon, nous nous sommes concentrés sur la compréhension du rôle crucial du système énergétique du Rover martien, et sur les mécanismes pour surveiller l'énergie restante du Rover. Le système énergétique basé sur les panneaux solaires ne se contente pas d'alimenter le Rover, il souligne également l'importance des sources d'énergie renouvelables dans l'exploration spatiale.

Avec les connaissances que vous avez maintenant, réfléchissez aux implications réelles de ce système. Envisagez les défis qu'un système d'énergie solaire pourrait rencontrer sur Mars. Comment les températures extrêmes, les tempêtes de poussière ou les longues périodes d'obscurité pourraient-elles affecter l'approvisionnement en énergie ? Quelles solutions pourriez-vous proposer pour relever ces défis ?

**Étape 7 : Perspectives**

Maintenant que nous avons donné à notre Rover martien la capacité de se déplacer, il est temps de le laisser commencer son voyage d'exploration ! Vous pouvez le laisser vagabonder sur divers terrains imitant l'environnement martien.

Par exemple, vous pouvez le laisser grimper sur un tas de pierres.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/move_stone.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Ou le laisser naviguer à travers une épaisse herbe.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/move_grass.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Ou le mettre sur un parcours de gravier parsemé de pierres.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/move_stone1.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Cependant, notez que si l'obstacle est trop élevé, le rover pourrait ne pas être capable de le franchir.

.. raw:: html

   <video width="400" height="400" loop autoplay muted>
      <source src="_static/video/move_failed.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Ces terrains variés présentent des défis uniques pour le Rover, tout comme ils le feraient pour un véritable Rover sur Mars. En observant votre Rover tenter de surmonter ces obstacles, vous vivrez une petite partie de ce que les scientifiques et ingénieurs de la NASA expérimentent lorsqu'ils envoient des rovers sur Mars !

Alors que nous concluons nos leçons sur le Rover martien, il est important de réfléchir à ce que nous avons appris. Nous espérons que ce voyage a non seulement élargi vos connaissances et compétences, mais aussi éveillé votre curiosité et votre désir d'explorer. Que votre Rover parcourt votre jardin ou les vastes étendues de votre imagination, les découvertes que vous ferez en chemin seront extraordinaires.
