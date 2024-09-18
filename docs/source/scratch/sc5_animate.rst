

.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez-vous dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions lors des fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !


Leçon 5 Animation interactive
===============================================

Précédemment, nous avons utilisé le module à ultrasons pour permettre à GalaxyRVR d’éviter automatiquement les obstacles sur son chemin.

Dans cette activité, nous allons combiner ce module avec une scène pour créer une animation interactive d’un rover traversant joyeusement la surface de Mars.


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_jump.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>



Objectifs d'apprentissage
----------------------------

* Apprendre à dessiner des sprites et à modifier les arrière-plans.
* Comprendre les concepts de base de la programmation tels que les écouteurs d'événements et les structures de boucles.
* Se familiariser avec l'environnement de programmation de l'application et les opérations de base pour créer une animation simple simulant un rover sur Mars.

Matériel
--------------

* Smartphone ou tablette
* Application Mammoth Coding
* GalaxyRVR


Ajouter de nouveaux sprites
-------------------------------

Supprimez le sprite dont vous n'avez pas besoin.

.. image:: img/6_animate_delete.png
..   :align: left



Dans le coin inférieur droit de l'interface, vous verrez le bouton "choisir un sprite". Appuyez dessus pour faire apparaître quatre options déroulantes.


.. image:: img/2_create_sp.png
..  :align: left

Pour les écrans plus petits, il se peut que vous deviez naviguer vers un autre écran pour voir ce bouton.


.. image:: img/2_create_sp0.png
..  :align: left



Les quatre options sont :

* **Télécharger un sprite** : Charger un sprite depuis le stockage de votre appareil.
* **Surprise** : Sélectionner un sprite au hasard depuis la bibliothèque.
* **Peindre** : Dessiner un sprite.
* **Choisir un sprite** : Ouvrir la bibliothèque pour choisir un sprite.

Ensuite, nous allons utiliser **Choisir un sprite** pour sélectionner un sprite et **Peindre** pour en dessiner un.


**Choisir un sprite**

Cliquez sur "choisir un sprite" (icône de loupe) pour accéder à la bibliothèque, qui propose une multitude de ressources pour votre scène.

.. image:: img/2_sp_list.png
.. :align: left

Trouvez et sélectionnez GalaxyRVR dans la bibliothèque.

.. image:: img/2_sprite_rvr.png
.. :align: left




**Peindre un nouveau sprite**

Nous allons créer un sprite "Mars", mais malheureusement, il n’y a pas de ressource appropriée dans la bibliothèque.

Nous allons donc sélectionner **Peindre** (icône de pinceau) et dessiner nous-mêmes la planète.

.. image:: img/2_create_custom.png
.. :align: left

Tout d’abord, utilisez l’outil cercle pour dessiner un cercle représentant la planète.

.. image:: img/2_create_custom1.png
.. :align: left

Ensuite, utilisez l'outil pointeur pour déplacer le cercle afin qu’il soit aligné au centre de la toile.
Cette étape est cruciale car les coordonnées, la direction et les mouvements de votre sprite sont basés sur son point central.

.. image:: img/2_create_custom2.png
.. :align: left

Utilisez l'outil pot de peinture pour colorier la planète en rouge.

.. image:: img/2_create_custom3.png
.. :align: left

Ensuite, sélectionnez l'outil pinceau, augmentez sa taille, et choisissez une couleur appropriée dans les options de remplissage pour ajouter de la texture à Mars.

.. image:: img/2_create_custom_pen.png
.. :align: left

Si la couleur ne convient pas après la peinture, vous pouvez changer la couleur de remplissage et utiliser à nouveau l’outil pot de peinture pour remplir la forme.

.. image:: img/2_create_custom5.png
.. :align: left

Sélectionnez à nouveau le pinceau, réglez sa taille sur 2 et changez la couleur en noir. Utilisez votre créativité pour ajouter des cratères et des détails sur Mars.

.. image:: img/2_create_custom6.png
.. :align: left

Avec l’outil Pot de Peinture, choisissez une couleur appropriée pour remplir ces cratères.

.. image:: img/2_create_custom7.png
.. :align: left

Une fois terminé, revenez à l'interface Code. Votre sprite Mars est maintenant terminé.

.. image:: img/2_create_custom8.png
.. :align: left

Pour les petits écrans, revenez à l'interface Code en cliquant ici.

.. image:: img/2_create_custom8.1.png
.. :align: left

