.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Leçon 4 : Maîtriser le moteur TT
=================================

Dans les leçons précédentes, nous avons exploré les rovers martiens et leurs systèmes de suspension. Dans ce cours passionnant, nous allons explorer le fonctionnement des moteurs, un composant clé qui entraîne les rovers martiens.

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/left_1.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::

    Si vous suivez ce cours après avoir entièrement assemblé le GalaxyRVR, vous devez déplacer cet interrupteur vers la droite avant de téléverser le code.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Objectifs du cours
----------------------
* Comprendre les principes de base des moteurs et les caractéristiques du moteur TT.
* Apprendre à contrôler la direction et la vitesse du moteur TT.
* Comprendre comment le GalaxyRVR Shield contrôle six moteurs.

Matériel du cours
-----------------------
* Carte SunFounder R3
* Moteur TT
* GalaxyRVR Shield
* Batterie
* Câble USB
* Arduino IDE
* Ordinateur

Étapes du cours
------------------

**Étape 1 : Qu'est-ce qu'un moteur ?**

Les moteurs font partie intégrante de notre vie quotidienne. Des ventilateurs électriques aux mixeurs en passant par les voitures électriques, les moteurs font bouger les choses !

.. image:: img/motor_application.jpg

Un moteur convertit l'énergie électrique en énergie mécanique. Le principe derrière un moteur est l'induction électromagnétique : lorsque l'électricité alimente un moteur, elle génère un champ magnétique qui interagit avec d'autres aimants à l'intérieur du moteur, le faisant tourner.

.. image:: img/motor_rotate.gif
    :align: center

Le type de moteur utilisé dans notre GalaxyRVR est un moteur TT à engrenages. Il combine un moteur standard avec une série d'engrenages dans une coque en plastique, ce qui augmente le couple pour déplacer des charges plus lourdes.

.. image:: img/tt_motor_xh.jpg
    :align: center
    :width: 400

**Étape 2 : Explorer le fonctionnement du moteur**

Si vous connectez un moteur directement à une batterie, il tourne. Inversez les connexions et il tourne dans la direction opposée ! Mais les broches de signal d'Arduino ne produisent qu'environ 20mA, ce qui est insuffisant pour entraîner un moteur. C'est là qu'intervient un driver de moteur - il prend le signal de commande à faible courant d'Arduino, l'amplifie et l'envoie au moteur.

.. image:: img/motor_uno2.png

**Étape 3 : Comment le moteur est contrôlé par le driver**

Le GalaxyRVR Shield sert de centre de contrôle. Il comporte six ports moteur répartis en deux groupes : trois ports "Left" contrôlés par une puce (broches 2 et 3), et trois ports "Right" contrôlés par une autre (broches 4 et 5).

.. image:: img/motor_shield.png

**1. Connexion du circuit** : Insérez le Shield dans la carte R3, connectez un moteur et branchez la batterie.

**2. Écriture du code :**

.. code-block:: arduino

    void setup() {
        pinMode(2, OUTPUT);
        pinMode(3, OUTPUT);
    }
    void loop() {
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
    }

**3. Logique de pilotage** : La table de vérité du driver :

.. list-table::
   :widths: 25 25 50
   :header-rows: 1

   * - INA
     - INB
     - Moteur
   * - L
     - L
     - Veille
   * - L
     - H
     - Horaire
   * - H
     - L
     - Antihoraire
   * - H
     - H
     - Frein

**Étape 4 : Contrôle de la vitesse du moteur**

La PWM (Modulation de Largeur d'Impulsion) permet de simuler une tension variable en commutant rapidement entre HIGH et LOW. Comme les broches 2-5 n'ont pas de PWM matérielle, nous utilisons la bibliothèque SoftPWM.

#. Installez ``softpwm`` depuis le **LIBRARY MANAGER**.

.. code-block:: arduino

    #include <SoftPWM.h>
    const int in1 = 2;
    const int in2 = 3;
    void setup() { SoftPWMBegin(); }
    void loop() {
        SoftPWMSet(in1, 0);
        SoftPWMSet(in2, 255);
    }

La vitesse est une valeur entre 0 (arrêt) et 255 (pleine vitesse). Vous pouvez utiliser une boucle ``for`` pour augmenter progressivement la vitesse :

.. code-block:: arduino

    for (int i = 0; i <= 255; i++) {
        SoftPWMSet(in2, i);
        delay(100);
    }

**Étape 5 : Réfléchir et s'améliorer**

Vous savez maintenant contrôler la direction et la vitesse des moteurs. Mettez-vous au défi : comment modifier la boucle for pour diminuer progressivement la vitesse ? Comment contrôler le moteur en accélération/décélération en sens antihoraire ?
