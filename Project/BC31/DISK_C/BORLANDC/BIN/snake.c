#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h> /*���õĿ⺯��*/
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP 0x4800
#define ESC 0x011b/*�궨�����*/
#define N 200
int i,key;
int level;/*��Ϸ�ȼ�*/
int score=0;/*�÷�*/
int gamespeed;/*��Ϸ�ٶ�*/
struct Food
{
int x;/*ʳ��ĺ�����*/
int y;/*ʳ���������*/
int yes;/*�ж��Ƿ�Ҫ����ʳ��ı���*/
}food;/*ʳ��Ľṹ��*/
struct Snake
{
int x[N];
int y[N];
int node;/*�ߵĽ���*/
int direction;/*���ƶ�����*/
int life;/* �ߵ�����,0����,1����*/
}snake;/*�ߵĽṹ��*/
void Choicelevle(void);/*ѡ����Ϸ�ȼ�*/
void Init(void);/*ͼ������*/
void Close(void);/*ͼ�ν���*/
void DRAW(void);/*��Ϸ����*/
void GameOver(void);/*������Ϸ*/
void GamePlay(void);/*����Ϸ�������*/
void PrScore(void);/*����ɼ�*/
/*������*/
void main(void)
{
Init();/*ͼ������*/
Choicelevle();/*ѡ����Ϸ�ȼ�*/
DRAW();/*��Ϸ����*/
GamePlay();/*����Ϸ�������*/
Close();/*ͼ�ν���*/
}

