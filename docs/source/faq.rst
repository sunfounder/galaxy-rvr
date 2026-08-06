.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

FAQ
==============

1. Pourquoi devriez-vous mettre a jour le micrologiciel ?
----------------------------------------------------------------------------------------

SunFounder ameliore continuellement le micrologiciel du GalaxyRVR pour offrir une meilleure experience. Nous vous recommandons de mettre a jour le micrologiciel avant la premiere utilisation afin de garantir un fonctionnement optimal. La mise a jour du micrologiciel permet de :

* **Corriger des bugs** : Resout les problemes connus et ameliore la stabilite.
* **Assurer la compatibilite des applications** : Le dernier micrologiciel est necessaire au bon fonctionnement de l'application RoboPilot et de Mammoth Coding.
* **Ajouter de nouvelles fonctionnalites** : Les mises a jour du micrologiciel peuvent apporter de nouvelles capacites et ameliorations.
* **Ameliorer les performances** : Optimisations de la connectivite WiFi, du flux video et du controle des moteurs.

Pour des instructions de mise a jour detaillees, consultez : :ref:`update_firmware`.

.. note::
   Si vous preferez ne pas mettre a jour le micrologiciel et souhaitez continuer a utiliser votre configuration actuelle, vous pouvez consulter la `Documentation GalaxyRVR v1 <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_.


2. Impossible de se connecter au GalaxyRVR ?
-------------------------------------------------------------------------------------------------

Si vous ne parvenez pas a vous connecter au GalaxyRVR, veuillez verifier les points suivants :

1. **Verifiez la batterie** : Observez les indicateurs de batterie sur le rover. Si les deux LED sont eteintes, la batterie est faible. Rechargez le rover a l'aide d'un cable USB Type-C.
2. **Verifiez l'ESP32 CAM** : Assurez-vous que l'ESP32 CAM est correctement insere dans son emplacement. Si la LED de l'ESP32 CAM n'est pas allumee, le module camera ne recoit peut-etre pas d'alimentation ou pourrait etre endommage. L'ESP32 CAM cree le point d'acces WiFi : s'il ne fonctionne pas, aucun reseau n'apparaîtra.
3. **Verifiez l'interrupteur de mode** : Assurez-vous que l'interrupteur de mode est regle sur **Run** (pas **Upload**). Le point d'acces WiFi fonctionne uniquement en mode Run.

   .. image:: img/camera_run.png
        :width: 500
        :align: center

4. **Reinitialisez la carte R3** : Apres etre passe en mode Run, appuyez sur le bouton **Reset** de la carte R3. La bande lumineuse inferieure doit clignoter pour indiquer un demarrage reussi.
5. **Verifiez le mot de passe WiFi** : Le nom du point d'acces (SSID) par defaut est ``GalaxyRVR`` et le mot de passe est ``12345678``. Assurez-vous d'avoir saisi le mot de passe correctement.
6. **Interferences WiFi** : D'autres appareils sur le meme canal WiFi peuvent causer des problemes de connexion. Si vous soupçonnez des interferences, essayez de :ref:`changer le canal WiFi <change_wifi_channel>`.
7. **Apres une mise a jour du micrologiciel** : Si vous venez de mettre a jour le micrologiciel de l'ESP32 CAM et que le WiFi a cesse de fonctionner, consultez :ref:`faq_wifi_after_update`.
8. **Verifiez la connexion de votre appareil mobile** : Si vous utilisez le GalaxyRVR en mode AP (par defaut), connectez votre appareil mobile au point d'acces GalaxyRVR. Si vous avez :ref:`configure un reseau WiFi domestique <ap_to_sta>`, assurez-vous que votre appareil mobile est connecte au **meme** reseau WiFi domestique.


3. La lumiere du dessous est orange fixe et aucun point d'acces WiFi n'apparaît ?
--------------------------------------------------------------------------------------------------

Si la bande lumineuse inferieure du GalaxyRVR affiche une **lumiere orange fixe** et que le reseau WiFi ``GalaxyRVR`` n'apparaît pas, la cause est une **incompatibilite de version du micrologiciel** :

- Le micrologiciel de l'**ESP32 CAM** est encore une version ancienne (1.4.x ou 1.3.x)
- Le micrologiciel de la **carte UNO R3** a ete mis a jour vers la version 2.x
- Cette incompatibilite empeche la communication entre l'ESP32 CAM et la carte UNO R3

Pour resoudre ce probleme, suivez ces etapes **dans l'ordre exact** :

#. **Revenez d'abord au micrologiciel version 1.x de la carte UNO R3** :

   Suivez le guide dans la documentation v1 : `GalaxyRVR v1 — Comment televerser le code galaxy-rvr.ino <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/faq.html#how-to-upload-the-galaxy-rvr-ino-code>`_

