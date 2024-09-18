.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirte?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Previsualizaciones exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

Lección 2: Comprendiendo y Construyendo el Sistema Rocker-Bogie
==================================================================
En nuestra lección anterior, aprendimos sobre los rovers de Marte y su estructura 
básica. Un aspecto interesante que notamos al observar la evolución de los rovers 
de Marte es la consistencia en su sistema de suspensión. A pesar de los avances 
tecnológicos, todos los rovers, desde Sojourner hasta Perseverance, han sido diseñados 
utilizando un tipo de sistema de suspensión similar conocido como el sistema Rocker-Bogie.

Pero, ¿por qué seguir usando el sistema Rocker-Bogie, te preguntarás? ¿Qué beneficios ofrece este diseño particular para la exploración de Marte?

.. image:: img/rocker_bogie_pic.webp

En la lección de hoy, profundizaremos en la ciencia e ingeniería detrás del sistema 
Rocker-Bogie y luego construiremos uno.

¡Vamos a embarcarnos en este emocionante viaje de ingeniería!

Objetivos de aprendizaje
---------------------------

* Comprender el principio de diseño del sistema de suspensión Rocker-Bogie y sus ventajas.
* Aprender a diseñar y construir un modelo básico del sistema de suspensión Rocker-Bogie.
* Aplicar principios básicos de física para explicar cómo el sistema Rocker-Bogie supera terrenos complejos.

Materiales
------------

* Planos y materiales de referencia (como diseños de los rovers de Marte de la NASA y videos sobre el funcionamiento del sistema Rocker-Bogie).
* Kit de estructura del rover de Marte.
* Herramientas y accesorios básicos (por ejemplo, destornillador, tornillos, etc.).

Pasos
-------

**Paso 1: Desentrañando el Sistema Rocker-Bogie**

El sistema Rocker-Bogie es como una cabra montesa de la mecánica, diseñado para mantener todas las ruedas del rover en contacto con el suelo mientras navega por terrenos accidentados y rocosos. Está especialmente construido para manejar el impredecible paisaje de Marte, incluidas pendientes pronunciadas y grandes rocas. Este sistema prescinde de los resortes y, en su lugar, aprovecha la geometría de sus seis ruedas y sus interacciones para conquistar terrenos difíciles. Es un brillante ejemplo de cómo un diseño mecánico inteligente puede superar obstáculos ambientales.

Vamos a sumergirnos en las dos partes principales de este sistema: el "rocker" y el "bogie".

.. image:: img/rocker_bogie.png

* La parte "rocker" del sistema es como los dos grandes brazos a cada lado del cuerpo del rover. Estos brazos, o rockers, están conectados entre sí y al cuerpo del rover, o chasis, a través de un mecanismo llamado diferencial. Al igual que dos piernas caminando, los rockers rotan en direcciones opuestas en relación con el chasis, asegurando que la mayoría de las ruedas mantengan contacto con el suelo. El cuerpo del rover mantiene el ángulo promedio de ambos rockers. Un extremo del rocker se conecta a una rueda, mientras que el otro extremo se conecta al bogie.

* La parte "bogie" del sistema es como una criatura de extremidades pequeñas conectada al rocker. Es un sistema de enlaces más pequeño que pivota en el medio hacia el rocker y tiene una rueda en cada extremo.

Con este entendimiento básico, vamos al siguiente paso de nuestra aventura.


**Paso 2: Ver el Sistema en Acción**

A continuación, un GIF que muestra las características únicas del sistema de suspensión Rocker-Bogie e ilustra cómo permite a los rovers de Marte navegar por el desafiante terreno marciano.

.. image:: img/rocker_bogie.gif
    :align: center

Después de ver el GIF, tengamos una discusión. Reflexiona sobre estas preguntas:

* ¿Por qué crees que el sistema de suspensión Rocker-Bogie es adecuado para la exploración de Marte?
* ¿Puedes describir cómo funciona el sistema Rocker-Bogie con tus propias palabras?
* ¿Cuáles son las características clave del sistema Rocker-Bogie que ayudan a los rovers a atravesar terrenos difíciles?

No dudes en compartir tus ideas y perspectivas sobre el sistema de suspensión Rocker-Bogie.

**Paso 3: Construyéndolo**

Ahora que hemos aprendido sobre el sistema Rocker-Bogie, es hora de construir el nuestro.

Materiales que necesitas:

* Kit GalaxyRVR.
* Herramientas básicas como destornillador y llave inglesa.
* Sigue los pasos proporcionados en las instrucciones de ensamblaje del kit GalaxyRVR para construir el sistema de suspensión del rover.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/a1xtgDUEvR0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Ten en cuenta que la paciencia y la precisión son esenciales aquí, asegúrate de colocar correctamente cada pieza y asegurarlas firmemente.

Mientras tanto, discute con tus compañeros sobre el diseño y la función de cada 
componente que estás ensamblando. Esto no solo te ayudará a entender el diseño, 
sino también su aplicación práctica en la exploración de Marte.

Recuerda, no te preocupes si encuentras algún problema durante el ensamblaje o 
las pruebas. Esto es parte del proceso de ingeniería. Resolver problemas es cómo 
aprendemos e innovamos.

**Paso 4: Resumen y Reflexión**

Durante el ensamblaje del sistema de suspensión, ¿notaste que todas las partes móviles utilizan tuercas autoblocantes? ¿Te has preguntado por qué?

.. image:: img/self_locking_nuts.webp
    :align: center

Las tuercas autoblocantes son un tipo de sujetador que incluye un anillo de goma dentro de una tuerca normal. Este diseño asegura que las partes ensambladas no se aflojen fácilmente debido a las vibraciones durante el movimiento.

Además, garantiza que las piezas puedan girar dentro de un rango determinado.

Por lo tanto, durante el ensamblaje, primero debes apretar el tornillo y la tuerca autoblocante con un zócalo y un destornillador, y luego aflojarlo un poco. Esto asegura que haya espacio para la rotación libre entre las piezas sin que estén demasiado sueltas.

.. raw:: html

   <video width="600" loop autoplay muted>
        <source src="_static/video/rocker_bogie_system.mp4" type="video/mp4">
        Your browser does not support the video tag.
   </video>

En esta lección, no solo aprendimos sobre el sistema Rocker-Bogie, sino que también construimos uno nosotros mismos. Además, podemos simular manualmente cómo permite que el rover de Marte se desplace suavemente sobre varios terrenos accidentados.

Con este conocimiento y experiencia, ahora estamos mejor equipados para aventurarnos más profundamente en los reinos desconocidos de la exploración marciana. Sigamos desentrañando los misterios del planeta rojo.
