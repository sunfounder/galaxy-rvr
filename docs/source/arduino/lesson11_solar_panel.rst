.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 11 : Exploration du système énergétique du Mars Rover
===========================================================

Bienvenue dans la dernière leçon de notre aventure d'exploration du Mars Rover. Cette fois-ci, nous allons nous intéresser au cœur même du Rover : son système énergétique.

Lorsque l'on pense à l'exploration de planètes lointaines comme Mars, l'un des aspects les plus importants à considérer est l'énergie.

Comment ces rovers parviennent-ils à s'alimenter dans des environnements aussi hostiles et isolés ?

Dans cette leçon, nous allons explorer ce sujet fascinant et découvrir comment les rovers, comme notre modèle de Mars Rover, produisent, stockent et gèrent leur énergie.

Nous étudierons le fonctionnement des batteries et des panneaux solaires, puis nous passerons à la pratique en installant et en utilisant ces sources d'énergie sur notre modèle de Rover.

Enfin, nous irons encore plus loin en utilisant Arduino pour surveiller le niveau de charge de la batterie.

.. image:: img/solar_panel.jpg
    :width: 600
    :align: center

Objectifs d'apprentissage
-------------------------

* Comprendre le principe de fonctionnement des batteries et des panneaux solaires.
* S'exercer à installer le panneau solaire sur le modèle de Mars Rover.
* Apprendre à utiliser Arduino pour surveiller le niveau de la batterie et l'état de charge du panneau solaire.

Matériel nécessaire
------------------------

