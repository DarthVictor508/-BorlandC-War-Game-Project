#include "welcome.h"

/********************
����չʾ��ʼ����
lzzд��
********************/
int welcome(char *s){
	int cnt=0,now=235;
	char temp[5];
	int now_loc=0;
	
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,640,480);
	puthz(195+15,300+5,"�ᵺ����",48,60,RED);
	putbmp(195,0,"source\\picture\\logo.bmp");
	setfillstyle(SOLID_FILL,BLUE);
	bar(240,375,240+40*4,375+40);
	puthz(240+5,375+5,"��ʼ��Ϸ",32,40,BLACK);
	clrmous(MouseX,MouseY);
	delay(100);
	while(1){
		if(mouse_in(240,375,240+40*4,375+40)&&now_loc==0){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=1;
			setfillstyle(SOLID_FILL,LIGHTBLUE);
			bar(240,375,240+40*4,375+40);
			puthz(240+5,375+5,"��ʼ��Ϸ",32,40,BLACK);
		}
		if((!mouse_in(240,375,240+40*4,375+40))&&now_loc==1){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=0;
			setfillstyle(SOLID_FILL,BLUE);
			bar(240,375,240+40*4,375+40);
			puthz(240+5,375+5,"��ʼ��Ϸ",32,40,BLACK);
		}
		newmouse(&MouseX,&MouseY,&press);
		mouse(MouseX,MouseY);
		if(mouse_press(240,375,240+40*4,375+40)==1){
			delay(100);
			break;
		}
	}
	
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,640,480);
	putbmp(110,0,"source\\picture\\ougen3.bmp");
	puthz(10,360,"������齢",32,40,BLACK);
	puthz(20,405,"�ţ������������ָ�ӹ���",24,30,BLACK);
	puthz(495,455,"������⴦����",16,18,BLACK);
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		mouse(MouseX,MouseY);
		if(mouse_press(0,0,640,480)==1){
			delay(100);
			break;
		}
	}
	
	clrmous(MouseX,MouseY);
	delay(100);
	bar(0,360,640,480);
	puthz(10,360,"ŷ��",32,40,BLACK);
	puthz(20,405,"��ã�����������齢ŷ����",24,30,BLACK);
	puthz(495,455,"������⴦����",16,18,BLACK);
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		mouse(MouseX,MouseY);
		if(mouse_press(0,0,640,480)==1){
			delay(100);
			break;
		}
	}
	
	clrmous(MouseX,MouseY);
	delay(100);
	bar(0,405,640,480);
	puthz(20,405,"�������Ķᵺ��ս�Ͱ�������ָ���ˡ�",24,30,BLACK);
	puthz(495,455,"������⴦����",16,18,BLACK);
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		mouse(MouseX,MouseY);
		if(mouse_press(0,0,640,480)==1){
			delay(100);
			break;
		}
	}
	
	clrmous(MouseX,MouseY);
	delay(100);
	bar(0,405,640,480);
	puthz(20,405,"��ô�������ȸ��������������",24,30,BLACK);
	puthz(495,455,"������⴦����",16,18,BLACK);
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		mouse(MouseX,MouseY);
		if(mouse_press(0,0,640,480)==1){
			delay(100);
			break;
		}
	}
	
	if(mouse_in(230,380,620,405)) now_loc=1;
	else now_loc=0;
	if(now_loc) MouseS=2;
	clrmous(MouseX,MouseY);
	delay(100);
	bar(0,360,640,480);
	puthz(20,380,"����������֣�",24,30,BLACK);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(230,380,620,405);
	while(1){
		if(mouse_in(230,380,620,405)&&now_loc==0){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=1;
			MouseS=2;
		}
		if((!mouse_in(230,380,620,405))&&now_loc==1){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=0;
			MouseS=0;
		}
		newmouse(&MouseX,&MouseY,&press);
		mouse(MouseX,MouseY);
		if(mouse_press(230,380,620,465)==1){
			MouseS=0;
			delay(100);
			break;
		}
	}
	
	while(kbhit()){
		getch();
	}
	clrmous(MouseX,MouseY);
	delay(100);
	setfillstyle(SOLID_FILL,BLACK);
	bar(230,380,620,405);
	puthz(230,407,"��������ֲ��ܳ���ʮ����ַ�Ŷ��",16,18,BLACK);
	setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    settextjustify(LEFT_TEXT, TOP_TEXT);
	while(1){
		s[cnt++]=getch();
		if(s[cnt-1]=='\r'){
			s[cnt-1]='\0';
			break;
		}
		if(s[cnt-1]=='\b'){
			if(cnt>=2){
				cnt-=2;
				bar(now-15,380,now,405);
				now-=15;
			}
			else cnt--;
		}
		else if(cnt<=15){
			temp[0]=s[cnt-1];
			temp[1]='\0';
			outtextxy(now,385,temp);
			now+=15;
		}
		else cnt--;
	}
	
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,360,640,480);
	puthz(10,360,"ŷ��",32,40,BLACK);
	if(!exist(s)) puthz(20,405,"����Ȥ�����֡��Ҽ�ס�ˡ�",24,30,BLACK);
	else puthz(20,405,"Ŷ��ԭ�����㰡����ӭ������",24,30,BLACK);
	puthz(495,455,"������⴦����",16,18,BLACK);
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		mouse(MouseX,MouseY);
		if(mouse_press(0,0,640,480)==1){
			delay(100);
			break;
		}
	}
	
	if(mouse_in(20,440,185,465)) now_loc=1;
	else if(mouse_in(195,440,360,465)) now_loc=2;
	else now_loc=0;
	clrmous(MouseX,MouseY);
	delay(100);
	bar(0,405,640,480);
	puthz(20,405,"������������Ҫ�ҽ̸�������ָ��ս����",24,30,BLACK);
	setfillstyle(SOLID_FILL,BLUE);
	bar(20,440,185,465);
	puthz(20+5,440+5,"�ǵģ�����Ҫ�̳�",16,20,WHITE);
	setfillstyle(SOLID_FILL,RED);
	bar(195,440,360,465);
	puthz(195+5,440+5,"����Ҫ�ˣ�лл��",16,20,WHITE);
	while(1){
		if(mouse_in(20,440,185,465)&&now_loc!=1){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=1;
			setfillstyle(SOLID_FILL,LIGHTBLUE);
			bar(20,440,185,465);
			puthz(20+5,440+5,"�ǵģ�����Ҫ�̳�",16,20,WHITE);
		}
		if(mouse_in(195,440,360,465)&&now_loc!=2){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=2;
			setfillstyle(SOLID_FILL,LIGHTRED);
			bar(195,440,360,465);
			puthz(195+5,440+5,"����Ҫ�ˣ�лл��",16,20,WHITE);
		}
		if((!mouse_in(20,440,185,465))&&(!mouse_in(195,440,360,465))&&now_loc!=0){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=0;
			setfillstyle(SOLID_FILL,BLUE);
			bar(20,440,185,465);
			puthz(20+5,440+5,"�ǵģ�����Ҫ�̳�",16,20,WHITE);
			setfillstyle(SOLID_FILL,RED);
			bar(195,440,360,465);
			puthz(195+5,440+5,"����Ҫ�ˣ�лл��",16,20,WHITE);
		}
		newmouse(&MouseX,&MouseY,&press);
		mouse(MouseX,MouseY);
		if(mouse_press(20,440,185,465)==1){
			delay(100);
			cleardevice();
			return 1;
		}
		if(mouse_press(195,440,360,465)==1){
			delay(100);
			cleardevice();
			return 0;
		}
	}
}


