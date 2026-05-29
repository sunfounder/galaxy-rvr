.. _sh_fishing:

趣味5 钓鱼
===========================

深入我们的互动钓鱼游戏，利用左侧避障模块获得沉浸式体验。

脚本运行时，鱼儿会在舞台上左右游动。要钓到鱼，你必须在鱼儿即将经过鱼钩时遮挡左侧避障模块。游戏会自动记录你钓到的鱼的数量。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_fishing.mp4"  type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>

按照以下初始步骤设置项目，熟悉设置后可以自由自定义效果。

1. 添加背景和精灵
------------------------------------

首先，选择一个 **Underwater** 背景，然后添加一个 **Fish** 精灵，让它游过舞台。

* 使用 **选择一个背景** 按钮选择 **Underwater** 背景。

  .. image:: img/fish_choose_backdrop.png

* 删除原始精灵，然后选择 **Fish** 精灵。

  .. image:: img/fish_choose_fish.png

* 调整 **Fish** 精灵的大小和位置。

  .. image:: img/fish_set_fish.png

2. 绘制一个 **鱼钩** 精灵
-------------------------------------

接下来，创建一个 **鱼钩** 精灵，你将通过左侧避障模块控制它开始钓鱼。

* 通过 **选择一个精灵** 添加 **Glow-J** 精灵，并将其重命名为 "Fishhook"。

  .. image:: img/fish_choose_j.png

* 进入 **Glow-J** 精灵的 ** 造型** 页面，将其重命名为 **Fishhook** ，选择内部白色的 'J'，并将其颜色改为红色。

  .. image:: img/fish_set_j1.png
    :width: 90%

* 移除外部青色填充并减小其宽度。确保鱼钩的顶部与中心点对齐。

  .. image:: img/fish_set_j2.png

* 使用 **线段工具** 从中心点向上画一条线，延伸出舞台。

  .. image:: img/fish_set_j3.png

3. 为 **鱼** 精灵编写脚本
---------------------------------------

**Fish** 精灵应在舞台上左右移动，当它在钓鱼状态下与 ** 鱼钩** 精灵互动时，应缩小、移动到特定位置、消失，然后生成一个新的 **Fish** 精灵。

* 创建一个变量 **score** 来存储钓到的鱼的数量，隐藏此精灵并克隆它。

  .. image:: img/fish_script_fish1.png

* 显示 **Fish** 精灵的克隆体，切换其造型，并设置初始位置。

  .. image:: img/fish_script_fish2.png

* 使 **Fish** 精灵的克隆体能够在舞台上左右移动，并在碰到舞台边缘时反弹。

  .. image:: img/fish_script_fish3.png

* 如果 **Fish** 精灵的克隆体在钓鱼状态下（当鱼钩变为红色时）碰到 ** 鱼钩** 精灵。

  .. image:: img/fish_script_fish4.png
    :width: 90%

* 将分数（变量 score）增加 1，显示得分动画（缩小 40%，快速移动到记分板位置并消失）。同时，生成一条新鱼（一个新的 **Fish** 精灵克隆体）并继续游戏。

  .. image:: img/fish_script_fish5.png

4. 为 **鱼钩** 精灵编写脚本
---------------------------------------------

**鱼钩** 精灵通常以黄色状态停留水下。当你的手遮挡左侧红外模块时，它会变为钓鱼状态（红色）并移动到舞台上方。

* 当绿旗被点击时，将精灵的颜色特效设置为 30（黄色），并设置其初始位置。

  .. image:: img/fish_script_hook1.png

* 当你的手遮挡左侧红外模块时，将颜色特效设置为 0（红色，进入钓鱼状态），等待 0.1 秒，然后将 **鱼钩** 精灵移动到舞台顶部。

  .. image:: img/fish_script_hook2.png

* 移开手后，让 **鱼钩** 返回其初始位置。

  .. image:: img/fish_script_hook3.png

编程完成后，点击绿旗运行脚本，看看是否达到了预期效果。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_fishing.mp4"  type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>


