.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

FAQ
==============

1. Pourquoi mettre à jour le firmware ?
----------------------------------------------------------------------------------------

SunFounder améliore continuellement le firmware du GalaxyRVR pour offrir une meilleure expérience. Nous vous recommandons de mettre à jour le firmware avant votre première utilisation pour garantir un fonctionnement optimal. La mise à jour du firmware assure :

* **Corrections de bugs** : Résout les problèmes connus et améliore la stabilité.
* **Compatibilité des applications** : Le dernier firmware est nécessaire au bon fonctionnement de l'application RoboPilot et de Mammoth Coding.
* **Nouvelles fonctionnalités** : Les mises à jour du firmware peuvent ajouter de nouvelles capacités et améliorations.
* **Meilleures performances** : Optimisations pour la connectivité WiFi, le streaming de la caméra et le contrôle des moteurs.

Pour des instructions de mise à jour étape par étape, voir :ref:`update_firmware`.

.. note::
   Si vous préférez ne pas mettre à jour le firmware et continuer à utiliser votre configuration actuelle, vous pouvez consulter la `Documentation GalaxyRVR v1 <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_.


2. Impossible de se connecter au GalaxyRVR ?
-------------------------------------------------------------------------------------------------

Si vous ne pouvez pas vous connecter au GalaxyRVR, veuillez vérifier les points suivants :

1. **Vérifiez la batterie** : Regardez les indicateurs de batterie sur le rover. Si les deux LED sont éteintes, la batterie est faible. Rechargez le rover à l'aide d'un câble USB Type-C.
2. **Vérifiez le commutateur de mode** : Assurez-vous que le commutateur de mode est réglé sur **Run** (pas **Upload**). Le hotspot WiFi ne fonctionne qu'en mode Run.

   .. image:: img/camera_run.png
        :width: 500
        :align: center

3. **Réinitialisez la carte R3** : Après être passé en mode Run, appuyez sur le bouton **Reset** de la carte R3. La bande lumineuse inférieure doit clignoter pour indiquer un démarrage réussi.
4. **Vérifiez le mot de passe WiFi** : Le nom du hotspot par défaut (SSID) est ``GalaxyRVR`` et le mot de passe est ``12345678``. Assurez-vous d'avoir saisi le bon mot de passe.
5. **Vérifiez l'ESP32 CAM** : Assurez-vous que l'ESP32 CAM est correctement inséré dans son emplacement. Si la LED de l'ESP32 CAM n'est pas allumée, le module caméra peut ne pas être alimenté ou pourrait être endommagé.
6. **Interférences WiFi** : D'autres appareils sur le même canal WiFi peuvent causer des problèmes de connexion. Si vous soupçonnez des interférences, essayez de :ref:`changer le canal WiFi <change_wifi_channel>`.
7. **Après la mise à jour du firmware** : Si vous venez de mettre à jour le firmware de l'ESP32 CAM et que le WiFi a cessé de fonctionner, voir :ref:`faq_wifi_after_update`.
8. **Vérifiez la connexion de votre appareil mobile** : Si vous utilisez GalaxyRVR en mode AP (par défaut), connectez votre appareil mobile au hotspot GalaxyRVR. Si vous avez :ref:`configuré un réseau Wi-Fi domestique <ap_to_sta>`, assurez-vous que votre appareil mobile est connecté au **même** réseau Wi-Fi domestique.


3. L'application RoboPilot ne peut pas se connecter ?
---------------------------------------------------------------------------------------

Si l'application RoboPilot ne trouve pas ou ne peut pas se connecter à votre GalaxyRVR, vérifiez les points suivants :

1. **Le firmware R3 est-il à jour ?** La carte R3 doit avoir le firmware de communication d'usine installé. Si vous avez téléversé du code Arduino personnalisé, il écrasera ce firmware et rompra la communication avec RoboPilot. Suivez :ref:`update_r3_firmware` pour le restaurer.
2. **Le firmware ESP32 CAM est-il à jour ?** Un firmware ESP32 CAM obsolète peut causer des problèmes de connexion. Suivez :ref:`update_esp32_firmware` pour vérifier et mettre à jour.
3. **Le commutateur de mode est-il sur Run ?** Le commutateur de mode doit être réglé sur **Run** (pas Upload) pour que le hotspot WiFi fonctionne.
4. **Votre appareil mobile est-il sur le bon réseau WiFi ?** Connectez-vous au hotspot GalaxyRVR (``GalaxyRVR`` / ``12345678``), ou si vous avez configuré un WiFi domestique, connectez-vous à ce même réseau.
5. **Essayez de réinitialiser** : Passez en mode **Run** et appuyez sur le bouton **Reset**, puis essayez de vous reconnecter.

Si rien de ce qui précède ne vous aide, essayez d':ref:`effacer la configuration de l'ESP32 CAM <faq_wifi_after_update>`.


