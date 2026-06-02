.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

お楽しみプロジェクト6 距離感応ボール
===========================================================

このプロジェクトでは、超音波モジュールを使用して、ステージ上のボールの垂直移動を制御します。緑色の旗をクリックしたら、超音波モジュールの上に手をかざします。手とモジュールの距離が 15 cm 未満の場合はボールが上昇し、それ以外の場合は下降します。ボールが線に接触すると、楽しいサウンドが鳴り、きらめく星のエフェクトが作動します。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4" type="video/mp4">
      お使いのブラウザはこのビデオタグをサポートしていません。
   </video>

以下の手順に従ってプロジェクトをセットアップしてください。仕組みに慣れてきたら、お好みに応じてエフェクトを自由に調整してください。

1. スプライトを選択する
--------------------------

* デフォルトのスプライトを削除し、 **Ball** 、 **Bowl** 、 **Star** の各スプライトを選択します。

  .. image:: img/ball_choose_sprite.png

* **Bowl** スプライトをステージの中央下部に配置し、サイズを大きくします。

  .. image:: img/ball_set_bowl.png

* **Ball** スプライトを **Bowl** スプライトの真上に配置し、方向を 0 に設定して垂直移動を可能にします。

  .. image:: img/ball_set_ball.png

* **Star** スプライトのサイズを調整し、方向を 180 に設定して下向きに落下するようにします。必要に応じて、異なる角度に変更することもできます。

  .. image:: img/ball_set_star.png

* 雰囲気を高めるために **Stars** 背景を追加します。

  .. image:: img/ball_select_backdrop.png

2. **線** スプライトを描く
-------------------------------

* 次に、 **Line** スプライトを追加します。

  .. image:: img/ball_select_line.png

* **Line** スプライトの ** コスチューム** ページに移動します。

  .. image:: img/ball_open_cos.png
    :width: 90%

* キャンバス上の赤い線の幅を少し狭め、4 つに複製して、これらの線を整列させます。

  .. image:: img/ball_copy_line.png
    :width: 90%

* 各線を異なる色に着色します。線を選択し、 **塗りつぶし** ツールを使用して色を選びます。

  .. image:: img/ball_set_bk_color.png
    :width: 90%

* この方法を適用して、すべての線に色を付けます。

  .. image:: img/ball_select_line_color.png
    :width: 90%

* **コード** ページに戻り、 **Line** スプライトをステージの上部に配置します。

  .. image:: img/ball_line_position.png

3. **ボール** スプライトのスクリプト
-------------------------------------

ここでは、超音波モジュールが検出した距離に基づいて **Ball** スプライトが上下に移動するようにスクリプトを書き、 **Bowl** スプライトに着地するように移動範囲を制限します。

* 緑色の旗がクリックされたら、 **Ball** スプライトの初期位置を設定します。

  .. image:: img/ball_script_ball1.png

* [もし～でなければ] ブロックを使用して、距離が 15 未満かどうかを確認します。真の場合は、方向が 0 に設定されているため、 **Ball** スプライトを 10 ステップ上に移動します。

  .. image:: img/ball_script_ball3.png

* それ以外の場合は、 **Ball** スプライトを落下させ、Y座標の最小値を -100 に制限します。これは調整可能で、 **Bowl** スプライトに着地しているように見せることができます。

  .. image:: img/ball_script_ball4.png

* **Ball** スプライトが **Line** スプライトに触れたときの相互作用をスクリプト化します。Y位置を変数 **ball_coor** に記録し、 **bling** メッセージをブロードキャストします。

  .. image:: img/ball_script_ball5.png

4. **星** スプライトのスクリプト
------------------------------------

* 緑色の旗がクリックされたら、最初に **Star** スプライトを非表示にします。 **Bling** メッセージを受信したら、 **Star** スプライトのクローンを作成します。

  .. image:: img/ball_script_star1.png

* **Ball** スプライトの位置に合わせてクローンの位置とサウンドエフェクトを設定します。

  .. image:: img/ball_script_star2.png

* -80 度から 80 度の間でランダムに回転するようにします。

  .. image:: img/ball_script_star3.png

* 視覚効果を高めるために、必要に応じて **Star** スプライトの外観と動作を調整します。

  .. image:: img/ball_script_star4.png

プログラミングは完了です。緑色の旗をクリックしてスクリプトを実行し、期待通りに動作するか確認してください。


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4"  type="video/mp4">
      お使いのブラウザはこのビデオタグをサポートしていません。
   </video>
