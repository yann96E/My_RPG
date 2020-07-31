/*
** EPITECH PROJECT, 2020
** player_event
** File description:
** player_event
*/

#include "source.h"

void change_sprite_intrect(int *top, int const height,
                            int const start, int const end)
{
    if (*top > end)
        *top = start;
    else
        *top += height;
}

static void set_player_animation(window_t *win, player_t *player)
{
    refresh_time(win->win_clock);
    if (player->is_falling == true || player->is_jumping == true) {
        player->action = falling;
    } else if (player->is_moving == true &&
               win->win_clock->second > player->time) {
        change_sprite_intrect(&player->animation[moving].top, SKIN_HEIGHT,
            SKIN_MOVE_START, SKIN_MOVE_END);
        change_sprite_intrect(&player->animation[hair_animation].top,
            SKIN_HEIGHT, SKIN_HEIGHT, SKIN_HAIR_END);
        player->action = moving;
        player->time += 0.1;
    } else if (player->is_moving == false) {
        player->animation[moving].top = SKIN_MOVE_START;
        player->action = nothing;
    }
}

static void let_player_fall(window_t *win, player_t *player)
{
    if (player->is_falling == false) player->jump_speed = 3;
    if (player->is_jumping == false &&
        (!TILE(0, 0) || !TILE(0, 0)->sprite[fg]) &&
        (((!TILE(0, 1) || !TILE(0, 1)->sprite[fg]) &&
          (!TILE(-1, 1) || !TILE(-1, 1)->sprite[fg])) ||
         ((!TILE(0, -1) || !TILE(0, -1)->sprite[fg]) &&
          (!TILE(-1, -1) || !TILE(-1, -1)->sprite[fg])))) {
        player->is_falling = true;
        player->jump_speed += (player->jump_speed < 15) ? (1) : (0);
        player->tile_offset.y -= player->jump_speed;
        if (player->tile_offset.y < 0 - TILE_PXL_SIZE) {
            ++player->pos.y;
            if (TILE(1, 0)) player->tile_offset.y = 0;
            else player->tile_offset.y += TILE_PXL_SIZE;
        }
    } else player->is_falling = false;
}

void player_event(window_t *win, player_t *player)
{
    static void (*player_action[3])(window_t *win, player_t *player) =
            {&player_left, &player_right, &player_jump};

    player->is_moving = false;
    for (char const *i = player->control; *i; ++i)
        if (sfKeyboard_isKeyPressed(*i) == true)
            player_action[i - player->control](win, player);
    if (player->is_jumping == true) player_jump(win, player);
    else let_player_fall(win, player);
    set_player_animation(win, player);
}
