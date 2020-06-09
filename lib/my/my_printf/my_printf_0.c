/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include <unistd.h>
#include "../my.h"

int check_format(char c)
{
    if (c == 'c' || c == 'd' || c == 'i' || c == 'e' || c == 'E' || c == 'g')
        return (1);
    if (c == 'G' || c == 'o' || c == 's' || c == 'u' || c == 'x' || c == 'X')
        return (1);
    if (c == 'p' || c == 'n' || c == '%' || c == 'b')
        return (1);
    return (0);
}