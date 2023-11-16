レッスン11：火星ローバー視覚システムの探検 - カメラとリアルタイム制御
==================================================================================

若い探検家の皆さん、おかえりなさい！前回のレッスンでは、火星ローバーにチルトメカニズムを使用して「うなずく」能力を装備しました。今回は、ローバーに「目」、つまりカメラを与える時です！

このスリリングな旅では、ローバーのカメラシステムの設定に深く潜ります。ローバーのカメラが捉えた映像をウェブページに転送する方法を学び、リアルタイムでローバーが見ているものを正確に見ることができます。ローバーの視点から火星の風景を体験する興奮を想像してみてください！

更にワクワクすることに、SunFounder Controllerアプリの紹介もあります。このアプリケーションを使うと、ローバーが周囲をナビゲートする際のライブフィードを得られ、スマートフォンやタブレットから直接チルトメカニズムを制御できます。内蔵画面付きのリモコンを持っているようなものです！

これにより、ローバーとのさらにインタラクティブで魅力的な体験が提供されます。これからも更なる冒険にご期待ください！

    .. image:: img/app/camera_view_app.png

学習目標
------------------
* ESP32 CAMとWiFi接続を確立する方法を理解する。
* リアルタイムでローバーが見ているものを正確に見る方法を学ぶ。
* SunFounder Controllerアプリを使用して仮想リモコンを作成し、火星ローバーを制御する方法を学ぶ。

材料
------------------------

* すべてのコンポーネントを備えた火星ローバーモデル
* Arduino IDE
* コンピューター
* SunFounder Controllerアプリをインストールしたタブレットまたはスマートフォン

手順
----------------------

**ステップ1：ESP32 CAMの紹介**

前回の冒険では、ESP32 CAMを統合することで火星ローバーに一対の「目」を装備しました。今日は、それについてもっと学び、実際に「見る」ことを実現しましょう。

.. image:: img/esp32_cam.png
    :width: 400
    :align: center

ローバーの目として機能するESP32 CAMは、小さいながらも強力なモジュールです。Wi-FiとBluetoothの機能を統合するだけでなく、コンパクトなカメラも備えています。このカメラにより、ローバーは周囲の映像を捉えることができます。

私たちが目を使って環境を観察するように、ESP32 CAMはローバーの前方にあるものを「見て」、その視覚データをスマートフォンやコンピューターに送信します。これにより、ローバーが見ているものをリアルタイムで全て見ることができます！

ローバー自体だけでなく、探検する世界も観察しているかのように、ローバーを直接操縦しているかのようです！信じられないですね？さあ、もっと深く探ってみましょう...


**ステップ2：ローバーのカメラのプログラミングとフィードの表示**

ESP32-CAMをローバーに取り付けた後、今度はそれに命を吹き込む必要があります。
そのためには、Arduino IDEを使用して、カメラを制御し、Wi-Fiに接続し、捉えた映像をストリーミングするプログラムを書きます。

その方法は次の通りです：

#. ``SunFounder AI Camera`` ライブラリをインストールします。

    * Arduino IDEの **Library Manager** を開き、「SunFounder Camera」を検索して、 **INSTALL** をクリックします。

        .. image:: img/camera_install_lib.png

    * ライブラリ依存関係のインストールのためのポップアップウィンドウが表示されます。 **INSTALL ALL** をクリックして、処理が完了するまで待ちます。

        .. image:: img/camera_install_lib1.png

#. Arduino IDEで以下のコードを入力します。

    コード内の変数 ``NAME``、 ``TYPE``、 ``PORT`` については、この時点では深く考えず、次のステップで役立つことを覚えておいてください。これらの変数は、火星ローバーからのリアルタイムビデオフィードを確立する今後の旅において重要になります。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b648e4-23e8-4b28-accd-aac171069116/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


    コード内には2つの接続モードがあります - **AP** モードと **STA** モード。特定のニーズに基づいて、どちらを使用するかを決めることができます。

    * **AP Mode**: このモードでは、ローバーがホットスポット（コード内で ``GalaxyRVR`` として名付けられています）を作成します。これにより、携帯電話、タブレット、ラップトップなどのデバイスがこのネットワークに接続できます。特に、どんな状況でもローバーを遠隔操作したい場合に便利です。ただし、これによりデバイスが一時的にインターネットに接続できなくなることに注意してください。

        .. code-block:: arduino

        // AP Mode
        #define WIFI_MODE WIFI_MODE_AP
        #define SSID "GalaxyRVR"
        #define PASSWORD "12345678"

    * **STA Mode**: このモードでは、ローバーが自宅のWi-Fiネットワークに接続します。携帯電話やタブレットなどの制御デバイスも同じWi-Fiネットワークに接続している必要があります。このモードでは、デバイスが通常のインターネットアクセスを維持しながらローバーを制御できますが、ローバーの操作範囲はWi-Fiのカバレッジエリアに限られます。

        .. code-block:: arduino

            // STA Mode
            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "YOUR SSID"
            #define PASSWORD "YOUR PASSWORD"

