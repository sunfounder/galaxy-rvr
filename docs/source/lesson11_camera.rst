.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirte?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy!


Lección 11: Explorando el Sistema Visual del Rover Marciano - Cámara y Control en Tiempo Real
==================================================================================================

¡Bienvenidos de nuevo, jóvenes exploradores! En la lección anterior, equipamos a nuestro Rover Marciano con la capacidad de "asentir" utilizando un mecanismo de inclinación. Ahora, ¡es el momento de darle "ojos" al Rover: la cámara!

En esta emocionante aventura, configuraremos el sistema de cámara del Rover. Aprenderás cómo transmitir las imágenes capturadas por la cámara del Rover a una página web, para que puedas ver exactamente lo que el Rover ve en tiempo real. ¡Imagina la emoción de experimentar el paisaje marciano desde la perspectiva del Rover!

La emoción no termina ahí, ya que también presentaremos la aplicación SunFounder Controller. Esta aplicación nos permitirá recibir una transmisión en vivo de lo que ve el Rover mientras navega, y podremos controlar el mecanismo de inclinación directamente desde nuestros smartphones o tabletas. ¡Es como tener un control remoto con pantalla incorporada!

Esto ofrece una experiencia aún más interactiva y atractiva con nuestro Rover. ¡Sigue atento para más aventuras!

    .. image:: img/app/camera_view_app.png

Objetivos de aprendizaje
---------------------------
* Comprender cómo establecer una conexión WiFi con la ESP32 CAM.
* Aprender cómo ver exactamente lo que ve el Rover en tiempo real.
* Aprender a usar la aplicación SunFounder Controller para crear un control remoto virtual y controlar el Rover Marciano.

Materiales necesarios
-------------------------
* Modelo del Rover Marciano (equipado con todos los componentes)
* Arduino IDE
* Computadora
* Tableta o smartphone con la aplicación SunFounder Controller instalada

Pasos del curso
-----------------

**Paso 1: Introducción a la ESP32 CAM**

En nuestra aventura anterior, equipamos a nuestro Rover Marciano con un par de "ojos" al integrar la ESP32 CAM. Hoy, vamos a aprender más sobre ella y haremos que realmente "vea".

.. image:: img/esp32_cam.png
    :width: 400
    :align: center

La ESP32 CAM, actuando como los ojos de nuestro Rover, es un módulo pequeño pero poderoso. No solo integra funcionalidades de Wi-Fi y Bluetooth, sino que también viene con una cámara compacta. Esta cámara permite a nuestro Rover capturar imágenes de su entorno.

Al igual que usamos nuestros ojos para observar el entorno, la ESP32 CAM puede "ver" lo que hay delante del Rover y enviar estos datos visuales a nuestro smartphone o computadora. ¡Esto nos permite ver todo lo que el Rover ve en tiempo real!

Es como si estuviéramos pilotando el Rover directamente, ¡observando no solo al propio Rover, sino también el mundo que explora! Increíble, ¿verdad? Así que, profundicemos en ello...


**Paso 2: Programando la Cámara del Rover y Visualizando la Transmisión**

Después de instalar la ESP32-CAM en nuestro Rover, ahora necesitamos darle vida.
Para hacerlo, utilizaremos el Arduino IDE para escribir un programa que controle 
la cámara, permita conectarse a WiFi y transmita las imágenes que captura.

Aquí te explico cómo hacerlo:

#. Instala la biblioteca ``SunFounder AI Camera``.

    * Abre el **Administrador de Bibliotecas** en Arduino IDE, busca "SunFounder Camera" y haz clic en **INSTALAR**.

        .. image:: img/camera_install_lib.png

    * Aparecerá una ventana emergente para la instalación de dependencias de la biblioteca. Haz clic en **INSTALAR TODO** y espera a que se complete el proceso.

        .. image:: img/camera_install_lib1.png

