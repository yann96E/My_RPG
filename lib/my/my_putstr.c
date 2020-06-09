/*
** EPITECH PROJECT, 2019
** Library Function
** File description:
** by Patrick Eiermann
*/

#include "my.h"

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return (0);
}
