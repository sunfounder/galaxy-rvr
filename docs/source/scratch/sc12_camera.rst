.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 12 : Voir à travers les yeux de votre Rover
=================================================

Maintenant que votre rover peut hocher sa caméra, donnons-lui une vraie vision ! Dans cette leçon, vous apprendrez à voir exactement ce que votre Rover Martien voit à travers sa caméra.

Regardez la vidéo en direct du point de vue de votre rover pendant qu'il explore – observez les paysages martiens, découvrez des rochers intéressants et naviguez comme un véritable explorateur spatial !

.. image:: img/11_camera_image.png

Objectifs d'apprentissage
-------------------------

* Visionner en temps réel les images de la caméra de votre Rover Martien
* Combiner la visualisation de la caméra avec le contrôle du servo pour une exploration interactive

Voici les yeux de votre Rover : l'ESP32-CAM
-------------------------------------------

Dites bonjour à l'ESP32-CAM – le puissant système de vision de votre rover ! Ce module incroyable, c'est comme donner à votre rover des yeux super-intelligents.

.. image:: img/esp32_cam.png
    :width: 400
    :align: center

L'ESP32-CAM fait deux choses incroyables :

1. **Prend des photos et des vidéos** de tout ce que votre rover regarde
2. **Transmet la vidéo** directement sur votre téléphone ou votre ordinateur

C'est comme être sur Mars avec votre rover ! Vous verrez tout ce qu'il voit, en temps réel. Prêt à commencer l'exploration à travers les yeux de votre rover ?

.. _camera_system:

Explorer le système de caméra de votre Rover
--------------------------------------------

1. Glissez un bloc ``turn camera ON`` et cliquez dessus – regardez la scène se transformer en une vue caméra en direct de votre rover !

   .. image:: img/11_camera_on.png

2. Si l'image de la caméra apparaît à l'envers, utilisez ``set camera image orientation to inverted`` pour la corriger.

   .. image:: img/11_camera_orientation.png

3. Besoin de plus de lumière ? Utilisez ``turn camera LED ON`` pour activer la lumière intégrée de la caméra.

   .. image:: img/11_camera_led.png

**Créer des boutons de contrôle de la caméra**

1. Construisons un panneau de contrôle de la caméra ! Créez quatre sprites et disposez-les proprement.

   .. image:: img/11_camera_4.png

2. Programmez chaque bouton :

   - Balle 1 : Éteint la caméra

   .. image:: img/11_camera_1sp.png

   - Balle 2 : Allume la caméra et définit l'orientation

   .. image:: img/11_camera_2sp.png

   - Ballon 1 : Allume la LED

   .. image:: img/11_camera_3sp.png

   - Ballon 2 : Éteint la LED

   .. image:: img/11_camera_4sp.png

3. Gagnez de l'espace en empilant les contrôles – ils apparaîtront quand vous en aurez besoin !

   .. image:: img/11_camera_fold.png

4. Ajoutez ``go to back layer`` à chaque sprite – cliquer sur un bouton révèle le suivant, créant un effet de basculement.

   .. image:: img/11_camera_layer.png

5. Cliquez sur le bouton d'expansion de la scène pour passer en mode de contrôle complet.

   .. image:: img/11_camera_go_stage.png

6. Vous verrez maintenant la vidéo en direct du point de vue de votre rover pendant qu'il explore – observez les paysages martiens, découvrez des rochers intéressants et naviguez comme un véritable explorateur spatial !

   .. image:: img/11_camera_image.png

Blocs de contrôle de la caméra
------------------------------

* Allume ou éteint la caméra. Lorsqu'elle est allumée, la scène affiche la vidéo en direct de votre rover !

  .. image:: img/block/camera_turn.png

* Contrôle la lumière LED de la caméra – parfait pour les explorations dans l'obscurité.

  .. image:: img/block/camera_led_turn.png

* Ajuste la transparence de la vue caméra.

  .. image:: img/block/camera_transp.png

* Retourne l'image de la caméra si elle apparaît à l'envers.

  .. image:: img/block/camera_orientation.png
