/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** generate_caves
*/

#include "source.h"

u_int8_t get_neighbours(bool **_map, sfVector2i point, sfVector2i dim)
{
    u_int8_t ret = 0;

    for (int i = point.y - 1; i <= point.y + 1; ++i)
        for (int j = point.x - 1; j <= point.x + 1; ++j)
            if (j < 0 || i < 0 ||
                i >= dim.y || j >= dim.x)
                ++ret;
            else if ((i != point.y || j != point.x) &&
                    _map[i][j])
                ++ret;
    return (ret);
}

void smoothen(bool **_map, sfVector2i dim)
{
    u_int8_t neighbours = 0;

    for (int i = 0; i < dim.y; ++i)
        for (int j = 0; j < dim.x; ++j) {
            neighbours = get_neighbours(_map, (sfVector2i){j, i}, dim);
            if (neighbours > THRESHOLD)
                _map[i][j] = 1;
            else if (neighbours < THRESHOLD)
                _map[i][j] = 0;
        }
    return;
}

void place(window_t *win, tile_t ***map, sfVector2i dim, bool **_map)
{
    sfVector2i offset = {0, DIRT_MED};

    for (int i = 0; i < dim.y; ++i)
        for (int j = 0; j < dim.x; ++j)
            if (_map[i][j] == 0)
                remove_tile(&map[i + offset.y][j + offset.x]);
}
void map_scale(bool **_map, sfVector2i dim, sfVector2i cursor)
{
    int i = cursor.y * CAVE_SCALE_Y;
    int j = cursor.x * CAVE_SCALE_X;
    bool _rand = (rand() % 100) < FILLPERC;

    for (int w = 0; w < CAVE_SCALE_Y; ++w)
        for (int v = 0; v < CAVE_SCALE_X; ++v)
            if (i + w < dim.y && j + v < dim.x)
            _map[i + w][j + v] = ((i + w == 0 || i + w == dim.y - 1 ||
                j + v == 0 || j + v == dim.x - 1)
                || (_rand));
}

void generate_caves(window_t *win, tile_t ***map,
                    u_int32_t width, u_int32_t height)
{
    bool **_map = malloc(sizeof(bool *) * height);

    if (!(_map))
        return;
    for (u_int32_t i = 0; i < height; ++i) {
        _map[i] = malloc(sizeof(tile_t) * width);
        for (u_int32_t j = 0; j < width; ++j)
            _map[i][j] = 0;
    }
    for (u_int32_t i = 0; i < height / CAVE_SCALE_Y; ++i) {
        for (u_int32_t j = 0; j < width / CAVE_SCALE_X; ++j)
            map_scale(_map, (sfVector2i){width, height}, (sfVector2i){j, i});
    }
    for (int i = SMOOTH_CYCLE; i; --i) {
        smoothen(_map, (sfVector2i){width, height});
    }
    place(win ,map, (sfVector2i){width, height}, _map);
    for (u_int32_t i = 0; i < height; ++i)
        free_if(_map[i]);
    free_if(_map);
}
