第十三课 实时控制
=======================================

我们已经探索了大部分 GalaxyRVR 的功能。
为了完成我们的旅程并将 GalaxyRVR 转变为一台完全功能的机器人，我们需要将之前讲解的三个主要部分结合起来。


    * :ref:`camera_system` ：包括摄像头和 LED 控制功能。

    * :ref:`rgb_move` ：包括移动和灯光效果。

    * :ref:`tilt_system` ：涉及调整摄像头云台的方向。

将这些功能整合在一起后，你可以点击精灵来开启或关闭摄像头和 LED，并使用箭头键来移动 GalaxyRVR。

.. image:: img/13_camera_go_all2.png


**摄像头系统**
------------------------------------


对于这一部分，请重复 :ref:`camera_system` 中的步骤。

1. 创建四个新的精灵来控制摄像头及其 LED。调整它们的大小，使它们看起来协调。

.. image:: img/11_camera_4.png
.. :align: center

2. 为每个精灵编程：点击球体 1 会关闭摄像头。

.. image:: img/11_camera_1sp.png
.. :align: center

3. 点击球体 2 会开启摄像头并设置图像方向。

.. image:: img/11_camera_2sp.png
.. :align: center

4. 点击气球 3 会开启 LED。

.. image:: img/11_camera_3sp.png
.. :align: center

5. 点击气球 4 会关闭 LED。

.. image:: img/11_camera_4sp.png
.. :align: center

6. 为了节省舞台空间，将每组控制块叠放起来。

.. image:: img/11_camera_fold.png
.. :align: center

7. 为每个精灵添加一个“去往后层”块。点击时，精灵将移动到后层，显示下一个精灵，从而创建切换效果。

.. image:: img/11_camera_layer.png
.. :align: center


**移动与 RGB 系统**
----------------------------------


让我们增强移动功能。我们已经在 :ref:`rgb_move` 部分中编写了这些代码。

建议将这些代码块放在背景中。这样修改精灵的代码就不会影响这个功能。

.. image:: img/13.ccc_code_in_stage.png

1. 让 GalaxyRVR 在前进时开启绿色灯光。

.. image:: img/13.ccc_light_forward.png

2. 让 GalaxyRVR 在后退时开启红色灯光。

.. image:: img/13.ccc_light_left_right.png

3. 让 GalaxyRVR 在左转或右转时开启黄色灯光。

.. image:: img/13.ccc_light_backfwd.png

4. 让 GalaxyRVR 在停止移动时开启呼吸灯。

.. image:: img/13.ccc_light_breath.png

最后，您的代码应该如下所示。请注意，这些代码应写在背景中。

.. image:: img/11_camera_backdrops.png





**倾斜系统**
------------------------


这一部分与 :ref:`tilt_system` 相同。只需重复步骤即可。

1. 添加一个箭头精灵。我们将根据箭头精灵的方向来设置云台的方向。

.. image:: img/10_servo_arrow.png

2. 一个 ``当此精灵被点击`` 块正是我们所需要的。

.. image:: img/6_animate_when_touch.png
    :width: 230

3. 让程序重复执行，直到我们松开精灵，即不再触摸它。

.. image:: img/6_animate_repeat_touching.png
    :width: 550

4. 拖动一个 ``指向触摸位置`` 块，让精灵朝向触摸位置。

.. image:: img/10_servo_arrow_point_toward.png

5. 拖动一个 ``将舵机角度设为 90 度`` 块，并嵌入一个 ``方向`` 块，使云台角度与箭头精灵的方向对齐。这样，当我们改变箭头精灵的方向（即触摸舞台区域）时，就能改变云台的角度。

.. image:: img/10_servo_arrow_angle_direction.png

6. 添加限制检查，确保箭头精灵的方向不超过 135 度。

.. image:: img/10_servo_arrow_135.png

7. 同样，确保它的方向不低于 0 度。

.. image:: img/10_servo_arrow_0.png

触摸精灵时，它会随着拖动而改变方向，从而调整云台角度。

如果你发现很容易滑出箭头精灵，可以适当增大精灵的大小。
