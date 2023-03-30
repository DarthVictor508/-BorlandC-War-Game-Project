#include"common.h"
#include"welcome.h"
#include"info.h"
#include"myturn.h"
#include"anime.h"

void main(){
	char name[20],tmp[3];
	int gdriver,gmode;
	int map_type[13+3][13+3];
	int f[13+3][13+3];
	struct unit my[10];
	struct unit en[10];
	int num_my=5;
	int num_en=5;
	int x,y,op;
	int cnt=0;

	gdriver=VGA;
	gmode=VGAHI;
	initgraph(&gdriver,&gmode,"source\\BGI");
	mouseinit();

	init(map_type, my, en, 1);
	if(welcome(name)) teach(map_type, my, en, num_my, num_en);
	while(1){
		cnt=0;
		init(map_type,my,en,choose());
		print_UI();
		print_map(map_type);
		print_en(en);
		place(map_type,my,en,num_my,num_en);
		while(++cnt){
			if(cnt==20) break;
			puthz(122,361,"当前为第",16,18,WHITE);
			puthz(227,361,"回合",16,18,WHITE);
			nts(cnt,tmp);
			setfillstyle(SOLID_FILL,BLACK);
			bar(196,361,226,379);
			setcolor(WHITE);
			settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
			settextjustify(LEFT_TEXT, TOP_TEXT);
			outtextxy(196,361,tmp);
			if(myturn(map_type,my,en,num_my,num_en)) break;
			if(!enturn(map_type,my,en,num_my)){
				cnt=20;
				break;
			}
		}
		if(!rank(name,cnt)) break;
	}
}