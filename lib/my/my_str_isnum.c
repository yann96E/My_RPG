/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Patrick Eiermann
*/

#include "my.h"

int	my_str_isnum(char const *str)
{
    while (*str) {
        if (!(*str > 47 && *str < 58))
            return (0);
        ++str;
    }
    return (1);
}