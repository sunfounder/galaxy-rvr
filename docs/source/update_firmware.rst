
.. _update_firmware:

Actualizar Firmware
==========================

Es posible que su dispositivo no tenga el firmware más reciente debido a las continuas mejoras del producto.
Para garantizar un rendimiento óptimo y estable, siga los pasos a continuación para verificar y actualizar el firmware en su ESP32 CAM y placa R3.

.. raw:: html

   <iframe width="560" height="315" src="https://www.youtube.com/embed/Tl2W26pIQoU?si=98bbfUPc1g2cEz3A" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


1. Verificar si es Necesaria una Actualización
-----------------------------------------------

#. Antes de usar el GalaxyRVR por primera vez, cargue completamente la batería con el cable USB Tipo-C suministrado. Después de cargar, encienda el dispositivo.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_start.mp4" type="video/mp4">
            Su navegador no soporta la etiqueta de video.
        </video>

#. Para iniciar la ESP32 CAM, cambie el modo a **Run** y presione el botón **Reset** en la placa R3. La tira de luz inferior comenzará a parpadear para indicar un inicio exitoso.

   .. note::

      * Si la tira de luz inferior muestra una **luz verde parpadeante**, el firmware de su ESP32 ya está actualizado.
      * Puede continuar con :ref:`quick_start`.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset_green.mp4" type="video/mp4">
            Su navegador no soporta la etiqueta de video.
        </video>

#. Si la tira de luz inferior parpadea en **otro color**, necesitará:

   * :ref:`update_esp32_firmware`
   * :ref:`update_r3_firmware`

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Su navegador no soporta la etiqueta de video.
        </video>


.. _update_esp32_firmware:

2. Actualizar el Firmware de la ESP32 CAM
------------------------------------------

La ESP32 CAM transmite el punto de acceso Wi-Fi y captura video para el GalaxyRVR.
Si el firmware está desactualizado, estas funciones pueden no funcionar correctamente. Siga los pasos a continuación para actualizar el firmware.

#. Encienda el interruptor de alimentación del GalaxyRVR. Para iniciar la ESP32 CAM, cambie el modo a **Run** y presione el botón **Reset** en la placa R3.

   .. image:: img/camera_run.png
        :width: 500
        :align: center

#. Descargue el archivo de firmware.

   * |download_galaxyrvr_filmware|

#. Extraiga el archivo ZIP descargado. Localice el archivo de firmware llamado ``ai-camera-firware.ino.x.x.x.bin`` y transfiéralo a su dispositivo móvil. Puede usar cualquier aplicación de gestión de archivos, como ES File Explorer o una utilidad de transferencia de archivos.

   .. image:: img/firmware_bin_file.png
        :align: center

#. Conecte su dispositivo móvil a la red WiFi del GalaxyRVR.

   * El nombre de la red (SSID) es ``GalaxyRVR`` y la contrase?a es ``12345678``.
   * Si ve una advertencia que indica "Sin acceso a Internet", elija la opción **"Mantener conexión".**

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Abra un navegador web en su dispositivo móvil y navegue a ``http://192.168.4.1`` para acceder a la página de actualización OTA de la ESP32 CAM.


.. note:: En esta página, verá las opciones de actualización OTA en una de dos interfaces. La Versión A (la primera) y la Versión B (la segunda) aparecerán dependiendo de la versión de su firmware. Simplemente seleccione los pasos de actualización correspondientes según la interfaz que vea.

   .. image:: img/firmware_access_ab.png
      :width: 90%
      :align: center


**Versión A**

   6. En la página OTA, haga clic en el botón para seleccionar el archivo de firmware.

      .. image:: img/faq_cam_ota_choose.png
         :width: 400

   #. Seleccione el archivo ``ai-camera-firmware-vX.X.X-ota.bin`` previamente descargado de su dispositivo y haga clic en **Add**.

      .. image:: img/faq_cam_ota_file.png
         :width: 400

   #. Haga clic en el botón **Update** para iniciar el proceso de actualización del firmware.

      .. image:: img/faq_cam_ota_update.png
         :width: 400

   #. Espere a que se complete la actualización.

      .. image:: img/faq_cam_ota_finish.png
         :width: 400

   #. Una vez completada la actualización, puede cerrar el navegador web. Presione el botón **Reset** para reiniciar el dispositivo. La ESP32 CAM ya está lista para funcionar con normalidad.

      .. image:: img/camera_reset.png
         :width: 600

   .. note:: Una vez completada la actualización, el nombre del punto de acceso WiFi del GalaxyRVR cambiará a "AI Camera-xxxxxx", y la contrase?a seguirá siendo "12345678".


