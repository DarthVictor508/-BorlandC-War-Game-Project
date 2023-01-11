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
	char name[10];
	int type;
	int num;
	int hp;
	int oil;
	int x,y;
	int max_move;
	int atk;
};

int get_dis(struct unit a,struct unit b); //计算两个单位之间的距离
void print_map(int (*map_type)[13+3]);//打印地图（不含清屏）
void print_UI();//打印UI（头像、边框）（不含清屏）
void init(int (*map_type)[13+3],struct unit my[],struct unit en[],int num_my,int num_en);//初始化
//从前往后依次是9*13地图上的土地类型（0是陆地，1是海洋），我方单位，敌方单位，我方单位数量，敌方单位数量

#endif