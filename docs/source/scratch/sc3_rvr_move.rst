.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Lección 3: Control Remoto de tu GalaxyRVR
============================================

¡Prepárate para tomar los controles! En esta lección, te convertirás en el comandante de la misión de tu propio GalaxyRVR Mars Rover.

Transformaremos nuestro conocimiento de programación en acción real, programando tu rover para navegar por el terreno marciano simulado. Observa cómo tus comandos dan vida al rover, moviéndose exactamente como lo diriges aquí en el aula.

Aquí es donde tu misión marciana realmente comienza. ¡Comencemos a conducir!

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      Tu navegador no soporta la etiqueta de video.
   </video>

Objetivos de Aprendizaje
------------------------

* Configurar la comunicación entre la aplicación Mammoth Coding y tu GalaxyRVR subiendo el código Arduino necesario
* Dominar el control de los movimientos de tu rover usando la interfaz de teclas de dirección en la aplicación
* Programar y ejecutar las cuatro maniobras fundamentales del rover: avanzar, retroceder, girar a la izquierda y girar a la derecha

.. _app_connect:

Conectando la Aplicación a GalaxyRVR
-------------------------------------------

.. note::

    * Si has sobrescrito el firmware y necesitas restaurar la comunicación, sigue :ref:`update_r3_firmware`.

.. raw:: html

   <iframe width="560" height="315" src="https://www.youtube.com/embed/kZIrm-_yWrA?si=Cbp0TxN-EZU_6Ksn" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Antes de usar el GalaxyRVR por primera vez, carga completamente la batería con el cable USB Tipo-C suministrado. Después de cargar, enciende el dispositivo.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_start.mp4" type="video/mp4">
            Tu navegador no soporta la etiqueta de video.
        </video>

#. Para iniciar la ESP32 CAM, cambia el modo a **Run** y presiona el botón **Reset** en la placa R3. La tira de luces inferior comenzará a parpadear para indicar un inicio exitoso.

   .. note::

      * Si la tira de luces inferior muestra una **luz parpadeante de cualquier color que no sea verde**, tu GalaxyRVR necesita una actualización de firmware. Consulta :ref:`update_firmware`.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_reset_green.mp4" type="video/mp4">
            Tu navegador no soporta la etiqueta de video.
        </video>

#. Conecta tu dispositivo móvil a la red WiFi del GalaxyRVR.

   * El nombre de la red (SSID) es ``GalaxyRVR`` y la contraseña es ``12345678``.
   * Si ves una advertencia que dice "Sin acceso a Internet", elige la opción **"Mantener conexión"**.

     .. image:: ../img/camera_lan.png
        :width: 500

#. Abre la aplicación en tu dispositivo móvil para iniciar el proceso de conexión.

   .. image:: img/connet_app_04.png

#. Selecciona y carga la extensión GalaxyRVR dentro de la aplicación.

   .. image:: img/connet_app_05.png

#. La aplicación escaneará y buscará automáticamente los dispositivos GalaxyRVR disponibles.

   .. image:: img/connet_app_06.png

#. Selecciona tu GalaxyRVR de la lista para conectarte.

   .. image:: img/reconnect_2.png

   .. note::

      El estado de la conexión se indica mediante las luces LED del GalaxyRVR:

      - **Púrpura intermitente**: Buscando conexión
      - **Apagado**: Conectado exitosamente y listo

Reconectar la Aplicación
-------------------------------------

Cuando tu dispositivo se desconecte del GalaxyRVR, verás aparecer esta ventana emergente en la interfaz. Haz clic en reconectar.

   .. image:: img/reconnect_0.png

Si cierras la ventana emergente, también puedes reconectar haciendo clic en este botón en la categoría GalaxyRVR.

   .. image:: img/reconnect_1.png

Encuentra tu GalaxyRVR y haz clic en conectar.

   .. image:: img/reconnect_2.png


Controlando el GalaxyRVR con la Aplicación
------------------------------------------

1. En la interfaz de programación, encuentra la categoría dedicada GalaxyRVR que contiene todos los bloques de control del rover.

   .. image:: img/3_rvr_catego.png

2. Aunque normalmente usamos la bandera verde para iniciar programas, hay otras formas de activar acciones. Encuentra el bloque ``when up arrow key pressed`` en la categoría Eventos; este ejecutará código cada vez que presiones esa tecla específica.


   .. image:: img/3_rvr_when_arrow.png

3. Crea cuatro bloques de evento, uno para cada dirección de flecha (arriba, abajo, izquierda, derecha). Esto formará la base del sistema de control de tu rover.

   .. image:: img/3_rvr_4_arrow.png
        :width: 800
        :align: center

   .. note:: ¿Necesitas más espacio para programar? Haz clic en el icono del ojo debajo de la bandera verde para ocultar temporalmente el área del escenario.

4. Ahora completa cada bloque de evento con el comando de movimiento correspondiente:

   - Flecha arriba —Avanzar
   - Flecha abajo —Retroceder
   - Flecha izquierda —Girar a la izquierda
   - Flecha derecha —Girar a la derecha

   .. image:: img/3_rvr_4_dir.png
        :width: 800
        :align: center

5. Haz clic en el botón de expansión del escenario para entrar al modo de control completo.

   .. image:: img/3_rvr_stage.png

6. ¡Ahora verás un escenario ampliado con teclas de dirección virtuales! Presiona estas teclas y observa cómo controlas directamente los movimientos de tu GalaxyRVR en tiempo real.

   .. image:: img/3_rvr_stage2.png


Bloques de Control de Movimiento
--------------------------------

* **Control Básico de Dirección**

  Controla la dirección de movimiento del GalaxyRVR. Usa el menú desplegable para seleccionar avanzar, retroceder, girar a la izquierda o girar a la derecha.

  .. image:: img/block/move_forward.png

* **Configuración de Velocidad**

  Establece la velocidad de movimiento del GalaxyRVR. Nota: Este bloque solo configura la velocidad y no inicia el movimiento por sí mismo.

  .. image:: img/block/move_set_speed.png

* **Movimiento Temporizado**

  Hace que el GalaxyRVR se mueva en la dirección seleccionada durante una duración específica. Puedes:

  * Elegir la dirección (avanzar/retroceder/izquierda/derecha) del menú desplegable
  * Establecer la duración del movimiento cambiando el valor de tiempo

  .. image:: img/block/move_forward_1s.png

* **Movimiento Controlado por Velocidad**

  Mueve el GalaxyRVR a un porcentaje de velocidad específico. Puedes:

  * Seleccionar la dirección de movimiento del menú desplegable
  * Ajustar el porcentaje de velocidad (0-100%)

  .. image:: img/block/move_forward_80.png

* **Control de Movimiento Preciso**

  Combina el control de velocidad y tiempo para movimientos precisos. Puedes:

  * Establecer la dirección de movimiento
  * Ajustar el porcentaje de velocidad
  * Establecer la duración del movimiento

  .. image:: img/block/move_forward_80_1s.png

* **Control Avanzado de Ruedas**

  Proporciona control independiente sobre cada rueda para maniobras complejas. Puedes:

  * Establecer la velocidad de la rueda izquierda por separado
  * Establecer la velocidad de la rueda derecha por separado
  * Controlar la duración del movimiento

  .. image:: img/block/move_lr_sp_1s.png

* **Parada de Emergencia**

  Detiene inmediatamente todo el movimiento del GalaxyRVR.

  .. image:: img/block/move_stop.png
