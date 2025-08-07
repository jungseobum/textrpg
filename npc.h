typedef enum {
    NPC_SHOP,
    NPC_QUEST,
    NPC_HEALER
} NpcType;

typedef struct {
    int x, y;
    NpcType type;
    char name[20];
} NPC;
