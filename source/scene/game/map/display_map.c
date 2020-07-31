/*
** EPITECH PROJECT, 2020
** display_map
** File description:
** display_map
*/

#include "source.h"

/* static void draw_light(window_t *win, sfVector2f *pos) */
/* { */
/*     for (win->radius = 0; win->radius < 100; ++win->radius) */
/*         my_pc(&win->fb, *pos, win, (unsigned char const [4]){0, 0, 0, 0}); */
/* } */

static void draw_tile(sfRenderWindow *win, tile_t *tile,
                      sfVector2f *pos, window_t *window)
{
    if (!tile) return;
    draw_sprite(tile->sprite[fg], tile->rect[fg], pos, win);
    draw_sprite(tile->sprite[bg], tile->rect[bg], pos, win);
    /* if (tile->sprite[fg] == window->obj[game][tiles][4]->sprite) { */
    /*     sfSprite_setPosition(win->light, (sfVector2f){pos.x + 4, pos.y + 4}); */
    /*     /\* draw_light(window, pos); *\/ */
    /* } */
}

sfVector2i check_if_camera_is_near_border(window_t *win, sfVector2i *pos,
                                          sfVector2f *offset)
{
    sfVector2i start = {0, 0};

    if (pos->y < win->tile_offset.y + 1) {
        start.y = 0;
        offset->y = (0 - (pos->y - win->tile_offset.y) + 1) *
        TILE_PXL_SIZE;
    } else
        start.y = pos->y - win->tile_offset.y - 1;
    if (pos->x < win->tile_offset.x + 1) {
        start.x = 0;
        offset->x = (0 - (pos->x - win->tile_offset.x) + 1) *
        TILE_PXL_SIZE;
    } else
        start.x = pos->x - win->tile_offset.x - 1;
    return (start);
}

void display_map(window_t *win, sfVector2f *tile_offset, sfVector2i *pos)
{
    sfVector2f offset = {0};
    sfVector2i start = check_if_camera_is_near_border(win, pos, &offset);
    sfVector2i end = {start.x + win->tile_total.x,
                      start.y + win->tile_total.y};
    sfVector2f cur = {0};
    float start_x = (0 - TILE_PXL_SIZE) - win->player.tile_offset.x;

    cur.y = (0 - TILE_PXL_SIZE) + win->player.tile_offset.y + offset.y;
    for (; start.y < end.y; ++start.y) {
        cur.x = start_x;
        for (int x = start.x; x < end.x; ++x) {
            if (win->player.remove == true && win->mouse_pos.x > cur.x &&
                win->mouse_pos.x < cur.x + TILE_PXL_SIZE &&
                win->mouse_pos.y > cur.y &&
                win->mouse_pos.y < cur.y + TILE_PXL_SIZE) {
                remove_ground(&win->map->tile[start.y][x], fg);
                win->player.remove = false;
            }
            draw_tile(win->window, win->map->tile[start.y][x], &cur, win);
            cur.x += TILE_PXL_SIZE;
        }
        cur.y += TILE_PXL_SIZE;
    }
    if (!BIT(win->creative_mode, 0)) display_player(win, &win->player);
    else creative_event(win, &win->creative);
    display_sprite(win, win->day);
    display_hud(win, &win->player);
    print_inventory(win, win->player.inventory, (sfVector2f){10, 10});
}
