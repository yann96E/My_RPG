/*
** EPITECH PROJECT, 2019
** Library Function
** File description:
** by Patrick Eiermann
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
    int tmp = 0;

    for (int i = 0; i != size; ++i) {
        if (i > 0 && array[i] < array[i - 1]) {
            tmp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = tmp;
            i -= 2;
        }
    }
}