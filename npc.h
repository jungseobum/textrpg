
/*typedef enum {
    NPC_SHOP,
    NPC_QUEST,
    NPC_HEALER
} NpcType;

extern int npc_count;
extern int npc_list[20];

typedef struct {
    int x, y;
    NpcType type;
    char name[20];
} NPC;
*/
#ifndef NPC_H
#define NPC_H
typedef enum { NPC_SHOP, NPC_QUEST, NPC_HEALER } NpcType;
typedef struct { int x, y; NpcType type; char name[20]; } NPC;

void npc_init(void);
void npc_add(int x, int y, NpcType type, const char* name);

int  npc_count(void);
const NPC* npc_get(int idx);

int  npc_find_at(int x, int y);           // 해당 좌표의 NPC index, 없으면 -1
int  npc_adjacent_index(int px, int py);  // 플레이어 인접 NPC index, 없으면 -1
char npc_symbol(NpcType type);

#endif