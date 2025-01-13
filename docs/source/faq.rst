.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. ¡Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 con otros entusiastas!

    **¿Por qué unirte?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Previsualizaciones exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

FAQ
==============

Cómo cambiar el canal Wi-Fi
----------------------------------

La banda Wi-Fi de 2.4GHz tiene canales que van del 1 al 13. El ESP32 admite los canales del 1 al 11. Otros dispositivos que operan en el mismo canal pueden causar interferencias, lo que lleva a problemas de conexión. Para mitigar esto, puedes intentar cambiar el canal. Por defecto, el canal está configurado en el 1. Al seleccionar un nuevo canal, se recomienda saltar 1-2 canales a la vez. Por ejemplo, si el canal actual es el 1, prueba primero con el canal 3 y, si la señal sigue siendo débil, continúa con el canal 5.

.. note::

   Se requiere la versión de firmware 1.4.1 o superior del ESP32 CAM para cambiar canales. Consulta :ref:`update_firmware` para más detalles.

#. Enciende el GalaxyRVR. Para activar el ESP32 CAM, mueve el interruptor de modo a la posición **Run** y presiona el botón **reset** para reiniciar la placa R3.

     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Encuentra ``GalaxyRVR`` en la lista de redes disponibles en tu dispositivo móvil (tableta o teléfono inteligente), introduce la contraseña ``12345678`` y conéctate a él.

     .. note::

        * La conexión actual es al hotspot de GalaxyRVR, por lo que no hay acceso a Internet. Si se te solicita cambiar de red, elige "Mantenerse conectado".

     .. image:: img/app/camera_lan.png
        :width: 500

#. Abre un navegador web en tu dispositivo móvil y navega a ``http://192.168.4.1`` para acceder a la página de actualización OTA del ESP32 CAM.

   .. image:: img/faq_cam_ota_141.jpg
      :width: 400

#. En la sección **Wi-Fi AP Channel**, selecciona un canal diferente. 

   * El canal predeterminado es el 1. Al seleccionar un nuevo canal, salta 1-2 canales a la vez (por ejemplo, del canal 1 al 3, y si es necesario, al 5).  
   * Haz clic en el botón **Confirm** para guardar los cambios.

   .. image:: img/faq_cam_ota_channel.png
      :width: 400

#. Aparecerá un mensaje de confirmación solicitándote que reinicies el dispositivo. Haz clic en **Confirm**.

   .. image:: img/faq_cam_ota_reset.jpg
      :width: 400
   
#. Presiona el botón **Reset** para reiniciar el dispositivo. El GalaxyRVR ya está listo para su funcionamiento normal.

   .. image:: img/camera_reset.png

.. _update_firmware:

Cómo actualizar el firmware del ESP32 CAM
-----------------------------------------

Sigue estos pasos detallados para actualizar el firmware de tu ESP32 CAM:

#. Enciende el GalaxyRVR. Para activar el ESP32 CAM, mueve el interruptor de modo a la posición **Run** y presiona el botón **reset** para reiniciar la placa R3.

     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Encuentra ``GalaxyRVR`` en la lista de redes disponibles en tu dispositivo móvil (tableta o teléfono inteligente), introduce la contraseña ``12345678`` y conéctate a él.

     .. note::

        * La conexión actual es al hotspot de GalaxyRVR, por lo que no hay acceso a Internet. Si se te solicita cambiar de red, elige "Mantenerse conectado".

     .. image:: img/app/camera_lan.png
        :width: 500

#. Haz clic en el siguiente enlace para descargar el archivo de firmware ``ai-camera-firmware-v1.4.1-ota.bin`` y guárdalo en tu dispositivo móvil.

   * :download:`Archivo de firmware de ESP32 CAM <https://github.com/sunfounder/ai-camera-firmware/releases/download/1.4.1/ai-camera-firmware-v1.4.1-ota.bin>` 

#. Abre un navegador web en tu dispositivo móvil y navega a ``http://192.168.4.1`` para acceder a la página de actualización OTA del ESP32 CAM.

   .. image:: img/faq_cam_ota.jpg
      :width: 400

#. En la página OTA, haz clic en el botón para seleccionar el archivo de firmware.

   .. image:: img/faq_cam_ota_choose.png
      :width: 400

#. Elige el archivo ``ai-camera-firmware-v1.4.1-ota.bin`` descargado previamente desde tu dispositivo y haz clic en **OK**.

   .. image:: img/faq_cam_ota_file.png
      :width: 400

#. Haz clic en el botón **Update** para iniciar el proceso de actualización de firmware.

   .. image:: img/faq_cam_ota_update.png
      :width: 400
   
