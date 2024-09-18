.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, de l'Arduino et de l'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions lors des fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Leçon 12 Système de Caméra
================================================

Bienvenue de nouveau, jeunes explorateurs ! Lors de la dernière leçon, nous avons équipé notre GalaxyRVR de la capacité de "hocher la tête" grâce à un mécanisme d'inclinaison. Maintenant, il est temps de donner à notre Rover des "yeux" - la caméra !

Dans cette aventure passionnante, nous allons configurer le système de caméra du Rover. Vous apprendrez à transmettre les images capturées par la caméra du Rover à l'APP, afin que vous puissiez voir exactement ce que le Rover voit en temps réel. Imaginez l'excitation de découvrir le paysage martien depuis la perspective du Rover !

Cela offre une expérience encore plus interactive et captivante avec notre GalaxyRVR. Restez à l'affût pour de nouvelles aventures !

.. image:: img/11_camera_image.png


Objectifs d'apprentissage
-----------------------------

* Apprendre à voir en temps réel tout ce que le Rover martien voit.
* Comprendre comment combiner l'entrée de la caméra et le contrôle du servo pour améliorer l'interactivité du projet.

Matériel
---------

* Smartphone ou tablette
* Application Mammoth Coding
* GalaxyRVR

Introduction à l'ESP32 CAM
-------------------------------------------------------

Lors de notre précédente aventure, nous avons équipé notre Rover martien d'une paire d'"yeux" en intégrant l'ESP32 CAM. Aujourd'hui, nous allons en apprendre davantage et lui permettre de "voir" réellement.

.. image:: ../img/esp32_cam.png
    :width: 400
    :align: center

L'ESP32 CAM, agissant comme les yeux de notre Rover, est un module petit mais puissant. Il intègre non seulement des fonctionnalités Wi-Fi et Bluetooth, mais il est également équipé d'une caméra compacte. Cette caméra permet à notre Rover de capturer des images de son environnement.

Tout comme nous utilisons nos yeux pour observer notre environnement, l'ESP32 CAM peut "voir" ce qui se trouve devant le Rover, puis envoyer ces données visuelles à notre smartphone ou ordinateur. Cela nous permet de voir tout ce que le Rover voit en temps réel !

C'est comme si nous pilotions directement le Rover, observant non seulement le Rover lui-même, mais aussi le monde qu'il explore ! Incroyable, non ? Alors, plongeons plus profondément dans son fonctionnement...

.. _camera_system:

Exploration du Système Visuel du Rover Martien
----------------------------------------------------

1. Faites glisser un bloc ``activer la caméra``. Cliquez dessus, et vous verrez l'arrière-plan de la scène afficher le flux de la caméra.

.. image:: img/11_camera_on.png
.. :align: center

2. Si vous voyez le flux de la caméra inversé, un bloc ``mettre l'orientation de l'image de la caméra à inversé`` peut vous aider à le corriger.

.. image:: img/11_camera_orientation.png
.. :align: center

3. Faites glisser un bloc ``activer la LED de la caméra``. Cliquez dessus, et la LED à côté de la caméra du GalaxyRVR s'allumera.

.. image:: img/11_camera_led.png
.. :align: center

**Cliquez sur le Sprite pour Allumer la Caméra**

1. Maintenant que nous savons comment contrôler le module de caméra, créez quatre nouveaux sprites pour contrôler la caméra et sa LED. Ajustez leur taille pour qu'ils soient harmonieux.

.. image:: img/11_camera_4.png
.. :align: center

2. Programmez chaque sprite : cliquer sur la balle 1 éteindra la caméra.

.. image:: img/11_camera_1sp.png
.. :align: center

3. Cliquer sur la balle 2 allumera la caméra et réglera l'orientation de l'image.

.. image:: img/11_camera_2sp.png
.. :align: center

4. Cliquer sur le ballon 3 allumera la LED.

.. image:: img/11_camera_3sp.png
.. :align: center

5. Cliquer sur le ballon 4 éteindra la LED.

.. image:: img/11_camera_4sp.png
.. :align: center

6. Pour gagner de l'espace sur la scène, superposez chaque ensemble de contrôles.

.. image:: img/11_camera_fold.png
.. :align: center

7. Ajoutez un bloc ``aller à l'arrière-plan`` pour chaque sprite. Lorsqu'on clique dessus, le sprite se déplacera vers l'arrière-plan, révélant le sprite suivant, créant ainsi un effet de bascule.

.. image:: img/11_camera_layer.png
.. :align: center



Blocs Liés à la Caméra
---------------------------------

.. image:: img/block/camera_turn.png

Activez (ou désactivez) le module de caméra. Une fois activé, l'arrière-plan de la scène changera pour afficher la vue de la caméra.

.. image:: img/block/camera_led_turn.png

Activez (ou désactivez) la LED supplémentaire sur le module de caméra.

.. image:: img/block/camera_transp.png

Réglez l'opacité de la vue de la caméra.

.. image:: img/block/camera_orientation.png

Réglez l'orientation de la vue de la caméra. Vous pouvez utiliser ce bloc pour retourner la vue.
