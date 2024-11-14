.. note::

    你好，欢迎加入 SunFounder 树莓派、Arduino 和 ESP32 爱好者社区！与其他爱好者一起深入探索树莓派、Arduino 和 ESP32 的世界。

    **为什么加入？**

    - **专家支持**：通过我们的社区和团队，解决售后问题和技术难题。
    - **学习与分享**：交流技巧和教程，提升你的技能。
    - **独家预览**：提前获取新产品发布和抢先体验。
    - **专属折扣**：享受最新产品的独家折扣。
    - **节日促销和赠品**：参与赠品活动和节日促销。

    👉 准备好和我们一起探索和创造了吗？点击 [|link_sf_facebook|] 立即加入！

第十一课 探索火星漫游车视觉系统 - 摄像头与实时控制
=======================================================

欢迎回来，年轻的探险者们！在上一课中，我们为火星漫游车安装了“点头”功能，通过倾斜机制让它能够“点头”。今天，我们将为我们的漫游车装上“眼睛”——摄像头！

在这次激动人心的旅程中，我们将深入了解火星漫游车摄像头系统的设置。你将学会如何将漫游车摄像头捕捉到的影像传输到网页上，这样你就可以实时看到漫游车所看到的景象。想象一下，从漫游车的视角体验火星的景色，这将是多么兴奋的体验！

更令人兴奋的是，我们还将介绍 SunFounder Controller 应用程序。这个应用程序可以让我们实时查看漫游车的视角，同时还能直接通过手机或平板控制倾斜机制。就像一个内置屏幕的遥控器一样！

这将为我们的漫游车带来更加互动和引人入胜的体验。敬请期待更多的冒险！

    .. image:: img/app/camera_view_app.png

学习目标
-------------------

* 理解如何与 ESP32 CAM 建立 Wi-Fi 连接。
* 学习如何实时查看火星漫游车所看到的景象。
* 学习如何使用 SunFounder Controller 应用创建虚拟遥控器，控制火星漫游车。


所需材料
-----------------------

* 火星漫游车模型（已配备所有组件）
* Arduino IDE
* 电脑
* 安装了 SunFounder Controller 应用的平板或智能手机

课程步骤
------------------

**步骤1：了解 ESP32 CAM**

在之前的冒险中，我们通过集成 ESP32 CAM 为火星漫游车装上了一对“眼睛”。
今天，我们将进一步了解它，并让它“看见”！

.. image:: img/esp32_cam.png
    :width: 400
    :align: center

ESP32 CAM 就像我们漫游车的“眼睛”，它是一个小巧却功能强大的模块。它不仅集成了 Wi-Fi 和蓝牙功能，还配备了一个紧凑的摄像头，帮助我们的漫游车捕捉周围环境的图像。

就像我们用眼睛观察周围的环境一样，ESP32 CAM 可以“看到”漫游车前方的景象，并将这些视觉数据发送到我们的手机或电脑。这样，我们就能实时看到漫游车所看到的一切！

就像我们亲自操控漫游车一样，不仅能看到漫游车本身，还能看到它所探索的世界！是不是很不可思议？让我们深入了解它……


**步骤2：编程火星漫游车的摄像头并查看影像**

安装好 ESP32-CAM 后，我们需要让它发挥作用。
为了做到这一点，我们将使用 Arduino IDE 编写一个程序来控制摄像头，连接 Wi-Fi，并将捕获的影像进行直播。

下面是具体的操作步骤：

#. 安装 ``SunFounder AI Camera`` 库。

    * 打开 Arduino IDE 的 **库管理器**，搜索“SunFounder Camera”，点击 **安装**。

        .. image:: img/camera_install_lib.png

    * 弹出窗口将出现，安装库的依赖项。点击 **安装所有**，等待安装过程完成。

        .. image:: img/camera_install_lib1.png

#. 在 Arduino IDE 中输入以下代码。

    关于代码中的 ``NAME``、 ``TYPE`` 和 ``PORT`` 变量，暂时不深入讨论。它们将在接下来的步骤中派上用场。请记住，这些变量将在我们建立火星漫游车实时视频流的过程中发挥重要作用。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b648e4-23e8-4b28-accd-aac171069116/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


    注意，代码中有两种连接模式—— **AP 模式** 和 **STA 模式** 。你可以根据自己的需求选择适合的模式。

    * **AP 模式**：在这种模式下，漫游车创建一个热点（在我们的代码中命名为 ``GalaxyRVR``）。任何设备，如手机、平板或笔记本，都可以连接到这个网络。这在你需要远程控制漫游车时非常有用。不过，请注意，这会导致你的设备暂时无法连接到互联网。

        .. code-block:: arduino

        // AP 模式
        #define WIFI_MODE WIFI_MODE_AP
        #define SSID "GalaxyRVR"
        #define PASSWORD "12345678"

    * **STA 模式**：在这种模式下，漫游车连接到你的家庭 Wi-Fi 网络。记得你的控制设备（如手机或平板）也需要连接到相同的 Wi-Fi 网络。这种模式下，你的设备可以保持正常的互联网连接，同时控制漫游车，但漫游车的操作范围将受限于 Wi-Fi 覆盖范围。

        .. code-block:: arduino

            // STA 模式
            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "YOUR SSID"
            #define PASSWORD "YOUR PASSWORD"

