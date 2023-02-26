# 1.11
lzz建立项目并上传文件，common和welcome有了一些修改，要不你同步一下？
# 1.11晚上
1. lzz更新了common系列，```welcome.c```和```main.c```，更新内容包括```welcome.c```做了一些小优化，common系列里添加了打印地图和UI的函数。
2. lzz修改了所有文件中注释的方式，函数前统一加上注释区，内容包括函数用途和作者。
3. lzz添加了```teach.h```和```teach.c```，用于演示教程。现在还什么都没写。
# 1.12
1. lpc更新common系列，添加了初始化函数。
# 1.13
1. lzz在common系列里新增一个函数```get_block```，用于根据鼠标的像素位置判断鼠标位于哪个格子，以及是格子的上半还是下半。
2. lpc更改common.h中位置坐标的类型，并在common.c中更新了```init```，增加了初始化敌方位置的信息，删除了```init```中的形参 my_num和en_num，新增函数```print_en```,打印敌方单位。
# 1.14
1. lzz发现自己需要进行字符串操作但是之前忘了在```common.h```里调用string库，所以在```common.h```里面加上了```#include<string.h>```
2. lzz在结构体里添加了```max_attack```参数和一些关于运输船的参数。
3. lzz添加了```info.h```和```info.c```，用于在右侧的信息栏里输出信息。
# 1.15
1. lzz添加了```anime.h```和```anime.c```，用于动画类功能。目前内部有一个函数```print_atk```，用于播放攻击动画。
2. lpc更新```common.h```,敌方单位名称改为指针，加入地图位置坐标（即第几格），更新```init```,添加敌方地图位置坐标，```print_en```新增功能：可判定敌方hp
3. lpc优化了commmon.c中的地图类型,敌方单位下移。
4. 保险起见，lzz在```common.c```中```init```函数里添加了将所有我方单位坐标初始化为0
5. lzz修改了info系列中的```info```函数，添加了一个参数，使得它能够在显示信息时选择不打印按钮。
6. lzz在welcome系列中添加了```place```函数，用于初始放置我方单位
# 1.30
1. lzz将项目名称改为了BorlandC-War-Game-Project
# 2.21
1. lpc修改了```anime.c```
# 2.23
1. lzz上传了```data.h```和```data.c```，内涵记录用户信息以及显示结算界面的函数
2. lzz修改了```welcome.h```和```welcome.c```，现在开场动画可以分辨名字是否先前出现过。同时在welcome系列中增加了```teach()```函数用于之后写教程
# 2.26
1. lzz在```common.c```里新增函数nts（number to string）用来将数字转换为字符串
2. lzz修改了```welcome.c```，现在输入名字时可以退格
3. lzz修改了```data.c```，现在显示数字时不会出现黑框
4. lzz修改了```common.c```，新增了一些初始化
