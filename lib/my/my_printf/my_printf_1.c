/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include "../my.h"

void my_put_binary(int nb)
{
    int div_max = 2;
    int temp_nb = nb;
    int digit = 0;

    while (temp_nb > 2) {
        div_max = div_max * 2;
        temp_nb = temp_nb / 2;
    }
    for (int i = div_max; i >= 1; i = i / 2) {
        digit = 48 + (nb / i % 2);
        my_putchar(digit);
    }
}

void my_put_hexa(int nb)
{
    int div_max = 1;
    int temp_nb = nb;
    int digit = 0;

    while (temp_nb >= 16) {
        div_max = div_max * 16;
        temp_nb = temp_nb / 16;
    }
    for (int i = div_max; i >= 1; i = i / 16) {
        digit = 48 + (nb / i % 16);
        my_putchar(digit);
    }
    if (digit > 9)
        my_putchar(digit + 87);
    else
        my_putchar(digit + 48);
}

void my_put_octal(int nb)
{
    int div_max = 1;
    int temp_nb = nb;
    int digit = 0;

    while (temp_nb > 9) {
        div_max = div_max * 8;
        temp_nb = temp_nb / 8;
    }
    for (int i = div_max; i >= 1; i = i / 8) {
        digit = 48 + (nb / i % 8);
        my_putchar(digit);
    }
}

static int display_digit(unsigned int nb)
{
    unsigned int figure = nb % 10;

    nb = nb / 10;
    if (nb != 0)
        display_digit(nb);
    my_putchar(figure + 48);
    return (0);
}

void my_put_unsigned_nbr(unsigned int nb)
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
}
