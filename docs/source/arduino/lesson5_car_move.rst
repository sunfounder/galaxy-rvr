第5课：释放火星车的移动能力
======================================================

准备好，年轻的探索者们！我们已经掌握了控制电机的技能，现在要把这些技能带到红色星球上。在本课中，我们将让火星车活起来！

我们将学习如何将电机组装到摇臂转向架悬挂系统中，然后利用我们的编程技能，引导我们的火星车穿越想象中的火星地貌。

这是我们教室里的火星冒险。让我们开始吧！

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>

.. note::

    如果你是在完全组装好GalaxyRVR之后学习本课程，你需要在上传代码之前将此开关拨到右侧。

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

学习目标
---------------------------

* 理解如何将电机组装到火星车的摇臂转向架悬挂系统中。
* 学习使用Arduino控制火星车的运动。
* 练习编写程序控制火星车在不同地形上的运动。

所需材料
--------------------------
* SunFounder R3板
* TT电机
* GalaxyRVR扩展板
* 电池
* 火星车模型（配备摇臂转向架系统）
* 基本工具和配件（例如螺丝刀、螺丝等）
* USB数据线
* Arduino IDE
* 计算机

步骤
--------------

**步骤1：组装火星车组件**

在这一步中，我们将把电池、R3板、GalaxyRVR扩展板、电机和轮子组装到预装好的摇臂转向架系统上。这将使GalaxyRVR达到可运行状态。

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/lu8K26MY96s" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

恭喜！我们成功建造了我们自己的火星车，它已经准备好开始探索了。让我们动起来吧！

**步骤2：让火星车动起来**

现在是时候为我们的创造注入生命，并送它开始首次航行。
但我们如何与我们的火星车通信？我们如何告诉它去哪里以及做什么？
这就是我们的编程技能发挥作用的地方！

在现实世界中，如果我们想让汽车向前行驶，我们会踩下油门，两个轮子开始旋转。
右侧的轮子顺时针旋转，而左侧的轮子逆时针旋转。

.. image:: img/move_car.gif
    :align: center

想象你坐在驾驶座上，世界在你身边飞驰而过——这正是我们要给我们的火星车的体验。

现在，让我们将这个体验翻译成我们的火星车能理解的语言——代码！

    .. code-block:: arduino

        #include <SoftPWM.h>

        // Define the pins of motors
        const int in1 = 2;
        const int in2 = 3;
        const int in3 = 4;
        const int in4 = 5;

        void setup() {
            // Initialize SoftPWM
            SoftPWMBegin();
        }

        void loop() {
            // Set the left motors rotate counterclockwise
            SoftPWMSet(in1, 255);  // Full speed
            SoftPWMSet(in2, 0);    // Stop

            // Set the right motors rotate clockwise
            SoftPWMSet(in3, 0);    // Stop
            SoftPWMSet(in4, 255);  // Full speed

        }

在这段代码中，我们在对火星车说话，精确地告诉它该做什么。
通过 ``SoftPWMSet()`` 函数，我们就像汽车的油门和刹车一样，
控制着每个电机的速度和方向。
我们告诉左边的电机逆时针旋转，右边的电机顺时针旋转，就这样，我们的火星车向前移动！

当然，一旦理解了如何让火星车向前移动，后退的概念就很简单了。
要让火星车向后移动，我们只需反转每个电机的旋转方向。

在代码中，我们这样做完全相反的操作。右侧轮子现在应该逆时针旋转，左侧轮子应该顺时针旋转。

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Define the pins of motors
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set the left motors to rotate clockwise
        SoftPWMSet(in1, 0);    // Stop
        SoftPWMSet(in2, 255);  // Full speed

        // Set the right motors to rotate counterclockwise
        SoftPWMSet(in3, 255);  // Full speed
        SoftPWMSet(in4, 0);    // Stop

    }

在这段代码中，我们使用 ``SoftPWMSet()`` 告诉左边的电机顺时针旋转，右边的电机逆时针旋转。

仅仅通过代码就能控制我们的火星车旅程，是不是很迷人？下次你在汽车里时，花点时间想想你的火星车的旅程，一次旋转一个轮子地探索世界。请继续关注，因为我们的火星车之旅才刚刚开始！

**步骤3：让火星车向其他方向移动**

既然我们知道如何让火星车向前和向后移动，如果我们想让它向左或向右转弯呢？

就像现实生活中的驾驶一样，汽车向左转弯主要有两种方式。

* 第一种方式是让左侧的轮子比右侧的轮子旋转得慢。这种速度差会使火星车向左转弯。
* 第二种方式是让左右电机都朝同一方向旋转（本例中为顺时针），这将使火星车绕其轴心向左旋转。

让我们看看如何在代码中实现这两种方式：

**方法1：两侧速度不同**

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // Define the pins of motors
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set the left motors rotate counterclockwise in low speed
        SoftPWMSet(in1, 40);
        SoftPWMSet(in2, 0);

        // Set the right motors rotate clockwise in higher speed
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 200);

        delay(2000);  // Last for 2 seconds
    }

在这段代码中，我们降低了左侧电机的速度，同时保持右侧电机以较高速度运转。这将使火星车向左转弯。

**方法2：所有电机朝同一方向旋转**

.. code-block:: arduino
    :emphasize-lines: 16,17,18,19

    #include <SoftPWM.h>

    // Define the motor pins
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // Initialize SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // Set all motors to rotate clockwise
        SoftPWMSet(in1, 0);
        SoftPWMSet(in2, 255);
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 255);
    }

在这段代码中，我们设置所有电机顺时针旋转。火星车将绕其自身轴心旋转，方向将向左改变。

要让火星车向右转弯，概念相同但方向相反。你能想出如何实现吗？

**步骤4：向各个方向移动**

随着我们为火星车开发更多功能，我们的代码可能会变得相当冗长和混乱。在编程中，保持代码组织有序和可维护性是一个好习惯。实现这一目标的一种方法是为不同的任务创建单独的函数。

在这种情况下，我们可以为火星车可以移动的每个方向创建单独的函数。这不仅使我们的代码更容易理解，还允许我们在程序中的任何地方重复使用这些函数，而无需重新编写相同的代码行。

让我们看看如何做到这一点：

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/90c13522-9757-4212-b250-63ffbc790fd3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

通过这种结构，我们的主循环保持简单且易于理解。我们可以清楚地看到火星车向前移动，然后向后移动，
然后左右转弯，最后停止。

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/car_move.mp4" type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>

每个动作如何实现的细节都隐藏在单独的函数中。这是良好编程实践的一个关键方面，称为抽象。

**步骤5：分享与反思**

恭喜你完成了这次火星车探索之旅！这是你科学和工程知识的实际应用，你做得非常出色！

现在，你可以分享你的火星车如何克服各种地形障碍。你可以拍摄你的火星车在不同地形上导航的视频，或者向你的朋友展示你的火星车。

反思你的学习过程也非常重要。在这个过程中你学到了什么？是否有任何新想法或创意思维涌现？你在控制电机和编程方面获得了什么？

你可以继续探索，发现新知识，并不断提高自己。加油，未来的科学家和工程师们！
