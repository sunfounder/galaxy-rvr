.. _sh_fishing:

扩展项目 5：钓鱼
===========================

进入我们的互动钓鱼游戏，利用左侧避障模块，体验充满乐趣的钓鱼过程。

当脚本启动后，鱼将在舞台上来回游动。要捕获一条鱼，你必须在鱼快经过钩子时，遮挡左侧的红外避障模块。游戏会自动记录你捕获的鱼的数量。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_fishing.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

按照以下初步步骤设置项目，熟悉后你可以根据需要自定义效果。

1. 添加背景和角色
------------------------------------

首先，选择一个 **水下** 背景，然后添加一个 **鱼** 角色，让它在舞台上游动。

* 使用 **选择背景** 按钮选择 **水下** 背景。

  .. image:: img/fish_choose_backdrop.png

* 删除默认角色，选择 **鱼** 角色。

  .. image:: img/fish_choose_fish.png

* 调整 **鱼** 角色的大小和位置。

  .. image:: img/fish_set_fish.png

2. 绘制 **鱼钩** 角色
-------------------------------------

接下来，创建一个 **鱼钩** 角色，你可以通过左侧红外避障模块控制它来开始钓鱼。

* 通过 **选择角色** 按钮添加 **Glow-J** 角色，并将其重命名为 "Fishhook"。

  .. image:: img/fish_choose_j.png

* 转到 **Glow-J** 角色的 **造型** 页面，将其重命名为 **Fishhook**，选择内部的白色 'J'，并将其颜色改为红色。

  .. image:: img/fish_set_j1.png
    :width: 90%

* 去除外部青色填充，并缩小其宽度，确保钩子的顶部对准中心点。

  .. image:: img/fish_set_j2.png

* 使用 **线条工具** 从中心点向上绘制一条线，延伸至舞台外部。

  .. image:: img/fish_set_j3.png

3. 为 **鱼** 角色编写脚本
---------------------------------------

**鱼** 角色应该在舞台上左右移动，当它与 **鱼钩** 角色发生交互时（钓鱼状态下），它会缩小，移动到指定位置，然后消失，之后会生成一个新的 **鱼** 角色。

* 创建一个变量 **score** 来存储捕获的鱼的数量，隐藏该角色并克隆它。

  .. image:: img/fish_script_fish1.png

* 显示 **鱼** 角色的克隆，切换其造型并设置初始位置。

  .. image:: img/fish_script_fish2.png

* 使 **鱼** 角色的克隆左右移动，并在接触舞台边缘时反弹。

  .. image:: img/fish_script_fish3.png

* 如果 **鱼** 角色的克隆与 **鱼钩** 角色发生碰撞（钓鱼状态下，颜色变为红色）。

  .. image:: img/fish_script_fish4.png
    :width: 90%

* 增加 **score**（捕获鱼的数量）变量值 1，显示一个得分动画（缩小 40%，迅速移动到记分板位置并消失）。同时，创建一个新的鱼（新的 **鱼** 角色克隆）并继续游戏。

  .. image:: img/fish_script_fish5.png

4. 为 **鱼钩** 角色编写脚本
---------------------------------------------

**鱼钩** 角色通常处于水下的黄色状态。当你的手遮挡左侧红外模块时，它会变为钓鱼状态（红色），并移动到舞台上方。

* 点击绿色旗帜时，将角色的颜色效果设置为 30（黄色），并设置其初始位置。

  .. image:: img/fish_script_hook1.png

* 当你的手遮挡左侧红外模块时，将颜色效果设置为 0（红色，进入钓鱼状态），等待 0.1 秒后，将 **鱼钩** 角色移动到舞台顶部。

  .. image:: img/fish_script_hook2.png

* 移开手后，让 **鱼钩** 返回初始位置。

  .. image:: img/fish_script_hook3.png

编程完成后，点击绿色旗帜运行脚本，看看是否达到了预期效果。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_fishing.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>


