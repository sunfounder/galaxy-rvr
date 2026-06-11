.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Module d'évitement d'obstacles IR
=======================================

Il s'agit d'un module d'évitement d'obstacles infrarouge qui peut détecter la présence d'objets devant lui. Il est couramment utilisé dans les robots, les systèmes d'automatisation et autres dispositifs intelligents. Sa portée de détection est de 2 cm à 40 cm, et les objets de différentes couleurs ont des niveaux de réflectivité différents. Ainsi, plus l'objet est sombre, plus la distance de détection est courte.

.. image:: img/ir_avoid.png
    :width: 400
    :align: center

Voici les définitions des broches :

* **GND** : Masse
* **+** : Alimentation, 3,3 ~ 5V CC.
* **Out** : Par défaut, il reste haut et ne passe à bas que lorsqu'il détecte un obstacle.
* **EN** : Cette broche **d'activation** détermine quand le module doit fonctionner. Par défaut, elle est connectée à GND, ce qui signifie que le module est toujours en service.


**Comment ça fonctionne ?**

Ce module contient une paire de composants d'émission et de réception IR. Fondamentalement, l'émetteur émet une lumière infrarouge ; lorsque la lumière infrarouge émise rencontre un obstacle, elle est réfléchie et reçue par le récepteur. Lors de la détection, l'indicateur s'allume. Après traitement par le circuit, il émet un signal de niveau bas.

.. image:: img/ir_receive.png
    :width: 600
    :align: center


L'état de niveau bas de la broche **EN** active le module, le capuchon de cavalier fixant la broche **EN** à GND. Pour contrôler la broche EN par programmation, retirez le capuchon de cavalier.

.. image:: img/ir_cap.png
    :width: 400
    :align: center

Il y a deux potentiomètres sur le module, un pour régler la puissance d'émission et un pour régler la fréquence d'émission ; en ajustant ces deux potentiomètres, vous pouvez régler sa distance effective.

.. image:: img/ir_avoid_pot.png
    :width: 400
    :align: center


**Régler la distance de détection**

La portée de détection du module d'évitement d'obstacles doit être précisément calibrée pour des performances optimales, car les paramètres d'usine par défaut peuvent ne pas correspondre aux exigences spécifiques.

La calibration comprend les étapes suivantes :

#. Alignement du module : Commencez par le module d'évitement d'obstacles du côté droit. Le transport peut parfois déplacer l'alignement de l'émetteur et du récepteur infrarouge du module. Ils doivent être réalignés manuellement pour garantir la précision.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Placez un obstacle à environ 20 cm directement devant le module droit. La boîte dans laquelle notre kit Rover est livré est un bon choix pour cela ! Maintenant, tournez le potentiomètre sur le module jusqu'à ce que le voyant indicateur du module s'allume. Ensuite, continuez à déplacer l'obstacle d'avant en arrière pour vérifier si le voyant s'allume à la distance souhaitée. Si le voyant ne s'allume pas à la bonne distance ou s'il reste allumé sans s'éteindre, vous devrez régler l'autre potentiomètre.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>


#. Répétez le même processus pour l'autre module.

**Caractéristiques**

* tension de fonctionnement : 3,3 V à 5 V
* sortie : numérique (on/off)
* seuil de détection : réglable par 2 potentiomètres
* plage de distance : 2 à 40 cm
* réglage R5 : réglage de fréquence 38 kHz (déjà optimisé)
* réglage R6 : réglage du rapport cyclique de la LED IR (déjà optimisé)
* température de fonctionnement : -10 °C à +50 °C
* angle effectif : 35°
* interface E/S : interface 4 fils (- / + / S / EN)
* dimensions : 45 x 16 x 10 mm
* poids : 9 g
