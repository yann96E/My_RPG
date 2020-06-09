/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#include "../include/my_rpg.h"

static void free_obj(window_t *win)
{
    for (int i = 0; win->obj[i]; ++i) {
        for (int j = 0; win->obj[i][j]; ++j) {
            for (int k = 0; win->obj[i][j][k]; ++k) {
                sfTexture_destroy(win->obj[i][j][k]->texture);
                free(win->obj[i][j][k]);
            }
            free(win->obj[i][j]);
        }
        free(win->obj[i]);
    }
    freeif(win->obj);
}

static void free_struct(window_t *win)
{
    free(win->win_clock);
    free(win->intro);
    free(win->menu);
}

static window_t *malloc_struct(void)
{
    window_t *win = init_window();

    if (!win || !(win->win_clock = init_clock())) return (NULL);
    win->intro = NULL;
    win->menu = NULL;
    return (win);
}

int main(int argc, char **argv)
{
    window_t *win = malloc_struct();

    srand(time(NULL));
    if (!win) return (84);
    launch_game(win);
    free_struct(win);
    free_obj(win);
    free(win);
    return (0);
}
