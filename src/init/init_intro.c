
/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#include "../../include/my_rpg.h"

intro_t *init_intro(window_t *win)
{
    intro_t *intro  = malloc(sizeof(intro_t));

    if (!intro) return (NULL);
    intro->status = 0;
    sfClock_restart(win->win_clock->clock);
    texture_createfromfile(&intro->S_logo, &intro->T_logo,
    "./assets/sprite/global/logo/Logo.png");
    texture_createfromfile(&intro->S_back_0, &intro->T_back_0,
    "./assets/sprite/global/background/atari130.png");
    texture_createfromfile(&intro->S_back_1, &intro->T_back_1,
    "./assets/sprite/global/background/atari800.png");
    sfSprite_setPosition(intro->S_logo, (sfVector2f){717, 150});
    sfSprite_setPosition(intro->S_back_0, (sfVector2f){710, 500});
    sfSprite_setPosition(intro->S_back_1, (sfVector2f){983, 500});
    if (!(intro->font = sfFont_createFromFile("./assets/font/game_font.ttf")))
        return (NULL);
    intro->text = move_text(create_sftext(intro->font, "0 %", 50,
    sfWhite), (sfVector2f){930, 900});
    win->font = sfFont_createFromFile("./assets/font/menu_font.ttf");
    if (!intro->S_logo || !intro->S_back_0 || !intro->S_back_1 ||
        !intro->text || !win->font) return (NULL);
    win->player.control = create_control((char const [3]){sfKeyQ, sfKeyD,
                           sfKeySpace}, 3);
    win->creative_mode = false;
    return (intro);
}
