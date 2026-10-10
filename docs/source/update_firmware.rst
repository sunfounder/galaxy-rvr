.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _update_firmware:

ファームウェアの更新
==========================

製品の継続的な改良により、お使いのデバイスに最新のファームウェアが搭載されていない場合があります。
すべてがスムーズに動作するように、初めて使用する前にファームウェアを更新することをお勧めします。ファームウェアの更新により、以下のことが保証されます：

* **バグ修正**: 既知の問題を解決し、安定性を向上させます。
* **アプリ互換性**: RoboPilot アプリと Mammoth Coding が正しく動作するために最新のファームウェアが必要です。
* **新機能**: ファームウェアの更新により新しい機能や改善が追加される場合があります。
* **パフォーマンス向上**: Wi-Fi 接続、カメラストリーミング、モーター制御の最適化。

.. note::
   ファームウェアを更新せず、現在の設定のまま使用したい場合は、 `GalaxyRVR v1 ドキュメント <https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html>`_ を参照してください。


.. raw:: html

   <iframe width="600" height="400" src="https://www.youtube.com/embed/Tl2W26pIQoU?si=98bbfUPc1g2cEz3A" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


.. _update_uno_firmware:

1. UNO R3 ボードファームウェアの更新
--------------------------------------

R3 ボードには、RoboPilot アプリおよび Mammoth Coding との通信を可能にするファームウェアが組み込まれています。以下のウェブ書き込みツールを使えば、コンピューターに追加のソフトウェアをインストールせずに再インストールできます。

**方法 1：ウェブ書き込みツール**

#. GalaxyRVR の電源を入れ、USB A-B ケーブル（USB Type-C ケーブルではありません）を **メインボード** に接続し、車の **Upload** スイッチを書き込み側に切り替えます。

#. 書き込みの前に ESP32 CAM をスロットから取り外します。ESP32 CAM は R3 ボードと RX・TX ピンを共有しているためです。詳しくは :ref:`FAQ <faq_r3_upload_bat>` を参照してください。

#. コンピューターの **Chrome** または **Edge** で |link_galaxy_rvr_flasher| を開き、ファームウェアのバージョンを選択します：

   * バージョン **2.0.0** は現在の世代の GalaxyRVR 用です。
   * バージョン **1.1.0** は初代 GalaxyRVR 用です。

   どちらの世代か分からない場合は、箱のラベルを確認するか、お問い合わせください。

#. **Connect & Flash** をクリックし、ダイアログでお使いのボードのシリアルポートを選択します。書き込みは自動的に始まり、約 1 分で完了します。

   .. image:: img/faq_web_flasher_en.png
      :width: 600
      :align: center

#. 書き込みが完了したら、スイッチを **Run** に戻し、ESP32 CAM を取り付けて、GalaxyRVR の電源を入れ直します。

.. note::

   * このページは Web Serial を使用するため、コンピューターの **Chrome** または **Edge** を使用し、ページが **https** で開かれていることを確認してください。Windows では、デバイスマネージャーに **USB-SERIAL CH340** が表示されているかで、USB シリアルドライバーがインストール済みかを確認できます。
   * Arduino IDE、シリアルモニター、別のブラウザータブなど、シリアルポートを使用している可能性のある他のプログラムは終了してください。

.. _update_esp32_firmware:

2. ESP32 CAM ファームウェアの更新
--------------------------------------

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
   * 「インターネットなし」という警告が表示された場合は、 **「接続したままにする」** を選択してください。

   .. image:: img/camera_lan.png
        :width: 50%
        :align: center

#. モバイルデバイスでウェブブラウザを開き、``http://192.168.4.1`` にアクセスして ESP32 CAM OTA 更新ページを開きます。


.. note:: このページでは、2つのインターフェースのいずれかで OTA アップグレードオプションが表示されます。ファームウェアのバージョンに応じて、バージョン A（前者）とバージョン B（後者）が表示されます。表示されたインターフェースに応じて、対応するアップグレード手順を選択してください。

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center


**バージョン A**

   6. OTA ページでファームウェアファイルを選択し、更新を開始します：

      * デバイスから先ほどダウンロードした ``ai-camera-firmware-vX.X.X-ota.bin`` ファイルを選択し、**Add** をクリックします。
      * **Update** ボタンをクリックしてファームウェアの更新を開始し、完了するまで待ちます。

      .. image:: img/faq_ota_a.png
         :width: 700

   #. 更新が完了すると、GalaxyRVR の WiFi ホットスポット名は "AI Camera-xxxxxx" に変更され、パスワードは "12345678" のままです。


**バージョン B**


   6. **OTA** ページで、ウェブページに表示されている現在のファームウェアバージョンを確認します。

      * バージョン番号が **1.5.1 より新しい場合** 、更新は必要ありません。残りの手順をスキップして、:ref:`quick_start` に直接進んでください。
      * バージョンが **1.5.1 以下の場合** 、更新を続けてください。

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center


   #. **Upgrade Firmware** をタップし、ファームウェアファイルを選択して更新の完了を待ちます：

      * **Upgrade Firmware** ボタンをタップし、先ほどデバイスにダウンロードした ``ai-camera-firware.ino.x.x.x.bin`` ファイルを選択します。
      * 更新はすぐに開始され、通常1〜2分かかります。完了したら **CONFIRM** を選択して GalaxyRVR を再起動します。

      .. image:: img/faq_ota_b.png
         :width: 700

   #. 更新が完了すると、GalaxyRVR の WiFi ホットスポット名は "AI Camera-xxxxxx" に変更され、パスワードは "12345678" のままです。


3. R3 ファームウェア更新後の起動確認
--------------------------------------------

#. GalaxyRVR の電源を入れ、底部のライトストリップを確認します。

   * GalaxyRVR を初めて使用する前に、付属の Type-C USB ケーブルでバッテリーを完全に充電してください。
   * 電源スイッチをオンにします。
   * モードを **Run** に切り替え、R3 ボードの **Reset** ボタンを押します。
   * 底部のライトストリップが点滅し、起動成功を示します。

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

#. 底部のライトストリップを確認します。

   * 底部のライトストリップが **緑色に点滅** している場合、R3 のファームウェアは正常に動作しています。 :ref:`quick_start` に進んでください。
   * 底部のライトストリップが **他の色** で点滅している場合は、:ref:`update_uno_firmware` で R3 のファームウェアを再インストールしてください。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            お使いのブラウザはこのビデオタグをサポートしていません。
        </video>

.. important::

   * このファームウェアにより、GalaxyRVR はアプリのコマンドに応答できるようになります。
   * RoboPilot リモートコントロールアプリまたは Mammoth Coding ソフトウェアを使用する際に、追加のコードをアップロードする必要はありません。
   * これで :ref:`quick_start` に進み、GalaxyRVR の旅を始めることができます！
