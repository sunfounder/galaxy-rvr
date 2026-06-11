.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 7 : Améliorer la navigation du Rover avec un module à ultrasons
======================================================================

Lors de notre précédente aventure, nous avons équipé notre Mars Rover de « yeux » latéraux, lui permettant d’éviter les obstacles de manière simple. Cependant, il restait un angle mort juste devant lui — un défi que nous allons relever aujourd’hui !

Dans cette leçon, nous allons offrir à notre Rover un nouveau sens de la « vue ». Nous installerons un module à ultrasons qui jouera le rôle d’une paire d’yeux frontaux, permettant au rover de détecter les obstacles directement devant lui.

Nous découvrirons également le fonctionnement fascinant des ondes ultrasonores et verrons comment elles améliorent la capacité de notre Rover à se déplacer dans des environnements complexes. Grâce à cet ajout, notre Mars Rover sera plus attentif, plus agile et prêt à entreprendre des missions d’exploration encore plus ambitieuses.

Rejoignez-nous pour cette nouvelle étape passionnante de notre aventure STEAM et aidons notre Mars Rover à explorer encore plus efficacement les territoires inconnus !

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/ultrasonic_avoid.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la lecture de vidéos HTML5.
   </video>

.. note::

    Si vous suivez ce cours après avoir entièrement assemblé le GalaxyRVR, vous devez déplacer cet interrupteur vers la droite avant de téléverser le programme.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center


Objectifs du cours
--------------------------

* Comprendre le principe de la mesure de distance par ultrasons.
* Apprendre à utiliser un Arduino et un module à ultrasons pour mesurer des distances.
* Mettre en pratique l’utilisation du module à ultrasons pour l’évitement d’obstacles sur le modèle de Mars Rover.

Matériel nécessaire
---------------------

* Module à ultrasons
* Outils et accessoires de base (tournevis, vis, câbles, etc.)
* Modèle de Mars Rover (équipé du système rocker-bogie, des cartes principales, des moteurs et du module d’évitement d’obstacles)
* Câble USB
* Arduino IDE
* Ordinateur

Étapes du cours
--------------------

**Étape 1 : Assembler le module de capteur à ultrasons**

Maintenant que nous avons décidé d’équiper notre Mars Rover d’un nouveau système de « vision », il est temps d’assembler le module à ultrasons.

.. raw:: html

  <iframe width="600" height="400" src="https://www.youtube.com/embed/c_xWAVapGic?si=ovuxheXdGVpHopPa" title="Lecteur vidéo YouTube" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Et voilà ! Notre Mars Rover est maintenant équipé d’un module à ultrasons entièrement assemblé, prêt à l’aider à se déplacer avec encore plus d’intelligence. Curieux de découvrir comment cela va améliorer sa capacité à détecter les obstacles ? Alors continuons !

**Étape 2 : Découverte du module à ultrasons**

Faisons connaissance avec le HC-SR04, un puissant capteur de distance à ultrasons. Ce petit module est capable de mesurer avec précision des distances allant de 2 cm à 400 cm, sans aucun contact physique ! Impressionnant, n’est-ce pas ? C’est un peu comme un super-pouvoir ! Il peut « voir » les distances simplement grâce aux ondes sonores, tout comme les chauves-souris qui se déplacent dans l’obscurité.

Pour accomplir sa mission, il utilise quatre « super-pouvoirs », ou plus précisément quatre broches :

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG (Entrée de déclenchement)** — C’est le bouton de départ de notre super-héros. Cette broche lui indique : « C’est le moment d’envoyer une onde ultrasonore ! »
* **ECHO (Sortie d’écho)** — Grâce à cette broche, notre super-héros écoute le retour de l’onde sonore qu’il a envoyée.
* **VCC** — Même les super-héros ont besoin d’énergie ! Cette broche est reliée à une alimentation de 5 V.
* **GND** — La connexion à la masse. Après tout, même les super-héros doivent garder les pieds sur terre !

Imaginez maintenant notre super-héros, le capteur à ultrasons HC-SR04, en train de jouer au jeu de l’écho dans une vallée de montagne.

.. image:: img/ultrasonic_prin.jpg
    :width: 800

