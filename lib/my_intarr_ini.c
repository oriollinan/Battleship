/*
** EPITECH PROJECT, 2022
** my_arr_ini
** File description:
** initiang and creating a 2d array
*/

#include "my_arr.h"

void free_intarr(int **arr)
{
    for (int a = 0; arr[a]; a++)
        free(arr[a]);
    free(arr);
}

int **my_intarr_ini(int x, int y)
{
    int **arr = malloc(sizeof(int *) * (y + 1));

    if (!arr)
        return (NULL);
    for (int i = 0; i < y; i++) {
        arr[i] = malloc(sizeof(int) * (x + 1));
        if (!arr[i])
            return (NULL);
        for (int j = 0; j < x; j++)
            arr[i][j] = 0;
        arr[i][x] = -1;
    }
    arr[y] = malloc(sizeof(int) * (1));
    if (!arr[y])
        return (NULL);
    arr[y][0] = -2;
    return (arr);
}
