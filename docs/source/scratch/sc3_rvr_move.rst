.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _rvr_move:

Leçon 3 : Piloter votre GalaxyRVR à distance
=============================================

Préparez-vous à prendre les commandes ! Dans cette leçon, vous allez devenir le commandant de mission de votre propre Rover Martien GalaxyRVR.

Nous allons transformer nos connaissances en programmation en actions concrètes, en codant votre rover pour qu'il navigue sur un terrain martien simulé. Regardez vos commandes donner vie au rover, qui se déplace exactement selon vos instructions, ici même dans la salle de classe.

Votre mission martienne commence vraiment ici – en avant !

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>

Objectifs d'apprentissage
-------------------------

* Établir la communication entre l'application Mammoth Coding et votre GalaxyRVR en téléchargeant le code Arduino nécessaire
* Maîtriser le contrôle des mouvements de votre rover à l'aide des touches fléchées de l'application
* Programmer et exécuter les quatre manœuvres fondamentales du rover : avancer, reculer, tourner à gauche et tourner à droite

.. _app_connect:

Connecter l'application au GalaxyRVR
-------------------------------------

.. note::

    * Si vous avez écrasé le micrologiciel et devez rétablir la communication, suivez :ref:`update_r3_firmware`.

.. raw:: html

   <iframe width="560" height="315" src="https://www.youtube.com/embed/kZIrm-_yWrA?si=Cbp0TxN-EZU_6Ksn" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

#. Avant d'utiliser le GalaxyRVR pour la première fois, chargez complètement la batterie avec le câble USB Type-C fourni. Une fois la charge terminée, mettez l'appareil sous tension.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_start.mp4" type="video/mp4">
            Votre navigateur ne prend pas en charge la balise vidéo.
        </video>

#. Pour démarrer l'ESP32-CAM, basculez l'interrupteur sur le mode **Run** et appuyez sur le bouton **Reset** de la carte R3. La bande lumineuse inférieure se mettra à clignoter pour indiquer un démarrage réussi.

   .. note::

      * Si la bande lumineuse inférieure affiche un **clignotement d'une couleur autre que le vert**, votre GalaxyRVR a besoin d'une mise à jour du micrologiciel. Veuillez consulter :ref:`update_firmware`.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_reset_green.mp4" type="video/mp4">
            Votre navigateur ne prend pas en charge la balise vidéo.
        </video>

#. Connectez votre appareil mobile au réseau WiFi du GalaxyRVR.

   * Le nom du réseau (SSID) est ``GalaxyRVR`` et le mot de passe est ``12345678``.
   * Si un message d'avertissement « Pas d'accès Internet » s'affiche, veuillez choisir l'option **« Rester connecté ».**

     .. image:: ../img/camera_lan.png
        :width: 500

#. Ouvrez l'application sur votre appareil mobile pour lancer le processus de connexion.

   .. image:: img/connet_app_04.png

#. Sélectionnez et chargez l'extension GalaxyRVR dans l'application.

   .. image:: img/connet_app_05.png

#. L'application va automatiquement rechercher les appareils GalaxyRVR disponibles.

   .. image:: img/connet_app_06.png

#. Sélectionnez votre GalaxyRVR dans la liste pour vous connecter.

   .. image:: img/reconnect_2.png

   .. note::

      L'état de la connexion est indiqué par les voyants LED du GalaxyRVR :

      - **Violet clignotant** : Recherche de connexion
      - **Éteint** : Connecté et prêt

Reconnecter l'application
-------------------------

Lorsque votre appareil est déconnecté du GalaxyRVR, cette fenêtre contextuelle apparaît dans l'interface. Cliquez sur reconnecter.

   .. image:: img/reconnect_0.png

Si vous fermez la fenêtre contextuelle, vous pouvez également vous reconnecter en cliquant sur ce bouton dans la catégorie GalaxyRVR.

   .. image:: img/reconnect_1.png

