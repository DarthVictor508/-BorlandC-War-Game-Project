#ifndef _COMMON_H
#define _COMMON_H

#include<stdio.h>
#include<dos.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<mouse.h>
#include<hz.h>
#include<putbmp.h>

struct unit{
	char name[10]; //战斗单位名称（中文）
	int type; //战斗单位类型，统一编码，比如坦克是0等等
	int num; //战斗单位编号，指在数组里的下标
	int hp; //剩余血量
	int oil; //剩余资源
	int x[25],y[25]; //位置
	int max_move; //最大移动距离
	int atk; //攻击力（打一次对面掉多少血）
};

int get_dis(struct unit a,struct unit b);
void print_map(int (*map_type)[13+3]);
void print_UI();
void init(int (*map_type)[13+3],struct unit my[],struct unit en[],int num_my,int num_en);
int get_block(int Moux,int MouY,int *x,int *y);

#endif
