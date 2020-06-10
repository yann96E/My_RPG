/*
** EPITECH PROJECT, 2020
** menu_pause
** File description:
** menu_pause
*/

#include "source.h"

static void button_action(window_t *win, signed char status)
{
    switch (status) {
    case _continue: win->is_on_pause = false; break;
    case _settings: break;
    case _return_menu: win->status = menu_; break;
    case _quit_game: sfRenderWindow_close(win->window); break;
    default: break;
    }
}

static void handle_menu_pause_button(button_t *button,
                                     sfVector2i const *mouse_pos, window_t *win)
{
    if (BIT(win->has_resolution_changed, 1))
        set_button_position(button, &win->half_resolution);
    display_text(win, button->text);
    if (mouse_pos->x >= button->start.x && mouse_pos->x <= button->end.x &&
        mouse_pos->y >= button->start.y && mouse_pos->y <= button->end.y) {
        if (win->event.type == sfEvtMouseButtonReleased)
            button_action(win, button->status);
        else
            sfText_setCharacterSize(button->text, 80);
    } else
        sfText_setCharacterSize(button->text, 75);
}

void display_pause_menu(window_t *win)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win->window);

    display_sprite(win, win->pause.background);
    if (win->player.life.killed == true) {
        display_text(win, win->player.life.text[4]);
        for (char i = 0; i < 5; ++i)
            handle_menu_pause_button(&win->pause.button[i], &mouse_pos, win);
    } else
        for (char i = 0; i < 5; ++i)
            handle_menu_pause_button(&win->pause.button[i], &mouse_pos, win);
    CLEAR_BIT(win->has_resolution_changed, 1);
}
