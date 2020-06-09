/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#include "../../include/my_rpg.h"

static sfSprite *create_texture_from_pixel(sfUint8 *fb, unsigned int const w,
                                             unsigned int const h)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_create(w, h);

    if (!sprite || !texture) return (NULL);
    sfTexture_updateFromPixels(texture, fb, w, h, 0, 0);
    sfSprite_setTexture(sprite, texture, false);
    return (sprite);
}

window_t *init_window(void)
{
    window_t *win = malloc(sizeof(window_t));

    if (!win) return (NULL);
    win->is_on_pause = false;
    win->status = intro_;
    win->resolution = (sfVector2i){1920, 1080};
    win->half_resolution = (sfVector2i){win->resolution.x / 2,
    win->resolution.y / 2};
    win->tile_total = (sfVector2i){(win->resolution.x / TILE_PXL_SIZE + 3),
    (win->resolution.y / TILE_PXL_SIZE + 3)};
    win->tile_offset = (sfVector2i){win->tile_total.x / 2,
    win->tile_total.y / 2};
    win->window = sfRenderWindow_create((sfVideoMode){win->resolution.x,
    win->resolution.y, 32}, "Dimentions", sfResize | sfClose, NULL);
    win->len = win->resolution.x * win->resolution.y * 4;
    win->fb = create_framebuffer(win->resolution.x, win->resolution.y,
    (unsigned char const [4]){0, 0, 0, 120});
    win->light = create_texture_from_pixel(win->fb,
    win->resolution.x, win->resolution.y);
    replace_framebuffer(&win->fb, (unsigned char const [4]){0, 0, 0, 0}, win->len);
    win->pause.background = create_texture_from_pixel(win->fb,
    win->resolution.x, win->resolution.y);
    win->has_resolution_changed = UCHAR_MAX;
    win->day = create_texture_from_pixel(win->fb,
    win->resolution.x, win->resolution.y);
    win->tx = sfTexture_create(win->resolution.x, win->resolution.y);
    win->day_night = day;
    win->check_time = 0;
    return ((!win->window || !win->pause.background) ? (NULL) : (win));
}
