/*
** EPITECH PROJECT, 2020
** count_files
** File description:
** count files
*/

#include "my.h"

char *my_itoa(int nb, int malloc_size)
{
    int	len;
    char *str;
    int	tmp;

    tmp = nb;
    len = 0;
    while (tmp > 0) {
        tmp /= 10;
        len++;
    }
    str = malloc(sizeof(char) * malloc_size);
    str[len] = '\0';
    while (len--) {
        str[len] = nb % 10  + '0';
        nb /= 10;
    }
    return (str);
}
