/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Patrick Eiermann
*/

#include "my.h"

int	my_str_islower(const char *str)
{
    int	i = 0;
    while (str[i] != '\0') {
        if (str[i] < 97 || str[i] > 122) return (0);
        i++;
    }
    return (1);
}
