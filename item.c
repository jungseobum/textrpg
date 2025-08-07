#include <stdio.h>
#include <string.h>
#include "item.h"
#include "player.h"

InventorySlot consumables[MAX_ITEMS] = {0};
InventorySlot equipments[MAX_ITEMS] = {0};
InventorySlot misc_items[MAX_ITEMS] = {0};

static Item item_db[] = {
    {0, "Potion", "Restores 20 HP", ITEMTYPE_CONSUMABLE, 20, 10},
    {1, "Elixir", "Fully restores HP", ITEMTYPE_CONSUMABLE, 9999, 50},
    {2, "Iron Sword", "Basic weapon. ATK+3", ITEMTYPE_EQUIPMENT, 3, 30},
    {3, "Quest Item", "Important for quest.", ITEMTYPE_MISC, 0, 0}
};
static int item_db_size = sizeof(item_db) / sizeof(item_db[0]);

Item* get_item_by_id(int id) {
    for (int i = 0; i < item_db_size; i++) {
        if (item_db[i].id == id) return &item_db[i];
    }
    return NULL;
}

void add_item(InventorySlot* inventory, int id, int count) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i].item && inventory[i].item->id == id) {
            inventory[i].count += count;
            return;
        }
    }
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (!inventory[i].item) {
            inventory[i].item = get_item_by_id(id);
            inventory[i].count = count;
            return;
        }
    }
}

void use_consumable(Player* p, int slot) {
    if (!consumables[slot].item || consumables[slot].count <= 0) return;
    Item* item = consumables[slot].item;
    if (item->category == ITEMTYPE_CONSUMABLE) {
        p->hp += item->value;
        if (p->hp > p->max_hp) p->hp = p->max_hp;
        consumables[slot].count--;
        printf("You used %s. HP: %d/%d\n", item->name, p->hp, p->max_hp);
    }
}
