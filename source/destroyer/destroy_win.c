/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#include "source.h"

void destroy_win(window_t *win)
{
    sfRenderWindow_destroy(win->window);
}
