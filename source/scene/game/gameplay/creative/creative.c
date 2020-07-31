/*
** EPITECH PROJECT, 2020
** creative
** File description:
** creative
*/

#include "source.h"

void switch_player_creative(window_t *win)
{
    if (!BIT(win->creative_mode, 0)) {
        SET_BIT(win->creative_mode, 0);
        win->creative.tile_offset.x = win->player.tile_offset.x;
        win->creative.tile_offset.y = win->player.tile_offset.y;
        win->creative.pos.x = win->player.pos.x;
        win->creative.pos.y = win->player.pos.y;
        win->creative.control = create_control((char const [4]){sfKeyQ,
        sfKeyD, sfKeyZ, sfKeyS}, 4);
    } else {
        CLEAR_BIT(win->creative_mode, 0);
        free(win->creative.control);
    }
    SET_BIT(win->creative_mode, 1);
}

