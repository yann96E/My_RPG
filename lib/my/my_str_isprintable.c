/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Patrick Eiermann
*/

#include "my.h"

int	my_str_isprintable(char const *str)
{
    int	i = 0;

    while (str[i] != '\0') {
        if (str[i] >=  0 || str[i] <=  31 || str[i] == 127) return (0);
        i++;
    }
    return (1);
}