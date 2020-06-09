/*
** EPITECH PROJECT, 2020
** freeif
** File description:
** free if
*/

#include "my.h"

void freeif(void *thing)
{
    if (thing)
        free(thing);
}