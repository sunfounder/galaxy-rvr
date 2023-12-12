レッスン7：超音波モジュールを使った火星ローバーのナビゲーション向上
====================================================================

前回の冒険では、火星ローバーに側面に「目」を装備し、基本的な障害物回避システムを作成しました。しかし、正面にはまだ盲点があります。今回はその課題に立ち向かいます！

今回のレッスンでは、ローバーに新しい「視覚」を与えます。超音波センサーモジュールを取り付けて、中央の目として機能させ、直接前方の障害物を検出する手助けをします。

超音波の魅力的なメカニズムについて深く掘り下げ、複雑な地形でのナビゲーション能力をどのように高めるかを探求します。この追加により、火星ローバーはより敏感かつ機敏になり、より野心的な探索ミッションに挑戦する準備が整います。

このエキサイティングなSTEAMの旅にさらに一歩踏み出し、火星ローバーが未知の領域を探索する能力を高める過程にご参加ください！

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/ultrasonic_avoid.mp4" type="video/mp4">
      お使いのブラウザーはビデオタグをサポートしていません。
   </video>

.. note::

    GalaxyRVRを完全に組み立てた後にこのコースを学習する場合、コードをアップロードする前にこのスイッチを右に移動させる必要があります。

    .. image:: img/camera_upload.png
        :width: 500
        :align: center


学習目標
--------------------------

* 超音波を使用した距離測定の原理を理解する。
* Arduinoと超音波モジュールを使った距離測定の方法を学ぶ。
* 火星ローバーモデルで超音波モジュールを使用した障害物回避を実践する。

材料
---------------------

* 超音波モジュール
* 基本的なツールとアクセサリー（例：ドライバー、ネジ、ワイヤーなど）
* 火星ローバーモデル（ロッカーボギーシステム、メインボード、モーター、障害物回避モジュール装備）
* USBケーブル
* Arduino IDE
* コンピュータ

手順
--------------------
**ステップ1：超音波センサーモジュールの組み立て**

新しい「視覚」で火星ローバーを装備する目標を持っている今、超音波センサーモジュールを組み立てる時が来ました。

.. raw:: html

  <iframe width="600" height="400" src="https://www.youtube.com/embed/c_xWAVapGic?si=ovuxheXdGVpHopPa" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

これで、火星ローバーは完全に組み立てられた超音波センサーモジュールを備え、これまでにないナビゲーションを実現できるようになりました。ローバーの障害物検出能力がどのように変化するか、見てみるのはワクワクしませんか？さっそく始めましょう！


**ステップ2：超音波モジュールの探索**

HC-SR04、強力な超音波距離センサーについて知りましょう。この小さなデバイスは、2cmから400cmまでの距離を正確に測定できます。そして、何も触れることなくです！すごいでしょう？まるでスーパーヒーローの力のようです！まるでコウモリが夜にナビゲートするように、音波を使って距離を「見る」ことができます。

4つのスーパーパワー、つまり4つのピンを使ってその魔法を行います：

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG (Trigger Pulse Input)** - これは私たちのスーパーヒーローのスタートボタンです。スーパーヒーローに「ねえ、超音波を送信する時間だよ！」と教えています。
* **ECHO (Echo Pulse Output)** - これはスーパーヒーローが送った音波のエコーを聞く方法です。
* **VCC** - スーパーヒーローもエネルギーが必要です。5Vの電源に接続します。
* **GND** - 地面接続です。スーパーヒーローが現実と繋がっているように！

山でエコーのゲームをするHC-SR04超音波センサー、私たちのスーパーヒーローを想像してみてください。

.. image:: img/ultrasonic_prin.jpg
    :width: 800

* まず、私たちのスーパーヒーローの脳、MCUが、「Ready, Set, Go!」とスーパーヒーローに少なくとも10マイクロ秒の高レベル信号を送り出します。これは、谷に向かって大声を出す前にエネルギーを集めるようなものです。
* 「Go!」の合図を聞くと、私たちのスーパーヒーローは非常に速く8回大声を出します。この超音速の叫び声は40kHzの速度で送り出されます。スーパーヒーローは同時にストップウォッチをスタートし、戻ってくる叫び声に耳を澄ませます。
* 前方に障害物がある場合、叫び声はそれに当たってエコーとして戻ってきます。エコーを聞いたとき、スーパーヒーローはストップウォッチを止め、時間を記録します。また、MCUにエコーを聞いたことを知らせるために高レベル信号を送り出します。
* 最後に、障害物までの距離を知るために、スーパーヒーローは単純な公式を使います。記録した時間を2で割り、音速（340m/秒）を掛けます。その結果が障害物までの距離になります！

このようにして、私たちのスーパーヒーローセンサーは、その道に障害物があるかどうか、そしてどのくらい離れているかを把握することができます。素晴らしいでしょう？次に、このスーパーヒーローパワーを火星ローバーでどのように活用するかを学びます！


**ステップ3：スーパーヒーローセンサーのコーディング**

スーパーヒーローセンサーを組み立て、そのスーパーパワーの使い方を理解したので、それらの力を行動に移す時が来ました！超音波センサーが距離を測定し、その測定値を表示できるように、Arduinoスケッチを書きましょう。

