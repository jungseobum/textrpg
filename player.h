#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    char name[20];
    int hp, max_hp;
    int atk, def;
    int exp, level;
    int x, y;  // 맵 위치
    int gold;
} Player;

void init_player(Player *p, const char *name);
void show_menu(Player *p);
void show_inventory();

#endif
