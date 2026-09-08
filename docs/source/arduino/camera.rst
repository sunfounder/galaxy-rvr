.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Exploration du système de vision du Mars Rover – Caméra et contrôle en temps réel
==============================================================================================

Bienvenue à nouveau, jeunes explorateurs ! Lors de la Leçon 10, nous avons équipé notre Mars Rover d'un mécanisme d'inclinaison lui permettant de « hocher la tête ». Il est maintenant temps de lui donner des « yeux » : la caméra !

Dans cette aventure passionnante, nous allons découvrir comment mettre en place le système de caméra du Rover. Vous apprendrez à transmettre les images capturées par la caméra du Rover vers une page web afin de voir exactement ce que le Rover voit, en temps réel. Imaginez l'excitation de découvrir le paysage martien depuis le point de vue du Rover !

L'aventure continue avec la découverte de l'application SunFounder Controller. Cette application nous permet d'obtenir un flux vidéo en direct de la vue du Rover pendant ses déplacements, tout en contrôlant le mécanisme d'inclinaison directement depuis un smartphone ou une tablette. C'est un peu comme avoir une télécommande avec un écran intégré !

Objectifs d'apprentissage
-------------------------

* Comprendre comment établir une connexion Wi-Fi avec l'ESP32-CAM.
* Apprendre à voir exactement ce que le Rover voit, en temps réel.
* Apprendre à utiliser l'application SunFounder Controller pour créer une télécommande virtuelle et contrôler le Mars Rover.

Matériel nécessaire
------------------------

* Modèle de Mars Rover (équipé de tous ses composants)
* Arduino IDE
* Ordinateur
* Tablette ou smartphone avec l'application SunFounder Controller installée

Étapes du cours
----------------------

**Étape 1 : Introduction à l'ESP32-CAM**

Lors de notre précédente aventure, nous avons équipé notre Mars Rover d'une paire d'« yeux » en intégrant un module ESP32-CAM. Aujourd'hui, nous allons en apprendre davantage sur lui et lui permettre de réellement « voir ».

.. image:: img/esp32_cam.png
    :width: 400
    :align: center

L'ESP32-CAM, qui joue le rôle des yeux de notre Rover, est un module compact mais puissant. En plus d'intégrer les fonctionnalités Wi-Fi et Bluetooth, il est équipé d'une caméra miniature. Cette caméra permet à notre Rover de capturer des images de son environnement.

Tout comme nous utilisons nos yeux pour observer notre environnement, l'ESP32-CAM peut « voir » ce qui se trouve devant le Rover puis transmettre ces données visuelles vers notre smartphone ou notre ordinateur. Cela nous permet de voir tout ce que le Rover voit en temps réel !

C'est comme si nous pilotions directement le Rover, en observant non seulement le Rover lui-même, mais aussi le monde qu'il explore ! Incroyable, n'est-ce pas ? Alors, approfondissons le sujet...

**Étape 2 : Programmer la caméra du Rover et visualiser le flux vidéo**

Après avoir installé l'ESP32-CAM sur notre Rover, nous devons maintenant lui donner vie.

Pour cela, nous allons utiliser Arduino IDE afin d'écrire un programme qui contrôlera la caméra, lui permettra de se connecter au Wi-Fi et diffusera les images qu'elle capture.

Voici comment procéder :

#. Installez la bibliothèque ``SunFounder AI Camera``.

    * Ouvrez le **Gestionnaire de bibliothèques** d'Arduino IDE, recherchez « SunFounder Camera » puis cliquez sur **INSTALLER**.

        .. image:: img/camera_install_lib.png

    * Une fenêtre contextuelle apparaîtra pour l'installation des bibliothèques dépendantes. Cliquez sur **INSTALL ALL** et attendez la fin de l'installation.

        .. image:: img/camera_install_lib1.png

