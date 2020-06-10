/*
** EPITECH PROJECT, 2020
** texture_sprite_handling
** File description:
** texture_sprite_handling
*/

#include "source.h"

sfSprite *create_sprite(sfTexture *texture, sfVector2f const position,
                        sfVector2f const origin)
{
    sfSprite *sprite = sfSprite_create();

    if (!sprite || !texture) return (NULL);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, position);
    sfSprite_setOrigin(sprite, origin);
    return (sprite);
}

sfSprite *create_sprite_without_set(sfTexture const *texture)
{
    sfSprite *sprite = sfSprite_create();

    if (!sprite || !texture) return (NULL);
    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

void texture_createfromfile(sfSprite **sp, sfTexture **tx, char const *path)
{
    *sp = sfSprite_create();
    *tx = sfTexture_createFromFile(path, NULL);
    if (!tx || !sp) return;
    sfSprite_setTexture(*sp, *tx, sfFalse);
}

void show_pict(sfRenderWindow *wind, sfSprite *sp,
               sfVector2f *pos, sfIntRect *rect)
{
    if (!sp) return;
    sfSprite_setPosition(sp, *pos);
    sfSprite_setTextureRect(sp, *rect);
    sfRenderWindow_drawSprite(wind, sp, NULL);
}
