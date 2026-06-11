.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Leçon 6 : Explorer le module d'évitement d'obstacles
==============================================================

Nous plongeons dans le monde du module d'évitement d'obstacles infrarouge. Placés sur les côtés de notre Mars Rover, ces capteurs agissent comme les "yeux" du rover, l'aidant à esquiver les obstacles latéraux.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_ir1.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. note::

    Si vous suivez ce cours après avoir entièrement assemblé le GalaxyRVR, déplacez l'interrupteur vers la droite avant de téléverser le code.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Objectifs d'apprentissage
-------------------------
* Comprendre le principe de fonctionnement du module d'évitement d'obstacles infrarouge.
* Apprendre à utiliser Arduino pour contrôler le module.
* Concevoir un système automatique d'évitement d'obstacles.

Matériel nécessaire
---------------------
* Modules d'évitement d'obstacles
* Modèle Mars Rover (avec système rocker-bogie, cartes, moteurs)
* Câble USB, Arduino IDE, Ordinateur

Étapes
-------------
**Étape 1 : Installer le module d'évitement d'obstacles**

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/UWEj_ROYAt0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Étape 2 : Démystifier le module**

.. image:: img/ir_avoid.png
    :width: 300
    :align: center

Définitions des broches :
* **GND** : Masse
* **+** : Alimentation, 3.3~5V DC
* **Out** : Reste haut par défaut, passe à bas lorsqu'un obstacle est détecté
* **EN** : Broche d'activation, connectée à GND par défaut (module toujours actif)

Le module utilise une paire de composants IR - un émetteur et un récepteur. L'émetteur envoie une lumière infrarouge ; lorsqu'elle rencontre un obstacle, elle est réfléchie vers le récepteur. Le module émet alors un signal bas.

.. image:: img/ir_receive.png
    :align: center

Deux potentiomètres permettent de régler la puissance et la fréquence d'émission pour ajuster la distance de détection.

.. image:: img/ir_avoid_pot.png
    :width: 400
    :align: center

**Étape 3 : Lire les 2 modules**

Notre rover est équipé de deux capteurs sur les broches 7 (droit) et 8 (gauche).

.. code-block:: arduino

    #define IR_RIGHT 7
    #define IR_LEFT 8
    void setup() {
        pinMode(IR_RIGHT, INPUT);
        pinMode(IR_LEFT, INPUT);
        Serial.begin(9600);
    }
    void loop() {
        int rightValue = digitalRead(IR_RIGHT);
        int leftValue = digitalRead(IR_LEFT);
        Serial.print("Right IR: "); Serial.println(rightValue);
        Serial.print("Left IR: "); Serial.println(leftValue);
        delay(200);
    }

Ouvrez le moniteur série à 9600 bauds pour voir les valeurs. 0 = obstacle détecté, 1 = chemin libre.

**Étape 4 : Réglage de la distance de détection**

Calibrez les modules en plaçant un obstacle à 20 cm et en tournant le potentiomètre jusqu'à ce que l'indicateur s'allume.

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
    </video>
    <video width="600" loop autoplay muted>
        <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
    </video>

**Étape 5 : Concevoir un système automatique d'évitement**

Logique : Si le capteur droit détecte → tourner arrière droit. Si le gauche détecte → tourner arrière gauche. Les deux → reculer. Aucun → avancer.

.. image:: img/ir_flowchart.png

Le code utilise des instructions ``if...else if...else`` pour implémenter cette logique.

**Étape 6 : Réflexion et résumé**

Notre rover évite bien les obstacles latéraux mais peut avoir des difficultés avec les petits obstacles frontaux. Dans la prochaine leçon, nous ajouterons un capteur à ultrasons pour résoudre ce problème !
