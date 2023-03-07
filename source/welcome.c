#include "welcome.h"

/********************
用于展示开始界面
lzz写的
********************/
int welcome(char *s){
	int cnt=0,now=235;
	char temp[5];
	
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,640,480);
	puthz(195+15,300+5,"夺岛军演",48,60,RED);
	putbmp(195,0,"source\\picture\\logo.bmp");
	setfillstyle(SOLID_FILL,BLUE);
	bar(240,375,240+40*4,375+40);
	puthz(240+5,375+5,"开始游戏",32,40,BLACK);
	clrmous(MouseX,MouseY);
	delay(100);
	while(1){
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
	puthz(10,360,"你的秘书舰",32,40,BLACK);
	puthz(20,405,"嗯？你就是新来的指挥官吗？",24,30,BLACK);
	puthz(495,455,"点击任意处继续",16,18,BLACK);
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
	puthz(10,360,"欧根",32,40,BLACK);
	puthz(20,405,"你好，我是你的秘书舰欧根。",24,30,BLACK);
	puthz(495,455,"点击任意处继续",16,18,BLACK);
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
	puthz(20,405,"接下来的夺岛作战就拜托你来指挥了。",24,30,BLACK);
	puthz(495,455,"点击任意处继续",16,18,BLACK);
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
	puthz(20,405,"那么，可以先告诉我你的名字吗？",24,30,BLACK);
	puthz(495,455,"点击任意处继续",16,18,BLACK);
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
	puthz(20,380,"输入你的名字：",24,30,BLACK);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(230,380,620,405);
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		mouse(MouseX,MouseY);
		if(mouse_press(230,380,620,465)==1){
			delay(100);
			break;
		}
	}
	
	clrmous(MouseX,MouseY);
	delay(100);
	setfillstyle(SOLID_FILL,BLACK);
	bar(230,380,620,405);
	puthz(230,407,"（你的名字不能超过十五个字符哦）",16,18,BLACK);
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
	puthz(10,360,"欧根",32,40,BLACK);
	if(!exist(s)) puthz(20,405,"唔，有趣的名字。我记住了。",24,30,BLACK);
	else puthz(20,405,"哦，原来是你啊。欢迎回来！",24,30,BLACK);
	puthz(495,455,"点击任意处继续",16,18,BLACK);
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
	puthz(20,405,"接下来……需要我教给你怎样指挥战斗吗？",24,30,BLACK);
	setfillstyle(SOLID_FILL,BLUE);
	bar(20,440,185,465);
	puthz(20+5,440+5,"是的，我需要教程",16,20,WHITE);
	setfillstyle(SOLID_FILL,RED);
	bar(195,440,360,465);
	puthz(195+5,440+5,"不需要了，谢谢你",16,20,WHITE);
	while(1){
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
布置我方单位
lzz写的
********************/
void place(int(*map_type)[13+3], struct unit my[],struct unit en[],int num_my,int num_en){
	int i,j,k,l,x,y,half,judge;
	for(i=1;i<=num_my;i++){
		info(my[i],1,0,my,0);
		save_bk_mou(MouseX,MouseY);
		for(j=1;j<=my[i].num;j++){
			setfillstyle(SOLID_FILL,BLACK);
			bar(123,383,519,480);
			puthz(128,388,"请您部署我方",16,18,WHITE);
			puthz(236,388,my[i].name,16,18,WHITE);
			bar(524,275,640,315);
			puthz(528,285,"剩余",16,18,WHITE);
			puthz(586,285,"个单位",16,18,WHITE);
			puthz(555,305,"待部署",16,18,WHITE);
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
					puthz(128,388,"您不能将陆地作战单位部署在海里",16,18,WHITE);
				}
				if(my[i].type!=3&&my[i].type==4&&map_type[y][x]==0){
					judge=0;
					setfillstyle(SOLID_FILL,BLACK);
					bar(123,383,519,480);
					puthz(128,388,"您不能将海上作战单位部署在陆地上",16,18,WHITE);
				}
				if(my[i].type!=3){
					for(k=1;k<=num_my;k++){
						if(my[k].type==3) continue;
						for(l=1;l<=my[k].num;l++){
							if(my[k].a[l]==x&&my[k].b[l]==y){
								judge=0;
								setfillstyle(SOLID_FILL,BLACK);
								bar(123,383,519,480);
								puthz(128,388,"该位置已被占据",16,18,WHITE);
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
								puthz(128,388,"该位置已被占据",16,18,WHITE);
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
							puthz(128,388,"该位置已被占据",16,18,WHITE);
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
			if(my[i].type==4) puthz(my[i].x[j],my[i].y[j],"运输",16,17,WHITE);
			if(my[i].type==5) puthz(my[i].x[j],my[i].y[j],"支援",16,17,WHITE);
			save_bk_mou(MouseX,MouseY);
		}
	}
}

/********************
用于显示教程
lpc写的
********************/
void teach(){
}
