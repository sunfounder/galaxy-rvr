.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirte?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

Tira de LEDs RGB de 4 luces
================================

.. image:: img/4_rgb_strip.jpg


* **+5V**: Ánodo común de los tres LEDs que debe conectarse a 5V de CC.
* **B**: Cátodo del LED azul.
* **R**: Cátodo del LED rojo.
* **G**: Cátodo del LED verde.

Esta tira de LEDs RGB cuenta con cuatro LEDs R5050 RGB, capaces de generar cualquier tono de color combinando los tres colores primarios: rojo, azul y verde.

Los LEDs R5050 RGB están diseñados con una configuración de ánodo común. Cada LED en la tira funciona como un circuito independiente, lo que permite cortar la tira en puntos designados sin afectar las demás secciones. La flexibilidad y adaptabilidad de la tira se ven mejoradas por su construcción en una placa FPC, respaldada con adhesivo de doble cara para una fácil instalación.


**¿Qué es un LED R5050 RGB?**

El LED R5050 RGB es un tipo de LED que combina diodos emisores de luz roja, azul y verde en un solo encapsulado. Cada LED dentro de este paquete tiene su propio pin, lo que permite un control individual. Esta configuración permite la producción de una amplia gama de colores variando la intensidad de cada LED.

.. image:: img/rgb_5050.jpg
    :width: 400

.. image:: img/rgb_5050_sche.png
    :width: 200

En una aplicación típica, múltiples LEDs R5050 RGB se organizan en un circuito flexible en una configuración inteligente. Esto se logra conectando los extremos "positivos" (ánodos) de todos los LEDs entre sí, mientras que los extremos "negativos" (cátodos) se conectan a sus respectivos canales de color. Esto significa que todos los cátodos verdes están conectados entre sí, al igual que los cátodos rojos y los cátodos azules. Este arreglo permite un control eficiente de la mezcla de colores y la intensidad de la luz, lo que hace que estos LEDs sean populares en aplicaciones donde se desee iluminación de color personalizable, como en iluminación decorativa, señalización y tecnologías de visualización.

.. image:: img/rgb_strip_sche.png


**Características**

* Voltaje de trabajo: DC5V
* Color: RGB de color completo
* Temperatura de trabajo: -15-50°C
* Tipo de RGB: 5050RGB
* Corriente: 150mA (circuito individual)
* Potencia: 1.5W
* Grosor de la tira de luz: 2mm
* Ancho de la tira de luz: 5.5mm
* Cable: ZH1.5-4P, 25cm, 28AWG, Negro