* Modèle de Mars Rover (équipé de tous les composants, à l'exception du panneau solaire et de la plaque inférieure)
* Panneau solaire et plaque inférieure
* Arduino IDE
* Ordinateur

Étapes du cours
----------------------

**Étape 1 : Introduction au système énergétique du Mars Rover**

Tout comme notre corps a besoin d'un apport constant en énergie pour fonctionner, notre Mars Rover a besoin d'un système capable de stocker et de produire l'énergie nécessaire à ses missions d'exploration.

Imaginez le système énergétique du Rover comme le cœur de notre corps. De la même manière que notre cœur pompe le sang dans tout notre organisme pour fournir oxygène et nutriments, le système énergétique du Rover distribue l'énergie à chacun de ses composants afin qu'il puisse accomplir ses tâches efficacement.

Les principaux éléments de ce système sont les batteries et les panneaux solaires, qui travaillent ensemble pour permettre au Rover de fonctionner de jour comme de nuit.

Le rôle des batteries est comparable à celui des réserves d'énergie de notre corps. Tout comme nous stockons de l'énergie pour l'utiliser lorsque nous en avons besoin, le Rover emmagasine de l'énergie pour ses missions d'exploration.

L'énergie stockée dans les batteries est ensuite distribuée en permanence aux différents systèmes du Rover afin de lui permettre de fonctionner correctement.

.. image:: img/battery_galaxyrvr.png
    :width: 600
    :align: center

Mais que se passe-t-il lorsque les batteries se déchargent ? Comment le Rover reconstitue-t-il ses réserves d'énergie ?

C'est là que les panneaux solaires entrent en jeu.

Tout comme les plantes utilisent la lumière du Soleil pour réaliser la photosynthèse et produire leur nourriture, notre Mars Rover utilise des panneaux solaires pour capter l'énergie solaire et la transformer en électricité qui sera stockée dans les batteries.

Chaque panneau solaire est composé de nombreuses cellules photovoltaïques. Ces cellules sont fabriquées à partir de matériaux capables de transformer la lumière en électricité grâce à un phénomène appelé **effet photovoltaïque**.

Lorsque la lumière du Soleil frappe ces cellules, elles produisent un courant électrique qui peut être utilisé immédiatement ou stocké dans les batteries du Rover pour une utilisation ultérieure.

.. image:: img/solar_panel_gala.png
    :width: 600
    :align: center

Cependant, exploiter l'énergie solaire sur Mars n'est pas aussi simple qu'il n'y paraît.

Les tempêtes de poussière peuvent réduire considérablement la quantité de lumière atteignant les panneaux solaires, et l'ensoleillement martien est plus faible que celui de la Terre. Les panneaux produisent donc moins d'énergie qu'ils ne le feraient chez nous.

Malgré ces défis, l'énergie solaire reste la solution la plus pratique et la plus efficace pour alimenter notre Mars Rover.

Mais comment savoir si les panneaux solaires fonctionnent correctement ou si les batteries commencent à se décharger ?

C'est ici qu'intervient Arduino.

Dans la prochaine section, nous allons apprendre à utiliser Arduino pour surveiller la charge et la décharge des batteries du Rover.

**Étape 2 : Installation du panneau solaire sur le Mars Rover**

Avant de commencer cette étape, assurez-vous de disposer du modèle de Mars Rover, du panneau solaire et des câbles nécessaires pour relier le panneau solaire au système d'alimentation du Rover.

Cette étape nous permet de mettre la théorie en pratique et d'apprécier pleinement l'intérêt des disciplines STEM (Science, Technologie, Ingénierie et Mathématiques).

Commençons !

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/-Vj-dcniFrA" title="Lecteur vidéo YouTube" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Étape 3 : Programmer la surveillance de la tension et de la charge de la batterie**

Maintenant que nous avons installé les panneaux solaires sur notre modèle de Mars Rover, l'étape suivante consiste à surveiller la tension et le niveau de charge de la batterie grâce à la programmation.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2e85e234-9575-4a1f-982b-2f9aba8e3156/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Ce programme crée un moniteur de batterie simple mais très utile, particulièrement dans des projets comme le Mars Rover où la gestion de l'énergie est essentielle.

Il vous permettra de surveiller l'état de la batterie et de mieux comprendre à quel moment le Rover doit être rechargé ou quand certaines tâches gourmandes en énergie doivent être planifiées.

Décomposons maintenant les différentes parties du programme :

* Cette ligne définit ``BATTERY_PIN`` comme la broche analogique A3, qui servira à mesurer la tension de la batterie.

    .. code-block:: arduino

        #define BATTERY_PIN A3

* Cette fonction calcule la tension de la batterie. Elle commence par lire la valeur analogique provenant de ``BATTERY_PIN``, puis la convertit en tension.

  Comme le convertisseur analogique-numérique (ADC) de l'Arduino fonctionne sur une échelle de 0 à 1023, nous divisons la valeur brute par 1023. Nous multiplions ensuite le résultat par 5 (la tension de référence de l'Arduino) puis par 2 (en supposant l'utilisation d'un diviseur de tension de rapport 2) afin d'obtenir la tension réelle de la batterie.

    .. code-block:: arduino
        :emphasize-lines: 5

        float batteryGetVoltage() {
            // Lit la valeur analogique de la batterie
            int adcValue = analogRead(BATTERY_PIN);
            // Convertit la valeur analogique en tension
            float adcVoltage = adcValue / 1023.0 * 5 * 2;
            // Arrondit la tension à deux décimales
            float batteryVoltage = int(adcVoltage * 100) / 100.0;
            return batteryVoltage;
        }

    La valeur brute provenant du convertisseur analogique-numérique de l'Arduino est divisée par 1023 afin d'obtenir une proportion, puis multipliée par 5 puisque l'Arduino utilise une tension de référence de 5 volts.

    Cependant, comme la tension de la batterie est supérieure à la tension maximale admissible sur une entrée analogique de l'Arduino, un réseau de résistances est utilisé pour protéger la carte. Nous multiplions donc la tension calculée par 2 afin de compenser l'effet du diviseur de tension et retrouver la tension réelle de la batterie.

* Cette fonction calcule le pourcentage de charge de la batterie à partir de sa tension. Elle utilise la fonction ``map`` pour convertir (« mapper ») la plage de tension comprise entre 6,6 V et 8,4 V en un pourcentage compris entre 0 % et 100 %.

    .. code-block:: arduino

        uint8_t batteryGetPercentage() {
            float voltage = batteryGetVoltage();  // Gets the battery voltage
            // Maps the voltage to a percentage.
            int16_t temp = map(voltage, 6.6, 8.4, 0, 100);
            // Ensures the percentage is between 0 and 100
            uint8_t percentage = max(min(temp, 100), 0);
            return percentage;
        }

