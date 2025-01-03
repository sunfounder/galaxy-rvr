.. note::

    Bonjour, et bienvenue dans la communauté des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !


.. _quick_start:

Jouer rapidement avec l'application
=================================================

Plongez directement dans votre aventure martienne ! Avec le code préchargé en usine, vous pouvez commencer à utiliser votre GalaxyRVR juste après l'assemblage. Explorez des fonctionnalités telles que la conduite à la première personne, l'évitement d'obstacles, les modes de suivi et le contrôle vocal, le tout via l'application SunFounder Controller. Commencez votre voyage dès aujourd'hui !

.. raw:: html
    
    <video width="600" loop autoplay muted>
        <source src="_static/video/play_mode.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::  

    Si votre carte R3 est programmée avec un autre code et que vous souhaitez contrôler le GalaxyRVR via l'application, suivez les étapes décrites dans :ref:`upload_galaxy_code`.

Guide rapide
---------------------

#. Démarrons le GalaxyRVR.

   * Lors de la première utilisation de votre GalaxyRVR, il est recommandé de brancher un câble USB Type-C pour charger complètement la batterie. Ensuite, allumez-le.
    
     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_start.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

   * Pour activer l'ESP32 CAM, mettez l'interrupteur de mode en position **Run** et appuyez sur le bouton **reset** pour redémarrer la carte R3. Vous observerez alors une lumière cyan clignotant sur la bande inférieure.

     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Installez `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ depuis **APP Store (iOS)** ou **Google Play (Android)**.


#. Connectez-vous au réseau ``GalaxyRVR``.

   Pour une communication optimale entre votre appareil mobile et le Rover, vous devez les connecter au même réseau local (LAN) fourni par GalaxyRVR.

   * Trouvez ``GalaxyRVR`` dans la liste des réseaux disponibles sur votre appareil mobile (tablette ou smartphone), entrez le mot de passe ``12345678`` et connectez-vous.

     .. note::

        * La connexion actuelle est au point d'accès Galaxy, donc il n'y a pas d'accès Internet. Si on vous demande de changer de réseau, choisissez "Rester connecté".
        * :ref:`ap_to_sta`

     .. image:: img/app/camera_lan.png
        :width: 500


    
#. Configurez un contrôleur.

   * Pour créer un contrôleur dans l'application SunFounder Controller, appuyez sur l'icône **+**.

     .. image:: img/app/app1.png

   * Des contrôleurs préconfigurés sont disponibles pour certains produits, ici, nous choisissons **GalaxyRVR**. Donnez-lui un nom ou appuyez simplement sur **Confirmer**.

     .. image:: img/app/play_preset.jpg
    
   * Une fois à l'intérieur, l'application recherchera automatiquement le GalaxyRVR. Après un moment, vous verrez une invite indiquant "Connecté avec succès".

     .. image:: img/app/auto_connect.jpg

     .. note::

       * Si vous n'êtes pas connecté, veuillez confirmer que votre Wi-Fi est connecté à ``GalaxyRVR``.
       * Vous pouvez également appuyer sur le bouton |app_connect| pour vous connecter manuellement. Après une courte attente, vous devriez voir ``GalaxyRVR(IP)`` apparaître. Appuyez dessus pour établir une connexion.
     
       .. image:: img/app/camera_connect.png
           :width: 300
           :align: center


   * Maintenant, appuyez sur le bouton |app_run| pour visualiser le flux vidéo en direct de la caméra et contrôler la voiture à l'aide des widgets fournis. 

     .. image:: img/app/play_run_view.jpg

#. Examinons maintenant les fonctions de chaque widget :

   * **Servo(D)** : Contrôle le mécanisme d'inclinaison de la caméra du Rover, vous permettant d'observer une plage plus large.
   * :ref:`app_avoid` : Passe le Rover en mode évitement d'obstacles. Les distances de détection d'usine pour chaque module d'évitement d'obstacles peuvent varier. Un réglage manuel est nécessaire.
   * :ref:`app_follow` : Active le mode suivi du Rover. Les distances de détection d'usine pour chaque module d'évitement d'obstacles peuvent varier. Un réglage manuel est nécessaire.
   * **Stop(I)** : Arrête immédiatement tous les mouvements du Rover.
   * :ref:`app_speech_control` : Appuyez sur ce widget pour lancer la reconnaissance vocale et faire effectuer au Rover des actions correspondantes.
   * **HeadLamp(M)** : Permet d'allumer/éteindre la LED sur l'ESP32 CAM.
   * **Widgets de manette sur K et Q** : Le widget de manette dans la zone K contrôle les moteurs gauches du Rover, tandis que celui dans la zone Q contrôle les moteurs droits. La coordination des deux widgets permet au GalaxyRVR de se déplacer dans n'importe quelle direction.
   * **Left IR(N)** : Affiche les relevés du module d'évitement d'obstacles gauche.
   * **Ultrasonic(O)** : Affiche la distance mesurée par le module ultrasonique.
   * **Right IR(P)** : Affiche les relevés du module d'évitement d'obstacles droit.

.. _app_avoid:

Éviter (E)
------------------------

Appuyez sur le widget **Éviter (E)** pour activer le mode évitement d'obstacles.

Avant d'activer ce mode, vous devrez peut-être ajuster les plages de détection des capteurs en fonction de votre environnement, car les paramètres d'usine peuvent ne pas convenir à toutes les situations.

Voici comment ajuster les paramètres :

#. Commencez par ajuster le module d'évitement d'obstacles droit. Pendant le transport, les collisions peuvent faire incliner l'émetteur et le récepteur du module infrarouge. Vous devez donc les redresser manuellement.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Placez un obstacle à environ 20 cm directement devant le module droit. La boîte dans laquelle votre kit Rover est arrivé est un bon choix ! Maintenant, tournez le potentiomètre sur le module jusqu'à ce que le voyant sur le module s'allume. Ensuite, déplacez l'obstacle pour vérifier si le voyant s'allume à la distance souhaitée.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>


#. Répétez le même processus pour l'autre module.

.. _app_follow:

Suivi (F)
------------

Lorsque vous êtes prêt à activer le mode suivi, appuyez simplement sur le widget **Suivi (F)**. Si vous n'avez pas encore ajusté la distance de détection des modules d'évitement d'obstacles, vous devrez suivre les étapes dans :ref:`app_avoid`.

En mode suivi, le GalaxyRVR se déplacera vers un objet devant lui ou tournera à gauche ou à droite pour suivre les mouvements de l'objet.

.. _app_speech_control:

STT (J)
-------------------

STT signifie Speech to Text (Parole en texte). L'application SunFounder Controller s'intègre au moteur de reconnaissance vocale de votre appareil mobile. En appuyant et en maintenant le widget **STT(J)** sur le SunFounder Controller et en parlant à votre appareil mobile, celui-ci convertira votre discours en texte et l'enverra au GalaxyRVR. Si ce texte correspond aux commandes prédéfinies dans votre code, le Rover effectuera les actions correspondantes.

Les commandes actuelles dans le code sont les suivantes :

.. image:: img/app/play_speech.png
    :width: 600

* ``stop`` : Arrête tous les mouvements du rover.
* ``forward`` : Fait avancer le rover.
* ``backward`` : Fait reculer le rover.
* ``left`` : Fait tourner le rover à gauche.
* ``right`` : Fait tourner le rover à droite.

.. note::

    La fonction STT (Speech to Text) nécessite une connexion Internet et les services Google sur les appareils Android. Cependant, cela ne fonctionne pas avec le mode AP (point d'accès) par défaut sur le GalaxyRVR.
    
    En mode AP, le GalaxyRVR crée un réseau Wi-Fi local auquel votre appareil mobile peut se connecter, mais il ne fournit pas d'accès Internet.
    
    Pour utiliser la fonction STT sur Android, passez le code du Rover du mode AP au mode STA comme indiqué dans :ref:`stt_android`.

.. note::

    Les appareils iOS, utilisant un moteur de reconnaissance vocale hors ligne, fonctionnent bien à la fois en mode AP et STA. 
