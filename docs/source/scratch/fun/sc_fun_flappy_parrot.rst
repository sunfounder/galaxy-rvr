.. _sc_parrot:

趣味2 飞翔的鹦鹉
==============================

在这个项目中，我们利用超声波模块来玩飞翔的鹦鹉游戏。

启动脚本后，绿色竹竿（挡板）会以随机高度从右向左移动。要控制鹦鹉，将手放在超声波模块上方。如果你的手与模块之间的距离小于10厘米，鹦鹉将上升；否则，它将下降。你必须小心控制这个距离，帮助鹦鹉穿过绿色竹竿。碰到竹竿则游戏结束。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4" type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>

以下是实现该项目的步骤。建议先按照这些步骤操作，熟悉后可以根据需要改变效果。

1. 添加精灵
---------------------------

* 删除默认精灵，使用 **选择一个精灵** 按钮添加 **Parrot** 精灵。将其大小设置为 50%，并放置在左下角。

  .. image:: img/parrot_choose_parrot.png

* 添加 **Paddle** 精灵，将其大小设置为 150%，旋转到 180 度，并放置在右上角。

  .. image:: img/parrot_choose_paddle.png

* 进入 **Paddle** 精灵的 ** 造型** 页面，选择画布上的 **Paddle** ，然后点击 **轮廓** 工具。

  .. image:: img/parrot_set_parrot1.png
    :width: 90%

* 将轮廓效果改为完全填充模式，并使用移除工具将其消除。

  .. image:: img/parrot_set_parrot2.png
    :width: 90%

2. 为 **鹦鹉** 精灵编写脚本
---------------------------------------------

为 **Parrot** 精灵编写脚本，模拟飞行，高度根据超声波模块的检测距离进行调整。

* 当绿旗被点击时，每 0.2 秒切换一次造型，以保持飞行的外观。

  .. image:: img/parrot_script_parrot1.png

* 如果超声波检测距离小于 10 厘米，将 y 坐标增加 50，使 **Parrot** 上升。否则，将 y 坐标减少 40，使 **Parrot** 下降。

  .. image:: img/parrot_script_parrot3.png

* 如果 **Parrot** 精灵碰到 **Paddle** 精灵，游戏结束，脚本停止执行。

  .. image:: img/parrot_script_parrot4.png

3. 为 **挡板** 精灵编写脚本
-----------------------------------------------

为 **Paddle** 精灵编写脚本，使其随机出现在舞台上。

* 当绿旗被点击时，隐藏 **Paddle** 精灵，同时创建其克隆体。[`创建克隆体 <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_] 积木块控制此克隆过程。

  .. image:: img/parrot_script_paddle1.png

* 设置克隆体的位置，x 坐标为 220（最右侧），y 坐标在 -125 到 125 之间随机。

  .. image:: img/parrot_script_paddle2.png

* 使用 [重复执行] 积木块逐渐减小其 x 坐标，使克隆体从右向左缓慢移动，直到消失。

  .. image:: img/parrot_script_paddle3.png

* 重新克隆一个新的 **Paddle** 精灵并删除前一个克隆体。

  .. image:: img/parrot_script_paddle4.png

编程完成。现在你可以点击绿旗运行脚本，看看是否达到了预期效果。


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4"  type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>