#. En el Arduino IDE, ingresa el siguiente código.

    En cuanto a las variables ``NAME``, ``TYPE`` y ``PORT`` en el código, no las abordaremos por ahora. Serán importantes en nuestro próximo paso para establecer una transmisión de video en tiempo real desde nuestro Rover Marciano.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b648e4-23e8-4b28-accd-aac171069116/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

    Observa que tenemos dos modos de conexión en el código: el modo **AP** y el modo **STA**. Puedes decidir cuál usar según tus necesidades específicas.

    * **Modo AP**: En este modo, el Rover crea un punto de acceso (nombrado como ``GalaxyRVR`` en nuestro código). Esto permite que cualquier dispositivo, como un teléfono móvil, tableta o computadora portátil, se conecte a esta red. Es útil cuando deseas controlar el Rover de manera remota en cualquier circunstancia. Sin embargo, ten en cuenta que esto hará que tu dispositivo no pueda conectarse temporalmente a Internet.

        .. code-block:: arduino

        // Modo AP
        #define WIFI_MODE WIFI_MODE_AP
        #define SSID "GalaxyRVR"
        #define PASSWORD "12345678"

    * **Modo STA**: En este modo, el Rover se conecta a tu red WiFi doméstica. Recuerda que tu dispositivo de control (como un móvil o tableta) también debe estar conectado a la misma red WiFi. Este modo permite que tu dispositivo mantenga su acceso regular a Internet mientras controla el Rover, pero limita el rango operativo del Rover al área de cobertura de tu red WiFi.

        .. code-block:: arduino

            // Modo STA
            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "TU SSID"
            #define PASSWORD "TU CONTRASEÑA"

#. Sube el código a nuestro Rover y dale vida a la ESP32 CAM.

    * La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Entonces, antes de subir el código, necesitarás liberar la ESP32-CAM deslizando este interruptor hacia el lado derecho para evitar conflictos o posibles problemas.

        .. image:: img/camera_upload.png
            :width: 600

    * Una vez que el código se haya subido correctamente, vuelve a deslizarlo hacia el lado izquierdo para iniciar la ESP32 CAM.

        .. note::
            Este paso y el anterior son necesarios cada vez que vuelvas a subir el código.

        .. image:: img/camera_run.png
            :width: 600
        
    * Abre el **Monitor Serial** y establece la velocidad de transmisión en 115200. Si no aparece ninguna información, presiona el **botón de reinicio** en el escudo GalaxyRVR para ejecutar el código nuevamente. Deberías ver una dirección IP en la salida del monitor serial. Esta es la dirección a la que la cámara de tu Rover está transmitiendo.

        .. image:: img/camera_serial.png


    * Ahora, ¡es el momento de ver lo que ve nuestro Rover! Abre un navegador web, recomendamos Google Chrome, e ingresa la URL que ves en el Monitor Serial, en el formato ``http://ip:9000/mjpg``.

        .. image:: img/camera_view.png

Y ¡voilá! Ahora deberías poder ver la transmisión en vivo desde la cámara de tu Rover. ¿No es asombroso pensar que estás viendo Marte (o quizás solo tu sala de estar) desde la perspectiva del Rover? ¡Como un verdadero científico de rovers en Marte!

Recuerda, esto es solo el comienzo. Hay mucho más por explorar y aprender. En nuestro próximo paso, exploraremos cómo controlar nuestro Rover mientras vemos la transmisión en vivo de la cámara. ¡Emocionante, verdad? ¡En marcha, exploradores!


**Paso 3: Controlar y Visualizar la Cámara Usando la Aplicación**

¿Alguna vez has deseado ver la transmisión visual del Rover Marciano directamente en tu smartphone mientras también puedes controlar su mecanismo de inclinación? ¡Ahora puedes hacerlo! Con la ayuda de la aplicación SunFounder Controller, podrás hacer precisamente eso. Sigue los pasos a continuación:

#. Instala la aplicación desde **App Store (iOS)** o **Google Play (Android)**.

