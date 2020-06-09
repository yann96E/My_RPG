/*
** EPITECH PROJECT, 2019
** Library Function
** File description:
** by Patrick Eiermann
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strcpy_m(char const *src)
{
    char *dest = malloc(my_strlen(src) + 1);
    char *i = dest;

    if (!src || !dest || *src == '\0') return (NULL);
    for (; *src; ++src, ++i)
        *i = *src;
    *i = '\0';
    return (dest);
}
