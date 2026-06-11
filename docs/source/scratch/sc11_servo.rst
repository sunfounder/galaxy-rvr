.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 11 : Contrôler l'inclinaison de la caméra de votre Rover
==============================================================

Offrez une caméra mobile à votre Rover Martien ! Tout comme vous pouvez hocher la tête de haut en bas, votre rover peut désormais incliner sa caméra pour explorer le paysage martien sous différents angles.

Nous allons utiliser un moteur spécial appelé « servo » qui peut se déplacer vers des positions précises – parfait pour contrôler l'inclinaison de la caméra de votre rover. Apprenez à programmer le servo pour regarder vers le haut, vers les montagnes martiennes, ou vers le bas, sur des rochers intéressants !

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/servo_range.mp4" type="video/mp4">
        Votre navigateur ne prend pas en charge la balise vidéo.
    </video>

Objectifs d'apprentissage
-------------------------

* Découvrir comment fonctionne un servo
* Apprendre à contrôler les angles de la caméra à l'aide de blocs de code simples
* Créer des projets interactifs permettant d'incliner la caméra avec des commandes tactiles

Qu'est-ce qu'un servo ?
-----------------------

Voici le servo – le muscle mobile de votre robot !

Tout comme vous pouvez positionner votre bras exactement là où vous le souhaitez, un servomoteur peut se déplacer vers des angles spécifiques et les maintenir parfaitement. Pensez-y comme à un moteur intelligent qui sait exactement où s'arrêter.

.. image:: img/servo.png
    :align: center

**Connexions simples :**

- Fil marron : Masse (-)
- Fil rouge : Alimentation (+)
- Fil orange : Signal (indique au servo où se déplacer)

Dans votre Rover Martien, le servo agit comme une tête qui hoche – déplaçant la caméra de haut en bas pour capturer la vue parfaite !

Comment fonctionne un servo ?
-----------------------------

À l'intérieur de chaque servo, une équipe intelligente travaille ensemble :

.. image:: img/servo_internal.png
    :align: center

1. **Moteur classique** – Tourne rapidement comme les roues de votre rover
2. **Engrenages** – Ralentissent le mouvement et le rendent plus puissant
3. **Circuit de contrôle** – Sait exactement dans quelle position se trouve le servo
4. **Capteur de position** – Indique où le servo est orienté

Nous contrôlons les servos à l'aide de signaux spéciaux qui disent « va à cet angle exact ! » C'est comme dire à un ami exactement de combien tourner la tête.

Prêt à faire danser votre servo ? Commençons la programmation !


Contrôler le système d'inclinaison de votre Rover
-------------------------------------------------

Apprenons à contrôler le système d'inclinaison de votre Rover Martien – la partie qui déplace la caméra de haut en bas comme une tête qui hoche !

**Régler l'angle de la caméra**

1. Commencez par :ref:`app_connect`.

2. Vérifiez l'angle actuel du servo – il s'affiche sur la scène.

   .. image:: img/10_servo_angle.png

3. Glissez un bloc ``set servo angle to 90 degrees``. Cliquez dessus pour que votre rover regarde vers l'avant.

   .. image:: img/10_servo_set_angle.png

4. Changez la valeur à 45 et cliquez – votre rover regarde maintenant vers le ciel martien !

   .. image:: img/10_servo_set_angle_45.png

5. Expérimentez avec différents angles ! Vous découvrirez que votre rover peut s'incliner entre 0 et 135 degrés.

**Créer des commandes de caméra**

1. Construisons un panneau de contrôle pour la caméra de votre rover :

2. Créez un bouton de réinitialisation – glissez un bloc ``when this sprite clicked``.

   .. image:: img/10_servo_when_click.png

3. Ajoutez ``set servo angle to 90 degrees`` pour que la caméra regarde à nouveau vers l'avant.

   .. image:: img/10_servo_when_90.png

4. Ajoutez les commandes haut/bas – glissez les blocs ``when up arrow key pressed`` et ``when down arrow key pressed``.

   .. image:: img/10_servo_when_up.png

5. Programmez la flèche haut pour diminuer l'angle (regarder vers le haut).

   .. image:: img/10_servo_when_up2.png

6. Programmez la flèche bas pour augmenter l'angle (regarder vers le bas).

   .. image:: img/10_servo_when_down.png

Cliquez maintenant sur le bouton plein écran et prenez le contrôle ! Utilisez les touches fléchées pour ajuster la vue de votre rover, et cliquez sur le sprite pour réinitialiser. Vous êtes le cadreur !

.. _tilt_system:

Contrôle tactile de l'angle de la caméra
----------------------------------------

Créez une caméra à contrôle tactile ! Faites glisser une flèche pour orienter la caméra de votre rover exactement où vous le souhaitez.

1. Videz la scène en supprimant les sprites existants.

   .. image:: img/6_animate_delete.png

2. Ajoutez un sprite Arrow à utiliser comme contrôleur tactile.

   .. image:: img/10_servo_arrow.png

3. Commencez par ``when this sprite clicked`` pour activer le contrôle tactile.

   .. image:: img/6_animate_when_touch.png
       :width: 200

4. Créez une boucle qui s'exécute pendant que vous touchez la flèche.

   .. image:: img/6_animate_repeat_touching.png
       :width: 400

5. Faites pointer la flèche vers votre doigt lorsque vous la faites glisser.

   .. image:: img/10_servo_arrow_point_toward.png
       :width: 400

6. Liez la direction de la flèche à l'angle de la caméra – tournez la flèche, déplacez la caméra !

   .. image:: img/10_servo_arrow_angle_direction.png
       :width: 800

7. Définissez des limites pour maintenir la caméra entre 0 et 135 degrés.

   .. image:: img/10_servo_arrow_135.png
       :width: 400

   .. image:: img/10_servo_arrow_0.png
       :width: 400

Touchez et faites glisser la flèche pour orienter la caméra de votre rover ! Faites en sorte que la flèche bouge de manière fluide et réponde instantanément à votre toucher pour une sensation de contrôle réaliste.

Blocs de contrôle du servo
--------------------------

* Réglez le servo sur un angle spécifique (0-135 degrés)

  .. image:: img/block/servo_set_angle.png

* Augmentez ou diminuez l'angle du servo (utilisez des nombres négatifs pour diminuer)

  .. image:: img/block/servo_increase_angle.png

* Vérifiez l'angle actuel du servo

  .. image:: img/block/servo_value.png
