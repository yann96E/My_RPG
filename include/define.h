/*
** EPITECH PROJECT, 2020
** define
** File description:
** define
*/

#define NEXT(thing) (thing = thing->next)
#define LINK_PREV_NEXT(thing) ((thing->prev) ? \
    (thing->prev->next = thing->next) : (thing))
#define LINK_NEXT_PREV(thing) ((thing->next) ? \
    (thing->next->prev = thing->prev) : (thing))
#define INVERSE_BOOL(bool) (bool = ((bool == false) ? (true) : (false)))

#define CHECK_MODE(a) (((win->creative_mode & 1) == false) ? \
                       (&win->player.a) : (&win->creative.a))
#define BIT(a, b) (a & b)
#define TOGGLE(a, b) (a ^= 1 << b)
#define CLEAR_BIT(a, b) (a &= ~(1 << b))
#define SET_BIT(a, b) (a |= b)

#define SKIN_WIDTH 40
#define SKIN_HEIGHT 56
#define SKIN_MOVE_START (336)
#define SKIN_MOVE_END (1040)
#define SKIN_HAIR_END (700)
#define SKIN_FALL_START (280)
#define SKIN_FALL_END (336)

#define SPRITE_PATH ("./assets/sprite/")
#define HOUSE_PATH ("./assets/templates/house")

#define MAP_SIZE_X (1750)
#define MAP_SIZE_Y (900)
#define MAP_SIZE (MAP_SIZE_X * MAP_SIZE_Y)
#define TILE_PXL_SIZE (16)
#define HALF_BLOCK (8)

#define DIRT_SEP 60
#define DIRT_MAX 20
#define DIRT_MED 30

#define INVENTORY_SIZE 40

#define CAVE_SCALE_X 4
#define CAVE_SCALE_Y 3

#define FILLPERC 80
#define SMOOTH_CYCLE 10
#define THRESHOLD 4

#define CREATIVE_SPEED 8
#define SPEED_X 3.5

#define WAIT_CLOCK (1)
#define TRUE (1)

typedef enum direction {left = 0, mid = 1, right = 2, up = 0, down = 2}
direction;
#define RECT(x, y) (sfIntRect){x * TILE_PXL_SIZE, y * TILE_PXL_SIZE, \
                            TILE_PXL_SIZE, TILE_PXL_SIZE}
#define TILE(a, b) (win->map->tile[player->pos.y + a]\
                                  [player->pos.x + b])
#define RAND(a, b) ((rand() % ((b) - (a))) + (a))
#define COLLIDE(a, b) (TILE(a, b) && TILE(a, b)->sprite[fg])

#define SPRITE(a, b, c) (win->obj[a][b][c]->sprite)

enum scene{intro_, menu_, gameplay_};

enum scene_sprite{game, global, loading};

enum game_sprite{axe, bow, chestplate, gore, hammer, helmet, legs, npc, ore,
                pickaxe, player, projectile, sword, tiles,trousers, wall};

enum global_sprite{background, logo};

enum day_night{day, night};
