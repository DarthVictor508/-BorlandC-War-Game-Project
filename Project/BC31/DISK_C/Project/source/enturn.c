#include<common.h>
#include<enturn.h>

/*
敌方回合函数
lpc写的
*/
int enturn(int (*map_type)[13 + 3],struct unit my[], struct unit en[],int num_my) {
	int en_atk[20] = {0}; //发出攻击的敌方单位信息
	struct ab_atk able[20];
	int i,j,dea_my=0;
	en_turn(); //更新侧边栏
	mine_boom(my, en, num_my);
	en_p_search(my, en, en_atk, able);
	en_print_atk(my, en, en_atk, able,num_my, map_type);
	en_p_dis_blood(my, en, able);

	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= my[i].num; j++) {
			if (my[i].hp[j] <= 0 || my[i].oil[j]<=0) {
				dea_my++;
			}
		}
	}
	if (dea_my == (my[1].num + my[2].num + my[3].num)) return 0; //表示游戏失败
	return 1; //游戏继续
}

/*
敌方炮台搜索攻击单位函数
lpc写的
*/
void en_p_search(struct unit my[], struct unit en[],int en_atk[], struct ab_atk able[]) {
	int i, j;                  //i代表炮台号信息 ，j代表攻击单位
	int t, flag1 = 0;          //s[t]记录已被搜索的攻击单位  flag1=1 :该单位已被搜索并储存的单位  flag1=0：未被储存
	int s[20] = { 0 };         //记录已被搜索的单位 
	int n, flag2 = 0;          //flag1=1 :该敌方单位已攻击  flag1=0：该敌方单位未攻击
	int m, k;                  //m查找已被搜索的单位
	//储存本回合攻击的单位
	t = k = n = 0;        


	for (i = 0; i < 20; i++) { //初始化 
		able[i].x = 0;
		able[i].y = 0;
	}


	for (i = 1; i <= en[2].num; i++) { //对所有炮台进行遍历    
		for (j = 1; j <= my[3].num; j++) { //首先搜索飞机单位
			for (m = 0; m < t; m++) {
				if (s[m] == j) {
					flag1 = 1;
					break;
				}
				else flag1 = 0;
			}
			if (abs(my[3].a[j] - en[2].a[i]) <= en[2].max_attack && abs(my[3].b[j] - en[2].b[i]) <= en[2].max_attack && flag1 == 0 && my[3].hp[j]>0 && my[3].oil[j]>0&& en[2].hp[i]>0) {
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

	for (i = 0; i < 20; i++) {
		s[i] = 0;
	}
	t = 0;
	flag1 = 0;

	if (n <= en[2].num) {
		for (i = 1; i <= en[2].num; i++) { //对所有炮台进行遍历
			for (m = 0; m <= n; m++) {
				if (en_atk[m] == i) {
					flag2 = 1;
					break;
				}
				else flag2 = 0;
			}
			if (flag2 == 1) continue;
			else {

				for (j = 1; j <= my[2].num; j++) { //搜索坦克单位

					for (m = 0; m <= t; m++) {
						if (s[m] == j) {
							flag1 = 1;
							break;
						}
						else flag1 = 0;
					}
					if (abs(my[2].a[j] - en[2].a[i]) <= en[2].max_attack && abs(my[2].b[j] - en[2].b[i]) <= en[2].max_attack && flag1 == 0 && my[2].hp[j] > 0 && my[2].oil[j] > 0 && en[2].hp[i] > 0&& (!my[2].ported[j])) {

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

	for (i = 0; i < 20; i++) {
		s[i] = 0;
	}
	t = 0;
	flag1 = 0;

	if (n <= en[2].num) {
		for (i = 1; i <= en[2].num; i++) { //对所有炮台进行遍历
			for (m = 0; m <= n; m++) {
				if (en_atk[m] == i) {
					flag2 = 1;
					break;
				}
				else flag2 = 0;
			}
			if (flag2 == 1) continue;
			else {

				for (j = 1; j <= my[1].num; j++) { //搜索士兵单位

					for (m = 0; m <= t; m++) {
						if (s[m] == j) {
							flag1 = 1;
							break;
						}
						else flag1 = 0;
					}
					if (abs(my[1].a[j] - en[2].a[i]) <= en[2].max_attack && abs(my[1].b[j] - en[2].b[i]) <= en[2].max_attack && flag1 == 0 && my[1].hp[j] > 0&& my[1].oil[j] > 0&& en[2].hp[i] > 0 && (!my[1].ported[j])) {

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

	for (i = 0; i < 20; i++) {
		s[i] = 0;
	}
	t = 0;
	flag1 = 0;

	if (n <= en[2].num) {
		for (i = 1; i <= en[2].num; i++) { //对所有炮台进行遍历
			for (m = 0; m <= n; m++) {
				if (en_atk[m] == i) {
					flag2 = 1;
					break;
				}
				else flag2 = 0;
			}
			if (flag2 == 1) continue;
			else {

				for (j = 1; j <= my[4].num; j++) { //搜索运输船单位

					for (m = 0; m <= t; m++) {
						if (s[m] == j) {
							flag1 = 1;
							break;
						}
						else flag1 = 0;
					}
					if (abs(my[4].a[j] - en[2].a[i]) <= en[2].max_attack && abs(my[4].b[j] - en[2].b[i]) <= en[2].max_attack && flag1 == 0 && my[4].hp[j] > 0&&my[4].oil[j] > 0 && en[2].hp[i] > 0) {

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

	for (i = 0; i < 20; i++) {
		s[i] = 0;
	}
	t = 0;
	flag1 = 0;

	if (n <= en[2].num) {
		for (i = 1; i <= en[2].num; i++) {    //对所有炮台进行遍历
			for (m = 0; m <= n; m++) {
				if (en_atk[m] == i) {
					flag2 = 1;
					break;
				}
				else flag2 = 0;
			}
			if (flag2 == 1) continue;
			else {

				for (j = 1; j <= my[5].num; j++) { //搜索支援兵单位

					for (m = 0; m <= t; m++) {
						if (s[m] == j) {
							flag1 = 1;
							break;
						}
						else flag1 = 0;
					}
					if (abs(my[5].a[j] - en[2].a[i]) <= en[2].max_attack && abs(my[5].b[j] - en[2].b[i]) <= en[2].max_attack && flag1 == 0 && my[5].hp[j] > 0&&my[5].oil[j] > 0 && en[2].hp[i] > 0&& (!my[5].ported[j])) {

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


/*
打印敌方炮台攻击动画函数
lpc写的
*/
void en_print_atk(struct unit my[], struct unit en[], int en_atk[], struct ab_atk able[],int num_my, int(*map_type)[13 + 3]) {
	int i;
	for (i = 0; i < en[2].num; i++) {
		if (able[i].x == 0) break;
		delay(500);	
		print_map(map_type);
		print_my(my, num_my);
		print_en(en);
		print_atk(en[2].x[en_atk[i]]+20, en[2].y[en_atk[i]]+10, able[i].x * 40-20 , able[i].y * 40-20 );
		delay(100);
	}
}


/*
扣除我方单位被炮台攻击血量函数
lpc写的
*/
void en_p_dis_blood(struct unit my[], struct unit en[], struct ab_atk able[]) {
	int i,j;
	for (i = 0; i < en[2].num; i++) {
		if (able[i].x == 0) {
			break;
		}
		my[able[i].type].hp[able[i].code] -= en[2].atk;
	}
}


/*
敌方地雷攻击函数（含动画）
lpc写的
*/

void mine_boom(struct unit my[], struct unit en[], int num_my) {
	int i, j, k;
	for (i = 1; i <= num_my; i++) {
		if ((i == 3) || (i == 4)) continue;
		for (j = 1; j <= my[i].num; j++) {
			if (my[i].a[j] == en[5].a[1] && my[i].b[j] == en[5].b[1] && en[5].hp[1] > 0 &&(!my[i].ported[j])) {
				print_boom(en[5].x[1], en[5].y[1]);           //一号雷爆炸
				puthz(en[5].x[1], en[5].y[1], en[5].name, 16, 17, RED);
				delay(500);
				my[i].hp[j] -= en[5].atk;
				en[5].hp[1] = 0;
			}

			if (my[i].a[j] == en[5].a[2] && my[i].b[j] == en[5].b[2] && en[5].hp[2] > 0&&(!my[i].ported[j])) {
				print_boom(en[5].x[2], en[5].y[2]);           //二号雷爆炸
				puthz(en[5].x[2], en[5].y[2], en[5].name, 16, 17, RED);
				delay(500);
				my[i].hp[j] -= en[5].atk;
				en[5].hp[2] = 0;
			}

			if (my[i].a[j] == en[5].a[3] && my[i].b[j] == en[5].b[3] && en[5].hp[3] > 0&&(!my[i].ported[j])) {
				print_boom(en[5].x[3], en[5].y[3]);           //三号雷爆炸
				puthz(en[5].x[3], en[5].y[3], en[5].name, 16, 17, RED);
				delay(500);
				my[i].hp[j] -= en[5].atk;
				en[5].hp[3] = 0;
			}

			if (my[i].a[j] == en[5].a[4] && my[i].b[j] == en[5].b[4] && en[5].hp[4] > 0&&(!my[i].ported[j])) {
				print_boom(en[5].x[4], en[5].y[4]);          //四号雷爆炸
				puthz(en[5].x[4], en[5].y[4], en[5].name, 16, 17, RED);
				delay(500);
				my[i].hp[j] -= en[5].atk;
				en[5].hp[4] = 0;
			}

			if (en[5].num == 8) {

				if (my[i].a[j] == en[5].a[5] && my[i].b[j] == en[5].b[5] && en[5].hp[5] > 0 && (!my[i].ported[j])) {
					print_boom(en[5].x[5], en[5].y[5]);          //五号雷爆炸
					puthz(en[5].x[5], en[5].y[5], en[5].name, 16, 17, RED);
					delay(500);
					my[i].hp[j] -= en[5].atk;
					en[5].hp[5] = 0;
				}

				if (my[i].a[j] == en[5].a[6] && my[i].b[j] == en[5].b[6] && en[5].hp[6] > 0 && (!my[i].ported[j])) {
					print_boom(en[5].x[6], en[5].y[6]);          //六号雷爆炸
					puthz(en[5].x[6], en[5].y[6], en[5].name, 16, 17, RED);
					delay(500);
					my[i].hp[j] -= en[5].atk;
					en[5].hp[6] = 0;
				}

				if (my[i].a[j] == en[5].a[7] && my[i].b[j] == en[5].b[7] && en[5].hp[7] > 0 && (!my[i].ported[j])) {
					print_boom(en[5].x[7], en[5].y[7]);          //七号雷爆炸
					puthz(en[5].x[7], en[5].y[7], en[5].name, 16, 17, RED);
					delay(500);
					my[i].hp[j] -= en[5].atk;
					en[5].hp[7] = 0;
				}

				if (my[i].a[j] == en[5].a[8] && my[i].b[j] == en[5].b[8] && en[5].hp[8] > 0 && (!my[i].ported[j])) {
					print_boom(en[5].x[8], en[5].y[8]);          //八号雷爆炸
					puthz(en[5].x[8], en[5].y[8], en[5].name, 16, 17, RED);
					delay(500);
					my[i].hp[j] -= en[5].atk;
					en[5].hp[8] = 0;
				}
			}
		}
	}
}