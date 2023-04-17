#include"anime.h"

/********************
用于召唤一个炮弹（小 红 点）然后播放一段它从(x,y)移动到(xx,yy)的动画
形参以像素为单位，不是格子
lzz写的
********************/
void print_atk(int x, int y, int xx, int yy) {
	void* buff;
	int size;
	
	int nx, ny;
	int lx, ly;
	int i;
	int hz = 8;
	
	size=imagesize(x-10,y-10,x+10,y+10);
	buff=malloc(size);
	if(buff!=NULL) getimage(x-10,y-10,x+10,y+10,buff);
	
	setfillstyle(SOLID_FILL, RED);
	pieslice(x, y, 0, 360, 5);
	for (i = 1; i <= hz; i++) {
		nx = (int)(x + (xx - x) / (double)hz * i);
		ny = (int)(y + (yy - y) / (double)hz * i);
		lx = (int)(x + (xx - x) / (double)hz * (i - 1));
		ly = (int)(y + (yy - y) / (double)hz * (i - 1));
		
		setwritemode(XOR_PUT);
		putimage(lx-10,ly-10,buff,COPY_PUT);
		free(buff);
		setwritemode(COPY_PUT);
		size=imagesize(nx-10,ny-10,nx+10,ny+10);
		buff=malloc(size);
		if(buff!=NULL) getimage(nx-10,ny-10,nx+10,ny+10,buff);
		
		setfillstyle(SOLID_FILL, RED);
		pieslice(nx, ny, 0, 360, 5);
		if(i==1) delay(200);
		delay(50);
	}
	
	setwritemode(XOR_PUT);
	putimage(xx-10,yy-10,buff,COPY_PUT);
	free(buff);
	setwritemode(COPY_PUT);
	size=imagesize(x-10,y-10,x+10,y+10);
	buff=malloc(size);
	if(buff!=NULL) getimage(xx -15, yy - 21, xx + 21, yy + 20,buff);
	
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	line(xx - 3, yy + 15, xx + 2, yy + 9);
	line(xx + 2, yy + 9, xx + 9, yy + 10);
	line(xx + 9, yy + 10, xx + 9, yy + 4);
	line(xx + 9, yy + 4, xx + 15, yy + 9);
	line(xx + 15, yy + 9, xx + 9, yy - 3);
	line(xx + 9, yy - 3, xx + 9, yy - 9);
	line(xx + 10, yy - 9, xx + 4, yy - 9);
	line(xx + 4, yy - 9, xx - 2, yy - 15);
	line(xx - 2, yy - 15, xx - 2, yy - 9);
	line(xx - 2, yy - 9, xx - 9, yy - 9);
	line(xx - 9, yy - 9, xx - 4, yy - 3);
	line(xx - 4, yy - 3, xx - 9, yy + 9);
	line(xx - 9, yy + 8, xx - 4, yy + 2);
	line(xx - 3, yy + 2, xx - 3, yy + 15);
	setcolor(YELLOW);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	line(xx - 1, yy + 11, xx, yy + 5);
	line(xx, yy + 5, xx + 5, yy + 7);
	line(xx + 5, yy + 7, xx + 6, yy + 2);
	line(xx + 6, yy + 2, xx + 11, yy + 5);
	line(xx + 11, yy + 5, xx + 6, yy - 1);
	line(xx + 6, yy - 1, xx + 7, yy - 6);
	line(xx + 7, yy - 6, xx + 2, yy - 5);
	line(xx + 2, yy - 5, xx, yy - 11);
	line(xx, yy - 11, xx, yy - 5);
	line(xx, yy - 5, xx - 6, yy - 6);
	line(xx - 6, yy - 6, xx - 2, yy - 1);
	line(xx - 2, yy - 1, xx - 6, yy + 6);
	line(xx - 6, yy + 5, xx - 2, yy);
	line(xx - 2, yy, xx - 1, yy + 11);
	delay(200);
	
	setwritemode(XOR_PUT);
	putimage(xx-15, yy-21, buff, COPY_PUT);
	free(buff);
	setwritemode(COPY_PUT);
}


/********************
用于显示在（x,y）处地雷炸裂效果动画
形参以像素为单位，不是格子
lpc写的
********************/
void print_boom(int x, int y) {
	x+=20;
	y+=10;
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	line(x - 3, y + 15, x + 2, y + 9);
	line(x + 2, y + 9, x + 9, y + 10);
	line(x + 9, y + 10, x + 9, y + 4);
	line(x + 9, y + 4, x + 15, y + 9);
	line(x + 15, y + 9, x + 9, y - 3);
	line(x + 9, y - 3, x + 9, y - 9);
	line(x + 10, y - 9, x + 4, y - 9);
	line(x + 4, y - 9, x - 2, y - 15);
	line(x - 2, y - 15, x - 2, y - 9);
	line(x - 2, y - 9, x - 9, y - 9);
	line(x - 9, y - 9, x - 4, y - 3);
	line(x - 4, y - 3, x - 9, y + 9);
	line(x - 9, y + 8, x - 4, y + 2);
	line(x - 3, y + 2, x - 3, y + 15);
	setcolor(YELLOW);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	line(x - 1, y + 11, x, y + 5);
	line(x, y + 5, x + 5, y + 7);
	line(x + 5, y + 7, x + 6, y + 2);
	line(x + 6, y + 2, x + 11, y + 5);
	line(x + 11, y + 5, x + 6, y - 1);
	line(x + 6, y - 1, x + 7, y - 6);
	line(x + 7, y - 6, x + 2, y - 5);
	line(x + 2, y - 5, x, y - 11);
	line(x, y - 11, x, y - 5);
	line(x, y - 5, x - 6, y - 6);
	line(x - 6, y - 6, x - 2, y - 1);
	line(x - 2, y - 1, x - 6, y + 6);
	line(x - 6, y + 5, x - 2, y);
	line(x - 2, y, x - 1, y + 11);
	delay(100);
}