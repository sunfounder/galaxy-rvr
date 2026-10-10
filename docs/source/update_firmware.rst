.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


.. _update_firmware:

Actualizar Firmware
==========================

Es posible que su dispositivo no tenga el firmware más reciente debido a las continuas mejoras del producto.
Para garantizar un rendimiento óptimo y estable, actualice el firmware antes del primer uso. La actualización del firmware garantiza:

* **Corrección de errores**: resuelve problemas conocidos y mejora la estabilidad.
* **Compatibilidad con la aplicación**: se requiere el firmware más reciente para que la aplicación RoboPilot y Mammoth Coding funcionen correctamente.
* **Nuevas funciones**: las actualizaciones de firmware pueden añadir nuevas capacidades y mejoras.
* **Mejor rendimiento**: optimizaciones de la conectividad WiFi, la transmisión de la cámara y el control de los motores.

.. note::
   Si prefiere no actualizar el firmware y seguir usando su configuración actual, puede consultar la `documentación de GalaxyRVR v1 <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_.

.. raw:: html

   <iframe width="560" height="315" src="https://www.youtube.com/embed/Tl2W26pIQoU?si=98bbfUPc1g2cEz3A" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


.. _update_uno_firmware:

1. Actualizar el firmware del UNO R3
------------------------------------------

La placa R3 incluye firmware integrado que permite la comunicación con la aplicación RoboPilot y Mammoth Coding. Puede reinstalarlo con el grabador web, que no necesita software adicional en su ordenador.

**Método 1: Grabador web**

#. Encienda el GalaxyRVR, conecte el cable USB A a B (no el cable USB Type-C) a la **placa principal** y ponga el interruptor **Upload** del coche en el extremo de grabación.

#. Antes de grabar, retire la ESP32 CAM de su ranura: comparte los mismos pines RX y TX con la placa R3, consulte :ref:`FAQ 7 <faq_r3_upload_bat>`.

#. En un ordenador, abra |link_galaxy_rvr_flasher| en **Chrome** o **Edge** y seleccione la versión del firmware:

   * La versión **2.0.0** es para la generación actual del GalaxyRVR.
   * La versión **1.1.0** es para la primera generación del GalaxyRVR.

   Si no está seguro de qué generación tiene, consulte la etiqueta de la caja o póngase en contacto con nosotros.

#. Haga clic en **Connect & Flash** y seleccione el puerto serie de su placa en el cuadro de diálogo. La actualización comienza automáticamente y termina en aproximadamente un minuto.

   .. image:: img/faq_web_flasher_en.png
      :width: 600
      :align: center

#. Cuando termine la actualización, vuelva a poner el interruptor en **Run**, vuelva a colocar la ESP32 CAM y encienda de nuevo el GalaxyRVR.

.. note::

   * Esta página usa Web Serial, así que utilice **Chrome** o **Edge** en un ordenador y asegúrese de que la página se abre mediante **https**. En Windows, puede confirmar que el controlador serie USB está instalado comprobando que aparece **USB-SERIAL CH340** en el Administrador de dispositivos.
   * Cierre otros programas que puedan estar usando el puerto serie, como el Arduino IDE, el monitor serie u otra pestaña del navegador.

**Método 2: Script de actualización**

.. note::

   Si está usando un Mac, siga la guía específica para macOS:

   :ref:`uno_firmware_mac`

#. Conecte el Arduino al ordenador con un cable USB A a B (no USB Tipo C) y coloque el interruptor de modo en **Upload**.

   .. image:: img/camera_upload.png
        :width: 500
        :align: center

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

   * El nombre de la red (SSID) es ``GalaxyRVR`` y la contraseña es ``12345678``.
   * Si ve una advertencia que indica "Sin acceso a Internet", elija la opción **"Mantener conexión".**

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Abra un navegador web en su dispositivo móvil y navegue a ``http://192.168.4.1`` para acceder a la página de actualización OTA de la ESP32 CAM.


.. note:: En esta página, verá las opciones de actualización OTA en una de dos interfaces. La Versión A (la primera) y la Versión B (la segunda) aparecerán dependiendo de la versión de su firmware. Simplemente seleccione los pasos de actualización correspondientes según la interfaz que vea.

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center


**Versión A**

   6. En la página OTA, seleccione el archivo de firmware e inicie la actualización:

      * Seleccione el archivo ``ai-camera-firmware-vX.X.X-ota.bin`` previamente descargado de su dispositivo y haga clic en **Add**.
      * Haga clic en el botón **Update** para iniciar la actualización del firmware y espere a que se complete.

      .. image:: img/faq_ota_a.png
         :width: 700

   #. Una vez completada la actualización, el nombre del punto de acceso WiFi del GalaxyRVR cambiará a "AI Camera-xxxxxx", y la contraseña seguirá siendo "12345678".


**Versión B**


   6. En la página **OTA**, verifique la versión actual del firmware mostrada en la página web.

      * Si su número de versión es **superior a 1.5.1**, no es necesaria una actualización. Puede omitir los pasos restantes y continuar directamente con :ref:`quick_start`.
      * Si la versión es **1.5.1 o inferior**, continúe con la actualización.

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center


   #. Toque **Upgrade Firmware**, seleccione el archivo de firmware y espere a que finalice la actualización:

      * Toque el botón **Upgrade Firmware** y seleccione el archivo ``ai-camera-firware.ino.x.x.x.bin`` previamente descargado de su dispositivo.
      * La actualización comenzará inmediatamente y generalmente toma 1-2 minutos. Una vez finalizada, seleccione **CONFIRM** para reiniciar el GalaxyRVR.

      .. image:: img/faq_ota_b.png
         :width: 700

   #. Una vez completada la actualización, el nombre del punto de acceso WiFi del GalaxyRVR cambiará a "AI Camera-xxxxxx", y la contraseña seguirá siendo "12345678".


3. Verificación de arranque
------------------------------

#. Encienda el GalaxyRVR y verifique la tira de luz inferior.

   * Antes de usar el GalaxyRVR por primera vez, cargue completamente la batería con el cable USB Tipo-C suministrado.
   * Encienda el interruptor de alimentación.
   * Cambie el modo a **Run** y presione el botón **Reset** en la placa R3.
   * La tira de luz inferior comenzará a parpadear para indicar un inicio exitoso.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

#. Verifique la tira de luz inferior.

   * Si la tira de luz inferior muestra una **luz verde parpadeante**, el firmware de la R3 se está ejecutando correctamente. Puede continuar con :ref:`quick_start`.
   * Si la tira de luz inferior parpadea en **otro color**, reinstale el firmware de la R3 con :ref:`update_uno_firmware`.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Su navegador no soporta la etiqueta de video.
        </video>

.. important::

   * Este firmware permite que el GalaxyRVR responda a los comandos de la aplicación.
   * No necesitará cargar ningún código adicional al usar la aplicación de control remoto RoboPilot o el software Mammoth Coding.
   * Ahora puede continuar con :ref:`quick_start` para comenzar su viaje con el GalaxyRVR.