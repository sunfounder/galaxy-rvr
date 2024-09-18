.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et à des aperçus privilégiés.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et concours** : Participez à des concours et des promotions durant les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Carte Adaptateur Caméra
===========================

.. image:: img/cam_adapter_board.jpg
    :width: 500
    :align: center

* **RST** : Utilisé pour réinitialiser l'ESP32-CAM.
* **SCL** : Broche de données série pour le QMC6310.
* **SDA** : Broche d'horloge série du QMC6310.
* **RXD** : RXD de l'ESP32-CAM, vous devez téléverser du code vers l'ESP32-CAM via ces deux broches série, RXD et TXD.
* **TXD** : TXD de l'ESP32-CAM.
* **5V** : Entrée d'alimentation 5V DC.
* **GND** : Entrée de masse.

La carte adaptateur caméra, comme son nom l'indique, est une carte d'extension pour l'ESP-32 CAM, utilisée pour fixer l'ESP32-CAM au robot et faciliter son câblage.

.. image:: img/cam_adapter_esp32cam.png
    :width: 400
    :align: center

Également, en raison de la sensibilité du puce géomagnétique QMC6310 aux interférences des moteurs, nous l'avons placé sur cette carte adaptateur caméra pour le maintenir aussi éloigné que possible des moteurs.

.. image:: img/cam_adapter_qmc6310.png
    :width: 400
    :align: center

**Caractéristiques**

* Tension de fonctionnement : 5V
* Modèle d'interface : ZH1.5, 7P
* Dimensions : 40mm x 27mm x 15mm
* Protocole de communication : UART et I2C

**Documents**

* PCB

.. image:: img/cam_adap_pcb_bottom.png
    :width: 300

.. image:: img/cam_adap_pcb_top.png
    :width: 300

* Schéma

.. image:: img/cam_adapter_sche.png


**À propos du QMC6310**

Le QMC6310 est un capteur magnétique à trois axes qui intègre des capteurs magnétiques et un ASIC de conditionnement de signal dans une seule puce en silicium. Ce boîtier Land Grid Array (LGA) est destiné à des applications telles que la boussole électronique, la rotation de carte, les jeux et la navigation personnelle sur des appareils mobiles et portables.

Le QMC6310 repose sur une technologie magnétorésistive de haute résolution à la pointe de l'industrie. Associé à l'ASIC 16 bits spécialement conçu, il offre des avantages tels qu'un faible bruit, une haute précision, une faible consommation d'énergie, une annulation de l'offset et des compensations de température. Le QMC6310 permet une précision d'orientation de la boussole de 1° à 2°. Le bus série I²C permet une interface facile.

Le QMC6310 est présenté dans un boîtier LGA de montage en surface à 8 broches de 1.2x1.2x0.53mm³.

* |link_qmc6310_datasheet|
