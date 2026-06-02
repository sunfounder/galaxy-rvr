.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

レッスン5: マーズローバーの機動性を解き放つ
======================================================

準備はいいですか、若き探検家たち！モーターの制御をマスターしました。今度はそのスキルを赤い惑星で活かします。このレッスンでは、マーズローバーを動かします！

モーターをロッカーボギーサスペンションシステムに組み立て、コーディングスキルを使ってローバーを想像上の火星の風景の中へ導く方法を学びます。

教室の中での火星冒険です。始めましょう！

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      お使いのブラウザはこのビデオタグをサポートしていません。
   </video>

.. note::

    GalaxyRVRを完全に組み立てた後にこのコースを学習する場合は、コードをアップロードする前に、このスイッチを右に移動してください。

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

学習目標
---------------------------

* モーターをマーズローバーのロッカーボギーサスペンションシステムに組み立てる方法を理解する。
* Arduinoを使用してマーズローバーの動きを制御する方法を学ぶ。
* 異なる地形でマーズローバーの動きを制御するプログラムを作成する練習をする。

必要な材料
--------------------------
* SunFounder R3 Board
* TTモーター
* GalaxyRVR Shield
* バッテリー
* マーズローバーモデル（ロッカーボギーシステム搭載）
* 基本工具と付属品（ドライバー、ネジなど）
* USBケーブル
* Arduino IDE
* コンピューター

手順
--------------

**ステップ1: ローバーコンポーネントの組み立て**

このステップでは、バッテリー、R3ボード、GalaxyRVR Shield、モーター、車輪を事前に組み立てられたロッカーボギーシステムに取り付けます。これにより、GalaxyRVRが走行可能な状態になります。

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/lu8K26MY96s" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

おめでとうございます！私たちは自分だけのローバーを無事に組み立て、探索を開始する準備が整いました。さあ、動き出しましょう！

**ステップ2: ローバーを動かす**

いよいよ私たちの作品に命を吹き込み、処女航海に送り出す時です。しかし、どうやってローバーと通信するのでしょうか？どこに行き、何をするかをどうやって伝えるのでしょうか？そこでコーディングスキルの出番です！

現実世界で車を前進させたい場合、アクセルを踏み、両方の車輪が回転し始めます。右側の車輪は時計回りに回転し、左側の車輪は反時計回りに回転します。

.. image:: img/move_car.gif
    :align: center

運転席に座って、車が開けた道を走りながら世界が横を流れていく様子を想像してください。それがまさにローバーに与えようとしている体験です。

では、その体験をローバーが理解できる言語、すなわちコードに変換しましょう！

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Define the pins of motors
        const int in1 = 2;
        const int in2 = 3;
        const int in3 = 4;
        const int in4 = 5;

        void setup() {
            // Initialize SoftPWM
            SoftPWMBegin();
        }

        void loop() {
            // Set the left motors rotate counterclockwise
            SoftPWMSet(in1, 255);  // Full speed
            SoftPWMSet(in2, 0);    // Stop

            // Set the right motors rotate clockwise
            SoftPWMSet(in3, 0);    // Stop
            SoftPWMSet(in4, 255);  // Full speed

        }

このコードでは、ローバーに話しかけ、何をすべきかを正確に指示しています。``SoftPWMSet()`` 関数を使用して、車のアクセルとブレーキのように、各モーターの速度と方向を制御しています。左のモーターには反時計回りに回転するように指示し、右のモーターには時計回りに回転するように指示します。すると、ローバーは前進します！

ローバーを後退させる概念は、前進させる方法を理解すれば非常に簡単です。ローバーを後退させるには、各モーターの回転方向を逆にするだけです。

コードで行う方法は次のとおりで、正反対のことを行います。右側の車輪は反時計回りに回転し、左側の車輪は時計回りに回転するようにします。

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Define the pins of motors
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set the left motors to rotate clockwise
        SoftPWMSet(in1, 0);    // Stop
        SoftPWMSet(in2, 255);  // Full speed

        // Set the right motors to rotate counterclockwise
        SoftPWMSet(in3, 255);  // Full speed
        SoftPWMSet(in4, 0);    // Stop

    }

