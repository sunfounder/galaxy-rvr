.. note:: 

    你好，欢迎加入 SunFounder Raspberry Pi、Arduino 和 ESP32 爱好者社区！与其他爱好者一起深入探索 Raspberry Pi、Arduino 和 ESP32 的奥秘。

    **为什么要加入？**

    - **专家支持**：在售后问题和技术挑战上，社区和团队会为你提供帮助。
    - **学习与分享**：交换技巧和教程，提升你的技能。
    - **独家预览**：提前获取新品发布和预告片。
    - **特别折扣**：享受我们最新产品的独家折扣。
    - **节日促销和赠品**：参与赠品活动和节日促销。

    👉 准备好与我们一起探索与创造了吗？点击 [|link_sf_facebook|] 今天就加入吧！

第五课 释放火星车的移动能力
======================================================

准备好了吗，年轻的探索者们！我们已经掌握了电机控制，现在将这些技能带到红色星球。在本课程中，我们将使火星车“复活”！

我们将学习如何将电机组装到摇臂-摆臂悬挂系统中，然后利用我们的编程技能，带领火星车穿越模拟的火星地形。

这是一次火星冒险，在课堂上开始吧！让我们动手吧！

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. note::

    如果你是在完全组装好 GalaxyRVR 后学习本课程，请在上传代码前，将开关切换到右侧。

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

学习目标
---------------------------

* 理解如何将电机组装到火星车的摇臂-摆臂悬挂系统中。
* 学习如何使用 Arduino 控制火星车的运动。
* 练习编写程序，控制火星车在不同地形上的运动。

所需材料
--------------------------
* SunFounder R3 板
* TT 电机
* GalaxyRVR Shield
* 电池
* 火星车模型（配有摇臂-摆臂系统）
* 基本工具和配件（如螺丝刀、螺丝等）
* USB 数据线
* Arduino IDE
* 电脑

步骤
--------------

**步骤 1：组装火星车组件**

在此步骤中，我们将把电池、R3 板、GalaxyRVR Shield、电机和轮子安装到预先组装好的摇臂-摆臂系统上，使 GalaxyRVR 处于可运行状态。

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/lu8K26MY96s" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

恭喜！我们已经成功组装了自己的火星车，它已经准备好开始探索了。让我们启程吧！

**步骤 2：让火星车开始运动**

现在是时候给我们的创造物注入生命，开启它的首次航行了。
但我们该如何与火星车进行通信呢？我们如何指挥它去哪里，做什么？
这时，编程技能派上用场！

在现实生活中，如果我们想让一辆车前进，我们会踩下油门，两个车轮开始旋转。
右侧车轮顺时针旋转，左侧车轮逆时针旋转。

.. image:: img/move_car.gif
    :align: center

想象你坐在驾驶座上，世界在你眼前飞驰——这正是我们要赋予火星车的体验。

现在，让我们将这种体验转化为火星车能理解的语言——代码！

    .. code-block:: arduino

        #include <SoftPWM.h>

        // 定义电机引脚 
        const int in1 = 2;
        const int in2 = 3;
        const int in3 = 4;
        const int in4 = 5;

        void setup() {
            // 初始化 SoftPWM
            SoftPWMBegin();
        }

        void loop() {
            // 设置左侧电机逆时针旋转
            SoftPWMSet(in1, 255);  // 全速
            SoftPWMSet(in2, 0);    // 停止
            
            // 设置右侧电机顺时针旋转
            SoftPWMSet(in3, 0);    // 停止
            SoftPWMSet(in4, 255);  // 全速
        }


在这段代码中，我们正与火星车对话，告诉它该做什么。
通过 ``SoftPWMSet()`` 函数，我们充当了车的油门和刹车，控制每个电机的速度和方向。
我们让左侧电机逆时针旋转，右侧电机顺时针旋转，就这样，火星车开始前进了！

当你理解了如何让火星车前进，控制它倒退就变得很简单了。
要让火星车倒退，我们只需要反转每个电机的旋转方向。

