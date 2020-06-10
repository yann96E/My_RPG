/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/

#include "lib.h"

#ifndef __PLAYER__
#define __PLAYER__

typedef struct life_s
{
    char *heart_str;
    char heart;
    sfText *text[4];
    bool killed;
    unsigned char is_hit;
} life_t;

enum skin{head, shirt, hand, pants, shoes, hair};
enum animation{nothing, moving, hair_animation, falling};

typedef struct player_s
{
    char *control;
    sfVector2i pos;
    sfVector2f screen_pos;
    sfVector2f tile_offset;
    float jump_speed;
    sfSprite *skin[6];
    sfIntRect animation[4];
    char action;
    float time;
    bool left;
    bool is_moving;
    bool is_jumping;
    bool is_falling;
    unsigned char remove;
    life_t life;
    inventory_t *inventory;
    struct mouse_s *mouse;
    void (*action_)(void *, sfVector2i *);
    sfVector2f action_pos;
}player_t;

#endif /*__PLAYER__*/

