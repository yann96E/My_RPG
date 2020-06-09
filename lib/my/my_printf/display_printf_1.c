/*
** EPITECH PROJECT, 2019
** display function
** File description:
** thts is for librery
*/

#include <stdarg.h>
#include "../my.h"

void display_hexa(va_list params_list)
{
    my_put_hexa(va_arg(params_list, int));
}

void display_binary(va_list params_list)
{
    my_put_binary(va_arg(params_list, int));
}

void display_pointer(va_list params_list)
{
    char *print_directory =  (void *)va_arg(params_list, char *);
    my_printf("%s", print_directory);
}