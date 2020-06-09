/*
** EPITECH PROJECT, 2020
** touch_action
** File description:
** touch_action
*/

#include "my_rpg.h"

void tools_pickaxe(void *window, sfVector2i *pos)
{
    window_t *win = (window_t *)(window);

    win->player.remove = true;
}
