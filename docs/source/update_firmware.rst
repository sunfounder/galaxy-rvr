.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _update_firmware:

Mise à jour du firmware
==========================

Votre appareil peut ne pas disposer du dernier firmware en raison des améliorations continues du produit.
Nous vous recommandons de mettre à jour le firmware avant votre première utilisation pour garantir un fonctionnement optimal. La mise à jour du firmware garantit :

* **Corrections de bugs** : Résout les problèmes connus et améliore la stabilité.
* **Compatibilité des applications** : Le dernier firmware est nécessaire au bon fonctionnement de l'application RoboPilot et de Mammoth Coding.
* **Nouvelles fonctionnalités** : Les mises à jour du firmware peuvent ajouter de nouvelles capacités et des améliorations.
* **Meilleures performances** : Optimisations pour la connectivité WiFi, le streaming de la caméra et le contrôle des moteurs.

.. note::
   Si vous préférez ne pas mettre à jour le firmware et continuer à utiliser votre configuration actuelle, vous pouvez consulter la `Documentation GalaxyRVR v1 <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_.


.. La vidéo est temporairement désactivée : elle montre l'ancienne procédure de mise à jour et n'est plus à jour. Réactivez-la une fois la nouvelle vidéo enregistrée.
..
.. .. raw:: html
..
..    <iframe width="600" height="400" src="https://www.youtube.com/embed/Tl2W26pIQoU?si=98bbfUPc1g2cEz3A" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

.. _update_r3_firmware:

1. Mise à jour du firmware de l'UNO R3
--------------------------------------

La carte R3 embarque le firmware qui dialogue avec l'application RoboPilot et Mammoth Coding. Réinstallez-le avec le flasheur en ligne : ouvrez |link_galaxy_rvr_flasher| dans **Chrome** ou **Edge** sur un ordinateur — il s'exécute dans votre navigateur, ne nécessite aucun logiciel supplémentaire et affiche chaque étape avec sa propre image.

Le flasheur comporte trois étapes :

#. **Connect** — Allumez le rover, connectez la carte principale à votre ordinateur avec un câble USB A vers B (pas le câble Type-C), puis placez l'interrupteur de mode sur la position **Upload**. Cliquez ensuite sur **Next**.

   .. image:: img/flasher_step1.jpg
      :width: 500

#. **Flash** — Cliquez sur **Connect & Flash**. Dans la fenêtre de port qui s'affiche, sélectionnez le port de votre carte (par exemple ``USB Serial (COMxx)``), puis cliquez sur **Connect** : le flashage démarre. En cas d'échec, cliquez simplement à nouveau sur **Connect & Flash**.

   .. image:: img/flasher_step2.jpg
      :width: 500

#. **Debug** — Lorsque le flashage est terminé, vous verrez ce qui suit dans la fenêtre de journal, ce qui confirme que le firmware a été écrit et indique la version actuelle (**2.0.2**). Ignorez ``Initialzing...`` et tout ce qui suit à ce stade : le rover est encore en mode **Upload** et ne peut donc pas encore communiquer avec l'ESP32 CAM. Cliquez ensuite sur **Next**.

   .. code-block::

      Reading firmwares/galaxy-rvr-2.0.2.hex
      Resetting the board...
      Connecting to the board...
      Firmware written.
      Verified - flash matches the file.

      ---------- serial open at 115200 ----------
      GalaxyRVR version 2.0.2
      Initialzing...
      SET+RESET
      ...SET+RESET
      ...SET+RESET
      ...[FAIL]

#. Suivez maintenant l'invite : allumez l'interrupteur d'alimentation, remettez l'interrupteur de mode dans sa position d'origine et appuyez sur le bouton **Reset** de la carte R3.

   .. image:: img/flasher_step3_run.jpg
      :width: 500

#. La fenêtre de journal affiche alors le firmware actuel de l'ESP32 CAM.

   * Si le firmware de l'ESP32 CAM est **1.5.0 ou supérieur**, le journal affiche le firmware de l'UNO R3, le firmware de l'ESP32 CAM et enfin une adresse web comme ``http://xxx.xxx.xx.xxx:9000/mjpg``.
   * S'il est **inférieur à 1.5.0**, la fenêtre de journal indique que le firmware de l'ESP32 CAM doit être mis à jour — poursuivez avec :ref:`update_esp32_firmware`.

   .. image:: img/flasher_step3.jpg
      :width: 500


.. _update_esp32_firmware:

2. Mise à jour du firmware de l'ESP32 CAM
-----------------------------------------

L'ESP32 CAM diffuse le point d'accès Wi-Fi et capture la vidéo pour le GalaxyRVR.
Si le firmware est obsolète, ces fonctions peuvent ne pas fonctionner correctement. Suivez les étapes ci-dessous pour mettre à jour le firmware.

#. Allumez l'interrupteur d'alimentation du GalaxyRVR. Pour démarrer l'ESP32 CAM, passez le mode sur **Run** et appuyez sur le bouton **Reset** de la carte R3.

   .. image:: img/camera_run.png
        :width: 500
        :align: center

#. Téléchargez le fichier du firmware.

   * |download_galaxyrvr_filmware|

#. Extrayez le fichier ZIP téléchargé. Localisez le fichier de firmware nommé ``ai-camera-firware.ino.x.x.x.bin`` et transférez-le sur votre appareil mobile. Vous pouvez utiliser n'importe quelle application de gestion de fichiers, comme ES File Explorer ou un utilitaire de transfert de fichiers.

   .. image:: img/firmware_bin_file.png
        :align: center

#. Connectez votre appareil mobile au réseau WiFi du GalaxyRVR.

   * Le nom du réseau (SSID) est ``GalaxyRVR`` et le mot de passe est ``12345678``.
   * Si vous voyez un avertissement indiquant "Aucun accès Internet", veuillez choisir l'option **"Rester connecté"**.

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Ouvrez un navigateur web sur votre appareil mobile et accédez à ``http://192.168.4.1`` pour accéder à la page de mise à jour OTA de l'ESP32 CAM.


.. note:: Sur cette page, vous verrez les options de mise à niveau OTA dans l'une des deux interfaces. La Version A (la première) et la Version B (la seconde) apparaîtront selon la version de votre firmware. Sélectionnez simplement les étapes de mise à jour correspondantes en fonction de l'interface que vous voyez.

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center


**Version A**

   6. Sur la page OTA, sélectionnez le fichier du firmware et lancez la mise à jour :

      * Choisissez le fichier ``ai-camera-firmware-vX.X.X-ota.bin`` précédemment téléchargé depuis votre appareil et cliquez sur **Add**.
      * Cliquez sur le bouton **Update** pour lancer la mise à jour du firmware, puis attendez qu'elle se termine.

      .. image:: img/faq_ota_a.png
         :width: 700


   #. Une fois la mise à jour terminée, le nom du point d'accès WiFi du GalaxyRVR deviendra "AI Camera-xxxxxx" et le mot de passe restera "12345678".


**Version B**


   6. Sur la page **OTA**, vérifiez la version actuelle du firmware affichée sur la page web.

      * Si votre numéro de version est **1.5.0 ou supérieur**, aucune mise à jour n'est nécessaire. Vous pouvez ignorer les étapes restantes et passer directement à :ref:`quick_start`.
      * Si la version est **inférieure à 1.5.0**, veuillez poursuivre la mise à jour.

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center

   #. Appuyez sur **Upgrade Firmware**, sélectionnez le fichier du firmware et attendez la fin de la mise à jour :

      * Appuyez sur le bouton **Upgrade Firmware**, puis sélectionnez le fichier ``ai-camera-firware.ino.x.x.x.bin`` précédemment téléchargé sur votre appareil.
      * La mise à jour démarrera immédiatement et prend généralement 1 à 2 minutes. Une fois terminée, sélectionnez **CONFIRM** pour redémarrer le GalaxyRVR.

      .. image:: img/faq_ota_b.png
         :width: 700

   #. Une fois la mise à jour terminée, le nom du point d'accès WiFi du GalaxyRVR deviendra "AI Camera-xxxxxx" et le mot de passe restera "12345678".


3. Vérification du démarrage
-----------------------------

* Avant d'utiliser le GalaxyRVR pour la première fois, chargez complètement la batterie avec le câble USB Type-C fourni.
* Allumez l'interrupteur d'alimentation.
* Passez le mode sur **Run** et appuyez sur le bouton **Reset** de la carte R3.
* La bande lumineuse inférieure clignotera en **vert**, indiquant un démarrage réussi.

.. raw:: html

   <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=_idwN0kJrxbVW-5H" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
