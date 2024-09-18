.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à notre communauté et notre équipe.
    - **Apprenez & Partagez** : Échangez des astuces et tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos produits récents.
    - **Promotions festives et concours** : Participez à des concours et promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !


Leçon 11 : Explorer le système visuel du Rover martien - Caméra et contrôle en temps réel
=============================================================================================

Bienvenue à nouveau, jeunes explorateurs ! Dans la leçon précédente, nous avons équipé notre Rover martien de la capacité de "hocher la tête" grâce à un mécanisme d'inclinaison. Maintenant, il est temps de donner des "yeux" à notre Rover – une caméra !

Dans cette aventure passionnante, nous allons configurer le système de caméra du Rover. Vous apprendrez à transmettre les images capturées par la caméra du Rover à une page web, afin de voir exactement ce que voit le Rover, en temps réel. Imaginez l'excitation de découvrir le paysage martien à travers les yeux du Rover !

L'excitation continue avec l'introduction de l'application SunFounder Controller. Cette application vous permet de recevoir un flux vidéo en direct tout en contrôlant le mécanisme d'inclinaison depuis votre smartphone ou tablette. C'est comme avoir une télécommande avec un écran intégré !

Cela offre une expérience encore plus interactive et captivante avec notre Rover. Restez à l'écoute pour plus d'aventures !

    .. image:: img/app/camera_view_app.png

Objectifs d'apprentissage
----------------------------

* Comprendre comment établir une connexion Wi-Fi avec l'ESP32 CAM.
* Apprendre à voir exactement ce que voit le Rover, en temps réel.
* Apprendre à utiliser l'application SunFounder Controller pour créer une télécommande virtuelle et contrôler le Rover martien.

Matériel nécessaire
-----------------------

* Modèle de Rover martien (équipé de tous les composants)
* IDE Arduino
* Ordinateur
* Tablette ou smartphone avec l'application SunFounder Controller installée

Étapes du cours
-----------------

**Étape 1 : Introduction à l'ESP32 CAM**

Dans notre aventure précédente, nous avons équipé notre Rover martien de "yeux" en intégrant l'ESP32 CAM. Aujourd'hui, nous allons en apprendre davantage à son sujet et lui permettre de "voir".

.. image:: img/esp32_cam.png
    :width: 400
    :align: center

L'ESP32 CAM, qui agit comme les yeux de notre Rover, est un module petit mais puissant. Non seulement il intègre des fonctionnalités Wi-Fi et Bluetooth, mais il est également doté d'une caméra compacte. Cette caméra permet à notre Rover de capturer des images de son environnement.

Tout comme nous utilisons nos yeux pour observer notre environnement, l'ESP32 CAM peut "voir" ce qui se trouve devant le Rover, puis envoyer ces données visuelles à notre smartphone ou ordinateur. Cela nous permet de voir tout ce que le Rover voit en temps réel !

C'est comme si nous pilotions directement le Rover, observant non seulement le Rover lui-même, mais aussi le monde qu'il explore ! Incroyable, n'est-ce pas ? Alors, plongeons plus profondément...


**Étape 2 : Programmer la caméra du Rover et visualiser le flux vidéo**

Après avoir installé l'ESP32-CAM sur notre Rover, nous devons maintenant 
lui donner vie. Pour ce faire, nous utiliserons l'IDE Arduino pour écrire 
un programme qui contrôlera la caméra, lui permettra de se connecter au Wi-Fi, 
et diffusera les images capturées.

Voici comment procéder :

#. Installez la bibliothèque ``SunFounder AI Camera``.

    * Ouvrez le **Gestionnaire de Bibliothèques** de l'IDE Arduino, recherchez "SunFounder Camera", et cliquez sur **INSTALLER**.

        .. image:: img/camera_install_lib.png

    * Une fenêtre contextuelle apparaîtra pour l'installation des dépendances de la bibliothèque. Cliquez sur **INSTALLER TOUT** et attendez la fin du processus.

        .. image:: img/camera_install_lib1.png