/********************
�����ҷ���λ
lzzд��
********************/
void place(int(*map_type)[13+3], struct unit my[],struct unit en[],int num_my,int num_en){
	int i,j,k,l,x,y,half,judge;
	for(i=1;i<=num_my;i++){
		info(my[i],1,0,my,0);
		save_bk_mou(MouseX,MouseY);
		for(j=1;j<=my[i].num;j++){
			setfillstyle(SOLID_FILL,BLACK);
			bar(123,383,519,480);
			puthz(128,388,"���㲿���ҷ�",16,18,WHITE);
			puthz(236,388,my[i].name,16,18,WHITE);
			bar(524,275,640,315);
			puthz(528,285,"ʣ��",16,18,WHITE);
			puthz(586,285,"����λ",16,18,WHITE);
			puthz(555,305,"������",16,18,WHITE);
			gotoxy(72,19);
			printf("%d",my[i].num-j+1);
			while(1){
				clrmous(MouseX,MouseY);
				while(1){
					newmouse(&MouseX,&MouseY,&press);
					mouse(MouseX,MouseY);
					if(mouse_press(1,1,520,360)==1){
						half=get_block(MouseX,MouseY,&x,&y);
						delay(100);
						break;
					}
				}
				judge=1;
				if(my[i].type!=3&&my[i].type!=4&&map_type[y][x]==1){
					judge=0;
					setfillstyle(SOLID_FILL,BLACK);
					bar(123,383,519,480);
					puthz(128,388,"�㲻�ܽ�½����ս��λ�����ں���",16,18,WHITE);
				}
				if(my[i].type!=3&&my[i].type==4&&map_type[y][x]==0){
					judge=0;
					setfillstyle(SOLID_FILL,BLACK);
					bar(123,383,519,480);
					puthz(128,388,"�㲻�ܽ�������ս��λ������½����",16,18,WHITE);
				}
				if(my[i].type!=3){
					for(k=1;k<=num_my;k++){
						if(my[k].type==3) continue;
						for(l=1;l<=my[k].num;l++){
							if(my[k].a[l]==x&&my[k].b[l]==y){
								judge=0;
								setfillstyle(SOLID_FILL,BLACK);
								bar(123,383,519,480);
								puthz(128,388,"��λ���ѱ�ռ��",16,18,WHITE);
								break;
							}
						}	
						if(!judge) break;
					}
					for(k=1;k<=num_en;k++){
						for(l=1;l<=en[k].num;l++){
							if(en[k].type==5) continue;
							if(en[k].a[l]==x&&en[k].b[l]==y){
								judge=0;
								setfillstyle(SOLID_FILL,BLACK);
								bar(123,383,519,480);
								puthz(128,388,"��λ���ѱ�ռ��",16,18,WHITE);
								break;
							}
						}
						if(!judge) break;
					}
				}
				else{
					for(k=1;k<=my[3].num;k++){
						if(my[3].a[k]==x&&my[3].b[k]==y){
							judge=0;
							setfillstyle(SOLID_FILL,BLACK);
							bar(123,383,519,480);
							puthz(128,388,"��λ���ѱ�ռ��",16,18,WHITE);
							break;
						}
					}	
				}
				if(judge){
					my[i].a[j]=x;
					my[i].b[j]=y;
					my[i].x[j]=(x-1)*40+2;
					my[i].y[j]=(y-1)*40+(my[i].type==3?2:22);
					break;
				}
			}
			clrmous(MouseX,MouseY);
			if(my[i].type!=4&&my[i].type!=5) puthz(my[i].x[j],my[i].y[j],my[i].name,16,17,WHITE);
			if(my[i].type==4) puthz(my[i].x[j],my[i].y[j],"����",16,17,WHITE);
			if(my[i].type==5) puthz(my[i].x[j],my[i].y[j],"֧Ԯ",16,17,WHITE);
			save_bk_mou(MouseX,MouseY);
		}
	}
}

