/*
** EPITECH PROJECT, 2019
** Library Function
** File description:
** by Patrick Eiermann
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32 ;
        i++;
    }
    return (str);
}