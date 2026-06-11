.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Bande 4 LED RGB
====================

.. image:: img/4_rgb_strip.jpg


* **+5V** : Anode commune des trois LED, doit être connectée à 5V CC
* **B** : Cathode de la LED bleue
* **R** : Cathode de la LED rouge
* **G** : Cathode de la LED verte

Cette bande LED RGB comporte quatre LED R5050 RGB, capables de créer n'importe quelle nuance de couleur en combinant les trois couleurs primaires : rouge, bleu et vert.

Les LED R5050 RGB sont conçues avec une configuration à anode commune. Chaque LED de la bande fonctionne comme un circuit indépendant, vous permettant de couper la bande aux points désignés sans affecter les autres sections. La flexibilité et l'adaptabilité de la bande sont renforcées par sa construction sur une carte FPC, doublée d'un adhésif double face pour une installation facile.


**Qu'est-ce qu'une LED R5050 RGB ?**

La LED R5050 RGB est un type de LED qui combine des diodes électroluminescentes rouges, bleues et vertes dans un seul boîtier. Chaque LED de ce boîtier possède sa propre broche, permettant un contrôle individuel. Cette configuration permet de produire une large gamme de couleurs en faisant varier l'intensité de chaque LED.

.. image:: img/rgb_5050.jpg
    :width: 400

.. image:: img/rgb_5050_sche.png
    :width: 200

Dans une application typique, plusieurs LED R5050 RGB sont disposées sur un circuit flexible dans une configuration intelligente. Cela se fait en connectant les extrémités "positives" (anodes) de toutes les LED ensemble, tandis que les extrémités "négatives" (cathodes) sont connectées à leurs voies de couleur respectives. Cela signifie que toutes les cathodes vertes sont connectées ensemble, toutes les cathodes rouges sont connectées ensemble et toutes les cathodes bleues sont connectées ensemble. Cette disposition permet un contrôle efficace du mélange des couleurs et de l'intensité lumineuse, rendant ces LED populaires dans les applications où un éclairage coloré personnalisable est souhaité, comme dans l'éclairage décoratif, la signalétique et les technologies d'affichage.

.. image:: img/rgb_strip_sche.png



**Caractéristiques**

* Tension de fonctionnement : 5V CC
* Couleur : RGB pleine couleur
* Température de fonctionnement : -15-50
* Type RGB : 5050RGB
* Courant : 150mA (circuit unique)
* Puissance : 1,5W
* Épaisseur de la bande lumineuse : 2mm
* Largeur de la bande lumineuse : 5,5mm
* Câble : ZH1.5-4P, 25cm, 28AWG, Noir
