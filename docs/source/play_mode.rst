.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur du Raspberry Pi, de l'Arduino et de l'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Soutien d'experts** : Résolvez les problèmes après-vente et surmontez les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez astuces et tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et à des promotions lors des fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _play_mode:

Mode Jeu
=========================

Vous êtes impatient de commencer votre aventure martienne ? Le Mode Jeu est conçu pour ceux qui veulent plonger directement dans l'action. Grâce au code préchargé en usine, vous pouvez entrer immédiatement en scène après avoir assemblé votre GalaxyRVR. Utilisez l'application conviviale SunFounder Controller pour explorer ses nombreuses fonctionnalités, y compris la conduite en vue à la première personne, le basculement entre les modes évitement d'obstacles et suivi, et même le contrôle vocal.

.. raw:: html
    
    <video width="600" loop autoplay muted>
        <source src="_static/video/play_mode.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

Mais avant de vous lancer dans l'exploration de la planète rouge, assurons-nous que vous êtes bien équipé et prêt pour cette aventure. Voici un guide rapide pour vous aider dans cette excitante exploration !

.. note::

    * Si votre carte R3 a déjà été programmée avec un autre code et que vous souhaitez continuer à utiliser le Mode Jeu, vous devrez télécharger le code correspondant.

        * :download:`GalaxyRVR Codes <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/main.zip>`

    * Installez |link_download_arduino|, puis :ref:`install_lib`

    * Ensuite, ouvrez le fichier ``galaxy-rvr.ino`` situé dans le répertoire ``galaxy-rvr-main\galaxy-rvr``.

    .. note:: Dans le programme d'exemple, il vous sera demandé de connecter votre appareil mobile au point d'accès créé par le GalaxyRVR, ce qui vous empêchera d'utiliser les réseaux externes en même temps. Vous pouvez :ref:`ap_to_sta`. Une fois configuré en mode STA, tant que votre appareil et le GalaxyRVR sont sur le même réseau WLAN, vous pourrez contrôler le GalaxyRVR.

    * Déplacez l'interrupteur vers la droite, puis cliquez sur **Téléverser**.

    .. image:: img/camera_upload.png
        :width: 400
        :align: center

Guide rapide
---------------------

#. Commençons par démarrer le GalaxyRVR.

    * Lors de la première utilisation de votre GalaxyRVR, il est recommandé de brancher un câble USB Type-C pour charger complètement la batterie. Ensuite, allumez-le.
    
        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/play_start.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    * Pour activer l'ESP32 CAM, déplacez l'interrupteur de mode sur la position **Run**, puis appuyez sur le bouton **reset** pour redémarrer la carte R3. Vous verrez alors une lumière cyan clignoter sur la bande inférieure.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/play_reset.mp4" type="video/mp4">
                Votre navigateur ne supporte pas la balise vidéo.
            </video>

#. Installez `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ depuis l'**APP Store (iOS)** ou **Google Play (Android)**.

#. Connectez-vous au réseau ``GalaxyRVR``.

    Pour une communication optimale entre votre appareil mobile et le Rover, vous devez les connecter au même réseau local (LAN) fourni par GalaxyRVR.

    * Recherchez ``GalaxyRVR`` dans la liste des réseaux disponibles sur votre appareil mobile (tablette ou smartphone), entrez le mot de passe ``12345678``, et connectez-vous.

        .. image:: img/app/camera_lan.png

    * Le mode de connexion par défaut est le **mode AP**. Après votre connexion, il se peut qu'un message apparaisse indiquant qu'il n'y a pas d'accès à Internet sur ce réseau. Dans ce cas, choisissez "Rester connecté".

        .. image:: img/app/camera_stay.png

#. Configurez un contrôleur.

    * Pour créer un contrôleur sur SunFounder Controller, appuyez sur l'icône **+**.

        .. image:: img/app/app1.png

    * Des contrôleurs prédéfinis sont disponibles pour certains produits. Ici, nous choisissons **GalaxyRVR**. Donnez-lui un nom ou appuyez simplement sur **Confirmer**.

        .. image:: img/app/play_preset.jpg
    
    * Une fois à l'intérieur, l'application recherchera automatiquement le GalaxyRVR. Après un moment, vous verrez un message indiquant "Connexion réussie".

        .. image:: img/app/auto_connect.jpg

        .. note::

            * Si la connexion échoue, vérifiez que votre Wi-Fi est bien connecté à ``GalaxyRVR``.
            * Vous pouvez également appuyer sur le bouton |app_connect| pour vous connecter manuellement. Après une courte attente, ``GalaxyRVR(IP)`` apparaîtra. Appuyez dessus pour établir la connexion.

            .. image:: img/app/camera_connect.png
                :width: 300
                :align: center

    * Appuyez maintenant sur le bouton |app_run| pour afficher le flux vidéo en direct de la caméra et contrôler la voiture à l'aide des widgets fournis.

        .. image:: img/app/play_run_view.jpg

