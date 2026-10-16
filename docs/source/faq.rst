.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

FAQ
==============

1. Pourquoi mettre à jour le firmware ?
----------------------------------------------------------------------------------------

SunFounder améliore continuellement le firmware du GalaxyRVR pour offrir une meilleure expérience. Nous vous recommandons de mettre à jour le firmware avant votre première utilisation pour garantir un fonctionnement optimal. La mise à jour du firmware garantit :

* **Corrections de bugs** : Résout les problèmes connus et améliore la stabilité.
* **Compatibilité des applications** : Le dernier firmware est nécessaire au bon fonctionnement de l'application RoboPilot et de Mammoth Coding.
* **Nouvelles fonctionnalités** : Les mises à jour du firmware peuvent ajouter de nouvelles capacités et des améliorations.
* **Meilleures performances** : Optimisations pour la connectivité WiFi, le streaming de la caméra et le contrôle des moteurs.

Pour obtenir des instructions de mise à jour étape par étape, consultez :ref:`update_firmware`.

.. note::
   Si vous préférez ne pas mettre à jour le firmware et continuer à utiliser votre configuration actuelle, vous pouvez consulter la `Documentation GalaxyRVR v1 <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_.

.. _serial_monitor:

2. Comment vérifier la sortie série dans un navigateur ?
--------------------------------------------------------

Si vous voulez voir ce que la carte R3 ou l'ESP32 CAM affiche — par exemple pour confirmer que les deux cartes communiquent, ou pour vérifier l'adresse IP de la caméra — vous pouvez utiliser |link_galaxy_rvr_flasher|. Il fonctionne dans le navigateur, vous n'avez donc pas besoin d'installer l'Arduino IDE :


#. Ouvrez |link_galaxy_rvr_flasher| dans **Chrome** ou **Edge** sur un ordinateur.

#. Cliquez deux fois sur **Next** pour atteindre la troisième étape, **Debug**, puis suivez la vidéo : allumez l'interrupteur d'alimentation, passez le mode sur **Run** et appuyez sur le bouton **Reset** de la carte R3.

   .. image:: img/faq_serial_monitor.png
      :width: 500

#. Cliquez sur **Connect**. Dans la fenêtre de port qui s'affiche, sélectionnez le port de votre carte (par exemple ``USB Serial (COMxx)``), puis cliquez sur **Connect**.

   * S'il est **inférieur à 1.5.0**, la fenêtre de journal indique que le firmware de l'ESP32 CAM doit être mis à jour — poursuivez avec :ref:`update_esp32_firmware`.

   .. image:: img/flasher_step3.jpg
      :width: 500



3. Impossible de se connecter au GalaxyRVR ?
-------------------------------------------------------------------------------------------------

Si vous ne parvenez pas à vous connecter au GalaxyRVR, veuillez vérifier les points suivants :

1. **Vérifiez la batterie** : Observez les indicateurs de batterie sur le rover. Si les deux LED sont éteintes, la batterie est faible. Rechargez le rover à l'aide d'un câble USB Type-C.
2. **Vérifiez l'ESP32 CAM** : Assurez-vous que l'ESP32 CAM est correctement inséré dans son emplacement. Si la LED de l'ESP32 CAM n'est pas allumée, le module caméra ne reçoit peut-être pas d'alimentation ou pourrait être endommagé. L'ESP32 CAM crée le point d'accès WiFi — s'il ne fonctionne pas, aucun réseau n'apparaîtra.
3. **Vérifiez l'interrupteur de mode** : Assurez-vous que l'interrupteur de mode est réglé sur **Run** (pas **Upload**). Le point d'accès WiFi fonctionne uniquement en mode Run.

   .. image:: img/camera_run.png
        :width: 500
        :align: center

4. **Réinitialisez la carte R3** : Après être passé en mode Run, appuyez sur le bouton **Reset** de la carte R3. La bande lumineuse inférieure doit clignoter pour indiquer un démarrage réussi.
5. **Vérifiez le mot de passe WiFi** : Le nom du point d'accès (SSID) par défaut est ``GalaxyRVR`` et le mot de passe est ``12345678``. Assurez-vous d'avoir saisi le mot de passe correctement.
6. **Interférences WiFi** : D'autres appareils sur le même canal WiFi peuvent causer des problèmes de connexion. Si vous soupçonnez des interférences, essayez de :ref:`changer le canal WiFi <change_wifi_channel>`.
7. **Après une mise à jour du firmware** : Si vous venez de mettre à jour le firmware de l'ESP32 CAM et que le WiFi a cessé de fonctionner, consultez :ref:`faq_wifi_after_update`.
8. **Vérifiez la connexion de votre appareil mobile** : Si vous utilisez le GalaxyRVR en mode AP (par défaut), connectez votre appareil mobile au point d'accès GalaxyRVR. Si vous avez :ref:`configuré un réseau WiFi domestique <ap_to_sta>`, assurez-vous que votre appareil mobile est connecté au **même** réseau WiFi domestique.



4. L'application RoboPilot ne parvient pas à se connecter ?
---------------------------------------------------------------------------------------

Si l'application RoboPilot ne trouve pas ou ne parvient pas à se connecter à votre GalaxyRVR, vérifiez les points suivants :

1. **Le firmware de la carte R3 est-il à jour ?** La carte R3 doit disposer du firmware de communication d'usine. Si vous avez téléversé du code Arduino personnalisé, cela écrase ce firmware et interrompt la communication avec RoboPilot. Réinstallez le dernier firmware officiel avec le flasheur en ligne, comme décrit dans :ref:`update_r3_firmware`.
2. **Le firmware de l'ESP32 CAM est-il à jour ?** Un firmware ESP32 CAM obsolète peut aussi causer des problèmes de connexion. Suivez :ref:`update_esp32_firmware` pour le vérifier et le mettre à jour.
3. **L'interrupteur de mode est-il sur Run ?** L'interrupteur de mode doit être réglé sur **Run** (pas Upload) pour que le point d'accès WiFi fonctionne.
4. **Votre appareil mobile est-il connecté au bon réseau WiFi ?** Connectez-vous au point d'accès GalaxyRVR (``GalaxyRVR`` / ``12345678``), ou, si vous avez configuré un WiFi domestique, connectez-vous à ce même réseau.
5. **Essayez de réinitialiser** : Passez en mode **Run** et appuyez sur le bouton **Reset**, puis essayez de vous reconnecter.

Si rien de ce qui précède ne fonctionne, essayez :ref:`faq_wifi_after_update`.



5. L'application Mammoth Coding (Scratch) ne parvient pas à se connecter ?
-----------------------------------------------------------------------------------------------

Si Mammoth Coding ne parvient pas à se connecter à votre GalaxyRVR, vérifiez les points suivants :

1. **Le firmware de la carte R3 est-il à jour ?** Mammoth Coding nécessite le firmware de communication d'usine sur la carte R3. Si vous avez téléversé votre propre code Arduino, le firmware de communication est écrasé. Réinstallez le dernier firmware officiel avec le flasheur en ligne, comme décrit dans :ref:`update_r3_firmware`.
2. **Le firmware de l'ESP32 CAM est-il à jour ?** L'ESP32 CAM gère la connexion WiFi dont Mammoth Coding a besoin. Suivez :ref:`update_esp32_firmware` pour vous assurer qu'il est à jour.
3. **L'interrupteur de mode est-il sur Run ?** L'interrupteur de mode doit être réglé sur **Run** pour que le point d'accès WiFi soit actif.
4. **Votre appareil mobile est-il connecté au bon réseau WiFi ?** Assurez-vous que votre appareil est connecté au point d'accès GalaxyRVR ou au même réseau WiFi domestique configuré sur le rover.

.. note::
   Si vous souhaitez utiliser **à la fois** la programmation Arduino et Mammoth Coding, gardez à l'esprit que vous devez téléverser à nouveau le firmware de la carte R3 chaque fois que vous passez de l'un à l'autre.

.. _install_lib:

6. Erreur de compilation : ``SoftPWM.h`` ou ``SunFounder_AI_Camera.h`` : No such file or directory ?
-------------------------------------------------------------------------------------------------------
Si vous obtenez le message "Erreur de compilation : ``SoftPWM.h`` : No such file or directory", cela signifie que la bibliothèque SoftPWM n'est pas installée.

Veuillez installer les deux bibliothèques requises ``SoftPWM`` et ``SunFounder AI Camera`` comme indiqué.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Votre navigateur ne prend pas en charge la balise vidéo.
        </video>

Pour la bibliothèque ``SunFounder AI Camera``, vous devez sélectionner "INSTALL ALL" pour installer simultanément la dépendance ``ArduinoJson`` requise.

    .. image:: img/faq_install_ai_camera.png

.. _faq_r3_upload_bat:

7. avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e?
-----------------------------------------------------------------------------
Si le message suivant continue d'apparaître après avoir cliqué sur le bouton **Upload**, alors que la carte et le port ont été correctement sélectionnés.

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00

Dans ce cas, vous devez vous assurer que l'ESP32 CAM est débranché.

L'ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, avant de téléverser du code, vous devez d'abord débrancher l'ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Après avoir réussi à téléverser le code, si vous devez utiliser l'ESP32 CAM, déplacez alors l'interrupteur vers la gauche pour démarrer l'ESP32 CAM.

    .. image:: img/camera_run.png
        :width: 500
        :align: center

.. _change_wifi_channel:

8. Comment changer le canal WiFi ?
----------------------------------

La bande WiFi 2,4 GHz comporte des canaux allant de 1 à 13. L'ESP32 prend en charge les canaux 1 à 11. D'autres appareils fonctionnant sur le même canal peuvent provoquer des interférences, entraînant des problèmes de connexion. Pour y remédier, vous pouvez essayer de changer le canal. Par défaut, le canal est réglé sur 1. Lors du choix d'un nouveau canal, il est recommandé de sauter 1 à 2 canaux à la fois. Par exemple, si le canal actuel est 1, essayez d'abord le canal 3, et si le signal est toujours faible, passez au canal 5.


#. Allumez le GalaxyRVR. Pour activer l'ESP32 CAM, placez l'interrupteur de mode sur la position **Run**, puis appuyez sur le bouton **reset** pour redémarrer la carte R3.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=_idwN0kJrxbVW-5H" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

#. Connectez votre appareil mobile au réseau WiFi du GalaxyRVR.

   * Le nom du réseau (SSID) est ``GalaxyRVR`` et le mot de passe est ``12345678``.
   * Si vous voyez un avertissement indiquant "Pas d'accès Internet", veuillez choisir l'option **"Rester connecté."**

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Ouvrez un navigateur Web sur votre appareil mobile et accédez à l'adresse ``http://192.168.4.1``. Cela vous mènera au portail de mise à jour du firmware de l'ESP32-CAM.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. Dans la page **AP**, sélectionnez un autre canal.

   * Le canal par défaut est 1. Lors du choix d'un nouveau canal, sautez 1 à 2 canaux à la fois (par exemple, du canal 1 au 3, et si nécessaire, au 5).

   .. image:: img/fap_ap_channel.jpg
        :width: 50%
        :align: center

#. Revenez à la page **Base** et cliquez sur le bouton **Reboot** pour redémarrer le GalaxyRVR. Le GalaxyRVR est maintenant prêt pour un fonctionnement normal.

   .. image:: img/faq_firmware_reboot.png
        :width: 50%
        :align: center

9. Comment mettre à jour le firmware de l'ESP32 CAM
---------------------------------------------------------

Pour garantir la compatibilité des applications et des performances optimales, veuillez vous assurer que le firmware de votre ESP32 CAM est à jour.

Pour des instructions détaillées étape par étape, veuillez consulter : :ref:`update_esp32_firmware`

10. Comment restaurer le firmware de la carte R3
---------------------------------------------------------

La carte R3 du GalaxyRVR est livrée avec un firmware qui prend en charge à la fois l'application RoboPilot et Mammoth Coding.

Si vous avez écrasé ce firmware et devez restaurer la communication, réinstallez le dernier firmware officiel comme décrit dans :ref:`update_r3_firmware`.

.. _ap_to_sta:

11. Comment configurer la connexion WiFi
-----------------------------------------------------

Par défaut, le GalaxyRVR fonctionne en **mode AP**, créant son propre point d'accès WiFi auquel d'autres appareils peuvent se connecter.

Si vous souhaitez que le GalaxyRVR se connecte à votre **réseau WiFi domestique**, suivez les étapes ci-dessous :


#. Allumez le GalaxyRVR. Pour activer l'ESP32 CAM, placez l'interrupteur de mode sur la position **Run**, puis appuyez sur le bouton **reset** pour redémarrer la carte R3.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=_idwN0kJrxbVW-5H" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Connectez votre appareil mobile au réseau WiFi du GalaxyRVR.

   * Le nom du réseau (SSID) est ``GalaxyRVR`` et le mot de passe est ``12345678``.
   * Si vous voyez un avertissement indiquant "Pas d'accès Internet", veuillez choisir l'option **"Rester connecté."**

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Ouvrez un navigateur Web sur votre appareil mobile et accédez à l'adresse ``http://192.168.4.1``. Cela vous mènera au portail de mise à jour du firmware de l'ESP32-CAM.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. Dans la page **WiFi**, saisissez le nom (SSID) et le mot de passe de votre réseau WiFi domestique.

   .. image:: img/faq_wifi.png
        :width: 50%
        :align: center

#. Appuyez sur le bouton **CONFIRM**.

   * Le GalaxyRVR tentera de se connecter à votre WiFi domestique.
   * Si la connexion réussit, l'icône de rotation s'arrêtera et une coche apparaîtra.

#. Après le redémarrage, connectez votre appareil mobile au même réseau WiFi domestique.

#. Vous pouvez maintenant vous connecter au GalaxyRVR via l'application RoboPilot ou Mammoth Coding.

.. _faq_wifi_after_update:

12. Comment restaurer les paramètres d'usine de l'ESP32 CAM ?
---------------------------------------------------------------------------------------

Si le point d'accès WiFi du GalaxyRVR n'apparaît pas ou si vous ne parvenez pas à vous connecter après avoir mis à jour le firmware de l'ESP32 CAM, il est possible que l'ancienne configuration WiFi stockée dans la mémoire flash de l'ESP32 CAM cause un conflit.

Pour résoudre ce problème, vous devez restaurer les paramètres d'usine de l'ESP32 CAM en effaçant les données stockées. Pour ce faire, court-circuitez les broches **IO13** et **IO15** de l'ESP32 CAM :

#. Éteignez l'interrupteur d'alimentation du GalaxyRVR.
#. Localisez les broches **IO13** et **IO15** sur le module ESP32 CAM.

   .. image:: img/esp32cam_io1315.png
        :width: 300
        :align: center

#. Utilisez un cavalier ou une pince à épiler pour court-circuiter (connecter) les broches **IO13** et **IO15** ensemble.
#. Tout en maintenant les broches court-circuitées, allumez l'interrupteur d'alimentation du GalaxyRVR.
#. Observez la LED de l'ESP32 CAM : lorsqu'elle **clignote deux fois rapidement**, retirez le cavalier.

   .. image:: img/esp32cam_led.png
        :width: 300
        :align: center

#. Placez l'interrupteur de mode sur **Run** et appuyez sur le bouton **Reset** de la carte R3.
#. L'ESP32 CAM démarrera maintenant avec sa configuration effacée. Vous devriez voir un point d'accès nommé ``AI Camera-xxxxxx`` (où ``xxxxxx`` est un identifiant unique) dans la liste WiFi de votre appareil. Connectez-vous en utilisant le mot de passe ``12345678``.
#. Après avoir redémarré le GalaxyRVR, le nom du point d'accès passera de ``AI Camera-xxxxxx`` à ``GalaxyRVR-xxxxxx``, indiquant que les paramètres d'usine ont été rétablies avec succès.

.. note::
   Après avoir restauré les paramètres d'usine, vous devrez reconfigurer les paramètres WiFi domestiques précédemment enregistrés (:ref:`ap_to_sta`).


.. .. _uno_firmware_mac:
..
.. 14. Comment mettre à jour le firmware de la R3 sous macOS ?
.. ---------------------------------------------------------------
..
.. La carte R3 comprend un firmware intégré qui permet la communication avec l'application RoboPilot et Mammoth Coding.
..
.. Vous devez re-téléverser ce firmware si :
..
.. - Votre appareil utilise une ancienne version du firmware, ou
.. - Vous avez flashé votre propre code Arduino et souhaitez restaurer la compatibilité.
..
.. Suivez les étapes ci-dessous pour réinstaller le firmware de communication.
..
.. #. Connectez l'Arduino à votre ordinateur avec un câble USB et placez l'interrupteur de mode sur **Upload**.
..
..    .. image:: img/camera_upload.png
..         :width: 500
..
..    .. note:: Utilisez le port USB Type B (pour la connexion à l'Arduino), pas le port USB Type C (pour le chargement uniquement).
..
.. #. Assurez-vous que les fichiers du firmware ont été téléchargés.
..
..    * |download_galaxyrvr_filmware|
..
.. #. Extrayez l'archive téléchargée pour obtenir un dossier ``output``. Faites un clic droit (ou Ctrl-clic) sur le dossier ``output`` et sélectionnez **New Terminal at Folder** dans le menu contextuel.
..
..    .. image:: img/faq_mac_firmware_open.png
..       :width: 400
..
.. #. Le Terminal s'ouvrira directement dans le dossier ``output``.
..
..    * Exécutez la commande ``bash update-arduino-firmware-mac.sh``
..    * Puis entrez le numéro du port COM détecté (par exemple, ``1``) :
..
..    .. image:: img/faq_mac_firmware_run.png
..       :width: 600
..
.. #. Si vous voyez le message **"avrdude not Opened"** :
..
..    .. image:: img/faq_mac_firmware_avrdude.png
..       :width: 300
..
.. #. Allez dans **Réglages Système** > **Confidentialité et sécurité** et cliquez sur **Allow Anyway**.
..
..    .. image:: img/faq_mac_firmware_allow.png
..       :width: 600
..
.. #. Exécutez à nouveau le script : ``bash update-arduino-firmware-mac.sh``
..
..    Cette fois, vous pourrez sélectionner **Open Anyway**. Saisissez votre nom d'utilisateur et votre mot de passe administrateur pour autoriser l'opération.
..
..    .. image:: img/faq_mac_firmware_anyway.png
..       :width: 600
..
.. #. Une fois le message de succès affiché, vous pouvez débrancher le câble USB.
..
..    .. image:: img/faq_mac_firmware_finish.png
..       :width: 600
..
.. .. important::
..
..    * Ce firmware permet au GalaxyRVR de répondre aux commandes de l'application.
..    * Vous n'aurez pas besoin de téléverser du code supplémentaire lorsque vous utilisez l'application de contrôle à distance RoboPilot ou le logiciel Mammoth Coding.
..    * Vous pouvez maintenant passer à :ref:`quick_start` pour commencer votre aventure GalaxyRVR !
