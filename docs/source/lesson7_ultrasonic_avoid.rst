.. note::

    Bonjour et bienvenue dans la communauté des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !


Leçon 7 : Améliorer la navigation du Rover avec un module ultrason
========================================================================

Lors de notre dernière aventure, nous avons équipé notre Rover martien de "yeux" sur les côtés, créant ainsi un système basique d'évitement d'obstacles. Cependant, il reste un angle mort juste devant – un défi que nous sommes prêts à relever !

Aujourd'hui, dans cette leçon, nous allons donner à notre Rover une nouvelle capacité de "vision". Nous allons installer un module de capteur ultrasonique, qui agira comme une paire d'yeux centraux, permettant à notre Rover de détecter les obstacles directement en face de lui.

Nous explorerons les mécanismes fascinants des ondes ultrasoniques et découvrirons comment elles améliorent la capacité de notre Rover à naviguer sur des terrains complexes. Grâce à cette amélioration, notre Rover sera plus réactif et agile, prêt pour des missions exploratoires encore plus ambitieuses.

Rejoignez-nous pour faire un pas de plus dans ce passionnant voyage STEAM, et rendre notre Rover encore plus compétent pour explorer des territoires inconnus !


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/ultrasonic_avoid.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. note::

    Si vous suivez ce cours après avoir entièrement assemblé le GalaxyRVR, vous devez déplacer cet interrupteur vers la droite avant de téléverser le code.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center


Objectifs du cours
--------------------------

* Comprendre le principe de la mesure de distance par ultrasons.
* Apprendre à utiliser Arduino et un module ultrasonique pour mesurer des distances.
* S'exercer à utiliser le module ultrasonique pour l'évitement d'obstacles sur le modèle du Rover martien.

Matériel nécessaire
-----------------------

* Module ultrasonique
* Outils de base et accessoires (tournevis, vis, fils, etc.)
* Modèle du Rover martien (équipé du système Rocker-Bogie, cartes principales, moteurs, module d'évitement d'obstacles)
* Câble USB
* IDE Arduino
* Ordinateur

Étapes du cours
----------------------
**Étape 1 : Assembler le module de capteur ultrasonique**

Maintenant que nous sommes prêts à doter notre Rover martien d'un puissant nouveau sens de "vision", il est temps d'assembler le module de capteur ultrasonique.

.. raw:: html

  <iframe width="600" height="400" src="https://www.youtube.com/embed/c_xWAVapGic?si=ovuxheXdGVpHopPa" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Et voilà ! Notre Rover martien dispose désormais d'un module de capteur ultrasonique entièrement assemblé, prêt à l'aider à naviguer comme jamais auparavant. Êtes-vous prêt à découvrir comment cela change les capacités de détection d'obstacles de notre Rover ? Plongeons dans l'action !


**Étape 2 : Explorer le module ultrasonique**

Découvrons le HC-SR04, un capteur ultrasonique puissant. Ce petit appareil peut mesurer avec précision des distances allant de 2 cm à 400 cm, sans toucher quoi que ce soit ! Incroyable, non ? C'est comme avoir un super-pouvoir ! Il peut "voir" les distances en utilisant simplement des ondes sonores, un peu comme une chauve-souris qui navigue dans l'obscurité.

