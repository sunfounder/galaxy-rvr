.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lección 9: Tiras de LEDs RGB
============================================================

En nuestro viaje hasta ahora, hemos transformado nuestro Mars Rover en un explorador inteligente, capaz de maniobrar hábilmente alrededor de obstáculos. Se ha vuelto bastante hábil navegando por los terrenos similares a Marte que hemos preparado para él.

Pero, ¿qué tal si añadimos un poco de estilo a su funcionalidad? Démosle a nuestro Rover la capacidad de expresarse a través de un espectáculo de colores y luz. Estamos hablando de incorporar tiras de LED RGB - una característica genial que permitiría a nuestro Rover iluminar su camino, incluso en las condiciones más oscuras.

Imagínate esto - el Rover deja un rastro de señales codificadas por colores, facilitándonos la comprensión de sus movimientos. Un brillo verde cuando está en marcha, un rojo intenso cuando se detiene, o un amarillo destellante durante esos giros rápidos. ¡Incluso podría iluminarse en una variedad de colores solo por pura diversión!

Nuestro objetivo en esta lección es comprender los principios de las tiras de LED RGB, aprender a controlar su color y brillo, y luego sincronizar esto con los movimientos del Rover. Al final, nuestro Mars Rover será más que una máquina. Será una entidad luminosa y cambiante de color, ¡abriendo camino en el vasto paisaje marciano!

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/car_rgb.mp4" type="video/mp4">
        Tu navegador no soporta la etiqueta de video.
    </video>

.. note::

    Si estás aprendiendo este curso después de haber ensamblado completamente el GalaxyRVR, debes mover este interruptor hacia la derecha antes de cargar el código.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Objetivo
-------------

* Comprender los principios de funcionamiento y las aplicaciones de las tiras de LED RGB.
* Aprender a usar la programación de Arduino para controlar el color y el brillo de las tiras de LED RGB.
* Practicar la instalación y el uso de tiras de LED RGB en el modelo Mars Rover como indicadores.

Materiales Necesarios
-------------------------

* Tiras de LED RGB (cada tira tiene 8 LEDs RGB, un total de dos tiras)
* Herramientas y accesorios básicos (por ejemplo, destornillador, tornillos, cables, etc.)
* Modelo Mars Rover (Equipado con sistema rocker-bogie, placas principales, motores, módulo de evitación de obstáculos, módulo ultrasónico)
* Cable USB
* Arduino IDE
* Computadora

Pasos del Curso
------------------
**Paso 1: Instalar las Tiras de LED RGB en el Mars Rover**

Ahora, fija las dos tiras de luz RGB a los lados inferiores del coche. Están controladas por un solo conjunto de pines, por lo que no es necesario diferenciarlas durante el proceso de cableado.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/v4YGjNwPOJE" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**Paso 2: Explorar la Magia de la Luz con las Tiras de LED RGB**

¿Recuerdas la última vez que viste un arcoíris? ¿Cómo coloreó el cielo con siete tonos vibrantes? ¿Te gustaría crear tu propio arcoíris, aquí mismo, en nuestro pequeño rover marciano? ¡Sumergámonos en la magia de la luz con las tiras de LED RGB!

.. image:: img/4_rgb_strip.jpg

Puedes notar que nuestra tira de LED RGB tiene cuatro pines etiquetados de la siguiente manera:

* **+5V**: Este es el extremo "positivo" común o el "ánodo" de las tres pequeñas bombillas (LEDs) dentro de nuestra tira. Necesita conectarse a DC 5V, una especie de jugo eléctrico que alimenta nuestras pequeñas bombillas.
* **B**: Este es el extremo "negativo" o el "cátodo" del LED azul.
* **R**: Este es el "cátodo" del LED rojo.
* **G**: Este es el "cátodo" del LED verde.

.. image:: img/rgb_5050.jpg

¿Recuerdas los tres colores primarios - Rojo, Azul y Verde - que aprendimos en nuestra clase de arte? Así como un artista mezcla estos colores en su paleta para crear nuevos tonos, nuestra tira contiene 4 LEDs "5050" que pueden mezclar estos colores primarios para crear prácticamente cualquier color. ¡Cada LED "5050" es como un pequeño estudio de arte que alberga estas tres bombillas de colores!

.. image:: img/rgb_5050_sche.png

Estos pequeños estudios de arte están conectados de manera inteligente en un circuito flexible, ¡como una mini autopista eléctrica! Los extremos "positivos" de todos los LEDs (ánodos) están conectados entre sí, mientras que los extremos "negativos" (cátodos) están conectados a sus carriles de color correspondientes (G a G, R a R, B a B).

.. image:: img/rgb_strip_sche.png

¿Y la parte más genial? ¡Con nuestro comando, todos los LEDs de esta tira pueden cambiar sus colores a la vez! ¡Es como tener nuestra propia orquesta de luz al alcance de los dedos!

Así que preparémonos para tocar música de luz. En nuestro próximo paso, aprenderemos a controlar estos LEDs para mostrar los colores que queramos. ¡Será como dirigir una sinfonía de luz!


**Paso 3: Iluminar el Espectáculo - Programación para Controlar las Tiras de LED RGB**

Hemos entrado en el reino de los colores, es hora de dar vida a nuestro Mars Rover. Prepárate para pintar la oscuridad con un espectro de colores usando las tiras de LED RGB. ¡Piensa en esto como una oportunidad para transformar tu Mars Rover en una fiesta disco móvil!

