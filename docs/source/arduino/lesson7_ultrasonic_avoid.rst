.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

レッスン7: 超音波モジュールでローバー航法を強化する
=============================================================

前回の冒険では、マーズローバーに側面の「目」を装備して、基本的な障害回避システムを作成しました。しかし、正面には死角がありました。これは私たちが克服すべき課題です！

今日のレッスンでは、ローバーに新しい「視覚」を与えます。超音波センサーモジュールを取り付けます。これは中央の目として機能し、ローバーが真正面の障害物を検出するのに役立ちます。

超音波の魅力的な仕組みを掘り下げ、それがローバーの複雑な地形を移動する能力をどのように強化するかを探求します。この追加により、マーズローバーはより感知力と機動性を備え、より野心的な探査ミッションに乗り出す準備が整います。

このエキサイティングなSTEAMの旅をさらに一歩進め、マーズローバーを未踏の領域の探査にさらに適したものにしましょう！


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/ultrasonic_avoid.mp4" type="video/mp4">
      お使いのブラウザはこのビデオタグをサポートしていません。
   </video>

.. note::

    GalaxyRVRを完全に組み立てた後にこのコースを学習する場合は、コードをアップロードする前に、このスイッチを右に移動してください。

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center


コースの目標
--------------------------

* 超音波距離測定の原理を理解する。
* Arduinoと超音波モジュールを使用した距離測定方法を学ぶ。
* マーズローバーモデルで障害回避のための超音波モジュールを応用する練習をする。

必要な材料
---------------------

* 超音波モジュール
* 基本工具と付属品（ドライバー、ネジ、配線など）
* マーズローバーモデル（ロッカーボギーシステム、メインボード、モーター、障害回避モジュール搭載）
* USBケーブル
* Arduino IDE
* コンピューター

コースの手順
--------------------
**ステップ1: 超音波センサーモジュールの組み立て**

マーズローバーに強力な新しい「視覚」を装備することを目指しているので、超音波センサーモジュールを組み立てましょう。

.. raw:: html

  <iframe width="600" height="400" src="https://www.youtube.com/embed/c_xWAVapGic?si=ovuxheXdGVpHopPa" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

これで完了です！マーズローバーに超音波センサーモジュールが完全に組み立てられ、以前とは比べものにならないナビゲーションの準備が整いました。これがローバーの障害物検出能力をどのように変えるか、楽しみですか？さっそく見ていきましょう！


**ステップ2: 超音波モジュールを探る**

HC-SR04について知りましょう。これは強力な超音波距離センサーです。この小さなデバイスは、何にも触れることなく、2cmから最大400cmまでの距離を正確に測定できます。驚くべきことではないですか？まるでスーパーヒーローの力を持っているようです！コウモリが夜間に移動するように、音波を使って距離を「見る」ことができます。

この魔法を行うために、4つの超能力、つまり4つのピンを使用します：

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG（トリガーパルス入力）** - スーパーヒーローのスタートボタンです。「ねえ、超音波を送り出す時間だよ！」とスーパーヒーローに伝えます。
* **ECHO（エコーパルス出力）** - これはスーパーヒーローが送り出した音波の反響を聞く方法です。
* **VCC** - スーパーヒーローでもエネルギーが必要です。5V電源に接続します。
* **GND** - これはグランド接続です。スーパーヒーローが現実とつながっている必要があるのと同じです！

HC-SR04超音波センサーという私たちのスーパーヒーローが、山でやまびこ遊びをしているところを想像してみてください。

.. image:: img/ultrasonic_prin.jpg
    :width: 800

* まず、スーパーヒーローの頭脳であるMCUが、「位置について、よーい、ドン！」と言い、少なくとも10マイクロ秒のHighレベル信号をスーパーヒーローに送ります。これは、谷に向かって叫ぶ前にエネルギーを集めるようなものです。
* 「ドン！」を聞くと、スーパーヒーローは8回素早く大きな声で叫びます。この超音波の叫びは40kHzの速度で送り出されます。スーパーヒーローはストップウォッチも開始し、戻ってくる叫び声に耳を澄ませます。
* 前方に障害物があれば、叫び声はそれに当たって跳ね返ってきます（エコー）。反響を聞くと、スーパーヒーローはストップウォッチを止めて時間を記録します。また、Highレベル信号を送信して、反響を聞いたことをMCUに知らせます。
* 最後に、障害物までの距離を求めるために、スーパーヒーローは簡単な計算式を使用します。ストップウォッチで記録した時間を2で割り、音速（340m/s）を掛けます。結果が障害物までの距離です！

