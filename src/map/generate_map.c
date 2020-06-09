/*
** EPITECH PROJECT, 2020
** generare_map
** File description:
** generate_map
*/

#include "my_rpg.h"

enum block{cobble, dirt, wood};
enum tiles{grass_block = 2};


static tile_t ***alloc_map(void)
{
    tile_t ***map = malloc(sizeof(tile_t **) * (MAP_SIZE_Y + 1));

    if (!map) return (NULL);
    for (unsigned int y = 0; y < MAP_SIZE_Y; ++y) {
        if (!(map[y] = malloc(sizeof(tile_t *) * (MAP_SIZE_X + 1))))
            return (NULL);
        for (unsigned int x = 0; x <= MAP_SIZE_X; ++x) {
            map[y][x] = NULL;
        }
    }
    map[MAP_SIZE_Y] = NULL;
    return (map);
}

map_t *generate_map(window_t *win, char *title)
{
    tile_t ***map = alloc_map();
    map_t *new_map = malloc(sizeof(map_t));

    if (!new_map || !map) return (NULL);
    fill_map(win, map);
    new_map->title = title;
    new_map->tile = map;
    return (new_map);
}
