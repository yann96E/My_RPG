/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** generate_houses
*/

#include "my_rpg.h"

char **get_template(void)
{
    char *file = my_strcat_nf(HOUSE_PATH, "/normal.txt");
    char *str = read_file(get_fd(file), 50);
    char **house = parse(str, '\n');

    freeif(str);
    freeif(file);
    return (house);
}

u_int16_t get_ground(tile_t ***map, u_int16_t x)
{
    u_int16_t ret = 0;

    while (!map[++ret][x]);
    return (ret);
}

int get_med_ground(tile_t ***map, char **house, int length, int x)
{
    int ret = 0;

    for (int i = 0; i < length; ++i)
        ret += get_ground(map, x + i);
    return (ret / length);
}

void place_house(window_t *win, tile_t ***map, char **house, sfVector2i offset)
{
    int height = my_getnbr(house[0]);

    offset.y = get_med_ground(map, house,
                my_strlen(house[height]), offset.x) - (height / 2);
    for (int i = height; i > 0; --i) {
        for (int j = 0; house[i][j]; ++j)
            switch (house[i][j]) {
            case 48:
                remove_tile(&map[offset.y + i - 2][offset.x + j]);
                break;
            case 49:
                add_tile(&map[offset.y + i - 2][offset.x + j],
                        win->obj[game][tiles][20]->sprite, RECT(mid, mid), fg);
                break;
            case 50:
                remove_tile(&map[offset.y + i - 2][offset.x + j]);
                add_tile(&map[offset.y + i - 2][offset.x + j],
                        win->obj[game][wall][1]->sprite, RECT(up, left), bg);
            }
    }
}

void generate_houses(window_t *win, tile_t ***map)
{
    char **house = get_template();

    place_house(win, map, house,
        (sfVector2i){MAP_SIZE_X / 2 + 5, 0});
}