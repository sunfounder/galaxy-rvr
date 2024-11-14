.. note:: 

    你好，欢迎加入 Facebook 上的 SunFounder 树莓派、Arduino 和 ESP32 爱好者社区！与志同道合的朋友一起深入探索树莓派、Arduino 和 ESP32。

    **为什么加入？**

    - **专家支持**：在售后问题和技术挑战上获得我们社区和团队的帮助。
    - **学习与分享**：交流技巧和教程，提升你的技能。
    - **独家预览**：提前获取新产品的发布信息和抢先体验。
    - **专属折扣**：享受最新产品的独家优惠。
    - **节日促销与赠品**：参与赠品活动和节日促销。

    👉 准备好和我们一起探索与创造了吗？点击 [|link_sf_facebook|]，立即加入吧！


第十三课 探索火星探测器的能源系统
=================================================================

欢迎来到我们火星探测器探索之旅的最后一课。这一次，我们将深入探讨探测器的心脏——能源系统。

当我们考虑探索像火星这样遥远的星球时，最关键的方面之一就是能源。  
这些探测器在如此恶劣和遥远的环境中是如何提供能量的？  
在本课中，我们将探讨这一令人着迷的话题，了解像我们的火星探测器模型是如何获取和管理能源的。

我们将研究电池和太阳能板的工作原理，并亲手安装和使用这些电源来为我们的探测器提供动力。
此外，我们还将通过 Arduino 来监控电池电量，提升我们的技能。

本课结束时，我们将能够在我们的 APP 上显示这些重要的能源统计数据，实时了解探测器的能源状态。
准备好为我们的探索注入动力了吗？让我们开始吧！

.. image:: img/solar_panel.jpg
    :width: 600
    :align: center

学习目标
-----------------------

* 理解电池和太阳能板的工作原理。
* 练习在火星探测器模型上安装太阳能板。
* 学会如何使用 Arduino 监控电池电量和太阳能板的充电状态。
* 在 APP 上显示电池电量。

所需材料
------------------------

* 火星探测器模型（配备所有组件，除了太阳能板和底板）
* 太阳能板和底板
* Arduino IDE
* 计算机
* 安装了 SunFounder Controller 应用的平板或智能手机



课程步骤
----------------------

**步骤 1：了解火星探测器的能源系统**

就像我们的身体需要持续供应能量才能正常运作一样，我们的火星探测器也需要一种方式来存储和生成能量，以支持其探索任务。可以把探测器的能源系统比作我们身体中的心脏。正如我们的心脏将血液泵送到全身各个部位，供应必要的氧气和营养，探测器的能源系统则确保能量持续流动到探测器的各个部分，保证它能够顺利执行任务。

这个能源系统的主要组成部分是电池和太阳能板，它们协同工作，确保探测器在任何时间、无论白天还是黑夜，都能持续运作。

电池在探测器能源系统中的作用，类似于我们体内储存能量的方式。就像我们需要储存能量以应对活动时的需求一样，探测器也需要一种方式来储存能源以支持其探索任务。储存在电池中的能量会不断分配到探测器的各个部分，使其能够有序地执行任务。

.. image:: img/battery_galaxyrvr.png
    :width: 600
    :align: center

但是，当电池中的能量耗尽时会发生什么呢？它是如何补充能源的呢？这时，太阳能板就发挥了作用。

就像树木吸收阳光进行光合作用以制造食物一样，我们的火星探测器也利用太阳能板来捕获太阳能，将其转化为电力，并储存到电池中备用。每个太阳能板由多个小型太阳能电池组成，这些电池由能够将光转化为电力的材料构成——这一过程叫做光伏效应。当阳光照射到这些电池时，它们会产生电流，电流可以立即使用或存储在探测器的电池中以供日后使用。

.. image:: img/solar_panel_gala.png
    :width: 600
    :align: center

然而，在火星上利用太阳能并不像听起来那么简单。沙尘暴会减少阳光到达太阳能板的量，而火星上的阳光比地球上的要弱，这意味着太阳能板产生的电力也比在地球上少。尽管面临这些挑战，太阳能仍然是为火星探测器供电最实用、最有效的方式。

