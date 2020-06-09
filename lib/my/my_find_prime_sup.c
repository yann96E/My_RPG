/*
** EPITECH PROJECT, 2019
** Library Function
** File description:
** by Patrick Eiermann
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    if (nb <= 2) nb = 2;
    for (int i = 0; (nb + i) <= 2147483647; i++)
        if (my_is_prime(nb + i)) return (nb + i);
    return (0);
}