Trouvez votre GalaxyRVR et cliquez sur connecter.

   .. image:: img/reconnect_2.png


Piloter le GalaxyRVR avec l'application
---------------------------------------

1. Dans l'interface de codage, trouvez la catégorie dédiée GalaxyRVR contenant tous les blocs de contrôle du rover.

   .. image:: img/3_rvr_catego.png

2. Bien que nous utilisions généralement le drapeau vert pour lancer les programmes, il existe d'autres façons de déclencher des actions. Trouvez le bloc ``when up arrow key pressed`` dans la catégorie Événements – il exécutera du code chaque fois que vous appuierez sur cette touche spécifique.


   .. image:: img/3_rvr_when_arrow.png

3. Créez quatre blocs d'événement – un pour chaque direction (haut, bas, gauche, droite). Cela constituera la base du système de contrôle de votre rover.

   .. image:: img/3_rvr_4_arrow.png
        :width: 800
        :align: center

   .. note:: Besoin de plus d'espace de codage ? Cliquez sur l'icône en forme d'œil sous le drapeau vert pour masquer temporairement la zone de la scène.

4. Complétez maintenant chaque bloc d'événement avec la commande de mouvement correspondante :

   - Flèche haut → Avancer
   - Flèche bas → Reculer
   - Flèche gauche → Tourner à gauche
   - Flèche droite → Tourner à droite

   .. image:: img/3_rvr_4_dir.png
        :width: 800
        :align: center

5. Cliquez sur le bouton d'expansion de la scène pour passer en mode de contrôle complet.

   .. image:: img/3_rvr_stage.png

6. Vous verrez maintenant une scène agrandie avec des touches directionnelles virtuelles. Appuyez sur ces touches et regardez comment vous contrôlez directement les mouvements de votre GalaxyRVR en temps réel !

   .. image:: img/3_rvr_stage2.png


Blocs de contrôle des mouvements
--------------------------------

* **Contrôle de la direction de base**

  Contrôle la direction du mouvement du GalaxyRVR. Utilisez le menu déroulant pour sélectionner avancer, reculer, tourner à gauche ou tourner à droite.

  .. image:: img/block/move_forward.png

* **Réglage de la vitesse**

  Définit la vitesse de déplacement du GalaxyRVR. Note : Ce bloc définit uniquement la vitesse et ne déclenche pas le mouvement par lui-même.

  .. image:: img/block/move_set_speed.png

* **Mouvement chronométré**

  Fait avancer le GalaxyRVR dans la direction sélectionnée pendant une durée déterminée. Vous pouvez :

  * Choisir la direction (avancer/reculer/gauche/droite) dans le menu déroulant
  * Définir la durée du mouvement en modifiant la valeur de temps

  .. image:: img/block/move_forward_1s.png

* **Mouvement avec contrôle de la vitesse**

  Déplace le GalaxyRVR à un pourcentage de vitesse spécifique. Vous pouvez :

  * Sélectionner la direction du mouvement dans le menu déroulant
  * Ajuster le pourcentage de vitesse (0-100 %)

  .. image:: img/block/move_forward_80.png

* **Contrôle précis des mouvements**

  Combine le contrôle de la vitesse et de la durée pour des mouvements précis. Vous pouvez :

  * Définir la direction du mouvement
  * Ajuster le pourcentage de vitesse
  * Définir la durée du mouvement

  .. image:: img/block/move_forward_80_1s.png

* **Contrôle avancé des roues**

  Permet un contrôle indépendant de chaque roue pour des manœuvres complexes. Vous pouvez :

  * Régler séparément la vitesse de la roue gauche
  * Régler séparément la vitesse de la roue droite
  * Contrôler la durée du mouvement

  .. image:: img/block/move_lr_sp_1s.png

* **Arrêt d'urgence**

  Arrête immédiatement tout mouvement du GalaxyRVR.

  .. image:: img/block/move_stop.png