4. L'application Mammoth Coding (Scratch) ne peut pas se connecter ?
---------------------------------------------------------------------------------------

Si Mammoth Coding ne peut pas se connecter à votre GalaxyRVR, vérifiez les points suivants :

1. **Le firmware R3 est-il à jour ?** Mammoth Coding nécessite le firmware de communication d'usine sur la carte R3. Si vous avez téléversé votre propre code Arduino, le firmware de communication est écrasé. Suivez :ref:`update_r3_firmware` pour le restaurer.
2. **Le firmware ESP32 CAM est-il à jour ?** L'ESP32 CAM gère la connexion WiFi sur laquelle Mammoth Coding s'appuie. Suivez :ref:`update_esp32_firmware` pour vous assurer qu'il est à jour.
3. **Le commutateur de mode est-il sur Run ?** Le commutateur de mode doit être réglé sur **Run** pour que le hotspot WiFi soit actif.
4. **Votre appareil mobile est-il sur le bon réseau WiFi ?** Assurez-vous que votre appareil est connecté au hotspot GalaxyRVR ou au même réseau WiFi domestique configuré sur le rover.
5. **Après avoir téléversé du code Arduino** : N'oubliez pas que téléverser n'importe quel sketch Arduino sur la carte R3 écrasera le firmware de communication. Vous devrez :ref:`restaurer le firmware R3 <update_r3_firmware>` avant que Mammoth Coding puisse se reconnecter.

.. note::
   Si vous souhaitez utiliser **à la fois** la programmation Arduino et Mammoth Coding, gardez à l'esprit que vous devez re-téléverser le firmware R3 chaque fois que vous passez de l'un à l'autre.

.. _install_lib:

5. Erreur de compilation : ``SoftPWM.h`` ou ``SunFounder_AI_Camera.h`` : Fichier ou répertoire introuvable ?
--------------------------------------------------------------------------------------------------------------
Si vous obtenez un message "Erreur de compilation : ``SoftPWM.h`` : Fichier ou répertoire introuvable", cela signifie que la bibliothèque SoftPWM n'est pas installée.

Veuillez installer les deux bibliothèques requises ``SoftPWM`` et ``SunFounder AI Camera`` comme indiqué.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

Pour la bibliothèque ``SunFounder AI Camera``, vous devez sélectionner "INSTALL ALL" pour installer simultanément la dépendance requise ``ArduinoJson``.

    .. image:: img/faq_install_ai_camera.png

6. avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e?
-----------------------------------------------------------------------------
Si le message suivant continue d'apparaître après avoir cliqué sur le bouton **Upload** alors que la carte et le port ont été correctement sélectionnés.

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00

À ce stade, vous devez vous assurer que l'ESP32 CAM est débranché.

L'ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Donc, avant de téléverser du code, vous devez d'abord déconnecter l'ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Une fois le code téléversé avec succès, si vous devez utiliser l'ESP32 CAM, vous devez déplacer le commutateur vers la gauche pour démarrer l'ESP32 CAM.

    .. image:: img/camera_run.png
        :width: 500
        :align: center

.. _change_wifi_channel:

7. Comment changer le canal Wi-Fi ?
-------------------------------------

La bande Wi-Fi 2,4 GHz dispose de canaux allant de 1 à 13. L'ESP32 prend en charge les canaux 1 à 11. D'autres appareils fonctionnant sur le même canal peuvent provoquer des interférences, entraînant des problèmes de connexion. Pour atténuer cela, vous pouvez essayer de changer de canal. Par défaut, le canal est réglé sur 1. Lors de la sélection d'un nouveau canal, il est recommandé de sauter 1 à 2 canaux à la fois. Par exemple, si le canal actuel est 1, essayez d'abord le canal 3, et si le signal est encore faible, passez au canal 5.


#. Allumez le GalaxyRVR. Pour activer l'ESP32 CAM, placez le commutateur de mode en position **Run** et appuyez sur le bouton **reset** pour redémarrer la carte R3.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Connectez votre appareil mobile au réseau WiFi du GalaxyRVR.

   * Le nom du réseau (SSID) est ``GalaxyRVR`` et le mot de passe est ``12345678``.
   * Si vous voyez un avertissement indiquant "Aucun accès Internet", veuillez choisir l'option **"Rester connecté"**.

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Ouvrez un navigateur web sur votre appareil mobile et allez à l'adresse ``http://192.168.4.1``. Cela vous mènera au portail de mise à jour du firmware ESP32-CAM.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. Sous la page **AP**, sélectionnez un canal différent.

   * Le canal par défaut est 1. Lors de la sélection d'un nouveau canal, sautez 1 à 2 canaux à la fois (par exemple, du canal 1 au 3, et si nécessaire, au 5).

   .. image:: img/fap_ap_channel.jpg
        :width: 50%
        :align: center

