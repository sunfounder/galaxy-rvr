.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

.. _update_firmware:

ファームウェアの更新
==========================

製品の継続的な改良により、お使いのデバイスに最新のファームウェアが搭載されていない場合があります。
最適で安定したパフォーマンスを確保するために、以下の手順に従って ESP32 CAM および R3 ボードのファームウェアを確認し、更新してください。

1. 更新が必要かどうかの確認
-------------------------------------

#. GalaxyRVR を初めて使用する前に、付属の Type-C USB ケーブルでバッテリーを完全に充電してください。充電後、電源をオンにします。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_start.mp4" type="video/mp4">
            お使いのブラウザはこのビデオタグをサポートしていません。
        </video>

#. ESP32 CAM を起動するには、モードを **Run** に切り替え、R3 ボードの **Reset** ボタンを押します。底部のライトストリップが点滅し、起動成功を示します。

   .. note::

      * 底部のライトストリップが **緑色に点滅** している場合、ESP32 ファームウェアは最新です。
      * :ref:`quick_start` に進んでください。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset_green.mp4" type="video/mp4">
            お使いのブラウザはこのビデオタグをサポートしていません。
        </video>

#. 底部のライトストリップが **他の色** で点滅している場合は、以下を実行する必要があります：

   * :ref:`update_esp32_firmware`
   * :ref:`update_r3_firmware`

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/play_reset.mp4" type="video/mp4">
            お使いのブラウザはこのビデオタグをサポートしていません。
        </video>


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
      :width: 90%
      :align: center


**バージョン A**

   6. OTA ページで、ファームウェアファイルを選択するボタンをクリックします。

      .. image:: img/faq_cam_ota_choose.png
         :width: 400

   #. デバイスから先ほどダウンロードした ``ai-camera-firmware-vX.X.X-ota.bin`` ファイルを選択し、 **Add** をクリックします。

      .. image:: img/faq_cam_ota_file.png
         :width: 400

   #. **Update** ボタンをクリックして、ファームウェアの更新プロセスを開始します。

      .. image:: img/faq_cam_ota_update.png
         :width: 400

   #. 更新が完了するまで待ちます。

      .. image:: img/faq_cam_ota_finish.png
         :width: 400

   #. 更新が完了したら、ウェブブラウザを閉じてください。 **Reset** ボタンを押してデバイスを再起動します。これで ESP32 CAM は通常の動作が可能になります。

      .. image:: img/camera_reset.png
         :width: 600

   .. note:: 更新が完了すると、GalaxyRVR の WiFi ホットスポット名は "AI Camera-xxxxxx" に変更され、パスワードは "12345678" のままです。


**バージョン B**


   6. **OTA** ページで、ウェブページに表示されている現在のファームウェアバージョンを確認します。

      * バージョン番号が **1.5.1 より新しい場合** 、更新は必要ありません。残りの手順をスキップして、:ref:`quick_start` に直接進んでください。
      * バージョンが **1.5.1 以下の場合** 、更新を続けてください。

      .. image:: img/firmware_version.jpg
         :width: 50%
         :align: center


   #. **Upgrade Firmware** ボタンをタップします。

      .. image:: img/firmware_tap.jpg
         :width: 50%
         :align: center

   #. ファイル選択ダイアログが表示されます。先ほどモバイルデバイスに転送した ``ai-camera-firware.ino.x.x.x.bin`` ファイルを参照して選択します。

      .. image:: img/firmware_select.jpg
         :width: 50%
         :align: center

   #. ファイルを選択すると、ファームウェアの更新がすぐに開始されます。

      .. image:: img/firmware_upgrade.jpg
         :width: 50%
         :align: center

   #. ファームウェアのアップグレードが完了するまで待ちます。

      * アップロードプロセスは通常1〜2分かかります。完了すると、ポップアップウィンドウに成功メッセージが表示されます。
      * その後、 **CONFIRM** を選択して GalaxyRVR を再起動するか、 **CLOSE** を選択してウィンドウを閉じることができます。

      .. image:: img/firmware_finish.jpg
         :width: 50%
         :align: center


.. _update_r3_firmware:

3. R3 ボードファームウェアの更新
--------------------------------------

R3 ボードには、RoboPilot APP および Mammoth Coding との通信を可能にするファームウェアが組み込まれています。

以下の場合、このファームウェアを再アップロードする必要があります：

- お使いのデバイスが古いファームウェアバージョンを使用している場合、または
- 独自の Arduino コードを書き込んでおり、互換性を復元したい場合。

以下の手順に従って、通信ファームウェアを再インストールしてください。

#. Arduino とコンピューターを USB ケーブルで接続し、車の **upload** スイッチをアップロード側に切り替えます。

   .. image:: img/camera_upload.png
        :width: 500
        :align: center

   .. note:: Arduino に接続するのは USB Type B ポートです。充電用の USB Type C ポートではありません。

#. ファームウェアファイルがダウンロードされているか確認します。

   * |download_galaxyrvr_filmware|

#. 更新スクリプトを実行します

   * ``galaxy-rvr.ino.xxx`` フォルダー（前の手順でダウンロードおよびインストール済み）を開きます。
   * ``update-arduino-firmware.bat`` スクリプトをダブルクリックします。
   * コマンドプロンプトウィンドウが自動的に表示されます。

   .. image:: img/faq_bat_file.png

#. シリアルポートを選択してアップロードします

   * コマンドプロンプトに、利用可能なシリアルポートのリストが表示されます。
   * 左側に表示されているシーケンス番号を入力して、Arduino Uno のシリアルポートを選択します。
   * **Enter** キーを押して、自動アップロードを開始します。
   * 例：リストに `1 USB-SERIALXXX (COMxx)` と表示されている場合、 **1** を入力して **Enter** キーを押します。

   .. image:: img/faq_select_com.png

#. アップロードが完了するのを待ってから、USB ケーブルを抜いてください。

   .. image:: img/faq_uno_updating.png

   .. note::

      このコードにより、GalaxyRVR は APP コマンドに応答できるようになります。RoboPilot リモートコントロール APP または Mammoth Coding ソフトウェアを使用する際に、追加のコードをアップロードする必要はありません。

#. これで :ref:`quick_start` に進み、GalaxyRVR の旅を始めることができます！
