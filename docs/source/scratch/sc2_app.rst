.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et à des aperçus privilégiés.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et concours** : Participez à des concours et des promotions pendant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Leçon 2 : Commencer avec l'APP Mammoth Coding
======================================================

Plongeons dans l'univers de Mammoth Coding et créons votre premier projet ! 
Pour une expérience optimale, il est recommandé d'utiliser un appareil avec 
un écran plus grand.






Objectifs d'apprentissage
----------------------------------

* Comprendre l'environnement de programmation de l'APP et les opérations de base.
* Apprendre à programmer des événements dans les sprites, utiliser le drapeau vert, répéter, glisser et changer de costumes.
* Créer une animation simple simulant un rover martien.


Matériel
-------------
* Smartphone ou tablette
* APP Mammoth Coding


Installation de l'APP Mammoth Coding
--------------------------------------

Tout d'abord, recherchez Mammoth Coding sur Google Play ou l'Apple Store et téléchargez-le.

.. image:: img/mammoth_download.jpg
    :align: center


Comprendre l'interface de l'APP Mammoth Coding
------------------------------------------------------------

Mammoth Coding est conçu pour être amusant, éducatif et facile à apprendre. 
Il propose des outils pour créer des histoires interactives, des jeux, de l'art, 
des simulations et bien plus encore en utilisant la programmation par blocs. 
Il inclut également ses propres éditeurs de dessin et de son.

Voici à quoi ressemble l'interface :

.. image:: img/2_app_ui_001.png
    :align: center

Pour les appareils à écran plus petit, l'interface ressemble à ceci :

.. image:: img/2_app_ui_002.png
    :align: center


**Section supérieure**

La section supérieure de Mammoth Coding inclut plusieurs options de base.

.. image:: img/2_app_ui_1.png
    :align: center

* La première option à gauche est la configuration de la langue, permettant de choisir différentes langues de programmation.
* La deuxième option est le menu de fichiers, où vous pouvez créer de nouveaux fichiers, charger des fichiers locaux et enregistrer le fichier actuel.
* La troisième option est pour renommer votre projet.


**Navigation**


Juste en dessous de la section supérieure se trouve la barre de navigation, 
qui vous permet de passer entre les pages Code, Costumes 
et Sons.

.. image:: img/2_app_ui_3.png
    :align: center

Sur les petits écrans, la barre de navigation apparaît en haut.

.. image:: img/2_app_ui_2.png
    :align: center

Les options sont Code, Costumes, Sons et Scène. 
La page Scène se trouve sur le côté droit de l'interface sur les grands écrans, 
séparée sur les petits appareils pour éviter l'encombrement.

.. image:: img/2_app_ui_4.png
    :align: center


**Code**

.. image:: img/2_app_ui_code.png
    :align: center

La page Code (et Scène) est celle où la plupart de vos activités de programmation auront lieu.

**Costumes**

.. image:: img/2_app_ui_custom.png
    :align: center

La page Costumes est utilisée pour éditer les sprites et les décors, 
fournissant les éléments visuels de vos programmes.

**Sons**

.. image:: img/2_app_ui_sound.png
    :align: center

La page Sons gère l'audio, fournissant les éléments multimédias de vos programmes.

Première utilisation de l'APP Mammoth Coding
------------------------------------------------

Faites glisser un bloc vers la zone centrale.

.. image:: img/2_drag.png
    :align: center

Cliquez sur le bloc et observez ce qui se passe.

.. image:: img/2_click.png
    :align: center

Vous verrez le sprite au centre de la scène bouger légèrement. 
Si vous continuez à cliquer sur le bloc, il continuera à bouger.

.. image:: img/2_show.png
    :align: center

Remarquez comment la forme de ces blocs suggère qu'ils peuvent être connectés, 
similaires aux briques LEGO. Lorsque vous connectez les blocs, 
le sprite sur la scène exécutera les blocs de code connectés 
séquentiellement (par exemple, se déplacer puis tourner).

.. image:: img/2_click2.png
    :align: center


.. note:: Voici le processus de programmation de base dans l'APP. Faites glisser des blocs depuis la zone de gauche, connectez-les ensemble, et cliquez dessus pour faire exécuter des actions au sprite sur la scène.


**Choisir un sprite**

Dans le coin inférieur droit de l'interface, 
vous trouverez le bouton "choisir un sprite". Touchez-le pour voir quatre options s'afficher.

.. image:: img/2_create_sp.png
    :align: center

Sur les petits écrans, vous devez naviguer pour voir ce bouton.

.. image:: img/2_create_sp0.png
    :align: center


Les quatre options sont :

* **Télécharger un sprite** : Charger un sprite depuis le stockage de votre appareil.
* **Surprise** : Sélectionner un sprite aléatoire dans la bibliothèque d'actifs.
* **Peindre** : Dessiner un sprite.
* **Choisir un sprite** : Ouvrir la bibliothèque d'actifs pour choisir un sprite.

Appuyez sur "choisir un sprite" pour entrer dans la bibliothèque d'actifs, qui propose une variété de matériaux pour votre scène.

.. image:: img/2_sp_list.png
    :align: center

Trouvez et sélectionnez "GalaxyRVR".

.. image:: img/2_sprite_rvr.png
    :align: center

**Votre premier exemple**

Créons une animation simple en utilisant l'APP pour faire bouger GalaxyRVR aléatoirement.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_app.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>


**1. Commencez avec la catégorie des Événements jaunes.**

Alors que nous avons précédemment exécuté du code en cliquant sur des blocs dans la zone centrale, la plupart du temps, notre code doit être déclenché par des événements. Les événements agissent comme des gardiens, surveillant des actions telles que les clics de sprite ou les pressions sur les touches, et indiquent au programme quoi faire lorsqu'ils se produisent.

Faites glisser le bloc "quand drapeau vert cliqué".

.. image:: img/2_first_flag.png

Le drapeau vert agit comme un signal de départ, représentant le début du programme. Ce bloc se déclenche lorsque vous cliquez sur le drapeau vert à côté de la scène, démarrant tous les personnages et le code.

**2. La catégorie Contrôle est le chef d'orchestre du programme.**

Ces blocs aident à contrôler le déroulement du programme, décidant quand et à quelle fréquence les actions doivent se produire.

Faites glisser un bloc "répéter 10 fois" et attachez-le sous le bloc du drapeau vert.

.. image:: img/2_first_repeat.png

Cela signifie qu'après avoir cliqué sur le drapeau vert, quelque chose se produira dix fois.

**3. La catégorie Mouvement donne des instructions aux acteurs de la scène (les sprites).**

Faites glisser un bloc "glisser pendant 1 sec vers une position aléatoire" et imbriquez-le dans le bloc "répéter 10 fois".

.. image:: img/2_first_glide.png

Cela fera glisser votre sprite vers une position aléatoire.

**4. La catégorie Apparence ajoute de l'animation et de l'intérêt visuel à vos personnages.**

Faites glisser un bloc "costume suivant" et placez-le à l'intérieur du bloc "répéter 10 fois".

.. image:: img/2_first_custom.png

Cela permet à votre sprite de changer de costume à chaque action, donnant l'impression qu'il marche.

Maintenant, cliquez sur le drapeau vert à côté de la scène et regardez votre GalaxyRVR se déplacer de manière aléatoire.
