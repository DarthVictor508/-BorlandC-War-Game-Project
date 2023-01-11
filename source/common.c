#include "common.h"

/********************
用于获得两个单位之间的距离
lzz写的
********************/
int get_dis(struct unit a,struct unit b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}

/********************
用于打印地图（不清屏）
lzz写的
********************/
void print_map(int (*map_type)[13+3]){
	int i;
	int j;
	for(i=1;i<=13;i++){
		for(j=1;j<=9;j++){
			if(map_type[j][i]==0){
				setfillstyle(SOLID_FILL,GREEN);
				bar((i-1)*40+1,(j-1)*40+1,(i-1)*40+39,(j-1)*40+39);
			}
			else{
				setfillstyle(SOLID_FILL,BLUE);
				bar((i-1)*40+1,(j-1)*40+1,(i-1)*40+39,(j-1)*40+39);
			}
		}
	}
}

/********************
打印UI，包括头像和边框（不清屏）
lzz写的
********************/
void print_UI(){
	putbmp(0,361,"source\\picture\\head.bmp");
	setfillstyle(SOLID_FILL,RED);
	bar(0,360,120,362);
	bar(120,360,122,480);
	bar(120,380,520,382);
	bar(521,0,523,480);
}

/********************
用于初始化
形参从前往后依次是9*13地图上的土地类型（0是陆地，1是海洋），我方单位，敌方单位，我方单位数量，敌方单位数量
XXX写的
********************/
void init(int (*map_type)[13+3],struct unit my[],struct unit en[],int num_my,int num_en){
}
