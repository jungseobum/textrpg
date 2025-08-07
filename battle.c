#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "battle.h"
#include "util.h"

float rand_multiplier() {
    return 0.8f + ((float)rand() / RAND_MAX) * 0.7f; // 0.8 ~ 1.5
}

void battle(Player *p, Monster *m) {
    printf("\n=== Battle! ===\n%s appeared!\n\n", m->name);

    while (p->hp > 0 && m->hp > 0) {
        //printf("\n[Player] HP:%d / [Monster] %s HP:%d\n", p->hp, m->name, m->hp);
        printf("Player: %d/%d ", p->hp, p->max_hp);
        print_hp_bar(p->hp, p->max_hp);
        printf("%s: %d/%d ", m->name, m->hp, m->max_hp);
        print_hp_bar(m->hp, m->max_hp);
        printf("\n1. Attack  2. Runaway\n> ");
        int choice;
        scanf("%d", &choice);

        if (choice == 2) {
            printf("Ran away!\n");
            printf("\nPress any key to continue...\n");
            _getch();
            return;
        }

        // 플레이어 공격
        int dmg = p->atk*rand_multiplier() - m->def;
        if (dmg < 1) dmg = 1;
        m->hp -= dmg;
        printf("\nYou gave %d Damage to %s!\n", dmg, m->name);

        if (m->hp <= 0) break;

        // 몬스터 반격
        dmg = m->atk*rand_multiplier() - p->def;
        if (dmg < 1) dmg = 1;
        p->hp -= dmg;
        printf("%s gave you %d Damage!\n\n", m->name, dmg);
    }

    if (p->hp > 0) {
        printf("\nWin! EXP +%d, Gold +%d\n", m->exp,m->gold);
        p->exp += m->exp;
        p->gold += m->gold;
        // 레벨업 체크
        if (p->exp >= p->level * 100) {
            p->level++;
            p->max_hp += 10;
            p->atk += 2;
            p->def += 1;
            p->hp = p->max_hp;
            printf("Level up! Now level: %d\n", p->level);
        }
        printf("\nPress any key to continue...\n");
        _getch();
    } else {
        printf("\nDied... Game Over\n");
        exit(0);
    }
}
