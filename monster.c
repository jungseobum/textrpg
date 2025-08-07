#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monster.h"

Monster generate_monster(int player_level) {
    Monster m;
    int type = rand() % 3;  // 3종류 몬스터

    if (type == 0) strcpy(m.name, "slime");
    else if (type == 1) strcpy(m.name, "goblin");
    else strcpy(m.name, "wolf");

    // 플레이어 레벨 기반으로 능력치 증가
    m.hp = 10 + player_level * 5;
    m.max_hp = m.hp;
    m.atk = 3 + player_level * 2;
    m.def = 1 + player_level;
    m.exp = 20 + player_level * 5;
    m.gold = 10 + player_level * 2;

    return m;
}
