/*
** EPITECH PROJECT, 2019
** Library Function
** File description:
** by Patrick Eiermann
*/

#include "my.h"

int my_compute_power_rec(int nb , int power)
{
    int result = nb;

    if (power == 0)
        return (1);
    if (nb == 0)
        return (1);
    if (nb < 0)
        return (0);

    result = nb * (my_compute_power_rec(nb, power - 1));

    return (result);
}