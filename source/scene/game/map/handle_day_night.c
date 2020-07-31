/*
** EPITECH PROJECT, 2020
** handle_day_night
** File description:
** handle_day_night
*/

#include "source.h"

static void change_night_day(window_t *win, unsigned char const alpha)
{
    change_fb(&win->fb, (unsigned char const[4]){0, 0, 0, alpha}, win->len);
    sfTexture_updateFromPixels(win->tx, win->fb,
    win->resolution.x, win->resolution.y, 0, 0);
    sfSprite_setTexture(win->day, win->tx, sfFalse);
}

void set_time_filter(window_t *win)
{
    if (win->check_time > 600) {
        win->check_time = 0;
        TOGGLE_BOOL(win->day_night);
    }
    if (win->day_night == day && win->check_time > 360 && win->fb[3] < 140)
        change_night_day(win, 1);
    else if (win->day_night == night && win->check_time < 360 && win->fb[3] > 0)
        change_night_day(win, -1);
}