#. Espera a que la actualización se complete. Una vez que el número de versión mostrado cambie a ``1.4.1``, la actualización habrá sido exitosa.

   .. image:: img/faq_cam_ota_finish.png
      :width: 400
   
#. Después de completar la actualización, puedes cerrar el navegador web. Presiona el botón **Reset** para reiniciar el dispositivo. El ESP32 CAM ya está listo para su funcionamiento normal.

   .. image:: img/camera_reset.png


.. _upload_galaxy_code:

¿Cómo cargar el código ``galaxy-rvr.ino``?
-----------------------------------------------

Por defecto, la placa Uno R3 del GalaxyRVR viene preinstalada con el firmware necesario, permitiéndote controlarlo a través de la APP. Si tu placa R3 ha sido sobrescrita con otro código y deseas volver al firmware predeterminado para continuar con el proceso :ref:`quick_start`, sigue estos pasos para recargar el código en tu placa R3:

#. Usa un cable USB para conectar el Arduino a tu computadora. Luego, cambia el interruptor **upload** en el rover a la posición "upload".

   .. image:: img/camera_upload.png
        :width: 400
        :align: center

#. Descarga el firmware necesario desde el siguiente enlace:

   * :download:`Archivo de firmware de la placa R3 <https://github.com/sunfounder/galaxy-rvr/releases/download/1.1.0/galaxy-rvr-1.1.0.zip>`

#. Extrae el archivo zip descargado y haz doble clic en el archivo ``update-arduino-firmware.bat`` para ejecutarlo.

   .. image:: img/faq_firmware_file.png

#. Escribe el número correspondiente a la placa Arduino Uno de tu GalaxyRVR (por ejemplo, ``2``) y presiona **Enter** para comenzar la actualización.

   .. note::

     * Si el puerto COM correcto no aparece o si no estás seguro de cuál es, desconecta otros dispositivos USB de tu computadora dejando solo el rover conectado.
     * Si encuentras un error como "avrdude.exe: stk500_getsync() attempt 1 of 10: not in sync: resp=0xXX", asegúrate de que el interruptor **upload** en el rover esté en la posición "upload", como se describe en el paso 1.

   .. image:: img/faq_firmware_port.png
      :width: 600

#. Después de un breve momento, el nuevo código se cargará exitosamente en la placa Uno R3 del GalaxyRVR.

   .. image:: img/faq_firmware_finish.png
      :width: 600

.. _ap_to_sta:

¿Cómo controlar el rover utilizando tu WiFi doméstico?
------------------------------------------------------
Por defecto, el Uno R3 está preinstalado con un código configurado en modo APP. Esto significa que el GalaxyRVR transmitirá un punto de acceso, permitiéndote conectarte con tu dispositivo móvil para controlarlo a través de la aplicación SunFounder Controller.

Si prefieres controlar el rover utilizando tu WiFi doméstico, sigue estos pasos para cargar el código modificado en la placa Uno:

#. Descarga los archivos necesarios desde el siguiente enlace:

   * :download:`GalaxyRVR Codes <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/main.zip>`

#. Consulta la guía de instalación: :ref:`install_arduino_ide`.

#. Usa el **Library Manager** para instalar las bibliotecas ``SoftPWM`` y ``SunFounder AI Camera``. Para pasos detallados, consulta :ref:`install_lib`.

#. Navega al directorio ``galaxy-rvr-main\galaxy-rvr`` y abre el archivo ``galaxy-rvr.ino``.

   .. image:: img/faq_galaxy_code.png
      :width: 400

#. Comenta las líneas 69-71, descomenta las líneas 73-75 y reemplaza ``SSID`` y ``PASSWORD`` con las credenciales de tu WiFi doméstico.

   .. image:: img/ap_sta.png
      :align: center

#. Conecta el GalaxyRVR y tu computadora con un cable USB, y luego mueve el interruptor **upload** del rover a la posición "upload".

   .. image:: img/camera_upload.png
        :width: 400
        :align: center

#. Haz clic en el botón **Upload** en el IDE de Arduino para cargar el código modificado en la placa Uno.

   .. image:: img/faq_galaxy_upload.png

#. Para activar el ESP32 CAM, mueve el interruptor de modo a la posición **Run** y presiona el botón **reset** para reiniciar la placa R3. Luego observarás una luz cian parpadeando en la tira inferior.

   .. raw:: html
   
       <video width="600" loop autoplay muted>
           <source src="_static/video/play_reset.mp4" type="video/mp4">
           Your browser does not support the video tag.
       </video>

