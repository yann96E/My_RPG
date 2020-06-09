/*
** EPITECH PROJECT, 2020
** init_menu_pause
** File description:
** init_menu_pause
*/

#include "my_rpg.h"

void init_menu_pause(window_t *win, menu_pause_t *pause)
{
    pause->button[_continue] = create_new_button(create_sftext(win->font,
    "Continue", 75, sfWhite), (sfVector2i){-110, -200}, (sfVector2i){300, 100}
    , _continue);
    pause->button[1] = create_new_button(create_sftext(win->font,
    "Save game", 75, sfWhite), (sfVector2i){-140, -100}, (sfVector2i){300, 100}
    , _save_game);
    pause->button[2] = create_new_button(create_sftext(win->font,
    "Settings", 75, sfWhite), (sfVector2i){-110, 0}, (sfVector2i){300, 100},
    _settings);
    pause->button[3] = create_new_button(create_sftext(win->font,
    "Return menu", 75, sfWhite), (sfVector2i){-160, 100},
    (sfVector2i){300, 100}, _return_menu);
    pause->button[4] = create_new_button(create_sftext(win->font,
    "Quit Game", 75, sfWhite), (sfVector2i){-120, 200}, (sfVector2i){300, 100},
    _quit_game);
}
