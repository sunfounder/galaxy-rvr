.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et relevez les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez & Partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et à des aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et concours** : Participez à des promotions et à des concours durant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

FAQ
==============

.. _ap_to_sta:

Q1 : Passer du mode AP au mode STA
-------------------------------------------------

* Vous devez télécharger le code correspondant.

    * :download:`GalaxyRVR Codes <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/main.zip>`

* Installez l'IDE, puis les bibliothèques ``SoftPWM`` et ``SunFounder AI Camera``. :ref:`install_lib`.

* Ensuite, ouvrez le fichier ``galaxy-rvr.ino`` situé dans le répertoire ``galaxy-rvr-main\galaxy-rvr``.

* Commentez les lignes 69-71, décommentez les lignes 73-75 et remplacez les ``SSID`` et ``PASSWORD`` par ceux de votre réseau WLAN.

.. image:: img/ap_sta.png
    :align: center

* Connectez l'Arduino à votre ordinateur via un câble USB, puis basculez l'interrupteur **upload** de la voiture en mode téléchargement.

.. image:: img/camera_upload.png
    :width: 400
    :align: center

* Téléchargez votre code.

.. _install_lib:

Q2 : Erreur de compilation : SoftPWM.h : Aucun fichier ou répertoire de ce type ?
----------------------------------------------------------------------------------------
Si vous obtenez une erreur de compilation : "SoftPWM.h : Aucun fichier ou répertoire de ce type", cela signifie que vous n'avez pas installé la bibliothèque SoftPWM.

Veuillez installer les deux bibliothèques requises ``SoftPWM`` et ``SunFounder AI Camera`` comme indiqué.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

Q3 : avrdude : stk500_getsync() tentative 10 sur 10 : pas en synchronisation : resp=0x6e ?
------------------------------------------------------------------------------------------------
Si ce message apparaît après avoir cliqué sur le bouton **Upload** alors que la carte et le port ont été sélectionnés correctement.

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00
    À ce stade, vous devez vous assurer que l'ESP32 CAM est déconnectée.

L'ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Donc, avant de télécharger le code, vous devez d'abord déconnecter l'ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Une fois le code téléchargé avec succès, si vous devez utiliser l'ESP32 CAM, déplacez l'interrupteur vers la gauche pour démarrer l'ESP32 CAM.

    .. image:: img/camera_run.png
        :width: 500
        :align: center

.. _stt_android:

Q4 : Comment utiliser le mode STT sur mon appareil Android ?
------------------------------------------------------------------------

Le mode STT nécessite que l'appareil mobile Android soit connecté à Internet et que le composant de service Google soit installé.

Suivez les étapes ci-dessous.

#. Modifiez le fichier ``galaxy-rvr.ino`` pour passer du mode AP au mode STA.

    * Ouvrez le fichier ``galaxy-rvr.ino`` situé dans le répertoire ``galaxy-rvr-main\galaxy-rvr``.
    * Commentez le code lié au mode AP. Décommentez le code du mode STA et renseignez les champs ``SSID`` et ``PASSWORD`` de votre réseau Wi-Fi domestique.

        .. code-block:: arduino

            /** Configurer le mode Wifi, SSID, mot de passe*/
            // #define WIFI_MODE WIFI_MODE_AP
            // #define SSID "GalaxyRVR"
            // #define PASSWORD "12345678"

            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "xxxxxxxxxx"
            #define PASSWORD "xxxxxxxxxx"

    * Enregistrez ce code, sélectionnez la bonne carte (Arduino Uno) et le bon port, puis cliquez sur le bouton **Upload** pour le téléverser sur la carte R3.

#. Recherchez ``google`` dans le Google Play Store, trouvez l'application ci-dessous et installez-la.

    .. image:: img/google_voice.png
        :width: 500
        :align: center

#. Connectez votre appareil mobile au même réseau Wi-Fi que celui configuré dans le code.

    .. image:: img/sta_wifi.png
        :width: 500
        :align: center

#. Ouvrez le contrôleur précédemment créé dans SunFounder Controller et connectez-le à ``GalaxyRVR`` via le bouton |app_connect|.

    .. image:: img/app/camera_connect.png
        :width: 400
        :align: center

