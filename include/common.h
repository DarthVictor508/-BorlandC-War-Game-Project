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
#include<string.h>

struct unit{
	char name[10]; //战斗单位名称（中文）
	int type; //战斗单位类型，统一编码，比如坦克是0等等
	int num; //战斗单位编号，指在数组里的下标
	int hp[25]; //剩余血量
	int oil[25]; //剩余资源
	int x[25],y[25]; //像素位置
	int a[25],b[25]://地图位置	
	int max_move; //最大移动距离
	int max_attack; //最大打击距离
	int atk; //攻击力（打一次对面掉多少血）
	//以下是一些关于运输船的参数
	int ported[25]; //表示单位是否被运输，0表示未被运输，1表示被运输，被运输时在地图上不显示
	int port_type; //仅运输船会用到的参数，表示运输物的兵种
	int port_num; //仅运输船会用到的参数，表示运输物在该兵种中的标号
};

int get_dis(struct unit a,struct unit b);
void print_map(int (*map_type)[13+3]);
void print_UI();
void init(int (*map_type)[13+3],struct unit my[],struct unit en[],int num_my,int num_en);
int get_block(int Moux,int MouY,int *x,int *y);

#endif