Il utilise quatre super-pouvoirs, ou plutôt, quatre broches pour accomplir ses merveilles :

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG (Entrée du déclencheur)** - C'est le bouton de départ de notre super-héros. Il lui dit : "Allez, c'est le moment d'envoyer une onde supersonique !"
* **ECHO (Sortie de l'écho)** - C'est ainsi que notre super-héros écoute l'écho de l'onde sonore qu'il a émise.
* **VCC** - Même les super-héros ont besoin d'énergie. Nous le connectons à une alimentation de 5V.
* **GND** - C'est la connexion à la terre. Comme les super-héros qui doivent rester ancrés à la réalité !

Imaginez notre super-héros, le capteur ultrasonique HC-SR04, jouant à l'écho dans les montagnes.

.. image:: img/ultrasonic_prin.jpg
    :width: 800

* D'abord, le cerveau de notre super-héros, le MCU, dit : "Prêt, feu, partez !" en envoyant un signal de niveau haut pendant au moins 10 microsecondes à notre super-héros. C'est comme si nous rassemblions notre énergie avant de crier dans une vallée.
* En entendant "Partez !", notre super-héros crie 8 fois très rapidement. Ce cri supersonique est émis à une vitesse de 40 kHz. Le super-héros démarre également un chronomètre et reste attentif au retour de l'écho.
* S'il y a un obstacle devant, le cri rebondit sur celui-ci et revient sous forme d'écho. En entendant cet écho, notre super-héros arrête le chronomètre et note le temps. Il envoie également un signal haut pour informer le MCU qu'il a entendu l'écho.
* Enfin, pour déterminer la distance à l'obstacle, notre super-héros utilise une formule simple. Il prend le temps enregistré sur le chronomètre, le divise par 2 et le multiplie par la vitesse du son (340 m/s). Le résultat est la distance à l'obstacle !

C'est ainsi que notre capteur super-héros peut déterminer s'il y a un obstacle sur son chemin et à quelle distance il se trouve. Impressionnant, non ? Ensuite, nous apprendrons comment utiliser ce super-pouvoir dans notre Rover martien !


**Étape 3 : Programmer notre capteur super-héros**

Maintenant que nous avons assemblé notre capteur super-héros et compris comment il utilise ses super-pouvoirs, il est temps de mettre ces pouvoirs en action ! Écrivons un programme Arduino pour permettre à notre capteur ultrasonique de mesurer des distances et de nous les montrer.

Voici les étapes clés que notre capteur suivra :

* Nous avons connecté les broches TRIG et ECHO à la broche 10 du bouclier GalaxyRVR. Cela nous permet de contrôler à la fois l'émission et la réception du module ultrasonique avec une seule broche Arduino.

.. image:: img/ultrasonic_shield.png

.. code-block:: arduino

    // Définir la broche pour le module ultrasonique
    #define ULTRASONIC_PIN 10

* **Préparation** : Pour commencer, nous établissons une communication série à un débit de 9600 bauds afin de pouvoir voir les mesures de notre super-héros dans le moniteur série.

.. code-block:: arduino

    void setup() {
        // Démarrer la communication série
        Serial.begin(9600);
    }

* **Crier !** : Nous définissons la broche ``ULTRASONIC_PIN`` comme une broche ``OUTPUT`` pour envoyer une impulsion de 10 microsecondes, comme si nous commandions à notre super-héros d'émettre un puissant cri (ondes sonores ultrasoniques) !

.. code-block:: arduino

    // Un délai de 4ms est nécessaire, sinon la lecture peut être nulle
    delay(4);

    // Régler en OUTPUT pour envoyer le signal
    pinMode(ULTRASONIC_PIN, OUTPUT);

    // Effacer la broche de déclenchement
    digitalWrite(ULTRASONIC_PIN, LOW);
    delayMicroseconds(2);

    // Déclencher le capteur en envoyant une impulsion haute pendant 10µs
    digitalWrite(ULTRASONIC_PIN, HIGH);
    delayMicroseconds(10);

    // Réinitialiser la broche de déclenchement à LOW
    digitalWrite(ULTRASONIC_PIN, LOW);

* **Attendre et écouter** : Nous réglons la broche ``ULTRASONIC_PIN`` sur INPUT. Ainsi, notre capteur super-héros est prêt à écouter l'écho de son cri. S'il y a un obstacle devant, le cri rebondit et revient sous forme d'écho. En entendant l'écho, notre super-héros arrête le chronomètre et note le temps. Il envoie également un signal haut pour informer le MCU qu'il a entendu l'écho.

.. code-block:: arduino

    pinMode(ULTRASONIC_PIN, INPUT);
    float duration = pulseIn(ULTRASONIC_PIN, HIGH);

* **Super calcul** : Avec l'écho reçu, notre capteur utilise la vitesse du son pour calculer la distance à l'objet. Nous divisons le temps total de l'écho par 2 car ce temps inclut à la fois le cri et l'attente de l'écho.

.. code-block:: arduino

    float distance = duration * 0.034 / 2;

* **Rapporter les résultats** : Notre capteur super-héros révèle ensuite le résultat de sa mission, en affichant la distance dans le moniteur série.

.. code-block:: arduino

    // Afficher la distance dans le moniteur série
    Serial.print("La distance est : ");
    Serial.print(distance);
    Serial.println(" cm");

* **Repos et préparation** : Chaque super-héros a besoin de repos, donc notre capteur prend une courte pause avant la prochaine mission. Cela permet au capteur de se "réinitialiser" avant de commencer une nouvelle mesure.

.. code-block:: arduino

    delay(200);

Voici le code complet qui transforme notre capteur en super-héros :

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/35bddbcf-145c-4e4f-b3ea-21e8210af4a6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Étape 4 : Programmer le module ultrasonique pour diriger le Rover martien**

Maintenant que nous avons équipé notre Rover martien d'un module de capteur ultrasonique, il est temps de le programmer pour réagir en fonction des mesures du capteur.

* Pour faciliter la lecture, nous avons créé une fonction appelée ``readSensorData()``. Cette fonction encapsule tout le code nécessaire pour lire la distance à partir du capteur ultrasonique.

  .. code-block:: arduino

    float readSensorData() {
        // Un délai de 4ms est nécessaire, sinon la lecture peut être nulle
        delay(4);
      
        // Régler en OUTPUT pour envoyer le signal
        pinMode(ULTRASONIC_PIN, OUTPUT);
      
        // Effacer la broche de déclenchement
        digitalWrite(ULTRASONIC_PIN, LOW);
        delayMicroseconds(2);
      
        // Déclencher le capteur en envoyant une impulsion haute pendant 10µs
        digitalWrite(ULTRASONIC_PIN, HIGH);
        delayMicroseconds(10);
      
        // Réinitialiser la broche de déclenchement à LOW
        digitalWrite(ULTRASONIC_PIN, LOW);
      
        // Régler en INPUT pour lire
        pinMode(ULTRASONIC_PIN, INPUT);
      
        // pulseIn renvoie la durée de l'impulsion sur la broche
        float duration = pulseIn(ULTRASONIC_PIN, HIGH);
      
        // Calculer la distance (en cm) en fonction de la vitesse du son (340 m/s ou 0,034 cm/µs)
        float distance = duration * 0.034 / 2;
      
        return distance;
    }

* Dans la fonction ``loop()``, nous appelons ``readSensorData()`` et stockons sa valeur renvoyée dans la variable ``distance``.

  .. code-block:: arduino

    float distance = readSensorData();

* En fonction de cette distance, le Rover avancera, reculera ou s'arrêtera.

  .. code-block:: arduino
  
    // Contrôler le rover en fonction de la lecture de distance
    if (distance > 50) {  // Si c'est sans danger d'avancer
      moveForward(200);
    } else if (distance < 15) {  // S'il y a un obstacle proche
      moveBackward(200);
      delay(500);  // Attendre un moment avant d'essayer de tourner
      backLeft(150);
      delay(1000);
    } else {  // Pour les distances intermédiaires, avancer prudemment
      moveForward(150);
    }

  * Si la voie est dégagée (l'obstacle est à plus de 50 cm), notre Rover avance avec assurance.
  * Et si un obstacle est proche (entre 15 et 50 cm), notre Rover avance à une vitesse plus faible.
  * Si un obstacle est trop proche (moins de 15 cm), le Rover recule puis tourne à gauche.

  .. image:: img/ultrasonic_flowchart.png

Voici le code complet. Vous pouvez téléverser ce code sur la carte R3 et voir s'il atteint l'effet souhaité. Vous pouvez également modifier la distance de détection en fonction de l'environnement réel pour rendre ce système d'évitement d'obstacles encore plus performant.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cded6408-1469-4289-b79b-7d445b56352b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



En utilisant ces capacités améliorées, le Rover martien sera mieux équipé pour identifier les obstacles potentiels sur son chemin, mesurer les distances avec précision et prendre des décisions éclairées pour les éviter. Cela réduira considérablement les risques de collisions ou d'autres dangers susceptibles de freiner la mission d'exploration du Rover.

Grâce à ses super-capteurs, le Rover martien peut opérer avec plus de confiance et d'efficacité, lui permettant d'explorer en profondeur les mystères de Mars et de recueillir des données scientifiques précieuses pour les chercheurs sur Terre.


**Étape 5 : Résumé et réflexion**

Dans cette leçon, nous avons exploré le fonctionnement des ondes ultrasoniques et comment traduire leur temps de retour en une distance mesurable grâce à la programmation.

Ensuite, nous avons utilisé ces ondes ultrasoniques pour concevoir un système d'évitement d'obstacles. Ce système particulier ajuste ses réponses en fonction de la distance par rapport à l'obstacle imminent.

Réfléchissons à cette leçon avec quelques questions :

* Comment un module ultrasonique détecte-t-il la distance ? Pouvez-vous expliquer le concept sous-jacent ?
* En quoi le système d'évitement d'obstacles de cette leçon diffère-t-il de celui de la leçon précédente ? Quels sont leurs avantages et inconvénients respectifs ?
* Est-il possible de combiner ces deux systèmes d'évitement d'obstacles ?

Répondre à ces questions nous aidera à renforcer notre compréhension et à envisager l'application de ces concepts à d'autres projets. À bientôt pour notre prochaine aventure !
