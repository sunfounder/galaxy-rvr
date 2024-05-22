.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

FAQ
==============

.. _install_lib:

Q1: コンパイルエラー：SoftPWM.h: そのようなファイルやディレクトリはありませんか？
---------------------------------------------------------------------------------

「Compilation error: SoftPWM.h: No such file or directory」というプロンプトが表示された場合、SoftPWMライブラリがインストールされていないことを意味します。

``SoftPWM`` と ``SunFounder AI Camera`` の2つの必要なライブラリを以下のようにインストールしてください。

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            お使いのブラウザはビデオタグをサポートしていません。
        </video>


Q2: avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e?
-----------------------------------------------------------------------------
ボードとポートが正しく選択されているにもかかわらず、 **Upload** ボタンをクリックした後に以下のメッセージが繰り返し表示される場合。

.. code-block::
    
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00
    At this point, you need to make sure that the ESP32 CAM is unplugged.

ESP32-CAMとArduinoボードは同じRX（受信）およびTX（送信）ピンを共有しています。そのため、コードをアップロードする前に、ESP32-CAMを一時的に切断して、衝突や潜在的な問題を避ける必要があります。

    .. image:: img/camera_upload.png
        :width: 600

コードが正常にアップロードされた後、ESP32 CAMを使用する必要がある場合は、左にスイッチを移動してESP32 CAMを起動する必要があります。

    .. image:: img/camera_run.png
        :width: 600

.. _stt_android:

Q3: AndroidデバイスでSTTモードを使用する方法は？
------------------------------------------------------------------------

STTモードは、Androidモバイルデバイスがインターネットに接続され、Googleサービスコンポーネントがインストールされている必要があります。

以下の手順に従います。

#. ``galaxy-rvr.ino`` ファイルのAPモードをSTAモードに変更します。

    * ``galaxy-rvr-main\galaxy-rvr`` ディレクトリ内にある ``galaxy-rvr.ino`` ファイルを開きます。
    * 次に、APモードに関連するコードをコメントアウトし、STAモードに関連するコードのコメントを解除し、自宅のWi-Fiの ``SSID`` と ``PASSWORD`` を入力します。

        .. code-block:: arduino

            /** Configure Wifi mode, SSID, password*/
            // #define WIFI_MODE WIFI_MODE_AP
            // #define SSID "GalaxyRVR"
            // #define PASSWORD "12345678"

            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "xxxxxxxxxx"
            #define PASSWORD "xxxxxxxxxx"

    * このコードを保存し、正しいボード（Arduino Uno）とポートを選択して、 **Upload** ボタンをクリックしてR3ボードにアップロードします。

#. Google Playで ``google`` を検索し、以下のアプリを見つけてインストールします。

    .. image:: img/google_voice.png

#. モバイルデバイスをコードに記載されたWi-Fiと同じものに接続します。

    .. image:: img/sta_wifi.png

#. SunFounder Controllerで以前に作成したコントローラーを開き、|app_connect| ボタンを介して ``GalaxyRVR`` に接続します。

    .. image:: img/app/camera_connect.png


#. |app_run| ボタンをクリックした後、 **STT(J)** ウィジェットをタップして押し続けると、聞いていることを示すプロンプトが表示されます。以下のコマンドを話して車を動かします。

    .. image:: img/app/play_speech.png

    * ``stop``：ローバーのすべての動きを停止させることができます。
    * ``forward``：ローバーを前進させます。
    * ``backward``：ローバーを後退させます。
    * ``left``：ローバーを左に曲げます。
    * ``right``：ローバーを右に曲げます。

Q4: ESP32 CAMファームウェアについて
---------------------------------------------------

こちらはESP32 CAMのファームウェアリンクです：|link_ai_camera_firmware|


Q5: ESP32 CAMに新しいファームウェアをフラッシュする方法
--------------------------------------------------------

カメラモジュールは通常工場出荷時にプリフラッシュされています。ただし、データの破損が発生した場合やファームウェアを更新する必要がある場合、Arduino IDEを使用して新しいファームウェアをフラッシュできます。以下がその方法です。

**1. プログラマーの準備**

#. まず、プログラマーを用意してください。

    .. image:: img/esp32_cam_programmer.png
        :width: 300
        :align: center

#. ESP32-CAMモジュールをプログラマーに挿入し、次にプログラマーをコンピューターに接続します。

    .. image:: img/esp32_cam_usb.jpg
        :width: 300
        :align: center

**2. ESP32ボードのインストール**

ESP32マイクロコントローラーをプログラムするには、Arduino IDEにESP32ボードパッケージをインストールする必要があります。以下の手順に従ってください。

#. **ファイル** に移動し、ドロップダウンメニューから **設定** を選択します。

    .. image:: img/install_esp321.png
        :width: 500
        :align: center

#. **設定** ウィンドウで、 **追加のボードマネージャーのURL** フィールドを見つけます。これを有効にするためにクリックしてテキストボックスを有効にします。

    .. image:: img/install_esp322.png
        :width: 500
        :align: center

#. 以下のURLを **追加のボードマネージャーのURL** フィールドに追加します: https://espressif.github.io/arduino-esp32/package_esp32_index.json。このURLはESP32ボードのパッケージインデックスファイルへのリンクです。変更を保存するために **OK** をクリックします。

    .. image:: img/install_esp323.png
        :width: 500
        :align: center

#. **ボードマネージャー** ウィンドウで **ESP32** を検索します。インストールを開始するために **インストール** ボタンをクリックします。これによりESP32ボードパッケージがダウンロードおよびインストールされます。

    .. image:: img/install_esp324.png
        :align: center

**3. 必要なライブラリのインストール**

#. **ライブラリマネージャー** から ``WebSockets`` ライブラリをインストールします。

    .. image:: img/esp32_cam_websockets.png
        :width: 500
        :align: center

#. 同じ手順で ``ArduinoJson`` ライブラリをインストールしてください。

    .. image:: img/esp32_cam_arduinojson.png
        :width: 500
        :align: center

**4. ファームウェアのダウンロードとアップロード**

#. こちらからファームウェアファイルをダウンロードしてください。

    * :download:`ai-camera-firmware <https://github.com/sunfounder/ai-camera-firmware/archive/refs/heads/main.zip>`

#. ダウンロードしたファームウェアファイルを解凍し、抽出されたフォルダの名前を ``ai-camera-firmware-main`` から ``ai-camera-firmware`` に変更します。

    .. image:: img/esp32_cam_change_name.png
        :align: center

#. Arduino IDEで ``ai-camera-firmware.ino`` ファイルを開きます。これにより関連するコードファイルも開かれます。

    .. image:: img/esp32_cam_ino.png
        :align: center

#. **ボード** -> **esp32** -> **ESP32 Dev Module** を選択します。

    .. image:: img/esp32_cam_board.png
        :width: 500
        :align: center

#. 正しいポートを選択してください。

    .. image:: img/esp32_cam_port.png
        :width: 400
        :align: center

#. **PSRAM** を有効にし、 **Partition Scheme** で **Huge APP** を選択してください。

    .. image:: img/esp32_cam_psram.png
        :width: 400
        :align: center

#. 最後に、ファームウェアをESP32-CAMにアップロードします。

    .. image:: img/esp32_cam_upload.png
        :width: 500
        :align: center

#. ファームウェアのアップロードが成功したら、詳細情報は以下のリンクで確認できます: https://github.com/sunfounder/ai-camera-firmware。
