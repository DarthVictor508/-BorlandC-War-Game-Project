#include "myturn.h"

/********************
��������һ����λ���ߵ���Щ����
lzzд��
********************/
void bfs(struct unit x,int num,int (*map_type)[13+3],int (*f)[13+3],struct unit my[],struct unit en[],int num_my,int num_en){
	const int dirx[4]={-1,1,0,0};//�ĸ�����
	const int diry[4]={0,0,-1,1};
	int i,j,k;
	int nx,ny;
	int judge;
	struct node q[117+3];
	struct node tmp,temp;
	int head=1,tail=0;
	for(i=1;i<=9;i++)
		for(j=1;j<=13;j++)
			f[i][j]=0;
	tmp.x=x.b[num];
	tmp.y=x.a[num];
	tmp.rest=x.max_move;
	f[tmp.x][tmp.y]=1;
	q[++tail]=tmp;//��ʼλ�����
	while(tail>=head){
		tmp=q[head++];//ȡһ���������
		if(tmp.rest==0) continue;
		for(i=0;i<4;i++){
			nx=tmp.x+dirx[i];
			ny=tmp.y+diry[i];//ȡһ������
			if(f[nx][ny]) continue;
			if(x.type!=3&&x.type!=4&&map_type[nx][ny]==1){ //½�ص�λ��һ���ں���
				judge=0;
				for(j=1;j<=my[4].num;j++){ //�жϺ����Ƿ������䴬
					if(my[4].b[j]==nx&&my[4].a[j]==ny&&my[4].port_type[j]==0){
						judge=1;
						break;
					}
				}
				f[nx][ny]=judge;
				continue;
			}
			if(x.type==4&&map_type[nx][ny]==0) continue; //���ϵ�λ��һ����½��
			if(nx<=0||ny<=0||nx>9||ny>13) continue; //��һ������
			judge=1;
			if(x.type!=3){ //���Ƿɻ�ʱ�ж���һ���Ƿ��ѱ�ռ��
				for(j=1;j<=num_my;j++){
					if(my[j].type==3) continue;
					for(k=1;k<=my[j].num;k++){
						if(my[j].ported[k]||my[j].hp[k]<=0||my[j].oil[k]<=0) continue;
						if(my[j].b[k]==nx&&my[j].a[k]==ny){
							judge=0;
							break;
						}
					}	
					if(!judge) break;
				}
				for(j=1;j<=num_en;j++){
					for(k=1;k<=en[j].num;k++){
						if(en[j].hp[k]<=0||en[j].type==5) continue;
						if(en[j].b[k]==nx&&en[j].a[k]==ny){
							judge=0;
							break;
						}
					}	
					if(!judge) break;
				}
			}
			else{ //�ɻ�
				for(j=1;j<=my[3].num;j++){
					if(my[3].hp[k]<=0||my[3].oil[k]<=0) continue;
					if(my[3].b[j]==nx&&my[3].a[j]==ny){
						judge=0;
						break;
					}
				}	
			}
			if(!judge) continue;//��һ��λ�ò��Ϸ�������
			f[nx][ny]=1;//��һ��λ�úϷ����ǲ����
			temp.x=nx,temp.y=ny,temp.rest=tmp.rest-1;
			q[++tail]=temp;
		}
	}
	f[x.b[num]][x.a[num]]=0;//�����ʼλ��ȡ����ǣ���Ϊ���ƶ�û���壩
}

