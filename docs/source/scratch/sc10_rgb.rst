
第10课：用 RGB LED 灯带点亮道路
===============================================================

我们的火星车已经成为一名熟练的探险家，但现在是时候增添一些多彩的个性了！在本课中，我们将用 RGB LED 灯带改造我们的火星车，让它能发出你能想象到的任何颜色的光。

想象一下你的 GalaxyRVR 像科幻电影中的宇宙飞船一样照亮前路：

- 前进时发出绿色光芒
- 停止时发出红色光芒
- 转向时发出黄色闪烁
- 还有仅仅为了有趣的绚丽色彩展示！

我们将学习如何编程这些神奇的灯光，并将它们与火星车的移动同步。准备好创建你自己的发光火星探险家吧！

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/car_rgb.mp4" type="video/mp4">
        您的浏览器不支持此视频标签。
    </video>

学习目标
-------------------

* 了解 RGB LED 灯带的工作原理以及如何编程控制它们
* 学习使用 Mammoth Coding 控制颜色并创建灯光效果
* 为你的火星探索任务设计灯光信号和颜色

探索 RGB LED 灯带的光之魔法
-------------------------------------------------------------

你是否曾经想创造自己的彩虹？现在你可以了！有了 RGB LED 灯带，你可以让你的火星车发出你能想象到的任何颜色的光。让我们来发现彩色灯光的神奇之处！

.. image:: img/4_rgb_strip.jpg

认识 LED 灯带上的四个重要引脚：

* **+5V** - 为所有灯提供能量的电源引脚（需要5V电源）
* **B** - 控制蓝色灯
* **R** - 控制红色灯
* **G** - 控制绿色灯

.. image:: img/rgb_5050.jpg

还记得在美术课上学到的三原色吗？就像混合颜料一样，每个 LED 都可以混合红色、蓝色和绿色光，创造出神奇的颜色！每个"5050"LED 就像一个小型颜色工厂，包含全部三种颜色。

.. image:: img/rgb_5050_sche.png

所有这些颜色工厂都连接在一条柔性电路上——就像一条彩色的电气高速公路！电源引脚连接在一起，而颜色引脚各有自己的专用路径。

.. image:: img/rgb_strip_sche.png

最令人兴奋的部分？你可以编程让所有 LED 同时变色！想象一下只用几个积木块就能创建你自己的灯光秀。准备好点亮你的火星车冒险之旅吧！

点亮表演
------------------------------

#. 首先，请执行 :ref:`app_connect` 的步骤。

#. 现在，让你的 GalaxyRVR 发光！拖出一个"显示颜色"积木块开始。

   .. image:: img/9_rgb_block.png

#. 从颜色菜单中选择你喜欢的任意颜色。

   .. image:: img/9_rgb_color.png

#. 点击积木块，观看你的 GalaxyRVR 用你选择的颜色亮起来！

**创建一个颜色控制器**

现在让我们构建一个交互式颜色控制器！我们将在舞台上创建彩色按钮，点击它们即可改变 GalaxyRVR 的灯光。

1. 首先，删除所有现有精灵，重新开始。

   .. image:: img/6_animate_delete.png

2. 从库中添加一个球精灵。这个精灵很合适，因为它自带多种颜色造型。

   .. image:: img/9_animate_rgb_ball.png

3. 添加一个"当此精灵被点击"积木块——点击球时就会触发动作。

   .. image:: img/9_animate_rgb_when.png

4. 连接一个"显示颜色"积木块，点亮你的 GalaxyRVR。

   .. image:: img/9_animate_rgb_display.png

5. 在小屏设备上，点击眼睛按钮确保你能看到舞台。

   .. image:: img/9_animate_rgb_eye.png

6. 点击显示积木块中的色块，然后点击底部的取色器按钮。

   .. image:: img/9_animate_rgb_pick.png

7. 长按舞台区域——会出现一个放大镜！将它移到球精灵上方松开，以复制其颜色。

   .. image:: img/9_animate_rgb_pick_color_n.png

8. 长按球精灵并选择复制，制作更多颜色按钮。

   .. image:: img/9_animate_rgb_duplicate.png

