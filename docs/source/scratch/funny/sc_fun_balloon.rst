.. _sc_balloon:

扩展项目 1：给气球充气
=========================================

在这个互动项目中，我们将控制气球的飞行。

点击绿色旗帜后，气球将逐渐充气。如果气球充得太大，它会爆炸；如果充得太小，它会下落。你的任务是在适当的时刻遮挡左侧的红外模块，使气球上升。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_balloon.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

下面是实现这个项目的步骤。建议初次操作时按照这些步骤进行，熟悉后你可以根据需要调整效果。

1. 添加角色和背景
----------------------------------------

* 删除默认角色，点击角色区右下角的 **选择角色** 按钮，然后选择 **Balloon1** 角色。

  .. image:: img/balloon_choose_sprite.jpg

* 通过 **选择背景** 按钮添加一个 **Boardwalk** 背景，或者选择其他你喜欢的背景。

  .. image:: img/balloon_choose_backdrop.jpg

2. 为 **Balloon1** 角色绘制服装
-------------------------------------------------------

接下来，我们为气球绘制一个爆炸效果的服装。

* 在 **Balloon1** 角色的 **服装** 标签中，点击左下角的 **选择服装** 按钮，选择 **绘制**，打开一个空白的 **服装**，并命名为 "boom"。

  .. image:: img/balloon_set_ball1.jpg

* 选择一种颜色，使用 **画笔** 工具绘制一个图案。

  .. image:: img/balloon_set_ball2（2）.png
    :width: 90%

* 选择另一种颜色，使用 **填充** 工具点击图案内部进行填充。

  .. image:: img/balloon_set_ball3（2）.png
    :width: 90%

* 最后，添加 "BOOM" 文字，完成爆炸效果的服装。

  .. image:: img/balloon_set_ball4.jpg
    :width: 90%

3. 为 **Balloon1** 角色编写脚本
------------------------------------------

* 初始化 **Balloon1** 角色的位置和大小。

  .. image:: img/balloon_script1(1).png

* 逐渐增大 **Balloon1** 角色的大小。

  .. image:: img/balloon_script2(2).png

* 此时，遮挡左侧的障碍物避让模块，停止 **Balloon1** 角色继续膨胀。

  .. image:: img/balloon_script3.png

* 让 **Balloon1** 角色根据其大小决定是上升还是下降。

  * 如果大小小于 90，它将下落（y 坐标减小）。
  * 如果大小在 90 和 120 之间，它将上升（y 坐标增大）。

  .. image:: img/balloon_script4.png

* 如果你没有及时遮挡左侧的障碍物避让模块，气球将继续膨胀，直到超过 120 大小，届时气球将爆炸（切换到爆炸效果服装）。

  .. image:: img/balloon_script5.png

编程完成后，你可以点击绿色旗帜运行脚本，看看是否达到了预期效果。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_balloon.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>