#. Maintenez enfoncé le widget **STT(J)** après avoir cliqué sur le bouton |app_run|. Un message s'affichera indiquant qu'il écoute. Prononcez la commande suivante pour déplacer la voiture.

    .. image:: img/app/play_speech.png

    * ``stop`` : Arrêter tous les mouvements du rover.
    * ``forward`` : Faire avancer le rover.
    * ``backward`` : Faire reculer le rover.
    * ``left`` : Faire tourner le rover à gauche.
    * ``right`` : Faire tourner le rover à droite.

Q5 : À propos du firmware ESP32 CAM
---------------------------------------------------

Voici le lien vers le firmware de l'ESP32 CAM : |link_ai_camera_firmware|

Q6 : Comment flasher un nouveau firmware sur une ESP32 CAM ?
-----------------------------------------------------------------
Le module caméra est préflashé en usine. Cependant, si vous rencontrez un problème de corruption de données, vous pouvez le reflasher avec un nouveau firmware en utilisant l'IDE Arduino. Voici comment procéder :

**1. Préparer le programmeur**

#. Tout d'abord, préparez un programmeur.

#. Insérez l'ESP32 CAM dans le programmeur puis branchez-le à votre ordinateur.

**2. Installer la carte ESP32**

Pour programmer le microcontrôleur ESP32, vous devez installer le package de carte ESP32 dans l'IDE Arduino. Suivez ces étapes :

#. Allez dans **Fichier** et sélectionnez **Préférences** dans le menu déroulant.

    .. image:: img/esp32_cam_usb.jpg
        :width: 300
        :align: center

#. Dans la fenêtre **Préférences**, trouvez le champ **URLs supplémentaires du gestionnaire de cartes**. Cliquez dessus pour activer la zone de texte.

#. Ajoutez cette URL dans le champ **URLs supplémentaires du gestionnaire de cartes** : https://espressif.github.io/arduino-esp32/package_esp32_index.json. Cette URL pointe vers le fichier d'index du package pour les cartes ESP32. Cliquez sur **OK** pour enregistrer les modifications.

    .. image:: img/install_esp321.png
        :width: 500
        :align: center

#. Dans la fenêtre **Gestionnaire de cartes**, recherchez **ESP32**. Cliquez sur le bouton **Installer** pour commencer l'installation. Cela télécharge et installe le package de cartes ESP32.

    .. image:: img/install_esp322.png
        :width: 500
        :align: center

**3. Installer les bibliothèques**

#. Installez la bibliothèque ``WebSockets`` à partir du **Gestionnaire de bibliothèques**.

#. Suivez les mêmes étapes pour installer la bibliothèque ``ArduinoJson``.

**4. Télécharger et téléverser le firmware**

#. Téléchargez le fichier du firmware.

#. Extrayez le fichier du firmware téléchargé et renommez le dossier extrait de ``ai-camera-firmware-main`` à ``ai-camera-firmware``.

#. Ouvrez ``ai-camera-firmware.ino`` avec l'IDE Arduino, ce qui ouvrira également les fichiers de code associés.

    * :download:`ai-camera-firmware <https://github.com/sunfounder/ai-camera-firmware/archive/refs/heads/main.zip>`

#. Sélectionnez **Carte** -> **esp32** -> **ESP32 Dev Module**.

    .. image:: img/esp32_cam_change_name.png
        :align: center

#. Choisissez le bon port.

    .. image:: img/esp32_cam_ino.png
        :align: center

#. Assurez-vous d'activer **PSRAM** et sélectionnez **Huge APP** dans le **Schéma de partitionnement**.

    .. image:: img/esp32_cam_board.png
        :width: 500
        :align: center

#. Enfin, téléversez le firmware sur l'ESP32 CAM.

    .. image:: img/esp32_cam_port.png
        :width: 400
        :align: center

#. Après un téléversement réussi du firmware, vous pouvez trouver plus d'informations sur ce lien : https://github.com/sunfounder/ai-camera-firmware.

