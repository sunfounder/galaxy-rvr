ESP32 CAM
=================

.. image:: img/esp32_cam.png
    :width: 500
    :align: center

Das ESP32-CAM ist ein sehr kleines Kameramodul mit dem ESP32-S Chip, das ungefähr 10 Dollar kostet. Neben der OV2640 Kamera und mehreren GPIOs zum Anschluss von Peripheriegeräten verfügt es auch über einen microSD-Kartensteckplatz, der nützlich sein kann, um Bilder aufzunehmen oder Dateien für Kunden bereitzustellen.

Das Modul kann als das kleinste System unabhängig arbeiten, mit einer Größe von nur 27*40.5*4.5mm und einem Tiefschlafstrom von nur 6mA.

Das ESP32-CAM kann in verschiedenen IoT-Anwendungen weit verbreitet eingesetzt werden, geeignet für Heim-Smart-Geräte, industrielle drahtlose Steuerung, drahtlose Überwachung, QR-drahtlose Identifikation, drahtlose Positionierungssystemsignale und andere IoT-Anwendungen. Es ist eine ideale Lösung für IoT-Anwendungen.



**Technische Spezifikationen**

.. list-table::
    :widths: 25 50

    * - Modell
      - ESP32-CAM
    * - Gehäuse
      - DIP-16
    * - Größe
      - 27*40.5*4.5（±0.2）mm
    * - SPI Flash
      - Standard 32Mbit
    * - RAM
      - Intern 520KB + Extern 8MB PSRAM
    * - Bluetooth
      - Bluetooth 4.2 BR/EDR und BLE-Standards
    * - Wi-Fi
      - 802.11 b/g/n/e/i
    * - Unterstützte Schnittstellen
      - UART、SPI、I2C、PWM
    * - Unterstützt TF-Karte
      - bis zu 4G
    * - IO Pins
      -  9
    * - Serielle Portgeschwindigkeit
      - Standard 115200 bps
    * - Bildausgabeformat
      - JPEG(nur OV2640 unterstützt), BMP, GRAUSTUFE
    * - Spektrumbereich
      - 2400 ~2483.5MHz
    * - Antennentyp
      - On-Board PCB-Antenne, Gewinn 2dBi
    * - Sendeleistung
      - 802.11b\: 17±2 dBm (@11Mbps) 
    * - 
      - 802.11g\: 14±2 dBm (@54Mbps) 
    * - 
      - 802.11n\: 13±2 dBm (@MCS7)
    * - Empfindlichkeit
      - CCK, 1 Mbps\: -90dBm, 
    * - 
      - CCK, 11 Mbps\: -85 dBm
    * - 
      - 6 Mbps (1/2 BPSK)\: -88 dBm
    * - 
      - 54 Mbps (3/4 64-QAM)\: -70dBm
    * - 
      - MCS7 (65 Mbps, 72.2 Mbps)\: -67dBm
    * - Stromverbrauch
      - Flash aus\: 180mA\@5V, 
    * - 
      - Flash an und Helligkeit maximal\: 310mA\@5V
    * - 
      - Tiefschlaf\: der niedrigste Stromverbrauch kann 6mA\@5V erreichen
    * - 
      - Modem-Schlaf\: Minimum 20mA\@5V
    * - 
      - Licht-Schlaf\: Minimum 6.7mA\@5V
    * - Sicherheit
      - WPA/WPA2/WPA2-Enterprise/WPS
    * - Stromversorgungsbereich
      - 4.75-5.25V
    * - Betriebstemperatur
      - -20 ℃ ~ 70 ℃
    * - Lagerumgebung
      - -40 ℃ ~ 125 ℃ , < 90%RH


**ESP32-CAM Pinbelegung**


Die folgende Abbildung zeigt die Pinbelegung des ESP32-CAM (AI-Thinker Modul).

.. image:: img/esp32_cam_pinout.png
    :width: 800

* Es gibt drei **GND**-Pins und drei Pins für die Stromversorgung: 3.3V, 5V und entweder 3.3V oder 5V.
* **GPIO 1** und **GPIO 3** sind die seriellen Pins. Sie benötigen diese Pins, um Code auf Ihr Board hochzuladen. 
* Zusätzlich spielt auch **GPIO 0** eine wichtige Rolle, da es bestimmt, ob der ESP32 im Flash-Modus ist oder nicht. Wenn **GPIO 0** mit **GND** verbunden ist, ist der ESP32 im Flash-Modus.

* Die folgenden Pins sind intern mit dem microSD-Kartenleser verbunden:

* GPIO 14: CLK
* GPIO 15: CMD
* GPIO 2: Daten 0
* GPIO 4: Daten 1 (auch verbunden mit der an Bord befindlichen LED)
* GPIO 12: Daten 2
* GPIO 13: Daten 3

**Hinweis**

* Stellen Sie sicher, dass die Eingangsleistung des Moduls mindestens 5V 2A beträgt, da sonst das Bild Wasserlinien haben kann.
* Der ESP32 GPIO32-Pin steuert die Kameraleistung. Wenn die Kamera arbeitet, ziehen Sie bitte GPIO32 nach unten.
* Da GPIO0 mit dem Kamera-XCLK verbunden ist, lassen Sie GPIO0 in der Luft, wenn Sie es verwenden, und verbinden Sie es nicht mit hohem oder niedrigem Pegel.
* Die Standard-Firmware ist bereits in der Fabrik enthalten und es wird kein zusätzlicher Download bereitgestellt. Bitte seien Sie vorsichtig, wenn Sie andere Firmware neu brennen müssen.


**Dokumentation**

* Schaltplan: |link_esp32cam_schematic|
* Kameraspezifikation (englische Version): |link_cam_ov2640|

.. note::
    Alle oben genannten Informationen stammen von |link_aithiner|
