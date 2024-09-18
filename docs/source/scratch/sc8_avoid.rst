
.. note::

    Bonjour, et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et surmontez les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions lors des fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !


.. _ir_ultra_avoid:


Leçon 8 Évitement d'obstacles avancé
==================================================

Le module d'évitement d'obstacles, comme son nom l'indique, aide notre Rover à éviter les obstacles. Il détecte les obstacles en émettant un signal infrarouge et en recevant le signal réfléchi par l'objet. S'il y a un obstacle devant le module, le signal infrarouge est réfléchi, et le module le détecte.

Maintenant, l'ajout d'un capteur à ultrasons améliore ce système. Les capteurs à ultrasons mesurent la distance en envoyant une onde sonore à une fréquence spécifique et en écoutant le retour de cette onde après avoir rebondi sur un objet. En enregistrant le temps écoulé entre l'émission et la réception de l'onde sonore, il est possible de calculer la distance entre le capteur et l'objet.

La combinaison de ces deux capteurs nous offre un système d'évitement d'obstacles fiable, efficace et polyvalent !

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

Objectifs d'apprentissage
-----------------------------

* Combiner les modules d'évitement d'obstacles à ultrasons et à infrarouge pour activer la fonction d'évitement d'obstacles de base du modèle de Rover martien.
* Apprendre à programmer le modèle de Rover martien pour détecter et éviter automatiquement les obstacles.


Matériel
-------------

* Smartphone ou tablette
* Application Mammoth Coding
* GalaxyRVR

Construction de systèmes avancés d'évitement d'obstacles
-----------------------------------------------------------

Dans les leçons précédentes, nous avons appris les bases de l'utilisation des capteurs infrarouges pour l'évitement d'obstacles. Nous avons également exploré les principes des modules à ultrasons. Maintenant, nous allons combiner toutes ces parties pour construire un système avancé d'évitement d'obstacles !

Notre Rover martien amélioré naviguera désormais dans son environnement en utilisant à la fois des capteurs à ultrasons et à infrarouge.

1. Nous pouvons utiliser le bloc de code de :ref:`ir_obstacle` comme modèle. Ouvrez-le à partir de vos projets enregistrés.


.. image:: img/7_avoid_open.png

2. Ensuite, enregistrez-le sous forme de copie.

.. image:: img/7_avoid_save_copy.png

3. Renommez le projet et sauvegardez-le.

.. image:: img/7_avoid_save_rename.png

4. Ajoutez la détection de distance en utilisant le capteur à ultrasons. Faites glisser un bloc ``quand la distance < 15 cm``.

.. image:: img/7_avoid_when.png
    :width: 800


5. De la même manière, faites glisser un bloc ``arrêter les autres scripts dans le sprite`` pour s'assurer que le GalaxyRVR ne réponde qu'à un capteur à la fois.

.. image:: img/7_avoid_stop.png

6. Reculez jusqu'à atteindre une distance de sécurité.

.. image:: img/7_avoid_backward.png

7. Tournez pendant une seconde (soit à gauche, soit à droite).

.. image:: img/7_avoid_turn.png

8. Avancez à nouveau.

.. image:: img/7_avoid_go.png

Désormais, les capteurs IR des deux côtés et le capteur à ultrasons à l'avant fonctionneront ensemble pour former un puissant système d'évitement d'obstacles, garantissant que le GalaxyRVR ne heurte aucun obstacle lors de ses missions.

