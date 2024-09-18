.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

Lección 2 Comenzando con la APP de Mammoth Coding
======================================================

¡Vamos a sumergirnos en el mundo de Mammoth Coding y crear tu primer proyecto! 
Para una experiencia óptima, se recomienda usar un dispositivo con pantalla grande.






Objetivos de aprendizaje
-------------------------------

* Comprender el entorno de programación de la APP y las operaciones básicas.
* Aprender a programar eventos en sprites, usar la bandera verde, repetir, deslizar y cambiar disfraces.
* Crear una animación simple que simule un rover de Marte.

Materiales
--------------

* Teléfono inteligente o tableta
* APP de Mammoth Coding

Instalación de la APP de Mammoth Coding
--------------------------------------------

Primero, busca Mammoth Coding en Google Play o la Apple Store y descárgala.

.. image:: img/mammoth_download.jpg
    :align: center

Entendiendo la interfaz de la APP de Mammoth Coding
------------------------------------------------------------

Mammoth Coding está diseñada para ser divertida, educativa y fácil de aprender. 
Proporciona herramientas para crear historias interactivas, juegos, arte, 
simulaciones y más usando programación basada en bloques. 
También incluye su propio editor de dibujo y de sonido.

Así se ve la interfaz:

.. image:: img/2_app_ui_001.png
    :align: center

Para dispositivos con pantallas más pequeñas, la interfaz se ve así:

.. image:: img/2_app_ui_002.png
    :align: center


**Sección superior**

La sección superior de Mammoth Coding incluye varias opciones básicas.

.. image:: img/2_app_ui_1.png
    :align: center

* La primera opción a la izquierda es la configuración de idioma, que te permite elegir diferentes lenguajes de programación.
* La segunda opción es el menú de archivos, donde puedes crear nuevos archivos, cargar archivos locales y guardar el archivo actual.
* La tercera opción es para renombrar tu proyecto.

**Navegación**

Justo debajo de la sección superior está la barra de navegación, 
que te permite cambiar entre las páginas de Código, Disfraces 
y Sonidos.

.. image:: img/2_app_ui_3.png
    :align: center

En pantallas más pequeñas, la barra de navegación aparece en la parte superior.

.. image:: img/2_app_ui_2.png
    :align: center

Las opciones son Código, Disfraces, Sonidos y Escenario. 
La página de Escenario está en el lado derecho de la interfaz en pantallas grandes, 
y se separa en dispositivos más pequeños para evitar el desorden.

.. image:: img/2_app_ui_4.png
    :align: center

**Código**

.. image:: img/2_app_ui_code.png
    :align: center

La página de Código (y Escenario) es donde se llevarán a cabo la mayoría 
de tus actividades de programación.

**Disfraces**

.. image:: img/2_app_ui_custom.png
    :align: center

La página de Disfraces se usa para editar sprites y fondos, 
proporcionando elementos visuales para tus programas.

**Sonidos**

.. image:: img/2_app_ui_sound.png
    :align: center

La página de Sonidos maneja el audio, proporcionando elementos multimedia para tus programas.

Primer uso de la APP de Mammoth Coding
------------------------------------------------

Arrastra un bloque al área central.

.. image:: img/2_drag.png
    :align: center

Haz clic en el bloque y observa qué sucede.

.. image:: img/2_click.png
    :align: center

Verás que el sprite en el centro del escenario se mueve un poco. 
Si sigues haciendo clic en el bloque, continuará moviéndose.

.. image:: img/2_show.png
    :align: center

Observa cómo las formas de estos bloques sugieren que pueden conectarse, 
similar a los ladrillos LEGO. Cuando conectas los bloques, 
el sprite en el escenario ejecutará los bloques de código conectados en secuencia 
(por ejemplo, moverse y luego girar).

.. image:: img/2_click2.png
    :align: center

.. note:: Este es el proceso básico de programación en la APP. Arrastra bloques desde el área izquierda, conéctalos entre sí y haz clic en ellos para que el sprite en el escenario realice acciones.

**Eligiendo un sprite**

En la esquina inferior derecha de la interfaz, 
encontrarás el botón "elegir un sprite". Tócalo para ver cuatro opciones emergentes.

.. image:: img/2_create_sp.png
    :align: center

En pantallas más pequeñas, debes navegar para ver este botón.

.. image:: img/2_create_sp0.png
    :align: center

Las cuatro opciones son:

* **Cargar Sprite**: Cargar un sprite desde el almacenamiento de tu dispositivo.
* **Sorpresa**: Selecciona un sprite aleatorio de la biblioteca de recursos.
* **Pintar**: Dibuja un sprite.
* **Elegir un Sprite**: Abre la biblioteca de recursos para elegir un sprite.

Toca "elegir un sprite" para ingresar a la biblioteca de recursos, que proporciona una variedad de materiales para tu escenario.

.. image:: img/2_sp_list.png
    :align: center

Encuentra y selecciona "GalaxyRVR".

.. image:: img/2_sprite_rvr.png
    :align: center

**Tu primer ejemplo**

Vamos a crear una animación simple usando la APP para hacer que GalaxyRVR se mueva aleatoriamente.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_app.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

**1. Comienza con la categoría amarilla de Eventos.**

Si bien anteriormente hemos ejecutado código haciendo clic en bloques en el área central, la mayoría de las veces nuestro código debe activarse mediante eventos. Los eventos actúan como "guardianes", monitoreando acciones como clics en sprites o presiones de teclas, y le indican al programa qué hacer cuando ocurren estos eventos.

Arrastra el bloque "cuando se haga clic en la bandera verde".

.. image:: img/2_first_flag.png

La bandera verde actúa como una señal de partida, representando el inicio del programa. Este bloque se activa cuando haces clic en la bandera verde junto al escenario, iniciando todos los personajes y código.

**2. La categoría Control es el director del programa.**

Estos bloques ayudan a controlar el flujo del programa, decidiendo cuándo y con qué frecuencia deben ocurrir las acciones.

Arrastra un bloque "repetir 10" y colócalo debajo del bloque de la bandera verde.

.. image:: img/2_first_repeat.png

Esto significa que después de hacer clic en la bandera verde, algo sucederá diez veces.

**3. La categoría Movimiento proporciona instrucciones para los actores del escenario (sprites).**

Arrastra un bloque "deslizar en 1 seg hacia posición aleatoria" y colócalo dentro del bloque "repetir 10".

.. image:: img/2_first_glide.png

Esto hará que tu sprite se deslice hacia una posición aleatoria.

**4. La categoría Apariencia añade animación e interés visual a tus personajes.**

Arrastra un bloque "siguiente disfraz" y colócalo dentro del bloque "repetir 10".

.. image:: img/2_first_custom.png

Esto hará que tu sprite cambie de disfraz con cada acción, lo que parecerá que está caminando.

Ahora, haz clic en la bandera verde junto al escenario y observa cómo tu GalaxyRVR se mueve aleatoriamente.
