/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** parsing for the file
*/

#include "navy.h"

bool in_bounds(int start, int size)
{
    if (start + size - 1 > 8 && start + size - 1 > 0)
        return (false);
    return (true);
}

int **horizontal_boat(int **map, int size, int y, int x)
{
    if (!in_bounds(x, size))
        return (NULL);
    for (int i = 0; i < size; i++)
        map[y][x + i] = size;
    return (map);
}

int **vertical_boat(int **map, int size, int y, int x)
{
    if (!in_bounds(y, size))
        return (NULL);
    for (int j = 0; j < size; j++)
        map[y + j][x] = size;
    return (map);
}

int **boats(int **map, char *size_str, char *start, char *end)
{
    int size = my_getnbr(size_str);
    int x = start[0] - 'A';
    int y = start[1] - '0' - 1;

    if (start[0] == end[0])
        map = vertical_boat(map, size, y, x);
    else
        map = horizontal_boat(map, size, y, x);
    return (map);
}

int **parsing(char *path)
{
    char *str = read_file(path, count_bytes(path));
    char **arr = my_new_split(str, ":\n");
    int **map = NULL;

    if (!arr)
        return (NULL);
    map = my_intarr_ini(8, 8);
    if (!map)
        return (NULL);
    for (int j = 0; arr[j]; j += 3) {
        map = boats(map, arr[j], arr[j + 1], arr[j + 2]);
        if (!map)
            return (NULL);
    }
    free(str);
    free_arr(arr);
    return (map);
}
