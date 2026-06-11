.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Servo
===========

Un servo est un moteur spécialisé reconnu pour sa précision dans le contrôle de positions angulaires spécifiques.

.. image:: img/servo.png
    :align: center

* **Fil marron** : GND
* **Fil orange** : Broche de signal, à connecter à la broche PWM de la carte principale.
* **Fil rouge** : VCC

Contrairement aux moteurs ordinaires qui tournent en continu, un servo peut se déplacer vers une position précise et la maintenir avec précision. Il y parvient grâce à une combinaison d'engrenages, d'un potentiomètre et de circuits de commande. Les servos sont couramment utilisés dans diverses applications nécessitant un contrôle précis de la position d'objets ou de mécanismes.

**Caractéristiques**

* **Type de moteur** : Moteur à noyau
* **Tension de fonctionnement** : 4,8~6V CC
* **Courant de veille** : ≤4 mA
* **Courant de consommation (à 4,8V sans charge)** : ≦50mA
* **Courant de consommation (à 6V sans charge)** : ≦60mA
* **Courant de blocage (à 4,8V bloqué)** : ≦550mA
* **Courant de blocage (à 6V bloqué)** : ≦650mA
* **Couple nominal** : 4,8V, ≥0,6 kgf·cm; 6V, ≥0,7 kgf·cm
* **Couple max.** : 4,8V, ≥1,4 kgf.cm; 6V, ≥1,6 kgf.cm
* **Vitesse sans charge** : 4,8V, ≦0,14sec/60°; 6V, ≦0,12sec/60°
* **Remarque** : Protection contre la torsion : ≥0,9 kgf.cm ; protection contre la panne après 5 secondes de surcharge continue
* **Plage de température de fonctionnement** : -10℃~+50℃
* **Plage de température de stockage** : -20℃~+60℃
* **Plage d'humidité de fonctionnement** : ≤ 90%HR
* **Plage d'humidité de stockage** : ≤ 90%HR
* **Poids** : 10± 0,5g
* **Matériau** : ABS
* **Angle de fonctionnement** : 180°±10° (500~2500us)
* **Angle limite mécanique** : 360°
* **Angle de déplacement gauche/droite** : ≤ 6°
* **Déviation de centrage** : ≤ 1°
* **Jeu** : ≤ 4 us
* **Type d'amplificateur** : Numérique
* **Matériau du câble** : Ф1,08,19 PVC
* **Longueur du câble** : 245±5mm (sans connecteurs)
* **Type de connecteur** : JR2.54mm/3Pin

**Principe de fonctionnement**

À l'intérieur d'un servo, des composants essentiels contribuent à sa fonctionnalité unique. Au cœur du servo se trouve un moteur conventionnel, étroitement lié à un grand engrenage, qui s'engrène à son tour avec un engrenage plus petit sur l'arbre du moteur. Cette disposition d'engrenages convertit efficacement le mouvement circulaire rapide du moteur en mouvements plus lents mais puissants.

.. image:: img/servo_internal.png

Mais la véritable magie se produit dans le servo, grâce à une minuscule merveille électronique appelée "potentiomètre" et à des "circuits de commande" sophistiqués. Lorsque le servo est en mouvement, le potentiomètre tourne, modifiant sa résistance électrique. Les circuits de commande détectent et interprètent ce changement de résistance avec une précision remarquable, déterminant ainsi la position exacte du servo. C'est un témoignage de son ingéniosité.

Dans le domaine du contrôle des servos, une méthode de signalisation unique appelée "modulation de largeur d'impulsion" ou PWM entre en jeu. En ajustant habilement la largeur de ces impulsions, les opérateurs peuvent commander au servo de se déplacer avec précision et de maintenir sa position. C'est l'essence de la technologie des servomoteurs, un domaine où précision et contrôle convergent pour permettre une multitude d'applications.
