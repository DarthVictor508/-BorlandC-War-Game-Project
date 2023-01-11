#include "common.h"

int get_dis(struct unit a,struct unit b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}

void print_map(int (*map_type)[13+3]){//打印地图（不含清屏）
}
void print_UI(){//打印UI（头像、边框）（不含清屏）
}
void init(int (*map_type)[13+3],struct unit my[],struct unit en[],int num_my,int num_en){//初始化
	//从前往后依次是9*13地图上的土地类型（0是陆地，1是海洋），我方单位，敌方单位，我方单位数量，敌方单位数量
}