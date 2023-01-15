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
我方单位：士兵、坦克、飞机、运输船。类型：1，2，3，4。HP:100，500，250，400。攻击距离：40，80，120，0    资源：5000，200，500，300  移动距离：40，80，120，80  数量：20，6，15，5。 攻击力：100，500，400。
敌方单位：主城、炮台、城墙。类型：1、2、3。HP:3000，500，600。攻击距离:40,80,0  资源：5000，5000，5000 移动距离：0，0，0.  攻击力：100，200，0.
关于敌方单位初始化位置信息：x[],y[],数字依次为表格上从上到下从左到右的顺序，特别地，敌方主城位置坐标：en[1].x[0]，en[1].y[0]。 然后最上方炮台为1号，位置坐标：en[2].x[1],en[2].y[1]

lpc写的
********************/
void init(int(*map_type)[13 + 3], struct unit my[], struct unit en[]) {
	int i;

	 //地图类型
	map_type[1][1] = 0;    
	map_type[1][2] = 0;
	map_type[1][3] = 0;
	map_type[1][4] = 0;
	map_type[1][5] = 0;
	map_type[1][6] = 1;     
	map_type[1][7] = 1;
	map_type[1][8] = 1;
	map_type[1][9] = 1;
	map_type[1][10] = 1;
	map_type[1][11] = 1;
	map_type[1][12] = 1;
	map_type[1][13] = 1;
	map_type[2][1] = 0;
	map_type[2][2] = 0;
	map_type[2][3] = 0;
	map_type[2][4] = 1;
	map_type[2][5] = 1;
	map_type[2][6] = 1;
	map_type[2][7] = 1;
	map_type[2][8] = 1;
	map_type[2][9] = 0;
	map_type[2][10] = 0;
	map_type[2][11] = 1;
	map_type[2][12] = 1;
	map_type[2][13] = 1;
	map_type[3][1] = 0;
	map_type[3][2] = 0;
	map_type[3][3] = 0;
	map_type[3][4] = 1;
	map_type[3][5] = 1;
	map_type[3][6] = 1;
	map_type[3][7] = 0;
	map_type[3][8] = 0;
	map_type[3][9] = 0;
	map_type[3][10] = 0;
	map_type[3][11] = 0;
	map_type[3][12] = 1;
	map_type[3][13] = 1;
	map_type[4][1] = 0;
	map_type[4][2] = 0;
	map_type[4][3] = 0;
	map_type[4][4] = 0;
	map_type[4][5] = 1;
	map_type[4][6] = 1;
	map_type[4][7] = 0;
	map_type[4][8] = 0;
	map_type[4][9] = 0;
	map_type[4][10] = 0;
	map_type[4][11] = 0;
	map_type[4][12] = 1;
	map_type[4][13] = 1;
	map_type[5][1] = 0;
	map_type[5][2] = 0;
	map_type[5][3] = 0;
	map_type[5][4] = 1;
	map_type[5][5] = 1;
	map_type[5][6] = 1;
	map_type[5][7] = 0;
	map_type[5][8] = 0;
	map_type[5][9] = 0;
	map_type[5][10] = 0;
	map_type[5][11] = 0;
	map_type[5][12] = 1;
	map_type[5][13] = 1;
	map_type[6][1] = 0;
	map_type[6][2] = 0;
	map_type[6][3] = 0;
	map_type[6][4] = 0;
	map_type[6][5] = 1;
	map_type[6][6] = 1;
	map_type[6][7] = 0;
	map_type[6][8] = 0;
	map_type[6][9] = 0;
	map_type[6][10] = 0;
	map_type[6][11] = 0;
	map_type[6][12] = 1;
	map_type[6][13] = 1;
	map_type[7][1] = 0;
	map_type[7][2] = 0;
	map_type[7][3] = 0;
	map_type[7][4] = 1;
	map_type[7][5] = 1;
	map_type[7][6] = 1;
	map_type[7][7] = 0;
	map_type[7][8] = 0;
	map_type[7][9] = 0;
	map_type[7][10] = 0;
	map_type[7][11] = 0;
	map_type[7][12] = 1;
	map_type[7][13] = 1;
	map_type[8][1] = 0;
	map_type[8][2] = 0;
	map_type[8][3] = 0;
	map_type[8][4] = 1;
	map_type[8][5] = 1;
	map_type[8][6] = 1;
	map_type[8][7] = 1;
	map_type[8][8] = 1;
	map_type[8][9] = 0;
	map_type[8][10] = 0;
	map_type[8][11] = 1;
	map_type[8][12] = 1;
	map_type[8][13] = 1;
	map_type[9][1] = 0;
	map_type[9][2] = 0;
	map_type[9][3] = 0;
	map_type[9][4] = 0;
	map_type[9][5] = 0;
	map_type[9][6] = 1;
	map_type[9][7] = 1;
	map_type[9][8] = 1;
	map_type[9][9] = 1;
	map_type[9][10] = 1;
	map_type[9][11] = 1;
	map_type[9][12] = 1;
	map_type[9][13] = 1;


	//我方士兵所有信息
	my[1].name = "士兵";
	my[1].type = 1;
	my[1].num = 20;
	for (i = 1; i <= 20; i++) {
		my[1].hp[i] = 100;
		my[1].oil[i] = 2000;
	}
	my[1].atk = 100;
	my[1].max_move = 1;
	my[1].max_attack = 1;

	//我方坦克所有信息
	my[2].name = "坦克";
	my[2].type = 2;
	my[2].num = 6;
	for (i = 1; i <= 6; i++) {
		my[2].hp[i] = 500;
		my[2].oil[i] = 200;
	}
	my[2].atk = 500;
	my[2].max_move = 2;
	my[2].max_attack = 2;

	//我方飞机所有信息
	my[3].name = "飞机";
	my[3].type = 3;
	my[3].num = 15;
	for (i = 1; i <= 15; i++) {
		my[3].hp[i] = 250;
		my[3].oil[i] = 500;
	}
	my[3].atk = 400;
	my[3].max_move = 3;
	my[3].max_attack = 3;

	//我方运输船所有信息
	my[4].name = "运输船";
	my[4].type = 4;
	my[4].num = 5;
	for (i = 1; i <= 5; i++) {
		my[4].hp[i] = 400;
		my[4].oil[i] = 300;
	}
	my[4].atk = 0;
	my[4].max_move = 2;
	my[4].max_attack = 0;

	//我方支援兵所有信息
	my[5].name = "支援兵";
	my[5].type = 5;
	my[5].num = 10;
	for (i = 1; i <= 5; i++) {
		my[5].hp[i] = 100;
		my[5].oil[i] = 2000;
	}
	my[5].atk = 0;
	my[5].max_move = 2;
	my[5].max_attack = 0;	
	

	//敌方主城所有信息
	en[1].name = "主城";
	en[1].type = 1;
	en[1].hp[1] = 3000;
	en[1].num = 1;
	en[1].oil[1] = 5000;
	en[1].atk = 100;
	en[1].max_move = 0;
	en[1].max_attack = 1;
	en[1].x[1] = 320 + 5;   en[1].y[1] = 160 + 12;
	en[1].a[1] = 9;  en[1].b[1] = 5;

	//敌方炮台所有信息
	en[2].name = "炮台";
	en[2].type = 2;
	en[2].num = 14;
	for (i = 1; i <= 14; i++){
		en[2].hp[i] = 500;
		en[2].oil[i] = 5000;
	}
		en[2].atk=200;
		en[2].max_move=0;
		en[2].max_attack=2;
		en[2].x[1]=320+5; en[2].y[1]=40+12;
		en[2].x[2]=280+5;en[2].y[2]=80+12;     en[2].x[3]=320+5;en[2].y[3]=80+12;
		en[2].x[4]=240+5;en[2].y[4]=120+12;    en[2].x[5]=280+5;en[2].y[5]=120+12;  en[2].x[6]=320+5;en[2].y[6]=120+12;
		en[2].x[7]=280+5;en[2].y[7]=160+12;    en[2].x[8]=400+5;en[2].y[8]=160+12;
		en[2].x[9]=240+5;en[2].y[9]=200+12;    en[2].x[10]=280+5;en[2].y[10]=200+12;  en[2].x[11]=320+5;en[2].y[11]=200+12;
		en[2].x[12]=280+5;en[2].y[12]=240+12;  en[2].x[13]=320+5;en[2].y[13]=240+12;
		en[2].x[14]=320+5;en[2].y[14]=280+12;

		en[2].a[1] = 9; en[2].b[1] = 2;
		en[2].a[2] = 8; en[2].b[2] = 3;    en[2].a[3] = 9; en[2].b[3] = 3;         
		en[2].a[4] = 7; en[2].b[4] = 4;	   en[2].a[5] = 8; en[2].b[5] = 4;    en[2].a[6] = 9;   en[2].b[6] = 4;
		en[2].a[7] = 8; en[2].b[7] = 5;    en[2].a[8] = 9; en[2].b[8] = 5;
		en[2].a[9] = 7; en[2].b[9] = 6;    en[2].a[10] = 8; en[2].b[10] = 6;	en[2].a[11] = 9;   en[2].b[11] = 6;
		en[2].a[12] = 8; en[2].b[12] = 7;  en[2].a[13] = 9; en[2].b[13] = 7;
		en[2].a[14] = 9; en[2].b[14] = 8;  

	//敌方城墙所有信息
	en[3].name = "城墙";
	en[3].type=3;
	en[3].num=8;
	for (i = 1; i <= 8; i++) {
		en[3].hp[i] = 600;
		en[3].oil[i] = 5000;
	}
		en[3].atk=0;
		en[3].max_move=0;
		en[3].max_attack=0;
		en[3].x[1]=360+5;en[3].y[1]=80+12;  en[3].x[2]=400+5;en[3].y[2]=80+12;
		en[3].x[3]=360+5;en[3].y[3]=120+12;
		en[3].x[4]=240+5;en[3].y[4]=160+12; en[3].x[5]=360+5;en[3].y[5]=160+12;
		en[3].x[6]=360+5;en[3].y[6]=200+12;
		en[3].x[7]=360+5;en[3].y[7]=240+12; en[3].x[8]=400+5;en[3].y[8]=240+12;


		en[3].a[1] = 10; en[3].b[1] = 3; en[3].a[2] = 11; en[3].b[2] = 3;
		en[3].a[3] = 10; en[3].b[3] = 4;
		en[3].a[4] = 7; en[3].b[4] = 5; en[3].a[5] = 10; en[3].b[5] = 5;
		en[3].a[6] = 10; en[3].b[6] = 6;
		en[3].a[7] = 10; en[3].b[7] = 7; en[3].a[8] = 11; en[3].b[8] = 7;
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

/*******************
打印敌方单位
lpc写的
********************/
void  print_en(struct unit en[]) {
	int i;
	if (en[1].hp[1] > 0){
		puthz(en[1].x[1], en[1].y[1], en[1].name, 16, 17, RED);
	}			 //	打印敌方主城

	for (i = 1; i <= en[2].num; i++) {
		if (en[2].hp[i] > 0) {
			puthz(en[2].x[i], en[2].y[i], en[2].name, 16, 17, BLACK);
		}
	}           // 打印敌方炮台

	for (i = 1; i <= en[3].num; i++) {
		if (en[3].hp[i] > 0) {
			puthz(en[3].x[i], en[3].y[i], "城墙", 16, 17, BLACK);
		}
	}           //打印敌方城墙
}