/*ͼ������*/
void Init(void)
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"\\turboc2"); /*��ʼ��ͼ��ϵͳ*/
cleardevice(); /*���ͼ�ν���*/
}
/*ѡ����Ϸ�ȼ�*/
void Choicelevle(void)
{char name[20];setcolor(YELLOW);settextstyle(0,0,6);outtextxy(150,150,"Snake");setcolor(GREEN);settextstyle(0,0,1);outtextxy(200,250,"please put in your English name:");outtextxy(200,270,"Choice levle from 1-9.");outtextxy(300,320,"name:yangzilong");/*����������*/outtextxy(300,350,"number:0902060226");/*������ѧ��*/outtextxy(300,380,"class:computer science 0602");/*�����˰༶*/getch();printf("please putin your name:");gets(name);printf("please choice levle:");scanf("%d",&level);gamespeed=100000-400*level-300*level*level;if(level>9||level<1){cleardevice(); /*���ͼ�ν���*/setcolor(YELLOW); /*����������ɫ*/settextstyle(0,0,2); /*������������*/outtextxy(150,200,"level input error"); /*��ʾ�ı�*/getch();level=1;}
}
void DRAW(void)
{cleardevice(); /*����*/setcolor(2);setlinestyle(SOLID_LINE,0,THICK_WIDTH);/*��������*/rectangle(45,45,465,325);}
/*����Ϸ�������*/
void GamePlay(void)
{setcolor(5);setlinestyle(SOLID_LINE,0,THICK_WIDTH);/*��������*/randomize();/*�����������*/food.yes=1;/*1��ʾ��Ҫ������ʳ��,0��ʾ�Ѿ�����ʳ��*/snake.life=0;/*����*/snake.direction=1;/*��������*/snake.x[0]=320;snake.y[0]=240;/*��ͷ*/snake.x[1]=330;snake.y[1]=240; /*�ߵĵڶ���λ��*/snake.node=3;/*����*/PrScore();/*����÷�*/while(1)/*�����ظ�����Ϸ,ѹESC������*/{while(!kbhit())/*��û�а����������,���Լ��ƶ�����*/{if(food.yes==1)/*��Ҫ������ʳ��*/{food.x=rand()%360+70;food.y=rand()%250+60;while(food.x%10!=0)/*ʳ��������ֺ������ʳ���ܹ���������,�����ſ������߳Ե�*/food.x++;while(food.y%10!=0)food.y++;food.yes=0;/*��������ʳ����*/}
if(food.yes==0)/*��������ʳ���˾�Ҫ��ʾ*/
{
setcolor(GREEN);
rectangle(food.x,food.y,food.x+10,food.y-10);
}
for(i=snake.node-1;i>0;i--)/*�ߵ�ÿ��������ǰ�ƶ�*/
{
snake.x[i]=snake.x[i-1];
snake.y[i]=snake.y[i-1];
}
/*1,2,3,4��ʾ��,��,��,���ĸ�����,ͨ������������ƶ���ͷ*/
switch(snake.direction)
{
case 1: snake.x[0]+=10;break;
case 2: snake.x[0]-=10;break;
case 3: snake.y[0]-=10;break;
case 4: snake.y[0]+=10;break;
}
for(i=3;i<snake.node;i++)/*���ߵĵ��Ľڿ�ʼ�ж��Ƿ�ײ���Լ��ˣ���Ϊ��ͷΪ���ڣ������ڲ����ܹչ���*/
{
if(snake.x[i]==snake.x[0]&&snake.y[i]==snake.y[0])
{
GameOver();/*��ʾʧ��*/
snake.life=1; /*����*/
break;
}
}

/*�����ͷ����ǽ�ڣ���ͷ�Ӷ���ǽ����*/
if(snake.x[0]<50)
{snake.x[0]=450;/*�����ͷԽ����߽�,����ұ߽����*/snake.y[0]=snake.y[0];/*�����겻��*/for(i=snake.node-1;i>0;i--){snake.x[i]=snake.x[i-1];snake.y[i]=snake.y[i-1]; /*�ߵ�����������ǰ�ƽ�*/}
{
setfillstyle(SOLID_FILL,0); /*�������ģʽ����ɫ��0��ʾ��ɫ*/
bar(50,55,455,315);/*bar�Ǳ�ʾ���ķ�Χ�ĺ���*/
}
}
else
if(snake.x[0]>450)
{snake.x[0]=50;/*�����ͷԽ���ұ߽�,����ͷ����߽����*/snake.y[0]=snake.y[0];/*�����겻��*/for(i=snake.node-1;i>0;i--){snake.x[i]=snake.x[i-1];snake.y[i]=snake.y[i-1]; /*�ߵ�����������ǰ�ƽ�*/}
{
setfillstyle(SOLID_FILL,0); /*�������ģʽ����ɫ��0��ʾ��ɫ*/
bar(50,55,455,315);/*bar�Ǳ�ʾ���ķ�Χ�ĺ���*/
}
}
else
if(snake.y[0]<60)
{snake.y[0]=320;/*�����ͷԽ���ϱ߽�,����±߽����*/snake.x[0]=snake.x[0];/*�����겻��*/for(i=snake.node-1;i>0;i--){snake.x[i]=snake.x[i-1];snake.y[i]=snake.y[i-1]; /*�ߵ�����������ǰ�ƽ�*/}
{
setfillstyle(SOLID_FILL,0); /*�������ģʽ����ɫ��0��ʾ��ɫ*/
bar(50,55,455,315);/*bar�Ǳ�ʾ���ķ�Χ�ĺ���*/
}
}
else
if(snake.y[0]>320)
{snake.y[0]=60;/*�����ͷԽ���±߽�,����ϱ߽����*/snake.x[0]=snake.x[0];/*�����겻��*/for(i=snake.node-1;i>0;i--){snake.x[i]=snake.x[i-1];snake.y[i]=snake.y[i-1]; /*�ߵ�����������ǰ�ƽ�*/}
{
setfillstyle(SOLID_FILL,0); /*�������ģʽ����ɫ��0��ʾ��ɫ*/
bar(50,55,455,315);/*bar�Ǳ�ʾ���ķ�Χ�ĺ���*/
}
}
if(snake.life==1)/*���������������ѭ�������¿�ʼ*/
break;
if(snake.x[0]==food.x&&snake.y[0]==food.y)/*�Ե�ʳ���Ժ�*/
{
setcolor(0);/*�ѻ����ϵ�ʳ�ﶫ��ȥ��*/
rectangle(food.x,food.y,food.x+10,food.y-10); /*�õ�ǰ���ͺ���ɫ��һ����*/
snake.x[snake.node]=-20;snake.y[snake.node]=-20;
/*�µ�һ���ȷ��ڿ�������λ��,�´�ѭ����ȡǰһ�ڵ�λ��*/
snake.node++;/*�ߵ����峤һ��*/
food.yes=1;/*��������Ҫ�����µ�ʳ��*/
score+=10; /*ÿ�Ե�һʳ��,�÷��ۼ�10��*/
if(score%100==0)
{level++;gamespeed=100000-400*level-300*level*level;/*ÿ�Ե�10ʳ������һ��,�ٶȼӿ�*/PrScore();/*����µ÷�*/setcolor(YELLOW); /*����������ɫ*/settextstyle(0,0,4); /*������������*/outtextxy(150,200,"LEVEL UP"); /*��ʾ�ı�*/if(level==10){level=1,gamespeed=100000-400*level-300*level*level;}
delay(6000000); 
delay(6000000); 
delay(6000000); 
delay(6000000); 
delay(6000000);
delay(6000000); 
delay(6000000);
bar(50,55,455,315);/*bar�Ǳ�ʾ���ķ�Χ�ĺ���*/
}
PrScore();/*����µ÷�*/ 
} 
setcolor(4);/*������*/ 
for(i=0;i<snake.node;i++) 
rectangle(snake.x[i],snake.y[i],snake.x[i]+10, 
snake.y[i]-10); 
delay(gamespeed); /*������Ϸ�ٶ�*/
setcolor(0);
rectangle(snake.x[snake.node-1],snake.y[snake.node-1], 
snake.x[snake.node-1]+10,snake.y[snake.node-1]-10); 
} /*endwhile����kbhit��*/ /*�ú�ɫȥ���ߵĵ����һ��*/ 
if(snake.life==1)/*�������������ѭ��*/ 
break; 
key=bioskey(0);/*���հ���*/ 
if(key==ESC)/*��ESC���˳�*/ 
break; 
else 
if(key==UP&&snake.direction!=4) 
/*�ж��Ƿ����෴�ķ����ƶ�*/ 
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
/*��Ϸ����*/ 
void GameOver(void) 
{ 
cleardevice(); /*����*/
PrScore(); 
setcolor(RED); /*����������ɫ*/
settextstyle(0,0,4); /*������������*/
outtextxy(200,200,"GAME OVER"); /*��ʾ�ı�*/
getch(); 
} 
/*����ɼ�����Ϸ�ȼ�*/ 
void PrScore(void) 
{ 
char str1[20];/*�����ַ�������*/ 
setfillstyle(SOLID_FILL,0); 
bar(50,15,390,35); /*�����ο�*/
setcolor(6); /*�����ı���ɫ*/
settextstyle(0,0,2); /*����������ʾλ��*/
sprintf(str1,"score %d level %d",score,level);/*��ʾ��������*/
outtextxy(55,20,str1); 
setcolor(YELLOW); /*����������ɫ*/
settextstyle(0,0,2); /*������������*/
outtextxy(250,400,"EXIT=ESC ");/*��ʾ�ı�*/
} 
void Close(void) 
{ 
closegraph(); 
}