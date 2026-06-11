.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Leçon 9 : Compagnon d'exploration martienne
===========================================

Maintenant que notre Rover sait éviter les obstacles avec habileté, apprenons-lui un nouveau tour – suivre une cible ! Dans cette mission, nous allons transformer notre rover anti-obstacle en un fidèle compagnon capable de vous suivre partout.

Quelle est la différence entre suivre et éviter ?

- **Éviter** : S'écarter des objets (comme esquiver des rochers)
- **Suivre** : Se diriger vers les objets (comme suivre un ami)

Préparez-vous à coder votre propre compagnon d'exploration martienne !

Objectifs d'apprentissage
-------------------------

* Combiner les capteurs ultrasoniques et infrarouges pour créer un rover suiveur
* Programmer votre Rover Martien pour qu'il suive automatiquement une cible en mouvement

Créer votre Rover suiveur
-------------------------

#. Commencez par :ref:`app_connect`.

#. Maintenant, ouvrez votre projet enregistré de la Leçon 8.

   .. image:: img/8_follow_open.png

#. Enregistrez une copie pour garder votre projet original en sécurité. Cliquez sur « Enregistrer une copie ».

   .. image:: img/8_follow_save_copy.png

#. Donnez à votre nouveau projet un nom amusant comme « Suiveur martien » ou « Rover copain ».

   .. image:: img/8_follow_save_rename.png

#. Supprimez les blocs « avancer » à la fin de chaque événement de capteur. Notre suiveur doit s'arrêter et attendre après chaque action.

   .. image:: img/8_follow_save_remove_forward.png

#. Maintenant, reprogrammons les capteurs IR ! Inversez les directions de rotation pour que le rover tourne VERS la cible au lieu de s'en éloigner.

   .. image:: img/8_follow_save_re_turn.png

#. Enfin, modifiez le comportement du capteur ultrasonique. Au lieu de reculer, faites-le AVANCER lorsqu'il détecte une cible devant lui.

   .. image:: img/8_follow_save_re_ultra.png


Incroyable ! Votre GalaxyRVR est maintenant votre partenaire d'exploration martienne. Testez-le :

- Marchez à côté de lui → il tourne pour vous faire face
- Tenez-vous devant lui → il se dirige vers vous
- Éloignez-vous → il s'arrête et attend

Votre rover copain est prêt à vous suivre dans votre prochaine aventure spatiale !
