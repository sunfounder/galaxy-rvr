Servo
===========

Ein Servo ist ein spezialisierter Motor, der für seine Präzision bei der Steuerung bestimmter Winkelpositionen bekannt ist.

.. image:: img/servo.png
    :align: center

* **Braune Leitung**: GND (Erde)
* **Orangefarbene Leitung**: Signalleitung, an den PWM-Pin der Hauptplatine anschließen.
* **Rotes Kabel**: VCC (Spannungsversorgung)

Im Gegensatz zu herkömmlichen Motoren, die sich kontinuierlich drehen, kann ein Servo zu einer präzisen Position bewegt werden und diese genau halten. Dies wird durch eine Kombination aus Zahnrädern, einem Potentiometer und einer Steuerschaltung erreicht. Servos werden häufig in verschiedenen Anwendungen eingesetzt, bei denen eine präzise Steuerung der Position von Objekten oder Mechanismen erforderlich ist.

**Merkmale**

* **Motortyp**: Kernmotor
* **Betriebsspannung**: 4,8~6V DC
* **Bereitschaftsstrom**: ≤4 mA
* **Stromverbrauch (bei 4,8V Leerlauf)**: ≦50mA
* **Stromverbrauch (bei 6 V Leerlauf)**: ≦60mA
* **Blockierstrom (bei gesperrtem 4,8V)**: ≦550mA
* **Blockierstrom (bei gesperrtem 6V)**: ≦650mA
* **Nenndrehmoment**: 4,8V, ≥0,6 kgf·cm; 6V, ≥0,7 kgf·cm
* **Max. Drehmoment**: 4,8V, ≥1,4 kgf.cm; 6V, ≥1,6 kgf.cm
* **Leerlaufdrehzahl**: 4,8V, ≦0,14s/60°; 6V, ≦0,12s/60°
* **Hinweis**: Torsionsschutz: ≥0,9 kgf.cm; Stromausfallabschaltung nach 5 Sekunden Dauerbetrieb
* **Betriebstemperaturbereich**: -10℃~+50℃
* **Lagerungstemperaturbereich**: -20℃~+60℃
* **Betriebsfeuchtigkeitsbereich**: ≤ 90%RH
* **Lagerungsfeuchtigkeitsbereich**: ≤ 90%RH
* **Gewicht**: 10± 0,5g
* **Material**: ABS
* **Betriebswinkel**: 180°±10°(500~2500us)
* **Mechanischer Begrenzungswinkel**: 360°
* **Linker & Rechter Drehwinkel**: ≤ 6°
* **Mittellagenabweichung**: ≤ 1°
* **Spiel**: ≤ 4 us
* **Verstärkertyp**: Digital
* **Kabelmaterial**: Ф1.08,19 PVC
* **Kabellänge**: 245±5mm (ohne Stecker)
* **Steckertyp**: JR2.54mm/3Pin

**Funktionsprinzip**

Im Inneren eines Servos tragen wesentliche Komponenten zu seiner einzigartigen Funktionalität bei. Im Kern eines Servos befindet sich ein herkömmlicher Motor, der dem Motor ähnelt, der die Räder unseres Marsrovers antreibt. Um den Motor herum befindet sich ein großes Zahnrad, das wiederum mit einem kleineren Zahnrad auf der Motorwelle in Verbindung steht. Diese Getriebeanordnung verwandelt die schnelle kreisförmige Bewegung des Motors in langsamere, aber kraftvollere Bewegungen.

.. image:: img/servo_internal.png

Doch die eigentliche Magie geschieht im Inneren des Servos, dank eines winzigen elektronischen Wunders namens "Potentiometer" und einer anspruchsvollen "Steuerungsschaltung". So funktioniert es: Wenn der Servo sich bewegt, dreht sich das Potentiometer und ändert seinen elektrischen Widerstand. Die Steuerungsschaltung erkennt und interpretiert diese Änderung des Widerstands mit bemerkenswerter Präzision und bestimmt so die genaue Position des Servos. Dies ist ein Zeugnis seiner Raffinesse.

In der Welt der Servosteuerung kommt eine einzigartige Signalisierungsmethode namens "Pulsweitenmodulation" oder PWM zum Einsatz. Durch geschickte Anpassung der Breite dieser Impulse können Bediener den Servo präzise steuern und in einer bestimmten Position halten. Dies ist die Essenz der Servomotortechnologie, ein Bereich, in dem Präzision und Kontrolle zusammenkommen, um eine Vielzahl von Anwendungen zu ermöglichen.
