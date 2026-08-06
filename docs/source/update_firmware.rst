
.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _update_firmware:

Mise à jour du firmware
==========================

Votre appareil peut ne pas avoir le dernier firmware en raison des améliorations continues du produit.
Nous vous recommandons de mettre à jour le firmware avant votre première utilisation pour garantir un fonctionnement optimal. La mise à jour du firmware assure :

* **Corrections de bugs** : Résout les problèmes connus et améliore la stabilité.
* **Compatibilité des applications** : Le dernier firmware est nécessaire au bon fonctionnement de l'application RoboPilot et de Mammoth Coding.
* **Nouvelles fonctionnalités** : Les mises à jour du firmware peuvent ajouter de nouvelles capacités et améliorations.
* **Meilleures performances** : Optimisations pour la connectivité WiFi, le streaming de la caméra et le contrôle des moteurs.

.. note::
   Si vous préférez ne pas mettre à jour le firmware et continuer à utiliser votre configuration actuelle, vous pouvez consulter la `Documentation GalaxyRVR v1 <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_.


.. raw:: html

   <iframe width="600" height="400" src="https://www.youtube.com/embed/Tl2W26pIQoU?si=98bbfUPc1g2cEz3A" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


1. Vérifier si une mise à jour est nécessaire
--------------------------------------------------

#. Allumez le GalaxyRVR et vérifiez la bande lumineuse inférieure.

   * Avant d'utiliser le GalaxyRVR pour la première fois, chargez complètement la batterie avec le câble USB Type-C fourni.
   * Mettez l'interrupteur d'alimentation en marche.
   * Passez le mode sur **Run** et appuyez sur le bouton **Reset** de la carte R3.
   * La bande lumineuse inférieure commencera à clignoter pour indiquer un démarrage réussi.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

#. Vérifiez la bande lumineuse inférieure.

   * Si la bande lumineuse inférieure affiche un **clignotement vert**, votre firmware ESP32 est déjà à jour. Vous pouvez passer à :ref:`quick_start`.
   * Si la bande lumineuse inférieure clignote d'une **autre couleur**, vous devrez :

     - :ref:`update_esp32_firmware`
     - :ref:`update_r3_firmware`


.. _update_esp32_firmware:

2. Mise à jour du firmware ESP32 CAM
--------------------------------------

L'ESP32 CAM diffuse le hotspot Wi-Fi et capture la vidéo pour le GalaxyRVR.
Si le firmware est obsolète, ces fonctions peuvent ne pas fonctionner correctement. Suivez les étapes ci-dessous pour mettre à jour le firmware.

#. Allumez l'interrupteur d'alimentation du GalaxyRVR. Pour démarrer l'ESP32 CAM, passez le mode sur **Run** et appuyez sur le bouton **Reset** de la carte R3.

   .. image:: img/camera_run.png
        :width: 500
        :align: center

#. Téléchargez le fichier du firmware.

   * |download_galaxyrvr_filmware|

#. Extrayez le fichier ZIP téléchargé. Localisez le fichier firmware nommé ``ai-camera-firware.ino.x.x.x.bin`` et transférez-le sur votre appareil mobile. Vous pouvez utiliser n'importe quelle application de gestion de fichiers, comme ES File Explorer ou un utilitaire de transfert de fichiers.

   .. image:: img/firmware_bin_file.png
        :align: center

#. Connectez votre appareil mobile au réseau WiFi du GalaxyRVR.

   * Le nom du réseau (SSID) est ``GalaxyRVR`` et le mot de passe est ``12345678``.
   * Si vous voyez un avertissement indiquant "Aucun accès Internet", veuillez choisir l'option **"Rester connecté"**.

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Ouvrez un navigateur web sur votre appareil mobile et accédez à ``http://192.168.4.1`` pour accéder à la page de mise à jour OTA de l'ESP32 CAM.


.. note:: Sur cette page, vous verrez les options de mise à jour OTA dans l'une des deux interfaces. La Version A (la première) et la Version B (la seconde) apparaîtront selon la version de votre firmware. Sélectionnez simplement les étapes de mise à jour correspondantes en fonction de l'interface que vous voyez.

   .. image:: img/firmware_access_ab.png
      :width: 90%
      :align: center


**Version A**

   6. Sur la page OTA, sélectionnez le fichier du firmware et lancez la mise à jour :

      * Choisissez le fichier ``ai-camera-firmware-vX.X.X-ota.bin`` précédemment téléchargé depuis votre appareil et cliquez sur **Add**.
      * Cliquez sur le bouton **Update** pour lancer la mise à jour du firmware, puis attendez qu'elle se termine.

      .. image:: img/faq_ota_a.png
         :width: 700

   #. Une fois la mise à jour terminée, le nom du hotspot WiFi du GalaxyRVR passera à "AI Camera-xxxxxx" et le mot de passe restera "12345678".


**Version B**


   6. Sur la page **OTA**, vérifiez la version actuelle du firmware affichée sur la page web.

      * Si votre numéro de version est **supérieur à 1.5.1**, une mise à jour n'est pas nécessaire. Vous pouvez ignorer les étapes restantes et passer directement à :ref:`quick_start`.
      * Si la version est **1.5.1 ou inférieure**, veuillez continuer la mise à jour.

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center


   #. Appuyez sur **Upgrade Firmware**, sélectionnez le fichier du firmware et attendez la fin de la mise à jour :

      * Appuyez sur le bouton **Upgrade Firmware**, puis sélectionnez le fichier ``ai-camera-firware.ino.x.x.x.bin`` précédemment téléchargé sur votre appareil.
      * La mise à jour commencera immédiatement et prend généralement 1 à 2 minutes. Une fois terminée, sélectionnez **CONFIRM** pour redémarrer le GalaxyRVR.

      .. image:: img/faq_ota_b.png
         :width: 700

   #. Une fois la mise à jour terminée, le nom du hotspot WiFi du GalaxyRVR passera à "AI Camera-xxxxxx" et le mot de passe restera "12345678".


.. _update_r3_firmware:

3. Mise à jour du firmware de la carte R3
--------------------------------------------

La carte R3 comprend un firmware intégré qui permet la communication avec l'application RoboPilot et Mammoth Coding.

Vous devez re-téléverser ce firmware si :

- Votre appareil utilise une ancienne version du firmware, ou
- Vous avez flashé votre propre code Arduino et souhaitez restaurer la compatibilité.

Suivez les étapes ci-dessous pour réinstaller le firmware de communication.

.. note::

   Si vous utilisez un Mac, veuillez consulter le guide spécifique à macOS :

   :ref:`uno_firmware_mac`

#. Connectez l'Arduino à votre ordinateur avec un câble USB A vers B (pas USB Type-C) et placez l'interrupteur de mode sur **Upload**.

   .. image:: img/camera_upload.png
        :width: 500
        :align: center

#. Vérifiez si les fichiers du firmware ont été téléchargés.

   * |download_galaxyrvr_filmware|

#. Exécutez le script de mise à jour

   * Ouvrez le dossier ``galaxy-rvr.ino.xxx`` (téléchargé et installé à l'étape précédente).
   * Double-cliquez sur le script ``update-arduino-firmware.bat``.
   * Une fenêtre d'invite de commandes apparaîtra automatiquement.

   .. image:: img/faq_bat_file.png

#. Sélectionnez le port série et téléversez

   * Dans l'invite de commandes, une liste des ports série disponibles sera affichée.
   * Entrez le numéro de séquence affiché à gauche pour sélectionner le port série de l'Arduino Uno.
   * Appuyez sur **Entrée** pour lancer le téléversement automatique.
   * Exemple : Si la liste affiche `1 USB-SERIALXXX (COMxx)`, entrez **1** et appuyez sur **Entrée**.

   .. image:: img/faq_select_com.png

#. Après avoir attendu la fin du téléversement, vous pouvez débrancher le câble USB.

   .. image:: img/faq_uno_updating.png

   .. important::

      Ce firmware permet au GalaxyRVR de répondre aux commandes de l'application. Vous n'aurez pas besoin de téléverser du code supplémentaire lorsque vous utilisez l'application de contrôle à distance RoboPilot ou le logiciel Mammoth Coding.

#. Vous pouvez maintenant passer à :ref:`quick_start` pour commencer votre aventure GalaxyRVR !