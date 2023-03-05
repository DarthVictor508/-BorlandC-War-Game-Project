#include<common.h>
#include<enturn.h>

/*
�з��غϺ���
*/
int enturn(struct unit my[], struct unit en[]) {
	int en_atk[15] = {0};            //���������ĵз���λ��Ϣ
	struct ab_atk able[15];
	en_search(my, en, en_atk, able);
	en_print_atk(my, en, en_atk, able);
	en_p_dis_blood(my, en, able);
	return 1;
}



/*
�з���̨����������λ����
*/
void en_search(struct unit my[], struct unit en[],int en_atk[], struct ab_atk able[]) {
	int i, j;                  //i������̨����Ϣ ��j��������λ
	int t, flag1 = 0;          //s[t]��¼�ѱ������Ĺ�����λ  flag1=1 :�õ�λ�ѱ�����������ĵ�λ  flag1=0��δ������
	int s[15] = { 0 };         //��¼�ѱ������ĵ�λ 
	int n, flag2 = 0;          //flag1=1 :�õз���λ�ѹ���  flag1=0���õз���λδ����
	int m, k;                  //m�����ѱ������ĵ�λ
	    //���汾�غϹ����ĵ�λ
	t = k = n = 0;        


	for (i = 0; i < 15; i++) {      //��ʼ�� 
		able[i].x = 0;
		able[i].y = 0;
	}


	for (i = 1; i <= en[2].num; i++) {    //��������̨���б���    
		for (j = 1; j <= 5; j++) {     //���������ɻ���λ
			for (m = 0; m < t; m++) {
				if (s[m] == j) {
					flag1 = 1;
					break;
				}
				else flag1 = 0;
			}
			if (abs(my[3].a[j] - en[2].a[i]) <= en[2].max_attack && abs(my[3].b[j] - en[2].b[i]) <= en[2].max_attack && flag1 == 0) {
				able[k].x = my[3].a[j];
				able[k].y = my[3].b[j];
				able[k].code = j;
				able[k].type = 3;
				k++;
				s[t] = j;
				t++;
				en_atk[n] = i;
				n++;
				break;
			}
		}
	}

	for (i = 0; i < 15; i++) {
		s[i] = 0;
	}
	t = 0;
	flag1 = 0;

	if (n <= en[2].num) {
		for (i = 1; i <= en[2].num; i++) {    //��������̨���б���
			for (m = 0; m <= n; m++) {
				if (en_atk[m] == i) {
					flag2 = 1;
					break;
				}
				else flag2 = 0;
			}
			if (flag2 == 1) continue;
			else {

				for (j = 1; j <= 5; j++) {     //����̹�˵�λ

					for (m = 0; m <= t; m++) {
						if (s[m] == j) {
							flag1 = 1;
							break;
						}
						else flag1 = 0;
					}
					if (abs(my[2].a[j] - en[2].a[i]) <= en[2].max_attack && abs(my[2].b[j] - en[2].b[i]) <= en[2].max_attack && flag1 == 0) {

						able[k].x = my[2].a[j];
						able[k].y = my[2].b[j];
						able[k].code = j;
						able[k].type = 2;
						k++;
						s[t] = j;
						t++;
						en_atk[n] = i;
						n++;
						break;
					}
				}
			}
		}
	}

	for (i = 0; i < 15; i++) {
		s[i] = 0;
	}
	t = 0;
	flag1 = 0;

	if (n <= en[2].num) {
		for (i = 1; i <= en[2].num; i++) {    //��������̨���б���
			for (m = 0; m <= n; m++) {
				if (en_atk[m] == i) {
					flag2 = 1;
					break;
				}
				else flag2 = 0;
			}
			if (flag2 == 1) continue;
			else {

				for (j = 1; j <= 7; j++) {     //����ʿ����λ

					for (m = 0; m <= t; m++) {
						if (s[m] == j) {
							flag1 = 1;
							break;
						}
						else flag1 = 0;
					}
					if (abs(my[1].a[j] - en[2].a[i]) <= en[2].max_attack && abs(my[1].b[j] - en[2].b[i]) <= en[2].max_attack && flag1 == 0) {

						able[k].x = my[1].a[j];
						able[k].y = my[1].b[j];
						able[k].code = j;
						able[k].type = 1;
						k++;
						s[t] = j;
						t++;
						en_atk[n] = i;
						n++;
						break;
					}
				}
			}
		}
	}

	for (i = 0; i < 15; i++) {
		s[i] = 0;
	}
	t = 0;
	flag1 = 0;

	if (n <= en[2].num) {
		for (i = 1; i <= en[2].num; i++) {    //��������̨���б���
			for (m = 0; m <= n; m++) {
				if (en_atk[m] == i) {
					flag2 = 1;
					break;
				}
				else flag2 = 0;
			}
			if (flag2 == 1) continue;
			else {

				for (j = 1; j <= 5; j++) {     //�������䴬��λ

					for (m = 0; m <= t; m++) {
						if (s[m] == j) {
							flag1 = 1;
							break;
						}
						else flag1 = 0;
					}
					if (abs(my[4].a[j] - en[2].a[i]) <= en[2].max_attack && abs(my[4].b[j] - en[2].b[i]) <= en[2].max_attack && flag1 == 0) {

						able[k].x = my[4].a[j];
						able[k].y = my[4].b[j];
						able[k].code = j;
						able[k].type = 4;
						k++;
						s[t] = j;
						t++;
						en_atk[n] = i;
						n++;
						break;
					}
				}
			}
		}
	}

	for (i = 0; i < 15; i++) {
		s[i] = 0;
	}
	t = 0;
	flag1 = 0;

	if (n <= en[2].num) {
		for (i = 1; i <= en[2].num; i++) {    //��������̨���б���
			for (m = 0; m <= n; m++) {
				if (en_atk[m] == i) {
					flag2 = 1;
					break;
				}
				else flag2 = 0;
			}
			if (flag2 == 1) continue;
			else {

				for (j = 1; j <= 5; j++) {     //����֧Ԯ����λ

					for (m = 0; m <= t; m++) {
						if (s[m] == j) {
							flag1 = 1;
							break;
						}
						else flag1 = 0;
					}
					if (abs(my[5].a[j] - en[2].a[i]) <= en[2].max_attack && abs(my[5].b[j] - en[2].b[i]) <= en[2].max_attack && flag1 == 0) {

						able[k].x = my[5].a[j];
						able[k].y = my[5].b[j];
						able[k].code = j;
						able[k].type = 5;
						k++;
						s[t] = j;
						t++;
						en_atk[n] = i;
						n++;
						break;
					}
				}
			}
		}
	}

}

void en_print_atk(struct unit my[], struct unit en[], int en_atk[], struct ab_atk able[]) {
	int i;
	for (i = 0; i < en[2].num; i++) {
		if (able[i].x == 0) break;
		delay(500);
		print_atk(en[2].x[en_atk[i]], en[2].y[en_atk[i]], able[i].x * 40-20 , able[i].y * 40-20 );
		delay(100);
		cleardevice;
	}
}

void en_p_dis_blood(struct unit my[], struct unit en[], struct ab_atk able[]) {
	int i,j;
	for (i = 0; i < en[2].num; i++) {
		if (able[i].x == 0) {
			break;
		}
		my[able[i].type].hp[able[i].code] -= en[2].atk;
	}
}
