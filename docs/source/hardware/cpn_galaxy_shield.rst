.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

GalaxyRVR Shield
=========================

.. image:: img/galaxy_shield.jpg
    :width: 500
    :align: center

Il s'agit d'une carte d'extension tout-en-un conçue par SunFounder pour Arduino, qui contient divers ports pour des modules
tels que moteur, bande RGB, évitement d'obstacles, niveaux de gris, ESP32 CAM et module à ultrasons.

Cette carte d'extension dispose également d'un circuit de charge intégré, qui peut charger la batterie avec une interface PH2.0-3P,
et le temps de charge estimé est de 130 minutes.


**Brochage**

.. image:: img/galaxyrvr_shield_pinout.png

* Port de charge
    * Après connexion au port USB-C 5V/2A, il peut être utilisé pour charger la batterie pendant 130 minutes.

* **Port batterie** :
    * Entrée d'alimentation PH2.0-3P 6,6V~8,4V.
    * Alimente simultanément le GalaxyRVR Shield et la carte Arduino.

* Bouton Reset
    * Appuyez sur ce bouton pour réinitialiser le programme sur la carte Arduino.

* Indicateurs
    * **Indicateur de charge** : S'allume en rouge lorsque le shield est en charge via le port USB-C.
    * **Indicateur d'alimentation** : S'allume en vert lorsque l'interrupteur d'alimentation est en position "ON".
    * **Indicateur de batterie** : Deux indicateurs orange représentent différents niveaux de batterie. Ils clignotent pendant la charge et s'éteignent lorsque la batterie doit être rechargée.

* Interrupteur d'alimentation
    * Glissez sur ON pour allumer le GalaxyRVR.

* Servo de caméra
    * Le servo de la caméra est connecté ici.
    * Le fil marron se connecte à "-", le fil rouge à "+" et le fil jaune à la broche 6.

* :ref:`shield_motor_pin`
    * **Port moteur (Droite)** : 3 moteurs peuvent être connectés, mais tous sont contrôlés par le même ensemble de signaux sur les **broches 2 et 3**.
    * **Port moteur (Gauche)** : 3 moteurs peuvent être connectés, mais tous sont contrôlés par le même ensemble de signaux sur les **broches 4 et 5**.
    * Type de port : XH2.54, 2P.

* :ref:`shield_strip_pin`
    * Pour connecter 2 bandes LED RGB, les trois broches de la bande sont respectivement connectées aux broches **12, 13 et 11**.
    * Type de port : ZH1.5, 4P.

* :ref:`shield_avoid_pin`
    * Utilisé pour connecter deux modules d'évitement d'obstacles IR.
    * Le **module d'évitement gauche** est connecté à la **broche 8**, le **module d'évitement droit** est connecté à la **broche 7**.
    * Type de port : ZH1.5, 3P.

* :ref:`shield_camera_pin`
    * Le port de la carte adaptateur caméra.
    * Type de port : ZH1.5, 5P.

* :ref:`shield_ultrasonic_pin`
    * Pour connecter le module à ultrasons, les broches Trig et Echo sont connectées à la **broche 10** de la carte Arduino.
    * Type de port : ZH1.5, 4P.

* Interrupteur de mode
    * L'ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission).
    * Ainsi, lors du téléversement de code, vous devrez basculer cet interrupteur vers la **droite** pour déconnecter l'ESP32-CAM afin d'éviter tout conflit.
    * Lorsque vous devez utiliser la caméra, basculez cet interrupteur vers la **gauche** pour que l'ESP32-CAM puisse communiquer avec la carte Arduino.

* SOLAR
    * C'est le port pour le panneau solaire, qui peut charger la batterie lorsqu'il est connecté au panneau solaire.
    * Type de port : XH2.54, 2P.


.. _shield_ultrasonic_pin:

SONAR
--------------------

Voici le brochage du port à ultrasons ZH1.5-4P, avec les broches Trig et Echo connectées à la broche 10 de la carte Arduino.

.. image:: img/ultrasonic_shield.png

.. _shield_camera_pin:

CAMÉRA
----------------------

Le schéma des broches de l'interface adaptateur caméra est présenté ici, le type est ZH1.5-7P.

* TX et RX sont utilisés pour l'ESP32 CAM.

.. image:: img/camera_shield.png


.. _shield_avoid_pin:

IR GAUCHE/DROITE
----------------------------

Voici les broches pour les modules d'évitement d'obstacles gauche et droit.

.. image:: img/ir_shield.png


.. _shield_strip_pin:

Bande RGB
-------------------------

Ci-dessous se trouve le schéma de brochage des deux bandes LED RGB, elles sont connectées en parallèle et leurs brochages sont identiques.

.. image:: img/rgb_shield.png



.. _shield_motor_pin:

Port moteur
---------------

Voici le brochage des deux ensembles de ports moteur.


.. image:: img/motor_shield.png
    :width: 600
    :align: center

