趣味6 感应球
===========================================================

在这个项目中，我们利用超声波模块控制球在舞台上的垂直运动。当你点击绿旗后，将手放在超声波模块上方。如果你的手与模块之间的距离小于 15 厘米，球将上升；否则，它将下降。当球触碰到线条时，会触发悦耳的声音并激活闪烁的星光效果。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4" type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>

按照以下步骤设置项目，熟悉工作原理后可以随意调整效果。

1. 选择精灵
--------------------------

* 移除默认精灵，选择 **Ball** 、 **Bowl** 和 **Star** 精灵。

  .. image:: img/ball_choose_sprite.png

* 将 **Bowl** 精灵放置在舞台中央底部并增大其大小。

  .. image:: img/ball_set_bowl.png

* 将 **Ball** 精灵直接放在 **Bowl** 精灵的上方，设置其方向为 0 以允许垂直移动。

  .. image:: img/ball_set_ball.png

* 调整 **Star** 精灵的大小，并将其方向设置为 180 以确保其向下掉落。如果需要，也可以改为其他角度。

  .. image:: img/ball_set_star.png

* 添加 **Stars** 背景以增加氛围感。

  .. image:: img/ball_select_backdrop.png

2. 绘制一个 **线条** 精灵
-------------------------------

* 现在添加一个 **Line** 精灵。

  .. image:: img/ball_select_line.png

* 进入 **Line** 精灵的 ** 造型** 页面。

  .. image:: img/ball_open_cos.png
    :width: 90%

* 稍微减小画布上红色线条的宽度，将其复制四份，并对齐这些线条。

  .. image:: img/ball_copy_line.png
    :width: 90%

* 为每条线条涂上不同的颜色。选择一条线条，使用 **填充** 工具，选择一种颜色。

  .. image:: img/ball_set_bk_color.png
    :width: 90%

* 使用此方法为所有线条上色。

  .. image:: img/ball_select_line_color.png
    :width: 90%

* 返回 **代码** 页面，将 **Line** 精灵放置在舞台顶部。

  .. image:: img/ball_line_position.png

3. 为 **球** 精灵编写脚本
-------------------------------------

在这里，我们为 **Ball** 精灵编写脚本，使其根据超声波模块检测到的距离上下移动，并设置运动约束以模拟落在 **Bowl** 精灵上。

* 当绿旗被点击时，设置 **Ball** 精灵的初始位置。

  .. image:: img/ball_script_ball1.png

* 使用 [如果那么否则] 积木块检查距离是否小于 15。如果为真，将 **Ball** 精灵向上移动 10 步，因为其方向设置为 0。

  .. image:: img/ball_script_ball3.png

* 否则，让 **Ball** 精灵下落，将其 Y 坐标限制在最小 -100，可根据需要调整，使其看起来像是落在 **Bowl** 精灵上。

  .. image:: img/ball_script_ball4.png

* 编写交互脚本，当 **Ball** 精灵碰到 **Line** 精灵时，将其 Y 位置记录到变量 **ball_coor** 中，并广播一个 **bling** 消息。

  .. image:: img/ball_script_ball5.png

4. 为 **星星** 精灵编写脚本
------------------------------------

* 当绿旗被点击时，初始隐藏 **Star** 精灵。收到 **Bling** 消息后，克隆 **Star** 精灵。

  .. image:: img/ball_script_star1.png

* 设置克隆体的位置和音效，使其与 **Ball** 精灵的位置同步。

  .. image:: img/ball_script_star2.png

* 让它在 -80 到 80 度之间随机旋转。

  .. image:: img/ball_script_star3.png

* 根据需要调整 **Star** 精灵的外观和行为，以增强视觉效果。

  .. image:: img/ball_script_star4.png

编程完成。点击绿旗运行脚本，看看它是否符合你的预期。


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4"  type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>
