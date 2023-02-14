/*
** EPITECH PROJECT, 2023
** error_handling
** File description:
** error_handling for navy
*/

#include "navy.h"
#include <stdio.h>
#include <stdlib.h>

ssize_t count_bytes(char *path)
{
    size_t line_len = 0;
    char *line = NULL;
    FILE *fd = fopen(path, "r");
    ssize_t bytes = 0;

    if (!fd)
        return (0);
    while (getline(&line, &line_len, fd) != -1)
        bytes += line_len;
    fclose(fd);
    return (bytes);
}

char *read_file(char *path, int size)
{
    char *buf = NULL;
    int fd = 0;

    if (size <= 0)
        return (NULL);
    if ((fd = open(path, O_RDONLY)) == -1)
        return (NULL);
    buf = my_malloc_ini(size + 1);
    if (!buf)
        return (NULL);
    if (read(fd, buf, size) == -1) {
        free(buf);
        return (NULL);
    }
    if (close(fd) == -1) {
        free(buf);
        return (NULL);
    }
    return (buf);
}

bool is_correct(char *str)
{
    if (!str)
        return (false);
    if (my_strlen(str) != 32 && my_strlen(str) != 31)
        return (false);
    for (int i = 0; str[i] && i < my_strlen(str); i += 8) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
        if (str[i + 1] != ':' || str[i + 4] != ':')
            return (false);
        if ((str[i + 2] < 'A' || str[i + 2] > 'Z')
        || (str[i + 5] < 'A' || str[i + 5] > 'Z'))
            return (false);
        if ((str[i + 3] < '0' || str[i + 3] > '9')
        || (str[i + 6] < '0' || str[i + 6] > '9'))
            return (false);
        if (str[i + 7] && str[i + 7] != '\n')
            return (false);
    }
    return (true);
}

bool error_handling(int ac, char **av)
{
    char *str = NULL;

    if (ac != 2 && ac != 3)
        return (true);
    if (ac == 2)
        str = read_file(av[1], count_bytes(av[1]));
    else if (ac == 3)
        str = read_file(av[2], count_bytes(av[2]));
    if (!is_correct(str))
        return (true);
    return (false);
}
