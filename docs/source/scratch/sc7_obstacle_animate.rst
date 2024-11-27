第七课 红外避障动画
=====================================================

在之前的课程中，我们使用了红外避障模块让 GalaxyRVR 自动避开障碍物，就像执行火星探索任务一样。

在本次活动中，我们将把避障模块与舞台结合，制作一个火星车在火星上躲避岩石的动画。

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_rock.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>



学习目标
-------------------------

* 更深入地了解红外避障模块及其在火星车中的应用。
* 学会如何在 Scratch 中读取和应用红外避障模块的数据。
* 使用红外模块和 Scratch 舞台，创建一个火星探索主题的避障游戏。


所需材料
-----------

* 智能手机或平板电脑
* Mammoth Coding 应用
* GalaxyRVR


创建动画
--------------------------------------

1. 首先，我们需要一个火星主题的背景。点击选择一个背景。

.. image:: img/5_animate_choose.png

2. 选择火星背景。

.. image:: img/5_animate_mars.png

3. 从资源库中选择 GalaxyRVR 精灵并调整其大小。

.. image:: img/5_animate_rvr.png

4. 从资源库中选择一个岩石精灵并调整其大小。

.. image:: img/5_animate_rock.png

5. 接下来，我们来编程这两个精灵：



**GalaxyRVR 精灵**

GalaxyRVR 精灵的任务是从屏幕的左侧缓慢移动到右侧。如果它碰到岩石精灵，它将停止移动。
在这个过程中，我们可以用手触发实际火星车上的两个红外传感器。触发右侧传感器会让精灵向下移动一点；触发左侧传感器会让精灵向上移动一点。



a. 当点击绿色旗帜时，精灵应出现在屏幕的最左侧。你可以先将精灵移到舞台上的相应位置，动作类中的坐标值会随之改变。

.. image:: img/5_animate_glide.png

b. 放置一个 forever 模块作为主循环。

.. image:: img/5_animate_forever.png

c. 拖入一个条件判断模块，检查是否触碰到岩石精灵。

.. image:: img/5_animate_touching.png

d. 如果没有触碰到，它继续向前移动。

.. image:: img/5_animate_moving.png

e. 如果触碰到岩石，它停止并发出喊叫声。

.. image:: img/5_animate_say.png

f. 最后，添加两个事件。当左侧或右侧红外传感器检测到障碍物（你的手）时，精灵向上或向下移动。

.. image:: img/5_animate_y.png


**岩石精灵**

岩石精灵的任务相对简单。它可以保持在原地，随机出现在不同位置，或者通过克隆多个岩石来增加 GalaxyRVR 精灵的难度。

a. 创建岩石精灵的克隆。

.. image:: img/5_animate_clone.png

b. 然后将克隆移动到一个随机位置。将这两个模块组合并点击，你会看到新的岩石在舞台上随机出现。

.. image:: img/5_animate_clone_move.png

c. 生成十个随机位置的岩石。

.. image:: img/5_animate_clone_10.png

d. 这些动作发生在点击绿色旗帜时。

.. image:: img/5_animate_clone_flag.png    
   :width: 200

现在，这个小游戏完成了。

将 GalaxyRVR 连接到 APP（参见 :ref:`app_connet`），点击绿色旗帜开始游戏。

你会看到许多岩石随机生成在舞台上。你的任务是用手触发两个红外传感器，指导 GalaxyRVR 成功到达舞台的右侧。
