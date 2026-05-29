
第5课 互动动画
===============================================

之前，我们使用超声波模块让 GalaxyRVR 自动避开路径中的障碍物。

在这个活动中，我们将结合模块与舞台，创建一个火星车在火星表面上欢快行驶的互动动画。


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_jump.mp4" type="video/mp4">
      您的浏览器不支持此视频标签。
   </video>

学习目标
-------------------------

* 学习如何绘制精灵和编辑背景。
* 理解事件监听和循环结构等基本编程概念。
* 熟悉应用编程环境和基本操作，创建一个模拟火星车的简单动画。

添加新精灵
----------------------------

#. 首先，请执行 :ref:`app_connect` 的步骤。

#. 删除不需要的精灵。

   .. image:: img/6_animate_delete.png

#. 在界面右下角，点击 **选择一个精灵** 按钮，显示四个选项。

   .. image:: img/5_create_sp.png

#. 在小屏设备上，你可能需要切换到另一个屏幕才能看到此按钮。

   .. image:: img/5_create_sp0.png

四个选项分别是：

* **上传精灵** – 从设备加载一个精灵。
* **随机** – 从库中随机选择一个精灵。
* **绘制** – 自己绘制一个精灵。
* **选择一个精灵** – 从精灵库中选择。

接下来，我们将使用 **选择一个精灵** 选择一个精灵，并使用 ** 绘制** 绘制一个。

**选择一个精灵**

#. 点击 **选择一个精灵** （放大镜图标），打开精灵库。

   .. image:: img/5_sp_list.png

#. 从库中找到并选择 **GalaxyRVR** 。

   .. image:: img/1_choose_galaxyrvr.png


**绘制一个新精灵**

#. 点击 **绘制** （画笔图标）创建一个新精灵。我们将绘制一个 **火星** 精灵。

   .. image:: img/5_create_custom.png

#. 使用 **圆形工具** 绘制一个代表行星的圆。

   .. image:: img/5_create_custom1.png

#. 使用 **选择工具** 将圆圈移到画布中心。这一步很重要，因为精灵的坐标和移动都是基于其中心点的。

   .. image:: img/5_create_custom2.png

#. 使用 **填充工具** 将圆圈填充为红色。

   .. image:: img/5_create_custom3.png

#. 选择 **画笔工具** ，增大画笔尺寸，并使用合适的填充颜色添加纹理。

   .. image:: img/5_create_custom_pen.png

#. 如果颜色不理想，更改填充颜色并再次使用 **填充工具** 。

   .. image:: img/5_create_custom5.png

#. 再次选择 **画笔工具** ，将尺寸设为2，颜色改为黑色，在火星上绘制陨石坑。

   .. image:: img/5_create_custom6.png

#. 使用 **填充工具** 为陨石坑填充合适的颜色。

   .. image:: img/5_create_custom7.png

#. 完成后，切换回 **代码界面** 。

   .. image:: img/5_create_custom8.png

#. 在小屏设备上，点击图标返回代码界面。

   .. image:: img/5_create_custom8.1.png

#. 现在你将在舞台上看到火星精灵。不要忘记 **重命名** 它。

   .. image:: img/5_create_custom9.png


**舞台**

#. 点击 **背景** 来修改背景。默认的白色背景将被改为模拟夜空的效果。

   .. image:: img/6_jump_backdrop.png

#. 进入 **背景** 界面。

   .. image:: img/6_jump_backdrop_page.png

#. 在画布上绘制一个矩形。

   .. image:: img/6_jump_rect.png

#. 使用 **填充工具** 用深色填充矩形。

   .. image:: img/6_jump_fill.png

#. 使用 **画笔工具** 添加一些星星。

   .. image:: img/6_jump_paint.png


创建动画
-------------------------------

现在我们已经有了火星和 GalaxyRVR，并且知道了如何制作精灵动画，让我们来创建一个 GalaxyRVR 在火星上移动的动画。
我们可以通过让火星反向旋转来制造精灵移动的效果，从而营造出 GalaxyRVR 在其表面行驶的视觉效果。

#. 首先，请执行 :ref:`app_connect` 的步骤。

#. 调整两个精灵的大小和位置。

   * 将 GalaxyRVR 精灵设置为 **(0, 0)** ，并放置火星的位置使 GalaxyRVR 看起来站在其表面上。

   .. image:: img/6_jump_place.png


**火星精灵**

#. 选择火星精灵。它的任务是逆时针旋转，制造 GalaxyRVR 正在前进的视觉效果。

   .. image:: img/6_ssp_mars.png

#. 拖入一个绿旗积木块。所有动画都以绿旗为起点。

   .. image:: img/6_jump_mar_flag.png

#. 拖入一个 ``重复执行`` 积木块，使动画持续运行。

   .. image:: img/6_jump_mar_forever.png


#. 拖入一个 ``旋转`` 积木块和一个 ``等待`` 积木块，使火星持续旋转。

   .. image:: img/6_jump_mar_turn.png

#. 现在点击绿旗，你将看到火星逆时针旋转。



**GalaxyRVR 精灵**

#. 选择 GalaxyRVR 精灵。它的任务是进行动画，看起来就像在移动一样，尽管它本身并没有移动。

   .. image:: img/6_ssp_rvr.png

#. 拖入一个绿旗积木块。所有动画都以绿旗为起点。

   .. image:: img/6_jump_mar_flag.png

#. 拖入一个 ``重复执行`` 积木块，使动画持续运行。

   .. image:: img/6_jump_mar_forever.png

#. 拖入一个 ``下一个造型`` 积木块和一个 ``等待`` 积木块，使 GalaxyRVR 持续动画化。

   .. image:: img/6_jump_mar_next.png

#. 拖入一个 ``当距离`` 积木块。当超声波模块检测到障碍物（例如你的手）时会触发此积木块。

   .. image:: img/6_jump_when.png


#. 拖入两个 ``滑行`` 积木块，并改变第一个积木块的 y 值，让精灵跳起来然后落下，产生跳跃效果。

   .. image:: img/6_jump_glide.png

#. GalaxyRVR 精灵的完整代码应如下所示：

   .. image:: img/6_jump_mar_rvr_all.png


现在，点击绿旗开始动画。将手放在超声波模块前来模拟障碍物，GalaxyRVR 精灵就会跳跃避障。

