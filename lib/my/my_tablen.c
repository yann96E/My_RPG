/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Patrick Eiermann
*/

#include "my.h"

int my_tablen(char **tab)
{
    int i;

    for (i = 0; tab[i] != NULL; i++);
    return (i);
}