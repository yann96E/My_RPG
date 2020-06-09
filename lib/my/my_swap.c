/*
** EPITECH PROJECT, 2019
** Library Function
** File description:
** by Patrick Eiermann
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}