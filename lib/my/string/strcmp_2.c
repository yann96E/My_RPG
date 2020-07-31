/*
** EPITECH PROJECT, 2020
** str_compare
** File description:
** compare two string in alphabetical order
*/

#include "my.h"

char strcmp_to_crt_number(char const *s1, char const *s2, char const crt)
{
    for (; *s1 && *s2 && *s1 == *s2 && s1[1] != crt && s2[1] != crt; ++s1, ++s2)
        if (s1[1] >= '0' && s1[1] <= '9' && s2[1] >= '0' && s2[1] <= '9')
            return ((my_getnbr(s1) - my_getnbr(s2) < 0) ? (-1) : (1));
    return (*s1 - *s2);

}
