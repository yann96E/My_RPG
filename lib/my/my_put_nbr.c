/*
** EPITECH PROJECT, 2019
** Library Function
** File description:
** by Patrick Eiermann
*/

#include "my.h"

static int display_digit(int nb)
{
    int figure = nb % 10;

    nb = nb / 10;
    if (nb != 0)
        display_digit(nb);
    my_putchar(figure + 48);
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            nb += 2000000000;
            my_putchar('2');
        }
        display_digit(-nb);
    }
    else
        display_digit(nb);
    return (0);
}
