.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 2 : Premiers pas avec l'application Mammoth Coding
========================================================

Plongeons dans l'univers de Mammoth Coding et créons votre tout premier projet ! Pour une expérience optimale, il est recommandé d'utiliser un appareil doté d'un écran de grande taille.

Objectifs d'apprentissage
-------------------------

* Configurer l'environnement de programmation Mammoth Coding.
* Comprendre les concepts de base de la programmation dans Mammoth Coding.
* Écrire et exécuter votre premier programme.

Installation de l'application
------------------------------

1. Recherchez **Mammoth Coding** sur Google Play ou dans l'Apple App Store, puis installez l'application.

   .. image:: img/1_app_install.png
      :width: 600
      :align: center

2. Une fois l'installation terminée, ouvrez l'application. Voici à quoi ressemble l'interface sur les appareils équipés d'un grand écran :

   .. image:: img/1_app_ui_001.png
      :width: 600
      :align: center

3. Sur les appareils disposant d'un écran plus petit, l'interface se présente de la manière suivante :

   .. image:: img/1_app_ui_002.png
      :width: 600
      :align: center

Comprendre l'application
-----------------------------------

Mammoth Coding a été conçu pour être amusant, éducatif et facile à prendre en main. Il fournit des outils permettant de créer des histoires interactives, des jeux, des œuvres graphiques, des simulations et bien plus encore grâce à la programmation par blocs. L'application inclut également des éditeurs de dessin et de sons intégrés.

Section supérieure
^^^^^^^^^^^^^^^^^^

La section supérieure de Mammoth Coding regroupe plusieurs options essentielles.

.. image:: img/1_app_ui_1.png
   :align: center

* **Paramètres de langue** : La première option à gauche permet de choisir la langue de l'interface. Actuellement, l'anglais et le chinois simplifié sont disponibles.
* **Menu Fichier** : La deuxième option correspond au menu **File**, qui permet de créer un nouveau projet, d'ouvrir un projet existant ou d'enregistrer le projet en cours.
* **Nom du projet** : La troisième option permet de renommer votre projet.

Barre de navigation
^^^^^^^^^^^^^^^^^^^^^

Juste en dessous de la section supérieure se trouve la barre de navigation, qui vous permet de basculer entre les différentes pages d'édition.

.. image:: img/1_app_ui_3.png
   :align: center

Sur les appareils à écran plus petit :

* La barre de navigation apparaît en haut de l'écran avec les onglets **Code**, **Costumes**, **Sounds** et **Stage**.

  .. image:: img/1_app_ui_2.png

* La page **Stage** correspond en réalité à la partie droite de l'interface sur les grands écrans. Sur les appareils plus petits, elle est affichée séparément afin d'éviter de surcharger l'interface.

  .. image:: img/1_app_ui_4.png
     :width: 600

Zone de code
^^^^^^^^^^^^^^

La page **Code** est l'endroit où se déroulera la majeure partie de vos activités de programmation.

.. image:: img/1_app_ui_code.png
   :width: 600
   :align: center

Costumes
^^^^^^^^^^^^^^^

La page **Costumes** permet de modifier les sprites et les arrière-plans, qui constituent les éléments visuels de vos programmes.

.. image:: img/1_app_ui_custom.png
   :width: 600
   :align: center

Sons
^^^^^^^^^^^^^

La page **Sounds** est dédiée à la gestion des éléments audio et permet d'ajouter des effets sonores et d'autres contenus multimédias à vos programmes.

.. image:: img/1_app_ui_sound.png
   :width: 600
   :align: center

Créer votre premier programme
----------------------------------------

1. Créer ou ouvrir un projet
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Chaque fois que vous ouvrez l'application Mammoth Coding, un nouveau projet est créé automatiquement.

  .. image:: img/1_open_new.png
     :width: 600

* Remplacez le nom par défaut « My Project » par un nom plus significatif.

  .. image:: img/1_new_name.png
     :width: 600

* Vous pouvez également ouvrir un projet que vous avez précédemment enregistré sur votre appareil.

  .. image:: img/1_new_save.png
     :width: 600

2. Choisir un sprite
^^^^^^^^^^^^^^^^^^^^^^^^^

* Lorsque vous démarrez un nouveau projet, un sprite par défaut est fourni. Vous pouvez :

  * Utiliser le sprite par défaut.
  * Choisir un nouveau sprite dans la bibliothèque.
  * Dessiner votre propre sprite.
  * Importer un sprite depuis votre appareil.

  .. image:: img/1_choose_sprite.png

* Pour choisir un nouveau sprite : appuyez sur **« Choisir un sprite »** puis sélectionnez **« GalaxyRVR »**.

  .. image:: img/1_choose_galaxyrvr.png

3. Écrire le programme
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Dans la barre latérale gauche, vous trouverez différentes catégories contenant divers blocs de programmation. Vous pouvez faire glisser ces blocs dans la zone de script afin de construire votre programme.

Par exemple, pour faire avancer le sprite **GalaxyRVR** de 10 pas puis lui faire changer de costume lorsque le drapeau vert est cliqué :

1. Dans la catégorie **Événements (Events)**, faites glisser le bloc **« Quand le drapeau vert est cliqué »** dans la zone de script.

     .. image:: img/1_code_flag.png
        :width: 600

2. Dans la catégorie **Mouvement (Motion)**, faites glisser le bloc **« Avancer de (10) pas »** et attachez-le sous le bloc d'événement.

     .. image:: img/1_code_move10.png
        :width: 600

3. Dans la catégorie **Apparence (Looks)**, faites glisser le bloc **« Costume suivant »** et attachez-le sous le bloc de mouvement.

     .. image:: img/1_code_next.png
        :width: 600

4. Exécuter le programme
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Il existe deux façons d'exécuter votre programme :

1. Appuyez simplement sur la pile de blocs que vous avez assemblée dans la zone de script. Un surlignage jaune apparaîtra pour indiquer que le script est en cours d'exécution.

     .. image:: img/1_code_run.png
        :width: 30%

2. Si votre script commence par le bloc **« Quand le drapeau vert est cliqué »**, vous pouvez cliquer sur le drapeau vert situé en haut à gauche de la **Scène (Stage)** pour exécuter le programme. Cette méthode est recommandée pour les projets comportant plusieurs sprites ou un code plus complexe.

     .. image:: img/1_code_green_flag.png
        :width: 70%

5. Enregistrer votre projet
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Après avoir testé votre programme et vérifié que tout fonctionne correctement, il est important de l'enregistrer.

1. Cliquez sur l'icône d'enregistrement située à droite du nom de votre projet.

     .. image:: img/1_code_save.png
        :width: 600

2. Un message **« Projet enregistré »** apparaîtra. Le projet sera sauvegardé dans l'application Mammoth Coding. Vous pourrez accéder à vos projets enregistrés en cliquant sur le bouton de menu situé tout à droite.

     .. image:: img/1_code_save_app.png
        :width: 600

3. Pour partager votre programme ou l'enregistrer sur votre appareil, cliquez sur **File > Save to your equipment**, puis choisissez une application de partage ou un emplacement de stockage sur votre appareil mobile.

     .. image:: img/1_code_save_device.png

**Félicitations !**

Vous avez créé et exécuté avec succès votre premier programme dans Mammoth Coding.

Continuez à expérimenter et à explorer les différentes fonctionnalités afin de découvrir tout le potentiel de l'application et de laisser libre cours à votre créativité !