#ifndef _MYTURN_H
#define _MYTURN_H

#include<common.h>

struct node{
	int x,y,rest;
};
void bfs(struct unit x,int num,int (*map_type)[13+3],int (*f)[13+3],struct unit my[],struct unit en[],int num_my,int num_en);
int myturn(int (*map_type)[13+3],struct unit my[],struct unit en[],int num_my,int num_en);

#endif
