/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#include "source.h"

static void pourcent_set(window_t *win)
{
    char *res;
    int len;

    ++win->intro->status;
    res = nb_to_str(&win->intro->status, int_e);
    len = my_strlen(res);
    res[len] = '%';
    res[len + 1] = '\0';
    win->intro->stat_num = res;
}

static void set_sprite(window_t *win, char *sprite_path, int pos_1, int pos_2)
{
    int offset = my_strlen(sprite_path);
    int len = 0, i = 0;
    file_path_t *sprite = get_all_path(opendir(sprite_path),
                                       sprite_path, &len, true);

    if (!sprite) return;
    win->obj[pos_1][pos_2] = malloc(sizeof(sprite_ress_t) * (len + 1));
    for (file_path_t *file = sprite; file; NEXT(file), ++i) {
        while (win->win_clock->second < 0.03) {
            win->win_clock->time =
                sfClock_getElapsedTime(win->win_clock->clock);
            win->win_clock->second =
                win->win_clock->time.microseconds / 1000000.0;
        }
        sfRenderWindow_clear(win->window, sfBlack);
        sfRenderWindow_drawText(win->window, win->intro->text, NULL);
        win->obj[pos_1][pos_2][i] = malloc(sizeof(sprite_ress_t));
        win->obj[pos_1][pos_2][i]->file_name = file->path + offset;
        win->obj[pos_1][pos_2][i]->texture =
            sfTexture_createFromFile(file->path, NULL);
        my_printf(1, "win->obj[%d][%d][%d], %d path =%s\n", pos_1, pos_2, i, win->intro->status, file->path);
        if (i % 3 == 0 && win->intro->status != 100) {
            pourcent_set(win);
            sfText_setString(win->intro->text, win->intro->stat_num);
        }
        if (win->intro->status == 100) {
            sfText_setString(win->intro->text, "Start Game... Go !");
            sfText_setPosition(win->intro->text, (sfVector2f){810, 900});
        }
        display_intro(win);
        sfClock_restart(win->win_clock->clock);
        win->win_clock->second = 0.00;
    }
    win->obj[pos_1][pos_2][len] = NULL;
}

static void set_content(window_t *win, char *path_folder, int pos)
{
    int len = 0, i = 0;
    file_path_t *path = get_all_path(opendir(path_folder),
                                     path_folder, &len, false);

    if (!path) return;
    win->obj[pos] = malloc(sizeof(sprite_ress_t **) * (len + 1));
    for (file_path_t *file = path; file; NEXT(file), ++i) {
        set_sprite(win, file->path, pos, i);
        sfClock_restart(win->win_clock->clock);
    }
    win->obj[pos][len] = NULL;
}

static void set_content_sprite(window_t *win)
{
    int len = 0, i = 0;
    file_path_t *path = get_all_path(opendir(SPRITE_PATH),
                                     SPRITE_PATH, &len, false);

    win->obj = malloc(sizeof(sprite_ress_t ***) * (len + 1));
    if (!path) return;
    for (file_path_t *file = path; file; NEXT(file), ++i)
        set_content(win, file->path, i);
    win->obj[len] = NULL;
}

void intro(window_t *win)
{
    win->intro = init_intro(win);
    set_content_sprite(win);
    /* destroy_intro(win); */
    win->status = menu_;
}
