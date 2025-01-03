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

.. _upload_galaxy_code:

``galaxy-rvr.ino`` コードのアップロード方法は？
-----------------------------------------------

デフォルトでは、GalaxyRVR の Uno R3 ボードには必要なファームウェアがプリロードされており、APP を介して制御できます。他のコードで R3 ボードが上書きされている場合でも、デフォルトのファームウェアに戻し、:ref:`quick_start` のプロセスを続行したい場合は、以下の手順でコードを R3 ボードに再アップロードしてください：

#. USB ケーブルを使用して Arduino をコンピューターに接続します。その後、ローバーの **upload** スイッチを「upload」位置に切り替えます。

   .. image:: img/camera_upload.png
        :width: 400
        :align: center

#. 以下のリンクから必要なファームウェアをダウンロードします：
        
   * :download:`GalaxyRVR Codes <https://github.com/sunfounder/galaxy-rvr/releases/download/1.1.0/galaxy-rvr-1.1.0.zip>`

#. ダウンロードした zip ファイルを解凍し、 ``update-arduino-firmware.bat`` ファイルをダブルクリックして実行します。

   .. image:: img/faq_firmware_file.png

#. GalaxyRVR の Arduino Uno に対応する番号（例: ``2``）を入力し、**Enter** を押して更新を開始します。

   .. note::

     * 正しい COM ポートが表示されない場合やどれかわからない場合は、他の USB デバイスをコンピューターから取り外し、ローバーだけを接続してください。
     * 「avrdude.exe: stk500_getsync() attempt 1 of 10: not in sync: resp=0xXX」というエラーが発生した場合は、手順 1 で説明されているように、ローバーの **upload** スイッチが「upload」位置にあることを確認してください。

   .. image:: img/faq_firmware_port.png

#. しばらくすると、新しいコードが GalaxyRVR の Uno R3 ボードに正常にアップロードされます。

   .. image:: img/faq_firmware_finish.png

.. _ap_to_sta:

ホーム WiFi を使用してローバーを制御する方法は？
-------------------------------------------------
デフォルトでは、Uno R3 には APP モードで構成されたコードがプリロードされています。このため、GalaxyRVR はホットスポットをブロードキャストし、SunFounder Controller APP を介してモバイルデバイスで制御できます。

ホーム WiFi を使用してローバーを制御したい場合は、以下の手順で Uno ボードに修正済みのコードをアップロードしてください：

#. 以下のリンクから必要なファイルをダウンロードします：

   * :download:`GalaxyRVR Codes <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/main.zip>`

#. インストールガイドを参照してください：:ref:`install_arduino_ide`.

#. **ライブラリマネージャー** を使用して、 ``SoftPWM`` および ``SunFounder AI Camera`` ライブラリをインストールします。詳細な手順は :ref:`install_lib` を参照してください。

#. ``galaxy-rvr-main\galaxy-rvr`` ディレクトリに移動し、 ``galaxy-rvr.ino`` ファイルを開きます。

   .. image:: img/faq_galaxy_code.png

#. 行 69-71 をコメントアウトし、行 73-75 をコメント解除して、 ``SSID`` と ``PASSWORD`` をホーム WiFi の認証情報に置き換えます。

   .. image:: img/ap_sta.png
      :align: center

#. GalaxyRVR とコンピューターを USB ケーブルで接続し、ローバーの **upload** スイッチをアップロード端に切り替えます。

   .. image:: img/camera_upload.png
        :width: 400
        :align: center

#. Arduino IDE の **Upload** ボタンをクリックして、修正済みのコードを Uno ボードにアップロードします。

   .. image:: img/faq_galaxy_upload.png

#. ESP32 CAM を有効化するには、モードスイッチを **Run** 位置に移動し、**reset** ボタンを押して R3 ボードを再起動します。底部ストリップでシアンの光が点滅するのが見えます。

   .. raw:: html
   
       <video width="600" loop autoplay muted>
           <source src="_static/video/play_reset.mp4" type="video/mp4">
           Your browser does not support the video tag.
       </video>

#. モバイルデバイス（タブレットやスマートフォン）がホーム WiFi ネットワークに接続されていることを確認してください。

   .. image:: img/faq_connect_wifi.jpg
        :width: 400
        :align: center

#. SunFounder Controller App を開き、「+」アイコンをタップして新しいコントローラーを作成し、「GalaxyRVR」プリセットを選択し、名前を入力するか「Confirm」をタップして続行します。

   .. image:: img/app/play_preset.jpg
        :width: 600

#. アプリが自動的に GalaxyRVR を検索します。しばらくすると、「Connected Successfully」というプロンプトが表示されます。

   .. image:: img/app/auto_connect.jpg
        :width: 600
    
#. 次に、|app_run| ボタンをタップすると、カメラのライブビデオフィードを表示し、提供されたウィジェットを使用してローバーを制御できます。

   .. image:: img/app/play_run_view.jpg
        :width: 600 

カメラを反転する方法は？
---------------------------

SunFounder Controller を使用しているときにカメラフィードが上下逆になっている場合は、アプリを介して簡単に修正できます。以下の手順に従ってください：

1. 右上の |app_edit| ボタンをタップします。

   .. image:: img/app/faq_edit.png  
        :width: 500 

2. **カメラ** ボタンをクリックしてポップアップを開き、**Inverted** スイッチをオンにします。

   .. image:: img/app/faq_inverted.png  
        :width: 500  

