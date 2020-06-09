/*
** EPITECH PROJECT, 2020
** display_player
** File description:
** display_player
*/

#include "my_rpg.h"

static sfIntRect flipp_sprite(sfIntRect const *cur, bool const inverse)
{
    sfIntRect const new = {cur->width, cur->top, 0 - cur->width, cur->height};

    return ((inverse == true) ? (new) : (*cur));
}

void display_player(window_t *win, player_t *player)
{
    sfVector2f pos = {player->screen_pos.x,
                       player->screen_pos.y + TILE_PXL_SIZE};

    for (char i = 0; i < 5; ++i) {
        draw_sprite(player->skin[i], flipp_sprite(
        &player->animation[player->action], player->left), &pos, win->window);
    }
    draw_sprite(player->skin[hair], flipp_sprite(
    &player->animation[hair_animation], player->left), &pos, win->window);
}
