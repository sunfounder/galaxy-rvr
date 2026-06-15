.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lección 9: Compañero de Exploración en Marte
====================================================

Ahora que nuestro Rover puede esquivar obstáculos con habilidad, enseñémosle un nuevo truco: ¡seguir un objetivo! En esta misión, transformaremos nuestro rover evasor de obstáculos en un compañero leal que pueda seguirte a donde vayas.

¿Cuál es la diferencia entre seguir y esquivar?

- **Esquivar**: Alejarse de objetos (como esquivar rocas)
- **Seguir**: Moverse hacia objetos (como seguir a un amigo)

¡Prepárate para programar tu propio compañero de exploración marciana!

Objetivos de Aprendizaje
-------------------------

* Combinar sensores ultrasónicos e infrarrojos para crear un rover seguidor
* Programar tu Mars Rover para que rastree y siga automáticamente un objetivo en movimiento

Creando Tu Rover Seguidor
-------------------------------------------------------

#. Primero, :ref:`app_connect`.

#. Ahora, abre tu proyecto guardado de la Lección 8.

   .. image:: img/8_follow_open.png

#. Guarda una copia para mantener tu proyecto original a salvo. Haz clic en "Guardar como copia".

   .. image:: img/8_follow_save_copy.png

#. Dale a tu nuevo proyecto un nombre divertido como "Mars Follower" o "Rover Buddy".

   .. image:: img/8_follow_save_rename.png

#. Elimina los bloques de "avanzar" del final de cada evento de sensor. Nuestro seguidor debe detenerse y esperar después de cada acción.

   .. image:: img/8_follow_save_remove_forward.png

#. ¡Ahora reprogramemos los sensores IR! Cambia las direcciones de giro para que el rover gire HACIA el objetivo en lugar de alejarse de él.

   .. image:: img/8_follow_save_re_turn.png

#. Finalmente, actualiza el comportamiento del sensor ultrasónico. En lugar de retroceder, haz que se mueva HACIA ADELANTE cuando detecte un objetivo al frente.

   .. image:: img/8_follow_save_re_ultra.png


¡Increíble! Tu GalaxyRVR es ahora tu compañero de exploración marciana. Pruébalo:

- Camina a su lado —gira para mirarte
- Colócate al frente —se mueve hacia ti
- Aléjate —se detiene y espera

¡Tu rover compañero está listo para seguirte en tu próxima aventura espacial!