#. Dans l'IDE Arduino, saisissez le code suivant.

    Concernant les variables ``NAME``, ``TYPE``, et ``PORT`` dans le code, nous ne les aborderons pas pour l'instant. Elles seront importantes lors de notre prochaine étape pour établir un flux vidéo en temps réel depuis notre Rover martien.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b648e4-23e8-4b28-accd-aac171069116/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


    Vous remarquerez que nous avons deux modes de connexion dans le code - le mode **AP** et le mode **STA**. Vous pouvez choisir celui qui convient le mieux à vos besoins.

    * **Mode AP** : Dans ce mode, le Rover crée un point d'accès (nommé ``GalaxyRVR`` dans notre code). Cela permet à tout appareil comme un téléphone portable, une tablette ou un ordinateur de se connecter à ce réseau. Cela est particulièrement utile si vous souhaitez contrôler le Rover à distance dans n'importe quelle circonstance. Cependant, notez que cela empêchera votre appareil de se connecter à Internet pendant ce temps.

        .. code-block:: arduino

        // Mode AP
        #define WIFI_MODE WIFI_MODE_AP
        #define SSID "GalaxyRVR"
        #define PASSWORD "12345678"

    * **Mode STA** : Dans ce mode, le Rover se connecte à votre réseau Wi-Fi domestique. Votre appareil de contrôle (comme un téléphone ou une tablette) doit également être connecté au même réseau Wi-Fi. Ce mode permet à votre appareil de conserver son accès à Internet tout en contrôlant le Rover, mais limite la portée d'opération du Rover à la couverture de votre réseau Wi-Fi.

        .. code-block:: arduino

            // Mode STA
            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "VOTRE SSID"
            #define PASSWORD "VOTRE MOT DE PASSE"

#. Téléversez le code dans notre Rover et donnez vie à notre ESP32 CAM !

    * L'ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Donc, avant de téléverser le code, vous devrez d'abord libérer l'ESP32-CAM en faisant glisser cet interrupteur sur le côté droit pour éviter tout conflit ou problème potentiel.

        .. image:: img/camera_upload.png
            :width: 600

    * Une fois le code téléversé avec succès, remettez l'interrupteur à gauche pour démarrer l'ESP32 CAM.

        .. note::
            Cette étape et la précédente sont nécessaires à chaque fois que vous téléversez le code.

        .. image:: img/camera_run.png
            :width: 600
        
    * Ouvrez le **Moniteur Série** et réglez la vitesse de transmission à 115200. Si aucune information n'apparaît, appuyez sur le **bouton de réinitialisation** du bouclier GalaxyRVR pour relancer le code. Vous devriez voir une adresse IP dans la sortie du moniteur série. C'est l'adresse vers laquelle la caméra de votre Rover diffuse.

        .. image:: img/camera_serial.png


    * Maintenant, il est temps de voir ce que voit notre Rover ! Ouvrez un navigateur web - nous vous recommandons Google Chrome - et entrez l'URL que vous voyez dans le Moniteur Série, au format ``http://ip:9000/mjpg``.

        .. image:: img/camera_view.png

Et voilà ! Vous devriez maintenant pouvoir voir le flux vidéo en direct depuis la caméra de votre Rover. N'est-ce pas incroyable de penser que vous regardez Mars (ou peut-être simplement votre salon) à travers les yeux du Rover ? Comme un vrai scientifique opérant un Rover martien !

Souvenez-vous, ce n'est que le début. Il y a encore tant à explorer et à apprendre. Dans notre prochaine étape, nous découvrirons comment contrôler notre Rover tout en visualisant le flux vidéo en direct. Excitant, n'est-ce pas ? En avant, explorateurs !


**Étape 3 : Contrôler et visualiser le flux vidéo à l'aide de l'application**

Vous avez toujours rêvé de voir le flux vidéo de votre Rover martien directement sur votre smartphone tout en contrôlant son mécanisme d'inclinaison ? 
C'est maintenant possible ! Grâce à l'application SunFounder Controller, vous pourrez faire exactement cela. Suivez les étapes ci-dessous :


#. Installez l'application depuis **APP Store (iOS)** ou **Google Play (Android)**.

