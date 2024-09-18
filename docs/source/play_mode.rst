.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirte?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy!


.. _play_mode:

Modo de Juego
=================

¿Estás ansioso por comenzar tu viaje a Marte de inmediato? Nuestro Modo de Juego está perfectamente diseñado para aquellos que no pueden esperar para comenzar. Con el código precargado de fábrica, puedes saltar directamente a la acción después de ensamblar tu GalaxyRVR. Usa la aplicación SunFounder Controller, fácil de usar, para explorar sus múltiples funciones, incluida la conducción en primera persona, el cambio entre los modos de evasión de obstáculos y seguimiento, e incluso el control por voz.

.. raw:: html
    
    <video width="600" loop autoplay muted>
        <source src="_static/video/play_mode.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

Pero antes de lanzarte a explorar el Planeta Rojo, asegurémonos de que estés completamente preparado para la aventura. A continuación, encontrarás una Guía Rápida que te ayudará en este emocionante viaje.

.. note::

    * Si tu placa R3 ya tiene otro código cargado, pero quieres seguir usando el Modo de Juego, necesitarás descargar el código correspondiente.

        * :download:`GalaxyRVR Codes <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/main.zip>`

    * Instala |link_download_arduino|, luego :ref:`install_lib`

    * Después, abre el archivo ``galaxy-rvr.ino`` ubicado en el directorio ``galaxy-rvr-main\galaxy-rvr``.
    
    .. note:: En el programa de ejemplo, se te pedirá que conectes tu dispositivo móvil al punto de acceso emitido por GalaxyRVR, lo que te impedirá usar redes externas al mismo tiempo. Puedes :ref:`ap_to_sta`. Después de configurarlo en modo STA, siempre que tu dispositivo y GalaxyRVR estén en la misma WLAN, podrás controlar GalaxyRVR.

    * Mueve el interruptor a la derecha y luego haz clic en **Subir**.


    .. image:: img/camera_upload.png
        :width: 400
        :align: center


Guía rápida
---------------

#. Comencemos con el GalaxyRVR.

    * La primera vez que uses tu GalaxyRVR, se recomienda conectar un cable USB Tipo-C para cargar completamente la batería. Luego, enciende el dispositivo.
    
        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/play_start.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    * Para activar la ESP32 CAM, mueve el interruptor de modo a la posición **Run**, y presiona el botón de **reset** para reiniciar la placa R3. Verás una luz cian parpadeando en la tira inferior.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/play_reset.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

#. Instala `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ desde **APP Store(iOS)** o **Google Play(Android)**.


#. Conéctate a la red ``GalaxyRVR``.

    Para una comunicación óptima entre tu dispositivo móvil y el Rover, tendrás que conectarlos a la misma red local (LAN) proporcionada por GalaxyRVR.

    * Busca ``GalaxyRVR`` en la lista de redes disponibles en tu dispositivo móvil (tableta o smartphone), introduce la contraseña ``12345678`` y conéctate.

        .. image:: img/app/camera_lan.png

    * El modo de conexión predeterminado es **modo AP**. Después de conectarte, podría aparecer un aviso advirtiendo que no hay acceso a Internet en esta red. Si es así, elige "Permanecer conectado".

        .. image:: img/app/camera_stay.png

    



#. Configura un controlador.

    * Para crear un controlador en SunFounder Controller, toca el icono **+**.

        .. image:: img/app/app1.png

    * Existen controladores preconfigurados para algunos productos; en este caso, elige **GalaxyRVR**. Ponle un nombre o simplemente toca **Confirmar**.

        .. image:: img/app/play_preset.jpg
    
    * Una vez dentro, la aplicación buscará automáticamente el GalaxyRVR. Después de un momento, verás un aviso que dice "Conexión exitosa".

        .. image:: img/app/auto_connect.jpg

        .. note::

            * Si no se conecta, confirma que tu Wi-Fi está conectado a ``GalaxyRVR``.
            * También puedes tocar el botón |app_connect| para conectar manualmente. Después de una breve espera, deberías ver ``GalaxyRVR(IP)`` aparecer. Toca sobre él para establecer la conexión.

            .. image:: img/app/camera_connect.png
                :width: 300
                :align: center


    * Ahora, toca el botón |app_run| para habilitar la vista de video en vivo desde la cámara y controlar el coche usando los widgets proporcionados. 

        .. image:: img/app/play_run_view.jpg

