.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez-vous plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprenez & Partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Soyez parmi les premiers à découvrir les nouvelles annonces de produits et à bénéficier d'avant-premières exclusives.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos nouveaux produits.
    - **Promotions festives et concours** : Participez à des concours et à des promotions durant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Leçon 2 : Comprendre et Construire le Système Rocker-Bogie
==============================================================

Lors de notre précédente leçon, nous avons étudié les rovers martiens et leur 
structure de base. Un aspect intéressant que nous remarquons en observant l'évolution 
des rovers martiens est la constance de leur système de suspension. Malgré les avancées 
technologiques, tous les rovers, de Sojourner à Perseverance, ont été conçus en utilisant 
un type de suspension similaire appelé le système Rocker-Bogie.

Mais pourquoi conserver le système Rocker-Bogie, vous demandez-vous peut-être ? Quels avantages ce design particulier offre-t-il pour l'exploration de Mars ?

.. image:: img/rocker_bogie_pic.webp

Dans cette leçon, nous allons approfondir la science et l'ingénierie derrière le système Rocker-Bogie, puis en construire un.

Partons ensemble pour cette aventure passionnante d'ingénierie !


Objectifs d'apprentissage
-----------------------------

* Comprendre le principe de conception du système de suspension Rocker-Bogie et ses avantages.
* Apprendre à concevoir et à fabriquer un modèle de base du système de suspension Rocker-Bogie.
* Appliquer des principes de physique de base pour expliquer comment le système Rocker-Bogie surmonte les terrains complexes.

Matériel
-------------

* Plans et documents de référence (tels que les dessins de conception du rover martien de la NASA et des vidéos sur le fonctionnement du système de suspension Rocker-Bogie)
* Kit de structure de Rover martien
* Outils et accessoires de base (tournevis, vis, etc.)

Étapes
--------------

**Étape 1 : Découverte du Système Rocker-Bogie**

Le système Rocker-Bogie est comme une chèvre de montagne mécanique – conçu pour maintenir toutes les roues du rover au sol pendant qu'il navigue sur des terrains accidentés et rocailleux. Il est spécialement conçu pour gérer les paysages imprévisibles de Mars, y compris les pentes abruptes et les gros rochers. Ce système n'utilise pas de ressorts, mais repose plutôt sur la géométrie de ses six roues et leur interaction pour conquérir les terrains difficiles. C'est un brillant exemple de conception mécanique ingénieuse surmontant les obstacles environnementaux.

Plongeons dans les deux parties principales de ce système : le "rocker" et le "bogie".

.. image:: img/rocker_bogie.png

* La partie "rocker" du système est comme les deux grands bras de chaque côté du corps du rover. Ces bras, ou bascules, sont reliés entre eux et au châssis du rover par un mécanisme appelé différentiel. Comme deux jambes qui marchent, les bascules tournent dans des directions opposées par rapport au châssis, ce qui permet à la plupart des roues de rester en contact avec le sol. Le corps du rover maintient l'angle moyen des deux bascules. Une extrémité d'une bascule est reliée à une roue, tandis que l'autre extrémité est reliée au bogie.

* La partie "bogie" du système est comme une petite créature articulée attachée à la bascule. C'est un plus petit système de liaison qui pivote au milieu de la bascule et possède une roue à chaque extrémité.

Avec cette compréhension de base, passons à la prochaine étape de notre aventure.


**Étape 2 : Observer le Système en Action**

Voici un GIF qui met en évidence les caractéristiques uniques du système de suspension Rocker-Bogie et illustre comment il permet aux rovers martiens de naviguer sur le terrain difficile de Mars.

.. image:: img/rocker_bogie.gif
    :align: center

Après avoir visionné le gif, discutons ensemble ! Réfléchissez aux questions suivantes :

* Pourquoi pensez-vous que le système de suspension Rocker-Bogie est adapté à l'exploration de Mars ?
* Pouvez-vous décrire comment fonctionne le système Rocker-Bogie avec vos propres mots ?
* Quelles sont les caractéristiques clés du système Rocker-Bogie qui aident les rovers à franchir les terrains accidentés ?

N'hésitez pas à partager vos idées et vos observations sur le système de suspension Rocker-Bogie.

**Étape 3 : Construisons-le**

Maintenant que nous avons étudié le système Rocker-Bogie, il est temps de construire le nôtre.

Matériel nécessaire :

* Kit GalaxyRVR
* Outils de base comme un tournevis et une clé
* Suivez les étapes fournies dans les instructions de montage du Kit GalaxyRVR pour construire le système de suspension du Rover.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/a1xtgDUEvR0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Veuillez noter que la patience et la précision sont essentielles ici, assurez-vous de bien placer chaque pièce et de la fixer correctement.

En attendant, discutez avec vos camarades du design et de la fonction de chaque composant que vous assemblez.
Cela vous aidera non seulement à comprendre la conception, mais aussi à appliquer ses principes pratiques à l'exploration martienne.

Rappelez-vous, ne vous inquiétez pas si vous rencontrez des problèmes lors de l'assemblage ou des tests.
Tout cela fait partie du processus d'ingénierie ! Résoudre les problèmes est la façon dont nous apprenons et innovons.

**Étape 4 : Résumé et Réflexion**

Pendant l'assemblage du système de suspension, avez-vous remarqué que toutes les pièces mobiles utilisent des écrous autobloquants ? Vous êtes-vous déjà demandé pourquoi ?

.. image:: img/self_locking_nuts.webp
    :align: center

Les écrous autobloquants sont un type de fixation qui inclut un anneau en caoutchouc à l'intérieur d'un écrou classique. Ce design garantit que les pièces assemblées ne se desserrent pas facilement à cause des vibrations lors du mouvement.

En outre, il permet également aux pièces de pivoter dans une certaine plage.

Donc, lors de l'assemblage, vous devez d'abord serrer la vis et l'écrou autobloquant avec une douille et un tournevis, puis les desserrer légèrement. Cela garantit qu'il y a suffisamment de jeu pour permettre une rotation libre entre les pièces sans qu'elles ne soient trop lâches.

.. raw:: html

   <video width="600" loop autoplay muted>
        <source src="_static/video/rocker_bogie_system.mp4" type="video/mp4">
        Your browser does not support the video tag.
   </video>

Dans cette leçon, nous avons non seulement appris le système Rocker-Bogie, mais nous en avons également construit un nous-mêmes. De plus, nous pouvons simuler manuellement comment il permet au Rover Martien de se déplacer sans encombre sur divers terrains accidentés.

Grâce à ces connaissances et cette expérience, nous sommes maintenant mieux préparés à explorer les mystères de la planète rouge. Continuons à percer les secrets de Mars ensemble !
