.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

レッスン12：アプリでローバーを操作
===========================================

前回の冒険では、SunFounderコントローラーを使い、ローバーの目を通じて世界を探索し、チルト機構を制御してその視線を調整する技術を習得しました。まるで、私たちの火星ローバーに視力を与えたかのようでした！

今度は、この火星探検車を自分の意志で操り、その道筋を指示できたらどうでしょう。このレッスンでは、まさにそれを実現します！SunFounderコントローラーについての理解を深め、ローバーを操る方法を学びます。まるで火星ローバーのドライバーになったようなスリリングな体験が待っています！

生き生きとしたSTEAMコースを通じて、子供たちはただ学ぶだけでなく、宇宙探査の興奮と驚きを体験します！準備を整え、ワクワクする旅に出発しましょう！

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/camera_app.mp4" type="video/mp4">
        お使いのブラウザーはビデオタグをサポートしていません。
    </video>

学習目標
-----------------------

* SunFounderコントローラーについての理解を深める。
* モバイルアプリを使用して火星ローバーを操作する方法を学ぶ。


材料
------------------------

* 全部品を装備した火星ローバーモデル（ソーラーパネルと底板を除く）
* Arduino IDE
* コンピューター
* SunFounderコントローラーアプリがインストールされたタブレットまたはスマートフォン

手順
----------------------

**ステップ1：SunFounderコントローラーをより深く理解する**

前回のレッスンでは、SunFounderコントローラーの基本的な操作と使用法を初めて体験しました。しかし、まだ疑問が残っているのではないでしょうか？この好奇心を満たし、この技術の驚異についてさらに深く掘り下げてみましょう。

新しいコントローラーを作成すると、最初は謎のように見える画面が表示されます。

.. image:: img/app/app_blank.png

長方形、短方形、大きな正方形など、さまざまな形のカレイドスコープが、AからQまでの識別子でユニークにタグ付けされています。

その多様性はなぜでしょうか？AからQの識別子は何を意味するのでしょうか？

この探索の旅に出発しましょう！

* **形の解読**

    たとえば、長方形のエリアをタップしてみてください。宝箱を開けるように、いくつかのウィジェットが現れます。前回のクラスで使った **Slider** を覚えていますか？左右にスワイプすると、火星ローバーのカメラのチルトを制御しました。次に、 **Gauge** があります。これは、あなたのローバーの個人的な速度計として使うことができます。そして、他にも多くのウィジェットがあります！

    .. image:: img/app/app_long.png

    短い長方形をタップすると、異なるウィジェットセットが現れます。 **Button** ウィジェットは、バイナリスイッチのように単一のコマンドを発行し、 **Microphone** ウィジェットはあなたの声のコマンドを聞いてローバーを制御することができます。

    .. image:: img/app/app_short.png

    正方形ブロックはどうでしょうか？ **Joystick** ウィジェット、Dパッドウィジェット、スロットルウィジェットが入っています。もちろん、それだけではありません！

    .. image:: img/app/app_square.png

    この時点で、各ウィジェットの機能や使用法について心配する必要はありません。どの形がどのウィジェットを収容しているかを知り、それに慣れることが大切です。


* **ウィジェットの活用**

    上記の内容から、さまざまなウィジェットがあることがわかります。では、これらのウィジェットは何に使えるのでしょうか？

    これらのウィジェットは、コントロール ウィジェットと表示ウィジェットの 2 つのタイプに分類されます。

    * **コントロールウィジェット** は主にアプリの操作を可能にし、その後、火星ローバーがこれらの制御コマンドを受け取り、対応する動作を行います。
    * **ショーウィジェット** は、アプリ内でセンサー値などの値を表示するために使用できます。

    これらのウィジェットの詳細な説明については、以下を参照してください：|link_widgets_list|。

    また、これらのウィジェットに関連する機能、パラメーターなどについては、以下を参照してください：|link_ai_camera_library_api|。

* **識別子の役割**

    各形には右下に識別子が付いています。なぜでしょうか？例を挙げて説明しましょう。

    前回のクラスでは、 **D** 領域に **Slider** ウィジェットを追加しました。その値を取得するコードは次のようなものでした：

        .. code-block:: arduino

            int16_t sliderD = aiCam.getSlider(REGION_D);
        
    もし、 **B** 領域に **Slider** ウィジェットを追加したら、コードはどのように変わるでしょうか？単に ``REGION_D`` を ``REGION_B`` に置き換えるだけです。

        .. code-block:: arduino

            int16_t sliderD = aiCam.getSlider(REGION_B);

    簡単ですよね？これらの識別子は、どの領域にどのウィジェットを追加したかを識別するのに役立ちます。


