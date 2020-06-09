/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"

void set_logo_animation(window_t *win)
{
    static double status = 1;
    static double size = 1.00;
    static double angle = 0;

    if (status == 1) {
        if (size >= 1.00) {
            status = 2;
        } else {
            sfSprite_setScale(win->menu->logo, (sfVector2f){size, size});
            sfSprite_setRotation(win->menu->logo, angle);
            size += 0.01;
            angle += ((angle < 10) ? (0.5) : (0));
        }
    }
    if (status == 2) {
        if (size <= 0.7) {
            status = 1;
        } else {
            sfSprite_setScale(win->menu->logo, (sfVector2f){size, size});
            sfSprite_setRotation(win->menu->logo, angle);
            size -= 0.01;
            angle -= ((angle > -10) ? (0.5) : (0));
        }
    }
}

void set_sprite_animation(window_t *win)
{
    win->win_clock->time =
        sfClock_getElapsedTime(win->win_clock->clock);
    win->win_clock->second =
        win->win_clock->time.microseconds / 1000000.0;
    if (win->win_clock->second > 0.04) {
        set_logo_animation(win);
        sfClock_restart(win->win_clock->clock);
    }
}

static void handle_menu_button(button_t *button, sfVector2i const *mouse_pos,
                               window_t *win)
{
    if (BIT(win->has_resolution_changed, 1) == true)
        set_button_position(button, &win->half_resolution);
    display_text(win, button->text);
    if (mouse_pos->x >= button->start.x && mouse_pos->x <= button->end.x &&
        mouse_pos->y >= button->start.y && mouse_pos->y <= button->end.y) {
        if (win->event.type == sfEvtMouseButtonReleased) {
            win->menu->status = button->status;
            win->menu->init = false;
        } else
            sfText_setCharacterSize(button->text, 80);
    } else
        sfText_setCharacterSize(button->text, 75);
    if (win->menu->status == quit_game_)
        sfRenderWindow_close(win->window);
}

static char display_main_menu(window_t *win)
{
    display_sprite(win, win->menu->background);
    display_sprite(win, win->menu->logo);
    for (char i = 0; i < 4; ++i)
        handle_menu_button(&win->menu->button[i], &win->mouse_pos, win);
    CLEAR_BIT(win->has_resolution_changed, 0);
    return (0);
}

void menu(window_t *win)
{
    static char (*scene_menu[4])(window_t *win) = {&display_main_menu,
                                                   &new_game, &load_game,
                                                   &settings};

    if (!win->menu) win->menu = init_menu(win);
    win->mouse_pos = sfMouse_getPositionRenderWindow(win->window);
    set_sprite_animation(win);
    if (scene_menu[win->menu->status](win) == 84 ||
        win->menu->status == quit_game_)
        sfRenderWindow_close(win->window);
}
