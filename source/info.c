#include"info.h"

/********************
�������Ҳ���Ϣ����ӡ�з��غ���Ϣ
lzzд��
********************/
void en_turn(){
	setfillstyle(SOLID_FILL,BLACK);
	bar(524,0,640,480);
	puthz(540,0,"�з��غ�",16,20,WHITE);
	setfillstyle(SOLID_FILL,RED);
	bar(524,21,640,23);
	puthz(535,28,"������",24,30,WHITE);
	puthz(550,60,"�ж�",24,30,WHITE);
}

/********************
�������Ҳ���Ϣ����ӡ�����غ���Ϣ
lzzд��
********************/
void my_turn(){
	setfillstyle(SOLID_FILL,BLACK);
	bar(524,0,640,480);
	puthz(540,0,"�ҵĻغ�",16,20,WHITE);
	setfillstyle(SOLID_FILL,RED);
	bar(525,21,640,23);
	puthz(539,28,"��ѡ��",24,30,WHITE);
	puthz(524,60,"Ҫ�鿴��",24,30,WHITE);
	puthz(554,92,"��λ",24,30,WHITE);
	setfillstyle(SOLID_FILL,GREEN);
	bar(528,448,636,474);
	puthz(542,454,"�����غ�",16,20,WHITE);
}

/********************
�������Ҳ���Ϣ����ӡĳһ��ս��λ��Ϣ
�β�num��ʾ����ñ����еĵڼ�����λ
�β�op��0��ʾ�Ǽ�����λ����1��ʾ�ǵз���λ
lzzд��
********************/
void info(struct unit x,int num,int op,struct unit my[]){
	setfillstyle(SOLID_FILL,BLACK);
	bar(524,0,640,480);
	puthz(540,0,"�ҵĻغ�",16,20,WHITE);
	setfillstyle(SOLID_FILL,RED);
	bar(525,21,640,23);
	if(op==0) puthz(524,28,"�ҷ���λ",24,30,WHITE);
	else puthz(524,28,"�з���λ",24,30,WHITE);
	if(op==0&&x.type==4) puthz(537,60,x.name,24,30,WHITE);//���䴬���ֳ�������
	else puthz(552,60,x.name,24,30,WHITE);//������λ���ֳ�2����
	
	puthz(525,93,"ʣ��Ѫ����",16,17,WHITE);
	gotoxy(77,7);
	printf("%d",x.hp[num]);
	
	puthz(525,126,"ʣ��ʯ�ͣ�",16,17,WHITE);
	gotoxy(77,9);
	printf("%d",x.oil[num]);
	
	puthz(525,157,"�ж�������",16,17,WHITE);
	gotoxy(77,11);
	printf("%d",x.max_move);
	
	puthz(525,190,"��̣�",16,17,WHITE);
	gotoxy(73,13);
	printf("%d",x.max_attack);
	
	puthz(525,221,"��������",16,17,WHITE);
	gotoxy(75,15);
	printf("%d",x.atk);
	
	if(x.type==4){
		puthz(525,252,"���ϵ�λ��",16,17,WHITE);
		if(x.port_type==0) puthz(605,252,"��",16,17,WHITE);
		else puthz(605,252,my[x.port_type].name,16,17,WHITE);
	}
	
	setfillstyle(SOLID_FILL,GREEN);
	bar(528,448,636,474);
	puthz(542,454,"�����غ�",16,20,WHITE);
	
	if(op==0){
		setfillstyle(SOLID_FILL,BLUE);
		bar(528,418,636,444);
		puthz(562,423,"�ƶ�",16,20,WHITE);
		
		if(x.type!=4&&x.type!=5){
			setfillstyle(SOLID_FILL,RED);
			bar(528,388,636,414);
			puthz(562,393,"����",16,20,WHITE);
		}
		
		if(x.type==4){
			setfillstyle(SOLID_FILL,RED);
			bar(528,388,636,414);
			puthz(532,393,"���ȴ��ϵ�λ",16,17,WHITE);
		}
	}
}