.. note::
    * ウィジェットの作成・追加、SunFounderコントローラーの接続・操作に関する詳細な指示は、 ``レッスン11`` の ``ステップ3`` で利用可能です。
    * より深い操作については、 |link_sc_page| をご覧ください。

**ステップ2：デュアルスロットルで火星ローバーを制御**

SunFounderコントローラーウィジェットの内外を掘り下げたので、2つのスロットルウィジェットを組み込んで火星ローバーの動きをコントロールすることで、私たちのゲームをレベルアップしましょう。

#. **K** 領域と **Q** 領域に **Throttle** ウィジェットをそれぞれ配置します。編集モードに切り替えるために右上の |app_edit| ボタンを押し、設定が完了したら、変更を保存するために |app_save| をクリックします。

    .. image:: img/app/app_throttle.png

#. 2つの **Throttle** ウィジェットを使用してローバーの移動を制御する予定なので、それに応じてローバーの動きを指示する機能を調整しましょう：

    .. code-block:: arduino

        // Function to set the power of the motors
        void carSetMotors(int8_t power_L, int8_t power_R) {
            // Set power for the left motor
            if (power_L >= 0) {
                SoftPWMSet(in1, map(power_L, 0, 100, 0, 255));
                SoftPWMSet(in2, 0);
            } else {
                SoftPWMSet(in1, 0);
                SoftPWMSet(in2, map(power_L, 0, -100, 0, 255));
            }

            // Set power for the right motor
            if (power_R >= 0) {
                SoftPWMSet(in3, 0);
                SoftPWMSet(in4, map(power_R, 0, 100, 0, 255));
            } else {
                SoftPWMSet(in3, map(power_R, 0, -100, 0, 255));
                SoftPWMSet(in4, 0);
            }
        }

    もちろんです。 ``carSetMotors()`` 関数を詳しく見てみましょう。この関数は2つの引数 ``power_L`` と ``power_R`` を受け取り、これらは左右のモーターの電力設定であると思われます。これらの引数の値は、マイナス100から100までで、負の値は後退を示し、0は停止を示し、正の値は前進を示します。

    * 左モーターの電力を設定する：

        * ``power_L`` が0以上の場合、左モーターは前進するように設定されます。

        * ``SoftPWMSet(in1, map(power_L, 0, 100, 0, 255))`` はArduinoの ``map`` 関数を使用して、入力範囲（0から100）を出力範囲（0から255）にマッピングします。これは、ArduinoのPWM値が0（0%デューティサイクル）から255（100%デューティサイクル）の間であるためです。このマッピングされた値は、 ``SoftPWMSet`` 関数に ``in1`` とともに渡されます。

        * ``power_L`` が0未満の場合、左モーターは逆方向に動くように設定され、 ``map`` 関数の入力範囲は0からマイナス100になります。

    * 右モーターの電力を設定する：

        * これは左モーターの電力を設定するのと同じロジックに従いますが、 ``in3`` と ``in4`` を使用し、入力電力値は ``power_L`` の代わりに ``power_R`` です。

    全体として、この関数は2つのモーターの電力値を受け取り、それを適切なPWM値に変換し、所望の動きを実現するために正しいモーター制御ピンにPWM値を設定します。

#. ``onReceive()`` 関数内で、2つの **Throttle** ウィジェットから値を取得し、火星ローバーの左右のモーターの電力として使用します。

    .. code-block:: arduino
        :emphasize-lines: 9,10,13

        void onReceive() {
            // Get the value of the slider in region D
            int16_t sliderD = aiCam.getSlider(REGION_D);

            // Move the servo to the angle indicated by the slider
            myServo.write(int(sliderD));

            // Get the throttle values for the left and right
            int throttle_L = aiCam.getThrottle(REGION_K);
            int throttle_R = aiCam.getThrottle(REGION_Q);

            // Set the power for the motors
            carSetMotors(throttle_L, throttle_R);
        }

