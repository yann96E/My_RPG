/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_inventory
*/

#include "my_rpg.h"

inventory_t *create_inventory(window_t *win, bool is_chest)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (!inventory) return (NULL);
    inventory->is_chest = is_chest;
    for (char i = 0; i < INVENTORY_SIZE; ++i) {
        inventory->tab[i].sprite = NULL;
        inventory->tab[i].nb = 0;
        inventory->tab[i].value = 0;
    }
    return (inventory);
}

void print_inventory(window_t *win, inventory_t *inventory,
                     sfVector2f const pos)
{
    sfVector2f item_pos = {pos.x, pos.y};

    sfSprite_setPosition(win->inventory, pos);
    display_sprite(win, win->inventory);
    for (char i = 0; i < INVENTORY_SIZE; ++i) {
        if (inventory->tab[i].sprite)
            sfSprite_setPosition(inventory->tab[i].sprite, item_pos);
        item_pos.x += 72;
        if (i == 9 || i == 18 || i == 27) {
            item_pos.y += 72;
            item_pos.x = pos.x;
        }
    }
}
