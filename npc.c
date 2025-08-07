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

