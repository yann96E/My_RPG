/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#include "source.h"

void set_sprite_pos(sfSprite *sprite, int x, int y)
{
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
}
