#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h> /*引用的库函数*/
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP 0x4800
#define ESC 0x011b/*宏定义键名*/
#define N 200
int i,key;
int level;/*游戏等级*/
int score=0;/*得分*/
int gamespeed;/*游戏速度*/
struct Food
{
int x;/*食物的横坐标*/
int y;/*食物的纵坐标*/
int yes;/*判断是否要出现食物的变量*/
}food;/*食物的结构体*/
struct Snake
{
int x[N];
int y[N];
int node;/*蛇的节数*/
int direction;/*蛇移动方向*/
int life;/* 蛇的生命,0活着,1死亡*/
}snake;/*蛇的结构体*/
void Choicelevle(void);/*选择游戏等级*/
void Init(void);/*图形驱动*/
void Close(void);/*图形结束*/
void DRAW(void);/*游戏区域*/
void GameOver(void);/*结束游戏*/
void GamePlay(void);/*玩游戏具体过程*/
void PrScore(void);/*输出成绩*/
/*主函数*/
void main(void)
{
Init();/*图形驱动*/
Choicelevle();/*选择游戏等级*/
DRAW();/*游戏区域*/
GamePlay();/*玩游戏具体过程*/
Close();/*图形结束*/
}

/*图形驱动*/
void Init(void)
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"\\turboc2"); /*初始化图形系统*/
cleardevice(); /*清除图形界面*/
}
/*选择游戏等级*/
void Choicelevle(void)
{char name[20];setcolor(YELLOW);settextstyle(0,0,6);outtextxy(150,150,"Snake");setcolor(GREEN);settextstyle(0,0,1);outtextxy(200,250,"please put in your English name:");outtextxy(200,270,"Choice levle from 1-9.");outtextxy(300,320,"name:yangzilong");/*制作人姓名*/outtextxy(300,350,"number:0902060226");/*制作人学号*/outtextxy(300,380,"class:computer science 0602");/*制作人班级*/getch();printf("please putin your name:");gets(name);printf("please choice levle:");scanf("%d",&level);gamespeed=100000-400*level-300*level*level;if(level>9||level<1){cleardevice(); /*清除图形界面*/setcolor(YELLOW); /*设置字体颜色*/settextstyle(0,0,2); /*设置字体类型*/outtextxy(150,200,"level input error"); /*显示文本*/getch();level=1;}
}
void DRAW(void)
{cleardevice(); /*清屏*/setcolor(2);setlinestyle(SOLID_LINE,0,THICK_WIDTH);/*设置线型*/rectangle(45,45,465,325);}
/*玩游戏具体过程*/
void GamePlay(void)
{setcolor(5);setlinestyle(SOLID_LINE,0,THICK_WIDTH);/*设置线型*/randomize();/*随机数发生器*/food.yes=1;/*1表示需要出现新食物,0表示已经存在食物*/snake.life=0;/*活着*/snake.direction=1;/*方向往右*/snake.x[0]=320;snake.y[0]=240;/*蛇头*/snake.x[1]=330;snake.y[1]=240; /*蛇的第二节位置*/snake.node=3;/*节数*/PrScore();/*输出得分*/while(1)/*可以重复玩游戏,压ESC键结束*/{while(!kbhit())/*在没有按键的情况下,蛇自己移动身体*/{if(food.yes==1)/*需要出现新食物*/{food.x=rand()%360+70;food.y=rand()%250+60;while(food.x%10!=0)/*食物随机出现后必须让食物能够在整格内,这样才可以让蛇吃到*/food.x++;while(food.y%10!=0)food.y++;food.yes=0;/*画面上有食物了*/}
if(food.yes==0)/*画面上有食物了就要显示*/
{
setcolor(GREEN);
rectangle(food.x,food.y,food.x+10,food.y-10);
}
for(i=snake.node-1;i>0;i--)/*蛇的每个环节往前移动*/
{
snake.x[i]=snake.x[i-1];
snake.y[i]=snake.y[i-1];
}
/*1,2,3,4表示右,左,上,下四个方向,通过这个控制来移动蛇头*/
switch(snake.direction)
{
case 1: snake.x[0]+=10;break;
case 2: snake.x[0]-=10;break;
case 3: snake.y[0]-=10;break;
case 4: snake.y[0]+=10;break;
}
for(i=3;i<snake.node;i++)/*从蛇的第四节开始判断是否撞到自己了，因为蛇头为两节，第三节不可能拐过来*/
{
if(snake.x[i]==snake.x[0]&&snake.y[i]==snake.y[0])
{
GameOver();/*显示失败*/
snake.life=1; /*蛇死*/
break;
}
}

/*如果蛇头碰到墙壁，蛇头从对面墙出来*/
if(snake.x[0]<50)
{snake.x[0]=450;/*如果蛇头越过左边界,则从右边界进入*/snake.y[0]=snake.y[0];/*纵坐标不变*/for(i=snake.node-1;i>0;i--){snake.x[i]=snake.x[i-1];snake.y[i]=snake.y[i-1]; /*蛇的其他节数向前推进*/}
{
setfillstyle(SOLID_FILL,0); /*设置填充模式和颜色，0表示黑色*/
bar(50,55,455,315);/*bar是表示填充的范围的函数*/
}
}
else
if(snake.x[0]>450)
{snake.x[0]=50;/*如果蛇头越过右边界,则蛇头从左边界进入*/snake.y[0]=snake.y[0];/*纵坐标不变*/for(i=snake.node-1;i>0;i--){snake.x[i]=snake.x[i-1];snake.y[i]=snake.y[i-1]; /*蛇的其他节数向前推进*/}
{
setfillstyle(SOLID_FILL,0); /*设置填充模式和颜色，0表示黑色*/
bar(50,55,455,315);/*bar是表示填充的范围的函数*/
}
}
else
if(snake.y[0]<60)
{snake.y[0]=320;/*如果蛇头越过上边界,则从下边界进入*/snake.x[0]=snake.x[0];/*横坐标不变*/for(i=snake.node-1;i>0;i--){snake.x[i]=snake.x[i-1];snake.y[i]=snake.y[i-1]; /*蛇的其他节数向前推进*/}
{
setfillstyle(SOLID_FILL,0); /*设置填充模式和颜色，0表示黑色*/
bar(50,55,455,315);/*bar是表示填充的范围的函数*/
}
}
else
if(snake.y[0]>320)
{snake.y[0]=60;/*如果蛇头越过下边界,则从上边界进入*/snake.x[0]=snake.x[0];/*横坐标不变*/for(i=snake.node-1;i>0;i--){snake.x[i]=snake.x[i-1];snake.y[i]=snake.y[i-1]; /*蛇的其他节数向前推进*/}
{
setfillstyle(SOLID_FILL,0); /*设置填充模式和颜色，0表示黑色*/
bar(50,55,455,315);/*bar是表示填充的范围的函数*/
}
}
if(snake.life==1)/*如果蛇死就跳出内循环，重新开始*/
break;
if(snake.x[0]==food.x&&snake.y[0]==food.y)/*吃到食物以后*/
{
setcolor(0);/*把画面上的食物东西去掉*/
rectangle(food.x,food.y,food.x+10,food.y-10); /*用当前线型和颜色画一矩形*/
snake.x[snake.node]=-20;snake.y[snake.node]=-20;
/*新的一节先放在看不见的位置,下次循环就取前一节的位置*/
snake.node++;/*蛇的身体长一节*/
food.yes=1;/*画面上需要出现新的食物*/
score+=10; /*每吃掉一食物,得分累加10分*/
if(score%100==0)
{level++;gamespeed=100000-400*level-300*level*level;/*每吃掉10食物提升一级,速度加快*/PrScore();/*输出新得分*/setcolor(YELLOW); /*设置字体颜色*/settextstyle(0,0,4); /*设置字体类型*/outtextxy(150,200,"LEVEL UP"); /*显示文本*/if(level==10){level=1,gamespeed=100000-400*level-300*level*level;}
delay(6000000); 
delay(6000000); 
delay(6000000); 
delay(6000000); 
delay(6000000);
delay(6000000); 
delay(6000000);
bar(50,55,455,315);/*bar是表示填充的范围的函数*/
}
PrScore();/*输出新得分*/ 
} 
setcolor(4);/*画出蛇*/ 
for(i=0;i<snake.node;i++) 
rectangle(snake.x[i],snake.y[i],snake.x[i]+10, 
snake.y[i]-10); 
delay(gamespeed); /*控制游戏速度*/
setcolor(0);
rectangle(snake.x[snake.node-1],snake.y[snake.node-1], 
snake.x[snake.node-1]+10,snake.y[snake.node-1]-10); 
} /*endwhile（！kbhit）*/ /*用黑色去除蛇的的最后一节*/ 
if(snake.life==1)/*如果蛇死就跳出循环*/ 
break; 
key=bioskey(0);/*接收按键*/ 
if(key==ESC)/*按ESC键退出*/ 
break; 
else 
if(key==UP&&snake.direction!=4) 
/*判断是否往相反的方向移动*/ 
snake.direction=3; 
else 
if(key==RIGHT&&snake.direction!=2) 
snake.direction=1; 
else 
if(key==LEFT&&snake.direction!=1) 
snake.direction=2; 
else 
if(key==DOWN&&snake.direction!=3) 
snake.direction=4; 
}/*endwhile(1)*/ 
} 
/*游戏结束*/ 
void GameOver(void) 
{ 
cleardevice(); /*清屏*/
PrScore(); 
setcolor(RED); /*设置字体颜色*/
settextstyle(0,0,4); /*设置字体类型*/
outtextxy(200,200,"GAME OVER"); /*显示文本*/
getch(); 
} 
/*输出成绩及游戏等级*/ 
void PrScore(void) 
{ 
char str1[20];/*设置字符型数组*/ 
setfillstyle(SOLID_FILL,0); 
bar(50,15,390,35); /*填充矩形框*/
setcolor(6); /*设置文本颜色*/
settextstyle(0,0,2); /*设置数组显示位置*/
sprintf(str1,"score %d level %d",score,level);/*显示数组内容*/
outtextxy(55,20,str1); 
setcolor(YELLOW); /*设置字体颜色*/
settextstyle(0,0,2); /*设置字体类型*/
outtextxy(250,400,"EXIT=ESC ");/*显示文本*/
} 
void Close(void) 
{ 
closegraph(); 
}