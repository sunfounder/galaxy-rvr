.. _sc_shooting:

趣味3 射击
====================================

你是否在电视上看过那些激动人心的射击游戏，参赛者精准地瞄准靶心得分？现在，你在 Scratch 中就能体验同样的刺激！在我们的互动射击游戏中，你将使用准星精灵瞄准并尽可能接近靶心，每发精准射击都能最大化你的得分。

首先，点击绿旗。你将通过创新的避障模块控制射击。准备好测试你的瞄准和反应能力了吗？看看你能得多少分！


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4" type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>

以下是实现该项目的步骤。建议先按照这些步骤操作，熟悉后可以根据需要修改效果。

1. 绘制 **准星** 精灵
----------------------------------------------

* 删除默认精灵，点击 **精灵** 按钮，然后选择 **绘制**。

  .. image:: img/shooting_paint_cross.png

* 进入 **造型** 页面。使用 ** 圆形** 工具，移除填充颜色，设置轮廓的颜色和宽度。

  .. image:: img/shooting_paint_cross1.png

* 使用 **圆形** 工具画一个圆。绘制完成后，使用 ** 选择** 工具将圆的中心与画布中心对齐。

  .. image:: img/shooting_paint_cross2.png

* 使用 **线段** 工具在圆内画一个十字。

  .. image:: img/shooting_paint_cross3.png

* 最后，返回 **代码** 页面，将精灵重命名为 "Crosshair"。

  .. image:: img/shooting_paint_cross4.png

2. 绘制 **靶子** 精灵
----------------------------------------

* 同样，点击 **精灵** 按钮，然后选择 **绘制**。

  .. image:: img/shooting_paint_target1.png

* 进入 **造型** 页面。使用 ** 圆形** 工具，选择黑色，移除轮廓，画一个大圆。

  .. image:: img/shooting_paint_target3.png
    :width: 90%

* 使用相同的方法绘制更多的圆，每个使用不同的颜色。使用 **前移** 或 ** 后移** 工具调整重叠圆的位置，确保所有圆的中心与画布中心对齐。

  .. image:: img/shooting_paint_target4.png
    :width: 90%

* 返回 **代码** 页面，将此精灵重命名为 "Target"。

  .. image:: img/shooting_paint_target5.png

3. 添加背景
--------------------------

* 添加一个合适的背景，最好颜色不太丰富，且不与 **Target** 精灵的颜色冲突。我选择了 **Wall1** 背景。

  .. image:: img/shooting_choose_backdrop.png

* 调整 **Target** 和 **Crosshair** 精灵的位置和大小。

  .. note::

    * 确保 **Crosshair** 精灵图层在 **Target** 精灵之上，方法是先移动 **Target** 精灵，再移动 **Crosshair** 。
    * **Crosshair** 应小于 **Target** 精灵颜色环之间的间距。

  .. image:: img/shooting_choose_backdrop1.png

4. 为 **准星** 精灵编写脚本
---------------------------------------

* 随机化 **Crosshair** 精灵的位置和大小，使其能够不可预测地移动。

  .. image:: img/shooting_script_cross.png

* 当左侧避障模块被遮挡时，广播一条消息 - 射击。

  .. image:: img/shooting_script_cross1.png

* 当收到 **shooting** 消息时，精灵停止移动并逐渐缩小，模拟子弹射击效果。

  .. image:: img/shooting_script_cross2.png

* 使用 [碰到颜色 ()] 积木块判断射击位置。

  .. image:: img/shooting_script_cross3.png
    :width: 90%

* 如果射中黄色圆圈内部，得分为 10。

  .. image:: img/shooting_script_cross4.png

* 如果射中红色圆圈内部，得分为 9。同样，使用 [碰到颜色 ()] 积木块匹配红色圆圈的颜色。

  .. image:: img/shooting_script_cross5.png
    :width: 90%

* 使用相同的方法确认子弹的落点。如果没有落在 **Target** 精灵上，则表示脱靶。

  .. image:: img/shooting_script_cross6.png

编程完成。现在你可以点击绿旗运行脚本，看看是否达到了预期效果。


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_shooting.mp4"  type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>