* Tout d’abord, le cerveau de notre super-héros, le microcontrôleur (MCU), lui donne le signal de départ en envoyant un niveau logique haut pendant au moins 10 microsecondes. C’est un peu comme lorsque nous prenons une grande inspiration avant de crier dans une vallée.
* Dès qu’il reçoit ce signal, notre super-héros émet rapidement huit impulsions ultrasonores à une fréquence de 40 kHz. En même temps, il démarre un chronomètre et se met à l’écoute d’un éventuel écho.
* Si un obstacle se trouve devant lui, les ondes ultrasonores le frappent et reviennent sous forme d’écho. Dès qu’il détecte cet écho, notre super-héros arrête son chronomètre et enregistre le temps écoulé. Il envoie également un signal logique haut au MCU pour indiquer qu’un écho a été reçu.
* Enfin, pour calculer la distance jusqu’à l’obstacle, notre super-héros applique une formule très simple : il prend le temps mesuré, le divise par deux, puis le multiplie par la vitesse du son (340 m/s). Le résultat correspond à la distance qui le sépare de l’obstacle.

C’est ainsi que notre capteur super-héros peut détecter la présence d’un obstacle et déterminer précisément à quelle distance il se trouve. Impressionnant, n’est-ce pas ? Dans la suite de cette leçon, nous allons apprendre à utiliser ce super-pouvoir sur notre Mars Rover !

**Étape 3 : Programmer notre capteur super-héros**

Maintenant que notre capteur super-héros est assemblé et que nous comprenons comment il utilise ses super-pouvoirs, il est temps de les mettre en action ! Écrivons un programme Arduino qui permettra à notre capteur à ultrasons de mesurer des distances et d'afficher les résultats.

Voici les principales étapes suivies par notre capteur super-héros :

* Nous avons connecté les broches **TRIG** et **ECHO** à la broche 10 du Shield GalaxyRVR. Cela nous permet de contrôler à la fois l'émission et la réception des signaux du module à ultrasons à l'aide d'une seule broche Arduino.

.. image:: img/ultrasonic_shield.png

.. code-block:: arduino

    // Définir la broche utilisée par le module à ultrasons
    #define ULTRASONIC_PIN 10

* **Préparation** : Pour commencer, nous établissons une communication série à 9600 bauds afin de pouvoir visualiser les mesures de notre super-héros dans le Moniteur Série.

.. code-block:: arduino

    void setup() {
        // Démarrer la communication série
        Serial.begin(9600);
    }

* **Lancer le cri !** : Nous configurons ``ULTRASONIC_PIN`` en mode ``OUTPUT`` afin d'envoyer une impulsion de 10 microsecondes. C'est comme si nous demandions à notre super-héros ultrasonique d'émettre un puissant cri (ondes ultrasonores) !

.. code-block:: arduino

    // Un délai de 4 ms est nécessaire, sinon la mesure peut être égale à 0
    delay(4);

    // Configurer la broche en sortie pour envoyer le signal
    pinMode(ULTRASONIC_PIN, OUTPUT);

    // Remettre la broche de déclenchement à l'état bas
    digitalWrite(ULTRASONIC_PIN, LOW);
    delayMicroseconds(2);

    // Déclencher le capteur avec une impulsion haute de 10 µs
    digitalWrite(ULTRASONIC_PIN, HIGH);
    delayMicroseconds(10);

    // Ramener la broche à l'état bas
    digitalWrite(ULTRASONIC_PIN, LOW);

* **Attendre et écouter** : Nous configurons ensuite ``ULTRASONIC_PIN`` en mode ``INPUT``. Notre capteur est alors prêt à écouter l'écho de son cri. Si un obstacle se trouve devant lui, l'onde sonore le percute et revient sous forme d'écho. Dès qu'il détecte cet écho, notre super-héros arrête son chronomètre, enregistre le temps écoulé et informe le MCU qu'un écho a été reçu.

.. code-block:: arduino

    pinMode(ULTRASONIC_PIN, INPUT);
    float duration = pulseIn(ULTRASONIC_PIN, HIGH);

* **Calcul de super-héros** : Une fois l'écho reçu, le capteur utilise la vitesse du son pour calculer la distance jusqu'à l'objet détecté. Nous divisons le temps mesuré par deux, car il inclut à la fois l'aller et le retour de l'onde sonore.

.. code-block:: arduino

    float distance = duration * 0.034 / 2;

* **Rapporter les résultats** : Notre capteur super-héros révèle ensuite le résultat de sa mission en affichant la distance mesurée dans le Moniteur Série.

.. code-block:: arduino

    // Afficher la distance dans le moniteur série
    Serial.print("La distance est de : ");
    Serial.print(distance);
    Serial.println(" cm");

* **Repos et préparation** : Même les super-héros ont besoin d'une pause ! Notre capteur attend brièvement avant de commencer une nouvelle mission. Cela lui permet de se réinitialiser avant la mesure suivante.

.. code-block:: arduino

    delay(200);

Voici le programme complet qui transforme notre capteur en véritable super-héros :

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/35bddbcf-145c-4e4f-b3ea-21e8210af4a6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Étape 4 : Programmer le module à ultrasons pour piloter le Mars Rover**

