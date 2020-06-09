/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include "../my.h"

void display_char(va_list params_list)
{
    my_putchar(va_arg(params_list, int));
}

void display_str(va_list params_list)
{
    my_putstr(va_arg(params_list, const char *));
}

void display_int(va_list params_list)
{
    my_put_nbr(va_arg(params_list, int));
}

void display_unsigned_int(va_list params_list)
{
    my_put_nbr(va_arg(params_list, int));
}

void display_octal(va_list params_list)
{
    my_put_octal(va_arg(params_list, int));
}