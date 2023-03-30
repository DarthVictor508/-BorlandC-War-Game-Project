#include "welcome.h"

/********************
用于展示开始界面
lzz写的
********************/
int welcome(char *s){
	int cnt=0,now=235;
	char temp[5];
	int now_loc=0;
	
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
		if(mouse_in(240,375,240+40*4,375+40)&&now_loc==0){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=1;
			setfillstyle(SOLID_FILL,LIGHTBLUE);
			bar(240,375,240+40*4,375+40);
			puthz(240+5,375+5,"开始游戏",32,40,BLACK);
		}
		if((!mouse_in(240,375,240+40*4,375+40))&&now_loc==1){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=0;
			setfillstyle(SOLID_FILL,BLUE);
			bar(240,375,240+40*4,375+40);
			puthz(240+5,375+5,"开始游戏",32,40,BLACK);
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
	
	if(mouse_in(230,380,620,405)) now_loc=1;
	else now_loc=0;
	if(now_loc) MouseS=2;
	clrmous(MouseX,MouseY);
	delay(100);
	bar(0,360,640,480);
	puthz(20,380,"输入你的名字：",24,30,BLACK);
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
	
	if(mouse_in(20,440,185,465)) now_loc=1;
	else if(mouse_in(195,440,360,465)) now_loc=2;
	else now_loc=0;
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
		if(mouse_in(20,440,185,465)&&now_loc!=1){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=1;
			setfillstyle(SOLID_FILL,LIGHTBLUE);
			bar(20,440,185,465);
			puthz(20+5,440+5,"是的，我需要教程",16,20,WHITE);
		}
		if(mouse_in(195,440,360,465)&&now_loc!=2){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=2;
			setfillstyle(SOLID_FILL,LIGHTRED);
			bar(195,440,360,465);
			puthz(195+5,440+5,"不需要了，谢谢你",16,20,WHITE);
		}
		if((!mouse_in(20,440,185,465))&&(!mouse_in(195,440,360,465))&&now_loc!=0){
			clrmous(MouseX,MouseY);
			delay(50);
			now_loc=0;
			setfillstyle(SOLID_FILL,BLUE);
			bar(20,440,185,465);
			puthz(20+5,440+5,"是的，我需要教程",16,20,WHITE);
			setfillstyle(SOLID_FILL,RED);
			bar(195,440,360,465);
			puthz(195+5,440+5,"不需要了，谢谢你",16,20,WHITE);
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
			puthz(128,388,"请你部署我方",16,18,WHITE);
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
					puthz(128,388,"你不能将陆地作战单位部署在海里",16,18,WHITE);
				}
				if(my[i].type!=3&&my[i].type==4&&map_type[y][x]==0){
					judge=0;
					setfillstyle(SOLID_FILL,BLACK);
					bar(123,383,519,480);
					puthz(128,388,"你不能将海上作战单位部署在陆地上",16,18,WHITE);
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



	bar(123, 383, 519, 480); //步骤1
	puthz(128, 388, "下面由我为你介绍游戏玩法", 16, 18, WHITE);
	puthz(374, 440, "点击任意处继续", 16, 18, WHITE);
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		mouse(MouseX, MouseY);
		if (mouse_press(0, 0, 640, 480) == 1) {
			delay(100);
			break;
		}
	};


	clrmous(MouseX, MouseY); //步骤2
	delay(100);
	setfillstyle(SOLID_FILL, BLACK);
	bar(123, 383, 519, 480);  
	puthz(128, 388, "首先，你可以布置我方单位的初始位置", 16, 18, WHITE);
	puthz(374, 440, "点击任意处继续", 16, 18, WHITE);
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
	puthz(128, 388, "需要注意的是，在战场上每个作战单位都需要物资", 16, 18, WHITE);
	puthz(128, 405, "才能生存，每回合结束时每个我方作战单位都会消", 16, 18, WHITE);
	puthz(128, 422, "耗一定物资，物资被消耗完时作战单位也会死亡", 16, 18, WHITE);
	puthz(374, 440, "点击任意处继续", 16, 18, WHITE);
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
	puthz(128, 388, "而我们负责后勤保障的支援兵能为一定范围内的作", 16, 18, WHITE);
	puthz(128, 405, "战单位补充物资。所以，你需要注意支援兵的穿插", 16, 18, WHITE);
	puthz(128, 422, "摆放", 16, 18, WHITE);
	puthz(374, 440, "点击任意处继续", 16, 18, WHITE);
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
	puthz(128, 388, "哦，对了，我们接到情报说敌人在某些位置摆放了", 16, 18, WHITE);
	puthz(128, 405, "地雷。你在地图上看不见它们，但它们就在那里，", 16, 18, WHITE);
	puthz(128, 422, "等着你的陆地单位踩上去的时候炸你一下，小心点", 16, 18, WHITE);
	puthz(374, 440, "点击任意处继续", 16, 18, WHITE);
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
	puthz(128, 388, "现在，开始布置你的兵力吧", 16, 18, WHITE);
	puthz(374, 440, "点击任意处继续", 16, 18, WHITE);
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


	                                      
	setfillstyle(SOLID_FILL, BLACK);//步骤3
	bar(123, 383, 519, 480);
	puthz(128, 388, "接下来将进入我方回合，选中单位后点击右下角对", 16, 18, WHITE);
	puthz(128, 405, "应的按钮，你可以进行移动我方单位、对敌方单位", 16, 18, WHITE);
	puthz(128, 422, "发动进攻、结束回合等操作", 16, 18, WHITE);
	puthz(374, 440, "点击任意处继续", 16, 18, WHITE);
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
	puthz(128, 388, "在一个回合中，你的一个作战单位只能攻击一", 16, 18, WHITE);
	puthz(128, 405, "次，移动一次", 16, 18, WHITE);
	puthz(374, 440, "点击任意处继续", 16, 18, WHITE);
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
	puthz(128, 388, "我们的时间很紧张，所以如果你没能在二十回合内", 16, 18, WHITE);
	puthz(128, 405, "拿下敌方的主城，也将被视为任务失败", 16, 18, WHITE);
	puthz(374, 440, "点击任意处继续", 16, 18, WHITE);
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
	puthz(128, 388, "现在，开始调度你的兵力吧", 16, 18, WHITE);
	puthz(374, 440, "点击任意处继续", 16, 18, WHITE);
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

	                                     
	setfillstyle(SOLID_FILL, BLACK);//步骤4
	bar(123, 383, 519, 480);
	puthz(128, 388, "接下来将进入敌方回合，你将无法进行操作", 16, 18, WHITE);
	puthz(374, 440, "点击任意处继续", 16, 18, WHITE);
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

	puthz(128, 388, "经过几个回合后，我们进入到了决胜时刻", 16, 18, WHITE);//步骤5
	puthz(374, 440, "点击任意处继续", 16, 18, WHITE);
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

	print_map(map_type);//步骤6
	print_my(my, num_my);
	print_en(en);
	setfillstyle(SOLID_FILL, BLACK);

	bar(123, 383, 519, 480);
	puthz(128, 388, "现在，消灭敌方主城，即可取得胜利", 16, 18, WHITE);
	puthz(374, 440, "点击任意处继续", 16, 18, WHITE);
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
	puthz(128, 388, "教程结束了，即将开始正式战斗！", 16, 18, WHITE);
	puthz(374, 440, "点击任意处继续", 16, 18, WHITE);
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
用于选择关卡难度
lpc写的
********************/
int choose() {

	int now_loc = 0;

	cleardevice();
	clrmous(MouseX, MouseY);
	setbkcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	bar(0, 0, 640, 480);

	clrmous(MouseX, MouseY);

	puthz(200+10, 40, "选择难度", 48, 60, BLUE);

	setfillstyle(SOLID_FILL, GREEN);
	bar(280,125 ,370 ,165 );
	puthz(280+5, 125+3, "简单", 32, 45, RED);

	setfillstyle(SOLID_FILL, GREEN);
	bar(280, 195, 370, 235);
	puthz(280 + 5, 195 + 3, "普通", 32, 45, RED);

	setfillstyle(SOLID_FILL, GREEN);
	bar(280, 265, 370, 305);
	puthz(280 + 5, 265 + 3, "困难", 32, 45, RED);

	mouseinit();
	while (1) {
		if (mouse_in(280, 125, 370, 165) && now_loc != 1) {
			clrmous(MouseX, MouseY);
			delay(50);
			now_loc = 1;
			setfillstyle(SOLID_FILL, LIGHTGREEN);
			bar(280, 125, 370, 165);
			puthz(280 + 5, 125 + 3, "简单", 32, 45, RED);
		}
		if (mouse_in(280, 195, 370, 235) && now_loc != 2) {
			clrmous(MouseX, MouseY);
			delay(50);
			now_loc = 2;
			setfillstyle(SOLID_FILL, LIGHTGREEN);
			bar(280, 195, 370, 235);
			puthz(280 + 5, 195 + 3, "普通", 32, 45, RED);
		}

		if (mouse_in(280, 265, 370, 305) && now_loc != 3) {
			clrmous(MouseX, MouseY);
			delay(50);
			now_loc = 3;
			setfillstyle(SOLID_FILL, LIGHTGREEN);
			bar(280, 265, 370, 305);
			puthz(280 + 5, 265 + 3, "困难", 32, 45, RED);
		}

		if ((!mouse_in(280, 125, 370, 165)) && (!mouse_in(280, 195, 370, 235)) && (!mouse_in(280, 265, 370, 305)) && now_loc != 0) {
			clrmous(MouseX, MouseY);
			delay(50);
			now_loc = 0;

			setfillstyle(SOLID_FILL, GREEN);
			bar(280, 125, 370, 165);
			puthz(280 + 5, 125 + 3, "简单", 32, 45, RED);

			setfillstyle(SOLID_FILL, GREEN);
			bar(280, 195, 370, 235);
			puthz(280 + 5, 195 + 3, "普通", 32, 45, RED);

			setfillstyle(SOLID_FILL, GREEN);
			bar(280, 265, 370, 305);
			puthz(280 + 5, 265 + 3, "困难", 32, 45, RED);
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