私たちのスーパーヒーローセンサーが従う主な手順は以下の通りです：

* GalaxyRVRシールドの10番ピンにTRIGとECHOの両方のピンを接続しました。これにより、単一のArduinoピンを使用して超音波モジュールの信号送受信を制御できます。

.. image:: img/ultrasonic_shield.png

.. code-block:: arduino

    // Define the pin for the ultrasonic module
    #define ULTRASONIC_PIN 10

* **準備**：始めに、シリアル通信を9600ボーのレートで確立し、シリアルモニターでスーパーヒーローの測定値を確認できるようにします。

.. code-block:: arduino

    void setup() {
        // Start the serial communication
        Serial.begin(9600);
    }

* **叫び声を出す！**： ``ULTRASONIC_PIN`` を ``OUTPUT`` ピンとして設定し、10マイクロ秒のパルスを送信します。これは、超音波の強力な叫び声（超音波音波）を発するように超音波スーパーヒーローに命じることに似ています。


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



* **待って聞く**： ``ULTRASONIC_PIN`` を INPUT として設定します。これにより、スーパーヒーローセンサーは、自分の叫び声のエコーを聞く準備ができました。前方に障害物がある場合、叫び声はそれに当たってエコーとして戻ってきます。エコーを聞いたとき、スーパーヒーローはストップウォッチを止め、時間を記録します。また、MCUにエコーを聞いたことを知らせるために高レベル信号を送り出します。

.. code-block:: arduino

    pinMode(ULTRASONIC_PIN, INPUT);
    float duration = pulseIn(ULTRASONIC_PIN, HIGH);

* **スーパー数学**：エコーが戻ってきたら、センサーは音速を使って物体までの距離を計算します。エコーの合計時間を2で割るのは、叫び声の発出とエコーを待つ時間を含んでいるためです。

.. code-block:: arduino

    float distance = duration * 0.034 / 2;


* **調査結果の報告**：スーパーヒーローセンサーは、そのミッションの結果を明らかにし、距離をシリアルモニターに表示して私たちに見せます。

.. code-block:: arduino

    // Print the distance to the serial monitor
    Serial.print("The distance is: ");
    Serial.print(distance);
    Serial.println(" cm");

* **休息して準備**：すべてのスーパーヒーローには休息が必要なので、センサーは次のミッションの前に短い休憩を取ります。これにより、センサーは「reset」され、次の測定を開始するように依頼する前に準備が整います。

.. code-block:: arduino

    delay(200);

以下がセンサーをスーパーヒーローに変える完全なコードです：

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/35bddbcf-145c-4e4f-b3ea-21e8210af4a6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**ステップ4：超音波モジュールを使って火星ローバーを動かすプログラミング**

超音波センサーモジュールを火星ローバーに装備したので、センサーの測定値に基づいて反応するようにプログラムする時が来ました。

* 読みやすさのために、 ``readSensorData()`` という関数を作成しました。この関数は、超音波センサーから距離を読み取るために必要なすべてのコードをカプセル化しています。

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

* ``loop()`` 関数では、 ``readSensorData()`` を呼び出し、その戻り値を ``distance`` 変数に格納します。

  .. code-block:: arduino

    float distance = readSensorData();

* この距離に応じて、ローバーは前進、後進、または停止します。

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

  * 障害物が50cm以上離れていれば、ローバーは大胆に前進します。
  * 障害物が近づいている場合（50cm未満だが15cm以上離れている場合）、ローバーは低速で前進します。
  * 障害物が近すぎる場合（15cm未満の場合）、火星ローバーは後進してから左に曲がります。

  .. image:: img/ultrasonic_flowchart.png

以下が完全なコードです。このコードをR3ボードにアップロードして、望ましい効果が得られるか確認してください。また、実際の環境に基づいて検出距離を調整し、この障害物回避システムをより完璧にすることもできます。

.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/cded6408-1469-4289-b79b-7d445b56352b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


これらの強化された機能を利用することで、火星ローバーは道に潜む潜在的な障害物をより適切に識別し、距離を正確に測定し、それらを回避するための情報に基づいた決定を下すことができます。これにより、ローバーの探査ミッションを妨げる可能性のある衝突やその他の危険性を大幅に減らすことができます。

スーパーセンスを持つ火星ローバーは、より自信を持って効率的に動作し、火星の謎を深く探求し、地球に戻る研究者たちに貴重な科学データを収集することができます。

**ステップ5：まとめと反省**

このレッスンでは、超音波の仕組みと、その戻り時間をコーディングを通じて測定可能な距離に変換する方法について深く掘り下げました。

その後、超音波を利用して障害物回避システムを考案しました。このシステムは、迫り来る障害物までの距離に応じて、反応を変えます。

このレッスンを振り返り、いくつかの質問を通じて考察しましょう：

* 超音波モジュールはどのように距離を検出するのですか？その基本的な概念を説明できますか？
* このレッスンの障害物回避システムは、前回のレッスンのものとどのように異なりますか？それぞれの利点と欠点は何ですか？
* これら2つの障害物回避システムを組み合わせることは可能ですか？

これらの問いに反省することで、理解を深め、これらの概念を他のプロジェクトに適用することを考えるきっかけとなります。次の冒険を楽しみにしています！
