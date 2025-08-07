#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "battle.h"
#include "player.h"

int main() {
    srand(time(NULL));

    Player hero;
    init_player(&hero, "HERO");

    printf("==== Text RPG ====\n");
    printf("Name: %s | HP: %d | ATK: %d | DEF: %d\n",
           hero.name, hero.hp, hero.atk, hero.def);
    printf("w/a/s/d to move, q to quit, m for menu\n");

    while (1) {
        draw_map(&hero);
        int encounter = move_player(&hero);
        if (encounter) {
            Monster m = generate_monster(hero.level);
            battle(&hero, &m);
        }
        if (hero.hp <= 0) {
            printf("game over...\n");
            break;
        }
    }
    return 0;
}