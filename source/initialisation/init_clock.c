/*
** EPITECH PROJECT, 2020
** init_clock
** File description:
** init_clock
*/

#include "source.h"

win_clock_t *init_clock(void)
{
    win_clock_t *win_clock = malloc(sizeof(win_clock_t));

    if (!win_clock) return (NULL);
    win_clock->clock = sfClock_create();
    if (!win_clock->clock) return (NULL);
    win_clock->second = 0;
    return (win_clock);
}
