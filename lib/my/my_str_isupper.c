/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Patrick Eiermann
*/

#include "my.h"

int	my_str_isupper(char const *str)
{
    while (*str) {
        if (!((*str > 64) && (*str < 91)))
            return (0);
        ++str;
    }
    return (1);
}