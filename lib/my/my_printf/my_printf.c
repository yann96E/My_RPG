/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** thts is for librery
*/

#include <stdarg.h>
#include "../my.h"

void send_function(char c, va_list params_list)
{
    void (*func_ptr[11])(va_list) = {display_char, display_str, display_int,
    display_int, display_unsigned_int, display_octal, display_hexa,
    display_hexa, display_binary, display_pointer, display_str};
    char flags[11] = "csdiuoxXbpS";

    if (c == 'c')
        func_ptr[0](params_list);
    else if (c == '%')
        my_putchar('%');
    else
    {
        int i;
        for (i = 1;flags[i] != c; i++);
        func_ptr[i](params_list);
    }
}

int my_printf(char *str, ...)
{
    va_list params_list;
    va_start(params_list, str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && check_format(str[i + 1]) == 1) {
            send_function(str[i + 1], params_list);
            i++;
        } else {
            my_putchar(str[i]);
        }
    }
    va_end(params_list);
    return (0);
}