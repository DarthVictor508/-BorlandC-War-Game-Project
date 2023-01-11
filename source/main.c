#include"common.h"
#include"welcome.h"

void main(){
	char name[20];
	int gdriver,gmode;
	gdriver=VGA;
	gmode=VGAHI;
	initgraph(&gdriver,&gmode,"source\\BGI");
	mouseinit();
	if(welcome(name)) printf("1\n");
	else printf("0\n");
}