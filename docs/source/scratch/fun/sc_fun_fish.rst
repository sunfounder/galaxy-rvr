.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _sh_fishing:

Projet ludique 5 : La pêche
===========================

Plongez dans notre jeu de pêche interactif, utilisant le module anti-obstacle gauche pour une expérience captivante.

Lorsque le script est actif, les poissons nagent d'avant en arrière sur la scène. Pour attraper un poisson, vous devez bloquer le module anti-obstacle gauche juste au moment où le poisson s'apprête à passer devant l'hameçon. Le jeu enregistre automatiquement le nombre de poissons que vous attrapez.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_fishing.mp4"  type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>

Suivez ces étapes pour mettre en place le projet, et n'hésitez pas à personnaliser les effets une fois que vous êtes familiarisé avec la configuration.

1. Ajouter l'arrière-plan et les sprites
----------------------------------------

D'abord, sélectionnez un arrière-plan **Underwater**, puis ajoutez un sprite **Fish** et faites-le nager sur la scène.

* Utilisez le bouton **Choisir un arrière-plan** pour sélectionner un arrière-plan **Underwater**.

  .. image:: img/fish_choose_backdrop.png

* Supprimez le sprite d'origine, puis sélectionnez le sprite **Fish**.

  .. image:: img/fish_choose_fish.png

* Ajustez la taille et la position du sprite **Fish**.

  .. image:: img/fish_set_fish.png

2. Dessiner un sprite **Fishhook**
----------------------------------

Ensuite, créez un sprite **Fishhook** que vous contrôlerez via le module anti-obstacle gauche pour commencer à pêcher.

* Ajoutez le sprite **Glow-J** via **Choisir un sprite** et renommez-le « Fishhook ».

  .. image:: img/fish_choose_j.png

* Allez dans l'onglet **Costumes** du sprite **Glow-J**, renommez-le **Fishhook**, sélectionnez le « J » blanc intérieur et changez sa couleur en rouge.

  .. image:: img/fish_set_j1.png
    :width: 90%

* Supprimez le remplissage cyan extérieur et réduisez sa largeur. Assurez-vous que le haut de l'hameçon est aligné avec le point central.

  .. image:: img/fish_set_j2.png

* Utilisez l'**outil Ligne** pour tracer une ligne vers le haut depuis le point central, dépassant de la scène.

  .. image:: img/fish_set_j3.png

3. Programmer le sprite **Fish**
--------------------------------

Le sprite **Fish** doit se déplacer de gauche à droite sur la scène, et lorsqu'il interagit avec le sprite **Fishhook** en état de pêche, il doit rétrécir, se déplacer vers une position spécifique, puis disparaître, suivi de l'apparition d'un nouveau sprite **Fish**.

* Créez une variable **score** pour stocker le nombre de poissons attrapés, masquez ce sprite et clonez-le.

  .. image:: img/fish_script_fish1.png

* Affichez le clone du sprite **Fish**, changez son costume et définissez la position initiale.

  .. image:: img/fish_script_fish2.png

* Faites en sorte que le clone du sprite **Fish** se déplace de gauche à droite et rebondisse en touchant le bord de la scène.

  .. image:: img/fish_script_fish3.png

* Si le clone du sprite **Fish** touche le sprite **Fishhook** en état de pêche (lorsqu'il devient rouge).

  .. image:: img/fish_script_fish4.png
    :width: 90%

* Augmentez le score (variable score) de 1, affichez une animation de score (rétrécit de 40 %, se déplace rapidement vers la position du tableau des scores et disparaît). Simultanément, créez un nouveau poisson (un nouveau clone du sprite **Fish**) et continuez le jeu.

  .. image:: img/fish_script_fish5.png

4. Programmer le sprite **Fishhook**
------------------------------------

Le sprite **Fishhook** reste généralement sous l'eau dans un état jaune. Lorsque votre main bloque le module infrarouge gauche, il passe à l'état de pêche (rouge) et se déplace au-dessus de la scène.

* Lorsque le drapeau vert est cliqué, définissez l'effet de couleur du sprite à 30 (jaune) et définissez sa position initiale.

  .. image:: img/fish_script_hook1.png

* Lorsque votre main bloque le module infrarouge gauche, définissez l'effet de couleur à 0 (rouge, déclenchant l'état de pêche), attendez 0,1 seconde, puis déplacez le sprite **Fishhook** en haut de la scène.

  .. image:: img/fish_script_hook2.png

* Après avoir retiré votre main, laissez le **Fishhook** revenir à sa position initiale.

  .. image:: img/fish_script_hook3.png

Une fois la programmation terminée, cliquez sur le drapeau vert pour exécuter le script et voir s'il produit l'effet souhaité.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_fishing.mp4"  type="video/mp4">
      Votre navigateur ne prend pas en charge la balise vidéo.
   </video>