* Antes de sumergirnos en la parte divertida, comprendamos que aunque tenemos dos tiras de LED, ambas están controladas por el mismo conjunto de pines. ¡Piensa en ello como tener dos bailarines deslumbrantes moviéndose en perfecta sincronización!

    .. image:: img/rgb_shield.png

* Es hora de invocar nuestra magia de programación. Vamos a inicializar nuestros pines con el código de Arduino.

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Define the pin numbers for the RGB strips
        const int bluePin = 11;
        const int redPin = 12;
        const int greenPin = 13;

* Con nuestros pines en su lugar, ahora usaremos la función ``SoftPWMSet()`` para controlar estos pines. Para hacer que la tira RGB muestre color rojo, encendemos el LED rojo y apagamos los demás.

    .. code-block:: arduino

        void setup() {
            // Initialize software-based PWM on all pins
            SoftPWMBegin();
        }

        void loop() {
            // Set the color to red by turning the red LED on and the others off
            SoftPWMSet(redPin, 255); // 255 is the maximum brightness
            SoftPWMSet(greenPin, 0); // 0 is off
            SoftPWMSet(bluePin, 0);  // 0 is off
            delay(1000); // Wait for 1 second
        }

En el código anterior, solo hemos demostrado cómo mostrar un único color.

Si mostráramos una variedad de colores usando este método, el código podría volverse bastante engorroso. Por lo tanto, para hacer nuestro código más conciso y mantenible, podemos crear una función para asignar valores PWM a los tres pines. Luego, dentro del ``loop()``, podemos establecer fácilmente una multitud de colores.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cac90501-04c1-44c2-a1d7-4f863e50f186/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Después de cargar el código en tu placa R3, puedes notar que los colores naranja y amarillo se ven un poco apagados.
Esto se debe a que el LED rojo en la tira es relativamente tenue en comparación con los otros dos LEDs.
Por lo tanto, necesitarás introducir valores de compensación en tu código para corregir esta discrepancia de color.

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/60ec867f-5637-44bd-b72d-4709fc4f5349/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Ahora, la tira de LED RGB debería poder mostrar los colores correctos. Si aún notas discrepancias, puedes ajustar manualmente los valores de ``R_OFFSET``, ``G_OFFSET`` y ``B_OFFSET``.

Siéntete libre de experimentar y mostrar cualquier color de tu elección en la tira de LED. Todo lo que necesitas hacer es completar los valores RGB para el color que desees.

Aquí tienes un consejo: puedes usar la herramienta Paint de tu computadora para determinar los valores RGB de tu color deseado.

.. image:: img/rgb_paint.png

Ahora que hemos dominado el arte de establecer colores, en el próximo paso integraremos estos deslumbrantes efectos de color con los movimientos del Mars Rover. ¡Tiempos emocionantes por delante!

**Paso 4: Mover el Rover con Indicación de Color**

Ahora, añadiremos indicaciones de color a los movimientos del Mars Rover. Por ejemplo, podemos usar verde para avanzar, rojo para retroceder y amarillo para girar a la izquierda o a la derecha.

Para hacer esto, añadiremos un mecanismo de control en nuestro código que establece el color de la tira de LED según el movimiento del Rover. Esto implicará modificar nuestro código de control del Rover para incluir nuestras funciones de control de color.

Veamos un ejemplo de cómo podemos hacer esto:

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/5412eebe-75b8-4f98-a348-f0889e8a7fde/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Dentro de la función ``loop()``, ordenamos al Rover realizar una serie de acciones llamando a diferentes funciones.
Cada acción tenía su correspondiente color de indicación - verde para avanzar, rojo para retroceder y amarillo para girar.
Esta función de indicación de color se hizo realidad mediante la función ``setColor()``, que manipulaba el brillo de
cada canal de color RGB.

Para la acción de detenerse, introdujimos un elemento atractivo - un efecto de respiración con luz roja y azul.
Esto se logró ajustando cíclicamente el brillo de los canales rojo y azul dentro de la función ``stopMove()``.
De esta manera, al detenerse, la tira de LED hacía una transición de colores entre rojo y azul, creando un efecto visual dinámico.

Ahora, nuestro Mars Rover posee sus propios efectos de color vibrantes, dejando un rastro de señales codificadas por colores, cada una representando un
movimiento único.

A través de este proyecto, hemos descubierto cómo las materias STEAM pueden amalgamarse para dar vida a una
máquina que de otro modo sería ordinaria, convirtiéndola en una herramienta de aprendizaje vibrante, interactiva y divertida.


**Paso 5: Resumen y Reflexión**

En la lección de hoy, nos adentramos en el mundo de las tiras de LED RGB, explorando cómo manipularlas para mostrar una vívida gama de colores. Estos brillantes matices dieron nueva vida a nuestro Mars Rover, transformándolo de una mera máquina en un espectáculo vibrante.

Ahora, te invito a reflexionar - Si estuvieras en el asiento del conductor, ¿cómo utilizarías estos colores para mejorar tu Mars Rover? ¿Qué efectos únicos te gustaría que exhibiera?

Además, a través del proceso, espero que hayas comprendido de manera práctica cómo diversos conceptos STEAM pueden entrelazarse en un proyecto atractivo, brindándote una perspectiva más amplia de sus aplicaciones prácticas.

¡Nos vemos en nuestra próxima aventura emocionante!