3. 設定を保存します。

   .. image:: img/app/faq_save.png  
        :width: 500 

4. コントロールインターフェイスに戻り、|app_run| ボタンをクリックします。

   .. note::  

        時々、カメラフィードが表示されない場合があります。その場合は、コントローラーを一時停止してから再度実行ボタンをクリックしてください。

   .. image:: img/app/faq_run.png  
        :width: 500 

.. _install_lib:

コンパイルエラー：「SoftPWM.h」または「SunFounder_AI_Camera.h」：そのようなファイルやディレクトリはありません？
-----------------------------------------------------------------------------------------------------------------

「SoftPWM.h」：そのようなファイルやディレクトリがない」というプロンプトが表示される場合、それは SoftPWM ライブラリがインストールされていないことを意味します。

以下の手順で、必要なライブラリ ``SoftPWM`` と ``SunFounder AI Camera`` をインストールしてください：

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

``SunFounder AI Camera`` ライブラリの場合は、「INSTALL ALL」を選択して、必要な ``ArduinoJson`` 依存関係を同時にインストールします。

    .. image:: img/faq_install_ai_camera.png


.. _stt_android:

AndroidデバイスでSTTモードを使用する方法は？
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

ESP32 CAMファームウェアについて
---------------------------------------------------

こちらはESP32 CAMのファームウェアリンクです：|link_ai_camera_firmware|


.. ESP32 CAMに新しいファームウェアをフラッシュする方法
.. --------------------------------------------------------

.. カメラモジュールは通常工場出荷時にプリフラッシュされています。ただし、データの破損が発生した場合やファームウェアを更新する必要がある場合、Arduino IDEを使用して新しいファームウェアをフラッシュできます。以下がその方法です。

.. **1. プログラマーの準備**

.. #. まず、プログラマーを用意してください。

..     .. image:: img/esp32_cam_programmer.png
..         :width: 300
..         :align: center

.. #. ESP32-CAMモジュールをプログラマーに挿入し、次にプログラマーをコンピューターに接続します。

..     .. image:: img/esp32_cam_usb.jpg
..         :width: 300
..         :align: center

.. **2. ESP32ボードのインストール**

.. ESP32マイクロコントローラーをプログラムするには、Arduino IDEにESP32ボードパッケージをインストールする必要があります。以下の手順に従ってください。

.. #. **ファイル** に移動し、ドロップダウンメニューから **設定** を選択します。

..     .. image:: img/install_esp321.png
..         :width: 500
..         :align: center

.. #. **設定** ウィンドウで、 **追加のボードマネージャーのURL** フィールドを見つけます。これを有効にするためにクリックしてテキストボックスを有効にします。

..     .. image:: img/install_esp322.png
..         :width: 500
..         :align: center

.. #. 以下のURLを **追加のボードマネージャーのURL** フィールドに追加します: https://espressif.github.io/arduino-esp32/package_esp32_index.json。このURLはESP32ボードのパッケージインデックスファイルへのリンクです。変更を保存するために **OK** をクリックします。

..     .. image:: img/install_esp323.png
..         :width: 500
..         :align: center

.. #. **ボードマネージャー** ウィンドウで **ESP32** を検索します。インストールを開始するために **インストール** ボタンをクリックします。これによりESP32ボードパッケージがダウンロードおよびインストールされます。

..     .. image:: img/install_esp324.png
..         :align: center

.. **3. 必要なライブラリのインストール**

.. #. **ライブラリマネージャー** から ``WebSockets`` ライブラリをインストールします。

..     .. image:: img/esp32_cam_websockets.png
..         :width: 500
..         :align: center

.. #. 同じ手順で ``ArduinoJson`` ライブラリをインストールしてください。

..     .. image:: img/esp32_cam_arduinojson.png
..         :width: 500
..         :align: center

.. **4. ファームウェアのダウンロードとアップロード**

.. #. こちらからファームウェアファイルをダウンロードしてください。

..     * :download:`ai-camera-firmware <https://github.com/sunfounder/ai-camera-firmware/archive/refs/heads/main.zip>`

.. #. ダウンロードしたファームウェアファイルを解凍し、抽出されたフォルダの名前を ``ai-camera-firmware-main`` から ``ai-camera-firmware`` に変更します。

..     .. image:: img/esp32_cam_change_name.png
..         :align: center

.. #. Arduino IDEで ``ai-camera-firmware.ino`` ファイルを開きます。これにより関連するコードファイルも開かれます。

..     .. image:: img/esp32_cam_ino.png
..         :align: center

.. #. **ボード** -> **esp32** -> **ESP32 Dev Module** を選択します。

..     .. image:: img/esp32_cam_board.png
..         :width: 500
..         :align: center

.. #. 正しいポートを選択してください。

..     .. image:: img/esp32_cam_port.png
..         :width: 400
..         :align: center

.. #. **PSRAM** を有効にし、 **Partition Scheme** で **Huge APP** を選択してください。

..     .. image:: img/esp32_cam_psram.png
..         :width: 400
..         :align: center

.. #. 最後に、ファームウェアをESP32-CAMにアップロードします。

..     .. image:: img/esp32_cam_upload.png
..         :width: 500
..         :align: center

.. #. ファームウェアのアップロードが成功したら、詳細情報は以下のリンクで確認できます: https://github.com/sunfounder/ai-camera-firmware。
