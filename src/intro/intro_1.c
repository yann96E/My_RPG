/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#include "../../include/my_rpg.h"

static void move_box(window_t *win)
{
    static int pos = 500;
    static int status = 1;

    if (status == 1) {
        if (pos == 400)
            status = 2;
        else
            sfSprite_setPosition(win->intro->S_back_1,
                (sfVector2f){983, --pos});
    }
    if (status == 2) {
        if (pos == 500)
            status = 1;
        else
            sfSprite_setPosition(win->intro->S_back_1,
                (sfVector2f){983, ++pos});
    }
}

void display_intro(window_t *win)
{
    sfRenderWindow_drawText(win->window, win->intro->text, NULL);
    display_sprite(win, win->intro->S_back_0);
    display_sprite(win, win->intro->S_back_1);
    display_sprite(win, win->intro->S_logo);
    sfClock_restart(win->win_clock->clock);
    move_box(win);
    sfRenderWindow_display(win->window);
}