**Versión B**


   6. En la página **OTA**, verifique la versión actual del firmware mostrada en la página web.

      * Si su número de versión es **superior a 1.5.1**, no es necesaria una actualización. Puede omitir los pasos restantes y continuar directamente con :ref:`quick_start`.
      * Si la versión es **1.5.1 o inferior**, continúe con la actualización.

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center


   #. Toque el botón **Upgrade Firmware**.

      .. image:: img/firmware_tap.jpg
         :width: 50%
         :align: center

   #. Aparecerá un cuadro de diálogo de selección de archivos. Navegue hasta el archivo ``ai-camera-firware.ino.x.x.x.bin`` que transfirió a su dispositivo móvil anteriormente y selecciónelo.

      .. image:: img/firmware_select.jpg
         :width: 50%
         :align: center

   #. La actualización del firmware comenzará inmediatamente después de seleccionar el archivo.

      .. image:: img/firmware_upgrade.jpg
         :width: 50%
         :align: center

   #. Espere a que finalice la actualización del firmware.

      * El proceso de carga generalmente toma 1-2 minutos. Una vez finalizado, aparecerá un mensaje de éxito en una ventana emergente.
      * Luego puede seleccionar **CONFIRM** para reiniciar el GalaxyRVR o **CLOSE** para cerrar la ventana.

      .. image:: img/firmware_finish.jpg
         :width: 50%
         :align: center


.. _update_r3_firmware:

3. Actualizar el Firmware de la Placa R3
------------------------------------------

La placa R3 incluye firmware integrado que permite la comunicación con la aplicación RoboPilot y Mammoth Coding.

Necesita volver a cargar este firmware si:

- Su dispositivo utiliza una versión de firmware anterior, o
- Ha grabado su propio código de Arduino y desea restaurar la compatibilidad.

Siga los pasos a continuación para reinstalar el firmware de comunicación.

#. Conecte el Arduino y el ordenador con un cable USB, y luego gire el interruptor **upload** del carro hacia el extremo de carga.

   .. image:: img/camera_upload.png
        :width: 500
        :align: center

   .. note:: Es el puerto USB Tipo B para conectar al Arduino, no el puerto USB Tipo C para cargar.

#. Verifique si los archivos de firmware se han descargado.

   * |download_galaxyrvr_filmware|

#. Ejecute el script de actualización

   * Abra la carpeta ``galaxy-rvr.ino.xxx`` (descargada e instalada en el paso anterior).
   * Haga doble clic en el script ``update-arduino-firmware.bat``.
   * Aparecerá automáticamente una ventana de símbolo del sistema.

   .. image:: img/faq_bat_file.png

#. Seleccione el puerto serie y cargue

   * En el símbolo del sistema, se mostrará una lista de puertos serie disponibles.
   * Ingrese el número de secuencia que aparece a la izquierda para seleccionar el puerto serie del Arduino Uno.
   * Presione **Enter** para comenzar la carga automática.
   * Ejemplo: Si la lista muestra `1 USB-SERIALXXX (COMxx)`, ingrese **1** y presione **Enter**.

   .. image:: img/faq_select_com.png

#. Después de esperar a que se complete la carga, puede desconectar el cable USB.

   .. image:: img/faq_uno_updating.png

   .. note::

      Este código permite que el GalaxyRVR responda a los comandos de la aplicación. No necesitará cargar ningún código adicional al usar la aplicación de control remoto RoboPilot o el software Mammoth Coding.

#. Ahora puede continuar con :ref:`quick_start` para comenzar su viaje con el GalaxyRVR.