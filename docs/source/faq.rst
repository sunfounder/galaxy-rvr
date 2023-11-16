FAQ
==============

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