#. コードをローバーにアップロードし、ESP32 CAMを起動します！

    * ESP32-CAMとArduinoボードは、同じRX（受信）とTX（送信）ピンを共有しています。したがって、コードをアップロードする前に、ESP32-CAMを右側にスライドさせて解放し、競合や潜在的な問題を避ける必要があります。

        .. image:: img/camera_upload.png
            :width: 600

    * コードのアップロードが成功したら、ESP32 CAMを開始するために左側にスイッチを戻します。

        .. note::
            このステップと前のステップは、コードを再アップロードするたびに必要です。

        .. image:: img/camera_run.png
            :width: 600
        
    * **Serial Monitor** を開き、ボーレートを115200に設定します。情報が表示されない場合は、GalaxyRVRシールド上の **Reset button** を押してコードを再度実行します。シリアルモニター出力にIPアドレスが表示されます。これは、ローバーのカメラが放送しているアドレスです。

        .. image:: img/camera_serial.png


    * さあ、ローバーが見ているものを実際に見る時です！ウェブブラウザーを開きます - Google Chromeをお勧めします - そしてシリアルモニターに表示されているURLを入力します。フォーマットは ``http://ip:9000/mjpg`` です。

        .. image:: img/camera_view.png

さあ、やってみましょう！これで、あなたのローバーのカメラからのライブフィードを見ることができるはずです。火星（あるいはリビングルーム）をローバーの視点から見るなんて、素晴らしいと思いませんか？まるで本物の火星探査車の科学者のようですね！

これは始まりに過ぎません。まだまだ探索し、学ぶべきことはたくさんあります。次のステップでは、ライブカメラフィードを見ながらローバーを操作する方法を探求します。ワクワクしますね？さあ、探検家の皆さん、前進しましょう！

**ステップ3: アプリを使用してカメラフィードをコントロールし、視聴する**

スマートフォンで火星探査車の映像フィードをリアルタイムで見たいと思ったことはありませんか？さらに、そのチルトメカニズムを操作したいとも思いませんか？
それが今、可能になりました！SunFounder Controllerアプリの助けを借りて、これを実現できます。以下の手順に従ってください：

#. **APP Store(iOS)** または **Google Play(Android)** からインストールします。

#. コントローラーを作成します。

    * SunFounder Controllerでコントローラーを追加するには、 **+** アイコンをクリックします。

        .. image:: img/app/app1.png

    * **Blank** プリセットを選択し、 **Dual** または **Single Stick** を好みに応じて選びます。新しいコントローラーに名前を付けて、 **Confirm** をクリックします。

        .. image:: img/app/camera_controller.png

    * コントローラー内に入ります。Dセクションの **+** アイコンをクリックし、ポップアップメニューからスライダーを選択します。

    .. image:: img/app/camera_add_slider.png

    * このスライダーウィジェットはチルトメカニズムをコントロールするために設計されています。前のレッスンで学んだように、その範囲は0から140までです。したがって、私たちはこの範囲をスライダーウィジェットの最小値と最大値として設定します。

        .. image:: img/app/camera_slider_set.png
    
    * 右上隅の |app_save| ボタンをクリックして、このコントローラーを保存します。
    
#. スライダーの値をキャプチャするコードを書きましょう：

    * 前のコードに基づいて、APモードに切り替えます。このモードでは、SSIDとPASSWORDを好きなものに設定できます。
    
    .. code-block:: arduino
    
        // AP Mode
        #define WIFI_MODE WIFI_MODE_AP
        #define SSID "GalaxyRVR"
        #define PASSWORD "12345678"

    * 次に、SunFounderコントローラーからの値を受信するための ``onReceive()`` 関数を追加し、シリアルモニターでこれらの値を表示します。 ``getSlider()`` 関数を使用して、 **slider** ウィジェットの値を取得します。私はDエリアに **slider** ウィジェットを追加しましたが、異なるエリアに追加した場合は、 ``REGION_D`` をあなたのエリアに変更する必要があります。

        .. code-block::

            void onReceive() {
                int16_t sliderD = aiCam.getSlider(REGION_D);
                Serial.print("Slider D: ");
                Serial.println(sliderD);
            }

            void setup() {
                ...
                // Set the function to execute when data is received
                aiCam.setOnReceived(onReceive);
                ...
            }

    * こちらが完全なコードです：

        .. raw:: html

            <iframe src=https://create.arduino.cc/editor/sunfounder01/b914aa48-85e7-4682-b420-89961cc761ca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
    * コードをアップロードする前に、スイッチが右になっていることを確認してください。

        .. image:: img/camera_upload.png
            :width: 600

    * コードが正常にアップロードされた後、ESP32 CAMを起動するためにスイッチを左に動かします。

        .. image:: img/camera_run.png
            :width: 600

    * シリアルモニターで次の情報が表示されたら、次のステップに進むことができます。

        .. code-block:: arduino
        
            ...[OK]
            SET+PORT8765
            ...[OK]
            SET+START
            ...[OK]
            WebServer started on ws://192.168.4.1:8765
            Video streamer started on http://192.168.4.1:9000/mjpg
            WS+null

