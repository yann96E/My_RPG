/*
** EPITECH PROJECT, 2020
** read_file
** File description:
** read file and put it in a string
*/

#include "my.h"
#include <fcntl.h>

int get_fd(char *name)
{
    int fd = open(name, O_RDONLY);

    return (fd);
}

char *read_file(int fd, int rdsize)
{
    char *ret = NULL;
    char buffer[rdsize + 1];
    int size = 1;
    int final_size = 0;

    if (fd == -1)
        return (NULL);
    while ((size = read(fd, buffer, rdsize))) {
        buffer[size] = '\0';
        ret = my_strncat(ret, my_strdup(buffer), size);
        if (ret == NULL)
            return (NULL);
        final_size += size;
    }
    if (fd > 2)
        close(fd);
    ret[final_size] = '\0';
    return (ret);
}
