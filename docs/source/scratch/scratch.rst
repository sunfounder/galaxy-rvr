.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _programming_scratch:

Scratchでのプログラミング
============================

Arduino IDEでのプログラミングに加えて、グラフィカルプログラミングも使用できます。

Scratchでのプログラミングをお勧めします。
ただし、公式のScratchは現在Raspberry Piのみをサポートしています。この問題に対処するため、Arduinoボード（Uno、Mega2560、Nano）専用に、Scratch 3をベースにしたグラフィカルプログラミングソフトウェア **Mammoth Coding** を開発しました。

Mammoth CodingはScratch 3の基本機能を保持しつつ、Arduino Uno、Mega、Nanoカスタムボードなどの様々なボードを制御する機能を追加しています。外部センサーやロボットを使用してステージ上のスプライトを制御でき、強力なハードウェア連携機能を提供します。

さらに、このアプリはプログラミング経験が豊富でなくても簡単に使用できます。これらの最先端技術を簡単に学び、活用することができます。

Scratchのコーディングブロックをドラッグ＆ドロップするだけで、エキサイティングなゲーム、アニメーション、インタラクティブなプロジェクトを作成したり、思い描いた通りのロボットを制御したりできます！

それでは、この探求の旅を始めましょう！


**コードのダウンロード**


.. note::

    以下のプロジェクトのScratchスクリプトはすべてGitHubにアップロードされています。リンクからダウンロードできます。すべての ``.sb3`` スクリプトファイルは ``galaxy-rvr-main/scratch_codes/`` フォルダにあります。

   * |download_galaxyrvr_code|

または、`SunFounder GalaxyRVR Kit for Arduino - GitHub <https://github.com/sunfounder/galaxy-rvr/tree/1.2>`_ でコードを確認してください。


**基本プロジェクト**

これらのプロジェクトは、Mammoth CodingでGalaxyRVRを制御するための基本コースです。GalaxyRVRの使用方法を段階的にガイドします。

.. toctree::
    :maxdepth: 1


    sc1_history
    sc2_app
    sc3_rvr_move
    sc4_ultrasonic
    sc5_animate
    sc6_obstacle
    sc7_obstacle_animate
    sc8_avoid
    sc9_follow
    sc10_rgb
    sc11_servo
    sc12_camera
    sc13_all


**ファンプロジェクト**

以下はGalaxyRVRを必要としない楽しいプロジェクトですが、ここで実装することができます。

.. toctree::
    :maxdepth: 1

    fun/sc_fun_balloon
    fun/sc_fun_flappy_parrot
    fun/sc_fun_shooting
    fun/sc_fun_eat_apple
    fun/sc_fun_fish
    fun/sc_fun_sensitive_ball
    fun/sc_fun_tap_tile
