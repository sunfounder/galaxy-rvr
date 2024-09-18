
.. note::

    Bonjour, et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et surmontez les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions lors des fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !



Leçon 9 Partenaire d'exploration martienne
====================================================

Maintenant que notre Rover est capable d'éviter les obstacles, améliorons-le davantage en lui permettant de suivre des objets. Notre objectif est de modifier le code existant pour que le Rover se dirige vers un objet en mouvement.

Vous vous êtes déjà demandé quelles sont les différences entre un système de suivi et un système d'évitement d'obstacles ?

La clé est que dans un système de suivi, nous voulons que notre Rover se déplace en réponse aux objets détectés, tandis que dans un système d'évitement d'obstacles, l'objectif est d'éviter ces objets.


Objectifs d'apprentissage
----------------------------

* Combiner les modules d'évitement d'obstacles à ultrasons et à infrarouge pour implémenter la fonction de suivi dans le modèle de Rover martien.
* Apprendre à programmer le modèle de Rover martien pour qu'il suive automatiquement une cible.


Matériel
-------------

* Smartphone ou tablette
* Application Mammoth Coding
* GalaxyRVR


Programmation du système de suivi intelligent
-------------------------------------------------------

1. Utilisez le bloc de code de :ref:`ir_ultra_avoid` comme modèle et ouvrez-le à partir du projet sauvegardé.

.. image:: img/8_follow_open.png

2. Ensuite, enregistrez-le sous forme de copie.

.. image:: img/8_follow_save_copy.png

3. Renommez le projet et sauvegardez-le.

.. image:: img/8_follow_save_rename.png

4. Tout d'abord, supprimez le bloc "avancer" à la fin de chaque bloc de code, car le rover doit s'arrêter après chaque événement capteur.

.. image:: img/8_follow_save_remove_forward.png

5. Ensuite, modifiez les directions de rotation des deux événements IR, car le GalaxyRVR doit suivre la direction de la cible.

.. image:: img/8_follow_save_re_turn.png

6. Enfin, modifiez les événements du capteur à ultrasons. Au lieu de reculer pour atteindre une distance de sécurité et tourner, il doit désormais avancer jusqu'à ce que la cible sorte de sa portée.

.. image:: img/8_follow_save_re_ultra.png

Désormais, le GalaxyRVR suivra vos pas. Lorsque vous êtes à côté de lui, il se tournera vers vous. Si vous êtes devant lui, il se dirigera vers vous. S'il ne peut pas vous détecter, il restera immobile.

