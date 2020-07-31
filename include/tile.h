/*
** EPITECH PROJECT, 2020
** tile
** File description:
** tile
*/

#include "lib.h"

#ifndef __TILE__
#define __TILE__

#define NB_GROUNDS 2

typedef enum grounds {bg, fg} grounds;

typedef struct tile_s
{
    bool stackable;
    sfSprite *sprite[NB_GROUNDS];
    sfIntRect rect[NB_GROUNDS];
} tile_t;

#endif /*__TILE__*/
