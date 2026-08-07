.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

よくある質問
================

1. ファームウェアを更新する理由
-----------------------------------------------

SunFounder は、より良い体験を提供するために GalaxyRVR のファームウェアを継続的に改善しています。初回使用前にファームウェアを更新して、すべてがスムーズに動作することをお勧めします。ファームウェアの更新により、以下の効果が得られます：

* **バグ修正** ：既知の問題を解決し、安定性を向上させます。
* **アプリの互換性** ：RoboPilot アプリと Mammoth Coding を正しく動作させるには、最新のファームウェアが必要です。
* **新機能** ：ファームウェアの更新により、新たな機能や改善が追加される場合があります。
* **パフォーマンス向上** ：Wi-Fi 接続、カメラストリーミング、モーター制御の最適化。

詳細な手順については、:ref:`update_firmware` を参照してください。

.. note::
   ファームウェアを更新したくない場合や、現在の設定を引き続き使用したい場合は、`GalaxyRVR v1 ドキュメント <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_ を参照してください。


2. GalaxyRVR に接続できない場合
----------------------------------------------------

GalaxyRVR に接続できない場合は、以下をご確認ください：

1. **バッテリーを確認する** ：ローバーのバッテリーインジケーターを確認してください。両方の LED が消灯している場合は、バッテリー残量が不足しています。Type-C USB ケーブルを使用してローバーを充電してください。
2. **ESP32 CAM を確認する** ：ESP32 CAM がスロットに正しく装着されていることを確認してください。ESP32 CAM の LED が点灯していない場合、カメラモジュールに電力が供給されていないか、故障している可能性があります。ESP32 CAM は Wi-Fi ホットスポットを生成するため、動作していないとネットワークが表示されません。
3. **モードスイッチを確認する** ：モードスイッチが **Upload** ではなく **Run** に設定されていることを確認してください。Wi-Fi ホットスポットは Run モードでのみ動作します。

   .. image:: img/camera_run.png
        :width: 500
        :align: center

4. **R3 ボードをリセットする** ：Run モードに切り替えた後、R3 ボードの **Reset** ボタンを押してください。底面のライトストリップが点滅して、正常に起動したことを示します。
5. **Wi-Fi パスワードを確認する** ：デフォルトのホットスポット名（SSID）は ``GalaxyRVR`` 、パスワードは ``12345678`` です。パスワードを正しく入力したかご確認ください。
6. **Wi-Fi の干渉** ：同じ Wi-Fi チャンネル上の他のデバイスが接続の問題を引き起こす可能性があります。干渉が疑われる場合は、:ref:`Wi-Fi チャンネルの変更 <change_wifi_channel>` をお試しください。
7. **ファームウェア更新後** ：ESP32 CAM のファームウェアを更新した後に Wi-Fi が動作しなくなった場合は、:ref:`faq_wifi_after_update` を参照してください。
8. **モバイルデバイスの接続を確認する** ：GalaxyRVR を AP モード（デフォルト）で使用している場合は、モバイルデバイスを GalaxyRVR のホットスポットに接続してください。:ref:`自宅の Wi-Fi ネットワークを設定 <ap_to_sta>` した場合は、モバイルデバイスが **同じ** 自宅の Wi-Fi ネットワークに接続されていることを確認してください。


3. 底面の LED が橙色のままで、Wi-Fi ホットスポットが表示されない
----------------------------------------------------------------------------------

GalaxyRVR の底面のライトストリップが **橙色に点灯** し、``GalaxyRVR`` の Wi-Fi ネットワークが表示されない場合、原因は **ファームウェアのバージョン不一致** です：

- **ESP32 CAM** のファームウェアが古いバージョン（1.4.x または 1.3.x）のままである
- **UNO R3 ボード** のファームウェアがバージョン 2.x に更新されている
- バージョンの不一致により、ESP32 CAM と UNO R3 の間の通信ができなくなっています

これを解決するには、以下の手順を **順番通りに** 実行してください：

#. **最初に UNO R3 のファームウェアをバージョン 1.x に戻す** ：

   v1 ドキュメントのガイドに従ってください： `GalaxyRVR v1 — How to Upload the galaxy-rvr.ino Code <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/faq.html#how-to-upload-the-galaxy-rvr-ino-code>`_

#. **ESP32 CAM → UNO R3 の順番で両方のファームウェアを更新する** ：

   更新されたガイドに従ってください： :ref:`update_firmware`

