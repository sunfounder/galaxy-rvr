GalaxyRVRシールド
=========================

.. image:: img/galaxy_shield.jpg
    :width: 500
    :align: center

これはSunFounderによってArduino用に設計されたオールインワン拡張ボードで、モーター、RGBストリップ、障害物回避、グレースケール、ESP32 CAM、超音波モジュールなど様々なモジュールポートが含まれています。

この拡張ボードには組み込みの充電回路があり、PH2.0-3Pインターフェースのバッテリーを充電することができ、推定充電時間は130分です。

**ピンアウト**

.. image:: img/zeus_car_shield_pinout.png

* Charge Port
    * 5V/2AのUSB-Cポートに接続すると、130分でバッテリーを充電できます。

* **Battery Port**: 
    * 6.6V～8.4VのPH2.0-3P電源入力。
    * GalaxyRVRシールドとArduinoボードの両方に電力を供給します。

* Reset Button
    * このボタンを押すと、Arduinoボード上のプログラムがリセットされます。

* Indicators
    * **Charge Indicator**: USB-Cポートを通じてシールドが充電されているときに赤く光ります。
    * **Power Indicator**: 電源スイッチが「ON」位置にあるときに緑色に光ります。
    * **Battery Indicator**: 2つのオレンジ色のインジケーターが異なるバッテリーレベルを表し、充電中に点滅し、バッテリーが充電を必要とするときに消えます。

* Power Switch
    * ONにスライドさせてGalaxyRVRを起動します。

* :ref:`shield_motor_pin`
    * **Motor Port(Right)**: 3つのモーターを接続できますが、すべてのモーターは同じ **pins 2 and 3** によって制御されます。
    * **Motor Port(Left)**: 3つのモーターを接続できますが、すべてのモーターは同じ **pins 4 and 5** によって制御されます。
    * ポートタイプ: XH2.54, 2P。

* :ref:`shield_strip_pin`
    * 2つのRGB LEDストリップを接続するために、ストリップの3つのピンがそれぞれ **12、13、11** に接続されます。
    * ポートタイプ: ZH1.5, 4P。

* :ref:`shield_avoid_pin`
    * 2つのIR障害物回避モジュールを接続するために使用します。
    * **left obstacle avoidance module** は **pin 8** に、 **right obstacle avoidance module** は **pin 7** に接続されます。
    * ポートタイプ: ZH1.5, 3P。

* :ref:`shield_camera_pin`
    * カメラアダプターボードポート。
    * ポートタイプ: ZH1.5, 5P。

* :ref:`shield_ultrasonic_pin`
    * 超音波モジュールを接続するために、TrigとEchoの両方のピンがArduinoボードの **pin 10** に接続されます。
    * ポートタイプ: ZH1.5, 4P。

* Mode Switch
    * ESP32-CAMとArduinoボードは、同じRX（受信）とTX（送信）ピンを共有します。
    * そのため、コードをアップロードする際には、このスイッチを **right side** に切り替えてESP32-CAMの接続を切断し、衝突や潜在的な問題を避ける必要があります。
    * カメラを使用する必要があるときは、このスイッチを **left side** に切り替えて、ESP32-CAMがArduinoボードと通信できるようにします。

* SOLAR
    * これはソーラーパネル用のポートで、ソーラーパネルに接続するとバッテリーを充電することができます。
    * ポートタイプ: XH2.54, 2P。


.. _shield_ultrasonic_pin:

Ultrasonic Port
--------------------

こちらはZH1.5-4P超音波ポートのピンアウトで、TrigとEchoのピンがArduinoボードのピン10に接続されます。

.. image:: img/ultrasonic_shield.png

.. _shield_camera_pin:

Camera Adapter Port
----------------------

こちらはカメラアダプターインターフェースのピン図で、タイプはZH1.5-7Pです。

* TXとRXはESP32 CAM用です。

.. image:: img/camera_shield.png


.. _shield_avoid_pin:

Obstacle Avoidance Port
----------------------------

こちらは障害物回避ポートのピンアウトです。

.. image:: img/ir_shield.png


.. _shield_strip_pin:

RGB LED Strip Port
-------------------------

以下は2つのRGB LEDストリップのピンアウト図で、並列接続され、ピンアウトは同じです。

.. image:: img/rgb_shield.png



.. _shield_motor_pin:

Motor Port
---------------

こちらは2セットのモーターポートのピンアウトです。


.. image:: img/motor_shield.png
    :width: 600
    :align: center
