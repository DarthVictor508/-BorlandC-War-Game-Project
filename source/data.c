#include "data.h"

/********************
�ж������Ƿ�֮ǰ����
lzzд��
********************/
int exist(char *s){
	int n,i;
	char name[20];
	FILE *fp;
	fp=fopen("source\\data.txt","r");
	fscanf(fp,"%d",&n);
	for(i=1;i<=n;i++){
		fscanf(fp,"%s",name);
		if(strcmp(name,s)==0) return (fclose(fp),1);
	}
	return (fclose(fp),0);
}

/********************
д���µ�ս�����ݲ���ʾ��β
lzzд��
********************/
void rank(char *s,int cnt){
	int n,grd[20],i,j,jud=0,t,fin[20],r;
	char name[20][20],temp[20];
	FILE *fp;
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
	if(!jud) strcpy(name[++n],s),grd[n]=cnt;
	for(i=1;i<=n-1;i++){
		for(j=i+1;j<=n;j++){
			if(grd[i]>grd[j]){
				t=grd[i],grd[i]=grd[j],grd[j]=t;
				strcpy(temp,name[i]),strcpy(name[i],name[j]),strcpy(name[j],temp);
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
	puthz(10,360,"ŷ��",32,40,BLACK);
	puthz(475,455,"������⴦������Ϸ",16,18,BLACK);
	puthz(422,5,"��Ϸ����",48,50,RED);
	if(cnt!=100){
		puthz(20,405,"��̫���ˣ�",24,30,BLACK);
		puthz(418,64,"������",16,18,BLACK);
		gotoxy(60,5);
		printf("%5d",cnt);
		puthz(523,64,"�غ�ȡ��ʤ��",16,18,BLACK);
		for(i=1;i<=n;i++){
			if(strcmp(name[i],s)==0){
				r=i;
				break;
			}
		}
		puthz(418,102,"��ĿǰΪֹ����óɼ������������������",16,18,BLACK);
		gotoxy(69,9);
		printf("%2d",fin[r]);
		puthz(450,150,"���а�",48,50,RED);
		for(i=1;i<=(n<=10?n:10);i++){
			gotoxy(54,14+i-1);
			printf("%2d %-15s %-5d\n",fin[i],name[i],grd[i]);
		}
	}
	else{
		puthz(20,405,"��ô�򵥵�ս����Ӯ�����𡭡�",24,30,BLACK);
		puthz(20,435,"��������ָ�ӹ١�",24,30,BLACK);
		puthz(418,74,"�ǳ��ź�",48,50,BLACK);
		puthz(418,150,"��ս����",48,50,BLACK);
	}
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		mouse(MouseX,MouseY);
		if(mouse_press(0,0,640,480)==1){
			delay(100);
			break;
		}
	}
}