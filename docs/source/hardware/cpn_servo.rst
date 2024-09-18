.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirte?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

Servo
===========

Un servo es un motor especializado conocido por su precisión en el control de posiciones angulares específicas.

.. image:: img/servo.png
    :align: center

* **Cable Marrón**: GND
* **Cable Naranja**: Pin de señal, conecta al pin PWM de la placa principal.
* **Cable Rojo**: VCC

A diferencia de los motores comunes que giran continuamente, un servo puede moverse a una posición precisa y mantenerla con exactitud. Esto se logra mediante una combinación de engranajes, un potenciómetro y circuitos de control. Los servos se utilizan comúnmente en aplicaciones que requieren un control preciso sobre la posición de objetos o mecanismos.

**Características**

* **Tipo de motor**: Motor con escobillas
* **Voltaje de operación**: 4.8~6V CC
* **Corriente en reposo**: ≤4 mA
* **Consumo de corriente (a 4.8V sin carga)**: ≦50mA
* **Consumo de corriente (a 6V sin carga)**: ≦60mA
* **Corriente de bloqueo (a 4.8V bloqueado)**: ≦550mA
* **Corriente de bloqueo (a 6V bloqueado)**: ≦650mA
* **Par nominal**: 4.8V, ≥0.6 kgf·cm; 6V, ≥0.7 kgf·cm
* **Par máximo**: 4.8V, ≥1.4 kgf.cm; 6V, ≥1.6 kgf.cm
* **Velocidad sin carga**: 4.8V, ≦0.14seg/60°; 6V, ≦0.12seg/60°
* **Nota**: Protección contra torsión: ≥0.9 kgf.cm; Desconexión automática después de 5 segundos de torsión continua.
* **Rango de temperatura de operación**: -10℃~+50℃
* **Rango de temperatura de almacenamiento**: -20℃~+60℃
* **Rango de humedad operativa**: ≤ 90% RH
* **Rango de humedad de almacenamiento**: ≤ 90% RH
* **Peso**: 10 ± 0.5g
* **Material**: ABS
* **Ángulo de operación**: 180°±10° (500~2500us)
* **Ángulo límite mecánico**: 360°
* **Ángulo de recorrido izquierdo/derecho**: ≤ 6°
* **Desviación de centrado**: ≤ 1°
* **Juego mecánico**: ≤ 4 us
* **Tipo de amplificador**: Digital
* **Material del cable**: Ф1.08,19 PVC
* **Longitud del cable**: 245±5mm (sin conectores)
* **Tipo de conector**: JR2.54mm/3Pin

**Principio de funcionamiento**

Dentro de un servo, componentes esenciales contribuyen a su funcionamiento único. En su núcleo, un servo incorpora un motor convencional, que está vinculado a un engranaje grande que, a su vez, se conecta a un engranaje más pequeño en el eje del motor. Este arreglo de engranajes convierte de manera eficiente el rápido movimiento circular del motor en movimientos más lentos pero potentes.

.. image:: img/servo_internal.png

Pero la verdadera magia ocurre dentro del servo, gracias a un diminuto componente electrónico conocido como "potenciómetro" y a un sofisticado "circuito de control". Cuando el servo se mueve, el potenciómetro gira, alterando su resistencia eléctrica. El circuito de control detecta e interpreta este cambio con notable precisión, determinando así la posición exacta del servo, lo que demuestra su ingenio.

En el ámbito del control de servos, entra en juego un método de señalización único llamado "modulación por ancho de pulso" o PWM. Al ajustar hábilmente la anchura de estos pulsos, los operadores pueden comandar al servo para moverse con precisión y mantener su posición. Esta es la esencia de la tecnología de motores servo, un campo donde convergen precisión y control para habilitar una amplia gama de aplicaciones.
