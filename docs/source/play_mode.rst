.. note::

    你好，欢迎加入SunFounder树莓派、Arduino和ESP32爱好者社区！与志同道合的朋友们一起，深入探索树莓派、Arduino和ESP32的世界。

    **为什么加入？**

    - **专家支持**：我们的社区和团队将帮助你解决售后问题和技术难题。
    - **学习与分享**：交流技巧与教程，共同提升技能。
    - **独家预览**：抢先体验新品发布与独家内容。
    - **特别折扣**：享受我们的最新产品的独家折扣。
    - **节日促销与赠品**：参与我们的赠品活动与节日促销。

    👉 准备好与我们一起探索和创作了吗？点击 [|link_sf_facebook|]，立即加入！

.. _play_mode:

游戏模式
=========================

你是否迫不及待地想要开始你的火星之旅？我们的游戏模式正是为那些急于探索的你量身定制的。
主控板中预装了完整的代码，你只需组装好GalaxyRVR，就能立刻投入行动。
通过易于使用的SunFounder Controller应用程序，你可以体验多种功能，
包括第一人称驾驶、在避障模式与跟随模式之间切换，甚至还可以通过语音控制。

.. raw:: html
    
    <video width="600" loop autoplay muted>
        <source src="_static/video/play_mode.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

在你出发探索红色星球之前，让我们确保你已经做好了充分的准备。
下面是一个快速指南，帮助你顺利开始这次激动人心的冒险！

.. note::

    * 如果你的R3板已经上传了其他代码，但你仍希望使用游戏模式，你需要下载相关代码。

        * :download:`GalaxyRVR代码 <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/main.zip>`

    * 安装 |link_download_arduino|

    * 接着，打开位于 ``galaxy-rvr-main\galaxy-rvr`` 目录下的 ``galaxy-rvr.ino`` 文件。

    * 在示例程序中，你需要将手机设备连接到GalaxyRVR发布的热点，这将阻止你同时使用外部网络。你可以 :ref:`ap_to_sta`。将其设置为STA模式后，只要你的设备和GalaxyRVR处于同一WLAN中，就可以控制GalaxyRVR。
 
    * 将开关拨到右侧，然后点击 **上传** 。

    * 如果你出现弹出了  :ref:`install_lib`  问题，请点进该链接处理。

    .. image:: img/camera_upload.png
        :width: 400
        :align: center


快速指南
---------------------

#. 启动GalaxyRVR。

    * 第一次使用GalaxyRVR时，建议先插入一根Type-C USB线进行完全充电，然后打开电源。

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/play_start.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    * 要激活ESP32 CAM，将模式开关拨到 **运行** 位置，并按下 **复位** 按钮以重启R3板。此时你将看到底部条形灯闪烁青色光。

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/play_reset.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

#. 从 **APP Store(iOS)** 或 **Google Play(Android)** 安装 `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_，或者扫描以下二维码，下载安装SunFounder Controller。

        .. image:: img/app/qrcode.png
         :width: 60%

            

#. 连接到 ``GalaxyRVR`` 网络。

    为了实现移动设备与Rover之间的最佳通信，你需要将它们连接到GalaxyRVR提供的同一个局域网(LAN)。

    * 在你的移动设备（平板或智能手机）上找到 ``GalaxyRVR`` ，输入密码 ``12345678`` 并连接。

        .. image:: img/app/camera_lan.png

    * 默认连接模式是 **AP模式** 。连接后，可能会弹出警告提示该网络没有互联网连接。如果是这样，选择“保持连接”。

        .. image:: img/app/camera_stay.png

#. 设置控制器。

    * 在SunFounder Controller中创建一个控制器，点击 **+** 图标。

        .. image:: img/app/app1.png

    * 对于某些产品，预设了控制器，这里我们选择 **GalaxyRVR** 。给它起个名字，或者直接点击 **确认** 。

        .. image:: img/app/play_preset.jpg

    * 进入后，应用程序会自动搜索GalaxyRVR。稍等片刻，你将看到“连接成功”的提示。

        .. image:: img/app/auto_connect.jpg

        .. note::

            * 如果未连接，请确认你的Wi-Fi已连接到 ``GalaxyRVR`` 。
            * 你也可以点击 |app_connect| 按钮手动连接。稍等片刻，你应该会看到 ``GalaxyRVR(IP)`` 出现。点击它以建立连接。

            .. image:: img/app/camera_connect.png
                :width: 300
                :align: center

    * 现在，点击 |app_run| 按钮，你可以查看来自摄像头的实时视频并通过提供的控件来控制小车。

        .. image:: img/app/play_run_view.jpg