Maintenant que notre Mars Rover est équipé d'un module à ultrasons, il est temps de le programmer afin qu'il puisse réagir en fonction des mesures du capteur.

* Pour rendre le programme plus facile à comprendre, nous avons créé une fonction appelée ``readSensorData()``. Cette fonction regroupe tout le code nécessaire pour mesurer la distance à l'aide du capteur à ultrasons.

  .. code-block:: arduino

    float readSensorData() {
        // A 4ms delay is required, otherwise the reading may be 0
        delay(4);
      
        //Set to OUTPUT to send signal
        pinMode(ULTRASONIC_PIN, OUTPUT);
      
        // Clear the trigger pin
        digitalWrite(ULTRASONIC_PIN, LOW);
        delayMicroseconds(2);
      
        // Trigger the sensor by sending a high pulse for 10us
        digitalWrite(ULTRASONIC_PIN, HIGH);
        delayMicroseconds(10);
      
        // Set the trigger pin back to low
        digitalWrite(ULTRASONIC_PIN, LOW);
      
        //Set to INPUT to read
        pinMode(ULTRASONIC_PIN, INPUT);
      
        // pulseIn returns the duration of the pulse on the pin
        float duration = pulseIn(ULTRASONIC_PIN, HIGH);
      
        // Calculate the distance (in cm) based on the speed of sound (340 m/s or 0.034 cm/us)
        float distance = duration * 0.034 / 2;
      
        return distance;
    }

* Dans la fonction ``loop()``, nous appelons ``readSensorData()`` et stockons la valeur retournée dans la variable ``distance``.

  .. code-block:: arduino

    float distance = readSensorData();

* En fonction de cette distance, le Rover avancera, reculera ou s'arrêtera.

  .. code-block:: arduino
  
    // Contrôle du rover en fonction de la distance mesurée
    if (distance > 50) {  // Si la voie est dégagée
      moveForward(200);
    } else if (distance < 15) {  // Si un obstacle est très proche
      moveBackward(200);
      delay(500);  // Attendre un instant avant de tourner
      backLeft(150);
      delay(1000);
    } else {  // Pour les distances intermédiaires, avancer prudemment
      moveForward(150);
    }

  * Si la voie est libre (l'obstacle se trouve à plus de 50 cm), notre Rover avance avec assurance.
  * Si un obstacle se rapproche (à moins de 50 cm mais à plus de 15 cm), le Rover continue d'avancer mais à une vitesse réduite.
  * Si un obstacle est trop proche (à moins de 15 cm), le Mars Rover recule puis tourne vers la gauche.

  .. image:: img/ultrasonic_flowchart.png

Vous trouverez ci-dessous le programme complet. Téléversez-le sur la carte R3 et observez si le comportement obtenu correspond à vos attentes. Vous pouvez également ajuster les distances de détection en fonction de votre environnement afin d'améliorer encore les performances de ce système d'évitement d'obstacles.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cded6408-1469-4289-b79b-7d445b56352b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Grâce à ces nouvelles capacités, le Mars Rover est désormais mieux équipé pour détecter les obstacles sur son parcours, mesurer précisément les distances et prendre des décisions adaptées afin de les contourner. Cela réduit considérablement les risques de collision ou d'autres incidents susceptibles de compromettre sa mission d'exploration.

Avec ses nouveaux « super-sens », le Mars Rover peut évoluer avec davantage de confiance et d'efficacité, lui permettant d'explorer plus profondément les mystères de Mars et de collecter des données scientifiques précieuses pour les chercheurs sur Terre.

**Étape 5 : Résumé et réflexion**

Dans cette leçon, nous avons découvert le fonctionnement des ondes ultrasonores et appris à convertir leur temps de retour en une distance mesurable grâce à la programmation.

Nous avons ensuite utilisé cette technologie pour concevoir un système d'évitement d'obstacles. Ce système adapte son comportement en fonction de la distance qui le sépare de l'obstacle détecté.

Prenons maintenant un moment pour réfléchir à ce que nous avons appris à travers quelques questions :

* Comment un module à ultrasons mesure-t-il une distance ? Pouvez-vous expliquer le principe de fonctionnement ?
* En quoi le système d'évitement d'obstacles présenté dans cette leçon diffère-t-il de celui de la leçon précédente ? Quels sont les avantages et les limites de chacun ?
* Serait-il possible de combiner ces deux systèmes d'évitement d'obstacles ?

Réfléchir à ces questions vous aidera à mieux comprendre les concepts abordés et à imaginer comment les appliquer à d'autres projets. À très bientôt pour une nouvelle aventure !