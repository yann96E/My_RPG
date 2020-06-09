/*
** EPITECH PROJECT, 2020
** button_handling
** File description:
** button_handling
*/

#include "my_rpg.h"

void destroy_button(button_t *button, char const nb)
{
    for (char i = 0; i < nb; ++i) {
        if (button[i].text)
            sfText_destroy(button[i].text);
    }
}

void set_button_position(button_t *button, sfVector2i const *center)
{
    button->start = (sfVector2i){button->pos.x + center->x,
                                  button->pos.y + center->y};
    button->end = (sfVector2i){button->start.x + button->size.x,
                                  button->start.y + button->size.y};
    sfText_setPosition(button->text, (sfVector2f){center->x + button->pos.x,
                                  center->y + button->pos.y});
}

button_t create_new_button(sfText *text, sfVector2i const pos,
                           sfVector2i const size, char const status)
{
    button_t button;

    button.pos = pos;
    button.size = size;
    button.text = text;
    button.status = status;
    return (button);
}