/********************
������ʾ�̳�
lpcд��
********************/
void teach(int(*map_type)[13 + 3], struct unit my[], struct unit en[], int num_my, int num_en) {
	int i, j;
	cleardevice();
	clrmous(MouseX, MouseY);
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	bar(0, 0, 640, 480);
	print_UI();
	print_map(map_type);
	print_en(en);
	setfillstyle(SOLID_FILL, BLACK);



	bar(123, 383, 519, 480); //����1
	puthz(128, 388, "��������Ϊ�������Ϸ�淨", 16, 18, WHITE);
	puthz(374, 440, "������⴦����", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			delay(100);
			break;
		}
	};


	clrmous(MouseX, MouseY); //����2
	delay(100);
	setfillstyle(SOLID_FILL, BLACK);
	bar(123, 383, 519, 480);  
	puthz(128, 388, "���ȣ�����Բ����ҷ���λ�ĳ�ʼλ��", 16, 18, WHITE);
	puthz(374, 440, "������⴦����", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			delay(100);
			break;
		}
	}
	
	
	clrmous(MouseX, MouseY);
	delay(100);
	setfillstyle(SOLID_FILL, BLACK);
	bar(123, 383, 519, 480);
	puthz(128, 388, "��Ҫע����ǣ���ս����ÿ����ս��λ����Ҫ����", 16, 18, WHITE);
	puthz(128, 405, "�������棬ÿ�غϽ���ʱÿ���ҷ���ս��λ������", 16, 18, WHITE);
	puthz(128, 422, "��һ�����ʣ����ʱ�������ʱ��ս��λҲ������", 16, 18, WHITE);
	puthz(374, 440, "������⴦����", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			delay(100);
			break;
		}
	}
	
	
	clrmous(MouseX, MouseY);
	delay(100);
	setfillstyle(SOLID_FILL, BLACK);
	bar(123, 383, 519, 480);
	puthz(128, 388, "�����Ǹ�����ڱ��ϵ�֧Ԯ����Ϊһ����Χ�ڵ���", 16, 18, WHITE);
	puthz(128, 405, "ս��λ�������ʡ����ԣ�����Ҫע��֧Ԯ���Ĵ���", 16, 18, WHITE);
	puthz(128, 422, "�ڷ�", 16, 18, WHITE);
	puthz(374, 440, "������⴦����", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			delay(100);
			break;
		}
	}
	
	
	clrmous(MouseX, MouseY);
	delay(100);
	setfillstyle(SOLID_FILL, BLACK);
	bar(123, 383, 519, 480);
	puthz(128, 388, "Ŷ�����ˣ����ǽӵ��鱨˵������ĳЩλ�ðڷ���", 16, 18, WHITE);
	puthz(128, 405, "���ס����ڵ�ͼ�Ͽ��������ǣ������Ǿ������", 16, 18, WHITE);
	puthz(128, 422, "�������½�ص�λ����ȥ��ʱ��ը��һ�£�С�ĵ�", 16, 18, WHITE);
	puthz(374, 440, "������⴦����", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			delay(100);
			break;
		}
	}
	
	
	clrmous(MouseX, MouseY);
	delay(100);
	setfillstyle(SOLID_FILL, BLACK);
	bar(123, 383, 519, 480);
	puthz(128, 388, "���ڣ���ʼ������ı�����", 16, 18, WHITE);
	puthz(374, 440, "������⴦����", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			delay(100);
			break;
		}
	}
	clrmous(MouseX, MouseY);
	delay(100);
	place(map_type, my, en, num_my, num_en);
	clrmous(MouseX, MouseY);
	delay(100);


	                                      
	setfillstyle(SOLID_FILL, BLACK);//����3
	bar(123, 383, 519, 480);
	puthz(128, 388, "�������������ҷ��غϣ�ѡ�е�λ�������½Ƕ�", 16, 18, WHITE);
	puthz(128, 405, "Ӧ�İ�ť������Խ����ƶ��ҷ���λ���Եз���λ", 16, 18, WHITE);
	puthz(128, 422, "���������������غϵȲ���", 16, 18, WHITE);
	puthz(374, 440, "������⴦����", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			delay(100);
			break;
		}
	}
	
	
	setfillstyle(SOLID_FILL, BLACK);
	bar(123, 383, 519, 480);
	puthz(128, 388, "��һ���غ��У����һ����ս��λֻ�ܹ���һ", 16, 18, WHITE);
	puthz(128, 405, "�Σ��ƶ�һ��", 16, 18, WHITE);
	puthz(374, 440, "������⴦����", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			delay(100);
			break;
		}
	}
	
	
	clrmous(MouseX, MouseY);
	delay(100);
	setfillstyle(SOLID_FILL, BLACK);
	bar(123, 383, 519, 480);
	puthz(128, 388, "���ǵ�ʱ��ܽ��ţ����������û���ڶ�ʮ�غ���", 16, 18, WHITE);
	puthz(128, 405, "���µз������ǣ�Ҳ������Ϊ����ʧ��", 16, 18, WHITE);
	puthz(374, 440, "������⴦����", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			delay(100);
			break;
		}
	}
	
	
	clrmous(MouseX, MouseY);
	delay(100);
	setfillstyle(SOLID_FILL, BLACK);
	bar(123, 383, 519, 480);
	puthz(128, 388, "���ڣ���ʼ������ı�����", 16, 18, WHITE);
	puthz(374, 440, "������⴦����", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			delay(100);
			break;
		}
	}
	myturn(map_type, my, en, num_my, num_en);
	clrmous(MouseX, MouseY);
	delay(100);

	                                     
	setfillstyle(SOLID_FILL, BLACK);//����4
	bar(123, 383, 519, 480);
	puthz(128, 388, "������������з��غϣ��㽫�޷����в���", 16, 18, WHITE);
	puthz(374, 440, "������⴦����", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			delay(100);
			break;
		}
	}
	clrmous(MouseX, MouseY);
	delay(100);
	enturn(map_type, my, en, num_my);
	clrmous(MouseX, MouseY);
	delay(100);

	setfillstyle(SOLID_FILL, BLACK);
	bar(123, 383, 519, 480);                                     

	puthz(128, 388, "���������غϺ����ǽ��뵽�˾�ʤʱ��", 16, 18, WHITE);//����5
	puthz(374, 440, "������⴦����", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			delay(100);
			break;
		}
	}
	clrmous(MouseX, MouseY);
	delay(100);

	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	bar(0, 0, 640, 480);
	print_UI();

	ending(my, en, num_my, num_en);              

	print_map(map_type);//����6
	print_my(my, num_my);
	print_en(en);
	setfillstyle(SOLID_FILL, BLACK);

	bar(123, 383, 519, 480);
	puthz(128, 388, "���ڣ�����з����ǣ�����ȡ��ʤ��", 16, 18, WHITE);
	puthz(374, 440, "������⴦����", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			break;
		}
	}
	clrmous(MouseX, MouseY);
	while (1) {
		if(myturn(map_type, my, en, num_my, num_en))
			break;
	}
	clrmous(MouseX, MouseY);
	delay(100);
	setfillstyle(SOLID_FILL, BLACK);
	bar(123, 383, 519, 480);
	puthz(128, 388, "�̳̽����ˣ�������ʼ��ʽս����", 16, 18, WHITE);
	puthz(374, 440, "������⴦����", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			break;
		}
	}
	clrmous(MouseX, MouseY);
	delay(100);
}

