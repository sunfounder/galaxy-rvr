.. note::

    Bonjour et bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 ! Plongez au cœur de l'univers du Raspberry Pi, d'Arduino et d'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Soutien d'experts** : Résolvez les problèmes après-vente et surmontez les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez astuces et tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus exclusifs.
    - **Réductions spéciales** : Bénéficiez de remises exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et à des promotions lors des fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _update_firmware:

Mise à jour du firmware
===============================

Connectez vos appareils mobiles (tels que téléphones ou tablettes) au point d'accès Wi-Fi émis par le GalaxyRVR. 
En général, le SSID est ``GalaxyRVR`` et le mot de passe est ``12345678``.

.. image:: img/firmware/SSID.png

.. note:: Le mode de connexion par défaut est le **mode AP**. Après la connexion, vous pourriez recevoir un avertissement indiquant qu'il n'y a pas d'accès à Internet sur ce réseau. Dans ce cas, choisissez "Rester connecté".

    .. image:: img/app/camera_stay.png

6. Accédez à l'adresse http://192.168.4.1 pour ouvrir l'interface de mise à jour du firmware de l'ESP32 Cam.

.. image:: img/firmware/OTAUpdate.jpg

7. Vérifiez le numéro de version. Si votre version est supérieure à ``1.5.1``, aucune mise à jour n'est nécessaire (passez les étapes 8-12). Sinon, une mise à jour est requise.

.. image:: img/firmware/OTAversion.jpg

8. Transférez le fichier ``ai-camera-firware.ino.1.5.1.bin`` sur l'appareil.

.. image:: img/firmware/selectBin.png

9. Revenez à l'interface de mise à jour du firmware. Cliquez pour sélectionner le firmware.

.. image:: img/firmware/OTASButton.jpg

10. Sélectionnez le fichier ``ai-camera-firware.ino.1.5.1.bin`` que vous venez de stocker sur votre appareil mobile, puis cliquez sur "Mettre à jour".

.. image:: img/firmware/OTASelect.jpg

11. Attendez que la mise à jour du firmware soit terminée. Une fois que le numéro de version affiché est 1.5.1, la mise à jour est réussie.

.. image:: img/firmware/OTAFinish.jpg

12. Fermez la page.

