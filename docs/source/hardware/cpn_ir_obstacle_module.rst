.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Módulo de Evitación de Obstáculos por Infrarrojos
==================================================

Este es un módulo de evitación de obstáculos por infrarrojos que puede detectar la presencia de objetos delante de él. Se utiliza comúnmente en robots, sistemas de automatización y otros dispositivos inteligentes. Su rango de detección es de 2 cm a 40 cm, y los objetos de diferentes colores tienen diferentes niveles de reflectividad. Por lo tanto, cuanto más oscuro sea el objeto, menor será la distancia de detección.

.. image:: img/ir_avoid.png
    :width: 400
    :align: center

Aquí están las definiciones de los pines:

* **GND**: Tierra
* **+**: Alimentación, 3.3 ~ 5V DC.
* **Out**: Por defecto, permanece en nivel alto y solo baja cuando detecta un obstáculo.
* **EN**: Este pin **enable** (habilitación) decide cuándo debe funcionar el módulo. Por defecto, está conectado a GND, lo que significa que el módulo está siempre activo.


**Funcionamiento**

Este módulo contiene un par de componentes emisores y receptores de infrarrojos. Básicamente, el transmisor emite luz infrarroja; cuando la luz infrarroja emitida encuentra un obstáculo, se refleja y es recibida por el receptor. Al detectarlo, el indicador se enciende. Después del procesamiento del circuito, emite una se?al de nivel bajo.

.. image:: img/ir_receive.png
    :width: 600
    :align: center


El estado de nivel bajo del pin **EN** activa el módulo, con el puente (jumper) asegurando el pin **EN** a GND. Para controlar el pin EN mediante programación, retire el puente.

.. image:: img/ir_cap.png
    :width: 400
    :align: center

Hay dos potenciómetros en el módulo, uno para ajustar la potencia de transmisión y otro para ajustar la frecuencia de transmisión. Ajustando estos dos potenciómetros se puede modificar la distancia efectiva.

.. image:: img/ir_avoid_pot.png
    :width: 400
    :align: center


**Ajuste de la distancia de detección**

El rango de detección del módulo de evitación de obstáculos debe calibrarse con precisión para un rendimiento óptimo, ya que la configuración predeterminada de fábrica puede no coincidir con los requisitos específicos.

La calibración implica los siguientes pasos:

#. Alineación del módulo: Comience con el módulo de evitación de obstáculos del lado derecho. El transporte puede ocasionalmente desplazar la alineación del transmisor y receptor infrarrojos del módulo. Deben realinearse manualmente para garantizar la precisión.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
            Su navegador no soporta la etiqueta de video.
        </video>

#. Coloque un obstáculo a unos 20 cm directamente frente al módulo derecho. ?La caja en la que vino nuestro kit Rover es una buena opción para esto! Ahora, gire el potenciómetro del módulo hasta que la luz indicadora del módulo se encienda. Luego, siga moviendo el obstáculo hacia adelante y hacia atrás para verificar si la luz indicadora se enciende a la distancia deseada. Si la luz no se enciende a la distancia correcta o si permanece encendida sin apagarse, deberá ajustar el otro potenciómetro.

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
            Su navegador no soporta la etiqueta de video.
        </video>


#. Repita el mismo proceso para el otro módulo.

**Características**

* voltaje de operación: 3.3 V a 5 V
* salida: digital (encendido/apagado)
* umbral de detección: ajustable mediante 2 potenciómetros
* rango de distancia: 2 a 40 cm
* ajuste R5: ajuste de frecuencia 38 kHz (ya optimizado)
* ajuste R6: ajuste del ciclo de trabajo del LED IR (ya optimizado)
* temperatura de operación: -10 °C a +50 °C
* ángulo efectivo: 35°
* interfaz de E/S: interfaz de 4 hilos (- / + / S / EN)
* dimensiones: 45 x 16 x 10 mm
* peso: 9 g 
