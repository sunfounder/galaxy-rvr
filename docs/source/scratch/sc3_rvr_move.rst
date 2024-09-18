.. note::

    Bonjour, et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, d'Arduino et d'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Soutien d'experts** : Résolvez les problèmes après-vente et surmontez les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Profitez d'annonces de nouveaux produits en avant-première et d'aperçus privilégiés.
    - **Réductions spéciales** : Bénéficiez de remises exclusives sur nos dernières nouveautés.
    - **Promotions festives et concours** : Participez à des concours et des promotions durant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _rvr_move:

Leçon 3 : Contrôler à distance votre GalaxyRVR
==================================================

Dans cette leçon, nous allons donner vie à notre Rover martien !

Grâce à nos compétences en codage, nous allons guider notre Rover à travers des paysages martiens imaginaires.

C'est une aventure martienne dans notre salle de classe. Allons-y !

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>


Objectifs d'apprentissage
-----------------------------

* Apprendre à télécharger et à téléverser le code Arduino correspondant pour contrôler le rover avec l'APP.
* Apprendre à utiliser les touches fléchées dans Mammoth Coding pour contrôler les mouvements du rover.
* Mettre en œuvre des contrôles de mouvement de base pour le rover : avancer, reculer, tourner à gauche, tourner à droite.

Matériel
-------------

* Smartphone ou tablette
* APP Mammoth Coding
* GalaxyRVR
* Ordinateur

Téléverser le programme de base sur le GalaxyRVR
----------------------------------------------------

Pour contrôler le GalaxyRVR avec l'APP, vous devez téléverser un programme spécifique en utilisant l'IDE Arduino.

Suivez ces étapes sur votre ordinateur :

Télécharger l'IDE Arduino
^^^^^^^^^^^^^^^^^^^^^^^^^^^

#. Rendez-vous sur https://www.arduino.cc/en/software#future-version-of-the-arduino-ide.

#. Téléchargez l'IDE pour votre version du système d'exploitation.

    .. image:: img/sp_001.png

#. Installez-le.

    .. image:: img/sp_005.png

Téléverser le code adapté
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

1. Allumez l'interrupteur du GalaxyRVR.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_start.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

2. Connectez l'Arduino et l'ordinateur avec un câble USB, puis tournez l'interrupteur **upload** de la voiture sur la position de téléversement.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

.. note:: Il s'agit du port USB Type B pour connecter l'Arduino, et non du port USB Type C pour la recharge.

3. Ouvrez le dossier galaxy-rvr-1.2.0 téléchargé. (Il a été téléchargé et installé dans la section :ref:`update_firmware`), double-cliquez pour exécuter le script ``update-arduino-firmware.bat``. Une fenêtre de commande s'ouvrira.

.. image:: ../img/firmware/updateFirmware.png

4. Dans la fenêtre de commande, vous verrez une liste de ports série montrant les ports auxquels l'ordinateur est actuellement connecté. Entrez le numéro de séquence à gauche de la liste des ports série pour sélectionner le port série de l'Arduino Uno. Appuyez sur Entrée pour téléverser automatiquement.

.. image:: ../img/firmware/selectCOM.png

5. Une fois le téléversement terminé, vous pouvez débrancher le câble USB.

.. image:: ../img/firmware/UNOupdating.png

6. Remettez l'interrupteur de téléversement à sa position initiale et appuyez sur le bouton de réinitialisation, la voiture est prête à l'emploi.

.. note:: Ce code permet au GalaxyRVR de répondre aux commandes de l'APP. Vous n'aurez plus besoin de téléverser de code dans les chapitres suivants utilisant l'APP Mammoth Coding.

.. _app_connect:

Connexion de l'APP au GalaxyRVR
-------------------------------------------

1. Pour activer l'ESP32 CAM, déplacez l'interrupteur de mode sur la position **Run**, puis appuyez sur le bouton **reset** pour redémarrer la carte R3. Vous verrez alors une lumière cyan clignoter sur la bande inférieure.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

2. Connectez votre appareil mobile (par exemple, téléphone, tablette) au hotspot WiFi fourni par GalaxyRVR. Généralement, son SSID est ``GalaxyRVR`` et le mot de passe est ``12345678``.

.. image:: ../img/firmware/SSID.png

.. note:: Le mode de connexion par défaut est le **mode AP**. Après vous être connecté, il se peut qu'un message vous avertisse que ce réseau n'a pas accès à Internet. Si c'est le cas, choisissez "Rester connecté".

    .. image:: ../img/app/camera_stay.png

3. Ouvrez l'APP. Cliquez ici.

.. image:: img/connet_app_04.png

4. Chargez le module GalaxyRVR.

.. image:: img/connet_app_05.png

