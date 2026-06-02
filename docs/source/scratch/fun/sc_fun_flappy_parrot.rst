.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _sc_parrot:

お楽しみプロジェクト2 フラッピーパロット
========================================

このプロジェクトでは、超音波モジュールを使用してフラッピーパロットゲームをプレイします。

スクリプトを開始すると、緑色の竹（パドル）がランダムな高さで右から左に移動します。オウムを制御するには、超音波モジュールの上に手をかざします。手とモジュールの距離が 10cm 未満の場合、オウムは上昇し、それ以外の場合は下降します。この距離を慎重に調整して、オウムが緑色の竹をうまく通過できるように導いてください。竹に接触するとゲーム終了です。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4" type="video/mp4">
      お使いのブラウザはこのビデオタグをサポートしていません。
   </video>

以下は、プロジェクトを実装するための手順です。最初はこれらの手順に従うことをお勧めします。慣れてきたら、お好みに応じてエフェクトを変更しても構いません。

1. スプライトを追加する
---------------------------

* デフォルトのスプライトを削除し、 **スプライトを選ぶ** ボタンを使用して **Parrot** スプライトを追加します。サイズを 50% に設定し、左下隅に配置します。

  .. image:: img/parrot_choose_parrot.png

* **Paddle** スプライトを追加し、サイズを 150% に設定し、180 度回転させて右上隅に配置します。

  .. image:: img/parrot_choose_paddle.png

* **Paddle** スプライトの ** コスチューム** ページに移動し、キャンバス上の **Paddle** を選択して、** 輪郭** ツールをクリックします。

  .. image:: img/parrot_set_parrot1.png
    :width: 90%

* 輪郭効果を完全な塗りつぶしモードに変更し、削除ツールを使用してそれを除去します。

  .. image:: img/parrot_set_parrot2.png
    :width: 90%

2. **オウム** スプライトのスクリプト
---------------------------------------------

**Parrot** スプライトに飛行をシミュレートするスクリプトを書き、超音波モジュールの検出距離に基づいて高度を調整します。

* 緑色の旗がクリックされたら、0.2 秒ごとにコスチュームを切り替えて飛行の外観を維持します。

  .. image:: img/parrot_script_parrot1.png

* 超音波の検出距離が 10cm 未満の場合、y座標を 50 増やして **Parrot** を上昇させます。それ以外の場合は、y座標を 40 減らして **Parrot** を下降させます。

  .. image:: img/parrot_script_parrot3.png

* **Parrot** スプライトが **Paddle** スプライトに接触すると、ゲームが終了し、スクリプトの実行が停止します。

  .. image:: img/parrot_script_parrot4.png

3. **パドル** スプライトのスクリプト
-----------------------------------------------

**Paddle** スプライトがステージ上にランダムに表示されるようにスクリプトを書きます。

* 緑色の旗がクリックされたら、 **Paddle** スプライトを非表示にし、同時に自身のクローンを作成します。[`自身のクローンを作る <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_] ブロックがこのクローン処理を制御します。

  .. image:: img/parrot_script_paddle1.png

* クローンの位置を x座標 220（右端）、y座標は (-125 から 125 の間でランダム) に設定します。

  .. image:: img/parrot_script_paddle2.png

* [繰り返し] ブロックを使用して、x座標を徐々に減少させ、クローンを右から左へゆっくりと移動させ、最後に消えるようにします。

  .. image:: img/parrot_script_paddle3.png

* 新しい **Paddle** スプライトを再クローンし、前のクローンを削除します。

  .. image:: img/parrot_script_paddle4.png

プログラミングは完了です。緑色の旗をクリックしてスクリプトを実行し、期待通りの効果が得られるか確認してみてください。


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4"  type="video/mp4">
      お使いのブラウザはこのビデオタグをサポートしていません。
   </video>
