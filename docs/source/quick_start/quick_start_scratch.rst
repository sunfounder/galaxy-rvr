Juego Rápido con Scratch
==================================

En este capítulo, aprenderá a **abrir y ejecutar rápidamente proyectos de ejemplo en Scratch (Mammoth Coding)** para ver su GalaxyRVR en acción.

Si desea aprender a crear estos scripts desde cero, consulte el capítulo :ref:`programming_scratch`.

.. note::

    * La placa R3 del GalaxyRVR viene con un firmware compatible con la aplicación RoboPilot y Mammoth Coding.
    * Si ha sobrescrito el firmware y necesita restaurar la comunicación, siga las instrucciones de :ref:`update_r3_firmware`.


Cómo abrir rápidamente un ejemplo de Scratch
---------------------------------------------

#. Descargue los códigos de ejemplo desde el siguiente enlace:

   * |download_galaxyrvr_code|

#. Extraiga el archivo descargado y transfiera la carpeta ``scratch_codes`` a su dispositivo móvil. Puede usar cualquier herramienta de transferencia de archivos, como **ES File Explorer** o **File Transfer Assistant**.

   .. image:: img/scratch_mobile_save.png
      :width: 400

#. Busque **Mammoth Coding** en **Google Play** o en la **Apple App Store** e instálelo.

   .. image:: img/scratch_app_install.png
      :width: 600

#. Antes de usar el GalaxyRVR por primera vez, cargue completamente la batería con el cable USB tipo C suministrado. Después de cargarla, encienda el robot.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_start.mp4" type="video/mp4">
            Su navegador no soporta la etiqueta de video.
        </video>

#. Para iniciar el ESP32 CAM, cambie el modo a **Run** y presione el botón **Reset** en la placa R3. La tira de luces inferior comenzará a parpadear para indicar un inicio exitoso.

   .. note::

      * Si la tira de luces inferior muestra una **luz parpadeante de cualquier color que no sea verde**, su GalaxyRVR necesita una actualización de firmware. Consulte :ref:`update_firmware`.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_reset_green.mp4" type="video/mp4">
            Su navegador no soporta la etiqueta de video.
        </video>


#. Conecte su dispositivo móvil a la red WiFi del GalaxyRVR.

   * El nombre de la red (SSID) es ``GalaxyRVR`` y la contraseña es ``12345678``.
   * Si aparece una advertencia que indica "Sin acceso a Internet", seleccione la opción **"Mantener conexión"**.


     .. image:: ../img/camera_lan.png
        :width: 500

#. En la aplicación, toque **File** > **Open from device** para explorar los archivos locales.

   .. image:: img/scratch_open_file.png
        :width: 600

#. Seleccione un archivo ``.sb3`` para abrirlo.

   .. image:: img/scratch_mobile_save.png
      :width: 400

#. Toque el icono de la bandera verde para iniciar el script.

   .. image:: img/scratch_run.png

Ejemplos
---------------

**Proyectos básicos**

Estos proyectos son los cursos básicos para controlar el GalaxyRVR con Mammoth Coding. Le guiarán paso a paso sobre cómo utilizar el GalaxyRVR.


* ``3_move.sb3``: Controle el movimiento de su GalaxyRVR en tiempo real usando las teclas de dirección.
* ``4_ultrasonic.sb3``: El rover avanza y evita obstáculos automáticamente usando el módulo ultrasónico.
* ``5_ultra_animate_jump.sb3``: Crea una escena animada del rover moviéndose alegremente por la superficie marciana.
* ``6_ir_obstacle_avoid.sb3``: El rover avanza y evita obstáculos usando sensores IR.
* ``7_ir_obstacle_avoid_animate.sb3``: Controle el sprite del rover para esquivar rocas en la superficie marciana activando los sensores IR con las manos.
* ``8_ir_ultrasonic_avoid.sb3``: El rover usa sensores ultrasónicos e IR juntos para navegar suavemente alrededor de obstáculos.
* ``9_ir_ultrasonic_follow.sb3``: El rover le sigue: se acerca cuando se pone frente a él, gira hacia usted cuando está a un lado y se detiene cuando se aleja.
* ``10_rgb.sb3``: Toque una bola de color para que las luces RGB del rover brillen en ese color.
* ``10_rgb_animate.sb3``: El rover se mueve y cambia el color de la luz según las teclas de dirección que se presionen.
* ``1scratch_servo.sb3``: Use las teclas de flecha para ajustar el ángulo de la cámara del rover; haga clic para restablecer su posición.
* ``1scratch_servo_stage.sb3``: Toque y arrastre la flecha en pantalla para dirigir la cámara del rover con una respuesta suave y en tiempo real.
* ``12_camera.sb3``: Vea la transmisión en vivo de la cámara desde la perspectiva del rover mientras explora.
* ``13_realtime_control.sb3``: Controle los movimientos y las luces de su rover en tiempo real a través de Scratch.

**Proyectos divertidos**

Estos divertidos proyectos de Scratch no requieren el GalaxyRVR.
Puede encontrarlos todos en la carpeta ``scratch_codes/fun/``.

* ``1_scratch_balloon.sb3``: Infle el globo bloqueando el sensor IR izquierdo; no deje que explote ni se caiga.
* ``2_flappy_parrot.sb3``: Controle el vuelo del loro usando su mano sobre el sensor ultrasónico para esquivar postes de bambú.
* ``3_shooting.sb3``: Apunte y dispare a los objetivos usando el módulo de evasión de obstáculos.
* ``4_eat_apple.sb3``: Guíe al escarabajo hacia la manzana usando gestos de la mano detectados por el sensor IR izquierdo.
* ``5_fishing.sb3``: Atrape peces bloqueando el sensor IR izquierdo en el momento adecuado.
* ``6_sensitive_ball.sb3``: Mueva la bola hacia arriba o hacia abajo con la mano sobre el sensor ultrasónico; active sonidos y luces cuando toque una línea.
* ``7_tap_white_tile.sb3``: Toque las fichas negras usando dos sensores IR para sumar puntos; evite las blancas.