5. L'APP recherchera votre robot.

.. image:: img/connet_app_06.png

6. Connectez-le.

.. note:: La lumière de respiration sur le GalaxyRVR peut indiquer l'état de la connexion. Un clignotement jaune signifie qu'aucun appareil n'est connecté. Une lumière bleue fixe signifie qu'il est connecté.

Re-connect APP
-------------------------------------

When your device is disconnected from GalaxyRVR, you will see this pop-up window appear in the interface. Click reconnect.

.. image:: img/reconnect_0.png

If you close the pop-up window, you can also reconnect by clicking this button in the GalaxyRVR category.

.. image:: img/reconnect_1.png

Find your GalaxyRVR and click connect.

.. image:: img/reconnect_2.png

Contrôler le GalaxyRVR avec l'APP
-----------------------------------------

1. Dans l'interface Code, vous trouverez la catégorie GalaxyRVR.

.. image:: img/3_rvr_catego.png

2. Nous avons déjà utilisé le drapeau vert pour démarrer des programmes. 
Pendant ce processus, vous remarquerez plusieurs blocs dans la catégorie 
Événements qui déclenchent l'exécution du code. Trouvez le bloc ``quand la touche flèche haut pressée``.

.. image:: img/3_rvr_when_arrow.png

3. Faites glisser quatre de ces blocs, un pour chaque événement de touche fléchée (haut, bas, gauche, droite).

.. image:: img/3_rvr_4_arrow.png

.. note:: Vous pouvez cliquer sur l'icône de l'œil sous le drapeau vert pour masquer la zone de la scène et obtenir plus d'espace pour le codage.

4. Complétez les blocs de code pour ces quatre événements. Lorsque la flèche haut est pressée, faites avancer le GalaxyRVR ; lorsque la flèche gauche est pressée, faites-le tourner à gauche, etc.

.. image:: img/3_rvr_4_dir.png

5. Agrandissez la scène en cliquant sur ce bouton.

.. image:: img/3_rvr_stage.png

6. Vous entrerez dans une interface avec une scène agrandie et un ensemble de touches directionnelles.

.. image:: img/3_rvr_stage2.png

Appuyez sur ces touches directionnelles et vous serez ravi de voir que vous pouvez contrôler directement le GalaxyRVR.

Blocs liés au mouvement
-----------------------------

.. image:: img/block/move_forward.png 
..    :align: center

Après l'exécution de ce bloc, le GalaxyRVR avancera. Vous pouvez :

    * Changer le paramètre dans le menu déroulant pour tourner à gauche, tourner à droite ou reculer.

.. image:: img/block/move_set_speed.png 
..    :align: center

Ce bloc est utilisé pour définir la vitesse de déplacement du GalaxyRVR. Il n'initie pas le mouvement en lui-même.

.. image:: img/block/move_forward_1s.png 
..    :align: center

Après l'exécution de ce bloc, le GalaxyRVR avancera pendant 1 seconde. Vous pouvez :
    
    * Changer le paramètre dans le menu déroulant pour tourner à gauche, tourner à droite ou reculer.
    * Ajuster le nombre dans le bloc pour définir la durée du mouvement du GalaxyRVR.

.. image:: img/block/move_forward_80.png 
..    :align: center

Après l'exécution de ce bloc, le GalaxyRVR avancera à 80% de sa vitesse. Vous pouvez :
    
    * Changer le paramètre dans le menu déroulant pour tourner à gauche, tourner à droite ou reculer.
    * Modifier le nombre dans le bloc pour ajuster la vitesse du GalaxyRVR pendant ce mouvement.

.. image:: img/block/move_forward_80_1s.png 
..    :align: center

Après l'exécution de ce bloc, le GalaxyRVR avancera à 80% de sa vitesse pendant 1 seconde. Vous pouvez :
    
    * Changer le paramètre dans le menu déroulant pour tourner à gauche, tourner à droite ou reculer.
    * Ajuster la durée dans le bloc pour définir la durée du mouvement.
    * Modifier la vitesse dans le bloc pour ajuster la vitesse du GalaxyRVR pendant ce mouvement.

.. image:: img/block/move_lr_sp_1s.png 
..    :align: center

Après l'exécution de ce bloc, vous pouvez définir indépendamment les vitesses des roues gauche et droite du GalaxyRVR et avancer pendant le temps spécifié. Vous pouvez :
    
    * Modifier la vitesse gauche pour définir la vitesse de la roue gauche du GalaxyRVR.
    * Modifier la vitesse droite pour définir la vitesse de la roue droite du GalaxyRVR.
    * Ajuster la durée pour déterminer la durée du mouvement.

.. image:: img/block/move_stop.png
..    :align: center

Arrête le mouvement du GalaxyRVR.

