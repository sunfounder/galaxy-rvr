通过 Scratch 快速开始
==================================

在本章中，您将学习如何 **在 Scratch（Mammoth Coding）中快速打开并运行示例项目** ，让您的 GalaxyRVR 动起来。

如果您想学习如何从头创建这些脚本，请参阅 :ref:`programming_scratch` 章节。

.. note::

    * GalaxyRVR 的 R3 板搭载了支持 RoboPilot App 和 Mammoth Coding 的固件。
    * 如果您已覆盖此固件并需要恢复通信，请按照 :ref:`update_r3_firmware` 进行操作。


如何快速打开 Scratch 示例
-------------------------------------

#. 从以下链接下载示例代码：

   * |download_galaxyrvr_code|

#. 解压下载的文件并将 ``scratch_codes`` 文件夹传输到您的移动设备。您可以使用任何文件传输工具，例如 **ES 文件浏览器** 或 **文件传输助手**。

   .. image:: img/scratch_mobile_save.png
      :width: 400

#. 在 **Google Play** 或 **Apple App Store** 上搜索 **Mammoth Coding** 并进行安装。

   .. image:: img/scratch_app_install.png
      :width: 600

#. 首次使用 GalaxyRVR 前，请使用附带的 Type-C USB 线将电池充满电。充电完成后，打开电源。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_start.mp4" type="video/mp4">
            您的浏览器不支持此视频标签。
        </video>

#. 要启动 ESP32 CAM，请将模式切换到 **Run** 并按下 R3 板上的 **Reset** 按钮。底部灯带将开始闪烁，表示启动成功。

   .. note::

      * 如果底部灯带显示 **非绿色的闪烁灯光** ，则您的 GalaxyRVR 需要固件更新。请参阅 :ref:`update_firmware`。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_reset_green.mp4" type="video/mp4">
            您的浏览器不支持此视频标签。
        </video>


#. 将您的移动设备连接到 GalaxyRVR 的 WiFi 网络。

   * 网络名称（SSID）为 ``GalaxyRVR``，密码为 ``12345678``。
   * 如果看到提示"无互联网访问"，请选择 **"保持连接"** 选项。


     .. image:: ../img/camera_lan.png
        :width: 500

#. 在应用中，点击 **File（文件）** > **Open from device（从设备打开）** 浏览本地文件。

   .. image:: img/scratch_open_file.png
        :width: 600

#. 选择一个 ``.sb3`` 文件将其打开。

   .. image:: img/scratch_mobile_save.png
      :width: 400

#. 点击绿色旗帜图标启动脚本。

   .. image:: img/scratch_run.png

示例
---------------

**基础项目**

这些项目是使用 Mammoth Coding 控制 GalaxyRVR 的基础课程。它们将逐步指导您如何使用 GalaxyRVR。


* ``3_move.sb3``：使用方向键实时控制您的 GalaxyRVR 移动。
* ``4_ultrasonic.sb3``：火星车前进并使用超声波模块自动避障。
* ``5_ultra_animate_jump.sb3``：创建火星车在火星表面欢快移动的动画场景。
* ``6_ir_obstacle_avoid.sb3``：火星车前进并使用红外传感器避障。
* ``7_ir_obstacle_avoid_animate.sb3``：通过用手触发红外传感器，控制火星车精灵躲避火星表面的岩石。
* ``8_ir_ultrasonic_avoid.sb3``：火星车同时使用超声波和红外传感器，平稳地绕开障碍物。
* ``9_ir_ultrasonic_follow.sb3``：火星车跟随您：当您站在前方时靠近，在侧面时转向，远离时停止。
* ``10_rgb.sb3``：点击彩色球体，让火星车的 RGB 灯发出相应颜色的光。
* ``10_rgb_animate.sb3``：火星车根据按下的方向键移动并改变灯光颜色。
* ``1scratch_servo.sb3``：使用方向键调整火星车的摄像头角度；点击可重置位置。
* ``1scratch_servo_stage.sb3``：触摸并拖动屏幕上的箭头，实时平滑地控制火星车摄像头的指向。
* ``12_camera.sb3``：从火星车的视角查看实时摄像头画面，探索周围环境。
* ``13_realtime_control.sb3``：通过 Scratch 实时控制火星车的运动和灯光。

**趣味项目**

这些有趣的 Scratch 项目无需 GalaxyRVR。
您可以在 ``scratch_codes/fun/`` 文件夹中找到它们。

* ``1_scratch_balloon.sb3``：挡住左侧红外传感器给气球充气；别让它爆掉或掉下来！
* ``2_flappy_parrot.sb3``：在超声波传感器上方用手控制鹦鹉飞行，躲避竹竿。
* ``3_shooting.sb3``：使用避障模块瞄准并射击目标。
* ``4_eat_apple.sb3``：通过左侧红外传感器检测手势，引导甲虫找到苹果。
* ``5_fishing.sb3``：在适当时机挡住左侧红外传感器来钓鱼。
* ``6_sensitive_ball.sb3``：在超声波传感器上方用手上下移动球；当球触碰线条时触发声音和灯光。
* ``7_tap_white_tile.sb3``：使用两个红外传感器点击黑色方块得分——避开白色方块！
