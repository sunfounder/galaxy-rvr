Preguntas Frecuentes
====================

1. No se puede conectar a GalaxyRVR?
-------------------------------------------------------------------------------------------------

Si no puede conectarse a GalaxyRVR, revise lo siguiente:

1. Revise los indicadores de batería en el rover. Si ambos LED están apagados, la batería está baja. Cargue el rover usando un cable USB Tipo-C.
2. Reinicie GalaxyRVR cambiando el modo a **Run** y presionando el botón **Reset**.
3. Verifique que su dispositivo móvil esté conectado al punto de acceso de GalaxyRVR.
4. Si ha configurado una red Wi-Fi doméstica, asegúrese de que su dispositivo móvil esté conectado a la **misma** red Wi-Fi doméstica.

.. _install_lib:

2. Error de compilación: ``SoftPWM.h`` o ``SunFounder_AI_Camera.h``: No such file or directory？
-------------------------------------------------------------------------------------------------
Si aparece el mensaje "Error de compilación: ``SoftPWM.h``: No such file or directory", significa que no tiene instalada la librería SoftPWM.

Instale las dos librerías requeridas ``SoftPWM`` y ``SunFounder AI Camera`` como se muestra.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Su navegador no soporta la etiqueta de video.
        </video>

Para la librería ``SunFounder AI Camera``, debe seleccionar "INSTALL ALL" para instalar simultáneamente la dependencia ``ArduinoJson`` requerida.

    .. image:: img/faq_install_ai_camera.png

3. avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e?
-----------------------------------------------------------------------------
Si el siguiente mensaje sigue apareciendo después de hacer clic en el botón **Upload** cuando la placa y el puerto se han seleccionado correctamente.

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00
    En este punto, debe asegurarse de que el ESP32 CAM esté desconectado.

El ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, primero debe desconectar el ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Después de que el código se haya cargado correctamente, si necesita usar el ESP32 CAM, debe mover el interruptor hacia la izquierda para iniciar el ESP32 CAM.

    .. image:: img/camera_run.png
        :width: 500
        :align: center

4. Cómo cambiar el canal Wi-Fi?
----------------------------------

La banda Wi-Fi de 2.4 GHz tiene canales del 1 al 13. El ESP32 admite los canales 1 al 11. Otros dispositivos que operan en el mismo canal pueden causar interferencias, lo que provoca problemas de conexión. Para mitigar esto, puede intentar cambiar el canal. De forma predeterminada, el canal está configurado en 1. Al seleccionar un nuevo canal, se recomienda saltar 1 o 2 canales a la vez. Por ejemplo, si el canal actual es 1, pruebe primero con el canal 3 y, si la señal sigue siendo deficiente, continúe con el canal 5.


#. Encienda GalaxyRVR. Para activar el ESP32 CAM, mueva el interruptor de modo a la posición **Run** y presione el botón **reset** para reiniciar la placa R3.

     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset_green.mp4" type="video/mp4">
            Su navegador no soporta la etiqueta de video.
        </video>

#. Conecte su dispositivo móvil a la red WiFi de GalaxyRVR.

   * El nombre de la red (SSID) es ``GalaxyRVR`` y la contraseña es ``12345678``.
   * Si ve una advertencia que indica "No Internet access", elija la opción de **"Stay connected"** (Mantener conexión).

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Abra un navegador web en su dispositivo móvil y vaya a la dirección ``http://192.168.4.1``. Esto lo llevará al portal de actualización de firmware del ESP32-CAM.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. En la página **AP**, seleccione un canal diferente.

   * El canal predeterminado es 1. Al seleccionar un nuevo canal, salte 1 o 2 canales a la vez (por ejemplo, del canal 1 al 3 y, si es necesario, al 5).

   .. image:: img/fap_ap_channel.jpg
        :width: 50%
        :align: center

#. Vuelva a la página **Base** y haga clic en el botón **Reboot** para reiniciar GalaxyRVR. GalaxyRVR ya está listo para funcionar con normalidad.

   .. image:: img/faq_firmware_reboot.png
        :width: 50%
        :align: center

5. Cómo actualizar el firmware del ESP32 CAM
----------------------------------------------------------

Para obtener instrucciones detalladas paso a paso, consulte: :ref:`update_firmware`

6. Cómo restaurar el firmware de la placa R3
-----------------------------------------------------------

La placa R3 de GalaxyRVR viene con un firmware que admite tanto la aplicación RoboPilot como Mammoth Coding.

Si ha sobrescrito este firmware y necesita restaurar la comunicación, siga :ref:`update_r3_firmware`.

.. _ap_to_sta:

7. Cómo configurar la conexión Wi-Fi
-----------------------------------------------------

De forma predeterminada, GalaxyRVR funciona en **modo AP**, donde crea su propio punto de acceso Wi-Fi al que otros dispositivos pueden conectarse.

Si desea que GalaxyRVR se conecte a su **red Wi-Fi doméstica**, siga los pasos a continuación:


#. Encienda GalaxyRVR. Para activar el ESP32 CAM, mueva el interruptor de modo a la posición **Run** y presione el botón **reset** para reiniciar la placa R3.

     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset_green.mp4" type="video/mp4">
            Su navegador no soporta la etiqueta de video.
        </video>

#. Conecte su dispositivo móvil a la red WiFi de GalaxyRVR.

   * El nombre de la red (SSID) es ``GalaxyRVR`` y la contraseña es ``12345678``.
   * Si ve una advertencia que indica "No Internet access", elija la opción de **"Stay connected"** (Mantener conexión).

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. Abra un navegador web en su dispositivo móvil y vaya a la dirección ``http://192.168.4.1``. Esto lo llevará al portal de actualización de firmware del ESP32-CAM.

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. En la página **WiFi**, introduzca el nombre de su red Wi-Fi doméstica (SSID) y la contraseña.

   .. image:: img/faq_wifi.png
        :width: 50%
        :align: center

#. Toque el botón **CONFIRM**.

   * GalaxyRVR intentará conectarse a su Wi-Fi doméstico.
   * Si la conexión es exitosa, el icono giratorio se detendrá y aparecerá una marca de verificación.

#. Después de reiniciar, conecte su dispositivo móvil a la misma red Wi-Fi doméstica.

#. Ahora puede conectarse a GalaxyRVR a través de la aplicación RoboPilot o Mammoth Coding.