#. **Mettez a jour les deux micrologiciels en suivant l'ordre ESP32 CAM puis UNO R3** :

   Suivez le guide mis a jour : :ref:`update_firmware`

.. note::

   L'ordre est important : mettez toujours a jour l'ESP32 CAM en premier, puis la carte R3. Ignorer l'etape de retour en arriere ou modifier l'ordre ne resoudra pas le probleme.



4. L'application RoboPilot ne parvient pas a se connecter ?
---------------------------------------------------------------------------------------

Si l'application RoboPilot ne trouve pas ou ne parvient pas a se connecter a votre GalaxyRVR, veuillez verifier les points suivants :

1. **Le micrologiciel de l'ESP32 CAM est-il a jour ?** Un micrologiciel ESP32 CAM obsolete peut causer des problemes de connexion. Suivez :ref:`update_esp32_firmware` pour verifier et mettre a jour.
2. **Le micrologiciel de la carte R3 est-il a jour ?** La carte R3 doit disposer du micrologiciel de communication d'usine. Si vous avez televerse du code Arduino personnalise, cela ecrasera ce micrologiciel et interrompra la communication avec RoboPilot. Suivez :ref:`update_r3_firmware` pour le restaurer.
3. **L'interrupteur de mode est-il sur Run ?** L'interrupteur de mode doit etre regle sur **Run** (pas Upload) pour que le point d'acces WiFi fonctionne.
4. **Votre appareil mobile est-il connecte au bon reseau WiFi ?** Connectez-vous au point d'acces GalaxyRVR (``GalaxyRVR`` / ``12345678``), ou si vous avez configure un WiFi domestique, connectez-vous a ce meme reseau.
5. **Essayez de reinitialiser** : Passez en mode **Run** et appuyez sur le bouton **Reset**, puis essayez de vous reconnecter.

Si rien de ce qui precede ne fonctionne, essayez :ref:`faq_wifi_after_update`.


5. L'application Mammoth Coding (Scratch) ne parvient pas a se connecter ?
-----------------------------------------------------------------------------------------------

Si Mammoth Coding ne parvient pas a se connecter a votre GalaxyRVR, veuillez verifier les points suivants :

1. **Le micrologiciel de l'ESP32 CAM est-il a jour ?** L'ESP32 CAM gere la connexion WiFi dont Mammoth Coding a besoin. Suivez :ref:`update_esp32_firmware` pour vous assurer qu'il est a jour.
2. **Le micrologiciel de la carte R3 est-il a jour ?** Mammoth Coding necessite le micrologiciel de communication d'usine sur la carte R3. Si vous avez televerse votre propre code Arduino, le micrologiciel de communication est ecrase. Suivez :ref:`update_r3_firmware` pour le restaurer.
3. **L'interrupteur de mode est-il sur Run ?** L'interrupteur de mode doit etre regle sur **Run** pour que le point d'acces WiFi soit actif.
4. **Votre appareil mobile est-il connecte au bon reseau WiFi ?** Assurez-vous que votre appareil est connecte au point d'acces GalaxyRVR ou au meme reseau WiFi domestique configure sur le rover.

.. note::
   Si vous souhaitez utiliser **a la fois** la programmation Arduino et Mammoth Coding, gardez a l'esprit que vous devez reteleverser le micrologiciel de la carte R3 a chaque changement entre les deux.

.. _install_lib:

6. Erreur de compilation : ``SoftPWM.h`` ou ``SunFounder_AI_Camera.h`` : No such file or directory？
-------------------------------------------------------------------------------------------------------
Si vous obtenez le message "Erreur de compilation : ``SoftPWM.h``: No such file or directory", cela signifie que la bibliotheque SoftPWM n'est pas installee.

Veuillez installer les deux bibliotheques requises ``SoftPWM`` et ``SunFounder AI Camera`` comme indique.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Votre navigateur ne prend pas en charge la balise video.
        </video>

Pour la bibliotheque ``SunFounder AI Camera``, vous devez selectionner "INSTALL ALL" pour installer simultanement la dependance ``ArduinoJson`` requise.

    .. image:: img/faq_install_ai_camera.png

7. avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e?
-----------------------------------------------------------------------------
Si le message suivant continue d'apparaître apres avoir clique sur le bouton **Upload** alors que la carte et le port ont ete correctement selectionnes.

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00

Dans ce cas, vous devez vous assurer que l'ESP32 CAM est debranche.

L'ESP32-CAM et la carte Arduino partagent les memes broches RX (reception) et TX (transmission). Par consequent, avant de televerser du code, vous devez d'abord debrancher l'ESP32-CAM pour eviter tout conflit ou probleme potentiel.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Apres avoir reussi a televerser le code, si vous devez utiliser l'ESP32 CAM, deplacez alors l'interrupteur vers la gauche pour demarrer l'ESP32 CAM.

    .. image:: img/camera_run.png
        :width: 500
        :align: center

