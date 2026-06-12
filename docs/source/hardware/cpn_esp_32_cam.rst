.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

ESP32 CAM
=================

.. image:: img/esp32_cam.png
    :width: 500
    :align: center

L'ESP32-CAM è un modulo fotocamera molto piccolo con il chip ESP32-S che costa circa 10 dollari. Oltre alla fotocamera OV2640 e a diversi GPIO per collegare periferiche, dispone anche di uno slot per scheda microSD che può essere utile per memorizzare le immagini scattate con la fotocamera o per archiviare file da servire ai client.

Il modulo può funzionare indipendentemente come il sistema più piccolo, con dimensioni di soli 27*40,5*4,5mm e una corrente di deep sleep di soli 6mA.

L'ESP32-CAM può essere ampiamente utilizzato in varie applicazioni IoT, adatto per dispositivi smart domestici, controllo wireless industriale, monitoraggio wireless, identificazione wireless QR, segnali di sistemi di posizionamento wireless e altre applicazioni IoT. È una soluzione ideale per applicazioni IoT.



**Specifiche tecniche**

.. list-table::
    :widths: 25 50

    * - Modello modulo
      - ESP32-CAM
    * - Package
      - DIP-16
    * - Dimensioni
      - 27*40,5*4,5（±0,2）mm
    * - SPI Flash
      - default 32Mbit
    * - RAM
      - Interna 520KB + Esterna 8MB PSRAM
    * - Bluetooth
      - Standard Bluetooth 4.2 BR/EDR e BLE
    * - Wi-Fi
      - 802.11 b/g/n/e/i
    * - Interfacce supportate
      - UART、SPI、I2C、PWM
    * - Supporto scheda TF
      - fino a 4G
    * - Pin IO
      -  9
    * - Velocità porta seriale
      - default 115200 bps
    * - Formato output immagine
      - JPEG(solo OV2640 supportato),BMP,GRAYSCALE
    * - Gamma spettrale
      - 2400 ~2483,5MHz
    * - Tipo antenna
      - Antenna PCB a bordo, guadagno 2dBi
    * - Potenza di trasmissione
      - 802.11b\: 17±2 dBm (@11Mbps)
    * -
      - 802.11g\: 14±2 dBm (@54Mbps)
    * -
      - 802.11n\: 13±2 dBm (@MCS7)
    * - Sensibilità di ricezione
      - CCK, 1 Mbps\: -90dBm,
    * -
      - CCK, 11 Mbps\: -85 dBm
    * -
      - 6 Mbps (1/2 BPSK)\: -88 dBm
    * -
      - 54 Mbps (3/4 64-QAM)\: -70dBm
    * -
      - MCS7 (65 Mbps, 72,2 Mbps)\: -67dBm
    * - Consumo energetico
      - Flash spento\: 180mA\@5V,
    * -
      - Flash acceso e luminosità al massimo\: 310mA\@5V
    * -
      - Deep-sleep\: il consumo minimo può raggiungere 6mA\@5V
    * -
      - Moderm-sleep\: minimo 20mA\@5V
    * -
      - Light-sleep\: minimo 6,7mA\@5V
    * - Sicurezza
      - WPA/WPA2/WPA2-Enterprise/WPS
    * - Intervallo alimentazione
      - 4,75-5,25V
    * - Temperatura operativa
      - -20 ℃ ~ 70 ℃
    * - Ambiente di stoccaggio
      - -40 ℃ ~ 125 ℃ , < 90%UR


**Pinout ESP32-CAM**


La figura seguente mostra il pinout dell'ESP32-CAM (modulo AI-Thinker).

.. image:: img/esp32_cam_pinout.png
    :width: 800

* Ci sono tre pin **GND** e tre pin per l'alimentazione: 3,3V, 5V e 3,3V o 5V.
* **GPIO 1** e **GPIO 3** sono i pin seriali. Sono necessari per caricare il codice sulla scheda.
* Inoltre, **GPIO 0** svolge anche un ruolo importante, poiché determina se l'ESP32 è in modalità flashing o meno. Quando **GPIO 0** è collegato a **GND**, l'ESP32 è in modalità flashing.

* I seguenti pin sono collegati internamente al lettore di schede microSD:

* GPIO 14: CLK
* GPIO 15: CMD
* GPIO 2: Data 0
* GPIO 4: Data 1 (anche collegato al LED a bordo)
* GPIO 12: Data 2
* GPIO 13: Data 3

**Nota**

* Assicurati che la potenza in ingresso del modulo sia di almeno 5V 2A, altrimenti l'immagine potrebbe presentare linee d'acqua.
* Il pin ESP32 GPIO32 controlla l'alimentazione della fotocamera. Quando la fotocamera è in funzione, porta GPIO32 a livello basso.
* Poiché GPIO0 è collegato al XCLK della fotocamera, lascia GPIO0 in aria quando lo usi e non collegarlo a livello alto o basso.
* Il firmware predefinito è già incluso in fabbrica e non viene fornito alcun download aggiuntivo. Fai attenzione se devi masterizzare altro firmware.


**Documenti**

* Schema elettrico: |link_esp32cam_schematic|
* Specifiche della fotocamera (versione inglese): |link_cam_ov2640|

.. note::
    Tutte le informazioni sopra provengono da |link_aithiner|
