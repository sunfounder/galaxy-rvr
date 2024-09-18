.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et à des aperçus privilégiés.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et concours** : Participez à des concours et des promotions durant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Servo
===========

Un servo est un moteur spécialisé, réputé pour sa précision dans le contrôle des positions angulaires spécifiques.

.. image:: img/servo.png
    :align: center

* **Fil marron** : GND
* **Fil orange** : Broche de signal, à connecter à la broche PWM de la carte principale.
* **Fil rouge** : VCC

Contrairement aux moteurs classiques qui tournent en continu, un servo peut se déplacer vers une position précise et la maintenir avec exactitude. Il y parvient grâce à une combinaison d'engrenages, d'un potentiomètre et de circuits de commande. Les servos sont couramment utilisés dans de nombreuses applications nécessitant un contrôle précis des positions d'objets ou de mécanismes.

**Caractéristiques**

* **Type de moteur** : Moteur à noyau
* **Tension de fonctionnement** : 4.8~6V DC
* **Courant de veille** : ≤4 mA
* **Courant de consommation (à 4.8V sans charge)** : ≦50mA
* **Courant de consommation (à 6V sans charge)** : ≦60mA
* **Courant de blocage (à 4.8V bloqué)** : ≦550mA
* **Courant de blocage (à 6V bloqué)** : ≦650mA
* **Couple nominal** : 4.8V, ≥0.6 kgf·cm; 6V, ≥0.7 kgf·cm
* **Couple max.** : 4.8V, ≥1.4 kgf.cm; 6V, ≥1.6 kgf.cm
* **Vitesse sans charge** : 4.8V, ≦0.14sec/60°; 6V, ≦0.12sec/60°
* **Remarque** : Protection contre la torsion : ≥0.9 kgf.cm; protection contre la panne après 5 secondes de surcharge continue.
* **Plage de température de fonctionnement** : -10℃~+50℃
* **Plage de température de stockage** : -20℃~+60℃
* **Plage d'humidité de fonctionnement** : ≤ 90%RH
* **Plage d'humidité de stockage** : ≤ 90%RH
* **Poids** : 10± 0.5g
* **Matériau** : ABS
* **Angle de fonctionnement** : 180°±10° (500~2500us)
* **Angle limite mécanique** : 360°
* **Angle de déplacement gauche/droite** : ≤ 6°
* **Déviation de centrage** : ≤ 1°
* **Jeu** : ≤ 4 us
* **Type d'amplificateur** : Numérique
* **Matériau du câble** : Ф1.08,19 PVC
* **Longueur du câble** : 245±5mm (sans connecteurs)
* **Type de connecteur** : JR2.54mm/3Pin

**Principe de fonctionnement**

À l'intérieur d'un servo, plusieurs composants essentiels contribuent à son fonctionnement unique. Au cœur du servo se trouve un moteur classique, étroitement lié à un grand engrenage, qui s'engrène avec un plus petit sur l'arbre du moteur. Cet ensemble d'engrenages convertit efficacement le mouvement circulaire rapide du moteur en mouvements plus lents mais puissants.

.. image:: img/servo_internal.png

Cependant, l'ingéniosité d'un servo réside dans ses composants électroniques, comme un petit dispositif appelé "potentiomètre" et des circuits de contrôle sophistiqués. Lorsque le servo se déplace, le potentiomètre tourne, modifiant ainsi sa résistance électrique. Les circuits de commande détectent et interprètent ce changement de résistance avec une grande précision, déterminant ainsi la position exacte du servo.


Dans le domaine du contrôle des servos, une méthode de signalisation unique appelée "modulation de largeur d'impulsion" (PWM) est utilisée. En ajustant habilement la largeur de ces impulsions, les opérateurs peuvent commander le servo pour qu'il se déplace avec précision et qu'il maintienne sa position. C'est là tout l'intérêt de la technologie des servomoteurs, où précision et contrôle se rejoignent pour permettre de nombreuses applications.

