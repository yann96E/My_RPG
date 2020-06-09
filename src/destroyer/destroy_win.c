/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#include "../../lib/my/my.h"
#include "../../include/my_rpg.h"

void destroy_win(window_t *win)
{
    sfRenderWindow_destroy(win->window);
}