但我们如何知道太阳能板是否正在发挥作用，以及电池是否电量不足呢？这时 Arduino 就派上用场了。在接下来的部分，我们将学习如何使用 Arduino 监控探测器电池的充电和放电状态。


**步骤 2：安装太阳能板到火星探测器上**

在开始这一步之前，我们需要准备好火星探测器模型、太阳能板，以及连接太阳能板和探测器电源系统所需的电缆。

这是一个让我们将理论付诸实践的过程，真正体会到科学、技术、工程和数学（STEM）教育的魅力。让我们开始吧！

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/-Vj-dcniFrA" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

**步骤 3：编程监控电池电压和电量**

现在我们已经在火星探测器模型上安装了太阳能板，接下来的步骤是通过编程监控电池的电压和电量。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2e85e234-9575-4a1f-982b-2f9aba8e3156/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


这段代码有效地创建了一个简单的电池监视器，这在像火星探测器这样的应用中尤为重要，因为电力管理至关重要。它将帮助你监控电池的状态，了解何时需要为探测器充电，或者何时应该安排高耗电任务。

我们来逐步解析这段代码的不同部分：

* 这一行代码定义了 ``BATTERY_PIN`` 为模拟引脚 A3，用于读取电池电压。

    .. code-block:: arduino

        #define BATTERY_PIN A3

* 这个函数用于计算电池电压。它首先读取 ``BATTERY_PIN`` 的模拟值，然后将其转换为电压值。由于 Arduino 的模拟-数字转换器（ADC）操作的范围是 0-1023，我们将原始读取值除以 1023，然后乘以 5（Arduino 的参考电压），再乘以 2（假设使用了 2 倍电压分压器），来将其转换为电压值。

    .. code-block:: arduino
        :emphasize-lines: 5

        float batteryGetVoltage() {
            // 读取电池引脚的模拟值
            int adcValue = analogRead(BATTERY_PIN);
            // 将模拟值转换为电压
            float adcVoltage = adcValue / 1023.0 * 5 * 2;
            // 将电压四舍五入到小数点后两位
            float batteryVoltage = int(adcVoltage * 100) / 100.0;
            return batteryVoltage;
        }


    Arduino 的模拟值通过将原始 ADC 读取值除以 1023 来转换为比例值，然后乘以 5，将其转化为电压，因为 Arduino 使用 5 伏的参考电压。

    由于电池电压高于 Arduino 的最大输入电压，因此使用了电阻来保护 Arduino。因此，我们将 ADC 电压乘以 2，以抵消电阻的影响，从而获得正确的电池电压。

* 这个函数根据电池电压计算电池的充电百分比。它使用 ``map`` 函数将电压值（范围在 6.6 到 8.4 伏之间）映射为百分比值（范围从 0 到 100）。

    .. code-block:: arduino

        uint8_t batteryGetPercentage() {
            float voltage = batteryGetVoltage();  // 获取电池电压
            // 将电压映射到百分比
            int16_t temp = map(voltage, 6.6, 8.4, 0, 100);
            // 确保百分比在 0 到 100 之间
            uint8_t percentage = max(min(temp, 100), 0);
            return percentage;
        }

**步骤 4：测试火星探测器能源系统：室内与室外测试**

在完成电池监控系统的编程后，是时候让火星探测器投入实际操作了。  
首先将探测器充电至满电状态，并计划进行两次各30分钟的探索任务——一次在室内，另一次在户外阳光下进行。
在每次任务前记录初始的电池电量，并与每次测试结束时的电池电量进行比较。  
以下表格可以帮助你记录测试结果：





.. list-table:: Power Test
   :widths: 50 25 25
   :header-rows: 1

   * - 
     - 阳光
     - 室内
   * - 开始时电池百分比
     - 
     - 
   * - 结束时电池百分比
     - 
     - 