#. 将代码上传到火星漫游车并启动 ESP32 CAM！

    * ESP32-CAM 和 Arduino 板共享相同的 RX（接收）和 TX（传输）引脚。因此，在上传代码之前，你需要先通过将开关滑动到右侧来释放 ESP32-CAM，避免任何冲突或潜在问题。

        .. image:: img/camera_upload.png
            :width: 600

    * 代码上传成功后，切换回左侧以启动 ESP32 CAM。

        .. note::
            每次重新上传代码时，都会需要完成这一步和前一步。

        .. image:: img/camera_run.png
            :width: 600

    * 打开 **串口监视器**，并将波特率设置为 115200。如果没有显示任何信息，请按下 **重置按钮**，重新运行代码。你应该会看到串口监视器输出一个 IP 地址。这是你漫游车摄像头正在广播的地址。

        .. image:: img/camera_serial.png

    * 现在，是时候真正看到火星漫游车所看到的景象了！打开一个网页浏览器——我们推荐使用 Google Chrome——在地址栏中输入串口监视器中显示的 URL，格式为 ``http://ip:9000/mjpg``。

        .. image:: img/camera_view.png

好啦！现在你应该能够看到来自漫游车摄像头的实时视频流了。想想看，你正在以漫游车的视角观察火星（或者也许是你的客厅）！就像真正的火星漫游车科学家一样！

记住，这只是一个开始。接下来，我们将继续探索如何在查看实时摄像头画面的同时控制火星漫游车。激动人心吧？探险者们，继续前进！


**步骤 3：使用应用控制并查看摄像头画面**

你是否曾希望能够在智能手机上查看火星漫游车的视觉画面，同时还能够控制它的倾斜机制？  
现在，你可以实现这一目标了！借助 SunFounder Controller 应用，你将能够做到这一切。请按照以下步骤操作：


#. 从 **APP Store(iOS)** 或 **Google Play(Android)** 下载并安装应用。

#. 创建一个控制器。

    * 在 SunFounder Controller 应用中，点击 **+** 图标以添加一个新的控制器。

        .. image:: img/app/app1.png

    * 选择 **Blank** 预设，按照你的喜好选择 **Dual** 或 **Single Stick**，给新的控制器命名，然后点击 **确认**。

        .. image:: img/app/camera_controller.png

    * 现在你已进入控制器设置界面。在 D 区域点击 **+** 图标，然后从弹出的菜单中选择 “Slider”。

        .. image:: img/app/camera_add_slider.png

    * 这个滑动条控件将用来控制倾斜机制。正如我们在前一课中学到的，它的范围是从 0 到 140。因此，我们将这些值设置为滑动条的最小值和最大值。

        .. image:: img/app/camera_slider_set.png
    
    * 点击右上角的 |app_save| 按钮保存控制器设置。

#. 编写代码以捕获滑动条的值：

    * 基于之前的代码，我们将切换到 AP 模式，在该模式下你可以设置 SSID 和密码为你所需的任何值。
    
    .. code-block:: arduino
    
        // AP 模式
        #define WIFI_MODE WIFI_MODE_AP
        #define SSID "GalaxyRVR"
        #define PASSWORD "12345678"

    * 接下来，我们添加一个 ``onReceive()`` 函数，用于接收来自 SunFounder Controller 的值并将这些值打印到串口监视器中。我们使用 ``getSlider()`` 函数来获取 **Slider** 控件的值。我在 D 区域添加了一个滑动条控件，但如果你添加到了其他区域，需要将 ``REGION_D`` 更改为你的区域。

        .. code-block::

            void onReceive() {
                int16_t sliderD = aiCam.getSlider(REGION_D);
                Serial.print("Slider D: ");
                Serial.println(sliderD);
            }

            void setup() {
                ...
                // 设置数据接收时执行的函数
                aiCam.setOnReceived(onReceive);
                ...
            }

    * 以下是完整代码：

        .. raw:: html

            <iframe src=https://create.arduino.cc/editor/sunfounder01/b914aa48-85e7-4682-b420-89961cc761ca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
    * 在上传代码之前，确保开关已切换到右侧。

        .. image:: img/camera_upload.png
            :width: 600

    * 代码上传成功后，切换回左侧以启动 ESP32 CAM。

        .. image:: img/camera_run.png
            :width: 600

    * 当你在串口监视器中看到以下信息时，就可以继续进行下一步了。

        .. code-block:: arduino
        
            ...[OK]
            SET+PORT8765
            ...[OK]
            SET+START
            ...[OK]
            WebServer started on ws://192.168.4.1:8765
            Video streamer started on http://192.168.4.1:9000/mjpg
            WS+null

