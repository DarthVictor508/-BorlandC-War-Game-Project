#include"common.h"
#include"welcome.h"

void main(){
	char name[20];
	int gdriver,gmode;
	int map_type[13+3][9+3];
	struct unit my[100];
	struct unit en[100];
	int num_my;
    	int num_en;
	gdriver=VGA;
	gmode=VGAHI;
	initgraph(&gdriver,&gmode,"source\\BGI");
	mouseinit();
	if(welcome(name)) teach();
}
