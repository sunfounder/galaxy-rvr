Juego Rápido con Arduino
===============================

En este capítulo, aprenderás a **abrir y ejecutar rápidamente códigos de ejemplo específicos de Arduino** para que tu GalaxyRVR realice diversas acciones.

Si deseas comprender la lógica del código y los principios de programación detrás de estos ejemplos, consulta el capítulo :ref:`programming_arduino`.

Cómo abrir rápidamente un ejemplo de Arduino
---------------------------------------------

En este ejemplo, demostraremos cómo usar el IDE de Arduino para abrir un ejemplo de Arduino.

#. Enciende el GalaxyRVR.

   * Cuando uses el GalaxyRVR por primera vez, se recomienda cargar completamente la batería conectando un cable USB Tipo-C. Luego, enciende el interruptor de encendido.

     .. raw:: html

          <video width="600" loop autoplay muted>
              <source src="../_static/video/play_start.mp4" type="video/mp4">
              Tu navegador no soporta la etiqueta de video.
          </video>

    * El ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, primero debes liberar el ESP32-CAM deslizando este interruptor hacia la derecha para evitar conflictos o problemas potenciales.

      .. image:: ../img/camera_upload.png
         :width: 600

#. Conecta tu placa Arduino al ordenador usando un cable USB.

#. Visita |link_download_arduino| y descarga el IDE de Arduino para tu sistema operativo. Sigue las instrucciones de instalación para completar la configuración.

   .. image:: img/arduino_download_page.png

#. Descarga los códigos de ejemplo desde el siguiente enlace:

   * |download_galaxyrvr_code|

#. Descomprime el archivo descargado y navega a ``galaxy-rvr-1.2.x\lesson_codes``.

   .. image:: img/arduino_open_folder.png

#. Selecciona una carpeta de código de ejemplo, navega a esa carpeta y haz doble clic en el archivo ``.ino`` para abrirlo en el IDE de Arduino.

   .. image:: img/arduino_open_file.png

#. En el IDE de Arduino, selecciona **Arduino Uno** como placa y elige el **puerto** adecuado para tu dispositivo.

   .. image:: img/arduino_choose_board.png

#. Haz clic en el botón **Cargar** (flecha que apunta a la derecha) para cargar el código en tu placa.

   .. image:: img/arduino_upload.png

.. note::

    Si no estás familiarizado con el IDE de Arduino, consulta lo siguiente:

    * :ref:`install_arduino_ide`
    * :ref:`upload_sketch`

Ejemplos
------------

* ``5_car_move``: El rover avanza, luego retrocede, gira a la izquierda y a la derecha, y finalmente se detiene.
* ``6_ir_avoid``: El rover evita obstáculos usando sensores infrarrojos.
* ``7_ultrasonic_avoid``: El rover evita obstáculos usando el módulo ultrasónico.
* ``8_ultrasonic_ir_avoid``: El rover usa tanto el sensor infrarrojo como el módulo ultrasónico para detectar obstáculos.
* ``8_ultrasonic_ir_follow``: El rover sigue objetos usando el sensor infrarrojo y el módulo ultrasónico.
* ``9_rgb_car_move``: Añade indicadores de color para el movimiento: verde para avanzar, rojo para retroceder y amarillo para girar a la izquierda o a la derecha.
* ``10_servo_range``: El cardán de la cámara gira de 0° a 180° usando un bucle for, y el ángulo actual se muestra en el Monitor Serie.
* ``11_camera_view``: Ve la transmisión de video en vivo desde la cámara del rover en un navegador web. Se requiere la librería **SunFounder AI Camera**.
* ``13_read_battery``: Monitorea el voltaje de la batería a través del código.
