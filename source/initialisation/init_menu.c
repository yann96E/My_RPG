/*
** EPITECH PROJECT, 2020
** init_menu
** File description:
** init_menu
*/

#include "source.h"

static inline int get_window_size_x(window_t *win)
{
    return (sfRenderWindow_getSize(win->window).x);
}

static inline int get_window_size_y(window_t *win)
{
    return (sfRenderWindow_getSize(win->window).y);
}

void destroy_menu(window_t *win)
{
    sfSprite_destroy(win->menu->background);
    sfSprite_destroy(win->menu->logo);
    destroy_button(win->menu->button, 4);
    free(win->menu);
    win->menu = NULL;
    /* sfMusic_destroy(win->menu->back_music); */
}

static void init_setting(window_t *win, menu_t *menu)
{
    menu->set_button[0] = create_new_button(create_sftext(win->font,
    "Back to Menu", 20, sfWhite),
    (sfVector2i){-940, -520}, (sfVector2i){100, 30}, main_menu_);
    menu->set_button[1] = create_new_button(create_sftext(win->font,
    "800*600", 20, sfWhite),
    (sfVector2i){-120, -10}, (sfVector2i){70, 20}, main_menu_);
    menu->set_button[2] = create_new_button(create_sftext(win->font,
    "1920*1280", 20, sfWhite),
    (sfVector2i){-130, 10}, (sfVector2i){90, 20}, main_menu_);
}

static void init_load(window_t *win, menu_t *menu)
{
    menu->load_button[0] = create_new_button(create_sftext(win->font,
    "Back to Menu", 20, sfWhite),
    (sfVector2i){-940, -520}, (sfVector2i){100, 30}, main_menu_);
}

menu_t *init_menu(window_t *win)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (!menu) return (NULL);
    menu->status = main_menu_;
    menu->background = create_sprite(win->obj[global][background][2]->texture,
    (sfVector2f){0, 0}, (sfVector2f){0, 0});
    menu->logo = create_sprite(win->obj[loading][background][0]->texture,
    (sfVector2f){950, 150}, (sfVector2f){243, 71});
    menu->button[0] = create_new_button(create_sftext(win->font,
    "New Game", 75, sfBlack), (sfVector2i){-130, -150}, (sfVector2i){300, 100},
    new_game_);
    menu->button[1] = create_new_button(create_sftext(win->font,
    "Load Game", 75, sfBlack), (sfVector2i){-140, -50}, (sfVector2i){300, 100},
    load_game_);
    menu->button[2] = create_new_button(create_sftext(win->font,
    "Settings", 75, sfBlack), (sfVector2i){-120, 50}, (sfVector2i){300, 100},
    settings_);
    menu->button[3] = create_new_button(create_sftext(win->font,
    "Quit Game", 75, sfBlack), (sfVector2i){-140, 150}, (sfVector2i){300, 100},
    quit_game_);
    if (!menu->background || !menu->logo || !menu->button[0].text ||
        !menu->button[1].text || !menu->button[2].text || !menu->button[3].text)
        return (NULL);
    /* menu->back_music = sfMusic_createFromFile("./assets/music/terraria_menu.ogg"); */
    /* sfMusic_setLoop(menu->back_music, true); */
    /* sfMusic_play(menu->back_music); */
    /* sfMusic_setVolume(menu->back_music, 50); */
    init_setting(win, menu);
    init_load(win, menu);
    return (menu);
}
