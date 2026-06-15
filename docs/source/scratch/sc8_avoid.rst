.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Lección 8: Evitación avanzada de obstáculos
==================================================

¿Alguna vez te has preguntado cómo los robots pueden navegar por las habitaciones sin chocar con los muebles? Hoy, vamos a enseñarle a nuestro Mars Rover a hacer precisamente eso. Combinaremos dos tipos diferentes de sensores para crear un sistema de evitación de obstáculos súper inteligente.

Cómo los sensores ayudan a los robots a "ver"
------------------------------------------------

Pensemos en cómo usamos nuestros sentidos:

* **Sensores infrarrojos** ¡Funcionan como los murciélagos usando ecolocalización! Emiten luz infrarroja invisible y escuchan su rebote en los objetos. Si la luz regresa rápidamente, hay un obstáculo cerca.

* **Sensores ultrasónicos** Funcionan con ondas sonoras que no podemos oír. Emiten sonido de alta frecuencia y miden cuánto tarda en regresar el eco. Un tiempo más largo significa que el objeto está más lejos.

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Tu navegador no soporta la etiqueta de video.
    </video>

Cuando usamos ambos sensores juntos, nuestro Rover obtiene una comprensión mucho mejor de su entorno, igual que usando tanto los ojos como los oídos para navegar en una habitación oscura.

Objetivos de aprendizaje
-------------------------

* Combinar sensores ultrasónicos e infrarrojos para crear un sistema avanzado de evitación de obstáculos
* Programar tu Mars Rover para detectar y sortear obstáculos automáticamente

Construyendo nuestro Rover súper inteligente
-----------------------------------------------------------

Recuerda el programa de evitación de obstáculos que creamos antes. Lo usaremos como punto de partida y lo mejoraremos aún más.

#. Primero, :ref:`app_connect`.

#. Ahora, abramos nuestro proyecto anterior de sensor infrarrojo de :ref:`ir_obstacle` como plantilla. Haz clic en "Archivo" y encuentra tu proyecto guardado de evitación de obstáculos por infrarrojos.

   .. image:: img/7_avoid_open.png

#. Antes de hacer cambios, guardemos una copia para no perder nuestro trabajo original. Haz clic en "Guardar una copia".

   .. image:: img/7_avoid_save_copy.png

#. Dale a tu nuevo proyecto un nombre genial como "Rover Súper Inteligente" o "Evitación Avanzada de Obstáculos".

   .. image:: img/7_avoid_save_rename.png

#. ¡Ahora agreguemos nuestro sensor ultrasónico! Arrastra el bloque ``when distance < 15 cm``. Este será nuestro "sistema de alerta temprana" que detecta obstáculos desde más lejos.

   .. image:: img/7_avoid_when.png
       :width: 800

#. Para evitar confusiones, agregaremos un bloque ``stop other scripts in sprite``. Esto asegura que nuestro Rover siga solo un conjunto de instrucciones a la vez.

   .. image:: img/7_avoid_stop.png

#. Cuando el sensor ultrasónico detecte algo cerca, queremos que nuestro Rover retroceda hasta una distancia segura.

   .. image:: img/7_avoid_backward.png

#. Ahora necesitamos girar para alejarnos del obstáculo. El Rover girará durante un segundo; ¡puedes elegir giro a la izquierda o a la derecha!

   .. image:: img/7_avoid_turn.png

#. Finalmente, le decimos al Rover que continúe avanzando en su nuevo camino.

   .. image:: img/7_avoid_go.png

¡Increíble! Ahora tienes un Rover que usa tres sensores trabajando juntos como un equipo:

- El sensor ultrasónico frontal detecta obstáculos lejanos
- El sensor IR izquierdo detecta objetos en el lado izquierdo
- El sensor IR derecho vigila el lado derecho

Prueba tu programa y observa con qué suavidad tu Rover navega alrededor de los obstáculos. ¡Intenta crear una pista de obstáculos y mira si tu Rover puede completarla sin chocar!

Desafío: ¿Puedes modificar el tiempo de giro o la distancia para que tu Rover sea aún mejor evitando obstáculos?
