#include "common.h"

/********************
���ڻ��������λ֮��ľ���
lzzд��
********************/
int get_dis(struct unit a, struct unit b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

/********************
�����ж�����Ƿ���ĳ��������
lzzд��
********************/
int mouse_in(int x,int y,int xx,int yy){
	return MouseX>=x&&MouseX<=xx&&MouseY>=y&&MouseY<=yy;
}

/********************
���ڽ�����ת��Ϊ�ַ���
lzzд��
********************/
void nts(int x, char* s) {
	int cnt = 0;
	int i;
	char temp;
	if (x == 0){
		s[0] = '0';
		cnt = 1;
	}
	while (x) {
		s[cnt++] = x % 10 + '0';
		x /= 10;
	}
	for (i = 0; i < cnt / 2; i++) {
		temp = s[i];
		s[i] = s[cnt - i - 1];
		s[cnt - i - 1] = temp;
	}
	s[cnt] = '\0';
	return s;
}

/********************
���ڴ�ӡ��ͼ����������
lzzд��
********************/
void print_map(int(*map_type)[13 + 3]) {
	int i;
	int j;
	setfillstyle(SOLID_FILL, BLACK);
	bar(0, 0, 519, 359);
	for (i = 1; i <= 13; i++) {
		for (j = 1; j <= 9; j++) {
			if (map_type[j][i] == 0) {
				setfillstyle(SOLID_FILL, GREEN);
				bar((i - 1) * 40 + 1, (j - 1) * 40 + 1, (i - 1) * 40 + 39, (j - 1) * 40 + 39);
			}
			if (map_type[j][i] == 1) {
				setfillstyle(SOLID_FILL, BLUE);
				bar((i - 1) * 40 + 1, (j - 1) * 40 + 1, (i - 1) * 40 + 39, (j - 1) * 40 + 39);
			}
		}
	}
}

/********************
��ӡUI������ͷ��ͱ߿򣨲�������
lzzд��
********************/
void print_UI() {
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	bar(0,0,640,480);
	putbmp(0, 361, "source\\picture\\head.bmp");
	setfillstyle(SOLID_FILL, RED);
	bar(0, 360, 120, 362);
	bar(120, 360, 122, 480);
	bar(120, 380, 520, 382);
	bar(521, 0, 523, 480);
}

/********************
���ڳ�ʼ��
�βδ�ǰ����������9*13��ͼ�ϵ��������ͣ�0��½�أ�1�Ǻ��󣩣��ҷ���λ���з���λ���ҷ���λ�������з���λ����
�ҷ���λ��ʿ����̹�ˡ��ɻ������䴬�����ͣ�1��2��3��4��HP:100��500��250��400���������룺40��80��120��0    ��Դ��5000��200��500��300  �ƶ����룺40��80��120��80  ������20��6��15��5�� ��������100��500��400��
�з���λ�����ǡ���̨����ǽ�����ͣ�1��2��3��HP:3000��500��600����������:40,80,0  ��Դ��5000��5000��5000 �ƶ����룺0��0��0.  ��������100��200��0.
���ڵз���λ��ʼ��λ����Ϣ��x[],y[],��������Ϊ����ϴ��ϵ��´����ҵ�˳���ر�أ��з�����λ�����꣺en[1].x[0]��en[1].y[0]�� Ȼ�����Ϸ���̨Ϊ1�ţ�λ�����꣺en[2].x[1],en[2].y[1]
lpcд��
********************/
void init(int(*map_type)[13 + 3], struct unit my[], struct unit en[]) {
	int i;

	//��ͼ����
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


	//�ҷ�ʿ��������Ϣ
	my[1].name = "ʿ��";
	my[1].type = 1;
	my[1].num = 6;
	for (i = 1; i <= my[1].num; i++) {
		my[1].hp[i] = 100;
		my[1].oil[i] = 2000;
		my[1].x[i] = 0;
		my[1].y[i] = 0;
		my[1].a[i] = 0;
		my[1].b[i] = 0;
		my[1].ported[i] = 0;
	}
	my[1].atk = 100;
	my[1].max_move = 1;
	my[1].max_attack = 1;

	//�ҷ�̹��������Ϣ
	my[2].name = "̹��";
	my[2].type = 2;
	my[2].num = 3;
	for (i = 1; i <= my[2].num; i++) {
		my[2].hp[i] = 500;
		my[2].oil[i] = 200;
		my[2].x[i] = 0;
		my[2].y[i] = 0;
		my[2].a[i] = 0;
		my[2].b[i] = 0;
		my[2].ported[i] = 0;
	}
	my[2].atk = 500;
	my[2].max_move = 2;
	my[2].max_attack = 2;

	//�ҷ��ɻ�������Ϣ
	my[3].name = "�ɻ�";
	my[3].type = 3;
	my[3].num = 3;
	for (i = 1; i <= my[3].num; i++) {
		my[3].hp[i] = 250;
		my[3].oil[i] = 500;
		my[3].x[i] = 0;
		my[3].y[i] = 0;
		my[3].a[i] = 0;
		my[3].b[i] = 0;
		my[3].ported[i] = 0;
	}
	my[3].atk = 400;
	my[3].max_move = 3;
	my[3].max_attack = 3;

	//�ҷ����䴬������Ϣ
	my[4].name = "���䴬";
	my[4].type = 4;
	my[4].num = 3;
	for (i = 1; i <= my[4].num; i++) {
		my[4].hp[i] = 400;
		my[4].oil[i] = 300;
		my[4].x[i] = 0;
		my[4].y[i] = 0;
		my[4].a[i] = 0;
		my[4].b[i] = 0;
		my[4].ported[i] = 0;
		my[4].port_type[i] = 0;
		my[4].port_num[i] = 0;
	}
	my[4].atk = 0;
	my[4].max_move = 2;
	my[4].max_attack = 0;

	//�ҷ�֧Ԯ��������Ϣ
	my[5].name = "֧Ԯ��";
	my[5].type = 5;
	my[5].num = 2;
	for (i = 1; i <= my[5].num; i++) {
		my[5].hp[i] = 100;
		my[5].oil[i] = 2000;
		my[5].x[i] = 0;
		my[5].y[i] = 0;
		my[5].a[i] = 0;
		my[5].b[i] = 0;
		my[5].ported[i] = 0;
	}
	my[5].atk = 0;
	my[5].max_move = 2;
	my[5].max_attack = 5; //�൱�ڿ�֧Ԯ��Χ


	//�з�����������Ϣ
	en[1].name = "����";
	en[1].type = 1;
	en[1].hp[1] = 2000;
	en[1].num = 1;
	en[1].oil[1] = 5000;
	en[1].atk = 100;
	en[1].max_move = 0;
	en[1].max_attack = 1;
	en[1].ported[1] = 0;
	en[1].x[1] = 320 + 5;
	en[1].y[1] = 170 + 12;
	en[1].a[1] = 9;
	en[1].b[1] = 5;

	//�з���̨������Ϣ
	en[2].name = "��̨";
	en[2].type = 2;
	en[2].num = 12;
	for (i = 1; i <= en[2].num; i++) {
		en[2].hp[i] = 500;
		en[2].oil[i] = 5000;
		en[2].ported[i] = 0;
	}
	en[2].atk = 200;
	en[2].max_move = 0;
	en[2].max_attack = 2;

	//��̨����λ��
	en[2].x[1] = 280 + 5; en[2].y[1] = 80 + 20;
	en[2].x[2] = 320 + 5; en[2].y[2] = 80 + 20;
	en[2].x[3] = 280 + 5; en[2].y[3] = 120 + 20;
	en[2].x[4] = 320 + 5; en[2].y[4] = 120 + 20;
	en[2].x[5] = 360 + 5; en[2].y[5] = 120 + 20;
	en[2].x[6] = 280 + 5; en[2].y[6] = 160 + 20;
	en[2].x[7] = 360 + 5; en[2].y[7] = 160 + 20;
	en[2].x[8] = 280 + 5; en[2].y[8] = 200 + 20;
	en[2].x[9] = 320 + 5; en[2].y[9] = 200 + 20;
	en[2].x[10] = 360 + 5; en[2].y[10] = 200 + 20;
	en[2].x[11] = 280 + 5; en[2].y[11] = 240 + 20;	   
	en[2].x[12] = 320 + 5; en[2].y[12] = 240 + 20;

	//��̨��ͼ����λ��
	en[2].a[1] = 8; en[2].b[1] = 3;
	en[2].a[2] = 9; en[2].b[2] = 3;
	en[2].a[3] = 8; en[2].b[3] = 4;
	en[2].a[4] = 9; en[2].b[4] = 4;	   
	en[2].a[5] = 10; en[2].b[5] = 4;
	en[2].a[6] = 8; en[2].b[6] = 5;	                                       
	en[2].a[7] = 10; en[2].b[7] = 5;
	en[2].a[8] = 8; en[2].b[8] = 6;	   
	en[2].a[9] = 9; en[2].b[9] = 6;     
	en[2].a[10] = 10; en[2].b[10] = 6;
	en[2].a[11] = 8; en[2].b[11] = 7;	
	en[2].a[12] = 9; en[2].b[12] = 7;

	//�з���ǽ������Ϣ
	en[3].name = "��ǽ";
	en[3].type = 3;
	en[3].num = 4;
	for (i = 1; i <= en[3].num; i++) {
		en[3].hp[i] = 600;
		en[3].oil[i] = 5000;
	}
	en[3].atk = 0;
	en[3].max_move = 0;
	en[3].max_attack = 0;

	//��ǽ��������
	en[3].x[1] = 360 + 5; en[3].y[1] = 80 + 20;
	en[3].x[2] = 240 + 5; en[3].y[2] = 160 + 20;   	
	en[3].x[3] = 400 + 5; en[3].y[3] = 160 + 20;
	en[3].x[4] = 360 + 5; en[3].y[4] = 240 + 20;

	//��ǽ��������
	en[3].a[1] = 10; 
	en[3].b[1] = 3;
	en[3].a[2] = 7; 
	en[3].b[2] = 5;	
	en[3].a[3] = 11; 
	en[3].b[3] = 5;
	en[3].a[4] = 10; 
	en[3].b[4] = 7;

	/*//�з��Ѿ���Ϣ
	en[4].name = "�Ѿ�";
	en[4].type = 4;
	en[4].num = 6;
	for (i = 1; i <= en[4].num; i++) {
		en[4].hp[i] = 300;
		en[4].oil[i] = 1000;
	}
	en[4].atk = 200;
	en[4].max_move = 2;
	en[4].max_attack = 2;

	//�Ѿ���������
	en[4].x[1] = 320 + 5; en[4].y[1] = 40 + 20;   en[4].x[2] = 360 + 5;  en[4].y[2] = 40 + 20;
	en[4].x[3] = 240 + 5; en[4].y[3] = 80 + 20;
	en[4].x[4] = 240 + 5; en[4].y[4] = 240 + 20;
	en[4].x[5] = 320 + 5; en[4].y[5] = 280 + 20;  en[4].x[6] = 360 + 5; en[4].y[6] = 280 + 20;

	//�Ѿ���������
	en[4].a[1] = 9; en[4].b[1] = 2;   en[4].a[2] = 10;  en[4].b[2] = 2;
	en[4].a[3] = 7; en[4].b[3] = 3;
	en[4].a[4] = 7; en[4].b[4] = 7;
	en[4].a[5] = 9; en[4].b[5] = 8;  en[4].a[6] = 10; en[4].b[6] = 8;*/

	//������Ϣ
	en[5].name = "����";
	en[5].type = 5;
	en[5].num = 4;
	for (i = 1; i <= en[5].num; i++) {
		en[5].hp[i] = 600;
	}
	en[5].atk = 500;

	//������������
	en[5].x[1] = 240 + 5; en[5].y[1] = 120 + 20;      
	en[5].x[2] = 400 + 5; en[5].y[2] = 120 + 20;
	en[5].x[3] = 240 + 5; en[5].y[3] = 200 + 20;      
	en[5].x[4] = 400 + 5; en[5].y[4] = 200 + 20;

	//��ͼ��������
	en[5].a[1] = 7; 
	en[5].b[1] = 4; 
	en[5].a[2] = 11; 
	en[5].b[2] = 4;
	en[5].a[3] = 7; 
	en[5].b[3] = 6; 
	en[5].a[4] = 11; 
	en[5].b[4] = 6;


}

/********************
���ڸ�������λ���ж����ڸ���
�����β��е�x��y���������괢��λ��
����ֵ��0��ʾ�ø����ϲ�������ֵ��1��ʾ�ø����²�
lzzд��
********************/
int get_block(int MouX, int MouY, int* x, int* y) {
	*x = MouX / 40 + 1;
	*y = MouY / 40 + 1;
	if (MouY % 40 >= 1 && MouY % 40 <= 20) return 0;
	return 1;
}

/*******************
��ӡ�з���λ
lpcд��
********************/
void  print_en(struct unit en[]) {
	int i;
	if (en[1].hp[1] > 0) {
		puthz(en[1].x[1], en[1].y[1], en[1].name, 16, 17, RED);
	}			 //	��ӡ�з�����
	for (i = 1; i <= en[2].num; i++) {
		if (en[2].hp[i] > 0) {
			puthz(en[2].x[i], en[2].y[i], en[2].name, 16, 17, BLACK);
		}
	}           // ��ӡ�з���̨

	for (i = 1; i <= en[3].num; i++) {
		if (en[3].hp[i] > 0) {
			puthz(en[3].x[i], en[3].y[i], en[3].name, 16, 17, BLACK);
		}
	}           //��ӡ�з���ǽ

	/*for (i = 1; i <= en[4].num; i++) {
		if (en[4].hp[i] > 0) {
			puthz(en[4].x[i], en[4].y[i], en[4].name, 16, 17, BLACK);
		}
	}   */        //��ӡ�з��Ѿ�

}

/*******************
��ӡ�ҷ���λ
lpcд��
********************/
void  print_my(struct unit my[], int num_my) {
	int i, j;
	for (i = 1; i <= num_my; i++) {
		for (j = 1; j <= my[i].num; j++) {
			if (my[i].hp[j] <= 0 || my[i].oil[j] <= 0) continue;
			if (my[i].ported[j]) continue;
			if (my[i].type != 4 && my[i].type != 5) puthz(my[i].x[j], my[i].y[j], my[i].name, 16, 17, WHITE);
			if (my[i].type == 4) puthz(my[i].x[j], my[i].y[j], "����", 16, 17, WHITE);
			if (my[i].type == 5) puthz(my[i].x[j], my[i].y[j], "֧Ԯ", 16, 17, WHITE);
		}
	}
}


/*******************
�̳̲о�
lpcд��
********************/
void ending( struct unit my[], struct unit en[], int num_my,int num_en) {
	int i, j;
	//ȥ���ҷ����൥λ
	for (i = 1; i <= my[1].num; i++) {    
		my[1].hp[i] = 0;
		my[1].oil[i] = 1000;
	}
	for (i = 1; i <= my[2].num; i++) {
		my[2].hp[i] = 0;
		my[2].oil[i] = 2000;
	}
	for (i = 1; i <= my[3].num; i++) {
		my[3].hp[i] = 0;
		my[3].oil[i] = 5000;
	}
	for (i = 1; i <= my[4].num; i++) {
		my[4].hp[i] = 0;
		my[4].oil[i] = 500;
	}
	for (i = 1; i <= my[5].num; i++) {
		my[5].hp[i] = 0;
		my[5].oil[i] = 500;
	}

	
	//ȥ���з����൥λ
	for (i = 1; i <= en[2].num; i++) {    
		en[2].hp[i] = 0;
		en[2].oil[i] = 5000;
	}
	for (i = 1; i <= en[3].num; i++) {    
		en[3].hp[i] = 0;
		en[3].oil[i] = 5000;
	}
	for (i = 1; i <= en[4].num; i++) {
		en[4].hp[i] = 0;
		en[4].oil[i] = 5000;
	}
	for (i = 1; i <= en[5].num; i++) {
		en[5].hp[i] = 0;
		en[5].oil[i] = 5000;
	}

	my[3].hp[1] = 100;
	my[2].hp[1] = 100;
	my[1].hp[1] = 100; 

	en[1].hp[1] = 200;
	en[2].hp[3] = 100;
	en[2].hp[5] = 100;
	en[2].hp[8] = 100;
	//�ɻ�����
	my[3].a[1] = 9;  
	my[3].b[1] = 3;    
	my[3].x[1] = (my[3].a[1] - 1) * 40 + 2;   
	my[3].y[1] = (my[3].b[1] - 1) * 40 + 2;
	//̹������
	my[2].a[1] = 9;  
	my[2].b[1] = 4;    
	my[2].x[1] = (my[2].a[1] - 1) * 40 + 2;   
	my[2].y[1] = (my[2].b[1] - 1) * 40 + 22;
	//ʿ������
	my[1].a[1] = 7;  
	my[1].b[1] = 5;    
	my[1].x[1] = (my[1].a[1] - 1) * 40 + 2;   
	my[1].y[1] = (my[1].b[1] - 1) * 40 + 22;
	//3����̨
	en[2].a[3] = 8; 
	en[2].b[3] = 4;
	en[2].x[3] = 280 + 5; 
	en[2].y[3] = 120 + 20;     
	//5����̨
	en[2].a[5] = 10; 
	en[2].b[5] = 4;
	en[2].x[5] = 360 + 5; 
	en[2].y[5] = 120 + 20;    
	//8����̨
	en[2].a[8] = 8; 
	en[2].b[8] = 6;                 
	en[2].x[8] = 280 + 5; 
	en[2].y[8] = 200 + 20;


}
