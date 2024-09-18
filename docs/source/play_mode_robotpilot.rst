.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirte?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy!


.. _play_robopilot:

Juega con RoboPilot
======================

¿Estás ansioso por iniciar tu viaje a Marte de inmediato? 
Nuestro Modo de Juego está perfectamente diseñado para aquellos que no pueden esperar para comenzar. 
Con el código preinstalado de fábrica, puedes saltar directamente a la acción después de ensamblar tu GalaxyRVR. 
Usa la app amigable RoboPilot para explorar sus múltiples funciones, incluida la conducción en primera persona, 
cambiando entre los modos de evasión de obstáculos y seguimiento.


.. image:: img/robopilot/rp1_inter.png

Pero antes de que te lances a explorar el Planeta Rojo, asegurémonos de que estás completamente preparado para la aventura. 
A continuación, encontrarás una Guía Rápida que te asistirá en este emocionante viaje.

.. note::

    * Si tu placa R3 ya tiene otro código cargado pero deseas seguir usando el Modo de Juego, necesitarás descargar el código relevante.

        * :download:`GalaxyRVR Codes <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/scratch.zip>`

    * Instala |link_download_arduino| y luego :ref:`install_lib`

    * Luego, abre el archivo ``galaxy-rvr.ino`` ubicado en el directorio ``galaxy-rvr-scratch\galaxy-rvr``.
    
    * En el programa de ejemplo, se te pedirá que conectes tu dispositivo móvil al punto de acceso emitido por GalaxyRVR, lo que te impedirá usar redes externas al mismo tiempo. Puedes :ref:`ap_to_sta`. Después de configurarlo en modo STA, siempre que tu dispositivo y el GalaxyRVR estén en la misma WLAN, podrás controlar el GalaxyRVR.

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

    * Para activar la ESP32 CAM, mueve el interruptor de modo a la posición **Run**, y presiona el botón de **reset** para reiniciar la placa R3. Verás entonces una luz cian parpadeando en la tira inferior.

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/play_reset.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

#. Instala **RoboPilot** desde **APP Store (iOS)** o **Google Play (Android)**.

#. Conéctate a la red ``GalaxyRVR``.

    Para una comunicación óptima entre tu dispositivo móvil y el Rover, tendrás que conectarlos a la misma red local (LAN) proporcionada por GalaxyRVR.

    * Busca ``GalaxyRVR`` en la lista de redes disponibles en tu dispositivo móvil (tableta o smartphone), introduce la contraseña ``12345678`` y conéctate.

        .. image:: img/app/camera_lan.png

    * El modo de conexión predeterminado es **modo AP**. Después de conectarte, podría aparecer un aviso advirtiendo que no hay acceso a Internet en esta red. Si es así, elige "Permanecer conectado".

        .. image:: img/app/camera_stay.png

#. Abre RoboPilot. Haz clic en 'Go into' para ingresar a la interfaz de control.

.. image:: img/robopilot/rp1_inter.png



Control remoto
-----------------

Al entrar en la interfaz de control, verás la siguiente pantalla.
El fondo muestra la vista capturada por la cámara de GalaxyRVR, con widgets de control superpuestos.

.. image:: img/robopilot/rp2_page.png

Aquí están los controles:

A. Volver
B. Configuración: Aquí puedes cambiar el nombre del dispositivo, la configuración de WiFi, **ajustar el ángulo de la cámara** y desconectar.


    .. image:: img/robopilot/rp3_setting.png

C. Indicador de nivel de batería
D. Pausar el programa
E. Selección de modo: Aquí puedes elegir entre los modos de evitación de obstáculos y remoto. La configuración predeterminada es el Modo Remoto.


    .. image:: img/robopilot/rp4_mode.png

F. Monitor de obstáculos: Este módulo está dividido en tres áreas, con los lados izquierdo y derecho mostrando los resultados de los módulos de obstáculos, y el área central mostrando las lecturas del sensor ultrasónico.
G. Selector de color: Aquí puedes elegir el color de iluminación del chasis.


    .. image:: img/robopilot/rp5_color.png

H. Interruptor de LED de la cámara.
I. Ajustar el ángulo del gimbal, que varía de 0° a 135°. A 0°, mira hacia el cielo.
J. Mueve el joystick para controlar el movimiento del GalaxyRVR. Un suave empuje hará que el GalaxyRVR se mueva lentamente.



Detección de obstáculos
-------------------------

Cuando cambies a modo Obstacle, verás la siguiente interfaz.
De nuevo, el fondo muestra la vista desde la cámara del GalaxyRVR, con controles superpuestos del modo de obstáculos.


.. image:: img/robopilot/rp6_avoid.png

Aquí están los controles:

A. Ajustar la velocidad del GalaxyRVR.
B. Cambiar entre los modos **Avoid** y **Follow**.
C. Iniciar/detener el movimiento automático del GalaxyRVR.
D. Ajustar el ángulo del gimbal, que varía de 0° a 135°. A 0°, mira hacia el cielo.
E. Monitor de obstáculos: Este módulo está dividido en tres áreas, con los lados izquierdo y derecho mostrando los resultados de los módulos de obstáculos, y el área central mostrando las lecturas del sensor ultrasónico.


**Avoid (Evasión de obstáculos)**

.. Toca el widget **Avoid(E)** para activar el modo de evasión de obstáculos.

Antes de activar este modo, puede que necesites ajustar los rangos de detección de los sensores según tu entorno actual, ya que la configuración de fábrica podría no ser ideal para todas las situaciones.

Si el rango de detección de los dos módulos de infrarrojos es demasiado corto, el Rover podría chocar con los obstáculos. Por el contrario, si el rango es demasiado largo, el Rover podría desviarse demasiado de un obstáculo, lo que podría interrumpir su navegación.

Así es como puedes ajustar los ajustes:

#. Comienza ajustando el módulo de evitación de obstáculos derecho. Durante el transporte, los golpes pueden hacer que el transmisor y receptor del módulo infrarrojo se inclinen. Por lo tanto, deberás enderezarlos manualmente.

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


**Follow (Seguimiento)**

Si no has ajustado previamente la distancia de detección de los módulos de evitación de obstáculos, 
deberás seguir los pasos en **Avoid** primero.

Una vez en el modo de seguimiento, 
el GalaxyRVR se moverá hacia un objeto frente a él o girará a la izquierda o derecha para seguir el movimiento del objeto.



Reconexión
------------

Si tu red falla o se desconecta, serás dirigido a esta página.

.. image:: img/robopilot/rp7_reconnect.png

En este punto, restablece la configuración de red y luego haz clic en la IP correspondiente a tu GalaxyRVR para reconectarte.

