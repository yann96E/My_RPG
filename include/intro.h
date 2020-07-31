/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** pour include tout
*/

#ifndef INTRO_H
#define INTRO_H

#include "lib.h"

typedef struct intro_s
{
    int init;
    int status;
    char *stat_num;
    sfSprite *S_back_0;
    sfTexture *T_back_0;
    sfSprite *S_back_1;
    sfTexture *T_back_1;
    sfSprite *S_logo;
    sfTexture *T_logo;
    sfText *text;
    sfFont* font;
} intro_t;

typedef struct file_path_s
{
    char *path;
    struct file_path_s *next;
    struct file_path_s *prev;
}file_path_t;

#endif /* INTRO_H */
