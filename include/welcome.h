#ifndef _WELCOME_H
#define _WELCOME_H

#include "common.h"
#include "info.h"

int welcome(char *s);
void place(int(*map_type)[13+3], struct unit my[],struct unit en[],int num_my,int num_en);
void teach(int(*map_type)[13 + 3], struct unit my[], struct unit en[], int num_my, int num_en);

#endif
