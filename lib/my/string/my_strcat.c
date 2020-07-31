/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** strcat
*/

#include "my.h"

char *my_strcat(char const *s1, char const *s2)
{
    char *ret = malloc(my_strlen(s1) + my_strlen(s2) + 1);
    char *i = ret;

    if (!ret) return (NULL);
    for (; *s1; ++s1, ++i)
        *i = *s1;
    for (; *s2; ++s2, ++i)
        *i = *s2;
    *i = '\0';
    return (ret);
}

char *my_strcat_to_crt(char const *s1, char const *s2, char const crt)
{
    char *new_str = malloc(my_strlen(s1) + my_strlen(s2) + 2);
    int x = -1;

    if (!new_str) return (NULL);
    for (; *s1; ++s1)
        new_str[++x] = *s1;
    new_str[++x] = crt;
    for (; *s2; ++s2)
        new_str[++x] = *s2;
    new_str[++x] = '\0';
    return (new_str);
}

char *my_strcat_insert_to_end(char const *s1, char const *to_insert,
                              char const *s2, char const end)
{
    char *new_str = malloc(my_strlen_to_crt(s1, end) +
                           my_strlen(to_insert) +
                           my_strlen(s2) + 1);
    char *x = new_str;

    if (!new_str) return (NULL);
    for (; *s1 && *s1 != end; ++s1, ++x)
        *x = *s1;
    if (to_insert && *to_insert)
        for (; *to_insert; ++to_insert, ++x)
            *x = *to_insert;
    for (; *s2; ++s2, ++x)
        *x = *s2;
    *x = '\0';
    return (new_str);
}
