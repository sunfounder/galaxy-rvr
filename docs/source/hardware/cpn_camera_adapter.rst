.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

カメラアダプターボード
=======================

.. image:: img/cam_adapter_board.jpg
    :width: 500
    :align: center

* **RST**: ESP32-CAM をリセットするために使用します。
* **SCL**: QMC6310 のシリアルデータピンです。
* **SDA**: QMC6310 のシリアルクロックピンです。
* **RXD**: ESP32-CAM の RXD です。これらの 2 つのシリアルピン（RXD と TXD）を介して ESP32-CAM にコードをアップロードする必要があります。
* **TXD**: ESP32-CAM の TXD です。
* **5V**: 5V DC 電源入力です。
* **GND**: グランド入力です。

カメラアダプターボードは、その名前が示すように、ESP-32 CAM の拡張ボードです。ESP32-CAM を拡張してロボットに固定できるようにし、配線を容易にします。

.. image:: img/cam_adapter_esp32cam.png
    :width: 400
    :align: center

また、地磁気チップ QMC6310 はモーターの干渉を受けやすいため、このカメラアダプターボードに配置して、モーターからできるだけ離すようにしています。

.. image:: img/cam_adapter_qmc6310.png
    :width: 400
    :align: center

**仕様**

* 動作電圧: 5V
* インターフェースモデル: ZH1.5, 7P
* 寸法: 40mm x 27mm x 15mm
* 通信プロトコル: UART および I2C

**ドキュメント**

* PCB

.. image:: img/cam_adap_pcb_bottom.png
    :width: 300

.. image:: img/cam_adap_pcb_top.png
    :width: 300

* 回路図

.. image:: img/cam_adapter_sche.png


**QMC6310 について**

QMC6310 は 3 軸磁気センサーで、磁気センサーと信号調整 ASIC を 1 つのシリコンチップに統合しています。この LGA（ランドグリッドアレイ）パッケージは、モバイルおよびウェアラブルデバイスにおける電子コンパス、地図回転、ゲーム、パーソナルナビゲーションなどのアプリケーションを対象としています。

QMC6310 は、最先端の高分解能磁気抵抗技術に基づいています。カスタム設計の 16 ビット ADC ASIC と組み合わせることで、低ノイズ、高精度、低消費電力、オフセットキャンセル、温度補償という利点を提供します。QMC6310 は 1° から 2° のコンパス方位精度を実現します。I²C シリアルバスにより、容易なインターフェースが可能です。

QMC6310 は 1.2x1.2x0.53mm3 の表面実装 8 ピン LGA パッケージです。

* |link_qmc6310_datasheet|
