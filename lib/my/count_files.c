/*
** EPITECH PROJECT, 2020
** count_files
** File description:
** count files
*/

#include "my.h"

int count_files(char *path)
{
    DIR *data;
    struct dirent *dir;
    unsigned int ret = 0;

    data = opendir(path);
    if (data == 0) {
        closedir(data);
        return (-1);
    }
    while ((dir = readdir(data)) != NULL) {
        ret += (dir->d_name[0] != '.');
    }
    closedir(data);
    return (ret);
}