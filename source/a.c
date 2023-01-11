#include "common.h"
#include "welcome.h"
void print_screen(char *s){
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL,WHITE);
	bar(150,150,150+100,150+30);
	puthz(150+15,150+5,s,16,30,BLACK);
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		mouse(MouseX,MouseY);
		if(mouse_press(150,150,150+100,150+30)==1){
			printf("Clicked successfully!\n");
			delay(2000);
			return;
		}
	}
}
void print_pic(char *s){
	cleardevice();
	setfillstyle(SOLID_FILL,WHITE);
	setbkcolor(BLACK);
	bar(0,0,640,475);
	putbmp(0,0,"source\\picture\\ougen3.bmp");
	puthz(200,400,s,24,28,BLACK);
	getchar();
}
void main(){
	char *s="ÄãºÃ";
	int gdriver,gmode;
	gdriver=VGA;
	gmode=VGAHI;
	initgraph(&gdriver,&gmode,"source\\BGI");
	mouseinit();
	welcome();
}