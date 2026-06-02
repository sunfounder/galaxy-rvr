.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _sc_shooting:

お楽しみプロジェクト3 シューティング
====================================

テレビで放映されるスリリングな射撃ゲームを観たことがありますか？ 出場者が見事に的の中心を狙って得点を重ねるあのゲームです。今度は、その興奮を Scratch で体験できます！ このインタラクティブなシューティングゲームでは、クロスヘアスプライトを使って狙いを定め、的の中心にできるだけ近づけて、正確なショットごとに最大のスコアを獲得します。

開始するには、緑色の旗をクリックしてください。革新的な障害物回避モジュールを使用してショットをコントロールします。狙いと反射神経を試す準備はできましたか？ あなたのスコアを見せてください！


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4" type="video/mp4">
      お使いのブラウザはこのビデオタグをサポートしていません。
   </video>

以下は、プロジェクトを実装するための手順です。最初はこれらの手順に従うことをお勧めします。慣れてきたら、お好みに応じてエフェクトを変更しても構いません。

1. **クロスヘア** スプライトを描く
----------------------------------------------

* デフォルトのスプライトを削除し、 **スプライト** ボタンを選択して ** ペイント** をクリックします。

  .. image:: img/shooting_paint_cross.png

* **コスチューム** ページに移動します。** 円** ツールを使用し、塗りつぶしの色を削除して、輪郭の色と幅を設定します。

  .. image:: img/shooting_paint_cross1.png

* **円** ツールで円を描きます。描画後、** 選択** ツールを使用して、円の中心をキャンバスの中心に合わせます。

  .. image:: img/shooting_paint_cross2.png

* **線** ツールで、円の中に十字線を描きます。

  .. image:: img/shooting_paint_cross3.png

* 最後に、 **コード** ページに戻り、スプライトの名前を「Crosshair」に変更します。

  .. image:: img/shooting_paint_cross4.png

2. **ターゲット** スプライトを描く
----------------------------------------

* 同様に、 **スプライト** ボタンを選択し、** ペイント** をクリックします。

  .. image:: img/shooting_paint_target1.png

* **コスチューム** ページに入ります。** 円** ツールを使用し、黒色を選択して輪郭を削除し、大きな円を描きます。

  .. image:: img/shooting_paint_target3.png
    :width: 90%

* 同じ方法で追加の円を描き、それぞれ異なる色にします。 **前方へ** または ** 後方へ** ツールを使用して重なり合う円の位置を調整し、すべての円の原点がキャンバスの中心に合うようにします。

  .. image:: img/shooting_paint_target4.png
    :width: 90%

* **コード** ページに戻り、このスプライトの名前を「Target」に変更します。

  .. image:: img/shooting_paint_target5.png

3. 背景を追加する
--------------------------

* できれば色が控えめで、 **Target** スプライトの色と一致しない適切な背景を追加します。ここでは **Wall1** 背景を選択しました。

  .. image:: img/shooting_choose_backdrop.png

* **Target** スプライトと **Crosshair** スプライトの位置とサイズを調整します。

  .. note::

    * **Crosshair** スプライトが **Target** スプライトの上に重なるように、最初に **Target** スプライトを移動し、次に **Crosshair** を移動します。
    * **Crosshair** は **Target** スプライトの色のリング間のスペースよりも小さくする必要があります。

  .. image:: img/shooting_choose_backdrop1.png

4. **クロスヘア** スプライトのスクリプト
-------------------------------------------

* **Crosshair** スプライトの位置とサイズをランダム化し、予測不能に動くようにします。

  .. image:: img/shooting_script_cross.png

* 左側の障害物回避モジュールが遮られると、メッセージ（shooting）がブロードキャストされます。

  .. image:: img/shooting_script_cross1.png

* **shooting** メッセージを受信すると、スプライトは動きを停止し、徐々に縮小します。これが弾丸の発射をシミュレートしています。

  .. image:: img/shooting_script_cross2.png

* [色に触れた] ブロックを使用して、ショットの位置を判定します。

  .. image:: img/shooting_script_cross3.png
    :width: 90%

* ショットが黄色い円の内側に入った場合、スコア 10 を報告します。

  .. image:: img/shooting_script_cross4.png

* ショットが赤い円の内側に入った場合、スコア 9 を報告します。同様に、[色に触れた] ブロックを使用して赤い円の色に一致させます。

  .. image:: img/shooting_script_cross5.png
    :width: 90%

* 同じ方法を使用して弾丸の着弾位置を確認します。 **Target** スプライトに当たらなかった場合は、ミスとなります。

  .. image:: img/shooting_script_cross6.png

プログラミングは完了です。緑色の旗をクリックしてスクリプトを実行し、期待通りの効果が得られるか確認してみてください。


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4"  type="video/mp4">
      お使いのブラウザはこのビデオタグをサポートしていません。
   </video>
