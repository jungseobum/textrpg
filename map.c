#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "npc.h"

#define H 10
#define W 20

char get_npc_symbol(NpcType type) {
    if (type == NPC_SHOP) return 'S';
    if (type == NPC_QUEST) return 'Q';
    if (type == NPC_HEALER) return 'H';
    return 'N';
}

int is_npc_at(int x, int y, int* index) {
    for (int i = 0; i < npc_count; i++) {
        if (npc_list[i].x == x && npc_list[i].y == y) {
            if (index) *index = i;
            return 1;
        }
    }
    return 0;
}

// 간단한 맵 (벽:#, 길:.)
char map[H][W + 1] = {
    "###################",
    "#.................#",
    "#.....#####.......#",
    "#.................#",
    "#.................#",
    "#.................#",
    "#.................#",
    "#.................#",
    "#.................#",
    "###################"
};

void draw_map(Player *p) {
    system("cls"); // 윈도우: cls, 리눅스/맥: clear
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == p->y && j == p->x)
                printf("&"); // 플레이어
            else {
                int idx;
                if (is_npc_at(j, i, &idx))
                    printf("%c", get_npc_symbol(npc_list[idx].type));
                else
                    printf("%c", map[i][j]);
            }
           
        printf("\n");
    }
    printf("\nmove: w/a/s/d | quit: q | menu: m\n");
}

void interact_with_npc(Player* p) {
    for (int i = 0; i < npc_count; i++) {
        if (abs(p->x - npc_list[i].x) + abs(p->y - npc_list[i].y) == 1) {
            printf("You talk to %s.\n", npc_list[i].name);
            if (npc_list[i].type == NPC_SHOP)
                open_consumable_shop(p);
            else if (npc_list[i].type == NPC_HEALER)
                printf("%s heals you!\n", npc_list[i].name), p->hp = p->max_hp;
            else if (npc_list[i].type == NPC_QUEST)
                printf("%s gives you a quest!\n", npc_list[i].name);
            return;
        }
    }
    printf("No one to talk to.\n");
}

int move_player(Player *p) {
    char input;
    scanf(" %c", &input);

    if (input == 'e') { interact_with_npc(p); return 0; }

    if (input == 'q') {
        printf("quit the game.\n");
        exit(0);
    }

    if (input == 'm') {           // 메뉴 열기
        show_menu(p);
        return 0;
    }

    int nx = p->x, ny = p->y;
    if (input == 'w') ny--;
    if (input == 's') ny++;
    if (input == 'a') nx--;
    if (input == 'd') nx++;

    // 벽이 아니면 이동
    if (map[ny][nx] != '#') {
        p->x = nx;
        p->y = ny;
    }

    // 일정 확률로 전투 조우
    return (rand() % 5 == 0); // 1/7 확률
}
