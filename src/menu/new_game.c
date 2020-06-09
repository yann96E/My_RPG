/*
** EPITECH PROJECT, 2020
** new_game
** File description:
** new_game
*/

#include "my_rpg.h"
#include "my_rpg.h"

void set_player_position(window_t *win)
{
    int x = MAP_SIZE_X / 2;
    int y = 0;

    for (y = 0; !win->map->tile[y + 1][x]; ++y);
    win->player.pos = (sfVector2i){x, y};
    win->player.screen_pos.x = win->resolution.x / 2;
    win->player.screen_pos.y = win->resolution.y / 2 - 45;
    x -= 2;
    for (y = 0; !win->map->tile[y + 1][x]; ++y);
    add_tile(&win->map->tile[y][x], win->obj[game][tiles][4]->sprite,
    (sfIntRect){left, up, 20, 20}, fg);
}

char new_game(window_t *win)
{
    if (init_gameplay(win) == 84) return (84);
    win->map = generate_map(win, "new");
    if (!win->map) sfRenderWindow_close(win->window);
    set_player_position(win);
    win->status = gameplay_;
    return (0);

}
