.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 13 : Contrôle complet du Rover Martien
============================================

Vous maîtrisez tous les éléments – maintenant, assemblons-les ! Combinez tout ce que vous avez appris pour créer votre Rover Martien entièrement fonctionnel avec vue caméra en direct, commandes de mouvement et inclinaison de la caméra.

Rassemblez trois systèmes incroyables :

- :ref:`camera_system` : Voyez à travers les yeux de votre rover avec la vidéo en direct
- :ref:`rgb_move` : Pilotez avec des signaux lumineux colorés
- :ref:`tilt_system` : Regardez vers le haut et vers le bas avec les commandes de la caméra

Le résultat ? Un contrôle complet de votre GalaxyRVR ! Cliquez sur les boutons pour les commandes de la caméra et utilisez les touches fléchées pour piloter.

.. image:: img/13_camera_go_all2.png


Système de caméra
-----------------

Reprenez la configuration de la caméra de la leçon précédente : :ref:`camera_system`.

1. Créez quatre sprites de contrôle et disposez-les proprement.

   .. image:: img/11_camera_4.png

2. Programmez la fonction de chaque bouton :

   - Balle 1 : Caméra ÉTEINTE

   .. image:: img/11_camera_1sp.png

   - Balle 2 : Caméra ALLUMÉE avec orientation correcte

   .. image:: img/11_camera_2sp.png

   - Ballon 1 : Lumière LED ALLUMÉE

   .. image:: img/11_camera_3sp.png

   - Ballon 2 : Lumière LED ÉTEINTE

   .. image:: img/11_camera_4sp.png

3. Empilez les contrôles pour gagner de l'espace – ils se déplieront quand vous en aurez besoin !

   .. image:: img/11_camera_fold.png

4. Ajoutez ``go to back layer`` pour créer un effet de basculement entre les boutons.

   .. image:: img/11_camera_layer.png

Système de mouvement et d'éclairage
-----------------------------------

Ajoutons des lumières colorées aux mouvements de votre rover ! Nous avons déjà codé cela dans la section :ref:`rgb_move`.

Nous vous recommandons de placer ce code dans la section Arrière-plans – cela le sépare du code des sprites et rend l'ensemble plus organisé.

   .. image:: img/13.ccc_code_in_stage.png

1. Faites briller votre rover en VERT lorsqu'il avance.

   .. image:: img/13.ccc_light_forward.png

2. Faites briller votre rover en ROUGE lorsqu'il recule.

   .. image:: img/13.ccc_light_backfwd.png

3. Faites briller votre rover en JAUNE lorsqu'il tourne à gauche ou à droite.

   .. image:: img/13.ccc_light_left_right.png

4. Créez un effet de lumière bleue respirante lorsque votre rover est à l'arrêt.

   .. image:: img/13.ccc_light_breath.png

Votre code d'arrière-plan complet devrait ressembler à ceci :

   .. image:: img/11_camera_backdrops.png

Contrôle de l'inclinaison de la caméra
--------------------------------------

Ajoutons les commandes de la caméra ! Cette partie est identique à :ref:`tilt_system`. Répétez simplement les étapes.

1. Ajoutez un sprite **Arrow** pour contrôler l'inclinaison de votre caméra.

   .. image:: img/10_servo_arrow.png

2. Commencez par un bloc ``when this sprite clicked``.

   .. image:: img/6_animate_when_touch.png
       :width: 200

3. Créez une boucle qui s'exécute pendant que vous touchez la flèche.

   .. image:: img/6_animate_repeat_touching.png
       :width: 400

4. Faites pointer la flèche vers votre doigt lorsque vous la faites glisser.

   .. image:: img/10_servo_arrow_point_toward.png
       :width: 400

5. Liez la direction de la flèche à l'angle de la caméra – tournez la flèche pour déplacer la caméra !

   .. image:: img/10_servo_arrow_angle_direction.png
       :width: 800

6. Définissez les limites pour maintenir la caméra entre 0 et 135 degrés.

   .. image:: img/10_servo_arrow_135.png
       :width: 400

   .. image:: img/10_servo_arrow_0.png
       :width: 400

Touchez et faites glisser la flèche pour orienter la caméra de votre rover ! Agrandissez la flèche si elle est difficile à contrôler.

Contrôle complet de votre GalaxyRVR
-----------------------------------

Vous avez maintenant le contrôle total de votre Rover Martien ! Voici comment piloter votre GalaxyRVR complet :

.. image:: img/13_camera_go_all2.png

**Pilotez votre Rover :**

- Utilisez les touches fléchées pour avancer, reculer et tourner
- Cliquez sur les sprites Balle pour allumer et éteindre la vidéo en direct de la caméra
- Cliquez sur les sprites Ballon pour allumer et éteindre la lumière LED de la caméra
- Faites glisser le sprite Flèche pour incliner la caméra vers le haut et vers le bas

**Testez toutes les fonctionnalités ensemble :**

- Pilotez tout en regardant le flux vidéo en direct de votre rover
- Remarquez les lumières colorées qui signalent chaque mouvement
- Entraînez-vous à incliner la caméra pour regarder les objets sous différents angles
- Essayez d'explorer dans des conditions claires et sombres en utilisant la lumière LED

Félicitations ! Vous avez réussi à combiner tous les systèmes pour créer un Rover Martien entièrement fonctionnel. Vous avez appris à programmer le mouvement, l'éclairage, les commandes de la caméra et les mécanismes d'inclinaison – toutes les compétences nécessaires pour piloter un véritable robot d'exploration.

Votre mission martienne est maintenant prête à commencer. Bonne exploration !
