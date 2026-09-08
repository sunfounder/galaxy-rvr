.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Sistema de Cámara del Rover
=========================================================================================

¡Bienvenidos de nuevo, jóvenes exploradores! En la Lección 10, equipamos nuestro Mars Rover con la capacidad de "asentir" usando un mecanismo de inclinación. ¡Ahora es momento de darle "ojos" a nuestro Rover: la cámara!

En este emocionante viaje, nos sumergiremos en la configuración del sistema de cámara del Rover. Aprenderás cómo transmitir las imágenes capturadas por la cámara del Rover a una página web, para que puedas ver exactamente lo que el Rover ve, en tiempo real. ¡Imagina la emoción de experimentar el paisaje marciano desde la perspectiva del Rover!

La emoción continúa mientras también presentamos la aplicación SunFounder Controller. Esta aplicación nos permite obtener una transmisión en vivo de la vista del Rover mientras se desplaza, y podemos controlar el mecanismo de inclinación directamente desde nuestros teléfonos inteligentes o tabletas. ¡Es como tener un control remoto con pantalla incorporada!

Objetivos de Aprendizaje
--------------------------
* Comprender cómo establecer una conexión WiFi con el ESP32 CAM.
* Aprender a ver exactamente lo que el Rover ve, en tiempo real.
* Aprender a usar la aplicación SunFounder Controller para crear un control remoto virtual y controlar el Mars Rover.

Materiales Necesarios
------------------------

* Modelo de Mars Rover (equipado con todos los componentes)
* Arduino IDE
* Computadora
* Tableta o teléfono inteligente con la aplicación SunFounder Controller instalada

Pasos del Curso
----------------------

**Paso 1: Introducción al ESP32 CAM**

En nuestra aventura anterior, equipamos nuestro Mars Rover con un par de "ojos" integrando el ESP32 CAM. Hoy, vamos a aprender más sobre él y realmente hacerlo "ver".

.. image:: img/esp32_cam.png
    :width: 400
    :align: center

El ESP32 CAM, que actúa como los ojos de nuestro Rover, es un módulo pequeño pero potente. No solo integra funcionalidades Wi-Fi y Bluetooth, sino que también viene con una cámara compacta. Esta cámara ayuda a nuestro Rover a capturar imágenes de su entorno.

Así como usamos nuestros ojos para observar nuestro entorno, el ESP32 CAM puede "ver" lo que tiene el Rover por delante y luego enviar estos datos visuales a nuestro teléfono inteligente o computadora. ¡Esto nos permite ver todo lo que el Rover ve en tiempo real!

Es como si estuviéramos pilotando el Rover directamente, ¡observando no solo el Rover en sí, sino también el mundo que explora! Increíble, ¿verdad? Entonces, profundicemos en ello...


**Paso 2: Programando la Cámara del Rover y Visualizando la Transmisión**

Después de instalar el ESP32-CAM en nuestro Rover, ahora necesitamos darle vida.
Para hacerlo, usaremos el Arduino IDE para escribir un programa que controle la cámara, le permita conectarse a WiFi
y transmita las imágenes que captura.

Así es como podemos hacerlo:

#. Instala la librería ``SunFounder AI Camera``.

    * Abre el **Administrador de Librerías** del Arduino IDE, busca "SunFounder Camera" y haz clic en **INSTALL**.

        .. image:: img/camera_install_lib.png

    * Aparecerá una ventana emergente para la instalación de las dependencias de la librería. Haz clic en **INSTALL ALL** y espera a que el proceso se complete.

        .. image:: img/camera_install_lib1.png

#. En el Arduino IDE, ingresa el siguiente código.

    Respecto a las variables ``NAME``, ``TYPE`` y ``PORT`` en el código, no las analicemos en este momento. Entrarán en juego en nuestro próximo paso. Solo ten en cuenta que estas variables serán importantes en nuestro próximo viaje para establecer una transmisión de video en tiempo real desde nuestro Mars Rover.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b648e4-23e8-4b28-accd-aac171069116/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


    Observa que tenemos dos modos de conexión en el código: el modo **AP** y el modo **STA**. Puedes decidir cuál usar según tus necesidades específicas.

    * **Modo AP**: En este modo, el Rover crea un punto de acceso (llamado ``GalaxyRVR`` en nuestro código). Esto permite que cualquier dispositivo, como un teléfono móvil, tableta o computadora portátil, se conecte a esta red. Esto es especialmente útil cuando deseas controlar el Rover de forma remota en cualquier circunstancia. Sin embargo, ten en cuenta que esto haría que tu dispositivo no pueda conectarse temporalmente a Internet.

        .. code-block:: arduino

            // AP Mode
            #define WIFI_MODE WIFI_MODE_AP
            #define SSID "GalaxyRVR"
            #define PASSWORD "12345678"

    * **Modo STA**: En este modo, el Rover se conecta a tu red WiFi doméstica. Recuerda que tu dispositivo de control (como un teléfono móvil o tableta) también debe estar conectado a la misma red WiFi. Este modo permite que tu dispositivo mantenga su acceso normal a Internet mientras controla el Rover, pero limita el rango operativo del Rover al área de cobertura de tu WiFi.

        .. code-block:: arduino

            // STA Mode
            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "YOUR SSID"
            #define PASSWORD "YOUR PASSWORD"

#. ¡Sube el código a nuestro Rover y dale vida al ESP32 CAM!

    * El ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de subir el código, deberás liberar primero el ESP32-CAM deslizando este interruptor hacia el lado derecho para evitar conflictos o problemas potenciales.

        .. image:: ../img/camera_upload.png
            :width: 600

    * Una vez que el código se haya subido correctamente, vuelve a colocarlo en el lado izquierdo para iniciar el ESP32 CAM.

        .. note::
            Este paso y el anterior son necesarios cada vez que vuelvas a subir el código.

        .. image:: img/camera_run.png
            :width: 600

    * Abre el **Monitor Serial** y configura la velocidad de transmisión en 115200. Si no aparece información, presiona el **botón Reset** en el shield GalaxyRVR para ejecutar el código nuevamente. Deberías ver una dirección IP en la salida del monitor serial. Esta es la dirección a la que la cámara de tu Rover está transmitiendo.

        .. image:: img/camera_serial.png


    * Ahora, ¡es momento de ver realmente lo que nuestro Rover ve! Abre un navegador web (recomendamos Google Chrome) e ingresa la URL que ves en el Monitor Serial, en el formato ``http://ip:9000/mjpg``.

        .. image:: img/camera_view.png

¡Y listo! Ahora deberías poder ver la transmisión en vivo de la cámara de tu Rover. ¿No es increíble pensar que estás viendo Marte (o tal vez solo tu sala de estar) desde la perspectiva del Rover? ¡Como un verdadero científico del Mars Rover!

Recuerda, esto es solo el comienzo. Hay mucho más por explorar y aprender. En nuestro próximo paso, exploraremos cómo controlar nuestro Rover mientras vemos la transmisión en vivo de la cámara. ¡Emocionante, ¿verdad?! ¡Adelante, exploradores!
