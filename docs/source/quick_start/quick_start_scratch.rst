.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

クイックプレイ with Scratch
==================================

この章では、 **Scratch（Mammoth Coding）でサンプルプロジェクトをすばやく開いて実行** し、GalaxyRVR を動作させる方法を学びます。

これらのスクリプトをゼロから作成する方法を学びたい場合は、:ref:`programming_scratch` の章を参照してください。

.. note::

    * GalaxyRVR の R3 ボードには、RoboPilot App と Mammoth Coding をサポートするファームウェアが付属しています。
    * ファームウェアを上書きしてしまい、通信を復元する必要がある場合は、:ref:`update_r3_firmware` に従ってください。


Scratch サンプルをすばやく開く方法
-------------------------------------

#. 以下のリンクからサンプルコードをダウンロードします：

   * |download_galaxyrvr_code|

#. ダウンロードしたファイルを解凍し、``scratch_codes`` フォルダーをモバイルデバイスに転送します。 **ES File Explorer** や **File Transfer Assistant** など、任意のファイル転送ツールを使用できます。

   .. image:: img/scratch_mobile_save.png
      :width: 400

#. **Google Play** または **Apple App Store** で **Mammoth Coding** を検索してインストールします。

   .. image:: img/scratch_app_install.png
      :width: 600

#. GalaxyRVR を起動します。

   * GalaxyRVR を初めて使用する前に、付属の Type-C USB ケーブルでバッテリーを完全に充電してください。
   * 電源スイッチをオンにします。
   * モードを **Run** に切り替え、R3 ボードの **Reset** ボタンを押します。
   * 底部のライトストリップが **緑色** に点滅し、起動成功を示します。

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. モバイルデバイスを GalaxyRVR の WiFi ネットワークに接続します。

   * ネットワーク名（SSID）は ``GalaxyRVR`` 、パスワードは ``12345678`` です。
   * 「インターネットなし」という警告が表示された場合は、 **「接続したままにする」** を選択してください。


     .. image:: ../img/camera_lan.png
        :width: 500

#. アプリで **File** > **Open from device** をタップして、ローカルファイルを参照します。

   .. image:: img/scratch_open_file.png
        :width: 600

#. ``.sb3`` ファイルを選択して開きます。

   .. image:: img/scratch_mobile_save.png
      :width: 400

#. 緑色の旗アイコンをタップしてスクリプトを開始します。

   .. image:: img/scratch_run.png

サンプル
---------------

**基本プロジェクト**

これらのプロジェクトは、Mammoth Coding で GalaxyRVR を制御するための基本コースです。GalaxyRVR の活用方法を段階的にガイドします。


* ``3_move.sb3`` ：方向キーを使用して GalaxyRVR の動きをリアルタイムで制御します。
* ``4_ultrasonic.sb3`` ：ローバーが前進し、超音波モジュールを使用して自動的に障害物を回避します。
* ``5_ultra_animate_jump.sb3`` ：ローバーが火星の表面で楽しそうに動き回るアニメーションシーンを作成します。
* ``6_ir_obstacle_avoid.sb3`` ：ローバーが前進し、IR センサーを使用して障害物を回避します。
* ``7_ir_obstacle_avoid_animate.sb3`` ：手で IR センサーをトリガーして、火星表面の岩をかわすローバースプライトを制御します。
* ``8_ir_ultrasonic_avoid.sb3`` ：ローバーが超音波センサーと IR センサーを一緒に使用して、障害物をスムーズに回避します。
* ``9_ir_ultrasonic_follow.sb3`` ：ローバーがあなたに追従します：あなたが前に立つと近づき、横に立つとあなたの方を向き、離れると停止します。
* ``10_rgb.sb3`` ：色付きのボールをタップして、ローバーの RGB ライトをその色で光らせます。
* ``10_rgb_animate.sb3`` ：押された方向キーに応じてローバーが移動し、ライトの色が変わります。
* ``1scratch_servo.sb3`` ：矢印キーを使用してローバーのカメラ角度を調整し、クリックで位置をリセットします。
* ``1scratch_servo_stage.sb3`` ：画面上の矢印をタッチしてドラッグし、ローバーのカメラをスムーズにリアルタイムで操作します。
* ``12_camera.sb3`` ：探索中にローバーの視点からライブカメラ映像を表示します。
* ``13_realtime_control.sb3`` ：Scratch を通じてローバーの動きとライトをリアルタイムで制御します。

**楽しいプロジェクト**

これらの楽しい Scratch プロジェクトには GalaxyRVR は必要ありません。
これらはすべて ``scratch_codes/fun/`` フォルダーにあります。

* ``1_scratch_balloon.sb3`` ：左の IR センサーを塞いで風船を膨らませます。割れたり落ちたりしないようにしましょう！
* ``2_flappy_parrot.sb3`` ：超音波センサーの上に手をかざしてオウムの飛行を制御し、竹の棒をかわします。
* ``3_shooting.sb3`` ：障害物回避モジュールを使用して照準を合わせ、ターゲットを撃ちます。
* ``4_eat_apple.sb3`` ：左の IR センサーで検出した手のジェスチャーを使って、カブトムシをリンゴまで誘導します。
* ``5_fishing.sb3`` ：適切なタイミングで左の IR センサーを塞いで魚を釣ります。
* ``6_sensitive_ball.sb3`` ：超音波センサーの上に手をかざしてボールを上下に動かします。線に触れると音と光がトリガーされます。
* ``7_tap_white_tile.sb3`` ：2 つの IR センサーを使用して黒いタイルをタップして得点します。白いタイルは避けてください！
