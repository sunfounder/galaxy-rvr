.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 5 : Libérer la mobilité du Mars Rover
======================================================

Préparez-vous, jeunes explorateurs ! Nous avons maîtrisé le contrôle des moteurs, maintenant nous allons appliquer ces compétences à la planète rouge. Dans cette leçon, nous donnerons vie au Mars Rover !

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. note::

    Si vous suivez ce cours après avoir entièrement assemblé le GalaxyRVR, vous devez déplacer cet interrupteur vers la droite avant de téléverser le code.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Objectifs d'apprentissage
---------------------------
* Comprendre comment assembler les moteurs dans le système de suspension Rocker-Bogie.
* Apprendre à utiliser Arduino pour contrôler le mouvement du Mars Rover.
* S'exercer à écrire un programme pour contrôler le mouvement du rover sur différents terrains.

Matériel nécessaire
--------------------------
* Carte SunFounder R3, Moteurs TT, GalaxyRVR Shield, Batterie
* Modèle Mars Rover (équipé du système Rocker-Bogie)
* Câble USB, Arduino IDE, Ordinateur

Étapes
--------------

**Étape 1 : Assemblage des composants du Rover**

Assemblez la batterie, la carte R3, le Shield, les moteurs et les roues sur le système rocker-bogie pré-assemblé.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/lu8K26MY96s" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Étape 2 : Mettre le Rover en mouvement**

Pour avancer, les moteurs droits tournent en sens horaire et les gauches en sens antihoraire.

.. code-block:: arduino

    #include <SoftPWM.h>
    const int in1 = 2; const int in2 = 3;
    const int in3 = 4; const int in4 = 5;
    void setup() { SoftPWMBegin(); }
    void loop() {
        SoftPWMSet(in1, 255); SoftPWMSet(in2, 0);  // Gauche antihoraire
        SoftPWMSet(in3, 0);   SoftPWMSet(in4, 255); // Droite horaire
    }

Pour reculer, inversez le sens de rotation : les gauches en horaire, les droites en antihoraire.

**Étape 3 : Déplacer le Rover dans d'autres directions**

Deux méthodes pour tourner à gauche :
1. Réduire la vitesse des moteurs gauches tout en maintenant les droits à pleine vitesse.
2. Faire tourner tous les moteurs dans le même sens (horaire).

**Étape 4 : Se déplacer dans toutes les directions**

Créez des fonctions séparées pour chaque direction (``moveForward()``, ``moveBackward()``, ``turnLeft()``, ``turnRight()``, ``stopMove()``). Cela rend le code plus organisé et réutilisable.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/90c13522-9757-4212-b250-63ffbc790fd3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Étape 5 : Partage et réflexion**

Félicitations ! Votre rover peut maintenant naviguer sur différents terrains. Continuez à explorer, à découvrir et à vous améliorer !
