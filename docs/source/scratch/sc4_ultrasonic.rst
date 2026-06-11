.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 4 : Le module ultrasonique
================================

Donnez à votre GalaxyRVR le pouvoir de « voir » avec le son !

Découvrez comment les capteurs ultrasoniques fonctionnent comme l'écholocalisation des chauves-souris – en émettant des ondes sonores et en écoutant leurs échos pour détecter les obstacles et mesurer les distances.

Rendez votre Rover Martien plus intelligent et plus sûr dans ses explorations !

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/ultrasonic_avoid.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>

Objectifs d'apprentissage
-------------------------

* Découvrir comment les capteurs ultrasoniques utilisent les ondes sonores pour mesurer la distance
* Apprendre à lire les mesures de distance avec l'application Mammoth Coding
* Programmer votre GalaxyRVR pour éviter les obstacles à l'aide du capteur ultrasonique

Découvrir le module ultrasonique
---------------------------------

Voici le capteur ultrasonique HC-SR04 – le nouveau « super-pouvoir » de votre rover pour voir les distances sans rien toucher ! Tout comme les chauves-souris utilisent le son pour se repérer, cet appareil ingénieux peut détecter des objets situés entre 2 cm et 400 cm de distance.

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

**Les quatre broches importantes :**

* **TRIG** – Le « bouton de démarrage » qui ordonne au capteur d'émettre des ondes sonores
* **ECHO** – Écoute l'écho renvoyé par les objets
* **VCC** – Alimentation électrique (nécessite 5 V)
* **GND** – Masse (ferme le circuit)

**Comment ça marche – Le jeu de l'écho :**

.. image:: img/ultrasonic_prin.jpg
    :width: 800

1. **ÉMISSION** – Le capteur envoie 8 ondes sonores rapides (trop aiguës pour nos oreilles !)
2. **ÉCOUTE** – Il déclenche un chronomètre et attend le retour de l'écho
3. **CALCUL** – À partir du temps d'écho, il calcule : Distance = (Temps × Vitesse du son) ÷ 2

C'est comme crier dans un canyon et compter le temps que met l'écho à revenir. Plus l'attente est longue, plus la paroi est éloignée !

Maintenant, offrons ce super-pouvoir à votre Rover Martien !

Tester le capteur ultrasonique
------------------------------

#. Commencez par :ref:`app_connect`.

2. Trouvez le bloc « distance en cm » dans la catégorie GalaxyRVR et cochez sa case.

   .. image:: img/6_ultrasonic_value.png

3. La valeur mesurée par le capteur s'affichera alors en direct sur la scène.

   .. image:: img/6_ultrasonic_value2.png

4. Passez votre main devant le capteur ultrasonique et regardez le nombre changer – il mesure la distance en centimètres !

Créer un rover anti-obstacle
-----------------------------

Programmons votre GalaxyRVR pour qu'il évite automatiquement les obstacles grâce au capteur ultrasonique.

1. Commencez par le bloc drapeau vert.

   .. image:: img/6_ultrasonic_flag.png

2. Définissez une vitesse confortable (nous recommandons 30 %) pour les tests.

   .. image:: img/6_ultrasonic_speed.png

3. Ajoutez un bloc « avancer » pour que le rover continue d'avancer lorsque la voie est libre.

   .. image:: img/6_ultrasonic_forward.png

4. Utilisez le bloc ``when distance < 15 cm`` pour détecter les obstacles proches.

   .. image:: img/6_ultrasonic_when.png

5. Lorsqu'un objet s'approche trop près, faites arrêter le rover et reculer.

   .. image:: img/6_ultrasonic_backward.png

6. Faites-le ensuite tourner légèrement (à gauche ou à droite – à vous de choisir !).

   .. image:: img/6_ultrasonic_turn.png

7. Enfin, ordonnez-lui d'avancer à nouveau sur sa nouvelle trajectoire.

   .. image:: img/6_ultrasonic_forward_again.png

Placez maintenant votre GalaxyRVR au sol et regardez-le partir ! Il avancera jusqu'à détecter un obstacle, puis changera intelligemment de direction pour continuer son exploration.

Blocs du capteur ultrasonique
-----------------------------

* **Bloc déclencheur d'événement**

  Lance du code lorsqu'un objet est détecté à une distance définie.

  - Modifiez le symbole de comparaison (< ou >)
  - Ajustez le seuil de distance (en cm)

  .. image:: img/block/ultra_when.png

* **Bloc d'attente**

  Met votre programme en pause jusqu'à ce que le capteur détecte un objet à la distance spécifiée.

  - Choisissez < ou > pour la comparaison de distance
  - Définissez la valeur de distance souhaitée

  .. image:: img/block/ultra_wait_until.png

* **Bloc de condition**

  Renvoie VRAI ou FAUX selon la détection de distance. Idéal avec les instructions ``si``.

  - Basculez entre < et > selon le besoin
  - Définissez la limite de distance

  .. image:: img/block/ultra_condition.png

* **Bloc de valeur de distance**

  Affiche la distance actuelle mesurée par le capteur ultrasonique en centimètres.

  .. image:: img/block/ultra_value.png
