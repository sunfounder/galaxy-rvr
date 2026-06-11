.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Leçon 3 : Entrer dans le monde d'Arduino et de la programmation
===============================================================

Dans la leçon précédente, nous avons construit avec succès le système de suspension Rocker-Bogie. Cependant, pour le rendre fonctionnel, nous devons lui fournir une alimentation, une carte de contrôle et une programmation pour dicter ses mouvements.

Dans cette leçon, nous allons nous familiariser avec la carte de contrôle et la plateforme de programmation que nous utiliserons.

.. image:: img/upload_blink.gif

Objectifs du cours
---------------------
* Comprendre les concepts de base et les fonctions d'Arduino.
* Découvrir la carte SunFounder R3.
* Installer l'IDE Arduino et se familiariser avec son interface.
* Apprendre les règles de syntaxe de base pour la programmation Arduino.

Matériel du cours
--------------------
* Carte SunFounder R3
* Arduino IDE
* Câble USB
* Ordinateur


Introduction à Arduino
------------------------------------------

Arduino est une plateforme électronique open-source facile à utiliser pour les applications matérielles et logicielles. Elle est conçue pour créer des dispositifs numériques et des objets interactifs qui peuvent percevoir et contrôler le monde physique qui les entoure.

* **Open-source** : Comme un jardin communautaire, tout le monde peut l'utiliser, y contribuer et en bénéficier. Les conceptions matérielles et les instructions logicielles sont partagées librement.

    .. image:: img/arduino_oscomm.png
        :width: 400
        :align: center

* **Microcontrôleur** : C'est comme le cerveau d'Arduino. Un petit ordinateur qui peut exécuter des logiciels simples, parfait pour des tâches simples comme comprendre les messages des capteurs ou allumer une LED.

    .. image:: img/arduino_micro.jpg
        :width: 500
        :align: center

* **Carte de développement** : Le corps qui soutient le cerveau. Elle contient des oscillateurs, des régulateurs de tension et des connecteurs pour l'alimentation et les données.

    .. image:: img/arduino_board.png
        :width: 600
        :align: center

* **Arduino IDE** : La salle de classe pour votre Arduino. Un programme sur votre ordinateur où vous écrivez des instructions en langage C++ et les envoyez à la carte Arduino via USB.

    .. image:: img/arduino_ide_icon.png
        :width: 200
        :align: center


Découvrir votre carte SunFounder R3
------------------------------------------------------------------

La carte SunFounder R3 est une carte de développement de type Arduino. Comprenons ses caractéristiques clés :

.. image:: img/sf_r3.jpg
    :width: 800

* **14 broches numériques** : Programmables pour envoyer (sortie) ou recevoir (entrée) des signaux "on" ou "off". Six d'entre elles peuvent utiliser le PWM pour contrôler la luminosité ou la vitesse.
* **6 broches analogiques** : Peuvent lire des signaux de différents types de capteurs.
* **Connexion USB** : Pour connecter la carte à l'ordinateur et téléverser des programmes.
* **Prise d'alimentation** : Pour alimenter la carte avec une batterie ou un adaptateur AC-DC.
* **Connecteur ICSP** : Pour la programmation avec un programmateur externe.
* **Bouton Reset** : Pour redémarrer le programme depuis le début.

.. _install_arduino_ide:

Installer l'IDE Arduino
-----------------------------------------------

L'IDE Arduino version 2.0 nécessite Windows 10+ 64 bits, Linux 64 bits ou Mac OS X 10.14+.

#. Visitez |link_download_arduino| et téléchargez l'IDE pour votre système d'exploitation.

    .. image:: img/sp_001.png

**Pour Windows :** Double-cliquez sur le fichier ``arduino-ide_xxxx.exe``, acceptez la licence, laissez les options par défaut et cliquez sur "Install".

    .. image:: img/sp_002.png

**Pour macOS :** Double-cliquez sur le fichier ``.dmg`` et faites glisser l'application dans le dossier Applications.

    .. image:: img/macos_install_ide.png
        :width: 800

**Pour Linux :** Consultez le tutoriel détaillé ici : |link_arduino_linux|.

Découvrir l'IDE Arduino
----------------------------------------------------------------

.. image:: img/ide-2-overview.png
    :width: 800

* **Verify / Upload** : Téléverse le code sur votre carte Arduino.
* **Select Board & Port** : Affiche les cartes connectées et leurs ports.
* **Sketchbook** : Bibliothèque personnelle où sont stockés vos programmes.
* **Boards Manager** : Pour trouver et installer des packages de cartes.
* **Library Manager** : Des milliers de bibliothèques disponibles.
* **Debugger** : Pour tester et déboguer le code en temps réel.
* **Search** : Pour rechercher des mots-clés dans le code.
* **Open Serial Monitor** : Pour la communication entre l'ordinateur et l'Arduino.

.. _upload_sketch:

Téléverser votre premier sketch
-----------------------------------------------

Nous allons faire clignoter une LED - le "Hello, World!" d'Arduino.

#. Connectez votre carte SunFounder R3 à l'ordinateur avec un câble USB.
#. Dans l'IDE Arduino, allez à **File** -> **Examples** -> **Basic** -> **Blink**.
#. Ce code allume la LED intégrée (broche 13) pendant une seconde, puis l'éteint pendant une seconde.
#. Cliquez sur le bouton **Upload**. Si tout va bien, la LED commencera à clignoter !

.. image:: img/upload_blink.gif


Quelques faits amusants sur la programmation Arduino
--------------------------------------------------------

* **``setup()`` et ``loop()``** : Un sketch Arduino a deux fonctions. ``setup()`` s'exécute une fois au démarrage. ``loop()`` s'exécute en boucle continue.

* **Ponctuation** : Les ``points-virgules (;)`` terminent les instructions. Les ``accolades {}`` délimitent les blocs de code.

* **Fonctions principales** : ``pinMode()`` définit une broche comme INPUT ou OUTPUT. ``digitalWrite()`` active (HIGH) ou désactive (LOW) une broche. ``delay()`` fait une pause en millisecondes.

* **Commentaires** : Utilisez ``//`` ou ``/* */`` pour laisser des notes dans le code. Arduino les ignore complètement.

* **Lisibilité** : Utilisez une indentation correcte, des noms de variables explicites et des commentaires pour rendre votre code compréhensible.

**Réfléchir et s'améliorer**

Prenez un moment pour réfléchir à cette aventure Arduino. Qu'avez-vous trouvé le plus intéressant ? Quels défis avez-vous rencontrés ? Que voulez-vous apprendre ensuite ?