#. Crea un controlador.

    * Para agregar un controlador en la aplicación SunFounder Controller, haz clic en el ícono **+**.

        .. image:: img/app/app1.png

    * Elige la plantilla **En blanco**, selecciona ya sea **Dual Stick** o **Single Stick** según tu preferencia. Ponle un nombre a tu nuevo controlador y haz clic en **Confirmar**.

        .. image:: img/app/camera_controller.png

    * Ahora estarás dentro del controlador. Haz clic en el ícono **+** en la sección D, luego selecciona **Slider** en el menú emergente.

    .. image:: img/app/camera_add_slider.png

    * Este control deslizante está diseñado para controlar el mecanismo de inclinación. Como aprendimos en la lección anterior, su rango es de 0 a 140. Por lo tanto, configuraremos estos valores como los valores mínimos y máximos para nuestro control deslizante.

        .. image:: img/app/camera_slider_set.png
    
    * Haz clic en el botón |app_save| en la esquina superior derecha para guardar este controlador.
    
#. Escribamos un código para capturar el valor del control deslizante:

    * Basándonos en el código anterior, cambiemos al modo AP, donde puedes configurar el SSID y la CONTRASEÑA como prefieras.
    
    .. code-block:: arduino
    
        // Modo AP
        #define WIFI_MODE WIFI_MODE_AP
        #define SSID "GalaxyRVR"
        #define PASSWORD "12345678"

    * A continuación, añadimos una función ``onReceive()`` para recibir los valores del SunFounder Controller y mostrarlos en el Monitor Serial. Utilizamos la función ``getSlider()`` para obtener el valor del control deslizante **slider**. Añadí un control deslizante en la Región D, pero si lo añadiste en otra región, necesitas cambiar ``REGION_D`` por tu región.

        .. code-block::

            void onReceive() {
                int16_t sliderD = aiCam.getSlider(REGION_D);
                Serial.print("Slider D: ");
                Serial.println(sliderD);
            }

            void setup() {
                ...
                // Configura la función que se ejecutará al recibir datos
                aiCam.setOnReceived(onReceive);
                ...
            }

    * Aquí tienes el código completo:

        .. raw:: html

            <iframe src=https://create.arduino.cc/editor/sunfounder01/b914aa48-85e7-4682-b420-89961cc761ca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
    * Antes de subir el código, asegúrate de que el interruptor esté deslizado hacia la derecha. 

        .. image:: img/camera_upload.png
            :width: 600

    * Después de que el código se haya subido correctamente, desliza el interruptor hacia la izquierda para iniciar la ESP32 CAM.

        .. image:: img/camera_run.png
            :width: 600

    * Cuando veas la siguiente información en el Monitor Serial, puedes pasar al siguiente paso.

        .. code-block:: arduino
        
            ...[OK]
            SET+PORT8765
            ...[OK]
            SET+START
            ...[OK]
            WebServer started on ws://192.168.4.1:8765
            Video streamer started on http://192.168.4.1:9000/mjpg
            WS+null

#. Conéctate a la red ``GalaxyRVR``.

    En este punto, debes conectar tu dispositivo móvil a la red de área local (LAN) proporcionada por el GalaxyRVR. 
    Al hacer esto, tanto tu dispositivo móvil como el Rover estarán en la misma red, lo que permitirá una comunicación fluida 
    entre las aplicaciones en tu dispositivo móvil y el Rover.

    * Encuentra ``GalaxyRVR`` en la lista de redes disponibles en tu dispositivo móvil (tableta o smartphone), ingresa la contraseña ``12345678`` y conéctate.

        .. image:: img/app/camera_lan.png

    * El modo de conexión predeterminado es **Modo AP**. Después de conectarte, puede aparecer un mensaje advirtiendo que no hay acceso a Internet en esta red WLAN. Elige continuar la conexión.

        .. image:: img/app/camera_stay.png