#. Asegúrate de que tu dispositivo móvil (tableta o smartphone) esté conectado a tu red WiFi doméstica.

   .. image:: img/faq_connect_wifi.jpg
        :width: 400
        :align: center

#. Abre la aplicación SunFounder Controller, toca el icono "+" para crear un nuevo controlador, selecciona el preajuste "GalaxyRVR", introduce un nombre o toca "Confirmar" para continuar.

   .. image:: img/app/play_preset.jpg
        :width: 600

#. La aplicación buscará automáticamente el GalaxyRVR. Después de un momento, verás un mensaje indicando "Conectado exitosamente."

   .. image:: img/app/auto_connect.jpg
        :width: 600

#. Ahora, toca el botón |app_run| para habilitar la vista de video en vivo de la cámara y controlar el rover utilizando los widgets proporcionados.

   .. image:: img/app/play_run_view.jpg
        :width: 600 

¿Cómo invertir la cámara?  
---------------------------

Si encuentras que la transmisión de la cámara está al revés mientras usas el SunFounder Controller, puedes corregirlo fácilmente a través de la aplicación. Sigue estos pasos:

1. Toca el botón |app_edit| en la esquina superior derecha.

   .. image:: img/app/faq_edit.png  
        :width: 500 

2. Haz clic en el botón **camera** para abrir una ventana emergente. Activa el interruptor **Inverted** para encenderlo.

   .. image:: img/app/faq_inverted.png  
        :width: 500  

3. Guarda tus configuraciones.

   .. image:: img/app/faq_save.png  
        :width: 500 

4. Vuelve a la interfaz de control y haz clic en el botón |app_run|.

   .. note::  

        Ocasionalmente, la transmisión de la cámara puede no aparecer. Si esto sucede, pausa el controlador y luego haz clic nuevamente en el botón ejecutar.

   .. image:: img/app/faq_run.png  
        :width: 500 

.. _install_lib:

¿Error de compilación: ``SoftPWM.h`` o ``SunFounder_AI_Camera.h``: No such file or directory？
------------------------------------------------------------------------------------------------

Si recibes un mensaje de "Error de compilación: ``SoftPWM.h``: No such file or directory", significa que no tienes instalada la biblioteca SoftPWM.

Por favor, instala las dos bibliotecas necesarias ``SoftPWM`` y ``SunFounder AI Camera`` como se muestra.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

Para la biblioteca ``SunFounder AI Camera``, necesitas seleccionar "INSTALL ALL" para instalar simultáneamente la dependencia requerida ``ArduinoJson``.

    .. image:: img/faq_install_ai_camera.png
      :width: 600

avrdude: stk500_getsync() intento 10 de 10: ¿no sincronizado: resp=0x6e?
---------------------------------------------------------------------------------
Si el siguiente mensaje sigue apareciendo después de hacer clic en el botón **Upload** y la placa y el puerto se han seleccionado correctamente.

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00

En este punto, debes asegurarte de que el ESP32 CAM esté desconectado.

El ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Entonces, antes de subir el código, deberás desconectar primero el ESP32-CAM para evitar conflictos o problemas potenciales.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Después de que el código se haya subido correctamente, si necesitas usar el ESP32 CAM, debes mover el interruptor a la izquierda para encender el ESP32 CAM.

    .. image:: img/camera_run.png
        :width: 500
        :align: center

.. _stt_android:

¿Cómo puedo usar el modo STT en mi dispositivo Android?
------------------------------------------------------------------------

El modo STT requiere que el dispositivo móvil Android esté conectado a Internet y tenga instalado el componente de servicio de Google.

Sigue los siguientes pasos:

#. Modifica el archivo ``galaxy-rvr.ino`` de modo AP a modo STA.

    * Abre el archivo ``galaxy-rvr.ino`` que se encuentra en el directorio ``galaxy-rvr-main\galaxy-rvr``. 
    * Luego comenta el código relacionado con el modo AP. Descomenta el código del modo STA y rellena el ``SSID`` y ``PASSWORD`` de tu Wi-Fi doméstico.

        .. code-block:: arduino

            /** Configurar modo Wifi, SSID, contraseña*/
            // #define WIFI_MODE WIFI_MODE_AP
            // #define SSID "GalaxyRVR"
            // #define PASSWORD "12345678"

            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "xxxxxxxxxx"
            #define PASSWORD "xxxxxxxxxx"

    * Guarda este código, selecciona la placa correcta (Arduino Uno) y el puerto, luego haz clic en el botón **Upload** para subirlo a la placa R3.

