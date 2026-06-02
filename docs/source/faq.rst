.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

FAQ
==============

1. GalaxyRVR に接続できません
-------------------------------------------------------------------------------------------------

GalaxyRVR に接続できない場合、以下を確認してください：

1. ローバーのバッテリーインジケーターを確認します。両方の LED が消灯している場合、バッテリー残量が不足しています。Type-C USB ケーブルを使用してローバーを充電してください。
2. モードを **Run** に切り替え、 **Reset** ボタンを押して GalaxyRVR をリセットします。
3. モバイルデバイスが GalaxyRVR ホットスポットに接続されていることを確認します。
4. 自宅の Wi-Fi ネットワークを設定した場合は、モバイルデバイスが **同じ** 自宅の Wi-Fi ネットワークに接続されていることを確認します。

.. _install_lib:

2. コンパイルエラー： ``SoftPWM.h`` または ``SunFounder_AI_Camera.h`` ：No such file or directory
-------------------------------------------------------------------------------------------------
「Compilation error: ``SoftPWM.h``: No such file or directory」というプロンプトが表示された場合、SoftPWM ライブラリがインストールされていないことを意味します。

以下のように、必要な 2 つのライブラリ ``SoftPWM`` と ``SunFounder AI Camera`` をインストールしてください。

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/install_softpwm.mp4" type="video/mp4">
            お使いのブラウザはこのビデオタグをサポートしていません。
        </video>

``SunFounder AI Camera`` ライブラリについては、"INSTALL ALL" を選択して、必要な ``ArduinoJson`` 依存関係を同時にインストールする必要があります。

    .. image:: img/faq_install_ai_camera.png

3. avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e？
-----------------------------------------------------------------------------
ボードとポートが正しく選択されている状態で **Upload** ボタンをクリックした後、以下のメッセージが表示され続ける場合。

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00
    この場合、ESP32 CAM が取り外されていることを確認する必要があります。

ESP32-CAM と Arduino ボードは同じ RX（受信）および TX（送信）ピンを共有しています。そのため、コードをアップロードする前に、まず ESP32-CAM を取り外して、競合や潜在的な問題を回避する必要があります。

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

コードが正常にアップロードされた後、ESP32 CAM を使用する必要がある場合は、スイッチを左に動かして ESP32 CAM を起動してください。

    .. image:: img/camera_run.png
        :width: 500
        :align: center

4. Wi-Fi チャンネルを変更する方法
----------------------------------

2.4GHz Wi-Fi 帯域には、1 から 13 までのチャンネルがあります。ESP32 はチャンネル 1 から 11 をサポートしています。同じチャンネルで動作している他のデバイスが干渉を引き起こし、接続の問題につながる可能性があります。これを軽減するには、チャンネルの変更を試みてください。デフォルトでは、チャンネルは 1 に設定されています。新しいチャンネルを選択する際は、一度に 1〜2 チャンネルスキップすることをお勧めします。例えば、現在のチャンネルが 1 の場合、まずチャンネル 3 を試し、それでも信号が弱い場合はチャンネル 5 に進んでください。


#. GalaxyRVR の電源をオンにします。ESP32 CAM を起動するには、モードスイッチを **Run** の位置に動かし、 **reset** ボタンを押して R3 ボードを再起動します。

     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset_green.mp4" type="video/mp4">
            お使いのブラウザはこのビデオタグをサポートしていません。
        </video>

#. モバイルデバイスを GalaxyRVR の WiFi ネットワークに接続します。

   * ネットワーク名（SSID）は ``GalaxyRVR`` 、パスワードは ``12345678`` です。
   * 「インターネットなし」という警告が表示された場合は、 **「接続したままにする」** を選択してください。

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. モバイルデバイスでウェブブラウザを開き、アドレス ``http://192.168.4.1`` にアクセスします。これにより、ESP32-CAM ファームウェア更新ポータルが表示されます。

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. **AP** ページで、別のチャンネルを選択します。

   * デフォルトのチャンネルは 1 です。新しいチャンネルを選択する際は、一度に 1〜2 チャンネルスキップしてください（例：チャンネル 1 から 3 へ、必要に応じて 5 へ）。

   .. image:: img/fap_ap_channel.jpg
        :width: 50%
        :align: center

#. **Base** ページに戻り、 **Reboot** ボタンをクリックして GalaxyRVR を再起動します。これで GalaxyRVR は通常の動作が可能になります。

   .. image:: img/faq_firmware_reboot.png
        :width: 50%
        :align: center

5. ESP32 CAM のファームウェアを更新する方法
---------------------------------------------

詳細な手順については、:ref:`update_firmware` を参照してください。

6. R3 ファームウェアを復元する方法
-----------------------------------------

GalaxyRVR の R3 ボードには、RoboPilot App と Mammoth Coding の両方をサポートするファームウェアが付属しています。

このファームウェアを上書きしてしまい、通信を復元する必要がある場合は、:ref:`update_r3_firmware` に従ってください。

.. _ap_to_sta:

7. Wi-Fi 接続を設定する方法
-----------------------------------------------------

デフォルトでは、GalaxyRVR は **AP モード** で動作し、他のデバイスが接続できる独自の Wi-Fi ホットスポットを作成します。

GalaxyRVR を **自宅の Wi-Fi ネットワーク** に接続したい場合は、以下の手順に従ってください：


#. GalaxyRVR の電源をオンにします。ESP32 CAM を起動するには、モードスイッチを **Run** の位置に動かし、 **reset** ボタンを押して R3 ボードを再起動します。

     .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset_green.mp4" type="video/mp4">
            お使いのブラウザはこのビデオタグをサポートしていません。
        </video>

#. モバイルデバイスを GalaxyRVR の WiFi ネットワークに接続します。

   * ネットワーク名（SSID）は ``GalaxyRVR`` 、パスワードは ``12345678`` です。
   * 「インターネットなし」という警告が表示された場合は、 **「接続したままにする」** を選択してください。

     .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. モバイルデバイスでウェブブラウザを開き、アドレス ``http://192.168.4.1`` にアクセスします。これにより、ESP32-CAM ファームウェア更新ポータルが表示されます。

   .. image:: img/firmware_access.jpg
        :width: 50%
        :align: center

#. **WiFi** ページで、自宅の WiFi ネットワーク名（SSID）とパスワードを入力します。

   .. image:: img/faq_wifi.png
        :width: 50%
        :align: center

#. **CONFIRM** ボタンをタップします。

   * GalaxyRVR は自宅の Wi-Fi への接続を試みます。
   * 接続が成功すると、回転アイコンが停止し、チェックマークが表示されます。

#. 再起動後、モバイルデバイスを同じ自宅の Wi-Fi ネットワークに接続します。

#. これで RoboPilot App または Mammoth Coding を通じて GalaxyRVR に接続できます。