.. _change_wifi_channel:

8. Comment changer le canal WiFi ?
----------------------------------

La bande WiFi 2,4 GHz comporte des canaux allant de 1 a 13. L'ESP32 prend en charge les canaux 1 a 11. D'autres appareils fonctionnant sur le meme canal peuvent provoquer des interferences, entrainant des problemes de connexion. Pour remedier a cela, vous pouvez essayer de changer le canal. Par defaut, le canal est regle sur 1. Lors du choix d'un nouveau canal, il est recommande de sauter 1 a 2 canaux a la fois. Par exemple, si le canal actuel est 1, essayez d'abord le canal 3, et si le signal est toujours faible, passez au canal 5.


#. Allumez le GalaxyRVR. Pour activer l'ESP32 CAM, placez l'interrupteur de mode sur la position **Run**, puis appuyez sur le bouton **reset** pour redemarrer la carte R3.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Connectez votre appareil mobile au reseau WiFi du GalaxyRVR.

   * Le nom du reseau (SSID) est ``GalaxyRVR`` et le mot de passe est ``12345678``.
   * Si vous voyez un avertissement indiquant "Pas d'acces Internet", veuillez choisir l'option **"Rester connecte."**

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Ouvrez un navigateur Web sur votre appareil mobile et accedez a l'adresse ``http://192.168.4.1``. Cela vous menera au portail de mise a jour du micrologiciel de l'ESP32-CAM.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. Dans la page **AP**, selectionnez un canal different.

   * Le canal par defaut est 1. Lors du choix d'un nouveau canal, sautez 1 a 2 canaux a la fois (par exemple, du canal 1 au 3, et si necessaire, au 5).

   .. image:: img/fap_ap_channel.jpg
        :width: 50%
        :align: center

#. Revenez a la page **Base** et cliquez sur le bouton **Reboot** pour redemarrer le GalaxyRVR. Le GalaxyRVR est maintenant pret pour un fonctionnement normal.

   .. image:: img/faq_firmware_reboot.png
        :width: 50%
        :align: center

9. Comment mettre a jour le micrologiciel de l'ESP32 CAM
---------------------------------------------------------

Pour garantir la compatibilite des applications et des performances optimales, assurez-vous que le micrologiciel de votre ESP32 CAM est a jour.

Pour des instructions detaillees, veuillez consulter : :ref:`update_esp32_firmware`

10. Comment restaurer le micrologiciel de la carte R3
---------------------------------------------------------

La carte R3 du GalaxyRVR est livree avec un micrologiciel qui prend en charge a la fois l'application RoboPilot et Mammoth Coding.

Si vous avez ecrase ce micrologiciel et devez restaurer la communication, suivez :ref:`update_r3_firmware`.

.. _ap_to_sta:

11. Comment configurer la connexion WiFi
-----------------------------------------------------

Par defaut, le GalaxyRVR fonctionne en **mode AP**, creant son propre point d'acces WiFi auquel d'autres appareils peuvent se connecter.

Si vous souhaitez que le GalaxyRVR se connecte a votre **reseau WiFi domestique**, suivez les etapes ci-dessous :


#. Allumez le GalaxyRVR. Pour activer l'ESP32 CAM, placez l'interrupteur de mode sur la position **Run**, puis appuyez sur le bouton **reset** pour redemarrer la carte R3.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Connectez votre appareil mobile au reseau WiFi du GalaxyRVR.

   * Le nom du reseau (SSID) est ``GalaxyRVR`` et le mot de passe est ``12345678``.
   * Si vous voyez un avertissement indiquant "Pas d'acces Internet", veuillez choisir l'option **"Rester connecte."**

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Ouvrez un navigateur Web sur votre appareil mobile et accedez a l'adresse ``http://192.168.4.1``. Cela vous menera au portail de mise a jour du micrologiciel de l'ESP32-CAM.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. Dans la page **WiFi**, saisissez le nom (SSID) et le mot de passe de votre reseau WiFi domestique.

   .. image:: img/faq_wifi.png
        :width: 50%
        :align: center

#. Appuyez sur le bouton **CONFIRM**.

   * Le GalaxyRVR tentera de se connecter a votre WiFi domestique.
   * Si la connexion reussit, l'icone de rotation s'arretera et une coche apparaîtra.

#. Apres le redemarrage, connectez votre appareil mobile au meme reseau WiFi domestique.

#. Vous pouvez maintenant vous connecter au GalaxyRVR via l'application RoboPilot ou Mammoth Coding.

.. _faq_wifi_after_update:

12. Comment restaurer les parametres d'usine de l'ESP32 CAM ?
---------------------------------------------------------------------------------------