#. Conecta y activa el controlador.

    * Ahora, regresa al controlador que creaste antes (en mi caso, se llama "camera"). Usa el botón |app_connect| para vincular la aplicación SunFounder Controller con el Rover y establecer una línea de comunicación. Después de una breve espera, aparecerá ``GalaxyRVR(IP)`` (el nombre que asignaste en el código con ``#define NAME "GalaxyRVR"``). Haz clic en él para establecer la conexión. 

        .. image:: img/app/camera_connect.png

        .. note::
            Por favor, verifica que tu Wi-Fi esté conectado a ``GalaxyRVR`` si no ves el mensaje anterior después de un tiempo.

    * Una vez que veas el mensaje "Conectado exitosamente", presiona el botón |app_run|. Esto mostrará las imágenes en vivo de la cámara en la aplicación.

        .. image:: img/app/camera_view_app.png

    * Ahora, mueve el control deslizante y abre simultáneamente el monitor serial de Arduino IDE. Deberías ver datos similares a los que se muestran a continuación.

        .. code-block:: 
    
            Slider D: 105
            WS+null
            Slider D: 105
            WS+null
            Slider D: 105
            WS+null


#. Deja que el control deslizante controle el mecanismo de inclinación.

    Ahora que sabemos los valores transmitidos por el control deslizante, podemos usar estos valores directamente para rotar el servo.
     Por lo tanto, basado en el código anterior, añade las siguientes líneas para inicializar el servo y escribir el valor del control deslizante en el servo.

    .. code-block::

        ...
        #include <Servo.h>

        Servo myServo;  // crea un objeto servo
        myServo.write(int(sliderD));  // controla el servo para moverse al ángulo actual

        ...

        void onReceive() {
            ...
            myServo.write(int(sliderD));  // controla el servo para moverse al ángulo actual
        }

        void setup() {
            ...
            myServo.attach(6);  // adjunta el servo al pin 6
            ...
        }

    Aquí tienes el código completo:
    
    .. raw:: html
    
        <iframe src=https://create.arduino.cc/editor/sunfounder01/b737352b-2509-4967-8147-1fd6bdc7d19d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

    Sube el código anterior al GalaxyRVR, repite los pasos 4 y 5, vuelve a conectarte a la red ``GalaxyRVR`` y ejecuta nuevamente el controlador en 
    la aplicación SunFounder Controller. Luego podrás deslizar el control para controlar el mecanismo de inclinación del rover.

Ahora has aprendido a implementar el controlador SunFounder y cómo usar el control deslizante para controlar los movimientos del servo. Este proceso te permitirá interactuar con tu GalaxyRVR de una manera más intuitiva y directa.


**Paso 4: Reflexión y Resumen**

Usar la aplicación SunFounder Controller para operar tu Rover Marciano puede parecer un poco complicado al principio. Cada vez que modifiques tu código, tendrás que repetir los siguientes pasos:

* Antes de subir el código, asegúrate de que el interruptor esté deslizado hacia la derecha.

    .. image:: img/camera_upload.png
        :width: 600

* Una vez que el código se haya subido correctamente, desliza el interruptor hacia la izquierda para iniciar la ESP32 CAM.
* Conéctate a la red ``GalaxyRVR``.
* Conéctate y ejecuta el controlador.

Aunque estos pasos puedan parecer tediosos, son cruciales para el proceso. Después de repetirlos algunas veces, te familiarizarás más con el procedimiento.


Ahora que hemos terminado esta lección, reflexionemos sobre lo que hemos aprendido con algunas preguntas:

* En el proceso de crear un nuevo controlador, te encontraste con muchos tipos diferentes de bloques. ¿Has considerado para qué podría servir cada uno de ellos?
* ¿Es posible usar otros widgets para controlar el mecanismo de inclinación?
* ¿O incluso controlar directamente los movimientos del Rover Marciano?

¡Anticipemos nuestra exploración de estas preguntas en la próxima lección!
