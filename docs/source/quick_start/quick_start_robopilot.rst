


通过 APP 快速开始
=========================

准备好开始您的火星冒险了吗？
通过 RoboPilot App 的快速开始功能，组装好 GalaxyRVR 后即可开始探索。

使用 RoboPilot，您可以：

- 以第一人称视角驾驶火星车
- 在三种控制模式间切换： **Remote** 、 **Avoid** 和 **Follow**


.. note::

    * 如果您已覆盖固件并需要恢复通信，请按照 :ref:`update_r3_firmware` 进行操作。

快速指南
---------------------

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


#. 从 **APP Store（iOS）** 或 **Google Play（Android）** 安装 **RoboPilot** 。

#. 将您的移动设备连接到 GalaxyRVR 的 WiFi 网络。

   * 网络名称（SSID）为 ``GalaxyRVR``，密码为 ``12345678``。
   * 如果看到提示"无互联网访问"，请选择 **"保持连接"** 选项。

     .. image:: ../img/camera_lan.png
        :width: 500

#. 打开 RoboPilot。点击 'Go into' 进入控制界面。

   .. image:: img/rp1_inter.png



Remote 模式
----------------------------------------------

进入控制界面后，您将看到以下画面。
背景显示的是 GalaxyRVR 摄像头拍摄的视图，并叠加了遥控控件。

.. image:: img/rp2_page.png

以下是各控件的说明：

A. Back（返回）
B. Settings（设置）：在此处可以更改 AP（热点）的名称和密码、设置 WiFi、翻转图像以及断开连接。

   .. image:: img/rp3_setting.jpg

C. Battery level indicator（电池电量指示器）
D. Pause/Run the APP（暂停/运行 APP）
E. Mode Selection（模式选择）：在此处可以选择 Remote 模式、Avoid 模式和 Follow 模式。默认设置为 **Remote 模式** 。

   .. image:: img/rp4_mode.jpg

F. Obstacle monitor（障碍物监测）：此模块分为三个区域，左右两侧显示避障模块的检测结果，中央区域显示超声波传感器的探测结果。
G. Color selector（颜色选择器）：在此处选择底盘的灯光颜色。

   .. image:: img/rp5_color.png

H. Camera LED switch（摄像头 LED 开关）
I. Adjust the gimbal angle（调节云台角度），范围 0-130°。0° 时朝向天空。
J. Move the joystick（移动摇杆）以控制 GalaxyRVR 的运动。轻推可使 GalaxyRVR 缓慢移动。


Avoid 模式与 Follow 模式
----------------------------------------------

* **Avoid 模式** ：GalaxyRVR 将向前移动并避开路径上的障碍物。
* **Follow 模式** ：GalaxyRVR 将朝向面前的物体移动，或左右转向以跟随物体的运动。

当您选择 **Avoid 模式** 或 **Follow 模式** 时，您将看到以下界面。GalaxyRVR 的实时摄像头画面构成背景，控制选项叠加在画面上方。

.. image:: img/rp6_avoid.png

**界面控件说明：**

A. **Speed Control（速度控制）** - 调整 GalaxyRVR 的运动速度
B. **Motor Control（电机控制）** - 启动或停止 GalaxyRVR 的运动
C. **Gimbal Control（云台控制）** - 调节摄像头角度，范围 0°（朝向天空）到 130°
D. **Obstacle Monitor（障碍物监测）** - 传感器的视觉反馈：

   - 左/右区域：红外障碍物检测
   - 中央区域：超声波距离测量

**调整障碍物检测范围**

在使用此模式前，请校准传感器检测范围以适应您的环境。出厂设置可能并非最佳。

- 范围过短：火星车可能撞上障碍物
- 范围过长：火星车可能不必要地转向

校准步骤：

1. **从右侧模块开始**

   - 确保发射器/接收器正确对齐
   - 如果在运输过程中弯曲，请将其掰直

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
        </video>

2. **测试并调整灵敏度**

   - 将障碍物放置在 20cm 处（使用火星车包装盒）
   - 旋转电位器直到指示灯亮起
   - 验证在所需距离处能否稳定触发
   - 如有需要，使用第二个电位器

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
        </video>

3. **对左侧模块重复相同操作**


重新连接
-------------------------------

如果网络失败或断开连接，您将跳转到此页面。

.. image:: img/rp7_reconnect.png

此时，请重置您的网络设置，然后点击与您的 GalaxyRVR 对应的 IP 以重新连接。