Si le point d'acces WiFi du GalaxyRVR n'apparaît pas ou si vous ne parvenez pas a vous connecter apres avoir mis a jour le micrologiciel de l'ESP32 CAM, il est possible que l'ancienne configuration WiFi stockee dans la memoire flash de l'ESP32 CAM cause un conflit.

Pour resoudre ce probleme, vous devez restaurer les parametres d'usine de l'ESP32 CAM en effacant les donnees stockees. Pour ce faire, court-circuitez les broches **IO13** et **IO15** de l'ESP32 CAM :

#. Eteignez l'interrupteur d'alimentation du GalaxyRVR.
#. Localisez les broches **IO13** et **IO15** sur le module ESP32 CAM.

   .. image:: img/esp32cam_io1315.png
        :width: 300
        :align: center

#. Utilisez un cavalier ou une pince a epiler pour court-circuiter (connecter) les broches **IO13** et **IO15** ensemble.
#. Tout en maintenant les broches court-circuitees, allumez l'interrupteur d'alimentation du GalaxyRVR.
#. Observez la LED de l'ESP32 CAM : lorsqu'elle **clignote deux fois rapidement**, retirez le cavalier.

   .. image:: img/esp32cam_led.png
        :width: 300
        :align: center

#. Placez l'interrupteur de mode sur **Run** et appuyez sur le bouton **Reset** de la carte R3.
#. L'ESP32 CAM demarrera maintenant avec sa configuration effacee. Vous devriez voir un point d'acces nomme ``AI Camera-xxxxxx`` (ou ``xxxxxx`` est un identifiant unique) dans la liste WiFi de votre appareil. Connectez-vous en utilisant le mot de passe ``12345678``.
#. Apres avoir redemarre le GalaxyRVR, le nom du point d'acces passera de ``AI Camera-xxxxxx`` a ``GalaxyRVR-xxxxxx``, indiquant que les parametres d'usine ont ete retablis avec succes.

.. note::
   Après avoir restauré les paramètres d'usine, vous devrez reconfigurer les paramètres WiFi domestiques précédemment enregistrés (:ref:`ap_to_sta`).


.. _uno_firmware_mac:

13. Comment mettre à jour le firmware de la R3 sous macOS ?
---------------------------------------------------------------

La carte R3 comprend un firmware intégré qui permet la communication avec l'application RoboPilot et Mammoth Coding.

Vous devez re-téléverser ce firmware si :

- Votre appareil utilise une ancienne version du firmware, ou
- Vous avez flashé votre propre code Arduino et souhaitez restaurer la compatibilité.

Suivez les étapes ci-dessous pour réinstaller le firmware de communication.

#. Connectez l'Arduino à votre ordinateur avec un câble USB A vers B (pas USB Type-C) et placez l'interrupteur de mode sur **Upload**.

   .. image:: img/camera_upload.png
        :width: 500

   .. note:: Utilisez le port USB Type B (pour la connexion à l'Arduino), pas le port USB Type C (pour le chargement uniquement).

#. Assurez-vous que les fichiers du firmware ont été téléchargés.

   * |download_galaxyrvr_filmware|

#. Extrayez l'archive téléchargée pour obtenir un dossier ``output``. Faites un clic droit (ou Ctrl-clic) sur le dossier ``output`` et sélectionnez **New Terminal at Folder** dans le menu contextuel.

   .. image:: img/faq_mac_firmware_open.png

#. Le Terminal s'ouvrira directement dans le dossier ``output``. Exécutez la commande suivante, puis entrez le numéro du port COM détecté (par exemple, ``1``) :

   .. code-block:: bash

      bash update-arduino-firmware-mac.sh

   .. image:: img/faq_mac_firmware_run.png
      :width: 500

#. Si vous voyez le message **"avrdude not Opened"** :

   .. image:: img/faq_mac_firmware_avrdude.png

#. Allez dans Réglages Système > **Confidentialité et sécurité** et cliquez sur **Allow Anyway** (Autoriser quand même).

   .. image:: img/faq_mac_firmware_allow.png
      :width: 500

#. Exécutez à nouveau le script :

   .. code-block:: bash

      bash update-arduino-firmware-mac.sh

   Cette fois, vous pourrez sélectionner **Open Anyway**. Saisissez votre nom d'utilisateur et votre mot de passe administrateur pour autoriser l'opération.

   .. image:: img/faq_mac_firmware_anyway.png
      :width: 500

#. Une fois le message de succès affiché, vous pouvez débrancher le câble USB.

   .. image:: img/faq_mac_firmware_finish.png
      :width: 500

   .. note::

      Ce firmware permet au GalaxyRVR de répondre aux commandes de l'application. Vous n'aurez pas besoin de téléverser du code supplémentaire lorsque vous utilisez l'application de contrôle à distance RoboPilot ou le logiciel Mammoth Coding.

#. Vous pouvez maintenant passer à :ref:`quick_start` pour commencer votre aventure GalaxyRVR !
