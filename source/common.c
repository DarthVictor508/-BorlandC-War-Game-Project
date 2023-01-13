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
我方单位：士兵、坦克、飞机、运输船。类型：1，2，3，4。HP:100，500，250，400。攻击距离：40，80，120，0    资源：5000，200，500，300  移动距离：40，80，120   数量：20，6，15，5。 攻击力：100，500，400。
敌方单位：主城、炮台、城墙。类型：1、2、3。HP:3000，500，600。攻击距离:40,80,0  资源：5000，5000，5000 移动距离：0，0，0.  攻击力：100，200，0.

lpc写的
********************/
void init(int(*map_type)[13 + 3], struct unit my[], struct unit en[], int *num_my, int *num_en) {

		map_type[1][6]=1;      //地图类型
		map_type[1][7]=1;
		map_type[1][8]=1;
		map_type[1][9]=1;
		map_type[1][10]=1;
		map_type[1][11]=1;
		map_type[1][12]=1;
		map_type[1][13]=1;
		map_type[2][4]=1;
		map_type[2][5]=1;
		map_type[2][6]=1;
		map_type[2][7]=1;
		map_type[2][8]=1;
		map_type[2][9]=0;
		map_type[2][10]=0;
		map_type[2][11]=1;
		map_type[2][12]=1;
		map_type[2][13]=1;
		map_type[3][4]=1;
		map_type[3][5]=1;
		map_type[3][6]=1;
		map_type[3][12]=1;
		map_type[3][13]=1;
		map_type[4][5]=1;
		map_type[4][6]=1;
		map_type[4][12]=1;
		map_type[4][13]=1;
		map_type[5][4]=1;
		map_type[5][5]=1;
		map_type[5][6]=1;
		map_type[5][12]=1;
		map_type[5][13]=1;
		map_type[6][5]=1;
		map_type[6][6]=1;
		map_type[6][12]=1;
		map_type[6][13]=1;
		map_type[7][4]=1;
		map_type[7][5]=1;
		map_type[7][6]=1;
		map_type[7][12]=1;
		map_type[7][13]=1;
		map_type[8][4]=1;
		map_type[8][5]=1;
		map_type[8][6]=1;
		map_type[8][7]=1;
		map_type[8][8]=1;
		map_type[8][11]=1;
		map_type[8][12]=1;
		map_type[8][13]=1;
		map_type[9][6]=1;
		map_type[9][7]=1;
		map_type[9][8]=1;
		map_type[9][9]=1;
		map_type[9][10]=1;
		map_type[9][11]=1;
		map_type[9][12]=1;
		map_type[9][13]=1;
		
		//我方士兵所有信息
		my[1].type=1;
		my[1].hp=100;
		my[1].num=20;
		my[1].oil=5000;
		my[1].atk=100;
		my[1].max_move=40;
		my[1].max_attack=40;

		//我方坦克所有信息
		my[2].type=2;
		my[2].hp=500;
		my[2].num=6;
		my[2].oil=200;
		my[2].atk=500;
		my[2].max_move=80;
		my[2].max_attack=80;

		//我方飞机所有信息
		my[3].type=3;
		my[3].hp=250;
		my[3].num=15;
		my[3].oil=500;
		my[3].atk=400;
		my[3].max_move=120;
		my[3].max_attack=120;
    
		//我方运输船所有信息
		my[4].type=4;
		my[4].hp=400;
		my[4].num=5;
		my[4].oil=300;
		my[4].atk=0;
		my[4].max_move=80;
		my[4].max_attack=0;

		//敌方主城所有信息
		en[1].type=1;
		en[1].hp=3000;
		en[1].num=1;
		en[1].oil=5000;
		en[1].atk=100;
		en[1].max_move=0;
		en[1].max_attack=40;

		//敌方炮台所有信息
		en[2].type=2;
		en[2].hp=500;
		en[2].num=14;
		en[2].oil=5000;
		en[2].atk=200;
		en[2].max_move=0;
		en[2].max_attack=80;

		//敌方城墙所有信息
		en[3].type=3;
		en[3].hp=600;
		en[3].num=7;
		en[3].oil=5000;
		en[3].atk=0;
		en[3].max_move=0;
		en[3].max_attack=0;
}		

/********************
用于根据鼠标的位置判断所在格子
其中形参中的x，y传格子坐标储存位置
返回值是0表示该格子上部，返回值是1表示该格子下部
lzz写的
********************/
int get_block(int MouX,int MouY,int *x,int *y){
	*x=MouX/40+1;
	*y=MouY/40+1;
	if(MouY%40>=1&&MouY%40<=20) return 0;
	return 1;
}
