.. _sc_balloon:

趣味1 吹气球
=========================================

在这个互动项目中，我们控制气球的飞行。

点击绿旗后，气球会逐渐膨胀。如果气球变得太大，它就会爆炸；如果太小，它就会下落。你的任务是在适当的时机遮挡左侧红外模块，让气球上升。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_balloon.mp4" type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>

以下是实现该项目的步骤。建议先按照这些步骤操作，熟悉后可以根据需要改变效果。

1. 添加精灵和背景
----------------------------------------

* 删除默认精灵，点击精灵区域右下角的 **选择一个精灵** 按钮，然后选择 **Balloon1** 精灵。

  .. image:: img/balloon_choose_sprite.png

* 通过 **选择背景** 按钮添加一个 **Boardwalk** 背景或你选择的其他背景。

  .. image:: img/balloon_choose_backdrop.png

2. 为 **Balloon1** 精灵绘制造型
-------------------------------------------------------

现在，让我们为气球创建一个爆炸效果的造型。

* 进入 **Balloon1** 精灵的 **造型** 选项卡，点击左下角的 **选择一个造型** 按钮，选择 **绘制** 打开一个空白 **造型**，将其命名为 "boom"。

  .. image:: img/balloon_set_ball1.png

* 选择一种颜色，使用 **画笔** 工具绘制图案。

  .. image:: img/balloon_set_ball2.png
    :width: 90%

* 选择另一种颜色，点击 **填充** 工具，然后在图案内部点击进行填充。

  .. image:: img/balloon_set_ball3.png
    :width: 90%

* 最后，添加文字 "BOOM" 完成爆炸效果造型。

  .. image:: img/balloon_set_ball4.png
    :width: 90%

3. 为 **气球** 精灵编写脚本
------------------------------------------

* 初始化 **Balloon1** 精灵的位置和大小。

  .. image:: img/balloon_script1.png

* 逐渐增加 **气球** 精灵的大小。

  .. image:: img/balloon_script2.png

* 此时，遮挡左侧避障模块，使 **Balloon1** 精灵停止继续膨胀。

  .. image:: img/balloon_script3.png

* 现在，让 **Balloon1** 精灵根据其大小决定上升还是下降。

  * 如果大小小于90，它将下降（y坐标减小）。
  * 如果大小在90到120之间，它将上升（y坐标增加）。

  .. image:: img/balloon_script4.png

* 如果你未能遮挡左侧避障模块，气球将继续膨胀，直到超过120的大小，此时它将爆炸（切换到爆炸效果造型）。

  .. image:: img/balloon_script5.png

编程完成。现在你可以点击绿旗运行脚本，看看是否达到了预期效果。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_balloon.mp4" type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>
