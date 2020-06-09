/*
** EPITECH PROJECT, 2019
** Library Function
** File description:
** by Patrick Eiermann
*/

#include "my.h"

char *my_strcnat(char *dest, char const *src, int n)
{
    int i = 0;
    int di = my_strlen(dest);

    while ('\0' != src[i] && i != n) {
        dest[di] = src[i];
        ++di;
        ++i;
    }
    dest[di] = '\0';
    return (dest);
}