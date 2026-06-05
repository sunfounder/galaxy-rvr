.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

FAQ
==============

1. なぜファームウェアを更新する必要がありますか？
----------------------------------------------------------------------------------------

SunFounder は GalaxyRVR のファームウェアを継続的に改善し、より良い体験を提供しています。すべてがスムーズに動作するように、初めて使用する前にファームウェアを更新することをお勧めします。ファームウェアの更新により、以下のことが保証されます：

* **バグ修正**: 既知の問題を解決し、安定性を向上させます。
* **アプリ互換性**: RoboPilot アプリと Mammoth Coding が正しく動作するために最新のファームウェアが必要です。
* **新機能**: ファームウェアの更新により新しい機能や改善が追加される場合があります。
* **パフォーマンス向上**: Wi-Fi 接続、カメラストリーミング、モーター制御の最適化。

更新手順については、 :ref:`update_firmware` を参照してください。

.. note::
   ファームウェアを更新せず、現在の設定のまま使用したい場合は、 `GalaxyRVR v1 ドキュメント <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_ を参照してください。


2. GalaxyRVR に接続できません
-------------------------------------------------------------------------------------------------

GalaxyRVR に接続できない場合、以下を確認してください：

1. **バッテリーを確認**: ローバーのバッテリーインジケーターを確認します。両方の LED が消灯している場合、バッテリー残量が不足しています。Type-C USB ケーブルを使用してローバーを充電してください。
2. **モードスイッチを確認**: モードスイッチが **Run**（ **Upload** ではない）に設定されていることを確認します。Wi-Fi ホットスポットは Run モードでのみ動作します。

   .. image:: img/camera_run.png
        :width: 500
        :align: center

3. **R3 ボードをリセット**: Run モードに切り替えた後、R3 ボードの **Reset** ボタンを押します。底部ライトストリップが点滅して起動成功を示します。
4. **Wi-Fi パスワードを確認**: デフォルトのホットスポット名（SSID）は ``GalaxyRVR`` 、パスワードは ``12345678`` です。パスワードを正しく入力したか確認してください。
5. **ESP32 CAM を確認**: ESP32 CAM がスロットに正しく装着されていることを確認します。ESP32 CAM の LED が点灯していない場合、カメラモジュールに電源が供給されていないか、損傷している可能性があります。
6. **Wi-Fi 干渉**: 同じ Wi-Fi チャンネル上の他のデバイスが干渉を引き起こす可能性があります。干渉が疑われる場合は、 :ref:`Wi-Fi チャンネルの変更 <change_wifi_channel>` を試してください。
7. **ファームウェア更新後**: ESP32 CAM のファームウェアを更新した後に Wi-Fi が動作しなくなった場合は、 :ref:`faq_wifi_after_update` を参照してください。
8. **モバイルデバイスの接続を確認**: GalaxyRVR を AP モード（デフォルト）で使用している場合は、モバイルデバイスを GalaxyRVR のホットスポットに接続します。 :ref:`自宅 Wi-Fi ネットワークを設定した場合 <ap_to_sta>` は、モバイルデバイスが **同じ** 自宅 Wi-Fi ネットワークに接続されていることを確認します。


3. RoboPilot アプリが接続できません
---------------------------------------------------------------------------------------

RoboPilot アプリが GalaxyRVR を見つけられないか接続できない場合、以下を確認してください：

1. **R3 ボードのファームウェアは最新ですか？** R3 ボードには工場出荷時の通信用ファームウェアがインストールされている必要があります。カスタム Arduino コードをアップロードすると、このファームウェアが上書きされ、RoboPilot 通信ができなくなります。 :ref:`update_r3_firmware` に従って復元してください。
2. **ESP32 CAM のファームウェアは最新ですか？** 古い ESP32 CAM ファームウェアは接続問題を引き起こす可能性があります。 :ref:`update_esp32_firmware` に従って確認および更新してください。
3. **モードスイッチは Run になっていますか？** Wi-Fi ホットスポットが動作するには、モードスイッチが **Run**（Upload ではない）に設定されている必要があります。
4. **モバイルデバイスは正しい Wi-Fi ネットワークに接続されていますか？** GalaxyRVR のホットスポット（ ``GalaxyRVR`` / ``12345678`` ）に接続するか、自宅 Wi-Fi を設定した場合はその同じネットワークに接続してください。
5. **リセットを試す**: **Run** モードに切り替えて **Reset** ボタンを押し、再度接続を試みてください。

上記のいずれでも解決しない場合は、 :ref:`ESP32 CAM の設定をクリア <faq_wifi_after_update>` してみてください。


4. Mammoth Coding（Scratch）アプリが接続できません
---------------------------------------------------------------------------------------

Mammoth Coding が GalaxyRVR に接続できない場合、以下を確認してください：

1. **R3 ボードのファームウェアは最新ですか？** Mammoth Coding は R3 ボードに工場出荷時の通信用ファームウェアが必要です。独自の Arduino コードをアップロードすると、通信用ファームウェアが上書きされます。 :ref:`update_r3_firmware` に従って復元してください。
2. **ESP32 CAM のファームウェアは最新ですか？** ESP32 CAM は Mammoth Coding が依存する Wi-Fi 接続を処理します。 :ref:`update_esp32_firmware` に従って最新であることを確認してください。
3. **モードスイッチは Run になっていますか？** Wi-Fi ホットスポットがアクティブになるには、モードスイッチが **Run** に設定されている必要があります。
4. **モバイルデバイスは正しい Wi-Fi ネットワークに接続されていますか？** デバイスが GalaxyRVR のホットスポット、またはローバーに設定されたのと同じ自宅 Wi-Fi ネットワークに接続されていることを確認してください。
5. **Arduino コードのアップロード後**: Arduino スケッチを R3 ボードにアップロードすると、通信用ファームウェアが上書きされることに注意してください。Mammoth Coding を再び接続するには、 :ref:`R3 ファームウェアの復元 <update_r3_firmware>` が必要です。

.. note::
   Arduino プログラミングと Mammoth Coding の **両方** を使用したい場合は、切り替えるたびに R3 ファームウェアを再アップロードする必要があることに注意してください。

.. _install_lib:

5. コンパイルエラー： ``SoftPWM.h`` または ``SunFounder_AI_Camera.h`` ：No such file or directory
-------------------------------------------------------------------------------------------------
「Compilation error: ``SoftPWM.h``: No such file or directory」というプロンプトが表示された場合、SoftPWM ライブラリがインストールされていないことを意味します。

以下のように、必要な 2 つのライブラリ ``SoftPWM`` と ``SunFounder AI Camera`` をインストールしてください。

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            お使いのブラウザはこのビデオタグをサポートしていません。
        </video>

``SunFounder AI Camera`` ライブラリについては、必要な ``ArduinoJson`` 依存関係を同時にインストールするために「INSTALL ALL」を選択する必要があります。

    .. image:: img/faq_install_ai_camera.png

6. avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e?
-----------------------------------------------------------------------------
ボードとポートが正しく選択されている状態で **Upload** ボタンをクリックした後、以下のメッセージが繰り返し表示される場合。

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00

この時点で、ESP32 CAM が取り外されていることを確認する必要があります。

ESP32-CAM と Arduino ボードは同じ RX（受信）ピンと TX（送信）ピンを共有しています。そのため、コードをアップロードする前に、競合や潜在的な問題を避けるために ESP32-CAM を最初に取り外す必要があります。

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

コードが正常にアップロードされた後、ESP32 CAM を使用する必要がある場合は、スイッチを左に動かして ESP32 CAM を起動する必要があります。

    .. image:: img/camera_run.png
        :width: 500
        :align: center

.. _change_wifi_channel:

7. Wi-Fi チャンネルの変更方法
----------------------------------

2.4GHz Wi-Fi 帯域には 1 から 13 までのチャンネルがあります。ESP32 はチャンネル 1 から 11 をサポートしています。同じチャンネルで動作する他のデバイスが干渉を引き起こし、接続問題につながる可能性があります。これを軽減するために、チャンネルを変更してみることができます。デフォルトでは、チャンネルは 1 に設定されています。新しいチャンネルを選択する際は、一度に 1〜2 チャンネルずつスキップすることをお勧めします。例えば、現在のチャンネルが 1 の場合、まずチャンネル 3 を試し、それでも信号が悪い場合はチャンネル 5 に進みます。


#. GalaxyRVR の電源を入れます。ESP32 CAM を起動するには、モードスイッチを **Run** の位置に動かし、R3 ボードの **reset** ボタンを押して再起動します。

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. モバイルデバイスを GalaxyRVR の Wi-Fi ネットワークに接続します。

   * ネットワーク名（SSID）は ``GalaxyRVR`` 、パスワードは ``12345678`` です。
   * 「インターネット接続なし」という警告が表示された場合は、 **「接続を維持する」** オプションを選択してください。

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. モバイルデバイスでウェブブラウザを開き、 ``http://192.168.4.1`` にアクセスします。これで ESP32-CAM ファームウェア更新ポータルに移動します。

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. **AP** ページで、別のチャンネルを選択します。

   * デフォルトのチャンネルは 1 です。新しいチャンネルを選択する際は、一度に 1〜2 チャンネルずつスキップしてください（例：チャンネル 1 から 3、必要に応じて 5 へ）。

   .. image:: img/fap_ap_channel.jpg
        :width: 50%
        :align: center

#. **Base** ページに戻り、**Reboot** ボタンをクリックして GalaxyRVR を再起動します。GalaxyRVR は通常動作の準備が整いました。

   .. image:: img/faq_firmware_reboot.png
        :width: 50%
        :align: center

8. ESP32 CAM のファームウェア更新方法
-----------------------------------------------

アプリの互換性と最適なパフォーマンスを確保するために、ESP32 CAM のファームウェアが最新であることを確認してください。

詳細な手順については、 :ref:`update_esp32_firmware` を参照してください。

9. R3 ファームウェアの復元方法
-----------------------------------------------

GalaxyRVR の R3 ボードには、RoboPilot アプリと Mammoth Coding の両方をサポートするファームウェアが搭載されています。

このファームウェアを上書きして通信を復元する必要がある場合は、 :ref:`update_r3_firmware` に従ってください。

.. _ap_to_sta:

10. Wi-Fi 接続の設定方法
-----------------------------------------------------

デフォルトでは、GalaxyRVR は **AP モード** で動作し、他のデバイスが接続できる独自の Wi-Fi ホットスポットを作成します。

GalaxyRVR を **自宅の Wi-Fi ネットワーク** に接続したい場合は、以下の手順に従ってください：


#. GalaxyRVR の電源を入れます。ESP32 CAM を起動するには、モードスイッチを **Run** の位置に動かし、R3 ボードの **reset** ボタンを押して再起動します。

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. モバイルデバイスを GalaxyRVR の Wi-Fi ネットワークに接続します。

   * ネットワーク名（SSID）は ``GalaxyRVR`` 、パスワードは ``12345678`` です。
   * 「インターネット接続なし」という警告が表示された場合は、 **「接続を維持する」** オプションを選択してください。

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. モバイルデバイスでウェブブラウザを開き、 ``http://192.168.4.1`` にアクセスします。これで ESP32-CAM ファームウェア更新ポータルに移動します。

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. **WiFi** ページで、自宅の Wi-Fi ネットワーク名（SSID）とパスワードを入力します。

   .. image:: img/faq_wifi.png
        :width: 50%
        :align: center

#. **CONFIRM** ボタンをタップします。

   * GalaxyRVR が自宅 Wi-Fi への接続を試みます。
   * 接続が成功すると、回転アイコンが停止し、チェックマークが表示されます。

#. 再起動後、モバイルデバイスを同じ自宅 Wi-Fi ネットワークに接続します。

#. これで RoboPilot アプリまたは Mammoth Coding を通じて GalaxyRVR に接続できます。

.. _faq_wifi_after_update:

11. ESP32 CAM を工場出荷設定に復元する方法
---------------------------------------------------------------------------------------

ESP32 CAM のファームウェアを更新した後に GalaxyRVR の Wi-Fi ホットスポットが表示されないか接続できない場合、ESP32 CAM のフラッシュメモリに保存されている古い Wi-Fi 設定データが競合を引き起こしている可能性があります。

これを解決するには、保存されたデータを消去して ESP32 CAM を工場出荷設定に復元する必要があります。これは、ESP32 CAM の **IO13** ピンと **IO15** ピンをショートさせることで行います：

#. GalaxyRVR の電源スイッチをオフにします。
#. ESP32 CAM モジュールの **IO13** ピンと **IO15** ピンを見つけます。

   .. image:: img/esp32cam_io1315.png
        :width: 300
        :align: center

#. ジャンパーワイヤーまたはピンセットを使用して、**IO13** ピンと **IO15** ピンをショート（接続）させます。
#. ピンをショートさせたまま、GalaxyRVR の電源スイッチをオンにします。
#. ESP32 CAM の LED を観察します — **2 回素早く点滅したら**、ジャンパーワイヤーを取り外します。

   .. image:: img/esp32cam_led.png
        :width: 300
        :align: center

#. モードを **Run** に切り替え、R3 ボードの **Reset** ボタンを押します。
#. ESP32 CAM が設定を消去した状態で起動します。デバイスの Wi-Fi リストに ``AI Camera-xxxxxx`` （ ``xxxxxx`` は一意の識別子）というホットスポットが表示されるはずです。パスワード ``12345678`` を使用して接続します。
#. GalaxyRVR を再起動すると、ホットスポット名が ``AI Camera-xxxxxx`` から ``GalaxyRVR-xxxxxx`` に変わり、工場出荷設定が正常に復元されたことを示します。

.. note::
   工場出荷設定を復元した後は、以前に保存した自宅 Wi-Fi 設定を再設定する必要があります（ :ref:`ap_to_sta` ）。