これが、私たちのスーパーヒーローセンサーが、自分の経路に障害物があるかどうか、そしてそれがどれだけ離れているかを判断する方法です。驚くべきではないですか？次に、このスーパーヒーローパワーをマーズローバーでどのように使用できるかを学びます！


**ステップ3: スーパーヒーローセンサーをコーディングする**

スーパーヒーローセンサーを組み立て、その超能力の使い方を理解したので、それらの能力を実際に使ってみましょう！Arduinoスケッチを書いて、超音波センサーが距離を測定し、その測定値を表示できるようにします。

スーパーヒーローセンサーが従う主要な手順は次のとおりです：

* TRIGピンとECHOピンの両方をGalaxyRVR Shieldのピン10に接続しました。これにより、単一のArduinoピンを使用して超音波モジュールの信号送信と受信の両方を制御できます。

.. image:: img/ultrasonic_shield.png

.. code-block:: arduino

    // Define the pin for the ultrasonic module
    #define ULTRASONIC_PIN 10

* **準備**: 最初に、9600ボーレートでシリアル通信を確立し、スーパーヒーローの測定値をシリアルモニターで確認できるようにします。

.. code-block:: arduino

    void setup() {
        // Start the serial communication
        Serial.begin(9600);
    }

* **叫び出す！**: ``ULTRASONIC_PIN`` を ``OUTPUT`` ピンとして設定し、10マイクロ秒のパルスを送信します。これは、超音波スーパーヒーローに強力な叫び（超音波）を発するよう命令するようなものです！

.. code-block:: arduino

    // A 4ms delay is required, otherwise the reading may be 0
    delay(4);

    //Set to OUTPUT to send signal
    pinMode(ULTRASONIC_PIN, OUTPUT);

    // Clear the trigger pin
    digitalWrite(ULTRASONIC_PIN, LOW);
    delayMicroseconds(2);

    // Trigger the sensor by sending a high pulse for 10us
    digitalWrite(ULTRASONIC_PIN, HIGH);
    delayMicroseconds(10);

    // Set the trigger pin back to low
    digitalWrite(ULTRASONIC_PIN, LOW);



* **待って聞く**: ``ULTRASONIC_PIN`` をINPUTに設定します。これにより、スーパーヒーローセンサーは自分の叫び声の反響を聞く準備が整います。前方に障害物があれば、叫び声はそれに当たって跳ね返ってきます。反響を聞くと、スーパーヒーローはストップウォッチを止めて時間を記録します。また、Highレベル信号を送信して、反響を聞いたことをMCUに知らせます。

.. code-block:: arduino

    pinMode(ULTRASONIC_PIN, INPUT);
    float duration = pulseIn(ULTRASONIC_PIN, HIGH);

* **スーパー計算**: エコーが返ってきたら、センサーは音速を使用して物体までの距離を計算します。全体のエコー時間を2で割るのは、その時間が叫び声を送り出す時間と反響を待つ時間の両方を含んでいるからです。

.. code-block:: arduino

    float distance = duration * 0.034 / 2;


* **結果を報告する**: スーパーヒーローセンサーはミッションの結果を明らかにし、距離をシリアルモニターに表示します。

.. code-block:: arduino

    // Print the distance to the serial monitor
    Serial.print("The distance is: ");
    Serial.print(distance);
    Serial.println(" cm");

* **休息と準備**: どのスーパーヒーローにも休息が必要なので、センサーは次のミッションの前に短い休止を取ります。これにより、次の測定を開始する前にセンサーを「リセット」できます。

.. code-block:: arduino

    delay(200);

