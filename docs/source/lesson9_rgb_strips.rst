.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirte?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy!

Lección 9: Iluminando el Camino con Tiras de LED RGB
========================================================

En nuestro viaje hasta ahora, hemos convertido nuestro Rover Marciano en un explorador inteligente, capaz de maniobrar hábilmente alrededor de obstáculos. Se ha vuelto bastante competente en navegar por los terrenos simulados de Marte que hemos preparado para él.

Pero, ¿qué tal si agregamos un toque de estilo a su funcionalidad? Vamos a darle a nuestro Rover la capacidad de expresarse a través de un espectáculo de colores y luces. Hablamos de incorporar tiras de LED RGB, una función genial que permitirá a nuestro Rover iluminar su camino, incluso en las condiciones más oscuras.

Imagínalo: el Rover dejando un rastro de señales codificadas por colores, facilitándonos entender sus movimientos. Un brillo verde cuando avanza, un rojo intenso cuando se detiene, o un amarillo llamativo durante esos giros rápidos. ¡Incluso podría iluminarse en una variedad de colores solo por diversión!

Nuestro objetivo en esta lección es comprender los principios de las tiras de LED RGB, aprender a controlar su color y brillo, y luego sincronizarlos con los movimientos del Rover. Al final, nuestro Rover Marciano será más que una máquina: ¡será una entidad luminosa y cambiante que liderará el camino en el vasto paisaje marciano!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/car_rgb.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::

    Si estás siguiendo este curso después de haber ensamblado completamente el GalaxyRVR, debes mover este interruptor hacia la derecha antes de cargar el código.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Objetivo
-------------

* Comprender los principios de funcionamiento y aplicaciones de las tiras de LED RGB.
* Aprender a usar programación en Arduino para controlar el color y el brillo de las tiras de LED RGB.
* Practicar la instalación y el uso de tiras de LED RGB en el modelo del Rover Marciano como indicadores.

Materiales Necesarios
---------------------

* Tiras de LED RGB (cada tira tiene 8 LEDs RGB, en total dos tiras)
* Herramientas y accesorios básicos (por ejemplo, destornillador, tornillos, cables, etc.)
* Modelo del Rover Marciano (equipado con sistema rocker-bogie, placas base, motores, módulo de evasión de obstáculos, módulo ultrasónico)
* Cable USB
* Arduino IDE
* Computadora


Pasos del Curso
-------------------

**Paso 1: Instalar las Tiras de LED RGB en el Rover Marciano**

Ahora, fija las dos tiras de luz RGB en los lados inferiores del coche. Ambas se controlan mediante un solo conjunto de pines, por lo que no es necesario diferenciarlas durante el proceso de cableado.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/v4YGjNwPOJE" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Paso 2: Explora la Magia de la Luz con las Tiras de LED RGB**

¿Recuerdas la última vez que viste un arco iris? ¿Cómo llenaba el cielo de siete colores vibrantes? ¿Qué te parece crear tu propio arco iris aquí mismo en nuestro pequeño Rover marciano? Vamos a sumergirnos en la magia de la luz con las tiras de LED RGB.

.. image:: img/4_rgb_strip.jpg

Puede que notes que nuestra tira de LED RGB tiene cuatro pines etiquetados de la siguiente manera:

* **+5V**: Este es el extremo "positivo" o el "ánodo" de las tres pequeñas bombillas (LEDs) dentro de nuestra tira. Debe conectarse a DC 5V, una especie de energía que alimenta nuestras diminutas bombillas.
* **B**: Este es el extremo "negativo" o "cátodo" del LED azul.
* **R**: Este es el cátodo del LED rojo.
* **G**: Este es el cátodo del LED verde.

.. image:: img/rgb_5050.jpg

¿Recuerdas los tres colores primarios: rojo, azul y verde, que aprendimos en clase de arte? Al igual que un artista mezcla estos colores en su paleta para crear nuevos tonos, nuestra tira contiene LEDs "5050" que pueden mezclar estos colores primarios para crear prácticamente cualquier color. ¡Cada LED "5050" es como un pequeño estudio de arte que alberga estas tres bombillas de colores!

.. image:: img/rgb_5050_sche.png

Estos pequeños estudios de arte están conectados de manera inteligente en una placa de circuito flexible, algo así como una mini autopista eléctrica. Los extremos positivos de todos los LEDs (ánodos) están conectados entre sí, mientras que los extremos negativos (cátodos) están conectados a sus correspondientes líneas de color (G a G, R a R, B a B).

.. image:: img/rgb_strip_sche.png

¿Y la parte más genial? ¡Con nuestro comando, todos los LEDs en esta tira pueden cambiar de color a la vez! Es como tener nuestra propia orquesta de luces al alcance de nuestros dedos.

Así que prepárate para tocar un poco de música luminosa. En nuestro próximo paso, aprenderemos a controlar estos LEDs para mostrar los colores que queremos. ¡Será como dirigir una sinfonía de luz!


**Paso 3: Ilumina el Espectáculo - Codificación para Controlar las Tiras de LED RGB**

Hemos entrado en el reino de los colores, y es hora de darle vida a nuestro Rover Marciano. Prepárate para pintar la oscuridad con un espectro de colores usando tiras de LED RGB. ¡Es como transformar tu Rover en una fiesta móvil de luces!

