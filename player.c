#include <string.h>
#include <stdio.h>
#include <conio.h>
#include "player.h"
#include "util.h"
#include "item.h"

void init_player(Player *p, const char *name) {
    strcpy(p->name, name);
    p->max_hp = 30;
    p->hp = p->max_hp;
    p->atk = 5;
    p->def = 2;
    p->exp = 0;
    p->level = 1;
    p->x = 1;
    p->y = 1;
    p->gold = 500;
}

void show_player_status(Player *p) {
    printf("\n==== STATUS ====\n");
    printf("Name : %s\n", p->name);
    printf("Level: %d\n", p->level);
    printf("HP   : %d / %d ", p->hp, p->max_hp);
    print_hp_bar(p->hp,p->max_hp);

    printf("ATK  : %d\n", p->atk);
    printf("DEF  : %d\n", p->def);
    printf("EXP  : %d / %d\n", p->exp, p->level * 100);
    printf("================\n");
    printf("\nPress any key to continue...\n");
            _getch();
}

void show_inventory(Player* p) {
    int choice;
    while (1) {
        printf("\n=== Inventory ===\n");
        printf("1. Consumables\n2. Equipment\n3. Misc\n4. Exit\n> ");
        scanf("%d", &choice);
        getchar();
        if (choice == 1) {
            printf("\n-- Consumables --\n");
            for (int i = 0; i < MAX_ITEMS; i++) {
                if (consumables[i].item)
                    printf("%d. %s (x%d)\n", i+1, consumables[i].item->name, consumables[i].count);
            }
            printf("Select item to use (0 to cancel): ");
            int slot;
            scanf("%d", &slot);
            getchar();
            if (slot > 0) use_consumable(p, slot - 1);
        }
        else if (choice == 2) {
            printf("\n-- Equipment --\n");
            for (int i = 0; i < MAX_ITEMS; i++) {
                if (equipments[i].item)
                    printf("%d. %s\n", i+1, equipments[i].item->name);
            }
            printf("(Equipment system not yet implemented)\n");
        }
        else if (choice == 3) {
            printf("\n-- Misc Items --\n");
            for (int i = 0; i < MAX_ITEMS; i++) {
                if (misc_items[i].item)
                    printf("%d. %s\n", i+1, misc_items[i].item->name);
            }
        }
        else if (choice == 4) break;
    }
}


void show_menu(Player *p) {
    while (1) {
        printf("\n==== MENU ====\n");
        printf("1. Status\n");
        printf("2. Inventory\n");
        printf("3. Exit Menu\n");
        printf("Select: ");
        int choice;
        scanf("%d", &choice);
        getchar();  // 버퍼 비우기

        if (choice == 1) {
            show_player_status(p);
        } else if (choice == 2) {
            show_inventory(p);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
}