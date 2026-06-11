.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _ir_obstacle:

Leçon 6 : Le module infrarouge anti-obstacle
============================================

Découvrez les « yeux » latéraux de votre rover – les capteurs infrarouges d'évitement d'obstacles !

Ces capteurs astucieux aident votre GalaxyRVR à détecter et à esquiver les obstacles sur ses côtés, comme une vision périphérique. Apprenez comment ils fonctionnent et programmez votre rover pour qu'il contourne automatiquement les objets.

Préparez-vous à faire de votre Rover Martien un as de l'évitement !

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_ir1.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>

Objectifs d'apprentissage
-------------------------

* Comprendre les principes de fonctionnement du module infrarouge anti-obstacle et son application dans le Rover Martien
* Apprendre à lire et à utiliser les données du module infrarouge anti-obstacle dans Scratch
* Créer un jeu d'évitement d'obstacles sur le thème de l'exploration martienne en utilisant le module IR et la scène Scratch

Découvrir le module anti-obstacle
----------------------------------

Dites bonjour au nouveau compagnon de votre GalaxyRVR – le module infrarouge anti-obstacle ! Ce petit dispositif ingénieux aide votre rover à détecter et à éviter les obstacles. Voyons ce qui le fait fonctionner :

.. image:: img/ir_avoid.png
    :width: 300
    :align: center

**Les quatre broches importantes :**

* **GND** – La masse (ferme le circuit)
* **+** – Alimentation électrique (nécessite 3,3 V à 5 V)
* **Out** – Sortie du signal (envoie les messages « obstacle détecté »)
* **EN** – Broche d'activation (contrôle quand le module est actif)

**Comment ça marche – La lampe torche invisible :**

Imaginez ce module comme une lampe torche invisible avec des lunettes spéciales :

.. image:: img/ir_receive.png
    :align: center

1. L'émetteur envoie de la lumière infrarouge (invisible à nos yeux)
2. Lorsque la lumière rencontre un obstacle, elle rebondit
3. Le récepteur « voit » la lumière réfléchie
4. Le module envoie un signal : « Obstacle devant ! »

**Informations utiles sur votre capteur :**

* **Portée de détection** : 2 à 40 cm (environ la longueur de votre trousse !)
* **La couleur compte** : Fonctionne mieux avec les objets de couleur claire
* **Objets sombres** : Plus difficiles à détecter de loin

**Contrôles avancés (pour les esprits curieux) :**

* **Broche EN** : Le cavalier maintient le module toujours actif. Retirez-le si vous souhaitez contrôler le module par code.

  .. image:: img/ir_cap.png
      :width: 400
      :align: center

* **Deux réglages** :

  - Un bouton contrôle la distance parcourue par la lumière infrarouge
  - Un bouton ajuste la fréquence de la lumière

  .. image:: img/ir_avoid_pot.png
      :width: 400
      :align: center

Maintenant que vous avez fait connaissance avec votre nouveau compagnon, connectons-le à votre rover et commençons à programmer !

Tester vos capteurs infrarouges
-------------------------------

#. Commencez par :ref:`app_connect`.

2. Réglons vos capteurs pour des performances optimales !

   a. Assurez-vous que les composants infrarouges sont droits. Ajustez-les doucement si nécessaire.

      .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
            </video>

   b. Placez un objet (comme la boîte de votre rover) à 20 cm. Tournez le bouton jusqu'à ce que le voyant s'allume. Testez en rapprochant et en éloignant l'objet.

      .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
            </video>

   c. Faites de même pour l'autre module infrarouge.

3. Puis, :ref:`app_connect`.

4. Trouvez les blocs « état IR gauche » et « état IR droit » dans la catégorie GalaxyRVR et cochez leurs cases.

   .. image:: img/4_ir_statusblock.png

5. Les valeurs des capteurs s'afficheront maintenant sur votre scène.

   .. image:: img/4_ir_statusvalue.png

6. Passez votre main près de chaque capteur infrarouge et regardez les valeurs changer !

**Signification des valeurs :**

- **True (Vrai)** = Obstacle détecté
- **False (Faux)** = Voie libre

Vous êtes maintenant prêt à voir ce que votre rover peut « voir » !


Programmer votre rover pour éviter les obstacles
------------------------------------------------

Apprenons à votre GalaxyRVR à esquiver automatiquement les obstacles grâce à ses capteurs infrarouges !

#. Commencez par :ref:`app_connect`.

#. Démarrez le programme avec un bloc drapeau vert.

   .. image:: img/4_ir_start.png

#. Réglez une vitesse de sécurité de 30 % pour faciliter les tests et le débogage.

   .. image:: img/4_ir_speed.png

#. Trouvez le bloc ``when left IR is blocked`` pour la détection du capteur gauche.

   .. image:: img/4_ir_when_blocked.png

#. Lorsque le capteur gauche détecte un obstacle, faites tourner le rover à droite.

   .. image:: img/4_ir_turn_right.png

#. Continuez à tourner à droite jusqu'à ce que le côté gauche ne détecte plus l'obstacle.

   .. image:: img/4_ir_wait_until.png

#. Arrêtez le mouvement une fois la voie dégagée.

   .. image:: img/4_ir_stop.png

#. Testez en déclenchant le capteur infrarouge gauche avec votre main. Le GalaxyRVR devrait tourner à droite pour l'éviter.

#. Dupliquez le code en appuyant longuement sur les blocs et en sélectionnant Dupliquer dans le menu.

   .. image:: img/4_ir_duplicate.png

#. Dans le code dupliqué, inversez les côtés gauche et droit pour gérer les obstacles du côté droit.

   .. image:: img/4_ir_left_right.png

#. Pour éviter un comportement erratique lorsque les deux capteurs sont déclenchés en même temps, ajoutez un bloc « stop other scripts in sprite ». Cela garantit qu'un seul événement de capteur est traité à la fois.

   .. image:: img/4_ir_stop_script.png
       :width: 800

   .. note:: Le bloc d'arrêt des scripts peut entrer en conflit avec les blocs de mouvement chronométrés, évitez donc de les utiliser ensemble lorsque c'est possible.

#. Votre GalaxyRVR tournera maintenant à gauche ou à droite lorsque des obstacles sont détectés de chaque côté. Testez en déclenchant les deux capteurs avec vos mains.

#. Ajoutez un bloc « avancer » sous chaque section de code pour que le rover continue d'avancer après avoir évité les obstacles.

   .. image:: img/4_ir_avoid_move.png
       :width: 800

Cliquez maintenant sur le drapeau vert ! Votre GalaxyRVR avancera en continu, esquivant intelligemment les obstacles et reprenant sa trajectoire après les avoir contournés.

Blocs liés au module IR
-----------------------

* Bloc d'événement déclenché lorsque le capteur IR gauche détecte un obstacle

  - Changez « left » en « right » dans le menu déroulant

  .. image:: img/block/ir_when.png

* Met le programme en pause jusqu'à ce que le capteur IR gauche ne détecte plus d'obstacle

  - Changez « left » en « right » pour l'autre capteur
  - Changez « is not » en « is » pour la condition inverse

  .. image:: img/block/ir_wait_until.png

* Bloc conditionnel qui renvoie VRAI si le capteur IR gauche détecte un obstacle

  - Idéal avec les instructions ``si``
  - Changez « left » en « right » pour l'autre capteur

  .. image:: img/block/ir_condition.png

* Affiche l'état actuel de détection du capteur IR gauche

  .. image:: img/block/ir_left_value.png

* Affiche l'état actuel de détection du capteur IR droit

  .. image:: img/block/ir_right_value.png
