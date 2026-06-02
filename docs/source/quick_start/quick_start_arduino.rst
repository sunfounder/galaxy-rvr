.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

クイックプレイ with Arduino
===============================

この章では、 **特定の Arduino サンプルコードをすばやく開いて実行** し、GalaxyRVR にさまざまな動作をさせる方法を学びます。

これらのサンプルのコードロジックやプログラミング原理を理解したい場合は、:ref:`programming_arduino` の章を参照してください。

Arduino サンプルをすばやく開く方法
-----------------------------------------

この例では、Arduino IDE を使用して Arduino サンプルを開く方法を説明します。

#. GalaxyRVR を起動します。

   * GalaxyRVR を初めて使用する際は、Type-C USB ケーブルを接続してバッテリーを完全に充電することをお勧めします。その後、電源をオンにします。

     .. raw:: html

          <video width="600" loop autoplay muted>
              <source src="../_static/video/play_start.mp4" type="video/mp4">
              お使いのブラウザはこのビデオタグをサポートしていません。
          </video>

    * ESP32-CAM と Arduino ボードは同じ RX（受信）および TX（送信）ピンを共有しています。そのため、コードをアップロードする前に、このスイッチを右側にスライドして ESP32-CAM を解放し、競合や潜在的な問題を回避する必要があります。

      .. image:: ../img/camera_upload.png
         :width: 600

#. USB ケーブルを使用して Arduino ボードをコンピューターに接続します。

#. |link_download_arduino| にアクセスし、お使いのオペレーティングシステム用の Arduino IDE をダウンロードします。インストールの指示に従ってセットアップを完了します。

   .. image:: img/arduino_download_page.png

#. 以下のリンクからサンプルコードをダウンロードします：

   * |download_galaxyrvr_code|

#. ダウンロードしたファイルを解凍し、``galaxy-rvr-1.2.x\lesson_codes`` に移動します。

   .. image:: img/arduino_open_folder.png

#. サンプルコードのフォルダーを選択し、そのフォルダーに移動して、``.ino`` ファイルをダブルクリックして Arduino IDE で開きます。

   .. image:: img/arduino_open_file.png

#. Arduino IDE で、ボードとして **Arduino Uno** を選択し、デバイスに適した ** ポート** を選択します。

   .. image:: img/arduino_choose_board.png

#. **Upload** ボタン（右向き矢印）をクリックして、コードをボードにアップロードします。

   .. image:: img/arduino_upload.png

.. note::

    Arduino IDE に慣れていない場合は、以下を参照してください：

    * :ref:`install_arduino_ide`
    * :ref:`upload_sketch`

サンプル
------------

* ``5_car_move`` ：ローバーが前進、後退、左右に旋回し、最後に停止します。
* ``6_ir_avoid`` ：ローバーが IR センサーを使用して障害物を回避します。
* ``7_ultrasonic_avoid`` ：ローバーが超音波モジュールを使用して障害物を回避します。
* ``8_ultrasonic_ir_avoid`` ：ローバーが IR と超音波モジュールの両方を使用して障害物を検出します。
* ``8_ultrasonic_ir_follow`` ：ローバーが IR と超音波モジュールを使用して物体を追跡します。
* ``9_rgb_car_move`` ：移動に色インジケーターを追加：前進は緑、後退は赤、左右旋回は黄色。
* ``10_servo_range`` ：カメラジンバルが for ループを使用して 0 ° から 180 ° まで回転し、現在の角度がシリアルモニターに表示されます。
* ``11_camera_view`` ：ウェブブラウザでローバーのカメラからのライブビデオ映像を表示します。 **SunFounder AI Camera** ライブラリが必要です。
* ``13_read_battery`` ：コードを通じてバッテリー電圧を監視します。
