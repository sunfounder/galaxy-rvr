.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Juego Rápido con la APP
=========================

¿Listo para comenzar tu aventura en Marte?
Con la función de inicio rápido de la aplicación RoboPilot, puedes comenzar a explorar tan pronto como tu GalaxyRVR esté ensamblado.

Con RoboPilot, puedes:

- Conducir el rover desde una perspectiva en primera persona
- Cambiar entre tres modos de control: **Remoto**, **Evitación** y **Seguimiento**


.. note::

    * Si has sobrescrito el firmware y necesitas restaurar la comunicación, sigue :ref:`update_r3_firmware`.

Guía Rápida
---------------------

.. raw:: html


   <iframe width="600" height="400" src="https://www.youtube.com/embed/NwWjgP9ldZw?si=_3PADiRd-UlDvtHc" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Antes de usar el GalaxyRVR por primera vez, carga completamente la batería con el cable USB Tipo-C suministrado. Después de cargar, enciende el dispositivo.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_start.mp4" type="video/mp4">
            Tu navegador no soporta la etiqueta de video.
        </video>

#. Para iniciar la ESP32 CAM, cambia el modo a **Run** y presiona el botón **Reset** en la placa R3. La tira de luz inferior comenzará a parpadear para indicar un inicio exitoso.

   .. note::

      * Si la tira de luz inferior muestra una **luz parpadeante de cualquier color que no sea verde**, tu GalaxyRVR necesita una actualización de firmware. Consulta :ref:`update_firmware`.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_reset_green.mp4" type="video/mp4">
            Tu navegador no soporta la etiqueta de video.
        </video>


#. Instala **RoboPilot** desde **APP Store(iOS)** o **Google Play(Android)**.

#. Conecta tu dispositivo móvil a la red WiFi del GalaxyRVR.

   * El nombre de la red (SSID) es ``GalaxyRVR`` y la contraseña es ``12345678``.
   * Si ves una advertencia que dice "Sin acceso a Internet", elige la opción **"Mantener conexión"**.

     .. image:: ../img/camera_lan.png
        :width: 500

#. Abre RoboPilot. Haz clic en 'Go into' para ingresar a la interfaz de control.

   .. image:: img/rp1_inter.png



Modo Remoto
----------------------------------------------

Al ingresar a la interfaz de control, verás la siguiente pantalla.
El fondo muestra la vista capturada por la cámara del GalaxyRVR, con los controles remotos superpuestos.

.. image:: img/rp2_page.png

Estos son los controles:

A. Atrás
B. Ajustes: Aquí puedes cambiar el nombre y la contraseña del AP (punto de acceso), configurar WiFi, voltear la imagen y desconectar.

   .. image:: img/rp3_setting.jpg

C. Indicador de nivel de batería
D. Pausar/Ejecutar la APP
E. Selección de modo: Aquí puedes elegir entre Modo Remoto, Modo Evitación y Modo Seguimiento. La configuración predeterminada es **Modo Remoto**.

   .. image:: img/rp4_mode.jpg

F. Monitor de obstáculos: Este módulo está dividido en tres áreas, con los lados izquierdo y derecho mostrando los resultados de los módulos de obstáculos, y el área central mostrando las lecturas del sensor ultrasónico.
G. Selector de color: Elige aquí el color de iluminación del chasis.

   .. image:: img/rp5_color.png

H. Interruptor de LED de la cámara.
I. Ajusta el ángulo del gimbal, de 0 a 130 grados. A 0 grados, apunta hacia el cielo.
J. Mueve el joystick para controlar el movimiento del GalaxyRVR. Un empuje suave hará que el GalaxyRVR se mueva lentamente.


Modo Evitación y Modo Seguimiento
----------------------------------------------

* **Modo Evitación**: el GalaxyRVR avanzará y evitará obstáculos en su camino.
* **Modo Seguimiento**: el GalaxyRVR se moverá hacia un objeto frente a él o girará a la izquierda o derecha para seguir el movimiento del objeto.

Cuando selecciones **Modo Evitación** o **Modo Seguimiento**, verás la siguiente interfaz. La vista en vivo de la cámara del GalaxyRVR forma el fondo, con opciones de control superpuestas.

.. image:: img/rp6_avoid.png

**Controles de la interfaz:**

A. **Control de velocidad** - Ajusta la velocidad de movimiento del GalaxyRVR
B. **Control del motor** - Inicia o detiene el movimiento del GalaxyRVR
C. **Control del gimbal** - Ajusta el ángulo de la cámara de 0 grados (hacia el cielo) a 130 grados
D. **Monitor de obstáculos** - Retroalimentación visual de los sensores:

   - Secciones izquierda/derecha: Detección de obstáculos por infrarrojos
   - Sección central: Mediciones de distancia ultrasónicas

**Ajuste del rango de detección de obstáculos**

Antes de usar este modo, calibra el rango de detección del sensor para adaptarlo a tu entorno. Es posible que la configuración de fábrica no sea la óptima.

- Demasiado corto: El rover podría chocar con obstáculos
- Demasiado largo: El rover podría girar innecesariamente

Pasos de calibración:

1. **Comienza con el módulo derecho**

   - Asegúrate de que el transmisor/receptor estén correctamente alineados
   - Enderézalos si se doblaron durante el transporte

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
        </video>

2. **Prueba y ajusta la sensibilidad**

   - Coloca un obstáculo a 20 cm de distancia (usa la caja del Rover)
   - Gira el potenciómetro hasta que el indicador se encienda
   - Verifica la activación constante a la distancia deseada
   - Usa el segundo potenciómetro si es necesario

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
        </video>

3. **Repite para el módulo izquierdo**


Reconectar
-------------------------------

Si tu red falla o se desconecta, serás dirigido a esta página.

.. image:: img/rp7_reconnect.png

En este punto, restablece la configuración de tu red, luego haz clic en la IP correspondiente a tu GalaxyRVR para reconectar.
