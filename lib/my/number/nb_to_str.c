/*
** EPITECH PROJECT, 2019
** nb_to_str
** File description:
** nb_to_str
*/

#include "my.h"

static unsigned int int_nbr_len(int nb, int *len)
{
    unsigned int size = 1;

    while (nb > 0) {
        nb /= 10;
        size *= 10;
        ++*len;
    }
    return (size);
}

static char *nb_to_str_int(void *thing)
{
    int nb = *((int *)thing);
    int len = 0;
    int size = int_nbr_len(nb, &len);
    char *str = malloc(len + (nb < 0) + 1);
    char *i = str;

    if (!str) return (NULL);
    if (nb < 0) *str++ = '-';
    if (size != 1) {
        for (size /= 10; size > 0; size /= 10, ++i)
            *i = nb / size % 10 + 48;
    } else
        *i = nb + 48;
    *i = 0;
    return (str);
}

char *nb_to_str(void *nb, unsigned char const var_type)
{
    static char *(*convert_nb_to_str[1])(void *) = {&nb_to_str_int};

    if (!nb || var_type > 1 || var_type < 0) return (NULL);
    return (convert_nb_to_str[var_type](nb));
}
