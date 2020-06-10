/*
** EPITECH PROJECT, 2020
** init_player
** File description:
** init_player
*/

#include "source.h"

char *create_control(char const *str, char const nb)
{
    char *control = malloc(nb + 1);

    for (char i = 0; i < nb; ++i)
        control[i] = str[i];
    control[nb] = 0;
    return (control);
}

static void init_player_status(window_t *win)
{
    win->player.life.heart_str = my_strcpy_m("100");
    win->player.life.heart = 100;
    win->player.life.text[0] = create_sftext(win->intro->font, "Life:", 30, sfWhite);
    win->player.life.text[1] = create_sftext(win->intro->font, "100", 30, sfWhite);
    win->player.life.text[2] = create_sftext(win->intro->font, "/ 100", 30, sfWhite);
    win->player.life.text[3] = create_sftext(win->intro->font, "You have been killed", 50, sfRed);
    win->player.life.killed = false;
    win->player.life.is_hit = false;
}

char init_player(window_t *win)
{
    win->player.tile_offset.x = 0;
    win->player.tile_offset.y = 0;
    win->player.skin[head] = win->obj[game][player][20]->sprite;
    win->player.skin[shirt] = win->obj[game][player][22]->sprite;
    win->player.skin[hand] = win->obj[game][player][19]->sprite;
    win->player.skin[pants] = win->obj[game][player][21]->sprite;
    win->player.skin[shoes] = win->obj[game][player][23]->sprite;
    win->player.skin[hair] = win->obj[game][player][2]->sprite;
    win->player.action = 0;
    win->player.animation[nothing] = (sfIntRect){0 , 0, SKIN_WIDTH, SKIN_HEIGHT};
    win->player.animation[moving] = (sfIntRect){0, SKIN_MOVE_START,
                                            SKIN_WIDTH, SKIN_HEIGHT};
    win->player.animation[hair_animation] = (sfIntRect){0, 0,
                                            SKIN_WIDTH, SKIN_HEIGHT};
    win->player.animation[falling] = (sfIntRect){0, SKIN_FALL_START,
                                           SKIN_WIDTH, SKIN_HEIGHT};
    win->player.is_moving = false;
    win->player.is_falling = false;
    win->player.is_jumping = false;
    win->player.time = 0;
    win->player.jump_speed = 2;
    init_player_status(win);
    win->player.inventory = create_inventory(win, false);
    win->player.action_ = tools_pickaxe;
    win->player.remove = false;
    win->player.action_pos = (sfVector2f){0, 0};
    return (0);
}