下面是如何用代码实现这一点——我们做的正好相反。右侧车轮现在应逆时针旋转，左侧车轮应顺时针旋转。

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // 定义电机引脚 
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // 初始化 SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // 设置左侧电机顺时针旋转
        SoftPWMSet(in1, 0);    // 停止
        SoftPWMSet(in2, 255);  // 全速

        // 设置右侧电机逆时针旋转
        SoftPWMSet(in3, 255);  // 全速
        SoftPWMSet(in4, 0);    // 停止
    }

在这段代码中，我们通过 ``SoftPWMSet()`` 告诉左侧电机顺时针旋转，右侧电机逆时针旋转。

是不是很神奇？我们仅凭几行代码就能控制火星车的移动！下次坐在车里时，不妨想一想火星车的旅程，它也是通过一次次的旋转探索世界的。敬请期待，因为火星车的冒险才刚刚开始！

**步骤 3：让火星车转向**

现在我们已经知道如何让火星车前进和后退，那么如果我们想让它转向左或右呢？

就像现实中的驾驶一样，汽车转向有两种主要方式。

* 第一种方式是让左侧车轮的速度比右侧车轮慢，这样火星车就会向左转。
* 第二种方式是让左右两侧的电机朝同一方向（此时为顺时针）旋转，这样火星车就会绕着自己的轴向左旋转。

让我们看看如何通过代码实现这两种方式：

**方法 1：两侧车速不同**

.. code-block:: arduino
    :emphasize-lines: 16,17,20,21

    #include <SoftPWM.h>

    // 定义电机引脚 
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // 初始化 SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // 设置左侧电机低速逆时针旋转
        SoftPWMSet(in1, 40);
        SoftPWMSet(in2, 0);

        // 设置右侧电机高速顺时针旋转
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 200);

        delay(2000);  // 持续 2 秒
    }

在这段代码中，我们将左侧电机的速度降低，同时保持右侧电机的速度较高。这将使火星车向左转。

**方法 2：所有电机同向旋转**

.. code-block:: arduino
    :emphasize-lines: 16,17,18,19

    #include <SoftPWM.h>

    // 定义电机引脚
    const int in1 = 2;
    const int in2 = 3;
    const int in3 = 4;
    const int in4 = 5;

    void setup() {
        // 初始化 SoftPWM
        SoftPWMBegin();
    }

    void loop() {
        // 设置所有电机顺时针旋转
        SoftPWMSet(in1, 0);
        SoftPWMSet(in2, 255);
        SoftPWMSet(in3, 0);
        SoftPWMSet(in4, 255);
    }

在这段代码中，我们让所有电机顺时针旋转。火星车会围绕自己的轴旋转，并改变方向向左转。

要让火星车向右转，方法相同，只需要将旋转方向反转。你能想出如何实现吗？

**步骤 4：全面控制火星车运动**

随着我们为火星车开发更多功能，代码可能会变得冗长且杂乱。为了保持代码的清晰和可维护性，编程中有一个好习惯，就是保持代码结构的整洁。一个有效的方式是将不同的任务拆分成单独的函数。

在这种情况下，我们可以为每个方向的运动创建独立的函数。这样不仅使我们的代码更容易理解，也让我们可以在程序的其他地方重用这些函数，而不必重复编写相同的代码。

让我们来看看如何做：

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/90c13522-9757-4212-b250-63ffbc790fd3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

这样一来，我们的主循环就保持了简洁易懂。
我们可以清晰地看到，火星车先前进，然后后退，再转左转右，最后停止。

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/car_move.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

每个动作的具体实现被隐藏在独立的函数中。这是良好的编程实践中的一个关键概念——抽象。

**步骤 5：分享与反思**

恭喜你完成了与火星车一起的探索之旅！这是你在科学和工程知识上的一次实际应用，做得非常棒！

现在，你可以分享你的火星车如何克服各种地形障碍。你可以拍摄火星车在不同地形上的表现，或者把火星车展示给你的朋友们。

回顾你的学习过程也非常重要。在这个过程中你学到了什么？是否有新的想法或创意出现？在电机控制和编程方面，你收获了什么？

你可以继续探索，发现新知识，不断提升自己。继续加油，未来的科学家和工程师们！
