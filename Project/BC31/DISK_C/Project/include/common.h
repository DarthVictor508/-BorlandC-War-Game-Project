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
	char *name; //ս����λ���ƣ����ģ�
	int type; //ս����λ���ͣ�ͳһ���룬����̹����0�ȵ�
	int num; //ս����λ��ţ�ָ����������±�
	int hp[20]; //ʣ��Ѫ��
	int oil[20]; //ʣ����Դ
	int x[20],y[20]; //����λ��
	int a[20],b[20];//��ͼλ��
	int moved[15],atked[15]; //��¼ĳ����λ���غ��Ƿ��ƶ���/������
	int max_move; //����ƶ�����
	int max_attack; //���������
	int atk; //����������һ�ζ��������Ѫ��
	//������һЩ�������䴬�Ĳ���
	int ported[15]; //��ʾ��λ�Ƿ����䣬0��ʾδ�����䣬1��ʾ�����䣬������ʱ�ڵ�ͼ�ϲ���ʾ
	int port_type[15]; //�����䴬���õ��Ĳ�������ʾ������ı���
	int port_num[15]; //�����䴬���õ��Ĳ�������ʾ�������ڸñ����еı��
};

int get_dis(struct unit a,struct unit b);
int mouse_in(int x,int y,int xx,int yy);
void print_map(int (*map_type)[13+3]);
void print_UI();
void init(int(*map_type)[13 + 3], struct unit my[], struct unit en[],int op);
int get_block(int Moux,int MouY,int *x,int *y);
void  print_en(struct unit en[]);
void  print_my(struct unit my[], int num_my);
void ending( struct unit my[], struct unit en[], int num_my,int num_en);


#endif