.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _rvr_move:

レッスン3：GalaxyRVRを遠隔操作しよう
============================================

コントロールを握る準備はできましたか？このレッスンでは、あなた自身のGalaxyRVRマーズローバーのミッションコマンダーになります。

コーディングの知識を実際の動作に変え、シミュレートされた火星の地形をローバーにナビゲートさせるプログラムを作成します。あなたのコマンドがローバーを動かし、教室で思い通りに操縦する様子を見守りましょう。

ここからあなたの火星ミッションが真に始まります。さあ、運転を始めましょう！

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      お使いのブラウザはこのビデオタグをサポートしていません。
   </video>

学習目標
-----------------------

* 必要なArduinoコードをアップロードして、Mammoth CodingアプリとGalaxyRVRの間の通信をセットアップする
* アプリの矢印キーインターフェースを使用してローバーの動きをマスターする
* 前進、後退、左折、右折の4つの基本動作をプログラムして実行する

.. _app_connect:

アプリをGalaxyRVRに接続する
-------------------------------------------

.. note::

    * ファームウェアを上書きしてしまい、通信を復元する必要がある場合は、:ref:`update_r3_firmware` に従ってください。

.. raw:: html

   <iframe width="560" height="315" src="https://www.youtube.com/embed/kZIrm-_yWrA?si=Cbp0TxN-EZU_6Ksn" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

#. GalaxyRVRを初めて使用する前に、付属のType-C USBケーブルでバッテリーを完全に充電してください。充電後、電源を入れます。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_start.mp4" type="video/mp4">
            お使いのブラウザはこのビデオタグをサポートしていません。
        </video>

#. ESP32 CAMを起動するには、モードを **Run** に切り替え、R3ボードの **Reset** ボタンを押します。下部のライトストリップが点滅し始め、起動が成功したことを示します。

   .. note::

      * 下部のライトストリップが **緑色以外の色で点滅している** 場合、GalaxyRVRのファームウェアを更新する必要があります。:ref:`update_firmware` を参照してください。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_reset_green.mp4" type="video/mp4">
            お使いのブラウザはこのビデオタグをサポートしていません。
        </video>

#. モバイルデバイスをGalaxyRVRのWi-Fiネットワークに接続します。

   * ネットワーク名（SSID）は ``GalaxyRVR``、パスワードは ``12345678`` です。
   * **「インターネットなし」** の警告が表示された場合は、** 「接続したままにする」** を選択してください。

     .. image:: ../img/camera_lan.png
        :width: 500

#. モバイルデバイスでアプリケーションを開き、接続プロセスを開始します。

   .. image:: img/connet_app_04.png

#. アプリ内でGalaxyRVR拡張機能を選択してロードします。

   .. image:: img/connet_app_05.png

#. アプリが自動的に利用可能なGalaxyRVRデバイスをスキャンして検索します。

   .. image:: img/connet_app_06.png

#. リストからGalaxyRVRを選択して接続します。

   .. image:: img/reconnect_2.png

   .. note::

      接続状態はGalaxyRVRのLEDライトで示されます：

      - **紫色の点滅** ：接続を検索中
      - **消灯** ：接続成功、準備完了

アプリの再接続
-------------------------------------

デバイスがGalaxyRVRから切断されると、インターフェースにこのポップアップウィンドウが表示されます。再接続をクリックします。

   .. image:: img/reconnect_0.png

ポップアップウィンドウを閉じた場合は、GalaxyRVRカテゴリのこのボタンをクリックして再接続することもできます。

   .. image:: img/reconnect_1.png

GalaxyRVRを見つけて、接続をクリックします。

   .. image:: img/reconnect_2.png


アプリでGalaxyRVRを制御する
-----------------------------------------

1. コーディングインターフェースで、ローバー制御ブロック専用のGalaxyRVRカテゴリを見つけます。

   .. image:: img/3_rvr_catego.png

2. 通常は緑色の旗を使用してプログラムを開始しますが、アクションをトリガーする他の方法もあります。イベントカテゴリにある ``上向き矢印キーが押されたとき`` ブロックを見つけます。これは特定のキーを押したときにコードを実行します。

   .. image:: img/3_rvr_when_arrow.png

3. 矢印の方向（上、下、左、右）ごとに1つずつ、4つのイベントブロックを作成します。これがローバーの制御システムの基礎となります。

   .. image:: img/3_rvr_4_arrow.png
        :width: 800
        :align: center

   .. note:: もっとコーディングスペースが必要ですか？緑色の旗の下にある目のアイコンをクリックすると、ステージエリアを一時的に非表示にできます。

4. 次に、各イベントブロックに対応する移動コマンドを追加します。

   - 上矢印 → 前進
   - 下矢印 → 後退
   - 左矢印 → 左折
   - 右矢印 → 右折

   .. image:: img/3_rvr_4_dir.png
        :width: 800
        :align: center

5. ステージ拡張ボタンをクリックして、フルコントロールモードに入ります。

   .. image:: img/3_rvr_stage.png

6. 拡大されたステージと仮想方向キーが表示されます。これらのキーを押して、GalaxyRVRの動きをリアルタイムで直接制御しましょう！

   .. image:: img/3_rvr_stage2.png


移動制御ブロック
-----------------------------

* **基本方向制御**

  GalaxyRVRの移動方向を制御します。ドロップダウンメニューから前進、後退、左折、右折を選択します。

  .. image:: img/block/move_forward.png

* **速度設定**

  GalaxyRVRの移動速度を設定します。注意：このブロックは速度を設定するだけで、それ自体では移動を開始しません。

  .. image:: img/block/move_set_speed.png

* **時間指定移動**

  選択した方向に指定した時間だけGalaxyRVRを移動させます。以下のことができます：

  * ドロップダウンから方向（前進/後退/左/右）を選択
  * 時間の値を変更して移動時間を設定

  .. image:: img/block/move_forward_1s.png

* **速度制御移動**

  特定の速度パーセントでGalaxyRVRを移動させます。以下のことができます：

  * ドロップダウンから移動方向を選択
  * 速度パーセント（0～100%）を調整

  .. image:: img/block/move_forward_80.png

* **精密移動制御**

  速度と時間の制御を組み合わせて正確な移動を実現します。以下のことができます：

  * 移動方向を設定
  * 速度パーセントを調整
  * 移動時間を設定

  .. image:: img/block/move_forward_80_1s.png

* **高度なホイール制御**

  各ホイールを個別に制御して複雑な操作を実現します。以下のことができます：

  * 左ホイールの速度を個別に設定
  * 右ホイールの速度を個別に設定
  * 移動時間を制御

  .. image:: img/block/move_lr_sp_1s.png

* **緊急停止**

  GalaxyRVRのすべての動きを即座に停止します。

  .. image:: img/block/move_stop.png
