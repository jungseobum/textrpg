/*
#include <stdio.h>
#include <string.h>
#include "npc.h"

#define MAX_NPC 20
NPC npc_list[MAX_NPC];
int npc_count = 0;

void add_npc(int x, int y, NpcType type, const char* name) {
    npc_list[npc_count].x = x;
    npc_list[npc_count].y = y;
    npc_list[npc_count].type = type;
    strcpy(npc_list[npc_count].name, name);
    npc_count++;
}
*/
#include <string.h>
#include <stdlib.h>
#include "npc.h"

#define MAX_NPC 20
static NPC g_npcs[MAX_NPC];
static int g_cnt = 0;

void npc_init(void){ g_cnt = 0; }

void npc_add(int x, int y, NpcType type, const char* name){
    if (g_cnt >= MAX_NPC) return;
    g_npcs[g_cnt] = (NPC){ x, y, type, {0} };
    strncpy(g_npcs[g_cnt].name, name, sizeof(g_npcs[g_cnt].name)-1);
    g_cnt++;
}

int npc_count(void){ return g_cnt; }

const NPC* npc_get(int idx){ return (idx>=0 && idx<g_cnt)? &g_npcs[idx] : NULL; }

int npc_find_at(int x, int y){
    for (int i=0;i<g_cnt;i++) if (g_npcs[i].x==x && g_npcs[i].y==y) return i;
    return -1;
}

int npc_adjacent_index(int px, int py){
    for (int i=0;i<g_cnt;i++){
        int dx=abs(px-g_npcs[i].x);
        int dy=abs(py-g_npcs[i].y);
        if (dx+dy==1) return i;
    }
    return -1;
}

char npc_symbol(NpcType t){
    switch (t){
        case NPC_SHOP:  return 'S';
        case NPC_HEALER:return 'H';
        case NPC_QUEST: return 'Q';
        default:        return 'N';
    }
}
