#include <stdio.h>
#include "util.h"

void print_hp_bar(int hp, int max_hp)
{
    if (hp*100/max_hp>50) printf("\x1b[32m"); // 초록
    else if (hp*100/max_hp>20) printf("\x1b[33m"); // 노랑
    else printf("\x1b[31m");
    int i=0;
    printf("[");
    for(i=0;i<hp*10/max_hp;i++) {printf("=");}
    for(;i<10;i++) {printf(" ");}
    printf("]\x1b[0m\n");
}