完全なコードはこちらです：

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c70d2598-a1f9-465a-83bb-4ebd38eb74fa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードを再実行するたびに、以下の4つのステップを繰り返す必要があります：

* コードをアップロードする前に、スイッチが右に向いていることを確認してください。

    .. image:: img/camera_upload.png


* コードが正常にアップロードされたら、左にスイッチを切り替えてESP32 CAMを起動します。
* ``GalaxyRVR`` ネットワークに接続します。
* コントローラーを接続し、実行します。

これで、 ``Throttle`` ウィジェット上で指を滑らせるだけで、火星ローバーが動き出し、新たな精神で力強くピボットします。探索を始めましょう！

**ステップ3：センサー読み取りの視覚化**

SunFounderコントローラーとの旅では、チルト調整のためのスライダーや、ローバーの動きを指示するスロットルなど、制御ウィジェットを通じて火星ローバーと積極的にやり取りしてきました。では、表示ウィジェットの力を利用して、ローバーの周囲の鮮明なイメージを描くのはどうでしょうか？

左右の赤外線（IR）回避モジュールと、超音波モジュールによって捕捉された距離の値を視覚化することで、これを実現しましょう。このリアルタイムデータにより、ローバーの運用環境の明確なスナップショットを提供します。

これを達成する方法は以下の通りです：

#. まず、SunFounderコントローラーに3つのナンバーウィジェットを追加します。設定ボタンを使用して、それらの名前や単位をカスタマイズすることを忘れないでください。

    .. image:: img/app/app_show.png

#. 次に、コードに取り掛かりましょう。前回のレッスンからIR回避モジュールと超音波モジュールのコードスニペットを持ってきます。

    .. code-block:: arduino

        ...
        // Define the pin for the ultrasonic module
        #define ULTRASONIC_PIN 10

        // Define the pins for the IR modules
        #define IR_RIGHT 7
        #define IR_LEFT 8

        void setup() {
            ...

            // Set the IR module pins as inputs
            pinMode(IR_RIGHT, INPUT);
            pinMode(IR_LEFT, INPUT);
        }


        float readSensorData() {
            // A 4ms delay is required, otherwise the reading may be 0
            delay(4);

            //Set to OUTPUT to send signal
            pinMode(ULTRASONIC_PIN, OUTPUT);

            ...
        }


#. ``onReceive()`` 関数内で、回避モジュールと超音波センサーから値を抽出し、それらの値を ``sendDoc[]`` 辞書に更新します。 ``N``、 ``P``、 ``O`` のキーは、追加した3つのナンバーウィジェットの領域コードに対応しています。

    .. code-block:: arduino

        // Function to execute when data is received from the Controller
        void onReceive() {

            ...

            // Read values from IR sensors
            int leftValue = digitalRead(IR_LEFT);
            int rightValue = digitalRead(IR_RIGHT);
            aiCam.sendDoc["N"] = leftValue;
            aiCam.sendDoc["P"] = rightValue;
            
            // ultrasonic
            float distance = readSensorData();
            aiCam.sendDoc["O"] = distance;
        }

完全なコードはこちらです：

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6c867007-a0e8-4f85-980d-ec1cd1a70969/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされたら、SunFounderコントローラーを起動します。回避モジュールと超音波センサーが検出した距離のリアルタイム値が表示され、ローバーの直接的な環境の明確なイメージが描かれます。

.. image:: img/app/app_show_ir_ultrasonic.png

このステップを終えると、表示ウィジェットの世界を無事にナビゲートできました。興味のある情報を表示するために、さまざまなウィジェットを試してみてください。探索を楽しんでください！

**ステップ4：振り返りと結論**

このレッスンでは、SunFounderコントローラーについての理解を深め、そのウィジェットを使用して火星ローバーを操縦するだけでなく、リアルタイムで環境データをモニタリングする方法を把握しました。

ここで挑戦です：

SunFounderコントローラーにスイッチウィジェットを追加してみませんか？これらのスイッチをアクティブにすると、火星ローバーは回避モードとフォローモードを切り替えることができます。または、ライトストリップを制御するためにスイッチを使用し、オンまたはオフにする、または色を変えるのはどうでしょうか？

この挑戦を受ける自信はありますか？

この挑戦を克服するあなたを楽しみにしています！


















