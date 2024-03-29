#include "data.h"

/********************
判断名字是否之前存在
lzz写的
********************/
int exist(char *s){
	int n;
	int i;
	char name[20];
	FILE *fp;
	fp=fopen("source\\data.txt","r");
	fscanf(fp,"%d",&n);
	for(i=1;i<=n;i++){
		fscanf(fp,"%s",name);
		if(strcmp(name,s)==0){
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}

/********************
写入新的战斗数据并显示结尾
lzz写的
********************/
int rank(char *s,int cnt){
	int n;
	int grd[20];
	int i,j;
	int jud=0;
	int t;
	int fin[20];
	int r;
	char name[20][20];
	char temp[20];
	FILE *fp;
	int now_loc=0;
	fp=fopen("source\\data.txt","r");
	fscanf(fp,"%d",&n);
	for(i=1;i<=n;i++){
		fscanf(fp,"%s",name[i]);
		if(strcmp(name[i],s)==0) jud=1;
	}
	for(i=1;i<=n;i++){
		fscanf(fp,"%d",&grd[i]);
		if(jud&&strcmp(name[i],s)==0) grd[i]=(grd[i]>cnt?cnt:grd[i]);
	}
	fclose(fp);
	if(!jud){
		strcpy(name[++n],s);
		grd[n]=cnt;
	}
	for(i=1;i<=n-1;i++){
		for(j=i+1;j<=n;j++){
			if(grd[i]>grd[j]){
				t=grd[i];
				grd[i]=grd[j];
				grd[j]=t;
				strcpy(temp,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],temp);
			}
		}
	}
	fp=fopen("source\\data.txt","w");
	fprintf(fp,"%d\n",n);
	for(i=1;i<=n;i++) fprintf(fp,"%s\n",name[i]);
	for(i=1;i<=n;i++) fprintf(fp,"%d\n",grd[i]);
	fclose(fp);
	for(i=1;i<=n;i++){
		fin[i]=i;
		if(grd[i]==grd[i-1]) fin[i]=fin[i-1];
	}
	
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,640,480);
	putbmp(0,0,"source\\picture\\ougen3.bmp");
	puthz(10,360,"欧根",32,40,BLACK);
	puthz(475,455,"点击任意处结束游戏",16,18,BLACK);
	puthz(422,5,"游戏结束",48,50,RED);
	if(cnt!=20){
		puthz(20,405,"您太巨了！",24,30,BLACK);
		puthz(418,64,"您用了",16,18,BLACK);
		setfillstyle(SOLID_FILL, WHITE);
		setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
		setcolor(BLACK);
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		nts(cnt,temp);
		outtextxy(485, 65, temp);
		puthz(520,64,"回合取得胜利",16,18,BLACK);
		for(i=1;i<=n;i++){
			if(strcmp(name[i],s)==0){
				r=i;
				break;
			}
		}
		puthz(418,102,"您目前为止的最好成绩在所有玩家中排名第",16,18,BLACK);
		nts(fin[r],temp);
		outtextxy(565, 129, temp);
		puthz(450,150,"排行榜",48,50,RED);
		for(i=1;i<=(n<=10?n:10);i++){
			gotoxy(54,14+i-1);
			printf("%2d %-15s %-5d\n",fin[i],name[i],grd[i]);
		}
	}
	else{
		puthz(20,405,"这么简单的战斗都赢不了吗……",24,30,BLACK);
		puthz(20,435,"真是杂鱼指挥官。",24,30,BLACK);
		puthz(418,74,"非常遗憾",48,50,BLACK);
		puthz(418,150,"您战败了",48,50,BLACK);
	}
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
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,640,480);
	puthz(150,100,"感谢您的游玩！",48,50,BLACK);
	puthz(140,180,"制作人：华中科技大学人工智能与自动化学院",16,18,BLACK);
	puthz(257,220,"刘政孜，李鹏程",16,18,BLACK);
	setfillstyle(SOLID_FILL,BLUE);
	bar(235,253,405,275);
	puthz(239,255,"太好玩啦，再来一局",16,18,WHITE);
	setfillstyle(SOLID_FILL,RED);
	bar(235,280,405,302);
	puthz(239,282,"我玩够了，退出游戏",16,18,WHITE);
	if(mouse_in(235,253,405,275)) now_loc=1;
	else if(mouse_in(235,280,405,302)) now_loc=2;
	else now_loc=0;
	while(1){
		if(mouse_in(235,253,405,275)&&now_loc!=1){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=1;
			setfillstyle(SOLID_FILL,LIGHTBLUE);
			bar(235,253,405,275);
			puthz(239,255,"太好玩啦，再来一局",16,18,WHITE);
		}
		if(mouse_in(235,280,405,302)&&now_loc!=2){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=2;
			setfillstyle(SOLID_FILL,LIGHTRED);
			bar(235,280,405,302);
			puthz(239,282,"我玩够了，退出游戏",16,18,WHITE);
		}
		if((!mouse_in(235,253,405,275))&&(!mouse_in(235,280,405,302))&&now_loc!=0){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=0;
			setfillstyle(SOLID_FILL,BLUE);
			bar(235,253,405,275);
			puthz(239,255,"太好玩啦，再来一局",16,18,WHITE);
			setfillstyle(SOLID_FILL,RED);
			bar(235,280,405,302);
			puthz(239,282,"我玩够了，退出游戏",16,18,WHITE);
		}
		newmouse(&MouseX,&MouseY,&press);
		mouse(MouseX,MouseY);
		if(mouse_press(235,253,405,275)==1){
			delay(100);
			return 1;
		}
		if(mouse_press(235,280,405,302)==1){
			delay(100);
			return 0;
		}
	}
}