#. Exploremos ahora las funciones de cada widget:

        * **Servo(D)**: Controla el mecanismo de inclinación de la cámara del Rover, permitiendo observar un rango más amplio.

        * :ref:`app_avoid`: Cambia el Rover al modo de evasión de obstáculos. Las distancias de detección predeterminadas para cada módulo de evitación de obstáculos pueden variar. Se requiere ajuste manual.

        * :ref:`app_follow`: Cambia el Rover al modo de seguimiento. Las distancias de detección predeterminadas para cada módulo de evitación de obstáculos pueden variar. Se requiere ajuste manual.

        * **Stop(I)**: Detiene inmediatamente todos los movimientos del Rover.

        * :ref:`app_speech_control`: Presiona este widget para iniciar el reconocimiento de voz y hacer que el Rover ejecute las acciones correspondientes.

        * **HeadLamp(M)**: Enciende/apaga el LED en la ESP32 CAM.
        * **Widgets de acelerador en K y Q**: El widget de acelerador en el área K controla los motores izquierdos del Rover, mientras que el de la Q controla los motores derechos. Coordinando ambos widgets, el GalaxyRVR puede moverse en cualquier dirección.

        * **Left IR(N)**: Muestra las lecturas del módulo de evitación de obstáculos izquierdo.

        * **Ultrasonic(O)**: Muestra la distancia medida por el módulo ultrasónico.

        * **Right IR(P)**: Muestra las lecturas del módulo de evitación de obstáculos derecho.


.. _app_avoid:

Evitación de obstáculos (E)
---------------------------------

Toca el widget **Avoid(E)** para activar el modo de evasión de obstáculos.

Antes de activar este modo, es posible que necesites ajustar los rangos de detección de los sensores según tu entorno actual, ya que las configuraciones de fábrica podrían no ser ideales para todas las situaciones.

Si el rango de detección de los dos módulos de infrarrojos es demasiado corto, el Mars Rover podría chocar con los obstáculos. Por el contrario, si el rango es demasiado largo, el Rover podría desviarse demasiado de un obstáculo, lo que podría interrumpir su navegación.

Así es como puedes ajustar los parámetros:

#. Comienza ajustando el módulo de evitación de obstáculos derecho. Durante el transporte, los golpes pueden hacer que el transmisor y el receptor del módulo infrarrojo se inclinen. Por lo tanto, deberás enderezarlos manualmente.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Coloca un obstáculo a unos 20 cm directamente frente al módulo derecho. La caja en la que vino nuestro kit del Rover es una buena opción para esto. Ahora, gira el potenciómetro en el módulo hasta que la luz indicadora encienda. Luego, sigue moviendo el obstáculo hacia adelante y hacia atrás para comprobar si la luz indicadora se enciende a la distancia deseada. Si la luz no se enciende en la distancia correcta o si permanece encendida sin apagarse, deberás ajustar el otro potenciómetro.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>


#. Repite el mismo proceso para el otro módulo.


.. _app_follow:

Seguimiento (F)
------------------

Cuando estés listo para activar el modo de seguimiento, simplemente toca el widget **Follow(F)**. Si no has ajustado previamente la distancia de detección de los módulos de evitación de obstáculos, deberás seguir los pasos en :ref:`app_avoid` primero.

Una vez en modo de seguimiento, el GalaxyRVR se moverá hacia un objeto que tenga frente a él o girará a la izquierda o derecha para seguir el movimiento del objeto.


.. _app_speech_control:

STT (J)
----------

STT significa "Speech to Text". La aplicación SunFounder Controller se integra con el motor de reconocimiento de voz de tu dispositivo móvil. Por lo tanto, cuando tocas y mantienes presionado el widget **STT(J)** en el SunFounder Controller y hablas en tu dispositivo móvil, 

tu dispositivo capturará tu voz, la convertirá en texto y enviará ese texto al GalaxyRVR. Si este texto coincide con los comandos preestablecidos en tu código, el Rover ejecutará las acciones correspondientes.

Los siguientes son los comandos actualmente preestablecidos en el código. Di cualquiera de estos comandos y observa cómo responde el GalaxyRVR.

.. image:: img/app/play_speech.png
    :width: 600

* ``stop``: Detiene todos los movimientos del Rover.
* ``forward``: Hace que el Rover avance.
* ``backward``: Hace que el Rover retroceda.
* ``left``: Hace que el Rover gire a la izquierda.
* ``right``: Hace que el Rover gire a la derecha.


.. note::

    La función STT (Speech to Text) requiere una conexión a Internet y los servicios de Google en dispositivos Android. Sin embargo, esto no funciona con el modo AP (Access Point) preestablecido en el GalaxyRVR.
    
    En modo AP, el GalaxyRVR crea una red Wi-Fi local a la que tu dispositivo móvil puede conectarse, pero no proporciona acceso a Internet.
    
    Para usar la función STT en Android, cambia el código del Rover de modo AP a modo STA como se describe en :ref:`stt_android`.

.. note::

    Los dispositivos iOS, que utilizan un motor de reconocimiento de voz fuera de línea, funcionan bien tanto en los modos AP como STA. 

