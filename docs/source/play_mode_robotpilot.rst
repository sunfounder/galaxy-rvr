.. note:: 

    你好，欢迎加入 SunFounder Raspberry Pi、Arduino 和 ESP32 爱好者社区！与其他爱好者一起，深入探索 Raspberry Pi、Arduino 和 ESP32。

    **为什么加入？**

    - **专家支持**：借助社区和团队的帮助解决售后问题和技术难题。
    - **学习与分享**：交换技巧和教程，提升你的技能。
    - **独家预览**：提前体验新品发布和独家内容。
    - **特别折扣**：享受最新产品的专属折扣。
    - **节日促销与赠品**：参与赠品活动和节日促销。

    👉 准备好和我们一起探索与创作了吗？点击 [|link_sf_facebook|]，立即加入！

.. _play_robopilot:

Play RoboPilot
=========================

你是否迫不及待想开始你的火星之旅？  
我们的“试玩模式”专为那些等不及要投入探索的你准备。  
只需组装好 GalaxyRVR，便可直接启动，代码已预装在出厂设备中。  
使用用户友好的 RoboPilot 应用，探索其丰富功能，包括第一人称驾驶、在避障模式和跟随模式之间切换。

.. image:: img/robopilot/rp1_inter.png

不过，在你出发探索红色星球之前，让我们确保你已准备好一切，迎接这场冒险。  
以下是快速指南，助你开启这段激动人心的旅程！

.. note::

    * 如果你的 R3 板已经上传了其他代码，但你仍想使用试玩模式，你需要下载相关代码。

        * :download:`GalaxyRVR 代码 <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/scratch.zip>`

    * 安装 |link_download_arduino|，然后 :ref:`install_lib`。

    * 然后，打开位于 ``galaxy-rvr-scratch\galaxy-rvr`` 目录中的 ``galaxy-rvr.ino`` 文件。
    
    * 在示例程序中，你需要将移动设备连接到 GalaxyRVR 发布的热点，这样你就无法同时使用外部网络了。你可以 :ref:`ap_to_sta`。将其设置为 STA 模式后，只要你的设备和 GalaxyRVR 在同一个 WLAN 中，你就可以控制 GalaxyRVR。

    * 将开关切换到右侧，然后点击 **上传**。

    .. image:: img/camera_upload.png
        :width: 400
        :align: center


快速指南
---------------------

#. 启动 GalaxyRVR。

    * 第一次使用 GalaxyRVR 时，建议先插入 Type-C USB 数据线，完全充电后再开机。
    
        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/play_start.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

    * 要激活 ESP32 CAM，将模式开关切换到 **运行** 位置，并按下 **重启** 按钮重新启动 R3 板。此时，你会看到底部条带上的青色指示灯开始闪烁。

        .. raw:: html

            <video width="600" loop autoplay muted>
                <source src="_static/video/play_reset.mp4" type="video/mp4">
                Your browser does not support the video tag.
            </video>

#. 从 **APP Store(iOS)** 或 **Google Play(Android)** 安装 **RoboPilot**。

#. 连接到 ``GalaxyRVR`` 网络。

    为了确保你的移动设备和 Rover 之间的通信畅通无阻，你需要将它们连接到 GalaxyRVR 提供的相同局域网（LAN）。

    * 在移动设备（平板或智能手机）上查找 ``GalaxyRVR``，输入密码 ``12345678``，连接该网络。

        .. image:: img/app/camera_lan.png

    * 默认连接模式为 **AP 模式**。连接后，可能会弹出提示，告知该网络没有互联网连接。如果是这样，请选择“保持连接”。

        .. image:: img/app/camera_stay.png

#. 打开 RoboPilot，点击“进入”以进入控制界面。

.. image:: img/robopilot/rp1_inter.png



遥控
----------------------------------------------

进入控制界面后，你将看到如下屏幕。
背景展示的是 GalaxyRVR 相机捕捉的画面，遥控小部件则叠加在上面。

.. image:: img/robopilot/rp2_page.png

以下是控制项：

A. 返回  
B. 设置：在这里你可以更改设备名称、WiFi 设置、**调整相机角度**，并断开连接。

    .. image:: img/robopilot/rp3_setting.png

C. 电池电量指示器  
D. 暂停程序  
E. 模式选择：在这里你可以选择避障模式或遥控模式。默认设置为遥控模式。

    .. image:: img/robopilot/rp4_mode.png

F. 障碍物监控：该模块分为三个区域，左右两边显示来自障碍物模块的结果，中央区域则展示超声波传感器的探测结果。  
G. 颜色选择器：在这里选择底盘的照明颜色。

    .. image:: img/robopilot/rp5_color.png

H. 相机 LED 开关。  
I. 调整云台角度，范围为 0-135°，在 0° 时，镜头会朝上看向天空。  
J. 移动摇杆控制 GalaxyRVR 的运动。轻轻推动摇杆，GalaxyRVR 会缓慢移动。



障碍物检测
-------------------------------

切换到避障模式时，你将看到以下界面。  
背景再次展示 GalaxyRVR 相机的画面，并叠加有避障模式的控制选项。

.. image:: img/robopilot/rp6_avoid.png

以下是控制项：

A. 调整 GalaxyRVR 的速度。  
B. 在此切换 **避障** 和 **跟随** 模式。  
C. 启动/停止 GalaxyRVR 的自动移动。  
D. 调整云台角度，范围为 0-135°，在 0° 时，镜头会朝上看向天空。  
E. 障碍物监控：该模块分为三个区域，左右两边显示来自障碍物模块的结果，中央区域则展示超声波传感器的探测结果。

**避障**

.. 点击 **避障(E)** 控件以激活避障模式。

启用此模式之前，你可能需要根据当前环境调整传感器的检测范围，因为出厂设置可能并不适合所有情况。

如果两个红外模块的检测范围过短，火星探测器可能会撞到障碍物；相反，如果范围过长，探测器可能会偏离障碍物过远，从而干扰导航。

以下是如何微调设置：

#. 从右侧的避障模块开始调整。在运输过程中，红外模块的发射器和接收器可能会因碰撞而倾斜，因此需要手动将其调整直。

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust1.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. 在右侧模块前约 20 cm 处放置一个障碍物。我们的 Rover 套件所附的盒子就是一个很好的选择！此时，旋转模块上的电位器，直到模块上的指示灯刚好亮起。然后，不断移动障碍物，检查指示灯是否在预定距离处点亮。如果灯光没有在正确的距离亮起，或者一直亮着未熄灭，你需要调整另一个电位器。

    .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="_static/video/ir_adjust2.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. 对另一个模块重复相同的过程。

**跟随**

如果你之前没有调整避障模块的检测距离，请先按 **避障** 部分中的步骤进行调整。

进入跟随模式后，GalaxyRVR 会向前方的物体移动，或者根据物体的移动调整左右转向。






重新连接
-------------------------------

如果你的网络连接失败或断开，你将被引导至此页面。

.. image:: img/robopilot/rp7_reconnect.png

此时，请重置网络设置，然后点击与 GalaxyRVR 对应的 IP 重新连接。
