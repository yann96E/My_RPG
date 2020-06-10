/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#include "source.h"

void destroy_intro(window_t *win)
{
    sfTexture_destroy(win->intro->T_logo);
    sfTexture_destroy(win->intro->T_back_0);
    sfTexture_destroy(win->intro->T_back_1);
    sfSprite_destroy(win->intro->S_logo);
    sfSprite_destroy(win->intro->S_back_0);
    sfSprite_destroy(win->intro->S_back_1);
    sfText_destroy(win->intro->text);
    sfFont_destroy(win->intro->font);
}
