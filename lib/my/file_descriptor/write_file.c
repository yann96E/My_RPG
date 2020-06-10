/*
** EPITECH PROJECT, 2020
** write_file
** File description:
** write_file
*/

#include "my.h"

char write_file(int const src, int const dest, unsigned char const close_)
{
    char res[100];
    int cur_read = 0;

    if (src == -1 || dest == -1) return (84);
    while ((cur_read = read(src, res, 100)) > 0)
        write(dest, res, cur_read);
    if (BIT(close_, 0))
        close(src);
    if (BIT(close_, 2))
        close(dest);
    return (0);
}
