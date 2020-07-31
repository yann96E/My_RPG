/*
** EPITECH PROJECT, 2020
** creative_event
** File description:
** creative_event
*/

#include "source.h"

static void creative_left(window_t *win, creative_t *creative)
{
    creative->tile_offset.x -= CREATIVE_SPEED;
    if (creative->tile_offset.x < 0 - TILE_PXL_SIZE) {
        --creative->pos.x;
        creative->tile_offset.x += TILE_PXL_SIZE;
    }
}

static void creative_right(window_t *win, creative_t *creative)
{
    creative->tile_offset.x += CREATIVE_SPEED;
    if (creative->tile_offset.x > TILE_PXL_SIZE) {
        ++creative->pos.x;
        creative->tile_offset.x -= TILE_PXL_SIZE;
    }
}

static void creative_up(window_t *win, creative_t *creative)
{
    creative->tile_offset.y -= CREATIVE_SPEED;
    if (creative->tile_offset.y < 0 - TILE_PXL_SIZE) {
        --creative->pos.y;
        creative->tile_offset.y += TILE_PXL_SIZE;
    }
}

static void creative_down(window_t *win, creative_t *creative)
{
    creative->tile_offset.y += CREATIVE_SPEED;
    if (creative->tile_offset.y > TILE_PXL_SIZE) {
        ++creative->pos.y;
        creative->tile_offset.y -= TILE_PXL_SIZE;
    }
}

void creative_event(window_t *win, creative_t *creative)
{
    static void (*creative_action[4])(window_t *, creative_t *) =
            {&creative_left, &creative_right, &creative_up, &creative_down};

    for (char const *i = win->creative.control; *i; ++i)
        if (sfKeyboard_isKeyPressed(*i) == true)
            creative_action[i - creative->control](win, creative);
}
