.. note::

    Bonjour, bienvenue dans la communauté SunFounder des passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Soyez parmi les premiers à découvrir les nouvelles annonces de produits et obtenez des avant-premières.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Leçon 5 : Développer la Mobilité du Rover Martien
======================================================

Préparez-vous, jeunes explorateurs ! Nous avons maîtrisé le contrôle des moteurs, et maintenant, nous allons appliquer ces compétences sur la planète rouge. Dans cette leçon, nous allons donner vie à notre rover martien !

Nous apprendrons à assembler les moteurs dans le système de suspension Rocker-Bogie et, grâce à nos compétences en codage, nous guiderons notre rover à travers des paysages martiens imaginaires.

C'est une aventure martienne en classe. Allons-y !

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. note::

    Si vous suivez ce cours après avoir entièrement assemblé le GalaxyRVR, vous devez déplacer cet interrupteur vers la droite avant de télécharger le code.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Objectifs d'apprentissage
-----------------------------

* Comprendre comment assembler les moteurs dans le système de suspension Rocker-Bogie du rover martien.
* Apprendre à utiliser Arduino pour contrôler le mouvement du rover martien.
* S'exercer à écrire un programme pour contrôler le mouvement du rover sur différents terrains.

Matériel nécessaire
----------------------------
* Carte SunFounder R3
* Moteurs TT
* Shield GalaxyRVR
* Batterie
* Modèle de Rover martien (équipé du système Rocker-Bogie)
* Outils de base et accessoires (tournevis, vis, etc.)
* Câble USB
* IDE Arduino
* Ordinateur

Étapes
--------------

**Étape 1 : Assemblage des composants du Rover**

Dans cette étape, nous allons assembler la batterie, la carte R3, le Shield GalaxyRVR, les moteurs et les roues sur le système Rocker-Bogie pré-assemblé. Cela rendra le GalaxyRVR opérationnel.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/lu8K26MY96s" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Félicitations ! Nous avons réussi à construire notre propre rover, et il est prêt à explorer. Allons-y !

**Étape 2 : Mettre le Rover en Mouvement**

Il est maintenant temps de donner vie à notre création et de l'envoyer dans sa première aventure. 
Mais comment communiquer avec notre rover ? Comment lui dire où aller et quoi faire ? 
C'est là que nos compétences en codage entrent en jeu !

Dans la réalité, si nous voulons qu'une voiture avance, nous appuyons sur l'accélérateur, et les deux roues commencent à tourner. 
Les roues du côté droit tournent dans le sens des aiguilles d'une montre, tandis que celles du côté gauche tournent dans le sens inverse.

.. image:: img/move_car.gif
    :align: center

Imaginez que vous êtes assis au volant, le monde défilant autour de vous tandis que vous parcourez la route – c'est exactement l'expérience que nous allons offrir à notre rover.

Maintenant, traduisons cette expérience dans le langage que notre rover comprend – le code !

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Définir les broches des moteurs 
        const int in1 = 2;
        const int in2 = 3;
        const int in3 = 4;
        const int in4 = 5;

        void setup() {
            // Initialiser SoftPWM
            SoftPWMBegin();
        }

        void loop() {
            // Faire tourner les moteurs gauches dans le sens inverse des aiguilles d'une montre
            SoftPWMSet(in1, 255);  // Vitesse maximale
            SoftPWMSet(in2, 0);    // Arrêt
            
            // Faire tourner les moteurs droits dans le sens des aiguilles d'une montre
            SoftPWMSet(in3, 0);    // Arrêt
            SoftPWMSet(in4, 255);  // Vitesse maximale
            
        }

Dans ce code, nous parlons à notre rover en lui indiquant exactement quoi faire. 
Avec la fonction ``SoftPWMSet()``, nous agissons comme l'accélérateur et les freins de la voiture, 
en contrôlant la vitesse et la direction de chaque moteur. 
Nous disons aux moteurs gauches de tourner dans le sens inverse des aiguilles d'une montre et aux moteurs droits de tourner dans le sens des aiguilles d'une montre, et voilà, notre rover avance !

Effectivement, le concept de faire reculer le rover est simple une fois que vous comprenez comment le faire avancer.
Pour faire reculer le rover, nous devons simplement inverser le sens de rotation de chaque moteur. 

Voici comment nous le faisons en code : nous faisons exactement l'opposé. Les roues droites doivent maintenant tourner dans le sens inverse des aiguilles d'une montre, et les roues gauches doivent tourner dans le sens des aiguilles d'une montre.

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Définir les broches des moteurs 
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialiser SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Faire tourner les moteurs gauches dans le sens des aiguilles d'une montre
        SoftPWMSet(in1, 0);    // Arrêt
        SoftPWMSet(in2, 255);  // Vitesse maximale

        // Faire tourner les moteurs droits dans le sens inverse des aiguilles d'une montre
        SoftPWMSet(in3, 255);  // Vitesse maximale
        SoftPWMSet(in4, 0);    // Arrêt
        
    }

