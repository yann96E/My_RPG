/*
** EPITECH PROJECT, 2020
** settings
** File description:
** settings
*/

#include "source.h"

static void handle_setting_button(button_t *button, sfVector2i const *mouse_pos,
                               window_t *win)
{
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

char settings(window_t *win)
{
    display_sprite(win, win->menu->background);
    display_sprite(win, win->menu->logo);
    for (char i = 0; i < 3; ++i) {
        display_text(win, win->menu->set_button[i].text);
        handle_setting_button(&win->menu->set_button[i], &win->mouse_pos, win);
    }
    return (0);
}