观察每次测试后电池电量的变化。
当探测器在户外阳光下时，它的电池是否能持续更长时间？从这些观察中，我们可以得出什么关于太阳能板效果的结论？

理解这些差异将有助于我们更好地理解太阳能如何有效地为火星探测器提供动力，即使在像火星表面这样的遥远而恶劣的环境中。



**步骤 5：在APP上显示电池电量**

显然，反复上传新代码到火星探测器以检查剩余电量并不现实，这样非常不便。

相反，我们可以将电池电量发送到APP，让我们在享受乐趣时轻松监控剩余电量！

在之前的课程中，我们已经学过，当我们希望在 SunFounder Controller 上显示数据或使用控件控制火星探测器时，首先需要添加这些控件。

然而，电池电量显示是一个特殊的控件。它有一个专用的键（ ``BV`` ），并且其显示位置不在标记为 A 到 Q 的区域中。相反，它通过右上角的电池图标来表示。

以下是如何在代码中包含该控件：

.. code-block:: Arduino

    ...
    // 该引脚读取电池电压
    #define BATTERY_PIN A3
    ...

    void setup() {
        ...
        // 设置电池引脚为输入模式
        pinMode(BATTERY_PIN, INPUT);
    }

    // 接收到控制器数据时执行的函数
    void onReceive() {
        ...
        // 显示电池电压
        aiCam.sendDoc["BV"] = batteryGetVoltage();
    }   

    ...

    // 读取电池电压的函数
    float batteryGetVoltage() {
        // 读取电池引脚的模拟值
        int adcValue = analogRead(BATTERY_PIN);
        // 将模拟值转换为电压
        float adcVoltage = adcValue / 1023.0 * 5 * 2;
        // 将电压四舍五入到小数点后两位
        float batteryVoltage = int(adcVoltage * 100) / 100.0;
        return batteryVoltage;
    }

请查看附带的完整代码：

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8b6e0dbd-6fcc-45ac-8408-e8aa706a4bf3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

在成功上传代码后，启动你的 SunFounder Controller，你将在右上角看到电池电量显示。

.. image:: img/battery_icon.png

通过完成这一步骤，我们已经掌握了火星探测器的能源系统，并具备了实时监控其电池电量的能力。

现在我们已经学会如何利用太阳能有效驱动火星探测器，我们可以开始规划更大范围的探索，甚至挑战更具难度的地形！

**步骤 6：反思**

在本课中，我们重点理解了火星探测器能源系统的关键作用，并学习了如何监控探测器剩余电量的机制。基于太阳能的能源系统不仅为探测器提供动力，还突显了可再生能源在太空探索中的重要性。

凭借你现在掌握的知识，思考一下这个系统在现实生活中的意义。考虑一下太阳能系统在火星上可能遇到的挑战。极端温度、沙尘暴或长时间的黑暗将如何影响能源供应？你能提出哪些解决方案来应对这些障碍？

**步骤 7：展望未来**

现在我们已经赋予了火星探测器移动能力，是时候让它开始探索之旅了！你可以让它在模拟火星环境的各种地形中自由穿行。

例如，你可以让它爬越一堆石头。

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/move_stone.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

或者让它穿越一片浓密的草地。

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/move_grass.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

又或者让它在一片布满石头的砾石地面上行驶。

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="_static/video/move_stone1.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

然而，请注意，如果障碍物过高，探测器可能无法爬越。

.. raw:: html

   <video width="400" height="400" loop autoplay muted>
      <source src="_static/video/move_failed.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

这些多样的地形对探测器提出了独特的挑战，就像它们会对真实的火星探测器造成挑战一样。当你观看探测器尝试克服这些障碍时，你正在体验 NASA 科学家和工程师们在将探测器送往火星时所面临的实际情况！

随着我们结束火星探测器课程的学习，重要的是反思我们所学到的内容。我们希望这段旅程不仅拓宽了你的知识和技能，也激发了你的好奇心和探索欲望。无论你的探测器是在后院漫游，还是穿越广阔的想象空间，你在旅程中的发现都一定是非凡的。