#. Créez un contrôleur.

    * Pour ajouter un contrôleur sur l'application SunFounder Controller, cliquez sur l'icône **+**.

        .. image:: img/app/app1.png

    * Choisissez le préréglage **Blank**, sélectionnez **Dual** ou **Single Stick** selon votre préférence. Donnez un nom à votre nouveau contrôleur et cliquez sur **Confirmer**.

        .. image:: img/app/camera_controller.png

    * Vous êtes maintenant dans le contrôleur. Cliquez sur l'icône **+** dans la section D, puis sélectionnez Slider dans le menu contextuel.

    .. image:: img/app/camera_add_slider.png

    * Ce widget Slider est conçu pour contrôler le mécanisme d'inclinaison. Comme nous l'avons appris lors de la leçon précédente, sa plage va de 0 à 140. Nous allons donc définir ces valeurs comme valeurs minimale et maximale pour notre widget Slider.

        .. image:: img/app/camera_slider_set.png
    
    * Cliquez sur le bouton |app_save| en haut à droite pour enregistrer ce contrôleur.
    
#. Écrivons un code pour capturer la valeur du curseur :

    * En nous basant sur le code précédent, passons en mode AP, où vous pouvez définir le SSID et le mot de passe selon votre préférence.
    
    .. code-block:: arduino
    
        // Mode AP
        #define WIFI_MODE WIFI_MODE_AP
        #define SSID "GalaxyRVR"
        #define PASSWORD "12345678"

    * Ensuite, nous ajoutons une fonction ``onReceive()`` pour recevoir les valeurs du contrôleur SunFounder et imprimer ces valeurs dans le Moniteur Série. Nous utilisons la fonction ``getSlider()`` pour obtenir la valeur du widget **slider**. J'ai ajouté un widget **slider** dans la région D, mais si vous l'avez ajouté dans une région différente, vous devez remplacer ``REGION_D`` par votre région.

        .. code-block::

            void onReceive() {
                int16_t sliderD = aiCam.getSlider(REGION_D);
                Serial.print("Slider D: ");
                Serial.println(sliderD);
            }

            void setup() {
                ...
                // Définir la fonction à exécuter lorsque des données sont reçues
                aiCam.setOnReceived(onReceive);
                ...
            }

    * Voici le code complet :

        .. raw:: html

            <iframe src=https://create.arduino.cc/editor/sunfounder01/b914aa48-85e7-4682-b420-89961cc761ca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
    * Avant de téléverser le code, assurez-vous que l'interrupteur est basculé vers la droite.

        .. image:: img/camera_upload.png
            :width: 600

    * Après avoir téléversé le code avec succès, basculez l'interrupteur vers la gauche pour démarrer l'ESP32 CAM.

        .. image:: img/camera_run.png
            :width: 600

    * Lorsque vous voyez les informations suivantes dans le Moniteur Série, vous pouvez passer à l'étape suivante.

        .. code-block:: arduino
        
            ...[OK]
            SET+PORT8765
            ...[OK]
            SET+START
            ...[OK]
            WebServer started on ws://192.168.4.1:8765
            Video streamer started on http://192.168.4.1:9000/mjpg
            WS+null

#.  Connectez-vous au réseau ``GalaxyRVR``.

    À ce stade, vous devez connecter votre appareil mobile au réseau local (LAN) fourni par le GalaxyRVR. 
    Cela permet à votre appareil mobile et au Rover d'être sur le même réseau, facilitant la communication 
    entre les applications de votre appareil mobile et le Rover.

    * Trouvez ``GalaxyRVR`` dans la liste des réseaux disponibles sur votre appareil mobile (tablette ou smartphone), entrez le mot de passe ``12345678`` et connectez-vous.

        .. image:: img/app/camera_lan.png

    * Le mode de connexion par défaut est le **mode AP**. Après vous être connecté, il se peut qu'un message vous avertisse que cette connexion réseau WLAN n'a pas accès à Internet ; choisissez de continuer la connexion.

        .. image:: img/app/camera_stay.png

