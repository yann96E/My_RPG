/*
** EPITECH PROJECT, 2019
** Library Function
** File description:
** by Patrick Eiermann
*/

#include "my.h"

static void my_swap_char(char *start, char *end)
{
    char save = *end;

    *end = *start;
    *start = save;
}

char *my_revstr(char *str)
{
    char *end = str + my_strlen(str) - 1;
    char *start = str;

    while (start < end) {
        my_swap_char(start, end);
        --end;
        ++start;
    }
    return (str);
}