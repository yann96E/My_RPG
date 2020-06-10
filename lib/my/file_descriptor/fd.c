/*
** EPITECH PROJECT, 2019
** check_fct
** File description:
** check-fct
*/

#include "my.h"

int get_fd(char const *str, unsigned char const rights)
{
    if (!str) return (-1);
    return (open(str, rights, S_IROTH));
}

char *get_str_from_file_path(char const *path)
{
    struct stat info;
    int const fd = get_fd(path, O_RDONLY);
    char *str = NULL;

    if (fd == -1) return (NULL);
    fstat(fd, &info);
    if (!(str = malloc(info.st_size + 1))) return (NULL);
    str[info.st_size] = '\0';
    read(fd, str, info.st_size);
    close(fd);
    return (str);
}

char *get_str_from_file_fd(int const fd)
{
    struct stat info;
    char *str = NULL;

    if (fd == -1) return (NULL);
    fstat(fd, &info);
    if (!(str = malloc(info.st_size + 1))) return (NULL);
    str[info.st_size] = '\0';
    read(fd, str, info.st_size);
    close(fd);
    return (str);
}
