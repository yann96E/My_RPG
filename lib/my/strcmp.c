/*
** EPITECH PROJECT, 2020
** str_compare
** File description:
** compare two string in alphabetical order
*/

#include "my.h"

char flag_cmp(char const crt, char const *fl)
{
    if (crt == 0)
        return (0);
    for (char const *i = fl; *i; ++i)
        if (crt == *i) return (1);
    return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    if (!s1 || !s2) return (84);
    while (*s1 && *s2 && *s1 == *s2) {
        ++s1;
        ++s2;
    }
    return (*s1 - *s2);
}

char strcmp_crt(char const *s1, char const *s2, char const crt)
{
    for (; *s1 && *s2 && *s1 == *s2 && *(s1 + 1) != crt &&
             *(s2 + 1) != crt; ++s1, ++s2);
    return (*s1 - *s2);
}

char strcmp_crt_number(char const *s1, char const *s2, char const crt)
{
    for (; *s1 && *s2 && *s1 == *s2 && *(s1 + 1) != crt &&
             *(s2 + 1) != crt; ++s1, ++s2)
        if (*(s1 + 1) >= '0' && *(s1 + 1) <= '9' &&
            *(s2 + 1) >= '0' && *(s2 + 1) <= '9')
            return ((my_getnbr(s1) - my_getnbr(s2) < 0) ? (-1) : (1));
    return (*s1 - *s2);
}

char cmp_extension(char const *str, char const *extension)
{
    return (my_strcmp(str + my_strlen_crt(str, *extension), extension));
}
