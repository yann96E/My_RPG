/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** generate_noise
*/

#include "source.h"

void generate_noise(window_t *win, tile_t ***map)
{
    int distance = DIRT_MED;
    int space = 0;
    int stonespace = distance - space;

    for (int i = 0; i < MAP_SIZE_X; ++i) {
        distance = RAND(distance - 1, distance + 2);
        distance = (distance < 0) ? 5 : distance;
        distance = (distance > DIRT_SEP) ? DIRT_SEP - 1 : distance;
        space = RAND(12, 20);
        stonespace = distance + space;
        for (int j = MAP_SIZE_Y - 1; j > stonespace; --j)
            add_tile(&map[j][i], win->obj[game][tiles][1]->sprite,
            RECT(mid, mid), fg);
        for (int j = stonespace; j > distance; --j)
            add_tile(&map[j][i], win->obj[game][tiles][0]->sprite,
            RECT(mid, mid), fg);
        add_tile(&map[distance][i], win->obj[game][tiles][2]->sprite,
            RECT(mid, up), fg);
    }
}

void fill_map(window_t *win, tile_t ***map)
{
    generate_noise(win, map);
    generate_caves(win, map, MAP_SIZE_X,
                    (MAP_SIZE_Y - DIRT_MED));
    generate_houses(win, map);
}
