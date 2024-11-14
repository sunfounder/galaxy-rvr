.. note:: 

    你好，欢迎加入 SunFounder 树莓派、Arduino 和 ESP32 爱好者社区！与其他爱好者一起，深入探索树莓派、Arduino 和 ESP32。

    **为什么加入？**

    - **专家支持**：通过社区和团队的帮助解决售后问题和技术挑战。
    - **学习与分享**：交流技巧和教程，提升你的技能。
    - **独家预览**：提前体验新产品发布和独家内容。
    - **专属折扣**：享受最新产品的专属优惠。
    - **节庆促销与赠品**：参与节日促销和赠品活动。

    👉 准备好与我们一起探索和创造了吗？点击 [|link_sf_facebook|] 即刻加入！

.. _sc_parrot:

扩展项目 2：飞翔的鹦鹉
==============================

在这个项目中，我们使用超声波模块来玩飞翔的鹦鹉游戏。

启动脚本后，绿色的竹竿（桨）会以随机高度从右向左移动。控制鹦鹉时，将手放在超声波模块上方。如果手与模块之间的距离小于 10 厘米，鹦鹉会上升；否则，它会下降。你需要仔细控制这个距离，帮助鹦鹉避开绿色竹竿。如果与竹竿发生碰撞，游戏结束。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_flappy_parrot.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

以下是实现该项目的步骤。建议初次按照这些步骤进行设置，熟悉之后，你可以根据需要修改效果。

1. 添加角色
---------------------------

* 删除默认角色，并使用 **选择角色** 按钮添加 **鹦鹉** 角色。将其大小设置为 50%，并将其放置在左下角。

  .. image:: img/parrot_choose_parrot.png

* 添加 **桨** 角色，将其大小设置为 150%，旋转 180 度，并将其放置在右上角。

  .. image:: img/parrot_choose_paddle.png
 
* 转到 **桨** 角色的 **造型** 页面，选择画布上的 **桨**，然后点击 **轮廓** 工具。

  .. image:: img/parrot_set_parrot1.png
    :width: 90%

* 将轮廓效果改为填充模式，并使用删除工具去除轮廓。

  .. image:: img/parrot_set_parrot2.png
    :width: 90%

2. 为 **鹦鹉** 角色编写脚本
---------------------------------------------

编写 **鹦鹉** 角色的脚本，使其能够模拟飞行，根据超声波模块的探测距离调整高度。

* 点击绿色旗帜时，每 0.2 秒切换一次造型，保持飞行的动态效果。

  .. image:: img/parrot_script_parrot1.png

* 如果超声波检测距离小于 10 厘米，将 y 坐标增加 50，使 **鹦鹉** 上升；否则，将 y 坐标减少 40，使 **鹦鹉** 下降。

  .. image:: img/parrot_script_parrot3.png

* 如果 **鹦鹉** 角色与 **桨** 角色发生碰撞，游戏结束，脚本停止执行。

  .. image:: img/parrot_script_parrot4.png

3. 为 **桨** 角色编写脚本
---------------------------------------------

编写 **桨** 角色的脚本，使其能随机出现在舞台上。

* 点击绿色旗帜时，隐藏 **桨** 角色并同时创建一个克隆。 [`create clone of <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_] 块用于控制克隆过程。

  .. image:: img/parrot_script_paddle1.png

* 设置克隆的 x 坐标为 220（最右侧），y 坐标随机在 (-125 到 125) 之间。

  .. image:: img/parrot_script_paddle2.png

* 使用 [repeat] 块逐渐减小其 x 坐标，使克隆角色从右向左慢慢移动，直到消失。

  .. image:: img/parrot_script_paddle3.png

* 重新克隆一个新的 **Paddle** 角色，并删除之前的克隆。

  .. image:: img/parrot_script_paddle4.png

编程完成后，点击绿色旗帜运行脚本，看看是否达到了预期效果。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_flappy_parrot.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>