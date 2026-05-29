.. _rvr_move:

第3课：远程控制你的 GalaxyRVR
============================================

准备好掌控一切！在本课中，你将成为你自己的 GalaxyRVR 火星车的任务指挥官。

我们将把编码知识转化为实际操作，编程让您的火星车在模拟的火星地形上导航。看着你的指令让火星车生动起来，按照你的指挥在教室里移动。

这就是你的火星任务真正开始的地方——让我们开始驾驶吧！

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>

学习目标
-----------------------

* 通过上传必要的 Arduino 代码，设置 Mammoth Coding 应用与你的 GalaxyRVR 之间的通信
* 掌握使用应用中的方向键界面控制火星车移动
* 编程并执行火星车的四种基本操作：前进、后退、左转和右转

.. _app_connect:

连接应用到 GalaxyRVR
-------------------------------------------

.. note::

    * 如果你覆盖了固件且需要恢复通信，请参考 :ref:`update_r3_firmware`。

#. 首次使用 GalaxyRVR 之前，请使用附带的 Type-C USB 数据线将电池充满电。充电后，打开电源。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_start.mp4" type="video/mp4">
            您的浏览器不支持此视频标签。
        </video>

#. 启动 ESP32 CAM，将模式开关切换到 **运行** 档，并按下 R3 主板上的 ** 复位** 按钮。底部灯带将开始闪烁，表示启动成功。

   .. note::

      * 如果底部灯带显示 **非绿色的闪烁灯光** ，则你的 GalaxyRVR 需要更新固件。请参考 :ref:`update_firmware`。

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_reset_green.mp4" type="video/mp4">
            您的浏览器不支持此视频标签。
        </video>

#. 将你的移动设备连接到 GalaxyRVR 的 WiFi 网络。

   * 网络名称（SSID）为 ``GalaxyRVR``，密码为 ``12345678``。
   * 如果看到"无互联网连接"的警告，请选择 **"保持连接"** 。

     .. image:: ../img/camera_lan.png
        :width: 500

#. 在你的移动设备上打开应用，开始连接过程。

   .. image:: img/connet_app_04.png

#. 在应用中选择并加载 GalaxyRVR 扩展。

   .. image:: img/connet_app_05.png

#. 应用将自动扫描并搜索可用的 GalaxyRVR 设备。

   .. image:: img/connet_app_06.png

#. 从列表中选择你的 GalaxyRVR 进行连接。

   .. image:: img/reconnect_2.png

   .. note::

      连接状态由 GalaxyRVR 的 LED 灯指示：

      - **闪烁紫色** ：正在搜索连接
      - **灯灭** ：连接成功，准备就绪

重新连接应用
-------------------------------------

当你的设备与 GalaxyRVR 断开连接时，界面上将弹出此窗口。点击重新连接。

   .. image:: img/reconnect_0.png

如果你关闭了弹出窗口，也可以通过点击 GalaxyRVR 分类中的此按钮重新连接。

   .. image:: img/reconnect_1.png

找到你的 GalaxyRVR 并点击连接。

   .. image:: img/reconnect_2.png


通过应用控制 GalaxyRVR
-----------------------------------------

1. 在编码界面中，找到包含所有火星车控制积木块的专用 GalaxyRVR 分类。

   .. image:: img/3_rvr_catego.png

2. 虽然我们通常使用绿旗来启动程序，但也有其他方式触发操作。在事件分类中找到 ``当按下上箭头键`` 积木块——它会在你按下该键时执行代码。

   .. image:: img/3_rvr_when_arrow.png

3. 创建四个事件积木块——每个箭头方向对应一个（上、下、左、右）。这将构成火星车控制系统的基础。

   .. image:: img/3_rvr_4_arrow.png
        :width: 800
        :align: center

   .. note:: 需要更多编码空间？点击绿旗下方的眼睛图标可暂时隐藏舞台区域。

4. 现在用相应的移动命令完成每个事件积木块：

   - 上箭头 → 前进
   - 下箭头 → 后退
   - 左箭头 → 左转
   - 右箭头 → 右转

   .. image:: img/3_rvr_4_dir.png
        :width: 800
        :align: center

5. 点击舞台展开按钮，进入全控制模式。

   .. image:: img/3_rvr_stage.png

6. 你现在将看到一个放大的舞台，带有虚拟方向键。按下这些键，你将实时直接控制你的 GalaxyRVR 的移动！

   .. image:: img/3_rvr_stage2.png


移动控制积木块
-----------------------------

* **基本方向控制**

  控制 GalaxyRVR 的移动方向。使用下拉菜单选择前进、后退、左转或右转。

  .. image:: img/block/move_forward.png

* **速度设置**

  设置 GalaxyRVR 的移动速度。注意：此积木块仅设置速度，本身不会启动移动。

  .. image:: img/block/move_set_speed.png

* **定时移动**

  使 GalaxyRVR 沿所选方向移动特定时长。你可以：

  * 从下拉菜单中选择方向（前进/后退/左转/右转）
  * 更改时间值来设置移动时长

  .. image:: img/block/move_forward_1s.png

* **速度控制移动**

  以特定速度百分比移动 GalaxyRVR。你可以：

  * 从下拉菜单中选择移动方向
  * 调整速度百分比（0-100%）

  .. image:: img/block/move_forward_80.png

* **精确移动控制**

  结合速度和时间控制，实现精确移动。你可以：

  * 设置移动方向
  * 调整速度百分比
  * 设置移动时长

  .. image:: img/block/move_forward_80_1s.png

* **高级车轮控制**

  独立控制每个车轮，实现复杂操作。你可以：

  * 分别设置左轮速度
  * 分别设置右轮速度
  * 控制移动时长

  .. image:: img/block/move_lr_sp_1s.png

* **紧急停止**

  立即停止 GalaxyRVR 的所有移动。

  .. image:: img/block/move_stop.png


