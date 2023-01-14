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