.. note::

   順番が重要です — 必ず ESP32 CAM を先に更新し、次に R3 ボードを更新してください。ロールバックの手順をスキップしたり、順番を変更しても問題は解決しません。



4. RoboPilot アプリが接続できない場合
----------------------------------------------------------------------

RoboPilot アプリが GalaxyRVR を見つけられない、または接続できない場合は、以下をご確認ください：

1. **ESP32 CAM のファームウェアは最新ですか？** 古い ESP32 CAM ファームウェアは接続の問題を引き起こす可能性があります。:ref:`update_esp32_firmware` に従って確認・更新してください。
2. **R3 のファームウェアは最新ですか？** R3 ボードには工場出荷時の通信用ファームウェアがインストールされている必要があります。カスタムの Arduino コードをアップロードすると、このファームウェアが上書きされ、RoboPilot との通信ができなくなります。:ref:`update_r3_firmware` に従って復元してください。
3. **モードスイッチは Run になっていますか？** Wi-Fi ホットスポットを動作させるには、モードスイッチを **Run**（Upload ではなく）に設定する必要があります。
4. **モバイルデバイスは正しい Wi-Fi ネットワークに接続されていますか？** GalaxyRVR のホットスポット（``GalaxyRVR`` / ``12345678``）に接続するか、自宅の Wi-Fi を設定した場合はその同じネットワークに接続してください。
5. **リセットをお試しください** ：**Run** モードに切り替えて **Reset** ボタンを押し、再度接続を試みてください。

上記のいずれも効果がない場合は、:ref:`faq_wifi_after_update` をお試しください。


5. Mammoth Coding（Scratch）アプリが接続できない場合
-------------------------------------------------------------------------------

Mammoth Coding が GalaxyRVR に接続できない場合は、以下をご確認ください：

1. **ESP32 CAM のファームウェアは最新ですか？** ESP32 CAM は Mammoth Coding が使用する Wi-Fi 接続を処理します。:ref:`update_esp32_firmware` に従って最新の状態にしてください。
2. **R3 のファームウェアは最新ですか？** Mammoth Coding を使用するには、R3 ボードに工場出荷時の通信用ファームウェアが必要です。独自の Arduino コードをアップロードした場合、通信ファームウェアは上書きされます。:ref:`update_r3_firmware` に従って復元してください。
3. **モードスイッチは Run になっていますか？** Wi-Fi ホットスポットを有効にするには、モードスイッチを **Run** に設定する必要があります。
4. **モバイルデバイスは正しい Wi-Fi ネットワークに接続されていますか？** GalaxyRVR のホットスポット、またはローバーに設定した自宅の Wi-Fi ネットワークにデバイスが接続されていることを確認してください。

.. note::
   Arduino プログラミング **と** Mammoth Coding の **両方** を使用する場合は、切り替えるたびに R3 のファームウェアを再アップロードする必要があることに注意してください。

.. _install_lib:

6. コンパイルエラー：``SoftPWM.h`` または ``SunFounder_AI_Camera.h``：No such file or directory？
---------------------------------------------------------------------------------------------------------------

「Compilation error: ``SoftPWM.h``: No such file or directory」というプロンプトが表示された場合、SoftPWM ライブラリがインストールされていないことを意味します。

以下のように、2 つの必要なライブラリ ``SoftPWM`` と ``SunFounder AI Camera`` をインストールしてください。

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            お使いのブラウザはこのビデオタグをサポートしていません。
        </video>

``SunFounder AI Camera`` ライブラリについては、必要な ``ArduinoJson`` の依存関係を同時にインストールするために「INSTALL ALL」を選択する必要があります。

    .. image:: img/faq_install_ai_camera.png

7. avrdude：stk500_getsync() attempt 10 of 10：not in sync：resp=0x6e？
---------------------------------------------------------------------------------------------------

ボードとポートが正しく選択されている状態で **Upload** ボタンをクリックした後に、以下のメッセージが表示され続ける場合：

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00

この場合、ESP32 CAM が接続されていないことを確認する必要があります。

ESP32-CAM と Arduino ボードは同じ RX（受信）ピンと TX（送信）ピンを共有しています。そのため、コードをアップロードする前に、まず ESP32-CAM を取り外して、競合や潜在的な問題を回避する必要があります。

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

コードのアップロードが成功した後、ESP32 CAM を使用する必要がある場合は、スイッチを左に動かして ESP32 CAM を起動してください。

    .. image:: img/camera_run.png
        :width: 500
        :align: center

.. _change_wifi_channel:

8. Wi-Fi チャンネルを変更する方法
-----------------------------------------------

2.4GHz Wi-Fi 帯域には 1 から 13 までのチャンネルがあります。ESP32 はチャンネル 1 から 11 をサポートしています。同じチャンネルで動作する他のデバイスが干渉を引き起こし、接続の問題につながる可能性があります。これを軽減するには、チャンネルを変更してみてください。デフォルトでは、チャンネルは 1 に設定されています。新しいチャンネルを選択する際は、一度に 1〜2 チャンネルずつスキップすることをお勧めします。たとえば、現在のチャンネルが 1 の場合は、まずチャンネル 3 を試し、それでも信号が弱い場合はチャンネル 5 に進んでください。


#. GalaxyRVR の電源を入れます。ESP32 CAM を起動するには、モードスイッチを **Run** の位置に動かし、**Reset** ボタンを押して R3 ボードを再起動します。

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. モバイルデバイスを GalaxyRVR の Wi-Fi ネットワークに接続します。

   * ネットワーク名（SSID）は ``GalaxyRVR`` 、パスワードは ``12345678`` です。
   * 「インターネットなし」という警告が表示された場合は、**「接続したままにする」** を選択してください。

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. モバイルデバイスで Web ブラウザを開き、アドレス ``http://192.168.4.1`` にアクセスします。これにより、ESP32-CAM ファームウェア更新ポータルが開きます。

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. **AP** ページで、別のチャンネルを選択します。

   * デフォルトのチャンネルは 1 です。新しいチャンネルを選択する際は、1〜2 チャンネルずつスキップしてください（例：チャンネル 1 から 3、必要に応じて 5 へ）。

   .. image:: img/fap_ap_channel.jpg
        :width: 50%
        :align: center

#. **Base** ページに戻り、**Reboot** ボタンをクリックして GalaxyRVR を再起動します。GalaxyRVR は通常の動作準備が整いました。

   .. image:: img/faq_firmware_reboot.png
        :width: 50%
        :align: center

9. ESP32 CAM のファームウェアを更新する方法
--------------------------------------------------------

アプリの互換性と最適なパフォーマンスを確保するために、ESP32 CAM のファームウェアが最新であることを確認してください。

詳細な手順については、以下を参照してください： :ref:`update_esp32_firmware`

10. R3 ファームウェアを復元する方法
------------------------------------------------

GalaxyRVR の R3 ボードには、RoboPilot アプリと Mammoth Coding の両方をサポートするファームウェアがプリインストールされています。

このファームウェアを上書きしてしまい、通信を復元する必要がある場合は、:ref:`update_r3_firmware` に従ってください。

.. _ap_to_sta:

11. Wi-Fi 接続を設定する方法
------------------------------------------------------

デフォルトでは、GalaxyRVR は **AP モード** で動作し、他のデバイスが接続できる独自の Wi-Fi ホットスポットを作成します。

GalaxyRVR を **自宅の Wi-Fi ネットワーク** に接続したい場合は、以下の手順に従ってください：


#. GalaxyRVR の電源を入れます。ESP32 CAM を起動するには、モードスイッチを **Run** の位置に動かし、**Reset** ボタンを押して R3 ボードを再起動します。

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. モバイルデバイスを GalaxyRVR の Wi-Fi ネットワークに接続します。

   * ネットワーク名（SSID）は ``GalaxyRVR`` 、パスワードは ``12345678`` です。
   * 「インターネットなし」という警告が表示された場合は、**「接続したままにする」** を選択してください。

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. モバイルデバイスで Web ブラウザを開き、アドレス ``http://192.168.4.1`` にアクセスします。これにより、ESP32-CAM ファームウェア更新ポータルが開きます。

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. **WiFi** ページで、自宅の Wi-Fi ネットワーク名（SSID）とパスワードを入力します。

   .. image:: img/faq_wifi.png
        :width: 50%
        :align: center

#. **CONFIRM** ボタンをタップします。

   * GalaxyRVR が自宅の Wi-Fi への接続を試みます。
   * 接続が成功すると、回転アイコンが停止し、チェックマークが表示されます。

#. 再起動後、モバイルデバイスを同じ自宅の Wi-Fi ネットワークに接続します。

#. RoboPilot アプリまたは Mammoth Coding から GalaxyRVR に接続できるようになります。

.. _faq_wifi_after_update:

12. ESP32 CAM を工場出荷時の設定に復元する方法
---------------------------------------------------------------------------

