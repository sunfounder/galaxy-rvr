.. note::

    Bonjour, et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, d'Arduino et d'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Soutien d'experts** : Résolvez les problèmes après-vente et surmontez les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Profitez d'annonces de nouveaux produits en avant-première et d'aperçus privilégiés.
    - **Réductions spéciales** : Bénéficiez de remises exclusives sur nos dernières nouveautés.
    - **Promotions festives et concours** : Participez à des concours et des promotions durant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Leçon 2 : Commencer avec l'APP Mammoth Coding
======================================================

Plongeons dans l'univers de Mammoth Coding et créons ensemble votre premier projet ! 
Pour une expérience optimale, il est recommandé d'utiliser un appareil avec un écran 
plus grand.


Objectifs d'apprentissage
----------------------------------

* Comprendre l'environnement de programmation de l'APP et les opérations de base.
* Apprendre à programmer des événements pour les sprites, utiliser le drapeau vert, répéter, glisser et changer de costumes.
* Créer une animation simple simulant un rover martien.


Matériel
-------------

* Smartphone ou tablette
* APP Mammoth Coding


Installation de l'APP Mammoth Coding
--------------------------------------

Recherchez d'abord Mammoth Coding sur Google Play ou l'Apple Store et téléchargez l'application.

.. image:: img/mammoth_download.jpg
    :align: center


Comprendre l'interface de l'APP Mammoth Coding
------------------------------------------------------------

Mammoth Coding est conçu pour être amusant, éducatif et facile à utiliser. 
Il propose des outils pour créer des histoires interactives, des jeux, de l'art, 
des simulations et bien plus encore à l'aide de la programmation par blocs. 
Il inclut également des éditeurs de dessin et de son intégrés.

Voici à quoi ressemble l'interface :

.. image:: img/2_app_ui_001.png
    :align: center

Pour les appareils à écran plus petit, l'interface est légèrement différente :

.. image:: img/2_app_ui_002.png
    :align: center


**Section supérieure**

La section supérieure de Mammoth Coding inclut plusieurs options essentielles.

.. image:: img/2_app_ui_1.png
    :align: center

* La première option à gauche vous permet de choisir la langue de programmation.
* La deuxième option est le menu de fichiers, où vous pouvez créer, charger et enregistrer des fichiers.
* La troisième option vous permet de renommer votre projet.


**Navigation**

Sous la section supérieure se trouve la barre de navigation, 
qui vous permet de basculer entre les pages Code, Costumes et Sons.

.. image:: img/2_app_ui_3.png
    :align: center

Sur les petits écrans, la barre de navigation apparaît en haut.

.. image:: img/2_app_ui_2.png
    :align: center

Les options sont : Code, Costumes, Sons et Scène. 
Sur les grands écrans, la page Scène se trouve sur le côté droit, 
mais elle est séparée sur les petits appareils pour éviter l'encombrement.

.. image:: img/2_app_ui_4.png
    :align: center


**Code**

.. image:: img/2_app_ui_code.png
    :align: center

La page Code (et Scène) est là où se déroulera la majorité de vos activités de programmation.

**Costumes**

.. image:: img/2_app_ui_custom.png
    :align: center

La page Costumes est utilisée pour modifier les sprites et les décors, 
qui constituent les éléments visuels de vos projets.

**Sons**

.. image:: img/2_app_ui_sound.png
    :align: center

La page Sons permet de gérer les éléments audio de vos projets.

Première utilisation de l'APP Mammoth Coding
------------------------------------------------

Faites glisser un bloc vers la zone centrale.

.. image:: img/2_drag.png
    :align: center

Cliquez sur le bloc et observez le résultat.

.. image:: img/2_click.png
    :align: center

Vous verrez le sprite au centre de la scène bouger légèrement. 
Si vous continuez à cliquer sur le bloc, le sprite continuera à se déplacer.

.. image:: img/2_show.png
    :align: center

Remarquez comment la forme de ces blocs suggère qu'ils peuvent être connectés, 
à la manière des briques LEGO. Lorsque vous connectez les blocs, 
le sprite sur la scène exécutera les actions définies par les blocs de code connectés 
séquentiellement (par exemple, se déplacer puis tourner).

.. image:: img/2_click2.png
    :align: center


.. note:: Voici le processus de programmation de base dans l'APP : faites glisser des blocs depuis la zone de gauche, connectez-les, et cliquez dessus pour exécuter des actions avec le sprite sur la scène.


**Choisir un sprite**

Dans le coin inférieur droit de l'interface, 
vous trouverez le bouton "choisir un sprite". Touchez-le pour voir quatre options s'afficher.

.. image:: img/2_create_sp.png
    :align: center

Sur les petits écrans, vous devrez naviguer pour trouver ce bouton.

.. image:: img/2_create_sp0.png
    :align: center


Les quatre options sont :

* **Télécharger un sprite** : Importer un sprite depuis le stockage de votre appareil.
* **Surprise** : Sélectionner un sprite aléatoire dans la bibliothèque.
* **Peindre** : Créer votre propre sprite en le dessinant.
* **Choisir un sprite** : Accéder à la bibliothèque pour choisir un sprite.

Appuyez sur "choisir un sprite" pour entrer dans la bibliothèque, qui propose une grande variété de ressources pour votre scène.

.. image:: img/2_sp_list.png
    :align: center

Trouvez et sélectionnez "GalaxyRVR".

.. image:: img/2_sprite_rvr.png
    :align: center

**Votre premier exemple**

Créons une animation simple en utilisant l'APP pour faire bouger GalaxyRVR de manière aléatoire.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_app.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>


**1. Commencez avec la catégorie des Événements jaunes.**

Nous avons déjà exécuté du code en cliquant sur des blocs dans la zone centrale, mais la plupart du temps, notre code sera déclenché par des événements. Les événements surveillent des actions comme les clics de sprite ou les pressions de touches, et déclenchent des actions dans le programme.

Faites glisser le bloc "quand drapeau vert cliqué".

.. image:: img/2_first_flag.png

Le drapeau vert représente le point de départ du programme. Ce bloc s'active lorsque vous cliquez sur le drapeau vert à côté de la scène, démarrant l'exécution du code pour tous les sprites.

**2. La catégorie Contrôle orchestre le flux du programme.**

Ces blocs définissent quand et à quelle fréquence les actions doivent se produire.

Faites glisser un bloc "répéter 10 fois" et attachez-le sous le bloc du drapeau vert.

.. image:: img/2_first_repeat.png

Cela signifie qu'après avoir cliqué sur le drapeau vert, une action sera répétée dix fois.

**3. La catégorie Mouvement permet de diriger les sprites sur la scène.**

Faites glisser un bloc "glisser pendant 1 sec vers une position aléatoire" et insérez-le dans le bloc "répéter 10 fois".

.. image:: img/2_first_glide.png

Cela déplacera votre sprite vers une position aléatoire sur la scène.

**4. La catégorie Apparence ajoute une dimension visuelle à vos personnages.**

Faites glisser un bloc "costume suivant" et placez-le à l'intérieur du bloc "répéter 10 fois".

.. image:: img/2_first_custom.png

Cela fera changer de costume à votre sprite à chaque action, créant une impression de mouvement.

Cliquez maintenant sur le drapeau vert à côté de la scène et observez GalaxyRVR se déplacer aléatoirement.