#. Retournez à la page **Base** et cliquez sur le bouton **Reboot** pour redémarrer le GalaxyRVR. Le GalaxyRVR est maintenant prêt pour un fonctionnement normal.

   .. image:: img/faq_firmware_reboot.png
        :width: 50%
        :align: center

8. Comment mettre à jour le firmware de l'ESP32 CAM
--------------------------------------------------------

Pour assurer la compatibilité des applications et des performances optimales, veuillez vous assurer que le firmware de votre ESP32 CAM est à jour.

Pour des instructions détaillées étape par étape, veuillez consulter : :ref:`update_esp32_firmware`

9. Comment restaurer le firmware R3
-----------------------------------------

La carte R3 du GalaxyRVR est livrée avec un firmware qui prend en charge à la fois l'application RoboPilot et Mammoth Coding.

Si vous avez écrasé ce firmware et devez restaurer la communication, suivez :ref:`update_r3_firmware`.

.. _ap_to_sta:

10. Comment configurer la connexion Wi-Fi
-----------------------------------------------------

Par défaut, GalaxyRVR fonctionne en **mode AP**, où il crée son propre hotspot Wi-Fi auquel d'autres appareils peuvent se connecter.

Si vous souhaitez que GalaxyRVR se connecte à votre **réseau Wi-Fi domestique**, suivez les étapes ci-dessous :


#. Allumez le GalaxyRVR. Pour activer l'ESP32 CAM, placez le commutateur de mode en position **Run** et appuyez sur le bouton **reset** pour redémarrer la carte R3.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Connectez votre appareil mobile au réseau WiFi du GalaxyRVR.

   * Le nom du réseau (SSID) est ``GalaxyRVR`` et le mot de passe est ``12345678``.
   * Si vous voyez un avertissement indiquant "Aucun accès Internet", veuillez choisir l'option **"Rester connecté"**.

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Ouvrez un navigateur web sur votre appareil mobile et allez à l'adresse ``http://192.168.4.1``. Cela vous mènera au portail de mise à jour du firmware ESP32-CAM.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. Sous la page **WiFi**, saisissez le nom de votre réseau WiFi domestique (SSID) et le mot de passe.

   .. image:: img/faq_wifi.png
        :width: 50%
        :align: center

#. Appuyez sur le bouton **CONFIRM**.

   * GalaxyRVR tentera de se connecter à votre Wi-Fi domestique.
   * Si la connexion réussit, l'icône de chargement s'arrêtera et une coche apparaîtra.

#. Après le redémarrage, connectez votre appareil mobile au même réseau Wi-Fi domestique.

#. Vous pouvez maintenant vous connecter à GalaxyRVR via l'application RoboPilot ou Mammoth Coding.

.. _faq_wifi_after_update:

11. Comment restaurer l'ESP32 CAM aux paramètres d'usine ?
---------------------------------------------------------------------------------------

Si le hotspot WiFi du GalaxyRVR n'apparaît pas ou si vous ne pouvez pas vous connecter après la mise à jour du firmware de l'ESP32 CAM, les anciennes données de configuration WiFi stockées dans la mémoire flash de l'ESP32 CAM peuvent causer un conflit.

Pour résoudre ce problème, vous devez restaurer l'ESP32 CAM à ses paramètres d'usine en effaçant les données stockées. Cela se fait en court-circuitant les broches **IO13** et **IO15** de l'ESP32 CAM :

#. Éteignez l'interrupteur d'alimentation du GalaxyRVR.
#. Repérez les broches **IO13** et **IO15** sur le module ESP32 CAM.

   .. image:: img/esp32cam_io1315.png
        :width: 300
        :align: center

#. Utilisez un fil de cavalier ou une pince à épiler pour court-circuiter (connecter) les broches **IO13** et **IO15** ensemble.
#. Tout en maintenant les broches court-circuitées, allumez l'interrupteur d'alimentation du GalaxyRVR.
#. Surveillez la LED de l'ESP32 CAM — lorsqu'elle **clignote deux fois rapidement**, retirez le fil de cavalier.

   .. image:: img/esp32cam_led.png
        :width: 300
        :align: center

#. Passez le mode sur **Run** et appuyez sur le bouton **Reset** de la carte R3.
#. L'ESP32 CAM démarrera maintenant avec sa configuration effacée. Vous devriez voir un hotspot nommé ``AI Camera-xxxxxx`` (où ``xxxxxx`` est un identifiant unique) dans la liste WiFi de votre appareil. Connectez-vous en utilisant le mot de passe ``12345678``.
#. Après avoir redémarré le GalaxyRVR, le nom du hotspot passera de ``AI Camera-xxxxxx`` à ``GalaxyRVR-xxxxxx``, indiquant que les paramètres d'usine ont été restaurés avec succès.

.. note::
   Après avoir restauré les paramètres d'usine, vous devrez reconfigurer tous les paramètres WiFi domestique précédemment enregistrés (:ref:`ap_to_sta`).