Vous verrez le sprite Mars sur la scène. N’oubliez pas de le renommer.

.. image:: img/2_create_custom9.png
.. :align: left






**Scène**

Cliquez sur arrière-plans. L’arrière-plan actuel est blanc ; nous devons le rendre plus sombre pour simuler le ciel nocturne.

1. Cliquez sur les arrière-plans de la scène.

.. image:: img/6_jump_backdrop.png
.. :align: left

2. Entrez dans l'interface des arrière-plans.

.. image:: img/6_jump_backdrop_page.png
.. :align: left

3. Dessinez un rectangle.

.. image:: img/6_jump_rect.png
.. :align: left

4. Utilisez l’outil pot de peinture pour le remplir d’une couleur sombre.

.. image:: img/6_jump_fill.png
.. :align: left

5. Utilisez l’outil pinceau pour ajouter quelques étoiles.

.. image:: img/6_jump_paint.png
.. :align: left



Créer l'animation
-------------------------------

Maintenant que nous avons Mars et GalaxyRVR, et que nous savons comment animer des sprites, créons une animation où GalaxyRVR se déplace sur Mars.
Nous pouvons donner l’illusion de mouvement en faisant tourner Mars dans le sens inverse, créant ainsi l’effet que GalaxyRVR traverse sa surface.

Ajustez la taille et la position des sprites, 
réglez les coordonnées du sprite GalaxyRVR à 0,0, et placez-le sur Mars.

Réglez la position et la taille du sprite Mars de manière à ce que le sprite GalaxyRVR soit parfaitement "posé" dessus.

.. image:: img/6_jump_place.png
.. :align: left


**Sprite Mars**

.. image:: img/6_ssp_mars.png
    :align: left

Sélectionnez le sprite Mars. Son rôle est de tourner dans le sens antihoraire, créant ainsi l'illusion que GalaxyRVR avance.


.. raw:: html

   <br></br>

1. Faites glisser un bloc drapeau vert. Toutes les animations commencent par le drapeau vert.

.. image:: img/6_jump_mar_flag.png
.. :align: left

2. Faites glisser un bloc ``toujours`` pour que l'animation fonctionne en continu.

.. image:: img/6_jump_mar_forever.png
.. :align: left

3. Faites glisser un bloc ``tourner`` et un bloc ``attendre`` pour que Mars tourne en continu.

.. image:: img/6_jump_mar_turn.png
.. :align: left


Maintenant, cliquez sur le drapeau vert, et vous verrez Mars tourner dans le sens antihoraire.



**Sprite GalaxyRVR**

.. image:: img/6_ssp_rvr.png
    :align: left


Sélectionnez le sprite GalaxyRVR. Son rôle est de simuler un mouvement, bien qu'il ne bouge pas réellement.

.. raw:: html

   <br></br>

1. Faites glisser un bloc drapeau vert. Toutes les animations commencent par le drapeau vert.

.. image:: img/6_jump_mar_flag.png
.. :align: left


2. Faites glisser un bloc ``toujours`` pour que l'animation fonctionne en continu.

.. image:: img/6_jump_mar_forever.png
.. :align: left

3. Faites glisser un bloc ``costume suivant`` et un bloc ``attendre`` pour que GalaxyRVR anime continuellement.

.. image:: img/6_jump_mar_next.png
.. :align: left

**Ajouter plus de divertissement**

.. image:: img/6_ssp_rvr.png
    :align: left

Nous pouvons ajouter de l'interactivité à cette animation en utilisant le module à ultrasons 
pour faire sauter le sprite GalaxyRVR afin d'éviter les obstacles.

Veuillez continuer à programmer dans le sprite GalaxyRVR.



1. Faites glisser un bloc ``quand distance``. Cela se déclenche lorsque le module à ultrasons détecte un obstacle (par exemple, votre main).

.. image:: img/6_jump_when.png
.. :align: left

2. Faites glisser deux blocs ``glisser`` et modifiez la valeur de y du premier pour faire sauter le sprite puis le faire redescendre, créant ainsi un effet de saut.

.. image:: img/6_jump_glide.png
.. :align: left


3. Le code complet pour le sprite GalaxyRVR devrait ressembler à ceci :

.. image:: img/6_jump_mar_rvr_all.png
.. :align: left


Maintenant, cliquez sur le drapeau vert pour démarrer l'animation. Simulez un obstacle en plaçant votre main devant le module à ultrasons, et le sprite GalaxyRVR sautera pour l'éviter.