#. Busca ``google`` en Google Play, encuentra la app que se muestra a continuación e instálala.

    .. image:: img/google_voice.png
        :width: 500
        :align: center

#. Conecta tu dispositivo móvil a la misma red Wi-Fi que escribiste en el código.

    .. image:: img/sta_wifi.png
        :width: 500
        :align: center

#. Abre el controlador previamente creado en SunFounder Controller y conéctalo a ``GalaxyRVR`` a través del botón |app_connect|.

    .. image:: img/app/camera_connect.png
        :width: 400
        :align: center

#. Toca y mantén presionado el widget **STT(J)** después de hacer clic en el botón |app_run|. Aparecerá un aviso indicando que está escuchando. Di los siguientes comandos para mover el coche.

    .. image:: img/app/play_speech.png

    * ``stop``: Detiene todos los movimientos del rover.
    * ``forward``: Mueve el rover hacia adelante.
    * ``backward``: Mueve el rover hacia atrás.
    * ``left``: Gira el rover hacia la izquierda.
    * ``right``: Gira el rover hacia la derecha.

Acerca del Firmware del ESP32 CAM
---------------------------------------------------

Aquí está el enlace del firmware del ESP32 CAM: |link_ai_camera_firmware|

.. ↓ this firmware only for sunfounder controller


.. Q6: How to Flash New Firmware to an ESP32 CAM?
.. ----------------------------------------------------
.. The camera module comes pre-flashed from the factory. However, if you encounter a data corruption issue, you can re-flash it with new firmware using the Arduino IDE. Here's how:

.. **1. Prepare the Programmer**

.. #. First, get a programmer ready.

..     .. image:: img/esp32_cam_programmer.png
..         :width: 300
..         :align: center

.. #. Insert the ESP32 CAM into the programmer and then plug the programmer into your computer.

..     .. image:: img/esp32_cam_usb.jpg
..         :width: 300
..         :align: center

.. **2. Install the ESP32 Board**

.. To program the ESP32 microcontroller, you must install the ESP32 board package in the Arduino IDE. Follow these steps:

.. #. Go to **File** and select **Preferences** from the drop-down menu.

..     .. image:: img/install_esp321.png
..         :width: 500
..         :align: center

.. #. In the **Preferences** window, find the **Additional Board Manager URLs** field. Click on it to enable the text box.

..     .. image:: img/install_esp322.png
..         :width: 500
..         :align: center

.. #. Add this URL to the **Additional Board Manager URLs** field: https://espressif.github.io/arduino-esp32/package_esp32_index.json. This URL links to the package index file for ESP32 boards. Click **OK** to save the changes.

..     .. image:: img/install_esp323.png
..         :width: 500
..         :align: center

.. #.  In the **Boards Manager** window, search for **ESP32**. Click the **Install** button to begin installation. This downloads and installs the ESP32 board package.

..     .. image:: img/install_esp324.png
..         :align: center

.. **3. Install the Libraries**

.. #. Install the ``WebSockets`` library from the **LIBRARY MANAGER**.

..     .. image:: img/esp32_cam_websockets.png
..         :width: 500
..         :align: center

.. #. Follow the same steps to install the ``ArduinoJson`` library.

..     .. image:: img/esp32_cam_arduinojson.png
..         :width: 500
..         :align: center

.. **3. Download and Upload Firmware**

.. #. Download the firmware file.

..     * :download:`ai-camera-firmware <https://github.com/sunfounder/ai-camera-firmware/archive/refs/heads/main.zip>`

.. #. Extract the downloaded firmware file and rename the extracted folder from ``ai-camera-firmware-main`` to ``ai-camera-firmware``.

..     .. image:: img/esp32_cam_change_name.png
..         :align: center

.. #. Open ``ai-camera-firmware.ino`` with the Arduino IDE, which also opens the associated code files.

..     .. image:: img/esp32_cam_ino.png
..         :align: center

.. #. Select **Board** -> **esp32** -> **ESP32 Dev Module**.

..     .. image:: img/esp32_cam_board.png
..         :width: 500
..         :align: center

.. #. Choose the correct port.

..     .. image:: img/esp32_cam_port.png
..         :width: 400
..         :align: center

.. #. Ensure to enable **PSRAM** and select **Huge APP** in the **Partition Scheme**.

..     .. image:: img/esp32_cam_psram.png
..         :width: 400
..         :align: center

.. #. Finally, upload the firmware to the ESP32 CAM.

..     .. image:: img/esp32_cam_upload.png
..         :width: 500
..         :align: center

.. #. After successful firmware upload, you can find more information at this link: https://github.com/sunfounder/ai-camera-firmware.