GalaxyRVR の Wi-Fi ホットスポットが表示されない場合、または ESP32 CAM ファームウェアの更新後に接続できない場合、ESP32 CAM のフラッシュメモリに保存されている古い Wi-Fi 設定データが競合を引き起こしている可能性があります。

これを解決するには、ESP32 CAM の **IO13** ピンと **IO15** ピンをショート（短絡）して、保存されているデータをクリアし、工場出荷時の設定に復元する必要があります：

#. GalaxyRVR の電源スイッチをオフにします。
#. ESP32 CAM モジュールの **IO13** ピンと **IO15** ピンの位置を確認します。

   .. image:: img/esp32cam_io1315.png
        :width: 300
        :align: center

#. ジャンパーワイヤーまたはピンセットを使用して、**IO13** ピンと **IO15** ピンをショート（接続）します。
#. ピンをショートしたまま、GalaxyRVR の電源スイッチをオンにします。
#. ESP32 CAM の LED を確認します — **2 回すばやく点滅** したら、ジャンパーワイヤーを取り外します。

   .. image:: img/esp32cam_led.png
        :width: 300
        :align: center

#. モードを **Run** に切り替え、R3 ボードの **Reset** ボタンを押します。
#. ESP32 CAM は設定がクリアされた状態で起動します。デバイスの Wi-Fi リストに ``AI Camera-xxxxxx``（``xxxxxx`` は一意の識別子）という名前のホットスポットが表示されるはずです。パスワード ``12345678`` を使用して接続してください。
#. GalaxyRVR を再起動すると、ホットスポット名が ``AI Camera-xxxxxx`` から ``GalaxyRVR-xxxxxx`` に戻り、工場出荷時の設定が正常に復元されたことを示します。

.. note::
   工場出荷時の設定に復元した後は、以前に保存した自宅の Wi-Fi 設定を再設定する必要があります（:ref:`ap_to_sta`）。


.. _uno_firmware_mac:

13. macOS での R3 ファームウェアの更新方法
----------------------------------------------

R3 ボードには、RoboPilot アプリおよび Mammoth Coding との通信を可能にするファームウェアが組み込まれています。

以下の場合、このファームウェアを再アップロードする必要があります：

- お使いのデバイスが古いファームウェアバージョンを使用している場合、または
- 独自の Arduino コードを書き込んでおり、互換性を復元したい場合。

以下の手順に従って、通信ファームウェアを再インストールしてください。

#. USB ケーブルで Arduino をコンピューターに接続し、モードスイッチを **Upload** に切り替えます。

   .. image:: img/camera_upload.png
        :width: 500

   .. note:: Arduino への接続には USB Type B ポートを使用してください。USB Type C ポートは充電専用です。

#. ファームウェアファイルがダウンロードされていることを確認します。

   * |download_galaxyrvr_filmware|

#. ダウンロードしたアーカイブを解凍し、``output`` フォルダーを取得します。``output`` フォルダーを右クリック（または Control キーを押しながらクリック）し、コンテキストメニューから **New Terminal at Folder** を選択します。

   .. image:: img/faq_mac_firmware_open.png
      :width: 400

#. ターミナルが ``output`` フォルダーで直接開きます。

   * ``bash update-arduino-firmware-mac.sh`` コマンドを実行します
   * 検出された COM ポートの番号（例：``1``）を入力します：

   .. image:: img/faq_mac_firmware_run.png
      :width: 600

#. **"avrdude not Opened"** というメッセージが表示された場合：

   .. image:: img/faq_mac_firmware_avrdude.png
      :width: 300

#. **システム設定** > **プライバシーとセキュリティ** に移動し、**Allow Anyway** をクリックします。

   .. image:: img/faq_mac_firmware_allow.png
      :width: 600

#. スクリプトを再度実行します：``bash update-arduino-firmware-mac.sh``

   今回は **Open Anyway** を選択できます。管理者のユーザー名とパスワードを入力して操作を許可します。

   .. image:: img/faq_mac_firmware_anyway.png
      :width: 600

#. 成功メッセージが表示されたら、USB ケーブルを取り外せます。

   .. image:: img/faq_mac_firmware_finish.png
      :width: 600

.. important::

   * このファームウェアにより、GalaxyRVR はアプリのコマンドに応答できるようになります。
   * RoboPilot リモートコントロールアプリまたは Mammoth Coding ソフトウェアを使用する際に、追加のコードをアップロードする必要はありません。
   * これで :ref:`quick_start` に進み、GalaxyRVR の旅を始めることができます！
