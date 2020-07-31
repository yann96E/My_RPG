/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#include "source.h"

void detect_mouse(window_t *win, player_t *player)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win->window);

    win->mouse_pos = pos;
    if (pos.x > player->screen_pos.x + 130 || pos.x < player->screen_pos.x - 20 ||
        pos.y > player->screen_pos.y + 230 || pos.y < player->screen_pos.y - 20)
        return;
    if (sfMouse_isButtonPressed(sfMouseLeft))
        player->action_((void *)win, &pos);
}

void gameplay(window_t *win)
{
    display_map(win, CHECK_MODE(tile_offset), CHECK_MODE(pos));
    if (!BIT(win->is_on_pause, 1) && !win->player.life.killed) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            TOGGLE(win->is_on_pause, 0);
            SET_BIT(win->is_on_pause, 1);
        }
    }
    if (!BIT(win->creative_mode, 1) && sfKeyboard_isKeyPressed(sfKeyC))
        switch_player_creative(win);
    if (BIT(win->is_on_pause, 0)) display_pause_menu(win);
    else if (!BIT(win->creative_mode, 0))
        player_event(win, &win->player);
    else creative_event(win, &win->creative);
    detect_mouse(win, &win->player);
}
