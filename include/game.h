/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** pour include tout
*/

#ifndef __MENU_PAUSE__
#define __MENU_PAUSE__

#include "lib.h"

enum menu_pause{_continue, _save_game, _settings, _return_menu, _quit_game};

typedef struct menu_pause_s
{
    sfSprite *background;
    button_t button[5];
} menu_pause_t;

#endif /*__MENU_PAUSE__*/