#. 接下来，让我们深入了解每个控件的功能：


        * **Servo(D)**：控制Rover摄像头的俯仰角度，让你可以观察更广阔的视野。

        * :ref:`app_avoid`：将Rover切换到避障模式。每个避障模块的工厂设置检测距离可能不同，需要手动调整。

        * :ref:`app_follow`：切换到跟随模式。每个避障模块的工厂设置检测距离可能不同，需要手动调整。

        * **Stop(I)**：立即停止Rover的所有动作。

        * :ref:`app_speech_control`：按下此控件启动语音识别，使Rover执行相应的动作。

        * **HeadLamp(M)**：控制ESP32 CAM上的LED开关。

        * **Throttle Widgets on K and Q**：K区域的油门控件控制Rover的左侧电机，Q区域的控件控制右侧电机。协调使用这两个控件可以让GalaxyRVR向任何方向移动。

        * **Left IR(N)**：显示左侧避障模块的读数。

        * **Ultrasonic(O)**：显示超声波模块的测距结果。

        * **Right IR(P)**：显示右侧避障模块的读数。

.. _app_avoid:

避障(E)
------------------------

点击 **避障(E)** 控件以启动避障模式。

在启用此模式之前，可能需要根据当前环境调整传感器的检测范围，因为工厂设置可能不适合所有情况。

如果两个红外模块的检测范围过短，火星Rover可能会碰到障碍物；相反，如果范围过长，Rover可能会偏离障碍物太远，导致导航偏差。

下面是如何微调设置：

#. 从调整右侧避障模块开始。在运输过程中，碰撞可能导致红外模块的发射器和接收器发生倾斜，因此你需要手动将其矫正。

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. 将一个障碍物放置在右侧模块前约20厘米处。我们Rover套件的包装盒就是一个很好的选择！现在，旋转模块上的电位器，直到模块上的指示灯刚好亮起。然后，来回移动障碍物，检查指示灯是否在期望的距离亮起。如果指示灯没有在正确的距离亮起，或者始终亮着不熄灭，你需要调整另一个电位器。

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. 对另一个模块重复相同的过程。

.. _app_follow:

跟随(F)
------------

当你准备好启动跟随模式时，只需点击 **跟随(F)** 控件。如果你之前没有调整避障模块的检测距离，你需要先按照 :ref:`app_avoid` 中的步骤进行调整。

进入跟随模式后，GalaxyRVR会向前方的物体移动，或左右转动以跟随物体的运动。

.. _app_speech_control:

STT(J)
-------------------


STT代表语音转文本（Speech to Text）。SunFounder Controller应用集成了你手机设备的语音识别引擎。
因此，当你点击并按住 **STT(J)** 控件并对着手机设备说话时，

你的设备会捕捉到你的语音，将其转换为文本并发送给GalaxyRVR。如果该文本与代码中预设的命令匹配，Rover将执行相应的动作。

以下是当前代码中预设的命令。说出以下任何命令，观察GalaxyRVR的反应。

.. image:: img/app/play_speech.png
    :width: 600

* ``stop``：停止Rover的所有动作。
* ``forward``：让Rover向前移动。
* ``backward``：让Rover向后移动。
* ``left``：让Rover向左转。
* ``right``：让Rover向右转。

.. note::

    STT（语音转文本）功能需要Android设备的互联网连接和Google服务。然而，这在GalaxyRVR的预设AP（接入点）模式下无法使用。
    
    在AP模式下，GalaxyRVR会创建一个本地Wi-Fi网络供你的移动设备连接，但它不提供互联网访问。
    
    要在Android设备上使用STT功能，请按照 :ref:`stt_android` 将Rover的代码从AP模式切换为STA模式。

.. note::

    使用离线语音识别引擎的iOS设备，在AP和STA模式下均可正常工作。