#. Explorons maintenant les fonctions de chaque widget :

        * **Servo(D)** : Contrôle le mécanisme d'inclinaison de la caméra du Rover, vous permettant d'observer une zone plus large.

        * :ref:`app_avoid` : Passe le Rover en mode évitement d'obstacles. Les distances de détection définies en usine pour chaque module d'évitement d'obstacles peuvent varier. Un ajustement manuel est nécessaire.

        * :ref:`app_follow` : Passe le Rover en mode suivi. Les distances de détection définies en usine pour chaque module d'évitement d'obstacles peuvent varier. Un ajustement manuel est nécessaire.

        * **Stop(I)** : Arrête immédiatement tous les mouvements du Rover.

        * :ref:`app_speech_control` : Appuyez sur ce widget pour activer la reconnaissance vocale et faire exécuter au Rover les actions correspondantes.

        * **HeadLamp(M)** : Permet d'allumer/éteindre la LED sur l'ESP32 CAM.
        * **Widgets Throttle sur K et Q** : Le widget de la zone K contrôle les moteurs gauches du Rover, tandis que celui de la zone Q contrôle les moteurs droits. La coordination des deux widgets permet au GalaxyRVR de se déplacer dans toutes les directions.

        * **IR gauche(N)** : Affiche les relevés du module d'évitement d'obstacles gauche.

        * **Ultrason(O)** : Affiche la distance mesurée par le module ultrasonique.

        * **IR droit(P)** : Affiche les relevés du module d'évitement d'obstacles droit.

.. _app_avoid:

Évitement(E)
------------------------

Appuyez sur le widget **Évitement(E)** pour activer le mode d'évitement d'obstacles.

Avant d'activer ce mode, il est recommandé d'ajuster les plages de détection des capteurs en fonction de votre environnement, car les réglages d'usine peuvent ne pas être adaptés à toutes les situations.

Si la portée de détection des deux modules infrarouges est trop courte, le Rover martien pourrait heurter des obstacles. Inversement, si la portée est trop longue, le Rover pourrait s'écarter trop loin d'un obstacle, perturbant ainsi sa navigation.

Voici comment ajuster les réglages :

#. Commencez par ajuster le module d'évitement d'obstacles droit. Pendant le transport, des collisions peuvent provoquer l'inclinaison de l'émetteur et du récepteur du module infrarouge. Vous devrez donc les redresser manuellement.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Placez un obstacle à environ 20 cm directement devant le module droit. La boîte dans laquelle notre kit Rover est arrivé est un bon choix ! Maintenant, tournez le potentiomètre sur le module jusqu'à ce que le voyant du module s'allume. Ensuite, déplacez l'obstacle d'avant en arrière pour vérifier si le voyant s'allume à la distance souhaitée. Si le voyant ne s'allume pas à la distance correcte ou s'il reste allumé, vous devrez ajuster l'autre potentiomètre.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Répétez le même processus pour l'autre module.

.. _app_follow:

Suivi(F)
------------

Lorsque vous êtes prêt à activer le mode suivi, appuyez simplement sur le widget **Suivi(F)**. Si vous n'avez pas encore ajusté la distance de détection des modules d'évitement d'obstacles, suivez les étapes de :ref:`app_avoid` d'abord.

En mode suivi, le GalaxyRVR se déplacera vers un objet placé devant lui ou tournera à gauche ou à droite pour suivre les mouvements de cet objet.

.. _app_speech_control:

STT(J)
-------------------

STT signifie "Speech to Text" (Reconnaissance vocale). L'application SunFounder Controller s'intègre au moteur de reconnaissance vocale de votre appareil mobile. Ainsi, lorsque vous appuyez et maintenez le widget **STT(J)** sur le SunFounder Controller et que vous parlez à votre appareil mobile,

Celui-ci capturera votre voix, la convertira en texte et l'enverra au GalaxyRVR. Si ce texte correspond aux commandes prédéfinies dans votre code, le Rover exécutera les actions correspondantes.

Voici les commandes actuellement prédéfinies dans le code. Prononcez l'une des commandes suivantes et observez la réaction du GalaxyRVR.

.. image:: img/app/play_speech.png
    :width: 600

* ``stop`` : Arrête tous les mouvements du Rover.
* ``forward`` : Fait avancer le Rover.
* ``backward`` : Fait reculer le Rover.
* ``left`` : Fait tourner le Rover à gauche.
* ``right`` : Fait tourner le Rover à droite.

.. note::

    La fonction STT (Speech to Text) nécessite une connexion Internet et les services Google sur les appareils Android. Cependant, cela ne fonctionne pas avec le mode AP (Point d'accès) prédéfini du GalaxyRVR.
    
    En mode AP, le GalaxyRVR crée un réseau Wi-Fi local auquel votre appareil mobile peut se connecter, mais il ne fournit pas d'accès à Internet.
    
    Pour utiliser la fonction STT sur Android, basculez le code du Rover du mode AP au mode STA comme expliqué dans :ref:`stt_android`.

.. note::

    Les appareils iOS, utilisant un moteur de reconnaissance vocale hors ligne, fonctionnent correctement à la fois en mode AP et STA.
