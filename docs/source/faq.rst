.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Preguntas frecuentes
====================

1. ¿Por qué debería actualizar el firmware?
----------------------------------------------------------------------------------------

SunFounder mejora continuamente el firmware de GalaxyRVR para ofrecer una mejor experiencia. Recomendamos actualizar el firmware antes del primer uso para garantizar que todo funcione correctamente. La actualización del firmware garantiza:

* **Corrección de errores**: Resuelve problemas conocidos y mejora la estabilidad.
* **Compatibilidad con las aplicaciones**: La versión más reciente del firmware es necesaria para que la aplicación RoboPilot y Mammoth Coding funcionen correctamente.
* **Nuevas funciones**: Las actualizaciones del firmware pueden añadir nuevas capacidades y mejoras.
* **Mejor rendimiento**: Optimizaciones para la conectividad WiFi, la transmisión de la cámara y el control de los motores.

Para obtener instrucciones detalladas de actualización, consulte :ref:`update_firmware`.

.. note::
   Si prefiere no actualizar el firmware y desea seguir usando su configuración actual, puede consultar la `Documentación de GalaxyRVR v1 <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_.


2. ¿No se puede conectar a GalaxyRVR?
-------------------------------------------------------------------------------------------------

Si no puede conectarse a GalaxyRVR, compruebe lo siguiente:

1. **Revise la batería**: Observe los indicadores de batería en el rover. Si ambos LED están apagados, la batería está baja. Cargue el rover con un cable USB tipo C.
2. **Revise el ESP32 CAM**: Asegúrese de que el ESP32 CAM esté correctamente insertado en su ranura. Si el LED del ESP32 CAM no se enciende, es posible que el módulo de la cámara no esté recibiendo alimentación o esté dañado. El ESP32 CAM crea el punto de acceso WiFi; si no funciona, no aparecerá ninguna red.
3. **Revise el interruptor de modo**: Asegúrese de que el interruptor de modo esté en **Run** (no en **Upload**). El punto de acceso WiFi solo funciona en el modo Run.

   .. image:: img/camera_run.png
        :width: 500
        :align: center

4. **Reinicie la placa R3**: Después de cambiar al modo Run, pulse el botón **Reset** de la placa R3. La tira de luz inferior debería parpadear para indicar un inicio correcto.
5. **Revise la contraseña WiFi**: El nombre del punto de acceso (SSID) predeterminado es ``GalaxyRVR`` y la contraseña es ``12345678``. Asegúrese de haber introducido la contraseña correctamente.
6. **Interferencia WiFi**: Otros dispositivos en el mismo canal WiFi pueden causar problemas de conexión. Si sospecha que hay interferencias, intente :ref:`cambiar el canal WiFi <change_wifi_channel>`.
7. **Después de actualizar el firmware**: Si acaba de actualizar el firmware del ESP32 CAM y el WiFi dejó de funcionar, consulte :ref:`faq_wifi_after_update`.
8. **Verifique la conexión de su dispositivo móvil**: Si está usando GalaxyRVR en modo AP (predeterminado), conecte su dispositivo móvil al punto de acceso de GalaxyRVR. Si ha :ref:`configurado una red WiFi doméstica <ap_to_sta>`, asegúrese de que su dispositivo móvil esté conectado a la **misma** red WiFi doméstica.


3. ¿La luz inferior es naranja fijo y no aparece el punto de acceso WiFi?
----------------------------------------------------------------------------------------------

Si la tira de luz inferior de GalaxyRVR muestra una **luz naranja fija** y la red WiFi ``GalaxyRVR`` no aparece, la causa es una **incompatibilidad de versiones del firmware**:

- El firmware del **ESP32 CAM** sigue siendo una versión anterior (1.4.x o 1.3.x)
- El firmware de la **placa UNO R3** se ha actualizado a la versión 2.x
- La incompatibilidad de versiones impide la comunicación entre el ESP32 CAM y la UNO R3

Para resolverlo, siga estos pasos **en el orden exacto**:

#. **Primero, revierta el firmware de la UNO R3 a la versión 1.x**:

   Siga la guía en la documentación v1: `GalaxyRVR v1 — Cómo cargar el código galaxy-rvr.ino <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/faq.html#how-to-upload-the-galaxy-rvr-ino-code>`_

#. **Actualice ambos firmware siguiendo el orden ESP32 CAM → UNO R3**:

   Siga la guía actualizada: :ref:`update_firmware`