9. 通过切换每个副本的造型，将其改为不同的颜色。

   .. image:: img/9_animate_rgb_change_costume.png

10. 对于每种新颜色，使用取色器使显示积木块与精灵的当前颜色匹配。

   .. image:: img/9_animate_rgb_pick_blue.png

11. 重复上述步骤，直到你拥有五个不同颜色的按钮！

   .. image:: img/9_animate_rgb_ball5.png

现在点击舞台上任意颜色的球，观看你的 GalaxyRVR 发出该颜色的光！轻轻一点，创建你自己的灯光秀。

.. _rgb_move:

GalaxyRVR 信号灯实战
----------------------------------------------------------------

**方向指示灯**

让我们将灯光颜色与移动结合起来，为你的 GalaxyRVR 创建信号灯！就像汽车有转向灯一样，你的火星车在移动时会以不同颜色亮起。

#. 首先，请执行 :ref:`app_connect` 的步骤。

#. 现在，为所有四个方向设置方向键和移动积木块。

   .. image:: img/9_rgb_move.png

#. 为每个方向添加颜色显示：

   - 前进时亮绿灯

   .. image:: img/9_rgb_green.png

   - 左转和右转时亮黄灯

   .. image:: img/9_rgb_yellow.png

   - 后退时亮红灯

   .. image:: img/9_rgb_red.png

现在，当你按下方向键时，你的 GalaxyRVR 将一边移动一边发出匹配颜色的光芒！

**呼吸灯效果**

让我们创建一个酷炫的呼吸灯效果，让火星车在静止时缓慢变亮和变暗，就像它在呼吸一样！

1. 创建一个名为"停止"的新广播消息，用于指示火星车不在移动时。

   .. image:: img/9_rgb_new_message.png

   .. note:: 广播消息有助于组织代码，通过在恰当的时机触发特定操作，使程序更清晰、更易懂。

2. 在每个移动命令后添加此广播。

   .. image:: img/9_rgb_new_boardcast.png

3. 创建一个"当收到[停止]"积木块来启动呼吸灯。

   .. image:: img/9_rgb_when_receive.png

4. 将亮度设置为0%，从完全熄灭开始。

   .. image:: img/9_rgb_set_bright.png

5. 使用重复循环，每0.2秒将蓝色灯光亮度增加10%。

   .. image:: img/9_rgb_increase.png

6. 然后逐渐降低亮度，完成一个呼吸周期。

   .. image:: img/9_rgb_decrease.png

7. 再次广播"停止"，使呼吸效果持续进行。

   .. image:: img/9_rgb_stopagain.png

8. 在每个按键事件结束时添加"停止其他脚本"，防止颜色冲突。

   .. image:: img/9_rgb_stop.png

9. 在每个方向键事件中重置灯光亮度。

   .. image:: img/9_rgb_set_bright_each.png

现在，你的 GalaxyRVR 在移动时会发出彩色信号灯，在静止时会发出柔和的蓝色呼吸灯光！

RGB 模块相关积木块
-------------------------------


* 用你选择的任何颜色点亮你的 GalaxyRVR。

  - 点击色块选择你喜欢的颜色

  .. image:: img/block/rgb_display.png


* 在指定时间内点亮你的 GalaxyRVR。

  - 选择任意颜色
  - 设置灯光保持的时间

  .. image:: img/block/rgb_display_1s.png

* 通过混合红、绿、蓝光创建自定义颜色——非常适合颜色渐变项目！

  - R：红色亮度（0-255）
  - G：绿色亮度（0-255）
  - B：蓝色亮度（0-255）

  .. image:: img/block/rgb_display_RGB.png

* 在设定时间内显示自定义 RGB 颜色。

  - 调整红、绿、蓝值（0-255）
  - 设置显示时长

  .. image:: img/block/rgb_display_RGB_1s.png

* 设置灯光的亮度（0-100%）。

  .. image:: img/block/rgb_set_brightness.png

* 使灯光变亮或变暗。使用负数来降低亮度。

  .. image:: img/block/rgb_increase_brightness.png


* 打开或关闭 RGB 灯光。

  .. image:: img/block/rgb_turn_on.png
