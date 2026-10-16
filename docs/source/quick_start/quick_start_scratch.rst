.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Jeu Rapide avec Scratch
==================================

Dans ce chapitre, vous apprendrez à **ouvrir et exécuter rapidement des projets d'exemple dans Scratch (Mammoth Coding)** pour voir votre GalaxyRVR en action.

Si vous souhaitez apprendre à créer ces scripts à partir de zéro, veuillez consulter le chapitre :ref:`programming_scratch`.

.. note::

    * La carte R3 du GalaxyRVR est livrée avec un firmware qui prend en charge l'application RoboPilot et Mammoth Coding.
    * Si vous avez écrasé le firmware et devez restaurer la communication, suivez :ref:`update_r3_firmware`.


Comment ouvrir rapidement un exemple Scratch
------------------------------------------------------

#. Téléchargez les codes d'exemple à partir du lien ci-dessous :

   * |download_galaxyrvr_code|

#. Extrayez le fichier téléchargé et transférez le dossier ``scratch_codes`` sur votre appareil mobile. Vous pouvez utiliser n'importe quel outil de transfert de fichiers, comme **ES File Explorer** ou **File Transfer Assistant**.

   .. image:: img/scratch_mobile_save.png
      :width: 400

#. Recherchez **Mammoth Coding** sur **Google Play** ou l'**Apple App Store** et installez-le.

   .. image:: img/scratch_app_install.png
      :width: 600

#. Démarrez le GalaxyRVR.

   * Avant d'utiliser le GalaxyRVR pour la première fois, chargez complètement la batterie avec le câble USB Type-C fourni.
   * Mettez l'interrupteur d'alimentation en marche.
   * Passez le mode sur **Run** et appuyez sur le bouton **Reset** de la carte R3.
   * La bande lumineuse inférieure clignotera en **vert**, indiquant un démarrage réussi.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Connectez votre appareil mobile au réseau WiFi du GalaxyRVR.

   * Le nom du réseau (SSID) est ``GalaxyRVR`` et le mot de passe est ``12345678``.
   * Si vous voyez un avertissement indiquant "Aucun accès Internet", veuillez choisir l'option **"Rester connecté"**.


     .. image:: ../img/camera_lan.png
        :width: 500

#. Dans l'application, appuyez sur **File** > **Open from device** pour parcourir les fichiers locaux.

   .. image:: img/scratch_open_file.png
        :width: 600

#. Sélectionnez un fichier ``.sb3`` pour l'ouvrir.

   .. image:: img/scratch_mobile_save.png
      :width: 400

#. Appuyez sur l'icône du drapeau vert pour lancer le script.

   .. image:: img/scratch_run.png

Exemples
---------------

**Projets de base**

Ces projets sont les cours de base pour contrôler le GalaxyRVR avec Mammoth Coding. Ils vous guideront étape par étape sur la façon d'utiliser GalaxyRVR.


* ``3_move.sb3`` : Contrôlez le mouvement de votre GalaxyRVR en temps réel à l'aide des touches directionnelles.
* ``4_ultrasonic.sb3`` : Le rover avance et évite automatiquement les obstacles à l'aide du module à ultrasons.
* ``5_ultra_animate_jump.sb3`` : Crée une scène animée du rover se déplaçant joyeusement sur la surface martienne.
* ``6_ir_obstacle_avoid.sb3`` : Le rover avance et évite les obstacles à l'aide de capteurs IR.
* ``7_ir_obstacle_avoid_animate.sb3`` : Contrôlez le sprite du rover pour esquiver les rochers sur la surface martienne en déclenchant les capteurs IR avec vos mains.
* ``8_ir_ultrasonic_avoid.sb3`` : Le rover utilise ensemble les capteurs à ultrasons et IR pour naviguer en douceur autour des obstacles.
* ``9_ir_ultrasonic_follow.sb3`` : Le rover vous suit : il s'approche quand vous êtes devant, se tourne vers vous quand vous êtes à côté et s'arrête quand vous vous éloignez.
* ``10_rgb.sb3`` : Appuyez sur une balle colorée pour que les lumières RGB du rover brillent de cette couleur.
* ``10_rgb_animate.sb3`` : Le rover se déplace et change de couleur de lumière selon les touches directionnelles pressées.
* ``1scratch_servo.sb3`` : Utilisez les touches fléchées pour régler l'angle de la caméra du rover ; cliquez pour réinitialiser sa position.
* ``1scratch_servo_stage.sb3`` : Touchez et faites glisser la flèche à l'écran pour orienter la caméra du rover avec une réponse fluide en temps réel.
* ``12_camera.sb3`` : Visualisez le flux en direct de la caméra depuis la perspective de votre rover pendant qu'il explore.
* ``13_realtime_control.sb3`` : Contrôlez les mouvements et les lumières de votre rover en temps réel via Scratch.

**Projets amusants**

Ces projets Scratch amusants ne nécessitent pas le GalaxyRVR.
Vous pouvez tous les trouver dans le dossier ``scratch_codes/fun/``.

* ``1_scratch_balloon.sb3`` : Gonflez le ballon en bloquant le capteur IR gauche ; ne le laissez pas éclater ou tomber !
* ``2_flappy_parrot.sb3`` : Contrôlez le vol du perroquet en utilisant votre main au-dessus du capteur à ultrasons pour esquiver les poteaux en bambou.
* ``3_shooting.sb3`` : Visez et tirez sur des cibles à l'aide du module d'évitement d'obstacles.
* ``4_eat_apple.sb3`` : Guidez le scarabée vers la pomme en utilisant les gestes de la main détectés par le capteur IR gauche.
* ``5_fishing.sb3`` : Attrapez des poissons en bloquant le capteur IR gauche au bon moment.
* ``6_sensitive_ball.sb3`` : Déplacez la balle vers le haut ou vers le bas avec votre main au-dessus du capteur à ultrasons ; déclenchez des sons et des lumières lorsqu'elle touche une ligne.
* ``7_tap_white_tile.sb3`` : Appuyez sur les tuiles noires à l'aide de deux capteurs IR pour marquer des points — évitez les blanches !
