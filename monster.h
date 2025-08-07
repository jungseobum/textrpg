#ifndef MONSTER_H
#define MONSTER_H

typedef struct {
    char name[20];
    int hp, max_hp, atk, def, exp, gold;
} Monster;

Monster generate_monster(int player_level);

#endif
