扩展项目 6：距离敏感的球
===========================================================

在这个项目中，我们利用超声波模块来控制舞台上球的垂直移动。当你点击绿色旗帜时，将手放在超声波模块上方。如果手与模块之间的距离小于 15 厘米，球将上升；否则，球会下降。当球与某条线接触时，会触发悦耳的音效并激活闪烁的星光效果。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_sensitive_ball.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

以下是设置项目的步骤。初次设置时，建议按照这些步骤进行，熟悉之后，你可以根据自己的需求调整效果。

1. 选择角色
--------------------------

* 删除默认角色，并选择 **球**、**碗** 和 **星星** 角色。

  .. image:: img/ball_choose_sprite.png

* 将 **碗** 角色放置在舞台底部中央，并调整其大小。

  .. image:: img/ball_set_bowl.png

* 将 **球** 角色放置在 **碗** 角色正上方，设置其方向为 0，使其可以垂直移动。

  .. image:: img/ball_set_ball.png

* 调整 **星星** 角色的大小，并将其方向设置为 180，确保它能向下掉落。如果需要，也可以调整为其他角度。

  .. image:: img/ball_set_star.png

* 添加 **星空** 背景，以增强氛围效果。

  .. image:: img/ball_select_backdrop.png

2. 绘制 **线条** 角色
-------------------------------

* 现在添加一个 **线条** 角色。

  .. image:: img/ball_select_line.png

* 转到 **线条** 角色的 **造型** 页面。

  .. image:: img/ball_open_cos.png
    :width: 90%

* 稍微缩小画布上红色线条的宽度，复制四次，并对齐这些线条。

  .. image:: img/ball_copy_line.png
    :width: 90%

* 为每条线条设置不同的颜色。选择一条线，使用 **填充** 工具并挑选颜色。

  .. image:: img/ball_set_bk_color.png
    :width: 90%

* 使用相同方法给所有线条上色。

  .. image:: img/ball_select_line_color.png
    :width: 90%

* 返回到 **代码** 页面，并将 **线条** 角色放置在舞台的顶部。

  .. image:: img/ball_line_position.png

3. 为 **球** 角色编写脚本
-------------------------------------

在这里，我们为 **球** 角色编写脚本，让其根据超声波模块检测到的距离上下移动，并限制其移动范围以模拟落到 **碗** 角色上的效果。

* 点击绿色旗帜时，设置 **球** 角色的初始位置。

  .. image:: img/ball_script_ball1.png

* 使用 [if else] 块判断距离是否小于 15。如果距离符合条件，将 **球** 角色向上移动 10 步，前提是其方向设置为 0。

  .. image:: img/ball_script_ball3.png

* 否则，让 **球** 角色下落，并将其 Y 坐标限制为最小值 -100，可以调整以模拟落入 **碗** 角色的效果。

  .. image:: img/ball_script_ball4.png

* 编写脚本，使得 **球** 角色在接触到 **线条** 角色时，记录其 Y 坐标到变量 **ball_coor** 并广播一个 **bling** 消息。

  .. image:: img/ball_script_ball5.png

4. 为 **星星** 角色编写脚本
------------------------------------

* 在点击绿色旗帜时隐藏 **星星** 角色。当收到 **bling** 消息时，克隆 **星星** 角色。

  .. image:: img/ball_script_star1.png

* 设置克隆角色的位置和音效，使其与 **球** 角色的位置同步。

  .. image:: img/ball_script_star2.png

* 让 **星星** 角色在 -80 到 80 度之间随机旋转。

  .. image:: img/ball_script_star3.png

* 根据需要调整 **星星** 角色的外观和行为，以增强视觉效果。

  .. image:: img/ball_script_star4.png

编程完成后，点击绿色旗帜运行脚本，查看是否达到了预期效果。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_sensitive_ball.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>