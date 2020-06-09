/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#include "../../lib/my/my.h"
#include "../../include/my_rpg.h"

void display_sprite(window_t *win, sfSprite *sprite)
{
    sfRenderWindow_drawSprite(win->window, sprite, NULL);
}

void display_text(window_t *win, sfText *text)
{
    sfRenderWindow_drawText(win->window, text, NULL);
}

void draw_sprite(sfSprite *sprite, sfIntRect const rect,
                            sfVector2f *pos, sfRenderWindow *win)
{
    if (!sprite) return;
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, *pos);
    sfRenderWindow_drawSprite(win, sprite, NULL);
}

void debug_print(window_t *win, player_t *player, int const x, int const y)
{
    add_tile(&TILE(y, x), win->obj[game][tiles][1]->sprite,
             RECT(mid, mid), bg);
}