#. Dans Arduino IDE, saisissez le code suivant.

    Concernant les variables ``NAME``, ``TYPE`` et ``PORT`` présentes dans le programme, nous n'allons pas les détailler pour le moment. Elles entreront en jeu dans l'étape suivante. Retenez simplement que ces variables joueront un rôle important dans notre prochaine aventure visant à établir un flux vidéo en temps réel depuis notre Mars Rover.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b648e4-23e8-4b28-accd-aac171069116/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

    Vous remarquerez que le programme propose deux modes de connexion : le mode **AP** et le mode **STA**. Vous pouvez choisir celui qui correspond le mieux à vos besoins.

    * **Mode AP** : Dans ce mode, le Rover crée son propre point d'accès Wi-Fi (nommé ``GalaxyRVR`` dans notre programme). Cela permet à n'importe quel appareil, comme un smartphone, une tablette ou un ordinateur portable, de se connecter directement à ce réseau. Ce mode est particulièrement utile lorsque vous souhaitez contrôler le Rover à distance dans n'importe quel environnement. Toutefois, notez que votre appareil ne pourra alors plus accéder à Internet pendant qu'il est connecté au Rover.

        .. code-block:: arduino

            // Mode AP
            #define WIFI_MODE WIFI_MODE_AP
            #define SSID "GalaxyRVR"
            #define PASSWORD "12345678"

    * **Mode STA** : Dans ce mode, le Rover se connecte à votre réseau Wi-Fi domestique. N'oubliez pas que l'appareil utilisé pour le contrôle (smartphone ou tablette, par exemple) doit également être connecté au même réseau Wi-Fi. Ce mode permet à votre appareil de conserver son accès Internet habituel tout en contrôlant le Rover, mais limite sa portée à la zone couverte par votre réseau Wi-Fi.

        .. code-block:: arduino

            // Mode STA
            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "VOTRE SSID"
            #define PASSWORD "VOTRE MOT DE PASSE"

#. Téléversez le programme sur le Rover et donnez vie à notre ESP32-CAM !

    * L'ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Avant de téléverser le programme, vous devez donc d'abord désactiver temporairement l'ESP32-CAM en faisant glisser cet interrupteur vers la droite afin d'éviter tout conflit ou problème de communication.

        .. image:: ../img/camera_upload.png
            :width: 600

    * Une fois le programme téléversé avec succès, replacez l'interrupteur vers la gauche afin de démarrer l'ESP32-CAM.

        .. note::
            Cette étape ainsi que la précédente sont nécessaires chaque fois que vous téléversez un nouveau programme.

        .. image:: img/camera_run.png
            :width: 600

    * Ouvrez le **Moniteur Série** et réglez la vitesse de communication à 115200 bauds. Si aucune information n'apparaît, appuyez sur le bouton **Reset** du shield GalaxyRVR afin de relancer le programme. Vous devriez voir apparaître une adresse IP dans le Moniteur Série. Il s'agit de l'adresse utilisée par la caméra du Rover pour diffuser son flux vidéo.

        .. image:: img/camera_serial.png

    * Il est maintenant temps de voir réellement ce que voit notre Rover ! Ouvrez un navigateur web — nous recommandons Google Chrome — puis saisissez l'adresse affichée dans le Moniteur Série sous le format ``http://ip:9000/mjpg``.

        .. image:: img/camera_view.png

Et voilà ! Vous devriez maintenant pouvoir visualiser en direct le flux vidéo provenant de la caméra de votre Rover. N'est-il pas incroyable de penser que vous observez Mars (ou peut-être simplement votre salon) du point de vue du Rover ? Tout comme un véritable scientifique travaillant sur un rover martien !

Rappelez-vous, ce n'est que le début. Il reste encore énormément de choses à explorer et à apprendre. Dans l'étape suivante, nous découvrirons comment contrôler notre Rover tout en visualisant le flux vidéo en direct. Passionnant, n'est-ce pas ? En avant, explorateurs !