/*
** EPITECH PROJECT, 2020
** text_handling
** File description:
** text_handling
*/

#include "my_rpg.h"

sfText *create_sftext(sfFont *font, char const *str, int size, sfColor color)
{
    sfText *text = sfText_create();

    if (!text) return (NULL);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, color);
    return (text);
}

sfText *move_text(sfText *text, sfVector2f pos)
{
    if (text) sfText_setPosition(text, pos);
    return (text);
}
