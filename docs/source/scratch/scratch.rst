.. _programming_scratch:

使用 Scratch 编程
============================

除了在 Arduino IDE 上进行编程外，我们还可以使用图形化编程。

我们推荐使用 Scratch 进行编程。
然而，官方 Scratch 目前仅支持 Raspberry Pi。为此，我们开发了 Mammoth Coding，
这是一款基于 Scratch 3 的图形化编程软件，专为 Arduino 主板（Uno、Mega2560 和 Nano）设计。

Mammoth Coding 保留了 Scratch 3 的基本功能，同时增加了控制 Arduino Uno、
Mega、Nano 等各种主板的能力。它允许您使用外部传感器和机器人来控制舞台上的精灵，提供强大的硬件交互能力。

此外，即使您没有太多编程经验，这款应用也很容易上手。您可以轻松学习和使用这些前沿技术。

只需拖放 Scratch 编程积木块，即可创建精彩的游戏、动画、互动项目，甚至完全按照您的设想控制机器人！

现在就开始这段探索之旅吧！


**下载代码**


.. note::

    以下所有项目的 Scratch 脚本均已上传至 GitHub。您可以通过提供的链接下载。所有 ``.sb3`` 脚本文件位于 ``galaxy-rvr-main/scratch_codes/`` 文件夹中。

   * |download_galaxyrvr_code|

或者查看 `SunFounder GalaxyRVR Kit for Arduino - GitHub <https://github.com/sunfounder/galaxy-rvr/tree/1.2>`_ 上的代码。


**基础项目**

这些项目是使用 Mammoth Coding 控制 GalaxyRVR 的基础课程。它们将逐步指导您如何使用 GalaxyRVR。

.. toctree::
    :maxdepth: 1


    sc1_history
    sc2_app
    sc3_rvr_move
    sc4_ultrasonic
    sc5_animate
    sc6_obstacle
    sc7_obstacle_animate
    sc8_avoid
    sc9_follow
    sc10_rgb
    sc11_servo
    sc12_camera
    sc13_all


**趣味项目**

以下是一些不需要 GalaxyRVR 即可实现的趣味项目。

.. toctree::
    :maxdepth: 1

    fun/sc_fun_balloon
    fun/sc_fun_flappy_parrot
    fun/sc_fun_shooting
    fun/sc_fun_eat_apple
    fun/sc_fun_fish
    fun/sc_fun_sensitive_ball
    fun/sc_fun_tap_tile