#.  ``GalaxyRVR`` ネットワークに接続します。

    この時点で、モバイルデバイスをGalaxyRVRによって提供されるローカルエリアネットワーク（LAN）に接続する必要があります。
    これにより、モバイルデバイスとローバーが同じネットワークになり、モバイルデバイスのアプリケーションとローバー間のスムーズな通信が可能になります。

    * モバイルデバイス（タブレットまたはスマートフォン）の利用可能なネットワークのリストから ``GalaxyRVR`` を探し、パスワード ``12345678`` を入力して接続します。

        .. image:: img/app/camera_lan.png

    * デフォルトの接続モードは **AP mode** です。接続後、このWLANネットワークにインターネットアクセスがないという警告が表示される場合がありますが、接続を続けてください。

        .. image:: img/app/camera_stay.png

#. コントローラーを接続し、起動させます。

    * 以前作成したコントローラー（私の場合は「camera」と名付けました）に戻ります。 |app_connect| ボタンを使用して、SunFounderコントローラーをローバーにリンクし、通信ラインを確立します。少し待つと、 ``GalaxyRVR(IP)`` （コード内で ``#define NAME "GalaxyRVR"`` として指定した名前）が表示されます。クリックして接続を確立します。

        .. image:: img/app/camera_connect.png

        .. note::
            もし上記のメッセージがしばらくしても表示されない場合は、Wi-Fiが ``GalaxyRVR`` に接続されていることを確認してください。

    * 「Connected Successfully」メッセージが表示されたら、 |app_run| ボタンを押します。これにより、アプリ上にカメラのライブ映像が表示されます。

        .. image:: img/app/camera_view_app.png

    * 今度はスライダーを動かしながらArduino IDEのシリアルモニターを開きます。以下のようなデータが表示されるはずです。

        .. code-block:: 
    
            Slider D: 105
            WS+null
            Slider D: 105
            WS+null
            Slider D: 105
            WS+null


#. スライダーでチルトメカニズムを制御させます。

    これで、スライダーウィジェットが送信する値がわかったので、これらの値を直接使用してサーボを回転させることができます。
     したがって、以前のコードに基づいて、以下の行を追加してサーボを初期化し、スライダーの値をサーボに書き込みます。


    .. code-block::

        ...
        #include <Servo.h>

        Servo myServo;  // create a servo object
        myServo.write(int(sliderD));  // control the servo to move to the current angle

        ...

        void onReceive() {
            ...
            myServo.write(int(sliderD));  // control the servo to move to the current angle
        }

        void setup() {
            ...
            myServo.attach(6);  // attaches the servo on pin 6
            ...
        }

    こちらが完全なコードです：
    
    .. raw:: html
    
        <iframe src=https://create.arduino.cc/editor/sunfounder01/b737352b-2509-4967-8147-1fd6bdc7d19d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

    上記のコードをGalaxyRVRにアップロードし、4番と5番の手順を繰り返して ``GalaxyRVR`` LANに再接続し、SunFounderコントローラーで再実行します。そうすると、スライダーを動かしてローバーのチルトメカニズムを制御できるようになります。

これで、SunFounderコントローラーの実装方法と、スライダーウィジェットを使用してサーボの動きを制御する方法を学びました。このプロセスにより、GalaxyRVRとより直感的で直接的なやり取りが可能になります。


**ステップ4: 反省とまとめ**

最初は複雑に思えるかもしれませんが、SunFounderコントローラーを使用して火星ローバーを操作することは、以下のステップを繰り返すことで習得できます：

* コードをアップロードする前に、スイッチが右になっていることを確認します。

    .. image:: img/camera_upload.png
        :width: 600

* コードが正常にアップロードされたら、左にスイッチを切り替えてESP32 CAMを起動します。
* ``GalaxyRVR`` ネットワークに接続します。
* コントローラーを接続し、実行します。

これらの手順は面倒に思えるかもしれませんが、プロセスには不可欠です。何度か繰り返すことで、手順に慣れ、快適に感じるようになります。


このレッスンを終えた今、学んだことをいくつかの質問を通じて振り返りましょう：

* 新しいコントローラーを作成する過程で、さまざまな種類のブロックに遭遇しました。それぞれの個々の機能について考えたことはありますか？
* チルトメカニズムを制御するために他のウィジェットを使用することは可能ですか？
* あるいは、火星ローバーの動きを直接制御することは？

これらの質問について、次のレッスンで探究することを楽しみにしましょう！
