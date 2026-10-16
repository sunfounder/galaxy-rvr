.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _update_firmware:

Actualizar el firmware
==========================

Es posible que su dispositivo no tenga el firmware más reciente debido a las continuas mejoras del producto.
Recomendamos actualizar el firmware antes del primer uso para garantizar que todo funcione correctamente. La actualización del firmware garantiza:

* **Corrección de errores**: resuelve problemas conocidos y mejora la estabilidad.
* **Compatibilidad con las aplicaciones**: se requiere el firmware más reciente para que la aplicación RoboPilot y Mammoth Coding funcionen correctamente.
* **Nuevas funciones**: las actualizaciones de firmware pueden añadir nuevas capacidades y mejoras.
* **Mejor rendimiento**: optimizaciones de la conectividad WiFi, la transmisión de la cámara y el control de los motores.

.. note::
   Si prefiere no actualizar el firmware y desea seguir usando su configuración actual, puede consultar la `documentación de GalaxyRVR v1 <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_.


.. Video desactivado temporalmente: muestra el procedimiento de actualización antiguo y está desactualizado. Vuelva a habilitarlo cuando se grabe el nuevo video.
..
.. .. raw:: html
..
..    <iframe width="600" height="400" src="https://www.youtube.com/embed/Tl2W26pIQoU?si=98bbfUPc1g2cEz3A" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

.. _update_r3_firmware:

1. Actualizar el firmware del UNO R3
-------------------------------------

La placa R3 lleva el firmware que se comunica con la aplicación RoboPilot y Mammoth Coding. Reinstálelo con el grabador web: abra |link_galaxy_rvr_flasher| en **Chrome** o **Edge** en un ordenador — se ejecuta en su navegador, no necesita software adicional y muestra cada paso con su propia imagen.

El grabador tiene tres pasos:

#. **Connect** — Encienda el rover, conecte la placa principal a su ordenador con un cable USB A a B (no el cable Tipo C) y, a continuación, ponga el interruptor de modo en la posición **Upload**. Después, haga clic en **Next**.

   .. image:: img/flasher_step1.jpg
      :width: 500

#. **Flash** — Haga clic en **Connect & Flash**. En la ventana de puerto que aparece, elija el puerto de su placa (por ejemplo, ``USB Serial (COMxx)``), luego haga clic en **Connect** y comenzará la grabación. Si falla, simplemente vuelva a hacer clic en **Connect & Flash**.

   .. image:: img/flasher_step2.jpg
      :width: 500

#. **Debug** — Cuando finalice la grabación, verá lo siguiente en la ventana de registro, lo que confirma que el firmware se escribió y muestra la versión actual (**2.0.2**). Ignore ``Initialzing...`` y todo lo que aparece después en este momento: el rover sigue en modo **Upload**, por lo que todavía no puede comunicarse con la ESP32 CAM. Después, haga clic en **Next**.

   .. code-block::

      Reading firmwares/galaxy-rvr-2.0.2.hex
      Resetting the board...
      Connecting to the board...
      Firmware written.
      Verified - flash matches the file.

      ---------- serial open at 115200 ----------
      GalaxyRVR version 2.0.2
      Initialzing...
      SET+RESET
      ...SET+RESET
      ...SET+RESET
      ...[FAIL]

#. Ahora siga la indicación: encienda el interruptor de alimentación, vuelva a poner el interruptor de modo en su posición original y pulse el botón **Reset** de la placa R3.

   .. image:: img/flasher_step3_run.jpg
      :width: 500
   
#. La ventana de registro muestra entonces el firmware actual de la ESP32 CAM.

   * Si el firmware de la ESP32 CAM es **1.5.0 o superior**, el registro muestra el firmware de la UNO R3, el firmware de la ESP32 CAM y, por último, una dirección web como ``http://xxx.xxx.xx.xxx:9000/mjpg``.
   * Si es **inferior a 1.5.0**, la ventana de registro muestra que es necesario actualizar el firmware de la ESP32 CAM; continúe con :ref:`update_esp32_firmware`.

   .. image:: img/flasher_step3.jpg
      :width: 500


.. _update_esp32_firmware:

2. Actualizar el firmware de la ESP32 CAM
-----------------------------------------

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
      
      * Si su número de versión es **1.5.0 o superior**, no es necesaria una actualización. Puede omitir los pasos restantes y continuar directamente con :ref:`quick_start`.
      * Si la versión es **inferior a 1.5.0**, continúe con la actualización.

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center

   #. Toque **Upgrade Firmware**, seleccione el archivo de firmware y espere a que finalice la actualización:

      * Toque el botón **Upgrade Firmware** y seleccione el archivo ``ai-camera-firware.ino.x.x.x.bin`` previamente descargado de su dispositivo.
      * La actualización comenzará inmediatamente y generalmente toma 1-2 minutos. Una vez finalizada, seleccione **CONFIRM** para reiniciar el GalaxyRVR.

      .. image:: img/faq_ota_b.png
         :width: 700

   #. Una vez completada la actualización, el nombre del punto de acceso WiFi del GalaxyRVR cambiará a "AI Camera-xxxxxx", y la contraseña seguirá siendo "12345678".


3. Verificación del arranque
-----------------------------

* Antes de usar el GalaxyRVR por primera vez, cargue completamente la batería con el cable USB Tipo-C suministrado.
* Encienda el interruptor de alimentación.
* Cambie el modo a **Run** y presione el botón **Reset** en la placa R3.
* La tira de luz inferior parpadeará en **verde**, lo que indica un inicio correcto.

.. raw:: html

   <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=_idwN0kJrxbVW-5H" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>