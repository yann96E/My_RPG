/*
** EPITECH PROJECT, 2020
** get_all_path
** File description:
** get_all_path
*/

#include "source.h"

static file_path_t *new_sprite(char *sprite_path, file_path_t **cur_node)
{
    file_path_t *new = malloc(sizeof(file_path_t));

    new->path = sprite_path;
    new->next = *cur_node;
    new->prev = NULL;
    if (*cur_node) (*cur_node)->prev = new;
    return (new);
}

static file_path_t *sort_path_by_alphabetic_order(file_path_t *path,
                                                  int const offset)
{
    file_path_t *new = NULL;
    file_path_t *biggest = path;

    if (!path) return (NULL);
    while (path->next) {
        biggest = path;
        for (file_path_t *i = path->next; i; NEXT(i)) {
            biggest = ((strcmp_to_crt_number(biggest->path + offset,
                       i->path + offset, '.') < 0) ? (i) : (biggest));
        }
        LINK_PREV_NEXT(biggest);
        LINK_NEXT_PREV(biggest);
        if (!biggest->prev) path = biggest->next;
        biggest->next = new;
        new = biggest;
    }
    path->next = new;
    new = path;
    return (new);
}

file_path_t *get_all_path(DIR *dir, char *folder_path, int *len,
                          bool const check_extension)
{
    struct dirent *cur_file = NULL;
    file_path_t *path = NULL;

    if (!dir) return (NULL);
    while ((cur_file = readdir(dir)) != NULL) {
        if (*cur_file->d_name == '.' ||
            (check_extension &&
             cmp_extension(cur_file->d_name, ".png") != 0 &&
             cmp_extension(cur_file->d_name, ".jpg") != 0))
            continue;
        path = new_sprite(my_strcat_insert_to_end(folder_path, "/", cur_file->d_name, 0), &path);
        if (!path) return (NULL);
        ++*len;
    }
    closedir(dir);
    return (sort_path_by_alphabetic_order(path, my_strlen(folder_path)));
}