/********************
����ѡ��ؿ��Ѷ�
lpcд��
********************/
int choose() {

	int now_loc = 0;

	cleardevice();
	clrmous(MouseX, MouseY);
	setbkcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	bar(0, 0, 640, 480);

	clrmous(MouseX, MouseY);

	puthz(200+10, 40, "ѡ���Ѷ�", 48, 60, BLUE);

	setfillstyle(SOLID_FILL, GREEN);
	bar(280,125 ,370 ,165 );
	puthz(280+5, 125+3, "��", 32, 45, RED);

	setfillstyle(SOLID_FILL, GREEN);
	bar(280, 195, 370, 235);
	puthz(280 + 5, 195 + 3, "��ͨ", 32, 45, RED);

	setfillstyle(SOLID_FILL, GREEN);
	bar(280, 265, 370, 305);
	puthz(280 + 5, 265 + 3, "����", 32, 45, RED);

	mouseinit();
	while (1) {
		if (mouse_in(280, 125, 370, 165) && now_loc != 1) {
			clrmous(MouseX, MouseY);
			delay(50);
			now_loc = 1;
			setfillstyle(SOLID_FILL, LIGHTGREEN);
			bar(280, 125, 370, 165);
			puthz(280 + 5, 125 + 3, "��", 32, 45, RED);
		}
		if (mouse_in(280, 195, 370, 235) && now_loc != 2) {
			clrmous(MouseX, MouseY);
			delay(50);
			now_loc = 2;
			setfillstyle(SOLID_FILL, LIGHTGREEN);
			bar(280, 195, 370, 235);
			puthz(280 + 5, 195 + 3, "��ͨ", 32, 45, RED);
		}

		if (mouse_in(280, 265, 370, 305) && now_loc != 3) {
			clrmous(MouseX, MouseY);
			delay(50);
			now_loc = 3;
			setfillstyle(SOLID_FILL, LIGHTGREEN);
			bar(280, 265, 370, 305);
			puthz(280 + 5, 265 + 3, "����", 32, 45, RED);
		}

		if ((!mouse_in(280, 125, 370, 165)) && (!mouse_in(280, 195, 370, 235)) && (!mouse_in(280, 265, 370, 305)) && now_loc != 0) {
			clrmous(MouseX, MouseY);
			delay(50);
			now_loc = 0;

			setfillstyle(SOLID_FILL, GREEN);
			bar(280, 125, 370, 165);
			puthz(280 + 5, 125 + 3, "��", 32, 45, RED);

			setfillstyle(SOLID_FILL, GREEN);
			bar(280, 195, 370, 235);
			puthz(280 + 5, 195 + 3, "��ͨ", 32, 45, RED);

			setfillstyle(SOLID_FILL, GREEN);
			bar(280, 265, 370, 305);
			puthz(280 + 5, 265 + 3, "����", 32, 45, RED);
		}
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(280, 125, 370, 165) == 1) {
			delay(100);
			cleardevice();
			return 1;
		}
		if (mouse_press(280, 195, 370, 235) == 1) {
			delay(100);
			cleardevice();
			return 2;
		}
		if (mouse_press(280, 265, 370, 305) == 1) {
			delay(100);
			cleardevice();
			return 3;
		}
	}
}