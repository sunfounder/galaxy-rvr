.. note::

    Ciao, benvenuto nella comunità SunFounder di appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri entusiasti.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti esclusivi**: Approfitta di sconti speciali sui nostri prodotti più recenti.
    - **Promozioni e concorsi festivi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

ESP32 CAM
=================

.. image:: img/esp32_cam.png
    :width: 500
    :align: center

L'ESP32-CAM è un modulo fotocamera molto compatto con il chip ESP32-S, disponibile a un costo di circa 10 dollari. Oltre alla fotocamera OV2640 e a diversi GPIO per collegare i periferici, è dotato di uno slot per schede microSD, utile per memorizzare immagini catturate dalla fotocamera o per archiviare file da servire ai client.

Il modulo può funzionare in modo indipendente come il più piccolo sistema, con una dimensione di soli 27*40.5*4.5mm e una corrente di deep sleep di appena 6mA.

L'ESP32-CAM può essere ampiamente utilizzato in varie applicazioni IoT, risultando adatto per dispositivi intelligenti domestici, controllo wireless industriale, monitoraggio wireless, identificazione wireless tramite QR, sistemi di posizionamento wireless e altre applicazioni IoT. È una soluzione ideale per applicazioni IoT.

**Specifiche Tecniche**

.. list-table::
    :widths: 25 50

    * - Modello del Modulo
      - ESP32-CAM
    * - Package
      - DIP-16
    * - Dimensioni
      - 27*40.5*4.5（±0.2）mm
    * - Memoria SPI Flash
      - default 32Mbit
    * - RAM
      - Interna 520KB + Esterna 8MB PSRAM
    * - Bluetooth
      - Bluetooth 4.2 BR/EDR e BLE standard
    * - Wi-Fi
      - 802.11 b/g/n/e/i
    * - Interfacce supportate
      - UART, SPI, I2C, PWM
    * - Supporto scheda TF
      - fino a 4G
    * - Pin IO
      - 9
    * - Velocità Porta Seriale
      - default 115200 bps
    * - Formati immagine supportati
      - JPEG (solo OV2640 supportato), BMP, GRAYSCALE
    * - Gamma di frequenza
      - 2400 ~ 2483.5MHz
    * - Tipo di Antenna
      - Antenna PCB integrata, guadagno 2dBi
    * - Potenza di trasmissione
      - 802.11b: 17±2 dBm (@11Mbps) 
    * - 
      - 802.11g: 14±2 dBm (@54Mbps) 
    * - 
      - 802.11n: 13±2 dBm (@MCS7)
    * - Sensibilità di ricezione
      - CCK, 1 Mbps: -90 dBm 
    * - 
      - CCK, 11 Mbps: -85 dBm
    * - 
      - 6 Mbps (1/2 BPSK): -88 dBm
    * - 
      - 54 Mbps (3/4 64-QAM): -70 dBm
    * - 
      - MCS7 (65 Mbps, 72.2 Mbps): -67 dBm
    * - Consumo di energia
      - Flash spento: 180 mA\@5V
    * - 
      - Flash acceso e luminosità al massimo: 310 mA\@5V
    * - 
      - Deep-sleep: il consumo minimo può raggiungere 6mA\@5V
    * - 
      - Moderm-sleep: minimo 20mA\@5V
    * - 
      - Light-sleep: minimo 6.7mA\@5V
    * - Sicurezza
      - WPA/WPA2/WPA2-Enterprise/WPS
    * - Gamma di alimentazione
      - 4.75-5.25V
    * - Temperatura operativa
      - -20 ℃ ~ 70 ℃
    * - Ambiente di conservazione
      - -40 ℃ ~ 125 ℃, < 90%RH


**Pinout ESP32-CAM**

La seguente immagine mostra il pinout dell'ESP32-CAM (modulo AI-Thinker).

.. image:: img/esp32_cam_pinout.png
    :width: 800

* Ci sono tre pin **GND** e tre pin di alimentazione: 3.3V, 5V e sia 3.3V che 5V.
* **GPIO 1** e **GPIO 3** sono i pin seriali. Sono necessari questi pin per caricare il codice sulla scheda. 
* Inoltre, **GPIO 0** gioca un ruolo importante, poiché determina se l'ESP32 è in modalità flashing o meno. Quando **GPIO 0** è collegato a **GND**, l'ESP32 è in modalità flashing.

I seguenti pin sono internamente collegati al lettore di schede microSD:

* GPIO 14: CLK
* GPIO 15: CMD
* GPIO 2: Data 0
* GPIO 4: Data 1 (collegato anche al LED integrato)
* GPIO 12: Data 2
* GPIO 13: Data 3

**Nota**

* Assicurati che l'alimentazione di ingresso del modulo sia di almeno 5V 2A, altrimenti l'immagine potrebbe presentare delle linee d'acqua.
* Il pin GPIO32 dell'ESP32 controlla l'alimentazione della fotocamera. Quando la fotocamera è in funzione, abbassa GPIO32.
* Poiché GPIO0 è collegato al segnale XCLK della fotocamera, lascialo libero quando lo utilizzi e non collegarlo a livelli alti o bassi.
* Il firmware predefinito è già incluso nella fabbrica, e non è previsto alcun download aggiuntivo. Presta attenzione se devi reinstallare un altro firmware.

**Documenti**

* Schema a blocchi: |link_esp32cam_schematic|
* Specifiche della fotocamera (versione in inglese): |link_cam_ov2640|

.. note::
    Tutte le informazioni sopra riportate provengono da |link_aithiner|
