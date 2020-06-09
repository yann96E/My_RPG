/*
** EPITECH PROJECT, 2019
** Library Function
** File description:
** by Patrick Eiermann
*/

#include "my.h"

int my_is_prime(int nb)
{
    int i = 2;

    if (nb == 0 || nb == 1) return (0);
    while (i < nb) {
        if (nb % i == 0) return (0);
        i++;
    }
    return (1);
}