このコードでは、``SoftPWMSet()`` を使用して、左のモーターに時計回り、右のモーターに反時計回りに回転するように指示しています。

コードだけでローバーの旅を制御できるなんて、魅力的ではないですか？次に車に乗るときは、ローバーの旅について少し考えてみてください。一度に1回転ずつ世界を探検しています。ローバーの旅は始まったばかりです。お楽しみに！

**ステップ3: ローバーを他の方向に動かす**

マーズローバーを前後に動かす方法を学びましたが、右や左に曲がらせたい場合はどうすればよいでしょうか？

実際の運転と同様に、車が左折するには主に2つの方法があります。

* 1つ目の方法は、左側の車輪を右側よりも遅く回転させることです。この速度差により、ローバーは左方向に曲がります。
* 2つ目の方法は、左右両方のモーターを同じ方向（この場合は時計回り）に回転させることです。これにより、ローバーはその場で左に回転します。

両方の方法をコードで実装する方法を見てみましょう：

**方法1: 各側で異なる速度**

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Define the pins of motors
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set the left motors rotate counterclockwise in low speed
        SoftPWMSet(in1, 40);
        SoftPWMSet(in2, 0);

        // Set the right motors rotate clockwise in higher speed
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 200);

        delay(2000);  // Last for 2 seconds
    }

このコードでは、左モーターの速度を下げ、右モーターの速度を高く保っています。これにより、ローバーは左方向に曲がります。

**方法2: すべてのモーターを同じ方向に回転させる**

.. code-block:: arduino
    :emphasize-lines: 16,17,18,19

    #include <SoftPWM.h>

    // Define the motor pins
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set all motors to rotate clockwise
        SoftPWMSet(in1, 0);
        SoftPWMSet(in2, 255);
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 255);
    }

このコードでは、すべてのモーターを時計回りに回転するように設定しています。ローバーはその軸を中心に回転し、方向が左に変わります。

ローバーを右折させる場合も、概念は同じで方向が逆になります。どのように行うか、考えられますか？

**ステップ4: あらゆる方向に移動する**

マーズローバーの機能をさらに開発していくにつれて、コードが非常に長く乱雑になる可能性があります。プログラミングでは、コードを整理整頓し、保守しやすく保つことが良い習慣です。これを実現する1つの方法は、タスクごとに個別の関数を作成することです。

この場合、ローバーが移動できる各方向に対して個別の関数を作成できます。これにより、コードの理解が容易になるだけでなく、同じコード行を再度書くことなく、プログラムのどこでもこれらの関数を再利用できます。

どのように行うか見てみましょう：

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/90c13522-9757-4212-b250-63ffbc790fd3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

この構造により、メインループはシンプルで追跡しやすいままです。ローバーが前進し、次に後退し、左右に曲がり、最後に停止することを明確に見ることができます。

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      お使いのブラウザはこのビデオタグをサポートしていません。
   </video>

これらの各アクションがどのように達成されるかの詳細は、個別の関数に隠されています。これは、抽象化として知られる優れたプログラミング手法の重要な側面です。

**ステップ5: 共有と振り返り**

マーズローバーによるこの探検の旅を完了したことをおめでとうございます！これは科学と工学の知識を実践的に応用したものであり、素晴らしい仕事でした！

では、ローバーがさまざまな地形の障害をどのように克服するかを共有できます。ローバーがさまざまな地形を走行する様子を撮影したり、友達にローバーを披露したりすることができます。

学習プロセスを振り返ることも非常に重要です。この過程で何を学びましたか？新しいアイデアや創造的な思考は生まれましたか？モーター制御とプログラミングにおいて、何を得ることができましたか？

探検を続け、新しい知識を発見し、絶えず自分自身を向上させることができます。その調子で頑張ってください、未来の科学者とエンジニアたち！