.. note::

   El orden es importante: actualice siempre primero el ESP32 CAM y luego la placa R3. Omitir el paso de reversión o cambiar el orden no solucionará el problema.



4. ¿La aplicación RoboPilot no puede conectar?
---------------------------------------------------------------------------------------

Si la aplicación RoboPilot no encuentra o no puede conectarse a su GalaxyRVR, compruebe lo siguiente:

1. **¿Está actualizado el firmware del ESP32 CAM?** Un firmware desactualizado del ESP32 CAM puede causar problemas de conexión. Siga :ref:`update_esp32_firmware` para verificar y actualizar.
2. **¿Está actualizado el firmware de la R3?** La placa R3 debe tener instalado el firmware de comunicación de fábrica. Si ha cargado código Arduino personalizado, este sobrescribirá dicho firmware y romperá la comunicación con RoboPilot. Siga :ref:`update_r3_firmware` para restaurarlo.
3. **¿El interruptor de modo está en Run?** El interruptor de modo debe estar en **Run** (no Upload) para que el punto de acceso WiFi funcione.
4. **¿Su dispositivo móvil está en la red WiFi correcta?** Conéctese al punto de acceso de GalaxyRVR (``GalaxyRVR`` / ``12345678``), o si configuró una WiFi doméstica, conéctese a esa misma red.
5. **Intente reiniciar**: Cambie al modo **Run** y pulse el botón **Reset**, luego intente conectar de nuevo.

Si nada de lo anterior funciona, pruebe con :ref:`faq_wifi_after_update`.


5. ¿La aplicación Mammoth Coding (Scratch) no puede conectar?
---------------------------------------------------------------------------------------

Si Mammoth Coding no puede conectarse a su GalaxyRVR, compruebe lo siguiente:

1. **¿Está actualizado el firmware del ESP32 CAM?** El ESP32 CAM gestiona la conexión WiFi de la que depende Mammoth Coding. Siga :ref:`update_esp32_firmware` para asegurarse de que está actualizado.
2. **¿Está actualizado el firmware de la R3?** Mammoth Coding requiere el firmware de comunicación de fábrica en la placa R3. Si ha cargado su propio código Arduino, el firmware de comunicación se sobrescribe. Siga :ref:`update_r3_firmware` para restaurarlo.
3. **¿El interruptor de modo está en Run?** El interruptor de modo debe estar en **Run** para que el punto de acceso WiFi esté activo.
4. **¿Su dispositivo móvil está en la red WiFi correcta?** Asegúrese de que su dispositivo esté conectado al punto de acceso de GalaxyRVR o a la misma red WiFi doméstica configurada en el rover.

.. note::
   Si desea utilizar **tanto** la programación Arduino como Mammoth Coding, tenga en cuenta que deberá volver a cargar el firmware de la R3 cada vez que cambie entre ellos.

.. _install_lib:

6. Error de compilación: ``SoftPWM.h`` o ``SunFounder_AI_Camera.h``: No such file or directory?
-------------------------------------------------------------------------------------------------
Si aparece el mensaje "Error de compilación: ``SoftPWM.h``: No such file or directory", significa que no tiene instalada la librería SoftPWM.

Instale las dos librerías necesarias ``SoftPWM`` y ``SunFounder AI Camera`` como se muestra a continuación.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Tu navegador no soporta la etiqueta de video.
        </video>

Para la librería ``SunFounder AI Camera``, debe seleccionar "INSTALL ALL" para instalar simultáneamente la dependencia ``ArduinoJson`` necesaria.

    .. image:: img/faq_install_ai_camera.png

7. avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e?
-----------------------------------------------------------------------------
Si el siguiente mensaje sigue apareciendo después de hacer clic en el botón **Upload** cuando la placa y el puerto se han seleccionado correctamente.

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00

En este punto, debe asegurarse de que el ESP32 CAM está desconectado.

El ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, primero debe desconectar el ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Después de que el código se haya cargado correctamente, si necesita usar el ESP32 CAM, debe mover el interruptor hacia la izquierda para iniciar el ESP32 CAM.

    .. image:: img/camera_run.png
        :width: 500
        :align: center

.. _change_wifi_channel:

8. ¿Cómo cambiar el canal WiFi?
----------------------------------

