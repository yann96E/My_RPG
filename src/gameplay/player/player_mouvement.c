/*
** EPITECH PROJECT, 2020
** player_mouvement
** File description:
** player_mouvement
*/

#include "my_rpg.h"

void player_right(window_t *win, player_t *player)
{
    unsigned char collide = 0 | COLLIDE(-1, 1) | (COLLIDE(-2, 1) * 2);

    player->is_moving = true;
    player->left = false;
    if (collide > 1) return;
    player->tile_offset.x += SPEED_X;
    if (player->tile_offset.x > HALF_BLOCK) {
        ++player->pos.x;
        player->tile_offset.x -= TILE_PXL_SIZE;
        if (COLLIDE(-3, 1) || COLLIDE(-3, 0)) return;
        player->pos.y -= collide;
    }

}

void player_left(window_t *win, player_t *player)
{
    unsigned char collide = 0 | COLLIDE(-1, -1) | (COLLIDE(-2, -1) * 2);

    player->is_moving = true;
    player->left = true;
    if (collide > 1) return;
    player->tile_offset.x -= SPEED_X;
    if (player->tile_offset.x < -2) {
        --player->pos.x;
        player->tile_offset.x += TILE_PXL_SIZE;
        if (COLLIDE(-3, -1) || COLLIDE(-3, 0)) return;
        player->pos.y -= collide;
    }
}

void player_jump(window_t *win, player_t *player)
{
    if (player->is_falling == true) return;
    if (player->is_jumping == false) {
        player->is_jumping = true;
        player->jump_speed = 6;
    }
    if (player->jump_speed >= 0 && (!TILE(-3, 0) || !TILE(-3, 0)->sprite[fg])) {
        player->jump_speed -= 0.2;
        player->tile_offset.y += player->jump_speed;
        if (player->tile_offset.y > HALF_BLOCK) {
            --player->pos.y;
            player->tile_offset.y -= TILE_PXL_SIZE;
        }
    } else {
        player->is_jumping = false;
        player->is_falling = true;
        player->jump_speed = 3;
    }
}
