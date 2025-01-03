.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！


.. _quick_start:

アプリで簡単プレイ
=========================

火星探検をすぐに始めましょう！工場出荷時にプリロードされたコードで、組み立て後すぐにGalaxyRVRを使用できます。サンファウンダーコントローラーアプリを通じて、一人称視点の運転、障害物回避、追従モード、音声制御などの機能を体験してください。冒険を始める準備はできましたか？

.. raw:: html
    
    <video width="600" loop autoplay muted>
        <source src="_static/video/play_mode.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

.. note::  

    R3ボードに他のコードがプログラムされている場合、アプリを使用してGalaxyRVRを制御するには、 :ref:`upload_galaxy_code` の手順に従ってください。

簡単ガイド
---------------------

#. GalaxyRVRの始動。

   * 初めてGalaxyRVRを使用する場合は、Type-C USBケーブルを接続してバッテリーを完全に充電することをお勧めします。その後、電源をオンにします。
    
     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_start.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

   * ESP32 CAMを起動するには、モードスイッチを **Run** 位置に移動し、 **リセット** ボタンを押してR3ボードを再起動します。下部ストリップでシアンの光が点滅するのが見えます。

     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. **APP Store(iOS)** または **Google Play(Android)** から `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ をインストールします。


#. ``GalaxyRVR`` ネットワークに接続。

   モバイルデバイスとローバー間の最適な通信のために、GalaxyRVRが提供する同じローカルエリアネットワーク（LAN）に接続する必要があります。


   * モバイルデバイス（タブレットまたはスマートフォン）で利用可能なネットワークリストから ``GalaxyRVR`` を見つけ、パスワード ``12345678`` を入力して接続します。

     .. note::

        * 現在の接続はGalaxyホットスポットへのものであり、インターネットアクセスはありません。ネットワークの切り替えを促された場合は、「接続を維持」を選択してください。
        * :ref:`ap_to_sta`

     .. image:: img/app/camera_lan.png
        :width: 500


    
#. コントローラーを設定。

   * SunFounder Controllerでコントローラーを作成するには、**+** アイコンをタップします。

     .. image:: img/app/app1.png

   * 一部の製品にはプリセットコントローラーが利用可能です。ここでは **GalaxyRVR** を選択します。名前を入力するか、 **Confirm** をタップします。

     .. image:: img/app/play_preset.jpg
    
   * アプリが自動的にGalaxyRVRを検索します。しばらくすると、「Connected Successfully」というプロンプトが表示されます。

     .. image:: img/app/auto_connect.jpg

     .. note::

       * 接続されていない場合は、Wi-Fiが ``GalaxyRVR`` に接続されていることを確認してください。
       * また、 |app_connect| ボタンをタップして手動で接続することもできます。短時間待つと、 ``GalaxyRVR(IP)`` が表示されます。それをタップして接続を確立します。
     
       .. image:: img/app/camera_connect.png
           :width: 300
           :align: center


   * 次に、|app_run| ボタンをタップすると、カメラのライブビデオフィードを表示し、提供されたウィジェットを使用してローバーを操作できます。

     .. image:: img/app/play_run_view.jpg

#. 各ウィジェットの機能を確認しましょう：

   * **Servo(D)**: ローバーのカメラのチルト機構を制御し、広い範囲を観察できます。
   * :ref:`app_avoid`: ローバーを障害物回避モードに切り替えます。各障害物回避モジュールの工場設定距離は異なります。手動で調整が必要です。
   * :ref:`app_follow`: ローバーを追従モードに切り替えます。各障害物回避モジュールの工場設定距離は異なります。手動で調整が必要です。
   * **Stop(I)**: ローバーのすべての動きを即座に停止します。
   * :ref:`app_speech_control`: このウィジェットを押して音声認識を開始し、ローバーに対応するアクションを実行させます。
   * **HeadLamp(M)**: ESP32 CAMのLEDをオン/オフにします。
   * **KおよびQのスロットルウィジェット**: Kエリアのスロットルウィジェットはローバーの左モーターを制御し、Qエリアのスロットルウィジェットは右モーターを制御します。両方のウィジェットを調整することで、GalaxyRVRを任意の方向に移動させることができます。
   * **Left IR(N)**: 左の障害物回避モジュールの読み取り値を表示します。
   * **Ultrasonic(O)**: 超音波モジュールで測定された距離を表示します。
   * **Right IR(P)**: 右の障害物回避モジュールの読み取り値を表示します。

.. _app_avoid:

障害物回避(E)
------------------------

**Avoid(E)** ウィジェットをタップして、障害物回避モードを有効にします。

このモードを有効にする前に、現在の環境に応じてセンサーの検出範囲を調整する必要があります。工場設定はすべての状況に適しているわけではありません。

検出範囲が短すぎる場合、ローバーは障害物に衝突する可能性があります。逆に、範囲が長すぎる場合、障害物から遠くに迂回しすぎてナビゲーションが乱れる可能性があります。

設定を微調整する方法は以下の通りです：

#. 右の障害物回避モジュールを調整します。輸送中の衝撃により、赤外線モジュールの送信機と受信機が傾く場合があります。そのため、手動で真っ直ぐにする必要があります。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. 障害物を右のモジュールの正面約20cmに配置します。ローバーキットが入っていた箱が良い選択です。次に、モジュールのポテンショメータを回してインジケータライトが点灯するまで調整します。その後、障害物を前後に移動させ、希望する距離でインジケータライトが点灯するか確認します。ライトが正しい距離で点灯しない場合、または点灯したまま消えない場合は、別のポテンショメータを調整する必要があります。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. 他のモジュールについても同様の手順を繰り返します。


.. _app_follow:

追従(F)
------------

追従モードを有効にする準備ができたら、**Follow(F)** ウィジェットをタップしてください。事前に障害物回避モジュールの検出距離を調整していない場合は、:ref:`app_avoid` の手順に従う必要があります。

追従モードでは、GalaxyRVRは前方の物体に向かって移動したり、左右に旋回して物体の動きに追従します。


.. _app_speech_control:

STT(J)
-------------------

STTはSpeech to Textの略です。SunFounder Controllerアプリはモバイルデバイスの音声認識エンジンと連携します。そのため、SunFounder Controllerの**STT(J)** ウィジェットをタップして押し続けながらモバイルデバイスに話しかけると、

デバイスが音声をテキストに変換し、そのテキストをGalaxyRVRに送信します。このテキストがコードに設定されたコマンドと一致すると、ローバーが対応するアクションを実行します。

現在コードにプリセットされているコマンドは以下の通りです。これらのコマンドを話しかけて、GalaxyRVRの反応を確認してください。

.. image:: img/app/play_speech.png
    :width: 600

* ``stop``: ローバーのすべての動きを停止します。
* ``forward``: ローバーを前進させます。
* ``backward``: ローバーを後退させます。
* ``left``: ローバーを左に旋回させます。
* ``right``: ローバーを右に旋回させます。

.. note::

    STT（Speech to Text）機能は、Androidデバイスではインターネット接続とGoogleサービスが必要です。しかし、GalaxyRVRのプリセットAP（アクセスポイント）モードではこの機能は動作しません。
    
    AndroidでSTT機能を使用するには、:ref:`stt_android` の手順に従ってRoverのコードをAPモードからSTAモードに切り替える必要があります。

.. note::

    iOSデバイスはオフラインの音声認識エンジンを使用しているため、APモードとSTAモードの両方で問題なく動作します。