La banda WiFi de 2.4 GHz tiene canales del 1 al 13. El ESP32 admite los canales 1 al 11. Otros dispositivos que operen en el mismo canal pueden causar interferencias, lo que provoca problemas de conexión. Para mitigarlo, puede intentar cambiar el canal. De forma predeterminada, el canal está configurado en 1. Al seleccionar un nuevo canal, se recomienda saltarse 1 o 2 canales a la vez. Por ejemplo, si el canal actual es el 1, pruebe primero con el canal 3 y, si la señal sigue siendo deficiente, pase al canal 5.


#. Encienda el GalaxyRVR. Para activar el ESP32 CAM, mueva el interruptor de modo a la posición **Run** y pulse el botón **Reset** para reiniciar la placa R3.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Conecte su dispositivo móvil a la red WiFi de GalaxyRVR.

   * El nombre de la red (SSID) es ``GalaxyRVR`` y la contraseña es ``12345678``.
   * Si aparece una advertencia que indica "Sin acceso a Internet", seleccione la opción **"Mantener conexión"**.

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Abra un navegador web en su dispositivo móvil y vaya a la dirección ``http://192.168.4.1``. Esto le llevará al portal de actualización de firmware del ESP32-CAM.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. En la página **AP**, seleccione un canal diferente.

   * El canal predeterminado es el 1. Al seleccionar un nuevo canal, salte 1 o 2 canales a la vez (por ejemplo, del canal 1 al 3 y, si es necesario, al 5).

   .. image:: img/fap_ap_channel.jpg
        :width: 50%
        :align: center

#. Vuelva a la página **Base** y haga clic en el botón **Reboot** para reiniciar el GalaxyRVR. El GalaxyRVR ya está listo para funcionar con normalidad.

   .. image:: img/faq_firmware_reboot.png
        :width: 50%
        :align: center

9. Cómo actualizar el firmware del ESP32 CAM
-----------------------------------------------

Para garantizar la compatibilidad con las aplicaciones y un rendimiento óptimo, asegúrese de que el firmware de su ESP32 CAM esté actualizado.

Para obtener instrucciones detalladas paso a paso, consulte: :ref:`update_esp32_firmware`

10. Cómo restaurar el firmware de la placa R3
------------------------------------------------

La placa R3 de GalaxyRVR viene con un firmware compatible tanto con la aplicación RoboPilot como con Mammoth Coding.

Si ha sobrescrito este firmware y necesita restaurar la comunicación, siga :ref:`update_r3_firmware`.

.. _ap_to_sta:

11. Cómo configurar la conexión WiFi
-----------------------------------------------------

De forma predeterminada, GalaxyRVR funciona en **modo AP**, en el que crea su propio punto de acceso WiFi al que otros dispositivos pueden conectarse.

Si desea que GalaxyRVR se conecte a su **red WiFi doméstica**, siga los pasos que se indican a continuación:


#. Encienda el GalaxyRVR. Para activar el ESP32 CAM, mueva el interruptor de modo a la posición **Run** y pulse el botón **Reset** para reiniciar la placa R3.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Conecte su dispositivo móvil a la red WiFi de GalaxyRVR.

   * El nombre de la red (SSID) es ``GalaxyRVR`` y la contraseña es ``12345678``.
   * Si aparece una advertencia que indica "Sin acceso a Internet", seleccione la opción **"Mantener conexión"**.

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Abra un navegador web en su dispositivo móvil y vaya a la dirección ``http://192.168.4.1``. Esto le llevará al portal de actualización de firmware del ESP32-CAM.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. En la página **WiFi**, introduzca el nombre (SSID) y la contraseña de su red WiFi doméstica.

   .. image:: img/faq_wifi.png
        :width: 50%
        :align: center

#. Pulse el botón **CONFIRM**.

   * GalaxyRVR intentará conectarse a su WiFi doméstica.
   * Si la conexión se realiza correctamente, el icono giratorio se detendrá y aparecerá una marca de verificación.

#. Después de reiniciar, conecte su dispositivo móvil a la misma red WiFi doméstica.

#. Ahora puede conectarse a GalaxyRVR a través de la aplicación RoboPilot o Mammoth Coding.

.. _faq_wifi_after_update:

12. ¿Cómo restaurar los ajustes de fábrica del ESP32 CAM?
---------------------------------------------------------------------------------------

Si el punto de acceso WiFi de GalaxyRVR no aparece o no puede conectarse después de actualizar el firmware del ESP32 CAM, es posible que los datos antiguos de configuración WiFi almacenados en la memoria flash del ESP32 CAM estén causando un conflicto.

