.. _ir_ultra_avoid:


第八课 高级避障
==================================================

正如名字所示，避障模块帮助我们的火星车避免障碍物。它通过发射红外信号并接收从物体反射回来的信号来检测障碍物。如果模块前方有障碍物，红外信号会被反射回来，模块就能检测到。

现在，我们加入了超声波传感器来增强这个系统。超声波传感器通过发射特定频率的声波并监听声波的反射来测量距离。通过记录声波发射与反射之间的时间差，我们可以计算出传感器与物体之间的距离。

将这两种传感器结合起来，我们就得到了一个可靠、高效且多功能的避障系统！

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

学习目标
-------------------------

* 将超声波和红外避障模块结合，实现火星车模型的基本避障功能。
* 学习如何编程使火星车模型自动感知并避开障碍物。


所需材料
-----------

* 智能手机或平板电脑
* Mammoth Coding 应用
* GalaxyRVR

构建高级避障系统
-----------------------------------------------------------

在之前的课程中，我们学习了如何使用红外传感器进行避障的基础知识，并了解了超声波模块的工作原理。现在，我们将把这些部分整合起来，构建一个高级避障系统！

我们的增强版火星车将利用超声波和红外传感器来导航并避开周围的障碍物。

1. 我们可以使用 :ref:`ir_obstacle` 中的代码块作为模板，打开你保存的项目。

.. image:: img/7_avoid_open.png

2. 然后，将其保存为副本。

.. image:: img/7_avoid_save_copy.png

3. 重命名项目并保存。

.. image:: img/7_avoid_save_rename.png

4. 使用超声波传感器添加距离检测。拖动一个 ``when distance < 15 cm`` 模块。

.. image:: img/7_avoid_when.png
    :width: 800

5. 同样，拖动一个 ``stop other scripts in sprite`` 模块，以确保 GalaxyRVR 每次只响应一个传感器。

.. image:: img/7_avoid_stop.png

6. 向后移动，直到达到安全距离。

.. image:: img/7_avoid_backward.png

7. 转动一秒钟（可以选择左转或右转）。

.. image:: img/7_avoid_turn.png

8. 再次向前移动。

.. image:: img/7_avoid_go.png

现在，两个侧面的红外传感器和前方的超声波传感器将协同工作，形成一个强大的避障系统，确保 GalaxyRVR 在执行任务时不会与障碍物发生碰撞。
