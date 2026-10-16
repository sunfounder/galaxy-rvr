.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Jeu Rapide avec l'APP
=========================

Prêt à commencer votre aventure sur Mars ?
Avec la fonction de démarrage rapide de l'application RoboPilot, vous pouvez commencer à explorer dès que votre GalaxyRVR est assemblé.

Avec RoboPilot, vous pouvez :

- Piloter le rover depuis une perspective à la première personne
- Basculer entre trois modes de contrôle : **Remote**, **Avoid** et **Follow**


.. note::

    * Si vous avez écrasé le firmware et devez restaurer la communication, suivez :ref:`update_r3_firmware`.

Guide rapide
---------------------

.. raw:: html


   <iframe width="600" height="400" src="https://www.youtube.com/embed/NwWjgP9ldZw?si=_3PADiRd-UlDvtHc" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Démarrez le GalaxyRVR.

   * Avant d'utiliser le GalaxyRVR pour la première fois, chargez complètement la batterie avec le câble USB Type-C fourni.
   * Mettez l'interrupteur d'alimentation en marche.
   * Passez le mode sur **Run** et appuyez sur le bouton **Reset** de la carte R3.
   * La bande lumineuse inférieure clignotera en **vert**, indiquant un démarrage réussi.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Installez **RoboPilot** depuis l'**APP Store(iOS)** ou **Google Play(Android)**.

#. Connectez votre appareil mobile au réseau WiFi du GalaxyRVR.

   * Le nom du réseau (SSID) est ``GalaxyRVR`` et le mot de passe est ``12345678``.
   * Si vous voyez un avertissement indiquant "Aucun accès Internet", veuillez choisir l'option **"Rester connecté"**.

     .. image:: ../img/camera_lan.png
        :width: 500

#. Ouvrez RoboPilot. Cliquez sur 'Go into' pour entrer dans l'interface de contrôle.

   .. image:: img/rp1_inter.png



Mode Remote
----------------------------------------------

En entrant dans l'interface de contrôle, vous verrez l'écran suivant.
L'arrière-plan montre la vue capturée par la caméra du GalaxyRVR, avec des widgets de contrôle à distance superposés.

.. image:: img/rp2_page.png

Voici les contrôles :

A. Retour
B. Paramètres : Vous pouvez ici changer le nom et le mot de passe de l'AP (hotspot), configurer le WiFi, retourner l'image et vous déconnecter.

   .. image:: img/rp3_setting.jpg

C. Indicateur de niveau de batterie
D. Pause/Exécuter l'APP
E. Sélection du mode : Vous pouvez choisir ici entre le Mode Remote, le Mode Avoid et le Mode Follow. Le paramètre par défaut est le **Mode Remote**.

   .. image:: img/rp4_mode.jpg

F. Moniteur d'obstacles : Ce module est divisé en trois zones, les côtés gauche et droit affichant les résultats des modules d'obstacles, et la zone centrale affichant les résultats du capteur à ultrasons.
G. Sélecteur de couleur : Choisissez ici la couleur d'éclairage du châssis.

   .. image:: img/rp5_color.png

H. Interrupteur LED de la caméra.
I. Réglez l'angle du gimbal, allant de 0 à 130°. À 0°, il regarde vers le ciel.
J. Déplacez le joystick pour contrôler le mouvement du GalaxyRVR. Une poussée douce fera avancer le GalaxyRVR lentement.


Mode Avoid et Mode Follow
----------------------------------------------

* **Mode Avoid** : le GalaxyRVR avancera et évitera les obstacles sur son chemin.
* **Mode Follow** : le GalaxyRVR se déplacera vers un objet devant lui ou tournera à gauche ou à droite pour suivre le mouvement de l'objet.

Lorsque vous sélectionnez le **Mode Avoid** ou le **Mode Follow**, vous verrez l'interface ci-dessous. La vue en direct de la caméra du GalaxyRVR forme l'arrière-plan, avec des options de contrôle superposées.

.. image:: img/rp6_avoid.png

**Contrôles de l'interface :**

A. **Contrôle de vitesse** - Réglez la vitesse de déplacement du GalaxyRVR
B. **Contrôle du moteur** - Démarrez ou arrêtez le mouvement du GalaxyRVR
C. **Contrôle du gimbal** - Réglez l'angle de la caméra de 0° (face au ciel) à 130°
D. **Moniteur d'obstacles** - Retour visuel des capteurs :

   - Sections gauche/droite : Détection d'obstacles infrarouge
   - Section centrale : Mesures de distance à ultrasons

**Réglage de la portée de détection d'obstacles**

Avant d'utiliser ce mode, calibrez la portée de détection des capteurs pour l'adapter à votre environnement. Les paramètres d'usine peuvent ne pas être optimaux.

- Trop courte : Le rover peut heurter des obstacles
- Trop longue : Le rover peut braquer inutilement

Étapes de calibration :

1. **Commencez par le module droit**

   - Assurez-vous que l'émetteur/récepteur sont correctement alignés
   - Redressez-les s'ils ont été pliés pendant le transport

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
        </video>

2. **Testez et réglez la sensibilité**

   - Placez un obstacle à 20 cm (utilisez la boîte du Rover)
   - Tournez le potentiomètre jusqu'à ce que l'indicateur s'allume
   - Vérifiez l'activation constante à la distance souhaitée
   - Utilisez le deuxième potentiomètre si nécessaire

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
        </video>

3. **Répétez pour le module gauche**


Reconnexion
-------------------------------

Si votre réseau échoue ou se déconnecte, vous serez dirigé vers cette page.

.. image:: img/rp7_reconnect.png

À ce stade, veuillez réinitialiser vos paramètres réseau, puis cliquez sur l'IP correspondant à votre GalaxyRVR pour vous reconnecter.
