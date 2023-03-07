#ifndef _ENTURN_H
#define _ENTURN_H

#include"common.h"
#include"anime.h"

struct ab_atk {
    int x;   //被搜到的攻击单位格子坐标
    int y;
    int code;
    int type;
};

int enturn(struct unit my[], struct unit en[]);
void en_p_search(struct unit my[], struct unit en[], int en_atk[], struct ab_atk able[]);
void en_print_atk(struct unit my[], struct unit en[],int en_atk[], struct ab_atk able[]);
void en_p_dis_blood(struct unit my[], struct unit en[], struct ab_atk able[]);

#endif
