/*
** EPITECH PROJECT, 2020
** window
** File description:
** window
*/

#include "lib.h"

#ifndef __WINDOW__
#define __WINDOW__

typedef struct sprite_ress_s
{
    char *file_name;
    sfTexture *texture;
    sfSprite *sprite;
} sprite_ress_t;

typedef struct win_clock_s
{
    sfClock *clock;
    sfTime time;
    float second;
} win_clock_t;

typedef struct window_s
{
    sfVector2i resolution;
    sfVector2i half_resolution;
    sfVector2i tile_offset;
    sfVector2i tile_total;
    sfRenderWindow *window;
    win_clock_t *win_clock;
    sfEvent event;
    unsigned char status;
    unsigned char init;
    sprite_ress_t ****obj;
    intro_t *intro;
    menu_t *menu;
    map_t *map;
    player_t player;
    creative_t creative;
    menu_pause_t pause;
    sfUint8 *fb;
    unsigned char is_on_pause;
    sfVector2i mouse_pos;
    sfFont *font;
    unsigned char has_resolution_changed;
    unsigned char creative_mode;

    sfSprite *inventory;
    sfTexture *inventory_tx;



   sfVector2i torch;
    sfTexture *tx;
    sfSprite *day;
    sfSprite *light;
    unsigned int len;
    float check_time;
    bool day_night;
    int radius;
} window_t;


#endif /*__WINDOW__*/
