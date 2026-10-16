.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _update_firmware:

ファームウェアの更新
======================

製品の継続的な改良により、お使いのデバイスに最新のファームウェアが搭載されていない場合があります。
すべてがスムーズに動作するように、初めて使用する前にファームウェアを更新することをお勧めします。ファームウェアの更新により、以下のことが保証されます：

* ** バグ修正** ：既知の問題を解決し、安定性を向上させます。
* ** アプリ互換性** ：RoboPilot アプリと Mammoth Coding が正しく動作するために最新のファームウェアが必要です。
* ** 新機能** ：ファームウェアの更新により新しい機能や改善が追加される場合があります。
* ** パフォーマンス向上** ：Wi-Fi 接続、カメラストリーミング、モーター制御の最適化。

.. note::
   ファームウェアを更新せず、現在の設定のまま使用したい場合は、 `GalaxyRVR v1 ドキュメント <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_ を参照してください。


.. 動画は一時的に無効にしています。以前の更新手順が表示されており、内容が古くなっているためです。新しい動画を撮影したら再度有効にしてください。
..
.. .. raw:: html
..
..    <iframe width="600" height="400" src="https://www.youtube.com/embed/Tl2W26pIQoU?si=98bbfUPc1g2cEz3A" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

.. _update_r3_firmware:

1. UNO R3 ファームウェアの更新
--------------------------------

R3 ボードには、RoboPilot アプリと Mammoth Coding と通信するファームウェアが搭載されています。ウェブベースの書き込みツールで再インストールしてください。コンピューターの **Chrome** または **Edge** で |link_galaxy_rvr_flasher| を開きます。ブラウザー上で動作し、追加のソフトウェアは不要で、各ステップを画像付きで表示します。

書き込みツールは 3 つのステップで構成されています：

#. **Connect** — ローバーの電源を入れ、USB A-B ケーブル（Type-C ケーブルではありません）でメインボードをコンピューターに接続し、モードスイッチを **Upload** の位置に切り替えます。次に **Next** をクリックします。

   .. image:: img/flasher_step1.jpg
      :width: 500

#. **Flash** — **Connect & Flash** をクリックします。表示されるポートウィンドウでお使いのボードのポート（例：``USB Serial (COMxx)``）を選択し、**Connect** をクリックすると書き込みが開始されます。失敗した場合は、もう一度 **Connect & Flash** をクリックしてください。

   .. image:: img/flasher_step2.jpg
      :width: 500

#. **Debug** — 書き込みが完了すると、ログウィンドウに以下が表示されます。これはファームウェアが書き込まれたことを確認するもので、現在のバージョン（**2.0.2** ）を示します。この時点では ``Initialzing...`` とそれ以降の表示は無視してください。ローバーはまだ **Upload** モードのままなので、ESP32 CAM と通信できません。次に **Next** をクリックします。

   .. code-block::

      Reading firmwares/galaxy-rvr-2.0.2.hex
      Resetting the board...
      Connecting to the board...
      Firmware written.
      Verified - flash matches the file.

      ---------- serial open at 115200 ----------
      GalaxyRVR version 2.0.2
      Initialzing...
      SET+RESET
      ...SET+RESET
      ...SET+RESET
      ...[FAIL]

#. プロンプトに従います：電源スイッチをオンにし、モードスイッチを元の位置に戻し、R3 ボードの **Reset** ボタンを押します。

   .. image:: img/flasher_step3_run.jpg
      :width: 500

#. ログウィンドウに現在の ESP32 CAM ファームウェアが表示されます。

   * ESP32 CAM のファームウェアが **1.5.0 以上** の場合、ログには UNO R3 のファームウェア、ESP32 CAM のファームウェア、最後に ``http://xxx.xxx.xx.xxx:9000/mjpg`` のようなウェブアドレスが表示されます。
   * **1.5.0 未満** の場合、ログウィンドウに ESP32 CAM のファームウェアを更新する必要があることが表示されます。:ref:`update_esp32_firmware` に進んでください。

   .. image:: img/flasher_step3.jpg
      :width: 500


.. _update_esp32_firmware:

2. ESP32 CAM ファームウェアの更新
-----------------------------------

ESP32 CAM は、GalaxyRVR の Wi-Fi ホットスポットをブロードキャストし、ビデオをキャプチャします。
ファームウェアが古い場合、これらの機能が正しく動作しない可能性があります。以下の手順に従ってファームウェアを更新してください。

#. GalaxyRVR の電源スイッチをオンにします。ESP32 CAM を起動するには、モードを **Run** に切り替え、R3 ボードの **Reset** ボタンを押します。

   .. image:: img/camera_run.png
        :width: 500
        :align: center

#. ファームウェアファイルをダウンロードします。

   * |download_galaxyrvr_filmware|

#. ダウンロードした ZIP ファイルを解凍します。``ai-camera-firware.ino.x.x.x.bin`` という名前のファームウェアファイルを見つけ、モバイルデバイスに転送します。ES File Explorer やファイル転送ユーティリティなど、任意のファイルマネージャーアプリを使用できます。

   .. image:: img/firmware_bin_file.png
        :align: center

#. モバイルデバイスを GalaxyRVR の WiFi ネットワークに接続します。

   * ネットワーク名（SSID）は ``GalaxyRVR`` 、パスワードは ``12345678`` です。
   * 「インターネットなし」という警告が表示された場合は、** 「接続したままにする」** を選択してください。

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. モバイルデバイスでウェブブラウザを開き、``http://192.168.4.1`` にアクセスして ESP32 CAM OTA 更新ページを開きます。


.. note:: このページでは、2 つのインターフェースのいずれかで OTA アップグレードオプションが表示されます。ファームウェアのバージョンに応じて、バージョン A（前者）とバージョン B（後者）が表示されます。表示されたインターフェースに応じて、対応するアップグレード手順を選択してください。

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center


** バージョン A**

   6. OTA ページでファームウェアファイルを選択し、更新を開始します：

      * デバイスから先ほどダウンロードした ``ai-camera-firmware-vX.X.X-ota.bin`` ファイルを選択し、**Add** をクリックします。
      * **Update** ボタンをクリックしてファームウェアの更新を開始し、完了するまで待ちます。

      .. image:: img/faq_ota_a.png
         :width: 700


   #. 更新が完了すると、GalaxyRVR の WiFi ホットスポット名は "AI Camera-xxxxxx" に変更され、パスワードは "12345678" のままです。


** バージョン B**


   6. **OTA** ページで、ウェブページに表示されている現在のファームウェアバージョンを確認します。

      * バージョン番号が **1.5.0 以上** の場合、更新は必要ありません。残りの手順をスキップして、:ref:`quick_start` に直接進んでください。
      * バージョンが **1.5.0 未満** の場合は、更新を続けてください。

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center


   #. **Upgrade Firmware** をタップし、ファームウェアファイルを選択して更新の完了を待ちます：

      * **Upgrade Firmware** ボタンをタップし、先ほどデバイスにダウンロードした ``ai-camera-firware.ino.x.x.x.bin`` ファイルを選択します。
      * 更新はすぐに開始され、通常 1〜2 分かかります。完了したら **CONFIRM** を選択して GalaxyRVR を再起動します。

      .. image:: img/faq_ota_b.png
         :width: 700

   #. 更新が完了すると、GalaxyRVR の WiFi ホットスポット名は "AI Camera-xxxxxx" に変更され、パスワードは "12345678" のままです。


3. 起動の確認
---------------

* GalaxyRVR を初めて使用する前に、付属の Type-C USB ケーブルでバッテリーを完全に充電してください。
* 電源スイッチをオンにします。
* モードを **Run** に切り替え、R3 ボードの **Reset** ボタンを押します。
* 底部のライトストリップが ** 緑色に点滅** し、起動成功を示します。

.. raw:: html

   <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=_idwN0kJrxbVW-5H" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
