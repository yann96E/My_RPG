/*
** EPITECH PROJECT, 2019
** Library Function
** File description:
** by Patrick Eiermann
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    if (str[0] != '\0') {
        for (int i = 0; to_find[i] != '\0'; ++i)
            if (to_find[i] != str[i])
                return (my_strstr(str + 1, to_find));
        return (str);
    } else {
        return (NULL);
    }
}