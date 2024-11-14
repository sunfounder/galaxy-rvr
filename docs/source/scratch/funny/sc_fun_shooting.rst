.. note:: 

    你好，欢迎加入 SunFounder 树莓派、Arduino 和 ESP32 爱好者社区！与其他爱好者一起，深入探索树莓派、Arduino 和 ESP32。

    **为什么加入？**

    - **专家支持**：通过社区和团队的帮助解决售后问题和技术挑战。
    - **学习与分享**：交流技巧和教程，提升你的技能。
    - **独家预览**：提前体验新产品发布和独家内容。
    - **专属折扣**：享受最新产品的专属优惠。
    - **节庆促销与赠品**：参与节日促销和赠品活动。

    👉 准备好与我们一起探索和创造了吗？点击 [|link_sf_facebook|] 即刻加入！

.. _sc_shooting:

扩展项目 3：射击游戏
====================================

你是否曾看过那些令人兴奋的射击游戏，参赛者通过精确瞄准靶心来积累分数？现在，你可以在 Scratch 中亲身体验这种刺激感受！在我们的互动射击游戏中，你将使用准星角色来瞄准并尽可能接近靶心，每一发准确的射击都能最大化你的得分。

首先，点击绿色旗帜。你将使用创新的避障模块来控制你的射击。准备好挑战你的瞄准和反应速度了吗？让我们看看你能得多少分！

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

以下是实现该项目的步骤。建议初次按照这些步骤进行，熟悉后可以根据需要调整效果。

1. 绘制 **准星** 角色
----------------------------------------------

* 删除默认角色，点击 **角色** 按钮，选择 **画画**。

  .. image:: img/shooting_paint_cross.png

* 转到 **造型** 页面。使用 **圆形** 工具，去掉填充颜色，设置边框颜色和宽度。

  .. image:: img/shooting_paint_cross1.png

* 使用 **圆形** 工具绘制一个圆形，绘制完成后，使用 **选择** 工具将圆心对齐到画布的中心。

  .. image:: img/shooting_paint_cross2.png

* 使用 **线条** 工具在圆形内绘制一条十字线。

  .. image:: img/shooting_paint_cross3.png

* 最后，返回到 **代码** 页面，并将角色重命名为“准星”。

  .. image:: img/shooting_paint_cross4.png

2. 绘制 **靶子** 角色
----------------------------------------

* 同样，点击 **角色** 按钮，选择 **画画**。

  .. image:: img/shooting_paint_target1.png

* 进入 **造型** 页面。使用 **圆形** 工具，选择黑色，去掉边框，绘制一个大圆形。

  .. image:: img/shooting_paint_target3.png
    :width: 90%

* 使用相同方法绘制多个不同颜色的圆形，调整重叠圆形的位置，确保所有圆形的圆心对齐到画布中心。

  .. image:: img/shooting_paint_target4.png
    :width: 90%

* 返回 **代码** 页面，并将该角色重命名为“靶子”。

  .. image:: img/shooting_paint_target5.png

3. 添加背景
--------------------------

* 添加一个适合的背景，最好颜色不太鲜艳，且不与 **靶子** 角色的颜色相匹配。我选择了 **墙壁1** 背景。

  .. image:: img/shooting_choose_backdrop.png

* 调整 **靶子** 和 **准星** 角色的位置和大小。

  .. note::

    * 确保 **准星** 角色在 **靶子** 角色之上，通过先移动 **靶子** 再移动 **准星** 来调整层次关系。
    * **准星** 角色的大小应小于 **靶子** 角色的颜色环之间的间距。

  .. image:: img/shooting_choose_backdrop1.png

4. 为 **准星** 角色编写脚本
---------------------------------------

* 随机化 **准星** 角色的位置和大小，使其移动不规则。

  .. image:: img/shooting_script_cross.png

* 当左侧避障模块被挡住时，广播一条消息——“射击”。

  .. image:: img/shooting_script_cross1.png

* 当接收到 **射击** 消息时，角色停止移动并逐渐缩小，模拟子弹发射。

  .. image:: img/shooting_script_cross2.png

* 使用 [Touch color ()] 块确定射击的位置。

  .. image:: img/shooting_script_cross3.png
    :width: 90%

* 如果射击命中黄色圆环，得分 10 分。

  .. image:: img/shooting_script_cross4.png

* 如果射击命中红色圆环，得分 9 分。使用 [Touch color ()] 块来匹配红色圆环的颜色。

  .. image:: img/shooting_script_cross5.png
    :width: 90%

* 使用相同的方法确认子弹着陆的情况。如果未命中 **靶子** 角色，则表示未命中。

  .. image:: img/shooting_script_cross6.png

编程完成后，你可以点击绿色旗帜运行脚本，查看效果是否符合预期。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_shooting.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>