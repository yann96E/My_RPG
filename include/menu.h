/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** pour include tout
*/

#ifndef MENU_H
#define MENU_H

#include "lib.h"

typedef enum {
    main_menu_,
    new_game_,
    load_game_,
    settings_,
    quit_game_
} menu_button;

typedef struct button_s
{
    sfText *text;
    sfVector2i pos;
    sfVector2i size;
    sfVector2i start;
    sfVector2i end;
    char status;
}button_t;

typedef struct menu_s
{
    unsigned char init : 1;
    unsigned char status;
    sfSprite *background;
    sfSprite *logo;
    button_t button[5];
    button_t set_button[3];
    button_t load_button[1];
    sfMusic *back_music;
} menu_t;

#endif /* MENU_H */
