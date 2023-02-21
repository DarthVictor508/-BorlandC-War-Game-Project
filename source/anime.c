#include"anime.h"

/********************
用于召唤一个炮弹（小 红 点）然后播放一段它从(x,y)移动到(xx,yy)的动画
形参以像素为单位，不是格子
lzz写的
********************/
void print_atk(int x,int y,int xx,int yy){
	void *buff;
	int size;
	int nx,ny;
	int lx,ly;
	int i;
	int hz=50;
	size=imagesize(x-5,y-5,x+5,y+5);
	buff=malloc(size);
	getimage(x-5,y-5,x+5,y+5,buff);
	setfillstyle(SOLID_FILL,RED);
	pieslice(x,y,0,360,5);
	for(i=1;i<=hz;i++){
		nx=(int)(x+(xx-x)/(double)hz*i);
		ny=(int)(y+(yy-y)/(double)hz*i);
		lx=(int)(x+(xx-x)/(double)hz*(i-1));
		ly=(int)(y+(yy-y)/(double)hz*(i-1));
		putimage(lx-5,ly-5,buff,COPY_PUT);
		free(buff);
		size=imagesize(nx-5,ny-5,nx+5,ny+5);
		buff=malloc(size);
		getimage(nx-5,ny-5,nx+5,ny+5,buff);
		setfillstyle(SOLID_FILL,RED);
		pieslice(nx,ny,0,360,5);
		delay(50);
	}
	putimage(xx-5,yy-5,buff,COPY_PUT);
	free(buff);
	getimage(xx -10, yy - 16, xx + 16, yy + 15,buff);
	setcolor(RED);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line(xx-3,yy+15,xx+2,yy+9);
	line(xx+2,yy+9,xx+9,yy+10);
	line(xx+9,yy+10,xx+9,yy+4);
	line(xx+9,yy+4,xx+15,yy+9);
	line(xx+15,yy+9,xx+9,yy-3);
	line(xx+9,yy-3,xx+9,yy-9);
	line(xx+10,yy-9,xx+4,yy-9);
	line(xx+4,yy-9,xx-2,yy-15);
	line(xx-2,yy-15,xx-2,yy-9);
	line(xx-2,yy-9,xx-9,yy-9);
	line(xx-9,yy-9,xx-4,yy-3);
	line(xx-4,yy-3,xx-9,yy+9);
	line(xx-9,yy+8,xx-4,yy+2);
	line(xx-3,yy+2,xx-3,yy+15);
	setcolor(YELLOW);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line(xx-1,yy+11,xx,yy+5);
	line(xx,yy+5,xx+5,yy+7);
	line(xx+5,yy+7,xx+6,yy+2);
	line(xx+6,yy+2,xx+11,yy+5);
	line(xx+11,yy+5,xx+6,yy-1);
	line(xx+6,yy-1,xx+7,yy-6);
	line(xx+7,yy-6,xx+2,yy-5);
	line(xx+2,yy-5,xx,yy-11);
	line(xx,yy-11,xx,yy-5);
	line(xx,yy-5,xx-6,yy-6);
	line(xx-6,yy-6,xx-2,yy-1);
	line(xx-2,yy-1,xx-6,yy+6);
	line(xx-6,yy+5,xx-2,yy);
	line(xx-2,yy,xx-1,yy+11);
	delay(100);
	putimage(xx-10, yy-16, buff, COPY_PUT);
	free(buff);
}
