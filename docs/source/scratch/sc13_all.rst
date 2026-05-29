第13课：完整的火星车控制
=======================================

你已经掌握了所有组件——现在让我们把它们整合起来！结合你所学的一切，创建功能完整的火星车，包括实时摄像头画面、移动控制和摄像头俯仰。

将三个令人惊叹的系统结合在一起：

- :ref:`camera_system`：通过实时视频透过火星车的眼睛看世界
- :ref:`rgb_move`：用彩色信号灯驾驶
- :ref:`tilt_system`：通过摄像头控制上下观察

结果如何？完全控制你的 GalaxyRVR！点击按钮控制摄像头，使用方向键驾驶。

.. image:: img/13_camera_go_all2.png


摄像头系统
----------------------------------

重复上一课中的摄像头设置步骤：:ref:`camera_system`。

1. 创建四个控制精灵并整齐排列。

   .. image:: img/11_camera_4.png

2. 编程每个按钮的功能：

   - 球1：关闭摄像头

   .. image:: img/11_camera_1sp.png

   - 球2：打开摄像头并设置正确方向

   .. image:: img/11_camera_2sp.png

   - 气球1：打开LED灯

   .. image:: img/11_camera_3sp.png

   - 气球2：关闭LED灯

   .. image:: img/11_camera_4sp.png

3. 堆叠控件以节省空间——需要时会展开！

   .. image:: img/11_camera_fold.png

4. 添加 ``移到最底层`` 积木块，在按钮之间创建酷炫的切换效果。

   .. image:: img/11_camera_layer.png

移动与灯光系统
----------------------------------

让我们为火星车的移动添加彩色灯光！我们已经在 :ref:`rgb_move` 部分中编写了这些代码。

我们建议将此代码放在背景部分——这样可以与精灵代码分开，使一切更有条理。

   .. image:: img/13.ccc_code_in_stage.png

1. 让火星车前进时发出绿色光芒。

   .. image:: img/13.ccc_light_forward.png

2. 让火星车后退时发出红色光芒。

   .. image:: img/13.ccc_light_backfwd.png

3. 让火星车左转或右转时发出黄色光芒。

   .. image:: img/13.ccc_light_left_right.png

4. 火星车停止时创建蓝色呼吸灯效果。

   .. image:: img/13.ccc_light_breath.png

完整的背景代码应如下所示：

   .. image:: img/11_camera_backdrops.png

摄像头俯仰控制
------------------------

让我们添加摄像头控制！这部分与 :ref:`tilt_system` 相同，只需重复步骤即可。

1. 添加一个 **箭头** 精灵来控制摄像头的俯仰。

   .. image:: img/10_servo_arrow.png

2. 以 ``当此精灵被点击`` 积木块开始。

   .. image:: img/6_animate_when_touch.png
       :width: 200

3. 创建一个在你触摸箭头时持续运行的循环。

   .. image:: img/6_animate_repeat_touching.png
       :width: 400

4. 让箭头在你拖动时指向手指方向。

   .. image:: img/10_servo_arrow_point_toward.png
       :width: 400

5. 将箭头方向与摄像头角度连接起来——旋转箭头来移动摄像头！

   .. image:: img/10_servo_arrow_angle_direction.png
       :width: 800

6. 设置限制，将摄像头角度保持在0-135度之间。

   .. image:: img/10_servo_arrow_135.png
       :width: 400

   .. image:: img/10_servo_arrow_0.png
       :width: 400

触摸并拖动箭头来瞄准火星车的摄像头！如果箭头难以控制，可以将其放大。

完全控制你的 GalaxyRVR
------------------------------------

现在你已经完全掌握了你的火星车！以下是操作你的完整 GalaxyRVR 的方法：

.. image:: img/13_camera_go_all2.png

**控制你的火星车：**

- 使用方向键前进、后退和转向
- 点击球精灵打开和关闭实时摄像头画面
- 点击气球精灵控制摄像头LED灯的开关
- 拖动箭头精灵上下倾斜摄像头

**一起测试所有功能：**

- 一边驾驶一边观看火星车的实时摄像头画面
- 注意每种移动对应的彩色灯光信号
- 练习倾斜摄像头，从不同角度观察物体
- 尝试在明亮和黑暗条件下使用LED灯进行探索

恭喜！你已成功将所有系统整合在一起，创建了一个功能完整的火星车。你已经学会了编程移动、灯光、摄像头控制和俯仰机制——操作真正的探测机器人所需的所有技能。

你的火星任务现在可以开始了。祝你探索愉快！
