.. _sc_tap_tile:

趣味7 点黑砖
==========================================

许多人都熟悉那款流行的手机游戏，点击黑色方块得分，同时避开白色方块。我们将使用两个避障模块来重现这个令人上瘾的挑战。当你的手遮挡住其中一个红外模块时，就会在舞台上触发一次点击。

如果点击落在黑色方块上，你得一分；点击白色方块则扣一分。玩家必须根据黑色方块的位置迅速决定遮挡左侧还是右侧的红外模块。

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../../_static/video/sc_tap_black_tile.mp4"  type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>

以下是实现该项目的步骤。建议先按照这些步骤操作，熟悉后可以根据需要修改效果。

1. 绘制 **方块** 精灵
-----------------------------------

使用 **Tile** 精灵来实现黑白方块向下滚动的效果；在手机版本中，通常有 4 列，这里我们只做两列。


* 删除默认精灵，点击 **添加精灵** 图标，选择 **绘制**。

  .. image:: img/tile_paint_tile1.png

* 接下来，进入 **造型** 页面，使用 ** 矩形** 工具绘制一个灰色边框、白色填充的矩形。

  .. image:: img/tile_paint_tile2.png
    :width: 90%

* 选中矩形，点击 **复制** -> ** 粘贴** 制作一个完全相同的矩形，然后将两个矩形移动到平齐的位置。

  .. image:: img/tile_paint_tile3.png
    :width: 90%

* 选中其中一个矩形，选择黑色填充颜色。

  .. image:: img/tile_paint_tile4.png
    :width: 90%

* 现在选中两个矩形并移动它们，使其中心点与画布中心对齐。

  .. image:: img/tile_paint_tile5.png
    :width: 90%

* 复制造型1，交替改变两个矩形的填充颜色。例如，造型1的填充颜色是左白右黑，造型2的填充颜色是左黑右白。

  .. image:: img/tile_paint_tile6.png
    :width: 90%

* 返回 **代码** 页面，将精灵名称设置为 **Tile** 。

  .. image:: img/tile_paint_tile7.png

2. 为 **方块** 精灵编写脚本
-------------------------------------

* 首先，设置 **Tile** 精灵的初始位置，使其位于舞台顶部。

  .. image:: img/tile_script_tile1.png

* 创建一个变量 **blocks** 并赋予其初始值，以确定 **Tile** 精灵出现的次数。使用 [重复执行直到] 积木块使变量 **blocks** 逐渐减少，直到 **blocks** 为 0。在此期间，让精灵 **Tile** 随机切换造型。点击绿旗后，你将看到舞台上的 **Tile** 精灵快速切换造型。

  .. image:: img/tile_script_tile2.png

* 在变量 **blocks** 减少的同时创建 **Tile** 精灵的克隆体，当 blocks 为 0 时停止脚本运行。这里使用了两个 [等待 () 秒] 积木块，第一个用于限制 **Tile** 克隆体之间的间隔，第二个是让变量 blocks 减少到 0 时不会立即停止程序，给最后一个方块精灵足够的时间移动。

  .. image:: img/tile_script_tile3.png

* 现在为 **Tile** 精灵的克隆体编写脚本，使其缓慢向下移动，并在到达舞台底部时删除。y 坐标的变化影响下落速度，数值越大，下落速度越快。

  .. image:: img/tile_script_tile4.png

* 隐藏本体，显示克隆体。

  .. image:: img/tile_script_tile5.png

3. 为背景编写脚本
-------------------------------

在背景中，读取 2 个红外模块的值并执行相应的动作。

* 当绿旗被点击时，将变量 **count** 设置为 0。

  .. image:: img/tile_script_backdrop.png
    :width: 90%

* 如果左侧红外避障模块感应到你的手，广播一条消息 - **left** 。

  .. image:: img/tile_script_backdrop1.png


* 如果右侧红外避障模块感应到你的手，广播一条消息 - **right** 。

  .. image:: img/tile_script_backdrop2.png


4. 绘制 **左侧红外** 精灵
-----------------------------
使用 **Left IR** 精灵来实现点击效果；当左侧红外模块感应到你的手时，会向 **Left IR** 精灵发送一条消息 - **left** ，让它开始工作。如果它碰到舞台上的黑色方块，分数加 1，否则分数减 1。


* 同样，点击 **添加精灵** 图标，选择 **绘制**。

  .. image:: img/tile_paint_ir1.png

* 进入 **造型** 页面，选择填充颜色（黑色和白色以外的任何颜色）并画一个圆。

  .. image:: img/tile_paint_ir2.png

* 返回 **代码** 页面，将精灵名称改为 **Left IR** 。

  .. image:: img/tile_paint_ir3.png

5. 为 **左侧红外** 精灵编写脚本
------------------------------------------

* 现在开始为 **Left IR** 精灵编写脚本。当绿旗被点击时，首先隐藏精灵。

  .. image:: img/tile_script_ir1.png

* 当收到消息 - **left** （左侧红外接收模块检测到障碍物）时，显示精灵，将其大小设置为 100%，然后使用 [重复执行] 积木块以 10 为间隔逐渐缩小，然后再次隐藏。这使精灵产生一种扩张和收缩的效果。

  .. image:: img/tile_script_ir2.png

* 然后判断是否碰到 **Tile** 精灵的黑色方块，如果碰到，让变量 **count** 增加 1，否则减少 1。

  .. image:: img/tile_script_ir3.png

.. note::

    你需要让 **Tile** 精灵出现在舞台上，然后吸取 **Tile** 精灵中黑色方块的颜色。

    .. image:: img/tile_script_ir4.png

6. **右侧红外** 精灵
-------------------------------------
**Right IR** 精灵的功能与 **Left IR** 基本相同，只是它接收 **Right** 消息。


* 现在复制 **Left IR** 精灵，将精灵名称改为 **Right IR** 。

  .. image:: img/tile_paint_ir4.png

* 然后将接收的消息改为 - **right** 。

    .. image:: img/tile_script_ir5.png

7. 运行脚本
---------------------------------

* 现在调整三个精灵的位置和大小。

  * 将 **Tile** 精灵拖到舞台底部，将其 x 位置设置为 0。
  * 将 **Left IR** 精灵移入左侧框架。你需要进入 ** 造型** 页面将精灵大小缩小至框架大小的 50%。
  * 同样，将 **Right IR** 精灵移入右侧框架。你需要进入 ** 造型** 页面将精灵大小缩小至框架大小的 50%。
  * 确保 **Left IR** 和 **Right IR** 精灵位于 **Tile** 精灵之上。

  .. image:: img/tile_paint_ir5.png

* 现在所有脚本已编写完成，你可以点击绿旗运行脚本。

  .. raw:: html

    <video loop autoplay muted style = "max-width:70%">
        <source src="../../_static/video/sc_tap_black_tile.mp4"  type="video/mp4">
        您的浏览器不支持此视频标签。
    </video>