**Étape 4 : Mettre à l'épreuve le système énergétique du Mars Rover : essais en intérieur et en extérieur**

Maintenant que nous avons programmé notre système de surveillance de la batterie, il est temps de mettre notre Mars Rover en action.

Commencez par charger complètement le Rover, puis prévoyez deux missions d'exploration de 30 minutes : l'une en intérieur et l'autre en extérieur sous la lumière du Soleil.

Avant chaque mission, notez le pourcentage de batterie initial, puis comparez-le au pourcentage restant à la fin de l'essai.

Le tableau suivant constitue un modèle pratique pour enregistrer vos résultats :

.. list-table:: Test d'autonomie
   :widths: 50 25 25
   :header-rows: 1

   * -
     - En plein soleil
     - En intérieur
   * - Pourcentage de batterie au départ
     -
     -
   * - Pourcentage de batterie à l'arrivée
     -
     -

Observez les différences de niveau de batterie après chaque test.

La batterie du Rover a-t-elle duré plus longtemps lorsqu'il évoluait sous la lumière du Soleil ?

Quelles conclusions pouvez-vous tirer concernant l'efficacité du panneau solaire à partir de cette observation ?

Comprendre ces différences nous aide à mieux saisir comment l'énergie solaire peut alimenter efficacement un Mars Rover, même dans des environnements éloignés et difficiles comme la surface martienne.

**Étape 5 : Réflexion**

Au cours de cette leçon, nous avons étudié le rôle essentiel du système énergétique du Mars Rover ainsi que les moyens de surveiller son niveau d'énergie restant.

Le système énergétique basé sur les panneaux solaires ne se contente pas d'alimenter le Rover ; il met également en évidence l'importance des sources d'énergie renouvelables dans l'exploration spatiale.

Avec les connaissances que vous possédez désormais, réfléchissez aux implications réelles de ce système.

Pensez aux défis qu'un système alimenté par l'énergie solaire pourrait rencontrer sur Mars.

Comment les températures extrêmes, les tempêtes de poussière ou les longues périodes d'obscurité pourraient-elles affecter l'approvisionnement en énergie ?

Quelles solutions proposeriez-vous pour surmonter ces obstacles ?

**Étape 6 : Aller plus loin**

Maintenant que notre Mars Rover est capable de se déplacer, il est temps de le laisser commencer sa véritable mission d'exploration !

Vous pouvez le faire évoluer sur différents terrains reproduisant les conditions que l'on pourrait rencontrer sur Mars.

Par exemple, vous pouvez le faire grimper sur un tas de pierres.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/move_stone.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la lecture de vidéos HTML5.
   </video>

Ou le faire traverser une zone couverte d'herbe épaisse.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/move_grass.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la lecture de vidéos HTML5.
   </video>

Ou encore le faire évoluer sur un terrain gravillonné rempli de pierres.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/move_stone1.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la lecture de vidéos HTML5.
   </video>

Attention toutefois : si l'obstacle est trop élevé, le Rover risque de ne pas pouvoir le franchir.

.. raw:: html

   <video width="400" height="400" loop autoplay muted>
      <source src="../_static/video/move_failed.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la lecture de vidéos HTML5.
   </video>

Chacun de ces terrains présente des défis particuliers pour le Rover, tout comme ceux rencontrés par les véritables rovers martiens.

En observant votre Rover tenter de franchir ces obstacles, vous vivez une petite partie du travail réalisé par les scientifiques et ingénieurs de la NASA lorsqu'ils envoient des rovers explorer Mars !

Alors que nous arrivons à la fin de ces leçons consacrées au Mars Rover, il est important de prendre un moment pour réfléchir à tout ce que nous avons appris.

Nous espérons que cette aventure vous a non seulement permis d'acquérir de nouvelles connaissances et compétences, mais qu'elle a également éveillé votre curiosité et votre envie d'explorer.

Que votre Rover parcoure votre jardin ou les vastes étendues de votre imagination, les découvertes que vous ferez en chemin seront certainement extraordinaires.