Para resolverlo, debe restaurar el ESP32 CAM a sus ajustes de fábrica borrando los datos almacenados. Esto se consigue puenteando los pines **IO13** e **IO15** del ESP32 CAM:

#. Apague el interruptor de alimentación de GalaxyRVR.
#. Localice los pines **IO13** e **IO15** en el módulo ESP32 CAM.

   .. image:: img/esp32cam_io1315.png
        :width: 300
        :align: center

#. Use un cable puente o unas pinzas para puentear (conectar) los pines **IO13** e **IO15**.
#. Manteniendo los pines puenteados, encienda el interruptor de alimentación de GalaxyRVR.
#. Observe el LED del ESP32 CAM; cuando **parpadee dos veces rápidamente**, retire el cable puente.

   .. image:: img/esp32cam_led.png
        :width: 300
        :align: center

#. Cambie el modo a **Run** y pulse el botón **Reset** de la placa R3.
#. El ESP32 CAM se iniciará ahora con su configuración borrada. Debería ver un punto de acceso llamado ``AI Camera-xxxxxx`` (donde ``xxxxxx`` es un identificador único) en la lista WiFi de su dispositivo. Conéctese usando la contraseña ``12345678``.
#. Después de reiniciar GalaxyRVR, el nombre del punto de acceso cambiará de ``AI Camera-xxxxxx`` a ``GalaxyRVR-xxxxxx``, lo que indica que los ajustes de fábrica se han restaurado correctamente.

.. note::
   Después de restaurar los ajustes de fábrica, deberá volver a configurar todos los ajustes de WiFi doméstica guardados previamente (:ref:`ap_to_sta`).


.. _uno_firmware_mac:

13. ¿Cómo actualizar el firmware de la R3 en macOS?
-------------------------------------------------------

La placa R3 incluye firmware integrado que permite la comunicación con la aplicación RoboPilot y Mammoth Coding.

Necesita volver a cargar este firmware si:

- Su dispositivo utiliza una versión de firmware anterior, o
- Ha grabado su propio código de Arduino y desea restaurar la compatibilidad.

Siga los pasos a continuación para reinstalar el firmware de comunicación.

#. Conecte el Arduino al ordenador con un cable USB y coloque el interruptor de modo en **Upload**.

   .. image:: img/camera_upload.png
        :width: 500

   .. note:: Use el puerto USB Tipo B (para conectar al Arduino), no el puerto USB Tipo C (solo para cargar).

#. Asegúrese de que los archivos de firmware se hayan descargado.

   * |download_galaxyrvr_filmware|

#. Extraiga el archivo descargado para obtener una carpeta ``output``. Haga clic derecho (o Control-clic) en la carpeta ``output`` y seleccione **New Terminal at Folder** del menú contextual.

   .. image:: img/faq_mac_firmware_open.png
      :width: 400

#. La Terminal se abrirá directamente en la carpeta ``output``.

   * Ejecute el comando ``bash update-arduino-firmware-mac.sh``
   * Luego ingrese el número del puerto COM detectado (por ejemplo, ``1``):

   .. image:: img/faq_mac_firmware_run.png
      :width: 600

#. Si aparece el mensaje **"avrdude not Opened"**:

   .. image:: img/faq_mac_firmware_avrdude.png
      :width: 300

#. Vaya a **Configuración del Sistema** > **Privacidad y seguridad** y haga clic en **Allow Anyway**.

   .. image:: img/faq_mac_firmware_allow.png
      :width: 600

#. Ejecute el script de nuevo: ``bash update-arduino-firmware-mac.sh``

   Esta vez podrá seleccionar **Open Anyway**. Ingrese su nombre de usuario y contraseña de administrador para permitir la operación.

   .. image:: img/faq_mac_firmware_anyway.png
      :width: 600

#. Una vez que aparezca el mensaje de éxito, puede desconectar el cable USB.

   .. image:: img/faq_mac_firmware_finish.png
      :width: 600

.. important::

   * Este firmware permite que el GalaxyRVR responda a los comandos de la aplicación.
   * No necesitará cargar ningún código adicional al usar la aplicación de control remoto RoboPilot o el software Mammoth Coding.
   * Ahora puede continuar con :ref:`quick_start` para comenzar su viaje con el GalaxyRVR.