/********************
�ҷ��ж���
lzzд��
********************/
int myturn(int (*map_type)[13+3],struct unit my[],struct unit en[],int num_my,int num_en){
	int x,y,half,i,j,k,now_type=0,now_num=0,now_op=2,re=0,f[13+3][13+3],judge,ship_num;
	for(i=1;i<=num_my;i++)
		for(j=1;j<=my[i].num;j++)
			my[i].moved[j]=my[i].atked[j]=1;
	clrmous(MouseX,MouseY);
	delay(100);
	my_turn();
	setfillstyle(SOLID_FILL,BLACK);
	bar(123,383,519,480);
	puthz(128,388,"��������Ļغϣ�����ȱ����ɡ�",16,18,WHITE);
	print_map(map_type);
	print_my(my,num_my);
	print_en(en);
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		mouse(MouseX,MouseY);
		//ˢ���Ҳ���Ϣ��
		if(re){
			if(now_op==0) info(my[now_type],now_num,now_op,my,1);
			if(now_op==1) info(en[now_type],now_num,now_op,my,1);
		}
		re=0;
		//����˽����غ�
		if(mouse_press(528,448,636,474)==1){ 
			delay(100);
			break;
		}
		if(now_op==0){
			//������ƶ�
			if(mouse_press(528,418,636,444)==1&&my[now_type].moved[now_num]>0){
				delay(100);
				bfs(my[now_type],now_num,map_type,f,my,en,num_my,num_en); //�������ƶ�������
				for(i=1;i<=9;i++){//������п���λ�õĵ�ͼ
					for(j=1;j<=13;j++){
						if(f[i][j]) setfillstyle(SOLID_FILL,LIGHTRED);
						else{
							if(map_type[i][j]==0) setfillstyle(SOLID_FILL,GREEN);
							if(map_type[i][j]==1) setfillstyle(SOLID_FILL,BLUE);
						}
						bar((j-1)*40+1,(i-1)*40+1,(j-1)*40+39,(i-1)*40+39);
					}
				}
				print_en(en);
				print_my(my,num_my);
				clrmous(MouseX,MouseY);
				delay(100);
				setfillstyle(SOLID_FILL,BLACK);//�޸İ�ťΪֻʣ��ȡ���ƶ�
				bar(528,388,640,480);
				setfillstyle(SOLID_FILL,GREEN);
				bar(528,448,636,474);
				puthz(542,454,"ȡ���ƶ�",16,20,WHITE);
				while(1){
					newmouse(&MouseX,&MouseY,&press);
					mouse(MouseX,MouseY);
					if(mouse_press(528,448,636,474)==1){//�����ȡ���ƶ�
						clrmous(MouseX,MouseY);
						delay(100);
						print_map(map_type);
						print_my(my,num_my);
						print_en(en);
						info(my[now_type],now_num,now_op,my,1);
						break;
					}
					if(mouse_press(0,0,520,359)==1){//����˵�ͼ���ж��ƶ���λ���Ƿ�Ϸ������ƶ�
						half=get_block(MouseX,MouseY,&x,&y);
						delay(100);
						if(!f[y][x]){
							setfillstyle(SOLID_FILL,BLACK);
							bar(123,383,519,480);
							puthz(128,388,"�õ�λ�޷��ƶ����Ǹ�λ��Ŷ��",16,18,WHITE);
							continue;
						}
						judge=0;
						for(i=1;i<=my[4].num;i++){ //�ж�Ҫȥ��λ���Ƿ������䴬
							if(my[4].hp[i]<=0||my[4].oil[i]<=0) continue;
							if(my[4].a[i]==x&&my[4].b[i]==y){
								judge=i;
								break;
							}
						}
						if((!judge)||now_type==3){//�����ϴ���ֱ���ƶ�
							my[now_type].b[now_num]=y;
							my[now_type].a[now_num]=x;
							my[now_type].x[now_num]=(x-1)*40+2;
							my[now_type].y[now_num]=(y-1)*40+(my[now_type].type==3?2:22);
							clrmous(MouseX,MouseY);
						}
						else{
							my[now_type].ported[now_num]=1;
							my[4].port_type[judge]=now_type;
							my[4].port_num[judge]=now_num;
							clrmous(MouseX,MouseY);
						}
						delay(100);
						print_map(map_type);
						print_my(my,num_my);
						print_en(en);
						my_turn();
						now_op=2;
						setfillstyle(SOLID_FILL,BLACK);
						bar(123,383,519,480);
						puthz(128,388,"��������Ļغϣ�����ȱ����ɡ�",16,18,WHITE);
						my[now_type].moved[now_num]--;
						break;
					}
				}
				continue;
			}
			//��ѡ�пɹ�������ʹ����˹�����
			if((now_type==1||now_type==2||now_type==3)&&mouse_press(528,388,636,414)==1&&my[now_type].atked[now_num]>0){
				delay(100);
				for(i=1;i<=9;i++)
					for(j=1;j<=13;j++)
						f[i][j]=0;
				for(i=1;i<=num_en;i++){
					if(en[i].type==5) continue;
					for(j=1;j<=en[i].num;j++){
						if(en[i].hp[j]<=0) continue;
						if(abs(my[now_type].a[now_num]-en[i].a[j])+abs(my[now_type].b[now_num]-en[i].b[j])<=my[now_type].max_attack)
							f[en[i].b[j]][en[i].a[j]]=1;
					}
				}
				for(i=1;i<=9;i++){//������пɹ���λ�õĵ�ͼ
					for(j=1;j<=13;j++){
						if(f[i][j]) setfillstyle(SOLID_FILL,LIGHTMAGENTA);
						else{
							if(map_type[i][j]==0) setfillstyle(SOLID_FILL,GREEN);
							if(map_type[i][j]==1) setfillstyle(SOLID_FILL,BLUE);
						}
						bar((j-1)*40+1,(i-1)*40+1,(j-1)*40+39,(i-1)*40+39);
					}
				}
				print_en(en);
				print_my(my,num_my);
				clrmous(MouseX,MouseY);
				delay(100);
				setfillstyle(SOLID_FILL,BLACK);//�޸İ�ťΪֻʣ��ȡ���ƶ�
				bar(528,388,640,480);
				setfillstyle(SOLID_FILL,GREEN);
				bar(528,448,636,474);
				puthz(542,454,"ȡ������",16,20,WHITE);
				while(1){
					newmouse(&MouseX,&MouseY,&press);
					mouse(MouseX,MouseY);
					if(mouse_press(528,448,636,474)==1){//�����ȡ������
						clrmous(MouseX,MouseY);
						delay(100);
						print_map(map_type);
						print_my(my,num_my);
						print_en(en);
						info(my[now_type],now_num,now_op,my,1);
						break;
					}
					if(mouse_press(0,0,520,359)==1){//����˵�ͼ���жϹ�����λ���Ƿ�Ϸ����ٹ���
						half=get_block(MouseX,MouseY,&x,&y);
						delay(100);
						if(!f[y][x]){
							setfillstyle(SOLID_FILL,BLACK);
							bar(123,383,519,480);
							puthz(128,388,"û�취��������Ŷ��",16,18,WHITE);
							continue;
						}
						for(i=1;i<=num_en;i++){
							for(j=1;j<=en[i].num;j++){
								if(en[i].hp[j]<=0||en[i].type==5) continue;
								if(en[i].a[j]==x&&en[i].b[j]==y){
									print_atk(my[now_type].x[now_num]+20,my[now_type].y[now_num]+10,en[i].x[j]+20,en[i].y[j]+10);
									clrmous(MouseX,MouseY);
									delay(100);
									print_map(map_type);
									print_my(my,num_my);
									print_en(en);
									en[i].hp[j]-=my[now_type].atk;
									if(en[1].hp[1]<=0) return 1;
								}
							}
						}
						clrmous(MouseX,MouseY);
						delay(100);
						print_map(map_type);
						print_en(en);
						print_my(my,num_my);
						my_turn();
						my[now_type].atked[now_num]--;
						break;
					}
				}
				continue;
			}
			//�����䴬����˵��ȴ��ϵ�λ
			if(now_type==4&&mouse_press(528,388,636,414)==1&&my[4].port_type[now_num]!=0&&my[my[4].port_type[now_num]].moved[my[4].port_num[now_num]]>0){
				delay(100);
				//�Ƚ������ȵ�λ�������봬ͳһ
				my[my[4].port_type[now_num]].a[my[4].port_num[now_num]]=my[4].a[now_num];
				my[my[4].port_type[now_num]].b[my[4].port_num[now_num]]=my[4].b[now_num];
				ship_num=now_num;
				now_type=my[4].port_type[now_num];
				now_num=my[4].port_num[now_num];
				bfs(my[now_type],now_num,map_type,f,my,en,num_my,num_en); //�������ƶ�������
				for(i=1;i<=9;i++){//������п���λ�õĵ�ͼ
					for(j=1;j<=13;j++){
						if(f[i][j]) setfillstyle(SOLID_FILL,RED);
						else{
							if(map_type[i][j]==0) setfillstyle(SOLID_FILL,GREEN);
							if(map_type[i][j]==1) setfillstyle(SOLID_FILL,BLUE);
						}
						bar((j-1)*40+1,(i-1)*40+1,(j-1)*40+39,(i-1)*40+39);
					}
				}
				print_en(en);
				print_my(my,num_my);
				clrmous(MouseX,MouseY);
				delay(100);
				setfillstyle(SOLID_FILL,BLACK);//�޸İ�ťΪֻʣ��ȡ���ƶ�
				bar(528,388,640,480);
				setfillstyle(SOLID_FILL,GREEN);
				bar(528,448,636,474);
				puthz(542,454,"ȡ���ƶ�",16,20,WHITE);
				while(1){
					newmouse(&MouseX,&MouseY,&press);
					mouse(MouseX,MouseY);
					if(mouse_press(528,448,636,474)==1){//�����ȡ���ƶ�
						clrmous(MouseX,MouseY);
						delay(100);
						print_map(map_type);
						print_my(my,num_my);
						print_en(en);
						info(my[now_type],now_num,now_op,my,1);
						break;
					}
					if(mouse_press(0,0,520,359)==1){//����˵�ͼ���ж��ƶ���λ���Ƿ�Ϸ������ƶ�
						half=get_block(MouseX,MouseY,&x,&y);
						delay(100);
						if(!f[y][x]){
							setfillstyle(SOLID_FILL,BLACK);
							bar(123,383,519,480);
							puthz(128,388,"�õ�λ�޷��ƶ����Ǹ�λ��Ŷ��",16,18,WHITE);
							continue;
						}
						judge=0;
						for(i=1;i<=my[4].num;i++){ //�ж�Ҫȥ��λ���Ƿ������䴬
							if(my[4].hp[i]<=0||my[4].oil[i]<=0) continue;
							if(my[4].a[i]==x&&my[4].b[i]==y){
								judge=i;
								break;
							}
						}
						if((!judge)||now_type==3){//�����ϴ���ֱ���ƶ�
							my[now_type].b[now_num]=y;
							my[now_type].a[now_num]=x;
							my[now_type].x[now_num]=(x-1)*40+2;
							my[now_type].y[now_num]=(y-1)*40+(my[now_type].type==3?2:22);
							my[now_type].ported[now_num]=0;
							my[4].port_type[ship_num]=0;
							my[4].port_num[ship_num]=0;
							if(now_type==4){
								my[my[4].port_type[now_num]].a[my[4].port_num[now_num]]=x;
								my[my[4].port_type[now_num]].b[my[4].port_num[now_num]]=y;
							}
						}
						else{
							my[now_type].ported[now_num]=1;
							my[4].port_type[judge]=now_type;
							my[4].port_num[judge]=now_num;
							my[4].port_type[ship_num]=0;
							my[4].port_num[ship_num]=0;
						}
						clrmous(MouseX,MouseY);
						delay(100);
						print_map(map_type);
						print_my(my,num_my);
						print_en(en);
						my_turn();
						now_op=2;
						setfillstyle(SOLID_FILL,BLACK);
						bar(123,383,519,480);
						puthz(128,388,"��������Ļغϣ�����ȱ����ɡ�",16,18,WHITE);
						my[now_type].moved[now_num]--;
						break;
					}
				}
				continue;
			}
		}
		if(mouse_press(0,0,520,359)==1){
			half=get_block(MouseX,MouseY,&x,&y);
			delay(100);
			for(i=1;i<=num_my;i++){
				for(j=1;j<=my[i].num;j++){
					if(my[i].hp[j]<=0||my[i].ported[j]||my[i].oil[j]<=0) continue;
					if(my[i].a[j]==x&&my[i].b[j]==y&&((half==0&&my[i].type==3)||(half!=0&&my[i].type!=3))){
						now_op=0;
						now_type=my[i].type;
						now_num=j;
						re=1;
						break;
					}
				}
			}
			for(i=1;i<=num_en;i++){
				for(j=1;j<=en[i].num;j++){
					if(en[i].hp[j]<=0||en[i].oil[j]<=0||en[i].type==5) continue;
					if(en[i].a[j]==x&&en[i].b[j]==y&&half==1){
						now_op=1;
						now_type=en[i].type;
						now_num=j;
						re=1;
						break;
					}
				}
			}
		}
	}
	//������Դ����
	for(i=1;i<=num_my;i++)
		for(j=1;j<=my[i].num;j++)
			my[i].oil[j]-=100;
	for(i=1;i<=my[5].num;i++){
		for(j=1;j<=num_my;j++){
			for(k=1;k<=my[j].num;k++){
				if(abs(my[j].a[k]-my[5].a[i])+abs(my[j].b[k]-my[5].b[i])<=my[5].max_attack) my[j].oil[k]+=200;				
			}
		}
	}
	clrmous(MouseX,MouseY);
	delay(100);
	return 0;
}