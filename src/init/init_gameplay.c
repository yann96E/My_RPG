/*
** EPITECH PROJECT, 2020
** init_gameplay
** File description:
** init_gameplay
*/

#include "my_rpg.h"

char init_gameplay(window_t *win)
{
    win->inventory = create_sprite_without_set(win->obj[global][1][0]->texture);
    init_menu_pause(win, &win->pause);
    if (!(win->map = malloc(sizeof(map_t)))) return (84);
    for (sprite_ress_t ***categorie = win->obj[game]; *categorie; ++categorie) {
        for (sprite_ress_t **i = *categorie; *i; ++i)
            if (!((*i)->sprite = create_sprite_without_set((*i)->texture)))
                return (84);
    }
    return (init_player(win));
}
