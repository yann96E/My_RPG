/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map_actions
*/

#include "my_rpg.h"

void remove_tile(tile_t **tile)
{
    freeif(*tile);
    *tile = NULL;
}

void remove_ground(tile_t **tile, u_int8_t ground)
{
    int count = 0;

    printf("%d\n", ground);
    if (!*tile) return;
    (*tile)->sprite[ground] = NULL;
    (*tile)->rect[ground] = (sfIntRect){0, 0, 0, 0};
    for (u_int8_t i = 0; i < NB_GROUNDS; ++i)
        count += ((*tile)->sprite[i] != NULL);
    if (count == 0)
        remove_tile(tile);
}

static tile_t *init_tile(void)
{
    tile_t *tile = malloc(sizeof(tile_t));

    if (!tile)
        return (NULL);
    tile->sprite[bg] = NULL;
    tile->sprite[fg] = NULL;
    return (tile);
}

bool add_tile(tile_t **tile, sfSprite *sprite, sfIntRect rect, u_int8_t flag)
{
    if (flag >= NB_GROUNDS)
        return (true);
    if (!*tile)
        if (!(*tile = init_tile()))
            return (true);
    (*tile)->sprite[flag] = sprite;
    (*tile)->rect[flag] = rect;
    (*tile)->stackable = true;
    return (false);
}
