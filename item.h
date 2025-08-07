#ifndef ITEM_H
#define ITEM_H

#include "player.h"

typedef enum {
    ITEMTYPE_CONSUMABLE,  // 포션 같은 소비 아이템
    ITEMTYPE_EQUIPMENT,   // 무기/방어구
    ITEMTYPE_MISC         // 퀘스트/기타
} ItemCategory;

typedef struct {
    int id;               // 아이템 고유 ID
    char name[30];
    char desc[100];
    ItemCategory category;
    int value;            // 회복량 or 능력치 or 용도
    int price;
} Item;

typedef struct {
    Item* item;
    int count;
} InventorySlot;

#define MAX_ITEMS 50

// 함수 선언
Item* get_item_by_id(int id);
void add_item(InventorySlot* inventory, int id, int count);
void use_consumable(Player* p, int slot);
void show_inventory(Player* p);

// 전역 인벤토리
extern InventorySlot consumables[MAX_ITEMS];
extern InventorySlot equipments[MAX_ITEMS];
extern InventorySlot misc_items[MAX_ITEMS];

#endif