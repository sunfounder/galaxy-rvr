.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et à des aperçus privilégiés.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et concours** : Participez à des concours et des promotions durant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Module d'évitement d'obstacles infrarouge
============================================

Il s'agit d'un module d'évitement d'obstacles infrarouge capable de détecter la présence d'objets à proximité. Il est couramment utilisé dans les robots, les systèmes automatisés et d'autres dispositifs intelligents. Sa plage de détection est de 2 cm à 40 cm, et les objets de couleurs différentes ont des niveaux de réflectivité variés. Ainsi, plus l'objet est foncé, plus la distance de détection est courte.

.. image:: img/ir_avoid.png
    :width: 400
    :align: center

Voici les définitions des broches :

* **GND** : Masse
* **+** : Alimentation, 3,3 ~ 5V DC.
* **Out** : Par défaut, le signal reste haut et ne passe au niveau bas qu'en présence d'un obstacle.
* **EN** : Cette broche **enable** détermine quand le module doit fonctionner. Par défaut, elle est connectée à GND, ce qui signifie que le module est toujours activé.

**Comment ça fonctionne ?**

Ce module contient une paire de composants émetteurs et récepteurs infrarouges. En principe, l'émetteur émet de la lumière infrarouge, qui est réfléchie lorsqu'elle rencontre un obstacle, puis captée par le récepteur. Lorsqu'une détection est faite, l'indicateur s'allume. Après traitement du signal, une sortie à bas niveau est générée.

.. image:: img/ir_receive.png
    :width: 600
    :align: center

La broche **EN** active le module lorsqu'elle est en état bas, le cavalier fixant la broche **EN** à la masse. Pour contrôler la broche EN de manière programmatique, retirez le cavalier.

.. image:: img/ir_cap.png
    :width: 400
    :align: center

Le module est équipé de deux potentiomètres : l'un pour ajuster la puissance de transmission et l'autre pour ajuster la fréquence de transmission. En ajustant ces deux potentiomètres, vous pouvez modifier la distance de détection effective.

.. image:: img/ir_avoid_pot.png
    :width: 400
    :align: center 


**Ajuster la distance de détection**

La plage de détection du module d'évitement d'obstacles doit être calibrée avec précision pour des performances optimales, car les réglages d'usine par défaut peuvent ne pas correspondre aux besoins spécifiques.

La calibration implique les étapes suivantes :

#. Alignement du module : Commencez par le module d'évitement d'obstacles de droite. Le transport peut parfois déplacer l'alignement de l'émetteur et du récepteur infrarouges du module. Ils doivent être réalignés manuellement pour garantir une détection précise.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Placez un obstacle à environ 20 cm directement devant le module droit. La boîte dans laquelle notre kit Rover est livré est un bon choix pour cela ! Tournez ensuite le potentiomètre sur le module jusqu'à ce que le voyant du module s'allume. Ensuite, déplacez l'obstacle d'avant en arrière pour vérifier si le voyant s'allume à la distance souhaitée. Si la lumière ne s'allume pas à la bonne distance ou si elle reste allumée sans s'éteindre, vous devrez ajuster l'autre potentiomètre.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Répétez le même processus pour l'autre module.

**Caractéristiques**

* tension de fonctionnement : 3,3 V à 5 V
* sortie : numérique (marche/arrêt)
* seuil de détection : ajustable par 2 potentiomètres
* plage de détection : 2 à 40 cm
* ajustement R5 : réglage de la fréquence à 38 kHz (déjà optimisé)
* ajustement R6 : réglage du cycle de fonctionnement de la LED IR (déjà optimisé)
* température de fonctionnement : -10 °C à +50 °C
* angle effectif : 35°
* interface d'E/S : interface à 4 fils (- / + / S / EN)
* dimensions : 45 x 16 x 10 mm
* poids : 9 g 

