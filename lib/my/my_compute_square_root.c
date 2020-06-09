/*
** EPITECH PROJECT, 2019
** Library Function
** File description:
** by Patrick Eiermann
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int i;

    if (nb < 0) return (0);
    for (i = 0; (i * i) != nb; i++)
        if ((i * i) > nb)
            return (0);
    return (i);
}