以下が、センサーをスーパーヒーローに変える完全なコードです：

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/35bddbcf-145c-4e4f-b3ea-21e8210af4a6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**ステップ4: 超音波モジュールをプログラムしてマーズローバーを駆動する**

マーズローバーに超音波センサーモジュールを装備したので、センサーの測定値に基づいて応答するようにプログラムしましょう。

* 読みやすくするために、``readSensorData()`` という関数を作成しました。この関数は、超音波センサーから距離を読み取るために必要なすべてのコードをカプセル化しています。

  .. code-block:: arduino

    float readSensorData() {
        // A 4ms delay is required, otherwise the reading may be 0
        delay(4);

        //Set to OUTPUT to send signal
        pinMode(ULTRASONIC_PIN, OUTPUT);

        // Clear the trigger pin
        digitalWrite(ULTRASONIC_PIN, LOW);
        delayMicroseconds(2);

        // Trigger the sensor by sending a high pulse for 10us
        digitalWrite(ULTRASONIC_PIN, HIGH);
        delayMicroseconds(10);

        // Set the trigger pin back to low
        digitalWrite(ULTRASONIC_PIN, LOW);

        //Set to INPUT to read
        pinMode(ULTRASONIC_PIN, INPUT);

        // pulseIn returns the duration of the pulse on the pin
        float duration = pulseIn(ULTRASONIC_PIN, HIGH);

        // Calculate the distance (in cm) based on the speed of sound (340 m/s or 0.034 cm/us)
        float distance = duration * 0.034 / 2;

        return distance;
    }

* ``loop()`` 関数で ``readSensorData()`` を呼び出し、その戻り値を ``distance`` 変数に格納します。

  .. code-block:: arduino

    float distance = readSensorData();

* この距離に応じて、ローバーは前進、後退、または停止します。

  .. code-block:: arduino

    // Control rover based on distance reading
    if (distance > 50) {  // If it's safe to move forward
      moveForward(200);
    } else if (distance < 15) {  // If there's an obstacle close
      moveBackward(200);
      delay(500);  // Wait for a while before attempting to turn
      backLeft(150);
      delay(1000);
    } else {  // For distances in between, proceed with caution
      moveForward(150);
    }

  * 経路がクリアな場合（障害物が50cm以上離れている場合）、ローバーは大胆に前進します。
  * 障害物が近づいている場合（50cm未満かつ15cm以上の場合）、ローバーは低速で前進します。
  * 障害物が近すぎる場合（15cm未満）、マーズローバーは後退し、その後左に曲がります。

  .. image:: img/ultrasonic_flowchart.png

以下が完全なコードです。このコードをR3ボードにアップロードして、目的の効果が得られるかどうかを確認できます。また、実際の環境に基づいて検出距離を変更し、この障害回避システムをより完全なものにすることもできます。

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cded6408-1469-4289-b79b-7d445b56352b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


これらの強化された機能を活用することで、マーズローバーは経路上の潜在的な障害物をより適切に識別し、距離を正確に測定し、それらを回避するための情報に基づいた判断を下すことができるようになります。これにより、ローバーの探査ミッションを妨げる可能性のある衝突やその他の危険を大幅に減らすことができます。

その超感覚により、マーズローバーはより大きな自信と効率で動作し、火星の謎により深く踏み込み、地球の研究者のために貴重な科学データを収集することができます。

**ステップ5: まとめと振り返り**

このレッスンでは、超音波の仕組みと、センサーへの戻り時間をコーディングによって測定可能な距離に変換する方法について掘り下げました。

その後、超音波を活用して障害回避システムを考案しました。この特定のシステムは、差し迫った障害物までの距離に基づいて応答を変化させます。

では、いくつかの質問を通して、このレッスンについて内省してみましょう：

* 超音波モジュールはどのように距離を検出しますか？根本的な概念を説明できますか？
* このレッスンの障害回避システムは、前回のレッスンのものとどのように異なりますか？それぞれの利点と欠点は何ですか？
* これら2つの障害回避システムを統合することは可能ですか？

これらの問いについて考察することで、理解を固め、これらの概念を他のプロジェクトに応用することを考える助けになります。次の冒険を楽しみにしています！
