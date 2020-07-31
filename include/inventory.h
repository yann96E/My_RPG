/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "lib.h"

typedef struct item_s {
    int value;
    int nb;
    sfSprite *sprite;
} item_t;

typedef struct inventory_s {
    bool is_chest;
    item_t tab[40];
} inventory_t;

#endif /* !ITEM_H_ */
