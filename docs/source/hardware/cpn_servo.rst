.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Servo
===========

Un servo es un motor especializado conocido por su precisión en el control de ángulos específicos.

.. image:: img/servo.png
    :align: center

* **Línea marrón**: GND
* **Línea naranja**: Pin de señal, conectar al pin PWM de la placa principal.
* **Cable rojo**: VCC

A diferencia de los motores convencionales que giran continuamente, un servo puede moverse a una posición precisa y mantenerla con exactitud. Esto se logra mediante una combinación de engranajes, un potenciómetro y un circuito de control. Los servos se utilizan comúnmente en diversas aplicaciones que requieren un control preciso de la posición de objetos o mecanismos.

**Características**

* **Tipo de motor**: Motor con núcleo
* **Voltaje de operación**: 4.8~6V DC
* **Corriente en reposo**: — mA
* **Corriente de consumo (a 4.8V sin carga)**: —0mA
* **Corriente de consumo (a 6V sin carga)**: —0mA
* **Corriente de bloqueo (a 4.8V bloqueado)**: —50mA
* **Corriente de bloqueo (a 6V bloqueado)**: —50mA
* **Par nominal**: 4.8V, —.6 kgf·cm; 6V, —.7 kgf·cm
* **Par máximo**: 4.8V, —.4 kgf.cm; 6V, —.6 kgf.cm
* **Velocidad sin carga**: 4.8V, —.14seg/60°; 6V, —.12seg/60°
* **Nota**: Protección contra torsión: —.9 kgf.cm; protección contra fallo de alimentación después de 5 segundos continuos
* **Rango de temperatura de operación**: -10℃~+50—* **Rango de temperatura de almacenamiento**: -20℃~+60—* **Rango de humedad de operación**: —90%HR
* **Rango de humedad de almacenamiento**: —90%HR
* **Peso**: 10±0.5g
* **Material**: ABS
* **Ángulo de operación**: 180°±10°(500~2500us)
* **Ángulo límite mecánico**: 360°
* **Ángulo de desplazamiento izquierda y derecha**: —6°
* **Desviación de centrado**: —1°
* **Juego**: —4 us
* **Tipo de amplificador**: Digital
* **Material del cable**: Ф1.08,19 PVC
* **Longitud del cable**: 245±5mm (sin incluir conectores)
* **Tipo de conector**: JR2.54mm/3Pin

**Principio de funcionamiento**

Dentro de un servo, componentes esenciales contribuyen a su funcionalidad única. En su núcleo, un servo incorpora un motor convencional, este motor está intrincadamente vinculado a un engranaje grande, que a su vez se acopla con un engranaje más pequeño en el eje del motor. Esta disposición de engranajes convierte eficientemente el movimiento circular rápido del motor en movimientos más lentos pero potentes.

.. image:: img/servo_internal.png

Pero la verdadera magia ocurre dentro del servo, gracias a una minúscula maravilla electrónica conocida como "potenciómetro" y un sofisticado "circuito de control". Cuando el servo se mueve, el potenciómetro gira, alterando su resistencia eléctrica. El circuito de control detecta e interpreta este cambio en la resistencia con una precisión notable, determinando así la posición exacta del servo. Esto es un testimonio de su ingenio.

En el ámbito del control de servos, entra en juego un método de señalización único llamado "modulación por ancho de pulso" o PWM. Al ajustar hábilmente la anchura de estos pulsos, los operadores pueden comandar al servo para que se mueva con precisión y mantenga su posición. Esta es la esencia de la tecnología de servomotores, un ámbito donde la precisión y el control convergen para permitir una gran variedad de aplicaciones.
