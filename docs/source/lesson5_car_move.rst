.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

レッスン5：火星ローバーの移動性の解放
======================================================

若い探検家たち、準備はいいですか？モーターの制御をマスターしたので、これらのスキルを赤い惑星へと持って行きます。このレッスンでは、火星ローバーを活性化させます！

ロッカーボギーサスペンションシステムにモーターを組み立てる方法を学び、コーディングスキルを使って、想像上の火星の風景をローバーで横断します。

教室での火星冒険です。始めましょう！

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_move.mp4" type="video/mp4">
      あなたのブラウザはビデオタグをサポートしていません。
   </video>

.. note::

    GalaxyRVRを完全に組み立てた後にこのコースを学ぶ場合、コードをアップロードする前にこのスイッチを右に移動する必要があります。

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

学習目標
---------------------------

* 火星ローバーのロッカーボギーサスペンションシステムにモーターを組み立てる方法を理解する。
* Arduinoを使用して火星ローバーの動きを制御する方法を学ぶ。
* 異なる地形で火星ローバーの動きを制御するプログラムを書く練習をする。

材料
--------------------------
* SunFounder R3ボード
* TTモーター
* GalaxyRVRシールド
* バッテリー
* ロッカーボギーシステム搭載の火星ローバーモデル
* 基本的な工具とアクセサリー（例：ドライバー、ネジなど）
* USBケーブル
* Arduino IDE
* コンピュータ

手順
--------------

**ステップ1：ローバーのコンポーネントを組み立てる**

このステップでは、バッテリー、R3ボード、GalaxyRVRシールド、モーター、車輪を事前に組み立てられたロッカーボギーシステムに組み付けます。これによりGalaxyRVRが走行可能な状態になります。

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/lu8K26MY96s" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

おめでとう！自分たちのローバーを成功裏に組み立て、探索の準備ができました。さあ、動き出しましょう！

**ステップ2：ローバーを動かす**

さて、私たちの作成物に命を吹き込み、初の旅行に出発させる時が来ました。
しかし、ローバーとどうやって通信するのでしょうか？どうやってどこに行くのか、何をするのかを指示するのでしょうか？
ここで私たちのコーディングスキルが活躍します！

現実世界で車を前進させたいときはアクセルを踏み込み、両方の車輪が回転を始めます。
右側の車輪は時計回りに、左側の車輪は反時計回りに回転します。

.. image:: img/move_car.gif
    :align: center

運転席に座っていると想像してください。道路を走りながら世界があなたの周りを駆け巡る - まさに私たちがローバーに与える経験です。

さて、その経験をローバーが理解する言語、つまりコードに変換しましょう！

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

このコードでは、ローバーに正確に何をすべきかを伝えています。
``SoftPWMSet()`` 関数を使って、車のアクセルとブレーキのように、各モーターの速度と方向を制御しています。
左のモーターに反時計回りに回転するように、右のモーターに時計回りに回転するように指示し、そのようにして、ローバーは前進します！

もちろん、ローバーを前進させる方法を理解すれば、後退させることも簡単です。
ローバーを後退させるには、各モーターの回転方向を逆にするだけです。

コードでどのように行うかというと、まさにその逆を行います。右の車輪は今度は反時計回りに、左の車輪は時計回りに回転させることになります。

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

このコードでは、 ``SoftPWMSet()`` を使って左のモーターを時計回りに、右のモーターを反時計回りに回転させます。

コードでローバーの旅を簡単に制御できるのは魅力的ではありませんか？次に車に乗るときは、一回転ごとに世界を探索するローバーの旅を考えてみてください。ローバーの旅はまだ始まったばかりですから、乞うご期待！

**ステップ3：ローバーを他の方向に動かす**

火星ローバーを前進・後進させる方法を学んだので、左または右に曲がるようにしたい場合はどうすればいいでしょうか？

実際の運転と同じように、車が左に曲がるには主に2つの方法があります。

* 一つ目の方法は、左側の車輪を右側よりも遅く回転させることです。この速度の差により、ローバーが左に曲がります。
* 二つ目の方法は、左右のモーターを同じ方向（この場合は時計回り）に回転させることで、ローバーが軸上で左に回転するようにします。

両方の方法をコードでどのように実装するか見てみましょう：

**方法1：各側で異なる速度**

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

このコードでは、左のモーターの速度を下げ、右のモーターの速度を高く保ちます。これにより、ローバーが左に曲がります。

**方法2：すべてのモーターを同じ方向に回転させる**

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

このコードでは、すべてのモーターを時計回りに回転させています。ローバーは自軸の周りで回転し、左方向に変わります。

ローバーを右に曲がらせるためには、概念は同じですが方向が逆になります。どのように行うかお分かりですか？

**ステップ4：全方向への移動**

火星ローバーの機能をさらに開発するにつれて、私たちのコードはかなり長く複雑になることがあります。プログラミングでは、コードを整理して保守しやすく保つことが良い習慣です。これを実現する一つの方法は、別々のタスクに対して別々の関数を作成することです。

この場合、ローバーが移動できる各方向に対して別々の関数を作成できます。これによりコードが理解しやすくなるだけでなく、同じ行のコードを再度書き直すことなく、プログラムのどこでもこれらの関数を再利用することができます。

どのように行うか見てみましょう：

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/90c13522-9757-4212-b250-63ffbc790fd3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

この構造により、メインループはシンプルで追いやすくなります。ローバーが前進し、後退し、
左右に曲がり、最後に停止することがはっきりとわかります。

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_move.mp4" type="video/mp4">
      あなたのブラウザはビデオタグをサポートしていません。
   </video>

これらの各アクションがどのように達成されるかの詳細は、別の関数に隠されています。これは、抽象化として知られる良いプログラミング慣行の重要な側面です。

**ステップ5：共有と振り返り**

火星ローバーとのこの探索旅行を完了したことをお祝いします！これはあなたの科学と工学に関する知識の実用的な応用で、素晴らしい仕事をしました！

さて、ローバーが様々な地形の障害をどのように乗り越えるかを共有することができます。ローバーが異なる地形をナビゲートする様子を撮影したり、友人にローバーを見せて自慢することもできます。

学習プロセスを振り返ることも非常に重要です。このプロセスで何を学びましたか？新しいアイデアや創造的な考えは出てきましたか？モーターの制御とプログラミングで何を得たのでしょうか？

さらに探求し、新しい知識を発見し、常に自分を改善し続けることができます。これからも頑張って、未来の科学者やエンジニアになりましょう！

