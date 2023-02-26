#include"info.h"

/********************
用于在右侧信息栏打印敌方回合信息
lzz写的
********************/
void en_turn(){
	setfillstyle(SOLID_FILL,BLACK);
	bar(524,0,640,480);
	puthz(540,0,"敌方回合",16,20,WHITE);
	setfillstyle(SOLID_FILL,RED);
	bar(524,21,640,23);
	puthz(535,28,"您不能",24,30,WHITE);
	puthz(550,60,"行动",24,30,WHITE);
}

/********************
用于在右侧信息栏打印己方回合信息
lzz写的
********************/
void my_turn(){
	setfillstyle(SOLID_FILL,BLACK);
	bar(524,0,640,480);
	puthz(540,0,"我的回合",16,20,WHITE);
	setfillstyle(SOLID_FILL,RED);
	bar(525,21,640,23);
	puthz(539,28,"请选择",24,30,WHITE);
	puthz(524,60,"要查看的",24,30,WHITE);
	puthz(554,92,"单位",24,30,WHITE);
	setfillstyle(SOLID_FILL,GREEN);
	bar(528,448,636,474);
	puthz(542,454,"结束回合",16,20,WHITE);
}

/********************
用于在右侧信息栏打印某一作战单位信息
形参num表示输出该兵种中的第几个单位
形参op是0表示是己方单位，是1表示是敌方单位
形参butt表示是否打印下方按钮，1表示打印
lzz写的
********************/
void info(struct unit x,int num,int op,struct unit my[],int butt){
	setfillstyle(SOLID_FILL,BLACK);
	bar(524,0,640,480);
	puthz(540,0,"我的回合",16,20,WHITE);
	setfillstyle(SOLID_FILL,RED);
	bar(525,21,640,23);
	if(op==0) puthz(524,28,"我方单位",24,30,WHITE);
	else puthz(524,28,"敌方单位",24,30,WHITE);
	if(op==0&&(x.type==4||x.type==5)) puthz(537,60,x.name,24,30,WHITE);//运输船和支援兵名字长三个字
	else puthz(552,60,x.name,24,30,WHITE);//其他单位名字长2个字
	
	puthz(525,93,"剩余血量：",16,17,WHITE);
	gotoxy(77,7);
	printf("%d",x.hp[num]);
	
	puthz(525,126,"剩余石油：",16,17,WHITE);
	gotoxy(77,9);
	printf("%d",x.oil[num]);
	
	puthz(525,157,"行动能力：",16,17,WHITE);
	gotoxy(77,11);
	printf("%d",x.max_move);
	
	puthz(525,190,"射程：",16,17,WHITE);
	gotoxy(73,13);
	printf("%d",x.max_attack);
	
	puthz(525,221,"攻击力：",16,17,WHITE);
	gotoxy(75,15);
	printf("%d",x.atk);
	
	if(x.type==4){
		puthz(525,252,"船上单位：",16,17,WHITE);
		if(x.port_type[num]==0) puthz(605,252,"无",16,17,WHITE);
		else puthz(605,252,my[x.port_type[num]].name,16,17,WHITE);
	}
	
	if(butt){
		setfillstyle(SOLID_FILL,GREEN);
		bar(528,448,636,474);
		puthz(542,454,"结束回合",16,20,WHITE);
	}
	
	if(op==0&&butt){
		setfillstyle(SOLID_FILL,BLUE);
		bar(528,418,636,444);
		puthz(562,423,"移动",16,20,WHITE);
		
		if(x.type!=4&&x.type!=5){
			setfillstyle(SOLID_FILL,RED);
			bar(528,388,636,414);
			puthz(562,393,"攻击",16,20,WHITE);
		}
		
		if(x.type==4){
			setfillstyle(SOLID_FILL,RED);
			bar(528,388,636,414);
			puthz(532,393,"调度船上单位",16,17,WHITE);
		}
	}
}