#. Connectez et activez le contrôleur.

    * Revenez maintenant au contrôleur que vous avez créé précédemment (dans mon cas, il s'appelle "camera"). Utilisez le bouton |app_connect| pour lier le contrôleur SunFounder au Rover et établir une ligne de communication. Après un court délai, ``GalaxyRVR(IP)`` (le nom que vous avez défini dans le code avec ``#define NAME "GalaxyRVR"``) apparaîtra. Cliquez dessus pour établir une connexion.

        .. image:: img/app/camera_connect.png

        .. note::
            Si vous ne voyez pas ce message après un certain temps, vérifiez que votre Wi-Fi est bien connecté à ``GalaxyRVR``.

    * Une fois que vous voyez le message "Connexion réussie", appuyez sur le bouton |app_run|. Cela affichera les images en direct de la caméra sur l'application.

        .. image:: img/app/camera_view_app.png

    * Maintenant, déplacez le curseur et ouvrez simultanément le Moniteur Série de l'IDE Arduino. Vous devriez voir des données similaires à celles-ci.

        .. code-block:: 
            
            Slider D: 105
            WS+null
            Slider D: 105
            WS+null
            Slider D: 105
            WS+null


#. Laissez le curseur contrôler le mécanisme d'inclinaison.

    Maintenant que nous connaissons les valeurs transmises par le widget slider, nous pouvons utiliser directement ces valeurs pour faire pivoter le servo. 
    Par conséquent, sur la base du code précédent, ajoutez les lignes suivantes pour initialiser le servo et transmettre la valeur du slider au servo.


    .. code-block::

        ...
        #include <Servo.h>

        Servo myServo;  // créer un objet servo
        myServo.write(int(sliderD));  // contrôler le servo pour qu'il se déplace à l'angle actuel

        ...

        void onReceive() {
            ...
            myServo.write(int(sliderD));  // contrôler le servo pour qu'il se déplace à l'angle actuel
        }

        void setup() {
            ...
            myServo.attach(6);  // attacher le servo à la broche 6
            ...
        }

    Voici le code complet :
    
    .. raw:: html
    
        <iframe src=https://create.arduino.cc/editor/sunfounder01/b737352b-2509-4967-8147-1fd6bdc7d19d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

    Téléversez le code ci-dessus dans le GalaxyRVR, répétez les étapes 4 et 5 ci-dessus, reconnectez-vous au réseau ``GalaxyRVR`` et relancez l'application 
    SunFounder Controller, puis vous pourrez faire glisser le curseur pour contrôler le mécanisme d'inclinaison du Rover.

Vous avez maintenant appris à utiliser l'application SunFounder Controller et comment utiliser le widget slider pour contrôler les mouvements du servo. Ce processus vous permettra d'interagir avec votre GalaxyRVR de manière plus intuitive et directe.


**Étape 4 : Réflexion et résumé**

Utiliser l'application SunFounder Controller pour opérer votre Rover martien peut sembler un peu compliqué au début. Chaque fois que vous modifiez votre code, vous devrez répéter les étapes suivantes :

* Avant de téléverser le code, assurez-vous que l'interrupteur est basculé vers la droite.

    .. image:: img/camera_upload.png
        :width: 600

* Une fois le code téléversé avec succès, basculez l'interrupteur vers la gauche pour démarrer l'ESP32 CAM.
* Connectez-vous au réseau ``GalaxyRVR``.
* Connectez et exécutez le contrôleur.

Même si ces étapes peuvent sembler fastidieuses, elles sont cruciales pour le processus. Après les avoir répétées quelques fois, vous deviendrez plus à l'aise et familier avec la procédure.


Maintenant que nous avons terminé cette leçon, réfléchissons à ce que nous avons appris à travers quelques questions :

* En créant un nouveau contrôleur, vous avez rencontré de nombreux types de blocs différents. Avez-vous envisagé à quoi pourraient servir leurs fonctions individuelles ?
* Est-il possible d'utiliser d'autres widgets pour contrôler le mécanisme d'inclinaison ?
* Ou même de contrôler directement les mouvements du Rover martien ?

Explorons ces questions dans la prochaine leçon !