Dans ce code, nous utilisons ``SoftPWMSet()`` pour indiquer aux moteurs gauches de tourner dans le sens des aiguilles d'une montre et aux moteurs droits de tourner dans le sens inverse des aiguilles d'une montre.

N'est-ce pas fascinant de voir que nous pouvons contrôler le parcours de notre rover simplement avec du code ? La prochaine fois que vous serez dans une voiture, pensez au voyage de votre rover, explorant le monde une rotation à la fois. Restez à l'écoute, car le voyage de notre rover ne fait que commencer !

**Étape 3 : Faire Bouger le Rover dans D'autres Directions**

Maintenant que nous savons comment déplacer notre rover martien en avant et en arrière, que faire si nous voulons le faire tourner à gauche ou à droite ?

Tout comme dans la conduite réelle, il existe deux façons principales pour une voiture de tourner à gauche.

* La première consiste à faire tourner les roues du côté gauche plus lentement que celles du côté droit. Cette différence de vitesse fera tourner le rover vers la gauche.
* La deuxième consiste à faire tourner les moteurs gauche et droit dans la même direction (dans le sens des aiguilles d'une montre dans ce cas), ce qui fera tourner le rover sur son axe.

Voyons comment nous pouvons implémenter ces deux méthodes en code :

**Méthode 1 : Différentes vitesses de chaque côté**

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Définir les broches des moteurs 
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialiser SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Faire tourner les moteurs gauches dans le sens inverse à faible vitesse
        SoftPWMSet(in1, 40);
        SoftPWMSet(in2, 0);

        // Faire tourner les moteurs droits dans le sens des aiguilles d'une montre à plus grande vitesse
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 200);

        delay(2000);  // Dure 2 secondes
    }

Dans ce code, nous avons réduit la vitesse des moteurs gauches tout en maintenant les moteurs droits à une vitesse plus élevée. Cela fera tourner le rover vers la gauche.

**Méthode 2 : Faire tourner tous les moteurs dans la même direction**

.. code-block:: arduino
    :emphasize-lines: 16,17,18,19

    #include <SoftPWM.h>

    // Définir les broches des moteurs
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialiser SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Faire tourner tous les moteurs dans le sens des aiguilles d'une montre
        SoftPWMSet(in1, 0);
        SoftPWMSet(in2, 255);
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 255);
    }

Dans ce code, nous faisons tourner tous les moteurs dans le sens des aiguilles d'une montre. Le rover tournera autour de son propre axe et changera de direction vers la gauche.

Pour faire tourner le rover à droite, les concepts sont les mêmes, mais les directions sont inversées. Saurez-vous comment le faire ?

**Étape 4 : Se Déplacer dans Toutes les Directions**

À mesure que nous développons plus de fonctionnalités pour notre rover martien, notre code pourrait devenir assez long et désordonné. En programmation, il est bon de garder son code organisé et maintenable. Une façon d'y parvenir est de créer des fonctions séparées pour chaque tâche.

Dans ce cas, nous pouvons créer des fonctions séparées pour chaque direction dans laquelle le rover peut se déplacer. Cela rend notre code plus facile à comprendre et nous permet de réutiliser ces fonctions n'importe où dans notre programme sans avoir à réécrire les mêmes lignes de code.

Voyons comment faire cela :

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/90c13522-9757-4212-b250-63ffbc790fd3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Avec cette structure, notre boucle principale reste simple et facile à suivre. On peut voir clairement que le rover avance, recule, 
tourne à gauche, à droite, et s'arrête.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Les détails de chaque action sont cachés dans des fonctions séparées. C'est un aspect clé des bonnes pratiques de programmation appelé abstraction.

**Étape 5 : Partage et Réflexion**

Félicitations pour avoir terminé cette aventure avec le rover martien ! C'est une application pratique de vos connaissances en science et en ingénierie, et vous avez fait un travail fantastique !

Vous pouvez maintenant montrer comment votre rover surmonte divers obstacles de terrain. Vous pouvez filmer votre rover naviguant sur différents terrains, ou montrer votre rover à vos amis.

Réfléchir à votre processus d'apprentissage est également très important. Qu'avez-vous appris au cours de ce processus ? De nouvelles idées ou pensées créatives ont-elles émergé ? Qu'avez-vous appris en matière de contrôle des moteurs et de programmation ?

Continuez à explorer, à découvrir de nouvelles connaissances et à vous améliorer constamment. Continuez comme ça, futurs scientifiques et ingénieurs !
