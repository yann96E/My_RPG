/*
** EPITECH PROJECT, 2020
** hud
** File description:
** hud
*/

#include "my_rpg.h"

static char *get_nb_heart(player_t *player)
{
    char heart = player->life.heart;

    for (char i = 2; i > 0; --i) {
        player->life.heart_str[i] = (heart > 0) ? (heart % 10 + 48) : (' ');
        heart /= 10;
    }
    return (player->life.heart_str);
}

static void check_if_alive(window_t *win, player_t *player)
{
    if (player->life.is_hit == TRUE) {
        sfText_setString(player->life.text[1], get_nb_heart(player));
        player->life.is_hit |= WAIT_CLOCK;
    }
    if (player->life.heart <= 0) {
        player->life.killed = true;
        SET_BIT(win->is_on_pause, 1);
    }
}

static void display_life(window_t *win, player_t *player)
{
    sfVector2f pos = {win->resolution.x - 232, 40};

    check_if_alive(win, player);
    if (BIT(win->has_resolution_changed, 4) == 4) {
        sfText_setPosition(player->life.text[0],
        (sfVector2f){win->resolution.x - 232, 0});
        sfText_setPosition(player->life.text[1],
        (sfVector2f){win->resolution.x - 172, 0});
        sfText_setPosition(player->life.text[2],
        (sfVector2f){win->resolution.x - 140, 0});
        CLEAR_BIT(win->has_resolution_changed, 4);
    }
    for (char i = 0; i < 3; ++i)
        sfRenderWindow_drawText(win->window, player->life.text[i], NULL);
    for (char i = player->life.heart / 20; i > 0; --i) {
        sfSprite_setPosition(SPRITE(game, tiles, 30), pos);
        sfRenderWindow_drawSprite(win->window, SPRITE(game, tiles, 30), NULL);
        pos.x += 20;
    }
}

void display_hud(window_t *win, player_t *player)
{
    display_life(win, player);
}