* Antes de sumergirnos en la diversión, entendamos que aunque tenemos dos tiras de LED, ambas están controladas por el mismo conjunto de pines. Piensa en ello como dos bailarines deslumbrantes moviéndose en perfecta sincronización.

    .. image:: img/rgb_shield.png

* Es hora de invocar nuestra magia de codificación. Vamos a iniciar nuestros pines con el código de Arduino.

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Definir los pines para las tiras de LED RGB
        const int bluePin = 11;
        const int redPin = 12;
        const int greenPin = 13;

* Con nuestros pines en su lugar, ahora utilizaremos la función ``SoftPWMSet()`` para controlar estos pines. Para hacer que la tira RGB muestre rojo, encendemos el LED rojo y apagamos los otros.

    .. code-block:: arduino

        void setup() {
            // Iniciar PWM basado en software en todos los pines
            SoftPWMBegin();
        }

        void loop() {
            // Configurar el color a rojo encendiendo el LED rojo y apagando los otros
            SoftPWMSet(redPin, 255); // 255 es el brillo máximo
            SoftPWMSet(greenPin, 0); // 0 es apagado
            SoftPWMSet(bluePin, 0);  // 0 es apagado
            delay(1000); // Esperar 1 segundo
        }

En el código anterior, solo hemos demostrado cómo mostrar un solo color. 

Si quisiéramos mostrar una variedad de colores usando este método, el código podría volverse bastante engorroso. Por lo tanto, para hacer nuestro código más conciso y fácil de mantener, podemos crear una función para asignar valores PWM a los tres pines. Luego, dentro de ``loop()``, podemos establecer fácilmente una multitud de colores.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cac90501-04c1-44c2-a1d7-4f863e50f186/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de cargar el código en tu placa R3, es posible que descubras que los colores 
naranja y amarillo no se ven del todo correctos. Esto se debe a que el LED rojo en la 
tira es relativamente tenue en comparación con los otros dos LEDs. Por lo tanto, 
necesitarás introducir valores de compensación en tu código para corregir esta discrepancia de color.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/60ec867f-5637-44bd-b72d-4709fc4f5349/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Ahora, la tira de LED RGB debería ser capaz de mostrar los colores correctos. Si aún notas discrepancias, puedes ajustar manualmente los valores de ``R_OFFSET``, ``G_OFFSET`` y ``B_OFFSET``.

Siéntete libre de experimentar y mostrar cualquier color que desees en la tira de LED. Todo lo que necesitas hacer es ingresar los valores RGB del color que quieres.

Aquí tienes un consejo: Puedes usar la herramienta Paint en tu computadora para determinar los valores RGB del color que desees.

.. image:: img/rgb_paint.png

Ahora que hemos dominado el arte de configurar los colores, en el próximo paso, integraremos estas deslumbrantes pantallas con los movimientos del Rover Marciano. ¡Tiempos emocionantes por delante!

**Paso 4: Mueve el Rover con Indicación de Color**

Ahora, agregaremos indicaciones de color a los movimientos del Rover Marciano. Por ejemplo, podemos usar verde para avanzar, rojo para retroceder y amarillo para girar a la izquierda o a la derecha.

Para hacerlo, añadiremos un mecanismo de control en nuestro código que configure el color de la tira de LED en función del movimiento del Rover. Esto implicará modificar nuestro código de control del Rover para incluir nuestras funciones de control de color.

Veamos un ejemplo de cómo podemos hacer esto:

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/5412eebe-75b8-4f98-a348-f0889e8a7fde/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dentro de la función ``loop()``, ordenamos al Rover realizar una serie de 
acciones llamando a diferentes funciones. Cada acción tenía su correspondiente 
pantalla de color: verde para avanzar, rojo para retroceder y amarillo para girar. 
Esta función de visualización de colores cobró vida mediante la función ``setColor()``, 
que manipulaba el brillo de cada canal de color RGB.

Para la acción de detenerse, introdujimos un elemento interactivo: un efecto de 
respiración con luz roja y azul. Esto se logró ajustando cíclicamente el brillo 
de los canales rojo y azul dentro de la función ``stopMove()``. Así, al detenerse, 
la tira de LED transicionaba entre rojo y azul, creando un efecto visual dinámico.

Ahora, nuestro Rover Marciano posee sus propios efectos de color vibrantes, dejando 
tras de sí un rastro de señales codificadas por colores, cada una representando un 
movimiento único.

A través de este proyecto, descubrimos cómo las materias STEAM pueden combinarse 
para dar vida a una máquina ordinaria, convirtiéndola en una herramienta de aprendizaje 
vibrante, interactiva y divertida.


**Paso 5: Resumen y Reflexión**

En la lección de hoy, nos adentramos en el mundo de las tiras de LED RGB, explorando cómo manipularlas para mostrar una vívida gama de colores. Estos brillantes tonos dieron nueva vida a nuestro Rover Marciano, transformándolo de una simple máquina a un espectáculo luminoso.

Ahora te invito a reflexionar: si estuvieras en el asiento del conductor, ¿cómo utilizarías estos colores para mejorar tu Rover Marciano? ¿Qué efectos únicos te gustaría que exhibiera?

Además, espero que a través de este proceso hayas adquirido una comprensión práctica de cómo los diversos conceptos STEAM pueden entrelazarse en un proyecto atractivo, proporcionándote una perspectiva más amplia de sus aplicaciones prácticas.

¡Nos vemos en nuestra próxima emocionante aventura!

