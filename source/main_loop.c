/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#include "source.h"

void refresh_time(win_clock_t *clock)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->second = sfTime_asSeconds(clock->time);
}

static void clock_handling(window_t *win, win_clock_t *clock)
{
    if (clock->second > 0.5) {
        sfClock_restart(clock->clock);
        win->player.time = 0;
        CLEAR_BIT(win->creative_mode, WAIT_CLOCK);
        CLEAR_BIT(win->is_on_pause, WAIT_CLOCK);
        win->player.life.is_hit = false;
        win->check_time += (win->check_time > 600) ? (-600) : (0.5);
        if (win->status == gameplay_)
            set_time_filter(win);
    }
    refresh_time(clock);
}

static void check_close_window(window_t *win)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
    }
}

void launch_game(window_t *win)
{
    static void (*scene[3])(window_t *win) = {&intro, &menu, &gameplay};

    sfClock_restart(win->win_clock->clock);
    while (sfRenderWindow_isOpen(win->window)) {
        sfRenderWindow_setKeyRepeatEnabled(win->window, sfTrue);
        sfRenderWindow_clear(win->window, sfBlack);
        check_close_window(win);
        scene[win->status](win);
        sfRenderWindow_display(win->window);
        clock_handling(win, win->win_clock);
        sfRenderWindow_setFramerateLimit(win->window, 60);
    }
    destroy_win(win);
}
