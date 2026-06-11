.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 5 : Animation interactive
===============================

Dans la leçon précédente, nous avons utilisé le module ultrasonique pour que le GalaxyRVR évite automatiquement les obstacles sur son chemin.

Dans cette activité, nous allons combiner le module avec une scène pour créer une animation interactive d'un rover parcourant joyeusement la surface de Mars.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_jump.mp4" type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>

Objectifs d'apprentissage
-------------------------

* Apprendre à dessiner des sprites et à modifier les arrière-plans
* Comprendre les concepts de base de la programmation tels que les écouteurs d'événements et les structures de boucle
* Se familiariser avec l'environnement de programmation de l'application et les opérations de base pour créer une animation simple simulant un Rover Martien

Ajouter de nouveaux sprites
----------------------------

#. Commencez par :ref:`app_connect`.

#. Supprimez les sprites dont vous n'avez pas besoin.

   .. image:: img/6_animate_delete.png

#. Dans le coin inférieur droit de l'interface, appuyez sur le bouton **Choisir un sprite** pour afficher quatre options.

   .. image:: img/5_create_sp.png

#. Sur les écrans plus petits, vous devrez peut-être passer à un autre écran pour voir ce bouton.

   .. image:: img/5_create_sp0.png

Les quatre options sont :

* **Importer un sprite** – Chargez un sprite depuis votre appareil.
* **Surprise** – Sélectionnez aléatoirement un sprite dans la bibliothèque.
* **Dessiner** – Dessinez votre propre sprite.
* **Choisir un sprite** – Sélectionnez dans la bibliothèque de sprites.

Ensuite, nous utiliserons **Choisir un sprite** pour sélectionner un sprite et **Dessiner** pour en créer un.

**Choisir un sprite**

#. Appuyez sur **Choisir un sprite** (icône en forme de loupe) pour ouvrir la bibliothèque de sprites.

   .. image:: img/5_sp_list.png

#. Trouvez et sélectionnez **GalaxyRVR** dans la bibliothèque.

   .. image:: img/1_choose_galaxyrvr.png


**Dessiner un nouveau sprite**

#. Appuyez sur **Dessiner** (icône en forme de pinceau) pour créer un nouveau sprite. Nous allons dessiner un sprite **Mars**.

   .. image:: img/5_create_custom.png

#. Utilisez l'**outil Cercle** pour dessiner un cercle représentant la planète.

   .. image:: img/5_create_custom1.png

#. Utilisez l'**outil Pointeur** pour déplacer le cercle au centre du canevas. Cette étape est importante car les coordonnées et les mouvements du sprite sont basés sur son centre.

   .. image:: img/5_create_custom2.png

#. Utilisez l'**outil Pot de peinture** pour remplir le cercle en rouge.

   .. image:: img/5_create_custom3.png

#. Sélectionnez l'**outil Pinceau**, augmentez la taille du pinceau et ajoutez de la texture avec une couleur de remplissage appropriée.

   .. image:: img/5_create_custom_pen.png

#. Si la couleur ne convient pas, changez la couleur de remplissage et utilisez à nouveau l'**outil Pot de peinture**.

   .. image:: img/5_create_custom5.png

#. Sélectionnez à nouveau l'**outil Pinceau**, réglez la taille sur 2, changez la couleur en noir et dessinez des cratères sur Mars.

   .. image:: img/5_create_custom6.png

#. Utilisez l'**outil Pot de peinture** pour remplir les cratères avec une couleur appropriée.

   .. image:: img/5_create_custom7.png

#. Une fois terminé, revenez à l'**interface de code**.

   .. image:: img/5_create_custom8.png

#. Sur les écrans plus petits, cliquez sur l'icône pour revenir à l'interface de code.

   .. image:: img/5_create_custom8.1.png

#. Vous verrez maintenant le sprite Mars sur la scène. N'oubliez pas de le **renommer**.

   .. image:: img/5_create_custom9.png


**Scène**

#. Cliquez sur **Arrière-plans** pour modifier l'arrière-plan. L'arrière-plan blanc par défaut sera modifié pour simuler un ciel nocturne.

   .. image:: img/6_jump_backdrop.png

#. Accédez à l'interface **Arrière-plans**.

   .. image:: img/6_jump_backdrop_page.png

#. Dessinez un rectangle sur le canevas.

   .. image:: img/6_jump_rect.png

#. Utilisez l'**outil Pot de peinture** pour le remplir d'une couleur sombre.

   .. image:: img/6_jump_fill.png

#. Utilisez l'**outil Pinceau** pour ajouter quelques étoiles.

   .. image:: img/6_jump_paint.png


Créer l'animation
-----------------

Maintenant que nous avons Mars et GalaxyRVR, et que nous savons animer des sprites, créons une animation de GalaxyRVR se déplaçant sur Mars.
Nous pouvons donner l'illusion du mouvement en faisant tourner Mars dans la direction opposée, créant ainsi l'effet que GalaxyRVR se déplace à sa surface.

#. Commencez par :ref:`app_connect`.

#. Ajustez la taille et la position des deux sprites.

   * Définissez le sprite GalaxyRVR à **(0, 0)** et positionnez Mars de sorte que GalaxyRVR semble se tenir à sa surface.

   .. image:: img/6_jump_place.png


**Sprite Mars**

#. Sélectionnez le sprite Mars. Sa tâche est de tourner dans le sens inverse des aiguilles d'une montre, créant l'illusion que GalaxyRVR avance.

   .. image:: img/6_ssp_mars.png

#. Glissez un bloc drapeau vert. Toute animation commence par le drapeau vert.

   .. image:: img/6_jump_mar_flag.png

#. Glissez un bloc ``répéter indéfiniment`` pour que l'animation tourne en continu.

   .. image:: img/6_jump_mar_forever.png

#. Glissez un bloc ``tourner`` et un bloc ``attendre`` pour faire tourner Mars en continu.

   .. image:: img/6_jump_mar_turn.png

#. Cliquez maintenant sur le drapeau vert : vous verrez Mars tourner dans le sens inverse des aiguilles d'une montre.



**Sprite GalaxyRVR**

#. Sélectionnez le sprite GalaxyRVR. Sa tâche est de s'animer comme s'il se déplaçait, même s'il ne bouge pas réellement.

   .. image:: img/6_ssp_rvr.png

#. Glissez un bloc drapeau vert. Toute animation commence par le drapeau vert.

   .. image:: img/6_jump_mar_flag.png

#. Glissez un bloc ``répéter indéfiniment`` pour que l'animation tourne en continu.

   .. image:: img/6_jump_mar_forever.png

#. Glissez un bloc ``costume suivant`` et un bloc ``attendre`` pour animer GalaxyRVR en continu.

   .. image:: img/6_jump_mar_next.png

#. Glissez un bloc ``when distance``. Il se déclenchera lorsque le module ultrasonique détectera un obstacle (par exemple, votre main).

   .. image:: img/6_jump_when.png

#. Glissez deux blocs ``glisser`` et modifiez la valeur y du premier pour faire sauter le sprite vers le haut puis redescendre, créant un effet de saut.

   .. image:: img/6_jump_glide.png

#. Le code complet du sprite GalaxyRVR devrait ressembler à ceci :

   .. image:: img/6_jump_mar_rvr_all.png


Maintenant, cliquez sur le drapeau vert pour lancer l'animation. Simulez un obstacle en plaçant votre main devant le module ultrasonique : le sprite GalaxyRVR sautera pour l'éviter.
