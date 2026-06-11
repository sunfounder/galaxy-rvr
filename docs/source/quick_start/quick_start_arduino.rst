.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Jeu Rapide avec Arduino
===============================

Dans ce chapitre, vous apprendrez à **ouvrir et exécuter rapidement des codes d'exemple Arduino spécifiques** pour faire exécuter diverses actions à votre GalaxyRVR.

Si vous souhaitez comprendre la logique du code et les principes de programmation derrière ces exemples, veuillez consulter le chapitre :ref:`programming_arduino`.

Comment ouvrir rapidement un exemple Arduino
-----------------------------------------------

Dans cet exemple, nous allons montrer comment utiliser l'IDE Arduino pour ouvrir un exemple Arduino.

#. Démarrez le GalaxyRVR.

   * Lors de la première utilisation du GalaxyRVR, il est recommandé de charger complètement la batterie en branchant un câble USB Type-C. Ensuite, allumez l'alimentation.

     .. raw:: html

          <video width="600" loop autoplay muted>
              <source src="../_static/video/play_start.mp4" type="video/mp4">
              Your browser does not support the video tag.
          </video>

    * L'ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Donc, avant de téléverser le code, vous devez d'abord libérer l'ESP32-CAM en faisant glisser cet interrupteur vers la droite pour éviter tout conflit ou problème potentiel.

      .. image:: ../img/camera_upload.png
         :width: 600

#. Connectez votre carte Arduino à votre ordinateur à l'aide d'un câble USB.

#. Visitez |link_download_arduino| et téléchargez l'IDE Arduino pour votre système d'exploitation. Suivez les instructions d'installation pour terminer la configuration.

   .. image:: img/arduino_download_page.png

#. Téléchargez les codes d'exemple à partir du lien ci-dessous :

   * |download_galaxyrvr_code|

#. Décompressez le fichier téléchargé, accédez à ``galaxy-rvr-1.2.x\lesson_codes``.

   .. image:: img/arduino_open_folder.png

#. Sélectionnez un dossier de code d'exemple, accédez à ce dossier, puis double-cliquez sur le fichier ``.ino`` pour l'ouvrir dans l'IDE Arduino.

   .. image:: img/arduino_open_file.png

#. Dans l'IDE Arduino, sélectionnez **Arduino Uno** comme carte et choisissez le **port** approprié pour votre appareil.

   .. image:: img/arduino_choose_board.png

#. Cliquez sur le bouton **Upload** (flèche pointant vers la droite) pour téléverser le code sur votre carte.

   .. image:: img/arduino_upload.png

.. note::

    Si vous n'êtes pas familier avec l'IDE Arduino, veuillez consulter :

    * :ref:`install_arduino_ide`
    * :ref:`upload_sketch`

Exemples
------------

* ``5_car_move`` : Le rover avance, puis recule, tourne à gauche et à droite, et enfin s'arrête.
* ``6_ir_avoid`` : Le rover évite les obstacles à l'aide de capteurs IR.
* ``7_ultrasonic_avoid`` : Le rover évite les obstacles à l'aide du module à ultrasons.
* ``8_ultrasonic_ir_avoid`` : Le rover utilise à la fois les capteurs IR et le module à ultrasons pour détecter les obstacles.
* ``8_ultrasonic_ir_follow`` : Le rover suit des objets à l'aide des capteurs IR et du module à ultrasons.
* ``9_rgb_car_move`` : Ajoute des indicateurs de couleur pour le mouvement : vert pour avancer, rouge pour reculer et jaune pour tourner à gauche ou à droite.
* ``10_servo_range`` : La nacelle de la caméra tourne de 0° à 180° à l'aide d'une boucle for, et l'angle actuel est affiché dans le moniteur série.
* ``11_camera_view`` : Visualisez le flux vidéo en direct de la caméra du rover dans un navigateur web. La bibliothèque **SunFounder AI Camera** est requise.
* ``13_read_battery`` : Surveille la tension de la batterie via le code.