#. 连接到 ``GalaxyRVR`` 网络。

    此时，你应该将移动设备连接到 GalaxyRVR 提供的局域网 (LAN) 网络。
    通过这种方式，你的移动设备和漫游车将处于同一网络中，从而实现应用和漫游车之间的顺畅通信。

    * 在移动设备（平板或智能手机）上的可用网络列表中找到 ``GalaxyRVR``，输入密码 ``12345678``，然后连接。

        .. image:: img/app/camera_lan.png

    * 默认连接模式为 **AP 模式**。连接后，可能会弹出提示，警告你该 WLAN 网络没有互联网连接，请选择继续连接。

        .. image:: img/app/camera_stay.png

#. 连接并激活控制器。

    * 现在，返回到你之前创建的控制器（在我的例子中，控制器名为“camera”）。使用 |app_connect| 按钮将 SunFounder Controller 与漫游车连接，建立通信连接。稍等片刻， ``GalaxyRVR(IP)`` （你在代码中通过 ``#define NAME "GalaxyRVR"`` 定义的名称）会显示出来。点击它以建立连接。

        .. image:: img/app/camera_connect.png

        .. note::
            如果长时间没有看到上述信息，请确认你的 Wi-Fi 是否已连接到 ``GalaxyRVR``。

    * 一旦看到“连接成功”的信息，点击 |app_run| 按钮。这将会在应用中显示摄像头的实时画面。

        .. image:: img/app/camera_view_app.png

    * 现在，移动滑动条并同时打开 Arduino IDE 的串口监视器。你应该会看到如下类似的数据：

        .. code-block:: 
    
            Slider D: 105
            WS+null
            Slider D: 105
            WS+null
            Slider D: 105
            WS+null


#. 让滑动条控制倾斜机制。

    现在我们已经知道滑动条控件传输的值，可以直接使用这些值来旋转舵机。
    因此，在之前的代码基础上，添加以下几行代码来初始化舵机，并将滑动条的值写入舵机。

    .. code-block::

        ...
        #include <Servo.h>

        Servo myServo;  // 创建舵机对象
        myServo.write(int(sliderD));  // 控制舵机转动到当前角度

        ...

        void onReceive() {
            ...
            myServo.write(int(sliderD));  // 控制舵机转动到当前角度
        }

        void setup() {
            ...
            myServo.attach(6);  // 将舵机连接到 6 号引脚
            ...
        }

    以下是完整的代码：

    .. raw:: html
    
        <iframe src=https://create.arduino.cc/editor/sunfounder01/b737352b-2509-4967-8147-1fd6bdc7d19d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

    将上述代码上传到 GalaxyRVR，重复步骤 4 和 5，重新连接到 ``GalaxyRVR`` LAN 网络，并重新在 SunFounder Controller 中运行，你就可以通过滑动滑动条来控制漫游车的倾斜机制了。

现在，你已经成功学习了如何实现 SunFounder Controller 并使用滑动条控件来控制舵机的运动。这个过程将让你以更直观、更直接的方式与 GalaxyRVR 进行互动。


**步骤 4：反思与总结**

使用 SunFounder Controller 操控你的火星漫游车，初看起来可能有些复杂。每次修改代码时，你都需要重复以下步骤：

* 在上传代码之前，确保开关切换到右侧。

    .. image:: img/camera_upload.png
        :width: 600

* 代码上传成功后，切换回左侧以启动 ESP32 CAM。
* 连接到 ``GalaxyRVR`` 网络。
* 连接并运行控制器。

虽然这些步骤看起来有些繁琐，但它们对整个过程至关重要。经过几次重复操作后，你会变得更加熟悉和得心应手。

现在我们已经完成了本课的内容，让我们通过一些问题来反思一下我们学到的知识：

* 在创建新控制器的过程中，你遇到了许多不同类型的控件。你是否考虑过它们各自的功能是什么？
* 是否可以使用其他控件来控制倾斜机制？
* 甚至直接控制火星漫游车的运动？

让我们在下一课中继续探索这些问题吧！
